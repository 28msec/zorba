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

#ifndef ZORBA_COLLECTIONS_IMPL_H
#define ZORBA_COLLECTIONS_IMPL_H

#include "runtime/base/narybase.h"

//#include "store/api/iterator.h"

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

NARY_ITER_STATE_SCTX (FnCollectionIterator, FnCollectionIteratorState);


// non-updating collection functions
NARY_ITER_SCTX (ZorbaCollectionExistsIterator);

NARY_ITER_SCTX (ZorbaNodeCountIterator);

NARY_ITER_SCTX (ZorbaNodeAtIterator);

NARY_ITER_SCTX (ZorbaIndexOfIterator);

NARY_ITER_SCTX (ZorbaExportXmlIterator);


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
NARY_UPDATE_ITER_SCTX (ZorbaImportXmlIterator);

NARY_UPDATE_ITER_SCTX (ZorbaImportCatalogIterator);

NARY_UPDATE_ITER (ZorbaImportFolderIterator);

NARY_UPDATE_ITER_SCTX (ZorbaCreateCollectionIterator);

NARY_UPDATE_ITER_SCTX (ZorbaDeleteCollectionIterator);

NARY_UPDATE_ITER_SCTX (ZorbaDeleteAllCollectionsIterator);

NARY_UPDATE_ITER_SCTX (ZorbaInsertNodeFirstIterator);

NARY_UPDATE_ITER_SCTX (ZorbaInsertNodeLastIterator);

NARY_UPDATE_ITER_SCTX (ZorbaInsertNodeBeforeIterator);

NARY_UPDATE_ITER_SCTX (ZorbaInsertNodeAfterIterator);

NARY_UPDATE_ITER_SCTX (ZorbaInsertNodeAtIterator);

NARY_UPDATE_ITER_SCTX (ZorbaRemoveNodeIterator);

NARY_UPDATE_ITER_SCTX (ZorbaRemoveNodeAtIterator);

// helper function
store::Collection_t getCollection(static_context*,
                                  const xqpStringStore_t,
                                  const QueryLoc&);

}/*namespace zorba*/

#endif /* ZORBA_COLLECTIONS_IMPL_H */
