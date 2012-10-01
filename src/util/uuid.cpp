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

#include "stdafx.h"
#include <zorba/config.h>

#include <cstdio>                       /* for sprintf(3) */

#if defined( __APPLE__ )
# include <cstring>                     /* for memcpy(3) */
# include <CoreFoundation/CoreFoundation.h>
#elif defined( ZORBA_HAVE_UUID_H )
# include <uuid/uuid.h>
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
#if defined( __APPLE__ )
  CFUUIDRef uuid_ref = CFUUIDCreate( NULL );
  CFUUIDBytes uuid_bytes = CFUUIDGetUUIDBytes( uuid_ref );
  CFRelease( uuid_ref );
  ::memcpy( result->data, &uuid_bytes, sizeof result->data );
#elif defined( ZORBA_HAVE_UUID_H )
  uuid_generate( result->data );
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
  value_type const temp = data[6] & 0xF0u;
  switch ( temp ) {
    case time_based:
    case dce_security:
    case name_based_md5:
    case random_number_based:
    case name_based_sha1:
      return static_cast<version>( temp );
    default:
      return unknown;
  }
}

///////////////////////////////////////////////////////////////////////////////

ostream& operator<<( ostream &os, uuid const &u ) {
  char buf[37];
  sprintf(                              // verbose & tedious, but fast
    buf,
    "%02x%02x%02x%02x-%02x%02x-%02x%02x-%02x%02x-%02x%02x%02x%02x%02x%02x",
    u.data[ 0], u.data[ 1], u.data[ 2], u.data[ 3],
    u.data[ 4], u.data[ 5], u.data[ 6], u.data[ 7],
    u.data[ 8], u.data[ 9], u.data[10], u.data[11],
    u.data[12], u.data[13], u.data[14], u.data[15]
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
