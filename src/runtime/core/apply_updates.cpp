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
#include "stdafx.h"

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

#include "diagnostics/util_macros.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(ApplyIterator)


/*******************************************************************************

********************************************************************************/
void ApplyIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  theXDMItems.clear();
}


/*******************************************************************************

********************************************************************************/
ApplyIterator::ApplyIterator(
    static_context* sctx,
    const QueryLoc& loc,
    bool discardXDM,
    PlanIter_t& arg) 
  :
  UnaryBaseIterator<ApplyIterator, ApplyIteratorState>(sctx, loc, arg),
  theDiscardXDM(discardXDM)
{
}


/*******************************************************************************

********************************************************************************/
void ApplyIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<ApplyIterator, ApplyIteratorState>*)this);

  ar & theDiscardXDM;
}


/*******************************************************************************

********************************************************************************/
bool ApplyIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{ 
  dynamic_context* gdctx = planState.theGlobalDynCtx;
  CompilerCB* ccb = planState.theCompilerCB;

  store::Item_t item;
  ulong numItems = 0;
  store::PUL_t pul;

  ApplyIteratorState* state;
  DEFAULT_STACK_INIT(ApplyIteratorState, state, planState);

  // Note: updating expr might not return a pul because of vacuous exprs
  while (consumeNext(item, theChild, planState))
  {
    if (item->isPul())
    {
      if (pul)
      {
        pul->mergeUpdates(item);
      }
      else
      {
        pul.transfer(item);
      }
    }
    else if (!theDiscardXDM)
    {
      state->theXDMItems.resize(++numItems);
      state->theXDMItems.back().transfer(item);
    }
  }

  if(pul)
    apply_updates(ccb, gdctx, theSctx, pul, loc);

  state->theXDMIte = state->theXDMItems.begin();
  state->theXDMEnd = state->theXDMItems.end();
  
  for (; state->theXDMIte != state->theXDMEnd; ++state->theXDMIte)
  {
    result.transfer((*state->theXDMIte));
    STACK_PUSH(true, state);
  }

  state->theXDMItems.clear();

  STACK_END(state);
}


void apply_updates(
    CompilerCB* ccb,
    dynamic_context* gdctx,
    static_context* sctx,
    store::PUL* pul,
    const QueryLoc& loc)
{
  SchemaValidatorImpl validator(loc, sctx);
  ICCheckerImpl icChecker(sctx, gdctx);
  std::vector<store::Index*> indexes;
  std::vector<store::Index*> truncate_indexes;
  store::ItemHandle<store::PUL> indexPul;

  // Get all the indexes that are associated with any of the collections that
  // are going to be updated by this pul. Check which of those indices can be
  // maintained incrementally, and pass this info back to the pul.
  pul->getIndicesToRefresh(indexes, truncate_indexes);

  csize numIndices = indexes.size();

  std::vector<IndexDecl*> zorbaIndexes(numIndices); 

  for (csize i = 0; i < numIndices; ++i)
  {
    IndexDecl* indexDecl = sctx->lookup_index(indexes[i]->getName());
    
    if (indexDecl == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
      ERROR_PARAMS(indexes[i]->getName()->getStringValue()));
    }

    if (indexDecl->getMaintenanceMode() == IndexDecl::DOC_MAP)
    {
      DocIndexer* docIndexer = indexDecl->getDocIndexer(ccb, loc);
      assert(docIndexer != NULL);

      docIndexer->setup(ccb);

      pul->addIndexEntryCreator(indexDecl->getSourceName(0), indexes[i], docIndexer);
    }

    zorbaIndexes[i] = indexDecl;
  }

  numIndices = truncate_indexes.size();
  for (csize i = 0; i < numIndices; ++i)
  {
    IndexDecl* indexDecl = sctx->lookup_index(indexes[i]->getName());

    if (indexDecl->getMaintenanceMode() == IndexDecl::DOC_MAP)
    {
      pul->addIndexTruncator(indexDecl->getSourceName(0), indexes[i]);
    }
  }

  try 
  {
    // Apply updates
    pul->setValidator(&validator);
    pul->setICChecker(&icChecker);
    bool inherit = (sctx->inherit_mode() == StaticContextConsts::inherit_ns);
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

          PlanWrapper_t planWrapper = new PlanWrapper(buildPlan,
                                                      ccb,
                                                      NULL,
                                                      NULL,
                                                      0,
                                                      false,
                                                      0);

          indexPul->addRefreshIndex(&loc, zorbaIndex->getName(), planWrapper);
        }
      }

      indexPul->applyUpdates(inherit);
    }
  }
  catch (XQueryException& e)
  {
    if (e.has_source() &&
        (e.diagnostic() == err::XUDY0021 ||
         e.diagnostic() == err::XUDY0015 ||
         e.diagnostic() == err::XUDY0016 ||
         e.diagnostic() == err::XUDY0017 ||
         e.diagnostic() == err::XUDY0014)) 
    {
      XQueryException lNewE = 
      XQUERY_EXCEPTION(err::XUDY0021, ERROR_PARAMS(ZED(XUDY0021_AppliedAt), loc));

      QueryLoc lLoc;
      lLoc.setFilename(e.source_uri());
      lLoc.setLineBegin(e.source_line());
      lLoc.setColumnBegin(e.source_column());
      set_source(lNewE, lLoc);
      lNewE.set_diagnostic(e.diagnostic());

      throw lNewE;
    }
    else
    {
      // exception raised by the store doesn't have a store location
      // hence, we add the location of the apply expression
      set_source(e, loc);
      throw;
    }
  }
}


UNARY_ACCEPT(ApplyIterator);



} // namespace zorba
/* vim:set et sw=2 ts=2: */
