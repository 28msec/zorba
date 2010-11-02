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

#include "../ft_token_seq_iterator.h"
#include "wordnet.h"

using namespace std;

namespace zorba {

wordnet::~wordnet() {
  // do nothing
}

void wordnet::lookup( FTTokenIterator &query_tokens,
                      zstring const &relationship,
                      ft_int at_least, ft_int at_most,
                      FTQueryItemSeq &result ) const {
  zstring query_phrase;
  FTToken const *qt0;

  FTTokenIterator::Mark_t const mark( query_tokens.pos() );
  for ( FTToken const *qt; (qt = query_tokens.next()); ) {
    if ( query_phrase.empty() )
      qt0 = qt;
    else
      query_phrase += ' ';
    query_phrase += qt->value();
  }
  query_tokens.pos( mark );

  // TODO: look-up query_phrase in thesaurus

  for ( int i = 0; i < 1; ++i ) {
    FTTokenSeqIterator::FTTokens thes_tokens;
    // TODO: tokenize thesaurus results
#if 0
    for ( each_token_in_current_result ) {
      FTToken const t( word, qt0->pos(), qt0->sent(), qt0->lang() );
      thes_tokens.push_back( t );
    }
#endif
    FTQueryItem const query_item( new FTTokenSeqIterator( thes_tokens ) );
    result.push_back( query_item );
  }
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
