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

#ifndef ZORBA_API_FS_UTIL_H
#define ZORBA_API_FS_UTIL_H

// standard
#include <cctype>
#include <iostream>
#include <string>
#ifdef WIN32
# include <windows.h>
#else
# include <dirent.h>
# include <sys/types.h>                 /* for off_t */
#endif /* WIN32 */

#ifndef MAX_PATH
/**
 * Maximum path length.  This is defined under Windows to be 1024.  There is no
 * equivalent constant/macro for *nix systems, so simply borrow Windows' value.
 */
#define MAX_PATH 1024
#endif /* MAX_PATH */

// Zorba
#include <zorba/config.h>
#include <zorba/internal/ztd.h>
#include <zorba/util/cxx_util.h>
#include <zorba/util/error_util.h>

namespace zorba {
namespace fs {

////////// Exceptions /////////////////////////////////////////////////////////

typedef os_error::exception exception;

////////// constants //////////////////////////////////////////////////////////

#ifdef WIN32
char const dir_separator = '\\';
char const path_separator = ';';
#else
char const dir_separator = '/';
char const path_separator = ':';
#endif /* WIN32 */

////////// types //////////////////////////////////////////////////////////////

/**
 * File size type.
 */
#ifdef WIN32
typedef __int64 size_type;
#else
typedef off_t size_type;
#endif /* WIN32 */

/**
 * File type.
 */
enum type {
  non_existent,
  directory,
  file,
  link,
  volume,
  other   // named pipe, character/block special, socket, etc.
};
extern char const *const type_string[];

/**
 * Emits the string representation of a file type to the given ostream.
 *
 * @param o The ostream to emit to.
 * @param t The file type to emit.
 * @return Returns \a o.
 */
inline std::ostream& operator<<( std::ostream &o, type t ) {
  return o << type_string[ t ];
}

////////// Windows ////////////////////////////////////////////////////////////

#ifdef WIN32
namespace win32 {

// Do not use this function directly.
void make_absolute_impl( char const *path, char *abs_path );

} // namespace win32
#endif /* WIN32 */

////////// Directory //////////////////////////////////////////////////////////

/**
 * Gets the current directory.
 *
 * @return Returns said directory.
 * @throws fs::exception if it fails.
 */
std::string curdir();

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Creates a directory.
 *
 * @param path The full path of the directory to create.
 * @throws fs::exception if the creation fails.
 */
void mkdir( char const *path );

/**
 * Creates a directory.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path of the directory to create.
 * @throws fs::exception if the creation fails.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),void>::type
mkdir( PathStringType const &path ) {
  mkdir( path.c_str() );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File deletion //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Removes the given file or directory.
 *
 * @param path The full path of the file or directory to remove.
 * @param ignore_not_found If \c true, a non-existant \a path will not throw an
 * exception.
 * @return Returns \c true if removal succeeds and \c false if it fails and
 * \a ignore_not_found is \c true.
 * @throws fs::exception if the removal fails unless \a path is non-existant
 * and \a ignore_not_found is \c true.
 */
bool remove( char const *path, bool ignore_not_found = false );

/**
 * Removes the given file or directory.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path of the file or directory to remove.
 * @param ignore_not_found If \c true, a non-existant \a path will not throw an
 * exception.
 * @return Returns \c true if removal succeeds and \c false if it fails and
 * \a ignore_not_found is \c true.
 * @throws fs::exception if the removal fails unless \a path is non-existant
 * and \a ignore_not_found is \c true.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),bool>::type
remove( PathStringType const &path, bool ignore_not_found = false ) {
  return remove( path.c_str(), ignore_not_found );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File information ///////////////////////////////////////////////////

/**
 * Checks whether the given path is an absolute path.
 *
 * @param path The full path to check.
 * @return Returns \c true only if the path is absolute.
 */
inline bool is_absolute( char const *path ) {
#ifndef WIN32
  return path[0] == '/';
#else
  //
  // No, this should NOT also check for '/'.  The path should have been
  // normalized for Windows first, i.e., have '/' replaced by '\'.
  //
  return isalpha( path[0] ) && path[1] == ':' && path[2] == '\\';
#endif /* WIN32 */
}

/**
 * Checks whether the given path is an absolute path.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path to check.
 * @return Returns \c true only if the path is absolute.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),bool>::type
is_absolute( PathStringType const &path ) {
  return is_absolute( path.c_str() );
}

/**
 * Gets the base name of the given path name, i.e., the file name without the
 * path leading up to it.
 *
 * @param path The full path to get the base name of.
 * @return Returns the base name.  Note that if \a path is just a file name,
 * then returns \a path.
 */
inline char const* base_name( char const *path ) {
  char const *const sep = ::strrchr( path, dir_separator );
  return sep && sep[1] ? sep + 1 : path;
}

/**
 * Gets the base name of the given path name, i.e., the file name without the
 * path leading up to it.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path to get the base name of.
 * @return Returns the base name.  If \a path is just a file name, returns
 * \a path.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType),PathStringType>::type
base_name( PathStringType const &path ) {
  typename PathStringType::size_type const pos = path.rfind( dir_separator );
  return pos != PathStringType::npos && pos < path.size() - 1 ?
    path.substr( pos + 1 ) : path;
}

/**
 * Gets the directory name of the given path name, i.e., the path up to but not
 * including the last path component.
 *
 * @param path The path to get the directory name of.
 * @return Returns the direcory path.  If \a path is just a file name, returns
 * <code>'.'</code>.
 */
inline std::string dir_name( char const *path ) {
  if ( char const *const sep = ::strrchr( path, dir_separator ) )
    return sep == path ?
      std::string( 1, dir_separator ) : std::string( path, sep );
  return std::string( 1, '.' );
}

/**
 * Gets the directory name of the given path name, i.e., the path up to but not
 * including the last path component.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The path to get the directory name of.
 * @return Returns the direcory path.  If \a path is just a file name, returns
 * <code>'.'</code>.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType),PathStringType>::type
dir_name( PathStringType const &path ) {
  typename PathStringType::size_type const pos = path.rfind( dir_separator );
  if ( pos == PathStringType::npos )
    return PathStringType( 1, '.' );
  if ( pos == 0 )                       // e.g., /foo
    return PathStringType( 1, dir_separator );
#ifdef WIN32
  if ( pos == 2 && is_absolute( path ) )
    return path.substr( 0, 3 );
#endif /* WIN32 */
  return path.substr( 0, pos );
}

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * File information for use with get_type().
 */
struct info {
  time_t    mtime;  ///< file's last modification time (in seconds since epoch)
  size_type size;   ///< file's size in bytes
  fs::type  type;   ///< file's type
};

/**
 * Gets the type of the given file.
 *
 * @param path The full path to check.
 * @param follow_symlink If \c true, follows symbolic links.
 * @param pinfo A pointer to a receive file information, or \c null.
 * @return If \a path refers to a symbolic link and \a follow_symlink is
 * \c true, the type returned is of that to which the link refers; if \a path
 * refers to a symbolic and \a follow_symlink is \c false, returns \c link; if
 * \a path does not refer to a symbolic link, returns the type of \a path.
 */
type get_type( char const *path, bool follow_symlink, info *pinfo = nullptr );

/**
 * Gets the type of the given file.
 *
 * @param path The full path to check.
 * @param pinfo A pointer to a receive file information, or \c null.
 * @return If \a path refers to a symbolic link, the type returned is of that
 * to which the link refers; if \a path does not refer to a symbolic link,
 * returns the type of \a path.
 */
inline type get_type( char const *path, info *pinfo = nullptr ) {
  return get_type( path, true, pinfo );
}

/**
 * Gets the type of the given file.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path to check.
 * @param follow_symlink If \c true, follows symbolic links.
 * @param pinfo A pointer to a receive file information, or \c null.
 * @return If \a path refers to a symbolic link and \a follow_symlink is
 * \c true, the type returned is of that to which the link refers; if \a path
 * refers to a symbolic and \a follow_symlink is \c false, returns \c link; if
 * \a path does not refer to a symbolic link, returns the type of \a path.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),type>::type
get_type( PathStringType const &path, bool follow_symlink,
          info *pinfo = nullptr ) {
  return get_type( path.c_str(), follow_symlink, pinfo );
}

/**
 * Gets the type of the given file.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path to check.
 * @param pinfo A pointer to a receive file information, or \c null.
 * @return If \a path refers to a symbolic link, the type returned is of that
 * to which the link refers; if \a path does not refer to a symbolic link,
 * returns the type of \a path.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),type>::type
get_type( PathStringType const &path, info *pinfo = nullptr ) {
  return get_type( path.c_str(), pinfo );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// Directory iteration ////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * An %fs::iterator iterates over the entries in a directory.
 */
class iterator {
public:
  /**
   * Constructs an %iterator.
   *
   * @param path The full path to the directory to iterate over.
   * @throws fs::exception if the construction failed, e.g., path not found.
   */
  iterator( char const *path ) : dir_path_( path ) {
    ctor_impl();
  }

