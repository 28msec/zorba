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

#include "store/api/iterator.h"

namespace zorba {

// non-updating collection functions
NARY_ITER (ZorbaCollectionExistsIterator);

NARY_ITER (ZorbaNodeCountIterator);

NARY_ITER (ZorbaNodeAtIterator);

NARY_ITER (ZorbaIndexOfIterator);

NARY_ITER (ZorbaExportXmlIterator);


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
NARY_UPDATE_ITER (ZorbaImportXmlIterator);

NARY_UPDATE_ITER (ZorbaImportCatalogIterator);

NARY_UPDATE_ITER (ZorbaImportFolderIterator);

NARY_UPDATE_ITER (ZorbaCreateCollectionIterator);

NARY_UPDATE_ITER (ZorbaDeleteCollectionIterator);

NARY_UPDATE_ITER (ZorbaDeleteAllCollectionsIterator);

NARY_UPDATE_ITER (ZorbaInsertNodeFirstIterator);

NARY_UPDATE_ITER (ZorbaInsertNodeLastIterator);

NARY_UPDATE_ITER (ZorbaInsertNodeBeforeIterator);

NARY_UPDATE_ITER (ZorbaInsertNodeAfterIterator);

NARY_UPDATE_ITER (ZorbaInsertNodeAtIterator);

NARY_UPDATE_ITER (ZorbaRemoveNodeIterator);

NARY_UPDATE_ITER (ZorbaRemoveNodeAtIterator);

// helper function
store::Collection_t getCollection(PlanState&, const xqpStringStore_t, const QueryLoc);

}/*namespace zorba*/

#endif /* ZORBA_COLLECTIONS_IMPL_H */
