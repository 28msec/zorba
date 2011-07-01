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

char const XQueryErrQName::NAMESPACE[] = XQUERY_ERR_NS;
char const XQueryErrQName::PREFIX[] = "err";

zorba::diagnostic::category XQueryErrQName::category() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ascii::begins_with( name, "FT", 2 ) )
    return XQUERY_FULL_TEXT;
  if ( ascii::begins_with( name, "SE", 2 ) )
    return XQUERY_SERIALIZATION;
  if ( ascii::begins_with( name, "XS", 2 ) )
    return XQUERY_SCRIPTING;
  if ( ascii::begins_with( name, "XU", 2 ) )
    return XQUERY_UPDATE;

  return XQUERY_CORE;
}

zorba::diagnostic::kind XQueryErrQName::kind() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ::strncmp( name + 2, "DY", 2 ) == 0 )
    return XQUERY_DYNAMIC;
  if ( ::strncmp( name + 2, "ST", 2 ) == 0 )
    return XQUERY_STATIC;
  if ( ::strncmp( name + 2, "TY", 2 ) == 0 )
    return XQUERY_TYPE;
  if ( ::strncmp( name, "FO", 2 ) == 0 )
    return XQUERY_DYNAMIC;              // all F&O errors are dynamic

  return UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaErrQName::NAMESPACE[] = ZORBA_ERR_NS;
char const ZorbaErrQName::PREFIX[] = "zerr";

zorba::diagnostic::category ZorbaErrQName::category() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();
  ZORBA_ASSERT( name );

  switch ( name[1] ) {
    case 'A': return ZORBA_API;
    case 'C': return ZORBA_SERIALIZATION;
    case 'D': return ZORBA_DDF;
    case 'G': return ZORBA_DEBUGGER;
    case 'O': return ZORBA_OS;
    case 'S': return ZORBA_STORE;
    case 'X': return ZORBA_XQP;
    default : ZORBA_ASSERT( false );
  }
}

zorba::diagnostic::kind ZorbaErrQName::kind() const {
  return zorba::diagnostic::UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaWarningQName::NAMESPACE[] = ZORBA_WARN_NS;
char const ZorbaWarningQName::PREFIX[] = "zwarn";

zorba::diagnostic::category ZorbaWarningQName::category() const {
  return zorba::diagnostic::ZORBA_XQP;
}

zorba::diagnostic::kind ZorbaWarningQName::kind() const {
  using namespace zorba::diagnostic;

  char const *const name = localname();

  if ( ::strncmp( name + 2, "DY", 2 ) == 0 )
    return XQUERY_DYNAMIC;
  if ( ::strncmp( name + 2, "ST", 2 ) == 0 )
    return XQUERY_STATIC;
  if ( ::strncmp( name + 2, "TY", 2 ) == 0 )
    return XQUERY_TYPE;

  return UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
