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
 * @file functions/StringsImpl.h
 *
 */

#ifndef XQP_STRINGS_IMPL_H
#define XQP_STRINGS_IMPL_H

#include "context/common.h"
#include "functions/function.h"
#include "runtime/item_iterator.h"
#include "runtime/batching.h"
#include "types/sequence_type.h"
#include "util/rchandle.h"

namespace xqp {

class zorba;


/**______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

 /**
 * 7.2.1 fn:codepoints-to-string
 * -------------------- */
class CodepointsToStringIterator : public Batcher<CodepointsToStringIterator>
{
public:
	CodepointsToStringIterator(
		yy::location loc,
		iterator_t _argv)
	:
		Batcher<CodepointsToStringIterator>(loc),
		argv(_argv)
	{}

	CodepointsToStringIterator(
		const CodepointsToStringIterator& cptostr_it)
	:
		Batcher<CodepointsToStringIterator>(cptostr_it),
		argv(cptostr_it.argv)
	{}

	~CodepointsToStringIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;

protected:
	iterator_t argv;
	std::string res;
	char seq[4];
}; /*class CodepointsToStringIterator*/


/**
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
class StringToCodepointsIterator : public Batcher<StringToCodepointsIterator>
{
public:
	StringToCodepointsIterator(
		yy::location loc,
		iterator_t _argv)
	:
		Batcher<StringToCodepointsIterator>(loc),
		argv(_argv)
	{}

		StringToCodepointsIterator(
		const StringToCodepointsIterator& strtocp_it)
	:
		Batcher<StringToCodepointsIterator>(strtocp_it),
		argv(strtocp_it.argv)
	{}

	~StringToCodepointsIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;

protected:
	iterator_t argv;
	uint32_t cp;
	std::vector<char> v;
	char * c;
	uint16_t vLength;
}; /*class StringToCodepointsIterator*/


/**
 * 7.3.2 fn:compare
 * --------------------*/
class CompareIterator : public Batcher<CompareIterator>
{
};/*class CompareIterator*/


/**
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
class CodepointEqualIterator : public Batcher<CodepointEqualIterator>
{
public:
	CodepointEqualIterator(
		yy::location loc,
		iterator_t _argv0,
		iterator_t _argv1)
	:
		Batcher<CodepointEqualIterator>(loc),
		argv0(_argv0),
		argv1(_argv1)
	{}

	CodepointEqualIterator(
		const CodepointEqualIterator& cpEqual_it)
	:
		Batcher<CodepointEqualIterator>(cpEqual_it),
		argv0(cpEqual_it.argv0),
		argv1(cpEqual_it.argv1)
	{}

	~CodepointEqualIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;

protected:
	iterator_t argv0;
	iterator_t argv1;

	std::vector<char> v0;
	std::vector<char> v1;
	char * c0;
	char * c1;
	int16_t vLength;
	bool finish;
};/*class CodepointEqualIterator */

}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
