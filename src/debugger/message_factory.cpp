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

#include "message_factory.h"
#include "util/stl_util.h"

namespace zorba {

  bool MessageFactory::checkMessage( Byte* aMessage )
  {
    try
    {
      switch ( aMessage[ MESSAGE_COMMAND_SET_FIELD_INDEX ] )
      {
      case 0:
        {
          if ( aMessage[ MESSAGE_FLAGS_FIELD_INDEX ] == REPLY_FLAG )
          {
            return true;
          }

          // Ignore the variable data flag at this point
          if ( (aMessage[ MESSAGE_FLAGS_FIELD_INDEX ]  == REPLY_VARIABLE_FLAG)
            || (aMessage[ MESSAGE_FLAGS_FIELD_INDEX ]  == (REPLY_VARIABLE_FLAG | VARIABLE_DATA_FLAG)) )
          {
            return true;
          }

          if( aMessage[MESSAGE_FLAGS_FIELD_INDEX]  == REPLY_SET_FLAG )
          {
            return true;
          }

          if( aMessage[MESSAGE_FLAGS_FIELD_INDEX] == REPLY_FRAME_FLAG )
          {
            return true;
          }

          if(aMessage[MESSAGE_FLAGS_FIELD_INDEX] == REPLY_LIST_FLAG)
          {
            return true;
          }
        }
      case EXECUTION:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case RUN:
            return true;
          case SUSPEND:
            return true;
          case RESUME:
            return true;
          case TERMINATE:
            return true;
          case DETACH:
            return true;
          case STEP:
            return true;
          }
        }
      case BREAKPOINTS:
        {
          switch( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case CLEAR:
            return true;
          case SET:
            return true;
          }
        }
      case ENGINE_EVENT:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case STARTED:
            return true;
          case TERMINATED:
            return true;
          case SUSPENDED:
            return true;
          case RESUMED:
            return true;
          case EVALUATED:
            return true;
          }
        }
      case STATIC:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case LIST:
            return true;
          }
        }
      case DYNAMIC:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case VARIABLES:
            return true;
          case EVAL:
            return true;
          case FRAME:
            return true;
          }
        }
      default:
        return false;
      } 
    } catch(MessageFormatException&) {
      return false;
    }
  }

AbstractMessage* MessageFactory::buildMessage(TCPSocket * aSocket)
{
  ztd::auto_vec<Byte> lBody(new Byte[MESSAGE_HEADER_SIZE]);
  memset(lBody.get(), '\0', MESSAGE_HEADER_SIZE);
  AbstractMessage* lMessage = 0;
  try {
    //read the packet length and write it into lLength
    if (aSocket->recv(lBody.get(), MESSAGE_HEADER_SIZE) == 0) {
      return 0;
    }

    if(!checkMessage(lBody.get())) {
      return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
    }

    Length length;
    if (is_little_endian()) {
      length = 
          lBody[3] |
          lBody[2] << 8 |
          lBody[1] << 16 |
          lBody[0] << 24;
    } else {
      length =
          lBody[0] |
          lBody[1] << 8 |
          lBody[2] << 16 |
          lBody[3] << 24;
    }
    // allocate memory for the whole packet
    ztd::auto_vec<Byte> lPacket(new Byte[length + 1]);
    memset(lPacket.get(), '\0', length + 1);
    memcpy(lPacket.get(), lBody.get(), MESSAGE_HEADER_SIZE);

    // read the data payload
    if (length > MESSAGE_HEADER_SIZE) {
      aSocket->recv(lPacket.get() + MESSAGE_HEADER_SIZE,
          length - MESSAGE_HEADER_SIZE);
    }

    // unserialize the packet
    lMessage =  MessageFactory::buildMessage(lPacket.get(), length);

  } catch (DebuggerSocketException &e) {
    synchronous_logger::cerr << e.what() << "\n";
    return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
  }
  return lMessage;
}

  AbstractMessage * MessageFactory::buildMessage( Byte * aMessage, const unsigned int aLength )
  {
    try
    {
      switch ( aMessage[ MESSAGE_COMMAND_SET_FIELD_INDEX ] )
      {
      case 0:
        {
          if ( aMessage[ MESSAGE_FLAGS_FIELD_INDEX ] == REPLY_FLAG )
          {
            return new ReplyMessage( aMessage, aLength );
          }

          if ( (aMessage[ MESSAGE_FLAGS_FIELD_INDEX ] == REPLY_VARIABLE_FLAG)
            || (aMessage[ MESSAGE_FLAGS_FIELD_INDEX ]  == (REPLY_VARIABLE_FLAG | VARIABLE_DATA_FLAG)) )
          {
            return new VariableReply( aMessage, aLength );
          }

          if( aMessage[MESSAGE_FLAGS_FIELD_INDEX]  == REPLY_SET_FLAG )
          {
            return new SetReply(aMessage, aLength);
          }

          if( aMessage[MESSAGE_FLAGS_FIELD_INDEX] == REPLY_FRAME_FLAG )
          {
            return new FrameReply(aMessage, aLength);
          }

          if (aMessage[MESSAGE_FLAGS_FIELD_INDEX] == REPLY_LIST_FLAG)
          {
            return new ListReply(aMessage, aLength);
          }
        }
      case EXECUTION:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case RUN:
            return new RunMessage( aMessage, aLength );
          case SUSPEND:
            return new SuspendMessage( aMessage, aLength );
          case RESUME:
            return new ResumeMessage( aMessage, aLength );
          case TERMINATE:
            return new TerminateMessage( aMessage, aLength );
          case DETACH:
            return new DetachMessage( aMessage, aLength );
          case STEP:
            return new StepMessage( aMessage, aLength );
          }
        }
      case BREAKPOINTS:
        {
          switch( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case CLEAR:
            return new ClearMessage( aMessage, aLength );
          case SET:
            return new SetMessage( aMessage, aLength );
          }
        }
      case ENGINE_EVENT:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
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
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case LIST:
            return new ListCommand(aMessage, aLength);
          }
        }
      case DYNAMIC:
        {
          switch ( aMessage[ MESSAGE_COMMAND_FIELD_INDEX ] )
          {
          case VARIABLES:
            return new VariableMessage( aMessage, aLength );
          case EVAL:
            return new EvalMessage( aMessage, aLength );
          case FRAME:
            return new FrameMessage( aMessage, aLength );
          }
        }
      default:
        {
          return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
        }
      } 
    } catch(MessageFormatException &e) {
      synchronous_logger::cerr << "The following error happened:\n";
      synchronous_logger::cerr << e.what() << "\n";
      return new ReplyMessage(0, DEBUGGER_ERROR_INVALID_MESSAGE_FORMAT);
    }
  }
}
