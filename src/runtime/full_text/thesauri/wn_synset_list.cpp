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

#include "decode_base128.h"
#include "wn_synset_list.h"

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

synset_list::synset_list( thes_seg::const_iterator const &i ) :
  b_( reinterpret_cast<byte const*>( *i ) )
{
  while ( *b_++ ) ;                     // skip past lemma
  size_ = decode_base128( &b_ );
}

///////////////////////////////////////////////////////////////////////////////

synset_list::byte const synset_list::const_iterator::end_value_ = 0;

synset_list::const_iterator& synset_list::const_iterator::operator++() {
  if ( !b_ || b_ == &end_value_ ) {
    //
    // If b_'s value is the "already at end" value (null), or the "just hit
    // end" value, set to the "already at end" value.
    //
    b_ = 0;         
    return *this;
  }

  int junk = 0;

  if ( (v_.pos_ = part_of_speech::find( *b_++ )) == part_of_speech::unknown )
    ++junk; // TODO: throw exception

  for ( unsigned n_lemmas = decode_base128( &b_ ); n_lemmas > 0; --n_lemmas ) {
    v_.lemma_ids_.push_back( decode_base128( &b_ ) );
  }

  for ( unsigned n_ptrs = decode_base128( &b_ ); n_ptrs > 0; --n_ptrs ) {
    synset::ptr ptr;
    if ( (ptr.pos_ = part_of_speech::find( *b_++ )) == part_of_speech::unknown )
      ++junk; // TODO: throw exception
    if ( (ptr.type_ = pointer::find( *b_++ )) == pointer::unknown )
      ++junk; // TODO: throw exception
    ptr.synset_id_ = decode_base128( &b_ );
    ptr.source_    = decode_base128( &b_ );
    if ( ptr.source_ )
      ptr.target_ = decode_base128( &b_ );
    v_.ptr_list_.push_back( ptr );
  }

  return *this;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

/* vim:set et sw=2 ts=2: */
