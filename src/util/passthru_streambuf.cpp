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

#include <stdexcept>

#include "stdafx.h"
#include "passthru_streambuf.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

passthru_streambuf::passthru_streambuf( char const*, streambuf *orig ) :
  internal::proxy_streambuf( orig )
{
  if ( !orig )
    throw invalid_argument( "null streambuf" );
}

passthru_streambuf::~passthru_streambuf() {
  // out-of-line since it's virtual
}

void passthru_streambuf::imbue( std::locale const &loc ) {
  original()->pubimbue( loc );
}

bool passthru_streambuf::is_necessary( char const *cc_charset ) {
  if ( !*cc_charset )
    throw invalid_argument( "empty charset" );
  zstring charset( cc_charset );
  ascii::trim_whitespace( charset );
  ascii::to_upper( charset );
  return charset != "ASCII"
      && charset != "US-ASCII"
      && charset != "UTF-8";
}

bool passthru_streambuf::is_supported( char const *cc_charset ) {
  return !is_necessary( cc_charset );
}

passthru_streambuf::pos_type
passthru_streambuf::seekoff( off_type o, ios_base::seekdir d,
                             ios_base::openmode m ) {
  return original()->pubseekoff( o, d, m );
}

passthru_streambuf::pos_type
passthru_streambuf::seekpos( pos_type p, ios_base::openmode m ) {
  return original()->pubseekpos( p, m );
}

streambuf* passthru_streambuf::setbuf( char_type *p, streamsize s ) {
  original()->pubsetbuf( p, s );
  return this;
}

streamsize passthru_streambuf::showmanyc() {
  return original()->in_avail();
}

int passthru_streambuf::sync() {
  return original()->pubsync();
}

passthru_streambuf::int_type passthru_streambuf::overflow( int_type c ) {
  return original()->sputc( c );
}

passthru_streambuf::int_type passthru_streambuf::pbackfail( int_type c ) {
  return  traits_type::eq_int_type( c, traits_type::eof() ) ?
          c : original()->sputbackc( traits_type::to_char_type( c ) );
}

passthru_streambuf::int_type passthru_streambuf::uflow() {
  return original()->sbumpc();
}

passthru_streambuf::int_type passthru_streambuf::underflow() {
  return original()->sgetc();
}

streamsize passthru_streambuf::xsgetn( char_type *to, streamsize size ) {
  return original()->sgetn( to, size );
}

streamsize passthru_streambuf::xsputn( char_type const *from,
                                       streamsize size ) {
  return original()->sputn( from, size );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
