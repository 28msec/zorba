#include <stdio.h>
#include <errno.h>

#include <exception>
#include <string>
#include <iostream>
#include <string>
#include <sstream>
#include <iostream>
#include <iomanip>

#include "tiny_json/json.hpp"

#include "zorbatypes/numconversions.h"

#include "debugger/debugger_protocol.hpp"


bool is_little_endian()
{
  short int word = 0x0001;
  char *byte = (char *) &word;
  return(byte[0] ? true : false);
}

uint16_t uint_swap( uint16_t i )
{
  if ( ! is_little_endian() )
  {
    return i;
  } else {
    uint8_t b1, b2;
    b1 = i & 255;
    b2 = ( i >> 8 ) + 255;
    return ( b1 << 8 ) + b2;
  }
}

uint32_t uint_swap( uint32_t i )
{
  if ( ! is_little_endian() )
  {
    return i;
  } else {
    uint8_t b1, b2, b3, b4;
    b1 = i & 255;
    b2 = ( i >> 8 ) & 255;
    b3 = ( i >> 16 ) & 255;
    b4 = ( i >> 24 ) & 255;
    return ( b1 << 24 ) + ( b2 << 16 ) + ( b3 << 8 ) + b4;
  }
}

namespace zorba{

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

ReplyMessage::~ReplyMessage()
{
  delete theReplyContent;
}

Byte * ReplyMessage::serialize( Length & aLength ) const
{
  aLength = MESSAGE_SIZE;
  Byte * lHeader = reinterpret_cast< Byte * > ( theHeaderContent );
  Byte * lReply  = reinterpret_cast< Byte * > ( theReplyContent );
  //Harcoded value to avoid padding on sizeof(HeaderContent)
  Byte * lMsg = new Byte[ SIZE_OF_HEADER_CONTENT + sizeof( ReplyContent ) ];
  memcpy( lMsg, lHeader, SIZE_OF_HEADER_CONTENT );
  memcpy( lMsg + SIZE_OF_HEADER_CONTENT, lReply, sizeof( ReplyContent ) );
  return lMsg;
}

bool ReplyMessage::isValidMessage() const
{
  //Logic of the reply packet
  //TODO: implement the logic of the message
  return true;
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
AbstractCommandMessage::AbstractCommandMessage( const CommandSet aCommandSet, const Command aCommand ): AbstractMessage( ++theLastId, NULL_FLAG )
{
  theCommandContent = new CommandContent();
  setCommandSet( aCommandSet );
  setCommand( aCommand );
  setLength( MESSAGE_SIZE );
}

AbstractCommandMessage::AbstractCommandMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractMessage( aMessage )
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
            getCommand() == SUSPENDED || getCommand() == RESUMED );
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
      getCommand() == COLLECTIONS );
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

SetMessage::SetMessage( const std::vector<QueryLoc> &aLocation ):
  AbstractCommandMessage( BREAKPOINTS, SET ), theLocations( aLocation )
{
  setLength( MESSAGE_SIZE + getData().length() );  
}


SetMessage::SetMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  boost::any lData = json::parse( &lMessage[0], &lMessage[ aLength - MESSAGE_SIZE ] );
    if ( lData.type() == typeid( json::object ) )
    {
      json::object const & lObject = boost::any_cast< json::object >( lData );
      json::array const & arr = boost::any_cast< json::array >( (*(lObject.begin())).second );
      for ( json::array::const_iterator it = arr.begin(); it != arr.end(); ++it )
      {
        json::object lQueryLoc = boost::any_cast< json::object >( *it );
        QueryLoc loc;
        loc.fromJSON( lQueryLoc );
        theLocations.push_back( loc );
      }
    } else {
      throw MessageFormatException("Invalid JSON format for Set breakpoint message.");
    }
    //setLength( MESSAGE_SIZE + getData().length() );  
    checkIntegrity();
}

SetMessage::~SetMessage(){}

Byte * SetMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() ];
 // memset(lMsg, '\0', getLength());
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
  lJSONString << theLocations.at(0).toJSON();
  for(unsigned int i=1; i<theLocations.size(); i++)
  {
    lJSONString << "," << theLocations.at(i).toJSON();
  }
  lJSONString << "]}";
  return lJSONString.str();
}

