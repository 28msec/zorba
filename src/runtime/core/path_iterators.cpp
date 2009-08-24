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
  //SERIALIZABLE_CLASS_VERSIONS(AxisIteratorHelper)
  //END_SERIALIZABLE_CLASS_VERSIONS(AxisIteratorHelper)

SERIALIZABLE_TEMPLATE_VERSIONS(AxisIterator)
END_SERIALIZABLE_TEMPLATE_VERSIONS(AxisIterator)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<SelfAxisIterator, SelfAxisState>, 1)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AttributeAxisIterator, AttributeAxisState>, 2)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<ParentAxisIterator, ParentAxisState>, 3)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorAxisIter, AncestorAxisState>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorReverseAxisIter, AncestorReverseAxisState>, 5)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorSelfAxisIter, AncestorAxisState>, 6)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorSelfReverseAxisIter, AncestorReverseAxisState>, 7)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<RSiblingAxisIter, RSiblingAxisState>, 8)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<LSiblingAxisIter, LSiblingAxisState>, 9)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<LSiblingReverseAxisIter, LSiblingReverseAxisState>, 10)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<ChildAxisIterator, ChildAxisState>, 11)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<DescendantAxisIterator,DescendantAxisState>, 12)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>, 13)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<PrecedingAxisIterator, PrecedingAxisState>, 14)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<PrecedingReverseAxisIter, PrecedingReverseAxisState>, 15)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<FollowingAxisIterator,FollowingAxisState>, 16)

SERIALIZABLE_CLASS_VERSIONS(SelfAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AttributeAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AttributeAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(ParentAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ParentAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorAxisIter)

SERIALIZABLE_CLASS_VERSIONS(AncestorReverseAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorReverseAxisIter)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorSelfAxisIter)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfReverseAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorSelfReverseAxisIter)

SERIALIZABLE_CLASS_VERSIONS(RSiblingAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(RSiblingAxisIter)

SERIALIZABLE_CLASS_VERSIONS(LSiblingAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(LSiblingAxisIter)

SERIALIZABLE_CLASS_VERSIONS(LSiblingReverseAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(LSiblingReverseAxisIter)

SERIALIZABLE_CLASS_VERSIONS(ChildAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ChildAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DescendantAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantSelfAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DescendantSelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(PrecedingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingReverseAxisIter)
END_SERIALIZABLE_CLASS_VERSIONS(PrecedingReverseAxisIter)

SERIALIZABLE_CLASS_VERSIONS(FollowingAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(FollowingAxisIterator)



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
  case match_xs_elem_test:
  {
    if (node->getNodeKind() != store::StoreConsts::elementNode)
      return false;

doctest2:
    assert(theQName != NULL);
    assert(theType != NULL);

    if (!theQName->equals(node->getNodeName()))
      return false;

    xqtref_t atype = planState.theCompilerCB->m_sctx->get_typemanager()->
                     create_value_type(node);
      
    if ((!TypeOps::is_subtype(*atype, *theType)) || 
        (theNilledAllowed == false &&
         node->getNilled()->getBooleanValue() == true))
      return false;

    return true;
  }
  case match_attr_test:
  {
    if (node->getNodeKind() != store::StoreConsts::attributeNode)
      return false;

    if (theQName != NULL && !theQName->equals(node->getNodeName()))
      return false;

    if (theType != NULL)
    {
      xqtref_t atype = planState.theCompilerCB->m_sctx->get_typemanager()->
                       create_value_type(node);

      if (! TypeOps::is_subtype(*atype, *theType))
        return false;
    }

    return true;
  }
  case match_xs_attr_test:
  {
    if (node->getNodeKind() != store::StoreConsts::attributeNode)
      return false;

    if (!theQName->equals(node->getNodeName()))
      return false;

    xqtref_t atype = planState.theCompilerCB->m_sctx->get_typemanager()->
                     create_value_type(node);

    if (! TypeOps::is_subtype(*atype, *theType))
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


void AttributeAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
  theAttributes = GENV_ITERATOR_FACTORY->createAttributesIterator();
}


void AttributeAxisState::reset(PlanState& planState)
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
bool AncestorAxisIter::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* ancestor;

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

    ancestor = state->theContextNode->getParent();

    while (ancestor != NULL)
    {
      if (nameOrKindTest(ancestor, planState))
      {
        state->theAncestors.push_back(ancestor);
      }
      ancestor = ancestor->getParent();
    }

    state->theCurrentAncPos = state->theAncestors.size() - 1;

    while (state->theCurrentAncPos >= 0)
    {
      result = state->theAncestors[state->theCurrentAncPos--];
      STACK_PUSH(true, state);
    }
    
    state->theAncestors.clear();
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool AncestorReverseAxisIter::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item* ancestor;

  AncestorReverseAxisState* state;
  DEFAULT_STACK_INIT(AncestorReverseAxisState, state, planState);

  while (true)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    ancestor = state->theContextNode->getParent();

    while (ancestor != NULL)
    {
      if (nameOrKindTest(ancestor, planState))
      {
        result = ancestor;
        state->theCurrentAnc = ancestor;
        STACK_PUSH(true, state);
        ancestor = state->theCurrentAnc->getParent();
      }
      else
      {
        ancestor = ancestor->getParent();
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool AncestorSelfAxisIter::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item* ancestor;

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

    ancestor = state->theContextNode.getp();

    while (ancestor != NULL)
    {
      if (nameOrKindTest(ancestor, planState))
      {
        state->theAncestors.push_back(ancestor);
      }
      ancestor = ancestor->getParent();
    }

    state->theCurrentAncPos = state->theAncestors.size() - 1;

    while (state->theCurrentAncPos >= 0)
    {
      result = state->theAncestors[state->theCurrentAncPos--];
      STACK_PUSH(true, state);
    }
    
    state->theAncestors.clear();
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
bool AncestorSelfReverseAxisIter::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  AncestorReverseAxisState* state;
  DEFAULT_STACK_INIT(AncestorReverseAxisState, state, planState);

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

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
void RSiblingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);

  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void RSiblingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  if (theChildren != NULL)
    theChildren->reset(); 
}


bool RSiblingAxisIter::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* parent;
  const store::Item* child;

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
      continue;

    state->theChildren->init(parent);
    state->theChildren->open();

    while ((child = state->theChildren->next()) != NULL &&
           child != state->theContextNode)
    {
      ;
    }

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
void LSiblingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);

  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void LSiblingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  if (theChildren != NULL)
    theChildren->reset();
}


bool LSiblingAxisIter::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* parent;
  const store::Item* sibling;

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
        ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                             "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      continue;

    state->theChildren->init(parent);
    state->theChildren->open();

    while ((sibling = state->theChildren->next()) != NULL &&
           sibling != state->theContextNode.getp())
    {
      if (nameOrKindTest(sibling, planState))
      {
        result = sibling;
        STACK_PUSH(true, state);
      }
    }
    
    state->theChildren->close();
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
void LSiblingReverseAxisState::init(PlanState& planState)
{
  AxisState::init(planState);

  theChildren = GENV_ITERATOR_FACTORY->createChildrenReverseIterator();
}


void LSiblingReverseAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  if (theChildren != NULL)
    theChildren->reset();
}


bool LSiblingReverseAxisIter::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  const store::Item* parent;
  const store::Item* sibling;

  LSiblingReverseAxisState* state;
  DEFAULT_STACK_INIT(LSiblingReverseAxisState, state, planState);

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
      continue;

    state->theChildren->init(parent);
    state->theChildren->open();

    while ((sibling = state->theChildren->next()) != NULL &&
           sibling != state->theContextNode.getp())
    {
      ;
    }

    while ((sibling = state->theChildren->next()) != NULL)
    {
      if (nameOrKindTest(sibling, planState))
      {
        result = sibling;
        STACK_PUSH(true, state);
      }
    }
    
    state->theChildren->close();
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/

ChildAxisState::ChildAxisState() 
{
}


ChildAxisState::~ChildAxisState() 
{
}


void ChildAxisState::init(PlanState& planState)
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
  const store::Item* child;

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


void DescendantAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}


void DescendantAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  for (ulong i = 0; i < theTop; ++i)
  {
    theCurrentPath[i].second->close();
  }

  theTop = 0;
}


