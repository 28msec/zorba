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

#include "runtime/nodes/nodes.h"
#include "zorbamisc/ns_consts.h"

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "util/string_util.h"
#include "util/uri_util.h"
#include "zorbautils/string_util.h"

using namespace std;

namespace zorba {

bool NodeReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  bool valid;
  store::Item_t inNode;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inNode, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getReference(result, inNode), state);
  STACK_END(state);
}

bool NodeByReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inUri;
  bool valid;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inUri, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getNodeByReference(result, inUri), state);
  STACK_END (state);
}


// 14.2 fn:local-name
//---------------------
bool FnLocalNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring strRes;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0], planState))
  {
    if(inNode->getNodeKind() == store::StoreConsts::documentNode ||
       inNode->getNodeKind() == store::StoreConsts::commentNode ||
       inNode->getNodeKind() == store::StoreConsts::textNode)
    {
      ;
    }
    else if(inNode->getNodeKind() == store::StoreConsts::piNode)
    {
      strRes = inNode->getTarget();
    }
    else
    {
      strRes = inNode->getNodeName()->getLocalName();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }

  STACK_END (state);
}


// 14.3 fn:namespace-uri
//---------------------
bool FnNamespaceUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  zstring  uriStr;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState)) 
  {
    if(inNode->getNodeKind() == store::StoreConsts::elementNode ||
       inNode->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      uriStr = inNode->getNodeName()->getNamespace();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }
  else
  {
    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
  }

  STACK_END (state);
}


// 14.5 fn:lang
//---------------------
bool
FnLangIterator::isLangAttr(const store::Item_t& aAttr) const
{
  store::Item* lAttrName = aAttr->getNodeName();

  return (ZSTREQ(lAttrName->getLocalName(), "lang") &&
          ZSTREQ(lAttrName->getNamespace(), XML_NS));
}

bool
FnLangIterator::matchesReqLang(
    const store::Item_t& aAttr,
    const zstring& aRequestLang) const
{
  return utf8::match_whole( 
            aAttr->getStringValue(), aRequestLang.str() + "(?:-.+)?", "i");
}

bool FnLangIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, attr;
  store::Iterator_t lAttributes;
  bool              lLangAttrFound = false, lLangAttrMatched = false;
  zstring reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(consumeNext(item, theChildren[0].getp(), planState))
  {
    item->getStringValue2(reqLang);

    if (consumeNext(item, theChildren[1].getp(), planState)) 
    {
      // nearest ancestor
      while (item != NULL)
      {
        if(item->getNodeKind () == store::StoreConsts::elementNode)
        {
          lAttributes = item->getAttributes();
          lAttributes->open();
          while (lAttributes->next(attr))
          {
            if (isLangAttr(attr)) {
              lLangAttrFound = true;
              if (matchesReqLang(attr, reqLang)) {
                lLangAttrMatched = true;
              }
              break; // inner attribute loop
            }
          }
          lAttributes->close();
        }
        else if(item->getNodeKind () == store::StoreConsts::attributeNode)
        {
          if(item->getParent() != NULL)
          {
            if (isLangAttr(item)) {
              lLangAttrFound = true;
              if (matchesReqLang(item, reqLang)) {
                lLangAttrMatched = true;
              }
            }
          }
        }
        if (lLangAttrFound || lLangAttrMatched ) {
          break; // break outer loop
        }
        item = item->getParent();
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lLangAttrMatched), state);

  STACK_END (state);
}

bool FnHasChildrenIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, child1;
  store::Iterator_t children;
  bool              has_children = false;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size() && consumeNext(item, theChildren[0].getp(), planState))
  {
    children = item->getChildren();
    if(!children.isNull())
    {
      children->open();
      if(children->next(child1))
        has_children = true;
      children->close();
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, has_children), state);

  STACK_END (state);
}

static bool is_ancestor_of(store::Item_t parent, store::Item_t child)
{
  if(parent == NULL)
    return false;
  while(child != NULL)
  {
    if(parent == child)
      return true;
    child = child->getParent();
  }
  return false;
}

