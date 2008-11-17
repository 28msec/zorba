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
#include <zorba/zorba.h>
#include <simplestore/simplestore.h>

#include "test_debugger_protocol.h"

using namespace zorba;

int test_debugger_protocol( int argc, char* argv[] )
{
  bool lResult;
  zorba::TestDebuggerSerialization * test = new zorba::TestDebuggerSerialization();
  lResult = test->testReplyMessage();
  if(!lResult) return 1;
  lResult = test->testReplyMessageOk();
  if(!lResult) return 1;
  lResult = test->testRunMessage();
  if(!lResult) return 1;
  lResult = test->testSuspendMessage();
  if(!lResult) return 1;
  lResult = test->testResumeMessage();
  if(!lResult) return 1;
  lResult = test->testTerminateMessage();
  if(!lResult) return 1;
  lResult = test->testStepIntoMessage();
  if(!lResult) return 1;
  lResult = test->testStepOutMessage();
  if(!lResult) return 1;
  lResult = test->testStepOverMessage();
  if(!lResult) return 1;
  lResult = test->testStartedEvent();
  if(!lResult) return 1;
  lResult = test->testTerminatedEvent();
  if(!lResult) return 1;
  lResult = test->testSuspendedEvent();
  if(!lResult) return 1;
  lResult = test->testResumedEvent();
  if(!lResult) return 1;
  lResult = test->testClearMessage();
  if(!lResult) return 1;
  lResult = test->testSetMessage();
  if(!lResult) return 1;
  lResult = test->testEvalMessage();
  if(!lResult) return 1;
  lResult = test->testVariableMessage();
  if(!lResult) return 1;
  delete test;
  return 0;
}

namespace zorba{

template<class T>
bool test_packet( AbstractMessage * aMessage ) 
{
  //Cast to the concrete Message Type
  T * lMessage1 = dynamic_cast<T *> ( aMessage );
  //Ensure that the cast is correct
  if(lMessage1 == 0){ return false; }
  //Serialize and unserialize the message
  Length length;
  Byte * msg = lMessage1->serialize( length );
  AbstractMessage * lAbstractMessage = MessageFactory::buildMessage( msg, length );
  delete[] msg;
  T * lMessage2 = dynamic_cast<T *> ( lAbstractMessage );
  if(lMessage2 == 0){ return false; }
  //Ensure that both message are identical
  bool lResult = (*lMessage1) == (*lMessage2);
  if(lResult == 0){ return false; }
  delete lAbstractMessage;
  return true;
}

  bool msgcmp( Byte * aMsg1, const char * aMsg2, unsigned int aLength )
  {
    
    Byte * lMsg2 = reinterpret_cast<Byte *>( const_cast< char * >( aMsg2 ) );
    return memcmp( aMsg1, lMsg2, aLength ) == 0;
  }

