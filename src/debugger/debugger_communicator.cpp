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
#include "stdafx.h"

#include "debugger_communicator.h"
#include "socket_streambuf.h"

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
  : theSocket(0),
    theSocketInStream(0),
    theSocketOutStream(0),
    theCommunicatorInStream(0),
    theCommunicatorOutStream(0),
    theResponseQueue(0)
{
	for (int i = 0; i < 3 && !theSocket; i++)
  {
		try
    {
			// Connect to the client on the given host and port
      std::auto_ptr<TCPSocket> lSocket(new TCPSocket(aHost, aPort));
      theSocket = lSocket.release();
      theSocketInStream = new socket_streambuf(*theSocket);
      theSocketOutStream = new socket_streambuf(*theSocket);
      theCommunicatorInStream = new std::istream(theSocketInStream);
      theCommunicatorOutStream = new std::ostream(theSocketOutStream);
      theResponseQueue = new ResponseQueue(theCommunicatorOutStream);
      theResponseQueue->start();
		}
    catch (DebuggerSocketException& /* e */)
    {
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
  // send the termination mressage to terminate the queue loop/thread
  theResponseQueue->enqueue("");
  // wait until the queue thread is done
  theResponseQueue->join();

  // now we can safely delete all the pointers
	delete theSocket;
	delete theSocketInStream;
	delete theSocketOutStream;
	delete theCommunicatorInStream;
	delete theCommunicatorOutStream;
	delete theResponseQueue;
}

void
DebuggerCommunicator::send(const std::string& aMessage)
{
  theResponseQueue->enqueue(aMessage);
}

void
DebuggerCommunicator::receive(std::string& aMessage)
{
  std::getline(*theCommunicatorInStream, aMessage, '\0');
}

/***********************************************************/

DebuggerCommunicator::ResponseQueue::ResponseQueue(std::ostream* aStream)
  : theStream(aStream),
    theMutex(),
    theCondition(theMutex)
{
}

DebuggerCommunicator::ResponseQueue::~ResponseQueue()
{
}

void
DebuggerCommunicator::ResponseQueue::run()
{
  while (true)
  {
    // make sure nobody else will go in here in the same time
    theLock.wlock();
    
    // freeze if we have nothing to send
    if (theQueue.size() == 0)
    {
      theLock.unlock();
      theCondition.wait();
      theLock.wlock();
    }

    // take out the front
    const std::string lMessage = theQueue.front();
    theQueue.pop();

    // we will use an empty string message to break the loop
    if (lMessage == "")
    {
      theLock.unlock();
      break;
    }

    // and send it
    (*theStream) << lMessage.length() << '\0' << lMessage << '\0';
    theStream->flush();

    // release the lock before trying to send one more sessage
    theLock.unlock();
  }
}

void
DebuggerCommunicator::ResponseQueue::finish()
{
}

void
DebuggerCommunicator::ResponseQueue::enqueue(const std::string& aMessage)
{
  theLock.wlock();
  theQueue.push(aMessage);
  theCondition.signal();
  theLock.unlock();
}

}
