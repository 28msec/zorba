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

#include <zorba/zorba_string.h>

#include "api/unmarshaller.h"
#include "util/ascii_util.h"
#include "util/cxx_util.h"
#include "util/regex.h"
#include "util/string_util.h"
#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "util/xml_util.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zstring.h"

using namespace std;

namespace zorba {

/**
 * The string type we're actually using.
 */
typedef zstring string_type;

// This is not an inline function since string_storage_ is private.
#define STRING_OF(STRING_OBJ)                                             \
  const_cast<string_type*>(                                               \
    reinterpret_cast<string_type const*>( &(STRING_OBJ).string_storage_ ) \
  )

#define THIS_STRING STRING_OF( *this )

void String::size_check() {
  static_assert(
    sizeof( string_storage_type ) >= sizeof( string_type ),
    "storage for zstring is too small"
  );
}

////////// constructors & destructor //////////////////////////////////////////

String::String() {
  new( THIS_STRING ) string_type;
}

String::String( String const &s ) {
  new( THIS_STRING ) string_type( *STRING_OF( s ) );
}

String::String( string const &s ) {
  new( THIS_STRING ) string_type( s );
}

String::String( const_pointer s ) {
  new( THIS_STRING ) string_type( s );
}

String::String( String const &s, size_type pos, size_type n ) {
  new( THIS_STRING ) string_type( *STRING_OF( s ), pos, n );
}

String::String( string const &s, size_type pos, size_type n ) {
  new( THIS_STRING ) string_type( s, pos, n );
}

String::String( const_pointer s, size_type n ) {
  new( THIS_STRING) string_type( s, n );
}

String::String( size_type n, value_type c ) {
  new( THIS_STRING ) string_type( n, c );
}

String::String( const_iterator i, const_iterator j ) {
  new( THIS_STRING ) string_type( i, j );
}

String::String( zstring_ptr zp ) {
  new( THIS_STRING ) string_type(
    *reinterpret_cast<string_type const*>( zp.ptr )
  );
}

String::~String() {
  THIS_STRING->~string_type();
}

////////// assignment /////////////////////////////////////////////////////////

String& String::operator=( String const &s ) {
  *THIS_STRING = *STRING_OF( s );
  return *this;
}

String& String::operator=( string const &s ) {
  *THIS_STRING = s;
  return *this;
}

String& String::operator=( const_pointer s ) {
  *THIS_STRING = s;
  return *this;
}

String& String::operator=( value_type c ) {
  *THIS_STRING = c;
  return *this;
}

String& String::operator=( zstring_ptr zp ) {
  *THIS_STRING = *reinterpret_cast<string_type const*>( zp.ptr );
  return *this;
}

////////// properties /////////////////////////////////////////////////////////

String::size_type String::capacity() const {
  return THIS_STRING->capacity();
}

String::size_type String::length() const {
  return THIS_STRING->length();
}

////////// character access ///////////////////////////////////////////////////

String::reference String::at( size_type pos ) {
  return THIS_STRING->at( pos );
}

String::value_type String::at( size_type pos ) const {
  return THIS_STRING->at( pos );
}

String::const_reference String::operator[]( size_type pos ) const {
  return (*THIS_STRING)[ pos ];
}

////////// append /////////////////////////////////////////////////////////////

String& String::append( String const &s ) {
  THIS_STRING->append( *STRING_OF( s ) );
  return *this;
}

String& String::append( string const &s ) {
  THIS_STRING->append( s );
  return *this;
}

String& String::append( const_pointer s ) {
  THIS_STRING->append( s );
  return *this;
}

String& String::append( String const &s, size_type s_pos, size_type s_n ) {
  THIS_STRING->append( *STRING_OF( s ), s_pos, s_n );
  return *this;
}

String& String::append( string const &s, size_type s_pos, size_type s_n ) {
  THIS_STRING->append( s, s_pos, s_n );
  return *this;
}

String& String::append( const_pointer s, size_type s_n ) {
  THIS_STRING->append( s, s_n );
  return *this;
}

String& String::append( size_type n, value_type c ) {
  THIS_STRING->append( n, c );
  return *this;
}

void String::push_back( value_type c ) {
  THIS_STRING->push_back( c );
}

////////// assign /////////////////////////////////////////////////////////////

String& String::assign( String const &s ) {
  THIS_STRING->assign( *STRING_OF( s ) );
  return *this;
}

String& String::assign( string const &s ) {
  THIS_STRING->assign( s );
  return *this;
}

String& String::assign( const_pointer s ) {
  THIS_STRING->assign( s );
  return *this;
}

String& String::assign( String const &s, size_type pos, size_type n ) {
  THIS_STRING->assign( *STRING_OF( s ), pos, n );
  return *this;
}

String& String::assign( string const &s, size_type pos, size_type n ) {
  THIS_STRING->assign( s, pos, n );
  return *this;
}

String& String::assign( const_pointer s, size_type n ) {
  THIS_STRING->assign( s, n );
  return *this;
}

String& String::assign( size_type n, value_type c ) {
  THIS_STRING->assign( n, c );
  return *this;
}

String& String::assign( const_iterator i, const_iterator j ) {
  THIS_STRING->assign( i, j );
  return *this;
}

////////// compare ////////////////////////////////////////////////////////////

int String::compare( String const &s ) const {
  return THIS_STRING->compare( *STRING_OF( s ) );
}

int String::compare( string const &s ) const {
  return THIS_STRING->compare( s );
}

int String::compare( const_pointer s ) const {
  return THIS_STRING->compare( s );
}

int String::compare( size_type pos, size_type n, String const &s ) const {
  return THIS_STRING->compare( pos, n, *STRING_OF( s ) );
}

int String::compare( size_type pos, size_type n, string const &s ) const {
  return THIS_STRING->compare( pos, n, s );
}

int String::compare( size_type pos, size_type n, const_pointer s ) const {
  return THIS_STRING->compare( pos, n, s );
}

int String::compare( size_type pos, size_type n, String const &s,
                     size_type s_pos, size_type s_n ) const {
  return THIS_STRING->compare( pos, n, *STRING_OF( s ), s_pos, s_n );
}

int String::compare( size_type pos, size_type n, string const &s,
                     size_type s_pos, size_type s_n ) const {
  return THIS_STRING->compare( pos, n, s, s_pos, s_n );
}

int String::compare( size_type pos, size_type n, const_pointer s,
                     size_type s_n ) const {
  return THIS_STRING->compare( pos, n, s, s_n );
}

////////// clear/erase ////////////////////////////////////////////////////////

void String::clear() {
  THIS_STRING->clear();
}

String& String::erase( size_type pos, size_type n ) {
  THIS_STRING->erase( pos, n );
  return *this;
}

String::iterator String::erase( iterator i ) {
  return THIS_STRING->erase( i );
}

String::iterator String::erase( iterator i, iterator j ) {
  return THIS_STRING->erase( i, j );
}

////////// find ///////////////////////////////////////////////////////////////

String::size_type String::find( String const &s, size_type pos ) const {
  return THIS_STRING->find( *STRING_OF( s ), pos );
}

String::size_type String::find( string const &s, size_type pos ) const {
  return THIS_STRING->find( s, pos );
}

String::size_type String::find( const_pointer s, size_type pos ) const {
  return THIS_STRING->find( s, pos );
}

String::size_type String::find( const_pointer s, size_type pos,
                                size_type n ) const {
  return THIS_STRING->find( s, pos, n );
}

String::size_type String::find( value_type c, size_type pos ) const {
  return THIS_STRING->find( c, pos );
}

String::size_type String::find_first_of( String const &s,
                                         size_type pos ) const {
  return THIS_STRING->find_first_of( *STRING_OF( s ), pos );
}

String::size_type String::find_first_of( string const &s,
                                         size_type pos ) const {
  return THIS_STRING->find_first_of( s, pos );
}

String::size_type String::find_first_of( const_pointer s,
                                         size_type pos ) const {
  return THIS_STRING->find_first_of( s, pos );
}

String::size_type String::find_first_of( const_pointer s, size_type pos,
                                         size_type n ) const {
  return THIS_STRING->find_first_of( s, pos, n );
}

String::size_type String::find_first_of( value_type c, size_type pos ) const {
  return THIS_STRING->find_first_of( c, pos );
}

String::size_type String::find_first_not_of( String const &s,
                                             size_type pos ) const {
  return THIS_STRING->find_first_not_of( *STRING_OF( s ), pos );
}

String::size_type String::find_first_not_of( string const &s,
                                             size_type pos ) const {
  return THIS_STRING->find_first_not_of( s, pos );
}

String::size_type String::find_first_not_of( const_pointer s,
                                             size_type pos ) const {
  return THIS_STRING->find_first_not_of( s, pos );
}

String::size_type String::find_first_not_of( const_pointer s, size_type pos,
                                             size_type n ) const {
  return THIS_STRING->find_first_not_of( s, pos, n );
}

String::size_type String::find_first_not_of( value_type c,
                                             size_type pos ) const {
  return THIS_STRING->find_first_not_of( c, pos );
}

String::size_type String::find_last_of( String const &s, size_type pos ) const {
  return THIS_STRING->find_last_of( *STRING_OF( s ), pos );
}

String::size_type String::find_last_of( string const &s, size_type pos ) const {
  return THIS_STRING->find_last_of( s, pos );
}

String::size_type String::find_last_of( const_pointer s, size_type pos ) const {
  return THIS_STRING->find_last_of( s, pos );
}

String::size_type String::find_last_of( const_pointer s, size_type pos,
                                        size_type n ) const {
  return THIS_STRING->find_last_of( s, pos, n );
}

String::size_type String::find_last_of( value_type c, size_type pos ) const {
  return THIS_STRING->find_last_of( c, pos );
}

String::size_type String::find_last_not_of( String const &s,
                                            size_type pos ) const {
  return THIS_STRING->find_last_not_of( *STRING_OF( s ), pos );
}

String::size_type String::find_last_not_of( string const &s,
                                            size_type pos ) const {
  return THIS_STRING->find_last_not_of( s, pos );
}

String::size_type String::find_last_not_of( const_pointer s,
                                            size_type pos ) const {
  return THIS_STRING->find_last_not_of( s, pos );
}

String::size_type String::find_last_not_of( const_pointer s, size_type pos,
                                            size_type n ) const {
  return THIS_STRING->find_last_not_of( s, pos, n );
}

String::size_type String::find_last_not_of( value_type c,
                                            size_type pos ) const {
  return THIS_STRING->find_last_not_of( c, pos );
}

String::size_type String::rfind( String const &s, size_type pos ) const {
  return THIS_STRING->rfind( *STRING_OF( s ), pos );
}

String::size_type String::rfind( string const &s, size_type pos ) const {
  return THIS_STRING->rfind( s, pos );
}

String::size_type String::rfind( const_pointer s, size_type pos ) const {
  return THIS_STRING->rfind( s, pos );
}

String::size_type String::rfind( const_pointer s, size_type pos,
                                 size_type n ) const {
  return THIS_STRING->rfind( s, pos, n );
}

String::size_type String::rfind( value_type c, size_type pos ) const {
  return THIS_STRING->rfind( c, pos );
}

////////// insert /////////////////////////////////////////////////////////////

String& String::insert( size_type pos, String const &s ) {
  THIS_STRING->insert( pos, *STRING_OF( s ) );
  return *this;
}

String& String::insert( size_type pos, string const &s ) {
  THIS_STRING->insert( pos, s );
  return *this;
}

String& String::insert( size_type pos, const_pointer s ) {
  THIS_STRING->insert( pos, s );
  return *this;
}

String& String::insert( size_type pos, String const &s, size_type s_pos, 
                        size_type n ) {
  THIS_STRING->insert( pos, *STRING_OF( s ), s_pos, n );
  return *this;
}

String& String::insert( size_type pos, string const &s, size_type s_pos, 
                        size_type n ) {
  THIS_STRING->insert( pos, s, s_pos, n );
  return *this;
}

String& String::insert( size_type pos, const_pointer s, size_type n ) {
  THIS_STRING->insert( pos, s, n );
  return *this;
}

String& String::insert( size_type pos, size_type n, value_type c ) {
  THIS_STRING->insert( pos, n, c );
  return *this;
}

String::iterator String::insert( iterator pos, value_type c ) {
  return THIS_STRING->insert( pos, c );
}

void String::insert( iterator pos, size_type n, value_type c ) {
  THIS_STRING->insert( pos, n, c );
}

////////// replace ////////////////////////////////////////////////////////////

String& String::replace( size_type pos, size_type n, String const &s ) {
  THIS_STRING->replace( pos, n, *STRING_OF( s ) );
  return *this;
}

String& String::replace( size_type pos, size_type n, std::string const &s ) {
  THIS_STRING->replace( pos, n, s );
  return *this;
}

String& String::replace( size_type pos, size_type n, const_pointer s ) {
  THIS_STRING->replace( pos, n, s );
  return *this;
}

String& String::replace( size_type pos, size_type n, String const &s,
                         size_type s_pos, size_type s_n ) {
  THIS_STRING->replace( pos, n, *STRING_OF( s ), s_pos, s_n );
  return *this;
}

String& String::replace( size_type pos, size_type n, string const &s,
                         size_type s_pos, size_type s_n ) {
  THIS_STRING->replace( pos, n, s, s_pos, s_n );
  return *this;
}

String& String::replace( size_type pos, size_type n, const_pointer s,
                         size_type s_n ) {
  THIS_STRING->replace( pos, n, s, s_n );
  return *this;
}

String& String::replace( size_type pos, size_type n, size_type c_n,
                         value_type c ) {
  THIS_STRING->replace( pos, n, c_n, c );
  return *this;
}

String& String::replace( iterator i, iterator j, String const &s ) {
  THIS_STRING->replace( i, j, *STRING_OF( s ) );
  return *this;
}

String& String::replace( iterator i, iterator j, std::string const &s ) {
  THIS_STRING->replace( i, j, s );
  return *this;
}

String& String::replace( iterator i, iterator j, const_pointer s ) {
  THIS_STRING->replace( i, j, s );
  return *this;
}

String& String::replace( iterator i, iterator j, const_pointer s,
                         size_type s_n ) {
  THIS_STRING->replace( i, j, s, s_n );
  return *this;
}

String& String::replace( iterator i, iterator j, size_type n, value_type c ) {
  THIS_STRING->replace( i, j, n, c );
  return *this;
}

String& String::replace( iterator i, iterator j, iterator si, iterator sj ) {
  THIS_STRING->replace( i, j, si, sj );
  return *this;
}

////////// iterators //////////////////////////////////////////////////////////

String::iterator String::begin() {
  return THIS_STRING->begin();
}

String::const_iterator String::begin() const {
  return THIS_STRING->begin();
}

String::iterator String::end() {
  return THIS_STRING->end();
}

String::const_iterator String::end() const {
  return THIS_STRING->end();
}

String::reverse_iterator String::rbegin() {
  return THIS_STRING->rbegin();
}

String::const_reverse_iterator String::rbegin() const {
  return THIS_STRING->rbegin();
}

String::reverse_iterator String::rend() {
  return THIS_STRING->rend();
}

String::const_reverse_iterator String::rend() const {
  return THIS_STRING->rend();
}

////////// miscellaneous //////////////////////////////////////////////////////

String::size_type String::copy( pointer buf, size_type n,
                                size_type pos ) const {
  return THIS_STRING->copy( buf, n, pos );
}

String::const_pointer String::c_str() const {
  return THIS_STRING->c_str();
}

String::const_pointer String::data() const {
  return THIS_STRING->data();
}

void String::reserve( size_type n ) {
  THIS_STRING->reserve( n );
}

void String::resize( size_type n, value_type c ) {
  THIS_STRING->resize( n, c );
}

string String::str() const {
  return THIS_STRING->str();
}

String String::substr( size_type pos, size_type n ) const {
  string_type const s( THIS_STRING->substr( pos, n ) );
  zstring_ptr const zp = { &s };
  return String( zp );
}

void String::swap( String &s ) {
  THIS_STRING->swap( *STRING_OF( s ) );
}

////////// relational operators ///////////////////////////////////////////////

bool operator==( String const &s1, String const &s2 ) {
  return *STRING_OF( s1 ) == *STRING_OF( s2 );
}

bool operator==( String const &s1, string const &s2 ) {
  return *STRING_OF( s1 ) == s2;
}

bool operator==( String const &s1, String::const_pointer s2 ) {
  return *STRING_OF( s1 ) == s2;
}

bool operator<( String const &s1, String const &s2 ) {
  return *STRING_OF( s1 ) < *STRING_OF( s2 );
}

bool operator<( String const &s1, string const &s2 ) {
  return *STRING_OF( s1 ) < s2;
}

bool operator<( String const &s1, String::const_pointer s2 ) {
  return *STRING_OF( s1 ) < s2;
}

bool operator<( string const &s1, String const &s2 ) {
  return s1 < *STRING_OF( s2 );
}

bool operator<( String::const_pointer s1, String const &s2 ) {
  return s1 < *STRING_OF( s2 );
}

bool operator<=( String const &s1, String const &s2 ) {
  return *STRING_OF( s1 ) <= *STRING_OF( s2 );
}

bool operator<=( String const &s1, string const &s2 ) {
  return *STRING_OF( s1 ) <= s2;
}

bool operator<=( String const &s1, String::const_pointer s2 ) {
  return *STRING_OF( s1 ) <= s2;
}

bool operator<=( string const &s1, String const &s2 ) {
  return s1 <= *STRING_OF( s2 );
}

bool operator<=( String::const_pointer s1, String const &s2 ) {
  return s1 <= *STRING_OF( s2 );
}

////////// concatenation //////////////////////////////////////////////////////

String operator+( String const &s1, String const &s2 ) {
  string_type const s( *STRING_OF( s1 ) + *STRING_OF( s2 ) );
  String::zstring_ptr const zp = { &s };
  return String( zp );
}

String operator+( String const &s1, string const &s2 ) {
  string_type const s( *STRING_OF( s1 ) + s2 );
  String::zstring_ptr const zp = { &s };
  return String( zp );
}

String operator+( String const &s1, String::const_pointer s2 ) {
  string_type const s( *STRING_OF( s1 ) + s2 );
  String::zstring_ptr const zp = { &s };
  return String( zp );
}

String operator+( string const &s1, String const &s2 ) {
  string_type const s( s1 + *STRING_OF( s2 ) );
  String::zstring_ptr const zp = { &s };
  return String( zp );
}

String operator+( String::const_pointer s1, String const &s2 ) {
  string_type const s( s1 + *STRING_OF( s2 ) );
  String::zstring_ptr const zp = { &s };
  return String( zp );
}

////////// ostream insertion //////////////////////////////////////////////////

ostream& operator<<( ostream &os, String const &s ) {
  return os << *STRING_OF( s );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
