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
#ifndef ZORBA_THESAURUS_H
#define ZORBA_THESAURUS_H

#include <zorba/locale.h>
#include <zorba/internal/unique_ptr.h>

#include "context/uri_resolver.h"
#include "util/stl_util.h"
#include "zorbatypes/zstring.h"

#include "ft_util.h"                    /* for ft_int */

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Thesaurus is the abstract base class for thesaurus implementations.
 */
class Thesaurus {
public:
  typedef ft_int level_type;
  typedef std::unique_ptr<Thesaurus,ztd::destroy_delete<Thesaurus> > ptr;

  /**
   * An %iterator is used to iterate over lookup results.
   */
  class iterator {
  public:
    typedef std::unique_ptr<iterator,ztd::destroy_delete<iterator> > ptr;

    /**
     * Destroys this %iterator.
     */
    virtual void destroy() const = 0;

    /**
     * Gets the next synonym.  This function must always include the original
     * phrase that was looked up in its results.
     *
     * @param synonym A pointer to the string to receive the next synonym.
     * @return Returns \c true only if there is a next synonym.
     */
    virtual bool next( zstring *synonym ) = 0;

  protected:
    virtual ~iterator();
  };

  /**
   * Destroys this %Thesaurus.
   */
  virtual void destroy() const = 0;

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
                                zstring const &relationship,
                                level_type at_least,
                                level_type at_most ) const = 0;

protected:
  Thesaurus() { }
  virtual ~Thesaurus();

private:
  // forbid these
  Thesaurus( Thesaurus const& );
  Thesaurus& operator=( Thesaurus const& );
};

///////////////////////////////////////////////////////////////////////////////

/**
 * A %ThesaurusProvider TODO
 */
class ThesaurusProvider : public internal::Resource {
public:
  /**
   * Gets a Thesaurus for the given language.
   *
   * @param lang The desired language of the thesaurus.
   * @param t If not \c null, set to point to a Thesaurus for \a lang.
   * @return Returns \c true only if this provider can provide a thesaurus for
   * \a lang.
   */
  virtual bool getThesaurus( locale::iso639_1::type lang,
                             Thesaurus::ptr *t = nullptr ) const = 0;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif  /* ZORBA_THESAURUS_H */
/* vim:set et sw=2 ts=2: */
