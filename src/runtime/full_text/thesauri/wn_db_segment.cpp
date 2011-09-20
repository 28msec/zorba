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

#include "wn_db_segment.h"

namespace zorba {
namespace wordnet {

db_segment::size_type const WordNet_File_Header_Size =
    + 4                                 // version char[4]
    + sizeof( uint32_t );               // endianness value

db_segment::db_segment( mmap_file const &file, id_t id ) :
  begin_( file.begin() )
{
  mmap_file::const_iterator byte_ptr = begin_ + WordNet_File_Header_Size;
  size_type const *size_ptr = reinterpret_cast<size_type const*>( byte_ptr );
  num_entries_ = size_ptr[0];
  for ( int i = id; i > 0; --i ) {
    byte_ptr += sizeof( size_type ) + num_entries_ * sizeof( offset_type );
    size_ptr = reinterpret_cast<size_type const*>( byte_ptr );
    num_entries_ = size_ptr[0];
  }
  offset_ = reinterpret_cast<offset_type const*>( &size_ptr[1] );
}

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
