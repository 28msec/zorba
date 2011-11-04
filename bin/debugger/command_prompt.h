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
#ifndef ZORBA_DEBUGGER_COMMAND_PROMPT_H
#define ZORBA_DEBUGGER_COMMAND_PROMPT_H

#include <string>
#include <map>
#include <vector>


namespace zorba { namespace debugger {

class UntypedCommand;

class CommandPrompt
{
  public:
    ~CommandPrompt();

  public:

    void execute();

    CommandPrompt& operator<< (UntypedCommand* command);

  private:

    void
    printHelp(UntypedCommand* command);

    bool
    findCommand(const std::string& prefix, UntypedCommand*& command);

    void
    parseLine(const std::string& line, std::vector<std::string>& vector);

  private:
    std::map<std::string, UntypedCommand*> theCommands;
};  

  
} // namespace zorba
} // namespace debugger

#endif // ZORBA_DEBUGGER_COMMAND_PROMPT_H
