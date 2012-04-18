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
#ifndef ZORBA_COMPILER_EXPR_UTILS
#define ZORBA_COMPILER_EXPR_UTILS

#include "zorbaserialization/serialize_basic_types.h"

namespace zorba 
{

/******************************************************************************
  Used by the orderspecs of an order by clause, and by the keyspecs of an
  index declaration.
********************************************************************************/
class OrderModifier : public SimpleRCObject
{
public:
  bool         theAscending;
  bool         theEmptyLeast;
  std::string  theCollation;

  SERIALIZABLE_CLASS(OrderModifier)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(OrderModifier, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver& ar)
  {
    ar & theAscending;
    ar & theEmptyLeast;
    ar & theCollation;
  }

public:
  OrderModifier() 
    :
    theAscending(true),
    theEmptyLeast(true)
  {
  }
};


}
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
