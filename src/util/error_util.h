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
namespace error {

////////// types //////////////////////////////////////////////////////////////

#ifdef WIN32
typedef DWORD os_code;
#else
typedef int os_code;
#endif /* WIN32 */

////////// operating system errors ////////////////////////////////////////////

/**
 * Gets the most recent operating system error code.
 *
 * @return Returns said error code.
 */
inline os_code get_os_err_code() {
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
zstring get_os_err_string( char const *what, os_code code = get_os_err_code() );

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
get_os_err_string( StringType const &what, os_code code = get_os_err_code() ) {
  return get_os_err_string( what.c_str(), code );
}

/**
 * Gets the error string for the given operating system error code.
 *
 * @param code The operating system error code.
 * @return Returns said error string.
 */
inline zstring get_os_err_string( os_code code = get_os_err_code() ) {
  return get_os_err_string( NULL, code );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace error
} // namespace zorba

#endif /* ZORBA_ERROR_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
