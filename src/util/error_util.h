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

#ifndef ZORBA_ERROR_UTIL_H
#define ZORBA_ERROR_UTIL_H

#include <zorba/config.h>

#ifndef WIN32
# include <cerrno>
#else
# include <windows.h>
#endif /* WIN32 */

#include "zorbatypes/zstring.h"

namespace zorba {
namespace error {

////////// types //////////////////////////////////////////////////////////////

#ifdef WIN32
typedef DWORD os_code;
#else
typedef int os_code;
#endif /* WIN32 */

////////// OS errors //////////////////////////////////////////////////////////

/**
 * Gets the most recent OS error code.
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
 * Gets the OS error string for the given OS error code.
 *
 * @param what What failed or \c NULL.
 * @param code The OS error code.
 * @return Returns said error string.
 */
zstring get_os_err_string( char const *what, os_code code = get_os_err_code() );

/**
 * Gets the OS error string for the given OS error code.
 *
 * @param code The OS error code.
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
