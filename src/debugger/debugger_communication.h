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
#ifndef DEBUGGER_COMMUNICATION_H
#define DEBUGGER_COMMUNICATION_H

#include "debugger_protocol.h"
#include "socket.h"

namespace zorba {

class DebuggerCommunicator {

  public:
    DebuggerCommunicator(
      std::string     aHost,
      unsigned short  aCommandPort,
      unsigned short  aEventPort);

		virtual ~DebuggerCommunicator();

	public:

    void handshake();
		
    AbstractCommandMessage* handleTCPClient();
		
    void sendEvent(AbstractCommandMessage* aMessage);
		
    void sendReplyMessage(AbstractCommandMessage* aMessage);

	private:

    TCPSocket* theCommandSocket;
		
    TCPSocket* theEventSocket;

};

}//end of namespace

#endif // DEBUGGER_COMMUNICATION_H

