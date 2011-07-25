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

#ifndef ZORBA_STRING_API_H
#define ZORBA_STRING_API_H

#include <iterator>
#include <memory>
#include <string>

#include <zorba/config.h>

namespace zorba {

/**
 * The Zorba string class.
 *
 * Its API is mostly compatible with that of std::string.
 */
class ZORBA_DLL_PUBLIC String {
public:
  typedef char value_type;
  typedef std::char_traits<value_type> traits_type;
  typedef std::allocator<value_type> allocator_type;
  typedef allocator_type::difference_type difference_type;
  typedef allocator_type::size_type size_type;

  typedef value_type* pointer;
  typedef value_type const* const_pointer;
  typedef value_type& reference;
  typedef value_type const& const_reference;

  typedef pointer iterator;
  typedef const_pointer const_iterator;
  typedef std::reverse_iterator<iterator> reverse_iterator;
  typedef std::reverse_iterator<const_iterator> const_reverse_iterator;

  /**
   * The special value used to denote either (a) the maximum possible number as
   * input or (b) "not found" as a result.
   */
  static size_type const npos = static_cast<size_type>( -1 );

  ////////// constructors & destructor ////////////////////////////////////////

  /**
   * Constructs an empty string.
   */
  String();

  /**
   * Copy constructs a new string from an existing string.
   *
   * @param s The string to copy from.
   */
  String( String const &s );

  /**
   * Constructs a new string from an existing std::string.
   *
   * @param s The string to copy from.
   */
  String( std::string const &s );

  /**
   * Constructs a string from the given C string.
   *
   * @param s The null-terminated C string.
   */
  String( const_pointer s );

  /**
   * Copy constructs a new string from a substring of an existing string.
   *
   * @param s The string to copy from.
   * @param pos The position of the first character to copy.
   * @param n The number of characters to copy.
   */
  String( String const &s, size_type pos, size_type n = npos );

  /**
   * Constructs a new string from a substring of an existing std::string.
   *
   * @param s The string to copy from.
   * @param pos The starting position of the substring.
   * @param n The number of characters of the substring.
   */
  String( std::string const &s, size_type pos, size_type n = npos );

  /**
   * Constructs a string from the given C string.
   *
   * @param s The C string.
   * @param n The number of characters to copy.
   */
  String( const_pointer s, size_type n );

  /**
   * Constructs a new string as \a n copies of \a c.
   *
   * @param n The number of times to repeat the character.
   * @param c The character to repeat.
   */
  String( size_type n, value_type c );

  /**
   * Constructs a string from a range of characters [i,j).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   */
  String( const_iterator i, const_iterator j );

  /**
   * Destructs this string.
   */
  ~String();

  ////////// assignment ///////////////////////////////////////////////////////

  /**
   * Assigns another string to this string.
   *
   * @param s The string to assign from.
   * @return this string.
   */
  String& operator=( String const &s );

  /**
   * Assigns a std::string to this string.
   *
   * @param s The string to assign from.
   * @return this string.
   */
  String& operator=( std::string const &s );

  /**
   * Assigns a C string to this string.
   *
   * @param s The null-terminated C string to assign from.
   * @return this string.
   */
  String& operator=( const_pointer s );

  /**
   * Assigns a character to this string.
   *
   * @param c The character to assign.
   * @return this string.
   */
  String& operator=( value_type c );

  ////////// properties ///////////////////////////////////////////////////////

  /**
   * Gets the capacity of this string.
   *
   * @return said capacity.
   */
  size_type capacity() const;

  /**
   * Checks whether the string is empty.
   *
   * @return True only if it is.
   */
  bool empty() const {
    return length() == 0;
  }

  /**
   * Gets the number of characters in this string.
   *
   * @return The number of UTF-8 characters.
   */
  size_type length() const;

  /**
   * Gets the number of characters in this string.
   * (This is a synonym for length().)
   *
   * @return The number of UTF-8 characters.
   */
  size_type size() const {
    return length();
  }

