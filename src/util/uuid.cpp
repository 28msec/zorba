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

#include <zorba/config.h>

#include <cstdio>
#if defined( ZORBA_HAVE_UUID_H )
# include <uuid/uuid.h>
#elif defined( __APPLE__ )
# include <cstring>
# include <CoreFoundation/CoreFoundation.h>
#elif defined( _WIN32 )
# include <Rpc.h>
#else
# error "Unsupported operating system for generating UUIDs"
#endif

#include "uuid.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

void uuid::create( uuid *result ) {
#if defined( ZORBA_HAVE_UUID_H )
  uuid_generate( result->data );
#elif defined( __APPLE__ )
  CFUUIDRef uuid_ref = CFUUIDCreate( NULL );
  CFUUIDBytes uuid_bytes = CFUUIDGetUUIDBytes( uuid_ref );
  CFRelease( uuid_ref );
  ::memcpy( result->data, &uuid_bytes, 16 );
#elif defined( _WIN32 )
  UuidCreateSequential( (UUID*)result->data );
#endif /* _WIN32 */
}

uuid::variant uuid::get_variant() const {
  value_type const octet8 = data[8];
  if ( (octet8 & 0x80u) == 0x00u )
    return ncs;
  if ( (octet8 & 0xC0u) == 0x80u )
    return rfc4122;
  if ( (octet8 & 0xE0u) == 0xC0u )
    return microsoft;
  return future;
}

uuid::version uuid::get_version() const {
  switch ( data[6] & 0xF0u ) {
    case 0x10u: return time_based;
    case 0x20u: return dce_security;
    case 0x30u: return name_based_md5;
    case 0x40u: return random_number_based;
    case 0x50u: return name_based_sha1;
    default   : return unknown;
  }
}

///////////////////////////////////////////////////////////////////////////////

ostream& operator<<( ostream &os, uuid const &u ) {
  uint32_t const time_low =
    (u.data[0] << 24) | (u.data[1] << 16) | (u.data[2] << 8) | u.data[3];
  uint16_t const time_mid = (u.data[4] << 8) | u.data[5];
  uint16_t const time_hi_and_version = (u.data[6] << 8) | u.data[7];
  uint8_t const clock_seq_hi_and_reserved = u.data[8];
  uint8_t const clock_seq_low = u.data[9];
  uuid::value_type const *const node = u.data + 10;
  char buf[37];
  sprintf(
    buf, "%8.8x-%4.4x-%4.4x-%2.2x%2.2x-%2.2x%2.2x%2.2x%2.2x%2.2x%2.2x",
    time_low, time_mid, time_hi_and_version, clock_seq_hi_and_reserved,
    clock_seq_low, node[0], node[1], node[2], node[3], node[4], node[5]
  );
  return os << buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
