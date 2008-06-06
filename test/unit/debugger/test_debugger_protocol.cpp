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
#include <store/naive/simple_store.h>

#include "test_debugger_protocol.h"

using namespace zorba;

int test_debugger_protocol( int argc, char* argv[] )
{
  zorba::TestDebuggerSerialization * test = new zorba::TestDebuggerSerialization();
  test->testRunMessage();
  test->testSuspendMessage();
  test->testResumeMessage();
  test->testTerminateMessage();
  test->testStepIntoMessage();
  test->testStepOutMessage();
  test->testStepOverMessage();
  test->testStartedEvent();
  test->testTerminatedEvent();
  test->testSuspendedEvent();
  test->testResumedEvent();
  test->testClearMessage();
  test->testSetMessage();
  test->testVariableMessage();
  delete test;
  return 0;
}

namespace zorba{

template<class T>
void test_packet( AbstractCommandMessage * aMessage ) 
{
  //Cast to the concrete Message Type
  T * lMessage1 = dynamic_cast<T *> ( aMessage );
  //Ensure that the cast is correct
  assert( lMessage1 != NULL);
  //Serialize and unserialize the message
  Length length;
  Byte * msg = lMessage1->serialize( length );
  AbstractMessage * lAbstractMessage = MessageFactory::buildMessage( msg, length );
  delete[] msg;
  T * lMessage2 = dynamic_cast<T *> ( lAbstractMessage );
  assert( lMessage2 != NULL);
  //Ensure that both message are identical
  assert((*lMessage1) == (*lMessage2));
  delete lAbstractMessage;
}

  bool msgcmp( Byte * aMsg1, const char * aMsg2, unsigned int aLength )
  {
    
    Byte * lMsg2 = reinterpret_cast<Byte *>( const_cast< char * >( aMsg2 ) );
    return memcmp( aMsg1, lMsg2, aLength ) == 0;
  }

  void TestDebuggerSerialization::testRunMessage()
  {
    std::cerr << "Test run message" << std::endl;
    RunMessage msg;
    test_packet<RunMessage>( &msg );
    const char * lBinary =  "\0\0\0\xb\0\0\0\1\0\xf1\1";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length ) );
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
    assert( msgcmp( lBmsg, lBinary, length) );
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
    assert( msgcmp( lBmsg, lBinary, length) );
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
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepIntoMessage()
  {
    std::cerr << "Test step into message" << std::endl;
    StepMessage msg( STEP_INTO );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\5\0\xf1\5\1"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepOutMessage()
  {
    std::cerr << "Test step out message" << std::endl;
    StepMessage msg( STEP_OUT );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\6\0\xf1\5\2"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStepOverMessage()
  {
    std::cerr << "Test step over message" << std::endl;
    StepMessage msg( STEP_OVER );
    test_packet<StepMessage>( &msg );
    const char * lBinary =  "\0\0\0\xc\0\0\0\7\0\xf1\5\3"; 
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testStartedEvent()
  {
    std::cerr << "Test started event message" << std::endl;
    StartedEvent msg;
    test_packet< StartedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\x8\0\xf8\1";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }
  
  void TestDebuggerSerialization::testTerminatedEvent()
  {
    std::cerr << "Test terminated event message" << std::endl;
    TerminatedEvent msg;
    test_packet< TerminatedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\x9\0\xf8\2";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
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
    memcpy( lBinary, "\0\0\0\x070\0\0\0\xa\0\xf8\3", MESSAGE_SIZE );
    const char * lJSONString = "{\"cause\":1,\"location\":{\"fileName\":\"data.xq\",\"lineBegin\":1,\"columnBegin\":1,\"lineEnd\":1,\"columnEnd\":1}}";
    memcpy( lBinary + MESSAGE_SIZE, lJSONString, length - MESSAGE_SIZE );
    assert( msgcmp( lBmsg, lBinary, length) );
    
    delete[] lBmsg;
    delete[] lBinary;
  }

  void TestDebuggerSerialization::testResumedEvent()
  {
    std::cerr << "Test resumed event message" << std::endl;
    ResumedEvent msg;
    test_packet< ResumedEvent >( &msg );
    const char * lBinary = "\0\0\0\xb\0\0\0\xb\0\xf8\4";
    Length length;
    Byte * lBmsg = msg.serialize( length );
    assert( msgcmp( lBmsg, lBinary, length) );
    delete[] lBmsg;
  }

  void TestDebuggerSerialization::testClearMessage()
  {
    std::cerr << "Test clear message" << std::endl;
    
    QueryLoc loc;
    std::string lFilename( "data.xq" );
    loc.setFilenameBegin( &lFilename );
    loc.setLineBegin( 1 );
    loc.setColumnBegin( 1 );
    loc.setLineEnd( 1 );
    loc.setColumnEnd( 1 );
    
    ClearMessage msg;
    msg.addLocation( loc );
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
    msg.addLocation( loc );
    test_packet< SetMessage >( &msg );
  }

  void TestDebuggerSerialization::testVariableMessage()
  {
    store::SimpleStore* lStore = store::SimpleStore::getInstance();
    Zorba * lZorba = Zorba::getInstance( lStore );
    ItemFactory * lFactory = lZorba->getItemFactory();
    /* The item that is to be bound to the external variable */
    Item lItem = lFactory->createInteger(4);
    VariableMessage msg( String("var"), lItem );
    test_packet< VariableMessage >( &msg );
  }
}