  ////////// character access /////////////////////////////////////////////////

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is bounds-checked.
   * @return said character as an l-value.
   * @throw std::out_of_range if \a pos >= \c size().
   */
  reference at( size_type pos );

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is bounds-checked.
   * @return said character as an r-value.
   */
  value_type at( size_type pos ) const;

  /**
   * References a particular character within the string.
   *
   * @param pos The index of the character.  The index is not bounds-checked.
   * @return said character as an r-value.
   */
  const_reference operator[]( size_type pos ) const;

  ////////// append ///////////////////////////////////////////////////////////

  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return this string.
   */
  String& append( String const &s );

  /**
   * Appends a substring of the given string to this string.
   *
   * @param s The string to append.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to append.
   * @return this string.
   */
  String& append( String const &s, size_type s_pos, size_type s_n );

  /**
   * Appends the given string to this string.
   *
   * @param s The string to append.
   * @return this string.
   */
  String& append( std::string const &s );

  /**
   * Appends a substring of the given string to this string.
   *
   * @param s The string to append.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to append.
   * @return this string.
   */
  String& append( std::string const &s, size_type s_pos, size_type s_n );

  /**
   * Appends the given C string to this string.
   *
   * @param s The null-terminated C string to append.
   * @return this string.
   */
  String& append( const_pointer s );

  /**
   * Appends the given C string to this string.
   *
   * @param s The C string to append.
   * @param s_n The number of characters of \a s to append.
   * @return this string.
   */
  String& append( const_pointer s, size_type s_n );

  /**
   * Appends \a n copies of \a c to this string.
   *
   * @param n The numer of copies of \a c to append.
   * @param c The character to append.
   * @return this string.
   */
  String& append( size_type n, value_type c );

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
   * @return this string.
   */
  String& operator+=( String const &s ) {
    return append( s );
  }

  /**
   * Appends the given std::string to this string.
   *
   * @param s The string to append.
   * @return this string.
   */
  String& operator+=( std::string const &s ) {
    return append( s.data(), s.size() );
  }

  /**
   * Appends the given C string to this string.
   *
   * @param s The null-terminated C string to append.
   * @return this string.
   */
  String& operator+=( const_pointer s ) {
    return append( s );
  }

  /**
   * Appends the given character to this string.
   *
   * @param c The character to append.
   * @return this string.
   */
  String& operator+=( value_type c ) {
    return append( 1, c );
  }

  ////////// assign ///////////////////////////////////////////////////////////

  /**
   * Assigns another string to this string.
   *
   * @param s The string to assign from.
   * @return this string.
   */
  String& assign( String const &s );

  /**
   * Assigns a std::string to this string.
   *
   * @param s The string to assign from.
   * @return this string.
   */
  String& assign( std::string const &s );

  /**
   * Assigns a substring of a string to this string.
   *
   * @param s The string to assign from.
   * @param pos The starting position withing \a s.
   * @param n The number of characters to assign.
   * @return this string.
   */
  String& assign( String const &s, size_type pos, size_type n );

  /**
   * Assigns a substring of a std::string to this string.
   *
   * @param s The string to assign from.
   * @param pos The starting position withing \a s.
   * @param n The number of characters to assign.
   * @return this string.
   */
  String& assign( std::string const &s, size_type pos, size_type n );

  /**
   * Assigns a C to this string.
   *
   * @param s The null-terminated C string to assign from.
   * @return this string.
   */
  String& assign( const_pointer s );

  /**
   * Assigns a substring of a C to this string.
   *
   * @param s The C string to assign from.
   * @param n The number of characters to assign.
   * @return this string.
   */
  String& assign( const_pointer s, size_type n );

  /**
   * Assigned \a n copies of a character to this string.
   *
   * @param n The number of copies of the character.
   * @param c The character.
   * @return this string.
   */
  String& assign( size_type n, value_type c );

  /**
   * Assigns characters from a range of characters [i,j).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   */
  String& assign( const_iterator i, const_iterator j );

  ////////// compare //////////////////////////////////////////////////////////

