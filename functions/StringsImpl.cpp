/**
 * @file StringsImpl.cpp
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @copyright 2006-2007 FLWOR Foundation (flworfound.org)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
 */

#include "StringsImpl.h"
#include "util/tracer.h"
#include <iostream>

using namespace std;
namespace xqp {

/*______________________________________________________________________
|  
|	7.2.1 fn:codepoints-to-string
|
|	fn:codepoints-to-string($arg as xs:integer*) as xs:string
|	
|	Summary:Creates an xs:string from a sequence of code points.
|Returns the zero-length string if $arg is the empty sequence.
|If any of the code points in $arg is not a legal XML character,
|an error is raised [err:FOCH0001] ("Code point not valid.").
|_______________________________________________________________________*/

void fn_codepoints_to_string_iterator::_open()
{
	arg->open();
}
  
item_t fn_codepoints_to_string_iterator::_next()
{
	item_t codepoint = arg->next();
	if(&*codepoint == NULL)
		return NULL;
	//TO DO implement the wchar_t funtionality
	return new stringValue( xs_string, "test");
}

void fn_codepoints_to_string_iterator::_close()
{
	arg->close();
}

std::ostream& fn_codepoints_to_string_iterator::_show(std::ostream& os)
const
{
	arg->show(os);
	return os;
}

bool fn_codepoints_to_string_iterator::done() const
{
	return arg->done();
}

fn_codepoints_to_string_iterator::fn_codepoints_to_string_iterator(
	yy::location loc,
	iterator_t _arg)
:
	BasicIterator(loc),
	arg(_arg),
	doc_node(NULL)
{
}

fn_codepoints_to_string_iterator::fn_codepoints_to_string_iterator(
	const fn_codepoints_to_string_iterator& it)
:
	BasicIterator(it),
	arg(it.arg),
	doc_node(it.doc_node)
{
}

fn_codepoints_to_string_iterator& fn_codepoints_to_string_iterator::operator=(
	const fn_codepoints_to_string_iterator& it)
{
	zorp = it.zorp;
	arg = it.arg;
	doc_node = it.doc_node;
	return *this;
}

/*______________________________________________________________________
|
|	7.2.2 fn:string-to-codepoints
|
|	fn:string-to-codepoints($arg as xs:string?) as xs:integer*
|
|	Summary: Returns the sequence of code points that constitute an
|xs:string.
|If $arg is a zero-length string or the empty sequence,
|the empty sequence is returned.
|_______________________________________________________________________*/

void fn_string_to_codepoints_iterator::_open()
{
	arg->open();
}

item_t fn_string_to_codepoints_iterator::_next()
{
	item_t nextChar = arg->next();
	if(&*nextChar == NULL)
		return NULL;
	//TO DO implement the wchar_t functionality
	return new numericValue(xs_integer, 2222);
}

void fn_string_to_codepoints_iterator::_close()
{
	arg->close();
}

std::ostream& fn_string_to_codepoints_iterator::_show(std::ostream& os)
const
{
	arg->show(os);
	return os;
}

bool fn_string_to_codepoints_iterator::done() const
{
	return arg->done();
}

fn_string_to_codepoints_iterator::fn_string_to_codepoints_iterator(
	yy::location loc,
iterator_t _arg)
:
BasicIterator(loc),
	arg(_arg),
	doc_node(NULL)
{
}

fn_string_to_codepoints_iterator::fn_string_to_codepoints_iterator(
	const fn_string_to_codepoints_iterator& it)
:
BasicIterator(it),
	arg(it.arg),
	doc_node(it.doc_node)
{
}

fn_string_to_codepoints_iterator& fn_string_to_codepoints_iterator::operator=(
	const fn_string_to_codepoints_iterator& it)
{
	zorp = it.zorp;
	arg = it.arg;
	doc_node = it.doc_node;
	return *this;
}

} /* namespace xqp */