/**
 * Clear Breakpoints message
 */
ClearMessage::ClearMessage(): AbstractCommandMessage( BREAKPOINTS, CLEAR ){}

ClearMessage::ClearMessage( const std::vector<QueryLoc> &aLocation ):
  AbstractCommandMessage( BREAKPOINTS, CLEAR ), theLocations( aLocation )
{
  setLength( MESSAGE_SIZE + getData().length() );  
}


ClearMessage::ClearMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  boost::any lData = json::parse( &lMessage[0], &lMessage[ aLength - MESSAGE_SIZE ] );
    if ( lData.type() == typeid( json::object ) )
    {
      json::object const & lObject = boost::any_cast< json::object >( lData );
      json::array const & arr = boost::any_cast< json::array >( (*(lObject.begin())).second );
      for ( json::array::const_iterator it = arr.begin(); it != arr.end(); ++it )
      {
        json::object lQueryLoc = boost::any_cast< json::object >( *it );
        QueryLoc loc;
        loc.fromJSON( lQueryLoc );
        theLocations.push_back( loc );
      }
    } else {
      throw MessageFormatException("Invalid JSON format for Set Clear message.");
    }
    //setLength( MESSAGE_SIZE + getData().length() );  
    checkIntegrity();
}

ClearMessage::~ClearMessage(){}

Byte * ClearMessage::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() ];
 // memset(lMsg, '\0', getLength());
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
  lJSONString << "{\"breakpoints\":[";
  lJSONString << theLocations.at(0).toJSON();
  for(unsigned int i=1; i<theLocations.size(); ++i)
  {
    lJSONString << "," << theLocations.at(i).toJSON();
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
  //std::cerr << "Length:" <<  l << std::endl;
  //std::cerr << "String:" << getData() << std::endl;
  setLength( l );
  checkIntegrity();
}

SuspendedEvent::SuspendedEvent( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength )
{
  char * lMessage = reinterpret_cast< char * >( aMessage + MESSAGE_SIZE );
  boost::any lData = json::parse( &lMessage[0], &lMessage[ aLength - MESSAGE_SIZE ] );
  
    if ( lData.type() == typeid( json::object ) )
    {
      json::object const & obj = boost::any_cast< json::object >( lData );
      for ( json::object::const_iterator it = obj.begin(); it != obj.end(); ++it )
      {
        std::string attrName = (*it).first;
        if ( attrName == "cause" ) {
          int lCause = boost::any_cast< int >( (*it).second );
          theCause = lCause;
        } else if ( attrName == "location" ) {
          json::object lQueryLoc = boost::any_cast< json::object >( (*it).second );
          theLocation.fromJSON( lQueryLoc );
        }
      }
    } else {
      throw MessageFormatException("Invalid JSON format for SuspendedEvent message.");
    }
  checkIntegrity();
}

SuspendedEvent::~SuspendedEvent(){}

Byte * SuspendedEvent::serialize( Length & aLength ) const
{
  Byte * lHeader = AbstractCommandMessage::serialize( aLength );
  std::string lJSONString = getData();
  Byte * lMsg = new Byte[ getLength() ];
 // memset(lMsg, '\0', getLength());
  memcpy( lMsg, lHeader, MESSAGE_SIZE );
  const char * s = lJSONString.c_str();
  unsigned int l = lJSONString.length();
  //memcpy( lMsg + MESSAGE_SIZE, s, l - 1 );
  memcpy( lMsg + MESSAGE_SIZE, s, l );
  delete[] lHeader;
  aLength = getLength();
  return lMsg; 
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
 * Variable Message
 */
VariableMessage::VariableMessage():
  AbstractCommandMessage( DYNAMIC, VARIABLES )
{
  checkIntegrity();
}

VariableMessage::VariableMessage( Byte * aMessage, const unsigned int aLength ):
  AbstractCommandMessage( aMessage, aLength ){}

VariableMessage::~VariableMessage(){}
}//end of namespace

