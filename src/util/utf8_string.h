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
#pragma once
#ifndef ZORBA_UTF8_STRING_H
#define ZORBA_UTF8_STRING_H

#include <iostream>
#include <stdexcept>
#include <string>

#include <zorba/zorba_string.h>

#include "utf8_util_base.h"

namespace zorba {

////////// utf8_string_traits /////////////////////////////////////////////////

/**
 * Various traits needed by utf8_string.  The only reason for having a traits
 * class at all is to be able to have a specialization for std::string.
 *
 * @tparam RStringType The rstring type this %utf8_string_traits is for.
 */
template<class RStringType>
struct utf8_string_traits {

  /**
   * The std::string type corresponding to the rstring type.
   */
  typedef typename RStringType::std_string std_string;

  /**
   * The result string type for operations that create a new string, e.g.,
   * operator+().
   */
  typedef typename RStringType::result_type result_type;

  /**
   * The corresponding std::string type when used as an overloaded function
   * argument.
   */
  typedef std_string std_string_arg;

  /**
   * The return-type for utf8_string::str().
   */
  typedef std_string str_return_type;

  /**
   * A utf8_string::str() helper function.
   */
  static str_return_type str( RStringType const &s ) {
    return s.str();
  }
};

/**
 * Partial specialization of %utf8_string_traits for std::string.
 */
template<class CharType,class TraitsType,class Allocator>
struct utf8_string_traits< std::basic_string<CharType,TraitsType,Allocator> > {

  /**
   * For std::string, it's its own corresponding type.
   */
  typedef std::basic_string<CharType,TraitsType,Allocator> std_string;

  /**
   * For std::string, it's its own result string type.
   */
  typedef std_string result_type;

  /**
   * The std::string type when used as an overloaded function argument.
   *
   * The utf8_string class has overloaded functions that take std::string as an
   * argument for convenience, for example:
   *
   *    utf8_string& operator=( StringType const& );
   *    utf8_string& operator=( std_string const& );
   *
   * When StringType is a rstring, there's no conflict; however for
   * utf8_string<std::string>, StringType is std::string, the above would
   * resolve to:
   *
   *    utf8_string& operator=( std::string const& );
   *    utf8_string& operator=( std::string const& );     // conflict
   *
   * One way to solve this problem is to introduce a std_string_arg type that's
   * used only by member function arguments instead of std_string directly:
   *
   *    utf8_string& operator=( StringType const& );
   *    utf8_string& operator=( std_string_arg const& );
   *
   * For utf8_string<std::string>, std_string_arg is specialized to a bogus
   * type just to be distinct from std::string so there will be no conflict:
   *
   *    utf8_string& operator=( std::string const& );
   *    utf8_string& operator=( std_string_arg const& );  // no conflict
   *
   * Note that std_string_arg when specialized to a bogus type will never
   * actually be used.
   */
  struct std_string_arg { };

  /**
   * The return-type for the utf8_string::str().  For utf8_string<std::string>,
   * the return-type can be optimized to return a reference to the std::string
   * itself.
   */
  typedef std_string const& str_return_type;

  /**
   * A utf8_string::str() helper function.  For utf8_string<std::string>, this
   * simply returns the std::string itself.
   */
  static str_return_type str( std_string const &s ) {
    return s;
  }
};

/**
 * Partial specialization of %utf8_string_traits for std::string const.
 */
template<class CharType,class TraitsType,class Allocator>
struct utf8_string_traits<
  std::basic_string<CharType,TraitsType,Allocator> const
> {
  typedef std::basic_string<CharType,TraitsType,Allocator> std_string;
  typedef std_string result_type;
  struct std_string_arg { };
  typedef std_string const& str_return_type;
  static str_return_type str( std_string const &s ) { return s; }
};

/**
 * Partial specialization of %utf8_string_traits for String.
 */
template<>
struct utf8_string_traits<String> {
  typedef std::string std_string;
  typedef String result_type;
  typedef std_string std_string_arg;
  typedef std_string str_return_type;
  static str_return_type str( String const &s ) { return s.str(); }
};

/**
 * Partial specialization of %utf8_string_traits for String const.
 */
template<>
struct utf8_string_traits<String const> {
  typedef std::string std_string;
  typedef String result_type;
  typedef std_string std_string_arg;
  typedef std_string str_return_type;
  static str_return_type str( String const &s ) { return s.str(); }
};

////////// utf8_string ////////////////////////////////////////////////////////

/**
 * A %utf8_string is a "wrapper" around an existing string class that modifies
 * all of its member functions to work correctly with a string encoded in
 * UTF-8.  This wrapper works with any string class having the same API as
 * std::string.
 *
 * @tparam StringType The string type to wrap.
 */
template<class StringType>
class utf8_string {
public:
  typedef StringType string_type;
  typedef typename StringType::allocator_type allocator_type;
  typedef typename StringType::difference_type difference_type;
  typedef typename StringType::size_type size_type;
  typedef typename StringType::traits_type traits_type;

  typedef unicode::code_point value_type;
  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  //
  // Since there is currently no way to have a value_type as an lvalue (say for
  // operator[]) and a value_type is small enough to be passed by value,
  // there's no point in having an actual reference; therefore, declare
  // "reference" and "const_reference" as simply a synonym for value_type.
  //
  typedef value_type reference;
  typedef value_type const const_reference;

  typedef typename StringType::value_type storage_type;
  typedef typename StringType::pointer storage_pointer;
  typedef typename StringType::const_pointer const_storage_pointer;
  typedef typename StringType::reference storage_reference;
  typedef typename StringType::const_reference const_storage_reference;
  typedef typename StringType::iterator storage_iterator;
  typedef typename StringType::const_iterator const_storage_iterator;

  typedef typename utf8::iterator<storage_iterator> iterator;
  typedef typename utf8::iterator<const_storage_iterator> const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  typedef utf8_string_traits<StringType> string_traits_type;
  typedef typename string_traits_type::result_type result_type;
  typedef typename string_traits_type::std_string std_string;
  typedef typename string_traits_type::std_string_arg std_string_arg;
  typedef typename string_traits_type::str_return_type str_return_type;

  static size_type const npos = static_cast<size_type>( -1 );

  ////////// constructors & destructor ////////////////////////////////////////

  /**
   * Constructs a %utf8_string around the given string.
   *
   * @param s The string to wrap.  Ownership is not taken.
   */
  explicit utf8_string( StringType &s ) : s_( &s ), delete_( false ) {
    // do nothing else
  }

  /**
   * Constructs a %utf8_string around the given string.
   *
   * @param s The string to wrap.  Ownership is taken: the string will be
   * deleted when the %utf8_string is destroyed.
   * @throws std::logic_error if \a s is \c nullptr.
   */
  explicit utf8_string( StringType *s ) : s_( s ), delete_( true ) {
    if ( !s )
      throw std::logic_error( "NULL not valid" );
  }

