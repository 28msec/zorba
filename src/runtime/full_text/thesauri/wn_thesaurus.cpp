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

#define DEBUG_FT_THESAURUS 0

#include <algorithm>                    /* for equal_range() */
#include <cstring>                      /* for strcmp(3) */
#include <limits>

#include <zorba/util/path.h>

#include <context/static_context.h>

#include "util/cxx_util.h"
#include "util/fs_util.h"
#include "util/less.h"
#if DEBUG_FT_THESAURUS
#include "util/oseparator.h"
#endif
#include "util/utf8_util.h"
#include "diagnostics/assert.h"
#include "diagnostics/dict.h"
#include "diagnostics/xquery_diagnostics.h"
#include "zorbautils/locale.h"

#include "decode_base128.h"
#include "wn_db_segment.h"
#include "wn_synset.h"
#include "wn_thesaurus.h"
#include "wn_types.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace wordnet {

/**
 * Used to ensure the endianness of the WordNet data file matches that of the
 * CPU we're running on.
 */
uint32_t const Magic_Number = 42;       // same as TIFF -- why not?

////////// Helper functions ///////////////////////////////////////////////////

/**
 * "Fixes" the "at most" parameter.  The Full Text specification section 3.4.3
 * says in part:
 *
 *    FTThesaurusID specifies the relationship sought between tokens and
 *    phrases written in the query and terms in the thesaurus and the number of
 *    levels to be queried in hierarchical relationships by including an
 *    FTRange "levels". If no levels are specified, the default is to query all
 *    levels in hierarchical relationships or to query an implementation-
 *    defined number of levels in hierarchical relationships.
 *
 * The problem with defaulting to "all levels" is that it makes queries too
 * broad, hence if at_most specifies "all levels" (max int), clamp it at 2
 * (which seems to work well in practice).
 */
inline internal::Thesaurus::level_type
fix_at_most( internal::Thesaurus::level_type at_most ) {
  return at_most == numeric_limits<internal::Thesaurus::level_type>::max() ?
    2 : at_most;
}

/**
 * Checks whether a WordNet synset pointer should be followed.
 *
 * @param ptr_type The pointer's type.
 * @return Returns \c true only if the pointer should be followed.
 */
static bool follow_ptr( pointer::type ptr_type ) {
  using namespace pointer;
  switch ( ptr_type ) {
    case antonym:
    case attribute:
    case cause:
    case derivationally_related_form:
    case derived_from_adjective:
    case domain_of_synset_region:
    case domain_of_synset_topic:
    case domain_of_synset_usage:
    case entailment:
    case member_holonym:
    case member_meronym:
    case member_of_domain_region:
    case member_of_domain_topic:
    case member_of_domain_usage:
    case part_holonym:
    case part_meronym:
    case participle_of_verb:
    case pertainym:
    case substance_holonym:
    case substance_meronym:
      //
      // These pointer types are skipped because it's thought that nobody would
      // want/expect such words as synonyms.
      //
      return false;

    case also_see:
    case hypernym:
    case hyponym:
    case instance_hypernym:
    case instance_hyponym:
    case similar_to:
    case verb_group:
      //
      // These pointer types are thought to be what most would want/expect
      // synonyms to be.
      //
      return true;

    case unknown:
      ZORBA_ASSERT( false );
  }
  return false;                         // suppesses warning -- never gets here
}

/**
 * Gets the "direction" of a WordNet pointer, i.e., whether a pointer leads to
 * a more specific, neutral, or more general lemma.
 *
 * @param ptr_type The WordNet pointer type to get the direction of.
 * @return Returns -1, 0, or +1 if \a ptr_type leads to a more specific,
 * neutral, or more general lemma, respectively.
 */
static iso2788::rel_dir get_ptr_dir( pointer::type ptr_type ) {
  using namespace pointer;
  switch ( ptr_type ) {
    case attribute:
    case derivationally_related_form:
    case domain_of_synset_region:
    case domain_of_synset_topic:
    case domain_of_synset_usage:
    case entailment:
    case hypernym:
    case instance_hypernym:
    case member_holonym:
    case part_holonym:
    case substance_holonym:
      return iso2788::broader;

    case derived_from_adjective:
    case hyponym:
    case instance_hyponym:
    case member_meronym:
    case member_of_domain_region:
    case member_of_domain_topic:
    case member_of_domain_usage:
    case part_meronym:
    case substance_meronym:
      return iso2788::narrower;

    case also_see:
    case antonym:
    case cause:
    case participle_of_verb:
    case pertainym:
    case similar_to:
    case unknown:
    case verb_group:
      return iso2788::neutral;

    default:                            // ensures all cases are handled
      ZORBA_ASSERT( false );
  }
  return iso2788::neutral;              // suppesses warning -- never gets here
}

