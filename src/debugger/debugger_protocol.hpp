#ifndef XQP_DEBUGGER_PROTOCOL_H
#define XQP_DEBUGGER_PROTOCOL_H

#include <errno.h>
#include <exception>
#include <string>
#include <sstream>
#include <ostream>
#include <istream>

#include "common/common.h"
#include "compiler/parser/query_loc.h"

#include "debugger/debugger_common.hpp"

/* Type definition of fields */
typedef uint8_t  Byte;
typedef uint32_t Length;
typedef uint32_t Id;
typedef uint8_t  Flags;
typedef uint16_t ErrorCode;
typedef uint8_t  CommandSet;
typedef uint8_t  Command;

/* sizeof(HeaderContent) == 12 because of the padding */
const int SIZE_OF_HEADER_CONTENT = 9;

/* Flags */
const Flags NULL_FLAG = 0x0;
const Flags REPLY_FLAG = 0x80;

/* CommandSet */
const CommandSet EXECUTION    = 0xf1;
const CommandSet BREAKPOINTS  = 0xf2;
const CommandSet STATIC       = 0xf3;
const CommandSet DYNAMIC      = 0xf4;
const CommandSet ENGINE_EVENT = 0xf8;

/* Execution Commands */
const Command RUN       = 0x01; 
const Command SUSPEND   = 0x02;
const Command RESUME    = 0x03;
const Command TERMINATE = 0x04;
const Command STEP      = 0x05;

/* Breakpoints Commands */
const Command SET   = 0x01;
const Command CLEAR = 0x02;

/* Engine events Commands */
const Command STARTED    = 0x01;
const Command TERMINATED = 0x02;
const Command SUSPENDED  = 0x03;
const Command RESUMED    = 0x04;

/* Static Commands */
const Command OPTIONS  = 0x01;
const Command DEFAULTS = 0x02;
const Command SETS     = 0x03;

/* Dynamic Commands */
const Command DATA        = 0x01;
const Command VARIABLES   = 0x02;
const Command FOCUS       = 0x03;
const Command TIME        = 0x04;
const Command DOCUMENTS   = 0x05;
const Command COLLECTIONS = 0x06;
const Command COLLECTION  = 0x07;

/* Error codes */
const ErrorCode DEBUGGER_NO_ERROR                      = 0x01;
const ErrorCode DEBUGGER_ERROR_EMPTY                   = 0x02;
const ErrorCode DEBUGGER_ERROR_UNKNOWN                 = 0x03;
const ErrorCode DEBUGGER_ERROR_INVALID_COMMAND         = 0x04;
const ErrorCode DEBUGGER_ERROR_COMMAND_NOT_IMPLEMENTED = 0x05;
const ErrorCode DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT  = 0x06;

/**
 * The header of the packet (containning the length of the whole packet) 
 * is set in 4 bytes
 */
const uint8_t MESSAGE_HEADER_SIZE = 4;
/* The minimum packet size is 7 bytes (+ 4 bytes of the header) */
const uint8_t MESSAGE_BODY_SIZE = 7;
/* The size of a message without data */
const uint8_t MESSAGE_SIZE = MESSAGE_HEADER_SIZE + MESSAGE_BODY_SIZE;
/* The packet id is set in 4 bytes */
const unsigned short MESSAGE_ID = 4;

/* The Flag is set at the index 4 of the packet */
const unsigned short MESSAGE_FLAGS = 4;
/* The Command Sets is at the index 5 of the packet */
const unsigned short MESSAGE_COMMAND_SET = 5;
/* The Command is at the index 6 of the packet */
const unsigned short MESSAGE_COMMAND = 6;
/* The data starts at the index 7 of the packet */
const unsigned short MESSAGE_DATA = 7;

/* deals with endianness */
bool is_little_endian();
uint16_t uint_swap( uint16_t i );
uint32_t uint_swap( uint32_t i );

namespace zorba{

/**
 *   Signals a problem with the debugging protocol.
 */
class MessageException : public std::exception
{
  public:
	  
    MessageException(const std::string &aMessage ) throw();
 
  /**
   *   Provided just to guarantee that no exceptions are thrown.
   */
    ~MessageException() throw();

