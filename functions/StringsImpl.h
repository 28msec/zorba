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
		argv(_argv),
		cursor(0)
	{}

	CodepointsToStringIterator(
		const CodepointsToStringIterator& cptostr_it)
	:
		Batcher<CodepointsToStringIterator>(cptostr_it),
		argv(cptostr_it.argv),
		cursor(cptostr_it.cursor)
	{}

	~CodepointsToStringIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;

protected:
	iterator_t argv;
	uint32_t cursor;

};

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
		argv(_argv),
		cursor(0)
	{}

		StringToCodepointsIterator(
		const StringToCodepointsIterator& strtocp_it)
	:
		Batcher<StringToCodepointsIterator>(strtocp_it),
		argv(strtocp_it.argv),
		cursor(strtocp_it.cursor)
	{}

	~StringToCodepointsIterator() {}

public:
	item_t nextImpl();
	void resetImpl();
	void releaseResourcesImpl();
	std::ostream&  _show(std::ostream&) const;

protected:
	iterator_t argv;
	uint32_t cursor;

};

}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
