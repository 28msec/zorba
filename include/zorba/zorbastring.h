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

class String 
{
public:
  String(const String& other);
  String(xqpStringStore *string);
  String(const char* string);
  String(const std::string& string);
  ~String();

  const char*
  c_str() const;

  const String& 
  operator =(const String& other);

  const String&
  operator =(xqpStringStore *other);

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
