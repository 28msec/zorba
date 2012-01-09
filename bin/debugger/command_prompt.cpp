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

#ifdef ZORBA_HAVE_LIBEDIT_H
const char*
prompt(EditLine* aEl) {
  return "(xqdb) ";
}
#endif

CommandPrompt::CommandPrompt()
{
#ifdef ZORBA_HAVE_LIBEDIT_H
  theEditLine = el_init("xqdb", stdin, stdout, stderr);
  theHistory = history_init();
  HistEvent lHistoryEvent;
  history(theHistory, &lHistoryEvent, H_SETSIZE, 100);

  el_set(theEditLine, EL_PROMPT, prompt);

  el_set(theEditLine, EL_HIST, history, theHistory);
  el_set(theEditLine, EL_EDITOR, "emacs");
#endif
}

CommandPrompt::~CommandPrompt()
{
#ifdef ZORBA_HAVE_LIBEDIT_H
  history_end(theHistory);
  el_end(theEditLine);
#endif

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
      std::cout << "  " << (*lIter).first;
      std::set<std::string> lAliases = (*lIter).second->getAliases();
      std::set<std::string>::const_iterator lAliasIter = lAliases.begin();
      while (lAliasIter != lAliases.end()) {
        std::cout << ", " << *lAliasIter;
        lAliasIter++;
      }
      std::cout << std::endl;
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
#ifdef ZORBA_HAVE_LIBEDIT_H
    const char* lBuf;
    int lCharsRead = -1;
    lBuf = el_gets(theEditLine, &lCharsRead);
    std::string lCommandLine(lBuf, lCharsRead - 1);
#else
    std::cout << "(xqdb) ";
    std::string lCommandLine;
    std::getline(std::cin, lCommandLine);
#endif
    std::vector<std::string> lArgs;

    // split the command into arguments
    parseLine(lCommandLine, lArgs);
    std::string::size_type lSize = lArgs.size();

    // empty command? do nothing!
    if (lSize == 0) {
      lArgs = theLastArgs;
      if (lArgs.size() == 0) {
        continue;
      }
    }
#ifdef ZORBA_HAVE_LIBEDIT_H
    else {
      HistEvent lHistoryEvent;
      history(theHistory, &lHistoryEvent, H_ENTER, lCommandLine.c_str());
    }
#endif
    theLastArgs = lArgs;

    UntypedCommand* lCommand = NULL;

    // help is not a command but a hook here
    if (lArgs.at(0) == "h" || lArgs.at(0) == "help") {
      std::string lCmd = "";

      // if the user needs the help for a specific command
      if (lSize > 1) {
        // do nothing if we don't have a command starting with this prefix?
        // findCommand will print the appropriate errors
        if (!findCommand(lArgs[1], lCommand)) {
          continue;
        }
      }
      printHelp(lCommand);
      continue;
    }
    if (findCommand(lArgs[0], lCommand) && lCommand->execute(lArgs)) {
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

    bool lIsCandidate = false;

    // add this command to candidate commands if the prefix matches
    if ((*lIter).first.find(aPrefix) == 0) {
      lFoundCommands.push_back((*lIter).second);
      lIsCandidate = true;
    }

    // now process the aliases
    std::set<std::string> lAliases = (*lIter).second->getAliases();
    std::set<std::string>::const_iterator lAliasIter = lAliases.begin();
    while (lAliasIter != lAliases.end()) {
      // if a command alias is equal with the prefix, this is the command we want
      if (*lAliasIter == aPrefix) {
        aCommand = (*lIter).second;
        return true;
      }

      // add this command to candidate commands if the prefix matches one alias
      // and if the command is not already added 
      if (!lIsCandidate && (*lAliasIter).find(aPrefix) == 0) {
        lFoundCommands.push_back((*lIter).second);
        break;
      }
      lAliasIter++;
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
      UntypedCommand* lCommand = lFoundCommands.at(i);

      // commands
      if (lCommand->getName().find(aPrefix) == 0) {
        std::cout << "  " << lCommand->getName() << std::endl;
      }

      // and aliases
      std::set<std::string> lAliases = lCommand->getAliases();
      std::set<std::string>::const_iterator lAliasIter = lAliases.begin();
      while (lAliasIter != lAliases.end()) {
        if ((*lAliasIter).find(aPrefix) == 0) {
          std::cout << "  " << *lAliasIter << std::endl;
        }
        lAliasIter++;
      }
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
