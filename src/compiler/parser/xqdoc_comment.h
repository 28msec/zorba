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
#pragma once
#ifndef ZORBA_XQDOC_COMMENT_H
#define ZORBA_XQDOC_COMMENT_H

#include <list>

#include "zorbatypes/zstring.h"

namespace zorba {

  class XQDocumentable;

  enum XQDocType
  {
    TYPE_AUTHOR,
    TYPE_VERSION,
    TYPE_PARAM,
    TYPE_RETURN,
    TYPE_ERROR,
    TYPE_DEPRECATED,
    TYPE_SEE,
    TYPE_SINCE,
    TYPE_LIBRARY,
    TYPE_EXAMPLE,
    TYPE_PROJECT,
    TYPE_UNKNOWN
  };

  class XQDocAnnotation
  {
    friend class XQDocComment;

    private:

      const zstring   theName;
      const zstring   theValue;
      const XQDocType theType;

      XQDocAnnotation(zstring const &aName, zstring const &aValue)
        : theName(aName),
          theValue(aValue),
          theType(map_type(aName))
      {
      }

      static XQDocType map_type( zstring const &name );

    public:

      const zstring&
      getName() const { return theName; }

      const zstring&
      getValue() const { return theValue; }

      XQDocType
      getType() const { return theType; }
  };

  class XQDocComment
  {
    friend class XQDocumentable;

    private:

      zstring                     theDescription;
      std::list<XQDocAnnotation>  theAnnotations;
      zstring                     theVersion;
      zstring                     theReturn;
      bool                        theDeprecated;
      zstring                     theDeprecatedComment;
      zstring                     theProject;

      bool
      startsWithColon(zstring& line);

      bool
      isAnAnnotationLine(const zstring& aLine);

      void
      parseAnnotation(const zstring& aLine);

      XQDocComment(const zstring& aComment);

    public:

      const zstring&
      getDescription() const { return theDescription; }

      const std::list<XQDocAnnotation>&
      getAnnotations() const { return theAnnotations; }

      bool
      hasVersion() const { return !theVersion.empty(); }

      const zstring&
      getVersion() const { return theVersion; }

      const zstring&
      getProject() const { return theProject; }

      bool
      hasReturn() const { return !theReturn.empty(); }

      const zstring&
      getReturn() const { return theReturn; }

      bool
      isDeprecated() const { return theDeprecated; }

      const zstring&
      getDeprecatedComment() const { return theDeprecatedComment; }

  };

}//end of namespace
#endif
/* vim:set et sw=2 ts=2: */
