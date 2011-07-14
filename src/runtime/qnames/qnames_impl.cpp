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

#include "system/globalenv.h"

#include "context/static_context.h"

#include "types/typemanager.h"
#include "types/casting.h"

#include "compiler/api/compilercb.h"

#include "runtime/qnames/qnames.h"
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
  zstring qname;
  zstring resNs;
  zstring resPre;
  zstring resLocal;
  zstring::size_type index;
  store::NsBindings NamespaceBindings;
  store::NsBindings::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemQName, theChild0.getp(), planState )) 
  {
    itemQName->getStringValue2(qname);

    ascii::trim_whitespace(qname);

    index = qname.find(":", 0, 1);

    if (index != zstring::npos) 
    {
      resPre = qname.substr(0, index);
      resLocal = qname.substr(index+1, qname.size() - index);

      // must check for FOCA0002 first
      if (!GENV_GCAST.castableToNCName(resPre) || ! GENV_GCAST.castableToNCName(resLocal))
        throw XQUERY_EXCEPTION(
          err::FOCA0002, ERROR_PARAMS( qname ), ERROR_LOC(loc)
        );
    } 
    else
    {
      resLocal = qname;

      if (! GENV_GCAST.castableToNCName(resLocal))
        throw XQUERY_EXCEPTION(
          err::FOCA0002, ERROR_PARAMS( qname ), ERROR_LOC(loc)
        );
    }
      
    if (consumeNext(itemElem, theChild1, planState )) 
    {
      itemElem->getNamespaceBindings(NamespaceBindings);

      bool found = false;

      for (iter = NamespaceBindings.begin();
           iter != NamespaceBindings.end();
           ++iter)
      {
        if ((*iter).first == resPre)
        {
          resNs = (*iter).second;
          found = true;
          break;
        }
      }

      if (!found && !resPre.empty())
        throw XQUERY_EXCEPTION(
          err::FONS0004, ERROR_PARAMS( resPre ), ERROR_LOC( loc )
        );
    }
    
    GENV_ITEMFACTORY->createQName(result, resNs, resPre, resLocal);

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


//11.1.2 fn:QName
bool QNameIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t itemURI;
  store::Item_t itemQName;
  zstring qname;
  zstring resNs;
  zstring resPre;
  zstring resLocal;
  zstring::size_type index;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(itemURI, theChild0.getp(), planState )) 
  {
    itemURI->getStringValue2(resNs);

    ascii::trim_whitespace(resNs);
  }

  consumeNext(itemQName, theChild1.getp(), planState );

  itemQName->getStringValue2(qname);
  
  ascii::trim_whitespace(qname);

  index = qname.find(":", 0, 1);

  if (index != zstring::npos) 
  {
    if (resNs.empty())
      throw XQUERY_EXCEPTION(
        err::FOCA0002, ERROR_PARAMS( resNs ), ERROR_LOC(loc)
      );

    resPre = qname.substr(0, index);
    resLocal = qname.substr(index+1, qname.size() - index);
  } 
  else
  {
    resLocal = qname;
  }
  
  if ((index != zstring::npos && ! GENV_GCAST.castableToNCName(resPre)) ||
      ! GENV_GCAST.castableToNCName(resLocal))
  {
    throw XQUERY_EXCEPTION(
      err::FOCA0002, ERROR_PARAMS( qname ), ERROR_LOC(loc)
    );
  }

  GENV_ITEMFACTORY->createQName(result, resNs, resPre, resLocal);

  STACK_PUSH(true, state);
  STACK_END(state);
}


//11.2.1 op:QName-equal
bool QNameEqualIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t arg1;
  store::Item_t arg2;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(arg1, theChild0.getp(), planState ))
  {
    if (consumeNext(arg2, theChild1.getp(), planState ))
    {
      if(arg1->getLocalName() == arg2->getLocalName())
      {
        if (arg1->getNamespace() == arg2->getNamespace())
          GENV_ITEMFACTORY->createBoolean(result, true);
        else
          GENV_ITEMFACTORY->createBoolean(result, false);
      }
      else
      {
        GENV_ITEMFACTORY->createBoolean(result, false);
      }

      STACK_PUSH(true, state );
    }
  }
  STACK_END (state);
}


//11.2.2 fn:prefix-from-QName
bool PrefixFromQNameIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::Item_t item;
  zstring tmp;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (consumeNext(item, theChild.getp(), planState))
  {
    if(!item->getPrefix().empty())
    {
      tmp = item->getPrefix();
      STACK_PUSH( GENV_ITEMFACTORY->createNCName(result, tmp), state );
    }
  }
  STACK_END (state);
}


//11.2.3 fn:local-name-from-QName
bool LocalNameFromQNameIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const 
{
  store::Item_t item;
  zstring localName;

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
bool NamespaceUriFromQNameIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const 
{
  store::Item_t item;
  zstring ns;

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
bool NamespaceUriForPrefixIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t itemPrefix, itemElem;
  zstring resNs;
  bool found = false;
  store::NsBindings NamespaceBindings;
  store::NsBindings::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

//  According to W3C bug #11590 comment #9
//  http://www.w3.org/Bugs/Public/show_bug.cgi?id=11590#c9
//  namespace-uri-for-prefix('', <a/>)
//  and
//  namespace-uri-for-prefix((), <a/>)
//  should return the empty sequence
  if(consumeNext(itemPrefix, theChildren[0].getp(), planState )) 
  {
    if (!consumeNext(itemElem, theChildren[1].getp(), planState ))
    {
      ZORBA_ASSERT(false);
    }
    else 
    {
      itemElem->getNamespaceBindings(NamespaceBindings);

      for (iter = NamespaceBindings.begin();
           iter != NamespaceBindings.end();
           ++iter)
      {
        zstring pre;
        itemPrefix->getStringValue2(pre);

        ascii::trim_whitespace(pre);

        if ((*iter).first == pre)
        {
          resNs = (*iter).second;
          found = true;
          break;
        }
      }
    }
  }

  if (found)
  {
    STACK_PUSH( GENV_ITEMFACTORY->createString(result, resNs), state );
  }

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
  zstring ncname("xml");

  InScopePrefixesIteratorState* state;
  DEFAULT_STACK_INIT(InScopePrefixesIteratorState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createNCName(result, ncname), state);

  if (consumeNext(itemElem, theChild.getp(), planState ))
  {
    itemElem->getNamespaceBindings(state->theBindings);
    while (state->theCurrentPos < state->theBindings.size())
    {
      if (!state->theBindings[state->theCurrentPos].second.empty())
      {
        ncname = state->theBindings[state->theCurrentPos].first;
        STACK_PUSH(GENV_ITEMFACTORY->createNCName(result, ncname), state);
      }
      state->theCurrentPos++;
    }
  }

  STACK_END (state);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
