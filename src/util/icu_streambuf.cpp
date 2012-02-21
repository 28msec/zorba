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
#define ZORBA_DEBUG_ICU_STREAMBUF 0

#ifdef ZORBA_DEBUG_ICU_STREAMBUF
# include <stdio.h>
#endif

#include <algorithm>
#include <cassert>

#include <zorba/diagnostic_list.h>

#include "diagnostics/assert.h"
#include "diagnostics/diagnostic.h"
#include "diagnostics/zorba_exception.h"
#include "util/cxx_util.h"
#include "util/string_util.h"
#include "util/utf8_util.h"

#include "icu_streambuf.h"

using namespace std;

namespace zorba {

int const Small_External_Buf_Size = 6;
int const Large_External_Buf_Size = 4096;

///////////////////////////////////////////////////////////////////////////////

inline void icu_streambuf::buf_type_base::reset() {
  pivot_source_ = pivot_target_ = pivot_buf_;
}

inline void icu_streambuf::resetg() {
  setg(
    g_.utf8_char_, g_.utf8_char_ + sizeof g_.utf8_char_,
    g_.utf8_char_ + sizeof g_.utf8_char_
  );
}

icu_streambuf::icu_streambuf( char const *charset, streambuf *orig ) :
  proxy_streambuf( orig ),
  no_conv_( !is_necessary( charset ) ),
  external_conv_( no_conv_ ? nullptr : create_conv( charset ) ),
  utf8_conv_( no_conv_ ? nullptr : create_conv( "UTF-8" ) )
{
  if ( !orig )
    throw invalid_argument( "null streambuf" );
  resetg();
}

icu_streambuf::~icu_streambuf() {
  if ( external_conv_ )
    ucnv_close( external_conv_ );
  if ( utf8_conv_ )
    ucnv_close( utf8_conv_ );
}

void icu_streambuf::clear() {
  if ( !no_conv_ ) {
    ucnv_reset( external_conv_ );
    ucnv_reset( utf8_conv_ );
    g_.reset();
    p_.reset();
    resetg();
  }
}

UConverter* icu_streambuf::create_conv( char const *charset ) {
  UErrorCode err = U_ZERO_ERROR;
  UConverter *const conv = ucnv_open( charset, &err );
  ucnv_setFromUCallBack(
    conv, UCNV_FROM_U_CALLBACK_STOP, nullptr, nullptr, nullptr, &err
  );
  ucnv_setToUCallBack(
    conv, UCNV_TO_U_CALLBACK_STOP, nullptr, nullptr, nullptr, &err
  );
  if ( !conv || U_FAILURE( err ) ) {
    if ( conv )
      ucnv_close( conv );
    throw invalid_argument( charset );
  }
  return conv;
}

bool icu_streambuf::is_necessary( char const *charset ) {
  //
  // Checking for "US-ASCII" explicitly isn't necessary since ICU knows about
  // aliases.
  //
  return  ucnv_compareNames( charset, "ASCII" )
      &&  ucnv_compareNames( charset, "UTF-8" );
}

bool icu_streambuf::is_supported( char const *charset ) {
  try {
    ucnv_close( create_conv( charset ) );
    return true;
  }
  catch ( invalid_argument const& ) {
    return false;
  }
}

icu_streambuf::pos_type icu_streambuf::seekoff( off_type o, ios_base::seekdir d,
                                                ios_base::openmode m ) {
  clear();
  return original()->pubseekoff( o, d, m );
}

icu_streambuf::pos_type icu_streambuf::seekpos( pos_type p,
                                                ios_base::openmode m ) {
  clear();
  return original()->pubseekpos( p, m );
}

streambuf* icu_streambuf::setbuf( char_type *p, streamsize s ) {
  original()->pubsetbuf( p, s );
  return this;
}

int icu_streambuf::sync() {
  return original()->pubsync();
}

icu_streambuf::int_type icu_streambuf::overflow( int_type c ) {
#if ZORBA_DEBUG_ICU_STREAMBUF
  printf( "overflow()\n" );
#endif
  if ( no_conv_ )
    return original()->sputc( c );

  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::eof();

  char_type const utf8_byte = traits_type::to_char_type( c );
  char_type const *from = &utf8_byte;
  char ebuf[ Small_External_Buf_Size ], *to = ebuf;

  bool const ok = to_external( &from, from + 1, &to, to + sizeof ebuf );
  assert( ok );
  if ( streamsize const n = to - ebuf ) {
    original()->sputn( ebuf, n );
    p_.reset();
  }

  return c;
}

bool icu_streambuf::to_external( char_type const **from,
                                 char_type const *from_end, char **to,
                                 char const *to_end, bool flush ) {
  UErrorCode err = U_ZERO_ERROR;
  ucnv_convertEx(
    external_conv_, utf8_conv_, to, to_end, from, from_end,
    p_.pivot_buf_, &p_.pivot_source_, &p_.pivot_target_,
    p_.pivot_buf_ + sizeof p_.pivot_buf_,
    /*reset*/ false, flush, &err
  );
  if ( err == U_TRUNCATED_CHAR_FOUND || err == U_BUFFER_OVERFLOW_ERROR )
    return false;
  if ( U_FAILURE( err ) )
    throw ZORBA_EXCEPTION(
      zerr::ZOSE0006_TRANSCODING_ERROR, ERROR_PARAMS( u_errorName( err ) )
    );
  return true;
}

bool icu_streambuf::to_utf8( char const **from, char const *from_end,
                             char_type **to, char_type const *to_end,
                             bool flush ) {
  UErrorCode err = U_ZERO_ERROR;
  ucnv_convertEx(
    utf8_conv_, external_conv_, to, to_end, from, from_end,
    g_.pivot_buf_, &g_.pivot_source_, &g_.pivot_target_,
    g_.pivot_buf_ + sizeof g_.pivot_buf_,
    /*reset*/ false, flush, &err
  );
  if ( err == U_TRUNCATED_CHAR_FOUND || err == U_BUFFER_OVERFLOW_ERROR )
    return false;
  if ( U_FAILURE( err ) )
    throw ZORBA_EXCEPTION(
      zerr::ZOSE0006_TRANSCODING_ERROR, ERROR_PARAMS( u_errorName( err ) )
    );
  return true;
}

icu_streambuf::int_type icu_streambuf::underflow() {
#if ZORBA_DEBUG_ICU_STREAMBUF
  printf( "underflow()\n" );
#endif
  if ( no_conv_ )
    return original()->sgetc();

  if ( gptr() >= egptr() ) {
    utf8::storage_type *to = g_.utf8_char_;
    utf8::storage_type const *const to_end = to + sizeof g_.utf8_char_;

    while ( true ) {
      int_type const c = original()->sbumpc();
      if ( traits_type::eq_int_type( c, traits_type::eof() ) )
        return traits_type::eof();

      char const ebyte = traits_type::to_char_type( c );
      char const *from = &ebyte;

      to_utf8( &from, from + 1, &to, to_end );
      if ( to > g_.utf8_char_ ) {
        setg( g_.utf8_char_, g_.utf8_char_, to );
        g_.reset();
        break;
      }
    }
  }
  return traits_type::to_int_type( *gptr() );
}

streamsize icu_streambuf::xsgetn( char_type *to, streamsize size ) {
#if ZORBA_DEBUG_ICU_STREAMBUF
  printf( "xsgetn()\n" );
#endif
  if ( no_conv_ )
    return original()->sgetn( to, size );

  streamsize return_size = 0;
  char_type *const to_end = to + size;

  if ( streamsize const gsize = egptr() - gptr() ) {
    // must first get any chars in g_.utf8_char_
    streamsize const n = min( gsize, size );
    traits_type::copy( to, gptr(), n );
    gbump( n );
    to += n;
    size -= n, return_size += n;
  }

  while ( size > 0 ) {
    char ebuf[ Large_External_Buf_Size ];
    streamsize const get = min( (streamsize)(sizeof ebuf), size );
    if ( streamsize const got = original()->sgetn( ebuf, get ) ) {
      char const *from = ebuf;
      char_type const *const to_orig = to;
      int_type const peek = original()->sgetc();
      bool const flush = traits_type::eq_int_type( peek, traits_type::eof() );
      to_utf8( &from, from + got, &to, to_end, flush );
      streamsize const n = to - to_orig;
      size -= n, return_size += n;
      if ( flush )
        break;
    } else
      break;
  }
  return return_size;
}

streamsize icu_streambuf::xsputn( char_type const *from, streamsize size ) {
#if ZORBA_DEBUG_ICU_STREAMBUF
  printf( "xsputn()\n" );
#endif
  if ( no_conv_ )
    return original()->sputn( from, size );

  streamsize return_size = 0;
  char_type const *const from_end = from + size;
  char ebuf[ Large_External_Buf_Size ], *to = ebuf;
  char const *const to_end = to + sizeof ebuf;

  while ( size > 0 ) {
    char_type const *const from_orig = from;
    to_external( &from, from_end, &to, to_end );
    streamsize n = to - ebuf;
    if ( n && !original()->sputn( ebuf, n ) )
      break;
    to = ebuf;
    n = from - from_orig;
    size -= n, return_size += n;
  }
  return return_size;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