  /**
   * Constructs an %iterator.
   *
   * @tparam PathStringType The \a path string type.
   * @param path The full path to the directory to iterate over.
   * @throws fs::exception if the construction failed, e.g., path not found.
   */
  template<class PathStringType>
  iterator( PathStringType const &path,
            typename std::enable_if<ZORBA_HAS_C_STR(PathStringType)
                                   >::type* = 0 ) : dir_path_( path.c_str() ) {
    ctor_impl();
  }

  /**
   * Destroys this %iterator.
   */
  ~iterator();

  /**
   * Attempts to get the next directory entry.
   *
   * @return Returns \c true only if there is a next directory.
   */
  bool next();

  /**
   * Gets the name of the curent directory entry.
   *
   * @return Returns said name.
   */
  char const* entry_name() const {
#   ifndef WIN32
    return ent_->d_name;
#   else
    return ent_name_;
#   endif /* WIN32 */
  }

  /**
   * Gets the type of the current directory entry.
   *
   * @return Returns said type.
   */
  type entry_type() const {
    return ent_type_;
  }

  /**
   * Gets the directory's path.
   *
   * @return Returns said path.
   */
  char const* path() const {
    return dir_path_.c_str();
  }

  /**
   * Resets this iterator to the beginning.
   */
  void reset();

private:
  std::string dir_path_;
  type ent_type_;
#ifndef WIN32
  DIR *dir_;
  struct dirent *ent_;
#else
  HANDLE dir_;
  bool dir_is_empty_;
  WIN32_FIND_DATA ent_data_;
  char ent_name_[ MAX_PATH ];
  bool use_first_;

