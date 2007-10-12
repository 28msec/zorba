/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *	
 *		http://www.apache.org/licenses/LICENSE-2.0
 *	
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
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
#include "types/sequence_type_mgr.h"
#include "runtime/paths/path_iterators.h"
#include "util/zorba.h"
#include "store/api/item.h"

#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}



namespace xqp
{

/*******************************************************************************

********************************************************************************/
Item_t KindTestIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t contextNode;

  bool skip = false;

  do
  {
    contextNode = consumeNext(theChild, stateBlock);
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
      break;
    }
    case match_elem_test:
    {
      if (contextNode->getNodeKind() != elementNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL && !theQName->equals(contextNode->getNodeName()))
      {
        skip = true;
        break;
      }

      if (theTypeName != NULL)
      {
        TypeCode etype = zorba::getZorbaForCurrentThread()->getSequenceTypeManager()->
                         getTypecode(reinterpret_cast<QNameItem*>(&*theTypeName));
        TypeCode atype = contextNode->getType();

        if ((atype != etype && !sequence_type::derives_from(atype, etype)) ||
            (theNilledAllowed == false && contextNode->getNilled() == true))
          skip = true;
      }

      break;
    }
    case match_attr_test:
    {
      if (contextNode->getNodeKind() != attributeNode)
      {
        skip = true;
        break;
      }

      if (theQName != NULL && !theQName->equals(contextNode->getNodeName()))
      {
        skip = true;
        break;
      }

      if (theTypeName != NULL)
      {
        TypeCode etype = zorba::getZorbaForCurrentThread()->getSequenceTypeManager()->
                         getTypecode(reinterpret_cast<QNameItem*>(&*theTypeName));
        TypeCode atype = contextNode->getType();

        if (atype != etype && !sequence_type::derives_from(atype, etype))
          skip = true;
      }

      break;
    }
    case match_xs_elem_test:
    {
      if (contextNode->getNodeKind() != elementNode)
      {
        skip = true;
        break;
      }

      break;
    }
    case match_xs_attr_test:
    {
      if (contextNode->getNodeKind() != attributeNode)
      {
        skip = true;
        break;
      }

      break;
    }
    case match_pi_test:
    {
      if (contextNode->getNodeKind() != processingInstructionNode)
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
      if (contextNode->getNodeKind() != commentNode)
        skip = true;

      break;
    }
    case match_text_test:
    {
      if (contextNode->getNodeKind() != textNode)
        skip = true;

      break;
    }
    case match_anykind_test:
    {
      break;
    }
    default:
      ZorbaErrorAlerts::error_alert(
         error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
         error_messages::SYSTEM_ERROR,
         NULL,
         false,
         "Unknown kind test kind");
    }
  }
  while (skip);

  return contextNode;
}


std::ostream& KindTestIterator::_show(std::ostream& os)	const
{
  os << IT_DEPTH << " " << "test kind: " << theTestKind << std::endl;

  if (theQName != NULL)
    os << IT_DEPTH << " " << "qname: " << theQName->show() << std::endl;
  else
    os << IT_DEPTH << " " << "qname: *" << endl;

  if (theTypeName != NULL)
    os << IT_DEPTH << " " << "typename: " << theTypeName->show() << std::endl;
  else
    os << IT_DEPTH << " " << "typename: *" << endl;

  os << IT_DEPTH << " " << "nill allowed: " << theNilledAllowed << std::endl;

  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t NameTestIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t contextNode;

  while (true)
  {
    contextNode = consumeNext(theChild, stateBlock);
    if (contextNode == NULL)
      return NULL;

    switch (theWildKind)
    {
    case match_no_wild:
    {
      if (theQName->equals(contextNode->getNodeName()))
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
      ZorbaErrorAlerts::error_alert(
         error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
         error_messages::SYSTEM_ERROR,
         NULL,
         false,
         "Unknown name test kind");
    }
  }

  return NULL;
}


std::ostream& NameTestIterator::_show(std::ostream& os)	const
{
  if (theQName != NULL)
    os << IT_DEPTH << " " << "qname: " << theQName->show() << std::endl;
  else
    os << IT_DEPTH << " " << "qname: *" << endl;

  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
template <class AxisIter>
void AxisIterator<AxisIter>::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  UnaryBaseIterator<AxisIter>::releaseResourcesImpl(stateBlock);

  AxisState* state;
  GET_STATE(AxisState, state, stateBlock);
  state->theContextNode = NULL;
}


/*******************************************************************************

********************************************************************************/
Item_t SelfAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  SelfAxisState* state;
  GET_STATE(SelfAxisState, state, stateBlock);

  do
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
         error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
         error_messages::RUNTIME_ERROR,
         NULL,
         false,
         "The context item of an axis step is not a node");
    }
  }
  while (theNodeKind != anyNode && state->theContextNode->getNodeKind() != theNodeKind);

  return state->theContextNode;
}


