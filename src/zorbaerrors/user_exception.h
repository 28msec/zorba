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

#ifndef ZORBA_USER_EXCEPTION_H
#define ZORBA_USER_EXCEPTION_H

#include <zorba/user_exception.h>
#include <zorba/item.h>

#include "api/unmarshaller.h"
#include "compiler/parser/query_loc.h"
#include "store/api/item.h"
#include "util/stl_util.h"
#include "zorbatypes/zstring.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

template<class SequenceType> inline
void convert_error_object( UserException::error_object_type const &in,
                           SequenceType *out ) {
  FOR_EACH( UserException::error_object_type, in_obj, in ) {
    out->push_back( Unmarshaller::getInternalItem( *in_obj ) );
  }
}

/**
 * Makes a UserException TODO
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param ns TODO
 * @param prefix TODO
 * @param localname TODO
 * @param msg TODO
 * @param err_obj TODO
 * @return Returns a new UserException.
 */
UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     zstring const &msg, QueryLoc const &loc,
                     UserException::error_object_type *err_obj = 0 );

inline UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     zstring const &msg,
                     UserException::error_object_type *err_obj = 0 ) {
  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, msg, QueryLoc::null, err_obj
  );
}

inline UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     Item const &qname, zstring const &msg,
                     QueryLoc const &loc,
                     UserException::error_object_type *err_obj = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    msg, loc, err_obj
  );
}

inline UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     Item const &qname, zstring const &msg,
                     UserException::error_object_type *err_obj = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    msg, QueryLoc::null, err_obj
  );
}

inline UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     store::Item_t const &qname, zstring const &msg,
                     QueryLoc const &loc,
                     UserException::error_object_type *err_obj = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    msg, loc, err_obj
  );
}

inline UserException
make_user_exception( char const *throw_file,
                     UserException::line_type throw_line,
                     store::Item_t const &qname, zstring const &msg,
                     UserException::error_object_type *err_obj = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    msg, QueryLoc::null, err_obj
  );
}

/**
 * A handy macro for throwing a UserException.
 */
#define USER_EXCEPTION(...) \
  zorba::make_user_exception( __FILE__, __LINE__, __VA_ARGS__ )

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_USER_EXCEPTION_H */
/* vim:set et sw=2 ts=2: */
