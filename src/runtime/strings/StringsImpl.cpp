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
	uint32_t cp;
	std::vector<char> v;
	char * c;
	uint16_t vLength;
	Item_t item;

	PlanIterator::PlanIteratorState* state;
	STACK_INIT2(PlanIterator::PlanIteratorState, state, planState);

	item = consumeNext ( theChild, planState );
	if ( item != NULL ){
		vLength = (item->getStringValue().length()) + 1;
		v.reserve(vLength);
		std::strcpy(&v[0], item->getStringValue().c_str());
		c = &v[0];

		while( --vLength > 0 ){
			cp = UTF8Decode(c);
			STACK_PUSH2(zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(cp), state);
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

CompareStrIterator::CompareStrIterator
		( const yy::location& loc, std::vector<Iterator_t>& args )
	:
		NaryBaseIterator<CompareStrIterator>( loc, args )
{}

CompareStrIterator::~CompareStrIterator()
{}

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
				if ( n2 != NULL )	{
					//TODO check if lowercase two-letter or three-letter ISO-639 code is a correct value for $collation
					res = zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(
									n0->getStringValue().compare(n1->getStringValue(), n2->getStringValue().c_str()));
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
std::ostream& CodepointEqualIterator::_show(std::ostream& os) const{
	argv0->show(os);
	argv1->show(os);
	return os;
}

Item_t CodepointEqualIterator::nextImpl(PlanState& planState){
	Item_t item0;
	Item_t item1;

	STACK_INIT();

	item0 = this->consumeNext(argv0, planState);
	item1 = this->consumeNext(argv1, planState);
	finish = false;

	if(&*item0 == NULL || &*item1 == NULL) {
		STACK_PUSH(NULL);
	}
	else
	{
		vLength = (item0->getStringValue().length());
		
		if(int32_t(vLength) != int32_t(item1->getStringValue().length()))
			STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(false));
		else
		{
			v0.reserve(vLength);
			std::strcpy(&v0[0], item0->getStringValue().c_str());
			c0 = &v0[0];
			
			v1.reserve(vLength);
			std::strcpy(&v1[0], item1->getStringValue().c_str());
			c1 = &v1[0];
			
			while( !finish && (vLength > 0) ){
				if(UTF8Decode(c0) != UTF8Decode(c1))
				{
					finish = true;
					STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(false));
				}
				vLength--;
			}

			if(!finish)
				STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(true));
		}
	}
	STACK_PUSH(NULL);
	STACK_END();
}

void CodepointEqualIterator::resetImpl(PlanState& planState){
	this->resetChild(argv0, planState);
	this->resetChild(argv1, planState);
}

void CodepointEqualIterator::releaseResourcesImpl(PlanState& planState) {
	this->releaseChildResources(argv0, planState);
	this->releaseChildResources(argv1, planState);
}

/**
 *______________________________________________________________________
 *
 *	7.4.1 fn:concat
 *
 * fn:concat( 	$arg1 	 as xs:anyAtomicType?,
 * 							$arg2 	 as xs:anyAtomicType?,
 * 							...													) as xs:string
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
std::ostream& ConcatFnIterator::_show(std::ostream& os)
		const
{
	std::vector<Iterator_t>::const_iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		(*iter)->show(os);
	}
	return os;
}

Item_t ConcatFnIterator::nextImpl(PlanState& planState) {

	Item_t item;
	
	STACK_INIT();
	
	this->cursor = 0;
	
	for (; this->cursor < this->argv.size (); this->cursor++) {;
		this->currit_h = this->argv[this->cursor];
		item = this->consumeNext(this->currit_h, planState);

		//TODO use a more high level function provided by the type system
		//if the item is not a node => it's a xs:anyAtomicType
		if((item->getType() & NODE_MASK) == NOT_NODE)
		{
			res.append(item->getStringProperty());
			//res.append("1");
		}
	}

	STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createString(this->res));
	STACK_PUSH(NULL);
	STACK_END();
}

void ConcatFnIterator::resetImpl(PlanState& planState) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter, planState);
	}
}

void ConcatFnIterator::releaseResourcesImpl(PlanState& planState) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter, planState);
	}
}


/**
 *______________________________________________________________________
 *
 *	7.4.2 fn:string-join
 *
 * fn:string-join($arg1 as xs:string*,
 * 								$arg2 as xs:string) as xs:string
 *
 *
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
std::ostream& StringJoinIterator::_show(std::ostream& os)
		const
{
	std::vector<Iterator_t>::const_iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		(*iter)->show(os);
	}
	return os;
}

Item_t StringJoinIterator::nextImpl(PlanState& planState) {

	STACK_INIT();
	STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createString("result"));
	STACK_PUSH(NULL);
	STACK_END();
}

void StringJoinIterator::resetImpl(PlanState& planState) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter, planState);
	}
}

void StringJoinIterator::releaseResourcesImpl(PlanState& planState) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter, planState);
	}
}
} /* namespace xqp */
