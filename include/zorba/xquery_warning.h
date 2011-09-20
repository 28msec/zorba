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

#ifndef ZORBA_XQUERY_WARNING_API_H
#define ZORBA_XQUERY_WARNING_API_H

#include <zorba/internal/qname.h>
#include <zorba/internal/system_diagnostic.h>
#include <zorba/xquery_exception.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

typedef Diagnostic Warning;

/**
 * A %ZorbaWarningCode is a diagnostic for all Zorba-specific warnings.
 */
typedef internal::SystemDiagnostic<internal::ZorbaWarningQName>
        ZorbaWarningCode;

/**
 * Re-use an XQueryException as an %XQueryWarning to:
 *  - leverage all the localization and printing code
 *  - allow warnings to be treated as exceptions and thrown
 */
typedef XQueryException XQueryWarning;

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_XQUERY_WARNING_API_H */
/* vim:set et sw=2 ts=2: */
