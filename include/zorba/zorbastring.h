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

namespace zorba {

class xqpStringStore;

/** \brief The Zorba String class.
 *
 * The interface of this class is similar to that of std::string. However, it contains Unicode 
 * characters encoded as UTF-8.
 * UTF-8 FAQ @see [http://unicode.org/faq/utf_bom.html#2].
 */
class String 
{
public:
  /** \brief Copy constructor
   */
  String(const String& other);

  /** \brief Constructor that is used to construct Items in the Zorba engine itself.
   *
   * This constructor is for internal use only.
   */
  String(xqpStringStore* aString);

  /** \brief Constructor to construct a String from a const char*.
   *
   * @param aString the const char* to construct the String from.
   */
  String(const char* aString);

  /** \brief Constructor to construct a String from a std::string.
   *
   * @param aString the std::string to construct the String from.
   */
  String(const std::string& aString);

  /** \brief Destructor
   */
  ~String();

  /** \brief Assignment operator
   */
  const String& 
  operator =(const String& other);

  /** \brief Assingment operator that is used in the Zorba engine itself.
   *
   * This operator is for internal use only.
   */
  const String&
  operator =(xqpStringStore *other);

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
  operator!=(const String& str) const;

  /** \brief Byte by byte comparison of two strings.
   *
   */  
  bool
  byteEqual(const char* aString, unsigned int aBytes) const;

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

  /** \brief Append characters onto "this".
   *
   */  
  const String&
  append(const char* suffix);

  /** \brief Convert to uppercase.
   *
   * @return String the String convert to uppercase.
   */  
  const String&
  uppercase();

  /** \brief Convert to lowercase.
   *
   * @return String the String convert to lowercase.
   */  
  const String&
  lowercase();

  /** \brief Returns the value of "this" with whitespace normalized by stripping leading 
   *         and trailing whitespace and replacing sequences of one or more than one 
   *         whitespace character with a single space, \#x20.
   *
   * @note whitespace = " \t\r\n" meaning (\#x20) (\#x9) (\#xD) (\#xA).
   * @return String the whitespace normalized String.
   */  
  const String&
  normalizeSpace();

  /** \brief Removes leading and trailing whitespace.
   *
   * @note If called with trim(" \t\r\n", 4) it will strip leading and trailing whitespaces.
   * Whitespace = " \t\r\n" meaning (\#x20) (\#x9) (\#xD) (\#xA).
   */  
  const String&
  trim(const char* start, int len);

  /** \brief Removes leading and trailing whitespace.
   *
   * @note Space = " " meaning (\#x20).
   */  
  const String&
  trim();

  /** \brief Escape all characters except US-ASCII coded character set.
   *
   */
  const String&
  formatAsXML();

  /** \brief Escape all characters except printable characters of the US-ASCII coded character set, 
   *         specifically the octets ranging from 32 to 126 (decimal).
   *
   */
  const String&
  escapeHtmlUri();

  /** \brief Converts an String containing an IRI into a URI.
   *         see Section 3.1 [http://www.ietf.org/rfc/rfc3987.txt]
   *
   */
  const String&
  iriToUri();

  /** \brief Encodes reserved characters in an String that is intended to be used in the 
   *         path segment of a URI.
   *         see Section 2 [http://www.ietf.org/rfc/rfc3986.txt]
   *
   */
  const String&
  encodeForUri();

private:
  friend class Unmarshaller;
  xqpStringStore *m_string;
};

std::ostream& operator <<(std::ostream& os, const String& str);

} // namespace zorba

#endif
