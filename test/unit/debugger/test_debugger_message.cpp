#include <cassert>
#include <iostream>
#include <vector>
#include <string>

#include "debugger/message_factory.hpp"

using namespace zorba;

template<class T>
void test_packet( AbstractCommandMessage * aMessage );
void test_message( AbstractCommandMessage * aMessage );
bool test_binary_message( char * aMsg, const unsigned int aLength, const ErrorCode aErrorCode = NO_ERROR );
bool test_binary_message( Byte * aMsg, const unsigned int aLength, const ErrorCode aErrorCode = NO_ERROR );

unsigned int i;

int test_debugger_message( int argc, char* argv[] )
{
  //First test the message hi-req...
  try
  {
    std::vector<AbstractCommandMessage *> lMessages;
    lMessages.push_back( new RunMessage() );    
    lMessages.push_back( new SuspendMessage() );
    lMessages.push_back( new ResumeMessage() );
    lMessages.push_back( new TerminateMessage() );
    lMessages.push_back( new StepMessage( STEP_INTO ) );
    lMessages.push_back( new StepMessage( STEP_OVER ) );
    lMessages.push_back( new StepMessage( STEP_OUT ) );

    for( i = 0; i < lMessages.size(); i++ )
    {
      test_message( lMessages.at( i ) );
    }

  } catch( MessageException &e ) {
    std::cerr << e.what() << std::endl;
    assert( false );
  }
//TODO: test endianness
  assert( test_binary_message( "\xb\0\0\0\1\0\0\0\0\xf7\1" , 11, ERROR_INVALID_MESSAGE_FORMAT ) );
  assert( test_binary_message( "\xb\0\0\0\1\0\0\0\0\xf1\x8" , 11 , ERROR_INVALID_MESSAGE_FORMAT ) );
  assert( test_binary_message( "\xb\0\0\0\1\0\0\0\0\1\1", 11, ERROR_INVALID_MESSAGE_FORMAT ) );
  assert( test_binary_message( "\xb\0\0\0\1\0\0\0\0\xf8\x8", 11, ERROR_INVALID_MESSAGE_FORMAT ) );

  return 0;
}

template<class T>
void test_packet( AbstractCommandMessage * aMessage ) 
{
  //Cast to the concrete Message Type
  T * lMessage1 = dynamic_cast<T *> ( aMessage );
  //Ensure that the cast is correct
  assert( lMessage1 != NULL);
  //Serialize and unserialize the message
  AbstractMessage * lAbstractMessage = MessageFactory::buildMessage( lMessage1->serialize(), lMessage1->getLength() );
  T * lMessage2 = dynamic_cast<T *> ( lAbstractMessage );
  assert( lMessage2 != NULL);
  //Ensure that both message are identical
  assert((*lMessage1) == (*lMessage2));
}

/**
 * 
 */

void test_message( AbstractCommandMessage *aMessage )
{
  switch( aMessage->getCommandSet() )
  {
    case EXECUTION:
    {
      switch( aMessage->getCommand() )
      {
        case RUN:
        {
          std::cout << "Test run execution message" << std::endl;
          test_packet<RunMessage> ( aMessage );
          break;
        }
        case SUSPEND:
        {
          std::cout << "Test suspend execution message" << std::endl;
          test_packet<SuspendMessage>(aMessage);
          break;
        }
        case RESUME:
        {
          std::cout << "Test resume execution message" << std::endl;
          test_packet<ResumeMessage>(aMessage);
          break;
        }
        case TERMINATE:
        {
          std::cout << "Test terminate execution message" << std::endl;
          test_packet<TerminateMessage>(aMessage);
          break;
        }
        case STEP:
        {
          std::cout << "Test step execution message" << std::endl;
          test_packet<StepMessage>(aMessage);
          break;
        }
      }
    }
  }
}

bool test_binary_message( char * aMsg, const unsigned int aLength, const ErrorCode aErrorCode )
{
  Byte * lBMsg = reinterpret_cast< Byte * >( aMsg );
  return test_binary_message( lBMsg, aLength, aErrorCode );
}

bool test_binary_message( Byte *  aMsg, const unsigned int aLength, const ErrorCode aErrorCode )
{
    AbstractMessage * lMessage = MessageFactory::buildMessage( aMsg, aLength );
    ReplyMessage * lReplyMessage;
    if ( ( lReplyMessage = dynamic_cast< ReplyMessage * > ( lMessage ) )
          && ( lReplyMessage->getErrorCode() == aErrorCode ) )
    {
      return true;
    } else if ( lReplyMessage == NULL && aErrorCode == NO_ERROR  ) {
      return true;
    } else {
      return false;
    }
}

