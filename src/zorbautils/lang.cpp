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

#include <algorithm>

#include <iostream>

#include "util/less.h"
#include "zorbautils/lang.h"

using namespace std;

namespace zorba {
namespace lang {

///////////////////////////////////////////////////////////////////////////////

inline int find_index( char const *const *begin, char const *const *end,
                       char const *lang ) {
  char const *const *const entry =
    ::lower_bound( begin, end, lang, less<char const*>() );
  return entry != end && ::strcmp( lang, *entry ) == 0 ? entry - begin : -1;
}

///////////////////////////////////////////////////////////////////////////////

namespace iso639_1 {

char const *const string_of[] = {
  "da", // Danish
  "de", // German
  "en", // English
  "es", // Spanish
  "fi", // Finnish
  "fr", // French
  "hu", // Hungarian
  "it", // Italian
  "nl", // Dutch
  "no", // Norwegian
  "pt", // Portuguese
  "ro", // Romanian
  "ru", // Russian
  "sv", // Swedish
  "tr", // Turkish
  "unknown"
};

type find( char const *lang ) {
  static char const *const *const end =
    string_of + sizeof( string_of ) / sizeof( char* );

  int const index = find_index( string_of, end, lang );
  return index >= 0 ? static_cast<type>( index ) : unknown;
}

} // namespace iso639_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_2 {

char const *const string_of[] = {
  "dan",  // Danish
  "deu",  // German (T)
  "dut",  // Dutch (B)
  "eng",  // English
  "fin",  // Finnish
  "fra",  // French (T)
  "fre",  // French (B)
  "ger",  // German (B)
  "hun",  // Hungarian
  "ita",  // Italian
  "nld",  // Dutch (T)
  "nor",  // Norwegian
  "por",  // Portuguese
  "ron",  // Romanian (T)
  "rum",  // Romanian (B)
  "rus",  // Russian
  "spa",  // Spanish
  "swe",  // Swedish
  "tur",  // Turkish
  "unknown"
};

type find( char const *lang ) {
  static char const *const *const end =
    string_of + sizeof( string_of ) / sizeof( char* );

  int const index = find_index( string_of, end, lang );
  return index >= 0 ? static_cast<type>( index ) : unknown;
}

} // namespace iso639_2

///////////////////////////////////////////////////////////////////////////////

iso639_1::type find( char const *lang ) {
  using namespace iso639_1;

  type const code_639_1 = iso639_1::find( lang );
  if ( code_639_1 != unknown )
    return code_639_1;

  static type const iso639_2_to_639_1[] = {
    da, // dan
    de, // deu
    nl, // dut
    en, // eng
    fi, // fin
    fr, // fra
    fr, // fre
    de, // ger
    hu, // hun
    it, // ita
    nl, // nld
    no, // nor
    pt, // por
    ro, // ron
    ro, // rum
    ru, // rus
    es, // spa
    sv, // swe
    tr, // tur
    unknown
  };
  return iso639_2_to_639_1[ iso639_2::find( lang ) ];
}

iso639_1::type get_default() {
  return iso639_1::en; // TODO: implement a real solution
}

///////////////////////////////////////////////////////////////////////////////

} // namespace lang
} // namespace zorba
/* vim:set et sw=2 ts=2: */