  /**
     *   Get the exception message
     *   @return exception message
   */
    const char* what() const throw();

  private:
    std::string userMessage;  // Exception message
};

class MessageFormatException: public MessageException
{
  public:
    MessageFormatException( const std::string &aMessage ): MessageException( aMessage ){}
};

class InvalidCommandException: public MessageException
{
   public:
     InvalidCommandException( const std::string &aMessage ): MessageException( aMessage ){}

};

/**
 * Abstract representation of a packet
 * in the debugging protocol
 */
class AbstractMessage
{
  protected:

    virtual bool isValidMessage() const = 0;

    /*
     * check the integrity of the packet
     * throws an exception is something's wrong
     */
    void checkIntegrity();
    
    struct HeaderContent
    {
      Length theLength;
      Id theId;
      Flags theFlags;
    };

    HeaderContent * theHeaderContent;

    void setLength ( Length aLength ) { theHeaderContent->theLength = uint_swap( aLength ); }

    Length getLength() const { return uint_swap( theHeaderContent->theLength ); }

    void setId ( Id aId ) { theHeaderContent->theId = uint_swap( aId ); }

    void setFlags ( Flags aFlags ) { theHeaderContent->theFlags = aFlags; }


  public:

    AbstractMessage( const Id aId, const Flags aFlags );

    AbstractMessage( Byte *  aMessage );

    virtual ~AbstractMessage();

    virtual Byte * serialize( Length & aLength ) const = 0;

    const Id getId() const { return uint_swap( theHeaderContent->theId ); }

    const Flags getFlags() const { return theHeaderContent->theFlags; }
    //friend std::ostream& operator << ( std::ostream &os, const AbstractMessage * );
    
    bool operator == ( const AbstractMessage & );

    bool operator != ( const AbstractMessage & );
};

std::ostream& operator << ( std::ostream &os, const AbstractMessage * message);

/**
 * Abstract representation of a reply packet
 */
class ReplyMessage: public AbstractMessage
{
  protected:
	
    bool isValidMessage() const;

    struct ReplyContent
    {
      ErrorCode theErrorCode;      
    };

    ReplyContent * theReplyContent;

  public:
    ReplyMessage( const Id aId, const ErrorCode aErrorCode );

    virtual ~ReplyMessage();
    
    Byte * serialize( Length & aLength ) const;

    const ErrorCode getErrorCode() const { return uint_swap( theReplyContent->theErrorCode ); }


    void setErrorCode( ErrorCode aErrorCode ) { theReplyContent->theErrorCode = uint_swap( aErrorCode ); }
    
    const std::string getMessage()
    {
      switch ( getErrorCode() )
      {
        case DEBUGGER_NO_ERROR:
          return "No error";
        case DEBUGGER_ERROR_EMPTY:
          return "Error empy";
        case DEBUGGER_ERROR_INVALID_COMMAND:
          return "Invalid Command";
        case DEBUGGER_ERROR_COMMAND_NOT_IMPLEMENTED:
          return "Command not implemented";
        case DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT:
          return "Invalid message format";
        default:
          return "Unknown error";
      }
    }
};

/**
 * 
 */
class AbstractCommandMessage: public AbstractMessage
{
  private:
    static unsigned long theLastId;
  
  protected:

    struct CommandContent
    {
      CommandSet theCommandSet;
      Command theCommand;
    };

    CommandContent * theCommandContent;

    void setCommandSet( CommandSet aCommandSet ){ theCommandContent->theCommandSet = aCommandSet; }

    void setCommand( Command aCommand ){ theCommandContent->theCommand = aCommand; }

    bool isValidMessage() const;

    bool isExecutionCommand() const;

    bool isBreakpointsCommand() const;

    bool isEngineEventCommand() const;

    bool isStaticCommand() const;

    bool isDynamicCommand() const;

  public:

    /**
     * Compute and assemble a packet implementing the debugger protocol
     * @param id (4 bytes): The packet id
     * @param flags (1 byte)
     * @param command_set (1 byte)
     * @param command (1 byte)
     * @param data (variable)
     */
    AbstractCommandMessage( const CommandSet aCommandSet,
        const Command aCommand );

