/**
 * @copyright
 * ========================================================================
 *	Copyright FLWOR Foundation
 * ========================================================================
 *
 * @author Sorin Nasoi (sorin.nasoi@ipdevel.ro)
 * @file functions/StringsImpl.h
 *
 */

#ifndef XQP_STRINGS_IMPL_H
#define XQP_STRINGS_IMPL_H

#include "context/common.h"
#include "runtime/base/iterator.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"


#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

namespace xqp {

class zorba;

/*______________________________________________________________________
 *
 * 7.2 Functions to Assemble and Disassemble Strings
 *_______________________________________________________________________*/

 /*
 * 7.2.1 fn:codepoints-to-string
 * -------------------- */
/* begin class CodepointsToStringIterator */
class CodepointsToStringIterator : public UnaryBaseIterator<CodepointsToStringIterator>{
public:
		CodepointsToStringIterator ( const yy::location& loc, PlanIter_t& arg )
	:
		UnaryBaseIterator<CodepointsToStringIterator>( loc, arg ){};

		~CodepointsToStringIterator(){};
public:
		Item_t nextImpl(PlanState& planState);
};
/* end class CodepointsToStringIterator */


/*
 * 7.2.2 fn:string-to-codepoints
 * --------------------*/
/*begin class StringToCodepointsIterator*/
class StringToCodepointsIterator : public UnaryBaseIterator<StringToCodepointsIterator>
{
public:
		StringToCodepointsIterator ( const yy::location& loc, PlanIter_t& arg )
	:
		UnaryBaseIterator<StringToCodepointsIterator>( loc, arg ){}

	~StringToCodepointsIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
		void resetImpl(PlanState& planState);
		void releaseResourcesImpl(PlanState& planState);

		virtual int32_t getStateSize();
		virtual int32_t getStateSizeOfSubtree();
		virtual void setOffset(PlanState& planState, int32_t& offset);

protected:
	class StringToCodepointsState : public PlanIteratorState
	{
	private:
		std::vector<uint32_t> resVector;
		uint32_t iter;
	public:
		void init();
		void reset();

		void setIterator(uint32_t);
		void setVector(std::vector<uint32_t> vect);
		uint32_t getItem(uint32_t iter);
		uint32_t getVectSize();
		uint32_t getIterator();
	};
};
/*end class StringToCodepointsIterator*/

/*______________________________________________________________________
 *
 * 7.3 Equality and Comparison of Strings
 *_______________________________________________________________________*/

/*
 * 7.3.2 fn:compare
 * --------------------*/
/* begin class CompareStrIterator */
class CompareStrIterator: public NaryBaseIterator<CompareStrIterator> {
public:
		CompareStrIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<CompareStrIterator>( loc, args ){}

		~CompareStrIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/* end class CompareStrIterator */

/*
 * 7.3.3 fn:codepoint-equal
 * --------------------*/
/*begin class CodepointEqualIterator */
class CodepointEqualIterator : public BinaryBaseIterator<CodepointEqualIterator>{
public:
	CodepointEqualIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
	:
	BinaryBaseIterator<CodepointEqualIterator>(loc, arg0, arg1){}

	~CodepointEqualIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class CodepointEqualIterator */

/*______________________________________________________________________
 *
 * 7.4 Functions on String Values
 *_______________________________________________________________________*/

/*
 * 7.4.1 fn:concat
 * --------------------*/
/*begin class ConcatStrIterator */
class ConcatStrIterator: public NaryBaseIterator<ConcatStrIterator> {
public:
		ConcatStrIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<ConcatStrIterator>( loc, args ){}

		~ConcatStrIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class ConcatStrIterator */


/*
 * 7.4.2 fn:string-join
 * --------------------*/
/*begin class StringJoinIterator*/
class StringJoinIterator : public BinaryBaseIterator<StringJoinIterator>{
public:
	StringJoinIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
	:
	BinaryBaseIterator<StringJoinIterator>(loc, arg0, arg1){}

	~StringJoinIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class StringJoinIterator*/

/*
 * 7.4.3 fn:substring
 * --------------------*/
/*begin class SubstringIterator*/
class SubstringIterator : public NaryBaseIterator<SubstringIterator>{
public:
	SubstringIterator( const yy::location loc, std::vector<PlanIter_t>& args )
	:
	NaryBaseIterator<SubstringIterator>( loc, args ){}

	~SubstringIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class SubstringIterator*/

/*
 * 7.4.4 fn:string-length
 * --------------------*/
/*begin class StringLengthIterator*/
class StringLengthIterator : public UnaryBaseIterator<StringLengthIterator>{
public:
	StringLengthIterator(const yy::location loc,  PlanIter_t& arg0)
	:
	UnaryBaseIterator<StringLengthIterator>(loc, arg0){}