  /**
   * Constructs a %utf8_string around a C string.
   *
   * @param s The C string.
   */
  explicit utf8_string( const_storage_pointer s ) :
    s_( new StringType( s ) ), delete_( true )
  {
    // do nothing else
  }

  /**
   * Constructs a %utf8_string around a C string.
   *
   * @param s The C string.
   */
  explicit utf8_string( storage_pointer s ) :
    s_( new StringType( s ) ), delete_( true )
  {
    // do nothing else
  }

  /**
   * Destructs this %utf8_string.
   */
  ~utf8_string() {
    if ( delete_ )
      delete s_;
  }

  ////////// assignment ///////////////////////////////////////////////////////

  /**
   * Assigns a string to the wrapped string.
   *
   * @param s The string to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( utf8_string const &s ) {
    return assign( *s.s_ );
  }

  /**
   * Assigns a string to the wrapped string.
   *
   * @param s The string to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  template<class StringType2>
  utf8_string& operator=( utf8_string<StringType2> const &s ) {
    return assign( s.data(), s.size() );
  }

  /**
   * Assigns a string to the wrapped string.
   *
   * @param s The string to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( StringType const &s ) {
    return assign( s );
  }

  /**
   * Assigns a string to the wrapped string.
   *
   * @param s The string to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( std_string_arg const &s ) {
    return assign( s );
  }

  /**
   * Assigns a C string to the wrapped string.
   *
   * @param s The C string to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( const_storage_pointer s ) {
    return assign( s );
  }

  /**
   * Assigns an ASCII character to the wrapped string.
   *
   * @param s The ASCII character to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( storage_type c ) {
    return assign( 1, c );
  }

  /**
   * Assigns a Unicode character to the wrapped string.
   *
   * @param s The Unicode character to assign from.
   * @return Returns a reference to this %utf8_string.
   */
  utf8_string& operator=( value_type c ) {
    utf8::encoded_char_type ec;
    s_->assign( ec, utf8::encode( c, ec ) );
    return *this;
  }

  ////////// properties ///////////////////////////////////////////////////////

  /**
   * Gets the number of bytes (not characters) in this string.
   * This function is an extension to the std::string API.
   *
   * @return Returns said number.
   */
  size_type bytes() const {
    return s_->size();
  }

  /**
   * Gets the capacity of this string.
   *
   * @return Returns said capacity (in bytes).
   */
  size_type capacity() const {
    return s_->capacity();
  }

  /**
   * Checks whether the string is empty.
   *
   * @return Returns \c true only if it is.
   */
  bool empty() const {
    return s_->empty();
  }

  /**
   * Gets the string around which this %utf8_string is wrapped.
   * This function is an extension to the std::string API.
   *
   * @return Returns said string.
   */
  StringType* get() const {
    return s_;
  }

  /**
   * Gets the alloctator used by this string.
   *
   * @return Returns said allocator.
   */
  allocator_type get_allocator() const {
    return s_->get_allocator();
  }

  /**
   * Gets the number of characters (not bytes) in this string.
   * Note that since UTF-8 is a variable-length encoding, this is an O(n)
   * operation.
   *
   * @return Returns said number.
   */
  size_type length() const {
    return utf8::length( s_->data(), s_->data() + s_->size() );
  }

  /**
   * Gets the number of characters (not bytes) in this string.
   * Note that since UTF-8 is a variable-length encoding, this is an O(n)
   * operation.
   * (This is a synonym for length().)
   *
   * @return Returns said number.
   */
  size_type size() const {
    return length();
  }

  ////////// character access /////////////////////////////////////////////////

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the UTF-8 character (not byte).  The index is
   * bounds-checked.
   * @return Returns said character as an r-value.
   * @throw std::out_of_range if \a pos >= \c size().
   */
  value_type at( size_type pos ) const {
    return utf8::char_at( s_->data(), s_->size(), pos );
  }

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the UTF-8 character (not byte).  The index is not
   * bounds-checked.
   * @return Returns said character as an r-value.
   */
  value_type operator[]( size_type pos ) const {
    return utf8::char_at( s_->data(), pos );
  }

  ////////// append ///////////////////////////////////////////////////////////

  utf8_string& append( utf8_string const &s ) {
    return append( *s.s_ );
  }

  template<class StringType2>
  utf8_string& append( utf8_string<StringType2> const &s ) {
    return append( s.data(), s.size() );
  }

  utf8_string& append( StringType const &s ) {
    s_->append( s );
    return *this;
  }

  utf8_string& append( utf8_string const &s, size_type pos, size_type n ) {
    return append( *s.s_ );
  }

  utf8_string& append( StringType const &s, size_type pos, size_type n ) {
    char2byte const b( s.data(), s.size(), pos, n );
    s_->append( s, b.byte_pos, b.byte_n );
    return *this;
  }

  utf8_string& append( std_string_arg const &s ) {
    s_->append( s );
    return *this;
  }

  utf8_string& append( std_string_arg const &s, size_type pos, size_type n ) {
    char2byte const b( s.data(), s.size(), pos, n );
    s_->append( s, b.byte_pos, b.byte_n );
    return *this;
  }

  utf8_string& append( const_storage_pointer s ) {
    s_->append( s );
    return *this;
  }

  utf8_string& append( const_storage_pointer s, size_type n ) {
    s_->append( s, utf8::byte_pos( s, n ) );
    return *this;
  }

  utf8_string& append( size_type n, storage_type c ) {
    s_->append( n, c );
    return *this;
  }

  // UTF8_STRING_APPEND_ST_VT_X
  utf8_string& append( size_type n, value_type c );

  void push_back( storage_type c ) {
    s_->push_back( c );
  }

  void push_back( value_type c ) {
    utf8::encoded_char_type ec;
    s_->append( ec, utf8::encode( c, ec ) );
  }

  utf8_string& operator+=( utf8_string const &s ) {
    return append( s );
  }

  template<class StringType2>
  utf8_string& operator+=( utf8_string<StringType2> const &s ) {
    return append( s );
  }

  utf8_string& operator+=( StringType const &s ) {
    return append( s );
  }

  utf8_string& operator+=( std_string_arg const &s ) {
    return append( s );
  }

  utf8_string& operator+=( const_storage_pointer s ) {
    return append( s );
  }

  utf8_string& operator+=( storage_type c ) {
    return append( 1, c );
  }

  utf8_string& operator+=( value_type c ) {
    push_back( c );
    return *this;
  }

  ////////// assign ///////////////////////////////////////////////////////////

