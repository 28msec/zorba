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

#include "runtime/core/path.h"

#ifdef PATH_ITERATOR

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

#include "system/globalenv.h"
#include "context/static_context.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/typemanager.h"

#include "store/api/item.h"
#include "store/api/iterator_factory.h"


namespace zorba
{

static inline bool isElementOrDocumentNode(const store::Item* node)
{
  assert(node->isNode());
  store::StoreConsts::NodeKind kind = node->getNodeKind();
  return (kind == store::StoreConsts::elementNode ||
          kind == store::StoreConsts::documentNode);
}


/*******************************************************************************

********************************************************************************/
bool NodePredicate::apply(
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
AttributeStepState::AttributeStepState()
{
  theAttributes = GENV_ITERATOR_FACTORY->createAttributesIterator();
}


void AttributeStepState::reset()
{
  if (theAttributes != NULL)
    theAttributes->reset();
}


/*******************************************************************************

********************************************************************************/
SiblingStepState::SiblingStepState()
{
  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void SiblingStepState::reset()
{
  if (theChildren != NULL)
    theChildren->reset();
}


/*******************************************************************************

********************************************************************************/
ChildStepState::ChildStepState()
{
  theChildren = GENV_ITERATOR_FACTORY->createChildrenIterator();
}


void ChildStepState::reset()
{
  if (theChildren != NULL)
    theChildren->reset();
}


/*******************************************************************************

********************************************************************************/
DescendantStepState::~DescendantStepState()
{
  ulong len = theCurrentPath.size();
  for (ulong i = 0; i < len; i++)
  {
    delete theCurrentPath[i].second;
  }
}


void DescendantStepState::push(store::Item* node)
{
  if (theTop < theCurrentPath.size())
  {
    theCurrentPath[theTop].first = node;
    store::Item_t tmp = node;
    theCurrentPath[theTop].second->init(tmp);
  }
  else
  {
    store::ChildrenIterator* ite = GENV_ITERATOR_FACTORY->createChildrenIterator();;
    store::Item_t tmp = node;
    ite->init(tmp);
    theCurrentPath.push_back(std::pair<store::Item*, store::ChildrenIterator*>
                             (node, ite));
  }

  theTop++;
}


/*******************************************************************************

********************************************************************************/
PathIteratorState::~PathIteratorState()
{
  ulong numSteps = theStepStates.size();
  for (ulong i = 0; i < numSteps; i++)
    delete theStepStates[i];
}


void PathIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
}


void PathIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  theCurrentStep = 0;

  for (ulong i = 0; i < theNumSteps; i++)
    theStepStates[i]->reset();
}


/*******************************************************************************

********************************************************************************/
PathIterator::~PathIterator() 
{
  ulong numSteps = theAxes.size();
  for (ulong i = 0; i < numSteps; i++)
    delete theNodePreds[i];
}


void PathIterator::addStep(axis_kind_t axis, NodePredicate* prd)
{
  theAxes.push_back(axis);
  theNodePreds.push_back(prd);
}


void PathIterator::openImpl(PlanState& planState, uint32_t& offset) 
{
  UnaryBaseIterator<PathIterator, PathIteratorState>::openImpl(planState, offset);

  PathIteratorState* state;
  state = StateTraitsImpl<PathIteratorState>::getState(planState, this->stateOffset);

  ulong numSteps = theAxes.size();
  state->theNumSteps = numSteps;
  state->theStepStates.resize(numSteps);

  for (ulong i = 0; i < numSteps; i++)
  {
    switch (theAxes[i])
    {
    case axis_kind_self:
      state->theStepStates[i] = new SelfStepState;
      break;
    case axis_kind_attribute:
      state->theStepStates[i] = new AttributeStepState;
      break;
    case axis_kind_parent:
      state->theStepStates[i] = new ParentStepState;
      break;
    case axis_kind_ancestor:
      state->theStepStates[i] = new AncestorStepState;
      break;
    case axis_kind_ancestor_or_self:
      state->theStepStates[i] = new AncestorStepState;
      break;
    case axis_kind_following_sibling:
      state->theStepStates[i] = new SiblingStepState;
      break;
    case axis_kind_preceding_sibling:
      state->theStepStates[i] = new SiblingStepState;
      break;
    case axis_kind_child:
      state->theStepStates[i] = new ChildStepState;
      break;
    case axis_kind_descendant:
      state->theStepStates[i] = new DescendantStepState;
      break;
    case axis_kind_descendant_or_self:
      state->theStepStates[i] = new DescendantStepState;
      break;
    case axis_kind_following:
      break;
    case axis_kind_preceding:
      break;
    default:
      ZORBA_FATAL(0, "");
    }
  }
}


bool PathIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ulong curStep;
  axis_kind_t curAxis;
  NodePredicate* curPred;
  store::Item* curResult;

