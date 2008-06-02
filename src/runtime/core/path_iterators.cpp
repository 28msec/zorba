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
#include "store/api/item.h"

#include "store/api/iterator.h"
#include "zorbaerrors/Assert.h"
#include "runtime/core/path_iterators.h"
#include "runtime/visitors/planitervisitor.h"
#include "zorbaerrors/error_manager.h"

#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}



namespace zorba
{

  template <typename T> void checked_pop (std::stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    stk.pop ();
  }

  template <typename T> const T& checked_top (std::stack<T> &stk) {
    ZORBA_ASSERT (! stk.empty ());
    return stk.top ();
  }

/*******************************************************************************

********************************************************************************/
bool KindTestIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool skip = false;

  do
  {
    if (!consumeNext(result, theChild.getp(), planState))
      return false;

    if (!result->isNode())
    {
      skip = true;
      continue;
    }

    switch (theTestKind)
    {
    case match_doc_test:
    {
      if (result->getNodeKind() != store::StoreConsts::documentNode)
      {
        skip = true;
        break;
      }

      store::Iterator_t children = result->getChildren();
      children->open();
      store::Item_t child;
      match_test_t elemTest = match_no_test;
      while(children->next(child))
      {
        if (child->getNodeKind() == store::StoreConsts::elementNode)
        {
          if (elemTest != match_no_test)
          {
            skip = true;
            break;
          }
          else
          {
            elemTest = theDocTestKind;
          }
        }
      }

      if (elemTest == match_elem_test)
        goto doctest1;
      else if (elemTest == match_xs_elem_test)
        goto doctest2;

      break;
    }
    case match_elem_test:
    {
      if (result->getNodeKind() != store::StoreConsts::elementNode)
      {
        skip = true;
        break;
      }

doctest1:
      if (theQName != NULL &&
          !theQName->equals(result->getNodeName(), planState.theRuntimeCB))
      {
        skip = true;
        break;
      }
      /*
      if (theTypeName != NULL)
      {
        TypeCode etype = Zorba::getSequenceTypeManager()->
                         getTypecode(reinterpret_cast<QNameItem*>(&*theTypeName));
        TypeCode atype = contextNode->getType();

        if ((atype != etype && !sequence_type::derives_from(atype, etype)) ||
            (theNilledAllowed == false && contextNode->getNilled() == true))
          skip = true;
      }
      */
      break;
    }
    case match_attr_test:
    {
      if (result->getNodeKind() != store::StoreConsts::attributeNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL &&
          !theQName->equals(result->getNodeName(), planState.theRuntimeCB))
      {
        skip = true;
        break;
      }
      /*
      if (theTypeName != NULL)
      {
        TypeCode etype = Zorba::getSequenceTypeManager()->
                         getTypecode(reinterpret_cast<QNameItem*>(&*theTypeName));
        TypeCode atype = contextNode->getType();

        if (atype != etype && !sequence_type::derives_from(atype, etype))
          skip = true;
      }
      */
      break;
    }
    case match_xs_elem_test:
    {
      if (result->getNodeKind() != store::StoreConsts::elementNode)
      {
        skip = true;
        break;
      }

doctest2:
      break;
    }
    case match_xs_attr_test:
    {
      if (result->getNodeKind() != store::StoreConsts::attributeNode)
      {
        skip = true;
        break;
      }

      break;
    }
    case match_pi_test:
    {
      if (result->getNodeKind() != store::StoreConsts::piNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL &&
          !theQName->getLocalName()->equals(result->getTarget()))
        skip = true;

      break;
    }
    case match_comment_test:
    {
      if (result->getNodeKind() != store::StoreConsts::commentNode)
        skip = true;

      break;
    }
    case match_text_test:
    {
      if (result->getNodeKind() != store::StoreConsts::textNode)
        skip = true;

      break;
    }
    case match_anykind_test:
    {
      break;
    }
    default:
      ZORBA_ASSERT (false && "Unknown kind test kind");
    }
  }
  while (skip);

  return true;
}


/*******************************************************************************

********************************************************************************/
bool NameTestIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  while (true)
  {
    if (!consumeNext(result, theChild.getp(), planState))
      return false;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(result->getNodeName(), planState.theRuntimeCB))
        return true;

      break;
    }
    case match_all_wild:
    {
      return true;
    }
    case match_prefix_wild:
    {
      if (theQName->getLocalName()->equals(result->getNodeName()->getLocalName()))
        return true;

      break;
    }
    case match_name_wild:
    {
      if (theQName->getNamespace()->equals(result->getNodeName()->getNamespace()))
        return true;

      break;
    }
    default:
      ZORBA_ASSERT (false && "Unknown name test kind");
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool SelfAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  SelfAxisState* state;
  state = StateTraitsImpl<SelfAxisState>::getState(planState, this->stateOffset);

  do
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(  XPTY0020, loc,  "The context item of an axis step is not a node");
    }
  }
  while (theNodeKind != store::StoreConsts::anyNode &&
         state->theContextNode->getNodeKind() != theNodeKind);
  result = state->theContextNode;

  return true;
}


