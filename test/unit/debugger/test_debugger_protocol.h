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

#ifndef ZORBA_TEST_DEBUGGER_SERIALIZATION_CLIENT_H
#define ZORBA_TEST_DEBUGGER_SERIALIZATION_CLIENT_H
#include <string>

#include "debugger/message_factory.h"

namespace zorba
{
  template<class T>
  bool test_packet( AbstractMessage * aMessage );
  
  class TestDebuggerSerialization
  {
    public:
      bool testReplyMessageOk();

      bool testReplyMessage();
      
      bool testRunMessage();

      bool testResumeMessage();
    
      bool testSuspendMessage();
    
      bool testTerminateMessage();

      bool testStepIntoMessage();
    
      bool testStepOutMessage();
    
      bool testStepOverMessage();

      bool testStartedEvent();

      bool testTerminatedEvent();

      bool testSuspendedEvent();

      bool testResumedEvent();

      bool testClearMessage();

      bool testSetMessage();

      bool testEvalMessage();

      bool testVariableMessage();
  };
}
#endif
