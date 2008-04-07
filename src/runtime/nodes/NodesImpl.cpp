/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file misc/MiscImpl.cpp
 *
 */

#include <vector>

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

// 14.2 fn:local-name
//---------------------
store::Item_t FnLocalNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;
  xqp_string strRes = "";

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if(inNode->getNodeKind() == store::StoreConsts::documentNode ||
       inNode->getNodeKind() == store::StoreConsts::commentNode ||
       inNode->getNodeKind() == store::StoreConsts::textNode)
      STACK_PUSH(GENV_ITEMFACTORY->createString(strRes.getStore()), state);
    else if(inNode->getNodeKind() == store::StoreConsts::piNode)
      STACK_PUSH(GENV_ITEMFACTORY->createString(inNode->getTarget().getStore()), state);
    else
      STACK_PUSH(GENV_ITEMFACTORY->createString(inNode->getNodeName()->getLocalName().getStore()), state);
  }
  else
    STACK_PUSH(GENV_ITEMFACTORY->createString(strRes.getStore()), state);
  
  STACK_END (state);
}

// 14.3 fn:namespace-uri
//---------------------
store::Item_t FnNamespaceUriIterator::nextImpl(PlanState& planState) const
{
  store::Item_t inNode;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  inNode = consumeNext(theChildren[0].getp(), planState);

  if (inNode != NULL)
  {
    if(inNode->getNodeKind() == store::StoreConsts::elementNode ||
       inNode->getNodeKind() == store::StoreConsts::attributeNode)
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(inNode->getNodeName()->getNamespace().getStore()), state);
    else
      STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(xqp_string().getStore()), state);
  }

  STACK_END (state);
}

// 14.5 fn:lang
//---------------------
store::Item_t FnLangIterator::nextImpl(PlanState& planState) const
{
  store::Item_t   item, node, attr, attrName;
  Iterator_t      theAttributes;
  bool            found = false;
  xqp_string      reqLang;

  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if(NULL != (item = CONSUME(0)))
  {
    reqLang = item->getStringValue().getp();
    
    for(node = CONSUME(1); NULL != node && !found; node = node->getParent() )
    {
      theAttributes = node->getAttributes();
      theAttributes->open();
    
      for ((theAttributes = node->getAttributes())->open ();
           ! found && NULL != (attr = theAttributes->next()); )
      {
        attrName = attr->getNodeName();
        found = xqp_string (attrName->getLocalName ()) == "lang"
          && xqp_string (attrName->getNamespace ()) == XML_NS
          && xqp_string(attr->getStringValue()).matches(xqp_string("^") + reqLang + "(-|$)", "i");
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

  itemArg = consumeNext(theChildren[0].getp(), planState);
  if (itemArg != NULL)
    uri = itemArg->getStringValue().getp();
  else
  {
    uri = planState.theRuntimeCB->theDynamicContext->get_default_collection();
    if(uri.empty())
      ZORBA_ERROR_LOC_DESC(ZorbaError::FODC0002, loc,
                           "Default collection is undefined in the dynamic context.");
  }

  theColl = GENV_STORE.getCollection(uri.getStore());

  if(theColl == NULL)
    ZORBA_ERROR_LOC_DESC(ZorbaError::FODC0004, loc,
                         "Invalid argument to fn:collection.");

  state->theIterator = theColl->getIterator(false);
  
  while((itemColl = state->theIterator->next()) != NULL )
    STACK_PUSH (itemColl, state);

  STACK_END (state);
}

} /* namespace zorba */