  // UTF8_STRING_ASSIGN_U_X
  utf8_string& assign( utf8_string const &s );

  // UTF8_STRING_ASSIGN_TU_X
  template<class StringType2>
  utf8_string& assign( utf8_string<StringType2> const &s );

  // UTF8_STRING_ASSIGN_S_X
  utf8_string& assign( StringType const &s );

  // UTF8_STRING_ASSIGN_U_2ST_X
  utf8_string& assign( utf8_string const &s, size_type pos, size_type n );

  // UTF8_STRING_ASSIGN_S_2ST_X
  utf8_string& assign( StringType const &s, size_type pos, size_type n );

  // UTF8_STRING_ASSIGN_SS_X
  utf8_string& assign( std_string_arg const &s );

  // UTF8_STRING_ASSIGN_SS_X
  utf8_string& assign( std_string_arg const &s, size_type pos, size_type n );

  // UTF8_STRING_ASSIGN_CSP_X
  utf8_string& assign( const_storage_pointer s );

  // UTF8_STRING_ASSIGN_CSP_ST_X
  utf8_string& assign( const_storage_pointer s, size_type n );

  // UTF8_STRING_ASSIGN_ST_B_X
  utf8_string& assign( size_type n, storage_type c );

  // UTF8_STRING_ASSIGN_ST_VT_X
  utf8_string& assign( size_type n, value_type c );

  // Added for disambiguation.
  utf8_string& assign( int n, storage_type c ) {
    return assign( static_cast<size_type>( n ), c );
  }

  // Added for disambiguation.
  utf8_string& assign( int n, value_type c ) {
    return assign( static_cast<size_type>( n ), c );
  }

  // UTF8_STRING_ASSIGN_2II_X
  template<class InputIterator>
  utf8_string& assign( InputIterator begin, InputIterator end );

  // UTF8_STRING_TAKE_U_X
  utf8_string& take( utf8_string &s );

  // UTF8_STRING_TAKE_S_X
  utf8_string& take( StringType &s );

  ////////// compare //////////////////////////////////////////////////////////

  // UTF8_STRING_COMPARE_U_X
  int compare( utf8_string const &s ) const;

  // UTF8_STRING_COMPARE_TU_X
  template<class StringType2>
  int compare( utf8_string<StringType2> const &s ) const;

  // UTF8_STRING_COMPARE_S_X
  int compare( StringType const &s ) const;

  // UTF8_STRING_COMPARE_SS_X
  int compare( std_string_arg const &s ) const;

  // UTF8_STRING_COMPARE_CSP_X
  int compare( const_storage_pointer s ) const;

  // UTF8_STRING_COMPARE_2ST_U_X
  int compare( size_type pos, size_type n, utf8_string const &s ) const;

  // UTF8_STRING_COMPARE_2ST_TU_X
  template<class StringType2>
  int compare( size_type pos, size_type n,
               utf8_string<StringType2> const &s ) const;

  // UTF8_STRING_COMPARE_2ST_S_X
  int compare( size_type pos, size_type n, StringType const &s ) const;

  // UTF8_STRING_COMPARE_2ST_SS_X
  int compare( size_type pos, size_type n, std_string_arg const &s ) const;

  // UTF8_STRING_COMPARE_2ST_CSP_X
  int compare( size_type pos, size_type n, const_storage_pointer s ) const;

  // UTF8_STRING_COMPARE_2ST_U_2ST_X
  int compare( size_type pos, size_type n, utf8_string const &s,
               size_type s_pos, size_type s_n ) const;

  // UTF8_STRING_COMPARE_2ST_TU_2ST_X
  template<class StringType2>
  int compare( size_type pos, size_type n, utf8_string<StringType2> const &s,
               size_type s_pos, size_type s_n ) const;

  // UTF8_STRING_2ST_S_2ST_X
  int compare( size_type pos, size_type n, StringType const &s,
               size_type s_pos, size_type s_n ) const;

  // UTF8_STRING_2ST_SS_2ST_X
  int compare( size_type pos, size_type n, std_string_arg const &s,
               size_type s_pos, size_type s_n ) const;

  // UTF8_STRING_2ST_CSP_2ST_X
  int compare( size_type pos, size_type n, const_storage_pointer s,
               size_type s_n ) const;

  ////////// clear/erase //////////////////////////////////////////////////////

  /**
   * Erases the string making it empty.
   */
  void clear() {
    s_->clear();
  }

  /**
   * Erases the given number of characters (not bytes) starting at the given
   * position.
   *
   * @return Returns a reference to this string.
   * @throw std::out_of_range if \a pos is beyond the end of the string.
   */
  utf8_string& erase( size_type pos = 0, size_type n = npos ) {
    char2byte const b( s_->data(), s_->size(), pos, n );
    s_->erase( b.byte_pos, b.byte_n );
    return *this;
  }

  /**
   * Erases the character (not byte) at the given iterator's position.
   *
   * @param i An iterator marking the position of the character to erase.
   * @return Returns a new iterator marking the same position (i.e., what
   * becomes the next character).
   */
  iterator erase( iterator i ) {
    iterator end = i;
    ++end;
    return iterator( s_->erase( i.base(), end.base() ) );
  }

  /**
   * Erases a range of characters (not bytes) [i,j).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @return Returns a new iterator marking the same position as \a i.
   */
  iterator erase( iterator i, iterator j ) {
    return iterator( s_->erase( i.base(), j.base() ) );
  }

  ////////// find /////////////////////////////////////////////////////////////

