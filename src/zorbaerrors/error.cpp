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

#include "dict.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace internal {

SystemErrorBase::map_type& SystemErrorBase::get_map() {
  static map_type m;
  return m;
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

Error::~Error() {
  // out-of-line since it's virtual
}

void Error::destroy() const {
  delete this;
}

err::category Error::category() const {
  return err::UNKNOWN_CATEGORY;
}

err::kind Error::kind() const {
  return err::UNKNOWN_KIND;
}

char const* Error::message() const {
  return err::dict::lookup( qname().localname() );
}

///////////////////////////////////////////////////////////////////////////////

UserError::UserError( char const *ns, char const *prefix,
                      char const *localname ) :
  qname_( ns, prefix, localname )
{
}

UserError::UserError(zorba::serialization::Archiver &ar) : qname_(ar)
{
}

UserError::~UserError() {
  // out-of-line since it's virtual
}

Error const* UserError::clone() const {
  return new UserError( *this );
}

err::QName const& UserError::qname() const {
  return qname_;
}

err::category UserError::category() const {
  return err::XQUERY_USER_DEFINED;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
