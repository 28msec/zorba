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
#ifndef ZORBA_XQUERY_WARNING_H
#define ZORBA_XQUERY_WARNING_H

#include <zorba/xquery_warning.h>
#include <zorba/diagnostic_list.h>

#include "xquery_exception.h"

namespace zorba {

////////// XQueryWarning creation /////////////////////////////////////////////

/**
 * Creates a dynamically allocated XQueryWarning using the local name of an
 * warning.
 * \hideinitializer
 */
#define NEW_XQUERY_WARNING NEW_XQUERY_EXCEPTION

/**
 * Creates a warning location.
 * Example:
 * \code
 * NEW_XQUERY_WARNING( ZWST0001, WARN_LOC( file, line, col ) );
 * \endcode
 * \hideinitializer
 */
#define WARN_LOC ERROR_LOC

/**
 * Creates a set of warning parameters.
 * Example:
 * \code
 * NEW_XQUERY_WARNING( ZWST0001, WARN_PARAMS( param1, param2, ... ) );
 * \endcode
 * \hideinitializer                     
 */
#define WARN_PARAMS ERROR_PARAMS

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_XQUERY_WARNING_H */
/* vim:set et sw=2 ts=2: */