  // UTF8_STRING_FIND_U_ST_X
  size_type find( utf8_string const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_TU_ST_X
  template<class StringType2>
  size_type find( utf8_string<StringType2> const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_S_ST_X
  size_type find( StringType const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_SS_ST_X
  size_type find( std_string_arg const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_CSP_ST_X
  size_type find( const_storage_pointer s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_CSP_2ST_X
  size_type find( const_storage_pointer s, size_type pos, size_type n ) const;

  // UTF8_STRING_FIND_B_ST_X
  size_type find( storage_type c, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_VT_ST_X
  size_type find( value_type c, size_type pos = 0 ) const;

  // UTF8_STRING_RFIND_U_ST_X
  size_type rfind( utf8_string const &s, size_type pos = npos ) const;

  // UTF8_STRING_RFIND_S_ST_X
  size_type rfind( StringType const &s, size_type pos = npos ) const;

  // UTF8_STRING_RFIND_SS_ST_X
  size_type rfind( std_string_arg const &s, size_type pos = npos ) const;

  // UTF8_STRING_RFIND_CSP_ST_X
  size_type rfind( const_storage_pointer s, size_type pos = npos ) const;

  // UTF8_STRING_RFIND_CSP_2ST_X
  size_type rfind( const_storage_pointer s, size_type pos, size_type n ) const;

  // UTF8_STRING_RFIND_B_ST_X
  size_type rfind( storage_type c, size_type pos = npos ) const;

  // UTF8_STRING_RFIND_VT_ST_X
  size_type rfind( value_type c, size_type pos = npos ) const;

  // UTF8_STRING_FIND_FIRST_OF_U_ST_X
  size_type find_first_of( utf8_string const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_OF_S_ST_X
  size_type find_first_of( StringType const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_OF_SS_ST_X
  size_type find_first_of( std_string_arg const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_OF_CSP_ST_X
  size_type find_first_of( const_storage_pointer s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_OF_CSP_2ST_X
  size_type find_first_of( const_storage_pointer s, size_type pos,
                           size_type n ) const;

  // UTF8_STRING_FIND_FIRST_OF_B_ST_X
  size_type find_first_of( storage_type c, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_OF_VT_ST_X
  size_type find_first_of( value_type c, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_U_ST_X
  size_type find_first_not_of( utf8_string const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_S_ST_X
  size_type find_first_not_of( StringType const &s, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_SS_ST_X
  size_type find_first_not_of( std_string_arg const&, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_CSP_ST_X
  size_type find_first_not_of( const_storage_pointer s,
                               size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_CSP_2ST_X
  size_type find_first_not_of( const_storage_pointer s, size_type pos,
                               size_type n ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_B_2ST_X
  size_type find_first_not_of( storage_type c, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_FIRST_NOT_OF_VT_2ST_X
  size_type find_first_not_of( value_type c, size_type pos = 0 ) const;

  // UTF8_STRING_FIND_LAST_OF_U_ST_X
  size_type find_last_of( utf8_string const &s, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_OF_S_ST_X
  size_type find_last_of( StringType const &s, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_OF_SS_ST_X
  size_type find_last_of( std_string_arg const &s, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_OF_CSP_ST_X
  size_type find_last_of( const_storage_pointer s, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_OF_CSP_2ST_X
  size_type find_last_of( const_storage_pointer s, size_type pos,
                          size_type n ) const;

  // UTF8_STRING_FIND_LAST_OF_B_ST_X
  size_type find_last_of( storage_type c, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_OF_VT_ST_X
  size_type find_last_of( value_type c, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_U_ST_X
  size_type find_last_not_of( utf8_string const &s,
                              size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_S_ST_X
  size_type find_last_not_of( StringType const &s, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_SS_ST_X
  size_type find_last_not_of( std_string_arg const &s,
                              size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_CSP_ST_X
  size_type find_last_not_of( const_storage_pointer s,
                              size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_CSP_2ST_X
  size_type find_last_not_of( const_storage_pointer s, size_type pos,
                              size_type n ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_B_ST_X
  size_type find_last_not_of( storage_type c, size_type pos = npos ) const;

  // UTF8_STRING_FIND_LAST_NOT_OF_VT_ST_X
  size_type find_last_not_of( value_type c, size_type pos = npos ) const;

  ////////// insert ///////////////////////////////////////////////////////////

  // UTF8_STRING_INSERT_ST_U_X
  utf8_string& insert( size_type pos, utf8_string const &s );

  // UTF8_STRING_INSERT_ST_TU_X
  template<class StringType2>
  utf8_string& insert( size_type pos, utf8_string<StringType2> const &s );

  // UTF8_STRING_INSERT_ST_S_X
  utf8_string& insert( size_type pos, StringType const &s );

  // UTF8_STRING_INSERT_ST_U_2ST_X
  utf8_string& insert( size_type pos, utf8_string const &s,
                       size_type s_pos, size_type n );

  // UTF8_STRING_INSERT_ST_TU_2ST_X
  template<class StringType2>
  utf8_string& insert( size_type pos, utf8_string<StringType2> const &s,
                       size_type s_pos, size_type n );

  // UTF8_STRING_INSERT_ST_S_2ST_X
  utf8_string& insert( size_type pos, StringType const &s,
                       size_type s_pos, size_type n );

  // UTF8_STRING_INSERT_ST_CSP_X
  utf8_string& insert( size_type pos, const_storage_pointer s );

  // UTF8_STRING_INSERT_ST_CSP_ST_X
  utf8_string& insert( size_type pos, const_storage_pointer s, size_type n );

  // UTF8_STRING_INSERT_2ST_B_X
  utf8_string& insert( size_type pos, size_type c_n, storage_type c );

  // UTF8_STRING_INSERT_2ST_VT_X
  utf8_string& insert( size_type pos, size_type c_n, value_type c );

  // UTF8_STRING_INSERT_I_B_X
  iterator insert( iterator pos, storage_type c );

  // UTF8_STRING_INSERT_I_VT_X
  iterator insert( iterator pos, value_type c );

  // UTF8_STRING_INSERT_I_ST_B_X
  void insert( iterator pos, size_type c_n, storage_type c );

  // Added for disambiguation.
  void insert( iterator pos, int c_n, storage_type c ) {
    insert( pos, static_cast<size_type>( c_n ), c );
  }

  // UTF8_STRING_INSERT_I_ST_VT_X
  void insert( iterator pos, size_type c_n, value_type c );

  // Added for disambiguation.
  void insert( iterator pos, int c_n, value_type c ) {
    insert( pos, static_cast<size_type>( c_n ), c );
  }

  // UTF8_STRING_INSERT_I_2II_X
  template<class InputIterator>
  void insert( iterator pos, InputIterator begin, InputIterator end );

  ////////// replace //////////////////////////////////////////////////////////

  // UTF8_STRING_REPLACE_2ST_U_X
  utf8_string& replace( size_type pos, size_type n, utf8_string const &s );

  // UTF8_STRING_REPLACE_2ST_TU_X
  template<class StringType2>
  utf8_string& replace( size_type pos, size_type n,
                        utf8_string<StringType2> const &s );

  // UTF8_STRING_REPLACE_2ST_S_X
  utf8_string& replace( size_type pos, size_type n, StringType const &s );

  // UTF8_STRING_REPLACE_2ST_U_2ST_X
  utf8_string& replace( size_type pos, size_type n, utf8_string const &s,
                        size_type s_pos, size_type s_n );

  // UTF8_STRING_REPLACE_2ST_TU_2ST_X
  template<class StringType2>
  utf8_string& replace( size_type pos, size_type n,
                        utf8_string<StringType2> const &s,
                        size_type s_pos, size_type s_n );

  // UTF8_STRING_REPLACE_2ST_S_2ST_X
  utf8_string& replace( size_type pos, size_type n, StringType const &s,
                        size_type s_pos, size_type s_n );

  // UTF8_STRING_REPLACE_2ST_CSP_X
  utf8_string& replace( size_type pos, size_type n, const_storage_pointer s );

  // UTF8_STRING_REPLACE_2ST_CSP_ST_X
  utf8_string& replace( size_type pos, size_type n, const_storage_pointer s,
                        size_type s_n );

  // UTF8_STRING_REPLACE_3ST_B_X
  utf8_string& replace( size_type pos, size_type n, size_type c_n,
                        storage_type c );

  // UTF8_STRING_REPLACE_3ST_VT_X
  utf8_string& replace( size_type pos, size_type n, size_type c_n,
                        value_type c );

  // UTF8_STRING_REPLACE_2I_U_X
  utf8_string& replace( iterator i, iterator j, utf8_string const &s );

  // UTF8_STRING_REPLACE_2I_TU_X
  template<class StringType2>
  utf8_string& replace( iterator i, iterator j,
                        utf8_string<StringType2> const &s );

  // UTF8_STRING_REPLACE_2I_S_X
  utf8_string& replace( iterator i, iterator j, StringType const &s );

  // UTF8_STRING_REPLACE_2I_CSP_X
  utf8_string& replace( iterator i, iterator j, const_storage_pointer s );

  // UTF8_STRING_REPLACE_2I_CSP_ST_X
  utf8_string& replace( iterator i, iterator j, const_storage_pointer s,
                        size_type s_n );

  // UTF8_STRING_REPLACE_2I_ST_B_X
  utf8_string& replace( iterator i, iterator j, size_type n, storage_type c );

  // UTF8_STRING_REPLACE_2I_ST_VT_X
  utf8_string& replace( iterator i, iterator j, size_type n, value_type c ) {
    // TODO
    return *this;
  }

  // Added for disambiguation.
  utf8_string& replace( iterator i, iterator j, int n, value_type c ) {
    return replace( i, i, static_cast<size_type>( n ), c );
  }

  // UTF8_STRING_REPLACE_2I_2II_X
  template<class InputIterator>
  utf8_string& replace( iterator i, iterator j, InputIterator ii,
                        InputIterator ij );

  ////////// iterators ////////////////////////////////////////////////////////

  /**
   * Returns a read-only iterator positioned at the first character (not byte)
   * of the string.
   * 
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return const_iterator( s_->begin() );
  }

  /**
   * Returns a read-only iterator positioned at one past the last character
   * (not byte) of the string.
   * 
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return const_iterator( s_->end() );
  }

  /**
   * Returns a read-only reverse iterator positioned at the first character
   * (not byte) of the string.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator( end() );
  }

  /**
   * Returns a read-only reverse iterator positioned at one past the last
   * character (not byte) of the string.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rend() const {
    return const_reverse_iterator( begin() );
  }

  ////////// miscellaneous ////////////////////////////////////////////////////

  /**
   * Copies a substring to a C string buffer.
   *
   * @param buf The buffer to copy into.
   * @param n The number of characters (not bytes) to copy.
   * @param pos The position of the first character (not byte) to copy.
   * @return Returns the number of bytes actually copied.
   * @throw std::out_of_range if \a pos >= size().
   */
  size_type copy( storage_pointer buf, size_type n, size_type pos = 0 ) const {
    char2byte const b( s_->data(), s_->size(), pos, n );
    return s_->copy( buf, b.byte_n, b.byte_pos );
  }

  /**
   * Gets a pointer to a null-terminated array of characters representing the
   * string's contents.
   *
   * @return Returns said pointer.
   * @see data()
   */
  const_storage_pointer c_str() const {
    return s_->c_str();
  }

  /**
   * Gets a pointer to the raw character data comprising the string, not
   * necessarily null-terminated.
   *
   * @return Returns said pointer.
   * @see c_str()
   */
  const_storage_pointer data() const {
    return s_->data();
  }

  /**
   * Attemts to pre-allocated enough memory to contains the given number of
   * bytes.
   *
   * @param n The number of bytes.
   */
  void reserve( size_type n ) {
    s_->reserve( n );
  }

  /**
   * Resizes the string to the given number of bytes.
   * If the number < \c size(), the string will be truncated;
   * if the number > \c size(), the string will be extended
   * and the new elements will be set to \a c.
   *
   * @param n The number of bytes.
   * @param c Characters to fill any new positions.
   */
  void resize( size_type n, storage_type c = storage_type() ) {
    s_->resize( n, c );
  }

  /**
   * Gets a std::string equivalent of this string.
   * (There intentionally is no <code>operator std::string() const</code> since
   * its convenience would mask the expense of creating a new std::string.)
   * This function is an extension to the std::string API.
   *
   * @return Returns said std::string.
   */
  str_return_type str() const {
    return string_traits_type::str( *s_ );
  }

  /**
   * Creates a new string that is a substring of this string.
   *
   * @param pos The position in this string for first character of the new
   * string.
   * @param n The number of characters to extract.
   * @return Returns the new string.
   * @throw std::out_of_range if \a pos >= size().
   */
  result_type substr( size_type pos = 0, size_type n = npos ) const {
    char2byte const b( s_->data(), s_->size(), pos, n );
    return s_->substr( b.byte_pos, b.byte_n );
  }

  /**
   * Swaps the contents of this string with another.
   * This is an O(1) operation.
   *
   * @param s The string to swap with.
   */
  void swap( utf8_string &s ) {
    s_->swap( *s.s_ );
  }

  /**
   * Swaps the contents of this string with another.
   * This is an O(1) operation.
   *
   * @param s The string to swap with.
   */
  void swap( StringType &s ) {
    s_->swap( s );
  }

private: //////////////////////////////////////////////////////////////////////

  /**
   * Duplicates the given character (uncoded into UTF-8) the given number of
   * times.
   *
   * @param c_n The number of times to duplicate the character.
   * @param c The character.
   * @return Returns the NULL-terminated string.  It is the caller's
   * responsibility to deallocate it.
   */
  const_storage_pointer dup( size_type c_n, value_type c );

  /**
   * A helper class to convert character position information into its
   * corresponding byte position information.
   */
  struct char2byte {
    size_type const byte_pos;
    size_type const byte_n;

    /**
     * Constructs a %char2byte.
     *
     * @param s A UTF-8 encoded string.
     * @param s_size The number of bytes in the string.
     * @param char_pos The desired character (not byte) position.
     * @param char_n The desired number of characters (not bytes).
     */
    char2byte( const_storage_pointer s, size_type s_size, size_type char_pos,
               size_type char_n ) :
      byte_pos( utf8::byte_pos( s, s_size, char_pos ) ),
      byte_n( byte_pos != utf8::npos ?
        utf8::byte_pos( s + byte_pos, s_size - byte_pos, char_n ) : utf8::npos
      )
    {
    }
  };

  /**
   * A base class for a helper class to convert a character sequence from
   * iterators to a string.  This class factors out code common to all
   * specializations.
   */
  class sequence2string_base {
  public:
    std_string& get() {
      return ss_;
    }
  protected:
    sequence2string_base() { }
    sequence2string_base( std_string const &s ) : ss_( s ) { }
    ~sequence2string_base() { }

    std_string ss_;
  };

  /**
   * The generic template for a class to convert a character sequence from
   * iterators to a string.
   *
   * @tparam InputIterator The type of iterator to read the sequence of
   * characters from.
   * @tparam ValueType The type of character.
   */
  template<
    class InputIterator,
    typename ValueType =
      typename std::iterator_traits<InputIterator>::value_type
  >
  struct sequence2string : sequence2string_base {
  };

  /**
   * Partial specialization of %sequence2string for storage_type (char)
   * characters.
   *
   * @tparam InputIterator The type of iterator to read the sequence of
   * characters from.
   */
  template<class InputIterator>
  struct sequence2string<InputIterator,storage_type> : sequence2string_base {
    sequence2string( InputIterator i, InputIterator j ) :
      sequence2string_base( i, j )
    {
    }
  };

  /**
   * Partial specialization of %sequence2string for value_type (UTF-16)
   * characters.
   *
   * @tparam InputIterator The type of iterator to read the sequence of
   * characters from.
   */
  template<class InputIterator>
  struct sequence2string<InputIterator,value_type> : sequence2string_base {
    sequence2string( InputIterator i, InputIterator j ) {
      while ( i != j ) {
        utf8::encoded_char_type ec;
        size_type const bytes = utf8::encode( *i, ec );
        this->ss_.append( ec, bytes );
        std::advance( i, bytes );
      }
    }
  };

  StringType *s_;
  bool const delete_;
};

////////// inline utf8_string members /////////////////////////////////////////

// UTF8_STRING_ASSIGN_U_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( utf8_string const &s ) {
  return assign( *s.s_ );
}

// UTF8_STRING_ASSIGN_TU_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::assign( utf8_string<StringType2> const &s ) {
  return assign( s.data(), s.size() );
}

// UTF8_STRING_ASSIGN_S_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( StringType const &s ) {
  *s_ = s;
  return *this;
}

// UTF8_STRING_ASSIGN_U_2ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( utf8_string const &s, size_type pos,
                                 size_type n ) {
  return assign( *s.s_, pos, n );
}

// UTF8_STRING_ASSIGN_S_2ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( StringType const &s, size_type pos,
                                 size_type n ) {
  char2byte const b( s.data(), s.size(), pos, n );
  s_->assign( s, b.byte_pos, b.byte_n );
  return *this;
}

// UTF8_STRING_ASSIGN_SS_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( std_string_arg const &s ) {
  *s_ = s;
  return *this;
}

// UTF8_STRING_ASSIGN_SS_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( std_string_arg const &s, size_type pos,
                                 size_type n ) {
  char2byte const b( s.data(), s.size(), pos, n );
  s_->assign( s, b.byte_pos, b.byte_n );
  return *this;
}

// UTF8_STRING_ASSIGN_CSP_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( const_storage_pointer s ) {
  *s_ = s;
  return *this;
}

// UTF8_STRING_ASSIGN_CSP_ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( const_storage_pointer s, size_type n ) {
  s_->assign( s, utf8::byte_pos( s, n ) );
  return *this;
}

// UTF8_STRING_ASSIGN_ST_B_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( size_type n, storage_type c ) {
  s_->assign( n, c );
  return *this;
}

// UTF8_STRING_ASSIGN_ST_VT_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::assign( size_type n, value_type c ) {
  utf8::encoded_char_type ec;
  s_->assign( ec, utf8::encode( c, ec ) );
  return *this;
}

// UTF8_STRING_ASSIGN_2II_X
template<class StringType>
template<class InputIterator> inline utf8_string<StringType>&
utf8_string<StringType>::assign( InputIterator begin, InputIterator end ) {
  sequence2string<InputIterator> sts( begin, end );
  s_->swap( sts.get() );
  return *this;
}

// UTF8_STRING_COMPARE_U_X
template<class StringType> inline int
utf8_string<StringType>::compare( utf8_string const &s ) const {
  return compare( *s.s_ );
}

// UTF8_STRING_COMPARE_TU_X
template<class StringType>
template<class StringType2> inline int
utf8_string<StringType>::compare( utf8_string<StringType2> const &s ) const {
  return compare( s.get() );
}

// UTF8_STRING_COMPARE_S_X
template<class StringType> inline int
utf8_string<StringType>::compare( StringType const &s ) const {
  return s_->compare( s );
}

// UTF8_STRING_COMPARE_SS_X
template<class StringType> inline int
utf8_string<StringType>::compare( std_string_arg const &s ) const {
  return s_->compare( s );
}

// UTF8_STRING_COMPARE_CSP_X
template<class StringType> inline int
utf8_string<StringType>::compare( const_storage_pointer s ) const {
  return s_->compare( s );
}

// UTF8_STRING_COMPARE_2ST_U_X
template<class StringType> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  utf8_string const &s ) const {
  return compare( pos, n, *s.s_ );
}

// UTF8_STRING_COMPARE_2ST_TU_X
template<class StringType>
template<class StringType2> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  utf8_string<StringType2> const &s ) const {
  return compare( pos, n, s.get() );
}

// UTF8_STRING_COMPARE_2ST_S_X
template<class StringType> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  StringType const &s ) const {
  char2byte const b( s_->data(), s_->size(), pos, n );
  return s_->compare( b.byte_pos, b.byte_n, s );
}

// UTF8_STRING_COMPARE_2ST_SS_X
template<class StringType> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  std_string_arg const &s ) const {
  char2byte const b( s_->data(), s_->size(), pos, n );
  return s_->compare( b.byte_pos, b.byte_n, s );
}

// UTF8_STRING_COMPARE_2ST_CSP_X
template<class StringType> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  const_storage_pointer s ) const {
  char2byte const b( s_->data(), s_->size(), pos, n );
  return s_->compare( b.byte_pos, b.byte_n, s );
}

// UTF8_STRING_COMPARE_2ST_U_2ST_X
template<class StringType> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  utf8_string const &s, size_type s_pos,
                                  size_type s_n ) const {
  return compare( pos, n, *s.s_, s_pos, s_n );
}

  // UTF8_STRING_COMPARE_2ST_TU_2ST_X
template<class StringType>
template<class StringType2> inline int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  utf8_string<StringType2> const &s,
                                  size_type s_pos, size_type s_n ) const {
  return compare( pos, n, s.get(), s_pos, s_n );
}

// UTF8_STRING_FIND_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( utf8_string const &s, size_type pos ) const {
  return find( *s.s_, pos );
}

// UTF8_STRING_FIND_TU_ST_X
template<class StringType>
template<class StringType2> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( utf8_string<StringType2> const &s,
                               size_type pos ) const {
  return find( s.data(), pos, s.size() );
}

// UTF8_STRING_RFIND_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( utf8_string const &s, size_type pos ) const {
  return rfind( *s.s_, pos );
}

// UTF8_STRING_FIND_FIRST_OF_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( utf8_string const &s,
                                        size_type pos ) const {
  return find_first_of( *s.s_, pos );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( utf8_string const &s,
                                            size_type pos ) const {
  return find_first_not_of( *s.s_, pos );
}

// UTF8_STRING_FIND_LAST_OF_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( utf8_string const &s,
                                       size_type pos ) const {
  return find_last_of( *s.s_, pos );
}

// UTF8_STRING_FIND_LAST_NOT_OF_U_ST_X
template<class StringType> inline typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( utf8_string const &s,
                                           size_type pos ) const {
  return find_last_not_of( *s.s_, pos );
}

// UTF8_STRING_INSERT_ST_U_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, utf8_string const &s ) {
  return insert( pos, *s.s_ );
}

// UTF8_STRING_INSERT_ST_TU_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos,
                                 utf8_string<StringType2> const &s ) {
  return insert( pos, s.get() );
}

// UTF8_STRING_INSERT_ST_S_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, StringType const &s ) {
  s_->insert( utf8::byte_pos( s_->data(), s_->size(), pos ), s );
  return *this;
}

// UTF8_STRING_INSERT_ST_U_2ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, utf8_string const &s,
                                 size_type s_pos, size_type n ) {
  return insert( pos, *s.s_, s_pos, n );
}

// UTF8_STRING_INSERT_ST_TU_2ST_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos,
                                 utf8_string<StringType2> const &s,
                                 size_type s_pos, size_type n ) {
  return insert( pos, s.get(), s_pos, n );
}

// UTF8_STRING_INSERT_ST_CSP_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, const_storage_pointer s ) {
  s_->insert( utf8::byte_pos( s_->data(), s_->size(), pos ), s );
  return *this;
}

// UTF8_STRING_INSERT_2ST_B_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, size_type n, storage_type c ) {
  s_->insert( utf8::byte_pos( s_->data(), s_->size(), pos ), n, c );
  return *this;
}

// UTF8_STRING_INSERT_I_B_X
template<class StringType> inline typename utf8_string<StringType>::iterator
utf8_string<StringType>::insert( iterator pos, storage_type c ) {
  return iterator( s_->insert( pos.base(), c ) );
}

// UTF8_STRING_INSERT_I_ST_B_X
template<class StringType> inline void
utf8_string<StringType>::insert( iterator pos, size_type n, storage_type c ) {
  s_->insert( pos.base(), n, c );
}

// UTF8_STRING_INSERT_I_2II_X
template<class StringType>
template<class InputIterator> inline void
utf8_string<StringType>::insert( iterator pos, InputIterator begin,
                                 InputIterator end ) {
  s_->insert( pos.base(), sequence2string<InputIterator>( begin, end ) );
}

// UTF8_STRING_REPLACE_2ST_U_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  utf8_string const &s ) {
  return replace( pos, n, *s.s_ );
}

// UTF8_STRING_REPLACE_2ST_TU_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  utf8_string<StringType2> const &s ) {
  return replace( pos, n, s.get() );
}

  // UTF8_STRING_REPLACE_2ST_S_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  StringType const &s ) {
  char2byte const b( s_->data(), s_->size(), pos, n );
  s_->replace( b.byte_pos, b.byte_n, s );
  return *this;
}

