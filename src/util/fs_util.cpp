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

# include <cstdlib>                     /* for getenv(3), _dupenv_s() */
#ifndef WIN32
# include <climits>                     /* for PATH_MAX */
# include <cstdio>
# include <fcntl.h>                     /* for creat(2) */
# include <sys/stat.h>
# include <sys/types.h>
# include <unistd.h>                    /* for chdir(2) */
#else
# include <shlwapi.h>
#endif /* WIN32 */

#include <zorba/internal/cxx_util.h>

#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/mutex.h"

#include "ascii_util.h"
#include "fs_util.h"
#include "string_util.h"
#include "uri_util.h"

using namespace std;

namespace zorba {
namespace fs {

///////////////////////////////////////////////////////////////////////////////

ostream& operator<<( ostream &o, type t ) {
  static char const *const string_of[] = {
    "non_existant",
    "directory",
    "file",
    "link",
    "volume",
    "other"
  };
  if ( t >= 0 && t <= other )
    o << string_of[ t ];
  else
    o << "<invalid fs::type " << (int)t << '>';
  return o;
}

////////// helper functions ///////////////////////////////////////////////////

static void canonicalize( string *path ) {
#ifdef WIN32
  // Temporarily remove the drive letter and ':' to make the code simpler.
  string drive;
  if ( is_absolute( *path ) ) {
    drive = path->substr( 0, 2 );
    path->erase( 0, 2 );
  }
#endif /* WIN32 */

  bool added_sentinel;
  if ( !ascii::ends_with( *path, dir_separator ) ) {
    *path += dir_separator;             // add sentinel
    added_sentinel = true;
  } else
    added_sentinel = false;

  ////////// Part 1: replace // by /

  char rbuf[5];
  rbuf[0] = rbuf[1] = dir_separator;

  while ( ascii::replace_all( *path, rbuf, 2, rbuf, 1 ) )
    ;

  ////////// Part 2: remove ./

  // actually look for /./ so as not to interfere with ../ case
  rbuf[0] = rbuf[2] = dir_separator;
  rbuf[1] = '.';

  while ( ascii::replace_all( *path, rbuf, 3, rbuf, 1 ) )
    ;

  ////////// Part 3: remove ../

  rbuf[0] = rbuf[3] = dir_separator;
  rbuf[1] = rbuf[2] = '.';
  rbuf[4] = '\0';

  for ( string::size_type pos = 0;
        (pos = path->find( rbuf, pos )) != string::npos; ) {
    if ( !pos )                         // leading /../
      path->erase( 0, 3 );
    else {
      string::size_type const prev_pos = path->rfind( dir_separator, pos - 1 );
      if ( prev_pos == string::npos ) {
        // "y/../z" => "z"
        path->erase( 0, pos + 4 );
        break;
      } else {
        // "x/y/../z" => "x/z"
        path->erase( prev_pos, pos - prev_pos + 3 );
        pos = prev_pos;
      }
    }
  }

  if ( added_sentinel && path->size() > 1 )
    path->erase( path->size() - 1 );    // remove sentinel
#ifdef WIN32
  path->insert( 0, drive );
#endif /* WIN32 */
}

#ifndef WIN32
inline bool is_dots( char const *s ) {
  return s[0] == '.' && (!s[1] || (s[1] == '.' && !s[2]));
}
#else
inline bool is_dots( LPCWSTR s ) {
  return s[0] == TEXT('.') && (!s[1] || (s[1] == TEXT('.') && !s[2]));
}
#endif /* WIN32 */

template<class PathStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType),void>::type
replace_foreign( PathStringType *path ) {
#ifdef WIN32
  ascii::replace_all( *path, '/', '\\' );
#else
  ascii::replace_all( *path, '\\', '/' );
#endif /* WIN32 */
}

static bool parse_file_uri( char const *uri, string *result ) {
  if ( !ZA_BEGINS_WITH( uri, "file://" ) )
    return false;

  using namespace diagnostic;

  *result = uri + 7;
  if ( result->empty() )
    throw invalid_argument( dict::lookup( ZED( EmptyPath ) ) );
  string::size_type slash = result->find( '/' );
  if ( slash == string::npos )
    throw invalid_argument(
      BUILD_STRING( '"', uri, "\": ", dict::lookup( ZED( BadPath ) ) )
    );
  if ( slash > 0 ) {
    string const authority( result->substr( 0, slash ) );
    if ( authority != "localhost" )
      throw invalid_argument(
        BUILD_STRING(
          '"', authority, "\": ", dict::lookup( ZED( NonLocalhostAuthority ) )
        )
      );
  }
#ifdef WIN32
  ++slash;                              // skip leading '/' in "/C:/file.txt"
#endif /* WIN32 */
  *result = result->substr( slash );
  uri::decode( *result );
#ifdef WIN32
  replace_foreign( result );
  if ( !is_absolute( *result ) )
    throw invalid_argument(
      BUILD_STRING(
        '"', result, "\": ", dict::lookup( ZED( NoDriveSpecification ) )
      )
    );
#endif /* WIN32 */
  return true;
}

////////// Windows functions //////////////////////////////////////////////////

#ifdef WIN32

#ifdef ZORBA_WITH_FILE_ACCESS

static type win32_map_type( DWORD dwFileAttributes ) {
  if ( dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY )
    return directory;
  if ( dwFileAttributes & FILE_ATTRIBUTE_REPARSE_POINT )
    return link;
  return file;
}

static type win32_get_type( LPCWSTR wpath, info *pinfo = nullptr ) {
  WIN32_FILE_ATTRIBUTE_DATA data;
  if ( ::GetFileAttributesEx( wpath, GetFileExInfoStandard, (void*)&data ) ) {
    fs::type const type = win32_map_type( data.dwFileAttributes );
    if ( pinfo ) {
      FILETIME const &ft = data.ftLastWriteTime;
      pinfo->mtime = ((time_t)ft.dwHighDateTime << 32) | ft.dwLowDateTime;
      pinfo->size = ((size_type)data.nFileSizeHigh << 32) | data.nFileSizeLow;
      pinfo->type = type;
    }
    return type;
  }
  return non_existent;
}

#endif /* ZORBA_WITH_FILE_ACCESS */

void win32_make_absolute( char const *path, char *abs_path ) {
#ifndef WINCE
  WCHAR wpath[ MAX_PATH ];
  win32::atow( path, wpath, MAX_PATH );
  WCHAR wfull_path[ MAX_PATH ];
  DWORD const result = ::GetFullPathName( wpath, MAX_PATH, wfull_path, NULL );
  if ( !result )
    throw ZORBA_IO_EXCEPTION( "GetFullPathName()", path );
  win32::wtoa( wfull_path, abs_path, MAX_PATH );
#else
  if ( abs_path != path )
    ::strcpy( abs_path, path );
#endif /* WINCE */
}

#endif /* WIN32 */

///////////////////////////////////////////////////////////////////////////////

void append( char *path1, char const *path2 ) {
  size_t path1_len = ::strlen( path1 );
  if ( path1_len ) {
    char const path1_last = path1[ path1_len - 1 ];
    if ( path1_last != dir_separator && path2[0] != dir_separator )
      path1[ path1_len++ ] = dir_separator;
    else if ( path1_last == dir_separator && path2[0] == dir_separator )
      ++path2;
  }
  ::strcpy( path1 + path1_len, path2 );
}

#ifdef ZORBA_WITH_FILE_ACCESS

void chdir( char const *path ) {
#ifndef WIN32
  if ( ::chdir( path ) != 0 )
    throw fs::exception( "chdir()", path );
#else
  WCHAR wpath[ MAX_PATH ];
  win32::atow( path, wpath, MAX_PATH );
  if ( ::_wchdir( wpath ) != 0 )
    throw fs::exception( "_wchdir()", path );
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
  win32::atow( path, wpath, MAX_PATH );
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

string configdir() {
#if defined( WINCE )
  return "";
#elif defined( WIN32 )
  char *buf;
  if ( _dupenv_s( &buf, nullptr, "APPDATA" ) != 0 )
    throw ZORBA_IO_EXCEPTION( "_dupenv_s()", "" );
  unique_ptr<char[]> const buf_ptr( buf );
  return buf;
#else
  return getenv( "HOME" );
#endif
}

string curdir() {
#ifndef WIN32
  static size_t dir_buf_len = PATH_MAX;
  static unique_ptr<char[]> dir_buf( new char[ dir_buf_len ] );

#ifndef ZORBA_FOR_ONE_THREAD_ONLY
  static Mutex mutex;
  AutoMutex const lock( &mutex );
#endif /* ZORBA_FOR_ONE_THREAD_ONLY */

  while ( !::getcwd( dir_buf.get(), dir_buf_len ) ) {
    if ( errno != ERANGE )
      throw ZORBA_IO_EXCEPTION( "getcwd()", "" );
    dir_buf.reset( new char[ dir_buf_len *= 2 ] );
  }
  return dir_buf.get();
#else
  WCHAR wpath[ MAX_PATH ];
  if ( !::GetCurrentDirectory( MAX_PATH, wpath ) )
    throw ZORBA_IO_EXCEPTION( "GetCurrentDirectory()", "" );
  char path[ MAX_PATH ];
  win32::wtoa( wpath, path, MAX_PATH );
  string dir( path );
  if ( !is_absolute( dir ) ) {
    // GetCurrentDirectory() sometimes misses the drive letter.
    make_absolute( &dir );
  }
  return dir;
#endif /* WIN32 */
}

#ifdef ZORBA_WITH_FILE_ACCESS

zstring get_temp_file() {
#ifndef WIN32
  static char const mkdtemp_template[] = "zorba_tmp.XXXXXXXX";
  static size_t const mkdtemp_template_len = ::strlen( mkdtemp_template );

  char const *tmp_dir = ::getenv( "TMPDIR" );
  if ( !tmp_dir )
    tmp_dir = "/tmp";
  unique_ptr<char[]> buf(
    new char[
      ::strlen( tmp_dir )
      + 1 // dir_separator
      + mkdtemp_template_len
      + 1 // null
    ]
  );
  ::strcpy( buf.get(), tmp_dir );
  append( buf.get(), mkdtemp_template );
  char const *const path = ::mkdtemp( buf.get() );
  if ( !path )
    throw fs::exception( "mkdtemp()", path );
  return path;
#else
  WCHAR wtemp[ MAX_PATH ];
  // GetTempFileName() needs a 14-character cushion.
  DWORD const wtemp_len = ::GetTempPath( MAX_PATH - 14, wtemp );
  if ( !wtemp_len || wtemp_len > MAX_PATH - 14 )
    throw fs::exception( "GetTempPath()", nullptr );
  WCHAR wpath[ MAX_PATH ];
  UINT const u_result = ::GetTempFileName( wtemp, TEXT("zxq"), 0, wpath );
  if ( !u_result )
    throw fs::exception( "GetTempFileName()", nullptr );
  char path[ MAX_PATH ];
  win32::wtoa( wpath, path, MAX_PATH );
  return path;
#endif /* WIN32 */
}

#endif /* ZORBA_WITH_FILE_ACCESS */

type get_type( char const *path, bool follow_symlink, info *pinfo ) {
  if ( pinfo )
    ::memset( pinfo, 0, sizeof( info ) );
#ifndef WIN32
  struct stat st_buf;
  int const status = follow_symlink ?
    ::stat( path, &st_buf ) : ::lstat( path, &st_buf );
  if ( status == -1 ) {
    switch ( errno ) {
      case ENOENT:
        return non_existent;
      case EACCES:
      case ELOOP:
      case ENAMETOOLONG:
      case ENOTDIR:
        throw fs::exception( follow_symlink ? "stat()" : "lstat()", path );
      default:
        throw ZORBA_IO_EXCEPTION( follow_symlink ? "stat()" : "lstat()", path );
    }
  }

  fs::type type;
  if ( S_ISDIR( st_buf.st_mode ) )
    type = directory;
  else if ( S_ISLNK( st_buf.st_mode ) )
    type = link;
  else if ( S_ISREG( st_buf.st_mode ) )
    type = file;
  else
    type = other;

  if ( pinfo ) {
    pinfo->mtime = st_buf.st_mtime;
    pinfo->size = st_buf.st_size;
    pinfo->type = type;
  }
  return type;
#else
  WCHAR wpath[ MAX_PATH ];
  win32::atow( path, wpath, MAX_PATH );
  return win32_get_type( wpath, pinfo );
#endif /* WIN32 */
}

#ifdef ZORBA_WITH_FILE_ACCESS

void mkdir_impl( char const *path, bool ignore_exists = false ) {
#ifndef WIN32
  if ( ::mkdir( path, 0755 ) != 0 &&
       !(ignore_exists && (errno == EEXIST || errno == EISDIR)) ) {
    throw fs::exception( "mkdir()", path );
  }
#else
  WCHAR wpath[ MAX_PATH ];
  win32::atow( path, wpath, MAX_PATH );
  if ( !::CreateDirectory( wpath, NULL ) &&
       !(ignore_exists && ::GetLastError() == ERROR_ALREADY_EXISTS) ) {
    throw fs::exception( "CreateDirectory()", path );
  }
#endif /* WIN32 */
}

void mkdir( char const *path, bool intermediate ) {
  if ( !intermediate )
    mkdir_impl( path );
  else {
    string const dir( dir_name( path ) );
    if ( dir != path )
      mkdir( dir, true );
    else
      mkdir_impl( dir.c_str(), true );
    mkdir_impl( path, true );
  }
}

string normalize_path( char const *path, char const *base ) {
  if ( !path[0] )
    throw invalid_argument( "empty path" );
  string new_path;
  if ( !parse_file_uri( path, &new_path ) ) {
    //
    // The path is an ordinary path.
    //
    string local_path( path );
    replace_foreign( &local_path );
    if ( !is_absolute( local_path ) && base && base[0] ) {
      new_path = base;
      replace_foreign( &new_path );
      append( new_path, local_path );
    } else
      new_path = local_path;
  }
  canonicalize( &new_path );
  return new_path;
}

void iterator::ctor_impl() {
  make_absolute( &dir_path_ );
#ifndef WIN32
  if ( !(dir_ = ::opendir( dir_path_.c_str() )) )
    throw fs::exception( "iterator()", dir_path_.c_str() );
#else
  win32_opendir( dir_path_.c_str() );
  entry_.name = entry_name_buf_;
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
    if ( dirent const *const entry = ::readdir( dir_ ) ) {
      entry_.name = entry->d_name;
      switch ( entry->d_type ) {
        case DT_DIR:
          if ( is_dots( entry_.name ) )
            continue;                   // skip "." and ".." entries
          entry_.type = directory;
          break;
        case DT_LNK:
          entry_.type = link;
          break;
        case DT_REG:
          entry_.type = file;
          break;
        case DT_UNKNOWN: {
          //
          // The d_type member is not supported by all filesystems. If it's
          // not, it will be set to DT_UNKNOWN.  Hence, we're forced to do an
          // explicit stat() to determine the entry type.
          //
          // This check fixes bug #1023862.
          //
          zstring entry_path( dir_path_ );
          append( entry_path, entry_.name );
          entry_.type = get_type( entry_path );
          if ( entry_.type == directory && is_dots( entry_.name ) )
            continue;                   // skip "." and ".." entries
          break;
        }
        default:
          entry_.type = other;
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

      if ( is_dots( ent_data_.cFileName ) )
        continue;                       // skip "." and ".." entries
      win32::wtoa( ent_data_.cFileName, entry_name_buf_, MAX_PATH );
      entry_.type = win32_map_type( ent_data_.dwFileAttributes );
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
  win32::atow( path, wpath, MAX_PATH );
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

bool remove( char const *path, bool ignore_not_found ) {
#ifndef WIN32
  if ( ::remove( path ) == 0 )
    return true;
  if ( ignore_not_found && errno == ENOENT )
    return false;
  throw fs::exception( "remove()", path );
#else
  WCHAR wpath[ MAX_PATH ];
  win32::atow( path, wpath, MAX_PATH );
  char const *win32_fn_name;

  switch ( win32_get_type( wpath ) ) {
    case directory:
      win32_fn_name = "RemoveDirectory()";
      if ( ::RemoveDirectory( wpath ) )
        return true;
      break;
    default:
      win32_fn_name = "DeleteFile()";
      if ( ::DeleteFile( wpath ) )
        return true;
  }
  if ( ignore_not_found && ::GetLastError() == ERROR_FILE_NOT_FOUND )
    return false;
  throw fs::exception( win32_fn_name, path );
#endif /* WIN32 */
}

void rename( char const *from, char const *to ) {
#ifndef WIN32
  if ( ::rename( from, to ) != 0 )
    throw fs::exception( "rename()", from );
#else
  WCHAR wfrom[ MAX_PATH ], wto[ MAX_PATH ];
  win32::atow( from, wfrom, MAX_PATH );
  win32::atow( to, wto, MAX_PATH );
  if ( !::MoveFile( wfrom, wto ) )
    throw fs::exception( "MoveFile()", from );
#endif /* WIN32 */
}

#endif /* ZORBA_WITH_FILE_ACCESS */

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba
/* vim:set et sw=2 ts=2: */
