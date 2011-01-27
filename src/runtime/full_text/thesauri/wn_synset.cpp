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

#include "zorbaerrors/error_manager.h"

#include "decode_base128.h"
#include "wn_synset.h"
#include "wn_types.h"

#define THROW_DATA_EXCEPTION(CHAR,MSG) {                        \
  ostringstream oss;                                            \
  oss << '\'' << (CHAR) << "': " MSG;                           \
  ZORBA_ERROR_DESC( XQP8402_THESAURUS_DATA_ERROR, oss.str() );  \
}

using namespace std;

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

synset::synset( char const *p ) {
  //
  // The binary format of a synset is:
  //
  //  synset = {pos}{#lemmas}{lemma#}...{#ptrs}{ptr}...
  //  pos = a | r | n | v
  //  ptr = {pos}{type}{synset#}{source}[{target}]
  //

  char c = *p++;
  if ( (pos_ = part_of_speech::find( c )) == part_of_speech::unknown )
    THROW_DATA_EXCEPTION( c, "invalid part-of-speech" );

  for ( unsigned n_lemmas = decode_base128( &p ); n_lemmas > 0; --n_lemmas )
    lemma_ids_.push_back( decode_base128( &p ) );

  for ( unsigned n_ptrs = decode_base128( &p ); n_ptrs > 0; --n_ptrs ) {
    synset::ptr ptr;

    c = *p++;
    if ( (ptr.pos_ = part_of_speech::find( c )) == part_of_speech::unknown )
      THROW_DATA_EXCEPTION( c, "invalid part-of-speech" );

    c = *p++;
    if ( (ptr.type_ = zorba::wordnet::pointer::find( c )) ==
          zorba::wordnet::pointer::unknown )
      THROW_DATA_EXCEPTION( c, "invalid pointer type" );

    ptr.synset_id_ = decode_base128( &p );
    ptr.source_    = decode_base128( &p );
    if ( ptr.source_ )
      ptr.target_ = decode_base128( &p );

    ptrs_.push_back( ptr );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

/* vim:set et sw=2 ts=2: */
