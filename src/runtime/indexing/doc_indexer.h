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
#ifndef ZORBA_RUNTIME_VALUE_INDEX_DOC_INDEXER
#define ZORBA_RUNTIME_VALUE_INDEX_DOC_INDEXER

#include "common/shared_types.h"

#include "store/api/index.h"


namespace zorba 
{


/*******************************************************************************

********************************************************************************/
class DocIndexer : public store::IndexEntryCreator
{
protected:
  ulong               theNumColumns;

  PlanIter_t          theIndexerPlan;
  var_expr_t          theNodeVar; 

  dynamic_context   * theDctx;
  store::Iterator_t   thePlanWrapper;
  
public:
  DocIndexer(ulong numColumns, PlanIterator* plan, var_expr* var);

  ~DocIndexer();

  void setup(CompilerCB* ccb);

  void createIndexEntries(store::Item* docNode, store::IndexDelta& delta);
};


}

#endif


/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
