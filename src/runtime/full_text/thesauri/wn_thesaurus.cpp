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

#include <iostream>

#include <algorithm>                    /* for equal_range */
#include <utility>                      /* for pair */

#include "util/ascii_util.h"
#include "util/less.h"
#include "util/mmap_file.h"
#include "util/stl_util.h"

#include "decode_base128.h"
#include "wn_db_segment.h"
#include "wn_synset.h"
#include "wn_thesaurus.h"
#include "wn_types.h"

using namespace std;

namespace zorba {
namespace wordnet {

////////// Helper functions ///////////////////////////////////////////////////

/**
 * Gets a reference to the WordNet thesaurus database file.
 *
 * @return Returns said reference.
 */
static mmap_file const& get_db_file() {
  static mmap_file thesaurus_file;
  if ( !thesaurus_file )
    thesaurus_file.open( "/usr/local/tmp/zorba/thesaurus.zth" ); // TODO
  return thesaurus_file;
}

/**
 * Gets a reference to a WordNet thesaurus database segment.
 *
 * @return Returns said segment.
 */
template<db_segment::seg_id SegID>
static db_segment const& get() {
  static db_segment const segment( get_db_file(), SegID );
  return segment;
}

/**
 * Attempts to find a lemma within the WordNet thesaurus.
 *
 * @param phrase The phrase to search for.
 * @return Returns said lemma or \c NULL if not found.
 */
static char const* find_lemma( zstring const &phrase ) {
  typedef pair<db_segment::const_iterator,db_segment::const_iterator>
    lemma_range;

  db_segment const &lemmas = get<db_segment::id_lemma>();
  char const *const c_phrase = phrase.c_str();
  less<char const*> comparator;

  lemma_range const range =
    ::equal_range( lemmas.begin(), lemmas.end(), c_phrase, comparator );
  if ( range.first == lemmas.end() || comparator( c_phrase, *range.first ) )
    return NULL;
  return *range.first;
}

/**
 * Gets the ith lemma.
 *
 * @param i The index of the lemma to get.
 * @return Returns said lemma.
 */
inline char const* get_lemma( db_segment::size_type i ) {
  return get<db_segment::id_lemma>()[ i ];
}

/**
 * Gets the ith synset.
 *
 * @param i The index of the synset to get.
 * @return Returns said synset.
 */
inline unsigned char const* get_synset( db_segment::size_type i ) {
  return reinterpret_cast<unsigned char const*>(
    get<db_segment::id_synset>()[ i ]
  );
}

/**
 * Attempts to map an XQuery thesaurus relationship to a WordNet pointer type.
 *
 * @param relationship The XQuery thesaurus relationship.
 * @return Returns the corresponding Wordnet pointer type.
 */
static pointer::type map_xquery_rel( zstring const &relationship ) {
  zstring relationship_lower;
  ascii::to_lower( relationship, &relationship_lower );
  if ( iso2788::rel_type iso_rel = iso2788::find_rel( relationship_lower ) )
    return pointer::map_iso_rel( iso_rel );
  return pointer::find( relationship_lower );
}

///////////////////////////////////////////////////////////////////////////////

synset_id_t const LevelSentinel = ~0u;

thesaurus::thesaurus( zstring const &phrase, zstring const &relationship,
                      ft_int at_least, ft_int at_most ) :
  ptr_type_( map_xquery_rel( relationship ) ),
  at_least_( at_least ), at_most_( at_most ), level_( 0 )
{
  if ( char const *const lemma = find_lemma( phrase ) ) {
    unsigned char const *p = reinterpret_cast<unsigned char const*>( lemma );
    while ( *p++ ) ;                    // skip past lemma
    for ( unsigned num_synsets = decode_base128( &p ); num_synsets-- > 0; )
      synset_id_queue_.push_back( decode_base128( &p ) );
    synset_id_queue_.push_back( LevelSentinel );
  }
}

thesaurus::~thesaurus() {
  // do nothing
}

bool thesaurus::next( zstring *synonym ) {
  while ( synonym_queue_.empty() ) {
    cout << "synonym_queue is empty" << endl;

    if ( synset_id_queue_.empty() ) {
      cout << "synset_id_queue is empty" << endl;
      return false;
    }

    synset_id_t const synset_id = pop_front( synset_id_queue_ );
    cout << "synset_id=" << synset_id << endl;
    if ( synset_id == LevelSentinel ) {
      cout << "+ found LevelSentinel" << endl;
      if ( ++level_ > at_most_ ) {
        cout << "+ level (" << level_ << ") > at_most (" << at_most_ << ')' << endl;
        return false;
      }
      continue;
    }

    synset const ss( get_synset( synset_id ) );
    if ( level_ >= at_least_ ) {
      cout << "+ level (" << level_ << ") >= at_least (" << at_least_ << ')' << endl;
      copy_seq( ss.lemma_ids_, synonym_queue_ );
    }

    FOR_EACH( synset::ptr_list, ptr, ss.ptr_list_ ) {
      if ( ptr_type_ && ptr->type_ != ptr_type_ )
        continue;
      synset_id_queue_.push_back( ptr->synset_id_ );

      if ( ptr->source_ ) {
        // TODO
        ptr->target_;
      } else {
        // TODO
      }
    }
    synset_id_queue_.push_back( LevelSentinel );
  }
  *synonym = get_lemma( pop_front( synonym_queue_ ) );
  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
