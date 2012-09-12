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
#include "util/stl_util.h"

#define CATCH_BASE64_EXCEPTION()                                            \
  catch ( base64::exception const &e ) {                                    \
    throw XQUERY_EXCEPTION(                                                 \
      err::FORG0001, ERROR_PARAMS( e.invalid_char(), ZED( Base64BadChar ) ) \
    );                                                                      \
  }                                                                         \
  catch ( std::invalid_argument const& ) {                                  \
    throw XQUERY_EXCEPTION(                                                 \
      err::FORG0001, ERROR_PARAMS( "", ZED( Base64Multiple4 ) )             \
    );                                                                      \
  }

using namespace std;

namespace zorba {

static size_t copy_without_ws( char const *from, size_t len, char *to ) {
  char const *const end = from + len;
  char const *const to_orig = to;
  for ( ; from < end; ++from )
    if ( !ascii::is_space( *from ) )
      *to++ = *from;
  return to - to_orig;
}


bool Base64::parseString(const char* aString, size_t aLength,  Base64& aBase64)
{
  if ( aLength ) {
    try 
    {
      base64::validate( aString, aLength, base64::dopt_ignore_ws );
      aBase64.theData.resize( aLength );
      aBase64.theData.resize(
        copy_without_ws( aString, aLength, &aBase64.theData[0] )
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


bool Base64::parseString(
    const char* aString,
    size_t aLength,
    Base64& aBase64, 
    string& lErrorMessage)
{
  if ( aLength ) {
    try 
    {
      base64::validate( aString, aLength, base64::dopt_ignore_ws );
      aBase64.theData.resize( aLength );
      aBase64.theData.resize(
        copy_without_ws( aString, aLength, &aBase64.theData[0] )
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


void Base64::encode(const zstring& aString, Base64& aResult)
{
  base64::encode( aString.data(), aString.size(), &aResult.theData );
}


void Base64::encode(istream& aStream, Base64& aResult)
{
  base64::encode( aStream, &aResult.theData );
}


zstring Base64::encode(istream& aStream)
{
  zstring result;
  base64::encode( aStream, &result );
  return result;
}


void Base64::encode(const vector<char>& aSource, vector<char>& aResult)
{
  if ( !aSource.empty() )
    base64::encode( &aSource[0], aSource.size(), &aResult );
}


void Base64::encode(
    const unsigned char* aSource, 
    unsigned int in_len,
    Base64& aResult)
{
  base64::encode( (char*)aSource, in_len, &aResult.theData );
}


void Base64::decode(istream& aStream, zstring *result)
{
  try {
    base64::decode(
      aStream, result, base64::dopt_any_len | base64::dopt_ignore_ws
    );
  }
  CATCH_BASE64_EXCEPTION()
}

void Base64::decode(const vector<char>& aSource, vector<char>& aResult)
{
  if ( !aSource.empty() ) {
    try {
      base64::decode(
        &aSource[0], aSource.size(), &aResult,
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


Base64::Base64(const Base16& aBase16)
{
  vector<char> lOrig;
  Base16::decode(aBase16.getData(), lOrig);
  Base64::encode(lOrig, theData);
}


Base64::Base64(const unsigned char *bin_data, size_t len)
{
  try {
    base64::encode( (char const*)bin_data, len, &theData );
  }
  CATCH_BASE64_EXCEPTION()
}



bool Base64::equal(const Base64& aBase64) const
{
  if (size() != aBase64.size())
    return false;

  vector<char>::const_iterator lIter0 = theData.begin();
  vector<char>::const_iterator lEnd0 = theData.end();
  vector<char>::const_iterator lIter1 = aBase64.theData.begin();

  while ( lIter0 != lEnd0 )
  {
    if (*lIter0 != *lIter1)
      return false;
    ++lIter0; ++lIter1;
  }
  return true;
}


zstring Base64::str() const 
{
  zstring result;
  vector<char>::const_iterator lIter = theData.begin();
  vector<char>::const_iterator lEnd = theData.end();
  for( ; lIter != lEnd ; ++lIter)
  {
    result.push_back( *lIter );
  }
  return result;
}


zstring Base64::decode() const
{
  zstring result;
  if ( !theData.empty() )
    base64::decode( &theData[0], theData.size(), &result );
  return result;
}


void Base64::decode(vector<char>& aResult)
{
  if ( !theData.empty() )
    base64::decode( &theData[0], theData.size(), &aResult );
}


uint32_t Base64::hash() const
{
  uint32_t lHash = 0;
  vector<char>::const_iterator lIter = theData.begin();
  vector<char>::const_iterator lEnd = theData.end();
  for(;lIter!=lEnd;++lIter)
  {
    uint32_t lDiff = 65535-*lIter;
    if (lDiff < lHash)
    {
      lHash = lHash - lDiff;
    } else {
      lHash += *lIter; 
    }
  }
  return lHash;
}


ostream& operator<<(ostream& os, const Base64& aBase64)
{
  vector<char>::const_iterator lIter = aBase64.getData().begin();
  vector<char>::const_iterator lEnd = aBase64.getData().end();
  for( ; lIter != lEnd ; ++lIter)
  {
    os << *lIter;
  }
  return os;
}

///////////////////////////////////////////////////////////////////////////////

const char* Base16::ENCODE_TABLE = "0123456789ABCDEF";

const unsigned char Base16::DECODE_TABLE[ 0x80 ] = {
  /*00-07*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*08-0f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*10-17*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*18-1f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*20-27*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*28-2f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*30-37*/ 0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, //8 = '0'-'7'
  /*38-3f*/ 0x08, 0x09, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, //2 = '8'-'9'
  /*40-47*/ 0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, //6 = 'A'-'F'
  /*48-4f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*50-57*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*58-5f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*60-67*/ 0xFF, 0x0a, 0x0b, 0x0c, 0x0d, 0x0e, 0x0f, 0xFF, //6 = 'a'-'f' (same as 'A'-'F')
  /*68-6f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*70-77*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  /*78-7f*/ 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

size_t Base16::ENCODE_INPUT = 1;
size_t Base16::ENCODE_OUTPUT = 2;
size_t Base16::DECODE_INPUT = 2;
size_t Base16::DECODE_OUTPUT = 1;


Base16::Base16(const Base64& aBase64)
{
  vector<char> lOrig;
  Base64::decode(aBase64.getData(), lOrig);
  Base16::encode(lOrig, theData);
}


bool Base16::parseString(const char* aString, size_t aLength, Base16& aBase16)
{
  aBase16.theData.clear();
  try 
  {
    aBase16.insertData(aString, aLength);
  }
  catch (...)
  {
    return false;
  }
  return true;
}


void Base16::insertData(const char* str, size_t len)
{
  zstring_b wrap;
  wrap.wrap_memory(str, len);

  ascii::trim_whitespace(wrap);

  len = wrap.size();
  str = wrap.data();

  if (len % 2 != 0) 
  {
    throw XQUERY_EXCEPTION(
      err::FORG0001, ERROR_PARAMS( "", ZED( HexBinaryMustBeEven ) )
    );
  }

  for (size_t i = 0; i < len; ++i)
  {
    char lChar = str[i];
    if ((lChar >= 65 && lChar <= 70)  // A-F
     || (lChar >= 48 && lChar <= 57))  // 0-9
    {
      theData.push_back(lChar);
    }
    else if (lChar >= 97 && lChar <= 102) // a-f
    {
      theData.push_back(lChar-32);
    }
    else
    {
      throw XQUERY_EXCEPTION(
        err::FORG0001, ERROR_PARAMS( lChar, ZED( BadHexDigit_3 ), lChar )
      );
    }
  }
}


bool Base16::equal(const Base16& aBase16) const
{
  if (size() != aBase16.size())
    return false;

  vector<char>::const_iterator lIter0 = theData.begin();
  vector<char>::const_iterator lEnd0 = theData.end();
  vector<char>::const_iterator lIter1 = aBase16.theData.begin();

  for (; lIter0 != lEnd0 ; )
  {
    if (*lIter0 != *lIter1)
      return false;
    ++lIter0; ++lIter1;
  }
  return true;
}


zstring Base16::str() const 
{
  stringstream lStream;
  lStream << *this;
  return zstring(lStream.str());
}


void Base16::encode(const vector<char>& aSource, vector<char>& aResult)
{
  size_t lSrcPos = 0;
  size_t lSrcSize = aSource.size();

  while (lSrcSize >= 1)
  {
    // 1 input...
    char ch = aSource[lSrcPos++];
    lSrcSize -= ENCODE_INPUT; //1

    // 2 outputs...
    aResult.push_back(ENCODE_TABLE[ (ch & 0xf0) >> 4 ]);
    aResult.push_back(ENCODE_TABLE[ (ch & 0x0f)      ]);
  }
}


void Base16::decode(const vector<char>& aSource, vector<char>& aResult)
{
  size_t lSrcSize = aSource.size();
  size_t lSrcPos = 0;
  assert(lSrcSize % DECODE_INPUT == 0);

  while (lSrcSize >= 1)
  {
    // 2 inputs...
    char in1 = aSource[lSrcPos++];
    char in2 = aSource[lSrcPos++];
    lSrcSize -= DECODE_INPUT;

    // Validate ascii...
    assert( 0 <= in1 /*&& in1 <= 0x7f*/ );
    assert( 0 <= in2 /*&& in2 <= 0x7f*/ );

    // Convert ascii to base16...
    in1 = DECODE_TABLE[ int(in1) ];
    in2 = DECODE_TABLE[ int(in2) ];

    // Validate base16...
    /*assert( in1 != 0xff );*/
    assert( 0 <= in1 && in1 <= 15 );
    assert( 0 <= in2 && in2 <= 15 );

    // 1 output...
    aResult.push_back(((in1 << 4) | in2));
  }
}

uint32_t Base16::hash() const
{
  uint32_t lHash = 0;
  vector<char>::const_iterator lIter = theData.begin();
  vector<char>::const_iterator lEnd = theData.end();
  for(;lIter!=lEnd;++lIter)
  {
    uint32_t lDiff = 65535-*lIter;
    if (lDiff < lHash)
    {
      lHash = lHash - lDiff;
    } else {
      lHash += *lIter; 
    }
  }
  return lHash;
}


ostream& operator<<(ostream& os, const Base16& aBase16)
{
  vector<char>::const_iterator lIter = aBase16.getData().begin();
  vector<char>::const_iterator lEnd = aBase16.getData().end();
  for( ; lIter != lEnd ; ++lIter)
  {
    os << *lIter;
  }
  return os;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
