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

#include "runtime/nodes/structural.h"
#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "store/naive/atomic_items.h"
#include "store/naive/ordpath.h"

#include "util/string_util.h"
#include "util/uri_util.h"
#include "zorbautils/string_util.h"

using namespace std;

namespace zorba {

/*******************************************************************************
 ********************************************************************************/
bool NodeStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  bool valid;
  store::Item_t inNode;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inNode, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getStructuralInformation(result, inNode), state);
  STACK_END(state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsAncestorStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isAncestor(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsFollowingSiblingStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isFollowingSibling(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsFollowingStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isFollowing(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsDescendantStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isDescendant(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsPrecedingSiblingStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isPrecedingSibling(lUriB));

  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsPrecedingStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isPreceding(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsChildStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isChild(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsAttributeOfStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isAttribute(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}


/*******************************************************************************
 ********************************************************************************/
bool
IsParentStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isParent(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsPrecedingInDocumentOrderStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isPrecedingInDocumentOrder(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsFollowingInDocumentOrderStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isFollowingInDocumentOrder(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
LevelStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    result = lUri->getLevel();
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true, state);

  STACK_END (state);
}


/*******************************************************************************
 ********************************************************************************/
bool
IsAttributeStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isAttribute());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsCommentStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isComment());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsDocumentStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isDocument());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsElementStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isElement());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsProcessingInstructionStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isProcessingInstruction());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
IsTextStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->isText());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}
/*******************************************************************************
 ********************************************************************************/
bool
IsSiblingStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->isSibling(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}


/*******************************************************************************
 ********************************************************************************/
bool
InSameTreeStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->inSameTree(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
InCollectionStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUri, theChildren[0].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUri->inCollection());
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

/*******************************************************************************
 ********************************************************************************/
bool
InSameCollectionStructuralInformationIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lUriA;
  store::Item_t lUriB;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lUriA, theChildren[0].getp(), planState);
  consumeNext(lUriB, theChildren[1].getp(), planState);

  try
  {
    GENV_ITEMFACTORY->createBoolean(result, lUriA->inSameCollection(lUriB));
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc);
    throw;
  }

  STACK_PUSH(true,state);

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */

