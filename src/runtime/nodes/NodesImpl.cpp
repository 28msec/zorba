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
 
#include "system/globalenv.h"
#include "runtime/nodes/NodesImpl.h"
#include "store/api/item_factory.h"

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
    if (inNode->getNodeKind() == store::StoreConsts::elementNode)
      STACK_PUSH(GENV_ITEMFACTORY->createString(inNode->getNodeName()->getLocalName().getStore()), state);
  }
  else
    STACK_PUSH(GENV_ITEMFACTORY->createString(strRes.getStore()), state);
  
  STACK_END();
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
    STACK_PUSH(GENV_ITEMFACTORY->createAnyURI(inNode->getNamespace().getStore()), state);

  STACK_END();
}

// 14.5 fn:lang
//---------------------
store::Item_t FnLangIterator::nextImpl(PlanState& planState) const
{
  //TODO fix the implementation
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  STACK_END();
}

} /* namespace zorba */
