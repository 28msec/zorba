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

#ifndef ZORBA_DEBUGGER_MESSAGE_FACTORY
#define ZORBA_DEBUGGER_MESSAGE_FACTORY

#include <iostream>

#include "debugger/socket.h"
#include "debugger/debugger_protocol.h"

namespace zorba
{
/**
 * Zorba Debugger message factory
 * TODO: Check error handling 
 */
class MessageFactory
{
  public:

    static AbstractMessage * buildMessage( TCPSocket * aSocket )
    {
      Byte * lengthField = new Byte[ MESSAGE_HEADER_SIZE ];
      memset( lengthField, '\0', MESSAGE_HEADER_SIZE );
      Byte * lPacket = 0;
      AbstractMessage * lMessage = 0;
      try
      {
        //read the packet length and write it into lLength
        aSocket->recv( lengthField, MESSAGE_HEADER_SIZE );

        //Convert the length field into an integer
        Length length;
        if( is_little_endian() ){
          length = lengthField[3] | lengthField[2] |
                    lengthField[1] | lengthField[0];
        } else {
          length = lengthField[0] | (lengthField[1]<<8) |
                    (lengthField[2]<<16) | (lengthField[3]<<24);
        }
        length -= MESSAGE_HEADER_SIZE;
        //allocate memory for the whole packet
        lPacket = new Byte[ length + MESSAGE_HEADER_SIZE ];
        memcpy( lPacket, lengthField, MESSAGE_HEADER_SIZE );
        //read the command packet
        aSocket->recv ( lPacket + MESSAGE_HEADER_SIZE, length );
        //unserialize the packet
        lMessage =  MessageFactory::buildMessage( lPacket, length + MESSAGE_HEADER_SIZE );
      } catch ( SocketException &e ) {
        std::cerr << e.what() << std::endl;
      }
      delete[] lengthField;
      //TODO: make it beautiful
      if ( lPacket )
      {
        delete[] lPacket;
      }
      return lMessage;
    }

    static AbstractMessage * buildMessage( Byte * aMessage, const unsigned int aLength )
    {
      switch ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND_SET ] )
      {
        case 0:
        {
          if ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_FLAGS ] == REPLY_FLAG )
          {
            return new ReplyMessage( aMessage, aLength );
          }
        }
        case EXECUTION:
        {
          switch ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND ] )
          {
            case RUN:
              return new RunMessage( aMessage, aLength );
            case SUSPEND:
              return new SuspendMessage( aMessage, aLength );
            case RESUME:
              return new ResumeMessage( aMessage, aLength );
            case TERMINATE:
              return new TerminateMessage( aMessage, aLength );
            case STEP:
              return new StepMessage( aMessage, aLength );
            case QUIT:
              return new QuitMessage( aMessage, aLength );
          }
        }
        case BREAKPOINTS:
        {
          switch( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND ] )
          {
            case CLEAR:
              return new ClearMessage( aMessage, aLength );
            case SET:
              return new SetMessage( aMessage, aLength );
          }
        }
        case ENGINE_EVENT:
        {
          switch ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND ] )
          {
            case STARTED:
              return new StartedEvent( aMessage, aLength );
            case TERMINATED:
              return new TerminatedEvent( aMessage, aLength );
            case SUSPENDED:
              return new SuspendedEvent( aMessage, aLength );
            case RESUMED:
              return new ResumedEvent( aMessage, aLength );
            case QUITED:
              return new QuitedEvent( aMessage, aLength );
          }
        }
        case STATIC:
        {

        }
        case DYNAMIC:
        {
          switch ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND ] )
          {
            case VARIABLES:
              return new VariableMessage( aMessage, aLength );
          }
        }
        default:
        {
          //std::cerr << "Tried to build an invalid message" << std::endl;
          //unsigned int commandset = (unsigned int)aMessage[9];
          //unsigned int command = (unsigned int)aMessage[10];
          //std::cerr << "CommandSet:" << commandset << std::endl;
          //std::cerr << "Command:" << command << std::endl;
          return new ReplyMessage( 0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT );
        }
      }
    }
};
}//end of zorba namespace
#endif /*ZORBA_DEBUGGER_MESSAGE_FACTORY_HPP_*/
