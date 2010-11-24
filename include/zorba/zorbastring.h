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

#include <string>

#include <zorba/config.h>

namespace zorba {

class Unmarshaller;

/** \brief The Zorba String class.
 *
 * The interface of this class is similar to that of std::string. However, it contains Unicode 
 * characters encoded as UTF-8.
 * UTF-8 FAQ @see [http://unicode.org/faq/utf_bom.html#2].
 */
class ZORBA_DLL_PUBLIC String 
{
public:
  /**
   * \brief Empty default constructor
   */
  String();

  /** \brief Copy constructor
   */
  String( String const &s );

  /** \brief Constructor to construct a String from a const char*.
   *
   * @param aString the const char* to construct the String from.
   */
  String( char const *s );

  /** \brief Constructor to construct a String from a std::string.
   *
   * @param s the std::string to construct the String from.
   */
  String( std::string const &s );

  /** \brief Destructor
   */
  ~String();

  /** \brief Assignment operator
   */
  String& 
  operator=(const String& other);

  /** \brief Returns a non-modifiable standard C character array version of the string.
   *
   * @return const char*  a const pointer to a UTF-8 encoded C string, identical to the current string. 
   *         The returned string is null-terminated.
   */
  const char*
  c_str() const;

  /** \brief Compares two strings.
   *
   * @return -1 if this \< aString, 0 if this == aString, 1 if this \> aString.
   */
  int
  compare(const String& aString) const;

  /** \brief Compares two strings.
   *
   * @return true if this == aString.
   * @see byteEqual().
   */
  bool
  equals(const String& aString) const;

  /** \brief Returns the number of characters in the string, not including any null-termination.
   *
   * @return The number of UTF-8 characters.
   * @see bytes(), empty().
   */
  size_t
  length() const;

  /** \brief Returns the number of bytes in the string, not including any null-termination.
   *
   * @return The number of bytes.
   * @see length(), empty().
   */
  size_t
  bytes() const;

  /** \brief Returns the real number of characters in the string. 
   *         Not including any null-termination, and withouth considering UTF-8 encodings.
   *
   * @return The number characters.
   */
  size_t
  nr_of_chars() const;

  /** \brief True if the string has no characters.
   *
   * @return True if the string has no elements, false otherwise.
   * @see length(), bytes().
   */
  bool
  empty() const;

  bool
  operator==(const String& str) const;

  bool
  operator!=(const String& str) const {
    return !(*this == str);
  }

  bool
  operator<(const String& str) const;

  bool
  operator<=(const String& str) const;

  bool
  operator>(const String& str) const;

  bool
  operator>=(const String& str) const;

  String
  operator+(const String& str) const {
    return append( str );
  }

  String
  operator+(const char* str) const {
    return append( str );
  }
  
  String&
  operator+=(const String& str);

  String&
  operator+=(const char* str);

  /** \brief Byte by byte comparison of two strings.
   *
   */  
  bool
  byteEqual( char const *s, unsigned s_n ) const;

  /** \brief Locate in "this" the first occurrence of the "pattern" substring.
   *
   * @return The offset into this of the start of "pattern", or -1 if not found.
   */  
  int
  indexOf(const char* pattern) const;

  /** \brief Locate in "this" the last occurrence of the "pattern" substring.
   *
   * @return The offset into this of the start of "pattern", or -1 if not found.
   */  
  int
  lastIndexOf(const char* pattern) const;

  /** \brief Determine if "pattern" is a suffix of "this".
   *
   * @return True if "this" ends with "pattern".
   */  
  bool
  endsWith(const char* pattern) const;

  /** \brief Determine if "pattern" is a prefix of "this".
   *
   * @return True if "this" starts with "pattern".
   */  
  bool
  startsWith(const char* pattern) const;

  /** \brief Returns a new zorba::String containing the substring of "this"
   *         starting at a certain index.
   *
   * @return The substring of "this" starting at index "aIndex".
   */  
  String
  substring( unsigned pos ) const;

