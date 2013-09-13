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
#include "zorbamisc/ns_consts.h"

using namespace std;

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

static zorba::diagnostic::kind standard_kind( char const *localname ) {
  using namespace zorba::diagnostic;

  if ( ::strncmp( localname + 2, "DY", 2 ) == 0 )
    return XQUERY_DYNAMIC;
  if ( ::strncmp( localname + 2, "ST", 2 ) == 0 )
    return XQUERY_STATIC;
  if ( ::strncmp( localname + 2, "TY", 2 ) == 0 )
    return XQUERY_TYPE;
  return UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

char const XQueryErrorQName::NAMESPACE[] = XQUERY_ERR_NS;
char const XQueryErrorQName::PREFIX[] = "err";

zorba::diagnostic::kind XQueryErrorQName::kind() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ::strncmp( name, "FO", 2 ) == 0 )
    return XQUERY_DYNAMIC;              // all F&O errors are dynamic
  return standard_kind( name );
}

///////////////////////////////////////////////////////////////////////////////

char const JSONiqErrorQName::NAMESPACE[] = JSONIQ_ERR_NS;
char const JSONiqErrorQName::PREFIX[] = "jerr";

zorba::diagnostic::kind JSONiqErrorQName::kind() const {
  return standard_kind( localname() );
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaErrorQName::NAMESPACE[] = ZORBA_ERR_NS;
char const ZorbaErrorQName::PREFIX[] = "zerr";

zorba::diagnostic::kind ZorbaErrorQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaWarningQName::NAMESPACE[] = ZORBA_WARN_NS;
char const ZorbaWarningQName::PREFIX[] = "zwarn";

zorba::diagnostic::kind ZorbaWarningQName::kind() const {
  return standard_kind( localname() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
