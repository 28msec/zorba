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
#include <cstring>
#include <cwchar>
#include <sstream>
#include <string>
#include <vector>

#include <zorba/zorba_string.h>

#include "util/ascii_util.h"
#include "util/atomic_int.h"
#include "util/regex.h"
#include "util/stl_util.h"
#include "util/string_util.h"
#include "util/unicode_util.h"
#include "util/uri_util.h"
#include "util/utf8_string.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"
#include "zorbatypes/zstring.h"

using namespace std;
using namespace zorba;

//
// UTF-8 byte sequences for some ISO 8859-1 characters.
//
#define utf8_Aacute  "\xC3\x81"
#define utf8_Eacute  "\xC3\x89"
#define utf8_Iacute  "\xC3\x8D"
#define utf8_Oacute  "\xC3\x93"
#define utf8_Uacute  "\xC3\x9A"
#define utf8_aacute  "\xC3\xA1"
#define utf8_eacute  "\xC3\xA9"
#define utf8_iacute  "\xC3\xAD"
#define utf8_oacute  "\xC3\xB3"
#define utf8_uacute  "\xC3\xBA"

#define utf8_aeiou_acute utf8_aacute utf8_eacute utf8_iacute utf8_oacute utf8_uacute
#define utf8_AEIOU_acute utf8_Aacute utf8_Eacute utf8_Iacute utf8_Oacute utf8_Uacute

//
// Unicode code-points for the above characters.
//
unicode::code_point const ucp_aacute = 0xE1;
unicode::code_point const ucp_eacute = 0xE9;
unicode::code_point const ucp_iacute = 0xED;
unicode::code_point const ucp_oacute = 0xF3;
unicode::code_point const ucp_uacute = 0xFA;

static char whitespace[] = " \f\n\r\t\v";

///////////////////////////////////////////////////////////////////////////////

static int failures;

static bool assert_true( char const *expr, int line, bool result ) {
  if ( !result ) {
    cout << "FAILED, line " << line << ": " << expr << endl;
    ++failures;
  }
  return result;
}

#define ASSERT_TRUE( EXPR ) assert_true( #EXPR, __LINE__, !!(EXPR) )

