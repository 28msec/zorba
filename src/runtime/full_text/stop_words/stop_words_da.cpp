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
extern char const *const stop_words_da[] = {
  "ad",
  "af",
  "alle",
  "alt",
  "anden",
  "at",
  "blev",
  "blive",
  "bliver",
  "da",
  "de",
  "dem",
  "den",
  "denne",
  "der",
  "deres",
  "det",
  "dette",
  "dig",
  "din",
  "disse",
  "dog",
  "du",
  "efter",
  "eller",
  "en",
  "end",
  "er",
  "et",
  "for",
  "fra",
  "ham",
  "han",
  "hans",
  "har",
  "havde",
  "have",
  "hende",
  "hendes",
  "her",
  "hos",
  "hun",
  "hvad",
  "hvis",
  "hvor",
  "i",
  "ikke",
  "ind",
  "jeg",
  "jer",
  "jo",
  "kunne",
  "man",
  "mange",
  "med",
  "meget",
  "men",
  "mig",
  "min",
  "mine",
  "mit",
  "mod",
  "n" aring "r",
  "ned",
  "noget",
  "nogle",
  "nu",
  "og",
  "ogs" aring,
  "om",
  "op",
  "os",
  "over",
  "p" aring,
  "s" aring "dan",
  "selv",
  "sig",
  "sin",
  "sine",
  "sit",
  "skal",
  "skulle",
  "som",
  "thi",
  "til",
  "ud",
  "under",
  "var",
  "v" aelig "re",
  "v" aelig "ret",
  "vi",
  "vil",
  "ville",
  "vor",

  0
};

} // namespace zorba
/* vim:set et sw=2 ts=2: */
