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

#ifndef ZORBA_CSV_UTIL_H
#define ZORBA_CSV_UTIL_H

// standard
#include <sstream>

// Zorba
#include <zorba/util/mem_streambuf.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

struct csv_parse_json_state {
  std::istringstream iss_;

  csv_parse_json_state() {
    iss_.std::ios::rdbuf( &buf_ );
  }

  void set_data( char const *s, size_t size ) {
    buf_.set( const_cast<char*>( s ), size );
    iss_.seekg( 0 );
	iss_.clear();
  }

private:
  mem_streambuf buf_;
};

namespace missing {
  enum type {
    null,
    omit,
    error
  };
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_CSV_UTIL_H */
/* vim:set et sw=2 ts=2: */