void DescendantAxisState::push(const store::Item* node)
{
  if (theTop < theCurrentPath.size())
  {
    theCurrentPath[theTop].first = node;
    theCurrentPath[theTop].second->init(node);
  }
  else
  {
    store::ChildrenIterator* ite = GENV_ITERATOR_FACTORY->createChildrenIterator();
    ite->init(node);
    theCurrentPath.push_back(std::pair<const store::Item*, store::ChildrenIterator*>
                             (node, ite));
  }

  theTop++;
}


bool DescendantAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* child = NULL;

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
      while (!state->empty() && (child = state->top()->next()) == NULL)
      {
        state->pop();
      }

      if (child == NULL)
        break;

      if (nameOrKindTest(child, planState))
      {
        result = child;

        if (child->getNodeKind() == store::StoreConsts::elementNode &&
            (child->isRecursive() || 
             theTestKind == match_anykind_test ||
             (theTestKind == match_elem_test && theQName == NULL) ||
             (theTestKind == match_name_test && theWildKind != match_no_wild)))
        {
          state->push(child);
        }

        STACK_PUSH(true, state);
      }
      else if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        state->push(child);
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
  const store::Item* child;
  store::StoreConsts::NodeKind childKind;

  DescendantAxisState* state;
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
           !isElementOrDocumentNode(state->theContextNode.getp()));

    child = state->theContextNode.getp();

    while (child != NULL)
    {
      childKind = child->getNodeKind();

      if (nameOrKindTest(child, planState))
      {
        result = child;

        if ((childKind == store::StoreConsts::elementNode ||
             (childKind == store::StoreConsts::documentNode &&
              theTestKind == match_anykind_test)) &&
            (child->isRecursive() || 
             theTestKind == match_anykind_test ||
             (theTestKind == match_elem_test && theQName == NULL) ||
             (theTestKind == match_name_test && theWildKind != match_no_wild)))
        {
          state->push(child);
        }

        STACK_PUSH(true, state);
      }
      else if ((childKind == store::StoreConsts::elementNode ||
                childKind == store::StoreConsts::documentNode) &&
               theTestKind != match_doc_test)
      {
        state->push(child);
      }

      child = NULL;

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      while (!state->empty() && (child = state->top()->next()) == NULL)
      {
        state->pop();
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
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


void PrecedingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}


void PrecedingAxisState::reset(PlanState& planState)
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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
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
PrecedingReverseAxisState::PrecedingReverseAxisState() 
  :
  theAncestorChild(NULL),
  theTop(0)
{
  theAncestor.first = NULL;
  theAncestor.second = NULL;
}


PrecedingReverseAxisState::~PrecedingReverseAxisState()
{
  if (theAncestor.second != NULL)
    delete theAncestor.second;

  ulong len = theCurrentPath.size();
  for (ulong i = 0; i < len; ++i)
  {
    delete theCurrentPath[i].second;
  }
}


void PrecedingReverseAxisState::init(PlanState& planState)
{
  AxisState::init(planState);

  if (theAncestor.second == NULL)
    theAncestor.second = GENV_ITERATOR_FACTORY->createChildrenReverseIterator();
}


void PrecedingReverseAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  for (ulong i = 0; i < theTop; ++i)
  {
    theCurrentPath[i].second->close();
  }

  theTop = 0;

  if (theAncestor.second != NULL)
    theAncestor.second->close();

  theAncestorChild = NULL;
}