// UTF8_STRING_REPLACE_2ST_U_2ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  utf8_string const &s, size_type s_pos,
                                  size_type s_n ) {
  return replace( pos, n, *s.s_, s_pos, s_n );
}

// UTF8_STRING_REPLACE_2ST_TU_2ST_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  utf8_string<StringType2> const &s,
                                  size_type s_pos, size_type s_n ) {
  return replace( pos, n, *s.s_, s_pos, s_n );
}

// UTF8_STRING_REPLACE_2ST_CSP_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  const_storage_pointer s ) {
  char2byte const b( s_->data(), s_->size(), pos, n );
  s_->replace( b.byte_pos, b.byte_n, s );
  return *this;
}

// UTF8_STRING_REPLACE_3ST_B_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n, size_type c_n,
                                  storage_type c ) {
  char2byte const b( s_->data(), s_->size(), pos, n );
  s_->replace( b.byte_pos, b.byte_n, c_n, c );
  return *this;
}

// UTF8_STRING_REPLACE_2I_U_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j,
                                  utf8_string const &s ) {
  return replace( i, j, *s.s_ );
}

// UTF8_STRING_REPLACE_2I_TU_X
template<class StringType>
template<class StringType2> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j,
                                  utf8_string<StringType2> const &s ) {
  return replace( i, j, s.get() );
}

