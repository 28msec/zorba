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

#include <zorba/internal/qname.h>

#include "assert.h"
#include "util/ascii_util.h"
#include "zorbamisc/ns_consts.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

char const XQueryErrQName::NAMESPACE[] = XQUERY_ERR_NS;
char const XQueryErrQName::PREFIX[] = "err";

zorba::err::category XQueryErrQName::error_category() const {
  using namespace zorba::err;

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

zorba::err::kind XQueryErrQName::error_kind() const {
  using namespace zorba::err;

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

zorba::err::category ZorbaErrQName::error_category() const {
  using namespace zorba::err;

  char const *const name = localname();
  ZORBA_ASSERT( name );

  switch ( name[1] ) {
    case 'A': return ZORBA_API;
    case 'C': return ZORBA_SERIALIZATION;
    case 'D': return ZORBA_DDF;
    case 'O': return ZORBA_OS;
    case 'S': return ZORBA_STORE;
    case 'X': return ZORBA_XQP;
    default : ZORBA_ASSERT( false );
  }
}

zorba::err::kind ZorbaErrQName::error_kind() const {
  return zorba::err::UNKNOWN_KIND;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
