/**
 *
 * @copyright
 * ========================================================================
 *  Copyright 2007 FLWOR Foundation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  
 *    http://www.apache.org/licenses/LICENSE-2.0
 *  
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 * ========================================================================
 *
 * @author Markos Zaharioudakis
 * @file runtime/path_iterators.h
 *
 */

#include "util/Assert.h"
#include "runtime/core/path_iterators.h"
#include "system/zorba.h"
#include "store/api/item.h"
#include "runtime/visitors/planitervisitor.h"
#include "errors/error_factory.h"
#include "zorba/runtime/iterator.h"

#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}



namespace xqp
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
Item_t KindTestIterator::nextImpl(PlanState& planState) const
{
  Item_t contextNode;

  bool skip = false;

  do
  {
    contextNode = consumeNext(theChild.getp(), planState);
    if (contextNode == NULL)
      return NULL;

    if (!contextNode->isNode())
    {
      skip = true;
      continue;
    }

    switch (theTestKind)
    {
    case match_doc_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::documentNode)
      {
        skip = true;
        break;
      }

      Iterator_t children = contextNode->getChildren();
      children->open();
      Item_t child = children->next();
      match_test_t elemTest = match_no_test;

      while (child != NULL)
      {
        if (child->getNodeKind() == StoreConsts::elementNode)
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
        child = children->next();
      }

      if (elemTest == match_elem_test)
        goto doctest1;
      else if (elemTest == match_xs_elem_test)
        goto doctest2;

      break;
    }
    case match_elem_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::elementNode)
      {
        skip = true;
        break;
      }

doctest1:
      if (theQName != NULL && !theQName->equals(contextNode->getNodeName().getp()))
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
      if (contextNode->getNodeKind() != StoreConsts::attributeNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL && !theQName->equals(contextNode->getNodeName().getp()))
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
      if (contextNode->getNodeKind() != StoreConsts::elementNode)
      {
        skip = true;
        break;
      }

doctest2:
      break;
    }
    case match_xs_attr_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::attributeNode)
      {
        skip = true;
        break;
      }

      break;
    }
    case match_pi_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::piNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL  && theQName->getLocalName() != contextNode->getTarget())
        skip = true;

      break;
    }
    case match_comment_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::commentNode)
        skip = true;

      break;
    }
    case match_text_test:
    {
      if (contextNode->getNodeKind() != StoreConsts::textNode)
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

  return contextNode;
}


/*******************************************************************************

********************************************************************************/
Item_t NameTestIterator::nextImpl(PlanState& planState) const
{
  Item_t contextNode;

  while (true)
  {
    contextNode = consumeNext(theChild.getp(), planState);
    if (contextNode == NULL)
      return NULL;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(contextNode->getNodeName().getp()))
        return contextNode;

      break;
    }
    case match_all_wild:
    {
      return contextNode;
    }
    case match_prefix_wild:
    {
      if (theQName->getLocalName() == contextNode->getNodeName()->getLocalName())
        return contextNode;

      break;
    }
    case match_name_wild:
    {
      if (theQName->getNamespace() == contextNode->getNodeName()->getPrefix())
        return contextNode;

      break;
    }
    default:
      ZORBA_ASSERT (false && "Unknown name test kind");
    }
  }

  return NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t SelfAxisIterator::nextImpl(PlanState& planState) const
{
  SelfAxisState* state;
  state = StateTraitsImpl<SelfAxisState>::getState(planState, this->stateOffset);

  do
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0020,
         &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
    }
  }
  while (theNodeKind != StoreConsts::anyNode &&
         state->theContextNode->getNodeKind() != theNodeKind);

  return state->theContextNode;
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

Item_t AttributeAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t attr;

  AttributeAxisState* state;
  DEFAULT_STACK_INIT(AttributeAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode);

    state->theAttributes = state->theContextNode->getAttributes();
    state->theAttributes->open();

    attr = state->theAttributes->next();

    while (attr != NULL)
    {
      STACK_PUSH(attr, state);
      attr = state->theAttributes->next();
    }
  }

  STACK_END();
}


