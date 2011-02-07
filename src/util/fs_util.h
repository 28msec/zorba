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

#ifndef ZORBA_FS_UTIL_H
#define ZORBA_FS_UTIL_H

#include <zorba/config.h>

#include <stdexcept>
#ifdef WIN32
# include <windows.h>
#else
# include <sys/types.h>                 /* for off_t */
#endif /* WIN32 */

#include "ascii_util.h"
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
char const separator = '\\';
#else
char const separator = '/';
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

////////// Exceptions /////////////////////////////////////////////////////////

/**
 * An %fs::exception is-a std::runtime_error for reporting errors with fs
 * functions.
 */
class exception : public std::runtime_error {
public:
  explicit exception( char const *what ) : std::runtime_error( what ) { }

  template<class StringType>
  explicit exception( StringType const &what ) :
    std::runtime_error( what.c_str() ) { }
};

////////// File deletion //////////////////////////////////////////////////////

/**
 * Removes the given file or directory.
 *
 * @param path The path of the file or directory to remove.
 * @return Returns \c true only if the file or directory was removed.
 */
bool remove( char const *path );

/**
 * Removes the given file or directory.
 *
 * @param path The path of the file or directory to remove.
 * @return Returns \c true only if the file or directory was removed.
 */
template<class StringType> inline
bool remove( StringType const &path ) {
  return remove( path.c_str() );
}

/**
 * An %auto_remover is a simple class to guarantee that a file or directory
 * referred to by a path is deleted upon the %auto_remover getting destroyed.
 *
 * @tparam StringType The type of string to store and return the path as.
 */
template<class StringType>
class auto_remover {
public:
  typedef StringType string_type;

  /**
   * Constructs an %auto_remover.
   *
   * @param The path of the file or directory to delete automatically, if any.
   */
  explicit auto_remover( char const *path = "" ) : path_( path ) {
  }

  /**
   * Constructs an %auto_remover.
   *
   * @tparam StringType The path's string type.
   * @param The path of the file or directory to delete automatically, if any.
   */
  explicit auto_remover( StringType const &path ) : path_( path ) {
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
   * @tparam StringType2 The other %auto_remover's string type.
   * @param a The %auto_remover to copy from.
   */
  template<class StringType2>
  auto_remover( auto_remover<StringType2> &a ) : path_( a.release() ) {
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
   * @tparam StringType2 The other %auto_remover's string type.
   * @param a The %auto_remover to assign from.
   * @return Returns \c *this.
   */
  template<class StringType2>
  auto_remover& operator=( auto_remover<StringType2> &a ) {
    reset( a.release() );
    return *this;
  }

  /**
   * Gets the path of the file or directory this %auto_remover will delete upon
   * destruction.
   *
   * @return Returns said path.
   */
  StringType const& path() const {
    return path_;
  }

  /**
   * Releases the current file or directory from being deleted automatically.
   */
  StringType release() {
    StringType const temp( path_ );
    path_.clear();
    return temp;
  }

  /**
   * Resets this %auto_remover to delete a different file or directory upon
   * destruction.  The previous file or directory is deleted immediately.
   * (If you don't want it to be deleted, call release() first.)
   *
   * @param The path of the file or directory to delete automatically.
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
   * @param The path of the file or directory to delete automatically.
   */
  void reset( StringType const &path ) {
    reset( path.c_str() );
  }

  /**
   * Resets this %auto_remover to delete a different file or directory upon
   * destruction.  The previous file or directory is deleted immediately.
   * (If you don't want it to be deleted, call release() first.)
   *
   * @tparam StringType2 The path's string type.
   * @param The path of the file or directory to delete automatically.
   */
  template<class StringType2>
  void reset( StringType2 const &path ) {
    reset( path.c_str() );
  }

private:
  void delete_path() {
    if ( !path_.empty() )
      remove( path_ );
  }

  StringType path_;
};

////////// File information ///////////////////////////////////////////////////

/**
 * Gets the type of the given file.
 *
 * @param path The path to check.
 * @return Returns said type.
 */
type get_type( char const *path );

/**
 * Gets the type of the given file.
 *
 * @param path The path to check.
 * @return Returns said type.
 */
template<class StringType> inline
type get_type( StringType const &path ) {
  return get_type( path.c_str() );
}

/**
 * Checks whether the given path is an absolute path.
 *
 * @param path The path to check.
 * @return Returns \c true only if the path is absolute.
 */
inline bool is_absolute( char const *path ) {
#ifndef WIN32
  return path[0] == '/';
#else
  return ascii::is_alpha( path[0] ) && path[1] == ':';
#endif /* WIN32 */
}

/**
 * Checks whether the given path is an absolute path.
 *
 * @param path The path to check.
 * @return Returns \c true only if the path is absolute.
 */
template<class StringType> inline
bool is_absolute( StringType const &path ) {
  return is_absolute( path.c_str() );
}

////////// Path normalization /////////////////////////////////////////////////

/**
 * Gets the normalized path of the given path.
 *
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 */
zstring get_normalized_path( char const *path, char const *base = 0 );

/**
 * Gets the normalized path of the given path.
 *
 * @tparam StringType The string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 */
template<class StringType> inline
zstring get_normalized_path( StringType const &path,
                             StringType const &base = "" ) {
  return get_normalized_path( path.c_str(), base.c_str() );
}

/**
 * Normalizes the given path.
 *
 * @tparam StringType The string type.
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 */
template<class StringType> inline
void normalize_path( StringType &path, StringType const &base = "" ) {
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
template<class StringType1>
inline void append( StringType1 &path1, char const *path2 ) {
  if ( !ascii::ends_with( path1, separator ) )
    path1 += separator;
  path1 += path2;
}

/**
 * Appends a path component onto another path.
 *
 * @param path1 The path to append to.
 * @param path2 The path to append.
 */
template<class StringType1,class StringType2>
inline void append( StringType1 &path1, StringType2 const &path2 ) {
  append( path1, path2.c_str() );
}

////////// Temporary files ////////////////////////////////////////////////////

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
 * @tpatah StringType The string type.
 * @param path The string to receive the path.
 * @throws fs::exception if the operation fails.
 */
template<class StringType> inline
void get_temp_file( StringType *path ) {
  char path_buf[ MAX_PATH ];
  get_temp_file( path_buf );
  *path = path_buf;
}

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
