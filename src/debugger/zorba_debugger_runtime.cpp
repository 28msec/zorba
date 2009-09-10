#include "zorba_debugger_runtime.h"

#include <memory>
#include <vector>

#include "store/api/store.h"

#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"

#include "context/static_context.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/debug/zorba_debug_iterator.h"

#include "zorba/exception.h"
#include "zorba/printer_error_handler.h"
#include "zorbaerrors/errors.h"

#include "debugger/debugger_protocol.h"
#include "debugger/synchronous_logger.h"
#include "debugger/debugger_communication.h"
#include "debugger/zorba_debugger_commons.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

namespace zorba {
  class EvalCommand : public Runnable
  {
  public:
    EvalCommand(ZorbaDebuggerCommons* aCommons, 
      DebuggerCommunicator* aCommunicator,
      const xqpString& aEvalString)
      : 
    theCommons(aCommons), 
    theCommunicator(aCommunicator),
    theEvalString(aEvalString)
    {}

    virtual ~EvalCommand() {}

    /**
    * @brief runs the evaluation command in the current scope.
    *
    * Runs theEvalString in. This method is supposed to run in its own thread
    * and it will send an evaluation event back to the client after finishing.
    *
    * @pre theCommons != NULL
    * @pre theCommunicator != NULL
    */
    virtual void run()
    {
      // Check preconditions
      ZORBA_ASSERT(theCommons != NULL);
      ZORBA_ASSERT(theCommunicator != NULL);
      std::auto_ptr<EvaluatedEvent> lEvent;

      try {
        lEvent.reset(
          new EvaluatedEvent(theEvalString, theCommons->eval(theEvalString)));
      } catch (error::ZorbaError& lError) {
        lEvent.reset(
          new EvaluatedEvent(theEvalString, lError.toString()));
      }
      theCommunicator->sendEvent(lEvent.get());
    }

    /**
    * @brief Adds the current thread to theEvalThreads.
    *
    * The finish method adds the current thread to theEvalThreads so that it
    * will get deleted by the runtime.
    */
    virtual void finish()
    {
    }

  private:
    ZorbaDebuggerCommons*   theCommons;
    DebuggerCommunicator*   theCommunicator;
    xqpString               theEvalString;
  };
}


zorba::ZorbaDebuggerRuntime::ZorbaDebuggerRuntime(
  XQueryImpl* xqueryImpl,
  std::ostream& oStream,
  const Zorba_SerializerOptions_t*  serializerOptions,
  DebuggerCommunicator* communicator)
  : theQuery(xqueryImpl),
    theOStream(oStream),
    theSerializerOptions(serializerOptions),
    theCommunicator(communicator),
    theWrapper(theQuery->generateWrapper()),
    theExecStatus(QUERY_IDLE),
    theCurrentMessage(0),
    theNotSendTerminateEvent(false)
{
}

zorba::ZorbaDebuggerRuntime::~ZorbaDebuggerRuntime()
{
}

// this is the main loop of the thread
// the runtime thread terminates if this method finishes
void
zorba::ZorbaDebuggerRuntime::run()
{
  theWrapper->open();

  StartedEvent lStarted;
  theCommunicator->sendEvent(&lStarted);

  runQuery();
}

void zorba::ZorbaDebuggerRuntime::finish()
{
  theWrapper->close();
  if (!theNotSendTerminateEvent) {
    TerminatedEvent lEvent;
    theCommunicator->sendEvent(&lEvent);
  }
}

void zorba::ZorbaDebuggerRuntime::resetRuntime()
{
  theWrapper = theQuery->generateWrapper();
  theExecStatus = QUERY_IDLE;
  theNotSendTerminateEvent = false;
  reset();
}

bool zorba::ZorbaDebuggerRuntime::processMessage(AbstractCommandMessage* message)
{
  AutoLock lLock(theLock, Lock::WRITE);
  theCurrentMessage = message;

  switch (theCurrentMessage->getCommandSet())
  {
  case EXECUTION:
    if (execCommands()) {
      return true;
    }
    break;
  case BREAKPOINTS:
    breakpointCommands();
    break;
  case DYNAMIC:
    dynamicCommands();
    break;
  default:
    throw InvalidCommandException("Internal Error: Command set not implemented");
  }
  return false;
}

