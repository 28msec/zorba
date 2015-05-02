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

#include "compiler/expression/function_item_expr.h"
#include "compiler/api/compilercb.h"
#include "compiler/translator/translator.h"

#include "functions/udf.h"

#include "runtime/api/plan_iterator_wrapper.h"
#include "runtime/util/iterator_impl.h"
#include "runtime/hof/fn_hof_functions.h"
#include "runtime/hof/function_item.h"
#include "runtime/core/fncall_iterator.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"

#include "types/typeops.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/api/temp_seq.h"

#include "diagnostics/util_macros.h"

#include "system/globalenv.h"

#include "zorbamisc/ns_consts.h"
#include "zorbatypes/integer.h"


#include "compiler/expression/expr_manager.h"
#include "compiler/expression/var_expr.h"

#include <zorba/internal/unique_ptr.h>


namespace zorba {


/*******************************************************************************

********************************************************************************/
bool FunctionLookupIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  CompilerCB* ccb = planState.theCompilerCB;
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  store::Item_t qname;
  store::Item_t arityItem;
  store::Item_t ctxItem;
  store::Item_t ctxPosItem;
  store::Item_t ctxSizeItem;
  csize arity;
  function* f;

  result = NULL;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(qname, theChildren[0], planState);
  consumeNext(arityItem, theChildren[1], planState);

  try
  {
    arity = static_cast<zorba::csize>(to_xs_unsignedLong(arityItem->getIntegerValue()));
  }
  catch ( std::range_error const& )
  {
    RAISE_ERROR(err::XPST0017, loc,
    ERROR_PARAMS(arityItem->getIntegerValue(), ZED(NoParseFnArity)));
  }

  f = theSctx->lookup_fn(qname, arity);

  if (f != NULL && f->isContextual())
  {
    try
    {
      consumeNext(ctxItem, theChildren[2], planState);
      consumeNext(ctxPosItem, theChildren[3], planState);
      consumeNext(ctxSizeItem, theChildren[4], planState);
    }
    catch (const ZorbaException& e)
    {
      if (e.diagnostic() != err::XPDY0002)
        throw;
    }
  }
  
  try
  {
    static_context_t impSctx = theSctx->create_child_context();
    ccb->theSctxMap[ccb->theSctxMap.size() + 1] = impSctx;

    std::unique_ptr<dynamic_context> fiDctx;
    fiDctx.reset(new dynamic_context(planState.theGlobalDynCtx));

    if (ctxItem)
    {
      store::Item_t ctxItemName;
      factory->createQName(ctxItemName, "", "", static_context::DOT_VAR_NAME);

      var_expr* ve = ccb->theEM->
      create_var_expr(impSctx, NULL, loc, var_expr::local_var, ctxItemName);

      ve->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM);

      impSctx->bind_var(ve, loc);

      fiDctx->add_variable(dynamic_context::IDVAR_CONTEXT_ITEM, ctxItem);
    }

    if (ctxPosItem)
    {
      store::Item_t ctxPosName;
      factory->createQName(ctxPosName, "", "", static_context::DOT_POS_VAR_NAME);

      var_expr* ve = ccb->theEM->
      create_var_expr(impSctx, NULL, loc, var_expr::local_var, ctxPosName);

      ve->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM_POSITION);

      impSctx->bind_var(ve, loc);

