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
  friend std::ostream& operator <<(std::ostream& os, const String& str);
  xqpStringStore* getInternalString() const { return m_string; }

  xqpStringStore *m_string;
};

std::ostream& operator <<(std::ostream& os, const String& str);

} // namespace zorba

#endif
