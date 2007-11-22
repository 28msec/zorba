/**
 * @file NumericsImpl.h
 * @authors Paul Pedersen (pcp071098@yahoo.com)
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

#ifndef XQP_NUMERICS_IMPL_H
#define XQP_NUMERICS_IMPL_H

#include "context/common.h"
#include "runtime/base/iterator.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/unarybase.h"

namespace xqp
{

	class zorba;
	class GenericCast;

	/** Operations for Add
		*/
	class AddOperations
	{
		public:
			static Item_t opDouble (const yy::location* , Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};
	
	/** Operations for Subtract
		*/
	class SubtractOperations
	{
		public:
			static Item_t opDouble (const yy::location* ,  Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};
	
	/** Operations for Multiply
		*/
	class MultiplyOperations
	{
		public:
			static Item_t opDouble (const yy::location* ,  Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};
	
	/** Operations for Division
		*/
	class DivideOperations
	{
		public:
			static Item_t opDouble (const yy::location* ,  Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};
	
	/** Operations for Integer Division
		*/
	class IntegerDivideOperations
	{
		public:
			static Item_t opDouble (const yy::location* ,  Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};
	
	/** Operations for Mod
		*/
	class ModOperations
	{
		public:
			static Item_t opDouble (const yy::location* ,  Item_t, Item_t );
			static Item_t opFloat (const yy::location* ,  Item_t, Item_t );
			static Item_t opDecimal (const yy::location* ,  Item_t, Item_t );
			static Item_t opInteger (const yy::location* ,  Item_t, Item_t );
	};

	/**
		* Generic Iterator for Arithmetic Operations. Specific operation (add, mod, etc.) is passed over the template parameter.
		*/
	template < typename Operations >
	class ArithmeticIterator : public BinaryBaseIterator<ArithmeticIterator<Operations> >
	{
		public:
			ArithmeticIterator ( const yy::location&, PlanIter_t&, PlanIter_t& );
			~ArithmeticIterator();

			Item_t nextImpl(PlanState&);
	}; /* class ArithmeticIterator */

	/*______________________________________________________________________
	|
	| 6.2 Operators on Numeric Values
	|_______________________________________________________________________*/

// 6.2.1 op:numeric-add
// --------------------



// 6.2.2 op:numeric-subtract
// -------------------------



// 6.2.3 op:numeric-multiply
// -------------------------


// 6.2.4 op:numeric-divide
// -----------------------


// 6.2.5 op:numeric-integer-divide
// -------------------------------


// 6.2.6 op:numeric-mod
// --------------------


// 6.2.7 op:numeric-unary-plus
// ---------------------------


// 6.2.8 op:numeric-unary-minus
// ----------------------------
	class OpNumericUnaryIterator : public UnaryBaseIterator<OpNumericUnaryIterator>
	{
		private:
			bool thePlus;

		public:
			OpNumericUnaryIterator ( const yy::location& loc, PlanIter_t& aChild, bool aPlus);
			virtual ~OpNumericUnaryIterator();

		public:	// iterator interface
			Item_t nextImpl(PlanState& planState);
	};



	/*______________________________________________________________________
	|
	| 6.3 Comparison Operators on Numeric Values
	|_______________________________________________________________________*/

// 6.3.1 op:numeric-equal
// -------------------------


// 6.3.2 op:numeric-less-than
// 6.3.3 op:numeric-greater-than


	/*______________________________________________________________________
	|
	| 6.4 Functions on Numeric Values
	|_______________________________________________________________________*/

// 6.4.1 fn:abs
	class FnAbsIterator : public UnaryBaseIterator<FnAbsIterator>
	{
  	public:
			FnAbsIterator ( const yy::location& loc, PlanIter_t& theChild );
			virtual ~FnAbsIterator();

		public:
			Item_t nextImpl(PlanState& planState);
	};

// 6.4.2 fn:ceiling
// 6.4.3 fn:floor
// 6.4.4 fn:round
// 6.4.5 fn:round-half-to-even

	
	/**
	 * Helper Iterator to produce a defined amount of integer items
	 */
	class ZorNumGen : public Batcher<ZorNumGen>
	{
	public:
		ZorNumGen ( const yy::location& loc);
		~ZorNumGen();
		Item_t nextImpl(PlanState& planState);
		void resetImpl(PlanState& planState);
		void releaseResourcesImpl(PlanState& planState);
		
		virtual int32_t getStateSize();
		virtual int32_t getStateSizeOfSubtree();
		virtual void setOffset(PlanState& planState, int32_t& offset);
		
	protected:
		class ZorNumGenState : public PlanIteratorState
		{
		private:
			int32_t curNumber;
		public:
			void init();
			void reset();
			
			int32_t getCurNumber();
			void setCurNumber(int32_t);
		};
	};

}	/* namespace xqp */
#endif	/* XQP_NUMERICS_H */
