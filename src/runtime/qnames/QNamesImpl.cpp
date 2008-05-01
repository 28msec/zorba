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
#include "runtime/qnames/QNamesImpl.h"
#include "runtime/api/runtimecb.h"
#include "system/globalenv.h"
#include "context/static_context.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"
#include "types/typemanager.h"
#include "types/casting.h"

namespace zorba {

#define GENV_GCAST (*GenericCast::instance ())

/**
 *______________________________________________________________________
 *
 * 11.1.1 fn:resolve-QName
 *
 * fn:resolve-QName($qname as xs:string?, $element as element()) as xs:QName?
 *
 *Summary: Returns an xs:QName value (that is, an expanded-QName) by taking an
 *xs:string that has the lexical form of an xs:QName (a string in the form
 *"prefix:local-name" or "local-name") and resolving it using the in-scope
 *namespaces for a given element.
 *If $qname does not have the correct lexical form for xs:QName
 *an error is raised [err:FOCA0002].
 *If $qname is the empty sequence, returns the empty sequence.
 *If the $qname has a prefix and if there is no namespace binding for $element
 *that matches this prefix, then an error is raised [err:FONS0004].
 *If the $qname has no prefix, and there is no namespace binding for $element
 *corresponding to the default (unnamed) namespace, then the resulting
 *expanded-QName has no namespace part.
 *The prefix (or absence of a prefix) in the supplied $qname argument is retained
 *in the returned expanded-QName
 *_______________________________________________________________________*/

 /* begin class ResolveQNameIterator */
store::Item_t
ResolveQNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t res;
  store::Item_t itemQName;
  store::Item_t itemElem;
  xqpStringStore_t qname;
  xqpStringStore_t resNs;
  xqpStringStore_t resPre;
  xqpStringStore_t resLocal;
  int32_t index = -1;
  std::vector<std::pair<xqp_string, xqp_string> > NamespaceBindings;
  std::vector<std::pair<xqp_string, xqp_string> > ::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemQName = consumeNext(theChild0.getp(), planState );
  if( itemQName != NULL) {
    itemQName = itemQName->getAtomizationValue();

    qname = itemQName->getStringValue()->trim();
    index = qname->indexOf(":");

    if(-1 != index) {
      resPre = new xqpStringStore(qname->str().substr(0, index));
      resLocal = new xqpStringStore(qname->str().substr(index+1, qname->bytes() - index));

      // must check for FOCA0002 first
      if (!GENV_GCAST.castableToNCName (resPre) || ! GENV_GCAST.castableToNCName (resLocal))
        ZORBA_ERROR (ZorbaError::FOCA0002);
      
      itemElem = consumeNext(theChild1, planState );
      if( itemElem != NULL ) {
        itemElem->getNamespaceBindings(NamespaceBindings);
        for (iter = NamespaceBindings.begin();
             iter != NamespaceBindings.end();
             ++iter)
          {
          if ((*iter).first.getStore()->byteEqual(*resPre)) {
            resNs = (*iter).second.getStore();
            break;
          }
          }
        if (resNs == NULL)
          ZORBA_ERROR (ZorbaError::FONS0004);
      }
    } else {
      resNs = new xqpStringStore("");
      resPre = new xqpStringStore("");
      resLocal = qname;
      if (! GENV_GCAST.castableToNCName (resLocal))
        ZORBA_ERROR (ZorbaError::FOCA0002);
    }

    res = GENV_ITEMFACTORY->createQName(resNs, resPre, resLocal);

    STACK_PUSH( res, state );
  }
  STACK_END (state);
}
/* end class ResolveQNameIterator */

/**
 *______________________________________________________________________
 *
 * 11.1.2 fn:QName
 *
 * fn:QName($paramURI as xs:string?, $paramQName as xs:string) as xs:QName
 *
 *Summary: Returns an xs:QName with the namespace URI given in $paramURI.
 *If $paramURI is the zero-length string or the empty sequence, it represents
 *"no namespace"; in this case, if the value of $paramQName contains a colon (:),
 *an error is raised [err:FOCA0002]. The prefix (or absence of a prefix)
 *in $paramQName is retained in the returned xs:QName value.
 *The local name in the result is taken from the local part of $paramQName.
 *If $paramQName does not have the correct lexical form for xs:QName
 *an error is raised [err:FOCA0002].
 *Note that unlike xs:QName this function does not require a xs:string literal as
 *the argument.
 *_______________________________________________________________________*/

 /* begin class QNameIterator */
