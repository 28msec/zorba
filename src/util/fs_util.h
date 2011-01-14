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

#ifndef WIN32
#include <sys/types.h>                  /* for off_t */
#endif

#include "ascii_util.h"
#include "zorbatypes/zstring.h"

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

////////// functions //////////////////////////////////////////////////////////

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

/**
 * Gets the normalized path of the given path.
 *
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 */
zstring get_normalized_path( zstring const &path, zstring const &base = "" );

/**
 * Normalizes the given path.
 *
 * @param path The path to normalize.
 * @param base The base path, if any.
 * @return Returns the normalized path.
 */
inline void normalize_path( zstring &path, zstring const &base = "" ) {
  path = get_normalized_path( path, base );
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
