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
# include <sys/types.h>
# include <sys/stat.h>
#endif /* WIN32 */

#include "zorbaerrors/error_manager.h"

#include "ascii_util.h"
#include "error_util.h"
#include "fs_util.h"
#include "uri_util.h"

using namespace std;

namespace zorba {
namespace fs {

////////// WIndows functions //////////////////////////////////////////////////

#ifdef WIN32

namespace win32 {

static type get_type( LPCWSTR wpath, size_type *size = 0 ) {
  WIN32_FILE_ATTRIBUTE_DATA data;
  if ( ::GetFileAttributesEx( wpath, GetFileExInfoStandard, (void*)&data ) ) {
    if ( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
      return directory;
    if ( data.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT )
      return link;
    if ( size )
      *size = (data.nFileSizeHigh << 32) | data.nFileSizeLow;
    return file;
  }
  return non_existent;
}

static bool to_char( LPCWSTR wpath, char *path ) {
  int const result = ::WideCharToMultiByte(
    CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL
  );
  return result != 0;
}

static bool to_wchar( char const *path, LPWSTR wpath ) {
  if ( ::MultiByteToWideChar( CP_UTF8, 0, path, -1, wpath, MAX_PATH ) )
    return true;
  return ::MultiByteToWideChar( CP_ACP, 0, path, -1, wpath, MAX_PATH );
}

} // namespace win32

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

zstring get_normalized_path( char const *path, char const *base ) {
  if ( !path[0] )
    ZORBA_ERROR_DESC( XPTY0004, "empty path" );
  zstring result;
  if ( ascii::begins_with( path, "file://" ) ) {
    result = path + 7;
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
    uri::decode( result );
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
    if ( !is_absolute( path2 ) && base && base[0] ) {
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

#ifdef ZORBA_WITH_FILE_ACCESS

void get_temp_file( char *path ) {
#ifndef WIN32
  if ( !::tmpnam( path ) )
    throw fs::exception( error::get_os_err_string( "tmpnam()" ) );
#else
  WCHAR wtemp[ MAX_PATH ];
  // GetTempFileName() needs a 14-character cushion.
  DWORD const dw_result = ::GetTempPath( MAX_PATH - 14, wtemp );
  if ( !dw_result || dw_result > MAX_PATH )
    throw fs::exception( error::get_os_err_string( "GetTempPath()" ) );
  WCHAR wpath[ MAX_PATH ];
  UINT const u_result = ::GetTempFileName( wtemp, TEXT("zxq"), 0, wpath );
  if ( !u_result )
    throw fs::exception( error::get_os_err_string( "GetTempFileName()" ) );
  win32::to_char( wpath, path );
#endif /* WIN32 */
}

type get_type( char const *path, size_type *size ) {
#ifndef WIN32
  struct stat st_buf;
  if ( ::stat( path, &st_buf ) == -1 )
    return non_existent;
  if ( S_ISDIR( st_buf.st_mode ) )
    return directory;
  if ( size )
    *size = st_buf.st_size;
  if ( S_ISREG( st_buf.st_mode ) )
    return file;
  return other;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  return win32::get_type( wpath, size );
#endif /* WIN32 */
}

bool remove( char const *path ) {
#ifndef WIN32
  return ::remove( path ) == 0;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  switch ( win32::get_type( wpath ) ) {
    case directory:
      return ::RemoveDirectory( wpath ) != 0;
    case non_existent:
      return false;
    default:
      return ::DeleteFile( wpath ) != 0;
  }
#endif /* WIN32 */
}

#endif /* ZORBA_WITH_FILE_ACCESS */

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba

/* vim:set et sw=2 ts=2: */
