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
#include <zorba/config.h>
#ifndef ZORBA_NO_XMLSCHEMA

#include "LoadSchemaErrorHandler.h"
#include "StrX.h"

namespace zorba
{

LoadSchemaErrorHandler::LoadSchemaErrorHandler(const QueryLoc& loc) :
    _loc(loc), _sawErrors(false)
{
}

LoadSchemaErrorHandler::~LoadSchemaErrorHandler()
{
}

// ---------------------------------------------------------------------------
//  LoadSchemaErrorHandler: Overrides of the SAX ErrorHandler interface
// ---------------------------------------------------------------------------
void LoadSchemaErrorHandler::error(const SAXParseException& e)
{
  _sawErrors = true;
  std::ostringstream os;
  os << "Error in schema " << StrX(e.getSystemId()) << ", line " << e.getLineNumber() 
     << ", column " << e.getColumnNumber() << "." << std::endl
     << StrX(e.getMessage());
  ZORBA_ERROR_LOC_DESC( XQST0059, _loc, os.str());
}

void LoadSchemaErrorHandler::fatalError(const SAXParseException& e)
{
  _sawErrors = true;
  std::ostringstream os;
  os << "Error in schema " << StrX(e.getSystemId()) << ", line " << e.getLineNumber() 
     << ", column " << e.getColumnNumber() << "." << std::endl
     << StrX(e.getMessage());
  ZORBA_ERROR_LOC_DESC( XQST0059, _loc, os.str());
    //ZORBA_ERROR_DESC(XQST0059, StrX(e.getMessage()));
}

void LoadSchemaErrorHandler::warning(const SAXParseException& e)
{
    XERCES_STD_QUALIFIER cerr << "\nWarning at file " << StrX(e.getSystemId())
    << ", line " << e.getLineNumber()
    << ", char " << e.getColumnNumber()
    << "\n  Message: " << StrX(e.getMessage()) << XERCES_STD_QUALIFIER endl;
    //error::ErrorManager errorManager;
    //ZORBA_WARNING(&errorManager, XQST0059, StrX(e.getMessage()), _loc);
}

void LoadSchemaErrorHandler::resetErrors()
{
    _sawErrors = false;
}

} // namspace xqp

#endif //#ifndef ZORBA_NO_XMLSCHEMA