  /** \brief Returns a new zorba::String containing the substring of "this"
   *         starting at a certain index and a certain length.
   *
   * @return The substring of "this" starting at index "aIndex"
   *         having the length "aLength".
   */  
  String
  substring( unsigned pos, unsigned n ) const;

  /** \brief Returns the character in "this" at certain position.
   *
   * @return The char in "this" at position "aIndex".
   *         having the length "aLength".
   */  
  char
  charAt(unsigned aIndex) const;

  /** \brief Appends the suffix characters to the string in "this".
   *
   * @return A new zorba::String containing the string in "this" suffixed
   *         with the charactes in "suffix".
   */  
  String
  append(const char* suffix) const;

  /** \brief Appends the suffix string to the string in "this".
   *
   * @return A new zorba::String containing the string in "this" suffixed
   *         with the "suffix" string.
   */  
  String
  append(const String& suffix) const;

  /** \brief Convert to uppercase.
   *
   * @return String the String convert to uppercase.
   */  
  String&
  uppercase();

  /** \brief Convert to lowercase.
   *
   * @return String the String convert to lowercase.
   */  
  String&
  lowercase();

  /** \brief Returns the value of "this" with whitespace normalized by stripping leading 
   *         and trailing whitespace and replacing sequences of one or more than one 
   *         whitespace character with a single space, \#x20.
   *
   * @note whitespace = " \t\r\n" meaning (\#x20) (\#x9) (\#xD) (\#xA).
   * @return String the whitespace normalized String.
   */  
  String&
  normalizeSpace();

  /** \brief Removes leading and trailing characters from this string.
   *
   * @param chars A string containing the characters to be trimmed.
   */  
  String&
  trim(String const &chars);

  /** \brief Removes leading and trailing characters from this string.
   *
   * @param chars An array containing the characters to be trimmed.
   * @param lengthOfChars The length of the chars array.
   */  
  String&
  trim(const char* chars, int lengthOfChars);

  /** \brief Removes leading and trailing whitespace.
   *
   * @note whitespace is any of the following: ' ', '\n', '\r', '\t'
   */  
  String&
  trim();

  /** \brief Escape all characters except US-ASCII coded character set.
   *
   */
  String&
  formatAsXML();

  /** \brief Escape all characters except printable characters of the US-ASCII coded character set, 
   *         specifically the octets ranging from 32 to 126 (decimal).
   *
   */
  String&
  escapeHtmlUri();

  /** \brief Converts an String containing an IRI into a URI.
   *         see Section 3.1 [http://www.ietf.org/rfc/rfc3987.txt]
   *
   */
  String&
  iriToUri();

  /** \brief Encodes reserved characters in an String that is intended to be used in the 
   *         path segment of a URI.
   *         see Section 2 [http://www.ietf.org/rfc/rfc3986.txt]
   *
   */
  String&
  encodeForUri();

  /** \brief Decodes the encoded characters from this String.
   *         see Section 2 [http://www.ietf.org/rfc/rfc3986.txt]
   *
   */
  String&
  decodeFromUri();

  /** \brief tokenizes a String
    */
  String tokenize( String const &pattern, String const &flags,
                   int32_t* startPos, bool* hasMatched ) const;

  friend ZORBA_DLL_PUBLIC
  std::ostream& operator<<( std::ostream& os, String const& );

private:

  // Using a struct guarantees correct struct/class alignment.
  struct string_storage_type {
    void *rep_storage;
#ifndef NDEBUG
    void *debug_str_storage;
#endif /* NDEBUG */
  };

  string_storage_type string_storage_;

  // Using a struct prevents void* ambiguity with char*.
  struct zstring_ptr { void const *ptr; };

  String( zstring_ptr );

  String& operator=( zstring_ptr );

  static void size_check();

  friend class Unmarshaller;
};

} // namespace zorba

#endif /* ZORBA_STRING_API_H */
/* vim:set et sw=2 ts=2: */
