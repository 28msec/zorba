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
#include <vector>

#include "zorbaerrors/Assert.h"
#include "system/globalenv.h"
#include "runtime/nodes/NodesImpl.h"
#include "store/api/item_factory.h"

#include "runtime/context/ContextImpl.h"
#include "runtime/api/runtimecb.h"
#include "runtime/util/iterator_impl.h"
#include "context/dynamic_context.h"
#include "context/namespace_context.h"

#include "store/api/store.h"
#include "store/api/collection.h"
#include "store/api/iterator.h"

using namespace std;

namespace zorba {

store::Item_t NodeReferenceIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0], planState);
  assert(inNode != NULL);

  STACK_PUSH(GENV_STORE.getReference(inNode), state);
  STACK_END(state);
}


store::Item_t NodeByReferenceIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inUri;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inUri = consumeNext(theChildren[0], planState);
  assert(inUri != NULL);

  STACK_PUSH(GENV_STORE.getNodeByReference(inUri), state);
  STACK_END (state);
}


// 14.2 fn:local-name
//---------------------
store::Item_t FnLocalNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t strRes;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0], planState);

  if (inNode != NULL)
  {
    if(inNode->getNodeKind() == store::StoreConsts::documentNode ||
       inNode->getNodeKind() == store::StoreConsts::commentNode ||
       inNode->getNodeKind() == store::StoreConsts::textNode)
    {
      strRes = new xqpStringStore("");
    }
    else if(inNode->getNodeKind() == store::StoreConsts::piNode)
    {
      strRes = inNode->getTarget();
    }
    else
    {
      strRes = inNode->getNodeName()->getLocalName();
    }

    STACK_PUSH(GENV_ITEMFACTORY->createString(strRes), state);
  }
  else
  {
    strRes = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(strRes), state);
  }

  STACK_END (state);
}


// 14.3 fn:namespace-uri
//---------------------
store::Item_t FnNamespaceUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t uriStr;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if(inNode->getNodeKind() == store::StoreConsts::elementNode ||
       inNode->getNodeKind() == store::StoreConsts::attributeNode)
    {
      uriStr = inNode->getNodeName()->getNamespace();
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(uriStr), state);
    }
    else
    {
      uriStr = new xqpStringStore("");
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(uriStr), state);
    }
  }

  STACK_END (state);
}

// 14.5 fn:lang
//---------------------
store::Item_t FnLangIterator::nextImpl(PlanState& planState) const
{
  store::Item_t     item, node, attr;
  store::Item*      attrName;
  store::Iterator_t theAttributes;
  bool              found = false;
  xqpStringStore_t  reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(NULL != (item = CONSUME(0)))
  {
    reqLang = item->getStringValue().getp();
    
    for(node = CONSUME(1);
        NULL != node && node->getNodeKind () == store::StoreConsts::elementNode && ! found;
        node = node->getParent())
    {
      for ((theAttributes = node->getAttributes())->open ();
           ! found && NULL != (attr = theAttributes->next()); )
      {
        attrName = attr->getNodeName();
        found = (attrName->getLocalName()->byteEqual("lang", 4) &&
                 attrName->getNamespace()->byteEqual(XML_NS, strlen(XML_NS)) &&
                 xqp_string(attr->getStringValue()).matches(xqp_string("^" + reqLang->str() + "(-|$)"), "i"));
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(found), state);
  
  STACK_END (state);
}

// 15.5.6 fn:collection
//---------------------
void
FnCollectionIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theIterator = NULL;
}

void
FnCollectionIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theIterator = NULL;
}

store::Item_t FnCollectionIterator::nextImpl(PlanState& planState) const
{
  store::Item_t       itemArg;
  store::Item_t       itemColl;
  xqp_string          uri;
  store::Collection_t theColl;
  
  FnCollectionIteratorState *state;
  DEFAULT_STACK_INIT(FnCollectionIteratorState, state, planState);

  if (theChildren.size() == 1 && (itemArg = consumeNext(theChildren[0].getp(), planState)) != NULL) 
    uri = itemArg->getStringValue().getp();
  else
  {
    uri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(uri.empty())
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
                           "Default collection is undefined in the dynamic context.");
  }

  theColl = GENV_STORE.getCollection(uri.getStore());

  if(theColl == NULL)
    ZORBA_ERROR_LOC_DESC(FODC0004, loc, "Invalid argument to fn:collection.");

  state->theIterator = theColl->getIterator(false);
  ZORBA_ASSERT(state->theIterator!=NULL);
  state->theIterator->open();
  
  while((itemColl = state->theIterator->next()) != NULL )
    STACK_PUSH (itemColl, state);

  STACK_END (state);
}

} /* namespace zorba */
