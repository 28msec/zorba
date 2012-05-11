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
#include <zorba/identtypes.h>

namespace zorba {
  
char const *const IdentTypes::kind_string_of[] = {
  "NAMED",
  "element",
  "attribute",
  "document-node",
  "processing-instruction",
  "text",
  "comment",
  "node",
  "item",
  "empty-sequence",
  "schema-element",
  "schema-attribute",
  "INVALID",
  0
};

char const *const IdentTypes::quantifier_string_of[] = {
  "",
  "?",
  "+",
  "*",
  0
};
  
}

namespace std {

ostream& operator<<(ostream& o, const zorba::IdentTypes::kind_t ik) {
  return o << zorba::IdentTypes::kind_string_of[ik];
}

ostream& operator<<(ostream& o, const zorba::IdentTypes::quantifier_t iq) {
  return o << zorba::IdentTypes::quantifier_string_of[iq];
}

}

/* vim:set et sw=2 ts=2: */
