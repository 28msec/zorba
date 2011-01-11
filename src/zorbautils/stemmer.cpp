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

#include <memory>

#include "mutex.h"
#include "stemmer.h"
#include "stemmer/sb_stemmer.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

Stemmer::~Stemmer() {
  // do nothing
}

Stemmer const* Stemmer::get( iso639_1::type lang ) {
  static auto_ptr<Stemmer const> cached_stemmers[ iso639_1::NUM_ENTRIES ];
  static Mutex mutex;

  if ( !lang )
    lang = get_host_lang();

  AutoMutex const lock( &mutex );
  auto_ptr<Stemmer const> &ptr_ref = cached_stemmers[ lang ];
  if ( !ptr_ref.get() ) {
    if ( Stemmer const *const stemmer = SnowballStemmer::create( lang ) )
      ptr_ref.reset( stemmer );
    else
      return NULL;
  }
  return ptr_ref.get();
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
