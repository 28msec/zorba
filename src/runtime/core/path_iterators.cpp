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
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorAxisIterator, AncestorAxisState>, 4)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorReverseAxisIterator, AncestorReverseAxisState>, 5)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorSelfAxisIterator, AncestorAxisState>, 6)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<AncestorSelfReverseAxisIterator, AncestorReverseAxisState>, 7)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<RSiblingAxisIterator, RSiblingAxisState>, 8)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<LSiblingAxisIterator, LSiblingAxisState>, 9)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<LSiblingReverseAxisIterator, LSiblingReverseAxisState>, 10)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<ChildAxisIterator, ChildAxisState>, 11)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<DescendantAxisIterator,DescendantAxisState>, 12)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>, 13)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<PrecedingAxisIterator, PrecedingAxisState>, 14)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<PrecedingReverseAxisIterator, PrecedingReverseAxisState>, 15)
SERIALIZABLE_TEMPLATE_INSTANCE_VERSIONS2(AxisIterator, AxisIterator<FollowingAxisIterator,FollowingAxisState>, 16)

SERIALIZABLE_CLASS_VERSIONS(SelfAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(SelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AttributeAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AttributeAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(ParentAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ParentAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorReverseAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorSelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfReverseAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AncestorSelfReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(RSiblingAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(RSiblingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(LSiblingAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LSiblingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(LSiblingReverseAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(LSiblingReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(ChildAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ChildAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DescendantAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantSelfAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DescendantSelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(PrecedingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingReverseAxisIterator)
END_SERIALIZABLE_CLASS_VERSIONS(PrecedingReverseAxisIterator)

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
bool AncestorAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
bool AncestorReverseAxisIterator::nextImpl(
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
bool AncestorSelfAxisIterator::nextImpl(
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
bool AncestorSelfReverseAxisIterator::nextImpl(
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
void SiblingAxisState::init(PlanState& planState)
{
  AxisState::init(planState);

  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void SiblingAxisState::reset(PlanState& planState)
{
  AxisState::reset(planState);

  if (theChildren != NULL)
    theChildren->reset(); 
}


bool RSiblingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* parent;
  const store::Item* child;

  SiblingAxisState* state;
  DEFAULT_STACK_INIT(SiblingAxisState, state, planState);

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

    state->theChildren->init(parent, state->theContextNode.getp());
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
bool LSiblingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* parent;
  const store::Item* sibling;

  SiblingAxisState* state;
  DEFAULT_STACK_INIT(SiblingAxisState, state, planState);

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


bool LSiblingReverseAxisIterator::nextImpl(
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

    state->theChildren->init(parent, state->theContextNode.getp());
    state->theChildren->open();

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
DescendantAxisState::~DescendantAxisState()
{
  ulong len = theCurrentPath.size();
  for (ulong i = 0; i < len; ++i)
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
    theCurrentPath[theTop].second->open();
  }
  else
  {
    store::ChildrenIterator* ite = GENV_ITERATOR_FACTORY->createChildrenIterator();
    ite->init(node);
    ite->open();
    theCurrentPath.push_back(PathPair(node, ite));
  }

  ++theTop;
}


bool DescendantAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  const store::Item* desc = NULL;

  DescendantAxisState* state;
  DEFAULT_STACK_INIT(DescendantAxisState, state, planState);

  while (theTestKind != match_doc_test)
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
    
    desc = state->top()->next();

    while (desc != NULL) 
    {
      if (nameOrKindTest(desc, planState))
      {
        result = desc;

        if (desc->getNodeKind() == store::StoreConsts::elementNode &&
            (desc->isRecursive() || 
             theTestKind == match_anykind_test ||
             (theTestKind == match_elem_test && theQName == NULL) ||
             (theTestKind == match_name_test && theWildKind != match_no_wild)))
        {
          state->push(desc);
        }

        STACK_PUSH(true, state);
      }
      else if (desc->getNodeKind() == store::StoreConsts::elementNode)
      {
        state->push(desc);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      while (!state->empty() && (desc = state->top()->next()) == NULL)
      {
        state->pop();
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
  const store::Item* desc;
  store::StoreConsts::NodeKind descKind;

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

    desc = state->theContextNode.getp();

    while (desc != NULL)
    {
      descKind = desc->getNodeKind();

      if (nameOrKindTest(desc, planState))
      {
        result = desc;

        if ((descKind == store::StoreConsts::elementNode ||
             (descKind == store::StoreConsts::documentNode &&
              theTestKind == match_anykind_test)) &&
            (desc->isRecursive() || 
             theTestKind == match_anykind_test ||
             (theTestKind == match_elem_test && theQName == NULL) ||
             (theTestKind == match_name_test && theWildKind != match_no_wild)))
        {
          state->push(desc);
        }

        STACK_PUSH(true, state);
      }
      else if ((descKind == store::StoreConsts::elementNode ||
                descKind == store::StoreConsts::documentNode) &&
               theTestKind != match_doc_test)
      {
        state->push(desc);
      }

      desc = NULL;

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      while (!state->empty() && (desc = state->top()->next()) == NULL)
      {
        state->pop();
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
void PrecedingAxisState::init(PlanState& planState)
{
  DescendantAxisState::init(planState);

  theAncestorChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void PrecedingAxisState::reset(PlanState& planState)
{
  DescendantAxisState::reset(planState);

  theAncestorPath.clear();
  theAncestorChildren->close();
}


bool PrecedingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* ancestor;
  const store::Item* child;
  const store::Item* desc;

  PrecedingAxisState* state;
  DEFAULT_STACK_INIT(PrecedingAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode.getp();

    while (ancestor != NULL)
    {
      state->theAncestorPath.push_back(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor A of the current context node N and for each child C
    // of A such as C is to the left of the next ancestor AC in the ancestor
    // path (note: AC is a child of A), traverse the subtree rooted at C. 
    while (state->theAncestorPath.size() > 1)
    {
      // Get the next ancestor A in the ancestors path and open an iterator
      // over its children. 
      ancestor = state->theAncestorPath.back();
      state->theAncestorPath.pop_back();

      state->theAncestorChildren->init(ancestor);
      state->theAncestorChildren->open();

      // For each child C of A such that C is to the left of AC ...
      while ((child = state->theAncestorChildren->next()) != NULL &&
             child != state->theAncestorPath.back())
      {
        // Special case: C is not element node, so there is no tree to travesre.
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(child, planState))
          {
            result = child;
            STACK_PUSH(true, state);
          }
          
          continue;
        }

        // C is an element node; traverse its subtree, unless we can skip it
        // based on the non-recursiveness of C and the node test associated 
        // with this axis step.
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

        // Do the descendant traversal
        desc = child;

        while (desc != NULL)
        {
          if (nameOrKindTest(desc, planState))
          {
            result = desc;

            if (desc->getNodeKind() == store::StoreConsts::elementNode &&
                (desc->isRecursive() || 
                 theTestKind == match_anykind_test ||
                 (theTestKind == match_elem_test && theQName == NULL) ||
                 (theTestKind == match_name_test && theWildKind != match_no_wild)))
            {
              state->push(desc);
            }
            
            STACK_PUSH(true, state);
          }
          else if (desc->getNodeKind() == store::StoreConsts::elementNode)
          {
            state->push(desc);
          }

          while (!state->empty() && (desc = state->top()->next()) == NULL)
          {
            state->pop();
          }
        }
      }

      state->theAncestorChildren->close();
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
    theCurrentPath[theTop].second->open();
  }
  else
  {
    store::ChildrenReverseIterator* ite =
    GENV_ITERATOR_FACTORY->createChildrenReverseIterator();

    ite->init(node);
    ite->open();

    theCurrentPath.push_back(std::pair<const store::Item*,
                             store::ChildrenReverseIterator*>(node, ite));
  }

  theTop++;
}


bool PrecedingReverseAxisIterator::nextImpl(
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

    // For each ancestor A of the current context node N (starting with N's parent)
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
void FollowingAxisState::init(PlanState& planState)
{
  DescendantAxisState::init(planState);

  theAncestorChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void FollowingAxisState::reset(PlanState& planState)
{
  DescendantAxisState::reset(planState);

  theAncestorPath.clear();
  theAncestorChildren->close();
}


bool FollowingAxisIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item* ancestor;
  const store::Item* child;
  const store::Item* desc;

  FollowingAxisState* state;
  DEFAULT_STACK_INIT(FollowingAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node"); 
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode.getp();

    while (ancestor != NULL)
    {
      state->theAncestorPath.push_back(ancestor);
      ancestor = ancestor->getParent();
    }

    // For each ancestor A of the current context node N and for each child C
    // of A such as C is to the right of the next ancestor AC in the ancestor
    // path (note: AC is a child of A), traverse the subtree rooted at C. 
    while (state->theAncestorPath.size() > 1)
    {
      // Get the next ancestor A in the ancestors path and open an iterator
      // over its children, placing the iterator to the right of the next
      // ancestor AC in the ancestor path.
      ancestor = state->theAncestorPath.back();
      state->theAncestorPath.pop_back();

      state->theAncestorChildren->init(ancestor, state->theAncestorPath.back());
      state->theAncestorChildren->open();

      // For each child C of A such that C is to the right of AC ...
      while ((child = state->theAncestorChildren->next()) != NULL)
      {
        // Special case: C is not element node, so there is no tree to travesre.
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(child, planState))
          {
            result = child;
            STACK_PUSH(true, state);
          }
          
          continue;
        }

        // C is an element node; traverse its subtree, unless we can skip it
        // based on the non-recursiveness of C and the node test associated 
        // with this axis step.
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

        // Do the descendant traversal
        desc = child;

        while (desc != NULL)
        {
          if (nameOrKindTest(desc, planState))
          {
            result = desc;

            if (desc->getNodeKind() == store::StoreConsts::elementNode &&
                (desc->isRecursive() || 
                 theTestKind == match_anykind_test ||
                 (theTestKind == match_elem_test && theQName == NULL) ||
                 (theTestKind == match_name_test && theWildKind != match_no_wild)))
            {
              state->push(desc);
            }
            
            STACK_PUSH(true, state);
          }
          else if (desc->getNodeKind() == store::StoreConsts::elementNode)
          {
            state->push(desc);
          }

          while (!state->empty() && (desc = state->top()->next()) == NULL)
          {
            state->pop();
          }
        }
      }

      state->theAncestorChildren->close();
    }
  }

  STACK_END (state);
}


};
