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

#include "debugger/debugger_protocol.h"

#include <iomanip>
#include <zorba/zorba.h>

#include "api/unmarshaller.h"

#include "zorbatypes/numconversions.h"

#include "json/parser.h"
#include "json/value.h"

namespace zorba{

bool is_little_endian()
{
  short int word = 0x0001;
  char * byte = (char *) &word;
  return(byte[0] ? true : false);
}

uint16_t uint_swap( uint16_t i )
{
  if ( ! is_little_endian() )
  {
    return i;
  } else {
    unsigned char b1, b2;
    b1 = i & 255;
    b2 = ( i >> 8 ) & 255;
    return ( b1 << 8 ) + b2;
  }
}

uint32_t uint_swap( uint32_t i )
{
  if ( ! is_little_endian() )
  {
    return i;
  } else {
    unsigned char b1, b2, b3, b4;
    b1 = i & 255;
    b2 = ( i >> 8 ) & 255;
    b3 = ( i >> 16 ) & 255;
    b4 = ( i >> 24 ) & 255;
    return ( b1 << 24 ) + ( b2 << 16 ) + ( b3 << 8 ) + b4;
  }
}

std::ostream& operator << ( std::ostream &os, const AbstractMessage * message )
{
  Length length;
  const char * lData = reinterpret_cast< const char * > ( message->serialize( length ) );
  os.write( lData, length );
  return os;
}

bool AbstractMessage::operator == ( const AbstractMessage & message )
{
  Length length;
  Byte * msg1 = serialize( length );
  Byte * msg2 = message.serialize( length );
  bool r = memcmp( msg1, msg2, length ) == 0;
  delete[] msg1;
  delete[] msg2;
  return r;
}

bool AbstractMessage::operator != (const AbstractMessage & message)
{
  return ! ( * this == message );
}

MessageException::MessageException( const std::string &aMessage) throw() : userMessage( aMessage ){}

MessageException::~MessageException() throw(){}

const char * MessageException::what() const throw()
{
  return userMessage.c_str();
}

AbstractMessage::AbstractMessage( const Id aId, const Flags aFlags )
{
  theHeaderContent = new HeaderContent();
  setId( aId );
  setFlags( aFlags );
  setLength( SIZE_OF_HEADER_CONTENT );
}

AbstractMessage::AbstractMessage( Byte * aMessage )
{
  HeaderContent * lmsg =  reinterpret_cast< HeaderContent *>( aMessage );
  theHeaderContent = new HeaderContent();
  memcpy( theHeaderContent, lmsg, SIZE_OF_HEADER_CONTENT );
}

AbstractMessage::~AbstractMessage()
{
  delete theHeaderContent;
}

//Byte * AbstractMessage::serialize( Length & aLength ) const
//{
//  return reinterpret_cast< Byte * >( theHeaderContent );
//}

void AbstractMessage::checkIntegrity()
{
  if( ! isValidMessage() )
  {
    throw MessageException( "Invalid Message" );
  }
}

ReplyMessage::ReplyMessage( const Id aId, const ErrorCode aErrorCode ):
  AbstractMessage( aId, REPLY_FLAG )
{
  theReplyContent = new ReplyContent();
  setErrorCode( aErrorCode );
  setLength( MESSAGE_SIZE );
}

ReplyMessage::ReplyMessage( Byte * aMessage, const unsigned int aLength ):  AbstractMessage( aMessage )
{
  ErrorCode * lmsg =  reinterpret_cast< ErrorCode * >( aMessage + SIZE_OF_HEADER_CONTENT );
  theReplyContent = new ReplyContent();
  memcpy( theReplyContent, lmsg, SIZE_OF_REPLY_CONTENT );
  if ( aLength - MESSAGE_SIZE > 0 )
  {
    char * lData = new char[ aLength - MESSAGE_SIZE + 1 ];
    //char *lMessage = reinterpret_cast<char *>( aMessage + MESSAGE_SIZE );
    memset(lData, '\0', aLength - MESSAGE_SIZE + 1);
    memcpy( lData, aMessage + MESSAGE_SIZE, aLength - MESSAGE_SIZE );
    theData = xqpString( lData );
    delete[] lData;
  }
  checkIntegrity();
}

ReplyMessage::~ReplyMessage()
{
  delete theReplyContent;
}

Byte * ReplyMessage::serialize( Length & aLength ) const
{
  std::stringstream lData;
  lData << theData;
  aLength = getLength();
  Byte * lHeader = reinterpret_cast< Byte * > ( theHeaderContent );
  Byte * lReply  = reinterpret_cast< Byte * > ( theReplyContent );
  //Harcoded value to avoid padding on sizeof(HeaderContent)
  Byte * lMsg = new Byte[ SIZE_OF_HEADER_CONTENT + SIZE_OF_REPLY_CONTENT + lData.str().length() ];
  memcpy( lMsg, lHeader, SIZE_OF_HEADER_CONTENT );
  memcpy( lMsg + SIZE_OF_HEADER_CONTENT, lReply, SIZE_OF_REPLY_CONTENT );
  if ( lData.str().length() > 0 )
  {
    memcpy( lMsg + SIZE_OF_HEADER_CONTENT + SIZE_OF_REPLY_CONTENT, lData.str().c_str(), lData.str().length() );
  }
  return lMsg;
}

bool ReplyMessage::isValidMessage() const
{
  //Logic of the reply packet
  //TODO: implement the logic of the message
  return true;
}

bool ReplyMessage::isOk() const
{
  return getErrorCode() == DEBUGGER_NO_ERROR;
}

unsigned long AbstractCommandMessage::theLastId = 0;

/**
 * Compute and assemble a packet implementing the debugger protocol
 * @param id (4 bytes): The packet id
 * @param flags (1 byte)
 * @param command_set (1 byte)
 * @param command (1 byte)
 * @param data (variable)
 */
AbstractCommandMessage::AbstractCommandMessage( const CommandSet aCommandSet, const Command aCommand ): AbstractMessage( ++theLastId, NULL_FLAG ), theReply(0)
{
  theCommandContent = new CommandContent();
  setCommandSet( aCommandSet );
  setCommand( aCommand );
  setLength( MESSAGE_SIZE );
}

AbstractCommandMessage::AbstractCommandMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractMessage( aMessage ), theReply(0)
{
  CommandContent * lmsg =  reinterpret_cast< CommandContent *>( aMessage + SIZE_OF_HEADER_CONTENT );
  theCommandContent = new CommandContent();
  memcpy( theCommandContent, lmsg, sizeof( CommandContent ) );
  checkIntegrity();
}

Byte * AbstractCommandMessage::serialize( Length & aLength ) const
{
  Byte * lHeader   = reinterpret_cast< Byte * > ( theHeaderContent );
  Byte * lCommand  = reinterpret_cast< Byte * > ( theCommandContent );
  //Harcoded value to avoid padding on sizeof(HeaderContent)
  Byte * lMsg = new Byte[ SIZE_OF_HEADER_CONTENT + sizeof( CommandContent ) ];
  memcpy( lMsg, lHeader, SIZE_OF_HEADER_CONTENT );
  memcpy( lMsg + SIZE_OF_HEADER_CONTENT, lCommand, sizeof( CommandContent ) );
  aLength = MESSAGE_SIZE;
  return lMsg;
}

AbstractCommandMessage::~AbstractCommandMessage()
{
  delete theCommandContent;
}

bool AbstractCommandMessage::isValidMessage() const
{
  return isExecutionCommand() || isBreakpointsCommand() ||
         isEngineEventCommand() || isStaticCommand() ||
         isDynamicCommand();
}

bool AbstractCommandMessage::isExecutionCommand() const
{
  return getCommandSet() == EXECUTION &&
          ( getCommand() == RUN || getCommand() == SUSPEND ||
            getCommand() == RESUME || getCommand() == STEP ||
            getCommand() == TERMINATE || getCommand() == QUIT );
}

bool AbstractCommandMessage::isBreakpointsCommand() const
{
  return getCommandSet() == BREAKPOINTS &&
          ( getCommand() == SET || getCommand() == CLEAR );
}

bool AbstractCommandMessage::isEngineEventCommand() const
{
  return getCommandSet() == ENGINE_EVENT &&
          ( getCommand() == STARTED || getCommand() == TERMINATED ||
            getCommand() == SUSPENDED || getCommand() == RESUMED  || getCommand() == EVALUATED );
}

bool AbstractCommandMessage::isStaticCommand() const
{
  return getCommandSet() == STATIC
          && ( getCommand() == OPTIONS || getCommand() == DEFAULTS ||
                getCommand() == SETS );
}

bool AbstractCommandMessage::isDynamicCommand() const
{
  return getCommandSet() == DYNAMIC &&
    ( getCommand() == DATA || getCommand() == VARIABLES ||
      getCommand() == FOCUS || getCommand() == TIME || 
      getCommand() == DOCUMENTS || getCommand() == COLLECTION ||
      getCommand() == COLLECTIONS || getCommand() == EVAL );
}

RunMessage::RunMessage():
  AbstractCommandMessage( EXECUTION, RUN ){}

RunMessage::RunMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

RunMessage::~RunMessage(){}

SuspendMessage::SuspendMessage():
  AbstractCommandMessage( EXECUTION, SUSPEND ){}

SuspendMessage::SuspendMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

SuspendMessage::~SuspendMessage(){}

TerminateMessage::TerminateMessage():
  AbstractCommandMessage( EXECUTION, TERMINATE ){}

TerminateMessage::TerminateMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

TerminateMessage::~TerminateMessage(){}

QuitMessage::QuitMessage():
  AbstractCommandMessage( EXECUTION, QUIT ){}

QuitMessage::QuitMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

QuitMessage::~QuitMessage(){}

ResumeMessage::ResumeMessage():
  AbstractCommandMessage( EXECUTION, RESUME ){}

ResumeMessage::ResumeMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

ResumeMessage::~ResumeMessage(){}

StepMessage::StepMessage( StepCommand aKind ):
  AbstractCommandMessage( EXECUTION, STEP ), theKind( aKind ){
  setLength( MESSAGE_SIZE + 1 );
  checkIntegrity();
}

StepMessage::StepMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  theKind = aMessage[11];
  checkIntegrity();
}

