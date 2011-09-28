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

#include <zorba/config.h>
#include <sstream>
#ifndef ZORBA_NO_XMLSCHEMA

#include "LoadSchemaErrorHandler.h"
#include "StrX.h"
#include <xercesc/sax/SAXParseException.hpp>
#ifdef CYGWIN
#undef WIN32
#endif

#include "compiler/parser/query_loc.h"
#include "diagnostics/xquery_diagnostics.h"

namespace zorba
{

LoadSchemaErrorHandler::LoadSchemaErrorHandler(const QueryLoc& loc) 
  :
  theQueryLoc(loc),
  theSawErrors(false)
{
}


LoadSchemaErrorHandler::~LoadSchemaErrorHandler()
{
}


// ---------------------------------------------------------------------------
//  LoadSchemaErrorHandler: Overrides of the SAX ErrorHandler interface
// ---------------------------------------------------------------------------
void LoadSchemaErrorHandler::error(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  theSawErrors = true;
  std::ostringstream os;
  os << "Error in schema ";

if ( e.getSystemId() != NULL )
    os << "with system id " << StrX(e.getSystemId());
  else if ( e.getPublicId() != NULL )
    os << "with public id " << StrX(e.getPublicId());
  else 
    os << "without id"; 
  
  os << ", line " << e.getLineNumber() 
     << ", column " << e.getColumnNumber() << "." << std::endl
     << StrX(e.getMessage());

  throw XQUERY_EXCEPTION( err::XQST0059, ERROR_PARAMS(os.str()), ERROR_LOC(theQueryLoc) );
}

void LoadSchemaErrorHandler::fatalError(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  theSawErrors = true;
  std::ostringstream os;
  os << "Fatal error in schema ";

  if ( e.getSystemId() != NULL )
    os << "with system id " << StrX(e.getSystemId());
  else if ( e.getPublicId() != NULL )
    os << "with public id " << StrX(e.getPublicId());
  else 
    os << "without id"; 
  
  os << ", line " << e.getLineNumber() 
     << ", column " << e.getColumnNumber() << "." << std::endl
     << StrX(e.getMessage());

  throw XQUERY_EXCEPTION( err::XQST0059, ERROR_PARAMS(os.str()), ERROR_LOC(theQueryLoc) );
}

void LoadSchemaErrorHandler::warning(const XERCES_CPP_NAMESPACE::SAXParseException& e)
{
  XERCES_STD_QUALIFIER cerr << "\nWarning at file " << StrX(e.getSystemId())
                            << ", line " << e.getLineNumber()
                            << ", char " << e.getColumnNumber()
                            << "\n  Message: " << StrX(e.getMessage())
                            << XERCES_STD_QUALIFIER endl;
  //XQueryDiagnostics xqueryDiagnostics;
  //ZORBA_WARNING(&xqueryDiagnostics, XQST0059, StrX(e.getMessage()), _loc);
}

void LoadSchemaErrorHandler::resetErrors()
{
  theSawErrors = false;
}

} // namspace xqp

#endif //#ifndef ZORBA_NO_XMLSCHEMA
/* vim:set et sw=2 ts=2: */
