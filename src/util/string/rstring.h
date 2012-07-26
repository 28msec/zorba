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

#ifndef ZORBA_RSTRING_H
#define ZORBA_RSTRING_H

#include <cstring>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>

#include "rep_proxy.h"
#include "util/cxx_util.h"

namespace zorba {

/**
 * A string class that delegates the underlying string representation and
 * management to a "rep" class.  This class assumes that every character
 * requires the same amount of storage.
 *
 * @tparam RepType The string representation type to use.
 */
template<class RepType>
class rstring {
public:
  typedef typename RepType::allocator_type allocator_type;
  typedef typename RepType::difference_type difference_type;
  typedef typename RepType::size_type size_type;
  typedef typename RepType::traits_type traits_type;

  typedef typename RepType::value_type value_type;
  typedef typename RepType::pointer pointer;
  typedef typename RepType::const_pointer const_pointer;
  typedef typename RepType::reference reference;
  typedef typename RepType::const_reference const_reference;

  typedef typename RepType::iterator iterator;
  typedef typename RepType::const_iterator const_iterator;
  typedef typename RepType::reverse_iterator reverse_iterator;
  typedef typename RepType::const_reverse_iterator const_reverse_iterator;

  typedef RepType rep_type;
  typedef typename RepType::result_rep_type result_rep_type;
  typedef rstring<result_rep_type> result_type;

  /**
   * The std::string type corresponding to this string type.
   */
  typedef std::basic_string<value_type,traits_type,allocator_type> std_string;

  /**
   * The special value used to denote either (a) the maximum possible number as
   * input or (b) "not found" as a result.
   */
  static size_type const npos = static_cast<size_type>( -1 );

  ////////// constructors & destructor ////////////////////////////////////////

  // RSTRING_C_X
  /**
   * Constructs an empty string.
   */
  rstring();

  // RSTRING_C_A_X
  /**
   * Constructs an empty string.
   *
   * @param a The allocator to use.
   */
  explicit rstring( allocator_type const &a );

  // RSTRING_C_RS_X
  /**
   * Copy constructs a new string from an existing string.
   *
   * @param s The string to copy from.
   */
  rstring( rstring const &s );

  // RSTRING_C_TRS_X
  /**
   * Copy constructs a new string from an existing string.
   *
   * @param s The string to copy from.
   */
  template<class RepType2>
  rstring( rstring<RepType2> const &s );

  // RSTRING_C_RS_2ST_X
  /**
   * Copy constructs a new string from a substring of an existing string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   */
  rstring( rstring const &s, size_type pos, size_type n = npos );

  // RSTRING_C_TRS_2ST_X
  /**
   * Copy constructs a new string from a substring of an existing string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   */
  template<class RepType2>
  rstring( rstring<RepType2> const &s, size_type pos, size_type n = npos );

  // RSTRING_C_RS_2ST_A_X
  /**
   * Copy constructs a new string from a substring of an existing string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   * @param a The allocator to use.
   */
  rstring( rstring const &s, size_type pos, size_type n,
           allocator_type const &a );

  // RSTRING_C_TRS_2ST_A_X
  /**
   * Copy constructs a new string from a substring of an existing string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   * @param a The allocator to use.
   */
  template<class RepType2>
  rstring( rstring<RepType2> const &s, size_type pos, size_type n,
           allocator_type const &a );

  // RSTRING_C_SS_X
  /**
   * Constructs a new string from an existing std::string.
   *
   * @param s The string to copy from.
   */
  rstring( std_string const &s );

  // RSTRING_C_SS_2ST_X
  /**
   * Constructs a new string from a substring of an existing std::string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   */
  rstring( std_string const &s, size_type pos, size_type n = npos );

  // RSTRING_C_SS_2ST_A_X
  /**
   * Constructs a new string from a substring of an existing std::string.
   *
   * @param s The string to copy from.
   * @param pos The starting position within \a s.
   * @param n The number of characters of \a s to copy.
   * @param a The allocator to use.
   */
  rstring( std_string const &s, size_type pos, size_type n,
           allocator_type const &a );

  // RSTRING_C_CP_A_X
  /**
   * Constructs a string from the given C string.
   *
   * @param s The null-terminated C string.
   * @param a The allocator to use.
   */
  rstring( const_pointer s, allocator_type const &a = allocator_type() );

  // RSTRING_C_P_A_X
  /**
   * Constructs a string from the given C string.
   * This constructor is an extension to the std::string API.
   *
   * @param s The null-terminated C string.
   * @param a The allocator to use.
   */
  rstring( pointer s, allocator_type const &a = allocator_type() );

  // RSTRING_C_CP_ST_A_X
  /**
   * Constructs a string from the given C string.
   *
   * @param s The C string.
   * @param n The number of characters of \a s to copy.
   * @param a The allocator to use.
   */
  rstring( const_pointer s, size_type n,
           allocator_type const &a = allocator_type() );

  // RSTRING_C_P_ST_A_X
  /**
   * Constructs a string from the given C string.
   * This constructor is an extension to the std::string API.
   *
   * @param s The null-terminated C string.
   * @param n The number of characters of \a s to copy.
   * @param a The allocator to use.
   */
  rstring( pointer s, size_type n, allocator_type const &a = allocator_type() );

  // RSTRING_C_ST_VT_A_X
  /**
   * Constructs a new string as \a n copies of \a c.
   *
   * @param n The number of copies of \a c.
   * @param c The character to repeat.
   * @param a The allocator to use.
   */
  rstring( size_type n, value_type c,
           allocator_type const &a = allocator_type() );

  // RSTRING_C_2II_A_X
  /**
   * Constructs a string from a range of characters [i,j).
   *
   * @tparam InputIterator The input iterator type.
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param a The allocator to use.
   */
  template<class InputIterator>
  rstring( InputIterator i, InputIterator j,
           allocator_type const &a = allocator_type() );

  // RSTRING_D_X
  /**
   * Destructs this string.
   */
  ~rstring() {
    rep().dispose( get_allocator() );
  }

  ////////// assignment ///////////////////////////////////////////////////////

  /**
   * Assigns another string to this string.
   *
   * @param s The string to assign from.
   * @return Returns this string.
   */
  rstring& operator=( rstring const &s ) {
    return assign( s );
  }

  /**
   * Assigns another string to this string.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to assign from.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& operator=( rstring<RepType2> const &s ) {
    return assign( s );
  }

  /**
   * Assigns a std::string to this string.
   *
   * @param s The string to assign from.
   * @return Returns this string.
   */
  rstring& operator=( std_string const &s ) {
    return assign( s );
  }

  /**
   * Assigns a C string to this string.
   *
   * @param s The null-terminated C string to assign from.
   * @return Returns this string.
   */
  rstring& operator=( const_pointer s ) {
    return assign( s );
  }

  /**
   * Assigns a C string to this string.
   * This operator is an extension to the std::string API.
   *
   * @param s The C string to assign from.
   * @return Returns this string.
   */
  rstring& operator=( pointer s ) {
    return assign( s );
  }

  /**
   * Assigns a character to this string.
   *
   * @param c The character to assign.
   * @return Returns this string.
   */
  rstring& operator=( value_type c ) {
    return assign( 1, c );
  }

  ////////// properties ///////////////////////////////////////////////////////

  /**
   * Gets the capacity of this string.
   *
   * @return Returns said capacity.
   */
  size_type capacity() const {
    return rep().capacity();
  }

  /**
   * Checks whether the string is empty.
   *
   * @return Returns \c true only if it is.
   */
  bool empty() const {
    return size() == 0;
  }

  /**
   * Gets the alloctator used by this string.
   *
   * @return Returns said allocator.
   */
  allocator_type get_allocator() const {
    return data_;
  }

  /**
   * Gets the number of characters in this string.
   *
   * @return Returns said number.
   */
  size_type length() const {
    return rep().length();
  }

  /**
   * Gets the number of characters in this string.
   * (This is a synonym for length().)
   *
   * @return Returns said number.
   */
  size_type size() const {
    return length();
  }

  /**
   *
   */
  bool is_shared() const {
    return rep().is_shared();
  }

