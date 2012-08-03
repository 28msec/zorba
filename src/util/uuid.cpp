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

#if defined( __APPLE__ )
# include <cstring>
# include <CoreFoundation/CoreFoundation.h>
#elif defined( __linux__ )
# include <uuid/uuid.h>
#elif defined( _WIN32 )
# include <Rpc.h>
#else
# error "Unsupported operating system for generating UUIDs"
#endif

#include "uuid.h"

using namespace std;

namespace zorba {
namespace uuid {

///////////////////////////////////////////////////////////////////////////////

variant type::variant() const {
  value_type const octet7 = data[8];
  if ( (octet7 & 0x80) == 0x00 )
    return ncs;
  if ( (octet7 & 0xC0) == 0x80 )
    return rfc4122;
  if ( (octet7 & 0xE0) == 0xC0 )
    return microsoft;
  return future;
}

version type::version() const {
  value_type const octet9 = data[6];
  switch ( octet9 & 0xF0 ) {
    case 0x10: return time_based;
    case 0x20: return dce_security;
    case 0x30: return name_based_md5;
    case 0x40: return random_number_based;
    case 0x50: return name_based_sha1;
    default  : return unknown;
  }
}

///////////////////////////////////////////////////////////////////////////////

void create( type *result ) {
#if defined( __APPLE__ )
  CFUUIDRef uuid_ref = CFUUIDCreate( NULL );
  CFUUIDBytes bytes = CFUUIDGetUUIDBytes( uuid_ref );
  CFRelease( uuid_ref );
  ::memcpy( result, &bytes, 16 );
#elif defined( __linux__ )
  uuid_generate( (uuid_t)result );
#elif defined( _WIN32 )
  UuidCreateSequential( (UUID*)result );
#endif /* _WIN32 */
}

ostream& operator<<( ostream &os, type const &u ) {
  // TODO
  return os;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace uuid
} // namespace zorba

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
