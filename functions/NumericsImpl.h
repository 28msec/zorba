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
#include "runtime/batching.h"


namespace xqp
{

	class zorba;
	class GenericCast;

	template <class IterType>
	class BinaryBaseIterator : public Batcher<IterType>
	{
		protected:
			Iterator_t iter0;
			Iterator_t iter1;
			
		public:
			BinaryBaseIterator
				( const yy::location& loc, Iterator_t& arg0_, Iterator_t& arg1_ );

			virtual ~BinaryBaseIterator();

			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);
			
			virtual int32_t getStackSize();
			virtual int32_t getStackSizeOfSubtree();
			virtual void setOffset(int32_t& offset);
	};

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
		private:
			GenericCast* genericCast;
		public:
			ArithmeticIterator ( const yy::location& loc, Iterator_t& iter0, Iterator_t& iter1 );
			~ArithmeticIterator();

			Item_t nextImpl(int8_t* stateBlock);
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
	class OpNumericUnaryIterator : public Batcher<OpNumericUnaryIterator>
	{
		private:
			Iterator_t arg0;
			GenericCast* genericCast;
			bool plus;

		public:
			OpNumericUnaryIterator ( yy::location loc, Iterator_t iter, bool plus_arg);
			~OpNumericUnaryIterator();

		public:	// iterator interface
			Item_t nextImpl(int8_t* stateBlock);
			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);
			std::ostream&  _show ( std::ostream& ) const;
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
	class FnAbsIterator : public Batcher<FnAbsIterator>
	{
		private:
			Iterator_t arg0;
			GenericCast* genericCast;

		public:
			FnAbsIterator ( yy::location loc, Iterator_t iter );
			~FnAbsIterator();

		public:
			Item_t nextImpl(int8_t* stateBlock);
			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);
			std::ostream&  _show ( std::ostream& ) const;
	};

// 6.4.2 fn:ceiling
// 6.4.3 fn:floor
// 6.4.4 fn:round
// 6.4.5 fn:round-half-to-even


}	/* namespace xqp */
#endif	/* XQP_NUMERICS_H */
