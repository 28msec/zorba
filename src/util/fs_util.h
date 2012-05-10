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
#ifndef ZORBA_FS_UTIL_H
#define ZORBA_FS_UTIL_H

#include <zorba/config.h>

#include <iostream>
#include <stdexcept>
#ifdef WIN32
# include <windows.h>
#else
# include <dirent.h>
# include <sys/types.h>                 /* for off_t */
#endif /* WIN32 */

#include "ascii_util.h"
#include "cxx_util.h"
#include "error_util.h"
#include "zorbatypes/zstring.h"

#ifndef MAX_PATH
/**
 * Maximum path length.  This is defined under Windows to be 1024.  There is no
 * equivalent constant/macro for *nix systems, so simply borrow Windows' value.
 */
#define MAX_PATH 1024
#endif /* MAX_PATH */

namespace zorba {
namespace fs {

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

////////// Exceptions /////////////////////////////////////////////////////////

typedef os_error::exception exception;

////////// Directory //////////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Changes the current working directory.
 *
 * @param path The full path of the directory to change to.
 */
void chdir( char const *path );

/**
 * Changes the current working directory.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path of the directory to change to.
 */
template<class PathStringType> inline
void chdir( PathStringType const &path ) {
  chdir( path.c_str() );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

/**
 * Gets the current directory.
 *
 * @return Returns said directory.
 * @throws fs::exception if it fails.
 */
zstring curdir();

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
void mkdir( PathStringType const &path ) {
  mkdir( path.c_str() );
}

////////// Directory iteration ////////////////////////////////////////////////

/**
 * An fs::iterator iterates over the entries in a directory.
 */
class iterator {
public:
  /**
   * Constructs an %itertor.
   *
   * @throws fs::exception if the construction failed, e.g., path not found.
   */
  iterator( char const *path );

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
  zstring dir_path_;
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

  // forbid
  iterator( iterator const& );
  iterator& operator=( iterator const& );
};

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File creation //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Creates the given file.
 *
 * @param path The full path of the file to create.
 * @throws fs::exception if the creation failed.
 */
void create( char const *path );

/**
 * Creates the given file.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path of the file to create.
 * @throws fs::exception if the creation failed.
 */
template<class PathStringType> inline
void create( PathStringType const &path ) {
  create( path.c_str() );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File deletion //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Removes the given file or directory.
 *
 * @param path The full path of the file or directory to remove.
 * @return Returns \c true only if the file or directory was removed.
 */
bool remove( char const *path );

/**
 * Removes the given file or directory.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path of the file or directory to remove.
 * @return Returns \c true only if the file or directory was removed.
 */
template<class PathStringType> inline
bool remove( PathStringType const &path ) {
  return remove( path.c_str() );
}

/**
 * An %auto_remover is a simple class to guarantee that a file or directory
 * referred to by a path is deleted upon the %auto_remover getting destroyed.
 *
 * @tparam PathStringType The type of string to store and return the path as.
 */
template<class PathStringType>
class auto_remover {
public:
  typedef PathStringType string_type;

  /**
   * Constructs an %auto_remover.
   *
   * @param The full path of the file or directory to delete automatically, if
   * any.
   */
  explicit auto_remover( char const *path = "" ) : path_( path ) {
  }

  /**
   * Constructs an %auto_remover.
   *
   * @tparam PathStringType The path's string type.
   * @param The full path of the file or directory to delete automatically, if
   * any.
   */
  explicit auto_remover( PathStringType const &path ) : path_( path ) {
  }

  /**
   * Copy-constructs an %auto_remover from another.  This is a destructive
   * construction: the other %auto_remover's path will be reset to the empty
   * string.
   *
   * @param a The %auto_remover to copy from.
   */
  auto_remover( auto_remover &a ) : path_( a.release() ) {
  }

  /**
   * Copy-constructs an %auto_remover from another.  This is a destructive
   * construction: the other %auto_remover's path will be reset to the empty
   * string.
   *
   * @tparam PathStringType2 The other %auto_remover's path string type.
   * @param a The %auto_remover to copy from.
   */
  template<class PathStringType2>
  auto_remover( auto_remover<PathStringType2> &a ) : path_( a.release() ) {
  }

  /**
   * Destroys this %auto_remover.  If its path is not empty, the referred to
   * file or directory is deleted.
   */
  ~auto_remover() {
    delete_path();
  }

  /**
   * Assigns the path of another %auto_remover to this %auto_remover.  This is
   * a destructive assignment: the other %auto_remover's path will be reset to
   * the empty string.
   *
   * @param a The %auto_remover to assign from.
   * @return Returns \c *this.
   */
  auto_remover& operator=( auto_remover &a ) {
    reset( a.release() );
    return *this;
  }

  /**
   * Assigns the path of another %auto_remover to this %auto_remover.  This is
   * a destructive assignment: the other %auto_remover's path will be reset to
   * the empty string.
   *
   * @tparam PathStringType2 The other %auto_remover's path string type.
   * @param a The %auto_remover to assign from.
   * @return Returns \c *this.
   */
  template<class PathStringType2>
  auto_remover& operator=( auto_remover<PathStringType2> &a ) {
    reset( a.release() );
    return *this;
  }

  /**
   * Gets the path of the file or directory this %auto_remover will delete upon
   * destruction.
   *
   * @return Returns said path.
   */
  PathStringType const& path() const {
    return path_;
  }

  /**
   * Releases the current file or directory from being deleted automatically.
   */
  PathStringType release() {
    PathStringType const temp( path_ );
    path_.clear();
    return temp;
  }

  /**
   * Resets this %auto_remover to delete a different file or directory upon
   * destruction.  The previous file or directory is deleted immediately.
   * (If you don't want it to be deleted, call release() first.)
   *
   * @param The full path of the file or directory to delete automatically.
   */
  void reset( char const *path ) {
    if ( path != path_ ) {
      delete_path();
      path_ = path;
    }
  }

  /**
   * Resets this %auto_remover to delete a different file or directory upon
   * destruction.  The previous file or directory is deleted immediately.
   * (If you don't want it to be deleted, call release() first.)
   *
   * @param The full path of the file or directory to delete automatically.
   */
  void reset( PathStringType const &path ) {
    reset( path.c_str() );
  }

  /**
   * Resets this %auto_remover to delete a different file or directory upon
   * destruction.  The previous file or directory is deleted immediately.
   * (If you don't want it to be deleted, call release() first.)
   *
   * @tparam PathStringType2 The path's string type.
   * @param The full path of the file or directory to delete automatically.
   */
  template<class PathStringType2>
  void reset( PathStringType2 const &path ) {
    reset( path.c_str() );
  }

private:
  void delete_path() {
    if ( !path_.empty() )
      remove( path_ );
  }

  PathStringType path_;
};

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File information ///////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Gets the type of the given file.
 *
 * @param path The full path to check.
 * @param size A pointer to a receive the size of the file in bytes.  The size
 * is set only if it's not \c nullptr and the file's type is \c file.
 * @return Returns said type.
 */
type get_type( char const *path, size_type *size = nullptr );

/**
 * Gets the type of the given file.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The full path to check.
 * @param size A pointer to a receive the size of the file in bytes.  The size
 * is set only if it's not \c nullptr and the file's type is \c file.
 * @return Returns said type.
 */
template<class PathStringType> inline
type get_type( PathStringType const &path, size_type *size = nullptr ) {
  return get_type( path.c_str(), size );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

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
  return ascii::is_alpha( path[0] ) && path[1] == ':' && path[2] == '\\';
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
bool is_absolute( PathStringType const &path ) {
  return is_absolute( path.c_str() );
}

////////// File renaming //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Renames a file or directory.
 *
 * @param from The full path of the existing file or directory to rename.
 * @param to The full path of the new name for the file or directory.
 * @throws fs::exception if the rename fails.
 */
void rename( char const *from, char const *to );

/**
 * Renames a file or directory.
 *
 * @tparam FromStringType The \a from string type.
 * @param from The full path of the existing file or directory to rename.
 * @param to The full path of the new name for the file or directory.
 * @throws fs::exception if the rename fails.
 */
template<class FromStringType> inline
void rename( FromStringType const &from, char const *to ) {
  rename( from.c_str(), to );
}

/**
 * Renames a file or directory.
 *
 * @tparam ToStringType The \a to string type.
 * @param from The full path of the existing file or directory to rename.
 * @param to The full path of the new name for the file or directory.
 * @throws fs::exception if the rename fails.
 */
template<class ToStringType> inline
void rename( char const *from, ToStringType const &to ) {
  rename( from, to.c_str() );
}

/**
 * Renames a file or directory.
 *
 * @tparam FromStringType The \a from string type.
 * @tparam ToStringType The \a to string type.
 * @param from The full path of the existing file or directory to rename.
 * @param to The full path of the new name for the file or directory.
 * @throws fs::exception if the rename fails.
 */
template<class FromStringType,class ToStringType> inline
void rename( FromStringType const &from, ToStringType const &to ) {
  rename( from.c_str(), to.c_str() );
}

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
zstring get_normalized_path( char const *path, char const *base = nullptr );

/**
 * Gets the normalized path of the given path.
 *
 * @tparam PathStringType The path string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType> inline
zstring get_normalized_path( PathStringType const &path,
                             PathStringType const &base = "" ) {
  return get_normalized_path( path.c_str(), base.c_str() );
}

/**
 * Normalizes the given path.
 *
 * @tparam PathStringType The path string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 * @throws XQueryException err::XPTY0004 for malformed paths.
 */
template<class PathStringType> inline
void normalize_path( PathStringType &path, PathStringType const &base = "" ) {
  path = get_normalized_path( path, base );
}

////////// Path manipulation //////////////////////////////////////////////////

/**
 * Appends a path component onto another path ensuring that exactly one
 * separator is used.
 *
 * @param path1 The path to append to.
 * @param path2 The path to append.
 */
template<class PathStringType1>
inline void append( PathStringType1 &path1, char const *path2 ) {
  if ( !ascii::ends_with( path1, dir_separator ) )
    path1 += dir_separator;
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
template<class PathStringType1,class PathStringType2>
inline void append( PathStringType1 &path1, PathStringType2 const &path2 ) {
  append( path1, path2.c_str() );
}

/**
 * Makes a relative path into an absolute path.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The path to make absolute.
 */
template<class PathStringType> inline
void make_absolute( PathStringType &path ) {
  if ( !is_absolute( path ) ) {
#ifndef WIN32
    typedef typename PathStringType::size_type size_type;
    path.insert( static_cast<size_type>(0), static_cast<size_type>(1), '/' );
    path.insert( 0, curdir().c_str() );
#else
    char temp[ MAX_PATH ];
    win32::make_absolute_impl( path.c_str(), temp );
    path = temp;
#endif /* WIN32 */
  }
}

////////// Temporary files ////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

/**
 * Gets a path for a temporary file.
 *
 * @param path_buf A buffer to receive the path.  It must be at least
 * \c MAX_PATH bytes long.
 * @throws fs::exception if the operation fails.
 */
void get_temp_file( char *path_buf );

/**
 * Gets a path for a temporary file.
 *
 * @tparam PathStringType The \a path string type.
 * @param path The string to receive the path.
 * @throws fs::exception if the operation fails.
 */
template<class PathStringType> inline
void get_temp_file( PathStringType *path ) {
  char path_buf[ MAX_PATH ];
  get_temp_file( path_buf );
  *path = path_buf;
}

#endif /* ZORBA_WITH_FILE_ACCESS */

///////////////////////////////////////////////////////////////////////////////

} // namespace fs
} // namespace zorba

#endif /* ZORBA_FS_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
