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

#include "zorbatypes/xqpstring.h"
#include "api/unmarshaller.h"

namespace zorba {

String::String()
{
  m_string = new xqpStringStore("");
  RCHelper::addReference(m_string);
}

String::String(xqpStringStore *other)
  : m_string(other)
{
  if (m_string != NULL) {
    RCHelper::addReference(m_string);
  }
}

String::String(const String& other)
  : m_string(other.m_string)
{
  if (m_string != NULL) {
    RCHelper::addReference(m_string);
  }
}

String::String(const char* string)
{
  m_string = new xqpStringStore(string);
  RCHelper::addReference(m_string);
}

String::String(const std::string& string)
{
  m_string = new xqpStringStore(string);
  RCHelper::addReference(m_string);
}

String::~String()
{
  if (m_string != NULL) {
    RCHelper::removeReference(m_string);
  }
}

const char *String::c_str() const
{
  return m_string->c_str();
}

const String& String::operator =(const String& rhs)
{
  if (m_string != rhs.m_string) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = rhs.m_string;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String& String::operator =(xqpStringStore *rhs)
{
  if (m_string != rhs) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = rhs;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

int
String::compare(const String& string) const
{
  return m_string->compare(string.m_string);
}

bool
String::equals(const String& aString) const
{
  return m_string->equals(aString.m_string);
}

size_t
String::length() const
{
  return m_string->numChars();
}

size_t
String::bytes() const
{
  return m_string->bytes();
}

bool
String::empty()  const
{
  return m_string->empty();
}

bool 
String::operator==(const String& str) const
{
  return equals(str);
}

bool 
String::operator!=(const String& str) const
{
  return !equals(str);
}

bool
String::byteEqual(const char* aString, unsigned int aBytes) const
{
  return m_string->byteEqual( aString, aBytes );
}

int
String::indexOf(const char* pattern) const
{
  return m_string->indexOf( pattern );
}

int
String::lastIndexOf(const char* pattern) const
{
  return m_string->lastIndexOf( pattern );
}

bool
String::endsWith(const char* pattern) const
{
  return m_string->endsWith( pattern );
}

const String&
String::append(const char* suffix)
{
  xqpStringStore* res = m_string->append( suffix );
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::uppercase()
{
  xqpStringStore* res = m_string->uppercase();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::lowercase()
{
  xqpStringStore* res = m_string->lowercase();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::normalizeSpace()
{
  xqpStringStore* res = m_string->normalizeSpace();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::trim(const char* start, int len)
{
  xqpStringStore* res = m_string->trim(start, len);
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::trim()
{
  xqpStringStore* res = m_string->trim();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::formatAsXML()
{
  xqpStringStore* res = m_string->formatAsXML();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::escapeHtmlUri()
{
  xqpStringStore* res = m_string->escapeHtmlUri();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::iriToUri()
{
  xqpStringStore* res = m_string->iriToUri();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

const String&
String::encodeForUri()
{
  xqpStringStore* res = m_string->encodeForUri();
  if (m_string != res) {
    if (m_string != NULL) {
      RCHelper::removeReference(m_string);
    }
    m_string = res;
    if (m_string != NULL) {
      RCHelper::addReference(m_string);
    }
  }
  return *this;
}

std::ostream& operator <<(std::ostream& os, const String& str)
{
  return os << *Unmarshaller::getInternalString(str);
}


}
