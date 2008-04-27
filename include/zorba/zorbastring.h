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
 * This class is a unicode encoded string that is used in Zorba.
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
  String(xqpStringStore *string);

  /** \brief Constructor to construct a String from a const char*.
   *
   * @param aString the const char* to construct the String from.
   */
  String(const char* string aString);

  /** \brief Constructor to construct a String from a std::string.
   *
   * @param aString the std::string to construct the String from.
   */
  String(const std::string& string aString);

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

  const char*
  c_str() const;

  int
  compare(const String& string) const;

  bool
  equals(const String& string) const;

  size_t
  length() const;

  bool
  empty() const;

  bool 
  operator==(const String& str) const;

  bool 
  operator!=(const String& str) const;

private:
  friend class Unmarshaller;
  xqpStringStore *m_string;
};

std::ostream& operator <<(std::ostream& os, const String& str);

} // namespace zorba

#endif
