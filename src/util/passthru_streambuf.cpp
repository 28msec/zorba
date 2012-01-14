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

#include "passthru_streambuf.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

passthru_streambuf::passthru_streambuf( char const*, streambuf *orig ) :
  orig_streambuf_( orig )
{
  if ( !orig_streambuf_ )
    throw invalid_argument( "null streambuf" );
}

passthru_streambuf::~passthru_streambuf() {
  // out-of-line since it's virtual
}

void passthru_streambuf::imbue( std::locale const &loc ) {
  orig_streambuf_->pubimbue( loc );
}

passthru_streambuf::pos_type
passthru_streambuf::seekoff( off_type o, ios_base::seekdir d,
                             ios_base::openmode m ) {
  return orig_streambuf_->pubseekoff( o, d, m );
}

passthru_streambuf::pos_type
passthru_streambuf::seekpos( pos_type p, ios_base::openmode m ) {
  return orig_streambuf_->pubseekpos( p, m );
}

streambuf* passthru_streambuf::setbuf( char_type *p, streamsize s ) {
  orig_streambuf_->pubsetbuf( p, s );
  return this;
}

streamsize passthru_streambuf::showmanyc() {
  return orig_streambuf_->in_avail();
}

int passthru_streambuf::sync() {
  return orig_streambuf_->pubsync();
}

passthru_streambuf::int_type passthru_streambuf::overflow( int_type c ) {
  return orig_streambuf_->sputc( c );
}

passthru_streambuf::int_type passthru_streambuf::pbackfail( int_type c ) {
  return orig_streambuf_->sputbackc( traits_type::to_char_type( c ) );
}

passthru_streambuf::int_type passthru_streambuf::uflow() {
  return orig_streambuf_->sbumpc();
}

passthru_streambuf::int_type passthru_streambuf::underflow() {
  return orig_streambuf_->sgetc();
}

streamsize passthru_streambuf::xsgetn( char_type *to, streamsize size ) {
  return orig_streambuf_->sgetn( to, size );
}

streamsize passthru_streambuf::xsputn( char_type const *from,
                                       streamsize size ) {
  return orig_streambuf_->sputn( from, size );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