/**
 * Gets the full path to the WordNet binary file.
 *
 * @param path The candidate path to the WordNet file.
 * @return Returns said path.
 */
static zstring get_wordnet_path( zstring path ) {
  ZORBA_ASSERT( !path.empty() );

  for ( bool loop = true; loop; ) {
    switch ( fs::get_type( path ) ) {
      case fs::directory:
        fs::append( path, "wordnet-" );
        path += iso639_1::string_of[ iso639_1::en ];
        path += ".zth";
        break;
      case fs::file:
        loop = false;
        break;
      case fs::non_existent:
        throw ZORBA_EXCEPTION(
          zerr::ZOSE0001_FILE_NOT_FOUND, ERROR_PARAMS( path )
        );
      default:
        throw ZORBA_EXCEPTION(
          zerr::ZOSE0002_NOT_PLAIN_FILE, ERROR_PARAMS( path )
        );
    }
  }
  return path;
}

/**
 * Attempts to map an XQuery thesaurus relationship to a WordNet pointer type.
 *
 * @param relationship The XQuery thesaurus relationship.
 * @param lang The language of the relationship.
 * @return Returns the corresponding Wordnet pointer type.
 */
static pointer::type map_xquery_rel( zstring const &relationship,
                                     iso639_1::type lang ) {
  zstring rel_lower;
  utf8::to_lower( relationship, &rel_lower );
  if ( iso2788::rel_type iso_rel = iso2788::find_rel( rel_lower, lang ) )
    return pointer::map_iso_rel( iso_rel );
  return pointer::find( rel_lower );
}

///////////////////////////////////////////////////////////////////////////////

thesaurus::iterator::candidate_queue_t::value_type const
  thesaurus::iterator::LevelMarker = make_pair( ~0u, iso2788::neutral );

thesaurus::iterator::iterator( thesaurus const &t, char const *p,
                               pointer::type ptr_type, level_type at_least,
                               level_type at_most ) :
  thesaurus_( t ), query_ptr_type_( ptr_type ),
  at_least_( at_least ), at_most_( fix_at_most( at_most ) ), level_( 0 )
{
  while ( *p++ ) ;                      // skip past lemma
  //
  // Load the candidate_queue_ will all the synsets for the lemma.
  //
  iso2788::rel_dir const query_dir = get_ptr_dir( query_ptr_type_ );
  for ( unsigned num_synsets = decode_base128( &p ); num_synsets-- > 0; ) {
    synset_id_t const synset_id = decode_base128( &p );
    candidate_queue_.push_back( make_pair( synset_id, query_dir ) );
  }
  //
  // All the candidates just added constitute a "level" so add the LevelMarker
  // to the queue.
  //
  candidate_queue_.push_back( LevelMarker );
}

thesaurus::iterator::~iterator() {
  // out-of-line since it's virtual
}

void thesaurus::iterator::destroy() const {
  delete this;
}