bool FnInnermostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;

  FnInnermostIteratorState *state;
  DEFAULT_STACK_INIT(FnInnermostIteratorState, state, planState);

  while(consumeNext(item, theChildren[0].getp(), planState))
  {
    std::list<store::Item_t>::iterator  list_it;
    bool dont_add = false;
    for(list_it = state->node_list.begin(); list_it != state->node_list.end();)
    {
      if(is_ancestor_of(item, *list_it))
      {
        dont_add = true;
        break;
      }
      if(is_ancestor_of(*list_it, item))
      {
        list_it = state->node_list.erase(list_it);
        continue;
      }
      list_it++;
    }
    if(!dont_add)
      state->node_list.push_back(item);
  }

  for(state->list_it = state->node_list.begin(); state->list_it != state->node_list.end(); state->list_it++)
  {
    result = *state->list_it;
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

bool FnOutermostIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;

  FnOutermostIteratorState *state;
  DEFAULT_STACK_INIT(FnOutermostIteratorState, state, planState);

  while(consumeNext(item, theChildren[0].getp(), planState))
  {
    std::list<store::Item_t>::iterator  list_it;
    bool dont_add = false;
    for(list_it = state->node_list.begin(); list_it != state->node_list.end();)
    {
      if(is_ancestor_of(*list_it, item))
      {
        dont_add = true;
        break;
      }
      if(is_ancestor_of(item, *list_it))
      {
        list_it = state->node_list.erase(list_it);
        continue;
      }
      list_it++;
    }
    if(!dont_add)
      state->node_list.push_back(item);
  }

  for(state->list_it = state->node_list.begin(); state->list_it != state->node_list.end(); state->list_it++)
  {
    result = *state->list_it;
    STACK_PUSH(true, state);
  }

  STACK_END (state);
}

bool FnGenerateIdIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item;
  bool retval;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(theChildren.size())
  {
    {
      zstring uri_string, lRes;
      if(consumeNext(item, theChildren[0].getp(), planState))
      {
        store::Item_t   item_uri;
        if(GENV_STORE.getReference(item_uri, item.getp()))
        {
          uri_string = item_uri->getStringValue();
          // need to convert the opaque uri into a valid ncname
          // e.g. z0.1.1.c.50
#ifndef NDEBUG
          ZORBA_ASSERT( uri_string.find_first_of("zorba:") == 0 );
#endif
          lRes = "z" + uri_string.substr(uri_string.find_first_of(":") + 1);
        }
      }
      retval = GENV_ITEMFACTORY->createString(result, lRes);
    }
    STACK_PUSH(retval, state);
  }

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsFollowingSiblingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialFollowingSibling;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialFollowingSibling, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialFollowingSibling->isFollowingSibling(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsFollowingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialFollowing;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialFollowing, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialFollowing->isFollowing(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsChildIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialChild;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialChild, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialChild->isChild(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
LevelIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lArg;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArg, theChildren[0].getp(), planState);

  result = lArg->getLevel();

  STACK_PUSH(true, state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
LeastCommonAncestor::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lArg1, lArg2;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lArg1, theChildren[0].getp(), planState);
  consumeNext(lArg2, theChildren[1].getp(), planState);

  result = lArg1->leastCommonAncestor(lArg2);

  STACK_PUSH(result != NULL, state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsParentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialParent;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialParent, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialParent->isParent(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsDescendantIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialDescendant;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialDescendant, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialDescendant->isDescendant(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsPrecedingSiblingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialPrecedingSibling;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialPrecedingSibling, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialPrecedingSibling->isPrecedingSibling(lItem)
      ), state);

  STACK_END (state);
}

/*******************************************************************************
********************************************************************************/
bool
IsPrecedingIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialPreceding;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialPreceding, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialPreceding->isPreceding(lItem)
      ), state);

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
IsAncestorIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lPotentialAncestor;
  store::Item_t lItem;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(lPotentialAncestor, theChildren[0].getp(), planState);
  consumeNext(lItem, theChildren[1].getp(), planState);

  STACK_PUSH(
      GENV_ITEMFACTORY->createBoolean(result,
        lPotentialAncestor->isAncestor(lItem)
      ), state);

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
