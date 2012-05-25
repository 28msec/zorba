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

// standard
#include <limits>

// local
#include "hash.h"

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

size_t hash_bytes( void const *p, size_t len, size_t seed ) {
  //
  // An adaptation of Peter J. Weinberger's (PJW) generic hashing algorithm
  // based on Allen Holub's version.  This version works for any hash code
  // size (in this case, size_t) and not only 'unsigned' as in PJW's version.
  //
  // The original PJW algorithm can be found in:
  //
  //    Fig. 7.35: Hash function hashpjw, written in C
  //    "Compilers: Principles, Techniques, and Tools," Section 7.6: "Symbol
  //    Tables," Alfred Aho, Ravi Sethi, and Jeffrey D. Ullman, Addison-Wesley,
  //    Reading, MA, 1986, pp. 435-436.
  //
  static size_t const BitsInSizeT   = sizeof( size_t ) *
                                      numeric_limits<unsigned char>::digits;
  static size_t const ThreeFourths  = BitsInSizeT * 3 / 4;
  static size_t const OneEighth     = BitsInSizeT / 8;
  static size_t const HighBits      = ~( (size_t)(~0ul) >> OneEighth );

  unsigned char const *c = reinterpret_cast<unsigned char const*>( p );
  unsigned char const *const end = c + len;
  size_t result = seed;
  while ( c < end ) {
    result = (result << OneEighth) + *c++;
    if ( size_t temp = result & HighBits )
      result = (result ^ (temp >> ThreeFourths)) & ~HighBits;
  }
  return result;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba

/* vim:set et ts=2 sw=2: */