bool thesaurus::iterator::next( zstring *synonym ) {
  while ( result_queue_.empty() ) {
#   if DEBUG_FT_THESAURUS
    cout << "--------------------------------------------------" << endl;
    cout << "result_queue is empty" << endl;
#   endif

    if ( candidate_queue_.empty() ) {
#     if DEBUG_FT_THESAURUS
      cout << "candidate_queue is empty --> no more synonyms" << endl;
#     endif
      return false;
    }

    candidate_t const candidate( ztd::pop_front( candidate_queue_ ) );
    synset_id_t const synset_id = candidate.first;
    iso2788::rel_dir const synset_ptr_dir = candidate.second;

    if ( synset_id == LevelMarker.first ) {
#     if DEBUG_FT_THESAURUS
      cout << "+ found LevelMarker" << endl;
#     endif
      if ( ++level_ > at_most_ ) {
#       if DEBUG_FT_THESAURUS
        cout << "+ level (" << level_ << ") > at_most (" << at_most_
             << ") --> no more synonyms" << endl;
#       endif
        return false;
      }

      //
      // We've just incremented the level, so all synsets that have been added
      // to the queue since the last time we were here constitute a "level",
      // therefore add the level marker so we know when to increment the level
      // next time.
      //
      // Note that we do this only if the queue isn't empty, otherwise the
      // queue would never become empty.
      //
      if ( !candidate_queue_.empty() )
        candidate_queue_.push_back( LevelMarker );

      if ( query_ptr_type_ == pointer::antonym ) {
        //
        // Antonyms are a special case.  When the initial batch of synset
        // pointers are followed, we obviously follow only those whose type is
        // antonym.
        //
        // After that, however, we can no longer follow antonym pointers
        // otherwise we'd get antonyms of the antonyms (i.e., synonyms of the
        // original word).  Instead, we need synonyms of the antonyms.  Hence,
        // after the initial batch of antonym synset pointers are followed, we
        // reset query_ptr_type_ to unknown.
        //
        // For example, given the word "poor", we initially follow an antonym
        // pointer to the word "rich".  After that, we don't want antonyms of
        // rich, but synonyms, e.g., "affluent", "wealthy", "well to do", etc.
        //
#       if DEBUG_FT_THESAURUS
        cout << "$ resetting query_ptr_type_ to unknown" << endl;
#       endif
        query_ptr_type_ = pointer::unknown;
      }
      continue;
    }

    synset const ss( thesaurus_.wn_synsets_[ synset_id ] );

    if ( level_ >= at_least_ ) {
#     if DEBUG_FT_THESAURUS
      cout << "+ level (" << level_ << ") >= at_least (" << at_least_ << ')'
           << endl;
#     endif
      if ( !query_ptr_type_ || level_ ) {
        //
        // The first batch of synsets in the queue are from the inital look-up
        // of the query phrase.  All the lemmas in all these synsets are
        // synonyms of the query phrase (they all have the same "sense").
        //
        // If there was no relationship specified in the query (query_ptr_type_
        // is "unknown"), then it's OK to return those lemmas as synonyms.
        //
        // However, if a relationship was specified, then it's not OK to return
        // those lemmas since the user isn't looking for synonyms, but is
        // instead looking for lemmas that have the given relationship.
        //
        // But once we're past the first (zeroth) level (the synsets of the
        // inital look-up), it's always OK to return the lemmas.
        //
        FOR_EACH( synset::lemma_id_list, lemma_id, ss.lemma_ids() ) {
#         if DEBUG_FT_THESAURUS
          cout << "? " << wn_lemmas_[ *lemma_id ] << " -> ";
#         endif
          if ( synonyms_seen_.insert( *lemma_id ).second ) {
            result_queue_.push_back( *lemma_id );
#           if DEBUG_FT_THESAURUS
            cout << "pushed";
#           endif
          }
#         if DEBUG_FT_THESAURUS
          else {
            cout << "skipped";
          }
          cout << endl;
#         endif
        }
#       if DEBUG_FT_THESAURUS
        cout << "  result_queue is now: ";
        oseparator comma;
        FOR_EACH( result_queue_t, lemma_id, result_queue_ ) {
          cout << comma << wn_lemmas_[ *lemma_id ];
        }
        cout << endl;
#       endif
      }
    }

    //
    // Examine, and possibly follow, this synset's pointers.
    //
    FOR_EACH( synset::ptr_list, ptr, ss.ptrs() ) {
      if ( query_ptr_type_ ) {
        //
        // A pointer type (relationship) was given for the thesaurus option: if
        // this ptr's type doesn't match, skip it.
        //
        if ( ptr->type_ != query_ptr_type_ )
          continue;
      } else {
        if ( !follow_ptr( ptr->type_ ) )
          continue;
      }

      //
      // Ensure the "direction" of the pointer that got us to this synset and
      // that of the current pointer are "congruous", i.e., they do not point
      // in opposite directions.  Once we start to follow a pointer that has a
      // direction, we want to keep going in the same direction (or at least
      // laterally) in the semantic tree.
      //
      // For example, given the word "poor" (as in "poor people"), if we
      // followed a hypernym pointer to the broader word "people", we would
      // then not want to follow a hyponym pointers to more specific words like
      // "blind" ("blind people"), "brave" ("brave people"), "clientele",
      // "rich" ("rich people"), i.e., all the different kinds of people, since
      // none of those are synonyms of "poor".
      //
      iso2788::rel_dir const current_ptr_dir = get_ptr_dir( ptr->type_ );
      if ( !iso2788::congruous( synset_ptr_dir, current_ptr_dir ) )
        continue;

#     if DEBUG_FT_THESAURUS
      cout << "+ pushing \"" << ptr->type_
           << "\" synset (ID=" << ptr->synset_id_ << ')' << endl;
      synset const ptr_ss( wn_synsets_[ ptr->synset_id_ ] );
      oseparator comma;
      cout << "  lemmas: ";
      FOR_EACH( synset::lemma_id_list, lemma_id, ptr_ss.lemma_ids() ) {
        cout << comma << wn_lemmas_[ *lemma_id ];
      }
      cout << endl;
#     endif

      candidate_queue_.push_back(
        make_pair( ptr->synset_id_, synset_ptr_dir + current_ptr_dir )
      );

#define DO_PTR_SOURCE 0
#if DO_PTR_SOURCE
      if ( ptr->source_ ) {
        lemma_id_t const source_lemma_id = ss.lemma_ids()[ ptr->source_ - 1 ];

        synset const tt( wn_synsets_[ ptr->synset_id_ ] );
        lemma_id_t const target_lemma_id = tt.lemma_ids()[ ptr->target_ - 1 ];
      }
#endif
    } // FOR_EACH
  } // while

  *synonym = thesaurus_.wn_lemmas_[ ztd::pop_front( result_queue_ ) ];
# if DEBUG_FT_THESAURUS
  cout << "--> synonym=" << *synonym << endl;
# endif
  return true;
}

