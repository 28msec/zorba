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

#include "util/mem_sizeof.h"
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

///////////////////////////////////////////////////////////////////////////////

class Base64
{
  friend void serialization::operator&(serialization::Archiver&, Base64&);

private:
  std::vector<char> theData;            // stored encoded

public:
  static bool parseString( zstring const &s, Base64 &to )
  {
    return parseString( s.data(), s.size(), to );
  }

  static bool parseString(char const *s, size_t aLength, Base64& to);

  static bool parseString(
        const char* aString, 
        size_t aLength,
        Base64& aBase64,
        std::string& lErrorMessage);

  static zstring encode(std::istream& aStream);

  static void encode(std::istream& aStream, Base64& to);

  static void encode(const zstring& aString, Base64&);

  static void encode(const std::vector<char>&, std::vector<char>&);

  static void encode(char const *from, size_t from_len, Base64 &to);

  static void encode(unsigned char const *from, size_t from_len, Base64& to) {
    return encode( (char const*)from, from_len, to );
  }

  static void decode(const std::vector<char>&, std::vector<char>&);

  static void decode(std::istream& aStream, zstring*);

  static void decode(char const*, size_t, zstring*);

public:
  Base64(const Base64& aBase64) 
  {
    theData = aBase64.theData;
  }

  explicit Base64(const Base16& aBase16);

  Base64(char const *bin_data, size_t len);

  Base64() { }

  const std::vector<char>& getData() const { return theData; }

  size_t size() const { return theData.size(); }

  bool equal(const Base64& aBase64) const;

  zstring str() const;

  zstring decode() const;

  void decode(std::vector<char>&);

  uint32_t hash() const;

  size_t alloc_size() const {
    return ztd::alloc_sizeof( theData );
  }
};

inline bool operator==( Base64 const &a, Base64 const &b ) {
  return a.equal( b );
}

inline bool operator!=( Base64 const &a, Base64 const &b ) {
  return !(a == b);
}

std::ostream& operator<<( std::ostream&, Base64 const& );

///////////////////////////////////////////////////////////////////////////////

class Base16
{
  friend void serialization::operator&(serialization::Archiver&, Base16&);

private:
  std::vector<char> theData;            // stored encoded

public:
  static bool parseString( zstring const &s, Base16 &to )
  {
    return parseString( s.data(), s.size(), to );
  }

  static bool parseString( char const *from, size_t from_len, Base16 &to );

  static void encode( std::vector<char> const&, std::vector<char>& );

  static void encode( char const *from, size_t from_len, Base16 &to );

  static void decode( std::vector<char> const&, std::vector<char>& );

public:
  Base16() { }
  
  Base16( Base16 const &from ) : theData( from.theData ) { }

  Base16( char const *bin_data, size_t len );

  explicit Base16( Base64 const& );
  
  const std::vector<char>& getData() const { return theData; }

  size_t size() const { return theData.size(); }

  bool equal( Base16 const& ) const;

  zstring str() const;

  uint32_t hash() const;

  size_t alloc_size() const {
    return ztd::alloc_sizeof( theData );
  }

private:
  void insertData( char const *from, size_t len );
};

inline bool operator==( Base16 const &a, Base16 const &b ) {
  return a.equal( b );
}

inline bool operator!=( Base16 const &a, Base16 const &b ) {
  return !(a == b);
}

std::ostream& operator<<(std::ostream&s, const Base16& );

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_ZORBATYPES_BINARY_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
