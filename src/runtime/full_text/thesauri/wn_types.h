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

#ifndef ZORBA_FULL_TEXT_WORDNET_TYPES_H
#define ZORBA_FULL_TEXT_WORDNET_TYPES_H

#include <zorba/config.h>
#ifndef WIN32
#include <stdint.h>
#else
#include "zorbamisc/config/stdint.h"
#endif
#include "iso2788.h"

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

typedef uint32_t lemma_id;
typedef uint32_t synset_id;

///////////////////////////////////////////////////////////////////////////////

/**
 * A WordNet part-of-speech.
 */
namespace part_of_speech {

  /**
   * The various parts-of-speech.
   */
  enum type {
    unknown,
    adjective = 'a',
    adverb    = 'r',
    noun      = 'n',
    verb      = 'v',
  };

  /**
   * Attempts to find the WordNet part-of-speech corresponding to the given
   * part-of-speech code.
   *
   * @param pos The part-of-speech code.
   * @return Returns the corresponding part-of-speech of \c unknown.
   */
  type find( char pos );

} // part_of_speech

///////////////////////////////////////////////////////////////////////////////

/**
 * A %pointer is a WordNet "pointer" (pointer between synsets), not a C++
 * pointer.
 */
namespace pointer {

  /**
   * The various types of WordNet pointer.
   */
  enum type {
    unknown,
    also_see,
    antonym,
    attribute,
    cause,
    derivationally_related_form,
    derived_from_adjective,
    domain_of_synset_region,
    domain_of_synset_topic,
    domain_of_synset_usage,
    entailment,
    hypernym,
    hyponym,
    instance_hypernym,
    instance_hyponym,
    member_holonym,
    member_meronym,
    member_of_domain_region,
    member_of_domain_topic,
    member_of_domain_usage,
    part_holonym,
    part_meronym,
    participle_of_verb,
    pertainym,
    similar_to,
    substance_holonym,
    substance_meronym,
    verb_group
  };
  extern char const *const string_of[];

  /**
   * Given a binary WordNet pointer symbol, find its corresponding type.
   *
   * @param ptr_symbol The pointer symbol to find.
   * @return Returns the corresponding type or \c unknown.
   */
  type find( char ptr_symbol );

  /**
   * Given a binary WordNet pointer symbol, find its corresponding type.
   *
   * @param ptr_symbol The pointer symbol to find.
   * @return Returns the corresponding type or \c unknown.
   */
  inline type find( unsigned char ptr_symbol ) {
    return find( static_cast<char>( ptr_symbol ) );
  }

  type find( char const *relationship );

  template<class StringType> inline
  type find( StringType const &relationship ) {
    return find( relationship.c_str() );
  }

  /**
   * Attempts to map an ISO 2788 relationship to a WordNet pointer type.
   *
   * @param iso_rel The ISO 2788 relationship.
   * @return Returns the closest equivalent WordNet pointer type.
   */
  type map_iso_rel( iso2788::rel_type iso_rel );

} // namespace pointer

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

#endif /* ZORBA_FULL_TEXT_WORDNET_TYPES_H */
/* vim:set et sw=2 ts=2: */
