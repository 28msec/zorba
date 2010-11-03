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

#include <memory>                       /* for auto_ptr */

#include "util/stl_util.h"

#include "th_token_collector.h"
#include "wordnet.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

wordnet::~wordnet() {
  // do nothing
}

void wordnet::lookup( zstring const &query_phrase, int pos_no, int sent_no,
                      iso639_1::type lang, zstring const &relationship,
                      ft_int at_least, ft_int at_most,
                      FTQueryItemSeq &result ) const {

  // TODO: look-up query_phrase in thesaurus
  list<char const*> synonyms;
  if ( query_phrase == "wealthy" ) {
    cout << "-> found phrase in thesaurus\n";
    synonyms.push_back( "affluent" );
    synonyms.push_back( "loaded" );
    synonyms.push_back( "rich" );
    synonyms.push_back( "wealthy" );
    synonyms.push_back( "well off" );
    synonyms.push_back( "well to do" );
  }

  auto_ptr<Tokenizer> tokenizer( Tokenizer::create() );

  FOR_EACH( list<char const*>, synonym, synonyms ) {
    FTTokenSeqIterator::FTTokens syn_tokens;
    th_token_collector collector( pos_no, sent_no, lang, syn_tokens );

    char const *const syn = *synonym;
    int const syn_len = ::strlen( syn );

    tokenizer->tokenize( syn, syn_len, lang_, collector );
    FTQueryItem const query_item( new FTTokenSeqIterator( syn_tokens ) );
    result.push_back( query_item );
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
