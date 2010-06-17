/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "zorba_debugger_runtime.h"

#include <memory>
#include <vector>
#include <sstream>
#include <fstream>

#include "store/api/store.h"

#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"
#include "api/serializerimpl.h"

#include "context/static_context.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/debug/zorba_debug_iterator.h"
#include "runtime/util/flowctl_exception.h"

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
      const xqpString& aEvalString,
      Zorba_SerializerOptions& aSerOpts,
      Id aId)
      : 
    theCommons(aCommons), 
    theCommunicator(aCommunicator),
    theEvalString(aEvalString),
    theSerOpts(aSerOpts),
    theId(aId)
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
          new EvaluatedEvent(
            theId,
            theEvalString,
            theCommons->eval(theEvalString, theSerOpts)));
      } catch (error::ZorbaError& lError) {
        lEvent.reset(
          new EvaluatedEvent(
            theId,
            theEvalString,
            lError.toString()));
      }
      theCommunicator->sendEvent(lEvent.get());
    }

    virtual void finish()
    {
    }

  private:
    ZorbaDebuggerCommons*     theCommons;
    DebuggerCommunicator*     theCommunicator;
    xqpString                 theEvalString;
    Zorba_SerializerOptions&  theSerOpts;
    Id                        theId;
  };

ZorbaDebuggerRuntime::ZorbaDebuggerRuntime(
  XQueryImpl* xqueryImpl,
  std::ostream& oStream,
  Zorba_SerializerOptions& serializerOptions,
  DebuggerCommunicator* communicator,
  itemHandler aHandler,
  void* aCallBackData)
  : theQuery(xqueryImpl),
    theOStream(oStream),
    theSerializerOptions(serializerOptions),
    theCommunicator(communicator),
    theWrapper(theQuery->generateWrapper()),
    theExecStatus(QUERY_IDLE),
    theCurrentMessage(0),
    theNotSendTerminateEvent(false),
    thePlanIsOpen(false),
    theSerializer(0),
    theItemHandler(aHandler),
    theCallbackData(aCallBackData)
{
}

ZorbaDebuggerRuntime::~ZorbaDebuggerRuntime()
{
  delete theSerializer;
}

// this is the main loop of the thread
// the runtime thread terminates if this method finishes
void
ZorbaDebuggerRuntime::run()
{
  theWrapper->open();
  thePlanIsOpen = true;

  std::auto_ptr<StartedEvent> lStarted(new StartedEvent());
  theCommunicator->sendEvent(lStarted.get());
  lStarted.reset(0);

  runQuery();
}

void ZorbaDebuggerRuntime::finish()
{
  if (thePlanIsOpen) {
    theWrapper->close();
  }
  if (!theNotSendTerminateEvent) {
    TerminatedEvent lEvent;
    theCommunicator->sendEvent(&lEvent);
  }
}

void ZorbaDebuggerRuntime::resetRuntime()
{
  theWrapper = theQuery->generateWrapper();
  thePlanIsOpen = false;
  theExecStatus = QUERY_IDLE;
  theNotSendTerminateEvent = false;
  reset();
}

bool ZorbaDebuggerRuntime::processMessage(AbstractCommandMessage* message)
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
  case STATIC:
    staticCommands();
    break;
  case DYNAMIC:
    dynamicCommands();
    break;
  default:
    throw InvalidCommandException("Internal Error: Command set not implemented");
  }
  return false;
}

ExecutionStatus ZorbaDebuggerRuntime::getExecutionStatus() const
{
  AutoLock lLock(theLock, Lock::READ);
  return theExecStatus;
}

void ZorbaDebuggerRuntime::runQuery()
{
  theLock.wlock();
  theExecStatus = theExecStatus == QUERY_SUSPENDED ? QUERY_RESUMED : QUERY_RUNNING;

  // used to print error messages
  PrinterErrorHandler lErrorHandler(theOStream);

  try {
    theWrapper->thePlanState->theDebuggerCommons->setRuntime(this);
    theLock.unlock();

    delete theSerializer;
    theSerializer = new serializer(theQuery->theErrorManager);
    SerializerImpl::setSerializationParameters(
      *theSerializer, theSerializerOptions);
    if (theItemHandler) {
      theSerializer->serialize((intern::Serializable*)theWrapper, theOStream,
        theItemHandler, theCallbackData);
    } else {
      theSerializer->serialize((intern::Serializable*)theWrapper, theOStream);
    }
    
    theOStream.flush();
  } catch (FlowCtlException&) {
    // Runtime correctly terminated by user interrupt
  } catch (error::ZorbaError& e){
    // this does not rethrow but only print the error message
    ZorbaImpl::notifyError(&lErrorHandler, e);
  }
  theLock.wlock();
  theExecStatus = QUERY_TERMINATED;
  theLock.unlock();
}

bool
ZorbaDebuggerRuntime::execCommands()
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

void ZorbaDebuggerRuntime::breakpointCommands()
{
  switch (theCurrentMessage->getCommand())
  {
  case SET:
    {
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
        QueryLoc lLoc = addBreakpoint(lIter->second, lIter->first);
        lReply->addBreakpoint(lIter->first, lLoc);
      }
      theCurrentMessage->setReplyMessage(lReply.release());
    }
    break;
  case CLEAR:
    {
      ZORBA_ASSERT(dynamic_cast<ClearMessage*>(theCurrentMessage));
      ClearMessage* lMessage = static_cast<ClearMessage*>(theCurrentMessage);
      std::vector<unsigned int> lIds = lMessage->getIds();
      std::vector<unsigned int>::iterator lIter;
      for (lIter = lIds.begin(); lIter != lIds.end(); ++lIter) {
        ZorbaDebuggerCommons* lCommons = 
          theWrapper->thePlanState->theDebuggerCommons;
        lCommons->clearBreakpoint(*lIter);
      }
    }
    break;
  }
}

void ZorbaDebuggerRuntime::staticCommands()
{
  switch (theCurrentMessage->getCommand())
  {
  case LIST:
    theCurrentMessage->setReplyMessage(listSource());
    break;
  }
}

void ZorbaDebuggerRuntime::dynamicCommands()
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

void ZorbaDebuggerRuntime::setQueryRunning()
{
  AutoLock lLock(theLock, Lock::WRITE);
  assert(theExecStatus == QUERY_RESUMED);
  theExecStatus = QUERY_RUNNING;
}

QueryLoc ZorbaDebuggerRuntime::addBreakpoint(const QueryLoc& aLocation,
                                             unsigned int aId)
{
  AutoLock lLock(theLock, Lock::WRITE);
  DebugLocation_t lLocation;
  lLocation.theFileName = aLocation.getFilename().c_str();
  lLocation.theLineNumber = aLocation.getLineno();
  ZorbaDebuggerCommons* lCommons = theWrapper->thePlanState->theDebuggerCommons;
  if (lCommons->addBreakpoint(lLocation, aId)){
    return lLocation.theQueryLocation;
  }
  return QueryLoc();
}

void ZorbaDebuggerRuntime::suspendRuntime( QueryLoc aLocation, SuspensionCause aCause )
{
  theLock.wlock();
  theExecStatus = QUERY_SUSPENDED;
  std::auto_ptr<SuspendedEvent> lMessage(new SuspendedEvent(aLocation, aCause));
  theCommunicator->sendEvent(lMessage.get());
  lMessage.reset(0);
  theLock.unlock();
  suspend();
}

void ZorbaDebuggerRuntime::resumeQuery()
{
  AutoLock lLock(theLock, Lock::WRITE);
#ifndef NDEBUG
  ResumeMessage* lMessage = dynamic_cast<ResumeMessage*>(theCurrentMessage);
  assert(lMessage);
#endif
  resumeRuntime();
}

void ZorbaDebuggerRuntime::resumeRuntime()
{
  theExecStatus = QUERY_RESUMED;
  resume();
  ResumedEvent lEvent;
  theCommunicator->sendEvent(&lEvent);
}

