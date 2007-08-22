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
	
	STACK_INIT();
	
	while(true){
		item = this->consumeNext(argv);
		
		if(&*item == NULL) {
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

} /* namespace xqp */
