/**
 * @copyright
 * ========================================================================
 *  Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file runtime/qnames/QNamesImpl.cpp
 *
 */

#include "runtime/qnames/QNamesImpl.h"

namespace xqp {
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
Item_t
ResolveQNameIterator::nextImpl(PlanState& planState){
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createQName("Not Implemented yet",
                                                                         "Not Implemented yet",
                                                                         "Not Implemented yet");
    STACK_PUSH( res, state );
    STACK_END();
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
Item_t
QNameIterator::nextImpl(PlanState& planState)
{
    Item_t itemURI;
    Item_t itemQName;
    Item_t res;
    xqp_string resNs = "";
    xqp_string resQName = "";
    int32_t index = -1;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);

    itemURI = consumeNext ( theChild0, planState );
    if ( itemURI != NULL )
    {
      itemURI = itemURI->getAtomizationValue();
      resNs = itemURI->getStringProperty();
    }

    itemQName = consumeNext ( theChild1, planState );
    if ( itemQName != NULL )
    {
      itemQName = itemQName->getAtomizationValue();
      resQName = itemQName->getStringProperty();
      
      //TODO check if $paramQName does not have the correct lexical form for xs:QName and raise an error [err:FOCA0002].

      index = resQName.indexOf(":");
      
      if( resNs.empty() && (-1 != index) )
        ZORBA_ERROR_ALERT(ZorbaError::FOCA0002);
    }

    if( -1 != index )
    {
    res = Zorba::getItemFactory()->createQName(
        resNs,
        resQName.substr( 0, index ),
        resQName.substr( index+1, resQName.length() - index ));
    }
    else
    {
      res = Zorba::getItemFactory()->createQName(
        resNs,
        "",
        resQName);
    }

    STACK_PUSH( res, state );
    STACK_END();
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
Item_t
QNameEqualIterator::nextImpl(PlanState& planState)
{
  Item_t arg1;
  Item_t arg2;
  Item_t res;

  PlanIterator::PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);

  arg1 = consumeNext ( theChild0, planState );
  if ( arg1 != NULL )
  {
    arg2 = consumeNext ( theChild1, planState );
    if ( arg2 != NULL )
    {
      arg1 = arg1->getAtomizationValue();
      arg2 = arg2->getAtomizationValue();
    
      if(arg1->getLocalName() == arg2->getLocalName())
      {
        if((arg1->getNamespace().empty() && arg2->getNamespace().empty()) ||
            (arg1->getNamespace() == arg2->getNamespace()))
          res = Zorba::getItemFactory()->createBoolean(true);
        else
          res = Zorba::getItemFactory()->createBoolean(false);
      }
      else
        res = Zorba::getItemFactory()->createBoolean(false);

      STACK_PUSH( res, state );
    }
  }
  STACK_END();
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
Item_t
PrefixFromQNameIterator::nextImpl(PlanState& planState){
    Item_t item;
    xqp_string tmp="";

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    item = consumeNext (theChild, planState);
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      tmp = item->getPrefix();
      if(!tmp.empty())
        STACK_PUSH( Zorba::getItemFactory()->createNCName(tmp), state );
    }
    STACK_END();
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
Item_t
LocalNameFromQNameIterator::nextImpl(PlanState& planState){
  Item_t item;

  PlanIterator::PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
  item = consumeNext (theChild, planState);
  if ( item != NULL )
  {
    item = item->getAtomizationValue();
    STACK_PUSH( Zorba::getItemFactory()->createNCName(item->getLocalName()), state );
  }
  STACK_END();
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
Item_t
NamespaceUriFromQNameIterator::nextImpl(PlanState& planState){
    Item_t item;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    
    item = consumeNext (theChild, planState);
    if ( item != NULL )
    {
      item = item->getAtomizationValue();
      STACK_PUSH( Zorba::getItemFactory()->createString(item->getNamespace()), state );
    }
    STACK_END();
}
/* end class NamespaceUriFromQNameIterator */

/**
 *______________________________________________________________________
 *
 * 11.2.5 fn:namespace-uri-for-prefix
 *
 * fn:namespace-uri-for-prefix($prefix as xs:string?,
 *                                         $element as element()) as xs:anyURI?
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
Item_t
NamespaceUriForPrefixlIterator::nextImpl(PlanState& planState){
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createAnyURI("Not Implemented yet");
    STACK_PUSH( res, state );
    STACK_END();
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

 /* begin class InScopePrefixesIterator */
Item_t
InScopePrefixesIterator::nextImpl(PlanState& planState){
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createString("Not Implemented yet");
    STACK_PUSH( res, state );
    STACK_END();
}
/* end class InScopePrefixesIterator */
} /* namespace xqp */
