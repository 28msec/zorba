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

#include "context/static_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/base/plan_iterator.h"

#include "runtime/util/flowctl_exception.h"

namespace zorba
{

/*******************************************************************************
  Global iterator ID counter, used for debugging purposes. Not really thread safe.
********************************************************************************/
#ifndef NDEBUG
static int global_iterator_id_counter = 1000;
#endif


/*******************************************************************************
  class PlanState
********************************************************************************/
PlanState::PlanState(
    dynamic_context* globalDctx,
    dynamic_context* localDctx,
    uint32_t blockSize,
    uint32_t aStackDepth,
    uint32_t aMaxStackDepth)
  :
  theBlockSize(blockSize),
  theStackDepth(aStackDepth),
  theMaxStackDepth(aMaxStackDepth),
  theCompilerCB(0),
  theQuery(0),
  theGlobalDynCtx(globalDctx),
  theLocalDynCtx(localDctx),
  theHasToQuit(false)
{
  assert(globalDctx != NULL && localDctx != NULL);
  theBlock = new int8_t[theBlockSize];
}



void PlanState::checkDepth(const QueryLoc& loc)
{
  if (theStackDepth > 256)
    throw XQUERY_EXCEPTION(
      zerr::ZXQP0003_INTERNAL_ERROR,
      ERROR_PARAMS( ZED( StackOverflow ) ),
      ERROR_LOC( loc )
    );
}


PlanState::~PlanState()
{
  // std::cerr << "--> PlanState::~PlanState() " << this << " deleting theBlock: " << (void*)theBlock << std::endl;
  delete[] theBlock;
  theBlock = 0;
}

/*******************************************************************************
  class PlanIteratorState
********************************************************************************/

PlanIteratorState::PlanIteratorState()
  :
  theDuffsLine(DUFFS_ALLOCATE_RESOURCES)
#if ZORBA_BATCHING_TYPE == 1
  , theCurrItem(ZORBA_BATCHING_BATCHSIZE)
#endif
#ifndef NDEBUG
  , theIsOpened(false)
#endif
{
}


/*******************************************************************************
  class PlanIterator
********************************************************************************/
PlanIterator::PlanIterator(zorba::serialization::Archiver& ar)
    :
    SimpleRCObject(ar),
    theSctx(NULL)
{
// Used for debugging purposes
#ifndef NDEBUG
  theId = global_iterator_id_counter++;
#endif

}

PlanIterator::PlanIterator(static_context* aContext, const QueryLoc& aLoc)
    :
    theStateOffset(0),
    loc(aLoc),
    theSctx(aContext)
{
// Used for debugging purposes
#ifndef NDEBUG
  theId = global_iterator_id_counter++;
#endif
}

SERIALIZE_INTERNAL_METHOD(PlanIterator)


void PlanIterator::serialize(::zorba::serialization::Archiver& ar)
{
  ar & loc;

  if (ar.dont_allow_delay_for_plan_sctx)
    ar.dont_allow_delay();

  ar & theSctx;
}


TypeManager* PlanIterator::getTypeManager() const
{
  return theSctx->get_typemanager();
}


#ifndef NDEBUG

bool PlanIterator::consumeNext(
    store::Item_t& result,
    const PlanIterator* iter,
    PlanState& planState)
{
  if (planState.theHasToQuit)
  {
    // std::cout << "Plan interupted" << std::endl;

    throw FlowCtlException(FlowCtlException::INTERRUPT);
  }

  if (planState.theCompilerCB->theConfig.print_item_flow)
  {
    std::cout << "next (" << iter->theId << " = " << iter->getClassName() << ") -> ?"
        << " on state: " << (void*)(planState.theBlock + iter->theStateOffset)
        << " (" << (void*)(planState.theBlock) << " + " << (void*)iter->theStateOffset << ")"
        << std::endl;
  }

  bool status = iter->produceNext(result, planState);

  if (planState.theCompilerCB->theConfig.print_item_flow)
  {
    // std::cout << "next (" << iter << " = " << typeid (*iter).name()
    std::cout << "next (" << iter->theId << " = " << iter->getClassName()
              << ") -> "
              << "status: " << status << " -> "
              << ((status && result != NULL) ? result->show().c_str() : "null")
              << std::endl;
  }
  return status;
}
#endif


} // namespace zorba
/* vim:set et sw=2 ts=2: */
