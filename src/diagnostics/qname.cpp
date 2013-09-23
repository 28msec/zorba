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

#include <cstring>

#include <zorba/internal/qname.h>

using namespace std;

namespace zorba {

extern diagnostic::kind get_standard_error_kind( char const* );

namespace internal {

///////////////////////////////////////////////////////////////////////////////

zorba::diagnostic::kind XQueryErrorQName::kind() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ::strncmp( name, "FO", 2 ) == 0 )
    return XQUERY_DYNAMIC;              // all F&O errors are dynamic
  return get_standard_error_kind( name );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