  ////////// character access /////////////////////////////////////////////////

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is bounds-checked.
   * @return Returns said character as an l-value.
   * @throw std::out_of_range if \a pos >= \c size().
   */
  reference at( size_type pos ) {
    make_unsharable_if_necessary();
    return data()[ check_pos( pos, "at" ) ];
  }

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is bounds-checked.
   * @return Returns said character as an r-value.
   */
  value_type at( size_type pos ) const {
    return data()[ check_pos( pos, "at" ) ];
  }

#define DISABLE_NON_CONST_OPERATOR_BRACKETS 1
#if DISABLE_NON_CONST_OPERATOR_BRACKETS
  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is not bounds-checked.
   * @return Returns said character as an l-value.
   */
  reference operator[]( size_type pos ) {
    make_unsharable_if_necessary();
    return data()[ pos ];
  }
#endif

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is not bounds-checked.
   * @return Returns said character as an r-value.
   */
  const_reference operator[]( size_type pos ) const {
    return data()[ pos ];
  }

  ////////// append ///////////////////////////////////////////////////////////

  // RSTRING_APPEND_RS_X
  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return Returns this string.
   */
  rstring& append( rstring const &s );

  // RSTRING_APPEND_TRS_X
  /**
   * Appends the given string to this string.
   *
   * @tparam RepType2 The string representation of \a s.
   * @param s The string to append.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& append( rstring<RepType2> const &s );

  // RSTRING_APPEND_RS_2ST_X
  /**
   * Appends a substring of the given string to this string.
   *
   * @param s The string to append.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to append.
   * @return Returns this string.
   */
  rstring& append( rstring const &s, size_type s_pos, size_type s_n );

  // RSTRING_APPEND_TRS_2ST_X
  /**
   * Appends a substring of the given string to this string.
   *
   * @tparam RepType2 The string representation of \a s.
   * @param s The string to append.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to append.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& append( rstring<RepType2> const &s, size_type s_pos, size_type s_n );

  // RSTRING_APPEND_SS_X
  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return Returns this string.
   */
  rstring& append( std_string const &s );

  // RSTRING_APPEND_SS_2ST_X
  /**
   * Appends a substring of the given string to this string.
   *
   * @param s The string to append.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to append.
   * @return Returns this string.
   */
  rstring& append( std_string const &s, size_type s_pos, size_type s_n );

  // RSTRING_APPEND_CP_X
  /**
   * Appends the given C string to this string.
   *
   * @param s The null-terminated C string to append.
   * @return Returns this string.
   */
  rstring& append( const_pointer s );

  // RSTRING_APPEND_CP_ST_X
  /**
   * Appends a substring of the given C string to this string.
   *
   * @param s The C string to append.
   * @param s_n The number of characters of \a s to append.
   * @return Returns this string.
   */
  rstring& append( const_pointer s, size_type s_n );

  // RSTRING_APPEND_ST_VT_X
  /**
   * Appends \a n copies of \a c to this string.
   *
   * @param n The number of copies of \a c to append.
   * @param c The character to append.
   * @return Returns this string.
   */
  rstring& append( size_type n, value_type c );

  /**
   * Appends the given character to this string.
   *
   * @param c The character to append.
   */
  void push_back( value_type c );

  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return Returns this string.
   */
  rstring& operator+=( rstring const &s ) {
    return append( s );
  }

  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& operator+=( rstring<RepType2> const &s ) {
    return append( s );
  }

  /**
   * Appends the given std::string to this string.
   *
   * @param s The string to append.
   * @return Returns this string.
   */
  rstring& operator+=( std_string const &s ) {
    return append( s.data(), s.size() );
  }

  /**
   * Appends the given C string to this string.
   *
   * @param s The null-terminated C string to append.
   * @return Returns this string.
   */
  rstring& operator+=( const_pointer s ) {
    return append( s );
  }

  /**
   * Appends the given character to this string.
   *
   * @param s The character to append.
   * @return Returns this string.
   */
  rstring& operator+=( value_type c ) {
    return append( 1, c );
  }

  ////////// assign ///////////////////////////////////////////////////////////

  // RSTRING_ASSIGN_RS_X
  /**
   * Assigns another string to this string.
   *
   * @param s The string to assign from.
   * @return Returns this string.
   */
  rstring& assign( rstring const &s );

  // RSTRING_ASSIGN_TRS_X
  /**
   * Assigns another string to this string.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to assign from.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& assign( rstring<RepType2> const &s ) {
    return assign( s.data(), s.size() );
  }

  // RSTRING_ASSIGN_RS_2ST_X
  /**
   * Assigns a substring of a string to this string.
   *
   * @param s The string to assign from.
   * @param pos The starting position within \a s.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  rstring& assign( rstring const &s, size_type pos, size_type n );

  // RSTRING_ASSIGN_RS_2ST_X
  /**
   * Assigns a substring of a string to this string.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to assign from.
   * @param pos The starting position within \a s.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& assign( rstring<RepType2> const &s, size_type pos, size_type n ) {
    return assign( s.data(), s.size() );
  }

  // RSTRING_ASSIGN_SS_X
  /**
   * Assigns a std::string to this string.
   *
   * @param s The string to assign from.
   * @return Returns this string.
   */
  rstring& assign( std_string const &s );

  // RSTRING_ASSIGN_SS_2ST_X
  /**
   * Assigns a substring of a std::string to this string.
   *
   * @param s The string to assign from.
   * @param pos The starting position within \a s.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  rstring& assign( std_string const &s, size_type pos, size_type n );

  // RSTRING_ASSIGN_CP_X
  /**
   * Assigns a C to this string.
   *
   * @param s The null-termianted C string to assign from.
   * @return Returns this string.
   */
  rstring& assign( const_pointer s );

  // RSTRING_ASSIGN_P_X
  /**
   * Assigns a C to this string.
   * This function is an extension to the std::string API.
   *
   * @param s The string to assign from.
   * @return Returns this string.
   */
  rstring& assign( pointer s );

  // RSTRING_ASSIGN_CP_ST_X
  /**
   * Assigns a substring of a C to this string.
   *
   * @param s The C string to assign from.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  rstring& assign( const_pointer s, size_type n );

  // RSTRING_ASSIGN_P_ST_X
  /**
   * Assigns part of a C to this string.
   * This function is an extension to the std::string API.
   *
   * @param s The string to assign from.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  rstring& assign( pointer s, size_type n );

  // RSTRING_ASSIGN_ST_VT_X
  /**
   * Assigns \a n copies of a character to this string.
   *
   * @param n The number of copies of \a c to assign.
   * @param c The character.
   * @return Returns this string.
   */
  rstring& assign( size_type n, value_type c );

  // RSTRING_ASSIGN_2II_X
  /**
   * Assigns characters from a range of characters [i,j).
   *
   * @tparam InputIterator The input iterator type.
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   */
  template<class InputIterator>
  rstring& assign( InputIterator begin, InputIterator end );

  // RSTRING_CONSTRUCT_CP_ST_X
  /**
   * Assigns a substring of a C to this string.
   * This function is an extension to the std::string API.
   *
   * @param s The C string to assign from.
   * @param n The number of characters to assign.
   * @return Returns this string.
   */
  rstring& wrap_memory( const_pointer s, size_type n );

  // RSTRING_TAKE_RS_X
  /**
   * "Takes" (transfers ownership from) the given string.
   * This function is an extension to the std::string API.
   *
   * @param s The string to take from.
   * @return Returns this string.
   */
  rstring& take( rstring &s );

  ////////// compare //////////////////////////////////////////////////////////

  // RSTRING_COMPARE_RS_X
  /**
   * Compares this string against another.
   *
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( rstring const &s ) const;

  // RSTRING_COMPARE_TRS_X
  /**
   * Compares this string against another.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  template<class RepType2>
  int compare( rstring<RepType2> const &s ) const;

  // RSTRING_COMPARE_SS_X
  /**
   * Compares this string against another.
   *
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( std_string const &s ) const;

  // RSTRING_COMPARE_SS_X
  /**
   * Compares this string against a C string.
   *
   * @param s The null-terminated C string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( const_pointer s ) const;

  // RSTRING_COMPARE_2ST_RS_X
  /**
   * Compares a substring of this string against another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, rstring const &s ) const;

  // RSTRING_COMPARE_2ST_TRS_X
  /**
   * Compares a substring of this string against another.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  template<class RepType2>
  int compare( size_type pos, size_type n, rstring<RepType2> const &s ) const;

  // RSTRING_COMPARE_2ST_SS_X
  /**
   * Compares a substring of this string against another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, std_string const &s ) const;

  // RSTRING_COMPARE_2ST_CP_X
  /**
   * Compares a substring of this string against a C string.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The null-terminated C string to compare to.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, const_pointer s ) const;

  // RSTRING_COMPARE_2ST_RS_2ST_X
  /**
   * Compares a substring of this string against a substring of another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @param s_pos The starting position within \a s.
   * @param s_n The number of characters of \s to compare.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, rstring const &s, size_type s_pos,
               size_type s_n ) const;

  // RSTRING_COMPARE_2ST_TRS_2ST_X
  /**
   * Compares a substring of this string against a substring of another.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @param s_pos The starting position within \a s.
   * @param s_n The number of characters of \s to compare.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  template<class RepType2>
  int compare( size_type pos, size_type n, rstring<RepType2> const &s,
               size_type s_pos, size_type s_n ) const;

  // RSTRING_COMPARE_2ST_SS_2ST_X
  /**
   * Compares a substring of this string against a substring of another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @param s_pos The starting position within \a s.
   * @param s_n The number of characters of \s to compare.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, std_string const &s,
               size_type s_pos, size_type s_n ) const;

  // RSTRING_COMPARE_2ST_CP_ST_X
  /**
   * Compares a substring of this string against a C string.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The C string to compare to.
   * @param s_n The number of characters of \s to compare.
   * @return Returns -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, const_pointer s,
               size_type s_n ) const;

  ////////// clear/erase //////////////////////////////////////////////////////

  /**
   * Erases the string making it empty.
   */
  void clear() {
    mutate( 0, size(), 0 );
  }

