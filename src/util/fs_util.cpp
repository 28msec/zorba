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

#include <zorba/util/path.h>

#ifndef WIN32
# include <fcntl.h>                     /* for creat(2) */
# include <cstdio>
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>                    /* for chdir(2) */
#endif /* WIN32 */

#include "diagnostics/xquery_diagnostics.h"

#include "ascii_util.h"
#include "cxx_util.h"
#include "fs_util.h"
#include "string_util.h"
#include "uri_util.h"

using namespace std;

namespace zorba {
namespace fs {

////////// helper functions ///////////////////////////////////////////////////

inline void replace_foreign( zstring *path ) {
#ifdef WIN32
  ascii::replace_all( *path, '/', '\\' );
#else
  ascii::replace_all( *path, '\\', '/' );
#endif /* WIN32 */
}

////////// Windows functions //////////////////////////////////////////////////

#ifdef WIN32

namespace win32 {

#ifdef ZORBA_WITH_FILE_ACCESS

static type get_type( LPCWSTR wpath, size_type *size = nullptr ) {
  WIN32_FILE_ATTRIBUTE_DATA data;
  if ( ::GetFileAttributesEx( wpath, GetFileExInfoStandard, (void*)&data ) ) {
    if ( data.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
      return directory;
    if ( data.dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT )
      return link;
    if ( size )
      *size = ((size_type)data.nFileSizeHigh << 32) | data.nFileSizeLow;
    return file;
  }
  return non_existent;
}

#endif /* ZORBA_WITH_FILE_ACCESS */

static bool to_char( LPCWSTR wpath, char *path ) {
  return !!::WideCharToMultiByte(
    CP_UTF8, 0, wpath, -1, path, MAX_PATH, NULL, NULL
  );
}

static bool to_wchar( char const *path, LPWSTR wpath ) {
  if ( ::MultiByteToWideChar( CP_UTF8, 0, path, -1, wpath, MAX_PATH ) )
    return true;
  return !!::MultiByteToWideChar( CP_ACP, 0, path, -1, wpath, MAX_PATH );
}

void make_absolute_impl( char const *path, char *abs_path ) {
#ifndef WINCE
  WCHAR wpath[ MAX_PATH ];
  to_wchar( path, wpath );
  WCHAR wfull_path[ MAX_PATH ];
  DWORD const result = ::GetFullPathName(
    wpath, sizeof( wpath ) / sizeof( wpath[0] ), wfull_path, NULL
  );
  if ( !result )
    throw ZORBA_IO_EXCEPTION( "GetFullPathName()", path );
  to_char( wfull_path, abs_path );
#endif /* WINCE */
}

} // namespace win32

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

void chdir( char const *path ) {
#ifndef WIN32
  if ( ::chdir( path ) != 0 )
    throw ZORBA_IO_EXCEPTION( "chdir()", path );
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  if ( ::_wchdir( wpath ) != 0 )
    throw fs::exception( "wchdir()", path );
#endif /* WIN32 */
}

void create( char const *path ) {
#ifndef WIN32
  int const fd = ::creat( path, 0644 );
  if ( fd == -1 )
    throw fs::exception( "creat()", path );
  ::close( fd );
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  HANDLE fd = ::CreateFile(
    wpath,
    GENERIC_READ | GENERIC_WRITE,
    FILE_SHARE_READ | FILE_SHARE_WRITE, NULL,
    CREATE_ALWAYS, 0, NULL
  );
  if ( fd == INVALID_HANDLE_VALUE )
    throw fs::exception( "CreateFile()", path );
  ::CloseHandle( fd );
#endif /* WIN32 */
}

#endif /* ZORBA_WITH_FILE_ACCESS */

zstring curdir() {
  char path[ MAX_PATH ];
#ifndef WIN32
  if ( !::getcwd( path, sizeof( path ) ) )
    throw ZORBA_IO_EXCEPTION( "getcwd()", "" );
#else
  WCHAR wpath[ MAX_PATH ];
  if ( !::GetCurrentDirectory( sizeof( wpath ) / sizeof( wpath[0] ), wpath ) )
    throw ZORBA_IO_EXCEPTION( "GetCurrentDirectory()", "" );
  win32::to_char( wpath, path );
  if ( !is_absolute( path ) ) {
    // GetCurrentDirectory() sometimes misses drive letter.
    filesystem_path   fspath( path );
    fspath.resolve_relative();
    return fspath.get_path();
  }
#endif /* WIN32 */
  return path;
}

zstring get_normalized_path( char const *path, char const *base ) {
  if ( !path[0] )
    throw XQUERY_EXCEPTION( err::XPTY0004, ERROR_PARAMS( ZED( EmptyPath ) ) );
  zstring result;
  if ( ascii::begins_with( path, "file://" ) ) {
    result = path + 7;
    if ( result.empty() )
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( QuotedColon_23 ), path, ZED( EmptyPath ) )
      );
    zstring::size_type slash = result.find( '/' );
    if ( slash == zstring::npos )
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS( ZED( QuotedColon_23 ), path, ZED( BadPath ) )
      );
    if ( slash > 0 ) {
      zstring const authority( result.substr( 0, slash ) );
      if ( authority != "localhost" )
        throw XQUERY_EXCEPTION(
          err::XPTY0004,
          ERROR_PARAMS(
            ZED( QuotedColon_23 ), authority, ZED( NonLocalhostAuthority )
          )
        );
    }
#ifdef WIN32
    ++slash;                            // skip leading '/' in "/C:/file.txt"
#endif /* WIN32 */
    result = result.substr( slash );
    uri::decode( result );
#ifdef WIN32
    replace_foreign( &result );
    if ( !is_absolute( result ) )
      throw XQUERY_EXCEPTION(
        err::XPTY0004,
        ERROR_PARAMS(
          ZED( QuotedColon_23 ), result, ZED( NoDriveSpecification )
        )
      );
#endif /* WIN32 */
  } else {
    zstring path2( path );
    replace_foreign( &path2 );
    if ( !is_absolute( path2 ) && base && base[0] ) {
      result = base;
      replace_foreign( &result );
      append( result, path2 );
    } else
      result = path2;
#ifdef WIN32
    while ( ascii::replace_all( result, "\\\\", 2, "\\", 1 ) )
      ;
#else
    while ( ascii::replace_all( result, "//", 2, "/", 1 ) )
      ;
#endif /* WIN32 */
  }
  return result;
}

