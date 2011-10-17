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
#pragma once
#include <string>
#include <iostream>
#include <zorba/debugger_event_handler.h>
#include <zorba/static_context.h>
#include "lock_free_queue.h"

namespace zorba {
  class Zorba;
}

namespace zorba { namespace debugclient {
  
class EventHandler : public zorba::DebuggerEventHandler
{
  public:
    EventHandler(
      LockFreeProducer<std::size_t>& aQueue,
      LockFreeProducer<bool>& aContQueue);

    ~EventHandler();

  public:
    virtual void parseMessage(const std::string& aMessage);

    virtual void error(unsigned int errcode, const std::string& msg);

    virtual void init();

  private:
    LockFreeProducer<std::size_t>& theIdQueue;
    LockFreeProducer<bool>& theContinueProducer;
    void* theStore;
    Zorba* theZorbaInstance;
    StaticContext_t theStaticContext;

};
  
} // namespace zorba
} // namespace debugclient
