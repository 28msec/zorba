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
#ifndef ZORBA_DEBUGGER_SERVER_H
#define ZORBA_DEBUGGER_SERVER_H

#include <string>
#include <ostream>
#include <list>

#include "zorbatypes/zstring.h"

#include "debugger_common.h"
#include "debugger_protocol.h"


struct Zorba_SerializerOptions;
typedef struct Zorba_SerializerOptions Zorba_SerializerOptions_t;

namespace zorba {

class DebuggerCommunicator;
class DebuggerRuntime;
class XQueryImpl;
typedef Zorba_SerializerOptions_t* (*itemHandler)(void* aUserData);

class DebuggerServer {
  public:
    DebuggerServer(
      XQueryImpl*               query,
      Zorba_SerializerOptions&  serializerOptions,
      std::ostream&             ostream,
      itemHandler               handler,
      void*                     callbackData,
      const std::string&        host,
      unsigned short            port);

    virtual ~DebuggerServer();

  public:
    virtual bool
    run();

    void
    throwError();

  private:

    std::string
    processCommand(DebuggerCommand command);

    std::string
    buildErrorResponse(
      int transactionID,
      std::string commandName,
      int errorCode,
      std::string errorMessage);

    std::string
    getVariableName(std::string& aFullName);

    void
    buildProperty(
      std::string& fullName,
      std::string& name,
      std::string& type,
      std::ostream& stream);

    void
    buildChildProperties(
      std::string& name,
      std::list<std::pair<zstring, zstring> >& children,
      std::ostream& stream);

    bool
    getEnvVar(const std::string& name, std::string& value);

    void
    init();

  private:

    DebuggerCommunicator* theCommunicator;
    DebuggerRuntime*      theRuntime;

  };
}

#endif // ZORBA_DEBUGGER_SERVER_H
