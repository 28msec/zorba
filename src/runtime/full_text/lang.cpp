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

#include "runtime/full_text/lang.h"
#include "zorbautils/less.h"

using namespace std;

namespace zorba {
namespace lang {

///////////////////////////////////////////////////////////////////////////////

namespace iso639_1 {

type find( char const *lang ) {
  static char const *const table[] = {
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
  };
  static char const *const *const end =
    table + sizeof( table ) / sizeof( char* );

  char const *const *const entry = ::lower_bound( table, end, lang );
  return entry != end ? static_cast<type>( entry - table ) : unknown;
}

} // namespace iso639_1

///////////////////////////////////////////////////////////////////////////////

namespace iso639_2 {

type find( char const *lang ) {
  static char const *const table[] = {
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
  };
  static char const *const *const end =
    table + sizeof( table ) / sizeof( char* );

  char const *const *const entry = ::lower_bound( table, end, lang );
  return entry != end ? static_cast<type>( entry - table ) : unknown;
}

} // namespace iso639_2

///////////////////////////////////////////////////////////////////////////////

iso639_1::type find( char const *lang ) {
  static iso639_1::type const table[] = {
    iso639_1::da, // Danish
    iso639_1::de, // German (T)
    iso639_1::nl, // Dutch (B)
    iso639_1::en, // English
    iso639_1::fi, // Finnish
    iso639_1::fr, // French (T)
    iso639_1::fr, // French (B)
    iso639_1::de, // German (B)
    iso639_1::hu, // Hungarian
    iso639_1::it, // Italian
    iso639_1::nl, // Dutch (T)
    iso639_1::no, // Norwegian
    iso639_1::pt, // Portuguese
    iso639_1::ro, // Romanian (T)
    iso639_1::ro, // Romanian (B)
    iso639_1::ru, // Russian
    iso639_1::es, // Spanish
    iso639_1::sv, // Swedish
    iso639_1::tr, // Turkish
  };
  static iso639_1::type const *const end =
    table + sizeof( table ) / sizeof( iso639_1::type );

  iso639_1::type const code_639_1 = iso639_1::find( lang );
  if ( code_639_1 != iso639_1::unknown )
    return code_639_1;

  iso639_2::type const code_639_2 = iso639_2::find( lang );
  if ( code_639_2 != iso639_2::unknown ) {
    //
    // Map the ISO 639-2 code to ISO 639-1.
    //
    iso639_1::type const *const entry = ::lower_bound( table, end, code_639_1 );
    if ( entry != end )
      return *entry;
  }

  return iso639_1::unknown;
}

///////////////////////////////////////////////////////////////////////////////

} // namespace lang
} // namespace zorba
/* vim:set et sw=2 ts=2: */
