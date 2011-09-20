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
#ifndef ZORBA_DIAGNOSTIC_H
#define ZORBA_DIAGNOSTIC_H

#include <zorba/diagnostic.h>

#include "compiler/parser/query_loc.h"
#include "store/api/item.h"

namespace zorba {
namespace diagnostic {

///////////////////////////////////////////////////////////////////////////////

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
inline internal::diagnostic::location make_location() {
  return internal::diagnostic::location();
}

/**
 * This is a simple pass-rhough function so that the \c ERROR_LOC macro
 * can be passed an \c diagnostic::location.
 *
 * @param loc The error location.
 * @return Returns \a loc.
 */
inline internal::diagnostic::location const&
make_location( internal::diagnostic::location const &loc ) {
  return loc;
}

/**
 * Makes a location.
 *
 * @param file The name of the file where the error occurred.
 * @param line The line number of the file where the error occurred.
 * @param column The column number, if any, of the file where the error
 * occurred.
 * @return Returns a new location.
 */
inline internal::diagnostic::location
make_location( char const *file, internal::diagnostic::location::line_type line,
               internal::diagnostic::location::column_type column = 0 ) {
  return internal::diagnostic::location( file, line, column );
}

/**
 * Makes a location.
 *
 * @tparam StringType The string type for \a file.
 * @param file The name of the file where the error occurred.
 * @param line The line number of the file where the error occurred.
 * @param column The column number, if any, of the file where the error
 * occurred.
 * @return Returns a new location.
 */
template<class StringType> inline internal::diagnostic::location
make_location( StringType const &file,
               internal::diagnostic::location::line_type line,
               internal::diagnostic::location::column_type column = 0 ) {
  return internal::diagnostic::location( file, line, column );
}

/**
 * Makes a location.
 *
 * @param QueryLoc loc The QueryLoc to convert to a location.
 * @return Returns a new location.
 */
inline internal::diagnostic::location make_location( QueryLoc const &loc ) {
  return internal::diagnostic::location(
    loc.getFilename(),
    loc.getLineBegin(),
    loc.getColumnBegin(),
    loc.getLineEnd(),
    loc.getColumnEnd()
  );
}

/**
 * Makes a location.
 *
 * @param QueryLoc loc The pointer to the QueryLoc to convert to a location.
 * @return Returns a new location.
 */
inline internal::diagnostic::location make_location( QueryLoc const *loc ) {
  return loc ? make_location( *loc ) : internal::diagnostic::location::empty;
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
#define ERROR_LOC ::zorba::diagnostic::make_location

/**
 * Creates a set of error parameters.
 * Example:
 * \code
 * throw XQUERY_EXCEPTION( XPST0001, ERROR_PARAMS( param1, param2, ... ) );
 * \endcode
 * \hideinitializer                     
 */
#define ERROR_PARAMS(...) \
  (::zorba::internal::diagnostic::parameters(), __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////

} // namespace diagnostic
} // namespace zorba

#endif /* ZORBA_DIAGNOSTIC_H */
/* vim:set et sw=2 ts=2: */
