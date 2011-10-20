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
#include "command_prompt.h"

#include <string>
#include <vector>
#include <map>
#include <iostream>

#include "command.h"


namespace zorba { namespace debugger {

CommandPrompt::~CommandPrompt()
{
  std::map<std::string, UntypedCommand*>::iterator lIter;
  for (lIter = theCommands.begin(); lIter != theCommands.end(); ++lIter) {
    delete lIter->second;
  }
}

void
CommandPrompt::execute()
{
  for (;;) {
    std::cout << "(xqdb) ";
    std::string lCommand;
    std::getline(std::cin, lCommand);
    std::vector<std::string> args;
    // we define the << operator to split the command (see below)
    parseLine(lCommand, args);
    if (args.size() == 0) {
      continue;
    }
    std::map<std::string, UntypedCommand*>::iterator lIter = theCommands.find(args[0]);
    if (lIter == theCommands.end()) {
      std::cout << args[0] << ": Command not found" << std::endl;
      continue;
    }
    if (!lIter->second->execute(args)) {
      continue;
    }
    return;
  }
}
  
CommandPrompt&
CommandPrompt::operator<<(UntypedCommand *aCommand)
{
  theCommands.insert(std::make_pair(aCommand->get_name(), aCommand));
  return *this;
}

void
CommandPrompt::parseLine(const std::string& aLine, std::vector<std::string>& aVector)
{
  std::string::size_type lBefore = 0;
  std::string::size_type lPos = aLine.find_first_of(" \t", 0);

  while (lPos != aLine.npos) {
    std::string lSub = aLine.substr(lBefore, lPos - lBefore);

    // if two consecutive spaces, you get an empty string here
    if (lSub != "") {
      if (lSub[0] == '"') {
        std::string::size_type lBeforeCopy = lBefore;
        do {
          lBeforeCopy = aLine.find("\"", lBeforeCopy + 1);
        } while (lPos != aLine.npos && aLine.size() > lPos + 1 && aLine[lPos + 1] == '\\');
        lPos = lBeforeCopy;
        lSub = aLine.substr(lBefore + 1, lPos - lBefore - 1);
      }
      aVector.push_back(lSub);
    }

    lBefore = lPos + 1;
    lPos = aLine.find_first_of(" \t", lBefore);
  }
  std::string lSub = aLine.substr(lBefore);

  // catching the case when the command ends with a space
  if (lSub == "") {
    return;
  }

  if (lSub[0] == '"') {
    lPos = aLine.find("\"", lBefore + 1);
    lSub = aLine.substr(lBefore + 1, lPos - lBefore - 1);
  }
  aVector.push_back(lSub);
}
  
} // namespace zorba
} // namespace debugger
