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

// local
#include "hash.h"

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

size_t hash_bytes( void const *p, size_t len, size_t seed ) {
  //
  // "The 'hashpjw' hashing algorithm," by P. J. Weinberger, "Compilers:
  // Principles, Techniques, and Tools," Alfred Aho, Ravi Sethi, and Jeffrey D.
  // Ullman, Addison-Wesley, Reading, MA, 1986, pp. 435-436.
  //
  unsigned char const *c = reinterpret_cast<unsigned char const*>( p );
  unsigned char const *const end = c + len;
  size_t result = seed;
  while ( c < end ) {
    result = (result << 4) + *c++;
    if ( size_t temp = result & 0xF0000000 ) {
      result ^= temp >> 24;
      result ^= temp;
    }
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba

/* vim:set et ts=2 sw=2: */