/*******************************************************************************

********************************************************************************/
AttributeAxisState::AttributeAxisState(){}
AttributeAxisState::~AttributeAxisState(){}

void
AttributeAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
AttributeAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theAttributes != NULL)
    theAttributes->reset();
}

bool AttributeAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  AttributeAxisState* state;
  DEFAULT_STACK_INIT(AttributeAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
        return false;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != store::StoreConsts::elementNode);

    state->theAttributes = state->theContextNode->getAttributes();
    state->theAttributes->open();

    while (state->theAttributes->next(result))
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool ParentAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ParentAxisState* state;
  DEFAULT_STACK_INIT(ParentAxisState, state, planState); 

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC( XPTY0020, loc, "The context item of an axis step is not a node");
    }

    result = state->theContextNode->getParent();


    if (result != NULL &&
        (theNodeKind == store::StoreConsts::anyNode ||
         result->getNodeKind() == theNodeKind))
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool AncestorAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  AncestorAxisState* state;
  DEFAULT_STACK_INIT(AncestorAxisState, state, planState);

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode->getParent();

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == store::StoreConsts::anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        result = state->theCurrentAnc;
        STACK_PUSH(true, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
bool AncestorSelfAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  AncestorSelfAxisState* state;
  DEFAULT_STACK_INIT(AncestorSelfAxisState, state, planState);

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC( XPTY0020, loc, "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode;

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == store::StoreConsts::anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        result = state->theCurrentAnc;
        STACK_PUSH(true, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
RSiblingAxisState::RSiblingAxisState(){}
RSiblingAxisState::~RSiblingAxisState(){}

void
RSiblingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
RSiblingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theChildren != NULL)
    theChildren->reset(); 
}

bool RSiblingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t parent;
  store::Item_t child;

  RSiblingAxisState* state;
  DEFAULT_STACK_INIT(RSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
        return false;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return false;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    while (state->theChildren->next(child) && child != state->theContextNode) ;

    while (state->theChildren->next(result))
    {
      if (theNodeKind == store::StoreConsts::anyNode ||
          result->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
LSiblingAxisState::LSiblingAxisState(){}
LSiblingAxisState::~LSiblingAxisState(){}

void
LSiblingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
LSiblingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theChildren != NULL)
    theChildren->reset(); 
}

bool LSiblingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t parent;

  LSiblingAxisState* state;
  DEFAULT_STACK_INIT(LSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
        return false;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return false;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    while (state->theChildren->next(result) && result != state->theContextNode)
    {
      if (theNodeKind == store::StoreConsts::anyNode ||
          result->getNodeKind() == theNodeKind)
      {
#ifndef WIN32
#ifdef DEBUG
        theLSibling = result;
#endif
#endif
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/

ChildAxisState::ChildAxisState() {}

ChildAxisState::~ChildAxisState() {}

void
ChildAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}


void ChildAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theChildren != NULL)
    theChildren->reset(); 
}

static bool isElementOrDocumentNode(store::Item *node)
{
  assert(node->isNode());
  store::StoreConsts::NodeKind kind = node->getNodeKind();
  return kind == store::StoreConsts::elementNode
    || kind == store::StoreConsts::documentNode;
}

bool ChildAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t child;

  ChildAxisState* state;
  DEFAULT_STACK_INIT(ChildAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
        return false;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    state->theChildren = state->theContextNode->getChildren();
    assert (state->theChildren != NULL);
    state->theChildren->open();

    while (state->theChildren->next(result))
    {
      if (theNodeKind == store::StoreConsts::anyNode ||
          result->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DescendantAxisState::DescendantAxisState()
{
}


DescendantAxisState::~DescendantAxisState()
{
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
}


void
DescendantAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}


void
DescendantAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
}


bool DescendantAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Iterator_t children;

  DescendantAxisState* state;
  DEFAULT_STACK_INIT(DescendantAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      {
        state->reset(planState);
        return false;
      }

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != store::StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != store::StoreConsts::documentNode);

    //MYTRACE("iter = " << this << " ctxNode = [" << &*state->theContextNode
    //        << " " << state->theContextNode->getNodeName()->show() << "]");

    children = state->theContextNode->getChildren();
    children->open();

    state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                              (state->theContextNode, children));
    
    if (state->theCurrentPath.top().second->next(result))
    {
      while(true) {
        if (result->getNodeKind() == store::StoreConsts::elementNode)
        {
          state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                  (result, result->getChildren()));
        }

        if (theNodeKind == store::StoreConsts::anyNode ||
            result->getNodeKind() == theNodeKind)
        {
          //MYTRACE("iter = " << this << " desc = [" << &*desc << " "
          //        << desc->getNodeName()->show() << "]");

          STACK_PUSH(true, state);
        }

        // The next descendant is the next child of the node N that is currently
        // at the top of the path stack. If N has no children or all of its
        // children have been processed already, N is removed from the stack
        // and the process is repeated.
        ;

        while (!checked_top (state->theCurrentPath).second->next(result))
        {
          checked_pop (state->theCurrentPath);
          if (state->theCurrentPath.empty())
            break;
        }
        if (state->theCurrentPath.empty()) {
            break;
        }
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DescendantSelfAxisState::DescendantSelfAxisState(){}
DescendantSelfAxisState::~DescendantSelfAxisState()
{
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
}


void
DescendantSelfAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
DescendantSelfAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
}


/*******************************************************************************

********************************************************************************/
bool DescendantSelfAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  DescendantSelfAxisState* state;
  bool first = false;
  DEFAULT_STACK_INIT(DescendantSelfAxisState, state, planState);

  while (true)
  {
    do
    {
      if (!consumeNext(state->theContextNode, theChild.getp(), planState))
        return false;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0020, loc, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != store::StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != store::StoreConsts::documentNode);

    result = state->theContextNode;
    first = true;

    while(first || !state->theCurrentPath.empty()) {
      first = false;
      if (result->getNodeKind() == store::StoreConsts::elementNode ||
          result->getNodeKind() == store::StoreConsts::documentNode)
      {
        store::Iterator_t children = result->getChildren();
        children->open();
        state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                  (result, children));
      }

      if (theNodeKind == store::StoreConsts::anyNode ||
          result->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(true, state);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      while (!checked_top (state->theCurrentPath).second->next(result))
      {
        checked_pop (state->theCurrentPath);
        if (state->theCurrentPath.empty())
          break;
      }
    }
  }

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/
PrecedingAxisState::PrecedingAxisState(){}
PrecedingAxisState::~PrecedingAxisState()
{
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
  while (!theAncestorPath.empty())
  {
    theAncestorPath.pop();
  }
}


void
PrecedingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
PrecedingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
  while (!theAncestorPath.empty())
  {
    theAncestorPath.pop();
  }
}


/*******************************************************************************

********************************************************************************/
bool PrecedingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t ancestor;
  store::Iterator_t children;

  PrecedingAxisState* state;
  DEFAULT_STACK_INIT(PrecedingAxisState, state, planState);

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC( XPTY0020, loc, "The context item of an axis step is not a node");
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode;

    while (ancestor != NULL)
    {
      state->theAncestorPath.push(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor N (starting from the top) return its descendants,
    // up to the point where the next ancestor M is reached (M is a child
    // of N). Then repeat the process with the subtree rooted at M. 
    while (state->theAncestorPath.size() > 1)
    {
      ancestor = state->theAncestorPath.top();

      state->theAncestorPath.pop();

      children = ancestor->getChildren();
      children->open();

      state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>(ancestor, children));
    
      if (!children->next(result)) {
        result = NULL;
      }

      while (result != state->theAncestorPath.top())
      {
        if (result->getNodeKind() == store::StoreConsts::elementNode)
        {
          store::Iterator_t children = result->getChildren();
          children->open();
          state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                    (result, children));
        }

        if (theNodeKind == store::StoreConsts::anyNode ||
            result->getNodeKind() == theNodeKind)
        {
          STACK_PUSH(true, state);
          result = NULL;
        }

        while (!checked_top (state->theCurrentPath).second->next(result))
        {
          result = NULL;
          checked_pop(state->theCurrentPath);
          if (state->theCurrentPath.empty())
            break;
        }
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
FollowingAxisState::FollowingAxisState(){}
FollowingAxisState::~FollowingAxisState()
{
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
  while (!theAncestorPath.empty())
  {
    theAncestorPath.pop();
  }
}


void
FollowingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}

void
FollowingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  while (!theCurrentPath.empty())
  {
    theCurrentPath.pop();
  }
  while (!theAncestorPath.empty())
  {
    theAncestorPath.pop();
  }
  theContextNode = NULL;
}

bool FollowingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t ancestor;
  store::Iterator_t children;

  FollowingAxisState* state;
  DEFAULT_STACK_INIT(FollowingAxisState, state, planState);

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(  XPTY0020, loc,  "The context item of an axis step is not a node"); 
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode;

    while (ancestor != NULL)
    {
      state->theAncestorPath.push(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor N (starting from the top) return its descendants,
    // starting from the rsibling of next ancestor M (M is a child of N).
    // Then repeat the process with the subtree rooted at M. 
    while (state->theAncestorPath.size() > 1)
    {
      ancestor = state->theAncestorPath.top();

      state->theAncestorPath.pop();

      children = ancestor->getChildren();
      children->open();

      state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>(ancestor, children));

      do
      {
        children->next(result);
      }
      while (result != state->theAncestorPath.top());

      if (!children->next(result)) {
        result = NULL;
      }

      while (result != NULL)
      {
        if (result->getNodeKind() == store::StoreConsts::elementNode)
        {
          store::Iterator_t children = result->getChildren();
          children->open();
          state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                    (result, children));
        }

        if (theNodeKind == store::StoreConsts::anyNode ||
            result->getNodeKind() == theNodeKind)
        {
          STACK_PUSH(true, state);
        }

        if (!checked_top (state->theCurrentPath).second->next(result)) {
          result = NULL;
        }

        while (result == NULL)
        {
          checked_pop (state->theCurrentPath);
          if (state->theCurrentPath.empty())
            break;
          if (!state->theCurrentPath.top().second->next(result)) {
            result = NULL;
          }
        }
      }
    }
  }

  STACK_END (state);
}


};