      fiDctx->add_variable(dynamic_context::IDVAR_CONTEXT_ITEM_POSITION, ctxPosItem);
    }

    if (ctxSizeItem)
    {
      store::Item_t ctxSizeName;
      factory->createQName(ctxSizeName, "", "", static_context::DOT_SIZE_VAR_NAME);

      var_expr* ve = ccb->theEM->
      create_var_expr(impSctx, NULL, loc, var_expr::local_var, ctxSizeName);

      ve->set_unique_id(dynamic_context::IDVAR_CONTEXT_ITEM_SIZE);

      impSctx->bind_var(ve, loc);

      fiDctx->add_variable(dynamic_context::IDVAR_CONTEXT_ITEM_SIZE, ctxSizeItem);
    }

    expr* fiExpr = 
    Translator::translate_literal_function(qname, arity, ccb, impSctx, loc);
    
    FunctionItemInfo_t fiInfo =
    static_cast<function_item_expr*>(fiExpr)->get_fi_info();

    fiInfo->theCCB = ccb;

    if (fiInfo->numInScopeVars() > 0)
    {
      result = new FunctionItem(fiInfo, fiDctx.get());
      fiDctx.release();
    }
    else
    {
      result = new FunctionItem(fiInfo, NULL);
    }
  }
  catch (const ZorbaException& e)
  {
    if (e.diagnostic() != err::XPST0017)
      throw;
  }
  
  if (result.getp() != NULL)
    STACK_PUSH(true, state); 
    
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool FunctionNameIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t lFItem;
  FunctionItem* lFunctionItem = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<FunctionItem*>(lFItem.getp());

  if ((!lFunctionItem->isInline() || lFunctionItem->isCoercion())
      &&
      lFunctionItem->getFunctionName()
      &&
      (lFunctionItem->getArity() == lFunctionItem->getStartArity()))
  {
    // non-inline function
    r = lFunctionItem->getFunctionName();
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool FunctionArityIterator::nextImpl(
    store::Item_t& r,
    PlanState& planState) const
{
  store::Item_t lFItem;
  FunctionItem* lFunctionItem = 0;
  xs_integer    lInt;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lFItem, theChildren[0], planState);

  // function signature guarantees that
  ZORBA_ASSERT(lFItem->isFunction());

  lFunctionItem = static_cast<FunctionItem*>(lFItem.getp());

  lInt = Integer(lFunctionItem->getArity());

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(r, lInt), state);

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
FnForEachPairIteratorState::~FnForEachPairIteratorState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


void FnForEachPairIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


void FnForEachPairIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen)
  {
    thePlan->reset(planState);
  }
}


uint32_t FnForEachPairIterator::getStateSizeOfSubtree() const
{
  uint32_t size = NaryBaseIterator<FnForEachPairIterator, FnForEachPairIteratorState>::
                  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


void FnForEachPairIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<FnForEachPairIteratorState>::createState(planState,
                                                theStateOffset,
                                                offset);

  StateTraitsImpl<FnForEachPairIteratorState>::initState(planState, theStateOffset);

  FnForEachPairIteratorState* state =
  StateTraitsImpl<FnForEachPairIteratorState>::getState(planState, theStateOffset);

  state->theUDFStateOffset = offset;

  offset += sizeof(UDFunctionCallIteratorState);

  std::vector<PlanIter_t>::iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
        {
    (*lIter)->open(planState, offset);
  }
}


bool FnForEachPairIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t child1, child2;
  std::vector<PlanIter_t> arguments;

  FnForEachPairIteratorState* state;
  DEFAULT_STACK_INIT(FnForEachPairIteratorState, state, planState);

  consumeNext(state->theFnItem, theChildren[2], planState);

  // function signature guarantees that
  ZORBA_ASSERT(state->theFnItem->isFunction());

  while (true)
  {
    if (!consumeNext(child1, theChildren[0], planState) ||
        !consumeNext(child2, theChildren[1], planState))
      break;

    if (child1.getp() && child2.getp())
    {
      {
        store::TempSeq_t seq1, seq2;
        seq1 = GENV_STORE.createTempSeq(child1);
        seq2 = GENV_STORE.createTempSeq(child2);
        store::Iterator_t seqIter1 = seq1->getIterator();
        store::Iterator_t seqIter2 = seq2->getIterator();
        seqIter1->open();
        seqIter2->open();

        arguments.push_back(NULL); // the first argument is expected to be the function item and it is not used
        arguments.push_back(new PlanStateIteratorWrapper(seqIter1));
        arguments.push_back(new PlanStateIteratorWrapper(seqIter2));
      }

      state->thePlan = static_cast<FunctionItem*>(state->theFnItem.getp())->getImplementation(arguments, planState.theCompilerCB);
      // must be opened after vars and params are set
      state->thePlan->open(planState, state->theUDFStateOffset);
      state->theIsOpen = true;

      while (consumeNext(result, state->thePlan, planState))
      {
        STACK_PUSH(true, state);
      }

      // need to close here early in case the plan is completely
      // consumed. Otherwise, the plan would still be opened
      // if destroyed from the state's destructor.
      state->thePlan->close(planState);
      state->theIsOpen = false;
    }
    else
    {
      result = NULL;
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
FnFoldLeftIteratorState::~FnFoldLeftIteratorState()
{
  if (theIsOpen)
  {
    thePlan->close(*thePlanState);
  }
}


void FnFoldLeftIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  thePlanState = &planState;
  thePlan = NULL;
  theIsOpen = false;
}


void FnFoldLeftIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theIsOpen)
  {
    thePlan->reset(planState);
  }
}


