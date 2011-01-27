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

#ifndef ZORBA_FULL_TEXT_WORDNET_THESAURUS_H
#define ZORBA_FULL_TEXT_WORDNET_THESAURUS_H

#include <deque>
#include <set>
#include <utility>                      /* for pair */

#include "util/mmap_file.h"

#include "../ft_thesaurus.h"
#include "iso2788.h"
#include "wn_db_segment.h"
#include "wn_types.h"

namespace zorba {
namespace wordnet {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %wordnet::thesaurus is an ft_thesaurus for Wordnet.
 * See: http://wordnet.princeton.edu/
 */
class thesaurus : public ft_thesaurus {
public:
  /**
   * Constructs a %thesaurus.
   *
   * @param path The path to the Wordnet database file or the directory it's
   * in.
   * @param lang The language of the phrase.
   * @param phrase The phrase to look up.
   * @param relationship The desired relationship the synonyms are to have.
   * @param at_least The least number of "levels" the synonyms are to be away
   * from the phrase.
   * @param at_most The most number of "levels" the synonyms are to be away
   * from the phrase.
   */
  thesaurus( zstring const &path, locale::iso639_1::type lang,
             zstring const &phrase, zstring const &relationship,
             ft_int at_least, ft_int at_most );

  ~thesaurus();

  // inherited
  bool next( zstring *synonym );

private:
  typedef std::pair<synset_id_t,iso2788::rel_dir> synset_queue_entry;
  typedef std::deque<synset_queue_entry> synset_queue;
  typedef std::deque<lemma_id_t> synonym_queue;
  typedef std::set<lemma_id_t> synonym_set;

  zstring const path_;
  ft_int const at_least_, at_most_;
  ft_int level_;

  /**
   * The WordNet pointer type that is the closest equivalent of the
   * "relationship" given in the original query, if any.
   */
  pointer::type query_ptr_type_;

  synset_queue synset_queue_;
  synonym_queue synonym_queue_;
  synonym_set synonyms_seen_;

  static synset_queue::value_type const LevelMarker;

  /**
   * Attempts to find a lemma within the WordNet thesaurus.
   *
   * @param phrase The phrase to search for.
   * @return Returns said lemma or \c NULL if not found.
   */
  char const* find_lemma( zstring const &phrase );

  /**
   * Gets a reference to a singleton instance of the WordNet thesaurus database
   * file.
   *
   * @param path The file or directory the WordNet thesaurus database is in.
   * @return Returns said reference.
   */
  static mmap_file const& get_wordnet_file( zstring const &path );

  /**
   * Gets a reference to a singleton instance of a WordNet thesaurus database
   * segment.
   *
   * @tparam SegID The database segment ID of the segment to get.
   * @param path The file or directory the WordNet thesaurus database is in.
   * @return Returns said segment.
   */
  template<db_segment::id_t SegID>
  static db_segment const& get_segment( zstring const &path );

  // forbid these
  thesaurus( thesaurus const& );
  thesaurus& operator=( thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace wordnet
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_WORDNET_THESAURUS_H */
/* vim:set et sw=2 ts=2: */