#ifdef ZORBA_WITH_FILE_ACCESS

void get_temp_file( char *path ) {
#ifndef WIN32
  if ( !::tmpnam( path ) )
    throw fs::exception( "tmpnam()", static_cast<char const*>( path ) );
#else
  WCHAR wtemp[ MAX_PATH ];
  // GetTempFileName() needs a 14-character cushion.
  DWORD const dw_result = ::GetTempPath( MAX_PATH - 14, wtemp );
  if ( !dw_result || dw_result > MAX_PATH )
    throw fs::exception( "GetTempPath()", static_cast<char const*>(path) );
  WCHAR wpath[ MAX_PATH ];
  UINT const u_result = ::GetTempFileName( wtemp, TEXT("zxq"), 0, wpath );
  if ( !u_result )
    throw fs::exception( "GetTempFileName()", static_cast<char const*>(path) );
  win32::to_char( wpath, path );
#endif /* WIN32 */
}

type get_type( char const *path, size_type *size ) {
#ifndef WIN32
  struct stat st_buf;
  if ( ::stat( path, &st_buf ) == -1 ) {
    if ( errno == ENOENT )
      return non_existent;
    throw ZORBA_IO_EXCEPTION( "stat()", path );
  }
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

void mkdir( char const *path ) {
#ifndef WIN32
  if ( ::mkdir( path, 0755 ) != 0 )
    throw fs::exception( "mkdir()", path );
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  if ( !::CreateDirectory( wpath, NULL ) )
    throw fs::exception( "CreateDirectory()", path );
#endif
}

void lsdir( char const *path, std::vector<std::string> &list )
{
  DIR *dir;
  struct dirent *ent;

  dir = opendir (path);
  if (dir != NULL)
  {
    /* print all the files and directories within directory */
    while ((ent = readdir (dir)) != NULL)
    {
      //printf ("%s\n", ent->d_name);
      std::string item(ent->d_name);
      list.push_back(item);
    }
    closedir (dir);
  }
  else
  {
    /* could not open directory */
    throw fs::exception( "lsdir()", path );
  }
}

bool remove( char const *path ) {
#ifndef WIN32
  return ::remove( path ) == 0;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  switch ( win32::get_type( wpath, NULL ) ) {
    case directory:
      return ::RemoveDirectory( wpath ) != 0;
    case non_existent:
      return false;
    default:
      return ::DeleteFile( wpath ) != 0;
  }
#endif /* WIN32 */
}

void rename( char const *from, char const *to ) {
#ifndef WIN32
  if ( ::rename( from, to ) != 0 )
    throw fs::exception( "rename()", from );
#else
  WCHAR wfrom[ MAX_PATH ], wto[ MAX_PATH ];
  win32::to_wchar( from, wfrom );
  win32::to_wchar( to, wto );
  if ( !::MoveFile( wfrom, wto ) )
    throw fs::exception( "MoveFile()", from );
#endif /* WIN32 */
}

#endif /* ZORBA_WITH_FILE_ACCESS */

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba
/* vim:set et sw=2 ts=2: */
