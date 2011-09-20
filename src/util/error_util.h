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
#ifndef ZORBA_ERROR_UTIL_H
#define ZORBA_ERROR_UTIL_H

#include <zorba/config.h>

#include <stdexcept>
#ifndef WIN32
# include <cerrno>
#else
# include <windows.h>
#endif /* WIN32 */

#include "cxx_util.h"
#include "string_util.h"

namespace zorba {
namespace os_error {

////////// types //////////////////////////////////////////////////////////////

#ifdef WIN32
typedef DWORD code_type;
#else
typedef int code_type;
#endif /* WIN32 */

////////// Exceptions /////////////////////////////////////////////////////////

/**
 * An %exception is-a std::runtime_error for reporting errors with operating
 * system or library functions.
 */
class exception : public std::runtime_error {
public:
  /**
   * Constructs an %exception.
   *
   * @param function The name of the operating system function that failed, if
   * any.
   * @param path The full path of the file or directory involved in the
   * failure, if any.
   * @param err_string If not \c nullptr, the error string to use instead of
   * the operating system error string; if empty, no error string is used.
   */
  exception( char const *function, char const *path,
             char const *err_string = nullptr ) :
    std::runtime_error( make_what( function, path, err_string ) ),
    function_( function ), path_( path )
  {
  }

  /**
   * Destroys an %exception.
   */
  ~exception() throw();

  /**
   * Gets the name of the function that failed.
   *
   * @return Returns said function name.
   */
  std::string const& function() const throw() {
    return function_;
  }

  /**
   * Gets the full path of the file or directory involved in the failure.
   *
   * @return Returns said path.
   */
  std::string const& path() const throw() {
    return path_;
  }

protected:
  static std::string make_what( char const *function, char const *path,
                                char const *err_string = nullptr );

  std::string function_;
  std::string path_;
};

////////// Operating system errors ////////////////////////////////////////////

/**
 * Formats an error string.
 *
 * @param function The function that failed or \c nullptr.
 * @param err_string The error string.
 * @return Returns said error string.
 */
std::string format_err_string( char const *function, char const *err_string );

/**
 * Formats an error string.
 *
 * @param function The function that failed or \c nullptr.
 * @param code The operating system error code.
 * @param err_string The error string.
 * @return Returns said error string.
 */
std::string format_err_string( char const *function, code_type code,
                               char const *err_string );

/**
 * Gets the most recent operating system error code.
 *
 * @return Returns said error code.
 */
inline code_type get_err_code() {
#ifdef WIN32
  return ::GetLastError();
#else
  return errno;
#endif /* WIN32 */
}

/**
 * Gets the error string for the given operating system error code.
 *
 * @param function The function that failed or \c nullptr.
 * @param code The operating system error code.
 * @return Returns said error string.
 */
std::string get_err_string( char const *function,
                            code_type code = get_err_code() );

/**
 * Gets the error string for the given operating system error code.
 *
 * @tparam StringType The \a function string type.
 * @param function The function that failed.
 * @param code The operating system error code.
 * @return Returns said error string.
 */
template<class StringType> inline
typename std::enable_if<
  ztd::has_c_str<StringType,char const* (StringType::*)() const>::value,
  std::string
>::type
get_err_string( StringType const &function, code_type code = get_err_code() ) {
  return get_err_string( function.c_str(), code );
}

/**
 * Gets the error string for the given operating system error code.
 *
 * @param code The operating system error code.
 * @return Returns said error string.
 */
inline std::string get_err_string( code_type code = get_err_code() ) {
  return get_err_string( nullptr, code );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace os_error
} // namespace zorba

#endif /* ZORBA_ERROR_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