  /**
   * Compares this string against another.
   *
   * @param s The string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( String const &s ) const;

  /**
   * Compares this string against another.
   *
   * @param s The string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( std::string const &s ) const;

  /**
   * Compares this string against a C string.
   *
   * @param s The null-terminated C string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( const_pointer s ) const;

  /**
   * Compares a substring of this string against another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, String const &s ) const;

  /**
   * Compares a substring of this string against another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, std::string const &s ) const;

  /**
   * Compares a substring of this string against a C string.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The null-terminated C string to compare to.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, const_pointer s ) const;

  /**
   * Compares a substring of this string against a substring of another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @param s_pos The starting position within \a s.
   * @param s_n The number of characters of \a s to compare.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, String const &s, size_type s_pos,
               size_type s_n ) const;

  /**
   * Compares a substring of this string against a substring of another.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The string to compare to.
   * @param s_pos The starting position within \a s.
   * @param s_n The number of characters of \a s to compare.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, std::string const &s,
               size_type s_pos, size_type s_n ) const;

  /**
   * Compares a substring of this string against a C string.
   *
   * @param pos The starting position within this string.
   * @param n The number of characters to compare.
   * @param s The C string to compare to.
   * @param s_n The number of characters of \a s to compare.
   * @return -1 only if this string \< \a s,
   * 0 only if this string == \a s,
   * or +1 only if this string \> \a s.
   */
  int compare( size_type pos, size_type n, const_pointer s,
               size_type s_n ) const;

  ////////// clear/erase //////////////////////////////////////////////////////

  /**
   * Erases the string making it empty.
   */
  void clear();

  /**
   * Erases the given number of characters starting at the given position.
   *
   * @param pos The position of the first character to erase.
   * @param n The number of characters to erase.
   * @return a reference to this string.
   * @throw std::out_of_range if \a pos is beyond the end of the string.
   */
  String& erase( size_type pos = 0, size_type n = npos );

  /**
   * Erases the character at the given iterator's position.
   *
   * @param i The iterator marking the position of the character to erase.
   * @return a new iterator marking the same position (i.e., what becomes the
   * next character).
   */
  iterator erase( iterator i );

  /**
   * Erases a range of characters [i,j).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @return a new iterator marking the same position as \a i.
   */
  iterator erase( iterator i, iterator j );

