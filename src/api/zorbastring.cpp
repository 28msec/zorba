#include <zorba/zorbastring.h>
#include "util/rchandle.h"
#include "zorbatypes/xqpstring.h"
#include "api/unmarshaller.h"

namespace zorba {

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
String::equals(const String& string) const
{
  return m_string->equals(string.m_string);
}

size_t
String::length() const
{
  return m_string->numChars();
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

std::ostream& operator <<(std::ostream& os, const String& str)
{
  return os << *Unmarshaller::getInternalString(str);
}


}
