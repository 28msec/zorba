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

#include "user_exception.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

UserException::UserException( char const *ns, char const *prefix,
                              char const *localname, char const *throw_file,
                              line_type throw_line, string const &message,
                              error_object_type *error_object ) :
  XQueryException(
    *(new UserError( ns, prefix, localname )), throw_file, throw_line, message
  )
{
  if ( error_object )
    error_object->swap( error_object_ );
}

UserException::~UserException() throw() {
  // out-of-line since it's virtual
}

auto_ptr<ZorbaException> UserException::clone() const {
  return auto_ptr<ZorbaException>( new UserException( *this ) );
}

void UserException::polymorphic_throw() const {
  throw *this;
}

UserException make_user_exception( char const *throw_file,
                                   UserException::line_type throw_line,
                                   char const *ns, char const *prefix,
                                   char const *localname, zstring const &msg,
                                   QueryLoc const &loc,
                                   UserException::error_object_type *err_obj ) {
  UserException ue(
    ns, prefix, localname, throw_file, throw_line, msg.c_str(), err_obj
  );
  if ( &loc != &QueryLoc::null ) {
    ue.set_source(
      loc.getFilename().str().c_str(), loc.getLineBegin(), loc.getColumnBegin()
    );
  }
  return ue;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
