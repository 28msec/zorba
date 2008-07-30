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
  zorba::TestDebuggerSerialization * test = new zorba::TestDebuggerSerialization();
  test->testReplyMessage();
  test->testReplyMessageOk();
  test->testRunMessage();
  test->testSuspendMessage();
  test->testResumeMessage();
  test->testTerminateMessage();
  test->testQuitMessage();
  test->testStepIntoMessage();
  test->testStepOutMessage();
  test->testStepOverMessage();
  test->testStartedEvent();
  test->testTerminatedEvent();
  test->testSuspendedEvent();
  test->testResumedEvent();
  test->testClearMessage();
  test->testSetMessage();
  test->testEvalMessage();
  test->testEvaluatedEvent();
  test->testVariableMessage();
  delete test;
  return 0;
}

namespace zorba{

template<class T>
void test_packet( AbstractMessage * aMessage ) 
{
  //Cast to the concrete Message Type
  T * lMessage1 = dynamic_cast<T *> ( aMessage );
  //Ensure that the cast is correct
  assert( lMessage1 != 0 );
  //Serialize and unserialize the message
  Length length;
  Byte * msg = lMessage1->serialize( length );
  AbstractMessage * lAbstractMessage = MessageFactory::buildMessage( msg, length );
  delete[] msg;
  T * lMessage2 = dynamic_cast<T *> ( lAbstractMessage );
  assert( lMessage2 != 0 );
  //Ensure that both message are identical
  bool lResult = (*lMessage1) == (*lMessage2);
  assert(lResult);
  delete lAbstractMessage;
}

  bool msgcmp( Byte * aMsg1, const char * aMsg2, unsigned int aLength )
  {
    
    Byte * lMsg2 = reinterpret_cast<Byte *>( const_cast< char * >( aMsg2 ) );
    return memcmp( aMsg1, lMsg2, aLength ) == 0;
  }

  void TestDebuggerSerialization::testReplyMessage()
  {
    std::cerr << "Test reply message" << std::endl;
    ReplyMessage msg( 1, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT );
    test_packet<ReplyMessage>( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\1\200\0\xb";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testReplyMessageOk()
  {
    std::cerr << "Test reply message Ok" << std::endl;
    ReplyMessage msg( 1, DEBUGGER_NO_ERROR );
    test_packet<ReplyMessage>( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\1\200\0\0";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

void TestDebuggerSerialization::testRunMessage()
  {
    std::cerr << "Test run message" << std::endl;
    RunMessage msg;
    test_packet<RunMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\1\0\xf1\1";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testSuspendMessage()
  {
    std::cerr << "Test suspend message" << std::endl;
    SuspendMessage msg;
    test_packet<SuspendMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\2\0\xf1\2"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testResumeMessage()
  {
    std::cerr << "Test resume message" << std::endl;
    ResumeMessage msg;
    test_packet<ResumeMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\3\0\xf1\3"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testTerminateMessage()
  {
    std::cerr << "Test terminate message" << std::endl;
    TerminateMessage msg;
    test_packet<TerminateMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\4\0\xf1\4"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testQuitMessage()
  {
    std::cerr << "Test quit message" << std::endl;
    QuitMessage msg;
    test_packet<QuitMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\5\0\xf1\6"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepIntoMessage()
  {
    std::cerr << "Test step into message" << std::endl;
    StepMessage msg( STEP_INTO );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\6\0\xf1\5\1"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepOutMessage()
  {
    std::cerr << "Test step out message" << std::endl;
    StepMessage msg( STEP_OUT );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\7\0\xf1\5\2"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepOverMessage()
  {
    std::cerr << "Test step over message" << std::endl;
    StepMessage msg( STEP_OVER );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\x8\0\xf1\5\3"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStartedEvent()
  {
    std::cerr << "Test started event message" << std::endl;
    StartedEvent msg;
    test_packet< StartedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\x9\0\xf8\1";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }
  
  void TestDebuggerSerialization::testTerminatedEvent()
  {
    std::cerr << "Test terminated event message" << std::endl;
    TerminatedEvent msg;
    test_packet< TerminatedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\xa\0\xf8\2";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testSuspendedEvent()
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
    test_packet< SuspendedEvent >( &msg );
    
    Length length;
    
    Byte * lBmsg = msg.serialize( length );
    
    char * lBinary = new char[length];
    memcpy( lBinary, "\0\0\0\x070\0\0\0\xb\0\xf8\3", MESSAGE_SIZE );
    const char * lJSONString = "{\"cause\":1,\"location\":{\"fileName\":\"data.xq\",\"lineBegin\":1,\"columnBegin\":1,\"lineEnd\":1,\"columnEnd\":1}}";
    memcpy( lBinary + MESSAGE_SIZE, lJSONString, length - MESSAGE_SIZE );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
    delete[] lBinary;
  }

  void TestDebuggerSerialization::testResumedEvent()
  {
    std::cerr << "Test resumed event message" << std::endl;
    ResumedEvent msg;
    test_packet< ResumedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\xc\0\xf8\4";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    bool lMsgcmp = msgcmp( lBmsg, lBinary, length );
    assert( lMsgcmp );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testClearMessage()
  {
    std::cerr << "Test clear message" << std::endl;
    ClearMessage msg;
    msg.addId( 1 );
    msg.addId( 2 );
    msg.addId( 3 );
    msg.addId( 4 );
    test_packet< ClearMessage >( &msg );
  }
  
  void TestDebuggerSerialization::testSetMessage()
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
    test_packet< SetMessage >( &msg );
  }

  void TestDebuggerSerialization::testEvalMessage()
  {
    std::cerr << "Test eval message" << std::endl;
    
    EvalMessage msg( "$i/foo" );
    test_packet< EvalMessage >( &msg );
  }

  void TestDebuggerSerialization::testEvaluatedEvent()
  {
    std::cerr << "Test evaluated event" << std::endl;
    {    
      EvaluatedEvent msg( "$i", "4", "xs:integer" );
      test_packet< EvaluatedEvent >( &msg );
    }
    {    
      EvaluatedEvent msg( xqpString("$i"), xqpString("Error!") );
      test_packet< EvaluatedEvent >( &msg );
    }
  }

  void TestDebuggerSerialization::testVariableMessage()
  {
    std::cerr << "Test variable message" << std::endl;
    {
      VariableMessage msg;
      test_packet<VariableMessage>( &msg );
    }
    {
      VariableReply msg( 1, DEBUGGER_NO_ERROR );
      msg.addGlobal( "$i", "xs:integer" );
      msg.addGlobal( "$j", "xs:integer" );
      msg.addLocal("$foo", "xs:string" );
      msg.addLocal("$bar", "xs:string" );
      test_packet< VariableReply >( &msg );
    }
  }
}

