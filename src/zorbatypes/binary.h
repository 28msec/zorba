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
  static const unsigned char DECODE_TABLE[0x80];
  static size_t ENCODE_INPUT;
  static size_t ENCODE_OUTPUT;
  static size_t DECODE_INPUT;
  static size_t DECODE_OUTPUT;

public:
  Base64(const Base64& aBase64) { theData = aBase64.theData; }
  explicit Base64(const Base16& aBase16);
  Base64() {}

  static bool parseString(const xqpString& aString, Base64& aBase64) {
    return parseString(aString.c_str(), aString.length(), aBase64);
  }
  static bool parseString(const char* aString, size_t aLength, Base64& aBase64);

private:
  void insertData(const char* aCharStar, size_t len);
public:

  const std::vector<char>& getData() const { return theData; }
  size_t size() const { return theData.size(); }
  bool equal(const Base64& aBase64) const;
  xqpString str() const;

  static std::vector<char> encode(const std::vector<char>&);
  static xqpString encode(std::istream& aStream);
  static void encode(const xqpStringStore* aString, Base64&);

  static std::vector<char> decode(const std::vector<char>&);

  xqpString
  decode() const;

  uint32_t hash() const;
};

std::ostream& operator<<(std::ostream& os, const Base64& aBase64);

class Base16
{
private:
  std::vector<char> theData;

  static const char* ENCODE_TABLE; 
  static const unsigned char DECODE_TABLE[0x80];
  static size_t ENCODE_INPUT;
  static size_t ENCODE_OUTPUT;
  static size_t DECODE_INPUT;
  static size_t DECODE_OUTPUT;

public:
  Base16(const Base16& aBase16) { theData = aBase16.theData; }
  explicit Base16(const Base64& aBase64);
  Base16() {}

  static bool parseString(const xqpString& aString, Base16& aBase16) {
    return parseString(aString.c_str(), aString.length(), aBase16);
  }
  static bool parseString(const char* aString, size_t aLength, Base16& aBase16);

private:
  void insertData(const char* aCharStar, size_t len);

public:
  const std::vector<char>& getData() const { return theData; }
  size_t size() const { return theData.size(); }
  bool equal(const Base16& aBase16) const;
  xqpString str() const;

  static std::vector<char> encode(const std::vector<char>&);
  static std::vector<char> decode(const std::vector<char>&);

  uint32_t hash() const;
};

std::ostream& operator<<(std::ostream& os, const Base16& aBase16);

} // namespace zorba

#endif
