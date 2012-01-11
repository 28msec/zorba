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
#ifndef ZORBA_XQUERY_EXCEPTION_H
#define ZORBA_XQUERY_EXCEPTION_H

#include <zorba/xquery_exception.h>
#include "compiler/parser/query_loc.h"
#include "diagnostic.h"

namespace zorba {

////////// XQueryException creation ///////////////////////////////////////////

/**
 * Makes an XQueryException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param params The diagnostic parameters.
 * @param loc The XQuery source-code location.
 * @return Returns a new XQueryException.
 */
XQueryException
make_xquery_exception( char const *raise_file,
                       ZorbaException::line_type raise_line,
                       Diagnostic const &diagnostic,
                       internal::diagnostic::parameters const &params,
                       internal::diagnostic::location const &loc =
                        internal::diagnostic::location::empty );

/**
 * Makes an XQueryException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param loc The diagnostic XQuery source-code location.
 * @return Returns a new XQueryException.
 */
inline XQueryException
make_xquery_exception( char const *raise_file,
                       ZorbaException::line_type raise_line,
                       Diagnostic const &diagnostic,
                       internal::diagnostic::location const &loc =
                        internal::diagnostic::location::empty ) {
  return make_xquery_exception(
    raise_file, raise_line, diagnostic,
    internal::diagnostic::parameters::empty, loc
  );
}

/**
 * Dynamically allocates an XQueryException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param params The diagnostic parameters.
 * @param loc The diagnostic XQuery source-code location.
 * @return Returns a new XQueryException.
 */
XQueryException*
new_xquery_exception( char const *raise_file,
                      ZorbaException::line_type raise_line,
                      Diagnostic const &diagnostic,
                      internal::diagnostic::parameters const &params,
                      internal::diagnostic::location const &loc =
                        internal::diagnostic::location::empty );

/**
 * Dynamically allocates an XQueryException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param loc The diagnostic XQuery source-code location.
 * @return Returns a new XQueryException.
 */
inline XQueryException*
new_xquery_exception( char const *raise_file,
                      ZorbaException::line_type raise_line,
                      Diagnostic const &diagnostic,
                      internal::diagnostic::location const &loc =
                        internal::diagnostic::location::empty ) {
  return new_xquery_exception(
    raise_file, raise_line, diagnostic,
    internal::diagnostic::parameters::empty, loc
  );
}

/**
 * Creates an XQueryException using the given Diagnostic variable.
 * \hideinitializer
 */
#define XQUERY_EXCEPTION_VAR(...) \
  ::zorba::make_xquery_exception( __FILE__, __LINE__, __VA_ARGS__ )

/**
 * Creates an XQueryException.
 * \hideinitializer
 */
#define XQUERY_EXCEPTION(...) \
  XQUERY_EXCEPTION_VAR( ::zorba:: __VA_ARGS__ )

/**
 * Creates a dynamically allocated XQueryException.
 * \hideinitializer
 */
#define NEW_XQUERY_EXCEPTION(...) \
  ::zorba::new_xquery_exception( __FILE__, __LINE__, ::zorba:: __VA_ARGS__ )

////////// XQuery diagnostic source location //////////////////////////////////

/**
 * Sets the XQuery source location of the given ZorbaException but only if it's
 * actually an XQueryException.  If it's actually a ZorbaException, constructs
 * a new XQueryException (copying the information from the ZorbaException) and
 * throws it.
 *
 * @param ze The ZorbaException to set the location of.
 * @param file The XQuery file name.
 * @param line The line number.
 * @param col The column number.
 * @param line_end The end line number.
 * @param col_end The end column number.
 * @param overwrite If \c false, sets the location only if the exception
 * doesn't already have one; if \c true, always sets the location even if the
 * exception already has one.
 */
void set_source( ZorbaException &ze, char const *file,
                 XQueryException::line_type line,
                 XQueryException::column_type col,
                 XQueryException::line_type line_end,
                 XQueryException::column_type col_end,
                 bool overwrite = true );

/**
 * Sets the XQuery source location of the given ZorbaException but only if it's
 * actually an XQueryException.
 *
 * @tparam StringType The \a file string type.
 * @param ze The ZorbaException to set the location of.
 * @param file The XQuery file name.
 * @param line The line number.
 * @param col The column number.
 * @param line_end The end line number.
 * @param col_end The end column number.
 * @param overwrite If \c false, sets the location only if the exception
 * doesn't already have one; if \c true, always sets the location even if the
 * exception already has one.
 */
template<class StringType> inline
void set_source( ZorbaException &ze, StringType const &file,
                 XQueryException::line_type line,
                 XQueryException::column_type col,
                 XQueryException::line_type line_end,
                 XQueryException::column_type col_end,
                 bool overwrite = true ) {
  set_source( ze, file.c_str(), line, col, line_end, col_end, overwrite );
}

/**
 * Sets the XQuery source location of the given ZorbaException but only if it's
 * actually an XQueryException.
 *
 * @param ze The ZorbaException to set the location of.
 * @param loc The query location.
 * @param overwrite If \c false, sets the location only if the exception
 * doesn't already have one; if \c true, always sets the location even if the
 * exception already has one.
 */
inline void set_source( ZorbaException &ze, QueryLoc const &loc,
                        bool overwrite = true ) {
  set_source(
    ze,
    loc.getFilename(),
    loc.getLineBegin(),
    loc.getColumnBegin(),
    loc.getLineEnd(),
    loc.getColumnEnd(),
    overwrite
  );
}

/**
 * Sets the XQuery source location of the given ZorbaException but only if it's
 * actually an XQueryException.
 *
 * @param to The ZorbaException to set the location of.
 * @param from The ZorbaException to get the location from but only if it's
 * actually an XQueryException.
 * @param overwrite If \c false, sets the location only if the exception
 * doesn't already have one; if \c true, always sets the location even if the
 * exception already has one.
 */
inline void set_source( ZorbaException &to, ZorbaException const &from,
                        bool overwrite = true ) {
  if ( XQueryException const *const xe =
        dynamic_cast<XQueryException const*>( &from ) ) {
    set_source(
      to,
      xe->source_uri(),
      xe->source_line(),
      xe->source_column(),
      xe->source_line_end(),
      xe->source_column_end(),
      overwrite
    );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_XQUERY_EXCEPTION_H */
/* vim:set et sw=2 ts=2: */
