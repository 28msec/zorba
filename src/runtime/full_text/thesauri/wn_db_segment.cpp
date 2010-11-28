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

#include "wn_db_segment.h"

using namespace std;

namespace zorba {
namespace wordnet {

void db_segment::set_file( mmap_file const &file, seg_id id ) {
  mmap_file::const_iterator c = begin_ = file.begin();
  size_type const *p = reinterpret_cast<size_type const*>( c );
  num_entries_ = p[0];
  for ( int i = id; i > 0; --i ) {
    c += sizeof( num_entries_ ) + num_entries_ * sizeof( off_t );
    p = reinterpret_cast<size_type const*>( c );
    num_entries_ = p[0];
  }
  offset_ = reinterpret_cast<off_t const*>( &p[1] );
}

} // namespace wordnet
} // namespace zorba

/* vim:set et sw=2 ts=2: */