std::ostream& SelfAxisIterator::_show(std::ostream& os)	const
{
  /*
  SelfAxisState* state;
  GET_STATE(SelfAxisState, state, stateBlock);

  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}

void SelfAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<SelfAxisIterator>::releaseResourcesImpl(stateBlock);
}                                   

/*******************************************************************************

********************************************************************************/
Item_t AttributeAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t attr;

  AttributeAxisState* state;
  STACK_INIT2(AttributeAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != elementNode);

    state->theAttributes = state->theContextNode->getAttributes();

    attr = consumeNext(state->theAttributes, stateBlock);

    while (attr != NULL)
    {
      STACK_PUSH2(attr, state);
      attr = consumeNext(state->theAttributes, stateBlock);
    }
  }

  STACK_END2();
}


void AttributeAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<AttributeAxisIterator>::resetImpl(stateBlock);

  AttributeAxisState* state;
  GET_STATE(AttributeAxisState, state, stateBlock); 
  state->theAttributes->reset(stateBlock);
}


void AttributeAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<AttributeAxisIterator>::releaseResourcesImpl(stateBlock);

  AttributeAxisState* state;
  GET_STATE(AttributeAxisState, state, stateBlock); 
  state->theAttributes = NULL;
}


std::ostream& AttributeAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */

  // theAttributes->show(os);
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ParentAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t parent;

  ParentAxisState* state;
  GET_STATE(ParentAxisState, state, stateBlock); 

  do
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
    }

    parent = state->theContextNode->getParent();
  }
  while (parent != NULL &&
         theNodeKind != anyNode && parent->getNodeKind() != theNodeKind);

  return parent;
}


std::ostream& ParentAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}

void ParentAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<ParentAxisIterator>::releaseResourcesImpl(stateBlock);
}
   

/*******************************************************************************

********************************************************************************/
Item_t AncestorAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  AncestorAxisState* state;
  STACK_INIT2(AncestorAxisState, state, stateBlock);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode->getParent();

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(state->theCurrentAnc, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END2();
}


void AncestorAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<AncestorAxisIterator>::releaseResourcesImpl(stateBlock);

  AncestorAxisState* state;
  GET_STATE(AncestorAxisState, state, stateBlock); 
  state->theCurrentAnc = NULL;
}


std::ostream& AncestorAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;

  os << IT_DEPTH << " " << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << IT_DEPTH << " " << theCurrentAnc->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t AncestorSelfAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  AncestorSelfAxisState* state;
  STACK_INIT2(AncestorSelfAxisState, state, stateBlock);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
    }

    state->theCurrentAnc = state->theContextNode;

    while (state->theCurrentAnc != NULL)
    {
      if (theNodeKind == anyNode ||
          state->theCurrentAnc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(state->theCurrentAnc, state);
      }

      state->theCurrentAnc = state->theCurrentAnc->getParent();
    }
  }

  STACK_END2();
}


void AncestorSelfAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<AncestorSelfAxisIterator>::releaseResourcesImpl(stateBlock);

  AncestorSelfAxisState* state;
  GET_STATE(AncestorSelfAxisState, state, stateBlock); 
  state->theCurrentAnc = NULL;
}


