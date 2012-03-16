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
#include "store/api/copymode.h"
#include "store/api/store.h"

#include "runtime/json/json_constructors.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "system/globalenv.h"

#include "context/static_context.h"

#include "diagnostics/util_macros.h"

#ifdef ZORBA_WITH_JSON

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(JSONObjectIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONObjectIterator)

SERIALIZABLE_CLASS_VERSIONS(JSONArrayIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONArrayIterator)

SERIALIZABLE_CLASS_VERSIONS(JSONDirectObjectIterator)
END_SERIALIZABLE_CLASS_VERSIONS(JSONDirectObjectIterator)


/*********************************************************************************

*********************************************************************************/
void JSONArrayIteratorState::open(
    PlanState& planState,
    const std::vector<PlanIter_t>& sources,
    const std::vector<bool>& copyInputs)
{
  csize numSources = sources.size();

  theSourcesWrappers.resize(numSources);
  theCopyModes.resize(numSources);

  for (csize i = 0; i < numSources; ++i)
  {
    theCopyModes[i].set(copyInputs[i], true, true, true);
    
    theSourcesWrappers[i] = new PlanIteratorWrapper(sources[i], planState);
  }
}


JSONArrayIterator::JSONArrayIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& content,
    bool copyInput)
  :
  NaryBaseIterator<JSONArrayIterator, JSONArrayIteratorState>(sctx, loc, content)
{
  csize numChildren = theChildren.size();

  theCopyInputs.resize(numChildren);

  for (csize i = 0; i < numChildren; ++i)
  {
    if (theChildren[i]->isConstructor())
    {
      theCopyInputs[i] = false;
    }
    else
    {
      theCopyInputs[i] = copyInput;
    }
  }
}


void JSONArrayIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<JSONArrayIterator, JSONArrayIteratorState>*)this);

  //ar & theCopyInputs; // TODO
}


void JSONArrayIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<JSONArrayIterator, JSONArrayIteratorState>::
  openImpl(planState, offset);

  JSONArrayIteratorState* state =
  StateTraitsImpl<JSONArrayIteratorState>::getState(planState, theStateOffset);

  state->open(planState, theChildren, theCopyInputs);
}


bool JSONArrayIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  JSONArrayIteratorState* state;
  DEFAULT_STACK_INIT(JSONArrayIteratorState, state, planState);

  try
  {
    GENV_ITEMFACTORY->createJSONArray(result, 
                                      state->theSourcesWrappers,
                                      state->theCopyModes);
  }
  catch (XQueryException& e)
  {
    result = NULL;
    set_source(e, loc, false);
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}


NARY_ACCEPT(JSONArrayIterator);


/*********************************************************************************

*********************************************************************************/
void JSONObjectIteratorState::open(
    PlanState& planState,
    const std::vector<PlanIter_t>& sources,
    const std::vector<bool>& copyInputs)
{
  csize numSources = sources.size();

  theSourcesWrappers.resize(numSources);
  theCopyModes.resize(numSources);

  for (csize i = 0; i < numSources; ++i)
  {
    theCopyModes[i].set(copyInputs[i], true, true, true);
    
    theSourcesWrappers[i] = new PlanIteratorWrapper(sources[i], planState);
  }
}


JSONObjectIterator::JSONObjectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& content,
    bool copyInput,
    bool accumulating)
  :
  NaryBaseIterator<JSONObjectIterator, JSONObjectIteratorState>(sctx, loc, content),
  theIsAccumulating(accumulating)
{
  csize numChildren = theChildren.size();

  theCopyInputs.resize(numChildren);

  for (csize i = 0; i < numChildren; ++i)
  {
    if (theChildren[i]->isConstructor())
    {
      theCopyInputs[i] = false;
    }
    else
    {
      theCopyInputs[i] = copyInput;
    }
  }
}


void JSONObjectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<JSONObjectIterator, JSONObjectIteratorState>*)this);

  //ar & theCopyInputs; // TODO
  ar & theIsAccumulating;
}


void JSONObjectIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  NaryBaseIterator<JSONObjectIterator, JSONObjectIteratorState>::
  openImpl(planState, offset);

  JSONObjectIteratorState* state =
  StateTraitsImpl<JSONObjectIteratorState>::getState(planState, theStateOffset);

  state->open(planState, theChildren, theCopyInputs);
}


bool JSONObjectIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  JSONObjectIteratorState* state;
  DEFAULT_STACK_INIT(JSONObjectIteratorState, state, planState);

  try
  {
    GENV_ITEMFACTORY->createJSONObject(result,
                                       state->theSourcesWrappers,
                                       state->theCopyModes,
                                       theIsAccumulating);

  }
  catch (XQueryException& e)
  {
    result = NULL;
    set_source(e, loc, false);
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}


NARY_ACCEPT(JSONObjectIterator);


/*********************************************************************************

*********************************************************************************/
JSONDirectObjectIterator::JSONDirectObjectIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& names,
    std::vector<PlanIter_t>& values,
    bool copyInput)
  :
  NaryBaseIterator<JSONDirectObjectIterator, PlanIteratorState>(sctx, loc, names)
{
  csize numPairs = values.size();

  theChildren.resize(2 * numPairs);

  theCopyInputs.resize(numPairs);

  for (csize i = 0; i < numPairs; ++i)
  {
    if (values[i]->isConstructor())
    {
      theCopyInputs[i] = false;
    }
    else
    {
      theCopyInputs[i] = copyInput;
    }

    theChildren[numPairs + i].transfer(values[i]);
  }
}


void JSONDirectObjectIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (NaryBaseIterator<JSONDirectObjectIterator, PlanIteratorState>*)this);

  //ar & theCopyInputs; // TODO
}


bool JSONDirectObjectIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  try
  {
    csize numPairs = theChildren.size() / 2;

    std::vector<store::Item_t> names(numPairs);
    std::vector<store::Item_t> values(numPairs);
    store::Item_t name;
    store::Item_t value;

    store::CopyMode copymode;
    copymode.set(true,
                 (theSctx->construction_mode() == StaticContextConsts::cons_preserve),
                 (theSctx->preserve_mode() == StaticContextConsts::preserve_ns),
                 true);

    for (csize i = 0; i < numPairs; ++i)
    {
      consumeNext(name, theChildren[i], planState);
      consumeNext(value, theChildren[numPairs + i], planState);

      if (theCopyInputs[i] && (value->isNode() || value->isJSONItem()))
        value = value->copy(NULL, copymode);

      names[i].transfer(name);
      values[i].transfer(value);
    }

    GENV_ITEMFACTORY->createJSONObject(result, names, values);
  }
  catch (XQueryException& e)
  {
    result = NULL;
    set_source(e, loc, false);
    throw;
  }

  STACK_PUSH(true, state);
  STACK_END(state);
}


NARY_ACCEPT(JSONDirectObjectIterator);

}

#endif // ZORBA_WITH_JSON
