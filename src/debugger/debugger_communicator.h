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
#ifndef ZORBA_DEBUGGER_COMMUNICATOR_H
#define ZORBA_DEBUGGER_COMMUNICATOR_H

#include <string>
#include <iostream>
#include <queue>

#include "zorbautils/runnable.h"
#include "zorbautils/lock.h"
#include "zorbautils/mutex.h"
#include "zorbautils/condition.h"

namespace zorba {

class TCPSocket;
class socket_streambuf;

class DebuggerCommunicator {

  class ResponseQueue : public Runnable {

    public:
      ResponseQueue(std::ostream* aStream);

      virtual ~ResponseQueue();

    public: // Runnable interface

      void
      run();

      void
      finish();

    public:
      void
      enqueue(const std::string& message);

	  private:

      std::queue<std::string> theQueue;
      std::ostream*           theStream;

      Lock                    theLock;
      Mutex                   theMutex;
      Condition               theCondition;
  };


  public:
    DebuggerCommunicator(
      const std::string&  aHost,
      unsigned short      aPort);

		virtual ~DebuggerCommunicator();

	public:

    bool
    isConnected();

    const std::string&
    getHost();

    unsigned short
    getPort();

    void
    connect();

    void
    send(const std::string& aMessage);

    void
    receive(std::string& aMessage);
		
	private:

    const std::string theHost;
    unsigned short    thePort;
    

    TCPSocket*        theSocket;
    socket_streambuf* theSocketInStream;
    socket_streambuf* theSocketOutStream;
    std::istream*     theCommunicatorInStream;
    std::ostream*     theCommunicatorOutStream;
    ResponseQueue*    theResponseQueue;
};

}//end of namespace

#endif // ZORBA_DEBUGGER_COMMUNICATOR_H
