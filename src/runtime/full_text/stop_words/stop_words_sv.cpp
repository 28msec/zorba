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
extern char const *const stop_words_sv[] = {
  "alla",
  "allt",
  auml "n",
  auml "r",
  acirc "t",
  "att",
  "av",
  "blev",
  "bli",
  "blir",
  "blivit",
  "d" acirc,
  "d" auml "r",
  "de",
  "dem",
  "den",
  "denna",
  "deras",
  "dess",
  "dessa",
  "det",
  "detta",
  "dig",
  "din",
  "dina",
  "ditt",
  "du",
  "efter",
  "ej",
  "eller",
  "en",
  "er",
  "era",
  "ert",
  "ett",
  "f" ouml "r",
  "fr" acirc "n",
  "ha",
  "hade",
  "han",
  "hans",
  "har",
  "h" auml "r",
  "henne",
  "hennes",
  "hon",
  "honom",
  "hur",
  "i",
  "icke",
  "ingen",
  "inom",
  "inte",
  "jag",
  "ju",
  "kan",
  "kunde",
  "man",
  "med",
  "mellan",
  "men",
  "mig",
  "min",
  "mina",
  "mitt",
  "mot",
  "mycket",
  "n" acirc "gon",
  "n" acirc "got",
  "n" acirc "gra",
  "n" auml "r",
  "ni",
  "nu",
  "och",
  "om",
  "oss",
  ouml "ver",
  "p" acirc,
  "s" acirc,
  "s" acirc "dan",
  "s" acirc "dana",
  "s" acirc "dant",
  "samma",
  "sedan",
  "sig",
  "sin",
  "sina",
  "sitta",
  "sj" auml "lv",
  "skulle",
  "som",
  "till",
  "under",
  "upp",
  "ut",
  "utan",
  "vad",
  "var",
  "v" acirc "r",
  "vara",
  "v" acirc "ra",
  "varf" ouml "r",
  "varit",
  "varje",
  "vars",
  "vart",
  "v" acirc "rt",
  "vem",
  "vi",
  "vid",
  "vilka",
  "vilkas",
  "vilken",
  "vilket",

  0
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
