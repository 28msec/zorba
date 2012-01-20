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
#ifndef ZORBA_TYPEIDENT_TYPES_API_H
#define ZORBA_TYPEIDENT_TYPES_API_H

#include <zorba/config.h>

namespace zorba 
{

class ZORBA_DLL_PUBLIC IdentTypes 
{
public:
  typedef enum 
  {
    NAMED_TYPE,     // builtin atomic type
    ELEMENT_TYPE,
    ATTRIBUTE_TYPE,
    DOCUMENT_TYPE,
    PI_TYPE,
    TEXT_TYPE,
    COMMENT_TYPE,
    ANY_NODE_TYPE, // node()
#ifdef ZORBA_WITH_JSON
    STRUCTURED_ITEM_TYPE,
    JSON_ITEM_TYPE,
    JSON_OBJECT_TYPE,
    JSON_ARRAY_TYPE,
    JSON_PAIR_TYPE,
#endif
    ITEM_TYPE,     // item()
    EMPTY_TYPE,    // empty-sequence()
    INVALID_TYPE,
  } kind_t;

  typedef enum 
  {
    QUANT_ONE,
    QUANT_QUESTION,
    QUANT_PLUS,
    QUANT_STAR,
  } quantifier_t;
};
}

#endif
/* vim:set et sw=2 ts=2: */