  // RSTRING_ERASE_2ST_X
  /**
   * Erases the given number of characters starting at the given position.
   *
   * @param pos The position of the first character to erase.
   * @param n The number of characters to erase.
   * @return Returns a reference to this string.
   * @throw std::out_of_range if \a pos is beyond the end of the string.
   */
  rstring& erase( size_type pos = 0, size_type n = npos );

  // RSTRING_ERASE_I_X
  /**
   * Erases the character at the given iterator's position.
   *
   * @param i The iterator marking the position of the character to erase.
   * @return Returns a new iterator marking the same position (i.e., what
   * becomes the next character).
   */
  iterator erase( iterator i );

  // RSTRING_ERASE_2I_X
  /**
   * Erases a range of characters [i,j).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @return Returns a new iterator marking the same position as \a i.
   */
  iterator erase( iterator i, iterator j );

  ////////// find /////////////////////////////////////////////////////////////

  // RSTRING_FIND_RS_ST_X
  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type find( rstring const &s, size_type pos = 0 ) const;

  // RSTRING_FIND_TRS_ST_X
  /**
   * Searches this string for the given string starting at the given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  template<class RepType2>
  size_type find( rstring<RepType2> const &s, size_type pos = 0 ) const;

  // RSTRING_FIND_SS_ST_X
  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type find( std_string const &s, size_type pos = 0 ) const;

  // RSTRING_FIND_CP_ST_X
  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The null-terminated C string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type find( const_pointer s, size_type pos = 0 ) const;

  // RSTRING_FIND_CP_2ST_X
  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The C string to search for.
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type find( const_pointer s, size_type pos, size_type n ) const;

  // RSTRING_FIND_VT_ST_X
  /**
   * Searches this string for the given character starting at the given
   * position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a c or \c npos if not found.
   */
  size_type find( value_type c, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_OF_RS_ST_X
  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_first_of( rstring const &s, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_OF_TRS_ST_X
  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  template<class RepType2>
  size_type find_first_of( rstring<RepType2> const &s,
                           size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_OF_SS_ST_X
  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_first_of( std_string const&, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  // RSTRING_FIND_FIRST_OF_CP_ST_X
  size_type find_first_of( const_pointer s, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_OF_CP_2ST_X
  /**
   * Searches this string for any one of the first \a s_n characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \s to consider.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_first_of( const_pointer s, size_type pos,
                           size_type s_n ) const;

  // RSTRING_FIND_FIRST_OF_VT_ST_X
  /**
   * Searches this string for the given character starting at the given
   * position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a c or \c npos if not found.
   */
  size_type find_first_of( value_type c, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_NOT_OF_RS_ST_X
  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a non-matching character or \c npos if not
   * found.
   */
  size_type find_first_not_of( rstring const&, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_NOT_OF_TRS_ST_X
  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a non-matching character or \c npos if not
   * found.
   */
  template<class RepType2>
  size_type find_first_not_of( rstring<RepType2> const &s,
                               size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_NOT_OF_SS_ST_X
  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a non-matching character or \c npos if not
   * found.
   */
  size_type find_first_not_of( std_string const&, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_NOT_OF_CP_ST_X
  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a non-matching character or \c npos if not
   * found.
   */
  size_type find_first_not_of( const_pointer s, size_type pos = 0 ) const;

  // RSTRING_FIND_FIRST_NOT_OF_CP_2ST_X
  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters to consider.
   * @return Returns the offset of a non-matching character or \c npos if not
   * found.
   */
  size_type find_first_not_of( const_pointer s, size_type pos,
                               size_type s_n ) const;

  // RSTRING_FIND_FIRST_NOT_OF_VT_ST_X
  /**
   * Searches this string for any character except the given character starting
   * at the given position.
   *
   * @param c The character not to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of any character except \a c or \c npos if not
   * found.
   */
  size_type find_first_not_of( value_type c, size_type pos = 0 ) const;

  // RSTRING_FIND_LAST_OF_RS_ST_X
  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_of( rstring const&, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_OF_TRS_ST_X
  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  template<class RepType2>
  size_type find_last_of( rstring<RepType2> const &s,
                          size_type pos = npos ) const;

  // RSTRING_FIND_LAST_OF_SS_ST_X
  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_of( std_string const&, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_OF_CP_ST_X
  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_of( const_pointer s, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_OF_CP_2ST_X
  /**
   * Searches this string backwards for any one of the first \a s_n characters
   * in \a s starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \s to consider.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_of( const_pointer s, size_type pos, size_type s_n ) const;

  // RSTRING_FIND_LAST_OF_VT_ST_X
  /**
   * Searches this string backwards for the given character starting at the
   * given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a c or \c npos if not found.
   */
  size_type find_last_of( value_type c, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_NOT_OF_RS_ST_X
  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_not_of( rstring const&, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_NOT_OF_TRS_ST_X
  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  template<class RepType2>
  size_type find_last_not_of( rstring<RepType2> const &s,
                              size_type pos = npos ) const;

  // RSTRING_FIND_LAST_NOT_OF_SS_ST_X
  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_not_of( std_string const&, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_NOT_OF_CP_ST_X
  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_not_of( const_pointer s, size_type pos = npos ) const;

  // RSTRING_FIND_LAST_NOT_OF_CP_2ST_X
  /**
   * Searches this string backwards for any one of the first \a s_n characters
   * not in \a s starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \s to consider.
   * @return Returns the offset of a matching character or \c npos if not
   * found.
   */
  size_type find_last_not_of( const_pointer s, size_type pos,
                              size_type s_n ) const;

  // RSTRING_FIND_LAST_NOT_OF_VT_ST_X
  /**
   * Searches this string backwards for any character except the given
   * character starting at the given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of any character except \a c or \c npos if not
   * found.
   */
  size_type find_last_not_of( value_type c, size_type pos = npos ) const;

  // RSTRING_RFIND_RS_ST_X
  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type rfind( rstring const &s, size_type pos = npos ) const;

  // RSTRING_RFIND_TRS_ST_X
  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  template<class RepType2>
  size_type rfind( rstring<RepType2> const &s, size_type pos = npos ) const;

  // RSTRING_RFIND_SS_ST_X
  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type rfind( std_string const &s, size_type pos = npos ) const;

  // RSTRING_RFIND_CP_ST_X
  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @param s The null-terminated C string to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type rfind( const_pointer s, size_type pos = npos ) const;

  // RSTRING_RFIND_CP_2ST_X
  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @param s The C string to search for.
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @return Returns the offset of \a s or \c npos if not found.
   */
  size_type rfind( const_pointer s, size_type pos, size_type s_n ) const;

  // RSTRING_RFIND_VT_ST_X
  /**
   * Searches this string backwards for the given character starting at the
   * given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return Returns the offset of \a c or \c npos if not found.
   */
  size_type rfind( value_type c, size_type pos = npos ) const;

  ////////// insert ///////////////////////////////////////////////////////////

  // RSTRING_INSERT_ST_RS_X
  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The string to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, rstring const &s );

  // RSTRING_INSERT_ST_TRS_X
  /**
   * Inserts the given string into this string at the given position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param pos The position within this string to insert at.
   * @param s The string to insert.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& insert( size_type pos, rstring<RepType2> const &s );

  // RSTRING_INSERT_ST_SS_X
  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The string to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, std_string const &s );

  // RSTRING_INSERT_ST_CP_X
  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, const_pointer s );

  // RSTRING_INSERT_ST_RS_2ST_X
  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_pos The starting position within \a s.
   * @param s_n The numer of characters of \a s to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, rstring const &s, size_type s_pos,
                   size_type s_n );

  // RSTRING_INSERT_ST_TRS_2ST_X
  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_pos The starting position within \a s.
   * @param s_n The numer of characters of \a s to insert.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& insert( size_type pos, rstring<RepType2> const &s, size_type s_pos,
                   size_type s_n );

  // RSTRING_INSERT_ST_SS_2ST_X
  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_pos The starting position within \a s.
   * @param s_n The numer of characters of \a s to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, std_string const &s, size_type s_pos,
                   size_type s_n );

  // RSTRING_INSERT_ST_CP_ST_X
  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_n The numer of characters of \a s to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, const_pointer s, size_type s_n );

  // RSTRING_INSERT_2ST_VT_X
  /**
   * Inserts \a n copies of \a c at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param n The number of copies of \a c to insert.
   * @param c The character to insert.
   * @return Returns this string.
   */
  rstring& insert( size_type pos, size_type n, value_type c );

  // RSTRING_INSERT_I_VT_X
  /**
   * Inserts the given character into this string at the given position.
   *
   * @param pos The iterator marking the position within this string to insert
   * at.
   * @param The character to insert.
   * @return Returns an iterator positioned at the newly inserted character.
   */
  iterator insert( iterator pos, value_type c );

  // RSTRING_INSERT_I_ST_VT_X
  /**
   * Inserts \a n copies of \a c into this string at the given position.
   *
   * @param pos The iterator marking the position within this string to insert
   * at.
   * @param n The number of copies of \a c to insert.
   * @param c The character to insert.
   */
  void insert( iterator pos, size_type n, value_type c );

  // RSTRING_INSERT_I_2II_X
  /**
   * Inserts the range of characters [i,j) into this string at the given
   * position.
   *
   * @tparam InputIterator The input iterator type.
   * @param pos The iterator marking the position within this string to insert
   * at.
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   */
  template<class InputIterator>
  void insert( iterator pos, InputIterator i, InputIterator j );

  ////////// replace //////////////////////////////////////////////////////////

  // RSTRING_REPLACE_2ST_RS_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, rstring const &s );

  // RSTRING_REPLACE_2ST_TRS_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @tparam RepType2 The representation type of \a s.
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& replace( size_type pos, size_type n, rstring<RepType2> const &s );

  // RSTRING_REPLACE_2ST_SS_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, std_string const &s );

  // RSTRING_REPLACE_2ST_CP_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The null-terminated replacement C string.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, const_pointer s );

  // RSTRING_REPLACE_2ST_RS_2ST_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to use.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, rstring const &s,
                    size_type s_pos, size_type s_n );

  // RSTRING_REPLACE_2ST_RS_2ST_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @tparam RepType2 The string representation of \a s.
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to use.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& replace( size_type pos, size_type n, rstring<RepType2> const &s,
                    size_type s_pos, size_type s_n );

  // RSTRING_REPLACE_2ST_SS_2ST_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to use.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, std_string const &s,
                    size_type s_pos, size_type s_n );

  // RSTRING_REPLACE_2ST_CP_ST_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement C string.
   * @param s_n The number of characters of \a s to use.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, const_pointer s,
                    size_type s_n );

  // RSTRING_REPLACE_3ST_VT_X
  /**
   * Replaces \a n characters of this string starting at the given position
   * with \a c_n copies of \a c.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param c_n The number of copies of \c to replace with.
   * @param c The character to replace with.
   * @return Returns this string.
   */
  rstring& replace( size_type pos, size_type n, size_type c_n, value_type c );

  // RSTRING_REPLACE_2I_RS_X
  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement string.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, rstring const &s );

  // RSTRING_REPLACE_2I_TRS_X
  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @tparam RepType2 The string representation of \a s.
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement string.
   * @return Returns this string.
   */
  template<class RepType2>
  rstring& replace( iterator i, iterator j, rstring<RepType2> const &s );

  // RSTRING_REPLACE_2I_SS_X
  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement string.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, std_string const &s );

  // RSTRING_REPLACE_2I_CP_X
  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The null-terminated replacement C string.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, const_pointer s );

  // RSTRING_REPLACE_2I_CP_ST_X
  /**
   * Replaces the range of characters [i,j) of this string with a substring of
   * the given string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement C string.
   * @param s_n The number of characters of \a s to use.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, const_pointer s, size_type s_n );

  // RSTRING_REPLACE_2I_ST_VT_X
  /**
   * Replaces the range of characters [i,j) of this string with \a c_n copies
   * of \a c.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param c_n The number of copies of \c to replace with.
   * @param c The character to replace with.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, size_type n, value_type c );

  // RSTRING_REPLACE_2I_2II_X
  /**
   * Replaces the range of characters [i,j) of this string with the range of
   * characters [ii,ij).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param ii The iterator marking the first character of the range.
   * @param ij The iterator marking one past the last character of the range.
   * @return Returns this string.
   */
  template<class InputIterator>
  rstring& replace( iterator i, iterator j, InputIterator ii,
                    InputIterator ij );
  // TODO: needs implementation

  // RSTRING_REPLACE_2I_2CP_X
  /**
   * Replaces the range of characters [i,j) of this string with the range of
   * characters [si,sj).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param si The iterator marking the first character of the range.
   * @param sj The iterator marking one past the last character of the range.
   * @return Returns this string.
   */
  rstring& replace( iterator i, iterator j, const_pointer si,
                    const_pointer sj );

  ////////// iterators ////////////////////////////////////////////////////////

  /**
   * Returns a read/write iterator positioned at the first character of the
   * string.
   * 
   * @return Returns said iterator.
   */
  iterator begin() {
    make_unsharable_if_necessary();
    return iterator( data() );
  }

  /**
   * Returns a read-only iterator positioned at the first character of the
   * string.
   * 
   * @return Returns said iterator.
   */
  const_iterator begin() const {
    return const_iterator( data() );
  }

  /**
   * Returns a read/write iterator positioned at one past the last character of
   * the string.
   * 
   * @return Returns said iterator.
   */
  iterator end() {
    make_unsharable_if_necessary();
    return iterator( data() + size() );
  }

  /**
   * Returns a read-only iterator positioned at one past the last character of
   * the string.
   * 
   * @return Returns said iterator.
   */
  const_iterator end() const {
    return const_iterator( data() + size() );
  }

  /**
   * Returns a read/write reverse iterator positioned at the first character of
   * the reversed string.
   * 
   * @return Returns said iterator.
   */
  reverse_iterator rbegin() {
    return reverse_iterator( end() );
  }

  /**
   * Returns a read-only reverse iterator positioned at the first character of
   * the reversed string.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rbegin() const {
    return const_reverse_iterator( end() );
  }

  /**
   * Returns a read/write reverse iterator positioned at one past the last
   * character of the reversed string.
   * 
   * @return Returns said iterator.
   */
  reverse_iterator rend() {
    return reverse_iterator( begin() );
  }

  /**
   * Returns a read-only reverse iterator positioned at one past the last
   * character of the reversed string.
   * 
   * @return Returns said iterator.
   */
  const_reverse_iterator rend() const {
    return const_reverse_iterator( begin() );
  }

  ////////// miscellaneous ////////////////////////////////////////////////////

  // RSTRING_COPY_P_2ST_X
  /**
   * Copies a substring to a C string buffer.
   *
   * @param buf The buffer to copy into.
   * @param n The number of characters to copy.
   * It's the caller's responsibility to ensure that the size of \a buf <= \a
   * n.
   * @param pos The position of the first character to copy.
   * @return Returns the number of characters actually copied.
   * @throw std::out_of_range if \a pos >= size().
   */
  size_type copy( pointer buf, size_type n, size_type pos = 0 ) const;

  /**
   * Gets a pointer to a null-terminated array of characters representing the
   * string's contents.
   *
   * @return Returns said pointer.
   * @see data()
   */
  const_pointer c_str() const {
    return data();
  }

  /**
   * Gets a pointer to the raw character data comprising the string, not
   * necessarily null-terminated.
   *
   * @return Returns said pointer.
   * @see c_str()
   */
  pointer data() {
    return rep().data();
  }

  /**
   * Gets a pointer to the raw character data comprising the string, not
   * necessarily null-terminated.
   *
   * @return Returns said pointer.
   * @see c_str()
   */
  const_pointer data() const {
    return rep().data();
  }

  /**
   * Attemts to pre-allocate enough memory to contain the given number of
   * bytes.
   *
   * @param n The number of bytes.
   */
  void reserve( size_type n ) {
     rep().reserve( n, get_allocator() );
  }

  // RSTRING_RESIZE_ST_VT_X
  /**
   * Resizes the string to the given number of characters.
   * If the number < size(), the string will be truncated;
   * if the number > size(), the string will be extended
   * and the new elements will be set to \a c.
   *
   * @param n The number of characters.
   * @param c Characters to fill any new positions.
   */
  void resize( size_type n, value_type c = value_type() );

  /**
   * Gets a \c std::string equivalent of this string.
   * (There intentionally is no <code>operator std::string() const</code> since
   * its convenient use would mask the expense of creating a new \c
   * std::string.)
   * This function is an extension to the std::string API.
   *
   * @return Returns said \c std::string.
   */
  std_string str() const {
    return std_string( data(), size() );
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
    return result_type(
      data() + check_pos( pos, "substr" ), limit_n( pos, n )
    );
  }

  // RSTRING_SWAP_RS_X
  /**
   * Swaps the contents of this string with another.
   * This is an O(1) operation.
   *
   * @param s The string to swap with.
   */
  void swap( rstring &s );

  ////////// friends //////////////////////////////////////////////////////////

  /**
   * Concatenates two strings.
   *
   * @param s1 The first string.
   * @param s2 The second string.
   * @return Returns a new string having a value of \a s1 followed by \a s2.
   */
  friend result_type operator+( rstring const &s1, rstring const &s2 ) {
    result_type result;
    result.append_safe( s1.data(), s1.size(), s2.data(), s2.size() );
    return result;
  }

  /**
   * Concatenates a string and a std::string.
   *
   * @param s1 The first string.
   * @param s2 The second string.
   * @return Returns a new string having a value of \a s1 followed by \a s2.
   */
  friend result_type operator+( rstring const &s1, std_string const &s2 ) {
    result_type result;
    result.append_safe( s1.data(), s1.size(), s2.data(), s2.size() );
    return result;
  }

  /**
   * Concatenates a std::string and a string.
   *
   * @param s1 The first string.
   * @param s2 The second string.
   * @return Returns a new string having a value of \a s1 followed by \a s2.
   */
  friend result_type operator+( std_string const &s1, rstring const &s2 ) {
    result_type result;
    result.append_safe( s1.data(), s1.size(), s2.data(), s2.size() );
    return result;
  }

  /**
   * Concatenates a string and a C string.
   *
   * @param s1 The first string.
   * @param s2 The second string.
   * @return Returns a new string having a value of \a s1 followed by \a s2.
   */
  friend result_type operator+( rstring const &s1, const_pointer s2 ) {
    result_type result;
    result.append_safe( s1.data(), s1.size(), s2, traits_type::length( s2 ) );
    return result;
  }

  /**
   * Concatenates a C string and a string.
   *
   * @param s1 The first string.
   * @param s2 The second string.
   * @return Returns a new string having a value of \a s1 followed by \a s2.
   */
  friend result_type operator+( const_pointer s1, rstring const &s2 ) {
    result_type result;
    result.append_safe( s1, traits_type::length( s1 ), s2.data(), s2.size() );
    return result;
  }

  /**
   * Concatenates a string and a character.
   *
   * @param s The string.
   * @param c The character.
   * @return Returns a new string having a value of \a s followed by \a c.
   */
  friend result_type operator+( rstring const &s, value_type c ) {
    result_type result;
    result.append_safe( s.data(), s.size(), &c, 1 );
    return result;
  }

  /**
   * Concatenates a character and a string.
   *
   * @param c The character.
   * @param s The string.
   * @return Returns a new string having a value of \a c followed by \a s.
   */
  friend result_type operator+( value_type c, rstring const &s ) {
    result_type result;
    result.append_safe( &c, 1, s.data(), s.size() );
    return result;
  }

private: //////////////////////////////////////////////////////////////////////

  typedef rstring_classes::rep_proxy<RepType> rep_proxy_type;

  // Use empty base class optimization: http://www.cantrip.org/emptyopt.html
  struct string_data : allocator_type {
    rep_proxy_type rep_;

    string_data( allocator_type const &a ) :
      allocator_type( a )
    {
    }
  };

  string_data data_;

//
// I currently don't understand why the compiler complains about append_safe()
// being private within operator+() functions even though they are declared as
// friends.  For now, just make them "public."
//
public:
  // RSTRING_APPEND_SAFE_CP_ST_CP_ST_X
  /**
   * Appends one or two C strings with known-valid length parameters.
   *
   * The method assumes that the C strings do not overlap with "this" string.
   *
   * @param s1 The first C string to append.
   * @param n1 The number of characters of the first C string to append; may be
   * zero.
   * @param s2 The second C string to append.
   * @param n3 The number of characters of the second C string to append; may be
   * zero.
   */
  void append_safe( const_pointer s1, size_type n1,
                    const_pointer s2 = nullptr, size_type n2 = 0 );
private:

  /**
   * A version of assign() optimized slightly for when \a n == 1.
   */
  static void assign_opt( pointer to, size_type n, value_type c ) {
    if ( n == 1 )
      traits_type::assign( *to, c );
    else
      traits_type::assign( to, n, c );
  }

  /**
   * Checks that the given \a pos <= the given \a size.
   *
   * @param pos The position to check.
   * @param size The size to check against.
   * @param msg The error message to use for the exception if thrown.
   * @return Returns \a pos for convenience.
   * @throw std::out_of_range if \a pos >= \c size().
   */
  static size_type check_pos( size_type pos, size_type size, char const *msg ) {
    if ( pos > size )
      throw std::out_of_range( msg );
    return pos;
  }

  /**
   * Checks that the given \a pos <= \c size().
   *
   * @param pos The position to check.
   * @param msg The error message to use for the exception if thrown.
   * @return Returns \a pos for convenience.
   * @throw std::out_of_range if \a pos >= \c size().
   */
  size_type check_pos( size_type pos, char const *msg ) const {
    return check_pos( pos, size(), msg );
  }

  /**
   * Does a 3-way comparison of two integers.
   *
   * @tparam IntType The integer type.
   * @param i The first integer.
   * @param j The second integer.
   * @return Returns -1 if \a i < \a j, 0 if \a i == \a j, or 1 if \a i > \a j.
   */
  template<typename IntType>
  static int compare( IntType i, IntType j ) {
    return i < j ? -1 : i > j ? 1 : 0;
  }

  // RSTRING_COMPARE_CP_ST_X
  /**
   * Compares this string to a C string.
   *
   * @param s The C string to compare to.
   * @param n The number of characters to compare.
   * @return Returns -1 if this string is < \a s, 0 if this string == \a s, or
   * 1 if this string > \a s.
   */
  int compare( const_pointer s, size_type n ) const;

  /**
   * Checks whether the given pointer is out of the range of the current
   * string.
   *
   * @param s The pointer to check.
   * @return Returns \c true only if it is.
   */
  bool disjunct( const_pointer s ) const {
    const_pointer const d = data();
    return s < d || d + size() < s;
  }

  /**
   * Like begin() but doesn't make the rep unsharable.
   */
  iterator ibegin() const {
    return iterator( data() );
  }

  /**
   * Like end() but doesn't make the rep unsharable.
   */
  iterator iend() const {
    return iterator( data() + size() );
  }

  /**
   * Limits \a n to be no greater than the given \a size.
   *
   * @param pos The position to calculate the limited value of \n relative to.
   * @param size The size of the string.
   * @param n The initial value of \a n.
   * @return Returns a limited value of \a n such that \a n <= \a size - \a pos.
   */
  static size_type limit_n( size_type pos, size_type size, size_type n ) {
    size_type const max_n = size - pos;
    return n < max_n ? n : max_n;
  }

  /**
   * Limits \a n to be no greater than \c size().
   *
   * @param pos The position to calculate the limited value of \n relative to.
   * @param n The initial value of \a n.
   * @return Returns a limited value of \a n such that \a n <= \a size() -
   * \a pos.
   */
  size_type limit_n( size_type pos, size_type n ) const {
    return limit_n( pos, size(), n );
  }

  /**
   * Makes the representation unsharable if necessary.  If it is currently
   * shared, it must be cloned.
   */
  void make_unsharable_if_necessary() {
    rep().make_unsharable_if_necessary( get_allocator() );
  }

  /**
   * Prepares the string for further mutation by adjusting the length of a
   * substring.  The substring will expand (n2 > n1) or contract (n2 < n1) and
   * characters will be "slid" as necessary.
   *
   * @param pos The starting position to be affected.
   * @param n1  The number of exising characters (starting at pos) to affect.
   * @param n2  The new length for the substring.
   */
  void mutate( size_type pos, size_type n1, size_type n2 );

  /**
   * Gets the current RepType object.
   *
   * @return Returns said object.
   */
  rep_proxy_type& rep() {
    return data_.rep_;
  }

  /**
   * Gets the current RepType object.
   *
   * @return Returns said object.
   */
  rep_proxy_type const& rep() const {
    return data_.rep_;
  }

  /**
   * Replaces a known-valid range of characters in this string.
   *
   * @param pos The position of the first character to replace.
   * @param n The number of characters to replace; may be zero.
   * @param s The C string containing the new characters.
   * @param s_n The number of characters of the C string to use.
   */
  rstring& replace_safe( size_type pos, size_type n, const_pointer s,
                         size_type s_n ) {
    mutate( pos, n, s_n );
    if ( s_n )
      RepType::copy( data() + pos, s, s_n );
    return *this;
  }

  /**
   * Replaces a known-valid range of characters in this string.
   *
   * @param pos The position of the first character to replace.
   * @param n The number of characters to replace; may be zero.
   * @param c_n The number of \a c characters.
   * @param c The replacement character.
   */
  rstring& replace_safe( size_type pos, size_type n, size_type c_n,
                         value_type c ) {
    mutate( pos, n, c_n );
    if ( c_n )
      RepType::assign( data() + pos, c_n, c );
    return *this;
  }

}; // rstring

////////// inline rstring members /////////////////////////////////////////////

// RSTRING_C_X
template<class Rep> inline
rstring<Rep>::rstring() :
  data_( allocator_type() )
{
}

// RSTRING_C_A_X
template<class Rep> inline
rstring<Rep>::rstring( allocator_type const &a ) :
  data_( a )
{
  rep().construct( 0, value_type(), a );
}

// RSTRING_C_RS_X
template<class Rep> inline
rstring<Rep>::rstring( rstring const &s ) :
  data_( s.get_allocator() )
{
  rep().share( s.rep(), s.get_allocator(), s.get_allocator() );
}

// RSTRING_C_TRS_X
template<class Rep>
template<class Rep2> inline
rstring<Rep>::rstring( rstring<Rep2> const &s ) :
  data_( allocator_type() )
{
  rep().construct( s.data(), s.data() + s.size(), allocator_type() );
}

// RSTRING_C_RS_2ST_X
template<class Rep> inline
rstring<Rep>::rstring( rstring const &s, size_type pos, size_type n ) :
  data_( allocator_type() )
{ 
  rep().construct( s.data() + s.check_pos( pos, "rstring" ),
                   s.data() + pos + s.limit_n( pos, n ),
                   allocator_type() );
}

// RSTRING_C_TRS_2ST_X
template<class Rep>
template<class Rep2> inline
rstring<Rep>::rstring( rstring<Rep2> const &s, size_type pos, size_type n ) :
  data_( allocator_type() )
{ 
  rep().construct( s.data() + s.check_pos( pos, "rstring" ),
                   s.data() + pos + s.limit_n( pos, n ),
                   allocator_type() );
}

// RSTRING_C_RS_2ST_A_X
template<class Rep> inline
rstring<Rep>::rstring( rstring const &s, size_type pos, size_type n,
                       allocator_type const &a ) :
  data_( a )
{
  rep().construct( s.data() + s.check_pos( pos, "rstring" ),
                   s.data() + pos + s.limit_n( pos, n ),
                   a );
}

// RSTRING_C_TRS_2ST_A_X
template<class Rep>
template<class Rep2> inline
rstring<Rep>::rstring( rstring<Rep2> const &s, size_type pos, size_type n,
                       allocator_type const &a ) :
  data_( a )
{
  rep().construct( s.data() + s.check_pos( pos, "rstring" ),
                   s.data() + pos + s.limit_n( pos, n ),
                   a );
}

// RSTRING_C_SS_X
template<class Rep> inline
rstring<Rep>::rstring( std_string const &s ) :
  data_( allocator_type() )
{
  rep().construct( s.data(), s.data() + s.size(), allocator_type() );
}

// RSTRING_C_SS_2ST_X
template<class Rep> inline
rstring<Rep>::rstring( std_string const &s, size_type pos, size_type n ) :
  data_( allocator_type() )
{
  rep().construct( s.data() + check_pos( pos, s.size(), "rstring" ),
                   s.data() + pos + limit_n( pos, s.size(), n ), allocator_type() );
}

// RSTRING_C_SS_2ST_A_X
template<class Rep> inline
rstring<Rep>::rstring( std_string const &s, size_type pos, size_type n,
                       allocator_type const &a ) :
  data_( a )
{
  rep().construct( s.data() + check_pos( pos, s.size(), "rstring" ),
                   limit_n( pos, s.size(), n ),
                   a );
}

// RSTRING_C_CP_A_X
template<class Rep> inline
rstring<Rep>::rstring( const_pointer s, allocator_type const &a ) :
  data_( a )
{
  rep().construct( s, s + (s ? traits_type::length( s ) : npos), a );
}

// RSTRING_C_P_A_X
template<class Rep> inline
rstring<Rep>::rstring( pointer s, allocator_type const &a ) :
  data_( a )
{
  // TODO: calls length unnecessarily when doing ptr_rep
  rep().construct( s, s + (s ? traits_type::length( s ) : 0), a );
}

// RSTRING_C_CP_ST_A_X
template<class Rep> inline
rstring<Rep>::rstring( const_pointer s, size_type n, allocator_type const &a ) :
  data_( a )
{
  rep().construct( s, s + n, a );
}

// RSTRING_C_P_ST_A_X
template<class Rep> inline
rstring<Rep>::rstring( pointer s, size_type n, allocator_type const &a ) :
  data_( a )
{
  rep().construct( s, s + n, a );
}

// RSTRING_C_ST_VT_A_X
template<class Rep> inline
rstring<Rep>::rstring( size_type n, value_type c, allocator_type const &a ) :
  data_( a )
{
  rep().construct( n, c, a );
}

// RSTRING_C_2II_A_X
template<class Rep>
template<class InputIterator> inline
rstring<Rep>::rstring( InputIterator i, InputIterator j,
                       allocator_type const &a ) :
  data_( a )
{
  rep().construct( i, j, a );
}

// RSTRING_APPEND_RS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::append( rstring const &s ) {
  append_safe( s.data(), s.size() );
  return *this;
}

// RSTRING_APPEND_TRS_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::append( rstring<Rep2> const &s ) {
  append_safe( s.data(), s.size() );
  return *this;
}

// RSTRING_APPEND_SS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::append( std_string const &s ) {
  append_safe( s.data(), s.size() );
  return *this;
}

// RSTRING_APPEND_CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::append( const_pointer s ) {
  append( s, traits_type::length( s ) );
  return *this;
}

// RSTRING_ASSIGN_RS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( rstring const &s, size_type s_pos, size_type s_n ) {
  return assign(
    s.data() + s.check_pos( s_pos, "assign" ), s.limit_n( s_pos, s_n )
  );
}

// RSTRING_ASSIGN_SS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( std_string const &s ) {
  return assign( s.c_str(), s.size() );
}

// RSTRING_ASSIGN_SS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( std_string const &s, size_type s_pos, size_type s_n ) {
  return assign(
    s.data() + check_pos( s_pos, s.size(), "assign" ),
    limit_n( s_pos, s.size(), s_n )
  );
}

// RSTRING_ASSIGN_CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( const_pointer s ) {
  return assign( s, traits_type::length( s ) );
}

// RSTRING_ASSIGN_P_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( pointer s ) {
  return assign( s, traits_type::length( s ) );
}

