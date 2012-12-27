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

//#define ZORBA_DEBUG_UTF8_STREAMBUF
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
# include <stdio.h>
#endif

#include <iomanip>
#include <stdexcept>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>

#include "diagnostics/diagnostic.h"
#include "diagnostics/zorba_exception.h"
#include "util/cxx_util.h"
#include "util/oseparator.h"
#include "util/string_util.h"
#include "util/utf8_util.h"

#include "utf8_streambuf.h"

using namespace std;

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

inline void streambuf::buf_type::clear() {
  char_len_ = 0;
}

void streambuf::buf_type::throw_invalid_utf8( storage_type *buf,
                                              size_type len ) {
  ostringstream oss;
  oss << hex << setfill('0') << setw(2) << uppercase;
  oseparator comma( ',' );

  for ( size_type i = 0; i < len; ++i )
    oss << comma << "0x" << (static_cast<unsigned>( buf[i] ) & 0xFF);

  clear();
  throw ZORBA_EXCEPTION(
    zerr::ZXQD0006_INVALID_UTF8_BYTE_SEQUENCE,
    ERROR_PARAMS( oss.str() )
  );
}

void streambuf::buf_type::validate( storage_type c, bool bump ) {
  size_type char_len_copy = char_len_, cur_len_copy = cur_len_;

  if ( !char_len_copy ) {
    //
    // This means we're (hopefully) at the first byte of a UTF-8 byte sequence
    // comprising a character.
    //
    if ( !(char_len_copy = char_length( c )) )
      throw_invalid_utf8( &c, 1 );
    cur_len_copy = 0;
  }

  storage_type *const cur_byte_ptr = utf8_char_ + cur_len_copy;
  storage_type const old_byte = *cur_byte_ptr;
  *cur_byte_ptr = c;

  if ( cur_len_copy++ && !is_continuation_byte( c ) )
    throw_invalid_utf8( utf8_char_, cur_len_copy );

  if ( bump ) {
    char_len_ = (cur_len_copy == char_len_copy ? 0 : char_len_copy);
    cur_len_ = cur_len_copy;
  } else {
    *cur_byte_ptr = old_byte;
  }
}

///////////////////////////////////////////////////////////////////////////////

inline void streambuf::clear() {
  gbuf_.clear();
  pbuf_.clear();
}

streambuf::streambuf( std::streambuf *orig, bool validate_put ) :
  orig_buf_( orig ),
  validate_put_( validate_put )
{
  if ( !orig )
    throw invalid_argument( "null streambuf" );
  clear();
}

void streambuf::imbue( std::locale const &loc ) {
  orig_buf_->pubimbue( loc );
}

void streambuf::resync() {
  int_type c = orig_buf_->sgetc();
  while ( !traits_type::eq_int_type( c, traits_type::eof() ) ) {
    if ( is_start_byte( traits_type::to_char_type( c ) ) )
      break;
    c = orig_buf_->sbumpc();
  }
}

streambuf::pos_type streambuf::seekoff( off_type o, ios_base::seekdir d,
                                        ios_base::openmode m ) {
  clear();
  return orig_buf_->pubseekoff( o, d, m );
}

streambuf::pos_type streambuf::seekpos( pos_type p, ios_base::openmode m ) {
  clear();
  return orig_buf_->pubseekpos( p, m );
}

std::streambuf* streambuf::setbuf( char_type *p, streamsize s ) {
  orig_buf_->pubsetbuf( p, s );
  return this;
}

streamsize streambuf::showmanyc() {
  return orig_buf_->in_avail();
}

int streambuf::sync() {
  return orig_buf_->pubsync();
}

streambuf::int_type streambuf::overflow( int_type c ) {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "overflow()\n" );
#endif
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();
  if ( validate_put_ )
    pbuf_.validate( traits_type::to_char_type( c ), true );
  orig_buf_->sputc( c );
  return c;
}

streambuf::int_type streambuf::pbackfail( int_type c ) {
  if ( !traits_type::eq_int_type( c, traits_type::eof() ) &&
       gbuf_.cur_len_ &&
       orig_buf_->sputbackc( traits_type::to_char_type( c ) ) ) {
    --gbuf_.cur_len_;
    return c;
  }
  return traits_type::eof();
}

streambuf::int_type streambuf::uflow() {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "uflow()\n" );
#endif
  int_type const c = orig_buf_->sbumpc();
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();
  gbuf_.validate( traits_type::to_char_type( c ) );
  return c;
}

streambuf::int_type streambuf::underflow() {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "underflow()\n" );
#endif
  int_type const c = orig_buf_->sgetc();
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();
  gbuf_.validate( traits_type::to_char_type( c ), false );
  return c;
}

streamsize streambuf::xsgetn( char_type *to, streamsize size ) {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "xsgetn()\n" );
#endif
  streamsize return_size = 0;

  if ( gbuf_.char_len_ ) {
    streamsize const want = gbuf_.char_len_ - gbuf_.cur_len_;
    streamsize const get = min( want, size );
    streamsize const got = orig_buf_->sgetn( to, get );
    for ( streamsize i = 0; i < got; ++i )
      gbuf_.validate( to[i] );
    to += got;
    size -= got, return_size += got;
  }

  while ( size > 0 ) {
    if ( streamsize const got = orig_buf_->sgetn( to, size ) ) {
      for ( streamsize i = 0; i < got; ++i )
        gbuf_.validate( to[i] );
      to += got;
      size -= got, return_size += got;
    } else
      break;
  }
  return return_size;
}

streamsize streambuf::xsputn( char_type const *from, streamsize size ) {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "xsputn()\n" );
#endif
  if ( validate_put_ )
    for ( streamsize i = 0; i < size; ++i )
      pbuf_.validate( from[i] );
  return orig_buf_->sputn( from, size );
}

///////////////////////////////////////////////////////////////////////////////

// Both new & delete are done inside Zorba rather than in the header to
// guarantee that they're cross-DLL-boundary safe on Windows.

std::streambuf* alloc_streambuf( std::streambuf *orig ) {
  return new utf8::streambuf( orig );
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

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
/* vim:set et sw=2 ts=2: */
