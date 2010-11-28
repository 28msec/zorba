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
#include "wn_synset.h"
#include "wn_types.h"

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

void synset::parse( unsigned char const *p ) {
  int junk = 0;

  if ( (pos_ = part_of_speech::find( *p++ )) == part_of_speech::unknown )
    ++junk; // TODO: throw exception

  for ( unsigned n_lemmas = decode_base128( &p ); n_lemmas > 0; --n_lemmas )
    lemma_ids_.push_back( decode_base128( &p ) );

  for ( unsigned n_ptrs = decode_base128( &p ); n_ptrs > 0; --n_ptrs ) {
    synset::ptr ptr;
    if ( (ptr.pos_ = part_of_speech::find( *p++ )) == part_of_speech::unknown )
      ++junk; // TODO: throw exception
    if ( (ptr.type_ = zorba::wordnet::pointer::find( *p++ )) ==
          zorba::wordnet::pointer::unknown )
      ++junk; // TODO: throw exception
    ptr.synset_id_ = decode_base128( &p );
    ptr.source_    = decode_base128( &p );
    if ( ptr.source_ )
      ptr.target_ = decode_base128( &p );
    ptr_list_.push_back( ptr );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

/* vim:set et sw=2 ts=2: */