// RSTRING_ASSIGN_ST_VT_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::assign( size_type n, value_type c ) {
  return replace_safe( 0, size(), n, c );
}

// RSTRING_ASSIGN_2II_X
template<class Rep>
template<class InputIterator> inline rstring<Rep>&
rstring<Rep>::assign( InputIterator ii, InputIterator ij ) {
  return replace( ibegin(), iend(), ii, ij );
}


// RSTRING_COMPARE_TRS_X
template<class Rep>
template<class Rep2> inline int
rstring<Rep>::compare( rstring<Rep2> const &s ) const {
  return compare( s.c_str() );
}

// RSTRING_COMPARE_SS_X
template<class Rep> inline int
rstring<Rep>::compare( std_string const &s ) const {
  return compare( s.c_str(), s.size() );
}

// RSTRING_COMPARE_CP_X
template<class Rep> inline int
rstring<Rep>::compare( const_pointer s ) const {
  return compare( s, traits_type::length( s ) );
}

// RSTRING_COMPARE_2ST_TRS_X
template<class Rep>
template<class Rep2> inline int
rstring<Rep>::compare( size_type pos, size_type n,
                       rstring<Rep2> const &s ) const {
  return compare( pos, n, s.data(), s.size() );
}

// RSTRING_COMPARE_2ST_SS_X
template<class Rep> inline int
rstring<Rep>::compare( size_type pos, size_type n, std_string const &s ) const {
  return compare( pos, n, s.data(), s.size() );
}

