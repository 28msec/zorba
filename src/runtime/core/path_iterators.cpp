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
#include "util/logging/logger.hh"
#include "util/logging/loggerconfig.hh"
#include "util/logging/loggermanager.hh"
#include "runtime/core/path_iterators.h"
#include "system/zorba.h"
#include "store/api/item.h"
#include "runtime/visitors/planitervisitor.h"
#include "errors/error_factory.h"

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
Item_t KindTestIterator::nextImpl(PlanState& planState)
{
  Item_t contextNode;

  bool skip = false;

  do
  {
    contextNode = consumeNext(theChild, planState);
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
      if (theQName != NULL && !theQName->equals(contextNode->getNodeName().get_ptr()))
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

      if (theQName != NULL && !theQName->equals(contextNode->getNodeName().get_ptr()))
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
Item_t NameTestIterator::nextImpl(PlanState& planState)
{
  Item_t contextNode;

  while (true)
  {
    contextNode = consumeNext(theChild, planState);
    if (contextNode == NULL)
      return NULL;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(contextNode->getNodeName().get_ptr()))
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
template <class AxisIter>
void AxisIterator<AxisIter>::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<AxisIter>::releaseResourcesImpl(planState);

  AxisState* state;
  GET_STATE(AxisState, state, planState);
  state->theContextNode = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t SelfAxisIterator::nextImpl(PlanState& planState)
{
  SelfAxisState* state;
  GET_STATE(SelfAxisState, state, planState);

  do
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
         ZorbaError::XPTY0020,
         &loc, false, "The context item of an axis step is not a node");
    }
  }
  while (theNodeKind != StoreConsts::anyNode &&
         state->theContextNode->getNodeKind() != theNodeKind);

  return state->theContextNode;
}

void SelfAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<SelfAxisIterator>::releaseResourcesImpl(planState);
}                                   

/*******************************************************************************

********************************************************************************/
Item_t AttributeAxisIterator::nextImpl(PlanState& planState)
{
  Item_t attr;

  AttributeAxisState* state;
  DEFAULT_STACK_INIT(AttributeAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode);

    state->theAttributes = state->theContextNode->getAttributes();

    attr = state->theAttributes->next();

    while (attr != NULL)
    {
      STACK_PUSH(attr, state);
      attr = state->theAttributes->next();
    }
  }

  STACK_END();
}


void AttributeAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<AttributeAxisIterator>::resetImpl(planState);

  AttributeAxisState* state;
  GET_STATE(AttributeAxisState, state, planState);
  if (state->theAttributes != NULL)
    state->theAttributes->reset();
}


void AttributeAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<AttributeAxisIterator>::releaseResourcesImpl(planState);

  AttributeAxisState* state;
  GET_STATE(AttributeAxisState, state, planState); 
  state->theAttributes = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t ParentAxisIterator::nextImpl(PlanState& planState)
{
  Item_t parent;

  ParentAxisState* state;
  DEFAULT_STACK_INIT(ParentAxisState, state, planState); 

  while (true)
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0020,
                        &loc, false,
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


void ParentAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<ParentAxisIterator>::releaseResourcesImpl(planState);
}
   

