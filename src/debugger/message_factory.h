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
#include "debugger/utils.h"
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
      ZorbaArrayAutoPointer<Byte> lengthField(new Byte[ MESSAGE_HEADER_SIZE ]);
      memset( lengthField.get(), '0', MESSAGE_HEADER_SIZE );
      AbstractMessage * lMessage = 0;
      try
      {
        //read the packet length and write it into lLength
        aSocket->recv( lengthField.get(), MESSAGE_HEADER_SIZE );
        //Convert the length field into an integer
        Length length;
        if( is_little_endian() ){
          length = lengthField.get()[3] | lengthField.get()[2] |
                    lengthField.get()[1] | lengthField.get()[0];
        } else {
          length = lengthField.get()[0] | (lengthField.get()[1]<<8) |
                    (lengthField.get()[2]<<16) | (lengthField.get()[3]<<24);
        }
        length -= MESSAGE_HEADER_SIZE;
        //allocate memory for the whole packet
        ZorbaArrayAutoPointer<Byte> lPacket(new Byte[ length + MESSAGE_HEADER_SIZE ]);
        memcpy( lPacket.get(), lengthField.get(), MESSAGE_HEADER_SIZE );
        //read the command packet
        aSocket->recv ( lPacket.get() + MESSAGE_HEADER_SIZE, length );
        //unserialize the packet
        lMessage =  MessageFactory::buildMessage( lPacket.get(), length + MESSAGE_HEADER_SIZE );
      } catch ( SocketException &e ) {
        std::cerr << e.what() << std::endl;
      }
      return lMessage;
    }

    static AbstractMessage * buildMessage( Byte * aMessage, const unsigned int aLength )
    {
      try
      {
        switch ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_COMMAND_SET ] )
        {
          case 0:
          {
            if ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_FLAGS ] == REPLY_FLAG )
            {
              return new ReplyMessage( aMessage, aLength );
            }

            if ( aMessage[ MESSAGE_HEADER_SIZE + MESSAGE_FLAGS ] == REPLY_VARIABLE_FLAG )
            {
              return new VariableReply( aMessage, aLength );
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
              case EVALUATED:
                return new EvaluatedEvent( aMessage, aLength );
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
              case EVAL:
                return new EvalMessage( aMessage, aLength );
            }
          }
          default:
          {
            return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
          }
        } 
      } catch(MessageFormatException &e) {
          std::cerr << "The following error happened: " << std::endl;
          std::cerr << e.what() << std::endl;
          return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
      }
    }
};
}//end of zorba namespace
#endif /*ZORBA_DEBUGGER_MESSAGE_FACTORY_HPP_*/
