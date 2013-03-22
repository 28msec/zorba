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
#ifndef ZORBA_STREAM_UTIL_H
#define ZORBA_STREAM_UTIL_H

#include <iostream>

#include "omanip.h"
#include "string_util.h"

namespace zorba {

int get_stream_uri_index();
void delete_stream_uri_callback( std::ios_base::event, std::ios_base&, int );

///////////////////////////////////////////////////////////////////////////////

/**
 * Sets a URI value for the given iostream.  The URI is intended to be used to
 * note the origination or destination URI (e.g., file) that data is coming
 * from or going to.
 * If the given iostream already has a URI set for it, that URI is replaced.
 *
 * @param ios The iostream to set the URI of.
 * @param uri The URI to set.
 */
template<typename charT,class Traits> inline
void set_uri( std::basic_ios<charT,Traits> &ios, char const *uri ) {
  int const index = get_stream_uri_index();
  void *&pword = ios.pword( index );
  if ( pword )
    delete[] static_cast<char const*>( pword );
  pword = ztd::new_strdup( uri );
  ios.register_callback( delete_stream_uri_callback, index );
}

/**
 * Gets a URI value for the given iostream.
 *
 * @param ios The iostream to get the URI of.
 * @return Returns said URI or \c null if none was set.
 */
template<typename charT,class Traits> inline
char const* get_uri( std::basic_ios<charT,Traits> &ios ) {
  return static_cast<char const*>( ios.pword( get_stream_uri_index() ) );
}

///////////////////////////////////////////////////////////////////////////////

/**
 * Reads from the given istream until \a n non-whitespace characters are read
 * or until EOF is encountered.
 *
 * @param is The istream to read from.
 * @param buf A pointer to the start of a buffer to read into.
 * @param n The number of non-whitespace characters to read.
 * @return Returns the number of non-whitespace characters read.
 */
std::streamsize read_without_whitespace( std::istream &is, char *buf,
                                         std::streamsize n );

/**
 * Emits an integer as Roman numerals to the given ostream.  By default,
 * numerals are emitted in lower-case.  To emit in upper-case, set the
 * \c uppercase format flag on the stream.
 *
 * @param o The ostream to emit to.
 * @param n The integer to emit.
 * @return Returns \a o.
 */
std::ostream& roman( std::ostream &o, unsigned n );

DEF_OMANIP1( roman, unsigned )

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_STREAM_UTIL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
