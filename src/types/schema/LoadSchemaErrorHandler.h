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
#ifndef LOADSCHEMAERRORHANDLER_H_
#define LOADSCHEMAERRORHANDLER_H_

#include "common/common.h"
#ifndef ZORBA_NO_XMLSCHEMA

#include <xercesc/sax2/DefaultHandler.hpp>
#ifdef CYGWIN
#undef WIN32
#endif



namespace zorba
{
  class QueryLoc;

class LoadSchemaErrorHandler : public XERCES_CPP_NAMESPACE::DefaultHandler
{
public:
  LoadSchemaErrorHandler (const QueryLoc& loc);

  ~LoadSchemaErrorHandler ();

  bool getSawErrors() const
  {
    return theSawErrors;
  }
  
  void warning(const XERCES_CPP_NAMESPACE::SAXParseException& exc);
  void error(const XERCES_CPP_NAMESPACE::SAXParseException& exc);
  void fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& exc);
  void resetErrors();
  
private:
  const QueryLoc& theQueryLoc;
  bool            theSawErrors;
};

} // namespace xqp

#endif // ifndef ZORBA_NO_XMLSCHEMA
#endif /*LOADSCHEMAERRORHANDLER_H_*/
/* vim:set et sw=2 ts=2: */
