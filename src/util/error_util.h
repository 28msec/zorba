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

#ifndef WIN32
# include <cerrno>
#else
# include <windows.h>
#endif /* WIN32 */

#include "string_util.h"
#include "zorbatypes/zstring.h"

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
 * system functions.
 */
class exception : public std::runtime_error {
public:
  /**
   * Constructs an %exception.
   *
   * @param function The name of the operating system function that failed.
   * @param path The full path of the file or directory involved in the failure.
   */
  explicit exception( char const *function, char const *path = "" ) :
    std::runtime_error( make_what( function, path ) ),
    function_( function ), path_( path )
  {
  }

  /**
   * Constructs an %exception.
   *
   * @tparam FunctionStringType The \a function string type.
   * @param function The name of the operating system function that failed.
   * @param path The full path of the file or directory involved in the failure.
   */
  template<class FunctionStringType>
  explicit exception( FunctionStringType const &function,
                      char const *path = "" ) :
    std::runtime_error( make_what( function.c_str(), path ) ),
    function_( function ), path_( path )
  {
  }

  /**
   * Constructs an %exception.
   *
   * @tparam PathStringType The \a path string type.
   * @param function The name of the operating system function that failed.
   * @param path The full path of the file or directory involved in the failure.
   */
  template<class PathStringType>
  explicit exception( char const *function,
                      PathStringType const &path = "" ) :
    std::runtime_error( make_what( function, path.c_str() ) ),
    function_( function ), path_( path )
  {
  }

  /**
   * Constructs an %exception.
   *
   * @tparam FunctionStringType The \a function string type.
   * @tparam PathStringType The \a path string type.
   * @param function The name of the operating system function that failed.
   * @param path The full path of the file or directory involved in the failure.
   */
  template<class FunctionStringType,class PathStringType>
  explicit exception( FunctionStringType const &function,
                      PathStringType const &path = "" ) :
    std::runtime_error( make_what( function.c_str(), path.c_str() ) ),
    function_( function ), path_( path )
  {
  }

  /**
   * Destroys an %exception.
   */
  ~exception() throw();

  /**
   * Gets the name of the operating system function that failed.
   *
   * @return Returns said function name.
   */
  zstring const& function() const throw() {
    return function_;
  }

  /**
   * Gets the full path of the file or directory involved in the failure.
   *
   * @return Returns said path.
   */
  zstring const& path() const throw() {
    return path_;
  }

protected:
  static std::string make_what( char const *function, char const *path );

  zstring function_;
  zstring path_;
};

////////// Operating system errors ////////////////////////////////////////////

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
 * @param what What failed or \c NULL.
 * @param code The operating system error code.
 * @return Returns said error string.
 */
zstring get_err_string( char const *what, code_type code = get_err_code() );

/**
 * Gets the error string for the given operating system error code.
 *
 * @tparam StringType The \a what string type.
 * @param what What failed.
 * @param code The operating system error code.
 * @return Returns said error string.
 */
template<class StringType> inline
typename ztd::enable_if<
  ztd::has_c_str<StringType,char const* (StringType::*)() const>::value,
  zstring
>::type
get_err_string( StringType const &what, code_type code = get_err_code() ) {
  return get_err_string( what.c_str(), code );
}

/**
 * Gets the error string for the given operating system error code.
 *
 * @param code The operating system error code.
 * @return Returns said error string.
 */
inline zstring get_err_string( code_type code = get_err_code() ) {
  return get_err_string( NULL, code );
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
