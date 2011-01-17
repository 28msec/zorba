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

#ifndef ZORBA_URI_UTIL_H
#define ZORBA_URI_UTIL_H

#include <algorithm>
#include <iostream>
#include <stdexcept>

#include "stl_util.h"

namespace zorba {
namespace uri {

////////// Encoding ///////////////////////////////////////////////////////////

ZORBA_DLL_PUBLIC extern char const uri_safe[];

/**
 * A %back_insert_iterator can be used to append characters to a string
 * ensuring that illegal characters in a URI are escaped.
 *
 * @tparam StringType The string type.
 */
template<class StringType>
class back_insert_iterator :
  public
    back_insert_iterator_base<
      StringType, back_insert_iterator<StringType>
    >
{
  typedef back_insert_iterator_base<
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

/**
 * A %fetch_exception is-a std::runtime_error for reporting errors with
 * fetch().
 */
class fetch_exception : public std::runtime_error {
public:
  explicit fetch_exception( std::string const &what ) :
    std::runtime_error( what ) { }
};

/**
 * Fetches a resource from the given URI.  Supported URI schemes are: "file",
 * "ftp", "http", and "https".
 *
 * @param uri The URI specifying the resource.
 * @param result The stream to which to write the resource to.
 * @throws fetch_exception if there was a problem fetching the resource.
 */
void fetch( char const *uri, std::iostream &result );

/**
 * Fetches a resource from the given URI.  Supported URI schemes are: "file",
 * "ftp", "http", and "https".
 *
 * @tparam StringType The URI string type.
 * @param uri The URI specifying the resource.
 * @param result The stream to which to write the resource to.
 * @throws fetch_exception if there was a problem fetching the resource.
 */
template<class StringType> inline
void fetch( StringType const &uri, std::iostream &result ) {
  fetch( uri.c_str(), result );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace uri
} // namespace zorba

#include "uri_util.tcc"

#endif /* ZORBA_URI_UTIL_H */
/* vim:set et sw=2 ts=2: */
