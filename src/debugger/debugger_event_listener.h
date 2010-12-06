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
#ifndef DEBUGGER_EVENT_LISTENER_H
#define DEBUGGER_EVENT_LISTENER_H

#include "zorbautils/runnable.h"

namespace zorba {

class DebuggerClientImpl;

class DebuggerEventListener : public Runnable {

  public:

    DebuggerEventListener(DebuggerClientImpl* aClient);

    virtual ~DebuggerEventListener();

	public:

    void run();

    void finish();

  private:

    DebuggerClientImpl* theClient;

};
}

#endif // DEBUGGER_EVENT_LISTENER_H