StepMessage::~StepMessage(){}

Byte * StepMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  Byte * lMsg = new Byte[ MESSAGE_SIZE + 1 ];
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  lMsg[ 11 ] = theKind;
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

bool StepMessage::isValidMessage() const
{
  return AbstractCommandMessage::isValidMessage() &&
    ( theKind == STEP_INTO || theKind == STEP_OUT || theKind == STEP_OVER );
}

const StepCommand StepMessage::getStepKind() const
{
  return theKind;
}

/**
 * Set Breakpoints message
 */
SetMessage::SetMessage(): AbstractCommandMessage( BREAKPOINTS, SET ){}

SetMessage::SetMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = new char[ aLength + 1 ];
  memset( lMessage, '\0', aLength );
  memcpy( lMessage, aMessage + MESSAGE_SIZE, aLength - MESSAGE_SIZE );
  json::parser lParser;
  json::value * lValue = lParser.parse( lMessage, aLength - MESSAGE_SIZE );
  if ( (*lValue)["breakpoints"]  != 0 )
  {
    json::array_list_t::iterator it; 
    for ( it=(*lValue)["breakpoints"]->getarraylist()->begin(); it != (*lValue)["breakpoints"]->getarraylist()->end(); it++ )
    {
      if ((**it)["location"] != 0 )
      {
        QueryLoc loc;
        loc.fromJSON( (**it)["location"] );
        if ( (**it)["id"] == 0 )
        {
          throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
        }
        theLocations.insert( std::make_pair((**it)["id"]->getinteger(), loc) );
      } else if ( (**it)["expr"] != 0 ) {
        std::wstring *lExpr = (**it)["expr"]->getstring(L"", true);
        std::string expr( lExpr->begin()+1, lExpr->end()-1 );
       	delete lExpr; 
	if ( (**it)["id"] == 0 )
        {
          throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
        }
        theExprs.insert( std::make_pair( (**it)["id"]->getinteger(),  xqpString( expr ) ) );
      } else {
        throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
      }
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
  }
  delete lValue;
  //setLength( MESSAGE_SIZE + getData().length() );  
  checkIntegrity();
  delete[] lMessage;
}

