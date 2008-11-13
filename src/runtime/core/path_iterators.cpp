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

#include "system/globalenv.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"

#include "runtime/core/path_iterators.h"


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

bool AxisIteratorHelper::nameOrKindTest(
    const store::Item* node,
    PlanState& planState) const
{
  switch (theTestKind)
  {
  case match_name_test:
  {
    if (node->getNodeKind() != theNodeKind)
      return false;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(node->getNodeName()))
        return true;
      
      return false;
    }
    case match_all_wild:
    {
      return true;
    }
    case match_prefix_wild:
    {
      if (theQName->getLocalName()->equals(node->getNodeName()->getLocalName()))
        return true;
    
      return false;
    }
    case match_name_wild:
    {
      if (theQName->getNamespace()->equals(node->getNodeName()->getNamespace()))
        return true;

      return false;
    }
    default:
      ZORBA_ASSERT(false && "Unknown name test kind");
    }
  }
  case match_doc_test:
  {
    if (node->getNodeKind() != store::StoreConsts::documentNode)
      return false;

    if (theDocTestKind == match_no_test)
      return true;

    store::Iterator_t children = node->getChildren();
    children->open();
    store::Item_t child;
    match_test_t elemTest = match_no_test;
    while(children->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        // return false if doc node has more than 1 element child
        if (elemTest != match_no_test)
          return false;
        else
          elemTest = theDocTestKind;
      }
    }

    if (elemTest == match_elem_test)
      goto doctest1;
    else if (elemTest == match_xs_elem_test)
      goto doctest2;
    else
      ZORBA_FATAL(0, "");
  }
  case match_elem_test:
  {
    if (node->getNodeKind() != store::StoreConsts::elementNode)
      return false;

doctest1:
    if (theQName != NULL && !theQName->equals(node->getNodeName()))
      return false;

    if (theType != NULL)
    {
      xqtref_t atype = planState.theCompilerCB->m_sctx->get_typemanager()->
                       create_value_type(node);
      
      if ((!TypeOps::is_subtype(*atype, *theType)) || 
          (theNilledAllowed == false &&
           node->getNilled()->getBooleanValue() == true))
        return false;
    }

    return true;
  }
  case match_attr_test:
  {
    if (node->getNodeKind() != store::StoreConsts::attributeNode)
      return false;

    if (theQName != NULL &&
        !theQName->equals(node->getNodeName()))
      return false;

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
    return true;
  }
  case match_xs_elem_test:
  {
    if (node->getNodeKind() != store::StoreConsts::elementNode)
      return false;

doctest2:
    return true;
  }
  case match_xs_attr_test:
  {
    if (node->getNodeKind() != store::StoreConsts::attributeNode)
      return false;

    return true;
  }
  case match_pi_test:
  {
    if (node->getNodeKind() != store::StoreConsts::piNode)
      return false;

    if (theQName != NULL &&
        !theQName->getLocalName()->equals(node->getTarget()))
      return false;
    
    return true;
  }
  case match_comment_test:
  {
    if (node->getNodeKind() != store::StoreConsts::commentNode)
      return false;

    return true;
  }
  case match_text_test:
  {
    if (node->getNodeKind() != store::StoreConsts::textNode)
      return false;

    return true;
  }
  case match_anykind_test:
  {
    return true;
  }
  default:
    ZORBA_ASSERT(false && "Unknown kind test kind");
  }
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
  while (!nameOrKindTest(result, planState));

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
  theAttributes = GENV_ITERATOR_FACTORY->createAttributesIterator();
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
  store::Item* attr;

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

    state->theAttributes->init(state->theContextNode);
    state->theAttributes->open();

    while ((attr = state->theAttributes->next()) != NULL)
    {
      if (nameOrKindTest(attr, planState))
      {
        result = attr;
        STACK_PUSH(true, state);
      }
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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    result = state->theContextNode->getParent();

    if (result != NULL && nameOrKindTest(result, planState))
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
      if (nameOrKindTest(state->theCurrentAnc, planState))
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
      if (nameOrKindTest(state->theCurrentAnc, planState))
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
    }//daniel: maybe we should allow attribute nodes if kind test permits
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return false;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    while (state->theChildren->next(child) && child != state->theContextNode) ;

    while (state->theChildren->next(result))
    {
      if (nameOrKindTest(result, planState))
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
    }//daniel: maybe we should allow attribute nodes if kind test permits
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return false;

    state->theChildren = parent->getChildren();
    state->theChildren->open();

    while (state->theChildren->next(result) && result != state->theContextNode)
    {
      if (nameOrKindTest(result, planState))
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
  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void ChildAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);
  if (theChildren != NULL)
    theChildren->reset(); 
}


bool ChildAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* child;

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
        ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                             "The context item of an axis step is not a node");
      }
    }
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    state->theChildren->init(state->theContextNode);
    state->theChildren->open();

    while ((child = state->theChildren->next()) != NULL)
    {
      if (nameOrKindTest(child, planState)) 
      {
        result = child;
        STACK_PUSH(true, state);
      }
    }

    state->theChildren->close();
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DescendantAxisState::DescendantAxisState() : theTop(0)
{
}


DescendantAxisState::~DescendantAxisState()
{
  ulong len = theCurrentPath.size();
  for (ulong i = 0; i < len; i++)
  {
    delete theCurrentPath[i].second;
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
  theTop = 0;
}


void DescendantAxisState::push(store::Item_t& node)
{
  if (theTop < theCurrentPath.size())
  {
    theCurrentPath[theTop].first = node.getp();
    theCurrentPath[theTop].second->init(node);
  }
  else
  {
    store::ChildrenIterator* ite = GENV_ITERATOR_FACTORY->createChildrenIterator();;
    store::Item* node1 = node.getp();
    ite->init(node);
    theCurrentPath.push_back(std::pair<store::Item*, store::ChildrenIterator*>
                             (node1, ite));
  }

  theTop++;
}


bool DescendantAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* child;
  store::Item_t tmp;
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
        ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                             "The context item of an axis step is not a node");
      }
    }
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    state->push(state->theContextNode);
    
    while(true) 
    {
      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.

      while ((child = state->top()->next()) == NULL)
      {
        state->pop();
        if (state->empty())
          break;
      }

      if (child == NULL)
        break;

      if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        tmp = child;
        state->push(tmp);
      }

      if (nameOrKindTest(child, planState))
      {
        result = child;
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool DescendantSelfAxisIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t desc;
  DescendantAxisState* state;
  bool first = false;
  DEFAULT_STACK_INIT(DescendantAxisState, state, planState);

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
    while ((theTestKind == match_name_test || theTestKind == match_no_test) &&
           !isElementOrDocumentNode(state->theContextNode.getp()));//for name test, check for principal node type

    result = state->theContextNode;
    first = true;

    while(first || !state->empty()) 
    {
      first = false;
      if (isElementOrDocumentNode(result))
      {
        desc = result;
        state->push(desc);
      }

      if (nameOrKindTest(result, planState))
      {
        STACK_PUSH(true, state);
      }

      if(state->empty())
        break;

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      while ((result = state->top()->next()) == NULL)
      {
        state->pop();
        if (state->empty())
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

        if (nameOrKindTest(result, planState))
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

        if (nameOrKindTest(result, planState))
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
