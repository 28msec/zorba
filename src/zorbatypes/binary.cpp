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

#include "zorbatypes/binary.h"

#include "diagnostics/xquery_diagnostics.h"

#include "util/ascii_util.h"
#include "util/base64_util.h"
#include "util/hash/hash.h"
#include "util/hexbinary_util.h"
#include "util/stl_util.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

#define CATCH_BASE64_EXCEPTION()                                        \
  catch (const base64::exception& e)                                    \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_Base64BadChar_2), e.invalid_char()));     \
  }                                                                     \
  catch (const std::invalid_argument&)                                  \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_Base64Multiple4)));                       \
  }

static size_t copy_without_ws( char const *from, size_t from_len, char *to ) {
  char const *const to_orig = to;
  for ( char const *const from_end = from + from_len; from < from_end; ++from )
    if ( !ascii::is_space( *from ) )
      *to++ = *from;
  return to - to_orig;
}


bool Base64::parseString(char const *s, size_t len, Base64& aBase64)
{
  if ( len ) {
    try 
    {
      base64::validate( s, len, base64::dopt_ignore_ws );
      aBase64.theData.resize( len );
      aBase64.theData.resize(
        copy_without_ws( s, len, &aBase64.theData[0] )
      );
    }
    catch (...) 
    {
      return false;
    }
  } else
    aBase64.theData.clear();
  return true;
}


bool Base64::parseString( char const *s, size_t len, Base64 &aBase64, 
                          string &lErrorMessage )
{
  if ( len ) {
    try 
    {
      base64::validate( s, len, base64::dopt_ignore_ws );
      aBase64.theData.resize( len );
      aBase64.theData.resize(
        copy_without_ws( s, len, &aBase64.theData[0] )
      );
    }
    catch (ZorbaException const& e) 
    {
      lErrorMessage = e.what();
      return false;
    }
  } else
    aBase64.theData.clear();
  return true;
}


void Base64::encode( zstring const &s, Base64 &to )
{
  base64::encode( s.data(), s.size(), &to.theData );
}


void Base64::encode( istream &is, Base64 &to )
{
  base64::encode( is, &to.theData );
}


zstring Base64::encode( istream &is )
{
  zstring result;
  base64::encode( is, &result );
  return result;
}


void Base64::encode( vector<char> const &from, vector<char> &to )
{
  if ( !from.empty() )
    base64::encode( &from[0], from.size(), &to );
}


void Base64::encode( char const *from, size_t from_len, Base64 &to )
{
  base64::encode( from, from_len, &to.theData );
}


void Base64::decode( istream &is, zstring *to )
{
  try {
    base64::decode( is, to, base64::dopt_any_len | base64::dopt_ignore_ws );
  }
  CATCH_BASE64_EXCEPTION()
}

void Base64::decode(vector<char> const &from, vector<char> &to )
{
  if ( !from.empty() ) {
    try {
      base64::decode(
        &from[0], from.size(), &to,
        base64::dopt_any_len | base64::dopt_ignore_ws
      );
    }
    CATCH_BASE64_EXCEPTION()
  }
}

void Base64::decode( char const *from, size_t from_len, zstring *to ) {
  try {
    base64::decode(
      from, from_len, to, base64::dopt_any_len | base64::dopt_ignore_ws
    );
  }
  CATCH_BASE64_EXCEPTION()
}


Base64::Base64( Base16 const &aBase16 )
{
  vector<char> tmp;
  Base16::decode( aBase16.getData(), tmp );
  Base64::encode( tmp, theData );
}


Base64::Base64( char const *bin_data, size_t len )
{
  try {
    base64::encode( bin_data, len, &theData );
  }
  CATCH_BASE64_EXCEPTION()
}



bool Base64::equal( Base64 const &aBase64 ) const
{
  if ( size() != aBase64.size() )
    return false;
  return ::strncmp( &theData[0], &aBase64.theData[0], size() ) == 0;
}


zstring Base64::str() const 
{
  zstring result;
  if ( theData.size() )
    result.assign( &theData[0], theData.size() );
  return result;
}


zstring Base64::decode() const
{
  zstring result;
  if ( !theData.empty() )
    base64::decode( &theData[0], theData.size(), &result );
  return result;
}


void Base64::decode( vector<char> &to )
{
  if ( !theData.empty() )
    base64::decode( &theData[0], theData.size(), &to );
}


uint32_t Base64::hash() const
{
  return theData.size() ? ztd::hash_bytes( &theData[0], theData.size() ) : 0;
}


ostream& operator<<(ostream& os, const Base64& aBase64)
{
  if ( aBase64.size() )
    os.write( &aBase64.getData()[0], aBase64.size() );
  return os;
}

///////////////////////////////////////////////////////////////////////////////

#define CATCH_HEXBINARY_EXCEPTION()                                     \
  catch (const hexbinary::exception& e)                                 \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_BadHexDigit_2), e.invalid_char()));       \
  }                                                                     \
  catch (const std::invalid_argument&)                                  \
  {                                                                     \
    throw XQUERY_EXCEPTION(err::FORG0001,                               \
    ERROR_PARAMS(ZED(FORG0001_HexBinaryMustBeEven)));                   \
  }

Base16::Base16( char const *bin_data, size_t len )
{
  try {
    hexbinary::encode( bin_data, len, &theData );
  }
  CATCH_HEXBINARY_EXCEPTION()
}

Base16::Base16(Base64 const &aBase64)
{
  vector<char> lOrig;
  Base64::decode(aBase64.getData(), lOrig);
  Base16::encode(lOrig, theData);
}


bool Base16::parseString(char const *s, size_t len, Base16& aBase16)
{
  if ( len ) {
    try 
    {
      hexbinary::validate( s, len );
      aBase16.theData.resize( len );
      aBase16.theData.resize(
        copy_without_ws( s, len, &aBase16.theData[0] )
      );
    }
    catch (...)
    {
      return false;
    }
  } else
    aBase16.theData.clear();
  return true;
}


void Base16::insertData(char const *s, size_t len)
{
  s = ascii::trim_whitespace( s, &len );
  try {
    hexbinary::encode( s, len, &theData );
  }
  CATCH_HEXBINARY_EXCEPTION()
}


bool Base16::equal( Base16 const &other ) const
{
  if ( size() != other.size() )
    return false;
  return ::strncmp( &theData[0], &other.theData[0], theData.size() ) == 0;
}


zstring Base16::str() const 
{
  if ( size() )
    return zstring( &theData[0], size() );
  return zstring();
}


void Base16::encode( vector<char> const &from, vector<char> &to )
{
  if ( !from.empty() ) {
    try {
      hexbinary::encode( &from[0], from.size(), &to );
    }
    CATCH_HEXBINARY_EXCEPTION()
  }
}

void Base16::encode( char const *from, size_t from_len, Base16 &to )
{
  hexbinary::encode( from, from_len, &to.theData );
}

void Base16::decode( vector<char> const &from, vector<char> &to )
{
  if ( !from.empty() ) {
    try {
      hexbinary::decode( &from[0], from.size(), &to );
    }
    CATCH_HEXBINARY_EXCEPTION()
  }
}

uint32_t Base16::hash() const
{
  return theData.size() ? ztd::hash_bytes( &theData[0], theData.size() ) : 0;
}


ostream& operator<<( ostream &os, Base16 const &b16 )
{
  if ( b16.size() )
    os.write( &b16.getData()[0], b16.size() );
  return os;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