SetMessage::~SetMessage(){}

Byte * SetMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  //memcpy( lMsg + MESSAGE_SIZE, s, l - 1 );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

std::string SetMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"breakpoints\":[";
  std::map<unsigned int, QueryLoc>::const_iterator it;
  for( it = theLocations.begin(); it != theLocations.end(); it++ )
  { 
    if ( it != theLocations.begin() )
    {
      lJSONString << ',';
    }
    lJSONString << "{\"id\":" << it->first << ",\"location\":" << it->second.toJSON() << "}";
  }

  std::map<unsigned int, xqpString>::const_iterator it2;
  for( it2 = theExprs.begin(); it2 != theExprs.end(); it2++ )
  {
    lJSONString << ",{\"id\":" << it2->first << ",\"expr\":\"" << it2->second << "\"}";
  }
  lJSONString << "]}";
  return lJSONString.str();
}

/**
 * Clear Breakpoints message
 */
ClearMessage::ClearMessage(): AbstractCommandMessage( BREAKPOINTS, CLEAR ){}

ClearMessage::ClearMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  json::parser lParser;
  json::value * lValue = lParser.parse( lMessage, aLength );
  if ( (*lValue)["ids"]  != 0 )
  {
    json::array_list_t::iterator it; 
    for ( it=(*lValue)["ids"]->getarraylist()->begin(); it != (*lValue)["ids"]->getarraylist()->end(); it++ )
    {
      theIds.push_back( (*it)->getinteger() );
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Clear breakpoint message.");
  }
  //setLength( MESSAGE_SIZE + getData().length() );  
  delete lValue;
  checkIntegrity();
}

