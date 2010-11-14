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

#ifndef ZORBA_FULL_TEXT_FT_THESAURUS_H
#define ZORBA_FULL_TEXT_FT_THESAURUS_H

#include <limits>

#include "zorbatypes/zstring.h"
#include "zorbautils/locale.h"

#include "ft_query_item.h"
#include "ft_util.h"

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * ISO 2788: Guidelines for the establishment and development of monolingual
 * thesauri.
 */
namespace iso2788 {

  /**
   * Relationship abbreviations from section 4.1.
   */
  enum rel_type {
    unknown,
    BT,   // broader term
    BTG,  // broader term (generic)
    BTP,  // broader term (partitive)
    NT,   // narrower term
    NTG,  // narrower term (generic)
    NTP,  // narrower term (partitive)
    RT,   // related term
    TT,   // top term
    UF,   // non-preferred term
    USE,  // preferred term
  };
  extern char const *const string_of[];

  rel_type find_rel( char const *relationship );

  template<class StringType> inline
  rel_type find_rel( StringType const &relationship ) {
    return find_rel( relationship.c_str() );
  }
}

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ft_thesaurus is the abstact base class for thesaurus implementations.
 */
class ft_thesaurus {
public:
  virtual ~ft_thesaurus();

  /**
   * Gets an instance of the requested thesaurus and performs a phrase look-up.
   *
   * @param uri The URI specifying the thesaurus to use.
   * @param lang The language of the thesaurus.
   * @param phrase The phrase to look up.
   * @param relationship The relationship the synonyms are to have to the given
   * \a phrase.
   * @param at_least The minimum number of levels within the thesaurus to be
   * traversed.
   * @param at_most The maximum number of levels within the thesaurus to be
   * traversed.
   * @return Returns said thesaurus or \c null if no thesaurus matches the
   * request.  It is the caller's responsibility to \c delete the thesaurus.
   */
  static ft_thesaurus* get( zstring const &uri, locale::iso639_1::type lang,
                            zstring const &phrase, zstring const &relationship,
                            ft_int at_least, ft_int at_most );

  /**
   * Gets the next synonym.
   *
   * @param synonym A pointer to the string to receive the next synonym.
   * @return Returns \c true only if there is a next synonym.
   */
  virtual bool next( zstring *synonym ) = 0;

protected:
  ft_thesaurus() { }

private:
  // forbid these
  ft_thesaurus( ft_thesaurus const& );
  ft_thesaurus& operator=( ft_thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif  /* ZORBA_FULL_TEXT_FT_THESAURUS_H */
/* vim:set et sw=2 ts=2: */
