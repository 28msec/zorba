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
#pragma once
#ifndef ZORBA_TYPECONSTANTS_H
#define ZORBA_TYPECONSTANTS_H

namespace zorba {

class TypeConstants 
{
 public:
  typedef enum 
  {
    QUANT_ONE = 0,
    QUANT_QUESTION,
    QUANT_STAR,
    QUANT_PLUS,
    QUANTIFIER_LIST_SIZE
  } quantifier_t;


  typedef enum 
  {
    NOT_CASTABLE,
    CASTABLE,
    MAYBE_CASTABLE,
  } castable_t;
};

}

#endif /* ZORBA_TYPECONSTANTS_H */
/* vim:set et sw=2 ts=2: */
