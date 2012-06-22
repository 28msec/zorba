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
#pragma once
#ifndef ZORBA_ZORBATYPES_BINARY_H
#define ZORBA_ZORBATYPES_BINARY_H

#include <vector>
#include <stdio.h>
#include <zorba/config.h>

#include "zorbatypes/zstring.h"

namespace zorba {


class Base16;
class Base64;

namespace serialization 
{
  class Archiver;
  void operator&(Archiver& ar, Base64& obj);
  void operator&(Archiver& ar, Base16& obj);
}


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC Base64
{
  friend void serialization::operator&(serialization::Archiver& ar, Base64& obj);

private:
  std::vector<char> theData;

public:
  static bool parseString(const zstring& aString, Base64& aBase64) 
  {
    return parseString(aString.c_str(), aString.size(), aBase64);
  }

  static bool parseString(const char* aString, size_t aLength, Base64& aBase64);

  static bool parseString(
        const char* aString, 
        size_t aLength,
        Base64& aBase64,
        std::string& lErrorMessage);

  static zstring encode(std::istream& aStream);

  static void encode(std::istream& aStream, Base64& aResult);

  static void encode(const zstring& aString, Base64&);

  static void encode(const std::vector<char>&, std::vector<char>&);

  static void encode(
        const unsigned char* aSource, 
        unsigned int in_len,
        Base64& aResult);

  static void decode(const std::vector<char>&, std::vector<char>&);

  static void decode(std::istream& aStream, zstring*);

  static void decode(char const*, size_t, zstring*);

public:
  Base64(const Base64& aBase64) 
  {
    theData = aBase64.theData;
  }

  explicit Base64(const Base16& aBase16);

  Base64(const unsigned char *bin_data, size_t len);

  Base64() {}

  const std::vector<char>& getData() const { return theData; }

  size_t size() const { return theData.size(); }

  bool equal(const Base64& aBase64) const;

  zstring str() const;

  zstring decode() const;

  void decode(std::vector<char>&);

  uint32_t hash() const;
};


std::ostream& operator<<(std::ostream& os, const Base64& aBase64);


/*******************************************************************************

********************************************************************************/
class ZORBA_DLL_PUBLIC Base16
{
  friend void serialization::operator&(serialization::Archiver& ar, Base16& obj);

private:
  std::vector<char> theData;

  static const char* ENCODE_TABLE; 
  static const unsigned char DECODE_TABLE[0x80];
  static size_t ENCODE_INPUT;
  static size_t ENCODE_OUTPUT;
  static size_t DECODE_INPUT;
  static size_t DECODE_OUTPUT;

public:
  static bool parseString(const zstring& aString, Base16& aBase16) 
  {
    return parseString(aString.c_str(), aString.size(), aBase16);
  }

  static bool parseString(const char* aString, size_t aLength, Base16& aBase16);

  static void encode(const std::vector<char>&, std::vector<char>&);

  static void decode(const std::vector<char>&, std::vector<char>&);

public:
  Base16(const Base16& aBase16) 
  {
    theData = aBase16.theData;
  }
  
  explicit Base16(const Base64& aBase64);
  
  Base16() {}
  
  virtual ~Base16() {}

  const std::vector<char>& getData() const { return theData; }

  size_t size() const { return theData.size(); }

  bool equal(const Base16& aBase16) const;

  zstring str() const;

  uint32_t hash() const;

private:
  void insertData(const char* aCharStar, size_t len);
};


std::ostream& operator<<(std::ostream& os, const Base16& aBase16);

} // namespace zorba

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
