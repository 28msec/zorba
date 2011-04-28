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
#ifndef ZORBA_CONTEXT_STATICALLY_KNOWN_COLLECTION_H
#define ZORBA_CONTEXT_STATICALLY_KNOWN_COLLECTION_H

#include "common/shared_types.h"

#include "context/static_context_consts.h"

#include "types/typeconstants.h"

#include "zorbaserialization/serialization_engine.h"

namespace zorba 
{

class StaticallyKnownCollection : public SimpleRCObject 
{
private:
  store::Item_t                                theName;
  StaticContextConsts::declaration_property_t  theUpdateProperty;
  StaticContextConsts::declaration_property_t  theOrderProperty;
  StaticContextConsts::node_modifier_t         theNodeModifier;
  xqtref_t                                     theNodeType; 
  xqtref_t                                     theCollectionType;

public:
  SERIALIZABLE_CLASS(StaticallyKnownCollection);

  SERIALIZABLE_CLASS_CONSTRUCTOR2(StaticallyKnownCollection, SimpleRCObject);

  void serialize(::zorba::serialization::Archiver& ar);

public:
  StaticallyKnownCollection(
        store::Item_t&                              aName,
        StaticContextConsts::declaration_property_t aUpdateProperty,
        StaticContextConsts::declaration_property_t aOrderProperty,
        StaticContextConsts::node_modifier_t        aNodeModifier,
        xqtref_t&                                   aNodeType,
        xqtref_t&                                   aCollectionType);

  ~StaticallyKnownCollection();

  const store::Item* getName() const { return theName.getp(); }

  StaticContextConsts::declaration_property_t getUpdateProperty() const
  {
    return theUpdateProperty;
  }

  StaticContextConsts::declaration_property_t getOrderProperty() const 
  {
    return theOrderProperty;
  }

  StaticContextConsts::node_modifier_t getNodeModifier() const
  {
    return theNodeModifier;
  }

  const XQType* getNodeType() const
  {
    return theNodeType.getp();
  }

  const XQType* getCollectionType() const
  {
    return theCollectionType.getp();
  }
};


typedef rchandle<StaticallyKnownCollection> StaticallyKownCollection_t;

}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
