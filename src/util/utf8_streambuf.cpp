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

#include <stdexcept>

#include <zorba/config.h>
#include <zorba/diagnostic_list.h>

#include "diagnostics/diagnostic.h"
#include "diagnostics/zorba_exception.h"
#include "util/cxx_util.h"
#include "util/string_util.h"
#include "util/utf8_util.h"

#include "utf8_streambuf.h"

using namespace std;

namespace zorba {
namespace utf8 {

///////////////////////////////////////////////////////////////////////////////

static void throw_invalid_utf8( storage_type *buf, size_type len ) {
  char err_buf[ 6 /* bytes at most */ * 5 /* chars per byte */ ], *b = err_buf;
  bool first = true;
  for ( size_type i = 0; i < len; ++i, b += 4 ) {
    if ( first )
      first = false;
    else
      *b++ = ',';
    ::sprintf( b, "0x%0hhX", buf[i] );
  }
  throw ZORBA_EXCEPTION(
    zerr::ZXQD0006_INVALID_UTF8_BYTE_SEQUENCE,
    ERROR_PARAMS( err_buf )
  );
}

///////////////////////////////////////////////////////////////////////////////

void streambuf::buf_type::validate( storage_type c, bool bump ) {
  size_type char_len = char_len_, cur_len = cur_len_;

  if ( !char_len ) {
    if ( !(char_len = char_length( c )) )
      throw_invalid_utf8( &c, 1 );
    cur_len = 0;
  }

  storage_type *const p = utf8_char_ + cur_len;
  storage_type const old = *p;
  *p = c;

  if ( cur_len++ && !is_continuation_byte( c ) )
    throw_invalid_utf8( utf8_char_, cur_len );

  if ( bump ) {
    char_len_ = (cur_len == char_len ? 0 : char_len);
    cur_len_ = cur_len;
  } else {
    *p = old;
  }
}

///////////////////////////////////////////////////////////////////////////////

inline void streambuf::clear() {
  gbuf_.char_len_ = pbuf_.char_len_ = 0;
}

streambuf::streambuf( std::streambuf *orig, bool validate_put ) :
  proxy_streambuf( orig ),
  validate_put_( validate_put )
{
  if ( !orig )
    throw invalid_argument( "null streambuf" );
  clear();
}

streambuf::pos_type streambuf::seekoff( off_type o, ios_base::seekdir d,
                                        ios_base::openmode m ) {
  clear();
  return original()->pubseekoff( o, d, m );
}

streambuf::pos_type streambuf::seekpos( pos_type p, ios_base::openmode m ) {
  clear();
  return original()->pubseekpos( p, m );
}

std::streambuf* streambuf::setbuf( char_type *p, streamsize s ) {
  original()->pubsetbuf( p, s );
  return this;
}

streamsize streambuf::showmanyc() {
  return original()->in_avail();
}

int streambuf::sync() {
  return original()->pubsync();
}

streambuf::int_type streambuf::overflow( int_type c ) {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "overflow()\n" );
#endif
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();
  if ( validate_put_ )
    pbuf_.validate( traits_type::to_char_type( c ) );
  original()->sputc( c );
  return c;
}

streambuf::int_type streambuf::uflow() {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "uflow()\n" );
#endif
  int_type const c = original()->sbumpc();
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();
  gbuf_.validate( traits_type::to_char_type( c ) );
  return c;
}

streambuf::int_type streambuf::underflow() {
#ifdef ZORBA_DEBUG_UTF8_STREAMBUF
  printf( "underflow()\n" );
#endif
  int_type const c = original()->sgetc();
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
    streamsize const got = original()->sgetn( to, get );
    for ( streamsize i = 0; i < got; ++i )
      gbuf_.validate( to[i] );
    to += got;
    size -= got, return_size += got;
  }

  while ( size > 0 ) {
    if ( streamsize const got = original()->sgetn( to, size ) ) {
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
  return original()->sputn( from, size );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace utf8
} // namespace zorba
/* vim:set et sw=2 ts=2: */