// RSTRING_COMPARE_2ST_TRS_2ST_X
template<class Rep>
template<class Rep2> inline int
rstring<Rep>::compare( size_type pos, size_type n, rstring<Rep2> const &s,
                       size_type s_pos, size_type s_n ) const {
  return compare( pos, n, s.data() + s_pos, s_n - s_pos );
}

// RSTRING_COMPARE_2ST_SS_2ST_X
template<class Rep> inline int
rstring<Rep>::compare( size_type pos, size_type n, std_string const &s,
                       size_type s_pos, size_type s_n ) const {
  return compare( pos, n, s.data() + s_pos, s_n - s_pos );
}

// RSTRING_ERASE_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::erase( size_type pos, size_type n ) {
  mutate( check_pos( pos, "erase" ), limit_n( pos, n ), 0 );
  return *this;
}

// RSTRING_ERASE_I_X
template<class Rep> inline typename rstring<Rep>::iterator
rstring<Rep>::erase( iterator i ) {
  size_type const pos = i - ibegin();
  mutate( pos, 1, 0 );
  rep().set_unsharable();
  return iterator( data() + pos );
}

// RSTRING_ERASE_2I_X
template<class Rep> inline typename rstring<Rep>::iterator
rstring<Rep>::erase( iterator i, iterator j ) {
  size_type const pos = i - ibegin();
  mutate( pos, j - i, 0 );
  rep().set_unsharable();
  return iterator( data() + pos );
}

