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
#else
# include <shlwapi.h>
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

///////////////////////////////////////////////////////////////////////////////

char const *const type_string[] = {
  "non_existant",
  "directory",
  "file",
  "link",
  "volume",
  "other"
};

////////// helper functions ///////////////////////////////////////////////////

#ifndef WIN32
inline bool is_dots( char const *s ) {
  return s[0] == '.' && (!s[1] || (s[1] == '.' && !s[2]));
}
#else
inline bool is_dots( LPCWSTR s ) {
  return s[0] == TEXT('.') && (!s[1] || (s[1] == TEXT('.') && !s[2]));
}
#endif /* WIN32 */

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

static type map_type( DWORD dwFileAttributes ) {
  if ( dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
    return directory;
  if ( dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT )
    return link;
  return file;
}

static type get_type( LPCWSTR wpath, size_type *size = nullptr ) {
  WIN32_FILE_ATTRIBUTE_DATA data;
  if ( ::GetFileAttributesEx( wpath, GetFileExInfoStandard, (void*)&data ) ) {
    type const t = map_type( data.dwFileAttributes );
    if ( t == file && size )
      *size = ((size_type)data.nFileSizeHigh << 32) | data.nFileSizeLow;
    return t;
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
    wpath, sizeof( wfull_path ) / sizeof( wfull_path[0] ), wfull_path, NULL
  );
  if ( !result )
    throw ZORBA_IO_EXCEPTION( "GetFullPathName()", path );
  to_char( wfull_path, abs_path );
#else
  ::strcpy( abs_path, path );
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
    filesystem_path fspath( path );
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
    //
    // The path is a file:// URI.
    //
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
    //
    // The path is an ordinary path.
    //
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

#endif /* ZORBA_WITH_FILE_ACCESS */

type get_type( char const *path, bool follow_symlink, size_type *size ) {
#ifndef WIN32
  struct stat st_buf;
  int const status = follow_symlink ?
    ::stat( path, &st_buf ) : ::lstat( path, &st_buf );
  if ( status == -1 ) {
    if ( errno == ENOENT )
      return non_existent;
    throw ZORBA_IO_EXCEPTION( follow_symlink ? "stat()" : "lstat()", path );
  }
  if ( S_ISDIR( st_buf.st_mode ) )
    return directory;
  if ( S_ISLNK( st_buf.st_mode ) )
    return link;
  if ( S_ISREG( st_buf.st_mode ) ) {
    if ( size )
      *size = st_buf.st_size;
    return file;
  }
  return other;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  return win32::get_type( wpath, size );
#endif /* WIN32 */
}

#ifdef ZORBA_WITH_FILE_ACCESS

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

void iterator::ctor_impl() {
  make_absolute( dir_path_ );
#ifndef WIN32
  if ( !(dir_ = ::opendir( dir_path_.c_str() )) )
    throw fs::exception( "iterator()", dir_path_.c_str() );
#else
  win32_opendir( dir_path_.c_str() );
#endif /* WIN32 */
}

iterator::~iterator() {
#ifndef WIN32
  if ( ::closedir( dir_ ) != 0 )
    throw fs::exception( "closedir()", path() );
#else
  win32_closedir();
#endif /* WIN32 */
}

bool iterator::next() {
  while ( true ) {
#ifndef WIN32
    if ( (ent_ = ::readdir( dir_ )) ) {
      switch ( ent_->d_type ) {
        case DT_DIR:
          if ( is_dots( ent_->d_name ) )
            continue;                   // skip "." and ".." entries
          ent_type_ = directory;
          break;
        case DT_LNK:
          ent_type_ = link;
          break;
        case DT_REG:
          ent_type_ = file;
          break;
        case DT_UNKNOWN: {
          //
          // The d_type member is not supported by all filesystems. If it's
          // not, it will be set to DT_UNKNOWN.  Hence, we're forced to do an
          // explicit stat() to determine the entry type.
          //
          // This check fixes bug #1023862.
          //
          zstring ent_path( dir_path_ );
          fs::append( ent_path, ent_->d_name );
          ent_type_ = get_type( ent_path );
          if ( ent_type_ == directory && is_dots( ent_->d_name ) )
            continue;                   // skip "." and ".." entries
          break;
        }
        default:
          ent_type_ = other;
      }
      return true;
    }
#else
    if ( !dir_is_empty_ ) {
      if ( use_first_ )
        use_first_ = false;
      else
        if ( !::FindNextFile( dir_, &ent_data_ ) ) {
          if ( ::GetLastError() != ERROR_NO_MORE_FILES )
            throw fs::exception( "FindNextFile()", path() );
          return false;
        }

      LPCWSTR const wname = ent_data_.cFileName;
      if ( is_dots( wname ) )
        continue;                       // skip "." and ".." entries
      win32::to_char( wname, ent_name_ );
      ent_type_ = win32::map_type( ent_data_.dwFileAttributes );
      return true;
    }
#endif /* WIN32 */
    return false;
  } // while
}

void iterator::reset() {
#ifndef WIN32
  ::rewinddir( dir_ );
#else
  win32_closedir();
  win32_opendir( dir_path_.c_str() );
#endif /* WIN32 */
}

#ifdef WIN32
void iterator::win32_closedir() {
  if ( dir_ != INVALID_HANDLE_VALUE && !::FindClose( dir_ ) )
    throw fs::exception( "FindClose()", path() );
}

void iterator::win32_opendir( char const *path ) {
  WCHAR wpath[ MAX_PATH ];
  win32::to_wchar( path, wpath );
  WCHAR wpattern[ MAX_PATH ];
  ::wcscpy( wpattern, wpath );
  ::PathAppend( wpattern, TEXT("*") );
  dir_ = ::FindFirstFile( wpattern, &ent_data_ );
  if ( dir_ == INVALID_HANDLE_VALUE ) {
    if ( ::GetLastError() != ERROR_FILE_NOT_FOUND )
      throw fs::exception( "FindFirstFile()", path );
    dir_is_empty_ = true;
  } else {
    dir_is_empty_ = false;
    use_first_ = true;
  }
}
#endif /* WIN32 */

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
