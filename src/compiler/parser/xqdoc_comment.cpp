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

#include "compiler/parser/xqdoc_comment.h"

#include <cctype>
#include <algorithm>
#include <string>

using namespace std;

namespace zorba {

string trim(const string& aString)
{
  size_t lStartPos = aString.find_first_not_of(" \t");
  size_t lEndPos = aString.find_last_not_of(" \t");

  if((string::npos == lStartPos) || (string::npos == lEndPos))
  {
    return "";
  } else {
    return aString.substr(lStartPos, lEndPos-lStartPos+1);
  }
}

XQDocComment::XQDocComment(const string& aComment): theDeprecated(false)
{ 
  ParsingState lState = DESCRIPTION;
  string lLine;
  istringstream lComment;
  lComment.str(aComment);
  while(getline(lComment, lLine, '\n'))
  {
    lLine = trim(lLine);
    if(lLine.empty()) continue;
    if("(:~" == lLine.substr(0, 3) || ":)" == lLine.substr(0, 2))
    {
      continue;
    } else if (':' == lLine.at(0)) {
      lLine = lLine.substr(1);
    }

    if(lState == DESCRIPTION)
    {
      if(isAnAnnotationLine(lLine))
      {
        lState = ANNOTATION;
        parseAnnotation(trim(lLine).substr(1));
      } else {
        appendDescription(lLine);
      }
    } else if(isAnAnnotationLine(lLine)) {
        parseAnnotation(trim(lLine).substr(1));
    }

  }
}

XQDocComment* XQDocComment::parseAnnotation(const std::string& aLine)
{
  size_t lIndex;
  string lName, lValue="";
  lIndex = aLine.find(' ');
  if(lIndex == string::npos)
  {
    lName = aLine;
  } else {
    lName = aLine.substr(0, lIndex);
    lValue = trim(aLine.substr(lIndex));
  }
  transform(lName.begin(), lName.end(), lName.begin(), ::tolower);
  if("version" == lName)
  {
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
  return this; 
}

bool XQDocComment::isAnAnnotationLine(const string& aLine)
{
  string lLine = trim(aLine);
  return !lLine.empty() && '@' == lLine.at(0);
}

XQDocComment* XQDocComment::appendDescription(const std::string& aLine)
{
  if(!aLine.empty())
  {
    if(!theDescription.str().empty())
    {
      theDescription << endl;
    }
    theDescription << aLine;
  }
  return this;
}
}//end of namespace