void PrecedingReverseAxisState::push(const store::Item* node)
{
  if (theTop < theCurrentPath.size())
  {
    theCurrentPath[theTop].first = node;
    theCurrentPath[theTop].second->init(node);
  }
  else
  {
    store::ChildrenReverseIterator* ite =
    GENV_ITERATOR_FACTORY->createChildrenReverseIterator();

    ite->init(node);

    theCurrentPath.push_back(std::pair<const store::Item*,
                             store::ChildrenReverseIterator*>(node, ite));
  }

  theTop++;
}


bool PrecedingReverseAxisIter::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  const store::Item* child;
  const store::Item* desc;

  PrecedingReverseAxisState* state;
  DEFAULT_STACK_INIT(PrecedingReverseAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    state->theAncestorChild = state->theContextNode.getp();
    state->theAncestor.first = state->theAncestorChild->getParent();

    // For each ancestor A of the current context node N ...
    while (state->theAncestor.first != NULL)
    {
      state->theAncestor.second->init(state->theAncestor.first);

      // Find the 1st child C of A such that C is to the left of the previous
      // ancestor (i.e. C is the left sibling of the previous ancestor).
      while ((child = state->theAncestor.second->next()) != NULL &&
             child != state->theAncestorChild)
      {
        ;
      }

      // For each child C of A such that C is to the left of the previous
      // ancestor, do a reverse traversal of the subtree T rooted at C.
      while ((child = state->theAncestor.second->next()) != NULL)
      {
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(child, planState))
          {
            result = child;
            STACK_PUSH(true, state);
          }

          continue;
        }

        if (nameOrKindTest(child, planState))
        {
          if (child->isRecursive() || 
              theTestKind == match_anykind_test ||
              (theTestKind == match_elem_test && theQName == NULL) ||
              (theTestKind == match_name_test && theWildKind != match_no_wild))
          {
            state->push(child);
          }
          else
          {
            result = child;
            STACK_PUSH(true, state);

            continue;
          }
        }
        else
        {
          state->push(child);
        }

        // Do the reverse traversal
        do
        {
          // Traversed all the subtrees of the node D that is at the top of
          // theCurrentPath.
          while ((desc = state->top()->next()) != NULL)
          {
            if (desc->getNodeKind() == store::StoreConsts::elementNode)
            {
              if (nameOrKindTest(desc, planState))
              {
                if (desc->isRecursive() || 
                    theTestKind == match_anykind_test ||
                    (theTestKind == match_elem_test && theQName == NULL) ||
                    (theTestKind == match_name_test && theWildKind != match_no_wild))
                {
                  state->push(desc); // recursive traversal
                }
                else
                {
                  result = desc;
                  STACK_PUSH(true, state);
                }
              }
              else
              {
                state->push(desc); // recursive traversal
              }
            }
            else
            {
              if (nameOrKindTest(desc, planState))
              {
                result = desc;
                STACK_PUSH(true, state);
              }
            }
          }

          // We have traversed all the subtrees of the node D that is at the
          // top of theCurrentPath. Return D to the caller, if it satifies the
          // node test, and then pop D from theCurrentPath.
          if (nameOrKindTest(state->topNode(), planState))
          {
            result = state->topNode();
            STACK_PUSH(true, state);
          }

          state->pop();
        }
        while (!state->empty());
      } // for each child C of current ancestor

      // Go to the next ancestor up the ancestor path
      state->theAncestorChild = state->theAncestor.first;
      state->theAncestor.first = state->theAncestorChild->getParent();
    }
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
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


void FollowingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);
}


void FollowingAxisState::reset(PlanState& planState)
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


bool FollowingAxisIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
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
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node"); 
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