// RSTRING_FIND_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find( rstring const &s, size_type pos ) const {
  return find( s.data(), pos, s.size() );
}

// RSTRING_FIND_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::find( rstring<Rep2> const &s, size_type pos ) const {
  return find( s.data(), pos, s.size() );
}

// RSTRING_FIND_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find( std_string const &s, size_type pos ) const {
  return find( s.data(), pos, s.size() );
}

// RSTRING_FIND_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find( const_pointer s, size_type pos ) const {
  return find( s, pos, traits_type::length( s ) );
}

// RSTRING_FIND_FIRST_OF_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( rstring const &s, size_type pos ) const {
  return find_first_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_OF_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( rstring<Rep2> const &s, size_type pos ) const {
  return find_first_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_OF_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( std_string const &s, size_type pos ) const {
  return find_first_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_OF_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( const_pointer s, size_type pos ) const {
  return find_first_of( s, pos, traits_type::length( s ) );
}

// RSTRING_FIND_FIRST_OF_VT_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_of( value_type c, size_type pos ) const {
  return find( c, pos );
}

// RSTRING_FIND_FIRST_NOT_OF_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( rstring const &s, size_type pos ) const {
  return find_first_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_NOT_OF_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( rstring<Rep2> const &s, size_type pos ) const {
  return find_first_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_NOT_OF_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( std_string const &s, size_type pos ) const {
  return find_first_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_FIRST_NOT_OF_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_first_not_of( const_pointer s, size_type pos ) const {
  return find_first_not_of( s, pos, traits_type::length( s ) );
}

// RSTRING_FIND_LAST_OF_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( rstring const &s, size_type pos ) const {
  return find_last_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_OF_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( rstring<Rep2> const &s, size_type pos ) const {
  return find_last_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_OF_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( std_string const &s, size_type pos ) const {
  return find_last_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_OF_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( const_pointer s, size_type pos ) const {
  return find_last_of( s, pos, traits_type::length( s ) );
}

// RSTRING_FIND_LAST_OF_VT_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_of( value_type c, size_type pos ) const {
  return rfind( c, pos );
}

// RSTRING_FIND_LAST_NOT_OF_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( rstring const &s, size_type pos ) const {
  return find_last_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_NOT_OF_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( rstring<Rep2> const &s, size_type pos ) const {
  return find_last_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_NOT_OF_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( std_string const &s, size_type pos ) const {
  return find_last_not_of( s.data(), pos, s.size() );
}

// RSTRING_FIND_LAST_NOT_OF_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::find_last_not_of( const_pointer s, size_type pos ) const {
  return find_last_not_of( s, pos, traits_type::length( s ) );
}

// RSTRING_INSERT_ST_RS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, rstring const &s ) {
  return insert( pos, s.data(), s.size() );
}

// RSTRING_INSERT_ST_TRS_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, rstring<Rep2> const &s ) {
  return insert( pos, s.data(), s.size() );
}

// RSTRING_INSERT_ST_SS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, std_string const &s ) {
  return insert( pos, s.data(), s.size() );
}

// RSTRING_INSERT_ST_CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, const_pointer s ) {
  return insert( pos, s, traits_type::length( s ) );
}

