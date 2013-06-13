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

#include <zorba/util/fs_util.h>

#include "string_util.h"

namespace zorba {
namespace fs {

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
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),void>::type
chdir( PathStringType const &path ) {
  chdir( path.c_str() );
}

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
typename std::enable_if<ZORBA_HAS_C_STR(PathStringType),void>::type
create( PathStringType const &path ) {
  create( path.c_str() );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

////////// File deletion //////////////////////////////////////////////////////

#ifdef ZORBA_WITH_FILE_ACCESS

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
typename std::enable_if<ZORBA_HAS_C_STR(FromStringType),void>::type
rename( FromStringType const &from, char const *to ) {
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
typename std::enable_if<ZORBA_HAS_C_STR(ToStringType),void>::type
rename( char const *from, ToStringType const &to ) {
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
typename std::enable_if<ZORBA_HAS_C_STR(FromStringType)
                     && ZORBA_HAS_C_STR(ToStringType),
                        void>::type
rename( FromStringType const &from, ToStringType const &to ) {
  rename( from.c_str(), to.c_str() );
}

#endif /* ZORBA_WITH_FILE_ACCESS */

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
typename std::enable_if<ZORBA_IS_STRING(PathStringType),void>::type
get_temp_file( PathStringType *path ) {
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
