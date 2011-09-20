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

#include <sstream>

#include "xqdoc_comment.h"
#include "util/ascii_util.h"

using namespace std;

namespace zorba {

XQDocType XQDocAnnotation::map_type( zstring const &name ) {
  if (name == "author")
    return TYPE_AUTHOR;
  if (name == "version")
    return TYPE_VERSION;
  if (name == "param")
    return TYPE_PARAM;
  if (name == "return")
    return TYPE_RETURN;
  if (name == "error")
    return TYPE_ERROR;
  if (name == "deprecated")
    return TYPE_DEPRECATED;
  if (name == "see")
    return TYPE_SEE;
  if (name == "since")
    return TYPE_SINCE;
  if (name == "library")
    return TYPE_LIBRARY;
  if (name == "example")
    return TYPE_EXAMPLE;
  if (name == "project")
    return TYPE_PROJECT;
  return TYPE_UNKNOWN;
}


XQDocComment::XQDocComment(const zstring& aComment)
  : theDeprecated(false)
{ 
  bool lDescriptionState = true;

  zstring lLine;
  zstring lAnntotation;
  stringstream lComment;
  
  // because the parser already digests the "(:~" token, in case the first line
  // already contains text, we prefix it with ":" such that all the lines will
  // be treated the same
  lComment << ":" << aComment;

  ostringstream lDesc;

  while(getline(lComment, lLine, '\n'))
  {
    // remove the leading and trailing whitespaces, and the leading ':'
    if (!startsWithColon(lLine) || lLine.empty()) {
      // the line did not start with a ':' preceeded by whitespaces or
      // if the line is empty, ignore it and proceed to the following
      continue;      
    }

    // if the line contains an annotation, than we finish the description
    zstring lTmp;
    ascii::trim_whitespace( lLine, &lTmp );
    if ( !lTmp.empty() && lTmp[0] == '@' ) {
      lDescriptionState = false;
      if (!lAnntotation.empty()) {
        parseAnnotation(lAnntotation);
      }
      lAnntotation = lTmp;
    } else if (lDescriptionState) {
      lDesc << lLine << endl;
    } else {
      lAnntotation += " " + lLine;
    }
  }
  if(!lAnntotation.empty()) {
    parseAnnotation(lAnntotation);
  }

  theDescription = lDesc.str();
}

bool
XQDocComment::startsWithColon(zstring& aLine)
{
  zstring temp;
  ascii::trim_whitespace( aLine, &temp );

  if ( !temp.empty() && temp[0] == ':' ) {
    aLine = temp.substr(1);
    return true;
  }
  return false;
}

void
XQDocComment::parseAnnotation(const zstring& aLine)
{
  size_t lIndex;
  zstring lName, lValue = "";
  lIndex = aLine.find(' ');

  if (lIndex == zstring::npos) {
    lName = aLine.substr(1);
  } else {
    lName = aLine.substr(1, lIndex - 1);
    lValue = aLine.substr(lIndex + 1);
  }

  ascii::to_lower( lName );
  ascii::normalize_whitespace( lValue );

  if ("version" == lName) {
    theVersion = lValue;
  } else if("project" == lName) {
    theProject = lValue;
  } else if("return" == lName) {
    theReturn = lValue;
  } else if("deprecated" == lName) {
    theDeprecated = true;
    theDeprecatedComment = lValue;
  } else if("author" == lName || "since" == lName || "see" == lName
            || "param" == lName || "error" == lName || "library" == lName
            || "example" == lName) {
    XQDocAnnotation lAnnotation(lName, lValue);
    theAnnotations.push_back(lAnnotation);
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
