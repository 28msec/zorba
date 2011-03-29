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

#include "debugger_communication.h"
#include "synchronous_logger.h"
#include "utils.h"
#include "message_factory.h"
#include "util/stl_util.h"

#include <zorbaerrors/assert.h>
#include <memory>

#ifdef WIN32
#define sleep(s) Sleep(1000*s)
#endif

zorba::DebuggerCommunicator::DebuggerCommunicator(
  std::string aHost,
  unsigned short aCommandPort,
  unsigned short aEventPort)
:
theCommandSocket(0), theEventSocket(0)
{
	std::auto_ptr<TCPServerSocket> lServerSocket(
    new TCPServerSocket(aHost, aCommandPort));
	theCommandSocket = lServerSocket->accept();
	ZORBA_ASSERT(theCommandSocket);
#ifndef NDEBUG
	synchronous_logger::clog << "[Server Thread] Client connected\n";
#endif
	for ( unsigned int i = 0; i < 3 && ! theEventSocket; i++ ) {
		try {
			//Wait one second before trying to reconnect
			sleep(1);
			//Connect the client to the event server
			theEventSocket = new TCPSocket( theCommandSocket->getForeignAddress(), aEventPort );
			break;
		} catch ( DebuggerSocketException &e )  {
			if ( i < 2 ) continue;
			synchronous_logger::cerr << "[Server Thread] Couldn't connect to the debugger server event: \n";
			synchronous_logger::cerr << "[Server Thread] " <<  e.what() << "\n";
			return;
		}
	}
}

void zorba::DebuggerCommunicator::handshake()
{
	ztd::auto_vec<Byte> msg(new Byte[11]);
	try
	{
		theCommandSocket->recv( msg.get(), 11 );
		theCommandSocket->send( msg.get(), 11 );
	} catch( DebuggerSocketException &e ) {
		synchronous_logger::clog << "[Server Thread] handshake failed\n";
		synchronous_logger::clog << "[Server Thread]" << e.what() << "\n";
	}
}

zorba::AbstractCommandMessage* zorba::DebuggerCommunicator::handleTCPClient()
{
  ztd::auto_vec<Byte> lByteMessage;
  std::auto_ptr<AbstractMessage> lMessage;
  try
  {
    lMessage.reset(MessageFactory::buildMessage(theCommandSocket));
    if (lMessage.get() == 0) {
#ifdef DEBUG
      synchronous_logger::clog << "[Server Thread] The connection with the client is closed\n";
#endif
      return NULL;
    }
    AbstractCommandMessage* lCommandMessage = dynamic_cast< AbstractCommandMessage * >(lMessage.get());
    assert(lCommandMessage);
    lMessage.release();
    return lCommandMessage;
#ifndef NDEBUG
  } catch ( std::exception const &e ) {
    synchronous_logger::clog << "[Server Thread] The connection with the client is closed\n";
    synchronous_logger::clog <<  e.what() << "\n";
#else
  } catch ( std::exception const& ) {
#endif
  } catch(...) {
    synchronous_logger::clog << "[Server Thread] unknown exception\n";
  }
  return NULL;
}

void zorba::DebuggerCommunicator::sendEvent( AbstractCommandMessage* aMessage )
{
	Length length;
	ztd::auto_vec<Byte> lMessage(aMessage->serialize(length));
	try
	{
#ifndef NDEBUG
		synchronous_logger::clog << "[Server Thread] send an event: ";
		switch ( aMessage->getCommand() )
		{
		case STARTED:
			synchronous_logger::cerr << "started\n";
			break;
		case TERMINATED:
			synchronous_logger::cerr << "terminated\n";
			break;
		case SUSPENDED:
			synchronous_logger::cerr << "suspended\n";
			break;
		case RESUMED:
			synchronous_logger::cerr << "resumed\n";
			break;
		case EVALUATED:
			synchronous_logger::cerr << "evaluated\n";
			break;
		}
#endif
		theEventSocket->send( lMessage.get(), length );
#ifndef NDEBUG
		synchronous_logger::clog << "[Server Thread] event sent\n";
#endif
	} catch( DebuggerSocketException &e ) {
		synchronous_logger::cerr << e.what() << "\n";
	}
}

zorba::DebuggerCommunicator::~DebuggerCommunicator()
{
	delete theEventSocket;
	delete theCommandSocket;
}

void zorba::DebuggerCommunicator::sendReplyMessage( AbstractCommandMessage* aMessage )
{
	Length length;
	ztd::auto_vec<Byte> lByteMessage;
	std::auto_ptr<ReplyMessage> lReply(aMessage->getReplyMessage());
	lByteMessage.reset(lReply->serialize( length ));
	theCommandSocket->send( lByteMessage.get(), length );
}
