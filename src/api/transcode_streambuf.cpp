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

#include "stdafx.h"
#include <zorba/transcode_stream.h>

#include "util/transcode_streambuf.h"

using namespace std;

namespace zorba {
namespace transcode {

///////////////////////////////////////////////////////////////////////////////

streambuf::streambuf( char const *charset, std::streambuf *orig ) :
  proxy_buf_( new internal::transcode::streambuf( charset, orig ) )
{
}

streambuf::~streambuf() {
  // out-of-line since it's virtual
}

void streambuf::imbue( std::locale const &loc ) {
  proxy_buf_->pubimbue( loc );
}

streambuf::pos_type streambuf::seekoff( off_type o, ios_base::seekdir d,
                                        ios_base::openmode m ) {
  return proxy_buf_->pubseekoff( o, d, m );
}

streambuf::pos_type streambuf::seekpos( pos_type p, ios_base::openmode m ) {
  return proxy_buf_->pubseekpos( p, m );
}

std::streambuf* streambuf::setbuf( char_type *p, streamsize s ) {
  proxy_buf_->pubsetbuf( p, s );
  return this;
}

streamsize streambuf::showmanyc() {
  return proxy_buf_->in_avail();
}

int streambuf::sync() {
  return proxy_buf_->pubsync();
}

streambuf::int_type streambuf::overflow( int_type c ) {
  return proxy_buf_->sputc( c );
}

streambuf::int_type streambuf::pbackfail( int_type c ) {
  return proxy_buf_->sputbackc( traits_type::to_char_type( c ) );
}

streambuf::int_type streambuf::uflow() {
  return proxy_buf_->sbumpc();
}

streambuf::int_type streambuf::underflow() {
  return proxy_buf_->sgetc();
}

streamsize streambuf::xsgetn( char_type *to, streamsize size ) {
  return proxy_buf_->sgetn( to, size );
}

streamsize streambuf::xsputn( char_type const *from,
                                       streamsize size ) {
  return proxy_buf_->sputn( from, size );
}

///////////////////////////////////////////////////////////////////////////////

bool is_necessary( char const *charset ) {
  return internal::transcode::streambuf::is_necessary( charset );
}

bool is_supported( char const *charset ) {
  return internal::transcode::streambuf::is_supported( charset );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace transcode
} // namespace zorba
/* vim:set et sw=2 ts=2: */