ClearMessage::~ClearMessage(){}

Byte * ClearMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  //memcpy( lMsg + MESSAGE_SIZE, s, l - 1 );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

std::string ClearMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"ids\":[";
  std::vector<unsigned int>::const_iterator it;
  for( it = theIds.begin(); it != theIds.end(); it++ )
  {
    if ( it != theIds.begin() )
    {
      lJSONString << ",";
    }
    lJSONString << *it;
  }
  lJSONString << "]}";
  return lJSONString.str();
}

/**
 * Started Engine Event
 */
StartedEvent::StartedEvent():
  AbstractCommandMessage( ENGINE_EVENT, STARTED ){}

StartedEvent::StartedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
    checkIntegrity();
}

StartedEvent::~StartedEvent(){}

/**
 * Terminated Engine Event
 */
TerminatedEvent::TerminatedEvent():
  AbstractCommandMessage( ENGINE_EVENT, TERMINATED ){}

TerminatedEvent::TerminatedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

TerminatedEvent::~TerminatedEvent(){}

/**
 * Suspended Engine Event
 */
SuspendedEvent::SuspendedEvent( const QueryLoc &aLocation, const SuspensionCause aCause ):
  AbstractCommandMessage( ENGINE_EVENT, SUSPENDED ), theLocation( aLocation ), theCause( aCause ) 
{
  unsigned int l = MESSAGE_SIZE + getData().length();
  setLength( l );
  checkIntegrity();
}

SuspendedEvent::SuspendedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  json::parser lParser;
  json::value * lValue = lParser.parse( lMessage, aLength - MESSAGE_SIZE );
  assert( lValue != 0 );
  if ( (*lValue)["cause"]  != 0 )
  {
    theCause = (*lValue)["cause"]->getinteger();
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  
  if ( (*lValue)["location"]  != 0 )
  {
    theLocation.fromJSON( (*lValue)["location"] );
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  //setLength( MESSAGE_SIZE + getData().length() );  
  delete lValue;
  checkIntegrity();
}

SuspendedEvent::~SuspendedEvent(){}

Byte * SuspendedEvent::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  //memcpy( lMsg + MESSAGE_SIZE, s, l - 1 );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

QueryLoc SuspendedEvent::getLocation() const
{
  return theLocation;
}

SuspensionCause SuspendedEvent::getCause() const
{
  return theCause;
}

std::string SuspendedEvent::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"cause\":" << theCause << ",";
  lJSONString << "\"location\":" << theLocation.toJSON();
  lJSONString << "}";
  return lJSONString.str();
}

/**
 * Resumed Engine Event
 */
ResumedEvent::ResumedEvent():
  AbstractCommandMessage( ENGINE_EVENT, RESUMED ) 
{
  checkIntegrity();
}

ResumedEvent::ResumedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

ResumedEvent::~ResumedEvent(){}

