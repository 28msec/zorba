/**
 * @copyright
 * ========================================================================
 *	Copyright 2006-2007 FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/StringsImpl.cpp
 *
 */

#include <iostream>

#include "runtime/strings/StringsImpl.h"
#include "util/tracer.h"
#include "types/casting.h"
#include "errors/Error.h"
#include "util/zorba.h"
#include "util/utf8/utf8.h"

using namespace std;
namespace xqp {
/**
 *______________________________________________________________________
 *
 *	7.2.1 fn:codepoints-to-string
 *
 *	fn:codepoints-to-string($arg as xs:integer*) as xs:string
 *
 *	Summary:Creates an xs:string from a sequence of code points.
 *Returns the zero-length string if $arg is the empty sequence.
 *If any of the code points in $arg is not a legal XML character,
 *an error is raised [err:FOCH0001] ("Code point not valid.").
 *_______________________________________________________________________*/
/* begin class CodepointsToStringIterator */
Item_t CodepointsToStringIterator::nextImpl(PlanState& planState){
	Item_t item;
	Item_t resItem;
	xqp_string resStr;

	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	while(true){
		item = consumeNext ( theChild, planState );
		if ( item != NULL ){
			item = item->getAtomizationValue();
			resStr += (uint32_t)item->getIntegerValue();
		}
		else{
			resItem = zorba::getZorbaForCurrentThread()->getItemFactory()->createString(resStr);
			STACK_PUSH2( resItem, state );
			break;
		}
	}
	STACK_END2();
}
/* end class CodepointsToStringIterator */

/**
 *______________________________________________________________________
 *
 *	7.2.2 fn:string-to-codepoints
 *
 *	fn:string-to-codepoints($arg as xs:string?) as xs:integer*
 *
 *	Summary: Returns the sequence of code points that constitute an
 *xs:string.
 *If $arg is a zero-length string or the empty sequence,
 *the empty sequence is returned.
 *_______________________________________________________________________*/
/* begin class StringToCodepointsIterator */
Item_t StringToCodepointsIterator::nextImpl(PlanState& planState){
/*
	Item_t item;
	Item_t resItem;
	xqp_string inputStr;
	std::vector<int> resVector;
	std::vector<int>::iterator iter;

	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	item = consumeNext ( theChild, planState );
	if ( item != NULL ){
		inputStr = item->getStringValue();
		resVector = inputStr.getCodepoints();
		for(iter = resVector.begin(); iter != resVector.end(); iter++){
			resItem = zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(*iter);
			STACK_PUSH2( resItem, state );
		}
	}
	STACK_END2();
*/
	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);
	STACK_END2();
}
/* end class StringToCodepointsIterator */

/**
 *______________________________________________________________________
 *	7.3.2 fn:compare
 * fn:compare($comparand1 as xs:string?,
 * 									$comparand2 as xs:string?) as xs:integer
 *
 * fn:compare( 	$comparand1	as xs:string?,
 * 										$comparand2	as xs:string?,
 * 										$collation	as xs:string) as xs:integer?
 *
 * Summary: Returns -1, 0, or 1, depending on whether the value of
 * the $comparand1 is respectively less than, equal to, or greater
 * than the value of $comparand2, according to the rules of
 * the collation that is used.
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 *_______________________________________________________________________*/

/* begin class CompareStrIterator */
Item_t
CompareStrIterator::nextImpl(PlanState& planState) {
	Item_t n0;
	Item_t n1;
	Item_t n2;
	Item_t res;

	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	n0 = consumeNext ( theChildren[0], planState );
	if ( n0 != NULL )	{
		n1 = consumeNext ( theChildren[1], planState );
		if ( n1 != NULL )	{
			n0 = n0->getAtomizationValue();
			n1 = n1->getAtomizationValue();
			n2 = consumeNext ( theChildren[2], planState );
			if(theChildren.size() == 3)	{
				if ( n2 != NULL )	{
					//TODO solve track issue no.26
					res = zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(
									n0->getStringValue().compare(n1->getStringValue(), n2->getStringValue().c_str()));
				}
			}
			else{
				res = zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(
								n0->getStringValue().compare(n1->getStringValue()));
			}
			STACK_PUSH2( res, state );
		}
	}

	STACK_END2();
}
/* end class CompareStrIterator */

