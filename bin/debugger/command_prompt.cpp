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
CommandPrompt::printHelp(UntypedCommand* aCommand)
{
  // if no command is provided, print all the available commands
  if (!aCommand) {
    std::cout << "Available commands:" << std::endl;

    // print the names of all commands
    std::map<std::string, UntypedCommand*>::iterator lIter = theCommands.begin();
    while (lIter != theCommands.end()) {
      std::cout << "  " << (*lIter).first << std::endl;
      lIter++;
    }

    // some hints for detailed help
    std::cout << std::endl;
    std::cout << "Type help <command> to get more information about one command." << std::endl;
    std::cout << std::endl;
  } else {
    // ok, so we have a command; then print the help
    aCommand->printHelp();
  }
}

void
CommandPrompt::execute()
{
  for (;;) {
    std::cout << "(xqdb) ";
    std::string lCommandLine;
    std::getline(std::cin, lCommandLine);
    std::vector<std::string> args;

    // split the command into arguments
    parseLine(lCommandLine, args);
    std::string::size_type lSize = args.size();

    // empty command? do nothing!
    if (lSize == 0) {
      continue;
    }

    UntypedCommand* lCommand = NULL;

    // help is not a command but a hook here, so please do not add commands that have
    // "h" or "help" as prefix, or you will get the help instead of that command
    if (args.at(0) == "h" || args.at(0) == "help") {
      std::string lCmd = "";

      // if the user needs the help for a specific command
      if (lSize > 1) {
        // do nothing if we don't have a command starting with this prefix?
        // findCommand will print the appropriate errors
        if (!findCommand(args[1], lCommand)) {
          continue;
        }
      }
      printHelp(lCommand);
      continue;
    }
    if (findCommand(args[0], lCommand) && lCommand->execute(args)) {
      return;
    }
    continue;
  }
}
  
CommandPrompt&
CommandPrompt::operator<<(UntypedCommand *aCommand)
{
  theCommands.insert(std::make_pair(aCommand->getName(), aCommand));
  return *this;
}

bool
CommandPrompt::findCommand(const std::string& aPrefix, UntypedCommand*& aCommand)
{
  std::vector<UntypedCommand*> lFoundCommands;

  std::map<std::string, UntypedCommand*>::iterator lIter = theCommands.begin();
  while (lIter != theCommands.end()) {
    // if a command name is equal with the prefix, this is the command we want
    if ((*lIter).first == aPrefix) {
      aCommand = (*lIter).second;
      return true;
    }
    if ((*lIter).first.find(aPrefix) == 0) {
      lFoundCommands.push_back((*lIter).second);
    }
    lIter++;
  }

  if (lFoundCommands.empty()) {
    std::cout << "Command not found: " << aPrefix << std::endl;
    return false;
  }

  if (lFoundCommands.size() > 1) {
    std::cout << "Ambigous command: " << aPrefix << std::endl;
    // show all possible commands that start with this prefix
    for (std::string::size_type i = 0; i < lFoundCommands.size(); i++) {
      std::cout << "  " << lFoundCommands.at(i)->getName() << std::endl;
    }
    return false;
  }

  aCommand = lFoundCommands[0];
  return true;
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
