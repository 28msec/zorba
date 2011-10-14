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

#include "runtime/nodes/node_position.h"
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
bool NodePositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsAncestorPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsFollowingSiblingPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsFollowingPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsDescendantPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsPrecedingSiblingPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsPrecedingPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsChildPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsAttributeOfPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsParentPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsPrecedingInDocumentOrderPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsFollowingInDocumentOrderPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
LevelPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsAttributePositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsCommentPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsDocumentPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsElementPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsProcessingInstructionPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsTextPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
IsSiblingPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
InSameTreePositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
InCollectionPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
InSameCollectionPositionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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