std::ostream& AncestorSelfAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;

  os << IT_DEPTH << " " << "ancestor node: " << std::endl;
  if (theCurrentAnc != NULL)
    os << IT_DEPTH << " " << theCurrentAnc->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t RSiblingAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t parent;
  Item_t sibling;

  RSiblingAxisState* state;
  STACK_INIT2(RSiblingAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();

    while (consumeNext(state->theChildren, stateBlock) != state->theContextNode) ;

    sibling = consumeNext(state->theChildren, stateBlock);

    while (sibling != NULL)
    {
      if (theNodeKind == anyNode || sibling->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(sibling, state);
      }

      sibling = consumeNext(state->theChildren, stateBlock);
    }
  }

  STACK_END2();
}


void RSiblingAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<RSiblingAxisIterator>::resetImpl(stateBlock);

  RSiblingAxisState* state;
  GET_STATE(RSiblingAxisState, state, stateBlock); 
  state->theChildren->reset(stateBlock); 
}


void RSiblingAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<RSiblingAxisIterator>::releaseResourcesImpl(stateBlock);

  RSiblingAxisState* state;
  GET_STATE(RSiblingAxisState, state, stateBlock); 
  state->theChildren = NULL; 
}


std::ostream& RSiblingAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t LSiblingAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t parent;
  Item_t sibling;

  LSiblingAxisState* state;
  STACK_INIT2(LSiblingAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() == attributeNode);

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      return NULL;

    state->theChildren = parent->getChildren();

    sibling = consumeNext(state->theChildren, stateBlock);

    while (sibling != state->theContextNode)
    {
      if (theNodeKind == anyNode || sibling->getNodeKind() == theNodeKind)
      {
#ifdef DEBUG
        theLSibling = sibling;
#endif
        STACK_PUSH2(sibling, state);
      }

      sibling = consumeNext(state->theChildren, stateBlock);
    }
  }

  STACK_END2();
}


void LSiblingAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<LSiblingAxisIterator>::resetImpl(stateBlock);

  LSiblingAxisState* state;
  GET_STATE(LSiblingAxisState, state, stateBlock); 
  state->theChildren->reset(stateBlock);
}


void LSiblingAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<LSiblingAxisIterator>::releaseResourcesImpl(stateBlock);

  LSiblingAxisState* state;
  GET_STATE(LSiblingAxisState, state, stateBlock); 
  state->theChildren = NULL; 
}


std::ostream& LSiblingAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t ChildAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t child;

  ChildAxisState* state;
  STACK_INIT2(ChildAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != elementNode &&
           state->theContextNode->getNodeKind() != documentNode);

    state->theChildren = state->theContextNode->getChildren();

    child = consumeNext(state->theChildren, stateBlock);

    while (child != NULL)
    {
      /*
      cout << "ite = " << this << " node = " << &*child
           << " is node child = " << child->isNode();
      if (child->isNode())
        cout << " node kind = "
             << sequence_type::describe(child->getNodeKind()) << endl;
      else
        cout << endl;
      */
      if (theNodeKind == anyNode || child->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(child, state);
      }

      child = consumeNext(state->theChildren, stateBlock);
    }
  }

  STACK_END2();
}


void ChildAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<ChildAxisIterator>::resetImpl(stateBlock);

  ChildAxisState* state;
  GET_STATE(ChildAxisState, state, stateBlock); 
  state->theChildren->reset(stateBlock);
}


void ChildAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<ChildAxisIterator>::releaseResourcesImpl(stateBlock);

  ChildAxisState* state;
  GET_STATE(ChildAxisState, state, stateBlock); 
  state->theChildren = NULL;
}