/**
 * Evaluated Engine Event
 */
EvaluatedEvent::EvaluatedEvent( xqpString anExpr, xqpString anError ):
  AbstractCommandMessage( ENGINE_EVENT, EVALUATED ), theExpr( anExpr ), theError( anError )
{
    unsigned int l = MESSAGE_SIZE + getData().length();
    setLength( l );
    checkIntegrity();
}

EvaluatedEvent::EvaluatedEvent( xqpString anExpr, xqpString aResult, xqpString aReturnType ):
  AbstractCommandMessage( ENGINE_EVENT, EVALUATED ), theExpr( anExpr ), theResult( aResult ), theReturnType( aReturnType )
{
    unsigned int l = MESSAGE_SIZE + getData().length();
    setLength( l );
    checkIntegrity();
}

EvaluatedEvent::EvaluatedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  json::parser lParser;
  json::value * lValue = lParser.parse( lMessage, aLength - MESSAGE_SIZE );
  if ( (*lValue)["expr"]  != 0 )
  {
    std::wstring* lWString = (*lValue)["expr"]->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theExpr = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }
  
  if ( (*lValue)["result"]  != 0 )
  {
    std::wstring* lWString = (*lValue)["result"]->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theResult = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }

  if ( (*lValue)["type"]  != 0 )
  {
    std::wstring* lWString = (*lValue)["type"]->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theReturnType = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }

  if ( (*lValue)["error"]  != 0 )
  {
    std::wstring* lWString = (*lValue)["error"]->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theError = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }
  delete lValue; 
  checkIntegrity();
}

EvaluatedEvent::~EvaluatedEvent(){}

xqpString EvaluatedEvent::getExpr() const
{
  return theExpr;
}

xqpString EvaluatedEvent::getResult() const
{
  return theResult;
}

xqpString EvaluatedEvent::getReturnType() const
{
  return theReturnType;
}

xqpString EvaluatedEvent::getError() const
{
  return theError;
}

Byte * EvaluatedEvent::serialize( Length &aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  xqpString lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  //memcpy( lMsg + MESSAGE_SIZE, s, l - 1 );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  //delete[] lHeader;
  aLength = getLength();
  delete[] lHeader;
  return lMsg; 
}

xqpString EvaluatedEvent::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"expr\":\"" << theExpr << "\",";
  lJSONString << "\"result\":\"" << theResult << "\",";
  lJSONString << "\"type\":\"" << theReturnType << "\",";
  lJSONString << "\"error\":\"" << theError << "\"";
  lJSONString << "}";
  xqpString lReturnString( lJSONString.str() );
  return lReturnString;
}

/**
 * Eval Message
 */
EvalMessage::EvalMessage( xqpString anExpr ):
  AbstractCommandMessage( DYNAMIC, EVAL ), theExpr( anExpr )
{
    unsigned int l = MESSAGE_SIZE + getData().length();
    setLength( l );
    checkIntegrity();
}

EvalMessage::EvalMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  json::parser lParser;
  json::value * lValue = lParser.parse( lMessage, aLength - MESSAGE_SIZE );
  if ( (*lValue)["expr"]  != 0 )
  {
    std::wstring* lWString = (*lValue)["expr"]->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theExpr = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  delete lValue;
  checkIntegrity();
}

EvalMessage::~EvalMessage(){}

xqpString EvalMessage::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"expr\":\"" << theExpr << "\"";
  lJSONString << "}";
  xqpString lReturnString( lJSONString.str() );
  return lReturnString;
}

Byte * EvalMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  xqpString lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

xqpString EvalMessage::getExpr() const
{
  return theExpr;
}

VariableMessage::VariableMessage():
  AbstractCommandMessage( DYNAMIC, VARIABLES ) 
{
  checkIntegrity();
}

VariableMessage::VariableMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

VariableMessage::~VariableMessage(){}

/**
 * Variable Reply Message
 */
VariableReply::VariableReply( const Id anId, const ErrorCode aErrorCode ):
  ReplyMessage( anId, aErrorCode )
{
  setFlags( REPLY_VARIABLE_FLAG );
  unsigned int l = MESSAGE_SIZE + getData().length();
  setLength( l );
  checkIntegrity();
}

