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

typedef uint32_t lemma_id_t;
typedef uint32_t synset_id_t;

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
    //
    // The char is the binary file WordNet pointer symbol; the comment is the
    // original file WordNet pointer symbol.
    //

    unknown,
    also_see,

    /**
     * A word opposite in meaning to another.
     */
    antonym,

    attribute,
    cause,
    derivationally_related_form,
    derived_from_adjective,
    domain_of_synset_region,
    domain_of_synset_topic,
    domain_of_synset_usage,

    /**
     * A verb that presupposes another, e.g., "snoring" entails "sleeping."
     */
    entailment,

    /**
     * A word with a broad meaning that more specific words fall under, e.g.,
     * "meal" is a hypernym of "breakfast."
     */
    hypernym,

    /**
     * A word of more specific meaning than a general term applicable to it,
     * e.g., "breakfast" is a hyponym of "meal."
     */
    hyponym,

    /**
     * A word that denotes a category of some specific instance, e.g., "author"
     * is an instance hypernym of "Asimov."
     */
    instance_hypernym,

    /**
     * A term that donotes a specific instance of some general category, e.g.,
     * "Asimov" is an instance hyponym of "author."
     */
    instance_hyponym,

    /**
     * A word that denotes a collection of individuals, e.g., "faculty" is a
     * member holonym of "professor."
     */
    member_holonym,

    /**
     * A word that denotes a member of a larger group, e.g., a "person" is a
     * member meronym of a "crowd."
     */
    member_meronym,

    member_of_domain_region,
    member_of_domain_topic,
    member_of_domain_usage,

    /**
     * A word that denotes a larger whole comprised of some part, e.g., "car"
     * is a part holonym of "engine."
     */
    part_holonym,

    /**
     * A word that denotes a part of a larger whole, e.g., an "engine" is part
     * meronym of a "car."
     */
    part_meronym,

    participle_of_verb,
    
    /**
     * An adjective that classifies its noun, e.g., "musical instrument."
     */
    pertainym,

    /**
     * Similar, though not necessarily interchangeable, adjectives.  For
     * example, "shiny" is similar to "bright", but they have subtle
     * differences.
     */
    similar_to,

    /**
     * A word that denotes a larger whole containing some constituent
     * substance, e.g., "bread" is a substance holonym of "flour."
     */
    substance_holonym,

    /**
     * A word that denotes a constituant substance of some larger whole, e.g.,
     * "flour" is a substance meronym of "bread."
     */
    substance_meronym,

    verb_group,
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
