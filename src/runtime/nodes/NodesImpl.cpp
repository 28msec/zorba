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
#include "context/static_context.h"
#include "context/internal_uri_resolvers.h"
#include "context/namespace_context.h"

#include "store/api/store.h"
#include "store/api/collection.h"
#include "store/api/iterator.h"

using namespace std;

namespace zorba {

bool NodeReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState *state;
  bool valid;
  store::Item_t inNode;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inNode, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getReference(result, inNode), state);
  STACK_END(state);
}


bool NodeByReferenceIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inUri;
  bool valid;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valid = consumeNext(inUri, theChildren[0], planState);
  assert(valid);

  STACK_PUSH(GENV_STORE.getNodeByReference(result, inUri), state);
  STACK_END (state);
}


// 14.2 fn:local-name
//---------------------
bool FnLocalNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t strRes;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0], planState))
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

    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }
  else
  {
    strRes = new xqpStringStore("");
    STACK_PUSH(GENV_ITEMFACTORY->createString(result, strRes), state);
  }

  STACK_END (state);
}


// 14.3 fn:namespace-uri
//---------------------
bool FnNamespaceUriIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t inNode;
  xqpStringStore_t uriStr;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(inNode, theChildren[0].getp(), planState))
  {
    if(inNode->getNodeKind() == store::StoreConsts::elementNode ||
       inNode->getNodeKind() == store::StoreConsts::attributeNode)
    {
      uriStr = inNode->getNodeName()->getNamespace();
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, uriStr), state);
    }
    else
    {
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(result, ""), state);
    }
  }

  STACK_END (state);
}

// 14.5 fn:lang
//---------------------
bool FnLangIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t     item, node, attr;
  store::Item*      attrName;
  store::Iterator_t theAttributes;
  bool              found = false;
  xqpStringStore_t  reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(CONSUME(item, 0))
  {
    reqLang = item->getStringValue().getp();
    
    if (CONSUME(node, 1)) {
      for(;
        NULL != node && node->getNodeKind () == store::StoreConsts::elementNode && ! found;
        node = node->getParent())
      {
        for ((theAttributes = node->getAttributes())->open ();
             ! found && theAttributes->next(attr); )
        {
          attrName = attr->getNodeName();
          found = (attrName->getLocalName()->byteEqual("lang", 4) &&
                   attrName->getNamespace()->byteEqual(XML_NS, strlen(XML_NS)) &&
                   xqp_string(attr->getStringValue()).matches(xqp_string("^" + reqLang->str() + "(-|$)"), "i"));
        }
      }
    }
  }

  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, found), state);
  
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

bool FnCollectionIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t       lURI;
  store::Collection_t theColl;
  
  FnCollectionIteratorState *state;
  DEFAULT_STACK_INIT(FnCollectionIteratorState, state, planState);

  if (theChildren.size() == 1 && consumeNext(lURI, theChildren[0].getp(), planState)) {
  } else {
    lURI = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(lURI->getStringValue()->empty())
      ZORBA_ERROR_LOC_DESC(FODC0002, loc,
                           "Default collection is undefined in the dynamic context.");
  }

  theColl =  planState.sctx()->get_collection_uri_resolver()->resolve(lURI, planState.sctx()); 

  if(theColl == NULL)
    ZORBA_ERROR_LOC_DESC_OSS(FODC0004, loc, "The collection could not be found: " << lURI->getStringValue());

  /** return the nodes of the collection */
  state->theIterator = theColl->getIterator(false);
  ZORBA_ASSERT(state->theIterator!=NULL);
  state->theIterator->open();
  
  while(state->theIterator->next(result))
    STACK_PUSH (true, state);

  STACK_END (state);
}

} /* namespace zorba */
