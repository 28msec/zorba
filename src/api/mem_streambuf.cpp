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
#include <cstring>                      /* for memcpy(3) */

#include <zorba/util/mem_streambuf.h>

#include "diagnostics/assert.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

mem_streambuf::int_type mem_streambuf::overflow( int_type c ) {
  if ( traits_type::eq_int_type( c, traits_type::eof() ) )
    return traits_type::not_eof( c );
  if ( pptr() >= epptr() )
    return traits_type::eof();
  *pptr() = traits_type::to_char_type( c );
  pbump( 1 );
  return c;
}

mem_streambuf::int_type mem_streambuf::pbackfail( int_type c ) {
  if ( !traits_type::eq_int_type( c, traits_type::eof() ) ) {
    *pptr() = traits_type::to_char_type( c );
    pbump( -1 );
  }
  return traits_type::to_int_type( *pptr() );
}

mem_streambuf::pos_type mem_streambuf::seekoff( off_type off,
                                                ios_base::seekdir dir,
                                                ios_base::openmode ) {
  switch ( dir ) {
    case ios_base::beg:
      our_setg( begin_ + off );
      break;
    case ios_base::cur:
      our_setg( gptr() + off );
      break;
    case ios_base::end:
      our_setg( end_ + off );
      break;
    default:
      ZORBA_ASSERT( false );
  }
  return off;
}

mem_streambuf::pos_type mem_streambuf::seekpos( pos_type pos,
                                                ios_base::openmode mode ) {
  return seekoff( pos, ios_base::beg, mode );
}

void mem_streambuf::set( char_type *begin, char_type *end ) {
  begin_ = begin;
  end_ = end;
  our_setg( begin );
  our_setp( end );
}

streamsize mem_streambuf::showmanyc() {
  return egptr() - gptr();
}

mem_streambuf::int_type mem_streambuf::underflow() {
  return gptr() < egptr() ?
    traits_type::to_int_type( *gptr() ) : traits_type::eof();
}

streamsize mem_streambuf::xsgetn( char_type *buf, std::streamsize size ) {
  streamsize const remaining = showmanyc();
  if ( size > remaining )
    size = remaining;
  ::memcpy( buf, gptr(), static_cast<size_t>( size ) );
  gbump( static_cast<int>(size) );
  return size;
}

streamsize mem_streambuf::xsputn( char_type const *buf, streamsize size ) {
  streamsize const remaining = epptr() - pptr();
  if ( size > remaining )
    size = remaining;
  ::memcpy( pptr(), buf, static_cast<size_t>( size ) );
  pbump( static_cast<int>(size) );
  return size;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
