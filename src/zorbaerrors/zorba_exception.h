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
 * Makes a ZorbaException.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error.
 * @param params The error message parameters.
 * @return Returns a new ZorbaException.
 */
ZorbaException make_zorba_exception( char const *throw_file,
                                     ZorbaException::line_type throw_line,
                                     Error const &error,
                                     internal::err::parameters const &params =
                                      internal::err::parameters::empty );

/**
 * Dynamically allocates a Zorbaxception.
 *
 * @param throw_file The C++ source-code file name whence the exception was
 * thrown.
 * @param throw_line The C++ source-code line number whence the exception was
 * thrown.
 * @param error The error.
 * @param params The error message parameters.
 * @return Returns a new Zorbaxception.
 */
ZorbaException* new_zorba_exception( char const *throw_file,
                                     ZorbaException::line_type throw_line,
                                     Error const &error,
                                     internal::err::parameters const &params =
                                      internal::err::parameters::empty );

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
