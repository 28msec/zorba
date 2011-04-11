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

zorba::err::type XQueryErrQName::error_type() const {
  using namespace zorba::err;

  char const *const name = localname();

  if ( name[0] == 'S' )
    return XQUERY_SERIALIZATION;
  switch ( name[2] ) {
    case 'D': return XQUERY_DYNAMIC;
    case 'S': return XQUERY_STATIC;
    case 'T': return XQUERY_TYPE;
  }
  if ( ascii::begins_with( name, "FO", 2 ) )
    return XQUERY_DYNAMIC;              // all F&O errors are dynamic

  return UNKNOWN;
}

///////////////////////////////////////////////////////////////////////////////

char const ZorbaErrQName::NAMESPACE[] = ZORBA_ERR_NS;
char const ZorbaErrQName::PREFIX[] = "zerr";

zorba::err::type ZorbaErrQName::error_type() const {
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

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
