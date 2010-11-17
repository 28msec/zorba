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

#include <algorithm>
#include <utility>                      /* for pair */

#include "util/ascii_util.h"
#include "util/less.h"
#include "util/mmap_file.h"

#include "wn_thesaurus.h"
#include "wn_thes_seg.h"
#include "wn_types.h"

using namespace std;

namespace zorba {
namespace wordnet {

typedef pair<thes_seg::const_iterator,thes_seg::const_iterator> lemma_range;

///////////////////////////////////////////////////////////////////////////////

#if 1
static mmap_file const& get_thesaurus_file() {
  static mmap_file thesaurus_file;
  if ( !thesaurus_file )
    thesaurus_file.open( "" ); // TODO
  return thesaurus_file;
}
#endif

///////////////////////////////////////////////////////////////////////////////

thesaurus::thesaurus( zstring const &phrase, zstring const &relationship,
                      ft_int at_least, ft_int at_most ) {
  zstring relationship_lower;
  ascii::to_lower( relationship, &relationship_lower );

  pointer::type ptr_type;
  if ( iso2788::rel_type iso_rel = iso2788::find_rel( relationship_lower ) )
    ptr_type = pointer::map_iso_rel( iso_rel );
  else
    ptr_type = pointer::find( relationship_lower );

  static thes_seg const lemmas ( get_thesaurus_file(), thes_seg::id_lemma  );
  static thes_seg const synsets( get_thesaurus_file(), thes_seg::id_synset );

  // always include the original phrase
  synonyms_.push_back( phrase.c_str() );

#if 0
  lemma_range const range = ::equal_range(
    lemmas.begin(), lemmas.end(), phrase, comparator
  );
  if ( range.first == lemmas.end() || comparator( phrase, *range.first ) ) {
    // NOT FOUND
  }
  synset_list const list( range.first );
  FOR_EACH( synset_list, list, synset ) {
    // TODO
  }
#endif

  i_ = synonyms_.begin();
}

thesaurus::~thesaurus() {
  // do nothing
}

bool thesaurus::next( zstring *synonym ) {
  if ( i_ != synonyms_.end() ) {
    *synonym = *i_;
    ++i_;
    return true;
  }
  return false;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