/*******************************************************************************

********************************************************************************/
Item_t AncestorAxisIterator::nextImpl(PlanState& planState)
{
  AncestorAxisState* state;
  DEFAULT_STACK_INIT(AncestorAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
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


void AncestorAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<AncestorAxisIterator>::releaseResourcesImpl(planState);

  AncestorAxisState* state;
  GET_STATE(AncestorAxisState, state, planState); 
  state->theCurrentAnc = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorSelfAxisIterator::nextImpl(PlanState& planState)
{
  AncestorSelfAxisState* state;
  DEFAULT_STACK_INIT(AncestorSelfAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
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


void AncestorSelfAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<AncestorSelfAxisIterator>::releaseResourcesImpl(planState);

  AncestorSelfAxisState* state;
  GET_STATE(AncestorSelfAxisState, state, planState); 
  state->theCurrentAnc = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t RSiblingAxisIterator::nextImpl(PlanState& planState)
{
  Item_t parent;
  Item_t sibling;

  RSiblingAxisState* state;
  DEFAULT_STACK_INIT(RSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();

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


void RSiblingAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<RSiblingAxisIterator>::resetImpl(planState);

  RSiblingAxisState* state;
  GET_STATE(RSiblingAxisState, state, planState);
  if (state->theChildren != NULL)
    state->theChildren->reset(); 
}


void RSiblingAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<RSiblingAxisIterator>::releaseResourcesImpl(planState);

  RSiblingAxisState* state;
  GET_STATE(RSiblingAxisState, state, planState); 
  state->theChildren = NULL; 
}


/*******************************************************************************

********************************************************************************/
Item_t LSiblingAxisIterator::nextImpl(PlanState& planState)
{
  Item_t parent;
  Item_t sibling;

  LSiblingAxisState* state;
  DEFAULT_STACK_INIT(LSiblingAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();

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


void LSiblingAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<LSiblingAxisIterator>::resetImpl(planState);

  LSiblingAxisState* state;
  GET_STATE(LSiblingAxisState, state, planState); 
  if (state->theChildren != NULL)
    state->theChildren->reset();
}


void LSiblingAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<LSiblingAxisIterator>::releaseResourcesImpl(planState);

  LSiblingAxisState* state;
  GET_STATE(LSiblingAxisState, state, planState); 
  state->theChildren = NULL; 
}


/*******************************************************************************

********************************************************************************/
Item_t ChildAxisIterator::nextImpl(PlanState& planState)
{
  Item_t child;

  ChildAxisState* state;
  DEFAULT_STACK_INIT(ChildAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != StoreConsts::documentNode);

    state->theChildren = state->theContextNode->getChildren();
    assert (state->theChildren != NULL);

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


void ChildAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<ChildAxisIterator>::resetImpl(planState);

  ChildAxisState* state;
  GET_STATE(ChildAxisState, state, planState);
  if (state->theChildren != NULL)
    state->theChildren->reset();
}


void ChildAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<ChildAxisIterator>::releaseResourcesImpl(planState);

  ChildAxisState* state;
  GET_STATE(ChildAxisState, state, planState); 
  state->theChildren = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantAxisIterator::nextImpl(PlanState& planState)
{
  Item_t desc;
  Iterator_t children;

  DescendantAxisState* state;
  DEFAULT_STACK_INIT(DescendantAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != StoreConsts::elementNode &&
           state->theContextNode->getNodeKind() != StoreConsts::documentNode);

    //MYTRACE("iter = " << this << " ctxNode = [" << &*state->theContextNode
    //        << " " << state->theContextNode->getNodeName()->show() << "]");

    children = state->theContextNode->getChildren();

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


void DescendantAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<DescendantAxisIterator>::resetImpl(planState);

  DescendantAxisState* state;
  GET_STATE(DescendantAxisState, state, planState); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<DescendantAxisIterator>::releaseResourcesImpl(planState);

  DescendantAxisState* state;
  GET_STATE(DescendantAxisState, state, planState); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantAxisIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  AxisIterator<DescendantAxisIterator>::setOffset(planState, offset);

  DescendantAxisState* state = new (planState.block + stateOffset) DescendantAxisState;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantSelfAxisIterator::nextImpl(PlanState& planState)
{
  Item_t desc;

  DescendantSelfAxisState* state;
  DEFAULT_STACK_INIT(DescendantSelfAxisState, state, planState);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, planState);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
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
        state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                  (desc, desc->getChildren()));
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


void DescendantSelfAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<DescendantSelfAxisIterator>::resetImpl(planState);

  DescendantSelfAxisState* state;
  GET_STATE(DescendantSelfAxisState, state, planState); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantSelfAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<DescendantSelfAxisIterator>::releaseResourcesImpl(planState);

  DescendantSelfAxisState* state;
  GET_STATE(DescendantSelfAxisState, state, planState);

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantSelfAxisIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  AxisIterator<DescendantSelfAxisIterator>::setOffset(planState, offset);

  DescendantSelfAxisState* state = new (planState.block + stateOffset) DescendantSelfAxisState;
}


/*******************************************************************************

********************************************************************************/
Item_t PrecedingAxisIterator::nextImpl(PlanState& planState)
{
  Item_t ancestor;
  Item_t desc;
  Iterator_t children;

  PrecedingAxisState* state;
  DEFAULT_STACK_INIT(PrecedingAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
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

      state->theCurrentPath.push(std::pair<Item_t, Iterator_t>(ancestor, children));
    
      desc = children->next();

      while (desc != state->theAncestorPath.top())
      {
        if (desc->getNodeKind() == StoreConsts::elementNode)
        {
          state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                    (desc, desc->getChildren()));
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


void PrecedingAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<PrecedingAxisIterator>::resetImpl(planState);

  PrecedingAxisState* state;
  GET_STATE(PrecedingAxisState, state, planState); 

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();
}


void PrecedingAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<PrecedingAxisIterator>::releaseResourcesImpl(planState);

  PrecedingAxisState* state;
  GET_STATE(PrecedingAxisState, state, planState); 

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();
}


void PrecedingAxisIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  AxisIterator<PrecedingAxisIterator>::setOffset(planState, offset);

  PrecedingAxisState* state = new (planState.block + stateOffset) PrecedingAxisState;
}


/*******************************************************************************

********************************************************************************/
Item_t FollowingAxisIterator::nextImpl(PlanState& planState)
{
  Item_t ancestor;
  Item_t following;
  Iterator_t children;

  FollowingAxisState* state;
  DEFAULT_STACK_INIT(FollowingAxisState, state, planState);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, planState);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_ALERT(
           ZorbaError::XPTY0020,
           &loc, false, "The context item of an axis step is not a node");
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
          state->theCurrentPath.push(std::pair<Item_t, Iterator_t>
                                    (following, following->getChildren()));
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


void FollowingAxisIterator::resetImpl(PlanState& planState)
{
  AxisIterator<FollowingAxisIterator>::resetImpl(planState);

  FollowingAxisState* state;
  GET_STATE(FollowingAxisState, state, planState);

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();

  state->theContextNode = NULL;
}


void FollowingAxisIterator::releaseResourcesImpl(PlanState& planState)
{
  AxisIterator<FollowingAxisIterator>::releaseResourcesImpl(planState);

  FollowingAxisState* state;
  GET_STATE(FollowingAxisState, state, planState);

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();

  state->theContextNode = NULL;
}


void FollowingAxisIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  AxisIterator<FollowingAxisIterator>::setOffset(planState, offset);

  FollowingAxisState* state = new (planState.block + stateOffset) FollowingAxisState;
}

};
