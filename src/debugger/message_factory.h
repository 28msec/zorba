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

#ifndef ZORBA_DEBUGGER_MESSAGE_FACTORY_H
#define ZORBA_DEBUGGER_MESSAGE_FACTORY_H

#include <iostream>

#include <zorba/debugger_exception.h>

#include "debugger/socket.h"
#include "debugger/utils.h"
#include "debugger/debugger_protocol.h"

#include "synchronous_logger.h"

namespace zorba
{
/**
 * Zorba Debugger message factory
 * TODO: Check error handling 
 *
 * This class is marked as public for testing purposes
 */
class ZORBA_DLL_PUBLIC MessageFactory
{
  public:
    static bool checkMessage(Byte* aMessage);
    static AbstractMessage* buildMessage(TCPSocket * aSocket);
    static AbstractMessage * buildMessage(
      Byte * aMessage, const unsigned int aLength);
};

}//end of zorba namespace

#endif // ZORBA_DEBUGGER_MESSAGE_FACTORY_H
