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

///////////////////////////////////////////////////////////////////////////////

namespace internal {

// Both new & delete are done here inside Zorba rather than in the header to
// guarantee that they're cross-DLL-boundary safe on Windows.

zorba::transcode::streambuf*
alloc_streambuf( char const *charset, std::streambuf *orig ) {
  return new zorba::transcode::streambuf( charset, orig );
}

void dealloc_streambuf( zorba::transcode::streambuf *buf ) {
  delete buf;
}

int get_streambuf_index() {
  //
  // This function is out-of-line because it has a static constant within it.
  // It has a static constant within it to guarantee (1) initialization before
  // use and (2) initialization happens exactly once.
  //
  // See: "Standard C++ IOStreams and Locales: Advanced Programmer's Guide and
  // Reference," Angelika Langer and Klaus Kreft, Addison-Wesley, 2000, section
  // 3.3.1.1: "Initializing and Maintaining the iword/pword Index."
  //
  // See: "The C++ Programming Language," Bjarne Stroustrup, Addison-Wesley,
  // 2000, section 10.4.8: "Local Static Store."
  //
  static int const index = ios_base::xalloc();
  return index;
}

void stream_callback( ios_base::event e, ios_base &ios, int index ) {
  //
  // See: "Standard C++ IOStreams and Locales: Advanced Programmer's Guide and
  // Reference," Angelika Langer and Klaus Kreft, Addison-Wesley, 2000, section
  // 3.3.1.4: "Using Stream Callbacks for Memory Management."
  //
  if ( e == ios_base::erase_event )
    delete static_cast<streambuf*>( ios.pword( index ) );
}

} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
