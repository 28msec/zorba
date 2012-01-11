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

#ifndef ZORBA_UTF8_STRING_TCC
#define ZORBA_UTF8_STRING_TCC

#ifndef ZORBA_UTF8_STRING_H
#error "This file is not meant to be included directly."
#endif /* ZORBA_UTF8_STRING_H */

#include <cstring>                      /* for memcpy(3) */

namespace zorba {

template<class StringType>
typename utf8_string<StringType>::const_storage_pointer
utf8_string<StringType>::dup( size_type c_n, value_type c ) {
  utf8::encoded_char_type ec;
  size_type const ec_bytes = utf8::encode( c, ec );
  size_type const buf_size = ec_bytes * c_n + 1 /* null */;
  storage_pointer const buf = new storage_type[ buf_size ];
  storage_pointer p = buf;
  for ( size_type i = 0; i < c_n; ++i, p += ec_bytes )
    std::memcpy( p, ec, ec_bytes );
  buf[ buf_size - 1 ] = storage_type();
  return buf;
}

// UTF8_STRING_APPEND_ST_VT_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::append( size_type n, value_type c ) {
  utf8::encoded_char_type ec;
  size_type const bytes = utf8::encode( c, ec );
  s_->reserve( s_->size() + n * bytes );
  for ( ; n > 0; --n )
    s_->append( ec, bytes );
  return *this;
}

// UTF8_STRING_2ST_S_2ST_X
template<class StringType> int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  StringType const &s, size_type s_pos,
                                  size_type s_n ) const {
  char2byte const b1( s_->data(), s_->size(), pos, n );
  char2byte const b2( s.data(), s.size(), s_pos, s_n );
  return s_->compare( b1.byte_pos, b1.byte_n, s, b2.byte_pos, b2.byte_n );
}

// UTF8_STRING_2ST_SS_2ST_X
template<class StringType> int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  std_string_arg const &s, size_type s_pos,
                                  size_type s_n ) const {
  char2byte const b1( s_->data(), s_->size(), pos, n );
  char2byte const b2( s.data(), s.size(), s_pos, s_n );
  return s_->compare( b1.byte_pos, b1.byte_n, s, b2.byte_pos, b2.byte_n );
}

// UTF8_STRING_2ST_CSP_2ST_X
template<class StringType> int
utf8_string<StringType>::compare( size_type pos, size_type n,
                                  const_storage_pointer s,
                                  size_type s_n ) const {
  char2byte const b( s_->data(), s_->size(), pos, n );
  return s_->compare( b.byte_pos, b.byte_n, s, utf8::byte_pos( s, s_n ) );
}

// UTF8_STRING_FIND_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( StringType const &s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( std_string_arg const &s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( const_storage_pointer s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( const_storage_pointer s, size_type pos,
                               size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->find( s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n ) )
  );
}

// UTF8_STRING_FIND_B_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( storage_type c, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_VT_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find( value_type c, size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->find( ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec ) )
  );
}

// UTF8_STRING_RFIND_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( StringType const &s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->rfind( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_RFIND_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( std_string_arg const &s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->rfind( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_RFIND_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( const_storage_pointer s, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->rfind( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_RFIND_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( const_storage_pointer s, size_type pos,
                                size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->rfind( s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n ) )
  );
}

// UTF8_STRING_RFIND_B_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( storage_type c, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->rfind( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_RFIND_VT_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::rfind( value_type c, size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->rfind( ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec ) )
  );
}

// UTF8_STRING_FIND_FIRST_OF_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( StringType const &s,
                                        size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_OF_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( std_string_arg const &s,
                                        size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_OF_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( const_storage_pointer s,
                                        size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_OF_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( const_storage_pointer s,
                                        size_type pos, size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->find_first_of(
      s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n )
    )
  );
}

