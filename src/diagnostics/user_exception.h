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

#pragma once
#ifndef ZORBA_USER_EXCEPTION_H
#define ZORBA_USER_EXCEPTION_H

#include <zorba/item.h>
#include <zorba/user_exception.h>

#include "api/unmarshaller.h"
#include "compiler/parser/query_loc.h"
#include "store/api/item.h"
#include "util/cxx_util.h"
#include "util/stl_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * Converts a UserException's \c error_object containing API Items into a
 * sequence containing store::Items.
 *
 * @tparam SequenceType The sequence type.
 * @param in The \c error_object to convert.
 * @param out A pointer to the sequence type to receive the items.
 */
template<class SequenceType> inline
void convert_error_object( UserException::error_object_type const &in,
                           SequenceType *out ) {
  FOR_EACH( UserException::error_object_type, in_obj, in ) {
    out->push_back( Unmarshaller::getInternalItem( *in_obj ) );
  }
}

///////////////////////////////////////////////////////////////////////////////

namespace internal {

/**
 * Makes a UserException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param ns The error code's namespace.
 * @param prefix The error code's prefix.
 * @param localname The error code's local-name.
 * @param description The error description.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException // MAKE_USER_EXCEPTION_CC_LT_4CC_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     char const *ns, char const *prefix, char const *localname,
                     char const *description,
                     error_object_type *error_object = nullptr ) {
  return make_user_exception(
    raise_file, raise_line, ns, prefix, localname, description,
    diagnostic::location::empty, error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param error_object The error object, if any.
 * @param loc The error location.
 * @return Returns a new UserException.
 */
UserException // MAKE_USER_EXCEPTION_CC_LT_I_CC_EL_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Item const &qname, char const *description,
                     diagnostic::location const &loc,
                     error_object_type *error_object = nullptr );

/**
 * Makes a UserException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param loc The error location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
UserException // MAKE_USER_EXCEPTION_CC_LT_SI_CC_EL_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     store::Item_t const &qname, char const *description,
                     diagnostic::location const &loc,
                     error_object_type *error_object = nullptr );

/**
 * Makes a UserException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param loc The error location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException // MAKE_USER_EXCEPTION_CC_LT_SI_CC_EOT_X
make_user_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     store::Item_t const &qname, char const *description,
                     error_object_type *error_object = nullptr ) {
  return make_user_exception(
    raise_file, raise_line, qname, description, diagnostic::location::empty,
    error_object
  );
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_USER_EXCEPTION_H */
/* vim:set et sw=2 ts=2: */
