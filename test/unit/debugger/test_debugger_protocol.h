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
#include <cassert>
#include <string>

#include "debugger/message_factory.h"

namespace zorba
{
  template<class T>
  void test_packet( AbstractCommandMessage * aMessage );
  
  class TestDebuggerSerialization
  {
    public:
      void testRunMessage();

      void testResumeMessage();
    
      void testSuspendMessage();
    
      void testTerminateMessage();
    
      void testStepIntoMessage();
    
      void testStepOutMessage();
    
      void testStepOverMessage();

      void testStartedEvent();

      void testTerminatedEvent();

      void testSuspendedEvent();

      void testResumedEvent();

      void testClearMessage();

      void testSetMessage();
  };
}
#endif