ExecutionStatus zorba::ZorbaDebuggerRuntime::getExecutionStatus() const
{
  AutoLock lLock(theLock, Lock::READ);
  return theExecStatus;
}

void zorba::ZorbaDebuggerRuntime::runQuery()
{
  theLock.wlock();
  theExecStatus = theExecStatus == QUERY_SUSPENDED ? QUERY_RESUMED : QUERY_RUNNING;

  // used to print error messages
  PrinterErrorHandler lErrorHandler(theOStream);

  try {
    theWrapper->theStateBlock->theDebuggerCommons->setRuntime(this);
    theLock.unlock();

    if (theQuery->isUpdateQuery()) {
      theQuery->applyUpdates(theWrapper);
      theOStream << "Query doesn't have a result because it is an updating query.";
    } else {
      serializer lSerializer(theQuery->theErrorManager);
      lSerializer.set_parameter("omit-xml-declaration", "yes");
      XQueryImpl::setSerializationParameters(&lSerializer, theSerializerOptions);
      
      lSerializer.serialize(&*theWrapper, theOStream);

      theOStream.flush();
    }
  } catch(error::ZorbaError& e){
    // this does not rethrow but only print the error message
    ZorbaImpl::notifyError(&lErrorHandler, e);
  }
  theLock.wlock();
  theExecStatus = QUERY_TERMINATED;
  theLock.unlock();
}

bool
zorba::ZorbaDebuggerRuntime::execCommands()
{
  switch (theCurrentMessage->getCommand())
  {
  case RESUME:
    resumeQuery();
    break;
  case TERMINATE:
    terminateRuntime();
    return true;
  case STEP:
    step();
    break;
  default:
    assert(false);
  }
  return false;
}

void zorba::ZorbaDebuggerRuntime::breakpointCommands()
{
  switch (theCurrentMessage->getCommand())
  {
  case SET:
    SetMessage* lMessage;
#ifndef NDEBUG
    lMessage = dynamic_cast<SetMessage*>(theCurrentMessage);
    assert(lMessage);
#else
    lMessage = static_cast<SetMessage*>(theCurrentMessage);
#endif
    std::auto_ptr<SetReply> lReply(new SetReply(theCurrentMessage->getId(), DEBUGGER_NO_ERROR));
    std::map<unsigned int, QueryLoc> lLocations = lMessage->getLocations();
    std::map<unsigned int, QueryLoc>::iterator lIter;
    for (lIter = lLocations.begin(); lIter != lLocations.end(); lIter++) {
      QueryLoc lLoc = addBreakpoint(lIter->second);
      lReply->addBreakpoint(lIter->first, lLoc);
    }
    theCurrentMessage->setReplyMessage(lReply.release());
  }
}

void zorba::ZorbaDebuggerRuntime::dynamicCommands()
{
  if (theExecStatus != QUERY_SUSPENDED) {
    std::auto_ptr<ReplyMessage> lReply(
      new ReplyMessage(theCurrentMessage->getId(), 
      DEBUGGER_ERROR_INVALID_COMMAND));
    theCurrentMessage->setReplyMessage(lReply.release());
    return;
  }
  switch (theCurrentMessage->getCommand())
  {
  case VARIABLES:
    theCurrentMessage->setReplyMessage(getAllVariables());
    break;
  case EVAL:
    evalCommand();
    break;
  }
}

void zorba::ZorbaDebuggerRuntime::setQueryRunning()
{
  AutoLock lLock(theLock, Lock::WRITE);
  assert(theExecStatus == QUERY_RESUMED);
  theExecStatus = QUERY_RUNNING;
}