///////////////////////////////////////////////////////////////////////////////

thesaurus::wordnet_file_checker::wordnet_file_checker( mmap_file const &file ) {
  typedef char version_type[4];
  static char const our_version[] = "ZW01";

  // check version
  char file_version[ sizeof( version_type ) + 1 ];
  char const *byte_ptr = file.begin();
  ::strncpy( file_version, byte_ptr, sizeof( version_type ) );
  file_version[ sizeof( version_type ) ] = '\0';
  if ( ::strcmp( file_version, our_version ) != 0 )
    throw ZORBA_EXCEPTION(
      zerr::ZXQP8401_THESAURUS_VERSION_MISMATCH,
      ERROR_PARAMS( file_version, our_version )
    );

  // check endian-ness
  byte_ptr += sizeof( uint32_t );
  uint32_t const file_endian = *reinterpret_cast<uint32_t const*>( byte_ptr );
  if ( file_endian != Magic_Number )
    throw ZORBA_EXCEPTION( zerr::ZXQP8402_THESAURUS_ENDIANNESS_MISMATCH );
}

///////////////////////////////////////////////////////////////////////////////

thesaurus::thesaurus( zstring const &path, iso639_1::type lang ) :
  wordnet_file_( get_wordnet_path( path ).c_str() ),
  wordnet_file_checker_( wordnet_file_ ),
  wn_lemmas_( wordnet_file_, db_segment::lemma ),
  wn_synsets_( wordnet_file_, db_segment::synset ),
  lang_( lang )
{
}

thesaurus::~thesaurus() {
  // do nothing
}

void thesaurus::destroy() const {
  delete this;
}

char const* thesaurus::find_lemma( zstring const &phrase ) const {
  typedef pair<db_segment::const_iterator,db_segment::const_iterator> range_t;

  char const *const c_phrase = phrase.c_str();
  less<char const*> const comparator;

  range_t const range =
    ::equal_range( wn_lemmas_.begin(), wn_lemmas_.end(), c_phrase, comparator );
  if ( range.first == wn_lemmas_.end() || comparator( c_phrase, *range.first ) )
    return nullptr;
  return *range.first;
}

thesaurus::iterator::ptr
thesaurus::lookup( zstring const &phrase, zstring const &relationship,
                   level_type at_least, level_type at_most ) const {
  iterator::ptr result;
# if DEBUG_FT_THESAURUS
  cout << "==================================================" << endl;
  cout << "query phrase: " << phrase << endl;
# endif
  if ( char const *const p = find_lemma( phrase ) ) {
    result.reset(
      new iterator(
        *this, p, map_xquery_rel( relationship, lang_ ), at_least, at_most
      )
    );
  }
  return std::move( result );
}

///////////////////////////////////////////////////////////////////////////////

provider::provider( zstring const &path ) : path_( path ) {
  //
  // Append the first part of the filename that's the same for all languages.
  //
  fs::append( path_, "wordnet-" );
}

bool provider::getThesaurus( iso639_1::type lang,
                             internal::Thesaurus::ptr *t ) const {
  zstring filepath( path_ );

  switch ( lang ) {
    case iso639_1::unknown:
      lang = iso639_1::en;
      // no break;
    case iso639_1::en:
      filepath.append( iso639_1::string_of[ lang ] );
      filepath.append( ".zth" );
      break;
    default:
      return false;
  }

  // We want to look for the Wordnet thesaurus file on the library path.
  // Unfortunately every static_context can have its own library path, and we
  // don't have direct access to the query's static_context here. So, for now
  // we only look on the root static_context's library path.
#ifdef ZORBA_WITH_FILE_ACCESS
  static_context& sctx = GENV.getRootStaticContext();
  std::vector<zstring> lib_path;
  sctx.get_lib_path( lib_path );
  bool found = false;
  FOR_EACH( std::vector<zstring>, i, lib_path ) {
    // PAUL: as above, better way to do this?
    zstring cand_path( *i );
    cand_path.append( filepath );
    if ( fs::get_type( cand_path ) == fs::file ) {
      found = true;
      break;
    }
  }

  if ( found ) {
    if ( t )
      t->reset( new thesaurus( path_, lang ) );
    return true;
  }
#else /* ZORBA_WITH_FILE_ACCESS */
  if ( t )
    t->reset();
#endif /* ZORBA_WITH_FILE_ACCESS */
  return false;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba
/* vim:set et sw=2 ts=2: */
