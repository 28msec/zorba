/*
 * Copyright 2006-2013 The FLWOR Foundation.
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
#include <cassert>

// local
#include "ftp_connections.h"

namespace zorba {
namespace ftp_client {

///////////////////////////////////////////////////////////////////////////////

connections::~connections() {
  for ( key_buf_map::const_iterator i = key_buf_.begin();
        i != key_buf_.end(); ++i ) {
    delete i->second;
  }
}

bool connections::delete_buf( String const &key ) {
  key_buf_map::iterator const i( key_buf_.find( key ) );
  if ( i != key_buf_.end() ) {
    delete i->second;
    key_buf_.erase( i );
    return true;
  }
  return false;
}

void connections::destroy() throw() {
  delete this;
}

curl::streambuf* connections::get_buf( String const &key ) const {
  key_buf_map::const_iterator const i( key_buf_.find( key ) );
  if ( i != key_buf_.end() )
    return i->second;
  return 0;
}

curl::streambuf* connections::new_buf( String const &key ) {
  curl::streambuf *&buf = key_buf_[ key ];
  assert( !buf );
  buf = new curl::streambuf();
  return buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
/* vim:set et sw=2 ts=2: */
