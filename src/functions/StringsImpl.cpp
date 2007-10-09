/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/StringsImpl.cpp
 *
 */

#include <iostream>

#include "StringsImpl.h"
#include "util/tracer.h"
#include "../utf8/utf8.h"
#include "runtime/zorba.h"

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
	
std::ostream& CodepointsToStringIterator::_show(std::ostream& os) const{
	argv->show(os);
	return os;
}

Item_t CodepointsToStringIterator::nextImpl(IteratorTreeStateBlock& stateBlock){
	Item_t item;
	sequence_type_t type0;
	//xqpString test;

	STACK_INIT();
	
	while(true){
		item = this->consumeNext(argv, stateBlock);
		
		if(&*item == NULL) {
			//test = (uint)23;
			//STACK_PUSH(new stringValue(xs_string, test));
			STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createString(this->res));
			STACK_PUSH(NULL);
		}
		else {

			seq[0] = 0;
			seq[1] = 0;
			seq[2] = 0;
			seq[3] = 0;
			
			UTF8Encode(item->getIntValue(), seq);

			res.append(seq);
		}
	}
	STACK_PUSH(NULL);
	STACK_END();
}

void CodepointsToStringIterator::resetImpl(IteratorTreeStateBlock& stateBlock){
		this->resetChild(argv, stateBlock);
}

void CodepointsToStringIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock) {
		this->releaseChildResources(argv, stateBlock);
}


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

std::ostream& StringToCodepointsIterator::_show(std::ostream& os) const{
	argv->show(os);
	return os;
}

Item_t StringToCodepointsIterator::nextImpl(IteratorTreeStateBlock& stateBlock){
	Item_t item;

	STACK_INIT();

	item = this->consumeNext(argv, stateBlock);
	
	if(&*item != NULL) {
		
		vLength = (item->getStringValue().length()) + 1;
		v.reserve(vLength);
		std::strcpy(&v[0], item->getStringValue().c_str());
		c = &v[0];

		while( --vLength > 0 ){
			cp = UTF8Decode(c);
			STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createInteger(cp));
		}
	}
	
	STACK_PUSH(NULL);
	STACK_END();
}

void StringToCodepointsIterator::resetImpl(IteratorTreeStateBlock& stateBlock){
	this->resetChild(argv, stateBlock);
}

void StringToCodepointsIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock) {
	this->releaseChildResources(argv, stateBlock);
}


/**
 *______________________________________________________________________
 *	7.3.2 fn:compare
 * fn:compare($comparand1 as xs:string?,
 * 						$comparand2 as xs:string?) as xs:integer
 *
 * fn:compare( 	$comparand1	as xs:string?,
 * 							$comparand2	as xs:string?,
 * 							$collation	as xs:string) as xs:integer?
 *
 * Summary: Returns -1, 0, or 1, depending on whether the value of
 * the $comparand1 is respectively less than, equal to, or greater
 * than the value of $comparand2, according to the rules of
 * the collation that is used.
 *
 * If either argument is the empty sequence, the result is the empty sequence.
 *_______________________________________________________________________*/

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

Item_t CodepointEqualIterator::nextImpl(IteratorTreeStateBlock& stateBlock){
	Item_t item0;
	Item_t item1;

	STACK_INIT();

	item0 = this->consumeNext(argv0, stateBlock);
	item1 = this->consumeNext(argv1, stateBlock);
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

void CodepointEqualIterator::resetImpl(IteratorTreeStateBlock& stateBlock){
	this->resetChild(argv0, stateBlock);
	this->resetChild(argv1, stateBlock);
}

void CodepointEqualIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock) {
	this->releaseChildResources(argv0, stateBlock);
	this->releaseChildResources(argv1, stateBlock);
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

Item_t ConcatFnIterator::nextImpl(IteratorTreeStateBlock& stateBlock) {

	Item_t item;
	
	STACK_INIT();
	
	this->cursor = 0;
	
	for (; this->cursor < this->argv.size (); this->cursor++) {;
		this->currit_h = this->argv[this->cursor];
		item = this->consumeNext(this->currit_h, stateBlock);

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

void ConcatFnIterator::resetImpl(IteratorTreeStateBlock& stateBlock) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter, stateBlock);
	}
}

void ConcatFnIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter, stateBlock);
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

Item_t StringJoinIterator::nextImpl(IteratorTreeStateBlock& stateBlock) {

	STACK_INIT();
	STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createString("result"));
	STACK_PUSH(NULL);
	STACK_END();
}

void StringJoinIterator::resetImpl(IteratorTreeStateBlock& stateBlock) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter, stateBlock);
	}
}

void StringJoinIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock) {
	std::vector<Iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter, stateBlock);
	}
}
} /* namespace xqp */
