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

#define DEBUG_THESAURUS 0
#define DEBUG_READ_THESAURUS 0

#include <fstream>

#include <zorba/store_consts.h>

#include "store/api/iterator.h"
#include "store/api/store.h"
#include "util/fs_util.h"
#if DEBUG_THESAURUS || DEBUG_READ_THESAURUS
#include "util/oseparator.h"
#endif
#include "util/stl_util.h"
#include "util/uri_util.h"
#include "util/utf8_util.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/dict.h"

#include "xqftts_thesaurus.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace xqftts {

///////////////////////////////////////////////////////////////////////////////

inline zstring const& get_local_name( store::Item_t const &item ) {
  return item->getNodeName()->getLocalName();
}

inline bool is_element( store::Item_t const &item ) {
  return  item->isNode() &&
          item->getNodeKind() == store::StoreConsts::elementNode;
}

///////////////////////////////////////////////////////////////////////////////

thesaurus::iterator::candidate_queue_t::value_type const
  thesaurus::iterator::LevelMarker =
    make_pair( static_cast<synonym*>(0), iso2788::neutral );

thesaurus::iterator::iterator( thesaurus_t const &t, zstring const &phrase,
                               zstring const &rel_string, level_type at_least,
                               level_type at_most ) :
  thesaurus_( t ), at_least_( at_least ), at_most_( at_most ), level_( 1 )
{
  using namespace iso2788;

  //
  // Always include the original phrase in the results.
  //
  result_queue_.push_back( phrase );
  synonyms_seen_.insert( phrase );

  //
  // Lookup the phrase in the thesaurus.
  //
  thesaurus_t::const_iterator const entry = thesaurus_.find( phrase );
  if ( entry != thesaurus_.end() ) {
    relationship const query_r( rel_string );
    rel_dir const query_dir = get_dir( query_r.get_iso2788() );
    FOR_EACH( synonym_set_t, i, entry->second ) {
      synonym const *const candidate_ptr = *i;
      //
      // For each synonym: if either the query didn't specify a relationship or
      // it did and a candidate's relationship matches, add the synonym as a
      // candidate result.
      //
      FOR_EACH( relationship_set_t, r, candidate_ptr->relationships ) {
        if ( query_r.empty() || *r == query_r ) {
          candidate_queue_.push_back(
            make_pair( candidate_ptr, query_dir + get_dir( r->get_iso2788() ) )
          );
        }
      }
    }
    //
    // All the candidates just added constitute a "level" so add the
    // LevelMarker to the queue.
    //
    candidate_queue_.push_back( LevelMarker );
  }
}

thesaurus::iterator::~iterator() {
  // out-of-line since it's virtual
}

void thesaurus::iterator::destroy() const {
  delete this;
}

