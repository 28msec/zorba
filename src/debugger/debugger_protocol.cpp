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
#include <list>

#include <zorba/zorba.h>

#include "api/unmarshaller.h"

#include "zorbatypes/numconversions.h"

#include "json/parser.h"
#include "json/value.h"

#include "debugger/utils.h"

using namespace std;

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

json::value* getValue(Byte* aMessage, const unsigned int aLength)
{
  char* lMessage = reinterpret_cast<char *>(aMessage+MESSAGE_SIZE);
  json::parser lParser;
  json::value* lValue = lParser.parse(lMessage, aLength-MESSAGE_SIZE);
  return lValue;
}

json::value* getValue(json::value* aValue, std::string anIndex)
{
  return (*aValue)[anIndex.c_str()];
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
  //if( ! isValidMessage() )
  //{
  //  throw MessageException( "Invalid Message" );
  //}
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
    ZorbaArrayAutoPointer<char> lData(new char[ aLength - MESSAGE_SIZE + 1 ]);
    memset(lData.get(), '\0', aLength - MESSAGE_SIZE + 1);
    memcpy(lData.get(), aMessage + MESSAGE_SIZE, aLength - MESSAGE_SIZE );
    theData = xqpString(lData.get());
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
            getCommand() == TERMINATE );
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

/**
 * Run message
 */
RunMessage::RunMessage():
  AbstractCommandMessage( EXECUTION, RUN ){}

RunMessage::RunMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

RunMessage::~RunMessage(){}

/**
 * Catch function execution message
 */
CatchFnExecMessage::CatchFnExecMessage():
  AbstractCommandMessage(EXECUTION, CATCH_FN_EXEC){}

CatchFnExecMessage::CatchFnExecMessage(Byte* aMessage, const unsigned int aLength):
  AbstractCommandMessage(aMessage, aLength){}

CatchFnExecMessage::~CatchFnExecMessage(){}

/**
 * Suspend message
 */
SuspendMessage::SuspendMessage():
  AbstractCommandMessage( EXECUTION, SUSPEND ){}

SuspendMessage::SuspendMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

SuspendMessage::~SuspendMessage(){}

/**
 * Terminate message
 */
TerminateMessage::TerminateMessage():
  AbstractCommandMessage( EXECUTION, TERMINATE ){}

TerminateMessage::TerminateMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

TerminateMessage::~TerminateMessage(){}

/**
 * Resume message
 */
ResumeMessage::ResumeMessage():
  AbstractCommandMessage( EXECUTION, RESUME ){}

ResumeMessage::ResumeMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

ResumeMessage::~ResumeMessage(){}

/**
 * Step message
 */
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
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  Byte * lMsg = new Byte[ MESSAGE_SIZE + 1 ];
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  lMsg[ 11 ] = theKind;
  aLength = getLength();
  return lMsg; 
}

bool StepMessage::isValidMessage() const
{
  return AbstractCommandMessage::isValidMessage() &&
    ( theKind == STEP_INTO || theKind == STEP_OUT || theKind == STEP_OVER );
}

StepCommand StepMessage::getStepKind() const
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
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  
  json::value* breakpoints = getValue(lValue.get(), "breakpoints");
  if( breakpoints != 0 )
  {
    json::array_list_t* list = breakpoints->getarraylist();
    json::array_list_t::iterator it; 
    
    for ( it=list->begin(); it != list->end(); ++it )
    {
      if ( getValue(*it, "location") != 0 )
      {
        QueryLoc loc = QueryLoc::fromJSON(getValue(*it, "location"));
        if ( getValue(*it, "id") == 0 )
        {
          throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
        }
        theLocations.insert( std::make_pair(getValue(*it, "id")->getinteger(), loc) );
      } else if ( getValue( *it, "expr" ) != 0 ) {
        std::wstring* lExpr = getValue(*it, "expr")->getstring(L"", true);
        std::string expr( lExpr->begin()+1, lExpr->end()-1 );
       	delete lExpr; 
	      if ( getValue(*it, "id") == 0 )
        {
          throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
        }
        theExprs.insert( std::make_pair( getValue(*it, "id")->getinteger(),  xqpString( expr ) ) );
      } else {
        throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
      }
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
  }
  checkIntegrity();
}

