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

#include "wordnet.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

wordnet::wordnet( zstring const &phrase, zstring const &relationship,
                  ft_int at_least, ft_int at_most ) {
  if ( phrase == "wealthy" ) {
    cout << "-> found phrase in thesaurus\n";
    synonyms_.push_back( "affluent" );
    synonyms_.push_back( "loaded" );
    synonyms_.push_back( "rich" );
    synonyms_.push_back( "wealthy" );
    synonyms_.push_back( "well off" );
    synonyms_.push_back( "well to do" );
    i_ = synonyms_.begin();
  }
}

wordnet::~wordnet() {
  // do nothing
}

bool wordnet::next( zstring *synonym ) {
  if ( !synonyms_.empty() && i_ != synonyms_.end() ) {
    synonym->assign( *i_ );
    ++i_;
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