VariableReply::VariableReply( Byte * aMessage, const unsigned int aLength ):
  ReplyMessage( aMessage, aLength )
{
  setFlags( REPLY_VARIABLE_FLAG );
  char *lMessage = reinterpret_cast<char *>( aMessage + MESSAGE_SIZE );
  json::parser lParser;
  json::value *lValue = lParser.parse( lMessage, aLength - MESSAGE_SIZE );
  if ( (*lValue)["globals"] != 0 )
  {
    json::array_list_t::iterator it;
    for ( it  = (*lValue)["globals"]->getarraylist()->begin();
          it != (*lValue)["globals"]->getarraylist()->end();
          it++ )
    {
      json::value *lVariable = (*it);
      
      if ( (*lVariable)["name"] == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lName = (*lVariable)["name"]->getstring(L"", true);
      std::string name = std::string( lName->begin()+1, lName->end()-1 );
      delete lName;
      if ( (*lVariable)["type"] == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lType = (*lVariable)["type"]->getstring(L"", true);
      std::string type = std::string( lType->begin()+1, lType->end()-1 );
      delete lType; 
      addGlobal(name, type);
    }
  } else {
    throw MessageFormatException("Invalid JSON format for variable message.");
  }

  if ( (*lValue)["locals"] != 0 )
  {
    json::array_list_t::iterator it;
    for ( it  = (*lValue)["locals"]->getarraylist()->begin();
          it != (*lValue)["locals"]->getarraylist()->end();
          it++ )
    {
      json::value *lVariable = (*it);
      
      if ( (*lVariable)["name"] == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lName = (*lVariable)["name"]->getstring(L"", true);
      std::string name = std::string( lName->begin()+1, lName->end()-1 );
      delete lName;
      if ( (*lVariable)["type"] == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lType = (*lVariable)["type"]->getstring(L"", true);
      std::string type = std::string( lType->begin()+1, lType->end()-1 );
      delete lType; 
      addLocal(name, type);
    }
    delete lValue;
  } else {
    throw MessageFormatException("Invalid JSON format for variable message.");
  }
} 

VariableReply::~VariableReply(){}

xqpString VariableReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"globals\":[";
  std::map<xqpString, xqpString>::const_iterator it = theGlobals.begin();
  for(; it != theGlobals.end(); it++ )
  {
    if ( it != theGlobals.begin() )
    {
      lJSONString << ',';
    }
    lJSONString << "{\"name\":\"" << it->first << "\",\"type\":\"" << it->second << "\"}";
  }
  lJSONString << "],\"locals\":[";
  std::map<xqpString, xqpString>::const_iterator lIter;
  for( lIter = theLocals.begin(); lIter != theLocals.end(); ++lIter )
  {
    if ( lIter != theLocals.begin() )
    {
      lJSONString << ',';
    }
    lJSONString << "{\"name\":\"" << lIter->first << "\",\"type\":\"" << lIter->second << "\"}";
  }
  lJSONString << "]}";
  xqpString lReturnString( lJSONString.str() );
  return lReturnString;
}

Byte * VariableReply::serialize( Length & aLength ) const
{
  Byte * lHeader = ReplyMessage::serialize( aLength );
  xqpString lJSONString = getData();
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  Byte * lMsg = new Byte[ MESSAGE_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_SIZE + l + 1);
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
}

std::map<xqpString, xqpString> VariableReply::getVariables() const
{
  std::map<xqpString, xqpString> lVariables;
  lVariables.insert( theGlobals.begin(), theGlobals.end() );
  lVariables.insert( theLocals.begin(), theLocals.end() );
  return lVariables;
}

std::map<xqpString, xqpString> VariableReply::getLocalVariables() const
{
  return theLocals;
}

std::map<xqpString, xqpString> VariableReply::getGlobalVariables() const
{
  return theGlobals;
}

void VariableReply::addGlobal( xqpString aVariable, xqpString aType )
{
  theGlobals.insert( std::make_pair( aVariable, aType ) );
  setLength( MESSAGE_SIZE + getData().length() );
}
    
void VariableReply::addLocal( xqpString aVariable, xqpString aType )
{
  theLocals.insert( std::make_pair( aVariable, aType ) );
  setLength( MESSAGE_SIZE + getData().length() );
}
}//end of namespace

