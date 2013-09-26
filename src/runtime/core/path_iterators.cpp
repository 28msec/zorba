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

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"

#include "system/globalenv.h"

#include "types/typeops.h"
#include "types/typeimpl.h"

#include "compiler/api/compilercb.h"

#include "runtime/core/path_iterators.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"


#define MYTRACE(msg) \
{\
  cout << __PRETTY_FUNCTION__ << ":" << __LINE__ << "  " << msg << endl; \
}



namespace zorba
{

#if 0
template<> const char* 
AxisIterator<SelfAxisIterator, SelfAxisState>::class_name_str =
"AxisIterator<SelfAxisIterator, SelfAxisState>";

template<> const char* 
AxisIterator<AttributeAxisIterator, AttributeAxisState>::class_name_str =
"AxisIterator<AttributeAxisIterator, AttributeAxisState>";

template<> const char* 
AxisIterator<ParentAxisIterator, ParentAxisState>::class_name_str =
"AxisIterator<ParentAxisIterator, ParentAxisState>";

template<> const char* 
AxisIterator<AncestorAxisIterator, AncestorAxisState>::class_name_str =
"AxisIterator<AncestorAxisIterator, AncestorAxisState>";

template<> const char* 
AxisIterator<AncestorReverseAxisIterator, AncestorReverseAxisState>::class_name_str =
"AxisIterator<AncestorReverseAxisIterator, AncestorReverseAxisState>";

template<> const char* 
AxisIterator<AncestorSelfAxisIterator, AncestorAxisState>::class_name_str =
"AxisIterator<AncestorSelfAxisIterator, AncestorAxisState>";

template<> const char* 
AxisIterator<AncestorSelfReverseAxisIterator, AncestorReverseAxisState>::class_name_str =
"AxisIterator<AncestorSelfReverseAxisIterator, AncestorReverseAxisState>";

template<> const char* 
AxisIterator<RSiblingAxisIterator, SiblingAxisState>::class_name_str =
"AxisIterator<RSiblingAxisIterator, SiblingAxisStat>";

template<> const char* 
AxisIterator<LSiblingAxisIterator, SiblingAxisState>::class_name_str =
"AxisIterator<LSiblingAxisIterator, SiblingAxisState>";

template<> const char* 
AxisIterator<LSiblingReverseAxisIterator, LSiblingReverseAxisState>::class_name_str =
"AxisIterator<LSiblingReverseAxisIterator, LSiblingReverseAxisState>";

template<> const char* 
AxisIterator<ChildAxisIterator, ChildAxisState>::class_name_str =
"AxisIterator<ChildAxisIterator, ChildAxisState>";

template<> const char* 
AxisIterator<DescendantAxisIterator,DescendantAxisState>::class_name_str =
"AxisIterator<DescendantAxisIterator,DescendantAxisState>";

template<> const char* 
AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>::class_name_str =
"AxisIterator<DescendantSelfAxisIterator,DescendantAxisState>";

template<> const char* 
AxisIterator<PrecedingAxisIterator, PrecedingAxisState>::class_name_str =
"AxisIterator<PrecedingAxisIterator, PrecedingAxisState>";

template<> const char* 
AxisIterator<PrecedingReverseAxisIterator, PrecedingReverseAxisState>::class_name_str =
"AxisIterator<PrecedingReverseAxisIterator, PrecedingReverseAxisState>";

template<> const char* 
AxisIterator<FollowingAxisIterator, FollowingAxisState>::class_name_str =
"AxisIterator<FollowingAxisIterator, FollowingAxisState>";
#endif

SERIALIZABLE_CLASS_VERSIONS(SelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AttributeAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(ParentAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(AncestorSelfReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(RSiblingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(LSiblingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(LSiblingReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(ChildAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(DescendantSelfAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(PrecedingReverseAxisIterator)

SERIALIZABLE_CLASS_VERSIONS(FollowingAxisIterator)


UNARY_ACCEPT(SelfAxisIterator);

UNARY_ACCEPT(AttributeAxisIterator);

UNARY_ACCEPT(ParentAxisIterator);

UNARY_ACCEPT(AncestorAxisIterator);

UNARY_ACCEPT(AncestorReverseAxisIterator);

UNARY_ACCEPT(AncestorSelfAxisIterator);

UNARY_ACCEPT(AncestorSelfReverseAxisIterator);

UNARY_ACCEPT(RSiblingAxisIterator);

UNARY_ACCEPT(LSiblingAxisIterator);

UNARY_ACCEPT(LSiblingReverseAxisIterator);

UNARY_ACCEPT(ChildAxisIterator);

UNARY_ACCEPT(DescendantAxisIterator);

UNARY_ACCEPT(DescendantSelfAxisIterator);

UNARY_ACCEPT(PrecedingAxisIterator);

UNARY_ACCEPT(PrecedingReverseAxisIterator);

UNARY_ACCEPT(FollowingAxisIterator);



static inline bool isElementOrDocumentNode(const store::Item* node)
{
  assert(node->isNode());
  store::StoreConsts::NodeKind kind = node->getNodeKind();
  return (kind == store::StoreConsts::elementNode ||
          kind == store::StoreConsts::documentNode);
}



/*******************************************************************************

********************************************************************************/
void AxisIteratorHelper::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_ENUM(match_test_t, theTestKind);
  SERIALIZE_ENUM(match_test_t, theDocTestKind);
  SERIALIZE_ENUM(store::StoreConsts::NodeKind, theNodeKind);
  ar & theQName;
  SERIALIZE_ENUM(match_wild_t, theWildKind);
  ar & theType;
  ar & theNilledAllowed;
  ar & theTargetPos;
}


bool AxisIteratorHelper::setTargetPos(xs_long pos)
{
  assert(pos == -2 || pos >= 0);

  if (theTargetPos == -2)
  {
    theTargetPos = pos;
    return true;
  }
  else
  {
    return false;
  }
}


bool AxisIteratorHelper::nameOrKindTest(
    static_context* sctx,
    const store::Item* node,
    const QueryLoc& loc) const
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
      if (theQName->getLocalName() == node->getNodeName()->getLocalName())
        return true;

      return false;
    }
    case match_name_wild:
    {
      if (theQName->getNamespace() == node->getNodeName()->getNamespace())
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
        {
          return false;
        }
        else
        {
          elemTest = theDocTestKind;
          node = child.getp();
        }
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
      xqtref_t atype = sctx->get_typemanager()->
      create_named_type(node->getType(), SequenceType::QUANT_ONE, loc);

      if ((!TypeOps::is_subtype(sctx->get_typemanager(), *atype, *theType)) ||
          (theNilledAllowed == false &&
           node->getNilled() == true))
      {
        return false;
      }
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

    xqtref_t atype = sctx->get_typemanager()->
    create_named_type(node->getType(), SequenceType::QUANT_ONE, loc);

    if ((!TypeOps::is_subtype(sctx->get_typemanager(), *atype, *theType)) ||
        (theNilledAllowed == false &&
         node->getNilled() == true))
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
      xqtref_t atype = sctx->get_typemanager()->
      create_named_type(node->getType(), SequenceType::QUANT_ONE, loc);

      if (! TypeOps::is_subtype(sctx->get_typemanager(), *atype, *theType))
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

    xqtref_t atype = sctx->get_typemanager()->
    create_named_type(node->getType(), SequenceType::QUANT_ONE, loc);

    if (! TypeOps::is_subtype(sctx->get_typemanager(), *atype, *theType))
      return false;

    return true;
  }
  case match_pi_test:
  {
    if (node->getNodeKind() != store::StoreConsts::piNode)
      return false;

    if (theQName != NULL &&
        theQName->getLocalName() != node->getTarget())
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
  case match_namespace_test:
  {
    if (node->getNodeKind() != store::StoreConsts::namespaceNode)
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
void SelfAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<SelfAxisIterator, SelfAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


bool SelfAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  SelfAxisState* state;
  state = StateTraitsImpl<SelfAxisState>::getState(planState, theStateOffset);

  do
  {
    if (!consumeNext(result, theChild.getp(), planState))
      return false;

    if (!result->isNode())
    {
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;

    if (nameOrKindTest(theSctx, result, loc))
    {
      if (theTargetPos >= 1)
        return false;

      break;
    }
  }
  while (true);

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


void AttributeAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<AttributeAxisIterator, AttributeAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
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
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while (state->theContextNode->getNodeKind() != store::StoreConsts::elementNode);

    state->theCurrentPos = 0;
    state->theAttributes->init(state->theContextNode);
    state->theAttributes->open();

    while ((attr = state->theAttributes->next()) != NULL)
    {
      if (nameOrKindTest(theSctx, attr, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = attr;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = attr;
          STACK_PUSH(true, state);
        }
      }
    }

    state->theAttributes->close();
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
void ParentAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<ParentAxisIterator, ParentAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;

    result = state->theContextNode->getParent();

    if (result != NULL && nameOrKindTest(theSctx, result, loc))
    {
      if (theTargetPos < 1)
        STACK_PUSH(true, state);
    }
  }

  STACK_END (state);
}


/*******************************************************************************
  Returns the ancestors in document order (top-down)
********************************************************************************/
void AncestorAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<AncestorAxisIterator, AncestorAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;
    state->theAncestors.clear();

    ancestor = state->theContextNode->getParent();
    while (ancestor != NULL)
    {
      if (nameOrKindTest(theSctx, ancestor, loc))
        state->theAncestors.push_back(ancestor);

      ancestor = ancestor->getParent();
    }

    state->theCurrentAncPos = (long)state->theAncestors.size() - 1;

    while (state->theCurrentAncPos >= 0)
    {
      result = state->theAncestors[state->theCurrentAncPos--];
      STACK_PUSH(true, state);

      if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
        break;
    }

    state->theAncestors.clear();
  }

  STACK_END (state);
}


/*******************************************************************************
  Returns the ancestors in reverse document order (bottom-up)
********************************************************************************/
void AncestorReverseAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<AncestorReverseAxisIterator, AncestorReverseAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;

    ancestor = state->theContextNode->getParent();

    while (ancestor != NULL)
    {
      if (nameOrKindTest(theSctx, ancestor, loc))
      {
        state->theCurrentAnc = ancestor;

        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = ancestor;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = ancestor;
          STACK_PUSH(true, state);
        }

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
void AncestorSelfAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<AncestorSelfAxisIterator, AncestorAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;

    ancestor = state->theContextNode.getp();

    while (ancestor != NULL)
    {
      if (nameOrKindTest(theSctx, ancestor, loc))
      {
        state->theAncestors.push_back(ancestor);
      }
      ancestor = ancestor->getParent();
    }

    state->theCurrentAncPos = (long)state->theAncestors.size() - 1;

    while (state->theCurrentAncPos >= 0)
    {
      result = state->theAncestors[state->theCurrentAncPos--];
      STACK_PUSH(true, state);

      if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
        break;
    }

    state->theAncestors.clear();
  }

  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
void AncestorSelfReverseAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<AncestorSelfReverseAxisIterator, AncestorReverseAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    state->theCurrentPos = 0;

    state->theCurrentAnc = state->theContextNode;

    while (state->theCurrentAnc != NULL)
    {
      if (nameOrKindTest(theSctx, state->theCurrentAnc, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = state->theCurrentAnc;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = state->theCurrentAnc;
          STACK_PUSH(true, state);
        }
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


void RSiblingAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<RSiblingAxisIterator, SiblingAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


bool RSiblingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
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
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    state->theCurrentPos = 0;

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      continue;

    state->theChildren->init(parent, state->theContextNode.getp());
    state->theChildren->open();

    while ((sibling = state->theChildren->next()) != NULL)
    {
      if (nameOrKindTest(theSctx, sibling, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = sibling;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = sibling;
          STACK_PUSH(true, state);
        }
      }
    }

    state->theChildren->close();
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
void LSiblingAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<LSiblingAxisIterator, SiblingAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    state->theCurrentPos = 0;

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      continue;

    state->theChildren->init(parent);
    state->theChildren->open();

    while ((sibling = state->theChildren->next()) != NULL &&
           sibling != state->theContextNode.getp())
    {
      if (nameOrKindTest(theSctx, sibling, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = sibling;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = sibling;
          STACK_PUSH(true, state);
        }
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


void LSiblingReverseAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<LSiblingReverseAxisIterator, LSiblingReverseAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
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
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while (state->theContextNode->getNodeKind() == store::StoreConsts::attributeNode);

    state->theCurrentPos = 0;

    parent = state->theContextNode->getParent();

    if (parent == NULL)
      continue;

    state->theChildren->init(parent, state->theContextNode.getp());
    state->theChildren->open();

    while ((sibling = state->theChildren->next()) != NULL)
    {
      if (nameOrKindTest(theSctx, sibling, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = sibling;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = sibling;
          STACK_PUSH(true, state);
        }
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


void ChildAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<ChildAxisIterator, ChildAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
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
        goto done;
      
      if (!state->theContextNode->isNode())
      {
        //assert(false);
        throw XQUERY_EXCEPTION(err::XPTY0020, ERROR_LOC(loc));
      }
    }
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    state->theCurrentPos = 0;
    state->theChildren->init(state->theContextNode);
    state->theChildren->open();

    while ((child = state->theChildren->next()) != NULL)
    {
      if (nameOrKindTest(theSctx, child, loc))
      {
        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = child;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = child;
          STACK_PUSH(true, state);
        }
      }
    }

    state->theChildren->close();
  }

 done:
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
DescendantAxisState::~DescendantAxisState()
{
  ulong len = (ulong)theCurrentPath.size();
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

  clear();
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


void DescendantAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<DescendantAxisIterator, DescendantAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
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
        goto done;
      }

      if (!state->theContextNode->isNode())
      {
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while (!isElementOrDocumentNode(state->theContextNode.getp()));

    state->theCurrentPos = 0;

    state->push(state->theContextNode);

    desc = state->top()->next();

    while (desc != NULL)
    {
      if (nameOrKindTest(theSctx, desc, loc))
      {
        if (desc->getNodeKind() == store::StoreConsts::elementNode &&
            (desc->isRecursive() ||
             theTestKind == match_anykind_test ||
             (theTestKind == match_elem_test && theQName == NULL) ||
             (theTestKind == match_name_test && theWildKind != match_no_wild)))
        {
          state->push(desc);
        }

        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = desc;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = desc;
          STACK_PUSH(true, state);
        }
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

    state->clear();
  }

 done:
  STACK_END(state);
}


/*******************************************************************************

********************************************************************************/
void DescendantSelfAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<DescendantSelfAxisIterator, DescendantAxisState>*)this);

  AxisIteratorHelper::serialize(ar);
}


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
        goto done;

      if (!state->theContextNode->isNode())
      {
        assert(false);
        throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
      }
    }
    while ((theTestKind == match_name_test || theTestKind == match_no_test) &&
           !isElementOrDocumentNode(state->theContextNode.getp()));

    state->theCurrentPos = 0;

    desc = state->theContextNode.getp();

    while (desc != NULL)
    {
      descKind = desc->getNodeKind();

      if (nameOrKindTest(theSctx, desc, loc))
      {
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

        if (theTargetPos >= 0)
        {
          if (state->theCurrentPos++ == theTargetPos)
          {
            result = desc;
            STACK_PUSH(true, state);
            break;
          }
        }
        else
        {
          result = desc;
          STACK_PUSH(true, state);
        }
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

    state->clear();
  }

 done:
  STACK_END(state);
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


void PrecedingAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (AxisIterator<PrecedingAxisIterator, PrecedingAxisState>*)this);
}


bool PrecedingAxisIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* ancestor;
  const store::Item* child;
  const store::Item* desc;
  bool getNextContextNode = false;

  PrecedingAxisState* state;
  DEFAULT_STACK_INIT(PrecedingAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    getNextContextNode = false;

    state->theCurrentPos = 0;

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
    while (!getNextContextNode && state->theAncestorPath.size() > 1)
    {
      // Get the next ancestor A in the ancestors path and open an iterator
      // over its children.
      ancestor = state->theAncestorPath.back();
      state->theAncestorPath.pop_back();

      state->theAncestorChildren->init(ancestor);
      state->theAncestorChildren->open();

      // For each child C of A such that C is to the left of AC ...
      while ((child = state->theAncestorChildren->next()) != NULL &&
             child != state->theAncestorPath.back() &&
             !getNextContextNode)
      {
        // Special case: C is not element node, so there is no tree to travesre.
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(theSctx, child, loc))
          {
            if (theTargetPos >= 0)
            {
              if (state->theCurrentPos++ == theTargetPos)
              {
                result = child;
                STACK_PUSH(true, state);
                getNextContextNode = true;
                break;
              }
            }
            else
            {
              result = child;
              STACK_PUSH(true, state);
            }
          }

          continue;
        }

        // C is an element node; traverse its subtree, unless we can skip it
        // based on the non-recursiveness of C and the node test associated
        // with this axis step.
        desc = child;

        while (desc != NULL)
        {
          if (nameOrKindTest(theSctx, desc, loc))
          {
            if (desc->getNodeKind() == store::StoreConsts::elementNode &&
                (desc->isRecursive() ||
                 theTestKind == match_anykind_test ||
                 (theTestKind == match_elem_test && theQName == NULL) ||
                 (theTestKind == match_name_test && theWildKind != match_no_wild)))
            {
              state->push(desc);
            }

            if (theTargetPos >= 0)
            {
              if (state->theCurrentPos++ == theTargetPos)
              {
                result = desc;
                STACK_PUSH(true, state);
                getNextContextNode = true;
                break;
              }
            }
            else
            {
              result = desc;
              STACK_PUSH(true, state);
            }
          }
          else if (desc->getNodeKind() == store::StoreConsts::elementNode)
          {
            state->push(desc);
          }

          desc = NULL;

          while (!state->empty() && (desc = state->top()->next()) == NULL)
          {
            state->pop();
          }
        }

      } // For each child C of A such that C is to the left of AC ...

      state->theAncestorChildren->close();

    } // For each ancestor A of the current context node N ...

    state->clear();
  }

  STACK_END(state);
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

  ulong len = (ulong)theCurrentPath.size();
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


void PrecedingReverseAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (AxisIterator<PrecedingReverseAxisIterator, PrecedingReverseAxisState>*)this);
}


