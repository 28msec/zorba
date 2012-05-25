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

#ifndef ZORBA_HASH_H
#define ZORBA_HASH_H

// standard
#include <functional>
#include <string>
#include <sys/types.h>

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

template<class RepType> class rstring;

namespace ztd {

/**
 * Generic hash function that hashes a byte sequence.
 *
 * @param p A pointer to the first byte in the sequence to hash.
 * @param len The number of bytes in the sequence.
 * @param seed The seed value.
 * @return Returns the hash code for the given byte sequence.
 */
size_t hash_bytes( void const *p, size_t len,
                   size_t seed = static_cast<size_t>( 0xC70F6907ul ) );

/**
 * Generic hash function that hashes the memory occupied by a value of some
 * type \a T.
 *
 * @tparam T The value's type.
 * @param v The value to hash.
 * @return Returns the hash code for the given value.
 */
template<typename T> inline
size_t hash_bytes( T const &v ) {
  return hash_bytes( &v, sizeof( v ) );
}

} // namespace ztd
} // namespace zorba

///////////////////////////////////////////////////////////////////////////////

namespace std {

/**
 * The generic %hash unary_function class.
 *
 * @tparam T The type to hash.
 */
template<typename T>
struct hash : unary_function<T,size_t> {
  typedef T argument_type;
  typedef size_t result_type;
  result_type operator()( argument_type ) const; // not defined
};

#define ZORBA_INTEGRAL_HASH(T)                                        \
  template<> inline                                                   \
  hash<T>::result_type hash<T>::operator()( argument_type a ) const { \
    return static_cast<size_t>( a );                                  \
  }

ZORBA_INTEGRAL_HASH( bool )
ZORBA_INTEGRAL_HASH( char )
ZORBA_INTEGRAL_HASH( signed char )
ZORBA_INTEGRAL_HASH( wchar_t )
ZORBA_INTEGRAL_HASH( short )
ZORBA_INTEGRAL_HASH( int )
ZORBA_INTEGRAL_HASH( long )
ZORBA_INTEGRAL_HASH( long long )
ZORBA_INTEGRAL_HASH( unsigned char )
ZORBA_INTEGRAL_HASH( unsigned short )
ZORBA_INTEGRAL_HASH( unsigned int )
ZORBA_INTEGRAL_HASH( unsigned long )
ZORBA_INTEGRAL_HASH( unsigned long long )

#undef ZORBA_INTEGRAL_HASH

/** Specialization for \c float. */
template<> inline
hash<float>::result_type hash<float>::operator()( float v ) const {
  return v != 0.0F ? zorba::ztd::hash_bytes( v ) : 0;
}

/** Specialization for \c double. */
template<> inline
hash<double>::result_type hash<double>::operator()( double v ) const {
  return v != 0.0 ? zorba::ztd::hash_bytes( v ) : 0;
}

/** Specialization for \c string. */
template<typename CharT,class Traits,class Alloc>
struct hash< basic_string<CharT,Traits,Alloc> > :
  unary_function<basic_string<CharT,Traits,Alloc> const&,size_t>
{
  typedef basic_string<CharT,Traits,Alloc> const& argument_type;
  typedef size_t result_type;

  result_type operator()( argument_type s ) const {
    return zorba::ztd::hash_bytes( s.data(), s.size() );
  }
};

/** Specialization for \c rstring. */
template<class RepType>
struct hash< zorba::rstring<RepType> > :
  unary_function<zorba::rstring<RepType> const&,size_t>
{
  typedef zorba::rstring<RepType> const& argument_type;
  typedef size_t result_type;

  result_type operator()( argument_type s ) const {
    return zorba::ztd::hash_bytes( s.data(), s.size() );
  }
};

} // namespace std

///////////////////////////////////////////////////////////////////////////////

#endif  /* ZORBA_HASH_H */
/* vim:set et ts=2 sw=2: */