// UTF8_STRING_REPLACE_2I_S_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j,
                                  StringType const &s ) {
  s_->replace( i.base(), j.base(), s );
  return *this;
}

// UTF8_STRING_REPLACE_2I_CSP_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j,
                                  const_storage_pointer s ) {
  s_->replace( i.base(), j.base(), s );
  return *this;
}

// UTF8_STRING_REPLACE_2I_CSP_ST_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j,
                                  const_storage_pointer s, size_type s_n ) {
  s_->replace( i.base(), j.base(), s, utf8::byte_pos( s, s_n ) );
  return *this;
}

// UTF8_STRING_REPLACE_2I_ST_B_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j, size_type n,
                                  storage_type c ) {
  s_->replace( i.base(), j.base(), n, c );
  return *this;
}

// UTF8_STRING_REPLACE_2I_2II_X
template<class StringType>
template<class InputIterator>
inline utf8_string<StringType>&
utf8_string<StringType>::replace( iterator i, iterator j, InputIterator ii,
                                  InputIterator ij ) {
  s_->replace( i.base(), j.base(), sequence2string<InputIterator>( ii, ij ) );
  return *this;
}

// UTF8_STRING_TAKE_U_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::take( utf8_string &s ) {
  return take( *s.s_ );
}

// UTF8_STRING_TAKE_S_X
template<class StringType> inline utf8_string<StringType>&
utf8_string<StringType>::take( StringType &s ) {
  s_->take( s );
  return *this;
}