bool PrecedingReverseAxisIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  const store::Item* child;
  const store::Item* desc;
  bool getNextContextNode = false;

  PrecedingReverseAxisState* state;
  DEFAULT_STACK_INIT(PrecedingReverseAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      assert(false);
      throw XQUERY_EXCEPTION(err::XPTY0020, ERROR_LOC(loc));
    }

    getNextContextNode = false;

    state->theCurrentPos = 0;
    state->theAncestorChild = state->theContextNode.getp();
    state->theAncestor.first = state->theContextNode->getParent();

    // For each ancestor A of the current context node N (starting with N's parent)
    while (!getNextContextNode && state->theAncestor.first != NULL)
    {
      // Find the 1st child C of A such that C is to the left of the previous
      // ancestor (i.e. C is the left sibling of the previous ancestor).
      state->theAncestor.second->init(state->theAncestor.first,
                                      state->theAncestorChild);

      // For each child C of A such that C is to the left of the previous
      // ancestor, do a reverse traversal of the subtree T rooted at C.
      while (!getNextContextNode && (child = state->theAncestor.second->next()) != NULL)
      {
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(theSctx, child, loc))
          {
            result = child;
            STACK_PUSH(true, state);

            if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
              getNextContextNode = true;
          }

          continue;
        }

        if (nameOrKindTest(theSctx, child, loc))
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

            if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
              getNextContextNode = true;

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
          // Traverse all the subtrees of the node D that is at the top of
          // theCurrentPath.
          while (!getNextContextNode && (desc = state->top()->next()) != NULL)
          {
            if (desc->getNodeKind() == store::StoreConsts::elementNode)
            {
              if (nameOrKindTest(theSctx, desc, loc))
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

                  if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
                    getNextContextNode = true;
                }
              }
              else
              {
                state->push(desc); // recursive traversal
              }
            }
            else
            {
              if (nameOrKindTest(theSctx, desc, loc))
              {
                result = desc;
                STACK_PUSH(true, state);

                if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
                  getNextContextNode = true;
              }
            }
          }

          // We have traversed all the subtrees of the node D that is at the
          // top of theCurrentPath. Return D to the caller, if it satifies the
          // node test, and then pop D from theCurrentPath.
          if (!getNextContextNode && nameOrKindTest(theSctx, state->topNode(), loc))
          {
            result = state->topNode();
            STACK_PUSH(true, state);

            if (theTargetPos >= 0 && state->theCurrentPos++ == theTargetPos)
              getNextContextNode = true;
          }

          state->pop();
        }
        while (!getNextContextNode && !state->empty());
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


void FollowingAxisIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (AxisIterator<FollowingAxisIterator, FollowingAxisState>*)this);
}


bool FollowingAxisIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item* ancestor;
  const store::Item* child;
  const store::Item* desc;
  bool getNextContextNode = false;

  FollowingAxisState* state;
  DEFAULT_STACK_INIT(FollowingAxisState, state, planState);

  while (theTestKind != match_doc_test)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      break;

    if (!state->theContextNode->isNode())
    {
      assert(false);
      throw XQUERY_EXCEPTION( err::XPTY0020, ERROR_LOC( loc ) );
    }

    getNextContextNode = false;

    state->theCurrentPos = 0;

    // Collect the context node and its ancestors
    ancestor = state->theContextNode.getp();

    while (ancestor != NULL)
    {
      state->theAncestorPath.push_back(ancestor);
      ancestor = ancestor->getParent();
    }

    std::reverse(state->theAncestorPath.begin(), state->theAncestorPath.end());

    // For each ancestor A of the current context node N and for each child C
    // of A such as C is to the right of the next ancestor AC in the ancestor
    // path (note: AC is a child of A), traverse the subtree rooted at C.
    while (!getNextContextNode && state->theAncestorPath.size() > 1)
    {
      // Get the next ancestor A in the ancestors path and open an iterator
      // over its children, placing the iterator to the right of the next
      // ancestor AC in the ancestor path.
      ancestor = state->theAncestorPath.back();
      state->theAncestorPath.pop_back();

      state->theAncestorChildren->init(state->theAncestorPath.back().getp(), ancestor);
      state->theAncestorChildren->open();

      // For each child C of A such that C is to the right of AC ...
      while ((child = state->theAncestorChildren->next()) != NULL &&
             !getNextContextNode)
      {
        // Special case: C is not element node, so there is no tree to travesre.
        if (child->getNodeKind() != store::StoreConsts::elementNode)
        {
          if (nameOrKindTest(theSctx, child, loc))
          {
            if (theTargetPos >= 0)
            {
              if (state->theCurrentPos++ == theTargetPos)
              {
                result = child;
                STACK_PUSH(true, state);
                getNextContextNode = true;
                break;
              }
            }
            else
            {
              result = child;
              STACK_PUSH(true, state);
            }
          }

          continue;
        }

        // C is an element node; traverse its subtree, unless we can skip it
        // based on the non-recursiveness of C and the node test associated
        // with this axis step.
        desc = child;

        while (desc != NULL)
        {
          if (nameOrKindTest(theSctx, desc, loc))
          {
            if (desc->getNodeKind() == store::StoreConsts::elementNode &&
                (desc->isRecursive() ||
                 theTestKind == match_anykind_test ||
                 (theTestKind == match_elem_test && theQName == NULL) ||
                 (theTestKind == match_name_test && theWildKind != match_no_wild)))
            {
              state->push(desc);
            }

            if (theTargetPos >= 0)
            {
              if (state->theCurrentPos++ == theTargetPos)
              {
                result = desc;
                STACK_PUSH(true, state);
                getNextContextNode = true;
                break;
              }
            }
            else
            {
              result = desc;
              STACK_PUSH(true, state);
            }
          }
          else if (desc->getNodeKind() == store::StoreConsts::elementNode)
          {
            state->push(desc);
          }

          desc = NULL;

          while (!state->empty() && (desc = state->top()->next()) == NULL)
          {
            state->pop();
          }
        }
      } // For each child C of A such that C is to the right of AC ...

      state->theAncestorChildren->close();

    } // For each ancestor A of the current context node N ...

    state->clear();
  }

  STACK_END (state);
}


};
/* vim:set et sw=2 ts=2: */
