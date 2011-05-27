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

#include "diagnostics/assert.h"
#include "zorbautils/synchronous_logger.h"

#include "api/unmarshaller.h"

#include "util/ascii_util.h"
#include "util/stl_util.h"

#include "debugger/debugger_event_listener.h"
#include "debugger/query_locationimpl.h"
#include "debugger/socket.h"
#include "debugger/message_factory.h"
#include "debugger/stackimpl.h"


#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

using namespace std;

namespace zorba {

unsigned int DebuggerClientImpl::theLastId = 0;

DebuggerClientImpl::DebuggerClientImpl(std::string aServerAddress, unsigned short aRequestPortno, unsigned short aEventPortno)
 : theEventHandler(0),
   theRequestSocket(0),
   theEventServerSocket(0),
   theExecutionStatus(QUERY_IDLE),
   theEventListener(0)	
{
	try {
		do {
			theRequestSocket.reset(new TCPSocket(aServerAddress, aRequestPortno));
			theEventServerSocket.reset(new TCPServerSocket(aEventPortno));
			//Perform the handshake with the server
		} while (!handshake());
		//Start the event listener thread
		theEventListener = new DebuggerEventListener(this);
    theEventListener->start();
	} catch(DebuggerSocketException& /* e */) {
		throw;
  }
}

DebuggerClientImpl::~DebuggerClientImpl()
{
  theEventListener->closeSocket();
  theEventListener->join();
  delete theEventListener;
}

ExecutionStatus
DebuggerClientImpl::getExecutionStatus() const
{
  AutoLock lLock(theExecutionStatusLock, Lock::READ);
  return theExecutionStatus;
}

void
DebuggerClientImpl::setExecutionStatus(const ExecutionStatus& e)
{
  AutoLock lLock(theExecutionStatusLock, Lock::WRITE);
  theExecutionStatus = e;
}

DebuggerClient*
DebuggerClientImpl::registerEventHandler(DebuggerEventHandler* anEventHandler)
{
  theEventHandler = anEventHandler;
  //Special case for event handler initialization
  if (theEventHandler != 0 && getExecutionStatus() == QUERY_IDLE) {
    theEventHandler->idle();
  }
  return this;
}

bool
DebuggerClientImpl::handshake()
{
  bool result = false;
  ztd::auto_vec<char> msg(new char[ 12 ]);
  memset(msg.get(), '\0', 12);
  try {
    theRequestSocket->send("XQHandshake", 11);
    theRequestSocket->recv(msg.get(), 11);
    result = strcmp(msg.get(), "XQHandshake") == 0; 
    if (result) {
      return true;
    }
  } catch (DebuggerSocketException&) {
    //do nothing...
  }
  return false;
}

bool
DebuggerClientImpl::isQueryRunning() const
{
  AutoLock lLock(theExecutionStatusLock, Lock::READ);
  return theExecutionStatus == QUERY_RUNNING;
}

bool
DebuggerClientImpl::isQueryIdle() const
{
  AutoLock lLock(theExecutionStatusLock, Lock::READ);
  return theExecutionStatus == QUERY_IDLE;
}

bool
DebuggerClientImpl::isQuerySuspended() const
{
  AutoLock lLock(theExecutionStatusLock, Lock::READ);
  return theExecutionStatus == QUERY_SUSPENDED;
}

bool
DebuggerClientImpl::isQueryTerminated() const
{
  AutoLock lLock(theExecutionStatusLock, Lock::READ);
  return theExecutionStatus == QUERY_TERMINATED;
}

ReplyMessage*
DebuggerClientImpl::send(AbstractCommandMessage* aMessage) const
{
  //Connect the client
  Length length;
  ztd::auto_vec<Byte> lMessage(aMessage->serialize(length));
  try {
    //send the command
    theRequestSocket->send(lMessage.get(), length);
    //check the reply
    AbstractMessage* lMsg = MessageFactory::buildMessage(theRequestSocket.get());
    std::auto_ptr<ReplyMessage> lReplyMessage(dynamic_cast<ReplyMessage*>(lMsg));
    if (lReplyMessage.get()) {
      return lReplyMessage.release();
    } 
  } catch(DebuggerSocketException& e) {
    std::stringstream lSs; lSs << "Request client:" << e.what() << "\n";
    zorba::cerr << lSs.str();
  }
  return 0;
}

bool
DebuggerClientImpl::run()
{
  RunMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::suspend()
{
  SuspendMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::resume()
{
  ResumeMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::terminate()
{
  TerminateMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

void
DebuggerClientImpl::detach()
{
  DetachMessage lMessage;
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
}

bool
DebuggerClientImpl::stepInto()
{
  StepMessage lMessage(STEP_INTO);
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::stepOver()
{
  StepMessage lMessage(STEP_OVER);
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::stepOut()
{
  StepMessage lMessage(STEP_OUT);
  //TODO: check reply message
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::addBreakpoint(const String& anExpr)
{
  zstring const &lExpr = Unmarshaller::getInternalString( anExpr );
  SetMessage lMessage;
  theLastId++;
  zstring temp( lExpr.c_str() );
  lMessage.addExpr( theLastId, temp );
  theBreakpoints.insert( std::make_pair( theLastId, anExpr ) );

  std::auto_ptr<ReplyMessage> lReply(send((&lMessage))); 
  return true;
}


QueryLocation_t
DebuggerClientImpl::addBreakpoint(const unsigned int aLineNo)
{
  QueryLoc loc;
  loc.setLineBegin(aLineNo);
  theLastId++;
  QueryLocation* lLocation = addBreakpoint(loc);
  std::stringstream lB;
  lB << lLocation;
  theBreakpoints.insert(std::make_pair(theLastId, lB.str()));
  return lLocation;
}

QueryLocation_t
DebuggerClientImpl::addBreakpoint(const String& aFileName, const unsigned int aLineNo)
{
  zstring const &lFilename = Unmarshaller::getInternalString(aFileName);
  QueryLoc loc;
  loc.setFilename(lFilename);
  loc.setLineBegin(aLineNo);
  theLastId++;
  QueryLocation_t lLocation = addBreakpoint(loc);
	if (lLocation->getLineBegin() == 0) {
    theLastId--;
    return 0;
  }
  std::stringstream lB;
  lB << lLocation;
  theBreakpoints.insert(std::make_pair(theLastId, lB.str()));
  return lLocation;
}

QueryLocation_t
DebuggerClientImpl::addBreakpoint(QueryLoc& aLocation)
{
  SetMessage lMessage;
  lMessage.addLocation(theLastId, aLocation);
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  SetReply* lSetReply = dynamic_cast<SetReply*>(lReply.get());
  if (lSetReply) {
    std::map<unsigned int, QueryLoc> breakpoints = lSetReply->getBreakpoints();
    std::map<unsigned int, QueryLoc>::iterator it;
    for (it = breakpoints.begin(); it != breakpoints.end(); ++it) {
      QueryLocation_t location(new QueryLocationImpl(it->second));
      return location;
    }
  } else {
    std::stringstream lSs; lSs << "An error occured\n";
    zorba::cerr << lSs.str();
  }
  return 0;  
}

bool
DebuggerClientImpl::clearBreakpoint(unsigned int anId)
{
  ClearMessage lMessage;
  lMessage.addId(anId);
  if (theBreakpoints.find(anId) != theBreakpoints.end()) {
    theBreakpoints.erase(theBreakpoints.find(anId));
  } else {
    return false;
  }
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::clearBreakpoint(const String& aFileName, unsigned int aLineNo)
{
  ClearMessage lMessage;
  std::stringstream lB;
  lB << aFileName << ":" << aLineNo;
  std::map<unsigned int, String>::const_iterator lIter;

  std::vector<unsigned int> lToRemove;
  for (lIter = theBreakpoints.begin(); lIter != theBreakpoints.end(); lIter++) {
    if (ascii::begins_with( lIter->second, lB.str() )) {
      lMessage.addId(lIter->first);
      lToRemove.push_back(lIter->first);
    }
  }
  size_t lNoBrks = lToRemove.size();
  for (size_t i = 0; i < lNoBrks; i++) {
    theBreakpoints.erase(lToRemove[i]);
  }
  if (lNoBrks > 0) {
    std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  }
  return true;
}

bool
DebuggerClientImpl::clearBreakpoints(std::list<unsigned int>& Ids)
{
  ClearMessage lMessage;
  std::list<unsigned int>::const_iterator it;
  for (it = Ids.begin(); it != Ids.end(); it++) {
    lMessage.addId(*it);
    theBreakpoints.erase(theBreakpoints.find(*it));
  }
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

bool
DebuggerClientImpl::clearBreakpoints()
{
  ClearMessage lMessage;
  std::map<unsigned int, String>::iterator it;
  for (it = theBreakpoints.begin(); it != theBreakpoints.end(); it++) {
    lMessage.addId(it->first);
  }
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  theBreakpoints.clear();
  return true;
}

std::map<unsigned int, String>
DebuggerClientImpl::getBreakpoints() const
{
  return theBreakpoints;
}

QueryLocation_t
DebuggerClientImpl::getLocation() const
{
  return new QueryLocationImpl(theRemoteLocation);
}

bool
DebuggerClientImpl::eval(String& anExpr) const
{
  zstring lExpr = Unmarshaller::getInternalString( anExpr );
  ascii::replace_all( lExpr, "\"", "&quot;" );
  zstring temp( lExpr.c_str() );
  EvalMessage lMessage( temp );
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  return true;
}

std::list<Variable>
DebuggerClientImpl::getAllVariables(bool data) const
{
  std::list<Variable> lVariables;
  VariableMessage lMessage(data);
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  VariableReply* lVariableReply = dynamic_cast<VariableReply*>(lReply.get());
  if (lVariableReply) {
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > variables = 
      lVariableReply->getVariables();
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >::iterator it;
    for (it = variables.begin(); it != variables.end(); ++it) {
      String lName( Unmarshaller::newString( it->first.first ) );
      String lType( Unmarshaller::newString( it->first.second ) );
      std::list<std::pair<zstring, zstring> > d = it->second;
      std::list<std::pair<String, String> > data;
      for (std::list<std::pair<zstring, zstring> >::iterator iter = d.begin(); iter != d.end(); iter++) {
        data.push_back(
          std::pair<String,String>(
            Unmarshaller::newString(iter->first),
            Unmarshaller::newString(iter->second)
          )
        );
      }
      Variable lVariable(lName, lType, data);
      lVariables.push_back(lVariable);
    }
  }
  return lVariables;
}

std::list<Variable>
DebuggerClientImpl::getLocalVariables(bool data) const
{
  std::list<Variable> lVariables;
  VariableMessage lMessage(data);
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  VariableReply* lVariableReply = dynamic_cast<VariableReply*>(lReply.get());
  if (lVariableReply) {
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > variables = 
      lVariableReply->getLocalVariables();
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >::iterator it;
    for (it = variables.begin(); it != variables.end(); ++it) {
      String lName( Unmarshaller::newString( it->first.first ) );
      String lType( Unmarshaller::newString( it->first.second ) );
      std::list<std::pair<zstring, zstring> > d = it->second;
      std::list<std::pair<String, String> > data;
      for (std::list<std::pair<zstring, zstring> >::iterator iter = d.begin(); iter != d.end(); iter++) {
        data.push_back(
          std::pair<String,String>(
            Unmarshaller::newString(iter->first),
            Unmarshaller::newString(iter->second)
          )
        );
      }
      Variable lVariable(lName, lType, data);
      lVariables.push_back(lVariable);
    }
  }
  return lVariables;
}

std::list<Variable>
DebuggerClientImpl::getGlobalVariables(bool data) const
{
  std::list<Variable> lVariables;
  if (theExecutionStatus != QUERY_SUSPENDED) {
    //throw std::exception("Query not suspended");
  }
  VariableMessage lMessage(data);
  std::auto_ptr<ReplyMessage> lReply(send((&lMessage)));
  VariableReply* lVariableReply = dynamic_cast<VariableReply*>(lReply.get());
  if (lVariableReply) {
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > > variables = 
      lVariableReply->getGlobalVariables();
    std::map<std::pair<zstring, zstring>, std::list<std::pair<zstring, zstring> > >::iterator it;
    for (it = variables.begin(); it != variables.end(); ++it) {
      String lName( Unmarshaller::newString( it->first.first ) );
      String lType( Unmarshaller::newString( it->first.second ) );
      std::list<std::pair<zstring, zstring> > d = it->second;
      std::list<std::pair<String, String> > data;
      for (std::list<std::pair<zstring, zstring> >::iterator iter = d.begin(); iter != d.end(); iter++) {
        data.push_back(
          std::pair<String,String>(
            Unmarshaller::newString(iter->first),
            Unmarshaller::newString(iter->second))
        );
      }
      Variable lVariable(lName, lType, data);
      lVariables.push_back(lVariable);
    }
  }
  return lVariables;
}

StackFrame_t
DebuggerClientImpl::getStack() const
{
  auto_ptr<StackFrameImpl> lStack(new StackFrameImpl());
  FrameMessage lMessage;
  std::auto_ptr<ReplyMessage> lReply(send(&lMessage));
  FrameReply* lFrameReply = dynamic_cast<FrameReply*>(lReply.get());
  if (lFrameReply) {
    std::stack< std::pair<std::string, QueryLoc> > stack = lFrameReply->getStack();
    while (!stack.empty()) {
      lStack->push(stack.top().first, new QueryLocationImpl(stack.top().second));
      stack.pop();
    }
  }
  StackFrame_t lReturnStack = lStack.get();
  lStack.release();
  return lReturnStack;
}

std::string
DebuggerClientImpl::listSource(
  const std::string& aUri,
  unsigned long aFirstline /*= 0*/,
  unsigned long aLastName /*= 0*/) const
{
  std::auto_ptr<ReplyMessage> lReply;
  std::auto_ptr<ListCommand> lCommand(
    new ListCommand(aUri, aFirstline, aLastName));
  lReply.reset(send(lCommand.get()));

  ZORBA_ASSERT(dynamic_cast<ListReply*>(lReply.get()));
  ListReply* lListReply = static_cast<ListReply*>(lReply.get());
  return lListReply->getString();
}

} //end of namespace
/* vim:set et sw=2 ts=2: */
