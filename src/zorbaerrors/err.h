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
#ifndef ZORBA_ERR_H
#define ZORBA_ERR_H

#include <zorba/err.h>
#include "store/api/item.h"
#include "compiler/parser/query_loc.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

namespace err {

/**
 * Given a store::Item_t that represents a QName, creates an instance of
 * QNameType having the same QName.
 *
 * @tparam QNameType The type of QName to create.
 * @param qname The QName item.
 * @return Returns said QNameType.
 */
template<class QNameType> inline
QNameType to_QName( store::Item_t const &qname ) {
  return QNameType(
    qname->getNamespace().c_str(),
    qname->getPrefix().c_str(),
    qname->getLocalName().c_str()
  );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Makes an empty location.
 *
 * @return Returns said location.
 */
inline internal::err::location make_location() {
  return internal::err::location();
}

/**
 * This is a simple pass-rhough function so that the \c ERROR_LOC macro
 * can be passed an \c err::location.
 *
 * @param loc The error location.
 */
inline internal::err::location const&
make_location( internal::err::location const &loc ) {
  return loc;
}

/**
 * Makes a location.
 *
 * @param file The name of the file where the error occurred.
 * @param line The line number of the file where the error occurred.
 * @param column The column number, if any, of the file where the error
 * occurred.
 */
inline internal::err::location
make_location( char const *file, internal::err::location::line_type line,
               internal::err::location::column_type column = 0 ) {
  return internal::err::location( file, line, column );
}

/**
 * Makes a location.
 *
 * @tparam StringType The string type for \a file.
 * @param file The name of the file where the error occurred.
 * @param line The line number of the file where the error occurred.
 * @param column The column number, if any, of the file where the error
 * occurred.
 */
template<class StringType> inline internal::err::location
make_location( StringType const &file, internal::err::location::line_type line,
               internal::err::location::column_type column = 0 ) {
  return internal::err::location( file, line, column );
}

/**
 * TODO
 */
inline internal::err::location make_location( QueryLoc const &loc ) {
  return internal::err::location(
    loc.getFilename(), loc.getLineno(), loc.getColumnBegin()
  );
}

/**
 * TODO
 */
inline internal::err::location make_location( QueryLoc const *loc ) {
  return loc ? make_location( *loc ) : internal::err::location::empty;
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Creates an error location.
 * Example:
 * \code
 * throw XQUERY_EXCEPTION( XPST0001, ERROR_LOC( file, line, col ) );
 * \endcode
 * \hideinitializer
 */
#define ERROR_LOC ::zorba::err::make_location

/**
 * Creates a set of error parameters.
 * Example:
 * \code
 * throw XQUERY_EXCEPTION( XPST0001, ERROR_PARAMS( param1, param2, ... ) );
 * \endcode
 * \hideinitializer                     
 */
#define ERROR_PARAMS(...) (::zorba::internal::err::parameters(), __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////

} // namespace err
} // namespace zorba

#endif /* ZORBA_ERR_H */
/* vim:set et sw=2 ts=2: */
