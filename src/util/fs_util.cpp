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
# include <sys/types.h>
# include <sys/stat.h>
#else
# include <windows.h>
#endif /* WIN32 */

#include "zorbaerrors/error_manager.h"

#include "ascii_util.h"
#include "fs_util.h"

using namespace std;

namespace zorba {
namespace fs {

///////////////////////////////////////////////////////////////////////////////

#ifdef WIN32

namespace win32 {

static bool to_wchar( char const *path, LPWSTR wpath ) {
  if ( ::MultiByteToWideChar( CP_UTF8, 0, path, -1, wpath, MAX_PATH ) )
    return true;
  return ::MultiByteToWideChar( CP_ACP, 0, path, -1, wpath, MAX_PATH );
}

} // namespace win32

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

zstring get_normalized_path( zstring const &path, zstring const &base ) {
  if ( path.empty() )
    ZORBA_ERROR_DESC( XPTY0004, "empty path" );
  zstring result;
  if ( ascii::begins_with( path, "file://" ) ) {
    result = path.substr( 7 );
    if ( result.empty() )
      ZORBA_ERROR_DESC( XPTY0004, "empty path" );
    zstring::size_type slash = result.find( '/' );
    if ( slash == zstring::npos )
      ZORBA_ERROR_DESC( XPTY0004, "invalid path" );
    if ( slash > 0 ) {
      zstring const authority( result.substr( 0, slash ) );
      if ( authority != "localhost" )
        ZORBA_ERROR_DESC( XPTY0004, "non-localhost authority" );
    }
#ifdef WIN32
    ++slash;                            // skip leading '/' in "/C:/file.txt"
#endif
    result = result.substr( slash );
    ascii::uri_decode( result );
#ifdef WIN32
    if ( !is_absolute( result ) )
      ZORBA_ERROR_DESC( XPTY0004, "missing drive specification" );
    ascii::replace_all( result, '/', '\\' );
#endif /* WIN32 */
  } else {
    zstring path2( path );
#ifdef WIN32
    ascii::replace_all( path2, '/', '\\' );
#endif /* WIN32 */
    if ( !is_absolute( path2 ) && !base.empty() ) {
      result = base;
#ifdef WIN32
      ascii::replace_all( result, '/', '\\' );
#endif /* WIN32 */
      append( result, path2 );
    } else
      result = path2;
#ifdef WIN32
    ascii::replace_all( result, "\\\\", 2, "\\", 1 );
#else
    ascii::replace_all( result, "//", 2, "/", 1 );
#endif /* WIN32 */
  }
  return result;
}

type get_type( char const *path ) {
#ifndef WIN32
  struct stat st_buf;
  if ( ::stat( path, &st_buf ) == -1 )
    return non_existent;
  if ( S_ISREG( st_buf.st_mode ) )
    return file;
  if ( S_ISDIR( st_buf.st_mode ) )
    return directory;
  return other;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  DWORD const attr = ::GetFileAttributes( wpath );
  if ( attr == INVALID_FILE_ATTRIBUTES )
    return non_existent;
  if ( attr & FILE_ATTRIBUTE_DIRECTORY )
    return directory;
  if ( attr & FILE_ATTRIBUTE_REPARSE_POINT )
    return link;
  return file;
#endif /* WIN32 */
}

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba

/* vim:set et sw=2 ts=2: */
