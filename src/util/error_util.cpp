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
#include "stdafx.h"

#include <sstream>

# include <cstring>
#ifndef WIN32
# include <cstdio>
#else
# include <windows.h>
#endif /* WIN32 */

#include <zorba/internal/unique_ptr.h>

#include "diagnostics/dict.h"
#include "diagnostics/diagnostic.h"

#include "error_util.h"
#include "stl_util.h"

namespace zorba {
namespace os_error {

using namespace std;

////////// exception //////////////////////////////////////////////////////////

exception::~exception() throw() {
  // out-of-line since it's virtual
}

string exception::make_what( char const *function, char const *path,
                             char const *err_string ) {
  ostringstream oss;
  if ( path && *path )
    oss << '"' << path << "\": ";
  if ( err_string )
    oss << format_err_string( function, err_string );
  else
    oss << get_err_string( function );
  return oss.str();
}

///////////////////////////////////////////////////////////////////////////////

string format_err_string( char const *function, char const *err_string ) {
  if ( function && *function ) {
    using namespace internal::diagnostic;
    parameters::value_type result =
      diagnostic::dict::lookup( ZED( FunctionFailed_12o ) );
    parameters const params( ERROR_PARAMS( function, err_string ) );
    params.substitute( &result );
    return result;
  } else {
    return err_string;
  }
}

string format_err_string( char const *function, code_type code,
                          char const *err_string ) {
  using namespace internal::diagnostic;
  parameters params;
  parameters::value_type result;
  if ( function && *function ) {
    result = diagnostic::dict::lookup(
      ZED( FunctionFailedErrorCodeMessage_123 )
    );
    params = ERROR_PARAMS( function, code, err_string );
  } else {
    result = diagnostic::dict::lookup( ZED( ErrorCodeMessage_12 ) );
    params = ERROR_PARAMS( code, err_string );
  }
  params.substitute( &result );
  return result;
}

string get_err_string( char const *function, code_type code ) {
#ifndef WIN32
  char err_string[ 128 ];
  ::strerror_r( code, err_string, sizeof( err_string ) );
#else
  LPWSTR werr_string;
  FormatMessage(
    FORMAT_MESSAGE_ALLOCATE_BUFFER
    | FORMAT_MESSAGE_FROM_SYSTEM
    | FORMAT_MESSAGE_IGNORE_INSERTS,
    NULL, code, MAKELANGID( LANG_NEUTRAL, SUBLANG_DEFAULT ),
    reinterpret_cast<LPWSTR>( &werr_string ), 0, NULL
  );
  int const err_size = ::wcslen( werr_string ) * 3;
  unique_ptr<char[]> const err_buf( new char[ err_size ] );
  char *const err_string = err_buf.get();
  WideCharToMultiByte(
    CP_UTF8, 0, werr_string, -1, err_string, err_size, NULL, NULL
  );
  LocalFree( werr_string );
#endif /* WIN32 */
  return format_err_string( function, code, err_string );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace os_error
} // namespace zorba
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
