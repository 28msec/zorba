#include "zorba_debugger_server.h"

#include "debugger/debugger_communication.h"
#include "debugger/zorba_debugger_runtime.h"
#include "api/xqueryimpl.h"

#include <memory>

namespace zorba {

ZorbaDebuggerServer::ZorbaDebuggerServer(XQueryImpl* aQuery,
                                         const Zorba_SerializerOptions_t* serializerOption,
                                         std::ostream& anOstream,
                                         unsigned short requestPort /*= 8000*/,
                                         unsigned short eventPort /*= 9000*/)
  : theRequestPort(requestPort),
    theEventPort(eventPort)
{
  theCommunicator = new DebuggerCommunicator(theRequestPort, theEventPort);
  theRuntime = new ZorbaDebuggerRuntime(aQuery, anOstream, serializerOption, theCommunicator);
}

ZorbaDebuggerServer::~ZorbaDebuggerServer()
{
  delete theRuntime;
  delete theCommunicator;
}

void
ZorbaDebuggerServer::run()
{
  theCommunicator->handshake();

  // Until the query execution has ended
  while (theRuntime->getExecutionStatus() != QUERY_TERMINATED) {
    std::auto_ptr<AbstractCommandMessage> lMessage(theCommunicator->handleTCPClient());
    if (lMessage.get() != NULL) {
       if (lMessage->isExecutionCommand() && lMessage->getCommand() == RUN) {
         if (theRuntime->getExecutionStatus() == QUERY_SUSPENDED) {
           theRuntime->setNotSendTerminateEvent();
           theRuntime->terminate();
           theRuntime->join();
           theRuntime->resetRuntime();

         }
         theRuntime->start();
       } else {
         bool lTerminate = theRuntime->processMessage(lMessage.get());
         if (lTerminate) {
           theRuntime->terminate();
           break;
         }
      } 
      theCommunicator->sendReplyMessage(lMessage.get());
    } // if (lMessage.get() != NULL)
  } // while
  theRuntime->join();
} // ZorbaDebuggerServer::run

} /* namespace zorba */
