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
 
#ifndef ZORBA_STEMMER_H
#define ZORBA_STEMMER_H

#include "zorbatypes/zstring.h"

#include "locale.h"
#include "mutex.h"
#include "stemmer/include/libstemmer.h"

namespace zorba {

class Stemmer {
public:
  ~Stemmer();

  /**
   * Gets an instance of a %Stemmer for the given language.
   *
   * @param lang The language for the stemmer.
   * @return Returns said %Stemmer or NULL if no stemmer is availabe for the
   * given language.
   */
  static Stemmer const* get( locale::iso639_1::type lang );

  /**
   * Gets the stem of the given word.
   *
   * @param word The word to stem.
   * @param result A pointer to the result string.
   */
  void stem( zstring const &word, zstring *result ) const;

private:
  sb_stemmer *const stemmer_;
  mutable Mutex mutex_;

  Stemmer( locale::iso639_1::type );

  // forbid these
  Stemmer( Stemmer const& );
  Stemmer& operator=( Stemmer const& );
};

} // namespace zorba
#endif  /* ZORBA_STEMMER_H */
/* vim:set et sw=2 ts=2: */