  void win32_opendir( char const *path );
  void win32_closedir();
#endif /* WIN32 */

  void ctor_impl();

  // forbid
  iterator( iterator const& );
  iterator& operator=( iterator const& );
};

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// Path normalization /////////////////////////////////////////////////

/**
 * Gets the normalized path of the given path.
 *
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
std::string get_normalized_path( char const *path, char const *base = nullptr );

/**
 * Gets the normalized path of the given path.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The path to normalize.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),std::string>::type
get_normalized_path( PathStringType const &path ) {
  return get_normalized_path( path.c_str() );
}

/**
 * Gets the normalized path of the given path.
 *
 * @tparam PathStringType The \a path string type.
 * @tparam BaseStringType The \a base string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType,class BaseStringType> inline
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType)
                     && ZORBA_HAS_C_STR(BaseStringType),
                        std::string>::type
get_normalized_path( PathStringType const &path,
                     BaseStringType const &base ) {
  return get_normalized_path( path.c_str(), base.c_str() );
}

/**
 * Normalizes the given path.
 *
 * @tparam PathStringType The path string type.
 * @param path The path to normalize.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType),void>::type
normalize_path( PathStringType &path ) {
  path = get_normalized_path( path );
}

/**
 * Normalizes the given path.
 *
 * @tparam PathStringType The path string type.
 * @tparam BaseStringType The \a base string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType,class BaseStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType)
                     && ZORBA_IS_STRING(BaseStringType),
                        void>::type
normalize_path( PathStringType &path, BaseStringType const &base ) {
  path = get_normalized_path( path, base );
}

////////// Path manipulation //////////////////////////////////////////////////

/**
 * Appends a path component onto another path ensuring that exactly one
 * separator is used.
 *
 * @tparam PathStringType1 The \a path1 string type.
 * @param path1 The path to append to.
 * @param path2 The path to append.
 */
template<class PathStringType1> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType1),void>::type
append( PathStringType1 &path1, char const *path2 ) {
  if ( !path1.empty() && path1[ path1.size() - 1 ] != dir_separator
       && path2[0] != dir_separator ) {
    path1 += dir_separator;
  }
  path1 += path2;
}

/**
 * Appends a path component onto another path.
 *
 * @tparam PathStringType1 The \a path1 string type.
 * @tparam PathStringType2 The \a path2 string type.
 * @param path1 The path to append to.
 * @param path2 The path to append.
 */
template<class PathStringType1,class PathStringType2> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType1)
                     && ZORBA_HAS_C_STR(PathStringType2),
                        void>::type
append( PathStringType1 &path1, PathStringType2 const &path2 ) {
  append( path1, path2.c_str() );
}

/**
 * Makes a relative path into an absolute path.
 *
 * @param path The path to make absolute.  It is assumes that the buffer to
 * which \a path points is at least MAX_PATH bytes.
 */
void make_absolute( char *path );

/**
 * Makes a relative path into an absolute path.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The path to make absolute.
 */
template<class PathStringType> inline
typename std::enable_if<ZORBA_IS_STRING(PathStringType),void>::type
make_absolute( PathStringType &path ) {
  if ( !is_absolute( path ) ) {
#ifndef WIN32
    typedef typename PathStringType::size_type size_type;
    path.insert( static_cast<size_type>(0), 1, '/' );
    path.insert( 0, curdir().c_str() );
#else
    char temp[ MAX_PATH ];
    win32::make_absolute_impl( path.c_str(), temp );
    path = temp;
#endif /* WIN32 */
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba
#endif /* ZORBA_API_FS_UTIL_H */
/*
* Local variables:
* mode: c++
* End:
*/
/* vim:set et sw=2 ts=2: */
