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
#ifndef ZORBA_DEBUGGER_SERVER_RUNNABLE
#define ZORBA_DEBUGGER_SERVER_RUNNABLE

#include <iostream>

#include "zorba/config.h"
#include "zorba/api_shared_types.h"
#include "zorbautils/runnable.h"
#include "zorba/options.h"

namespace zorba {

class DebuggerServerRunnable : public Runnable {

public:
    DebuggerServerRunnable(const XQuery_t& aQuery,
                           std::ostream&   aOutStream,
                           const std::string& aHost,
                           unsigned short  aPort,
                           const Zorba_SerializerOptions& aSerializerOptions);
    virtual ~DebuggerServerRunnable();

    virtual void
    run();

    virtual void
    finish();

private:
    XQuery_t       theQuery;
    std::ostream&  theOutStream;
    const std::string& theHost;
    unsigned short thePort;
    Zorba_SerializerOptions theSerializerOptions;

}; /* class DebuggerServerRunnable */

} /* namespace zorba */

#endif