std::ostream& ChildAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t desc;
  Iterator_t children;

  DescendantAxisState* state;
  STACK_INIT2(DescendantAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != elementNode &&
           state->theContextNode->getNodeKind() != documentNode);

    //MYTRACE("iter = " << this << " ctxNode = [" << &*state->theContextNode << " " << state->theContextNode->getNodeName()->show() << "]");

    children = state->theContextNode->getChildren();

    state->theCurrentPath.push(
              std::pair<Item_t, Iterator_t>(state->theContextNode, children));
    
    desc = consumeNext(children, stateBlock);

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode)
        state->theCurrentPath.push(
                  std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

      if (theNodeKind == anyNode || desc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(desc, state);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = consumeNext(state->theCurrentPath.top().second, stateBlock);

      while (desc == NULL)
      {
        state->theCurrentPath.pop();
        if (!state->theCurrentPath.empty())
          desc = consumeNext(state->theCurrentPath.top().second, stateBlock);
        else
          break;
      }
    }
  }

  STACK_END2();
}


void DescendantAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<DescendantAxisIterator>::resetImpl(stateBlock);

  DescendantAxisState* state;
  GET_STATE(DescendantAxisState, state, stateBlock); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<DescendantAxisIterator>::releaseResourcesImpl(stateBlock);

  DescendantAxisState* state;
  GET_STATE(DescendantAxisState, state, stateBlock); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantAxisIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  AxisIterator<DescendantAxisIterator>::setOffset(stateBlock, offset);

  DescendantAxisState* state = new (stateBlock.block + stateOffset) DescendantAxisState;
}


std::ostream& DescendantAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t DescendantSelfAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t desc;

  DescendantSelfAxisState* state;
  STACK_INIT2(DescendantSelfAxisState, state, stateBlock);

  while (true)
  {
    do
    {
      state->theContextNode = consumeNext(theChild, stateBlock);
      if (state->theContextNode == NULL)
        return NULL;

      if (!state->theContextNode->isNode())
      {
        ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
      }
    }
    while (state->theContextNode->getNodeKind() != elementNode &&
           state->theContextNode->getNodeKind() != documentNode);

    desc = state->theContextNode;

    while (desc != NULL)
    {
      if (desc->getNodeKind() == elementNode ||
          state->theContextNode->getNodeKind() == documentNode)
        state->theCurrentPath.push(
                  std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

      if (theNodeKind == anyNode || desc->getNodeKind() == theNodeKind)
      {
        STACK_PUSH2(desc, state);
      }

      // The next descendant is the next child of the node N that is currently
      // at the top of the path stack. If N has no children or all of its
      // children have been processed already, N is removed from the stack
      // and the process is repeated.
      desc = consumeNext(state->theCurrentPath.top().second, stateBlock);

      while (desc == NULL)
      {
        state->theCurrentPath.pop();
        if (!state->theCurrentPath.empty())
          desc = consumeNext(state->theCurrentPath.top().second, stateBlock);
        else
          break;
      }
    }
  }

  STACK_END2();
}


void DescendantSelfAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<DescendantSelfAxisIterator>::resetImpl(stateBlock);

  DescendantSelfAxisState* state;
  GET_STATE(DescendantSelfAxisState, state, stateBlock); 

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantSelfAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<DescendantSelfAxisIterator>::releaseResourcesImpl(stateBlock);

  DescendantSelfAxisState* state;
  GET_STATE(DescendantSelfAxisState, state, stateBlock);

  while (!state->theCurrentPath.empty())
  {
    state->theCurrentPath.pop();
  }
}


void DescendantSelfAxisIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  AxisIterator<DescendantSelfAxisIterator>::setOffset(stateBlock, offset);

  DescendantSelfAxisState* state = new (stateBlock.block + stateOffset) DescendantSelfAxisState;
}


std::ostream& DescendantSelfAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t PrecedingAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t ancestor;
  Item_t desc;
  Iterator_t children;

  PrecedingAxisState* state;
  STACK_INIT2(PrecedingAxisState, state, stateBlock);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode;
    state->theAncestorPath.push(ancestor);

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
    
      desc = consumeNext(children, stateBlock);

      while (desc != state->theAncestorPath.top())
      {
        if (desc->getNodeKind() == elementNode)
          state->theCurrentPath.push(
                    std::pair<Item_t, Iterator_t>(desc, desc->getChildren()));

        if (theNodeKind == anyNode || desc->getNodeKind() == theNodeKind)
        {
          STACK_PUSH2(desc, state);
        }

        desc = consumeNext(state->theCurrentPath.top().second, stateBlock);

        while (desc == NULL)
        {
          state->theCurrentPath.pop();
          Assert(!state->theCurrentPath.empty());
          desc = consumeNext(state->theCurrentPath.top().second, stateBlock);
        }
      }

      state->theCurrentPath.pop();
      state->theCurrentPath.pop();
      Assert(state->theCurrentPath.empty());
    }
  }

  STACK_END2();
}


void PrecedingAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<PrecedingAxisIterator>::resetImpl(stateBlock);

  PrecedingAxisState* state;
  GET_STATE(PrecedingAxisState, state, stateBlock); 

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();
}


void PrecedingAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<PrecedingAxisIterator>::releaseResourcesImpl(stateBlock);

  PrecedingAxisState* state;
  GET_STATE(PrecedingAxisState, state, stateBlock); 

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();
}


void PrecedingAxisIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  AxisIterator<PrecedingAxisIterator>::setOffset(stateBlock, offset);

  PrecedingAxisState* state = new (stateBlock.block + stateOffset) PrecedingAxisState;
}


std::ostream& PrecedingAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
Item_t FollowingAxisIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t ancestor;
  Item_t following;
  Iterator_t children;

  FollowingAxisState* state;
  STACK_INIT2(FollowingAxisState, state, stateBlock);

  while (true)
  {
    state->theContextNode = consumeNext(theChild, stateBlock);
    if (state->theContextNode == NULL)
      return NULL;

    if (!state->theContextNode->isNode())
    {
      ZorbaErrorAlerts::error_alert(
           error_messages::XPTY0020_TYPE_CONTEXT_NOT_A_NODE,
           error_messages::RUNTIME_ERROR,
           NULL,
           false,
           "The context item of an axis step is not a node");
    }

    // Collect the context node and its ancestors
    ancestor = state->theContextNode;
    state->theAncestorPath.push(ancestor);

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
        following = consumeNext(children, stateBlock);
      }
      while (following != state->theAncestorPath.top());

      following = consumeNext(children, stateBlock);

      while (following != NULL)
      {
        if (following->getNodeKind() == elementNode)
          state->theCurrentPath.push(
                 std::pair<Item_t, Iterator_t>(following, following->getChildren()));

        if (theNodeKind == anyNode || following->getNodeKind() == theNodeKind)
        {
          STACK_PUSH2(following, state);
        }

        following = consumeNext(state->theCurrentPath.top().second, stateBlock);

        while (following == NULL)
        {
          state->theCurrentPath.pop();
          Assert(!state->theCurrentPath.empty());
          following = consumeNext(state->theCurrentPath.top().second, stateBlock);
        }
      }

      state->theCurrentPath.pop();
      Assert(state->theCurrentPath.empty());
    }
  }

  STACK_END2();
}


void FollowingAxisIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<FollowingAxisIterator>::resetImpl(stateBlock);

  FollowingAxisState* state;
  GET_STATE(FollowingAxisState, state, stateBlock);

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();

  state->theContextNode = NULL;
}


void FollowingAxisIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  AxisIterator<FollowingAxisIterator>::releaseResourcesImpl(stateBlock);

  FollowingAxisState* state;
  GET_STATE(FollowingAxisState, state, stateBlock);

  while (!state->theCurrentPath.empty())
    state->theCurrentPath.pop();

  while (!state->theAncestorPath.empty())
    state->theAncestorPath.pop();

  state->theContextNode = NULL;
}


void FollowingAxisIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  AxisIterator<FollowingAxisIterator>::setOffset(stateBlock, offset);

  FollowingAxisState* state = new (stateBlock.block + stateOffset) FollowingAxisState;
}


std::ostream& FollowingAxisIterator::_show(std::ostream& os)	const
{
  /*
  os << IT_DEPTH << " " << "context node: " << std::endl;
  if (state->theContextNode != NULL)
    os << IT_DEPTH << " " << state->theContextNode->show() << std::endl;
  */
  theChild->show(os);
  return os;
}


};