void ZorbaDebuggerRuntime::terminateRuntime()
{
  AutoLock lLock(theLock, Lock::WRITE);
#ifndef NDEBUG
  TerminateMessage* lMessage = dynamic_cast<TerminateMessage*>(theCurrentMessage);
  assert(lMessage);
#endif
  theWrapper->thePlanState->theHasToQuit = true;
  if (theExecStatus == QUERY_SUSPENDED) {
    resume();
  } else if (theExecStatus == QUERY_IDLE) {
    TerminatedEvent lEvent;
    theCommunicator->sendEvent(&lEvent);
  }
  theExecStatus = QUERY_TERMINATED;
}

ReplyMessage* ZorbaDebuggerRuntime::getAllVariables()
{
  ZorbaDebuggerCommons* lCommons = 
    theWrapper->thePlanState->theDebuggerCommons;
  static_context* lContext = lCommons->getCurrentStaticContext();
  std::vector<std::string> lVariables;
  lContext->getVariables(lVariables);
  std::auto_ptr<VariableReply> lReply(
    new VariableReply(theCurrentMessage->getId(), DEBUGGER_NO_ERROR));
  std::vector<std::string>::iterator lIter;
  for (lIter = lVariables.begin(); lIter != lVariables.end(); lIter++) {
    if (*lIter == "local") {
      lReply->addLocal(*(++lIter), *(++lIter));
    } else if (*lIter == "global") {
      lReply->addGlobal(*(++lIter), *(++lIter));
    }
  }
  return lReply.release();
}

void ZorbaDebuggerRuntime::step()
{
#ifndef NDEBUG
  // Check preconditions
  ZORBA_ASSERT(dynamic_cast<StepMessage*>(theCurrentMessage) != NULL);
#endif // NDEBUG
  StepMessage* lMessage = static_cast<StepMessage*>(theCurrentMessage);
  StepCommand lCommand = lMessage->getStepKind();
  ZorbaDebuggerCommons* lCommons = theWrapper->thePlanState->theDebuggerCommons;

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

void ZorbaDebuggerRuntime::setNotSendTerminateEvent()
{
  theNotSendTerminateEvent = true;
}

void ZorbaDebuggerRuntime::evalCommand()
{
  ZORBA_ASSERT(dynamic_cast<EvalMessage*>(theCurrentMessage));
  xqpString lExpr = static_cast<EvalMessage*>(theCurrentMessage)->getExpr();
  // This command will care itself about garbage collection - so don't delete
  // it in this method!
  EvalCommand* lCommand = new EvalCommand(
    theWrapper->thePlanState->theDebuggerCommons,
    theCommunicator, lExpr.c_str(), theSerializerOptions,
    theCurrentMessage->getId());
  lCommand->setDeleteAfterRun(true);
  lCommand->start();
}

ReplyMessage* ZorbaDebuggerRuntime::listSource()
{
  ZORBA_ASSERT(dynamic_cast<ListCommand*>(theCurrentMessage));
  ListCommand* lCommand = dynamic_cast<ListCommand*>(theCurrentMessage);
  std::string lFile;
  lFile = theWrapper->thePlanState->theDebuggerCommons->getFilepathOfURI(
    lCommand->getFilename());

  std::string lCurrLine;
  //std::string::iterator lSIter;
  //for (lSIter = lFile.begin(); lSIter != lFile.end(); ++lSIter) {
  //  if (*lSIter == '\\' && *(lSIter+1) == '\\') {
  //    lFile.erase(lSIter);
  //    ++lSIter;
  //  }
  //}
  std::ifstream lStream(lFile.c_str());
  for (unsigned long i = 0; i < lCommand->getFirstline() && lStream.good(); ++i)
  {
    std::getline(lStream, lCurrLine);
  }
  std::stringstream lOut;
  for (unsigned long i = lCommand->getFirstline();
    i < lCommand->getLastline() && lStream.good(); ++i) {
    std::getline(lStream, lCurrLine);
    lOut << lCurrLine;
    if (lStream.good()) {
      lOut << std::endl;
    }
  }
  return new ListReply(
    theCurrentMessage->getId(), DEBUGGER_NO_ERROR, lOut.str());
}

} // namespace zorba
