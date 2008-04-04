#include <zorba/string.h>
#include "util/rchandle.h"
#include "zorbatypes/xqpstring.h"

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


std::ostream& operator <<(std::ostream& os, const String& str)
{
  return os << *str.m_string;
}

}
