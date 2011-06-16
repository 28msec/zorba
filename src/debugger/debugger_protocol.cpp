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
  std::size_t lNameEnd = aCommand.find(" ");
  theName = aCommand.substr(0, lNameEnd);
  std::size_t lDataBegin = aCommand.find("--", lNameEnd);
  std::string lArgs = aCommand.substr(lNameEnd + 1, lDataBegin);

  if (lDataBegin != std::string::npos) {
    lDataBegin += 2;
    while (lDataBegin < aCommand.size()) {
      switch (aCommand.at(lDataBegin)) {
      case ' ':
      case '\t':
        ++lDataBegin;
        continue;
      default:
        theData = aCommand.substr(lDataBegin);
        lDataBegin = aCommand.size();
      }
    }
  }

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

} // namespace zorba
/* vim:set et sw=2 ts=2: */
