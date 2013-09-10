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

#include <zorba/internal/qname.h>

#include "assert.h"
#include "util/ascii_util.h"
#include "zorbamisc/ns_consts.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

static zorba::diagnostic::kind get_kind( char const *localname ) {
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

char const XQueryErrQName::NAMESPACE[] = XQUERY_ERR_NS;
char const XQueryErrQName::PREFIX[] = "err";

zorba::diagnostic::kind XQueryErrQName::kind() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ::strncmp( name, "FO", 2 ) == 0 )
    return XQUERY_DYNAMIC;              // all F&O errors are dynamic
  return get_kind( name );
}

///////////////////////////////////////////////////////////////////////////////

char const JSONiqErrQName::NAMESPACE[] = JSONIQ_ERR_NS;
char const JSONiqErrQName::PREFIX[] = "jerr";

zorba::diagnostic::kind JSONiqErrQName::kind() const {
  return get_kind( localname() );
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaErrQName::NAMESPACE[] = ZORBA_ERR_NS;
char const ZorbaErrQName::PREFIX[] = "zerr";

zorba::diagnostic::kind ZorbaErrQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaWarningQName::NAMESPACE[] = ZORBA_WARN_NS;
char const ZorbaWarningQName::PREFIX[] = "zwarn";

zorba::diagnostic::kind ZorbaWarningQName::kind() const {
  return get_kind( localname() );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
