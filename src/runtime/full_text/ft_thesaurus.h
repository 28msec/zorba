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
#pragma once
#ifndef ZORBA_FULL_TEXT_FT_THESAURUS_H
#define ZORBA_FULL_TEXT_FT_THESAURUS_H

#include <zorba/locale.h>
#include <zorba/internal/unique_ptr.h>

#include "zorbatypes/zstring.h"

#include "ft_util.h"                    /* for ft_int */

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

/**
 * An %ft_thesaurus is the abstract base class for thesaurus implementations.
 */
class ft_thesaurus {
public:
  typedef std::unique_ptr<ft_thesaurus> ptr;

  /**
   * An %iterator is used to iterate over lookup results.
   */
  struct iterator {
    typedef std::unique_ptr<iterator> ptr;

    virtual ~iterator();

    /**
     * Gets the next synonym.
     *
     * @param synonym A pointer to the string to receive the next synonym.
     * @return Returns \c true only if there is a next synonym.
     */
    virtual bool next( zstring *synonym ) = 0;
  };

  virtual ~ft_thesaurus();

  /**
   * Gets an instance of the requested thesaurus.
   *
   * @param uri The URI provided in the query for the thesaurus.
   * @param lang The language of the thesaurus.
   * @return Returns said thesaurus or \c nullptr if no thesaurus matches the
   * request.
   */
  static ptr get( zstring const &uri, locale::iso639_1::type lang,
                  static_context const& sctx );

  /**
   * Looks-up the given phrase.
   *
   * @param phrase The phrase to look up.
   * @param relationship The relationship the synonyms are to have to the given
   * \a phrase.
   * @param at_least The minimum number of levels within the thesaurus to be
   * traversed.
   * @param at_most The maximum number of levels within the thesaurus to be
   * traversed.
   * @return Returns a pointer to an iterator for the results or \c nullptr if
   * the phrase was not found.
   */
  virtual iterator::ptr lookup( zstring const &phrase,
                                zstring const &relationship, ft_int at_least,
                                ft_int at_most ) const = 0;

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
