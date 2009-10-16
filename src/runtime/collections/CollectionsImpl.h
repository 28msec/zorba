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
NARY_ITER(ZorbaCollectionExistsIterator);

NARY_ITER(ZorbaNodeCountIterator);

NARY_ITER(ZorbaNodeAtIterator);

NARY_ITER(ZorbaIndexOfIterator);

NARY_ITER(ZorbaExportXmlIterator);


class ZorbaListCollectionsState : public PlanIteratorState 
{
public:
  store::Iterator_t   uriItState;

  ~ZorbaListCollectionsState();

  void init(PlanState&);
  void reset(PlanState&);
};


NARY_ITER_STATE(ZorbaListCollectionsIterator, ZorbaListCollectionsState);

// updating collection functions
NARY_ITER(ZorbaImportXmlIterator);

NARY_ITER(ZorbaImportCatalogIterator);

NARY_ITER (ZorbaImportFolderIterator);

NARY_ITER(ZorbaCreateCollectionIterator);

NARY_ITER(ZorbaDeleteCollectionIterator);

NARY_ITER(ZorbaDeleteAllCollectionsIterator);

NARY_ITER(ZorbaInsertNodeFirstIterator);

NARY_ITER(ZorbaInsertNodeLastIterator);

NARY_ITER(ZorbaInsertNodeBeforeIterator);

NARY_ITER(ZorbaInsertNodeAfterIterator);

NARY_ITER(ZorbaInsertNodeAtIterator);

NARY_ITER(ZorbaRemoveNodeIterator);

NARY_ITER(ZorbaRemoveNodeAtIterator);

// helper function
store::Collection_t getCollection(static_context*,
                                  const xqpStringStore_t,
                                  const QueryLoc&);

}/*namespace zorba*/

#endif /* ZORBA_COLLECTIONS_IMPL_H */
