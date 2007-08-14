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

	uint8_t * utf8String;
	
	STACK_INIT();
	
	this->cursor = 0;

	item = this->consumeNext(argv);
	if(&*item == NULL)
		STACK_PUSH(NULL);

	if(item == NULL){
		STACK_PUSH(NULL);
	}
	else{
		STACK_PUSH(new stringValue(xs_string, "TEST"));
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
	
	STACK_INIT();
	
	this->cursor = 0;

	item = this->consumeNext(argv);
	if(&*item == NULL)
		STACK_PUSH(NULL);

	if(item == NULL){
		STACK_PUSH(NULL);
	}
	else{
		STACK_PUSH(new numericValue(xs_integer, 2));
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
