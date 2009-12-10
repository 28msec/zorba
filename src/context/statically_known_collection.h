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
#ifndef ZORBA_CONTEXT_STATICALLY_KNOWN_COLLECTION_H
#define ZORBA_CONTEXT_STATICALLY_KNOWN_COLLECTION_H

#include "common/shared_types.h"
#include "context/static_context_consts.h"

#include "zorbaserialization/serialization_engine.h"

namespace zorba 
{

class StaticallyKnownCollection : public SimpleRCObject 
{
private:
  store::Item_t                              theName;
  StaticContextConsts::collection_property_t theCollProperty;
  StaticContextConsts::ordering_mode_t       theOrderProperty;
  StaticContextConsts::node_modifier_t       theNodeModifier;
  xqtref_t                                   theNodeType; 

public:
  SERIALIZABLE_CLASS(StaticallyKnownCollection);

  SERIALIZABLE_CLASS_CONSTRUCTOR2(StaticallyKnownCollection, SimpleRCObject);

  void serialize(::zorba::serialization::Archiver& ar)
  {
    serialize_baseclass(ar, (SimpleRCObject*)this);

    ar & theName;
    SERIALIZE_ENUM(StaticContextConsts::collection_property_t, theCollProperty);
    SERIALIZE_ENUM(StaticContextConsts::ordering_mode_t, theOrderProperty);
    SERIALIZE_ENUM(StaticContextConsts::node_modifier_t, theNodeModifier);
    ar & theNodeType;
  }

public:
  StaticallyKnownCollection(
        store::Item_t&                             aName,
        StaticContextConsts::collection_property_t aCollProperty,
        StaticContextConsts::ordering_mode_t       aOrderProperty,
        StaticContextConsts::node_modifier_t       aNodeModifier,
        xqtref_t&                                  aNodeType);

  ~StaticallyKnownCollection();

  const store::Item* getName() const { return theName.getp(); }

  StaticContextConsts::collection_property_t getCollProperty() const { return theCollProperty; }

  StaticContextConsts::ordering_mode_t getOrderProperty() const { return theOrderProperty; }

  StaticContextConsts::node_modifier_t getNodeModifier() const { return theNodeModifier; }

  const XQType* getNodeType() const { return theNodeType.getp(); }
};


typedef rchandle<StaticallyKnownCollection> StaticallyKownCollection_t;

}

#endif
