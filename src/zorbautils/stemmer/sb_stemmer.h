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
#ifndef ZORBA_SNOWBALL_STEMMER_H
#define ZORBA_SNOWBALL_STEMMER_H

#include "../stemmer.h"
#include "include/libstemmer.h"
#include "zorbautils/mutex.h"

namespace zorba {
namespace internal {

/**
 * A %SnowballStemmer is-a Stemmer that uses the C-from-Snowball code found at
 * http://snowball.tartarus.org/texts/stemmersoverview.html
 */
class SnowballStemmer : public Stemmer {
public:
  ~SnowballStemmer();

  /**
   * Creates a %SnowballStemmer.
   *
   * @param lang The language to create a stemmer for.
   * @return Returns a stemmer for the given language or \c NULL if no stemmer
   * for the given language is available.
   */
  static SnowballStemmer const* create( locale::iso639_1::type lang );

  // inherited
  void stem( zstring const &word, locale::iso639_1::type lang,
             zstring *result ) const;

private:
  sb_stemmer *const stemmer_;
  mutable Mutex mutex_;

  SnowballStemmer( locale::iso639_1::type );

  // forbid these
  SnowballStemmer( SnowballStemmer const& );
  SnowballStemmer& operator=( SnowballStemmer const& );
};

} // namespace internal
} // namespace zorba
#endif  /* ZORBA_SNOWBALL_STEMMER_H */
/* vim:set et sw=2 ts=2: */
