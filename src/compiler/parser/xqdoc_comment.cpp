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

#include "xqdoc_comment.h"

#include <cctype>
#include <algorithm>
#include <string>

#include <zorba/zorbastring.h>

namespace zorba {

XQDocComment::XQDocComment(const std::string& aComment)
  : theDeprecated(false)
{ 
  bool lDescriptionState = true;
  bool lNewLineAdded = true;

  std::string lLine;
  std::string lAnntotation;
  std::stringstream lComment;
  
  // because the parser already digests the "(:~" token, in case the first line
  // already contains text, we prefix it with ":" such that all the lines will
  // be treated the same
  lComment << ":" << aComment;

  while(std::getline(lComment, lLine, '\n'))
  {
    // remove the leading and trailing whitespaces, and the leading ':'
    if (!trimLine(lLine)) {
      // the line did not start with a ':' preceeded by whitespaces
      // therefore we ignore these lines
      continue;      
    }

    // only add one new line every time an sequence of empty lines is found
    if (lLine.empty()) {
      if (!lNewLineAdded) {
        if (lDescriptionState) {
          theDescription += "\n";
        } else {
          lAnntotation += "\n";
        }
        lNewLineAdded = true;
      }
      continue;
    }
    lNewLineAdded = false;

    // if the line contains an annotation, than we finish the description
    if (lLine.at(0) == '@') {
      lDescriptionState = false;
      if (!lAnntotation.empty()) {
        parseAnnotation(lAnntotation);
      }
      lAnntotation = lLine;
    } else if (lDescriptionState) {
      theDescription += lLine + " ";
    } else {
      lAnntotation += " " + lLine;
    }
  }
  if(!lAnntotation.empty()) {
    parseAnnotation(lAnntotation);
  }

  // normalize spaces in the description
  String lTemp(theDescription);
  lTemp.normalizeSpace();
  theDescription = std::string(lTemp.c_str());
}

bool
XQDocComment::trimLine(std::string& aLine)
{
  String lResult(aLine);
  lResult.trim(" \t");

  if (lResult.charAt(0) == ':') {
    lResult = lResult.substring(1);
    lResult.trim(" \t");
    aLine = std::string(lResult.c_str());
  } else {
    return false;
  }

  return true;
}

void
XQDocComment::parseAnnotation(const std::string& aLine)
{
  size_t lIndex;
  std::string lName, lValue = "";
  lIndex = aLine.find(' ');

  if (lIndex == std::string::npos) {
    lName = aLine.substr(1);
  } else {
    lName = aLine.substr(1, lIndex - 1);
    lValue = aLine.substr(lIndex + 1);
  }

  transform(lName.begin(), lName.end(), lName.begin(), ::tolower);

  String lNormValue(lValue);
  lNormValue.normalizeSpace();
  lValue = std::string(lNormValue.c_str());

  if ("version" == lName) {
    theVersion = lValue;
  } else if("return" == lName) {
    theReturn = lValue;
  } else if("deprecated" == lName) {
    theDeprecated = true;
    theDeprecatedComment = lValue;
  } else {
    XQDocAnnotation lAnnotation(lName, lValue);
    theAnnotations.push_back(lAnnotation);
  }
}

}//end of namespace