bool thesaurus::iterator::next( zstring *result ) {
  using namespace iso2788;

  while ( result_queue_.empty() ) {
#   if DEBUG_THESAURUS
    cout << "--------------------------------------------------" << endl;
    cout << "result_queue is empty" << endl;
#   endif

    if ( candidate_queue_.empty() ) {
#     if DEBUG_THESAURUS
      cout << "candidate_queue is empty --> no more synonyms" << endl;
#     endif
      return false;
    }

#   if DEBUG_THESAURUS
    oseparator comma;
    cout << "candidate_queue is: ";
    FOR_EACH( candidate_queue_t, i, candidate_queue_ )
      cout << comma << (i->first ? i->first->term.c_str() : "<LEVEL>");
    cout << endl;
#   endif

    candidate_t const candidate( ztd::pop_front( candidate_queue_ ) );
    synonym const *const candidate_ptr = candidate.first;
    rel_dir const candidate_dir = candidate.second;

    if ( candidate_ptr == LevelMarker.first ) {
#     if DEBUG_THESAURUS
      cout << "+ found LevelMarker" << endl;
#     endif
      if ( ++level_ > at_most_ ) {
#       if DEBUG_THESAURUS
        cout << "+ level (" << level_ << ") > at_most (" << at_most_
             << ") --> no more synonyms" << endl;
#       endif
        return false;
      }
      //
      // We've just incremented the level, so all candidates that have been
      // added to the queue since the last time we were here constitute a
      // "level", therefore add the level marker so we know when to increment
      // the level next time.
      //
      // Note that we do this only if the queue isn't empty, otherwise the
      // queue would never become empty.
      //
      if ( !candidate_queue_.empty() )
        candidate_queue_.push_back( LevelMarker );

      continue;
    }

    term_t const &term = candidate_ptr->term;
    //
    // Add the candidate's term to the result queue only if we're within the
    // specified level range and we haven't returned the term before.
    //
    if ( level_ >= at_least_ && synonyms_seen_.insert( term ).second )
      result_queue_.push_back( term );

    //
    // Look up the current synonym term to do the next "level" of synonyms.
    //
    thesaurus_t::const_iterator const entry = thesaurus_.find( term );
    if ( entry != thesaurus_.end() ) {
      FOR_EACH( synonym_set_t, i, entry->second ) {
        synonym const *const next_candidate_ptr = *i;
        if ( !ztd::contains( synonyms_seen_, next_candidate_ptr->term ) ) {
          FOR_EACH( relationship_set_t, r, next_candidate_ptr->relationships ) {
            rel_dir const d = get_dir( r->get_iso2788() );
            if ( congruous( candidate_dir, d ) ) {
              candidate_queue_.push_back(
                make_pair( next_candidate_ptr, candidate_dir + d )
              );
            }
          }
        }
      }
    }
  } // while

  *result = ztd::pop_front( result_queue_ );
# if DEBUG_THESAURUS
  cout << "--> synonym=" << *result << endl;
# endif
  return true;
}

///////////////////////////////////////////////////////////////////////////////

thesaurus::thesaurus( zstring const &path, iso639_1::type lang ) {
  read_xqftts_file( path );
}

thesaurus::~thesaurus() {
  MUTATE_EACH( thesaurus_t, entry, thesaurus_ )
    ztd::delete_ptr_seq( entry->second );
}

void thesaurus::destroy() const {
  delete this;
}

thesaurus::iterator::ptr
thesaurus::lookup( zstring const &phrase, zstring const &relationship,
                   level_type at_least, level_type at_most ) const {
# if DEBUG_THESAURUS
  cout << "==================================================" << endl;
  cout << "query phrase: " << phrase << endl;
# endif
  return iterator::ptr(
    new iterator( thesaurus_, phrase, relationship, at_least, at_most )
  );
}

#define BAD_XML_EXCEPTION(WHAT,ZED_KEY) \
  ZORBA_EXCEPTION( zerr::ZXQP0024_XML_DOES_NOT_MATCH_SCHEMA, \
                   ERROR_PARAMS( WHAT, ZED( ZED_KEY ) ) )

