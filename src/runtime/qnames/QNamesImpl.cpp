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
QNameEqualIterator::nextImpl(PlanState& planState){
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createBoolean(false);
    STACK_PUSH( res, state );
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
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createNCName("Not Implemented yet");
    STACK_PUSH( res, state );
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
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createNCName("Not Implemented yet");
    STACK_PUSH( res, state );
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
    Item_t res;

    PlanIterator::PlanIteratorState* state;
    DEFAULT_STACK_INIT(PlanIterator::PlanIteratorState, state, planState);
    res = Zorba::getItemFactory()->createAnyURI("Not Implemented yet");
    STACK_PUSH( res, state );
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
