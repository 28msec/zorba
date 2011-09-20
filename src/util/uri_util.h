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
#ifndef ZORBA_URI_UTIL_H
#define ZORBA_URI_UTIL_H

#include <algorithm>
#include <iostream>

#include "cxx_util.h"
#include "error_util.h"
#include "fs_util.h"
#include "stl_util.h"

namespace zorba {
namespace uri {

////////// Scheme /////////////////////////////////////////////////////////////

/**
 * A subset of official IANA-registere URI schemes.
 */
enum scheme {
  none,
  unknown,
  file,
  ftp,
  http,
  https,
  mailto
};
extern char const *const scheme_string[];

inline std::ostream& operator<<( std::ostream &o, scheme s ) {
  return o << scheme_string[ s ];
}

/**
 * Gets the scheme of the URI.
 *
 * @param uri The URI to get the scheme of.
 * @param colon If not \c nullptr, this pointer is set to the position of the
 * ':' (if any) that follows the scheme name.
 * @return Returns the URI's scheme, or scheme::none if none, or
 * scheme::unknown if unknown.
 */
scheme get_scheme( char const *uri, char const **colon = nullptr );

/**
 * Gets the scheme of the URI.
 *
 * @tparam StringType The string type.
 * @param uri The URI to get the scheme of.
 * @param sname If not \c nullptr and the scheme is known, this is set to the
 * scheme's name.
 * @return Returns the URI's scheme, or scheme::none if none, or
 * scheme::unknown if unknown.
 */
template<class StringType> inline
scheme get_scheme( StringType const &uri, StringType *sname = nullptr ) {
  char const *colon;
  scheme const s = get_scheme( uri.c_str(), &colon );
  if ( sname && s )
    *sname = StringType( uri.data(), colon - uri.data() );
  return s;
}

////////// Encoding ///////////////////////////////////////////////////////////

ZORBA_DLL_PUBLIC extern char const uri_safe[];
ZORBA_DLL_PUBLIC extern signed char const hex2dec[];

/**
 * A %back_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in a URI are escaped.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_insert_iterator :
  public
    ztd::back_insert_iterator_base<
      StringType, back_insert_iterator<StringType>
    >
{
  typedef ztd::back_insert_iterator_base<
    StringType, back_insert_iterator<StringType>
  > base_type;
public:
  typedef typename base_type::container_type container_type;
  typedef typename StringType::value_type value_type;

  /**
   * Constructs a %back_insert_iterator.
   *
   * @param s The string to append to.
   * @param encode_slash If \c true, encodes the '/' character also.
   */
  explicit back_insert_iterator( StringType &s, bool encode_slash = false )
    : base_type( s ), encode_slash_(  encode_slash )
  {
    buf_[0] = '%';
  }

  back_insert_iterator& operator=( value_type c );

private:
  char buf_[3]; // %xx -- no need for null at end
  bool encode_slash_;
};

/**
 * This is a convenience function to create a back_insert_iterator.
 *
 * @tparam StringType The string type.
 * @param out The output string.
 * @param encode_slash If \c true, encodes the '/' character also.
 */
template<class StringType> inline back_insert_iterator<StringType>
back_inserter( StringType &out, bool encode_slash = false ) {
  return back_insert_iterator<StringType>( out, encode_slash );
}

/**
 * Percent-decodes (%xx) illegal URI characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 */
template<class InputStringType,class OutputStringType>
void decode( InputStringType const &in, OutputStringType *out );

/**
 * Percent-decodes (%xx) illegal URI characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 */
template<class StringType> inline
void decode( StringType &s ) {
  StringType temp;
  decode( s, &temp );
  s = temp;
}

/**
 * Percent-encodes (%xx) illegal URI characters.
 *
 * @tparam InputStringType The input string type.
 * @tparam OutputStringType The output string type.
 * @param in The input string.
 * @param out The output string (which must be different from \a in).  Its
 * contents are appended to.
 * @param encode_slash Encodes the slash character ("/") only if \c true.
 */
template<class InputStringType,class OutputStringType> inline
void encode( InputStringType const &in, OutputStringType *out,
             bool encode_slash = true ) {
  std::copy( in.begin(), in.end(), back_inserter( *out, encode_slash ) );
}

/**
 * Percent-encodes (%xx) illegal URI characters.
 *
 * @tparam StringType The string type.
 * @param s The string.
 * @param encode_slash Encodes the slash character ("/") only if \c true.
 */
template<class StringType> inline
void encode( StringType &s, bool encode_slash = true ) {
  StringType temp;
  encode( s, &temp, encode_slash );
  s = temp;
}
  
////////// Fetching ///////////////////////////////////////////////////////////

// Internal use only!
void fetch_to_path_impl( char const *uri, char *path, bool *is_temp );
  
/**
 * Fetches a resource from the given URI to a local file.
 *
 * @tparam PathStringType The path's string type.
 * @param uri The URI specifying the resouce.
 * @param path On return, contains the path of the fetched resource.
 * @param is_temp If not \c nullptr, on return this is set to \c true if the
 * local file is a created temporary file; \c false otherwise.
 */
template<class PathStringType> inline
void fetch( char const *uri, PathStringType *path, bool *is_temp = nullptr ) {
  char path_buf[ MAX_PATH ];
  fetch_to_path_impl( uri, path_buf, is_temp );
  *path = path_buf;
}
  
/**
 * Fetches a resource from the given URI to a local file.
 *
 * @tparam URIStringType The URI's string type.
 * @tparam PathStringType The path's string type.
 * @param uri The URI specifying the resouce.
 * @param path On return, contains the path of the fetched resource.
 * @param is_temp If not \c nullptr, on return this is set to \c true if the
 * local file is a created temporary file; \c false otherwise.
 */
template<class URIStringType,class PathStringType> inline
void fetch( URIStringType const &uri, PathStringType *file,
            bool *is_temp = nullptr ) {
  fetch( uri.c_str(), file, is_temp );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace uri
} // namespace zorba

#include "uri_util.tcc"

#endif /* ZORBA_URI_UTIL_H */
/* vim:set et sw=2 ts=2: */
