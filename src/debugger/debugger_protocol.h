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

#ifndef ZORBA_DEBUGGER_PROTOCOL_H
#define ZORBA_DEBUGGER_PROTOCOL_H

#include <string>
#include <map>

#include "zorba/zorba_string.h"

#include "debugger_common.h"


namespace zorba {

typedef uint32_t Id;

class DebuggerCommand {

  private:
    std::string theName;
    std::map<std::string, std::string> theArgs;
    std::string theData;

  public:
    DebuggerCommand(std::string& command);

    bool
    getArg(std::string arg, std::string& value);

    bool
    getArg(std::string arg, int& value);

    std::string&
    getName() { return theName; }

    std::string&
    getData() { return theData; }

};

} // namespace zorba

#endif // ZORBA_DEBUGGER_PROTOCOL_H
