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

#include "debugger_communicator.h"

#include <memory.h>
#include <string>
#include <sstream>

#include "socket.h"
#include "zorbautils/synchronous_logger.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(1000*s)
#endif

namespace zorba {

DebuggerCommunicator::DebuggerCommunicator(
  const std::string&  aHost,
  unsigned short      aPort)
  : theSocket(0)
{
	for (int i = 0; i < 3 && !theSocket; i++) {
		try {
			// Connect to the client on the given host and port
      theSocket = new TCPSocket(aHost, aPort);
		} catch (DebuggerSocketException& /* e */)  {
      // Wait one second before trying to reconnect
      sleep(1);
		}
  }
  
  if (!theSocket) {
    zorba::cerr << "[Server Thread] Couldn't connect to the debugger client\n";
	  return;
  }
}

DebuggerCommunicator::~DebuggerCommunicator()
{
	delete theSocket;
}

void
DebuggerCommunicator::send(const std::string& aMessage)
{
  std::stringstream lLenS;
  lLenS << aMessage.length();
  int lLLen = lLenS.str().length();
  int lMLen = aMessage.length();
  int lTLen = lLLen + lMLen + 2;
  char* lData = new char[lTLen];
  memset(lData, '\0', lTLen);
  memcpy(lData, lLenS.str().c_str(), lLLen);
  memcpy(lData + lLLen + 1, aMessage.c_str(), lMLen);
  theSocket->send(lData, lTLen);

  delete lData;
}

void
DebuggerCommunicator::receive(std::string& aMessage)
{
  char* lData = new char[256];
  int count = theSocket->recv(lData, 256);

  if (count > 0) {
    aMessage = lData;
  } else {
    aMessage = "";
  }

  delete lData;
}

}