////////// inline global functions ////////////////////////////////////////////

template<class StringType> inline void
swap( utf8_string<StringType> &i, utf8_string<StringType> &j ) {
  i.swap( j );
}

template<class StringType> inline bool
operator==( utf8_string<StringType> const &s1,
            utf8_string<StringType> const &s2 ) {
  return s1.compare( s2 ) == 0;
}

template<class StringType1,class StringType2> inline bool
operator==( utf8_string<StringType1> const &s1,
            utf8_string<StringType2> const &s2 ) {
  return s1.compare( s2 ) == 0;
}

template<class StringType> inline bool
operator==( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::std_string_arg s2 ) {
  return s1.compare( s2 ) == 0;
}

template<class StringType> inline bool
operator==( typename utf8_string<StringType>::std_string_arg s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) == 0;
}

template<class StringType> inline bool
operator==( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return s1.compare( s2 ) == 0;
}

template<class StringType> inline bool
operator==( typename utf8_string<StringType>::const_storage_pointer s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) == 0;
}

template<class StringType> inline bool
operator==( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return s1.compare( s2 ) == 0;
}

template<class StringType> inline bool
operator==( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) == 0;
}

template<class StringType> inline bool
operator!=( utf8_string<StringType> const &s1,
            utf8_string<StringType> const &s2 ) {
  return !(s1 == s2);
}

