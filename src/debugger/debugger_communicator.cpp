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

#include <zorba/error.h>
#include <zorba/diagnostic_list.h>

#include "socket.h"
#include "zorbautils/synchronous_logger.h"

#include "diagnostics/diagnostic.h"
#include "diagnostics/zorba_exception.h"


#ifndef WIN32
# include <unistd.h>
# define msleep(s) usleep(1000*s);
#else
# include <windows.h>
# define msleep(s) Sleep(s)
#endif

namespace zorba {

DebuggerCommunicator::DebuggerCommunicator(
  const std::string&  aHost,
  unsigned short      aPort)
  : theHost(aHost),
    thePort(aPort),
    theSocket(0),
    theSocketInStream(0),
    theSocketOutStream(0),
    theCommunicatorInStream(0),
    theCommunicatorOutStream(0),
    theResponseQueue(0)
{
}

DebuggerCommunicator::~DebuggerCommunicator()
{
  if (theSocket) {
    // send the termination message to terminate the queue loop/thread
    theResponseQueue->enqueue("");
    // wait until the queue thread is done
    theResponseQueue->join();

    // now we can safely delete all the pointers
	  delete theResponseQueue;
	  delete theCommunicatorOutStream;
	  delete theCommunicatorInStream;
	  delete theSocketOutStream;
	  delete theSocketInStream;
    delete theSocket;
  }
}

#ifdef NDEBUG
# define TIMEOUT 6
#else
# define TIMEOUT 60
#endif

void
DebuggerCommunicator::connect()
{
  for (int i = 0; i < TIMEOUT && !theSocket; i++)
  {
		try
    {
			// Connect to the client on the given host and port
      std::auto_ptr<TCPSocket> lSocket(new TCPSocket(theHost, thePort));
      theSocket = lSocket.release();
      theSocketInStream = new SocketStreambuf(*theSocket);
      theSocketOutStream = new SocketStreambuf(*theSocket);
      theCommunicatorInStream = new std::istream(theSocketInStream);
      theCommunicatorOutStream = new std::ostream(theSocketOutStream);
      theResponseQueue = new ResponseQueue(theCommunicatorOutStream);
      theResponseQueue->start();
		}
    catch (DebuggerSocketException& /* e */)
    {
      // Wait one second before trying to reconnect
      msleep(1000);
		}
  }
}

bool
DebuggerCommunicator::isConnected()
{
  return theSocket != NULL;
}

const std::string&
DebuggerCommunicator::getHost()
{
  return theHost;
}

unsigned short
DebuggerCommunicator::getPort()
{
  return thePort;
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
  theMutex.lock();
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
