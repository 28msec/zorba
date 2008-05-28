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
#ifndef ZORBA_HASHFUN_H
#define ZORBA_HASHFUN_H

#include <string>

#include "common/common.h"

/*_____________________________________________________________
|                                                              |
|  hash functions                                              |
|______________________________________________________________*/
namespace zorba {

  class hashfun
  {
    public:
#define FNV_32_PRIME    ((uint32_t)0x01000193)
#define FNV_32_INIT     ((uint32_t)0x811c9dc5)
#define FNV_64_PRIME    ((uint64_t)0x100000001b3ULL)
#define FNV_64_INIT     ((uint64_t)0x84222325cbf29ce4LL)

      /**
       * 32 bit Fowler/Noll/Vo FNV-1a hash on binary (untyped) buffer
       *
       * input:
       *  buf   - start of buffer to hash
       *  len   - length of buffer in octets
       *  hval  - previous hash value or 0 if first call
       *
       * @return 32 bit hash
       *
       */
      static inline uint32_t h32( void *buf, size_t len, uint32_t hval) 
      {
        unsigned char *bp = (unsigned char *)buf;  /* start of buffer */
        unsigned char *be = bp + len; /* beyond end of buffer */

        while (bp < be) {

          /* multiply by the 32 bit FNV magic prime mod 2^32 */
          hval *= FNV_32_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint32_t)*bp++;
        }

        return hval;
      }

      static inline uint32_t h32( const std::string& key, uint32_t hval)
      {
        return h32(key.c_str(), key.length(), hval);
      }

      /*
       * 32 bit Fowler/Noll/Vo FNV-1a hash on a null-delimited string
       *
       * input:
       *  str - string to hash
       *  hval - previous hash value or 0 if first call
       *
       * @return 32 bit hash
       *
       */
      static inline uint32_t h32( char const* str, uint32_t hval)
      {
        unsigned char *s = (unsigned char *)str; /* unsigned string */

        while (*s) {

          /* multiply by the 32 bit FNV magic prime mod 2^32 */
          hval *= FNV_32_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint32_t)*s++;
        }

        return hval;
      }

      /*
       * 32 bit Fowler/Noll/Vo FNV-1a hash on a length-delimited string
       *
       * input:
       *  str  - string to hash
       *  len   - maximum number of characters of input
       *  hval  - previous hash value or 0 if first call
       *
       * @return 32 bit hash as a static hash type
       *
       */
      static inline uint32_t h32( char const* str, size_t len, uint32_t hval)
      {
        unsigned char *s = (unsigned char *)str; /* unsigned string */

        while (*s && len-- != 0) {

          /* multiply by the 32 bit FNV magic prime mod 2^32 */
          hval *= FNV_32_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint32_t)*s++;
        }

        return hval;
      }
      
      /*
       * 32 bit Fowler/Noll/Vo FNV-1a hash a POD
       *
       * input:
       *  val_to_hash  - POD value to hash
       *  len   - maximum number of characters of input
       *  hval  - previous hash value or 0 if first call
       *
       * @return 32 bit hash as a static hash type
       *
       */
      template <typename T>
      static inline uint32_t h32(T val_to_hash, uint32_t hval)
      {
        unsigned char *s = (unsigned char *)&val_to_hash; /* unsigned char ptr */
        int len = sizeof(T);

        while (len-- != 0) {

          /* multiply by the 32 bit FNV magic prime mod 2^32 */
          hval *= FNV_32_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint32_t)*s++;
        }

        return hval;
      }

      /*
       * 32 bit Fowler/Noll/Vo FNV-1a hash on a C++ string
       *
       * input:
       *  str  - string to hash
       *
       * @return 32 bit hash as a static hash type
       *
       */
      static inline uint32_t h32( std::string const& str)
      {
        return h32(str.c_str(), FNV_32_INIT);
      }

      /*
       * 64 bit Fowler/Noll/Vo hash on binary (untyped) buffer
       *
       * input:
       *  buf - start of buffer to hash
       *  len - length of buffer in octets
       *  hval - previous hash value or 0 if first call
       *
       * returns 64 bit hash as a static hash type
       *
       */
      static uint64_t h64( void *buf, size_t len, uint64_t hval)
      {
        unsigned char *bp = (unsigned char *)buf; /* start of buffer */
        unsigned char *be = bp + len; /* beyond end of buffer */

        while (bp < be) {

          /* multiply by the 64 bit FNV magic prime mod 2^64 */
          hval *= FNV_64_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint64_t)*bp++;
        }

        return hval;
      }

      static uint64_t h64( const std::string& s, uint64_t hval)
      {
        return h64(s.c_str(), s.length(), hval);
      }

      /*
       * 64 bit Fowler/Noll/Vo hash on null-delimited char string
       *
       * input:
       * buf - start of buffer to hash
       * hval - previous hash value or 0 if first call
       *
       * returns 64 bit hash as a static hash type
       *
       */
      static uint64_t h64( char const* str, uint64_t hval)
      {
        unsigned char *s = (unsigned char *)str; /* unsigned string */
        while (*s) {

          /* multiply by the 64 bit FNV magic prime mod 2^64 */
          hval *= FNV_64_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint64_t)*s++;
        }

        return hval;
      }

      /*
       * 64 bit Fowler/Noll/Vo FNV-1a hash on a length-delimited string
       *
       * input:
       * str - string to hash
       *  len   - maximum number of characters of input
       *  hval  - previous hash value or 0 if first call
       *
       * @return 64 bit hash as a static hash type
       *
       */
      static inline uint64_t h64( char const* str, size_t len, uint64_t hval)
      {
        unsigned char *s = (unsigned char *)str; /* unsigned string */

        while (*s && len-- != 0) {

          /* multiply by the 64 bit FNV magic prime mod 2^64 */
          hval *= FNV_64_PRIME;

          /* xor the bottom with the current octet */
          hval ^= (uint64_t)*s++;
        }

        return hval;
      }

      /*
       * 64 bit Fowler/Noll/Vo FNV-1a hash on a C++ string
       *
       * input:
       *  str - string to hash
       *
       * @return 64 bit hash as a static hash type
       *
       */
      static inline uint64_t h64( std::string const& str) {
        return h64(str.c_str(), FNV_64_INIT);
      }

  };

} /* namespace zorba */
#endif /* ZORBA_HASHFUN_H */
