#include <iostream>
#include <memory>

#include <boost/thread/thread.hpp>
#include <boost/bind.hpp>

#include  <zorba/zorba.h>

#include  "debugger/debugger_serverimpl.hpp"

#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"
//#include "zorba/properties.h"

#include "debugger/socket.hpp"
#include "debugger/message_factory.hpp"

#include "zorbatypes/numconversions.h"

boost::mutex io_mutex;

namespace zorba{

ZorbaDebuggerImpl::~ZorbaDebuggerImpl()
{
  delete theRequestServerSocket;
  delete theEventSocket;
}

void ZorbaDebuggerImpl::start( std::istream * aQuery, const String & aFileName, unsigned short aRequestPortno, unsigned short aEventPortno)
{
  TCPSocket * lSock;
  try
  {
    //Set the query to process
    theQuery = aQuery;
    //Set the fileName
    theFileName = aFileName; 
    //activate the debug mode
    theDebugMode = true;
    
    //Run the server 
    theRequestServerSocket = new TCPServerSocket( aRequestPortno );
    theEventPortno = aEventPortno;

    //Wait for a client to connect
    lSock = theRequestServerSocket->accept(); 
    //Connect the client to the event server
    theEventSocket = new TCPSocket( "127.0.0.1", theEventPortno );
    
    //Perform handshake
    handshake( lSock );
    //delete lSock;
    //Until the query execution has ended
    while ( theStatus != QUERY_TERMINATED )
    {
      //Wait for the client to connect
      //TCPSocket * lSock = theRequestServerSocket->accept();
      handleTcpClient( lSock );
      //delete lSock;
    }
  } catch( std::exception &e ) {
    std::cerr << e.what() << std::endl;
  }
  delete lSock;
  //exit( 0 );
}

void ZorbaDebuggerImpl::setStatus( ExecutionStatus Status, SuspensionCause aCause ){
  theStatus = Status;
  switch ( theStatus )
  {
    case QUERY_RUNNING:
      startedEvent();
      break;
    case QUERY_SUSPENDED:
      suspendedEvent( theLocation, aCause );
      break;
    case QUERY_TERMINATED:
      terminatedEvent();
      break;
    case QUERY_RESUMED:
      resumedEvent();
      break;
  }
}

void ZorbaDebuggerImpl::sendEvent( AbstractCommandMessage * aMessage )
{
    Length length;
    Byte * lMessage = aMessage->serialize( length );
    try
    {
      theEventSocket->send( lMessage, length );
    } catch( SocketException &e ) {
      std::cerr << e.what() << std::endl;
    }
    delete[] lMessage;
}


void ZorbaDebuggerImpl::startedEvent()
{
#ifndef NDEBUG
    std::cerr << "Send a started event" << std::endl;
#endif
    StartedEvent lMessage;
    sendEvent( &lMessage );
}

void ZorbaDebuggerImpl::suspendedEvent( QueryLoc &aLocation, SuspensionCause aCause )
{
#ifndef NDEBUG
    std::cerr << "Send a suspended event" << std::endl;
#endif
    SuspendedEvent lMessage( aLocation, aCause );
    sendEvent( &lMessage );
}

void ZorbaDebuggerImpl::resumedEvent()
{
#ifndef NDEBUG
    std::cerr << "Send a resumed event" << std::endl;
#endif
    ResumedEvent * lMessage = new ResumedEvent();
    sendEvent( lMessage );
    delete lMessage;
}

void ZorbaDebuggerImpl::terminatedEvent()
{
#ifndef NDEBUG
    std::cerr << "Send a terminated event" << std::endl;
#endif
    TerminatedEvent lMessage;
    sendEvent( &lMessage );
}

void ZorbaDebuggerImpl::run( std::istream * aQuery )
{
  setStatus( QUERY_RUNNING );
  ResultIterator_t lIterator;
  try
  {
    Zorba * lZorba = Zorba::getInstance();
    XQuery::CompilerHints lCompilerHints;
    lCompilerHints.opt_level = XQuery::CompilerHints::O0;
    XQuery_t lQuery =  lZorba->createQuery();
    lQuery->setFileName( theFileName );
    lQuery->compile( *aQuery, lCompilerHints ); 
    lIterator = lQuery->iterator();
    lIterator->open();
    Item lItem;
    while ( lIterator->next( lItem ) )
    {
      std::cout << lItem.getStringValue() << std::endl;
    }
    lZorba->shutdown();
  } catch ( StaticException& se ) {
    std::cerr << se << std::endl;
  } catch ( DynamicException& de ) {
    std::cerr << de << std::endl;
  } 
  lIterator->close();
  setStatus( QUERY_TERMINATED );
}

bool ZorbaDebuggerImpl::isEnabled() const
{
  return theDebugMode;
}

bool ZorbaDebuggerImpl::hasToSuspend()
{
  if( theStatus == QUERY_SUSPENDED )
  {
    return true;
  }

  for( unsigned int i = 0; i < theBreakpoints.size(); i++ )
  {
    if( theLocation.getFilename() == theBreakpoints.at( i ).getFilename()
        && theLocation.getLineno() == theBreakpoints.at( i ).getLineno() )
    {
      setStatus( QUERY_SUSPENDED, CAUSE_BREAKPOINT );
      return true;
    }
  }

  return false;
}

/**
 * Perform an handshake with the client.
 * Simply returns the received first 11 bytes.
 */
void ZorbaDebuggerImpl::handshake( TCPSocket * aSock )
{
  Byte * msg = new Byte[11];
  try
  {
    aSock->recv( msg, 11 );
    aSock->send( msg, 11 );
  } catch( SocketException &e ) {
    std::cerr << e.what() << std::endl;
  }
  delete[] msg;
}

/**
 * TODO: check if the client has closed the connection
 */
void ZorbaDebuggerImpl::handleTcpClient( TCPSocket * aSock )
{
    Byte * lByteMessage;
    AbstractMessage * lMessage;
    ReplyMessage * lReplyMessage;
    Length length;
    try
    {
    lMessage = MessageFactory::buildMessage( aSock );
    
    AbstractCommandMessage * lCommandMessage = dynamic_cast< AbstractCommandMessage * > ( lMessage );
    
    if ( lCommandMessage )
    {
#ifndef NDEBUG
      std::cerr << "Received a command" << std::endl;
#endif
      //Send the reply message
      lReplyMessage = lCommandMessage->getReplyMessage();
      lByteMessage = lReplyMessage->serialize( length );
      aSock->send( lByteMessage, length );
      //process the command message
      processMessage( lCommandMessage );
    } else {
#ifndef NDEBUG
      std::cerr << "Received something wrong" << std::endl;
#endif
      //If something goes wrong, buildMessage() receive a Reply Message containing the error description
      //Send it back to the client right away
      lReplyMessage = dynamic_cast<ReplyMessage *> ( lMessage );
      if( lReplyMessage ){
        lByteMessage = lReplyMessage->serialize( length );
        aSock->send( lByteMessage, length );
      } else {
        std::cerr << "Internal error occured. Couldn't send the error message." << std::endl;
      }
    }    
  } catch ( std::exception &e ) {
    std::cerr << e.what() << std::endl;
  }
  delete[] lByteMessage;
  delete lMessage;
  delete lReplyMessage;
}

void ZorbaDebuggerImpl::run()
{
#ifndef NDEBUG
  std::cout << "Status is now running" << std::endl;
#endif
  boost::thread theRuntimeThread (
      boost::bind( &ZorbaDebuggerImpl::run, this, theQuery ) );
}

void ZorbaDebuggerImpl::suspend()
{
#ifndef NDEBUG
  std::cout << "Status is now suspended" << std::endl; 
#endif
  setStatus( QUERY_SUSPENDED );
}

void ZorbaDebuggerImpl::resume()
{
#ifndef NDEBUG
  std::cout << "Status is now running" << std::endl;
#endif
// boost::mutex::scoped_lock lock(theRuntimeMutex);
  setStatus( QUERY_RUNNING );
  theRuntimeSuspendedCV.notify_one();
}

void ZorbaDebuggerImpl::terminate()
{
#ifndef NDEBUG
  std::cout << "Status is now terminated" << std::endl;
#endif
  setStatus( QUERY_TERMINATED );
}

void ZorbaDebuggerImpl::processMessage(AbstractCommandMessage * aMessage)
{
  switch( aMessage->getCommandSet() )
  {
    case EXECUTION:
    {
      switch( aMessage->getCommand() )
      {
        case RUN:
        {
#ifndef NDEBUG
          RunMessage * lMessage = dynamic_cast<RunMessage *> ( aMessage );
          assert( lMessage );
#endif
          run();
          break;
        }
        case SUSPEND:
        {
#ifndef NDEBUG
          SuspendMessage * lMessage = dynamic_cast<SuspendMessage *> ( aMessage );
          assert( lMessage );
#endif
          suspend();
          break;
        }
        case RESUME:
        {
#ifndef NDEBUG
          ResumeMessage * lMessage = dynamic_cast<ResumeMessage*> ( aMessage );
          assert( lMessage );
#endif
          resume();
          break;
        }
        case TERMINATE:
        {
#ifndef NDEBUG
          TerminateMessage * lMessage = dynamic_cast<TerminateMessage *> ( aMessage );
          assert( lMessage );
#endif
          terminate();
          break;
        }
        case STEP:
        {
#ifndef NDEBUG
          StepMessage * lMessage = dynamic_cast<StepMessage *> ( aMessage );
          assert( lMessage );
          processMessage( lMessage );
#else
          processMessage( static_cast<StepMessage *> ( aMessage );
#endif
          break;
        }
        default: throw InvalidCommandException("Internal Error. Command not implemented.");
    }
      break;
    case BREAKPOINTS:
    {
      switch( aMessage->getCommand() )
      {
        case SET:
        {
          SetMessage * lMessage;
#ifndef NDEBUG
          lMessage = dynamic_cast< SetMessage * > ( aMessage );
          assert( lMessage );
#else
          lMessage =  static_cast< SetMessage * > ( aMessage );
#endif
          for( unsigned int i = 0; i < lMessage->getLocations().size(); i++ )
          {
            theBreakpoints.push_back( lMessage->getLocations().at( i ) ); 
          }
          break;
        }
        case CLEAR:
        {

        }
        default: throw InvalidCommandException("Internal Error. Command not implemented.");
      }
    }
      break;
    case ENGINE_EVENT:
    case STATIC:
    case DYNAMIC:
    default:
      throw InvalidCommandException("Internal Error. CommandSet not implemented.");
  }
}
};
}//end of namespace

