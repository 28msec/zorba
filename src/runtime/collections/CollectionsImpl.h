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

#ifndef ZORBA_RUNTIME_COLLECTIONS
#define ZORBA_RUNTIME_COLLECTIONS

#include "runtime/base/narybase.h"


namespace zorba {

// fn:collection
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


// non-updating collection functions
class ZorbaCollectionIteratorState : public PlanIteratorState 
{
public:
  store::Iterator_t theIterator;
  bool              theIteratorOpened;

  ZorbaCollectionIteratorState();
  ~ZorbaCollectionIteratorState();

  void init(PlanState&);
  void reset(PlanState&);
};

NARY_ITER_STATE(ZorbaCollectionIterator, ZorbaCollectionIteratorState);

// non-updating collection functions
NARY_ITER(DcIsAvailableCollectionIterator);

NARY_ITER(ZorbaIndexOfIterator);


class CollectionNamesListState : public PlanIteratorState 
{
public:
  store::Iterator_t   nameItState;

  ~CollectionNamesListState();

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(DcAvailableCollectionsIterator, CollectionNamesListState);

NARY_ITER(ScIsDeclaredCollectionIterator);

NARY_ITER_STATE(ScDeclaredCollectionsIterator, CollectionNamesListState);

// updating collection functions
NARY_ITER(ZorbaCreateCollectionIterator);

NARY_ITER(ZorbaDropCollectionIterator);

NARY_ITER(ZorbaDropAllCollectionsIterator);

NARY_ITER(ZorbaInsertNodesFirstIterator);

NARY_ITER(ZorbaInsertNodesLastIterator);

NARY_ITER(ZorbaInsertNodesBeforeIterator);

NARY_ITER(ZorbaInsertNodesAfterIterator);

NARY_ITER(ZorbaInsertNodesAtIterator);

NARY_ITER(ZorbaRemoveNodesIterator);

NARY_ITER(ZorbaRemoveNodeAtIterator);

}/*namespace zorba*/

#endif /* ZORBA_COLLECTIONS_IMPL_H */
