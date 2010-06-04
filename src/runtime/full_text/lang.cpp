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

static char const *const iso639_1_table[] = {
  "ar",
  "bg",
  "cs",
  "cy",
  "da",
  "de",
  "el",
  "en",
  "es",
  "fa",
  "fi",
  "fr",
  "ga",
  "gd",
  "he",
  "hr",
  "hu",
  "hy",
  "id",
  "is",
  "it",
  "ja",
  "ko",
  "la",
  "my",
  "nb",
  "nl",
  "nn",
  "no",
  "pl",
  "pt",
  "ro",
  "ru",
  "th",
  "tr",
  "uk",
  "zh",
};

namespace zorba {
namespace lang {

iso639_1 find( char const *lang ) {
  static char const *const *const end =
    iso639_1_table + sizeof( iso639_1_table ) / sizeof( char* );

  char const *const *const x = ::lower_bound( iso639_1_table, end, lang );
  return x != end ? static_cast<iso639_1>( x - iso639_1_table ) : unknown_639_1;
}

} // namespace lang
} // namespace zorba
/* vim:set et sw=2 ts=2: */