#define ASSERT_EXCEPTION( EXPR, EXCEPTION ) \
  try { EXPR; assert_true( #EXPR, __LINE__, false ); } \
  catch ( EXCEPTION const& ) { }

#define ASSERT_NO_EXCEPTION( EXPR ) \
  try { EXPR; } \
  catch ( ... ) { assert_true( #EXPR, __LINE__, false ); }

inline char* new_c_string( char const *s ) 
{
  char * p = static_cast<char*>(::operator new(::strlen( s ) + 1));
  return ::strcpy( p, s );

    //return ::strcpy( new char[ ::strlen( s ) + 1 ], s );
}

/**
 * Tests for empty strings.
 */
template<class StringType>
static void test_empty( StringType const &s ) {
  ASSERT_TRUE( s.empty() );
  ASSERT_TRUE( s.size() == 0 );
}

/**
 * Common tests for non-empty strings.
 */
template<class StringType>
static void test_non_empty( StringType &s, char const *csc ) {
  unsigned const cs_len = (unsigned)::strlen( csc );
  char *const cs = new_c_string( "world" );

  ASSERT_TRUE( !s.empty() );
  ASSERT_TRUE( s.size() == cs_len );
  ASSERT_TRUE( s.at( 0 ) == csc[0] );
  ASSERT_TRUE( s.at( 1 ) == csc[1] );
  ASSERT_TRUE( s[0] == csc[0] );
  ASSERT_TRUE( s[1] == csc[1] );
  ASSERT_TRUE( s == csc );
  ASSERT_TRUE( s.compare( csc ) == 0 );
  ASSERT_TRUE( s.find( csc + 2 ) == 2 );
  ASSERT_TRUE( *s.c_str() == csc[0] );
  ASSERT_TRUE( s.str() == csc );
  ASSERT_TRUE( s.substr( 1 ) == csc + 1 );

  { // test swap()
    StringType s2( cs );
    s.swap( s2 );
    ASSERT_TRUE( s == cs );
    ASSERT_TRUE( s2 == csc );
    swap( s, s2 );
    ASSERT_TRUE( s == csc );
    ASSERT_TRUE( s2 == cs );
  }
}

template<class StringType>
static void test() {
  char const csc1[] = "hello";
  char const csc2[] = "world";
  string const ss( csc1 );

  { // test the empty string
    StringType s;
    test_empty( s );
  }
  { // test a string constructed from a C string
    StringType s( csc1 );
    test_non_empty( s, csc1 );
  }
  { // test a string constructed from a std::string
    StringType s( ss );
    test_non_empty( s, csc1 );
  }
  { // test copy constructors
    StringType s1( csc1 );
    StringType s2( s1 );
    ASSERT_TRUE( s1 == s2 );
    StringType s3( s1, 1 );
    ASSERT_TRUE( s3 == csc1 + 1 );
  }
  { // test copy-on-write
    StringType s1( csc1 );
    StringType s2( s1 );
    ASSERT_TRUE( s1.data() == s2.data() );
    s1 += 'x';
    ASSERT_TRUE( s1.data() != s2.data() );
  }
  { // test operator+
    StringType s1( csc1 );
    StringType s2 = s1 + csc2;
    ASSERT_TRUE( s2 == s1.str() + csc2 );
  }
}

/**
 * Tests buf_rep specifically.
 */
static void test_buf_rep() {
  char cs[] = "hello";
  string s( cs );

  { // test the empty string
    zstring_b s;
    test_empty( s );
  }
  { // test a string constructed from a C string
    zstring_b s( cs );
    test_non_empty( s, cs );
    ASSERT_TRUE( s.data() == cs );
  }
  { // test that it can't resize
    zstring_b s( cs );
    ASSERT_EXCEPTION( s += 'x', length_error );
  }
  { // test when size() < capacity()
    char buf[12] = "hello";
    zstring_b s( buf, sizeof( buf ) );
    ASSERT_TRUE( s.capacity() == sizeof( buf ) );
    ASSERT_TRUE( s.size() == 5 );
    s += " world";
    ASSERT_TRUE( s.size() == 11 );
  }
}

/**
 * Tests ptr_rep specifically.
 */
static void test_ptr_rep() {
  char const csc[] = "hello";
  { // ensure the string is NOT copied via construction
    char *const cs = new_c_string( "world" );
    zstring_p s( cs );
    ASSERT_TRUE( cs == s.data() );
  }
  { // ensure the string is copied via construction
    zstring_p s( csc );
    ASSERT_TRUE( csc != s.data() );
  }
  { // ensure the string is NOT copied via assignment
    char *const cs = new_c_string( "world" );
    zstring_p s;
    s = cs;
    ASSERT_TRUE( cs == s.data() );
  }
  { // ensure the string is copied via assignment
    zstring_p s;
    s = csc;
    ASSERT_TRUE( csc != s.data() );
  }
}

template<class StringType>
static void test_clark() {
  StringType result;

  StringType uname = "{foo}bar";
  ASSERT_TRUE( xml::clark_uri( uname, &result ) );
  ASSERT_TRUE( result == "foo" );
  ASSERT_TRUE( xml::clark_localname( uname, &result ) );
  ASSERT_TRUE( result == "bar" );

  uname = "{a}b";
  ASSERT_TRUE( xml::clark_uri( uname, &result ) );
  ASSERT_TRUE( result == "a" );
  ASSERT_TRUE( xml::clark_localname( uname, &result ) );
  ASSERT_TRUE( result == "b" );

  ASSERT_TRUE( !xml::clark_uri( StringType( "" ), &result ) );
  ASSERT_TRUE( !xml::clark_uri( StringType( "{" ), &result ) );
  ASSERT_TRUE( !xml::clark_uri( StringType( "}" ), &result ) );
  ASSERT_TRUE( !xml::clark_uri( StringType( "{}" ), &result ) );

  ASSERT_TRUE( !xml::clark_localname( StringType( "" ), &result ) );
  ASSERT_TRUE( !xml::clark_localname( StringType( "bar" ), &result ) );
  ASSERT_TRUE( !xml::clark_localname( StringType( "{}" ), &result ) );
  ASSERT_TRUE( !xml::clark_localname( StringType( "{foo}" ), &result ) );
}

/**
 * Tests utf8_iterator specifically.
 */
template<class StringType>
static void test_utf8_iterator( char const *csc ) {
  StringType const s( csc );
  utf8_string<StringType const> u( s );
  utf8::iterator<typename StringType::const_iterator> i( u.begin() );
  utf8::iterator<typename StringType::const_iterator> j( u.end() );
  for ( unsigned n = 0; n < u.size(); ++n, ++i )
    if ( !ASSERT_TRUE( *i == u[n] ) )
      break;
  ASSERT_TRUE( i == j );
}

/**
 * Tests utf8_iterator specifically.
 */
template<class StringType>
static void test_utf8_iterator() {
  test_utf8_iterator<StringType>( "hello" );
  test_utf8_iterator<StringType>( utf8_aeiou_acute );
}

/**
 * Tests utf8_string specifically.
 */
template<class StringType>
static void test_utf8_string() {
  StringType s1( utf8_aeiou_acute );
  utf8_string<StringType> u1( s1 );

  ASSERT_TRUE( u1.bytes() == s1.size() );
  ASSERT_TRUE( u1.size() == 5 );
  ASSERT_TRUE( u1[0] == ucp_aacute );
  ASSERT_TRUE( u1[1] == ucp_eacute );
  ASSERT_TRUE( u1[2] == ucp_iacute );
  ASSERT_TRUE( u1[3] == ucp_oacute );
  ASSERT_TRUE( u1[4] == ucp_uacute );

  StringType s2( utf8_aacute utf8_eacute utf8_iacute );
  utf8_string<StringType> u2( s2 );

  ASSERT_TRUE( u1.compare( s2 ) > 0 );
  ASSERT_TRUE( u1.compare( u2 ) > 0 );
  ASSERT_TRUE( u1.compare( 0, 3, u2 ) == 0 );
  ASSERT_TRUE( u1.compare( 1, 1, u2, 1, 1 ) == 0 );

  ASSERT_TRUE( u1.find( ucp_oacute ) == 3 );

  u1.erase( 0, 1 );
  ASSERT_TRUE( u1.bytes() == s1.size() );
  ASSERT_TRUE( u1.size() == 4 );
  ASSERT_TRUE( u1[0] == ucp_eacute );
  ASSERT_TRUE( u1[1] == ucp_iacute );
  ASSERT_TRUE( u1[2] == ucp_oacute );
  ASSERT_TRUE( u1[3] == ucp_uacute );
}

template<class StringType>
static void test_getline() {
  string const s( "hello world" );
  istringstream is( s );
  StringType t;
  getline( is, t );
  ASSERT_TRUE( s == t );
}

template<class StringType>
static void test_normalize_whitespace() {
  StringType const s( "  hello  world  " );
  StringType u;

  ascii::normalize_whitespace( s, &u );
  ASSERT_TRUE( u == "hello world" );

  utf8_string<StringType const> const s8( s );
  utf8_string<StringType> u8( u );
  utf8::normalize_whitespace( s8, &u8 );
  ASSERT_TRUE( u8 == "hello world" );
}

static void test_next_match() {
  unicode::regex re;
  ASSERT_NO_EXCEPTION( re.compile( "[a-z]+" ) );

  string const s( "hello world" );
  unicode::string u;
  ASSERT_TRUE( unicode::to_string( s, &u ) );

  unicode::size_type pos = 0;
  unicode::string u_match;
  string match;

  if ( !ASSERT_TRUE( re.next_match( u, &pos, &u_match ) ) )
    return;
  ASSERT_TRUE( utf8::to_string( u_match, &match ) );
  ASSERT_TRUE( match == "hello" );

  if ( !ASSERT_TRUE( re.next_match( u, &pos, &u_match ) ) )
    return;
  ASSERT_TRUE( utf8::to_string( u_match, &match ) );
  ASSERT_TRUE( match == "world" );
}

static void test_next_token() {
  unicode::regex re;
  ASSERT_NO_EXCEPTION( re.compile( "," ) );

  string const s( "a,b,c" );
  unicode::string u;
  ASSERT_TRUE( unicode::to_string( s, &u ) );

  unicode::size_type pos = 0;
  unicode::string u_token;
  string token;
  char comp[2];
  comp[1] = '\0';

  string const expected = "abc";
  for ( string::size_type i = 0; i < expected.size(); ++i ) {
    if ( !ASSERT_TRUE( re.next_token( u, &pos, &u_token ) ) )
      return;
    ASSERT_TRUE( utf8::to_string( u_token, &token ) );
    *comp = expected[i];
    ASSERT_TRUE( token == comp );
  }

  ASSERT_TRUE( !re.next_token( u, &pos, &u_token ) );
}

template<class StringType>
static void test_replace_all() {
  StringType s1( "/a/path/on/the/filesystem/" );
  StringType s2( s1 );
  StringType t( "\\a\\path\\on\\the\\filesystem\\" );

  ascii::replace_all( s1, "/", "\\" );
  ASSERT_TRUE( s1 == t );
  ascii::replace_all( s2, '/', '\\' );
  ASSERT_TRUE( s2 == t );

  s1 = StringType ("\"");
  t = StringType("\\\"");
  ascii::replace_all( s1, "\"", "\\\"");
  ASSERT_TRUE( s1 == t );
}

template<class StringType>
static void test_take() {
  StringType s1( "hello" );
  StringType s2;
  s2.take( s1 );
  ASSERT_TRUE( s1.empty() );
  ASSERT_TRUE( s2 == "hello" );
}

template<class StringType>
static void test_reverse( char const *s ) {
  StringType const s1( s );
  StringType s2;
  typename utf8_stringify<StringType const>::type const u1( s1 );
  typename utf8_stringify<StringType>::type u2( s2 );
  utf8::reverse( u1, &u2 );
  ASSERT_TRUE( s1.size() == s2.size() );
  typename StringType::size_type const u2_last = u2.size() - 1;
  for ( int i = (int)u1.size() / 2 - 1; i >= 0; --i )
    if ( !ASSERT_TRUE( u1[i] == u2[ u2_last - i ] ) )
      break;
}

template<class StringType>
static void test_append_codepoints( char const *s ) {
  StringType const s1( s );

  typedef vector<unicode::char_type> vector_type;
  vector_type code_points;
  utf8::to_codepoints( s1, &code_points );

  StringType s2;
  utf8::append_codepoints( code_points.begin(), code_points.end(), &s2 );
  ASSERT_TRUE( s1 == s2 );
}

template<class StringType>
static void test_begins_with() {
  StringType const ab( "ab" );
  utf8_string<StringType const> const u_ab( ab );

  ASSERT_TRUE(  ascii::begins_with( "ab", 'a' ) );
  ASSERT_TRUE( !ascii::begins_with( "ab", 'b' ) );
  ASSERT_TRUE(  ascii::begins_with( "ab", "a" ) );
  ASSERT_TRUE( !ascii::begins_with( "ab", "b" ) );

  ASSERT_TRUE( !ascii::begins_with( "", 'a' ) );
  ASSERT_TRUE( !ascii::begins_with( "", "a" ) );

  ASSERT_TRUE(  ascii::begins_with( ab, 'a' ) );
  ASSERT_TRUE( !ascii::begins_with( ab, 'b' ) );
  ASSERT_TRUE(  ascii::begins_with( ab, "a" ) );
  ASSERT_TRUE( !ascii::begins_with( ab, "b" ) );

  ASSERT_TRUE(  utf8::begins_with( u_ab, 'a' ) );
  ASSERT_TRUE( !utf8::begins_with( u_ab, 'b' ) );
  ASSERT_TRUE(  utf8::begins_with( u_ab, "a" ) );
  ASSERT_TRUE( !utf8::begins_with( u_ab, "b" ) );
}

template<class StringType>
static void test_ends_with() {
  StringType const ab( "ab" );
  utf8_string<StringType const> const u_ab( ab );

  ASSERT_TRUE(  ascii::ends_with( "ab", 'b' ) );
  ASSERT_TRUE( !ascii::ends_with( "ab", 'a' ) );
  ASSERT_TRUE(  ascii::ends_with( "ab", "b" ) );
  ASSERT_TRUE( !ascii::ends_with( "ab", "a" ) );

  ASSERT_TRUE( !ascii::ends_with( "", 'a' ) );
  ASSERT_TRUE( !ascii::ends_with( "", "a" ) );

  ASSERT_TRUE(  ascii::ends_with( ab, 'b' ) );
  ASSERT_TRUE( !ascii::ends_with( ab, 'a' ) );
  ASSERT_TRUE(  ascii::ends_with( ab, "b" ) );
  ASSERT_TRUE( !ascii::ends_with( ab, "a" ) );

  ASSERT_TRUE(  utf8::ends_with( u_ab, 'b' ) );
  ASSERT_TRUE( !utf8::ends_with( u_ab, 'a' ) );
  ASSERT_TRUE(  utf8::ends_with( u_ab, "b" ) );
  ASSERT_TRUE( !utf8::ends_with( u_ab, "a" ) );
}

static void test_skip_whitespace() {
  char const s[] = "  hello world";
  ascii::size_type const s_len = ::strlen( s );
  ascii::size_type pos = 0;
  ascii::skip_whitespace( s, s_len, &pos );
  ASSERT_TRUE( pos == 2 );
  pos = 7;
  ascii::skip_whitespace( s, s_len, &pos );
  ASSERT_TRUE( pos == 8 );
}

template<class StringType>
static void test_split( char const *left, char const *right ) {
  StringType in, out1, out2;

  in = left;
  in += ':';
  in += right;

  ASSERT_TRUE( ztd::split( in.c_str(), ':', &out1, &out2 ) );
  ASSERT_TRUE( out1 == left );
  ASSERT_TRUE( out2 == right );

  ASSERT_TRUE( ztd::split( in, ':', &out1, &out2 ) );
  ASSERT_TRUE( out1 == left );
  ASSERT_TRUE( out2 == right );

  StringType delim = ":=";

  in = left;
  in += delim;
  in += right;

  ASSERT_TRUE( ztd::split( in.c_str(), delim.c_str(), &out1, &out2 ) );
  ASSERT_TRUE( out1 == left );
  ASSERT_TRUE( out2 == right );

  ASSERT_TRUE( ztd::split( in, delim.c_str(), &out1, &out2 ) );
  ASSERT_TRUE( out1 == left );
  ASSERT_TRUE( out2 == right );

  ASSERT_TRUE( ztd::split( in, delim, &out1, &out2 ) );
  ASSERT_TRUE( out1 == left );
  ASSERT_TRUE( out2 == right );

  ASSERT_TRUE( !ztd::split( in, '|', &out1, &out2 ) );
  ASSERT_TRUE( !ztd::split( in, "|", &out1, &out2 ) );
}

template<class StringType>
static void test_strip_diacritics() {
  StringType result;

  StringType const s1( "x " utf8_aeiou_acute " x" );
  utf8::strip_diacritics( s1, &result );
  ASSERT_TRUE( result == "x aeiou x" );

  StringType const s2( "x " utf8_AEIOU_acute " x" );
  utf8::strip_diacritics( s2, &result );
  ASSERT_TRUE( result == "x AEIOU x" );
}

template<class StringType>
static void test_to_codepoints( char const *s ) {
  StringType const s1( s );

  typedef vector<unicode::char_type> vector_type;
  vector_type code_points;
  utf8::to_codepoints( s1, &code_points );

  typedef typename utf8_stringify<StringType const>::type utf8_string_type;
  utf8_string_type const u( s1 );
  typename utf8_string_type::const_iterator i = u.begin();
  vector_type::const_iterator v = code_points.begin();
  for ( ; i != u.end(); ++i, ++v )
    if ( !ASSERT_TRUE( *i == *v ) )
      break;
}

template<class StringType>
static void test_to_string_from_utf8() {
  StringType const s( utf8_aeiou_acute );
  unicode::string u;
  ASSERT_TRUE( unicode::to_string( s, &u ) );
  ASSERT_TRUE( (size_t)u.length() == utf8::length( s.c_str() ) );
  StringType t;
  ASSERT_TRUE( utf8::to_string( u, &t ) );
  ASSERT_TRUE( t == s );
}

#ifndef ZORBA_NO_ICU
template<class StringType>
static void test_to_string_from_wchar_t() {
  wchar_t const w[] = L"hello";
  StringType s;
  ASSERT_TRUE( utf8::to_string( w, &s ) );
  ASSERT_TRUE( ::wcslen( w ) == s.length() );
  for ( string::size_type i = 0; i < s.length(); ++i )
    ASSERT_TRUE( s[i] == w[i] );
}
#endif /* ZORBA_NO_ICU */

template<class StringType>
static void test_to_upper() {
  StringType const s( "hello" );
  {
    StringType s1( s );
    ascii::to_upper( s1 );
    ASSERT_TRUE( s1 == "HELLO" );
  }
  {
    StringType u;
    ascii::to_upper( s, &u );
    ASSERT_TRUE( u == "HELLO" );
  }
  {
    StringType const s( utf8_aeiou_acute );
    StringType u;
    utf8::to_upper( s, &u );
    ASSERT_TRUE( u == utf8_AEIOU_acute );

    utf8_string<StringType const> const s8( s );
    utf8_string<StringType> u8( u );
    utf8::to_upper( s8, &u8 );
    ASSERT_TRUE( u == utf8_AEIOU_acute );
  }
}

#ifndef ZORBA_NO_ICU
static void test_to_wchar_t() {
  string const s = "hello";
  wchar_t *w;
  unicode::size_type w_len;
  if ( !ASSERT_TRUE( utf8::to_wchar_t( s, &w, &w_len ) ) )
    return;
  ASSERT_TRUE( ::wcslen( w ) == s.length() );
  for ( string::size_type i = 0; i < s.length(); ++i )
    ASSERT_TRUE( w[i] == s[i] );
  delete[] w;
}
#endif /* ZORBA_NO_ICU */

static void test_trim_start() {
  char const *s;

  s = "hello";
  ASSERT_TRUE( ascii::trim_start( s, whitespace ) == s );
  ASSERT_TRUE( ascii::trim_start( s, ::strlen( s ), whitespace ) == s );

  s = " hello";
  ASSERT_TRUE( ascii::trim_start( s, whitespace ) == s + 1 );
  ASSERT_TRUE( ascii::trim_start( s, ::strlen( s ), whitespace ) == s + 1 );

  s = "  hello";
  ASSERT_TRUE( ascii::trim_start( s, whitespace ) == s + 2 );
  ASSERT_TRUE( ascii::trim_start( s, ::strlen( s ), whitespace ) == s + 2 );

  s = "     ";
  ASSERT_TRUE( ascii::trim_start( s, whitespace ) == s + 5 );
  ASSERT_TRUE( ascii::trim_start( s, ::strlen( s ), whitespace ) == s + 5 );
}

static void test_trim_end() {
  char const *s;
  ascii::size_type len;

  s = "hello"; len = ::strlen( s );
  ASSERT_TRUE( ascii::trim_end( s, len, whitespace ) == len );

  s = "hello "; len = ::strlen( s );
  ASSERT_TRUE( ascii::trim_end( s, len, whitespace ) == len - 1 );

  s = "hello  "; len = ::strlen( s );
  ASSERT_TRUE( ascii::trim_end( s, len, whitespace ) == len - 2 );

  s = "     "; len = ::strlen( s );
  ASSERT_TRUE( ascii::trim_end( s, len, whitespace ) == 0 );
}

template<class StringType>
static void test_trim_whitespace() {
  StringType const s( "  hello world  " );
  StringType u;

  ascii::trim_whitespace( s, &u );
  ASSERT_TRUE( u == "hello world" );

  utf8_string<StringType const> const s8( s );
  utf8_string<StringType> u8( u );
  utf8::trim_whitespace( s8, &u8 );
  ASSERT_TRUE( u8 == "hello world" );
}

static void test_iri_to_uri() {
  string const s( "\"hello\"" );
  string t;
  utf8::iri_to_uri( s, &t );
  ASSERT_TRUE( t == "%22hello%22" );
}

template<class StringType>
static void test_uri_encode() {
  StringType const s( "http://www.example.com/" utf8_aacute );

  StringType s2;
  uri::encode( s, &s2 , false );
  ASSERT_TRUE( s2 == "http%3A//www.example.com/%C3%A1" );

  StringType s3;
  uri::decode( s2, &s3 );
  ASSERT_TRUE( s3 == s );
}

static void test_validate() {

  // valid strings
  ASSERT_TRUE( utf8::validate( "" ) == 0 );
  ASSERT_TRUE( utf8::validate( "a" ) == 0 );
  ASSERT_TRUE( utf8::validate( "ab" ) == 0 );
  ASSERT_TRUE( utf8::validate( utf8_aacute ) == 0 );
  ASSERT_TRUE( utf8::validate( utf8_aacute utf8_eacute ) == 0 );

  // invalid start bytes
  char invalid[3];
  invalid[1] = '\0';
  for ( unsigned char c = 0x80; c <= 0xC1; ++c ) {
    invalid[0] = c;
    ASSERT_TRUE( utf8::validate( invalid ) == invalid );
  }
  invalid[0] = '\xFE';
  ASSERT_TRUE( utf8::validate( invalid ) == invalid );
  invalid[0] = '\xFF';
  ASSERT_TRUE( utf8::validate( invalid ) == invalid );

  // invalid continuation bytes
  invalid[0] = '\xC3';
  invalid[2] = '\0';
  for ( unsigned char c = 0x00; c <= 0x7F; ++c ) {
    invalid[1] = c;
    ASSERT_TRUE( utf8::validate( invalid ) == &invalid[1] );
  }
  for ( unsigned char c = 0xC0; c < 0xFF; ++c ) {
    invalid[1] = c;
    ASSERT_TRUE( utf8::validate( invalid ) == &invalid[1] );
  }
}

static void test_validate_with_size() {

  // valid strings
  ASSERT_TRUE( utf8::validate( "", 0 ) == 0 );
  ASSERT_TRUE( utf8::validate( "a", 1 ) == 0 );
  ASSERT_TRUE( utf8::validate( "ab", 2 ) == 0 );
  ASSERT_TRUE( utf8::validate( utf8_aacute, 2 ) == 0 );
  ASSERT_TRUE( utf8::validate( utf8_aacute utf8_eacute, 4 ) == 0 );

  // invalid: length too short
  char const *const invalid = utf8_aacute;
  ASSERT_TRUE( utf8::validate( invalid, 1 ) == invalid );
}

template<class StringType>
static void test_xml_escape() {
  StringType const s( "&b<de>" );
  StringType s2;
  xml::escape( s, &s2 );
  ASSERT_TRUE( s2 == "&#38;b&#60;de&#62;" );
}

static void test_xml_parse_entity() {
  unicode::code_point c;

  ASSERT_TRUE( xml::parse_entity( "&amp;", &c ) != -1 );
  ASSERT_TRUE( c == '&' );
  ASSERT_TRUE( xml::parse_entity( "&lt;", &c ) != -1 );
  ASSERT_TRUE( c == '<' );
  ASSERT_TRUE( xml::parse_entity( "&gt;", &c ) != -1 );
  ASSERT_TRUE( c == '>' );
  ASSERT_TRUE( xml::parse_entity( "&apos;", &c ) != -1 );
  ASSERT_TRUE( c == '\'' );
  ASSERT_TRUE( xml::parse_entity( "&quot;", &c ) != -1 );
  ASSERT_TRUE( c == '"' );

  ASSERT_TRUE( xml::parse_entity( "&#38;", &c ) != -1 );
  ASSERT_TRUE( c == '&' );
  ASSERT_TRUE( xml::parse_entity( "&#x26;", &c ) != -1 );
  ASSERT_TRUE( c == '&' );

  ASSERT_TRUE( xml::parse_entity( "&#x301;", &c ) != -1 );
  ASSERT_TRUE( c == 0x301 );
  ASSERT_TRUE( xml::parse_entity( "&#x0301;", &c ) != -1 );
  ASSERT_TRUE( c == 0x301 );

  ASSERT_TRUE( xml::parse_entity( "&", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&#", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&#x", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&#ZOO;", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&zoo;", &c ) == -1 );

  ASSERT_TRUE( xml::parse_entity( "&amp", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&#38", &c ) == -1 );
  ASSERT_TRUE( xml::parse_entity( "&#x26", &c ) == -1 );
}

///////////////////////////////////////////////////////////////////////////////

namespace zorba {
namespace UnitTests {

int test_string( int, char*[] ) {

  ////////// basic string functionality ///////////////////////////////////////

  test<zstring>();
  test<zstring_p>();
  test<String>();

  test_buf_rep();
  test_ptr_rep();

  test_take<zstring>();
  test_take<zstring_p>();

  test_utf8_string<string>();
  test_utf8_string<zstring>();
  test_utf8_string<zstring_p>();
  test_utf8_string<String>();

  test_utf8_iterator<string>();
  test_utf8_iterator<zstring>();
  test_utf8_iterator<zstring_p>();
  test_utf8_iterator<String>();

  ////////// string functions /////////////////////////////////////////////////

  test_append_codepoints<string>( "hello" );
  test_append_codepoints<string>( utf8_aeiou_acute );
  test_append_codepoints<zstring>( "hello" );
  test_append_codepoints<zstring>( utf8_aeiou_acute );
  test_append_codepoints<String>( "hello" );
  test_append_codepoints<String>( utf8_aeiou_acute );

  test_begins_with<zstring>();
  test_begins_with<String>();

  test_clark<string>();
  test_clark<zstring>();
  test_clark<String>();

  test_ends_with<string>();
  test_ends_with<zstring>();
  test_ends_with<String>();

  test_getline<string>();
  test_getline<zstring>();

  test_iri_to_uri();

  test_next_match();
  test_next_token();

  test_normalize_whitespace<string>();
  test_normalize_whitespace<zstring>();
  test_normalize_whitespace<zstring_p>();
  test_normalize_whitespace<String>();

  test_replace_all<string>();
  test_replace_all<String>();

  test_reverse<string>( "hello" );
  test_reverse<zstring>( "hello" );
  test_reverse<zstring_p>( "hello" );
  test_reverse<String>( "hello" );

  test_reverse<string>( utf8_aeiou_acute );
  test_reverse<zstring>( utf8_aeiou_acute );
  test_reverse<zstring_p>( utf8_aeiou_acute );
  test_reverse<String>( utf8_aeiou_acute );

  test_skip_whitespace();

  test_split<string>( "a", "b" );
  test_split<zstring>( "a", "b" );
  test_split<zstring>( "", "b" );
  test_split<zstring>( "a", "" );
  test_split<String>( "a", "" );

  test_strip_diacritics<string>();
  test_strip_diacritics<zstring>();

  test_to_codepoints<string>( "hello" );
  test_to_codepoints<string>( utf8_aeiou_acute );
  test_to_codepoints<zstring>( "hello" );
  test_to_codepoints<zstring>( utf8_aeiou_acute );
  test_to_codepoints<String>( "hello" );
  test_to_codepoints<String>( utf8_aeiou_acute );

  test_to_string_from_utf8<string>();
  test_to_string_from_utf8<zstring>();
  test_to_string_from_utf8<zstring_p>();

#ifndef ZORBA_NO_ICU
  test_to_string_from_wchar_t<string>();
  test_to_string_from_wchar_t<zstring>();
  test_to_string_from_wchar_t<zstring_p>();
#endif /* ZORBA_NO_ICU */

  test_to_upper<string>();
  test_to_upper<zstring>();
  test_to_upper<zstring_p>();
  test_to_upper<String>();

#ifndef ZORBA_NO_ICU
  test_to_wchar_t();
#endif /* ZORBA_NO_ICU */

  test_trim_start();
  test_trim_end();
  test_trim_whitespace<string>();
  test_trim_whitespace<zstring>();
  test_trim_whitespace<String>();

  test_uri_encode<string>();
  test_uri_encode<String>();

  test_validate();
  test_validate_with_size();

  test_xml_escape<string>();
  test_xml_escape<String>();

  test_xml_parse_entity();

  cout << failures << " test(s) failed\n";
  return failures ? 1 : 0;
}

} // namespace UnitTests
} // namespace zorba

/* vim:set et sw=2 ts=2: */