SetMessage::~SetMessage(){}

Byte * SetMessage::serialize( Length & aLength ) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
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
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* ids = getValue(lValue.get(), "ids");
  if ( ids != 0 )
  {
    json::array_list_t* list =  ids->getarraylist();
    json::array_list_t::iterator it; 
    for (it=list->begin(); it!=list->end(); ++it)
    {
      theIds.push_back( (*it)->getinteger() );
    }
  } else {
    throw MessageFormatException("Invalid JSON format for Clear breakpoint message.");
  }
  checkIntegrity();
}

ClearMessage::~ClearMessage(){}

Byte * ClearMessage::serialize( Length & aLength ) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
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
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* cause = getValue(lValue.get(), "cause");
  json::value* location = getValue(lValue.get(), "location");

  if ( cause  != 0 )
  {
    theCause = cause->getinteger();
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  
  if ( location  != 0 )
  {
    theLocation = QueryLoc::fromJSON( location );
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
  checkIntegrity();
}

SuspendedEvent::~SuspendedEvent(){}

Byte * SuspendedEvent::serialize( Length & aLength ) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '\0', getLength()+1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
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

EvaluatedEvent::EvaluatedEvent( xqpString anExpr, list<pair<xqpString, xqpString> > valuesAndTypes ):
  AbstractCommandMessage( ENGINE_EVENT, EVALUATED ), theExpr( anExpr ), theValuesAndTypes(valuesAndTypes)
{
    list<pair<xqpString, xqpString> > lValues;
    list<pair<xqpString, xqpString> >::iterator it;
    for(it=theValuesAndTypes.begin(); it!=theValuesAndTypes.end(); it++)
    {
      xqpString lFirst(it->first);
      xqpString lSecond(it->second);
      lValues.push_back(std::make_pair(lFirst.replace("\\\"", "&quot;", ""), 
                                    lSecond.replace("\\\"", "&quot;", "")));
    }
    theValuesAndTypes = lValues;
    unsigned int l = MESSAGE_SIZE + getData().length();
    setLength( l );
    checkIntegrity();
}

EvaluatedEvent::EvaluatedEvent( Byte* aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* expr = getValue(lValue.get(), "expr");
  json::value* results = getValue(lValue.get(), "results");
  json::value* error = getValue(lValue.get(), "error");

  if (expr != 0)
  {
    std::wstring* lWString = expr->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theExpr = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }
  
  if (results != 0)
  {
    json::array_list_t* list = results->getarraylist();
    json::array_list_t::iterator it;
    for (it=list->begin(); it!=list->end(); it++)
    {
      if ( getValue(*it, "result") == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lName = getValue(*it, "result")->getstring(L"", true);
      std::string result = std::string( lName->begin()+1, lName->end()-1 );
      delete lName;
      if ( getValue(*it, "type") == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lType = getValue(*it, "type")->getstring(L"", true);
      std::string type = std::string( lType->begin()+1, lType->end()-1 );
      delete lType; 
      theValuesAndTypes.push_back(std::make_pair(result, type));
    }   
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }

  if ( error != 0 )
  {
    std::wstring* lWString = error->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theError = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for EvaluatedEvent message.");
  }
  checkIntegrity();
}

EvaluatedEvent::~EvaluatedEvent(){}

xqpString EvaluatedEvent::getExpr() const
{
  return theExpr;
}

list<pair<xqpString, xqpString> > EvaluatedEvent::getValuesAndTypes() const
{
  return theValuesAndTypes;
}

xqpString EvaluatedEvent::getError() const
{
  return theError;
}

Byte * EvaluatedEvent::serialize( Length &aLength ) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  xqpString lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  aLength = getLength();
  return lMsg; 
}

xqpString EvaluatedEvent::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{";
  lJSONString << "\"expr\":\"" << theExpr << "\",";
  lJSONString << "\"results\":[";
  list<pair<xqpString, xqpString> >::const_iterator it = theValuesAndTypes.begin();
  for(; it != theValuesAndTypes.end(); it++ )
  {
    if ( it != theValuesAndTypes.begin() )
    {
      lJSONString << ',';
    }
    lJSONString << "{\"result\":\"" << it->first << "\",\"type\":\"" << it->second << "\"}";
  }
  lJSONString << "],";
  lJSONString << "\"error\":\"" << theError << "\"";
  lJSONString << "}";
  xqpString lData( lJSONString.str() );
  return lData;
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
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* expr = getValue(lValue.get(), "expr");
  if (expr != 0)
  {
    std::wstring* lWString = expr->getstring(L"", true);
    std::string lString( lWString->begin()+1, lWString->end()-1 );
    delete lWString;
    theExpr = lString;
  } else {
    throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
  }
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
  ZorbaArrayAutoPointer<Byte> lHeader(AbstractCommandMessage::serialize(aLength));
  xqpString lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() + 1 ];
  memset(lMsg, '0', getLength()+1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  memcpy( lMsg + MESSAGE_SIZE, s, l );
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
 * Frame Message
 */
FrameMessage::FrameMessage(): AbstractCommandMessage(DYNAMIC, FRAME){}

FrameMessage::FrameMessage(Byte* aMessage, const unsigned int aLength):
  AbstractCommandMessage(aMessage, aLength){}

FrameMessage::~FrameMessage(){}

/**
 * Frame Reply
 */
FrameReply::FrameReply(const Id anId, const ErrorCode aErrorCode,
                       std::stack< std::pair<std::string, QueryLoc> >  aStack)
  : ReplyMessage(anId, aErrorCode), theStack(aStack)
{
  setFlags(REPLY_FRAME_FLAG);
  unsigned int l = MESSAGE_SIZE + getData().length();
  setLength(l);
  checkIntegrity();
}

FrameReply::FrameReply(Byte* aMessage, const unsigned int aLength)
  : ReplyMessage(aMessage, aLength)
{
  setFlags(REPLY_FRAME_FLAG);
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* frame = getValue(lValue.get(), "frame");
  if(frame != 0)
  {
    json::array_list_t* list = frame->getarraylist();
    json::array_list_t::iterator it;
    for(it=list->begin(); it!=list->end(); ++it)
    {
      if(getValue(*it, "location") != 0)
      {
        QueryLoc loc = QueryLoc::fromJSON(getValue(*it, "location"));
        if(getValue(*it, "label") == 0)
        {
          throw MessageFormatException("Invalid JSON format for Stack");
        }
        std::wstring* lLabel = getValue(*it, "label")->getstring(L"", true);
        std::string label(lLabel->begin()+1, lLabel->end()-1);
        theStack.push(std::make_pair<std::string, const QueryLoc>(label, loc));
      } else {
        throw MessageFormatException("Invalid JSON format for Stack");
      }
    }
  } else {
    throw MessageFormatException("Invalid JSON format for stack frame messsage.");
  }
}

xqpString FrameReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"frame\":[";
  std::stack< std::pair<std::string, QueryLoc> > lStack(theStack);
  while(!lStack.empty())
  {
    if(lStack.size() != theStack.size())
    {
      lJSONString << ",";
    }
    std::pair<std::string, QueryLoc> it = lStack.top();
    lJSONString << "{\"label\":\"" << it.first << "\",\"location\":" << it.second.toJSON() << "}";
    lStack.pop();
  }
  lJSONString << "]}";
  return lJSONString.str();
}

Byte* FrameReply::serialize(Length& aLength) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(ReplyMessage::serialize(aLength));
  xqpString lJSON = getData();
  const char* s = lJSON.c_str();
  unsigned int l = lJSON.length();
  Byte* lMsg = new Byte[MESSAGE_SIZE+l+1];
  memset(lMsg, '0', MESSAGE_SIZE+l+1);
  memcpy(lMsg, lHeader.get(), MESSAGE_SIZE);
  memcpy(lMsg+MESSAGE_SIZE, s, l);
  aLength = getLength();
  return lMsg;
}


/**
 * Set Breakpoint reply message
 */
SetReply::SetReply(const Id anId, const ErrorCode aErrorCode):
  ReplyMessage(anId, aErrorCode)
{
  setFlags(REPLY_SET_FLAG);
  unsigned int l = MESSAGE_SIZE + getData().length();
  setLength(l);
  checkIntegrity();
}

SetReply::SetReply(Byte* aMessage, const unsigned int aLength): ReplyMessage(aMessage, aLength)
{
  setFlags(REPLY_SET_FLAG);
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* breakpoints = getValue(lValue.get(), "breakpoints");
  if(breakpoints != 0)
  {
    json::array_list_t* list = breakpoints->getarraylist();
    json::array_list_t::iterator it;
    for(it=list->begin(); it!=list->end(); ++it)
    {
      if(getValue(*it, "location") != 0)
      {
        QueryLoc loc = QueryLoc::fromJSON(getValue(*it, "location"));
        if(getValue(*it, "id") == 0)
        {
          throw MessageFormatException("Invalid JSON format for Set breakpoint reply message.");
        }
        theBreakpoints.insert( std::make_pair(getValue(*it, "id")->getinteger(), loc));
      } else {
        throw MessageFormatException("Invalid JSON format for breakpoint reply message.");
      }
    }
  } else {
    throw MessageFormatException("Invalid JSON format for breakpoint reply message.");
  }
}

SetReply::~SetReply(){}

xqpString SetReply::getData() const
{
  std::stringstream lJSONString;
  lJSONString << "{\"breakpoints\":[";
  std::map<unsigned int, QueryLoc>::const_iterator it;
  for( it = theBreakpoints.begin(); it != theBreakpoints.end(); ++it )
  { 
    if ( it != theBreakpoints.begin() )
    {
      lJSONString << ',';
    }
    lJSONString << "{\"id\":" << it->first << ",\"location\":" << it->second.toJSON() << "}";
  }
  lJSONString << "]}";
  return lJSONString.str();
}

Byte* SetReply::serialize(Length& aLength) const
{
  ZorbaArrayAutoPointer<Byte> lHeader(ReplyMessage::serialize( aLength ));
  xqpString lJSONString = getData();
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  Byte * lMsg = new Byte[ MESSAGE_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_SIZE + l + 1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  aLength = getLength();
  return lMsg; 
}

void SetReply::addBreakpoint(unsigned int anId, QueryLoc& aLocation)
{
  theBreakpoints.insert(std::make_pair<unsigned int, QueryLoc>(anId, aLocation));
  setLength(getData().length());
}

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
  std::auto_ptr<json::value> lValue(getValue(aMessage, aLength));
  json::value* globals = getValue(lValue.get(), "globals");
  json::value* locals = getValue(lValue.get(), "locals");

  if ( globals != 0 )
  {
    json::array_list_t* list = globals->getarraylist();
    json::array_list_t::iterator it;
    for (it=list->begin(); it!=list->end(); it++)
    {
      json::value* Name = getValue(*it, "name");
      json::value* Type = getValue(*it, "type");

      if ( Name == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lName = Name->getstring(L"", true);
      std::string name = std::string( lName->begin()+1, lName->end()-1 );
      delete lName;
      if ( Type == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lType = Type->getstring(L"", true);
      std::string type = std::string( lType->begin()+1, lType->end()-1 );
      delete lType; 
      addGlobal(name, type);
    }
  } else {
    throw MessageFormatException("Invalid JSON format for variable message.");
  }

  if ( locals != 0 )
  {
    json::array_list_t* list = locals->getarraylist();
    json::array_list_t::iterator it;
    for ( it =list->begin(); it!= list->end(); it++ )
    {
      json::value* Name = getValue(*it, "name");
      json::value* Type = getValue(*it, "type");

      if ( Name == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lName = Name->getstring(L"", true);
      std::string name = std::string( lName->begin()+1, lName->end()-1 );
      delete lName;
      if ( Type == 0 )
      {
        throw MessageFormatException("Invalid JSON format for variable message.");
      }
      std::wstring *lType = Type->getstring(L"", true);
      std::string type = std::string( lType->begin()+1, lType->end()-1 );
      delete lType; 
      addLocal(name, type);
    }
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
  ZorbaArrayAutoPointer<Byte> lHeader(ReplyMessage::serialize( aLength ));
  xqpString lJSONString = getData();
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  Byte * lMsg = new Byte[ MESSAGE_SIZE + l + 1 ];
  memset(lMsg, '0', MESSAGE_SIZE + l + 1);
  memcpy( lMsg, lHeader.get(), MESSAGE_SIZE );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
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

