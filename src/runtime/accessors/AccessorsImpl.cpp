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
  
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if (inNode->isNode()) 
      STACK_PUSH(inNode->getNilled(), state);
    else
      ZORBA_ERROR_LOC_DESC(ZorbaError::XPTY0004, loc,
                           "The argument of the fn:nilled function is not a node");
  }
  
  STACK_END (state);
}

// 2.5 fn:base-uri
//---------------------
store::Item_t FnBaseUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t baseuri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    baseuri = inNode->getBaseURI();
    if (baseuri != NULL)
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(baseuri), state);
  }
  
  STACK_END (state);
}

// 2.6 fn:document-uri
//---------------------
store::Item_t FnDocumentUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t docuri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    docuri = inNode->getDocumentURI();
    if (docuri != NULL)
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(docuri), state);
  }
  
  STACK_END (state);
}


// 2.3 fn:string
//---------------------
store::Item_t FnStringIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inVal;
  xqpStringStore_t strval;

  FnStringIteratorState *state;
  DEFAULT_STACK_INIT(FnStringIteratorState, state, planState);

  while((inVal = consumeNext(theChildren[0], planState)) != NULL) 
  {
    state->hasOutput = true;
    strval = inVal->getStringValue();
    STACK_PUSH(GENV_ITEMFACTORY->createString(strval), state);
  }

  if (!state->hasOutput && theEmptyStringOnNULL) 
  {
    state->hasOutput = true;
    strval = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(strval), state);
  }

  STACK_END (state);
}

} /* namespace zorba */
/* vim:set ts=2 sw=2: */