store::Item_t
QNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemURI;
  store::Item_t itemQName;
  store::Item_t res;
  xqpStringStore_t qname;
  xqpStringStore_t resNs;
  xqpStringStore_t resPre;
  xqpStringStore_t resLocal;
  int32_t index = -1;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemURI = consumeNext(theChild0.getp(), planState );
  if  ( itemURI != NULL ) {
    itemURI = itemURI->getAtomizationValue();
    resNs = itemURI->getStringValue()->trim();
  } else {
    resNs = new xqpStringStore("");
  }

  itemQName = consumeNext(theChild1.getp(), planState );
  itemQName = itemQName->getAtomizationValue();
  qname = itemQName->getStringValue()->trim();
  
  index = qname->indexOf(":");

  if( -1 != index ) {
    if (resNs->empty ())
      ZORBA_ERROR (ZorbaError::FOCA0002);

    resPre = new xqpStringStore(qname->str().substr(0, index));
    resLocal = new xqpStringStore(qname->str().substr(index+1, qname->bytes() - index));
  } else {
    resPre = new xqpStringStore("");
    resLocal = qname;
  }
  
  if ((index != -1 && ! GENV_GCAST.castableToNCName (resPre))
      || ! GENV_GCAST.castableToNCName (resLocal))
    ZORBA_ERROR (ZorbaError::FOCA0002);

  res = GENV_ITEMFACTORY->createQName(resNs, resPre, resLocal);
  STACK_PUSH( res, state );
  STACK_END (state);
}
/* end class QNameIterator */
/**
 *______________________________________________________________________
 *
 * 11.2.1 op:QName-equal
 *
 *  op:QName-equal($arg1 as xs:QName,
 *                            $arg2 as xs:QName) as xs:boolean
 *
 *Summary: Returns true if the namespace URIs of $arg1 and $arg2 are equal and
 *the local names of $arg1 and $arg2 are identical based on the
 *Unicode code point collation. Otherwise, returns false.
 *Two namespace URIs are considered equal if they are either both absent or
 *both present and identical based on the Unicode code point collation. The prefix
 *parts of $arg1 and $arg2, if any, are ignored.
 *_______________________________________________________________________*/

 /* begin class QNameEqualIterator */
store::Item_t
QNameEqualIterator::nextImpl(PlanState& planState) const
{
  store::Item_t arg1;
  store::Item_t arg2;
  store::Item_t res;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  arg1 = consumeNext(theChild0.getp(), planState );
  if ( arg1 != NULL )
  {
    arg2 = consumeNext(theChild1.getp(), planState );
    if ( arg2 != NULL )
    {
      arg1 = arg1->getAtomizationValue();
      arg2 = arg2->getAtomizationValue();
    
      if(arg1->getLocalName()->equals(arg2->getLocalName()))
      {
        if((arg1->getNamespace()->empty() && arg2->getNamespace()->empty()) ||
           (arg1->getNamespace()->equals(arg2->getNamespace())))
          res = GENV_ITEMFACTORY->createBoolean(true);
        else
          res = GENV_ITEMFACTORY->createBoolean(false);
      }
      else
        res = GENV_ITEMFACTORY->createBoolean(false);

      STACK_PUSH( res, state );
    }
  }
  STACK_END (state);
}
/* end class QNameEqualIterator */


/**
 *______________________________________________________________________
 *
 * 11.2.2 fn:prefix-from-QName
 *
 * fn:prefix-from-QName($arg as xs:QName?) as xs:NCName?
 *
 *Summary: Returns an xs:NCName representing the prefix of $arg. The empty sequence
 *is returned if $arg is the empty sequence or if the value of $arg contains no prefix.
 *_______________________________________________________________________*/

 /* begin class PrefixFromQNameIterator */
store::Item_t
PrefixFromQNameIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  xqpStringStore* pre;
  xqpStringStore_t preh;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    pre = item->getPrefix();
    if(!pre->empty())
    {
      preh = pre;
      STACK_PUSH( GENV_ITEMFACTORY->createNCName(preh), state );
    }
  }
  STACK_END (state);
}
/* end class PrefixFromQNameIterator */

/**
 *______________________________________________________________________
 *
 * 11.2.3 fn:local-name-from-QName
 *
 * fn:local-name-from-QName($arg as xs:QName?) as xs:NCName?
 *
 *Summary: Returns an xs:NCName representing the local part of $arg.
 *If $arg is the empty sequence, returns the empty sequence.
 *_______________________________________________________________________*/

 /* begin class LocalNameFromQNameIterator */
store::Item_t
LocalNameFromQNameIterator::nextImpl(PlanState& planState) const 
{
  store::Item_t item;
  xqpStringStore_t localName;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    localName = item->getLocalName();
    STACK_PUSH(GENV_ITEMFACTORY->createNCName(localName), state);
  }
  STACK_END (state);
}
/* end class LocalNameFromQNameIterator */

