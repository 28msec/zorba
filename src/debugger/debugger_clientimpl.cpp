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


#include "debugger/debugger_clientimpl.h"

#include <iostream>
#include <memory>

#include <zorba/api_shared_types.h>
#include <zorba/debugger_exception.h>

#include "common/common.h"

#include "api/unmarshaller.h"

#include "zorbatypes/xqpstring.h"

#include "debugger/query_locationimpl.h"
#include "debugger/utils.h"
#include "debugger/socket.h"
#include "debugger/message_factory.h"
#include "debugger/stackimpl.h"

#include "json/parser.h"
#include "json/value.h"

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

using namespace std;

namespace zorba{

unsigned int ZorbaDebuggerClientImpl::theLastId = 0;

ZorbaDebuggerClientImpl::ZorbaDebuggerClientImpl(std::string aServerAddress, unsigned short aRequestPortno, unsigned short aEventPortno )
 : theEventHandler(0),
   theRequestSocket(0),
   theEventServerSocket(0),
   theExecutionStatus( QUERY_IDLE ),
   theEventListener(0)	
{
	try
	{
		do{
			theRequestSocket.reset(new TCPSocket(aServerAddress, aRequestPortno));
			theEventServerSocket.reset(new TCPServerSocket(aEventPortno));
			sleep(1);
			//Perform the handshake with the server
		} while(!handshake());
		//Start the event listener thread
		theEventListener = new Thread( listenEvents, this );
	} catch(DebuggerSocketException &e) {
		throw e;
  }
}

ZorbaDebuggerClientImpl::~ZorbaDebuggerClientImpl()
{
  delete theEventListener;
}

ZorbaDebuggerClient* ZorbaDebuggerClientImpl::registerEventHandler( DebuggerEventHandler * anEventHandler )
{
  theEventHandler = anEventHandler;
  //Special case for event handler initialization
  if ( theEventHandler != 0 && theExecutionStatus == QUERY_IDLE )
  {
    theEventHandler->idle();
  }
  return this;
}

bool ZorbaDebuggerClientImpl::handshake()
{
  bool result = false;
  ZorbaArrayAutoPointer<char> msg(new char[ 12 ]);
  memset(msg.get(), '\0', 12);
  try
  {
    theRequestSocket->send( "XQHandshake", 11 );
    theRequestSocket->recv( msg.get(), 11 );
    result = strcmp( msg.get(), "XQHandshake" ) == 0; 
    if(result)
    {
      return true;
    }
  } catch ( DebuggerSocketException& ) {
    //do nothing...
  }
  return false;
}

ZORBA_THREAD_RETURN listenEvents( void * aClient )
{
  ZorbaDebuggerClientImpl * lClient = (ZorbaDebuggerClientImpl *) aClient;
  assert(lClient != 0);

  try
  {
    std::auto_ptr<TCPSocket> lSocket( lClient->theEventServerSocket->accept() );
    while( lClient->theExecutionStatus != QUERY_TERMINATED )
    {
      std::auto_ptr<AbstractMessage> lMessage(MessageFactory::buildMessage( lSocket.get() ));
      SuspendedEvent  *lSuspendedMsg;
      EvaluatedEvent  *lEvaluatedEvent;
      if ( ( lSuspendedMsg = dynamic_cast< SuspendedEvent * > ( lMessage.get() ) ) )
      {
        lClient->theExecutionStatus = QUERY_SUSPENDED;
        lClient->theRemoteLocation  = lSuspendedMsg->getLocation();
        if ( lClient->theEventHandler )
        {
          QueryLocationImpl loc( lSuspendedMsg->getLocation() );
          lClient->theEventHandler->suspended( loc, (SuspendedBy)lSuspendedMsg->getCause() );
        }
      } else if ( dynamic_cast< StartedEvent * > ( lMessage.get() ) ) {
        lClient->theExecutionStatus = QUERY_RUNNING;
        if ( lClient->theEventHandler )
        {
          lClient->theEventHandler->started();
        }
      } else if ( dynamic_cast< ResumedEvent * > ( lMessage.get() ) ) {
        lClient->theExecutionStatus = QUERY_RUNNING;
        if ( lClient->theEventHandler )
        {
          lClient->theEventHandler->resumed();
        }
      } else if ( dynamic_cast< TerminatedEvent * > ( lMessage.get() ) ) {
        if( lClient->theExecutionStatus != QUERY_IDLE )
        {
          lClient->theExecutionStatus = QUERY_TERMINATED;
          if ( lClient->theEventHandler )
          {
            lClient->theEventHandler->terminated();
          }
          lClient->theRequestSocket->send("quit", 5);
        }
      } else if ( (lEvaluatedEvent = dynamic_cast< EvaluatedEvent * >( lMessage.get() ))) {
        if ( lClient->theEventHandler )
        {
          String lExpr( lEvaluatedEvent->getExpr() );
          String lError( lEvaluatedEvent->getError() );
          if(lError.length() > 0)
          {
            lClient->theEventHandler->evaluated(lExpr, lError);
          } else {
            list<pair<String, String> > lValuesAndTypes;
            list< pair<xqpString, xqpString> > lMap = lEvaluatedEvent->getValuesAndTypes();
            list< pair<xqpString, xqpString> >::const_iterator it;
            for(it=lMap.begin(); it!=lMap.end(); ++it )
            {
              xqpString test(it->first);
              xqpString filter = test.replace("&quot;", "\"", "");
              String lResult(filter);
              String lType(it->second);
              lValuesAndTypes.push_back(std::make_pair(lResult, lType));
            }
            lClient->theEventHandler->evaluated(lExpr, lValuesAndTypes);
          }
        }
      }
    }
  } catch(std::exception&) {
    //do nothing...
  }
  return 0;
}

bool ZorbaDebuggerClientImpl::isQueryRunning() const
{
  return theExecutionStatus == QUERY_RUNNING;
}

bool ZorbaDebuggerClientImpl::isQueryIdle() const
{
  return theExecutionStatus == QUERY_IDLE;
}

bool ZorbaDebuggerClientImpl::isQuerySuspended() const
{
  return theExecutionStatus == QUERY_SUSPENDED;
}

bool ZorbaDebuggerClientImpl::isQueryTerminated() const
{
  return theExecutionStatus == QUERY_TERMINATED;
}

ReplyMessage *ZorbaDebuggerClientImpl::send( AbstractCommandMessage * aMessage ) const
{
  //Connect the client
  Length length;
  ZorbaArrayAutoPointer<Byte> lMessage(aMessage->serialize( length ));
  try
  {
    //send the command
    theRequestSocket->send( lMessage.get(), length );
    //check the reply
    AbstractMessage* lMsg = MessageFactory::buildMessage( theRequestSocket.get() );
	std::auto_ptr<ReplyMessage> lReplyMessage(dynamic_cast< ReplyMessage * >( lMsg ));
    if ( lReplyMessage.get() )
    {
      return lReplyMessage.release();
    } else {
    //TODO: print the error message.
      synchronous_logger::cerr << "Internal error occured\n";
    }
  } catch( DebuggerSocketException &e ) {
    synchronous_logger::cerr << "Request client:" << e.what() << "\n";
  }
  return 0;
}

bool ZorbaDebuggerClientImpl::run()
{
  RunMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  //TODO: check reply message
  return true;
}

bool ZorbaDebuggerClientImpl::suspend()
{
  SuspendMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::resume()
{
  ResumeMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::terminate()
{
  TerminateMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::stepInto()
{
  StepMessage lMessage( STEP_INTO );
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::stepOver()
{
  StepMessage lMessage( STEP_OVER );
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::stepOut()
{
  StepMessage lMessage( STEP_OUT );
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::addBreakpoint( const String &anExpr )
{
  xqpString lExpr = Unmarshaller::getInternalString( anExpr );
  SetMessage lMessage;
  theLastId++;
  lMessage.addExpr( theLastId, lExpr );
  theBreakpoints.insert( std::make_pair( theLastId, lExpr ) );
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage )); 
  return true;
}


QueryLocation_t ZorbaDebuggerClientImpl::addBreakpoint( const unsigned int aLineNo )
{
  QueryLoc loc;
  loc.setLineBegin( aLineNo );
  theLastId++;
  QueryLocation* lLocation = addBreakpoint(loc);
  std::stringstream lB;
  lB << lLocation;
  theBreakpoints.insert( std::make_pair( theLastId, lB.str() ) );
  return lLocation;
}

QueryLocation_t ZorbaDebuggerClientImpl::addBreakpoint( const String &aFileName, const unsigned int aLineNo )
{
  xqpString lFilename = Unmarshaller::getInternalString( aFileName );
  QueryLoc loc;
  std::string lTmp(lFilename);
  loc.setFilenameBegin( &lTmp );
  loc.setLineBegin( aLineNo );
  theLastId++;
  QueryLocation_t lLocation = addBreakpoint(loc);
  std::stringstream lB;
  lB << lLocation;
  theBreakpoints.insert( std::make_pair( theLastId, lB.str() ) );
  return lLocation;
}

QueryLocation_t ZorbaDebuggerClientImpl::addBreakpoint(QueryLoc& aLocation)
{
  SetMessage lMessage;
  lMessage.addLocation( theLastId, aLocation );
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  SetReply* lSetReply = dynamic_cast<SetReply*>(lReply.get());
  if(lSetReply)
  {
    std::map<unsigned int, QueryLoc> breakpoints = lSetReply->getBreakpoints();
    std::map<unsigned int, QueryLoc>::iterator it;
    for(it = breakpoints.begin(); it != breakpoints.end(); ++it)
    {
      QueryLocation_t location(new QueryLocationImpl(it->second));
      return location;
    }
  } else {
    synchronous_logger::cerr << "An error occured\n";
  }
  return 0;  
}

bool ZorbaDebuggerClientImpl::clearBreakpoint( unsigned int anId )
{
  ClearMessage lMessage;
  lMessage.addId( anId );
  if ( theBreakpoints.find( anId ) != theBreakpoints.end() )
  {
    theBreakpoints.erase( theBreakpoints.find( anId ) );
  } else {
    return false;
  }
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::clearBreakpoints( std::list<unsigned int> &Ids )
{
  ClearMessage lMessage;
  std::list<unsigned int>::const_iterator it;
  for ( it = Ids.begin(); it != Ids.end(); it++)
  {
    lMessage.addId( *it );
    theBreakpoints.erase( theBreakpoints.find( *it ) );
  }
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

bool ZorbaDebuggerClientImpl::clearBreakpoints()
{
  ClearMessage lMessage;
  std::map<unsigned int, String>::iterator it;
  for ( it = theBreakpoints.begin(); it != theBreakpoints.end(); it++ )
  {
    lMessage.addId( it->first );
  }
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  theBreakpoints.clear();
  return true;
}

std::map<unsigned int, String> ZorbaDebuggerClientImpl::getBreakpoints() const
{
  return theBreakpoints;
}

QueryLocation_t ZorbaDebuggerClientImpl::getLocation() const
{
  return new QueryLocationImpl( theRemoteLocation );
}

bool ZorbaDebuggerClientImpl::eval( String &anExpr ) const
{
  xqpString lExpr = Unmarshaller::getInternalString( anExpr );
  xqpString expr = lExpr.replace("\"", "&quot;", "");
  EvalMessage lMessage( expr );
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  return true;
}

std::list<Variable> ZorbaDebuggerClientImpl::getAllVariables() const
{
  std::list<Variable> lVariables;
  VariableMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  VariableReply *lVariableReply = dynamic_cast<VariableReply *>( lReply.get() );
  if ( lVariableReply )
  {
    std::map<xqpString, xqpString> variables = lVariableReply->getVariables();
    std::map<xqpString, xqpString>::iterator it;
    for ( it = variables.begin(); it != variables.end(); ++it )
    {
      String lName( it->first );
      String lType( it->second );
      Variable lVariable( lName, lType );
      lVariables.push_back( lVariable );
    }
  }
  return lVariables;
}

std::list<Variable> ZorbaDebuggerClientImpl::getLocalVariables() const
{
  std::list<Variable> lVariables;
  VariableMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  VariableReply *lVariableReply = dynamic_cast<VariableReply *>( lReply.get() );
  if ( lVariableReply )
  {
    std::map<xqpString, xqpString> variables = lVariableReply->getLocalVariables();
    std::map<xqpString, xqpString>::iterator it;
    for ( it = variables.begin(); it != variables.end(); ++it )
    {
      String lName( it->first );
      String lType( it->second );
      Variable lVariable( lName, lType );
      lVariables.push_back( lVariable );
    }
  }
  return lVariables;
}

std::list<Variable> ZorbaDebuggerClientImpl::getGlobalVariables() const
{
  std::list<Variable> lVariables;
  VariableMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send( &lMessage ));
  VariableReply *lVariableReply = dynamic_cast<VariableReply *>( lReply.get() );
  if ( lVariableReply )
  {
    std::map<xqpString, xqpString> variables = lVariableReply->getGlobalVariables();
    std::map<xqpString, xqpString>::iterator it;
    for ( it = variables.begin(); it != variables.end(); ++it )
    {
      String lName( it->first );
      String lType( it->second );
      Variable lVariable( lName, lType );
      lVariables.push_back( lVariable );
    }
  }
  return lVariables;
}

StackFrame_t ZorbaDebuggerClientImpl::getStack() const
{
  auto_ptr<StackFrameImpl> lStack(new StackFrameImpl());
  FrameMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send(&lMessage));
  FrameReply* lFrameReply = dynamic_cast<FrameReply*>(lReply.get());
  if(lFrameReply)
  {
    std::stack< std::pair<std::string, QueryLoc> > stack = lFrameReply->getStack();
    while(!stack.empty())
    {
      lStack->push(stack.top().first, new QueryLocationImpl(stack.top().second));
      stack.pop();
    }
  }
  StackFrame_t lReturnStack = lStack.get();
  lStack.release();
  return lReturnStack;
}
}//end of namespace