// UTF8_STRING_FIND_FIRST_OF_B_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( storage_type c, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_of( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_OF_VT_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_of( value_type c, size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->find_first_of(
      ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec )
    )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( StringType const &s,
                                            size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( std_string_arg const &s,
                                            size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( const_storage_pointer s,
                                            size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( const_storage_pointer s,
                                            size_type pos, size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->find_first_not_of(
      s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n )
    )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_B_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( storage_type c,
                                            size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_first_not_of( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_FIRST_NOT_OF_VT_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_first_not_of( value_type c,
                                            size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->find_first_not_of(
      ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec )
    )
  );
}

// UTF8_STRING_FIND_LAST_OF_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( StringType const &s,
                                       size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_OF_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( std_string_arg const &s,
                                       size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_OF_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( const_storage_pointer s,
                                       size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_OF_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( const_storage_pointer s,
                                       size_type pos, size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->find_last_of(
      s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n )
    )
  );
}

// UTF8_STRING_FIND_LAST_OF_B_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( storage_type c, size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_of( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_OF_VT_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_of( value_type c, size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->find_last_of(
      ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec )
    )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_S_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( StringType const &s,
                                           size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_SS_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( std_string_arg const &s,
                                           size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_CSP_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( const_storage_pointer s,
                                           size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_not_of( s, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_CSP_2ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( const_storage_pointer s,
                                           size_type pos, size_type n ) const {
  return utf8::char_pos(
    s_->data(),
    s_->find_last_not_of(
      s, utf8::byte_pos( s_->data(), pos ), utf8::byte_pos( s, n )
    )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_B_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( storage_type c,
                                           size_type pos ) const {
  return utf8::char_pos(
    s_->data(), s_->find_last_not_of( c, utf8::byte_pos( s_->data(), pos ) )
  );
}

// UTF8_STRING_FIND_LAST_NOT_OF_VT_ST_X
template<class StringType> typename utf8_string<StringType>::size_type
utf8_string<StringType>::find_last_not_of( value_type c, size_type pos ) const {
  utf8::encoded_char_type ec;
  return utf8::char_pos(
    s_->data(),
    s_->find_last_not_of(
      ec, utf8::byte_pos( s_->data(), pos ), utf8::encode( c, ec )
    )
  );
}

// UTF8_STRING_INSERT_ST_S_2ST_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, StringType const &s,
                                 size_type s_pos, size_type n ) {
  char2byte const b( s_->data(), s_->size(), s_pos, n );
  s_->insert(
    utf8::byte_pos( s_->data(), s_->size(), pos ), s, b.byte_pos, b.byte_n
  );
  return *this;
}

// UTF8_STRING_INSERT_ST_CSP_ST_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, const_storage_pointer s,
                                 size_type n ) {
  s_->insert(
    utf8::byte_pos( s_->data(), s_->size(), pos ), s, utf8::byte_pos( s, n )
  );
  return *this;
}

// UTF8_STRING_INSERT_2ST_VT_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::insert( size_type pos, size_type c_n, value_type c ) {
  const_storage_pointer const p = dup( c_n, c );
  insert( pos, p );
  delete[] p;
  return *this;
}

// UTF8_STRING_INSERT_I_VT_X
template<class StringType> typename utf8_string<StringType>::iterator
utf8_string<StringType>::insert( iterator pos, value_type c ) {
  size_type const offset = pos.base() - s_->begin();
  utf8::encoded_char_type ec;
  s_->insert( offset, ec, utf8::encode( c, ec ) );
  return iterator( s_->begin() + offset );
}

// UTF8_STRING_INSERT_I_ST_VT_X
template<class StringType> void
utf8_string<StringType>::insert( iterator pos, size_type c_n, value_type c ) {
  const_storage_pointer const p = dup( c_n, c );
  s_->insert( pos.base() - s_->begin(), p );
  delete[] p;
}

// UTF8_STRING_REPLACE_2ST_S_2ST_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  StringType const &s,
                                  size_type s_pos, size_type s_n ) {
  char2byte const b( s_->data(), s_->size(), pos, n );
  char2byte const s_b( s.data(), s.size(), s_pos, s_n );
  s_->replace( b.byte_pos, b.byte_n, s, s_b.byte_pos, s_b.byte_n );
  return *this;
}

// UTF8_STRING_REPLACE_2ST_CSP_ST_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n,
                                  const_storage_pointer s, size_type s_n ) {
  char2byte const b( s_->data(), s_->size(), pos, n );
  s_->replace( b.byte_pos, b.byte_n, s, utf8::byte_pos( s, s_n ) );
  return *this;
}

// UTF8_STRING_REPLACE_3ST_VT_X
template<class StringType> utf8_string<StringType>&
utf8_string<StringType>::replace( size_type pos, size_type n, size_type c_n,
                                  value_type c ) {
  const_storage_pointer const p = dup( c_n, c );
  char2byte const b( s_->data(), s_->size(), pos, n );
  s_->replace( b.byte_pos, b.byte_n, p );
  delete[] p;
  return *this;
}

} // namespace zorba

#endif /* ZORBA_UTF8_STRING_TCC */
/* vim:set et sw=2 ts=2: */
