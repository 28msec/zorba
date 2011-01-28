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

#ifndef ZORBA_FULL_TEXT_XQFTTS_THESAURUS_H
#define ZORBA_FULL_TEXT_XQFTTS_THESAURUS_H

#include <deque>
#include <functional>                   /* for binary_function */
#include <map>
#include <set>
#include <utility>                      /* for pair */

#include "../ft_thesaurus.h"
#include "xqftts_relationship.h"

namespace zorba {
namespace xqftts {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %xqftts::thesaurus is-an ft_thesaurus for the W3C XQuery Full-Text Test
 * Suite.  The only reason this implementation was written is to run and pass
 * the test suite's thesaurus tests.  However, users may find it useful for
 * their own production thesauri.
 */
class thesaurus : public ft_thesaurus {
public:
  thesaurus( zstring const &path, locale::iso639_1::type lang,
             zstring const &phrase, zstring const &relationship,
             ft_int at_least, ft_int at_most );

  ~thesaurus();

  // inherited
  bool next( zstring *synonym );

private:
  //
  // The XQuery Full-Text Test Suite thesaurus XML data file format is of the
  // form:
  //
  //    <thesaurus>
  //      <entry>
  //        <term>{word}</term>
  //        <synonym>
  //          <term>{word}</term>
  //          <relationship>{relationship}</relationship>
  //        </synonym>
  //        ...
  //      </entry>
  //      ...
  //    </thesaurus>
  //
  // Note: Term words can appear more than once.  Terms having the same word
  // must therefore be merged.  Hence, a synonym term can end up having more
  // than one relationship.
  //

  typedef zstring term_t;
  typedef std::set<relationship> relationship_set_t;

  /**
   * An XQFTTS %synonym consists simply of a term and a set of relationships
   * the term has to some other term that this %synonym is a %synonym for.
   */
  struct synonym {
    term_t term;
    relationship_set_t relationships;

    /**
     * Constructs a %synonym.
     *
     * @param t The term.
     */
    synonym( term_t const &t ) : term( t ) { }

    /**
     * Define a comparator for %synonym objects so that they can be put into
     * sorted STL containers.  However, to avoid copying %synonym objects
     * around, we use %synonym*.  We therefore need a comparator that compares
     * %synonym* by comparing the %synonym objects they point to.
     *
     * FYI: We need to define a comparator class because \c operator&lt; (and
     * operators in general) can't be overloaded for pointers.
     */
    struct less : std::binary_function<synonym const*,synonym const*,bool> {
      result_type operator()( first_argument_type i,
                              second_argument_type j ) const {
        return i->term < j->term;
      }
    };
  };

  typedef std::pair<synonym const*,iso2788::rel_dir> candidate_t;
  typedef std::deque<candidate_t> candidate_queue_t;

  typedef std::deque<term_t> result_queue_t;
  typedef std::set<term_t> seen_set_t;

  typedef std::set<synonym*,synonym::less> synonym_set_t;
  typedef std::map<term_t,synonym_set_t> thesaurus_t;

  candidate_queue_t candidate_queue_;
  result_queue_t result_queue_;
  seen_set_t synonyms_seen_;
  thesaurus_t thesaurus_;

  static candidate_queue_t::value_type const LevelMarker;

  ft_int const at_least_, at_most_;
  ft_int level_;

  void read_xqftts_file( zstring const &uri );

  // forbid these
  thesaurus( thesaurus const& );
  thesaurus& operator=( thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace xqftts
} // namespace zorba

#endif  /* ZORBA_FULL_TEXT_XQFTTS_THESAURUS_H */
/* vim:set et sw=2 ts=2: */
