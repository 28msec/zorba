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

#include "zorbautils/fatal.h"
#include "zorbautils/stemmer.h"

using namespace std;

namespace zorba {

///////////////////////////////////////////////////////////////////////////////

stemmer::stemmer( lang::iso639_1::type lang_code ) :
  stemmer_( sb_stemmer_new( lang::iso639_1::string_of[ lang_code ], NULL ) )
{
  ZORBA_FATAL( stemmer_, "out of memory" );
}

stemmer::~stemmer() {
  sb_stemmer_delete( stemmer_ );
}

stemmer const* stemmer::get( lang::iso639_1::type lang_code ) {
  static stemmer* cached_stemmers[ lang::iso639_1::unknown ];
  static Mutex mutex;

  AutoMutex const lock( &mutex );
  stemmer *&ptr = cached_stemmers[ lang_code ];
  if ( !ptr )
    ptr = new stemmer( lang_code );
  return ptr;
}

void stemmer::stem( string const &word, string &result ) const {
  //
  // We need a mutex since the libstemmer library is not thread-safe.
  //
  AutoMutex const lock( &mutex_ );

  sb_symbol const *const sb_word = sb_stemmer_stem(
    stemmer_, reinterpret_cast<sb_symbol const*>( word.c_str() ), word.length()
  );
  ZORBA_FATAL( sb_word, "out of memory" );
  result = reinterpret_cast<char const*>( sb_word );
}

///////////////////////////////////////////////////////////////////////////////

} // namespace zorba
/* vim:set et sw=2 ts=2: */
