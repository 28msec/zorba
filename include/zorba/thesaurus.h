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

#ifndef ZORBA_THESAURUS_API_H
#define ZORBA_THESAURUS_API_H

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include <zorba/internal/unique_ptr.h>
#include <zorba/internal/ztd.h>
#include <zorba/locale.h>
#include <zorba/zorba_string.h>

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

// CEEJ rename this class to ThesaurusResource, make it subclass Resource
/**
 * A %Thesaurus is an abstract base class for thesaurus implementations.
 */
class ZORBA_DLL_PUBLIC Thesaurus {
public:
  typedef std::unique_ptr<Thesaurus,internal::ztd::destroy_delete<Thesaurus> >
          ptr;

  /**
   * The integral type for "at least" and "at most" values.
   */
  typedef unsigned range_type;

  /**
   * An %iterator is used to iterate over lookup results.
   */
  class iterator {
  public:
    typedef std::unique_ptr<iterator,internal::ztd::destroy_delete<iterator> >
            ptr;

    /**
     * Destroys this iterator.
     */
    virtual void destroy() const = 0;

    /**
     * Gets the next synonym.  This function must always include the original
     * phrase that was looked up in its results.
     *
     * @param synonym A pointer to the string to receive the next synonym.
     * @return Returns \c true only if there is a next synonym.
     */
    virtual bool next( String *synonym ) = 0;
  protected:
    virtual ~iterator() {}
  };

  /**
   * Destroys this %Thesaurus.
   * This function is called by Zorba when the %Thesaurus is no longer needed.
   *
   * If your ThesaurusProvider dynamically allocates %Thesaurus objects, then
   * the implementation can simply be (and usually is) <code>delete
   * this</code>.
   *
   * If your ThesaurusProvider returns a pointer to a static %Thesaurus object,
   * then the implementation should do nothing.
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
   * @return Returns a pointer to an iterator for the results or \c NULL if the
   * phrase was not found.
   */
  virtual iterator::ptr
  lookup( String const &phrase, String const &relationship,
          range_type at_least, range_type at_most ) const = 0;

protected:
  virtual ~Thesaurus();
};

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
#endif /* ZORBA_NO_FULL_TEXT */
#endif /* ZORBA_THESAURUS_API_H */
/* vim:set et sw=2 ts=2: */
