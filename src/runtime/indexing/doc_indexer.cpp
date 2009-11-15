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

#include "context/dynamic_context.h"

#include "compiler/expression/var_expr.h"
#include "compiler/codegen/plan_visitor.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"
#include "runtime/indexing/doc_indexer.h"

#include "store/api/item.h"


namespace zorba 
{


/*******************************************************************************

********************************************************************************/
DocIndexer::DocIndexer(ulong numColumns, PlanIterator* plan, var_expr* var)
  :
  theNumColumns(numColumns),
  theIndexerPlan(plan),
  theNodeVar(var)
{
}


/*******************************************************************************

********************************************************************************/
DocIndexer::~DocIndexer()
{
  if (thePlanWrapper)
    thePlanWrapper->close();
}


/*******************************************************************************

********************************************************************************/
void DocIndexer::setup(CompilerCB* ccb, dynamic_context* dctx)
{
  if (thePlanWrapper == NULL)
  {
    theDctx = dctx;

    thePlanWrapper = new PlanWrapper(theIndexerPlan, ccb, dctx, NULL);

    theDctx->declare_variable(dctx->var_key(theNodeVar));

    thePlanWrapper->open();
  }
}


/*******************************************************************************

********************************************************************************/
void DocIndexer::createIndexEntries(
     store::Item* docNode,
     std::vector<store::Item_t>& domainNodes,
     std::vector<store::IndexKey*>& keyTuples)
{
  store::Item_t tmp = docNode;
  theDctx->set_variable(theDctx->var_key(theNodeVar), tmp);

  ulong numEntries = 0;
  store::Item_t domainNode;
  store::IndexKey* key = NULL;

  try
  {
    while (thePlanWrapper->next(domainNode))
    {
      key = new store::IndexKey(theNumColumns);

      for (ulong i = 0; i < theNumColumns; ++i)
      {
        if (!thePlanWrapper->next((*key)[i]))
        {
          ZORBA_ERROR_DESC(XQP0019_INTERNAL_ERROR, "Incomplete key during index refresh");
        }
      }
      
      domainNodes.resize(numEntries + 1);
      keyTuples.resize(numEntries + 1);
      domainNodes[numEntries].transfer(domainNode); 
      keyTuples[numEntries] = key;
      key = NULL;
      ++numEntries;
    }
  }
  catch(...)
  {
    if (key != NULL)
      delete key;

    for (ulong i = 0; i < keyTuples.size(); ++i)
    {
      delete keyTuples[i];
    }

    thePlanWrapper->reset();

    throw;
  }

  thePlanWrapper->reset();
}



}

