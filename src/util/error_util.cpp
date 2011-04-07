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

#ifndef WIN32
# include <cstdio>
# include <cstring>
#else
# include <windows.h>
# include <strsafe.h>
#endif /* WIN32 */

#include "error_util.h"
#include "stl_util.h"

namespace zorba {
namespace error {

using namespace std;

///////////////////////////////////////////////////////////////////////////////

zstring get_os_err_string( char const *what, os_code code ) {
#ifndef WIN32
  char err[ 512 ];
  if ( what && *what ) {
    snprintf(
      err, sizeof( err ), "%s failed (error %d): %s",
      what, code, ::strerror( code )
    );
  } else {
    snprintf(
      err, sizeof( err ), "error %d: %s",
      code, ::strerror( code )
    );
  }
  return zstring( err );
#else
  LPWSTR wmsg;
  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, code, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
    reinterpret_cast<LPWSTR>( &wmsg ), 0, NULL
  );
  int const werr_size = ::wcslen( wmsg ) + 40;
  ztd::auto_vec<WCHAR> const werr( new WCHAR[ werr_size ] );
  if ( what && *what ) {
    StringCchPrintf(
      werr.get(), werr_size, L"%hs failed (error %d): %ls",
      what, code, wmsg
    );
  } else {
    StringCchPrintf(
      werr.get(), werr_size, L"error %d: %ls", code, wmsg
    );
  }
  LocalFree( wmsg );

  int const err_size = ::wcslen( werr.get() ) * 2;
  ztd::auto_vec<char> const err( new char[ err_size ] );
  WideCharToMultiByte(
    CP_UTF8, 0, werr.get(), -1, err.get(), err_size, NULL, NULL
  );
  return zstring( err.get() );
#endif /* WIN32 */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace error
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