/**
 *______________________________________________________________________
 *
 * 11.2.4 fn:namespace-uri-from-QName
 *
 * fn:namespace-uri-from-QName($arg as xs:QName?) as xs:anyURI?
 *
 *Summary: Returns the namespace URI for $arg as an xs:string.
 *If $arg is the empty sequence, the empty sequence is returned.
 *If $arg is in no namespace, the zero-length string is returned.
 *_______________________________________________________________________*/

 /* begin class NamespaceUriFromQNameIterator */
store::Item_t
NamespaceUriFromQNameIterator::nextImpl(PlanState& planState) const 
{
  store::Item_t item;
  xqpStringStore_t ns;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
  item = consumeNext(theChild.getp(), planState);
  if ( item != NULL )
  {
    ns = item->getNamespace();
    STACK_PUSH( GENV_ITEMFACTORY->createString(ns), state );
  }
  STACK_END (state);
}
/* end class NamespaceUriFromQNameIterator */

/**
 *______________________________________________________________________
 *
 * 11.2.5 fn:namespace-uri-for-prefix
 *
 * fn:namespace-uri-for-prefix($prefix as xs:string?,
 *                             $element as element()) as xs:anyURI?
 *
 *Summary: Returns the namespace URI of one of the in-scope namespaces for
 *$element, identified by its namespace prefix.
 *If $element has an in-scope namespace whose namespace prefix is equal to $prefix,
 *it returns the namespace URI of that namespace. If $prefix is the zero-length string or
 *the empty sequence, it returns the namespace URI of the
 *default (unnamed) namespace. Otherwise, it returns the empty sequence.
 *Prefixes are equal only if their Unicode code points match exactly.
 *_______________________________________________________________________*/

 /* begin class NamespaceUriForPrefixlIterator */
store::Item_t
NamespaceUriForPrefixlIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemPrefix;
  store::Item_t itemElem;
  xqpStringStore_t resNs;
  std::vector<std::pair<xqp_string, xqp_string> > NamespaceBindings;
  std::vector<std::pair<xqp_string, xqp_string> > ::const_iterator iter;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  itemPrefix = consumeNext(theChild0, planState );
  if( itemPrefix != NULL)
  {
    itemPrefix = itemPrefix->getAtomizationValue();

    itemElem = consumeNext(theChild1, planState );
    if( itemElem != NULL)
    {
      itemElem->getNamespaceBindings(NamespaceBindings);
      for (
            iter = NamespaceBindings.begin();
            iter != NamespaceBindings.end();
            ++iter
          )
      {
        if( (*iter).first.getStore()->byteEqual(*itemPrefix->getStringValue()->trim()))
        {
          resNs = (*iter).second.getStore();
          break;
        }
      }
    }
    else
    {
      resNs = planState.theRuntimeCB->theStaticContext->default_elem_type_ns().getStore();
    }

    if( resNs != NULL && !resNs->empty() )
      STACK_PUSH( GENV_ITEMFACTORY->createString(resNs), state );
  }
  STACK_END (state);
}
/* end class NamespaceUriForPrefixlIterator */

/**
 *______________________________________________________________________
 *
 * 11.2.6 fn:in-scope-prefixes
 *
 * fn:in-scope-prefixes($element as element()) as xs:string*
 *
 *Summary: Returns the prefixes of the in-scope namespaces for $element.
 *For namespaces that have a prefix, it returns the prefix as an xs:NCName.
 *For the default namespace, which has no prefix, it returns the zero-length string.
 *_______________________________________________________________________*/

store::Item_t
InScopePrefixesIterator::nextImpl(PlanState& planState) const
{
  store::Item_t itemElem;
  xqpStringStore_t ncname = new xqpStringStore ("xml");

  InScopePrefixesState* state;
  DEFAULT_STACK_INIT(InScopePrefixesState, state, planState);

  STACK_PUSH(GENV_ITEMFACTORY->createNCName(ncname), state);

  itemElem = consumeNext(theChild.getp(), planState );
  if( itemElem != NULL)
  {
    itemElem->getNamespaceBindings(state->theBindings);
    while (state->theCurrentPos < state->theBindings.size())
    {
      ncname = state->theBindings[state->theCurrentPos].first.getStore();
      STACK_PUSH(GENV_ITEMFACTORY->createNCName(ncname), state);
      state->theCurrentPos++;
    }
  }

  STACK_END (state);
}


void
InScopePrefixesState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theBindings.clear();
  theCurrentPos = 0;
}


void
InScopePrefixesState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theBindings.clear();
  theCurrentPos = 0;
}


} /* namespace zorba */