void thesaurus::read_xqftts_file( zstring const &uri ) {
  ZORBA_ASSERT( !uri.empty() );
  zstring thesaurus_xml_path;
  bool is_temp_file;
  uri::fetch( uri, &thesaurus_xml_path, &is_temp_file );
  fs::auto_remover<zstring> file_remover;
  if ( is_temp_file )
    file_remover.reset( thesaurus_xml_path );

  ifstream ifs( thesaurus_xml_path.c_str() );
  store::LoadProperties props;
  props.setStoreDocument( false );
  store::Item_t doc = GENV_STORE.loadDocument( "", "", ifs, props );

  store::Iterator_t i = doc->getChildren();
  i->open();
  store::Item_t item;
  if ( i->next( item ) ) {
    store::Iterator_t i = item->getChildren();
    i->open();
    //
    // For each <entry> ...
    //
    while ( i->next( item ) ) {
      if ( !is_element( item ) )
        continue;
      store::Iterator_t i = item->getChildren();
      i->open();
      term_t new_term;
      synonym_set_t new_set;
      //
      // For each <term> or <synonym> ...
      //
      while ( i->next( item ) ) {
        if ( !is_element( item ) )
          continue;
        zstring const &element_name = get_local_name( item );
        if ( element_name == "term" ) {
          if ( !new_term.empty() )
            throw BAD_XML_EXCEPTION( "term", AlreadySpecified );
          item->getStringValue2( new_term );
          utf8::to_lower( new_term );
        } else if ( element_name == "synonym" ) {
          store::Iterator_t i = item->getChildren();
          i->open();
          term_t syn_term;
          relationship::string_t syn_relationship;
          //
          // For each synonym <term> or <relationship> ...
          //
          while ( i->next( item ) ) {
            if ( !is_element( item ) )
              continue;
            zstring const &element_name = get_local_name( item );
            if ( element_name == "term" ) {
              if ( !syn_term.empty() )
                throw BAD_XML_EXCEPTION( "term", AlreadySpecified );
              item->getStringValue2( syn_term );
              utf8::to_lower( syn_term );
            } else if ( element_name == "relationship" ) {
              if ( !syn_relationship.empty() )
                throw BAD_XML_EXCEPTION( "relationship", AlreadySpecified );
              item->getStringValue2( syn_relationship );
              utf8::to_lower( syn_relationship );
            } else
              throw BAD_XML_EXCEPTION( element_name, UnexpectedElement );
          }
          if ( syn_term.empty() )
            throw BAD_XML_EXCEPTION( "term", NotSpecified );
          if ( syn_relationship.empty() )
            throw BAD_XML_EXCEPTION( "relationship", NotSpecified );
          //
          // We now have a (possibly) new synonym for the new synonym set
          // being built.
          //
          synonym *const new_syn = new synonym( syn_term );
          synonym_set_t::iterator const old_syn = new_set.find( new_syn );
          if ( old_syn != new_set.end() ) {
            (*old_syn)->relationships.insert( syn_relationship );
            delete new_syn;
          } else {
            new_syn->relationships.insert( syn_relationship );
            new_set.insert( new_syn );
          }
        } else
          throw BAD_XML_EXCEPTION( element_name, UnexpectedElement );
      }

      if ( new_term.empty() )
        throw BAD_XML_EXCEPTION( "term", NotSpecified );
      if ( !new_set.empty() ) {
        //
        // We now have a (possibly) new term and one or more synonyms for it:
        // merge it into the thesaurus.
        //
        synonym_set_t &old_set = thesaurus_[ new_term ];
        if ( old_set.empty() )
          old_set.swap( new_set );
        else {
          FOR_EACH( synonym_set_t, new_syn, new_set ) {
            synonym_set_t::iterator const old_syn = old_set.find( *new_syn );
            if ( old_syn != old_set.end() ) {
              //
              // The same synonym for the term already exists: just add in
              // the relationships.
              //
              ztd::copy_set(
                (*new_syn)->relationships, (*old_syn)->relationships
              );
              delete *new_syn;
            } else
              old_set.insert( *new_syn );
          }
        }
      }
    }
#if DEBUG_READ_THESAURUS
    FOR_EACH( thesaurus_t, entry, thesaurus_ ) {
      cout << entry->first << endl;
      FOR_EACH( synonym_set_t, syn, entry->second ) {
        cout  << "  " << (*syn)->term << " (";
        oseparator comma;
        FOR_EACH( relationship_set_t, r, (*syn)->relationships )
          cout << comma << *r;
        cout << ')' << endl;
      }
    }
#endif /* DEBUG_READ_THESAURUS */
  }
}

///////////////////////////////////////////////////////////////////////////////

provider::provider( zstring const &path ) : path_( path ) {
}

bool provider::getThesaurus( iso639_1::type lang,
                             internal::Thesaurus::ptr *t ) const {
  switch ( lang ) {
    case iso639_1::unknown:
      lang = iso639_1::en;
      // no break;
    case iso639_1::en:
      if ( t ) {
#ifdef ZORBA_WITH_FILE_ACCESS
        t->reset( new thesaurus( path_, lang ) );
#else
        t->reset();
#endif /* ZORBA_WITH_FILE_ACCESS */
      }
      return true;
    default:
      return false;
  }
}

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba
/* vim:set et sw=2 ts=2: */