	~StringLengthIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class StringLengthIterator*/

/*
 * 7.4.5 fn:normalize-space
 * --------------------*/
/*begin class NormalizeSpaceIterator*/
class NormalizeSpaceIterator : public UnaryBaseIterator<NormalizeSpaceIterator>{
public:
	NormalizeSpaceIterator(const yy::location loc,  PlanIter_t& arg0)
	:
	UnaryBaseIterator<NormalizeSpaceIterator>(loc, arg0){}

	~NormalizeSpaceIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class NormalizeSpaceIterator*/

/*
 * 7.4.6 fn:normalize-unicode
 * --------------------*/
/*begin class NormalizeUnicodeIterator*/
class NormalizeUnicodeIterator : public BinaryBaseIterator<NormalizeUnicodeIterator>{
public:
	NormalizeUnicodeIterator( const yy::location loc,  PlanIter_t& arg0,  PlanIter_t& arg1 )
	:
	BinaryBaseIterator<NormalizeUnicodeIterator>(loc, arg0, arg1){}

	~NormalizeUnicodeIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class NormalizeUnicodeIterator*/

/*
 * 7.4.7 fn:upper-case
 * --------------------*/
/*begin class UpperCaseIterator*/
class UpperCaseIterator : public UnaryBaseIterator<UpperCaseIterator>{
public:
	UpperCaseIterator(const yy::location loc,  PlanIter_t& arg0)
	:
	UnaryBaseIterator<UpperCaseIterator>(loc, arg0){}

	~UpperCaseIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class UpperCaseIterator*/

/*
 * 7.4.8 fn:lower-case
 * --------------------*/
/*begin class LowerCaseIterator*/
class LowerCaseIterator : public UnaryBaseIterator<LowerCaseIterator>{
public:
	LowerCaseIterator(const yy::location loc,  PlanIter_t& arg0)
	:
	UnaryBaseIterator<LowerCaseIterator>(loc, arg0){}

	~LowerCaseIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class LowerCaseIterator*/

 /*
 * 7.4.9 fn:translate
 * -------------------- */
/*begin class TranslateIterator*/
class TranslateIterator: public NaryBaseIterator<TranslateIterator> {
public:
		TranslateIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<TranslateIterator>( loc, args ){}

		~TranslateIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class TranslateIterator*/

/*______________________________________________________________________
 *
 * 7.5 Functions Based on Substring Matching
 *_______________________________________________________________________*/

 /*
 * 7.5.1 fn:contains
 * -------------------- */
/*begin class ContainsIterator*/
class ContainsIterator: public NaryBaseIterator<ContainsIterator> {
public:
		ContainsIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<ContainsIterator>( loc, args ){}

		~ContainsIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class ContainsIterator*/

 /*
 * 7.5.2 fn:starts-with
 * -------------------- */
/*begin class StartsWithIterator*/
class StartsWithIterator: public NaryBaseIterator<StartsWithIterator> {
public:
		StartsWithIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<StartsWithIterator>( loc, args ){}

		~StartsWithIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class StartsWithIterator*/

 /*
 * 7.5.3 fn:ends-with
 * -------------------- */
/*begin class EndsWithIterator*/
class EndsWithIterator: public NaryBaseIterator<EndsWithIterator> {
public:
		EndsWithIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<EndsWithIterator>( loc, args ){}

		~EndsWithIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class EndsWithIterator*/

 /*
 * 7.5.4 fn:substring-before
 * -------------------- */
/*begin class SubstringBeforeIterator*/
class SubstringBeforeIterator: public NaryBaseIterator<SubstringBeforeIterator> {
public:
		SubstringBeforeIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<SubstringBeforeIterator>( loc, args ){}

		~SubstringBeforeIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class SubstringBeforeIterator*/

 /*
 * 7.5.5 fn:substring-after
 * -------------------- */
/*begin class SubstringAfterIterator*/
class SubstringAfterIterator: public NaryBaseIterator<SubstringAfterIterator> {
public:
		SubstringAfterIterator ( const yy::location& loc, std::vector<PlanIter_t>& args )
	:
		NaryBaseIterator<SubstringAfterIterator>( loc, args ){}

		~SubstringAfterIterator() {};
public:
		Item_t nextImpl(PlanState& planState);
};
/*end class SubstringAfterIterator*/
}/*namespace xqp*/
#endif /* XQP_STRINGS_IMPL_H */
