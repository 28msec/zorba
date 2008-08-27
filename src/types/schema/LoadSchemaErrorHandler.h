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
#ifndef LOADSCHEMAERRORHANDLER_H_
#define LOADSCHEMAERRORHANDLER_H_

#include "xercesIncludes.h"
#include "common/common.h"
#include <zorbaerrors/error_manager.h>
#include "zorbaerrors/errors.h"
#include <compiler/parser/query_loc.h>


using namespace XERCES_CPP_NAMESPACE;

namespace zorba
{

class LoadSchemaErrorHandler 
    : public DefaultHandler
{
public:
    // -----------------------------------------------------------------------
    //  Constructors and Destructor
    // -----------------------------------------------------------------------
    LoadSchemaErrorHandler (const QueryLoc& loc);
    ~LoadSchemaErrorHandler ();

    bool getSawErrors() const
    {
        return _sawErrors;
    }

    void warning(const SAXParseException& exc);
    void error(const SAXParseException& exc);
    void fatalError(const SAXParseException& exc);
    void resetErrors();


private:
    const QueryLoc& _loc;
    bool            _sawErrors;
};

} // namespace xqp

#endif /*LOADSCHEMAERRORHANDLER_H_*/
