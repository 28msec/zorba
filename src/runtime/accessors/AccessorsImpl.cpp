/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#include "store/api/item.h"
#include "store/api/iterator.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "runtime/accessors/AccessorsImpl.h"
#include "util/Assert.h"
#include "store/api/item_factory.h"
#include "context/namespace_context.h"

namespace zorba {

// 2.4 fn:data
//---------------------
FnDataIteratorState::FnDataIteratorState() {}

FnDataIteratorState::~FnDataIteratorState() {}

void FnDataIteratorState::init(PlanState& planState) 
{ 
  PlanIteratorState::init( planState );
  theTypedValue = NULL;
}

void FnDataIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset( planState );
  theTypedValue = NULL;
}


FnDataIterator::FnDataIterator (
    const QueryLoc& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<FnDataIterator, FnDataIteratorState> ( loc, childIter )
{
}

store::Item_t
FnDataIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  PlanIter_t iter;
  
  FnDataIteratorState* state;
  DEFAULT_STACK_INIT(FnDataIteratorState, state, planState);
  
  while (true) {
    item = consumeNext( theChild, planState );
    if (item == NULL)
      break;
    state->theTypedValue = item->getTypedValue();
    state->theTypedValue->open();
      
    while (true) {
      item = state->theTypedValue->next();
      if (item == NULL)
        break;
      ZORBA_ASSERT(!item->isNode());
      STACK_PUSH( item, state );
    }
  }
  state->theTypedValue = 0; // TODO remove???
  STACK_END (state);
}
  

// 14.9 fn:root
//---------------------
store::Item_t FnRootIterator::nextImpl(PlanState& planState) const
{
  store::Item_t contextNode;
  store::Item_t parentNode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  contextNode = consumeNext(theChildren[0].getp(), planState);

  if (contextNode == NULL)
    return NULL;

  if (!contextNode->isNode())
  {
    ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, "The argument of the fn:root function is not a node");
  }

  parentNode = contextNode->getParent();

  while (parentNode != NULL)
  {
    contextNode = parentNode;
    parentNode = parentNode->getParent();
  }

  STACK_PUSH(contextNode, state);
  STACK_END (state);
}

// 14.9 fn:node-name
//---------------------
store::Item_t FnNodeNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if( inNode->getNodeKind() == store::StoreConsts::elementNode ||
        inNode->getNodeKind() == store::StoreConsts::attributeNode)
      STACK_PUSH(inNode->getNodeName(), state);
    else if(inNode->getNodeKind() == store::StoreConsts::piNode)
      STACK_PUSH(
          GENV_ITEMFACTORY->createQName(xqp_string().getStore(),
                                        xqp_string().getStore(),
                                        inNode->getTarget()),
          state);
  }
  STACK_END (state);
}

// 2.2 fn:nilled
//---------------------
store::Item_t FnNilledIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  bool res;
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL && inNode->getNodeKind() == store::StoreConsts::elementNode)
  {
    res = (inNode->getParent() != NULL) ? inNode->getNilled() : false;
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(res), state);
  }
  
  STACK_END (state);
}

// 2.5 fn:base-uri
//---------------------
store::Item_t FnBaseUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t baseuri;
  bool          found = false;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if (inNode->isNode()) 
    {
      baseuri = inNode->getBaseURI();
      if (baseuri != NULL)
        STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(baseuri), state);
    }
    else
    {
      ZORBA_ERROR_LOC_DESC(ZorbaError::XPTY0004, loc,
                           "The argument of the fn:base-uri function is not a node");
    }
  }
  
  STACK_END (state);
}

// 2.6 fn:document-uri
//---------------------
store::Item_t FnDocumentUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if (!inNode->isNode())
      ZORBA_ERROR_LOC_DESC(ZorbaError::XPTY0004, loc,
                           "The argument of the fn:document-uri function is not a node");
    
    if(inNode->getNodeKind() == store::StoreConsts::documentNode)
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(inNode->getDocumentURI()), state);
  }
  
  STACK_END (state);
}


// 2.3 fn:string
//---------------------
store::Item_t FnStringIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inVal;
  xqpStringStore_t empty;

  FnStringIteratorState *state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while((inVal = consumeNext(theChildren[0].getp(), planState)) != NULL) {
    state->hasOutput = true;
    STACK_PUSH(GENV_ITEMFACTORY->createString(inVal->getStringValue()), state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) {
    state->hasOutput = true;
    empty = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(empty), state);
  }

  STACK_END (state);
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
