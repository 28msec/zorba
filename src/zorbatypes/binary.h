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

namespace serialization {
  class Archiver;
  void operator&( Archiver&, Base64& );
  void operator&( Archiver&, Base16& );
}

///////////////////////////////////////////////////////////////////////////////

class Base64 {
public:
  typedef std::vector<char> value_type;
  typedef value_type::size_type size_type;

  static bool parseString( char const *data, size_type size, Base64 &to );

  static bool parseString( zstring const &s, Base64 &to ) {
    return parseString( s.data(), s.size(), to );
  }

  static void decode( std::istream&, zstring* );

  static void decode( char const*, size_type, zstring* );

public:
  Base64();
  Base64( Base64 const &b64 );
  Base64( const char *data, size_type size, bool is_encoded );
  explicit Base64( Base16 const &b16 );

  size_t alloc_size() const;
  Base64& assign( char const *data, size_type size, bool is_encoded );
  value_type const& data() const;
  uint32_t hash() const;
  size_type size() const;
  zstring str() const;

private:
  value_type data_;                     // stored encoded

  friend void serialization::operator&( serialization::Archiver&, Base64& );
};

///////////////////////////////////////////////////////////////////////////////

inline Base64::Base64() {
}

inline Base64::Base64( Base64 const &b64 ) : data_( b64.data_ ) {
}

inline Base64::Base64( const char *data, size_type size, bool is_encoded ) {
  assign( data, size, is_encoded );
}

inline size_t Base64::alloc_size() const {
  return ztd::alloc_sizeof( data_ );
}

inline Base64::value_type const& Base64::data() const {
  return data_;
}

inline Base64::size_type Base64::size() const {
  return data_.size();
}

inline zstring Base64::str() const {
  return size() ? zstring( &data_[0], size() ) : zstring();
}

inline bool operator==( Base64 const &a, Base64 const &b ) {
  return a.size() == b.size()
      && std::strncmp( &a.data()[0], &b.data()[0], a.size() ) == 0;
}

inline bool operator!=( Base64 const &a, Base64 const &b ) {
  return !(a == b);
}

inline std::ostream& operator<<( std::ostream &o, Base64 const &b64 ) {
  if ( b64.size() )
    o.write( &b64.data()[0], b64.size() );
  return o;
}

///////////////////////////////////////////////////////////////////////////////

class Base16 {
public:
  typedef std::vector<char> value_type;
  typedef value_type::size_type size_type;

  static bool parseString( char const *data, size_type size, Base16 &to );

  static bool parseString( zstring const &s, Base16 &to ) {
    return parseString( s.data(), s.size(), to );
  }

  static void encode( value_type const&, value_type& );

public:
  Base16();
  Base16( Base16 const &from );
  Base16( char const *data, size_type size, bool is_encoded );
  explicit Base16( Base64 const& );
  
  size_t alloc_size() const;
  Base16& assign( char const *data, size_type size, bool is_encoded );
  value_type const& data() const;
  uint32_t hash() const;
  size_type size() const;
  zstring str() const;

private:
  value_type data_;                     // stored encoded

  friend void serialization::operator&(serialization::Archiver&, Base16&);
};

///////////////////////////////////////////////////////////////////////////////

inline Base16::Base16() {
}

inline Base16::Base16( Base16 const &b16 ) : data_( b16.data_ ) {
}

inline Base16::Base16( char const *data, size_type size, bool is_encoded ) {
  assign( data, size, is_encoded );
}

inline size_t Base16::alloc_size() const {
  return ztd::alloc_sizeof( data_ );
}

inline Base16::value_type const& Base16::data() const {
  return data_;
}

inline Base16::size_type Base16::size() const {
  return data_.size();
}

inline zstring Base16::str() const {
  return size() ? zstring( &data_[0], size() ) : zstring();
}

inline bool operator==( Base16 const &a, Base16 const &b ) {
  return a.size() == b.size()
      && std::strncmp( &a.data()[0], &b.data()[0], a.size() ) == 0;
}

inline bool operator!=( Base16 const &a, Base16 const &b ) {
  return !(a == b);
}

inline std::ostream& operator<<( std::ostream &o, Base16 const &b16 ) {
  if ( b16.size() )
    o.write( &b16.data()[0], b16.size() );
  return o;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

#endif /* ZORBA_ZORBATYPES_BINARY_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
