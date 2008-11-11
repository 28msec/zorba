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
#ifndef ZORBA_NODES_IMPL_H
#define ZORBA_NODES_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {

// zorba:node-reference
NARY_ITER(NodeReferenceIterator);

// zorba:node-by-reference
NARY_ITER(NodeByReferenceIterator);


// 14.2 fn:local-name
NARY_ITER(FnLocalNameIterator);

// 14.3 fn:namespace-uri
NARY_ITER(FnNamespaceUriIterator);

// 14.5 fn:lang
NARY_ITER(FnLangIterator);

// 15.5.6 fn:collection
class FnCollectionIteratorState : public PlanIteratorState 
{
public:
  store::Iterator_t theIterator;
  bool              theIteratorOpened;

  FnCollectionIteratorState();
  ~FnCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(FnCollectionIterator, FnCollectionIteratorState);

// NARY_ITER(FnCollectionIterator);
} /* namespace zorba */
#endif /* ZORBA_NODES_IMPL_H */
