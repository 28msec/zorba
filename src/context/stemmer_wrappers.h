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
#ifndef ZORBA_STEMER_WRAPPERS_H
#define ZORBA_STEMER_WRAPPERS_H

#include <zorba/config.h>

#ifndef ZORBA_NO_FULL_TEXT

#include <zorba/stemmer.h>
#include "zorbautils/stemmer.h"

namespace zorba {
namespace core {

class StemmerWrapper : public Stemmer {
public:
  StemmerWrapper( zorba::Stemmer const *api_stemmer );
  void stem( zstring const &word, zstring *result ) const;
private:
  zorba::Stemmer const *const api_stemmer_;
};

class StemmerProviderWrapper : public StemmerProvider {
public:
  StemmerProviderWrapper( zorba::StemmerProvider const *p );
  Stemmer const* get_stemmer( locale::iso639_1::type lang ) const;
private:
  zorba::StemmerProvider const *const api_stemmer_provider_;
};

} // namespace core
} // namespace zorba

#endif /* ZORBA_NO_FULL_TEXT */
#endif /* ZORBA_STEMER_WRAPPERS_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
