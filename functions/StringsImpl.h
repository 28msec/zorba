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
#include "runtime/batching.h"
#include "types/sequence_type.h"

#ifdef WIN32
#include "win32/compatib_defs.h"
#endif

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
		Iterator_t _argv)
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
	Item_t nextImpl(int8_t* stateBlock);
	void resetImpl(int8_t* stateBlock);
	void releaseResourcesImpl(int8_t* stateBlock);
	std::ostream&  _show(std::ostream&) const;

protected:
	Iterator_t argv;
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
		Iterator_t _argv)
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
	Item_t nextImpl(int8_t* stateBlock);
	void resetImpl(int8_t* stateBlock);
	void releaseResourcesImpl(int8_t* stateBlock);
	std::ostream&  _show(std::ostream&) const;

protected:
	Iterator_t argv;
	uint32_t cp;
	std::vector<char> v;
	char * c;
	uint16_t vLength;
}; /*class StringToCodepointsIterator*/


/**
 * 7.3.2 fn:compare
 * --------------------*/


/**
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
class CodepointEqualIterator : public Batcher<CodepointEqualIterator>
{
public:
	CodepointEqualIterator(
		yy::location loc,
		Iterator_t _argv0,
		Iterator_t _argv1)
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
	Item_t nextImpl(int8_t* stateBlock);
	void resetImpl(int8_t* stateBlock);
	void releaseResourcesImpl(int8_t* stateBlock);
	std::ostream&  _show(std::ostream&) const;

protected:
	Iterator_t argv0;
	Iterator_t argv1;

	std::vector<char> v0;
	std::vector<char> v1;
	char * c0;
	char * c1;
	int16_t vLength;
	bool finish;
};/*class CodepointEqualIterator */

/**
 * 7.4.1 fn:concat
 * --------------------*/
class ConcatFnIterator : public Batcher<ConcatFnIterator>
{
public:
	ConcatFnIterator(
		yy::location loc,
		const vector<Iterator_t>& _argv)
	:
	Batcher<ConcatFnIterator>(loc),
		argv(_argv),
		currit_h(NULL),
		cursor(0),
		res()
	{}

	ConcatFnIterator(
		const ConcatFnIterator& concatFn_it)
	:
	Batcher<ConcatFnIterator>(concatFn_it),
		argv(concatFn_it.argv),
		currit_h(concatFn_it.currit_h),
		cursor(concatFn_it.cursor),
		res(concatFn_it.res)
	{}

		~ConcatFnIterator() {}

public:
	Item_t nextImpl(int8_t* stateBlock);
	void resetImpl(int8_t* stateBlock);
	void releaseResourcesImpl(int8_t* stateBlock);
	std::ostream&  _show(std::ostream&) const;

protected:
	std::vector<Iterator_t> argv;
	Iterator_t currit_h;
	uint32_t cursor;
	std::string res;

}; /*class ConcatFnIterator*/


/**
 * 7.4.2 fn:string-join
 * --------------------*/
class StringJoinIterator : public Batcher<StringJoinIterator>
{
public:
	StringJoinIterator(
		yy::location loc,
		const vector<Iterator_t>& _argv)
	:
		Batcher<StringJoinIterator>(loc),
		argv(_argv),
		currit_h(NULL),
		cursor(0),
		res()
	{}

	StringJoinIterator(
		const StringJoinIterator& stringJoin_it)
	:
		Batcher<StringJoinIterator>(stringJoin_it),
		argv(stringJoin_it.argv),
		currit_h(stringJoin_it.currit_h),
		cursor(stringJoin_it.cursor),
		res(stringJoin_it.res)
	{}

		~StringJoinIterator() {}

public:
	Item_t nextImpl(int8_t* stateBlock);
	void resetImpl(int8_t* stateBlock);
	void releaseResourcesImpl(int8_t* stateBlock);
	std::ostream&  _show(std::ostream&) const;

protected:
	std::vector<Iterator_t> argv;
	Iterator_t currit_h;
	uint32_t cursor;
	std::string res;

}; /*class StringJoinIterator*/

}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
