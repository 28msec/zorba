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

#include "utf8_chars.h"

namespace zorba {

//
// These words come from http://snowball.tartarus.org/.
//
extern char const *const stop_words_nl[] = {
  "aan",
  "al",
  "alles",
  "als",
  "altijd",
  "andere",
  "ben",
  "bij",
  "daar",
  "dan",
  "dat",
  "de",
  "der",
  "deze",
  "die",
  "dit",
  "doch",
  "doen",
  "door",
  "dus",
  "een",
  "eens",
  "en",
  "er",
  "ge",
  "geen",
  "geweest",
  "haar",
  "had",
  "heb",
  "hebben",
  "heeft",
  "hem",
  "het",
  "hier",
  "hij",
  "hoe",
  "hun",
  "iemand",
  "iets",
  "ik",
  "in",
  "is",
  "ja",
  "je",
  "kan",
  "kon",
  "kunnen",
  "maar",
  "me",
  "meer",
  "men",
  "met",
  "mij",
  "mijn",
  "moet",
  "na",
  "naar",
  "niet",
  "niets",
  "nog",
  "nu",
  "of",
  "om",
  "omdat",
  "onder",
  "ons",
  "ook",
  "op",
  "over",
  "reeds",
  "te",
  "tegen",
  "toch",
  "toen",
  "tot",
  "u",
  "uit",
  "uw",
  "van",
  "veel",
  "voor",
  "want",
  "waren",
  "was",
  "wat",
  "werd",
  "wezen",
  "wie",
  "wil",
  "worden",
  "wordt",
  "zal",
  "ze",
  "zelf",
  "zich",
  "zij",
  "zijn",
  "zo",
  "zonder",
  "zou",

  0
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
