#include "zorba_debugger_runtime.h"

#include <memory>
#include <vector>

#include "store/api/store.h"
#include "api/zorbaimpl.h"
#include "api/xqueryimpl.h"
#include "runtime/debug/zorba_debug_iterator.h"
#include "zorba/exception.h"
#include "zorba/printer_error_handler.h"

#include "debugger/debugger_protocol.h"
#include "debugger/synchronous_logger.h"
#include "debugger/debugger_communication.h"
#include "debugger/zorba_debugger_commons.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

zorba::ZorbaDebuggerRuntime::ZorbaDebuggerRuntime(XQueryImpl* xqueryImpl,
                                                  std::ostream& oStream,
                                                  const Zorba_SerializerOptions_t*  serializerOptions,
                                                  DebuggerCommunicator* communicator)
  : theQuery(xqueryImpl),
    theOStream(oStream),
    theSerializerOptions(serializerOptions),
    theCommunicator(communicator),
    theWrapper(theQuery->generateWrapper()),
    theExecStatus(QUERY_IDLE),
    theCurrentMessage(0)
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
  TerminatedEvent lEvent;
  theCommunicator->sendEvent(&lEvent);
}

bool zorba::ZorbaDebuggerRuntime::processMessage( AbstractCommandMessage* message )
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
