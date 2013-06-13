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
#ifndef ZORBA_STEMMER_H
#define ZORBA_STEMMER_H

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include <zorba/internal/unique_ptr.h>
#include <zorba/util/locale.h>

#include "util/stl_util.h"
#include "zorbatypes/zstring.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Stemmer is used to "stem" words.
 */
class Stemmer {
public:
  typedef std::unique_ptr<Stemmer const,
                          ztd::destroy_delete<Stemmer const> > ptr;

  /**
   * Various properties of this %Stemmer.
   */
  struct Properties {
    /**
     * The URI that uniquely identifies this %Stemmer.
     */
    char const * uri;
  };

  /**
   * Destroys this %Stemmer.
   */
  virtual void destroy() const = 0;

  /**
   * Gets the Properties of this %Stemmer.
   *
   * @param result The Properties to populate.
   */
  virtual void properties( Properties *result ) const = 0;

  /**
   * Gets the stem of the given word.
   *
   * @param word The word to stem.
   * @param lang The language of the word.
   * @param result A pointer to the result string.
   */
  virtual void stem( zstring const &word, locale::iso639_1::type lang,
                     zstring *result ) const = 0;

protected:
  virtual ~Stemmer();
};

/**
 * A %StemmerProvider provides a Stemmer for a particular language.
 */
class StemmerProvider {
public:
  virtual ~StemmerProvider();

  /**
   * Gets the default %StemmerProvider.
   *
   * @return Returns said %StemmerProvider.
   */
  static StemmerProvider const& get_default();

  /**
   * Gets a Stemmer for the given language.
   *
   * @param lang The language to get a Stemmer for.
   * @param s If not \c null, set to point to a Stemmer for \a lang.
   * @return Returns \c true only if this provider can provide a stemmer for
   * \a lang.
   */
  virtual bool getStemmer( locale::iso639_1::type lang,
                           Stemmer::ptr *s = 0 ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif  /* ZORBA_NO_FULL_TEXT */
#endif  /* ZORBA_STEMMER_H */
/* vim:set et sw=2 ts=2: */