/*******************************************************************************

********************************************************************************/
Item_t ParentAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t parent;

  ParentAxisState* state;
  DEFAULT_STACK_INIT(ParentAxisState, state, planState); 

  while (true)
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0020,
                        &loc, DONT_CONTINUE_EXECUTION,
                        "The context item of an axis step is not a node");
    }

    parent = state->theContextNode->getParent();


    if (parent != NULL &&
        (theNodeKind == StoreConsts::anyNode ||
         parent->getNodeKind() == theNodeKind))
    {
      STACK_PUSH(parent, state);
    }
  }

  STACK_END();
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorAxisIterator::nextImpl(PlanState& planState) const
{
  AncestorAxisState* state;
  DEFAULT_STACK_INIT(AncestorAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode->getParent();

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == StoreConsts::anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(state->theCurrentAnc, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END();
}

/*******************************************************************************

********************************************************************************/
Item_t AncestorSelfAxisIterator::nextImpl(PlanState& planState) const
{
  AncestorSelfAxisState* state;
  DEFAULT_STACK_INIT(AncestorSelfAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode;

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == StoreConsts::anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(state->theCurrentAnc, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END();
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

Item_t RSiblingAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t parent;
  Item_t sibling;

  RSiblingAxisState* state;
  DEFAULT_STACK_INIT(RSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    while (state->theChildren->next() != state->theContextNode) ;

    sibling = state->theChildren->next();

    while (sibling != NULL)
    {
      if (theNodeKind == StoreConsts::anyNode ||
          sibling->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(sibling, state);
      }

      sibling = state->theChildren->next();
    }
  }

  STACK_END();
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

Item_t LSiblingAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t parent;
  Item_t sibling;

  LSiblingAxisState* state;
  DEFAULT_STACK_INIT(LSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    sibling = state->theChildren->next();

    while (sibling != state->theContextNode)
    {
      if (theNodeKind == StoreConsts::anyNode ||
          sibling->getNodeKind() == theNodeKind)
      {
#ifdef DEBUG
        theLSibling = sibling;
#endif
        STACK_PUSH(sibling, state);
      }

      sibling = state->theChildren->next();
    }
  }

  STACK_END();
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

void
ChildAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theChildren != NULL)
    theChildren->reset(); 
}

Item_t ChildAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t child;

  ChildAxisState* state;
  DEFAULT_STACK_INIT(ChildAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != StoreConsts::documentNode);

    state->theChildren = state->theContextNode->getChildren();
    assert (state->theChildren != NULL);
    state->theChildren->open();

    child = state->theChildren->next();

    while (child != NULL)
    {
      if (theNodeKind == StoreConsts::anyNode ||
          child->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(child, state);
      }

      child = state->theChildren->next();
    }
  }

  STACK_END();
}


/*******************************************************************************

********************************************************************************/
DescendantAxisState::DescendantAxisState(){}
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

Item_t DescendantAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t desc;
  Iterator_t children;

  DescendantAxisState* state;
  DEFAULT_STACK_INIT(DescendantAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != StoreConsts::documentNode);

    //MYTRACE("iter = " << this << " ctxNode = [" << &*state->theContextNode
    //        << " " << state->theContextNode->getNodeName()->show() << "]");

    children = state->theContextNode->getChildren();
    children->open();

    state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                              (state->theContextNode, children));
    
    desc = children->next();

    while (desc != NULL)
    {
      if (desc->getNodeKind() == StoreConsts::elementNode)
      {
        state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                  (desc, desc->getChildren()));
      }

      if (theNodeKind == StoreConsts::anyNode ||
          desc->getNodeKind() == theNodeKind)
      {
        //MYTRACE("iter = " << this << " desc = [" << &*desc << " "
        //        << desc->getNodeName()->show() << "]");

        STACK_PUSH(desc, state);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = checked_top (state->theCurrentPath).second->next();

      while (desc == NULL)
      {
        checked_pop (state->theCurrentPath);
        if (!state->theCurrentPath.empty())
          desc = state->theCurrentPath.top().second->next();
        else
          break;
      }
    }
  }

  STACK_END();
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
Item_t DescendantSelfAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t desc;

  DescendantSelfAxisState* state;
  DEFAULT_STACK_INIT(DescendantSelfAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild.getp(), planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != StoreConsts::documentNode);

    desc = state->theContextNode;

    while (desc != NULL)
    {
      if (desc->getNodeKind() == StoreConsts::elementNode ||
          desc->getNodeKind() == StoreConsts::documentNode)
      {
        Iterator_t children = desc->getChildren();
        children->open();
        state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                  (desc, children));
      }

      if (theNodeKind == StoreConsts::anyNode ||
          desc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH(desc, state);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = checked_top (state->theCurrentPath).second->next();

      while (desc == NULL)
      {
        checked_pop (state->theCurrentPath);
        if (!state->theCurrentPath.empty())
          desc = state->theCurrentPath.top().second->next();
        else
          break;
      }
    }
  }

  STACK_END();
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
Item_t PrecedingAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t ancestor;
  Item_t desc;
  Iterator_t children;

  PrecedingAxisState* state;
  DEFAULT_STACK_INIT(PrecedingAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
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

      state->theCurrentPath.push(std::pair<Item_t, Iterator_t>(ancestor, children));
    
      desc = children->next();

      while (desc != state->theAncestorPath.top())
      {
        if (desc->getNodeKind() == StoreConsts::elementNode)
        {
          Iterator_t children = desc->getChildren();
          children->open();
          state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                    (desc, children));
        }

        if (theNodeKind == StoreConsts::anyNode ||
            desc->getNodeKind() == theNodeKind)
        {
          STACK_PUSH(desc, state);
        }

        desc = checked_top (state->theCurrentPath).second->next();

        while (desc == NULL)
        {
          checked_pop(state->theCurrentPath);
          if (!state->theCurrentPath.empty())
            desc = state->theCurrentPath.top().second->next();
          else
            break;
        }
      }
    }
  }

  STACK_END();
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

Item_t FollowingAxisIterator::nextImpl(PlanState& planState) const
{
  Item_t ancestor;
  Item_t following;
  Iterator_t children;

  FollowingAxisState* state;
  DEFAULT_STACK_INIT(FollowingAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild.getp(), planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, DONT_CONTINUE_EXECUTION, "The context item of an axis step is not a node");
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

      state->theCurrentPath.push(std::pair<Item_t, Iterator_t>(ancestor, children));

      do
      {
        following = children->next();
      }
      while (following != state->theAncestorPath.top());

      following = children->next();

      while (following != NULL)
      {
        if (following->getNodeKind() == StoreConsts::elementNode)
        {
          Iterator_t children = following->getChildren();
          children->open();
          state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                    (following, children));
        }

        if (theNodeKind == StoreConsts::anyNode ||
            following->getNodeKind() == theNodeKind)
        {
          STACK_PUSH(following, state);
        }

        following = checked_top (state->theCurrentPath).second->next();

        while (following == NULL)
        {
          checked_pop (state->theCurrentPath);
          if (!state->theCurrentPath.empty())
            following = state->theCurrentPath.top().second->next();
          else
            break;
        }
      }
    }
  }

  STACK_END();
}


};
