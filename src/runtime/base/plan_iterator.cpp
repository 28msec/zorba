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

#include <typeinfo>

#include <zorba/properties.h>

#include "compiler/api/compilercb.h"

#include "context/static_context.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/util/flowctl_exception.h"

#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "system/globalenv.h"

#include "zorbatypes/integer.h"

#include "diagnostics/util_macros.h"


namespace zorba
{

/*******************************************************************************
  Global iterator ID counter, used for debugging purposes. Not really thread safe.
********************************************************************************/
#ifndef NDEBUG
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
static int global_iterator_id_counter = 1000;

void reset_global_iterator_id_counter()
{
  global_iterator_id_counter = 1000;
}
#endif
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
  theHasToQuit(false),
  profile_( Properties::instance().getProfile() )
{
  assert(globalDctx != NULL && localDctx != NULL);
  theBlock = new int8_t[theBlockSize];
}


void PlanState::checkDepth(const QueryLoc& loc)
{
  if (theStackDepth > 256)
    RAISE_ERROR(zerr::ZXQP0003_INTERNAL_ERROR, loc, ERROR_PARAMS(ZED(StackOverflow)));
}


PlanState::~PlanState()
{
  delete[] theBlock;
  theBlock = 0;
}


/*******************************************************************************
  class PlanIterator
********************************************************************************/
PlanIterator::PlanIterator(zorba::serialization::Archiver& ar)
    :    
    SimpleRCObject(ar),
    theStateOffset(0),
    theSctx(NULL)
{
}


PlanIterator::PlanIterator(static_context* sctx, const QueryLoc& aLoc)
    :
    theStateOffset(0),
    loc(aLoc),
    theSctx(sctx)
{
// Used for debugging purposes
#ifndef NDEBUG
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
  theId = global_iterator_id_counter++;
#endif
#endif
}


PlanIterator::PlanIterator(const PlanIterator& it)
  :
  SimpleRCObject(it),
  theStateOffset(0),
  loc(it.loc),
  theSctx(it.theSctx)
#ifndef NDEBUG
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
  , theId(it.theId)
#endif
#endif
{
}

PlanIterator::~PlanIterator() {
  // out-of-line since it's virtual
}

SERIALIZE_INTERNAL_METHOD(PlanIterator)

zstring PlanIterator::getNameAsString() const {
  return typeid( *this ).name();
}

void PlanIterator::serialize(::zorba::serialization::Archiver& ar)
{
  ar & loc;

  if (ar.dont_allow_delay_for_plan_sctx)
    ar.dont_allow_delay();

  ar & theSctx;
// Used for debugging purposes
#ifndef NDEBUG
#ifdef ZORBA_FOR_ONE_THREAD_ONLY
  ar & theId;
  // Set the global counter to the highest id +1.
  if (!ar.is_serializing_out())
    if (global_iterator_id_counter < theId + 1)
      global_iterator_id_counter = theId + 1;
#endif
#endif
}


#ifndef NDEBUG
std::string PlanIterator::toString() const
{
  std::stringstream ss;
  ss << getId() << " = " << getClassName();
  return ss.str();
}
#endif


TypeManager* PlanIterator::getTypeManager() const
{
  return theSctx->get_typemanager();
}


bool PlanIterator::count(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xs_integer count(0);

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (consumeNext(item, this, planState))
  {
    ++count;
  }

  STACK_PUSH(GENV_ITEMFACTORY->createInteger(result, xs_integer(count)), state);
  STACK_END(state);
}


bool PlanIterator::skip(int64_t count, PlanState& planState) const
{
  bool have_more_items = true;
  store::Item_t item;

  while (count-- > 0 && (have_more_items = consumeNext(item, this, planState)))
    ;

  return have_more_items;
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
  bool status = iter->produceNext(result, planState);

  if (planState.theCompilerCB->theConfig.print_item_flow)
  {
    if (Properties::instance().getStableIteratorIDs())
      std::cout << "next (" << iter->getId();
    else
      std::cout << "next (" << iter;

    std::cout << " = " << typeid (*iter).name()
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
