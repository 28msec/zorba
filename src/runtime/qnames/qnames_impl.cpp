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
#include "system/globalenv.h"

#include "context/static_context.h"

#include "types/typemanager.h"
#include "types/casting.h"

#include "compiler/api/compilercb.h"

#include "runtime/qnames/qnames.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/planiter_visitor.h"

#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "store/api/item.h"


namespace zorba {
#define GENV_GCAST (*GenericCast::instance ())

//11.1.1 fn:resolve-QName
bool
ResolveQNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemQName;
  store::Item_t itemElem;
  xqpStringStore_t qname;
  xqpStringStore_t resNs;
  xqpStringStore_t resPre;
  xqpStringStore_t resLocal;
  int32_t index = -1;
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > NamespaceBindings;
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > ::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemQName, theChild0.getp(), planState )) {
    itemQName = itemQName->getAtomizationValue();

    qname = itemQName->getStringValue()->trim();
    index = qname->indexOf(":");

    if(-1 != index) {
      resPre = new xqpStringStore(qname->str().substr(0, index));
      resLocal = new xqpStringStore(qname->str().substr(index+1, qname->bytes() - index));

      // must check for FOCA0002 first
      if (!GENV_GCAST.castableToNCName (resPre) || ! GENV_GCAST.castableToNCName (resLocal))
        ZORBA_ERROR_LOC (FOCA0002, loc);
    } else {
      resNs = new xqpStringStore("");
      resPre = new xqpStringStore("");
      resLocal = qname;
      if (! GENV_GCAST.castableToNCName (resLocal))
        ZORBA_ERROR_LOC (FOCA0002, loc);
    }
      
      if (consumeNext(itemElem, theChild1, planState )) 
      {
        itemElem->getNamespaceBindings(NamespaceBindings);
        for (iter = NamespaceBindings.begin();
             iter != NamespaceBindings.end();
             ++iter)
          {
          if ((*iter).first->byteEqual(*resPre)) {
            resNs = (*iter).second;
            break;
          }
          }
        if (resNs == NULL)
          ZORBA_ERROR_LOC (FONS0004, loc);
      }

    GENV_ITEMFACTORY->createQName(result, resNs, resPre, resLocal);

    STACK_PUSH(true, state );
  }
  STACK_END (state);
}


//11.1.2 fn:QName
bool
QNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemURI;
  store::Item_t itemQName;
  xqpStringStore_t qname;
  xqpStringStore_t resNs;
  xqpStringStore_t resPre;
  xqpStringStore_t resLocal;
  int32_t index = -1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChild0.getp(), planState )) {
    itemURI = itemURI->getAtomizationValue();
    resNs = itemURI->getStringValue()->trim();
  } else {
    resNs = new xqpStringStore("");
  }

  consumeNext(itemQName, theChild1.getp(), planState );
  itemQName = itemQName->getAtomizationValue();
  qname = itemQName->getStringValue()->trim();
  
  index = qname->indexOf(":");

  if( -1 != index ) {
    if (resNs->empty ())
      ZORBA_ERROR_LOC (FOCA0002, loc);

    resPre = new xqpStringStore(qname->str().substr(0, index));
    resLocal = new xqpStringStore(qname->str().substr(index+1, qname->bytes() - index));
  } else {
    resPre = new xqpStringStore("");
    resLocal = qname;
  }
  
  if ((index != -1 && ! GENV_GCAST.castableToNCName (resPre))
      || ! GENV_GCAST.castableToNCName (resLocal))
    ZORBA_ERROR_LOC (FOCA0002, loc);

  GENV_ITEMFACTORY->createQName(result, resNs, resPre, resLocal);
  STACK_PUSH(true, state );
  STACK_END (state);
}

//11.2.1 op:QName-equal
bool
QNameEqualIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t arg1;
  store::Item_t arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(arg1, theChild0.getp(), planState ))
  {
    if (consumeNext(arg2, theChild1.getp(), planState ))
    {
      arg1 = arg1->getAtomizationValue();
      arg2 = arg2->getAtomizationValue();

      if(arg1->getLocalName()->equals(arg2->getLocalName()))
      {
        if((arg1->getNamespace()->empty() && arg2->getNamespace()->empty()) ||
           (arg1->getNamespace()->equals(arg2->getNamespace())))
          GENV_ITEMFACTORY->createBoolean(result, true);
        else
          GENV_ITEMFACTORY->createBoolean(result, false);
      }
      else
        GENV_ITEMFACTORY->createBoolean(result, false);

      STACK_PUSH(true, state );
    }
  }
  STACK_END (state);
}


//11.2.2 fn:prefix-from-QName
bool
PrefixFromQNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore* pre;
  xqpStringStore_t preh;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState))
  {
    pre = item->getPrefix();
    if(!pre->empty())
    {
      preh = pre;
      STACK_PUSH( GENV_ITEMFACTORY->createNCName(result, preh), state );
    }
  }
  STACK_END (state);
}

//11.2.3 fn:local-name-from-QName
bool
LocalNameFromQNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  xqpStringStore_t localName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  if (consumeNext(item, theChild.getp(), planState))
  {
    localName = item->getLocalName();
    STACK_PUSH(GENV_ITEMFACTORY->createNCName(result, localName), state);
  }
  STACK_END (state);
}

//11.2.4 fn:namespace-uri-from-QName
bool
NamespaceUriFromQNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t item;
  xqpStringStore_t ns;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState))
  {
    ns = item->getNamespace();
    STACK_PUSH( GENV_ITEMFACTORY->createAnyURI(result, ns), state );
  }
  STACK_END (state);
}

//11.2.5 fn:namespace-uri-for-prefix
bool
NamespaceUriForPrefixIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemPrefix, itemElem;
  xqpStringStore_t resNs;
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > NamespaceBindings;
  std::vector<std::pair<xqpStringStore_t, xqpStringStore_t> > ::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(itemPrefix, theChildren[0].getp(), planState ))
    resNs = theSctx->default_elem_type_ns().getStore();
  else {
    if (!consumeNext(itemElem, theChildren[1].getp(), planState ))
      resNs = theSctx->default_elem_type_ns().getStore();
    else {
      itemElem->getNamespaceBindings(NamespaceBindings);
      for (
            iter = NamespaceBindings.begin();
            iter != NamespaceBindings.end();
            ++iter
          )
      {
        if( (*iter).first->byteEqual(*itemPrefix->getStringValue()->trim())) {
          resNs = (*iter).second;
          break;
        }
      }
    }
  }

  if( resNs != NULL && !resNs->empty() )
    STACK_PUSH( GENV_ITEMFACTORY->createString(result, resNs), state );

  STACK_END (state);
}

//11.2.6 fn:in-scope-prefixes
void InScopePrefixesIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theBindings.clear();
  theCurrentPos = 0;
}

void InScopePrefixesIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theBindings.clear();
  theCurrentPos = 0;
}

bool
InScopePrefixesIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemElem;
  xqpStringStore_t ncname = new xqpStringStore ("xml");

  InScopePrefixesIteratorState* state;
  DEFAULT_STACK_INIT(InScopePrefixesIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createNCName(result, ncname), state);

  if (consumeNext(itemElem, theChild.getp(), planState ))
  {
    itemElem->getNamespaceBindings(state->theBindings);
    while (state->theCurrentPos < state->theBindings.size())
    {
      ncname = state->theBindings[state->theCurrentPos].first;
      STACK_PUSH(GENV_ITEMFACTORY->createNCName(result, ncname), state);
      state->theCurrentPos++;
    }
  }

  STACK_END (state);
}

} /* namespace zorba */