template<class StringType1,class StringType2> inline bool
operator!=( utf8_string<StringType1> const &s1,
            utf8_string<StringType2> const &s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::std_string_arg s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( typename utf8_string<StringType>::std_string_arg s1,
            utf8_string<StringType> const &s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( typename utf8_string<StringType>::const_storage_pointer s1,
            utf8_string<StringType> const &s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator!=( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return !(s1 == s2);
}

template<class StringType> inline bool
operator<( utf8_string<StringType> const &s1,
           utf8_string<StringType> const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class StringType1,class StringType2> inline bool
operator<( utf8_string<StringType1> const &s1,
           utf8_string<StringType2> const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class StringType> inline bool
operator<( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::std_string_arg s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class StringType> inline bool
operator<( typename utf8_string<StringType>::std_string_arg s1,
           utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) > 0;
}

template<class StringType> inline bool
operator<( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class StringType> inline bool
operator<( typename utf8_string<StringType>::const_storage_pointer s1,
           utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) > 0;
}

template<class StringType> inline bool
operator<( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class StringType> inline bool
operator<( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) > 0;
}

template<class StringType> inline bool
operator<=( utf8_string<StringType> const &s1,
            utf8_string<StringType> const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class StringType1,class StringType2> inline bool
operator<=( utf8_string<StringType1> const &s1,
            utf8_string<StringType2> const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class StringType> inline bool
operator<=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::std_string_arg s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class StringType> inline bool
operator<=( typename utf8_string<StringType>::std_string_arg s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) >= 0;
}

template<class StringType> inline bool
operator<=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class StringType> inline bool
operator<=( typename utf8_string<StringType>::const_storage_pointer s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) >= 0;
}

template<class StringType> inline bool
operator<=( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class StringType> inline bool
operator<=( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) >= 0;
}

template<class StringType> inline bool
operator>( utf8_string<StringType> const &s1,
           utf8_string<StringType> const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class StringType1,class StringType2> inline bool
operator>( utf8_string<StringType1> const &s1,
           utf8_string<StringType2> const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class StringType> inline bool
operator>( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::std_string_arg s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class StringType> inline bool
operator>( typename utf8_string<StringType>::std_string_arg s1,
           utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) < 0;
}

template<class StringType> inline bool
operator>( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class StringType> inline bool
operator>( typename utf8_string<StringType>::const_storage_pointer s1,
           utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) < 0;
}

template<class StringType> inline bool
operator>( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class StringType> inline bool
operator>( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) < 0;
}

template<class StringType> inline bool
operator>=( utf8_string<StringType> const &s1,
            utf8_string<StringType> const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class StringType1,class StringType2> inline bool
operator>=( utf8_string<StringType1> const &s1,
            utf8_string<StringType2> const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class StringType> inline bool
operator>=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::std_string_arg s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class StringType> inline bool
operator>=( typename utf8_string<StringType>::std_string_arg s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) <= 0;
}

template<class StringType> inline bool
operator>=( utf8_string<StringType> const &s1,
            typename utf8_string<StringType>::const_storage_pointer s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class StringType> inline bool
operator>=( typename utf8_string<StringType>::const_storage_pointer s1,
            utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) <= 0;
}

template<class StringType> inline bool
operator>=( utf8_string<StringType> const &s1, StringType const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class StringType> inline bool
operator>=( StringType const &s1, utf8_string<StringType> const &s2 ) {
  return s2.compare( s1 ) <= 0;
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( utf8_string<StringType> const &s1,
           utf8_string<StringType> const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( *s1.get() + *s2.get() ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::std_string_arg const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( *s1.get() + s2 ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( typename utf8_string<StringType>::std_string_arg const &s1,
           utf8_string<StringType> const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( s1 + *s2.get() ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::const_storage_pointer const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( *s1.get() + s2 ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( typename utf8_string<StringType>::const_storage_pointer const &s1,
           utf8_string<StringType> const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( s1 + *s2.get() ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( utf8_string<StringType> const &s1,
           typename utf8_string<StringType>::storage_type c ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( *s1.get() + c ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( typename utf8_string<StringType>::storage_type c,
           utf8_string<StringType> const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( c + *s2.get() ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( utf8_string<StringType> const &s1, StringType const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( *s1.get() + s2 ) );
}

template<class StringType> inline
utf8_string<typename utf8_string_traits<StringType>::result_type>
operator+( StringType const &s1, utf8_string<StringType> const &s2 ) {
  typedef typename utf8_string_traits<StringType>::result_type result_type;
  return utf8_string<result_type>( new result_type( s1 + *s2.get() ) );
}

template<class StringType> inline std::ostream&
operator<<( std::ostream &os, utf8_string<StringType> const &s ) {
  return os << s.c_str();
}

////////// utf8_stringify /////////////////////////////////////////////////////

/**
 * Turns a StringType into a utf8_string<StringType>.  The specializations
 * exist so utf8_string-ification of a string type that is already a
 * utf8_string will be a no-op.
 */
template<class StringType>
struct utf8_stringify {
  typedef utf8_string<StringType> type;
};

/**
 * Partial specialization for utf8_string<StringType> that simply is its own
 * type.
 */
template<class StringType>
struct utf8_stringify< utf8_string<StringType> > {
  typedef utf8_string<StringType>& type;
};

/**
 * Partial specialization for utf8_string<StringType> const that simply is its
 * own type.
 */
template<class StringType>
struct utf8_stringify< utf8_string<StringType> const > {
  typedef utf8_string<StringType> const& type;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#include "utf8_string.tcc"

#endif /* ZORBA_UTF8_STRING_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
