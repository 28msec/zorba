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

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "store/api/item.h"
#include "store/api/iterator.h"

#include "runtime/core/path_iterators.h"
//#include "runtime/visitors/planitervisitor.h"


#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}



namespace zorba
{

template <typename T> void checked_pop(std::stack<T> &stk) 
{
  ZORBA_ASSERT (! stk.empty ());
  stk.pop ();
}


template <typename T> const T& checked_top(std::stack<T> &stk) 
{
  ZORBA_ASSERT (! stk.empty ());
  return stk.top ();
}


static inline bool isElementOrDocumentNode(const store::Item* node)
{
  assert(node->isNode());
  store::StoreConsts::NodeKind kind = node->getNodeKind();
  return (kind == store::StoreConsts::elementNode ||
          kind == store::StoreConsts::documentNode);
}


/*******************************************************************************

********************************************************************************/
bool SelfAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  SelfAxisState* state;
  state = StateTraitsImpl<SelfAxisState>::getState(planState, this->stateOffset);

  do
  {
    if (!consumeNext(result, theChild.getp(), planState))
      return false;

    if (!result->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }
  }
  while (!nameOrKindTest(result));

  return true;
}


/*******************************************************************************

********************************************************************************/
AttributeAxisState::AttributeAxisState()
{
}


AttributeAxisState::~AttributeAxisState()
{
}


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
        ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                             "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != store::StoreConsts::elementNode);

    state->theAttributes = state->theContextNode->getAttributes();
    state->theAttributes->open();

    while (state->theAttributes->next(result))
    {
      if (nameOrKindTest(result))
        STACK_PUSH(true, state);
    }

    state->theAttributes->close();
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

    if (result != NULL && nameOrKindTest(result))
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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode->getParent();

    while (state->theCurrentAnc != NULL)
    {
      if (nameOrKindTest(state->theCurrentAnc))
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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode;

    while (state->theCurrentAnc != NULL)
    {
      if (nameOrKindTest(state->theCurrentAnc))
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
RSiblingAxisState::RSiblingAxisState()
{
}


RSiblingAxisState::~RSiblingAxisState()
{
}


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
        ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                             "The context item of an axis step is not a node");
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
      if (nameOrKindTest(result))
      {
        STACK_PUSH(true, state);
      }
    }

    state->theChildren->close();    
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
LSiblingAxisState::LSiblingAxisState()
{
}


LSiblingAxisState::~LSiblingAxisState()
{
}


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
      if (nameOrKindTest(result))
      {
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END (state);
}

/*******************************************************************************

********************************************************************************/

ChildAxisState::ChildAxisState() 
{
}


ChildAxisState::~ChildAxisState() 
{
}


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
      if (nameOrKindTest(result))
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
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    children = state->theContextNode->getChildren();
    children->open();

    state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                              (state->theContextNode, children));
    
    if (state->theCurrentPath.top().second->next(result))
    {
      while(true) 
      {
        if (result->getNodeKind() == store::StoreConsts::elementNode)
        {
          state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                  (result, result->getChildren()));
        }

        if (nameOrKindTest(result))
        {
          STACK_PUSH(true, state);
        }

        // The next descendant is the next child of the node N that is currently
        // at the top of the path stack. If N has no children or all of its
        // children have been processed already, N is removed from the stack
        // and the process is repeated.

        while (!checked_top(state->theCurrentPath).second->next(result))
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
DescendantSelfAxisState::DescendantSelfAxisState()
{
}


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
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    result = state->theContextNode;
    first = true;

    while(first || !state->theCurrentPath.empty()) 
    {
      first = false;
      if (isElementOrDocumentNode(result))
      {
        store::Iterator_t children = result->getChildren();
        children->open();
        state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                  (result, children));
      }

      if (nameOrKindTest(result))
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
PrecedingAxisState::PrecedingAxisState()
{
}


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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc, "The context item of an axis step is not a node");
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
    
      if (!children->next(result))
        result = NULL;

      while (result != state->theAncestorPath.top())
      {
        if (result->getNodeKind() == store::StoreConsts::elementNode)
        {
          store::Iterator_t children = result->getChildren();
          children->open();
          state->theCurrentPath.push(std::pair<store::Item_t, store::Iterator_t>
                                    (result, children));
        }

        if (nameOrKindTest(result))
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
FollowingAxisState::FollowingAxisState()
{
}


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

        if (nameOrKindTest(result))
        {
          STACK_PUSH(true, state);
        }

        if (!checked_top (state->theCurrentPath).second->next(result))
          result = NULL;

        while (result == NULL)
        {
          checked_pop (state->theCurrentPath);
          if (state->theCurrentPath.empty())
            break;

          if (!state->theCurrentPath.top().second->next(result))
            result = NULL;
        }
      }
    }
  }

  STACK_END (state);
}


};
