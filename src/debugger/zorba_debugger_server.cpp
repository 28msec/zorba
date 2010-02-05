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
#include "context/static_context.h"

#include "zorba_debugger_server.h"

#include "debugger/debugger_communication.h"
#include "debugger/zorba_debugger_runtime.h"
#include "api/xqueryimpl.h"

#include <memory>

namespace zorba {

ZorbaDebuggerServer::ZorbaDebuggerServer(XQueryImpl* aQuery,
                                         Zorba_SerializerOptions& serializerOption,
                                         std::ostream& anOstream,
                                         unsigned short requestPort /*= 8000*/,
                                         unsigned short eventPort /*= 9000*/)
  : theRequestPort(requestPort),
    theEventPort(eventPort)
{
  theCommunicator = new DebuggerCommunicator("127.0.0.1", theRequestPort, theEventPort);
  theRuntime = new ZorbaDebuggerRuntime(aQuery, anOstream, serializerOption,
    theCommunicator);
}

ZorbaDebuggerServer::ZorbaDebuggerServer(XQueryImpl* aQuery,
                                         Zorba_SerializerOptions& serializerOption,
                                         std::ostream& anOstream,
                                         std::string aHost,
                                         unsigned short requestPort /*= 8000*/,
                                         unsigned short eventPort /*= 9000*/)
  : theRequestPort(requestPort),
    theEventPort(eventPort)
{
  theCommunicator = new DebuggerCommunicator(aHost, theRequestPort, theEventPort);
  theRuntime = new ZorbaDebuggerRuntime(aQuery, anOstream, serializerOption,
    theCommunicator);
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
           theCommunicator->sendReplyMessage(lMessage.get());
           break;
         }
      } 
      theCommunicator->sendReplyMessage(lMessage.get());
    } // if (lMessage.get() != NULL)
  } // while
  theRuntime->join();
} // ZorbaDebuggerServer::run

} /* namespace zorba */