uint32_t FnFoldLeftIterator::getStateSizeOfSubtree() const
{
  uint32_t size = NaryBaseIterator<FnFoldLeftIterator, FnFoldLeftIteratorState>::
                  getStateSizeOfSubtree();

  return size + sizeof(UDFunctionCallIteratorState);
}


void FnFoldLeftIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<FnFoldLeftIteratorState>::createState(planState,
                                                theStateOffset,
                                                offset);

  StateTraitsImpl<FnFoldLeftIteratorState>::initState(planState, theStateOffset);

  FnFoldLeftIteratorState* state =
  StateTraitsImpl<FnFoldLeftIteratorState>::getState(planState, theStateOffset);

  state->theUDFStateOffset = offset;

  offset += sizeof(UDFunctionCallIteratorState);

  std::vector<PlanIter_t>::iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
        {
    (*lIter)->open(planState, offset);
  }
}


bool FnFoldLeftIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t curSeqItem, nextSeqItem, tempItem;
  std::vector<store::Item_t> zero;
  bool haveSeqItems;

  FnFoldLeftIteratorState* state;
  DEFAULT_STACK_INIT(FnFoldLeftIteratorState, state, planState);

  consumeNext(state->theFnItem, theChildren[2], planState);

  // function signature guarantees that
  ZORBA_ASSERT(state->theFnItem->isFunction());

  if ((haveSeqItems = consumeNext(curSeqItem, theChildren[0], planState)))
    haveSeqItems = consumeNext(nextSeqItem, theChildren[0], planState);

  if (curSeqItem.getp() == NULL && nextSeqItem.getp() == NULL)
  {
    // consume and return the "zero" argument
    while (consumeNext(result, theChildren[1], planState))
    {
      STACK_PUSH(true, state);
    }
  }
  else
  {
    // read in the "zero" argument to be able to pass it to the hof
    while (consumeNext(tempItem, theChildren[1], planState))
    {
      zero.push_back(tempItem);
    }

    while (true)
    {
      {
        store::TempSeq_t zeroSeq = GENV_STORE.createTempSeq(zero);
        tempItem = curSeqItem; // because createTempSeq calls .release() on the item rchandle
        store::TempSeq_t seq = GENV_STORE.createTempSeq(tempItem);
        store::Iterator_t seqIter1 = zeroSeq->getIterator();
        store::Iterator_t seqIter2 = seq->getIterator();
        seqIter1->open();
        seqIter2->open();

        std::vector<PlanIter_t> arguments;
        arguments.push_back(NULL);
        arguments.push_back(new PlanStateIteratorWrapper(seqIter1));
        arguments.push_back(new PlanStateIteratorWrapper(seqIter2));
        if (theIsFoldRight)
          std::reverse(++arguments.begin(), arguments.end());

        state->thePlan = static_cast<FunctionItem*>(state->theFnItem.getp())->getImplementation(arguments, planState.theCompilerCB);
        state->thePlan->open(planState, state->theUDFStateOffset);
        state->theIsOpen = true; 
      }

      if (curSeqItem.isNull() || nextSeqItem.isNull())
        break;

      zero.clear();
      while (consumeNext(tempItem, state->thePlan, planState))
      {
        zero.push_back(tempItem);
      }

      state->thePlan->close(planState);
      state->theIsOpen = false;

      curSeqItem = nextSeqItem;
      nextSeqItem = NULL;
      if (haveSeqItems)
        haveSeqItems = consumeNext(nextSeqItem, theChildren[0], planState);

    } // while (true)

    while (consumeNext(result, state->thePlan, planState))
    {
      STACK_PUSH(true, state);
    }

    state->thePlan->close(planState);
    state->theIsOpen = false;

  } // else

  STACK_END(state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
