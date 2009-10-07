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

namespace zorba {

class StaticallyKnownCollection : public SimpleRCObject {
private:
  store::Item_t                              theName;
  xqtref_t                                   theNodeType; 
  StaticContextConsts::collection_modifier_t theCollectionModifier;
  StaticContextConsts::node_modifier_t       theNodeModifier;

public:
  StaticallyKnownCollection(store::Item_t&                             aName,
                            xqtref_t&                                  aNodeType,
                            StaticContextConsts::collection_modifier_t aCollectionModifier,
                            StaticContextConsts::node_modifier_t       aNodeModifier);
  ~StaticallyKnownCollection();

  const store::Item*                         getName() const               { return theName.getp(); }
  const XQType*                              getNodeType() const           { return theNodeType.getp(); }
  StaticContextConsts::collection_modifier_t getCollectionModifier() const { return theCollectionModifier; }
  StaticContextConsts::node_modifier_t       getNodeModifier() const       { return theNodeModifier; }
};

typedef rchandle<StaticallyKnownCollection> StaticallyKownCollection_t;

}

#endif
