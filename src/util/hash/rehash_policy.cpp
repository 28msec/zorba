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
#include <algorithm>
#include <cmath>
#include <iostream>

// zorba
#include <zorba/config.h>

// local
#include "rehash_policy.h"

using namespace std;

namespace zorba {
namespace ztd {

///////////////////////////////////////////////////////////////////////////////

typedef unsigned long prime_type;

static prime_type const primes[] = {
  2ul, 3ul, 5ul, 7ul, 11ul, 13ul, 17ul, 19ul, 23ul, 29ul, 31ul, 37ul, 41ul,
  43ul, 47ul, 53ul, 59ul, 61ul, 67ul, 71ul, 73ul, 79ul, 83ul, 89ul, 97ul,
  103ul, 109ul, 113ul, 127ul, 137ul, 139ul, 149ul, 157ul, 167ul, 179ul, 193ul,
  199ul, 211ul, 227ul, 241ul, 257ul, 277ul, 293ul, 313ul, 337ul, 359ul, 383ul,
  409ul, 439ul, 467ul, 503ul, 541ul, 577ul, 619ul, 661ul, 709ul, 761ul, 823ul,
  887ul, 953ul, 1031ul, 1109ul, 1193ul, 1289ul, 1381ul, 1493ul, 1613ul, 1741ul,
  1879ul, 2029ul, 2179ul, 2357ul, 2549ul, 2753ul, 2971ul, 3209ul, 3469ul,
  3739ul, 4027ul, 4349ul, 4703ul, 5087ul, 5503ul, 5953ul, 6427ul, 6949ul,
  7517ul, 8123ul, 8783ul, 9497ul, 10273ul, 11113ul, 12011ul, 12983ul, 14033ul,
  15173ul, 16411ul, 17749ul, 19183ul, 20753ul, 22447ul, 24281ul, 26267ul,
  28411ul, 30727ul, 33223ul, 35933ul, 38873ul, 42043ul, 45481ul, 49201ul,
  53201ul, 57557ul, 62233ul, 67307ul, 72817ul, 78779ul, 85229ul, 92203ul,
  99733ul, 107897ul, 116731ul, 126271ul, 136607ul, 147793ul, 159871ul,
  172933ul, 187091ul, 202409ul, 218971ul, 236897ul, 256279ul, 277261ul,
  299951ul, 324503ul, 351061ul, 379787ul, 410857ul, 444487ul, 480881ul,
  520241ul, 562841ul, 608903ul, 658753ul, 712697ul, 771049ul, 834181ul,
  902483ul, 976369ul, 1056323ul, 1142821ul, 1236397ul, 1337629ul, 1447153ul,
  1565659ul, 1693859ul, 1832561ul, 1982627ul, 2144977ul, 2320627ul, 2510653ul,
  2716249ul, 2938679ul, 3179303ul, 3439651ul, 3721303ul, 4026031ul, 4355707ul,
  4712381ul, 5098259ul, 5515729ul, 5967347ul, 6456007ul, 6984629ul, 7556579ul,
  8175383ul, 8844859ul, 9569143ul, 10352717ul, 11200489ul, 12117689ul,
  13109983ul, 14183539ul, 15345007ul, 16601593ul, 17961079ul, 19431899ul,
  21023161ul, 22744717ul, 24607243ul, 26622317ul, 28802401ul, 31160981ul,
  33712729ul, 36473443ul, 39460231ul, 42691603ul, 46187573ul, 49969847ul,
  54061849ul, 58488943ul, 63278561ul, 68460391ul, 74066549ul, 80131819ul,
  86693767ul, 93793069ul, 101473717ul, 109783337ul, 118773397ul, 128499677ul,
  139022417ul, 150406843ul, 162723577ul, 176048909ul, 190465427ul, 206062531ul,
  222936881ul, 241193053ul, 260944219ul, 282312799ul, 305431229ul, 330442829ul,
  357502601ul, 386778277ul, 418451333ul, 452718089ul, 489790921ul, 529899637ul,
  573292817ul, 620239453ul, 671030513ul, 725980837ul, 785430967ul, 849749479ul,
  919334987ul, 994618837ul, 1076067617ul, 1164186217ul, 1259520799ul,
  1362662261ul, 1474249943ul, 1594975441ul, 1725587117ul, 1866894511ul,
  2019773507ul, 2185171673ul, 2364114217ul, 2557710269ul, 2767159799ul,
  2993761039ul, 3238918481ul, 3504151727ul, 3791104843ul, 4101556399ul,
  4294967291ul,

#if ZORBA_SIZEOF_LONG < 8
  // Sentinel so we don't have to test the result of lower_bound().
  4294967291ul
#else
  6442450933ul, 8589934583ul, 12884901857ul, 17179869143ul, 25769803693ul,
  34359738337ul, 51539607367ul, 68719476731ul, 103079215087ul, 137438953447ul,
  206158430123ul, 274877906899ul, 412316860387ul, 549755813881ul,
  824633720731ul, 1099511627689ul, 1649267441579ul, 2199023255531ul,
  3298534883309ul, 4398046511093ul, 6597069766607ul, 8796093022151ul,
  13194139533241ul, 17592186044399ul, 26388279066581ul, 35184372088777ul,
  52776558133177ul, 70368744177643ul, 105553116266399ul, 140737488355213ul,
  211106232532861ul, 281474976710597ul, 562949953421231ul, 1125899906842597ul,
  2251799813685119ul, 4503599627370449ul, 9007199254740881ul,
  18014398509481951ul, 36028797018963913ul, 72057594037927931ul,
  144115188075855859ul, 288230376151711717ul, 576460752303423433ul,
  1152921504606846883ul, 2305843009213693951ul, 4611686018427387847ul,
  9223372036854775783ul, 18446744073709551557ul, 18446744073709551557ul
#endif /* ZORBA_SIZEOF_LONG */
};

static prime_type const *const primes_end =
  primes + sizeof( primes ) / sizeof( primes[0] );

///////////////////////////////////////////////////////////////////////////////

prime_rehash_policy::prime_rehash_policy( float max_load_factor ) :
  growth_factor_( 2.0F ),
  max_load_factor_( max_load_factor ),
  next_resize_( 0 )
{
}

prime_rehash_policy::size_type
prime_rehash_policy::adjust_buckets( size_type n_bkt ) const {
  prime_type const *const p = lower_bound( primes, primes_end, n_bkt );
  next_resize_ = static_cast<size_type>( ceil( *p * max_load_factor_ ) );
  return *p;
}

prime_rehash_policy::size_type
prime_rehash_policy::buckets_for_elements( size_type n_elt ) const {
  float const min_bkts = n_elt / max_load_factor_;
  prime_type const *const p = lower_bound( primes, primes_end, min_bkts );
  next_resize_ = static_cast<size_type>( ceil( *p * max_load_factor_ ) );
  return *p;
}

prime_rehash_policy::size_type
prime_rehash_policy::need_rehash( size_type n_bkt, size_type n_elt,
                                  size_type n_ins ) const {
  if ( n_elt + n_ins > next_resize_ ) {
    float min_bkts = (n_elt + n_ins) / max_load_factor_;
    if ( min_bkts > n_bkt ) {
      min_bkts = max( min_bkts, growth_factor_ * n_bkt );
      prime_type const *const p = lower_bound( primes, primes_end, min_bkts );
      next_resize_ = static_cast<size_type>( ceil( *p * max_load_factor_ ) );
      return *p;
    } else {
      next_resize_ = static_cast<size_type>( ceil( n_bkt * max_load_factor_ ) );
    }
  }
  return 0;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ztd
} // namespace zorba
/* vim:set et sw=2 ts=2: */