    AbstractCommandMessage( Byte * aMessage, const unsigned int aLength );

    virtual ~AbstractCommandMessage();
 
    const CommandSet getCommandSet() const { return theCommandContent->theCommandSet; }

    const Command getCommand() const { return theCommandContent->theCommand; }

    ReplyMessage * getReplyMessage() { return new ReplyMessage( getId(), DEBUGGER_NO_ERROR ); }

    Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class RunMessage: public AbstractCommandMessage
{
  public:
    RunMessage();

    RunMessage( Byte * aMessage, const unsigned int aLength ); 

    virtual ~RunMessage();
};


/**
 * 
 */
class SuspendMessage: public AbstractCommandMessage
{
  public:
    SuspendMessage();
    
    SuspendMessage( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~SuspendMessage();
};

/**
 * 
 */
class TerminateMessage: public AbstractCommandMessage
{
  public:
    TerminateMessage();

    TerminateMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~TerminateMessage();
};

/**
 * 
 */
class ResumeMessage: public AbstractCommandMessage
{
  public:
    ResumeMessage();
    
    ResumeMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~ResumeMessage();
};

/**
 * 
 */
class StepMessage: public AbstractCommandMessage
{
	protected:
		StepCommand theKind;

    bool isValidMessage() const;

	public:
	  StepMessage( const StepCommand aKind);
    
    StepMessage( Byte * aMessage, const unsigned int aLength ); 
    
    virtual ~StepMessage();

    const StepCommand getStepKind() const;

    Byte * serialize( Length &aLength ) const;
};

/**
 *
 */
class SetMessage: public AbstractCommandMessage
{
  protected:
    std::vector<QueryLoc> theLocations;
    std::string getData() const;

  public:

    SetMessage();

    SetMessage( const std::vector<QueryLoc> &aLocation );

    SetMessage( Byte * aMessage, const unsigned int aLength );

    void addLocation( QueryLoc &aLocation )
    {
      theLocations.push_back(aLocation);
      setLength( MESSAGE_SIZE + getData().length() );
    }

    std::vector< QueryLoc > getLocations()
    {
      return theLocations;
    }

    virtual ~SetMessage();

    Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class ClearMessage: public AbstractCommandMessage
{
  protected:
    std::vector<QueryLoc> theLocations;
    std::string getData() const;

  public:
    ClearMessage();

    ClearMessage( const std::vector<QueryLoc> &aLocation );

    ClearMessage( Byte * aMessage, const unsigned int aLength ); 

    void addLocation( QueryLoc & aLocation )
    {
      theLocations.push_back( aLocation );
      setLength( MESSAGE_SIZE + getData().length() );
    }
 
    virtual ~ClearMessage();

    Byte * serialize( Length & aLength ) const;
};

/**
 *
 */
class StartedEvent: public AbstractCommandMessage
{
  public:
    StartedEvent();
    
    StartedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~StartedEvent();
};

/**
 *
 */
class TerminatedEvent: public AbstractCommandMessage
{
  public:
    TerminatedEvent();
    
    TerminatedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~TerminatedEvent();
};

/**
 *
 */
class SuspendedEvent: public AbstractCommandMessage
{
  protected:
    QueryLoc theLocation;

    SuspensionCause theCause; 

    std::string getData() const;

  public:
    SuspendedEvent( const QueryLoc &aLocation, const SuspensionCause aCause = CAUSE_USER );
    
    SuspendedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~SuspendedEvent();

    Byte * serialize( Length & aLength ) const;

};

/**
 *
 */
class ResumedEvent: public AbstractCommandMessage
{
  public:
    ResumedEvent();
    
    ResumedEvent( Byte * aMessage, const unsigned int aLength ); 
   
    virtual ~ResumedEvent();
};

/**
 *
 */
class VariableMessage: public AbstractCommandMessage
{
  public:
    VariableMessage();

    VariableMessage( Byte * aMessage, const unsigned int aLength );

    virtual ~VariableMessage();

    //Byte * serialize( Length & aLength ) const;
};
}//end of namespace
#endif

