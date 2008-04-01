#ifndef ZORBA_BINARY_H
#define ZORBA_BINARY_H

#include <vector>
#include "zorbatypes/xqpstring.h"

namespace zorba {

class Base64
{
private:
  std::vector<char> theData;

  static const std::string base64_chars; 

public:
  Base64(const Base64& aBase64) { theData = aBase64.theData; }
  Base64() {}
  Base64(const char* aCharStar, size_t len) { insertData(aCharStar, len); }
  Base64(const xqpString& aString) { insertData(aString.c_str(), aString.length()); }

private:
  void insertData(const char* aCharStar, size_t len);
public:
  const std::vector<char>& getData() const { return theData; }
  size_t size() const { return theData.size(); }
  bool equal(const Base64& aBase64) const;
  xqpString str() const;
};

std::ostream& operator<<(std::ostream& os, const Base64& aBase64);

class Base16
{
private:
  std::vector<char> theData;

  static const std::string base16_chars;
  static const char base16_table[0x80];

public:
  Base16(const Base16& aBase16) { theData = aBase16.theData; }
  Base16() {}
  Base16(const char* aCharStar, size_t len) { insertData(aCharStar, len);}
  Base16(const xqpString& aString) { insertData(aString.c_str(), aString.length()); }

private:
  void insertData(const char* aCharStar, size_t len);

public:
  const std::vector<char>& getData() const { return theData; }
  size_t size() const { return theData.size(); }
  bool equal(const Base16& aBase16) const;
  xqpString str() const;
};

std::ostream& operator<<(std::ostream& os, const Base16& aBase16);

} // namespace zorba

#endif
