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

#include <zorba/locale.h>

#include "zorbatypes/zstring.h"

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

/**
 * A %Stemmer is used to "stem" words.
 */
class Stemmer {
public:
  virtual ~Stemmer();

  /**
   * Gets the stem of the given word.
   *
   * @param word The word to stem.
   * @param lang The language of the word.
   * @param result A pointer to the result string.
   */
  virtual void stem( zstring const &word, locale::iso639_1::type lang,
                     zstring *result ) const = 0;
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
  static StemmerProvider const& get_default_provider();

  /**
   * Gets an instance of a %Stemmer for the given language.
   *
   * @param lang The language for the stemmer.
   * @return Returns said %Stemmer or \c NULL if no stemmer is availabe for the
   * given language.
   */
  virtual Stemmer const* get_stemmer( locale::iso639_1::type lang ) const;
};

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
#endif  /* ZORBA_NO_FULL_TEXT */
#endif  /* ZORBA_STEMMER_H */
/* vim:set et sw=2 ts=2: */
