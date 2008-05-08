#ifndef ZORBA_TEST_DEBUGGER_SERIALIZATION_CLIENT_H
#define ZORBA_TEST_DEBUGGER_SERIALIZATION_CLIENT_H
#include <cassert>
#include <string>

#include "debugger/message_factory.hpp"

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
