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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"

#include "decode_base128.h"
#include "wn_synset.h"
#include "wn_types.h"

using namespace std;

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

void synset::ptr_decoder::operator()( mem_ptr_type *pptr,
                                      result_type *result ) const {
  //
  // The binary format of a ptr is:
  //
  //  ptr = {pos}{type}{synset#}{source}[{target}]
  //
  result->pos_ = synset::get_pos( pptr );

  char const c = *(*pptr)++;
  if ( !(result->type_ = zorba::wordnet::pointer::find( c )) )
    throw ZORBA_EXCEPTION(
      zerr::ZXQP8403_THESAURUS_DATA_ERROR,
      ERROR_PARAMS( ZED( BadWordNetPtr_2 ), c )
    );

  result->synset_id_ = decode_base128( pptr );
  result->source_    = decode_base128( pptr );
  result->target_    = result->source_ ? decode_base128( pptr ) : 0;
}

///////////////////////////////////////////////////////////////////////////////

synset::synset( mem_ptr_type p ) :
  //
  // The binary format of a synset is:
  //
  //  synset = {pos}{#lemmas}{lemma#}...{#ptrs}{ptr}...
  //
  pos_( get_pos( &p ) ),
  lemma_ids_( base128_list_args( &p ) ),
  //
  // The constructor above leaves p pointing to the first lemma#: we need to
  // skip all the lemma#s.
  //
  ptrs_( base128_list_args( skip_lemmas( lemma_ids_.size(), &p ) ) )
{
}

part_of_speech::type synset::get_pos( mem_ptr_type *pptr ) {
  //
  // The binary format of a pos is:
  //
  //  pos = a | r | n | v
  //
  char const c = *(*pptr)++;
  if ( part_of_speech::type const pos = part_of_speech::find( c ) )
    return pos;
  throw ZORBA_EXCEPTION(
    zerr::ZXQP8403_THESAURUS_DATA_ERROR,
    ERROR_PARAMS( ZED( BadWordNetPartOfSpeech_2 ), c )
  );
}

synset::mem_ptr_type* synset::skip_lemmas( size_type n, mem_ptr_type *pptr ) {
  //
  // This custom code is faster than using decode_base128() here.
  //
  while ( n-- > 0 )
    while ( static_cast<unsigned char>( *(*pptr)++ ) & 0x80 )
      ;
  return pptr;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
