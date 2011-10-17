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
#include <iostream>
#include "debug_client/debug_command.h"

namespace zorba { namespace debugclient {
  
  
  void CommandLine::execute()
  {
    for (;;) {
      std::cout << "xqdb>> ";
      std::string command;
      std::getline(std::cin, command);
      std::vector<std::string> args;
      // we define the << operator to split the command (see below)
      args << command;
      if (args.size() == 0) {
        continue;
      }
      std::map<std::string, UntypedCommand*>::iterator lIter = theCommands.find(args[0]);
      if (lIter == theCommands.end()) {
        std::cout << args[0] << ": Command not found" << std::endl;
        continue;
      }
      if (!lIter->second->execute(args))
        continue;
      return;
    }
  }
  
  
  CommandLine::~CommandLine()
  {
    for (std::map<std::string, UntypedCommand*>::iterator i = theCommands.begin();
         i != theCommands.end(); ++i)
    {
      delete i->second;
    }
  }
  
  CommandLine& CommandLine::operator<<(UntypedCommand *aCommand)
  {
    theCommands.insert(std::make_pair(aCommand->get_name(), aCommand));
    return *this;
  }
}}

namespace std {
  vector<string>& operator<< (vector<string>& vec, const string& str)
  {
    string::size_type before = 0;
    string::size_type pos = str.find_first_of(" \t", 0);
    while (pos != str.npos) {
      std::string lSub = str.substr(before, pos - before);

      // if two consecutive spaces, you get an empty string here
      if (lSub != "") {
        if (lSub[0] == '"') {
          std::string::size_type lBeforeCopy = before;
          do {
            lBeforeCopy = str.find("\"", lBeforeCopy + 1);
          } while (pos != str.npos && str.size() > pos + 1 && str[pos + 1] == '\\');
          pos = lBeforeCopy;
          lSub = str.substr(before + 1, pos - before - 1);
        }
        vec.push_back(lSub);
      }

      before = pos + 1;
      pos = str.find_first_of(" \t", before);
    }
    std::string lSub = str.substr(before);

    // catching the case when the command ends with a space
    if (lSub == "") {
      return vec;
    }

    if (lSub[0] == '"') {
      pos = str.find("\"", before + 1);
      lSub = str.substr(before + 1, pos - before - 1);
    }
    vec.push_back(lSub);
    return vec;
  }
  
  set<string>& operator<< (set<string>& vec, const string& str)
  {
    string::size_type before = 0;
    string::size_type pos = str.find(" ", 0);
    while (pos != str.npos) {
      vec.insert(str.substr(before, pos));
      before = pos + 1;
      pos = str.find(" ", before);
    }
    vec.insert(str.substr(before));
    return vec;
  }

}