// RSTRING_INSERT_ST_RS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, rstring const &s, size_type s_pos,
                      size_type s_n ) {
  return insert(
    pos, s.data() + s.check_pos( s_pos, "insert" ), s.limit_n( s_pos, s_n )
  );
}

// RSTRING_INSERT_ST_TRS_2ST_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, rstring<Rep2> const &s, size_type s_pos,
                      size_type s_n ) {
  return insert(
    pos, s.data() + s.check_pos( s_pos, "insert" ), s.limit_n( s_pos, s_n )
  );
}

// RSTRING_INSERT_ST_SS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, std_string const &s, size_type s_pos,
                      size_type s_n ) {
  return insert(
    pos,
    s.data() + check_pos( s_pos, s.size(), "insert" ),
    limit_n( s_pos, s.size(), s_n )
  );
}

// RSTRING_INSERT_2ST_VT_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::insert( size_type pos, size_type n, value_type c ) {
  return replace_safe( check_pos( pos, "insert" ), 0, n, c );
}

// RSTRING_INSERT_I_VT_X
template<class Rep> inline typename rstring<Rep>::iterator
rstring<Rep>::insert( iterator i, value_type c ) {
  size_type const pos = i - ibegin();
  replace_safe( pos, 0, 1, c );
  rep().set_unsharable();
  return iterator( data() + pos );
}

// RSTRING_INSERT_I_ST_VT_X
template<class Rep> inline void
rstring<Rep>::insert( iterator i, size_type n, value_type c ) {
  replace( i, i, n, c );
}

// RSTRING_INSERT_I_2II_X
template<class Rep>
template<class InputIterator> inline void
rstring<Rep>::insert( iterator i, InputIterator ii, InputIterator ij ) {
  replace( i, i, ii, ij );
}

// RSTRING_REPLACE_2ST_RS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, rstring const &s ) {
  return replace( pos, n, s.data(), s.size() );
}

// RSTRING_REPLACE_2ST_TRS_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, rstring<Rep2> const &s ) {
  return replace( pos, n, s.data(), s.size() );
}

// RSTRING_REPLACE_2ST_SS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, std_string const &s ) {
  return replace( pos, n, s.data(), s.size() );
}

// RSTRING_REPLACE_2ST_CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, const_pointer s ) {
  return replace( pos, n, s, traits_type::length( s ) );
}

// RSTRING_REPLACE_2ST_RS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, rstring const &s,
                       size_type s_pos, size_type s_n ) {
  return replace(
    pos, n, s.data() + s.check_pos( s_pos, "replace" ), s.limit_n( s_pos, s_n )
  );
}

// RSTRING_REPLACE_2ST_TRS_2ST_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, rstring<Rep2> const &s,
                       size_type s_pos, size_type s_n ) {
  return replace(
    pos, n, s.data() + s.check_pos( s_pos, "replace" ), s.limit_n( s_pos, s_n )
  );
}

// RSTRING_REPLACE_2ST_SS_2ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, std_string const &s,
                       size_type s_pos, size_type s_n ) {
  return replace(
    pos,
    n, s.data() + check_pos( s_pos, s.size(), "replace" ),
    limit_n( s_pos, s.size(), s_n )
  );
}

// RSTRING_REPLACE_3ST_VT_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( size_type pos, size_type n, size_type c_n,
                       value_type c ) {
  return replace_safe(
    check_pos( pos, "replace" ), limit_n( pos, n ), c_n, c
  );
}

// RSTRING_REPLACE_2I_RS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, rstring const &s ) {
  return replace( i, j, s.data(), s.size() );
}

