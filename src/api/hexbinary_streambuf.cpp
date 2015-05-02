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

// standard
#include <algorithm>
#include <stdexcept>
//#define ZORBA_DEBUG_HEXBINARY_STREAMBUF
#ifdef ZORBA_DEBUG_HEXBINARY_STREAMBUF
# include <stdio.h>
#endif

// Zorba
#include <zorba/util/hexbinary_stream.h>
#include <zorba/util/hexbinary_util.h>

using namespace std;

namespace zorba {
namespace hexbinary {

int const Large_External_Buf_Size = 4096;

///////////////////////////////////////////////////////////////////////////////

inline void streambuf::clear() {
  setg( gbuf_, gbuf_ + sizeof gbuf_, gbuf_ + sizeof gbuf_ );
}

streambuf::streambuf( std::streambuf *orig ) : orig_buf_( orig ) {
  if ( !orig )
    throw invalid_argument( "null streambuf" );
  clear();
}

void streambuf::imbue( std::locale const &loc ) {
  orig_buf_->pubimbue( loc );
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

streambuf::int_type streambuf::overflow( int_type c ) {
#ifdef ZORBA_DEBUG_HEXBINARY_STREAMBUF
  printf( "overflow()\n" );
#endif
  bool const is_eof = traits_type::eq_int_type( c, traits_type::eof() );
  if ( !is_eof ) {
    char const p = traits_type::to_char_type( c );
    char ebuf[2];
    orig_buf_->sputn( ebuf, hexbinary::encode( &p, 1, ebuf ) );
  }
  return c;
}

streambuf::int_type streambuf::pbackfail( int_type c ) {
  if ( !traits_type::eq_int_type( c, traits_type::eof() ) &&
       gptr() > eback() ) {
    c = orig_buf_->sputbackc( traits_type::to_char_type( c ) );
    if ( !traits_type::eq_int_type( c, traits_type::eof() ) )
      gbump( -1 );
    return c;
  }
  return traits_type::eof();
}

streambuf::int_type streambuf::underflow() {
#ifdef ZORBA_DEBUG_HEXBINARY_STREAMBUF
  printf( "underflow()\n" );
#endif
  char chunk[2];
  int chunk_len = 0;

  while ( gptr() >= egptr() ) {
    int_type const c = orig_buf_->sbumpc();
    bool is_eof = false;
    if ( traits_type::eq_int_type( c, traits_type::eof() ) ) {
      if ( !chunk_len )
        return traits_type::eof();
      is_eof = true;
    } else {
      chunk[ chunk_len++ ] = traits_type::to_char_type( c );
    }
    if ( chunk_len == sizeof chunk || (is_eof && chunk_len) ) {
      streamsize const n = hexbinary::decode( chunk, chunk_len, eback() );
      setg( gbuf_, gbuf_, gbuf_ + n );
    }
  }
  return traits_type::to_int_type( *gptr() );
}

streamsize streambuf::xsgetn( char_type *to, streamsize size ) {
#ifdef ZORBA_DEBUG_HEXBINARY_STREAMBUF
  printf( "xsgetn()\n" );
#endif
  streamsize return_size = 0;

  if ( streamsize const gsize = egptr() - gptr() ) {
    //
    // Get any chunk fragment pending in the get buffer first.
    //
    streamsize const n = min( gsize, size );
    traits_type::copy( to, gptr(), static_cast<size_t>( n ) );
    gbump( static_cast<int>( n ) );
    to += n;
    size -= n, return_size += n;
  }

  //
  // Must get bytes in terms of encoded size.
  //
  size = hexbinary::encoded_size( static_cast<size_type>( size ) );

  while ( size ) {
    char ebuf[ Large_External_Buf_Size ];
    streamsize const get = min( (streamsize)(sizeof ebuf), size );
    if ( streamsize got = orig_buf_->sgetn( ebuf, get ) ) {
      streamsize const decoded =
        hexbinary::decode( ebuf, static_cast<size_type>( got ), to );
      to += decoded;
      size -= got, return_size += decoded;
    } else
      break;
  }

  return return_size;
}

streamsize streambuf::xsputn( char_type const *from, streamsize size ) {
#ifdef ZORBA_DEBUG_HEXBINARY_STREAMBUF
  printf( "xsputn()\n" );
#endif
  streamsize return_size = 0;

  while ( size ) {
    char ebuf[ Large_External_Buf_Size ];
    static streamsize const esize =
      (streamsize)hexbinary::decoded_size( sizeof ebuf );
    streamsize const put = min( esize, size );
    streamsize const encoded =
      hexbinary::encode( from, static_cast<size_type>( put ), ebuf );
    orig_buf_->sputn( ebuf, encoded );
    from += put, size -= put, return_size += put;
  }

  return return_size;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace hexbinary

namespace internal {
namespace hexbinary {

// Both new & delete are done inside Zorba rather than in the header to
// guarantee that they're cross-DLL-boundary safe on Windows.

std::streambuf* alloc_streambuf( std::streambuf *orig ) {
  return new zorba::hexbinary::streambuf( orig );
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

} // namespace hexbinary
} // namespace internal

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
