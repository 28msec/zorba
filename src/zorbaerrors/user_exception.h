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

#include <zorba/item.h>
#include <zorba/user_exception.h>

#include "api/unmarshaller.h"
#include "compiler/parser/query_loc.h"
#include "store/api/item.h"
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

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param ns The error code's namespace.
 * @param prefix The error code's prefix.
 * @param localname The error code's local-name.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     char const *description, QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 );

template<class StringType> inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     StringType const &description, QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, description.c_str(), loc,
    error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param ns The error code's namespace.
 * @param prefix The error code's prefix.
 * @param localname The error code's local-name.
 * @param description The error description.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     char const *description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, description, QueryLoc::null,
    error_object
  );
}

template<class StringType> inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     char const *ns, char const *prefix, char const *localname,
                     StringType const &description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line, ns, prefix, localname, description.c_str(),
    QueryLoc::null, error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Item const &qname, char const *description,
                     QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    description, loc, error_object
  );
}

template<class StringType>inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Item const &qname, StringType const &description,
                     QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    description.c_str(), loc, error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Item const &qname, char const *description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    description, QueryLoc::null, error_object
  );
}

template<class StringType>inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     Item const &qname, StringType const &description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname.getNamespace().c_str(),
    qname.getPrefix().c_str(),
    qname.getLocalName().c_str(),
    description.c_str(), QueryLoc::null, error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param loc The XQuery source-code location.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     store::Item_t const &qname, char const *description,
                     QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    description, loc, error_object
  );
}

template<class StringType> inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     store::Item_t const &qname, StringType const &description,
                     QueryLoc const &loc,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    description.c_str(), loc, error_object
  );
}

/**
 * Makes a UserException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param qname The error code's QName.
 * @param description The error description.
 * @param error_object The error object, if any.
 * @return Returns a new UserException.
 */
inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     store::Item_t const &qname, char const *description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    description, QueryLoc::null, error_object
  );
}

template<class StringType> inline UserException
make_user_exception( char const *throw_file,
                     ZorbaException::line_type throw_line,
                     store::Item_t const &qname, StringType const &description,
                     UserException::error_object_type *error_object = 0 ) {
  return make_user_exception(
    throw_file, throw_line,
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str(),
    description.c_str(), QueryLoc::null, error_object
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
