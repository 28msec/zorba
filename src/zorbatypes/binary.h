#ifndef ZORBA_BINARY_H
#define ZORBA_BINARY_H

#include <vector>
#include "zorbatypes/xqpstring.h"

namespace zorba {

class Base16;
class Base64
{
private:
  std::vector<char> theData;

  static const char* ENCODE_TABLE; 
  static const char DECODE_TABLE[0x80];
  static size_t ENCODE_INPUT;
  static size_t ENCODE_OUTPUT;
  static size_t DECODE_INPUT;
  static size_t DECODE_OUTPUT;

public:
  Base64(const Base64& aBase64) { theData = aBase64.theData; }
  explicit Base64(const Base16& aBase16);
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

  static std::vector<char> encode(const std::vector<char>&);
  static std::vector<char> decode(const std::vector<char>&);
};

std::ostream& operator<<(std::ostream& os, const Base64& aBase64);

class Base16
{
private:
  std::vector<char> theData;

  static const char* ENCODE_TABLE; 
  static const char DECODE_TABLE[0x80];
  static size_t ENCODE_INPUT;
  static size_t ENCODE_OUTPUT;
  static size_t DECODE_INPUT;
  static size_t DECODE_OUTPUT;

public:
  Base16(const Base16& aBase16) { theData = aBase16.theData; }
  explicit Base16(const Base64& aBase64);
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

  static std::vector<char> encode(const std::vector<char>&);
  static std::vector<char> decode(const std::vector<char>&);
};

std::ostream& operator<<(std::ostream& os, const Base16& aBase16);

} // namespace zorba

#endif
