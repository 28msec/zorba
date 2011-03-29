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

#include "store/api/item_factory.h"
#include "store/api/pul.h"
#include "store/api/index.h"

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/core/apply_updates.h"
#include "runtime/indexing/doc_indexer.h"

#include "compiler/xqddf/value_index.h"
#include "compiler/xqddf/value_ic.h"

#include "context/static_context.h"

#include "types/schema/revalidateUtils.h"

#include "system/globalenv.h"

#include "zorbautils/fatal.h"

#include "common/shared_types.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ApplyIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ApplyIterator)


/*******************************************************************************

********************************************************************************/
bool ApplyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  store::Item_t tmp;
  store::Item_t pulItem;
  store::PUL* pul;
  SchemaValidatorImpl validator(loc, theSctx);
  store::ItemHandle<store::PUL> indexPul;
  std::vector<store::Index*> indexes;

  dynamic_context* gdctx = planState.theGlobalDynCtx;
  CompilerCB* ccb = planState.theCompilerCB;

  ICCheckerImpl icChecker(theSctx, gdctx);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Note: updating expr might not return a pul because of vacuous exprs
  if (consumeNext(pulItem, theChild, planState))
  {
    if (!pulItem->isPul())
      ZORBA_ERROR_LOC_DESC(XQP0019_INTERNAL_ERROR, loc,
                           "Expression does not return a pending update list");

    pul = static_cast<store::PUL*>(pulItem.getp());

    if (consumeNext(tmp, theChild, planState))
    {
      ZORBA_ERROR_LOC_DESC(XQP0019_INTERNAL_ERROR, loc,
                           "Expression returns more than one pending update lists");
    }

    // Get all the indexes that are associated with any of the collections that
    // are going to be updated by this pul. Check which of those indices can be
    // maintained incrementally, and pass this info back to the pul.
    pul->getIndicesToRefresh(indexes);

    ulong numIndices = (ulong)indexes.size();

    std::vector<IndexDecl*> zorbaIndexes(numIndices); 

    for (ulong i = 0; i < numIndices; ++i)
    {
      IndexDecl* zorbaIndex = theSctx->lookup_index(indexes[i]->getName());
      
      if (zorbaIndex == NULL)
      {
        ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                              indexes[i]->getName()->getStringValue().c_str(), "");
      }

      if (zorbaIndex->getMaintenanceMode() == IndexDecl::DOC_MAP)
      {
        DocIndexer* docIndexer = zorbaIndex->getDocIndexer(ccb, loc);
        assert(docIndexer != NULL);

        docIndexer->setup(ccb);

        pul->addIndexEntryCreator(zorbaIndex->getSourceName(0), indexes[i], docIndexer);
      }

      zorbaIndexes[i] = zorbaIndex;
    }

    try 
    {
      // Apply updates
      pul->setValidator(&validator);
      pul->setICChecker(&icChecker);
      bool inherit = (theSctx->inherit_mode() == StaticContextConsts::inherit_ns);
      pul->applyUpdates(inherit);

      // Rebuild the indices that must be rebuilt from scratch
      if (numIndices > 0)
      {
        indexPul = GENV_ITEMFACTORY->createPendingUpdateList();

        for (ulong i = 0; i < numIndices; ++i)
        {
          IndexDecl* zorbaIndex = zorbaIndexes[i];

          if (zorbaIndex->getMaintenanceMode() == IndexDecl::REBUILD)
          {
            PlanIter_t buildPlan = zorbaIndex->getBuildPlan(ccb, loc);

            PlanWrapper_t planWrapper = new PlanWrapper(buildPlan, ccb, NULL, NULL);

            indexPul->addRefreshIndex(zorbaIndex->getName(), planWrapper);
          }
        }

        indexPul->applyUpdates(inherit);
      }
    }
    catch (XQueryException& e)
    {
      set_source( e, loc );
      throw;
    }
  }

  STACK_END(state);
}


UNARY_ACCEPT(ApplyIterator);



}

