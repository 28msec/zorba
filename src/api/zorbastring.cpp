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

#include <zorba/zorbastring.h>

#include "api/unmarshaller.h"
#include "util/ascii_util.h"
#include "util/regex.h"
#include "util/static_assert.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"
#include "zorbaerrors/error_manager.h"
#include "zorbatypes/zstring.h"

using namespace std;

namespace zorba {

/**
 * The string type we're actually using.
 */
typedef zstring string_type;

#define STRING_OF(STRING_OBJ)                                             \
  (const_cast<string_type*>(                                              \
    reinterpret_cast<string_type const*>( &(STRING_OBJ).string_storage_ ) \
  ))

#define THIS_STRING STRING_OF( *this )

void String::size_check() {
  ZORBA_STATIC_ASSERT( sizeof( string_type ) <= sizeof( string_storage_type ) );
}

String::String() {
  new( THIS_STRING ) string_type;
}

String::String( String const &s ) {
  new( THIS_STRING ) string_type( *STRING_OF( s ) );
}

String::String( char const *s ) {
  new( THIS_STRING ) string_type( s );
}

String::String( string const &s ) {
  new( THIS_STRING ) string_type( s );
}

String::String( zstring_ptr zp ) {
  new( THIS_STRING ) string_type(
    *reinterpret_cast<string_type const*>( zp.ptr )
  );
}

String::~String() {
  THIS_STRING->~string_type();
}

char const* String::c_str() const {
  return THIS_STRING->c_str();
}

String& String::operator=( String const &s ) {
  *THIS_STRING = *STRING_OF( s );
  return *this;
}

String& String::operator=( zstring_ptr zp ) {
  *THIS_STRING = *reinterpret_cast<string_type const*>( zp.ptr );
  return *this;
}

size_t String::length() const {
  return utf8::length( THIS_STRING->c_str() );
}
 
size_t String::bytes() const {
  return THIS_STRING->length();
}

size_t String::nr_of_chars() const {
	return THIS_STRING->length();
}

bool String::empty() const {
  return THIS_STRING->empty();
}

int String::compare( String const &s ) const {
  return THIS_STRING->compare( *STRING_OF( s ) );
}

bool String::equals( String const &s ) const {
  return *THIS_STRING == *STRING_OF( s );
}

bool String::byteEqual( char const *s, unsigned s_n ) const {
  return ztd::equals( *THIS_STRING, s, s_n );
}

bool String::operator==( String const &s ) const {
  return *THIS_STRING == *STRING_OF( s );
}

bool String::operator<( String const &s ) const {
  return *THIS_STRING < *STRING_OF( s );
}

bool String::operator<=( String const &s ) const {
  return *THIS_STRING <= *STRING_OF( s );
}

bool String::operator>( String const &s ) const {
  return *THIS_STRING > *STRING_OF( s );
}

bool String::operator>=( String const &s ) const {
  return *THIS_STRING >= *STRING_OF( s );
}

char String::charAt( unsigned i ) const {
  return THIS_STRING->at( i );
}

int String::indexOf( char const *pattern ) const {
  return THIS_STRING->find( pattern );
}

int String::lastIndexOf( char const *pattern ) const {
  string_type::size_type const pos = THIS_STRING->rfind( pattern );
  return pos == string_type::npos ? -1 : pos;
}

bool String::endsWith( char const *pattern ) const {
  return utf8::ends_with( *THIS_STRING, pattern );
}

bool String::startsWith( char const *pattern ) const {
  return utf8::begins_with( *THIS_STRING, pattern );
}

String String::substring( unsigned pos ) const {
  return String( THIS_STRING->substr( pos ).c_str() );
}

String String::substring( unsigned pos, unsigned n ) const {
  return String( THIS_STRING->substr( pos, n ).c_str() );
}

String String::append( char const *s ) const {
  String result( *this );
  STRING_OF( result )->append( s );
  return result;
}

String String::append( String const &s ) const {
  String result( *this );
  STRING_OF( result )->append( *STRING_OF( s ) );
  return result;
}

String& String::operator+=( String const &s ) {
  THIS_STRING->append( *STRING_OF( s ) );
  return *this;
}

String& String::operator+=( char const *s ) {
  THIS_STRING->append( s );
  return *this;
}

String& String::uppercase() {
  utf8::to_upper( *THIS_STRING );
  return *this;
}

String& String::lowercase() {
  utf8::to_lower( *THIS_STRING );
  return *this;
}

String& String::normalizeSpace() {
  ascii::normalize_whitespace( *THIS_STRING );
  return *this;
}

String& String::trim( String const &aChars ) {
  ascii::trim( *THIS_STRING, STRING_OF( aChars )->c_str() );
  return *this;
}

String& String::trim(const char* aChars, int /* not used */ ) {
  ascii::trim( *THIS_STRING, aChars );
  return *this;
}

String& String::trim() {
  ascii::trim_whitespace( *THIS_STRING );
  return *this;
}

String& String::formatAsXML() {
  xml::escape( *THIS_STRING );
  return *this;
}

String& String::escapeHtmlUri() {
  utf8::to_html_uri( *THIS_STRING );
  return *this;
}

String& String::iriToUri() {
  utf8::iri_to_uri( *THIS_STRING );
  return *this;
}

String& String::encodeForUri() {
  uri::encode( *THIS_STRING );
  return *this;
}

String& String::decodeFromUri() {
  uri::decode( *THIS_STRING );
  return *this;
}

String String::tokenize( String const &pattern, String const &flags,
                         int32_t *pos, bool *got_token ) const {
  char const *const c_pattern = STRING_OF( pattern )->c_str();
  unicode::regex re;
  re.compile( c_pattern, STRING_OF( flags )->c_str() );

  unicode::string u_token;
  *got_token = re.next_token( *THIS_STRING, pos, &u_token );
  if ( *got_token ) {
    string token;
    utf8::to_string( u_token, &token );
    return String( token );
  }
  return String();
}

ostream& operator<<( ostream &os, String const &s ) {
  return os << *STRING_OF( s );
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
