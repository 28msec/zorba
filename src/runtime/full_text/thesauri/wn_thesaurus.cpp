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

#define DEBUG_FT_THESAURUS 1

#if DEBUG_FT_THESAURUS
#include <iostream>
#endif
#include <algorithm>                    /* for equal_range() */
#include <cassert>
#include <cstring>                      /* for strcmp(3) */
#include <utility>                      /* for pair */

#include <zorba/util/path.h>

#include "util/ascii_util.h"
#include "util/less.h"
#include "zorbaerrors/error_manager.h"

#include "decode_base128.h"
#include "wn_db_segment.h"
#include "wn_synset.h"
#include "wn_thesaurus.h"
#include "wn_types.h"

using namespace std;

namespace zorba {
namespace wordnet {

////////// Helper functions ///////////////////////////////////////////////////

#define THROW_VERSION_EXCEPTION(FILE_VERSION,OUR_VERSION) {           \
  ostringstream oss;                                                  \
  oss << '"' << FILE_VERSION                                          \
      << "\": wrong WordNet file version; should be \""               \
      << OUR_VERSION << '"';                                          \
  ZORBA_ERROR_DESC( XQP8402_THESAURUS_VERSION_MISMATCH, oss.str() );  \
}

/**
 * Gets a reference to a singleton instance of the WordNet thesaurus database
 * file.
 *
 * @return Returns said reference.
 */
mmap_file const& get_wordnet_file() {
  typedef char version_type[4];
  static char const our_version[] = "ZW01";

  static mmap_file wordnet_file;
  if ( !wordnet_file ) {
    zstring const &dir = thesaurus::get_directory();
    assert( !dir.empty() );

    zstring wordnet_path = dir;
    if ( !ascii::ends_with( wordnet_path,
                            filesystem_path::get_path_separator() ) )
      wordnet_path += filesystem_path::get_path_separator();
    wordnet_path += "wordnet.zth";

    wordnet_file.open( wordnet_path.c_str() );
    char file_version[ sizeof( version_type ) + 1 ];
    ::strncpy( file_version, wordnet_file.begin(), sizeof( version_type ) );
    file_version[ sizeof( version_type ) ] = '\0';
    if ( ::strcmp( file_version, our_version ) != 0 )
      THROW_VERSION_EXCEPTION( file_version, our_version );
  }
  return wordnet_file;
}

/**
 * Gets a reference to a singleton instance of a WordNet thesaurus database
 * segment.
 *
 * @return Returns said segment.
 */
template<db_segment::id_t SegID>
static db_segment const& get_segment() {
  static db_segment const segment( get_wordnet_file(), SegID );
  return segment;
}

#define GET_SEGMENT(SEG_ID) get_segment<db_segment::SEG_ID>()
#define LEMMAS              GET_SEGMENT( lemma )
#define SYNSETS             GET_SEGMENT( synset )

/**
 * Attempts to find a lemma within the WordNet thesaurus.
 *
 * @param phrase The phrase to search for.
 * @return Returns said lemma or \c NULL if not found.
 */
static char const* find_lemma( zstring const &phrase ) {
  typedef pair<db_segment::const_iterator,db_segment::const_iterator>
    lemma_range;

  db_segment const &lemmas = LEMMAS;
  char const *const c_phrase = phrase.c_str();
  less<char const*> const comparator;

  lemma_range const range =
    ::equal_range( lemmas.begin(), lemmas.end(), c_phrase, comparator );
  if ( range.first == lemmas.end() || comparator( c_phrase, *range.first ) )
    return NULL;
  return *range.first;
}

/**
 * Checks whether a WordNet synset pointer should be followed.
 *
 * @param ptr_type The pointer's type.
 * @return Returns \c true only if the pointer should be followed.
 */
static bool follow_ptr( pointer::type ptr_type ) {
  switch ( ptr_type ) {
    case pointer::antonym:
    case pointer::attribute:
    case pointer::cause:
    case pointer::derivationally_related_form:
    case pointer::derived_from_adjective:
    case pointer::entailment:
    case pointer::member_holonym:
    case pointer::member_meronym:
    case pointer::part_holonym:
    case pointer::part_meronym:
    case pointer::participle_of_verb:
    case pointer::pertainym:
    case pointer::substance_holonym:
    case pointer::substance_meronym:
      //
      // These pointer types are skipped because it's thought that nobody would
      // want/expect such words as synonyms.
      //
      return false;

    case pointer::also_see:
    case pointer::hypernym:
    case pointer::hyponym:
    case pointer::instance_hypernym:
    case pointer::instance_hyponym:
    case pointer::similar_to:
    case pointer::verb_group:
      //
      // These pointer types are thought to be what most would want/expect
      // synonyms to be.
      //
      return true;

    case pointer::domain_of_synset_region:
    case pointer::domain_of_synset_topic:
    case pointer::domain_of_synset_usage:
    case pointer::member_of_domain_region:
    case pointer::member_of_domain_topic:
    case pointer::member_of_domain_usage:
      //
      // TODO: It's not clear what to do with these.  For now, err on the side
      // of following them.
      //
      return true;

    default:
      assert( false );                  // ensures all cases are handled
  }
  return false;                         // suppesses warning -- never gets here
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
  if ( char const *p = find_lemma( phrase ) ) {
    while ( *p++ ) ;                    // skip past lemma
    //
    // Load the synset_id_queue_ will all the synsets for the lemma.
    //
    for ( unsigned num_synsets = decode_base128( &p ); num_synsets-- > 0; ) {
      synset_id_t const synset_id = decode_base128( &p );
      synset_id_queue_.push_back( synset_id );
    }
  }
}

thesaurus::~thesaurus() {
  // do nothing
}

bool thesaurus::next( zstring *synonym ) {
  while ( synonym_queue_.empty() ) {
#   if DEBUG_FT_THESAURUS
    cout << "==================================================" << endl;
    cout << "synonym_queue is empty" << endl;
#   endif

    if ( synset_id_queue_.empty() ) {
#     if DEBUG_FT_THESAURUS
      cout << "synset_id_queue is empty --> no more synonyms" << endl;
#     endif
      return false;
    }

    synset_id_t const synset_id = pop_front( synset_id_queue_ );
    if ( synset_id == LevelSentinel ) {
#     if DEBUG_FT_THESAURUS
      cout << "+ found LevelSentinel" << endl;
#     endif
      if ( ++level_ > 1 /*at_most_*/ ) {
#       if DEBUG_FT_THESAURUS
        cout << "+ level (" << level_ << ") > at_most (" << at_most_
             << ") --> no more synonyms" << endl;
#       endif
        return false;
      }
      continue;
    }

#   if DEBUG_FT_THESAURUS
    cout << "synset_id=" << synset_id << endl;
#   endif

    synset const ss( SYNSETS[ synset_id ] );
    if ( level_ >= at_least_ ) {
#     if DEBUG_FT_THESAURUS
      cout << "+ level (" << level_ << ") >= at_least (" << at_least_ << ')'
           << endl;
#     endif
      FOR_EACH( synset::lemma_id_list, lemma_id, ss.lemma_ids_ ) {
        if ( synonyms_seen_.insert( *lemma_id ).second )
          synonym_queue_.push_back( *lemma_id );
      }

#     if DEBUG_FT_THESAURUS
      cout << "+ copied lemmas; synonym_queue is now: ";
      bool comma = false;
      FOR_EACH( synonym_queue, lemma_id, synonym_queue_ ) {
        if ( comma )
          cout << ", ";
        else
          comma = true;
        cout << LEMMAS[ *lemma_id ];
      }
      cout << endl;
#     endif
    }

    FOR_EACH( synset::ptr_list, ptr, ss.ptr_list_ ) {
      if ( ptr_type_ ) {
        //
        // A pointer type (relationship) was given for the thesaurus option: if
        // this ptr's type doesn't match, skip it.
        //
        if ( ptr->type_ != ptr_type_ )
          continue;
      } else {
        if ( !follow_ptr( ptr->type_ ) )
          continue;
      }

#     if DEBUG_FT_THESAURUS
      cout << "+ ptr->type=" << pointer::string_of[ ptr->type_ ] << endl;
#     endif

      synset_id_queue_.push_back( ptr->synset_id_ );
#if 0
      if ( ptr->source_ ) {
        lemma_id_t const source_lemma_id = ss.lemma_ids_[ ptr->source_ - 1 ];

        synset const tt( SYNSETS[ ptr->synset_id_ ] );
        lemma_id_t const target_lemma_id = tt.lemma_ids_[ ptr->target_ - 1 ];
      }
#endif
    } // FOR_EACH

    //
    // The synset IDs of all the pointers of this synset constitute a "level",
    // so add the sentinel to the queue to increment the level.
    //
    synset_id_queue_.push_back( LevelSentinel );
  } // while

  *synonym = LEMMAS[ pop_front( synonym_queue_ ) ];
# if DEBUG_FT_THESAURUS
  cout << "--> synonym=" << *synonym << endl;
# endif
  return true;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
