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

#include <zorba/error.h>
#include "zorbaserialization/serialization_engine.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

UserError::UserError( char const *ns, char const *prefix,
                      char const *localname ) :
  qname_( ns, prefix, localname )
{
}

UserError::UserError( serialization::Archiver &ar ) : qname_( ar )
{
}

UserError::~UserError() {
  // out-of-line since it's virtual
}

Diagnostic const* UserError::clone() const {
  return new UserError( *this );
}

diagnostic::QName const& UserError::qname() const {
  return qname_;
}

diagnostic::category UserError::category() const {
  return diagnostic::XQUERY_USER_DEFINED;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
