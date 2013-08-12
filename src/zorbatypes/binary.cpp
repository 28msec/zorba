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

#include <cassert>
#include <cctype>
#include <zorba/error.h>
#include <string>

#include <zorba/util/base64_util.h>
#include <zorba/util/hexbinary_util.h>

#include "diagnostics/xquery_diagnostics.h"
#include "util/ascii_util.h"
#include "util/hash/hash.h"
#include "util/stl_util.h"
#include "zorbatypes/binary.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

static size_t copy_without_ws( char const *from, size_t from_len, char *to ) {
  char const *const to_orig = to;
  for ( char const *const from_end = from + from_len; from < from_end; ++from )
    if ( !ascii::is_space( *from ) )
      *to++ = *from;
  return to - to_orig;
}

///////////////////////////////////////////////////////////////////////////////

#define CATCH_BASE64_EXCEPTION()                                        \
  catch ( base64::exception const &e ) {                                \
    throw XQUERY_EXCEPTION( err::FORG0001,                              \
    ERROR_PARAMS( ZED(FORG0001_Base64BadChar_2), e.invalid_char() ) );  \
  }                                                                     \
  catch ( std::invalid_argument const& ) {                              \
    throw XQUERY_EXCEPTION( err::FORG0001,                              \
    ERROR_PARAMS( ZED(FORG0001_Base64Multiple4) ) );                    \
  }

void Base64::decode( istream &is, zstring *to ) {
  try {
    base64::decode( is, to, base64::dopt_any_len | base64::dopt_ignore_ws );
  }
  CATCH_BASE64_EXCEPTION()
}

void Base64::decode( char const *from, size_type from_len, zstring *to ) {
  try {
    base64::decode(
      from, from_len, to, base64::dopt_any_len | base64::dopt_ignore_ws
    );
  }
  CATCH_BASE64_EXCEPTION()
}

Base64::Base64( Base16 const &b16 ) {
  value_type tmp;
  hexbinary::decode( &b16.data()[0], b16.size(), &tmp );
  base64::encode( &tmp[0], tmp.size(), &data_ );
}

Base64& Base64::assign( char const *data, size_type size, bool is_encoded ) {
  try {
    if ( is_encoded ) {
      base64::validate( data, size, base64::dopt_ignore_ws );
      data_.resize( size );
      data_.resize( copy_without_ws( data, size, &data_[0] ) );
    } else
      base64::encode( data, size, &data_ );
    return *this;
  }
  CATCH_BASE64_EXCEPTION()
}

uint32_t Base64::hash() const {
  return data_.size() ? ztd::hash_bytes( &data_[0], data_.size() ) : 0;
}

bool Base64::parseString( char const *s, size_type size, Base64 &b64 ) {
  if ( size ) {
    try {
      base64::validate( s, size, base64::dopt_ignore_ws );
      b64.data_.resize( size );
      b64.data_.resize( copy_without_ws( s, size, &b64.data_[0] ) );
    }
    catch ( std::exception const& ) {
      return false;
    }
  } else
    b64.data_.clear();
  return true;
}

///////////////////////////////////////////////////////////////////////////////

#define CATCH_HEXBINARY_EXCEPTION()                                     \
  catch ( hexbinary::exception const &e ) {                             \
    throw XQUERY_EXCEPTION( err::FORG0001,                              \
    ERROR_PARAMS( ZED(FORG0001_BadHexDigit_2), e.invalid_char() ) );    \
  }                                                                     \
  catch ( std::invalid_argument const& ) {                              \
    throw XQUERY_EXCEPTION( err::FORG0001,                              \
    ERROR_PARAMS(ZED(FORG0001_HexBinaryMustBeEven) ) );                 \
  }

Base16::Base16( Base64 const &b64 ) {
  value_type temp;
  base64::decode( &b64.data()[0], b64.size(), &temp );
  assign( &temp[0], temp.size(), false );
}

Base16& Base16::assign( char const *data, size_type size, bool is_encoded ) {
  if ( !size )
    data_.clear();
  else {
    try {
      if ( is_encoded ) {
        hexbinary::validate( data, size, hexbinary::dopt_ignore_ws );
        data_.resize( size );
        data_.resize( copy_without_ws( data, size, &data_[0] ) );
      } else
        hexbinary::encode( data, size, &data_ );
    }
    CATCH_HEXBINARY_EXCEPTION()
  }
  return *this;
}

bool Base16::parseString( char const *data, size_type size, Base16 &b16 ) {
  if ( !size )
    b16.data_.clear();
  else {
    try {
      hexbinary::validate( data, size, hexbinary::dopt_ignore_ws );
      b16.data_.resize( size );
      b16.data_.resize( copy_without_ws( data, size, &b16.data_[0] ) );
    }
    catch ( std::exception const& ) {
      return false;
    }
  }
  return true;
}

void Base16::encode( value_type const &from, value_type &to ) {
  if ( !from.empty() ) {
    try {
      hexbinary::encode( &from[0], from.size(), &to );
    }
    CATCH_HEXBINARY_EXCEPTION()
  }
}

uint32_t Base16::hash() const {
  return data_.size() ? ztd::hash_bytes( &data_[0], data_.size() ) : 0;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