  bool TestDebuggerSerialization::testReplyMessage()
  {
    std::cerr << "Test reply message" << std::endl;
    ReplyMessage msg( 1, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary = "\0\0\0\xb\0\0\0\1\200\0\xb";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testReplyMessageOk()
  {
    std::cerr << "Test reply message Ok" << std::endl;
    ReplyMessage msg( 1, DEBUGGER_NO_ERROR );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    test_packet<ReplyMessage>( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\1\200\0\0";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testRunMessage()
  {
    std::cerr << "Test run message" << std::endl;
    RunMessage msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    test_packet<RunMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\1\0\xf1\1";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testSuspendMessage()
  {
    std::cerr << "Test suspend message" << std::endl;
    SuspendMessage msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xb\0\0\0\2\0\xf1\2"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testResumeMessage()
  {
    std::cerr << "Test resume message" << std::endl;
    ResumeMessage msg;
    bool lResult = test_packet<ReplyMessage>(&msg);
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xb\0\0\0\3\0\xf1\3"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testTerminateMessage()
  {
    std::cerr << "Test terminate message" << std::endl;
    TerminateMessage msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xb\0\0\0\4\0\xf1\4"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp(lBmsg.get(), lBinary, length);
  }

  bool TestDebuggerSerialization::testStepIntoMessage()
  {
    std::cerr << "Test step into message" << std::endl;
    StepMessage msg( STEP_INTO );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xc\0\0\0\5\0\xf1\5\1"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testStepOutMessage()
  {
    std::cerr << "Test step out message" << std::endl;
    StepMessage msg( STEP_OUT );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xc\0\0\0\6\0\xf1\5\2"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testStepOverMessage()
  {
    std::cerr << "Test step over message" << std::endl;
    StepMessage msg( STEP_OVER );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary =  "\0\0\0\xc\0\0\0\7\0\xf1\5\3"; 
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize( length ));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testStartedEvent()
  {
    std::cerr << "Test started event message" << std::endl;
    StartedEvent msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary = "\0\0\0\xb\0\0\0\x8\0\xf8\1";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }
  
  bool TestDebuggerSerialization::testTerminatedEvent()
  {
    std::cerr << "Test terminated event message" << std::endl;
    TerminatedEvent msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary = "\0\0\0\xb\0\0\0\x9\0\xf8\2";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testSuspendedEvent()
  {
    std::cerr << "Test suspended event message" << std::endl;
    
    QueryLoc loc;
    std::string lFilename( "data.xq" );
    loc.setFilenameBegin( &lFilename );
    loc.setLineBegin( 1 );
    loc.setColumnBegin( 1 );
    loc.setLineEnd( 1 );
    loc.setColumnEnd( 1 );
    
    SuspendedEvent msg( loc, CAUSE_USER );
    bool lResult =test_packet< SuspendedEvent >( &msg );
    if(!lResult) return false;

    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    ZorbaArrayAutoPointer<char> lBinary(new char[length]);
    memcpy( lBinary.get(), "\0\0\0\x070\0\0\0\xa\0\xf8\3", MESSAGE_SIZE );
    const char * lJSONString = "{\"cause\":1,\"location\":{\"fileName\":\"data.xq\",\"lineBegin\":1,\"columnBegin\":1,\"lineEnd\":1,\"columnEnd\":1}}";
    memcpy( lBinary.get() + MESSAGE_SIZE, lJSONString, length - MESSAGE_SIZE );
    return  msgcmp( lBmsg.get(), lBinary.get(), length );
  }

  bool TestDebuggerSerialization::testResumedEvent()
  {
    std::cerr << "Test resumed event message" << std::endl;
    ResumedEvent msg;
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    const char * lBinary = "\0\0\0\xb\0\0\0\xb\0\xf8\4";
    Length length;
    ZorbaArrayAutoPointer<Byte> lBmsg(msg.serialize(length));
    return msgcmp( lBmsg.get(), lBinary, length );
  }

  bool TestDebuggerSerialization::testClearMessage()
  {
    std::cerr << "Test clear message" << std::endl;
    ClearMessage msg;
    msg.addId( 1 );
    msg.addId( 2 );
    msg.addId( 3 );
    msg.addId( 4 );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    return true;
  }
  
  bool TestDebuggerSerialization::testSetMessage()
  {
    std::cerr << "Test set message" << std::endl;
    QueryLoc loc;
    std::string lFilename( "data.xq" );
    loc.setFilenameBegin( &lFilename );
    loc.setLineBegin( 1 );
    loc.setColumnBegin( 1 );
    loc.setLineEnd( 1 );
    loc.setColumnEnd( 1 );
    SetMessage msg;
    msg.addLocation( 1, loc );
    xqpString lExpr("$i=1");
    msg.addExpr( 2, lExpr);
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    return true;
  }

  bool TestDebuggerSerialization::testEvalMessage()
  {
    std::cerr << "Test eval message" << std::endl;
    EvalMessage msg( "$i/foo" );
    bool lResult = test_packet<ReplyMessage>( &msg );
    if(!lResult) return false;
    return true;
  }

  bool TestDebuggerSerialization::testVariableMessage()
  {
    std::cerr << "Test variable message" << std::endl;
    {
      VariableMessage msg;
      bool lResult = test_packet<ReplyMessage>( &msg );
      if(!lResult) return false;
    }
    {
      VariableReply msg( 1, DEBUGGER_NO_ERROR );
      msg.addGlobal( "$i", "xs:integer" );
      msg.addGlobal( "$j", "xs:integer" );
      msg.addLocal("$foo", "xs:string" );
      msg.addLocal("$bar", "xs:string" );
      bool lResult = test_packet<ReplyMessage>( &msg );
      if(!lResult) return false;
    }
    return true;
  }
}