zorba::QueryLoc zorba::ZorbaDebuggerRuntime::addBreakpoint( const QueryLoc& aLocation )
{
  AutoLock lLock(theLock, Lock::WRITE);
  DebugLocation_t lLocation;
  lLocation.theFileName = aLocation.getFilename().c_str();
  lLocation.theLineNumber = aLocation.getLineno();
  if (theWrapper->theStateBlock->theDebuggerCommons->addBreakpoint(lLocation)){
    return lLocation.theQueryLocation;
  }
  return QueryLoc();
}

void zorba::ZorbaDebuggerRuntime::suspendRuntime( QueryLoc aLocation, SuspensionCause aCause )
{
  theLock.wlock();
  theExecStatus = QUERY_SUSPENDED;
  SuspendedEvent lMessage( aLocation, aCause );
  theCommunicator->sendEvent( &lMessage );
  theLock.unlock();
  suspend();
}

void zorba::ZorbaDebuggerRuntime::resumeQuery()
{
  AutoLock lLock(theLock, Lock::WRITE);
#ifndef NDEBUG
  ResumeMessage* lMessage = dynamic_cast<ResumeMessage*>(theCurrentMessage);
  assert(lMessage);
#endif
  resumeRuntime();
}

void zorba::ZorbaDebuggerRuntime::resumeRuntime()
{
  theExecStatus = QUERY_RESUMED;
  resume();
  ResumedEvent lEvent;
  theCommunicator->sendEvent(&lEvent);
}

void zorba::ZorbaDebuggerRuntime::terminateRuntime()
{
  AutoLock lLock(theLock, Lock::WRITE);
  theExecStatus = QUERY_TERMINATED;
#ifndef NDEBUG
  TerminateMessage* lMessage = dynamic_cast<TerminateMessage*>(theCurrentMessage);
  assert(lMessage);
#endif
}

zorba::ReplyMessage* zorba::ZorbaDebuggerRuntime::getAllVariables()
{
  ZorbaDebuggerCommons* lCommons = 
    theWrapper->theStateBlock->theDebuggerCommons;
  static_context* lContext = lCommons->getCurrentStaticContext();
  std::vector<std::string> lVariables;
  lContext->getVariables(lVariables);
  std::auto_ptr<VariableReply> lReply(
    new VariableReply(theCurrentMessage->getId(), DEBUGGER_NO_ERROR));
  std::vector<std::string>::iterator lIter;
  for (lIter = lVariables.begin(); lIter != lVariables.end(); lIter++) {
    if (*lIter == "local") {
      lReply->addLocal(*(++lIter), "");
    }
  }
  return lReply.release();
}

void zorba::ZorbaDebuggerRuntime::step()
{
#ifndef NDEBUG
  // Check preconditions
  ZORBA_ASSERT(dynamic_cast<StepMessage*>(theCurrentMessage) != NULL);
#endif // NDEBUG
  StepMessage* lMessage = static_cast<StepMessage*>(theCurrentMessage);
  StepCommand lCommand = lMessage->getStepKind();
  ZorbaDebuggerCommons* lCommons = theWrapper->theStateBlock->theDebuggerCommons;

  switch (lCommand)
  {
  case STEP_INTO:
    // Resume and then suspend as soon as the next iterator is reached.
    lCommons->setBreak(true, CAUSE_STEP);
    resumeRuntime();
    break;
  case STEP_OUT:
    lCommons->makeStepOut();
    resumeRuntime();
    break;
  case STEP_OVER:
    lCommons->makeStepOver();
    resumeRuntime();
    break;
  }
}

void zorba::ZorbaDebuggerRuntime::setNotSendTerminateEvent()
{
  theNotSendTerminateEvent = true;
}

void zorba::ZorbaDebuggerRuntime::evalCommand()
{
  ZORBA_ASSERT(dynamic_cast<EvalMessage*>(theCurrentMessage));
  xqpString lExpr = static_cast<EvalMessage*>(theCurrentMessage)->getExpr();
  // This command will care itself about garbage collection - so don't delete
  // it in this method!
  EvalCommand* lCommand = new EvalCommand(
    theWrapper->theStateBlock->theDebuggerCommons,
    theCommunicator, lExpr.c_str());
  lCommand->setDeleteAfterRun(true);
  lCommand->start();
}
