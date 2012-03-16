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
#include "stdafx.h"

#include "util/cxx_util.h"
#include "zorbautils/fatal.h"
#include "zorbautils/locale.h"

#include "sb_stemmer.h"

using namespace std;
using namespace zorba::locale;

namespace zorba {
namespace internal {

///////////////////////////////////////////////////////////////////////////////

static bool is_lang_supported( iso639_1::type lang ) {
  using namespace iso639_1;
  switch ( lang ) {
    case da:  // Danish
    case de:  // German
    case en:  // English
    case es:  // Spanish
    case fi:  // Finnish
    case fr:  // French
    case hu:  // Hungarian
    case it:  // Italian
    case nl:  // Dutch
    case no:  // Norwegian
    case pt:  // Portuguese
    case ro:  // Romanian
    case ru:  // Russian
    case sv:  // Swedish
    case tr:  // Turkish
      return true;
    default:
      return false;
  }
}

///////////////////////////////////////////////////////////////////////////////

SnowballStemmer::SnowballStemmer( iso639_1::type lang ) :
  stemmer_( sb_stemmer_new( iso639_1::string_of[ lang ], nullptr ) )
{
  ZORBA_FATAL( stemmer_, "out of memory" );
}

SnowballStemmer::~SnowballStemmer() {
  sb_stemmer_delete( stemmer_ );
}

SnowballStemmer const* SnowballStemmer::create( iso639_1::type lang ) {
  return is_lang_supported( lang ) ? new SnowballStemmer( lang ) : nullptr;
}

void SnowballStemmer::destroy() const {
  // Do nothing since built-in stemmers are cached for re-use.
}

void SnowballStemmer::properties( Properties *p ) const {
  p->uri = "http://www.zorba-xquery.com/full-text/stemmer/snowball";
}

void SnowballStemmer::stem( zstring const &word, iso639_1::type,
                            zstring *result ) const {
  //
  // We need a mutex since the libstemmer library is not thread-safe.
  //
  AutoMutex const lock( &mutex_ );

  sb_symbol const *const sb_word = sb_stemmer_stem(
    stemmer_, reinterpret_cast<sb_symbol const*>( word.c_str() ), word.length()
  );
  ZORBA_FATAL( sb_word, "out of memory" );
  *result = reinterpret_cast<char const*>( sb_word );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace internal
} // namespace zorba
/* vim:set et sw=2 ts=2: */
