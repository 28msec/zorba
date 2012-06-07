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

// zorba
#include <zorba/config.h>

// standard
#include <functional>
#include <string>
#include <sys/types.h>

// Exactly ONE of these should be defined.
#define ZORBA_HASH_FN_FNV_1a  1 /* Fowler/Noll/Vo (FNV-1a) algorithm */
//#define ZORBA_HASH_FN_PJW     1 /* Peter J. Weinberger's (PJW) algorithm */

///////////////////////////////////////////////////////////////////////////////

namespace zorba {

template<class RepType> class rstring;

namespace ztd {

#ifdef ZORBA_HASH_FN_FNV_1a
#if ZORBA_SIZEOF_SIZE_T == 4
size_t const Hash_Init    = 2166136261ul;
size_t const Hash_Prime   = 16777619ul;
#elif ZORBA_SIZEOF_SIZE_T == 8
size_t const Hash_Init    = 14695981039346656037ul;
size_t const Hash_Prime   = 1099511628211ul;
#endif /* ZORBA_SIZEOF_SIZE_T */
#endif /* ZORBA_HASH_FN_FNV_1a */

#ifdef ZORBA_HASH_FN_PJW
size_t const Hash_Init    = 3339675911ul;
#endif /* ZORBA_HASH_FN_PJW */

/**
 * Generic hash function that hashes a byte sequence.
 *
 * @param p A pointer to the first byte in the sequence to hash.
 * @param len The number of bytes in the sequence.
 * @param init The initialization value.
 * @return Returns the hash code for the given byte sequence.
 */
size_t hash_bytes( void const *p, size_t len, size_t init = Hash_Init );

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

#ifndef ZORBA_HAVE_UNORDERED_MAP

/**
 * The generic %hash unary_function class.
 *
 * @tparam T The type to hash.
 */
template<typename T>
struct hash : unary_function<T,size_t> {
  size_t operator()( T ) const; // not defined
};

#define ZORBA_INTEGRAL_HASH(T)              \
  template<> inline                         \
  size_t hash<T>::operator()( T a ) const { \
    return static_cast<size_t>( a );        \
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
size_t hash<float>::operator()( float v ) const {
  return v != 0.0F ? zorba::ztd::hash_bytes( v ) : 0;
}

/** Specialization for \c double. */
template<> inline
size_t hash<double>::operator()( double v ) const {
  return v != 0.0 ? zorba::ztd::hash_bytes( v ) : 0;
}

/** Partial specialization for pointer types. */
template<typename T>
struct hash<T*> : unary_function<T*,size_t> {
  size_t operator()( T *p ) const {
    return reinterpret_cast<size_t>( p );
  }
};

/** Specialization for \c string. */
template<typename CharT,class Traits,class Alloc>
struct hash< basic_string<CharT,Traits,Alloc> > :
  unary_function<basic_string<CharT,Traits,Alloc> const&,size_t>
{
  size_t operator()( basic_string<CharT,Traits,Alloc> const &s ) const {
    return zorba::ztd::hash_bytes( s.data(), s.size() );
  }
};

#endif /* ZORBA_HAVE_UNORDERED_MAP */

/** Specialization for \c rstring. */
template<class RepType>
struct hash< zorba::rstring<RepType> > :
  unary_function<zorba::rstring<RepType> const&,size_t>
{
  size_t operator()( zorba::rstring<RepType> const &s ) const {
    return zorba::ztd::hash_bytes( s.data(), s.size() );
  }
};

} // namespace std

///////////////////////////////////////////////////////////////////////////////

#endif  /* ZORBA_HASH_H */
/* vim:set et ts=2 sw=2: */
