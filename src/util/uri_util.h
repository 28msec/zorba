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

#include <iostream>
#include <stdexcept>

namespace zorba {
namespace uri {

///////////////////////////////////////////////////////////////////////////////

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
 * Fetches a resource from the given URI.
 *
 * @param uri The URI specifying the resource.
 * @param result The stream to which to write the resource to.
 * @throws fetch_exception if there was a problem fetching the resource.
 */
void fetch( char const *uri, std::iostream &result );

/**
 * Fetches a resource from the given URI.
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

#endif /* ZORBA_URI_UTIL_H */
/* vim:set et sw=2 ts=2: */