  PathIteratorState* state;
  DEFAULT_STACK_INIT(PathIteratorState, state, planState);

  while (1)
  {
    if (!consumeNext(state->theContextNode, theChild.getp(), planState))
      return false;

    if (!state->theContextNode->isNode())
    {
      ZORBA_ERROR_LOC_DESC(XPTY0020, loc,
                           "The context item of an axis step is not a node");
    }

    assert(state->theCurrentStep == 0);

    state->theStepStates[0]->theContextNode = state->theContextNode;
    state->theStepStates[0]->theStart = true;

    while (state->theCurrentStep < state->theNumSteps)
    {
      curStep = state->theCurrentStep;
      curAxis = theAxes[curStep];
      curPred = theNodePreds[curStep];
      curResult = NULL;

      switch (curAxis)
      {
      case axis_kind_self:
      {
        break;
      }
      case axis_kind_attribute:
      {
        AttributeStepState* curState = reinterpret_cast<AttributeStepState*>
                                       (state->theStepStates[curStep]);
        if (curState->theStart)
        {
          store::Item_t tmp(curState->theContextNode);
          curState->theAttributes->init(tmp);
          curState->theAttributes->open();
          curState->theStart = false;
        }

        while ((curResult = curState->theAttributes->next()) != NULL)
        {
          if (curPred->apply(curResult, planState))
            break;
        }

        if (curResult == NULL)
          curState->theAttributes->close();

        break;
      }
      case axis_kind_parent:
      {
        break;
      }
      case axis_kind_ancestor:
      {
        break;
      }
      case axis_kind_ancestor_or_self:
      {
        break;
      }
      case axis_kind_following_sibling:
      {
        break;
      }
      case axis_kind_preceding_sibling:
      {
        break;
      }
      case axis_kind_child:
      {
        ChildStepState* curState = reinterpret_cast<ChildStepState*>
                                   (state->theStepStates[curStep]);
        if (curState->theStart)
        {
          if (!isElementOrDocumentNode(curState->theContextNode))
            break;

          store::Item_t tmp(curState->theContextNode);
          curState->theChildren->init(tmp);
          curState->theChildren->open();
          curState->theStart = false;
        }

        while ((curResult = curState->theChildren->next()) != NULL)
        {
          if (curPred->apply(curResult, planState))
            break;
        }

        if (curResult == NULL)
          curState->theChildren->close();

        break;
      }
      case axis_kind_descendant:
      {
        DescendantStepState* curState = reinterpret_cast<DescendantStepState*>
                                        (state->theStepStates[curStep]);
        if (curState->theStart)
        {
          if (!isElementOrDocumentNode(curState->theContextNode))
            break;

          curState->push(curState->theContextNode);
          curState->theStart = false;
        }

        while(true) 
        {
          // The next descendant is the next child of the node N that is currently
          // at the top of the path stack. If N has no children or all of its
          // children have been processed already, N is removed from the stack
          // and the process is repeated.

          while ((curResult = curState->top()->next()) == NULL)
          {
            curState->pop();
            if (curState->empty())
              break;
          }

          if (curResult == NULL)
            break;

          if (curResult->getNodeKind() == store::StoreConsts::elementNode)
            curState->push(curResult);

          if (curPred->apply(curResult, planState))
            break;
        }
        break;
      }
      case axis_kind_descendant_or_self:
      {
        break;
      }
      case axis_kind_following:
      {
        break;
      }
      case axis_kind_preceding:
      {
        break;
      }
      default:
        ZORBA_FATAL(0, "");
      }

      if (curResult == NULL)
      {
        if (curStep > 0)
          state->theCurrentStep--;
        else
          break;
      }
      else if (curStep < state->theNumSteps - 1)
      {
        curStep++;
        state->theCurrentStep = curStep;
        state->theStepStates[curStep]->theContextNode = curResult;
        state->theStepStates[curStep]->theStart = true;
      }
      else
      {
        result = curResult;
        STACK_PUSH(true, state);
      }
    }
  }

  STACK_END(state);
}


#if 0
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
#endif

};

#endif
