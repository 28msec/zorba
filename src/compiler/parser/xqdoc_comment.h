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
#ifndef ZORBA_XQDOC_COMMENT_H
#define ZORBA_XQDOC_COMMENT_H

#include <string>
#include <sstream>
#include <list>

namespace zorba {

class XQDocumentable;

enum XQDocType
{
  AUTHOR, VERSION, PARAM, RETURN, ERROR, DEPRECATED, SEE, SINCE, UNKNOWN
};

class XQDocAnnotation
{
  friend class XQDocComment;

  private:
    const std::string theName;
    const std::string theValue;
    XQDocType theType;   
 
    XQDocAnnotation(std::string& aName, std::string& aValue): theName(aName), theValue(aValue)
    {
      if(theName == "author")
      {
        theType = AUTHOR;
      } else if(theName == "version") {
        theType = VERSION;
      } else if(theName == "param") {
        theType = PARAM;
      } else if(theName == "return") {
        theType = RETURN;
      } else if(theName == "error") {
        theType = ERROR;
      } else if(theName == "deprecated") {
        theType = DEPRECATED;
      } else if(theName == "see") {
        theType = SEE;
      } else if(theName == "since") {
        theType = SINCE;
      } else {
        theType = UNKNOWN;
      }
    }

  public:
    const std::string& getName() const { return theName; }
    const std::string& getValue() const { return theValue; }
    const XQDocType getType() const { return theType; }
};

class XQDocComment
{
  friend class XQDocumentable;

  private:
    enum ParsingState { DESCRIPTION, ANNOTATION };
    std::stringstream theDescription;
    std::list<XQDocAnnotation> theAnnotations;
    std::string theVersion;
    std::string theReturn;
    bool theDeprecated;
    std::string theDeprecatedComment;

    bool isAnAnnotationLine(const std::string& aLine);
    XQDocComment* parseAnnotation(const std::string& aLine);
    XQDocComment* appendDescription(const std::string& aLine);

    XQDocComment(const std::string& aComment);
  
  public:
    const std::string getDescription() const { return theDescription.str(); }
    const std::list<XQDocAnnotation>& getAnnotations() const { return theAnnotations; }

    bool hasVersion() const { return !theVersion.empty(); }
    const std::string& getVersion() const { return theVersion; }
    bool hasReturn() const { return !theReturn.empty(); }
    const std::string& getReturn() const { return theReturn; }
    bool isDeprecated() const { return theDeprecated; }
    const std::string& getDeprecatedComment() const { return theDeprecatedComment; }
};
}//end of namespace
#endif