  ////////// find /////////////////////////////////////////////////////////////

  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type find( String const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type find( std::string const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The null-terminated C string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type find( const_pointer s, size_type pos = 0 ) const;

  /**
   * Searches this string for the given string starting at the given position.
   *
   * @param s The C string to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters to compare.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type find( const_pointer s, size_type pos, size_type s_n ) const;

  /**
   * Searches this string for the given character staring at the given
   * position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a c or \c npos if not found.
   */
  size_type find( value_type c, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_first_of( String const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_first_of( std::string const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters in \a s starting at the
   * given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_first_of( const_pointer s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the first \a s_n characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \a s to consider.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_first_of( const_pointer s, size_type pos,
                           size_type s_n ) const;

  /**
   * Searches this string for the given character starting at the given
   * position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a c or \c npos if not found.
   */
  size_type find_first_of( value_type c, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return the offset of a non-matching character or \c npos if not found.
   */
  size_type find_first_not_of( String const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return the offset of a non-matching character or \c npos if not found.
   */
  size_type find_first_not_of( std::string const &s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the characters not in \a s starting at
   * the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @return the offset of a non-matching character or \c npos if not found.
   */
  size_type find_first_not_of( const_pointer s, size_type pos = 0 ) const;

  /**
   * Searches this string for any one of the first \a s_n characters not in \a
   * s starting at the given position.
   *
   * @param s The set of characters not to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \a s to consider.
   * @return the offset of a non-matching character or \c npos if not found.
   */
  size_type find_first_not_of( const_pointer s, size_type pos,
                               size_type s_n ) const;

  /**
   * Searches this string for any character except the given character starting
   * at the given position.
   *
   * @param c The character not to search for.
   * @param pos The starting position within this string.
   * @return the offset of any character except \a c or \c npos if not found.
   */
  size_type find_first_not_of( value_type c, size_type pos = 0 ) const;

  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_of( String const &s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_of( std::string const &s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the characters in \a s
   * starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_of( const_pointer s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the first \a s_n characters
   * in \a s starting at the given position.
   *
   * @param s The set of characters to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \a s to consider.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_of( const_pointer s, size_type pos, size_type s_n ) const;

  /**
   * Searches this string backwards for the given character starting at the
   * given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a c or \c npos if not found.
   */
  size_type find_last_of( value_type c, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_not_of( String const &s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_not_of( std::string const &s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the characters not in \a s
   * starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_not_of( const_pointer s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for any one of the first \a s_n characters
   * not in \a s starting at the given position.
   *
   * @param s The set of characters to not search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters of \a s to consider.
   * @return the offset of a matching character or \c npos if not found.
   */
  size_type find_last_not_of( const_pointer s, size_type pos,
                              size_type s_n ) const;

  /**
   * Searches this string backwards for any character except the given
   * character starting at the given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return the offset of any character except \a c or \c npos if not found.
   */
  size_type find_last_not_of( value_type c, size_type pos = npos ) const;

  /**
   * Searches this backwards string for the given string starting at the given
   * position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type rfind( String const &s, size_type pos = npos ) const;

  /**
   * Searches this backwards string for the given string starting at the given
   * position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type rfind( std::string const &s, size_type pos = npos ) const;

  /**
   * Searches this backwards string for the given string starting at the given
   * position.
   *
   * @param s The string to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type rfind( const_pointer s, size_type pos = npos ) const;

  /**
   * Searches this string backwards for the given string starting at the given
   * position.
   *
   * @param s The C string to search for.
   * @param pos The starting position within this string.
   * @param s_n The number of characters to compare.
   * @return the offset of \a s or \c npos if not found.
   */
  size_type rfind( const_pointer s, size_type pos, size_type s_n ) const;

  /**
   * Searches this string backwards for the given character staring at the
   * given position.
   *
   * @param c The character to search for.
   * @param pos The starting position within this string.
   * @return the offset of \a c or \c npos if not found.
   */
  size_type rfind( value_type c, size_type pos = npos ) const;

  ////////// insert ///////////////////////////////////////////////////////////

  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The string to insert.
   * @return this string.
   */
  String& insert( size_type pos, String const &s );

  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The string to insert.
   * @return this string.
   */
  String& insert( size_type pos, std::string const &s );

  /**
   * Inserts the given string into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated string to insert.
   * @return this string.
   */
  String& insert( size_type pos, const_pointer s );

  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_pos The starting position within \a s.
   * @param s_n The numer of characters of \a s to insert.
   * @return this string.
   */
  String& insert( size_type pos, String const &s, size_type s_pos,
                  size_type s_n );

  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The null-terminated C string to insert.
   * @param s_pos The starting position within \a s.
   * @param s_n The numer of characters of \a s to insert.
   * @return this string.
   */
  String& insert( size_type pos, std::string const &s, size_type s_pos,
                  size_type s_n );

  /**
   * Inserts a substring of the given string into this string at the given
   * position.
   *
   * @param pos The position within this string to insert at.
   * @param s The C string to insert.
   * @param s_n The numer of characters of \a s to insert.
   * @return this string.
   */
  String& insert( size_type pos, const_pointer s, size_type s_n );

  /**
   * Inserts \a n copies of \a c into this string at the given position.
   *
   * @param pos The position within this string to insert at.
   * @param n The number of copies of \a c to insert.
   * @param c The character to insert.
   * @return this string.
   */
  String& insert( size_type pos, size_type n, value_type c );

  /**
   * Inserts the given character into this string at the given position.
   *
   * @param pos The iterator marking the position within this string to insert
   * at.
   * @param c The character to insert.
   * @return Returns an iterator positioned at the newly inserted character.
   */ 
  iterator insert( iterator pos, value_type c );

  /**
   * Inserts \a n copies of \a c into this string at the given position.
   *
   * @param pos The iterator marking the position within this string to insert
   * at.
   * @param n The number of copies of \a c to insert.
   * @param c The character to insert.
   */ 
  void insert( iterator pos, size_type n, value_type c );

  ////////// replace //////////////////////////////////////////////////////////

  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, String const &s );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, std::string const &s );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The null-terminated replacement C string.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, const_pointer s );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to use.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, String const &s,
                   size_type s_pos, size_type s_n );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement string.
   * @param s_pos The starting position is \a s.
   * @param s_n The number of characters of \a s to use.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, std::string const &s,
                   size_type s_pos, size_type s_n );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with a substring of the given string.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param s The replacement C string.
   * @param s_n The number of characters of \a s to use.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, const_pointer s, size_type s_n );

  /**
   * Replaces \a n characters of this string starting at the given position
   * with \a c_n copies of \a c.
   *
   * @param pos The position within this string to replace at.
   * @param n The number of characters to replace.
   * @param c_n The number of copies of \c to replace with.
   * @param c The character to replace with.
   * @return this string.
   */
  String& replace( size_type pos, size_type n, size_type c_n, value_type c );

  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement string.
   * @return this string.
   */
  String& replace( iterator i, iterator j, String const &s );

  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement string.
   * @return this string.
   */
  String& replace( iterator i, iterator j, std::string const &s );

  /**
   * Replaces the range of characters [i,j) of this string with the given
   * string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The null-terminated replacement C string.
   * @return this string.
   */
  String& replace( iterator i, iterator j, const_pointer s );

  /**
   * Replaces the range of characters [i,j) of this string with a substring of
   * the given string.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param s The replacement C string.
   * @param s_n The number of characters of \a s to use.
   * @return this string.
   */
  String& replace( iterator i, iterator j, const_pointer s, size_type s_n );

  /**
   * Replaces the range of characters [i,j) of this string with \a c_n copies
   * of \a c.
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param n The number of copies of \c to replace with.
   * @param c The character to replace with.
   * @return Returns this string.
   */
  String& replace( iterator i, iterator j, size_type n, value_type c );

  /**
   * Replaces the range of characters [i,j) of this string with the range of
   * characters [si,sj).
   *
   * @param i The iterator marking the first character of the range.
   * @param j The iterator marking one past the last character of the range.
   * @param si The iterator marking the first character of the range.
   * @param sj The iterator marking one past the last character of the range.
   * @return this string.
   */
  String& replace( iterator i, iterator j, iterator si, iterator sj );

  ////////// iterators ////////////////////////////////////////////////////////

  /**
   * Returns a read/write iterator positioned at the first character of the
   * string.
   * 
   * @return said iterator.
   */
  iterator begin();

  /**
   * Returns a read-only iterator positioned at the first character of the
   * string.
   * 
   * @return said iterator.
   */
  const_iterator begin() const;

  /**
   * Returns a read/write iterator positioned at one past the last character of
   * the string.
   * 
   * @return said iterator.
   */
  iterator end();

  /**
   * Returns a read-only iterator positioned at one past the last character of
   * the string.
   * 
   * @return said iterator.
   */
  const_iterator end() const;

  /**
   * Returns a read/write reverse iterator positioned at the first character of
   * the reversed string.
   * 
   * @return said iterator.
   */
  reverse_iterator rbegin();

  /**
   * Returns a read-only reverse iterator positioned at the first character of
   * the reversed string.
   * 
   * @return said iterator.
   */
  const_reverse_iterator rbegin() const;

  /**
   * Returns a read/write reverse iterator positioned at one past the last
   * character of the reversed string.
   * 
   * @return said iterator.
   */
  reverse_iterator rend();

  /**
   * Returns a read-only reverse iterator positioned at one past the last
   * character of the reversed string.
   * 
   * @return said iterator.
   */
  const_reverse_iterator rend() const;

  ////////// miscellaneous ////////////////////////////////////////////////////

  /**
   * Copies a substring to a C string buffer.
   *
   * @param buf The buffer to copy into.
   * @param n The number of characters to copy.
   * It's the caller's responsibility to ensure that the size of \a buf <= \a
   * n.
   * @param pos The position of the first character to copy.
   * @return the number of characters actually copied.
   * @throw std::out_of_range if \a pos >= size().
   */
  size_type copy( pointer buf, size_type n, size_type pos = 0 ) const;

  /**
   * Gets a pointer to a null-terminated array of characters representing the
   * string's contents.
   *
   * @return said pointer.
   * @see data()
   */
  const_pointer c_str() const;

  /**
   * Gets a pointer to the raw character data comprising the string, not
   * necessarily null-terminated.
   *
   * @return said pointer.
   * @see c_str()
   */
  const_pointer data() const;

  /**
   * Attemts to pre-allocated enough memory to contain the given number of
   * bytes.
   *
   * @param n The number of bytes.
   */
  void reserve( size_type n );

  /**
   * Resizes the string to the given number of characters.
   * If the number \< size(), the string will be truncated;
   * if the number \> size(), the string will be extended
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
   * @return said \c std::string.
   */
  std::string str() const;

  /**
   * Creates a new string that is a substring of this string.
   *
   * @param pos The position in this string for first character of the new
   * string.
   * @param n The number of characters to extract.
   * @return the new string.
   * @throw std::out_of_range if \a pos >= size().
   */
  String substr( size_type pos = 0, size_type n = npos ) const;

  /**
   * Swaps the contents of this string with another.
   * This is an O(1) operation.
   *
   * @param s The string to swap with.
   */
  void swap( String &s );

  /////////////////////////////////////////////////////////////////////////////

private:
  //
  // We need to use a struct in order to assert that its size >= the size of
  // the internal string class.
  //
  struct string_storage_type {
    //
    // We need to do this union weirdness so as not to break strict-aliasing
    // rules.
    //
    union {
      void *rep_;
      char storage_[1];
    };
#ifdef ZORBA_DEBUG_STRING
    char *debug_str_;
#endif /* ZORBA_DEBUG_STRING */
  };

  string_storage_type string_storage_;

  // Using a struct prevents void* ambiguity with char*.
  struct zstring_ptr { void const *ptr; };

  String( zstring_ptr );
  String& operator=( zstring_ptr );

  static void size_check();

  friend ZORBA_DLL_PUBLIC bool operator==( String const&, String const& );
  friend ZORBA_DLL_PUBLIC bool operator==( String const&, std::string const& );
  friend ZORBA_DLL_PUBLIC bool operator==( String const&, const_pointer );

  friend ZORBA_DLL_PUBLIC bool operator<( String const&, String const& );
  friend ZORBA_DLL_PUBLIC bool operator<( String const&, std::string const& );
  friend ZORBA_DLL_PUBLIC bool operator<( String const&, const_pointer );
  friend ZORBA_DLL_PUBLIC bool operator<( std::string const&, String const& );
  friend ZORBA_DLL_PUBLIC bool operator<( const_pointer, String const& );

  friend ZORBA_DLL_PUBLIC bool operator<=( String const&, String const& );
  friend ZORBA_DLL_PUBLIC bool operator<=( String const&, std::string const& );
  friend ZORBA_DLL_PUBLIC bool operator<=( String const&, const_pointer );
  friend ZORBA_DLL_PUBLIC bool operator<=( std::string const&, String const& );
  friend ZORBA_DLL_PUBLIC bool operator<=( const_pointer, String const& );

  friend ZORBA_DLL_PUBLIC String operator+( String const&, String const& );
  friend ZORBA_DLL_PUBLIC String operator+( String const&, std::string const& );
  friend ZORBA_DLL_PUBLIC String operator+( String const&, const_pointer );
  friend ZORBA_DLL_PUBLIC String operator+( std::string const&, String const& );
  friend ZORBA_DLL_PUBLIC String operator+( const_pointer, String const& );

  friend ZORBA_DLL_PUBLIC
  std::ostream& operator<<( std::ostream&, String const& );

  friend class Unmarshaller;
};

////////// relational operators ///////////////////////////////////////////////

ZORBA_DLL_PUBLIC bool operator==( String const &s1, String const &s2 );
ZORBA_DLL_PUBLIC bool operator==( String const &s1, std::string const &s2 );
ZORBA_DLL_PUBLIC bool operator==( String const &s1, String::const_pointer s2 );

ZORBA_DLL_PUBLIC bool operator<( String const &s1, String const &s2 );
ZORBA_DLL_PUBLIC bool operator<( String const &s1, std::string const &s2 );
ZORBA_DLL_PUBLIC bool operator<( String const &s1, String::const_pointer s2 );
ZORBA_DLL_PUBLIC bool operator<( std::string const &s1, String const &s2 );
ZORBA_DLL_PUBLIC bool operator<( String::const_pointer s1, String const &s2 );

ZORBA_DLL_PUBLIC bool operator<=( String const &s1, String const &s2 );
ZORBA_DLL_PUBLIC bool operator<=( String const &s1, std::string const &s2 );
ZORBA_DLL_PUBLIC bool operator<=( String const &s1, String::const_pointer s2 );
ZORBA_DLL_PUBLIC bool operator<=( std::string const &s1, String const &s2 );
ZORBA_DLL_PUBLIC bool operator<=( String::const_pointer s1, String const &s2 );

inline bool operator==( std::string const &s1, String const &s2 ) {
  return s2 == s1;
}

inline bool operator==( String::const_pointer s1, String const &s2 ) {
  return s2 == s1;
}

inline bool operator!=( String const &s1, String const &s2 ) {
  return !(s1 == s2);
}

inline bool operator!=( String const &s1, std::string const &s2 ) {
  return !(s1 == s2);
}

inline bool operator!=( String const &s1, String::const_pointer s2 ) {
  return !(s1 == s2);
}

inline bool operator!=( std::string const &s1, String const &s2 ) {
  return !(s1 == s2);
}

inline bool operator!=( String::const_pointer s1, String const &s2 ) {
  return !(s1 == s2);
}

inline bool operator>=( String const &s1, String const &s2 ) {
  return !(s1 < s2);
}

inline bool operator>=( String const &s1, std::string const &s2 ) {
  return !(s1 < s2);
}

inline bool operator>=( String const &s1, String::const_pointer s2 ) {
  return !(s1 < s2);
}

inline bool operator>=( std::string const &s1, String const &s2 ) {
  return !(s1 < s2);
}

inline bool operator>=( String::const_pointer s1, String const &s2 ) {
  return !(s1 < s2);
}

inline bool operator>( String const &s1, String const &s2 ) {
  return !(s1 <= s2);
}

inline bool operator>( String const &s1, std::string const &s2 ) {
  return !(s1 <= s2);
}

inline bool operator>( String const &s1, String::const_pointer s2 ) {
  return !(s1 <= s2);
}

inline bool operator>( std::string const &s1, String const &s2 ) {
  return !(s1 <= s2);
}

inline bool operator>( String::const_pointer s1, String const &s2 ) {
  return !(s1 <= s2);
}

////////// concatenation //////////////////////////////////////////////////////

ZORBA_DLL_PUBLIC String operator+( String const &s1, String const &s2 );
ZORBA_DLL_PUBLIC String operator+( String const &s1, std::string const &s2 );
ZORBA_DLL_PUBLIC String operator+( String const &s1, String::const_pointer s2 );
ZORBA_DLL_PUBLIC String operator+( std::string const &s1, String const &s2 );
ZORBA_DLL_PUBLIC String operator+( String::const_pointer s1, String const &s2 );

////////// ostream insertion //////////////////////////////////////////////////

ZORBA_DLL_PUBLIC std::ostream& operator<<( std::ostream &o, String const &s );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_STRING_API_H */
/* vim:set et sw=2 ts=2: */
