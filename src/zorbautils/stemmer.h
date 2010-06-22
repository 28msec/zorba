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

#include <string>

#include "zorbautils/locale.h"
#include "zorbautils/mutex.h"
#include "zorbautils/stemmer/include/libstemmer.h"

namespace zorba {

class Stemmer {
public:
  ~Stemmer();

  static Stemmer const* get( locale::iso639_1::type );

  void stem( std::string const &word, std::string &result ) const;

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
