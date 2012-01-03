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

#include "stdafx.h"

#include "debugger_protocol.h"

#include <map>
#include <string>
#include <sstream>


namespace zorba {

DebuggerCommand::DebuggerCommand(std::string& aCommand)
  : theData()
{
  // this implements the DBGP command specification:
  // http://xdebug.org/docs-dbgp.php#ide-to-debugger-engine-communications

  // the debugger client should only send space delimited command
  // and arguments, therefore we only check for space character
  std::size_t lNameEnd = aCommand.find(" ");

  // first whitespace delimited token is the command name
  theName = aCommand.substr(0, lNameEnd);

  std::string lArgs = aCommand.substr(lNameEnd + 1);

  bool lFollowsArg = true;
  bool lInArgName = false;
  bool lInArgValue = false;
  bool lInArgValueStr = false;
  std::stringstream lArgName;
  std::stringstream lArgValue;

  for (std::string::size_type i = 0; i < lArgs.length(); i++) {
    char c = lArgs.at(i);

    if (lFollowsArg) {
      switch (c) {
      case ' ':
      case '\t':
        // if whitespace while reading arg name, stop and add argument
        if (lInArgName) {
          lFollowsArg = false;
          lInArgName = false;
          theArgs[lArgName.str()] = "";
        }
        continue;
      case '-':
        if (!lInArgName) {
          lInArgName = true;
          continue;
        }
        // we found the encoded data in this message
        if (lArgName.str() == "") {
          // DBGP is fuzzy here: can there be whitespaces between "--" and the encoded data?
          // so, tollerate the whitespaces before data starts
          std::string::size_type lDataBegin = i + 1;
          while (++i < lArgs.size()) {
            switch (lArgs.at(i)) {
            case ' ':
            case '\t':
              continue;
            default:
              lDataBegin = i;
              // force the while to terminate
              i = lArgs.size();
            }
          }

          theData = lArgs.substr(lDataBegin);
        }

      default:
        if (!lInArgName) {
          throw "error reading command";
        }
        lArgName << c;
        continue;
      }

    } else {
      switch (c) {
      case ' ':
      case '\t':
        // skip whitespaces before the arg value
        if (!lInArgValue) {
          continue;
        }
        if (lInArgValueStr) {
          lArgValue << c;
        } else {
          lInArgValue = false;
          lFollowsArg = true;
          theArgs[lArgName.str()] = lArgValue.str();
          lArgName.clear();
          lArgName.str("");
          lArgValue.clear();
          lArgValue.str("");
        }
        continue;
      case '"':
        if (!lInArgValue) {
          lInArgValue = true;
          lInArgValueStr = true;
        } else if (lInArgValue) {
          lInArgValueStr = !lInArgValueStr;
        }
        continue;
      default:
        lInArgValue = true;
        lArgValue << c;
        continue;
      }
    }
  }

  if (lArgValue.str() != "") {
    theArgs[lArgName.str()] = lArgValue.str();
  }
}

bool
DebuggerCommand::getArg(std::string aArg, std::string& aValue) {
  std::map<std::string, std::string>::iterator lElem = theArgs.find(aArg); 
  if (lElem == theArgs.end()) {
    return false;
  } else {
    aValue = lElem->second;
    return true;
  }
}

bool
DebuggerCommand::getArg(std::string aArg, int& aValue) {
  std::map<std::string, std::string>::iterator lElem = theArgs.find(aArg); 
  if (lElem == theArgs.end()) {
    return false;
  } else {
    std::stringstream lSs(lElem->second);
    lSs >> aValue;
    return true;
  }
}

bool
DebuggerCommand::getArg(std::string aArg, unsigned int& aValue) {
  std::map<std::string, std::string>::iterator lElem = theArgs.find(aArg); 
  if (lElem == theArgs.end()) {
    return false;
  } else {
    std::stringstream lSs(lElem->second);
    lSs >> aValue;
    return true;
  }
}

} // namespace zorba