/**
 *______________________________________________________________________
 *
 *	7.3.3 fn:codepoint-equal
 *
 *	fn:codepoint-equal( 	$comparand1 	 as xs:string?,
 *  											$comparand2 	 as xs:string?) as xs:boolean?
 *
 *	Summary: Returns true or false depending on whether the value
 * of $comparand1 is equal to the value of $comparand2, according to
 * the Unicode code point collation
 * (http://www.w3.org/2005/xpath-functions/collation/codepoint).
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 * 
 * Note: This function allows xs:anyURI values to be compared
 * without having to specify the Unicode code point collation.
 *_______________________________________________________________________*/
/* begin class CodepointEqualIterator */
Item_t CodepointEqualIterator::nextImpl(PlanState& planState){
		Item_t item0;
		Item_t item1;
		Item_t res;

		PlanIterator::PlanIteratorState* state;
		STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

		item0 = consumeNext ( theChild0, planState );
		if ( item0 != NULL )	{
			item1 = consumeNext ( theChild1, planState );
			if ( item1 != NULL )	{
				item0 = item0->getAtomizationValue();
				item1 = item1->getAtomizationValue();
				res = zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(
									item0->getStringValue() == item1->getStringValue());
				STACK_PUSH2( res, state );
			}
		}
		STACK_END2();
}
/* end class CodepointEqualIterator */
/**
 *______________________________________________________________________
 *
 *	7.4.1 fn:concat
 *
 * fn:concat( 	$arg1 	 as xs:anyAtomicType?,
 * 									$arg2 	 as xs:anyAtomicType?,
 * 									...																					) as xs:string
 * 
 * Summary:
 * Accepts two or more xs:anyAtomicType arguments and casts them to xs:string.
 * Returns the xs:string that is the concatenation of the values of its
 * arguments after conversion.
 * If any of the arguments is the empty sequence, the argument is treated
 * as the zero-length string.
 *
 * The fn:concat function is specified to allow an two or more arguments
 * that are concatenated together.
 *
 * Note:
 * Unicode normalization is not automatically applied to the result
 * of fn:concat. If a normalized result is required, fn:normalize-unicode
 * can be applied to the xs:string returned by fn:concat.
 *_______________________________________________________________________*/
/* begin class ConcatStrIterator */
Item_t ConcatStrIterator::nextImpl(PlanState& planState) {
	Item_t item;
	Item_t resItem;
	xqp_string resStr;
	std::vector<PlanIter_t>::iterator iter = theChildren.begin();

	int argsNo = theChildren.size();
	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	for(; iter !=  theChildren.end(); iter ++ ){
		item = consumeNext (*iter, planState );
			item = item->getAtomizationValue();
			resStr += item->getStringValue();
	}

	if(theChildren.size()>0){
		resItem = zorba::getZorbaForCurrentThread()->getItemFactory()->createString(resStr);
		STACK_PUSH2( resItem, state );
	}

	STACK_END2();
}
/* end class ConcatStrIterator */

/**
 *______________________________________________________________________
 *
 *	7.4.2 fn:string-join
 *
 * fn:string-join($arg1 as xs:string*,
 * 										$arg2 as xs:string) as xs:string
 *
 * Summary: Returns a xs:string created by concatenating the members
 * of the $arg1 sequence using $arg2 as a separator.
 *
 * If the value of $arg2 is the zero-length string,
 * then the members of $arg1 are concatenated without a separator.
 *
 * If the value of $arg1 is the empty sequence,
 * the zero-length string is returned.
 *_______________________________________________________________________*/
/* begin class StringJoinIterator */
Item_t StringJoinIterator::nextImpl(PlanState& planState) {
	Item_t item;
	Item_t resItem;
	xqp_string resStr;
	xqp_string separator;

	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	item = consumeNext(theChild1, planState);
	separator = item->getStringValue();

	if(separator == ""){
		while(true){
			item = consumeNext ( theChild0, planState );
			if ( item != NULL ){
				item = item->getAtomizationValue();
				resStr += item->getStringValue();
			}
			else{
				resItem = zorba::getZorbaForCurrentThread()->getItemFactory()->createString(resStr);
				STACK_PUSH2( resItem, state );
				break;
			}
		}
	}
	else{
			while(true){
			item = consumeNext ( theChild0, planState );
			if ( item != NULL ){
				item = item->getAtomizationValue();
				resStr += item->getStringValue();
				resStr += separator;
			}
			else{
				resItem = zorba::getZorbaForCurrentThread()->getItemFactory()->createString(resStr);
				STACK_PUSH2( resItem, state );
				break;
			}
		}
	}
	STACK_END2();
}
/* end class StringJoinIterator */
} /* namespace xqp */
