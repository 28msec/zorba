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

bool connections::delete_buf( String const &uri ) {
  conn_buf_map::const_iterator const i( conn_buf_.find( uri ) );
  if ( i != conn_buf_.end() ) {
    i->second->close();
    conn_buf_.erase( i );
    return true;
  }
  return false;
}

void connections::destroy() throw() {
  for ( conn_buf_map::const_iterator i = conn_buf_.begin();
        i != conn_buf_.end(); ++i ) {
    delete i->second;
  }
}

curl::streambuf* connections::get_buf( String const &uri ) const {
  conn_buf_map::const_iterator const i( conn_buf_.find( uri ) );
  if ( i != conn_buf_.end() )
    return i->second;
  return 0;
}

curl::streambuf* connections::new_buf( String const &uri ) {
  curl::streambuf *&buf = conn_buf_[ uri ];
  assert( !buf );
  buf = new curl::streambuf();
  return buf;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace ftp_client
} // namespace zorba
/* vim:set et sw=2 ts=2: */