// RSTRING_REPLACE_2I_TRS_X
template<class Rep>
template<class Rep2> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, rstring<Rep2> const &s ) {
  return replace( i, j, s.data(), s.size() );
}

// RSTRING_REPLACE_2I_SS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, std_string const &s ) {
  return replace( i, j, s.data(), s.size() );
}

// RSTRING_REPLACE_2I_CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, const_pointer s ) {
  return replace( i, j, s, traits_type::length( s ) );
}

// RSTRING_REPLACE_2I_CP_ST_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, const_pointer s, size_type n ) {
  return replace( i - ibegin(), j - i, s, n );
}

// RSTRING_REPLACE_2I_ST_VT_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, size_type n, value_type c ) {
  return replace_safe( i - ibegin(), j - i, n, c );
}

// RSTRING_REPLACE_2I_2CP_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::replace( iterator i, iterator j, const_pointer s,
                       const_pointer t ) {
  return replace( i - ibegin(), j - i, s, t - s );
}

// RSTRING_RFIND_RS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::rfind( rstring const &s, size_type pos ) const {
  return rfind( s.data(), pos, s.size() );
}

// RSTRING_RFIND_TRS_ST_X
template<class Rep>
template<class Rep2> inline typename rstring<Rep>::size_type
rstring<Rep>::rfind( rstring<Rep2> const &s, size_type pos ) const {
  return rfind( s.data(), pos, s.size() );
}

// RSTRING_RFIND_SS_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::rfind( std_string const &s, size_type pos ) const {
  return rfind( s.data(), pos, s.size() );
}

// RSTRING_RFIND_CP_ST_X
template<class Rep> inline typename rstring<Rep>::size_type
rstring<Rep>::rfind( const_pointer s, size_type pos ) const {
  return rfind( s, pos, traits_type::length( s ) );
}

// RSTRING_TAKE_RS_X
template<class Rep> inline rstring<Rep>&
rstring<Rep>::take( rstring &s ) {
  rep().take( s.rep(), get_allocator(), s.get_allocator() );
  return *this;
}

////////// inline global functions ////////////////////////////////////////////

template<class Rep> inline void
swap( rstring<Rep> &i, rstring<Rep> &j ) {
  i.swap( j );
}

/**
 * Faster C string equals used to implement operator==().  This is
 * non-standard.
 *
 * @param s1 The first null-terminated C string.
 * @param s1_n The number of characters to compare of \a s1.
 * @param s2 The second null-terminated C string.
 * @param s2_n The number of characters to compare of \a s2.
 * @return Returns \c true only if \a s1 \c == \a s2.
 */
inline bool equals( char const *s1, size_t s1_n, char const *s2, size_t s2_n ) {
  return s1_n == s2_n && (s1 == s2 || std::memcmp( s1, s2, s1_n ) == 0);
}

template<class Rep> inline bool
operator==( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return equals( s1.data(), s1.size(), s2.data(), s2.size() );
}

template<class Rep1,class Rep2> inline bool
operator==( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return equals( s1.data(), s1.size(), s2.data(), s2.size() );
}

template<class Rep> inline bool
operator==( rstring<Rep> const &s1,
            typename rstring<Rep>::std_string const &s2 ) {
  return equals( s1.data(), s1.size(), s2.data(), s2.size() );
}

template<class Rep> inline bool
operator==( typename rstring<Rep>::std_string const &s1,
            rstring<Rep> const &s2 ) {
  return equals( s1.data(), s1.size(), s2.data(), s2.size() );
}

template<class Rep> inline bool
operator==( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  typedef typename rstring<Rep>::traits_type traits_type;
  return equals( s1.data(), s1.size(), s2, traits_type::length( s2 ) );
}

template<class Rep> inline bool
operator==( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  typedef typename rstring<Rep>::traits_type traits_type;
  return equals( s1, traits_type::length( s1 ), s2.data(), s2.size() );
}

template<class Rep> inline bool
operator!=( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return !(s1 == s2);
}

template<class Rep1,class Rep2> inline bool
operator!=( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return !(s1 == s2);
}

template<class Rep> inline bool
operator!=( rstring<Rep> const &s1,
            typename rstring<Rep>::std_string const &s2 ) {
  return !(s1 == s2);
}

template<class Rep> inline bool
operator!=( typename rstring<Rep>::std_string const &s1,
            rstring<Rep> const &s2 ) {
  return !(s1 == s2);
}

template<class Rep> inline bool
operator!=( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  return !(s1 == s2);
}

template<class Rep> inline bool
operator!=( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  return !(s1 == s2);
}

template<class Rep> inline bool
operator<( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class Rep1,class Rep2> inline bool
operator<( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class Rep> inline bool
operator<( rstring<Rep> const &s1,
           typename rstring<Rep>::std_string const &s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class Rep> inline bool
operator<( typename rstring<Rep>::std_string const &s1,
           rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) > 0;
}

template<class Rep> inline bool
operator<( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  return s1.compare( s2 ) < 0;
}

template<class Rep> inline bool
operator<( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) > 0;
}

template<class Rep> inline
bool operator<=( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class Rep1,class Rep2> inline
bool operator<=( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class Rep> inline bool
operator<=( rstring<Rep> const &s1,
            typename rstring<Rep>::std_string const &s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class Rep> inline bool
operator<=( typename rstring<Rep>::std_string const &s1,
            rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) >= 0;
}

template<class Rep> inline bool
operator<=( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  return s1.compare( s2 ) <= 0;
}

template<class Rep> inline bool
operator<=( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) >= 0;
}

template<class Rep> inline bool
operator>( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class Rep1,class Rep2> inline bool
operator>( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class Rep> inline bool
operator>( rstring<Rep> const &s1,
           typename rstring<Rep>::std_string const &s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class Rep> inline bool
operator>( typename rstring<Rep>::std_string const &s1,
           rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) < 0;
}

template<class Rep> inline bool
operator>( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  return s1.compare( s2 ) > 0;
}

template<class Rep> inline bool
operator>( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) < 0;
}

template<class Rep> inline bool
operator>=( rstring<Rep> const &s1, rstring<Rep> const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class Rep1,class Rep2> inline bool
operator>=( rstring<Rep1> const &s1, rstring<Rep2> const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class Rep> inline bool
operator>=( rstring<Rep> const &s1,
            typename rstring<Rep>::std_string const &s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class Rep> inline bool
operator>=( typename rstring<Rep>::std_string const &s1,
            rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) <= 0;
}

template<class Rep> inline bool
operator>=( rstring<Rep> const &s1, typename rstring<Rep>::const_pointer s2 ) {
  return s1.compare( s2 ) >= 0;
}

template<class Rep> inline bool
operator>=( typename rstring<Rep>::const_pointer s1, rstring<Rep> const &s2 ) {
  return s2.compare( s1 ) <= 0;
}

#if 1 || (!defined( __INTEL_COMPLER ) && \
    defined( __GNUC__ ) && (__GNUC__ * 10000 + __GNUC_MINOR__ * 100 < 40300))
template<class Rep> inline std::ostream&
operator<<( std::ostream &os, rstring<Rep> const &s ) {
  return os.write( s.data(), (std::streamsize)s.size() );
}
#else
template<
  class CharType,
  class TraitsType,
  class Allocator,
  class RefCountType,
  template<class,class,class> class RepType
>
inline std::basic_ostream<CharType,TraitsType>&
operator<<( std::basic_ostream<CharType,TraitsType> &os,
            rstring< RepType<RefCountType,TraitsType,Allocator> > const &s ) {
  return os.write( s.data(), s.size() );
}
#endif

////////// out-of-line global function declarations ///////////////////////////

/**
 * Reads a line from the given input stream.
 *
 * @param is The input stream to read from.
 * @param s The string to put the line into.
 * @param delim The delimiter character.
 * @return Returns \a is.
 */
template<typename CharType,class TraitsType,class Rep>
std::basic_istream<CharType,TraitsType>&
getline( std::basic_istream<CharType,TraitsType> &is, rstring<Rep> &s,
         typename rstring<Rep>::value_type delim );

/**
 * Reads a line from the given input stream.
 *
 * @param is The input stream to read from.
 * @param s The string to put the line into.
 * @return Returns \a is.
 */
template<typename CharType,class TraitsType,class Rep> inline
std::basic_istream<CharType,TraitsType>&
getline( std::basic_istream<CharType,TraitsType> &is, rstring<Rep> &s ) {
  return getline( is, s, is.widen( '\n' ) );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#include "rstring.tcc"

#endif /* ZORBA_RSTRING_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
