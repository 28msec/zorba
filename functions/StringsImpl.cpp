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

#include "StringsImpl.h"
#include "util/tracer.h"
#include <iostream>

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

item_t CodepointsToStringIterator::nextImpl(){
	item_t item;
	const numericValue* n0;
	sequence_type_t type0;
	//xqpString test;

	STACK_INIT();
	
	while(true){
		item = this->consumeNext(argv);
		
		if(&*item == NULL) {
			//test = (uint)23;
			//STACK_PUSH(new stringValue(xs_string, test));
			STACK_PUSH(new stringValue(xs_string, res));
			STACK_PUSH(NULL);
		}
		else {
			n0 = dynamic_cast<const numericValue*>(&*item);

			seq[0] = 0;
			seq[1] = 0;
			seq[2] = 0;
			seq[3] = 0;
			
			EncodeUtf8((uint32_t)n0->val(), seq);

			res.append(seq);
		}
	}
	
	STACK_PUSH(NULL);
	STACK_END();
}

void CodepointsToStringIterator::resetImpl(){
		this->resetChild(argv);
}

void CodepointsToStringIterator::releaseResourcesImpl() {
		this->releaseChildResources(argv);
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

item_t StringToCodepointsIterator::nextImpl(){
	item_t item;
	const stringValue* n0;

	STACK_INIT();

	item = this->consumeNext(argv);
	
	if(&*item == NULL) {
		STACK_PUSH(NULL);
	}
	else
	{
		n0 = dynamic_cast<const stringValue*>(&*item);
		
		vLength = (n0->val().length()) + 1;
		v.reserve(vLength);
		std::strcpy(&v[0], n0->val().c_str());
		c = &v[0];

		while( --vLength > 0 ){
			cp = DecodeUtf8(c);
			STACK_PUSH(new numericValue(xs_long, cp));
		}
	}
	
	STACK_PUSH(NULL);
	STACK_END();
}

void StringToCodepointsIterator::resetImpl(){
	this->resetChild(argv);
}

void StringToCodepointsIterator::releaseResourcesImpl() {
	this->releaseChildResources(argv);
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

item_t CodepointEqualIterator::nextImpl(){
	item_t item0;
	item_t item1;
	const stringValue* n0;
	const stringValue* n1;

	STACK_INIT();

	item0 = this->consumeNext(argv0);
	item1 = this->consumeNext(argv1);
	finish = false;

	if(&*item0 == NULL || &*item1 == NULL) {
		STACK_PUSH(NULL);
	}
	else
	{
		n0 = dynamic_cast<const stringValue*>(&*item0);
		n1 = dynamic_cast<const stringValue*>(&*item1);
		
		vLength = (n0->val().length());
		
		if(vLength != n1->val().length())
			STACK_PUSH(new booleanValue(false));
		else
		{
			v0.reserve(vLength);
			std::strcpy(&v0[0], n0->val().c_str());
			c0 = &v0[0];
			
			v1.reserve(vLength);
			std::strcpy(&v1[0], n1->val().c_str());
			c1 = &v1[0];
			
			while( !finish && (vLength > 0) ){
				if(DecodeUtf8(c0) != DecodeUtf8(c1))
				{
					finish = true;
					STACK_PUSH(new booleanValue(false));
				}
				vLength--;
			}

			if(!finish)
				STACK_PUSH(new booleanValue(true));
		}
	}
	STACK_PUSH(NULL);
	STACK_END();
}

void CodepointEqualIterator::resetImpl(){
	this->resetChild(argv0);
	this->resetChild(argv1);
}

void CodepointEqualIterator::releaseResourcesImpl() {
	this->releaseChildResources(argv0);
	this->releaseChildResources(argv1);
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
	std::vector<iterator_t>::const_iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		(*iter)->show(os);
	}
	return os;
}

item_t ConcatFnIterator::nextImpl() {

	item_t item;
	
	iterator_t currit_str;
	item_t item_str;
	const stringValue* n;
	
	STACK_INIT();
	
	this->cursor = 0;
	
	for (; this->cursor < this->argv.size (); this->cursor++) {;
		this->currit_h = this->argv[this->cursor];
		item = this->consumeNext(this->currit_h);

		//TODO use a more high level function provided by the type system
		//if the item is not a node => it's a xs:anyAtomicType
		if((item->type() & NODE_MASK) == NOT_NODE)
		{
			currit_str = item->string_value(loc);
			item_str = this->consumeNext(currit_str);
			n = dynamic_cast<const stringValue*>(&*item_str);
			res.append(n->val());
			//res.append("1");
		}
	}

	STACK_PUSH(new stringValue(xs_string, res));
	STACK_PUSH(NULL);
	STACK_END();
}

void ConcatFnIterator::resetImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter);
	}
}

void ConcatFnIterator::releaseResourcesImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter);
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
	std::vector<iterator_t>::const_iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		(*iter)->show(os);
	}
	return os;
}

item_t StringJoinIterator::nextImpl() {

	STACK_INIT();
	STACK_PUSH(new stringValue(xs_string, "result"));
	STACK_PUSH(NULL);
	STACK_END();
}

void StringJoinIterator::resetImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->resetChild(*iter);
	}
}

void StringJoinIterator::releaseResourcesImpl() {
	std::vector<iterator_t>::iterator iter = this->argv.begin();
	for(; iter != this->argv.end(); ++iter) {
		this->releaseChildResources(*iter);
	}
}
} /* namespace xqp */
