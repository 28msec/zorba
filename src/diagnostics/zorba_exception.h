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
#ifndef ZORBA_ZORBA_EXCEPTION_H
#define ZORBA_ZORBA_EXCEPTION_H

#include <zorba/zorba_exception.h>

namespace zorba {

////////// ZorbaException creation ////////////////////////////////////////////

/**
 * Helper function to clone a ZorbaException in order to keep ZorbaException's
 * clone() member function \c protected.
 *
 * @param e The ZorbaException to clone.
 * @return Returns a clone of \a e.
 */
inline std::unique_ptr<ZorbaException> clone( ZorbaException const &e ) {
  return e.clone();
}

/**
 * Makes a ZorbaException.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param params The message parameters.
 * @return Returns a new ZorbaException.
 */
ZorbaException
make_zorba_exception( char const *raise_file,
                      ZorbaException::line_type raise_line,
                      Diagnostic const &diagnostic,
                      internal::diagnostic::parameters const &params =
                        internal::diagnostic::parameters::empty );

/**
 * Dynamically allocates a Zorbaxception.
 *
 * @param raise_file The C++ source-code file name whence the exception was
 * raised.
 * @param raise_line The C++ source-code line number whence the exception was
 * raised.
 * @param diagnostic The diagnostic.
 * @param params The message parameters.
 * @return Returns a new Zorbaxception.
 */
ZorbaException*
new_zorba_exception( char const *raise_file,
                     ZorbaException::line_type raise_line,
                     Diagnostic const &diagnostic,
                     internal::diagnostic::parameters const &params =
                      internal::diagnostic::parameters::empty );

/**
 * The macro to use to create a ZorbaException.
 * \hideinitializer
 */
#define ZORBA_EXCEPTION(...) \
  ::zorba::make_zorba_exception( __FILE__, __LINE__, ::zorba:: __VA_ARGS__ )

/**
 * Creates a dynamically allocated Zorbaxception using the local name of an
 * error.
 * \hideinitializer
 */
#define NEW_ZORBA_EXCEPTION(...) \
  ::zorba::new_zorba_exception( __FILE__, __LINE__, ::zorba:: __VA_ARGS__ )

/**
 * Convenience macro for throwing "I/O error" exception.
 * \hideinitializer
 */
#define ZORBA_IO_EXCEPTION(FUNC,PATH) \
  ZORBA_EXCEPTION( zerr::ZOSE0004_IO_ERROR, ERROR_PARAMS( PATH, ::zorba::os_error::get_err_string( FUNC ) ) )

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_ZORBA_EXCEPTION_H */
/* vim:set et sw=2 ts=2: */
