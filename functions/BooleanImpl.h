/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_IMPL_H
#define XQP_BOOLEAN_IMPL_H

#include "context/common.h"
#include "types/sequence_type.h"
#include "runtime/batching.h"
#include "util/rchandle.h"

namespace xqp
{

	class zorba;
	class GenericCast;

	/*______________________________________________________________________
	|
	|	15.1.1 fn:boolean
	|	fn:boolean($arg as item()*) as xs:boolean
	|
	|	Computes the effective boolean value of the sequence $arg.
	|_______________________________________________________________________*/
	class FnBooleanIterator : public Batcher<FnBooleanIterator>
	{
		private:
			Iterator_t arg0_;
// 	bool donef;

		public:
			FnBooleanIterator ( yy::location loc, Iterator_t arg0 )
					:
					Batcher<FnBooleanIterator> ( loc ), arg0_ ( arg0 ) {}
			~FnBooleanIterator() {}

			Item_t nextImpl();
			void resetImpl();
			void releaseResourcesImpl();

			std::ostream&  _show ( std::ostream& ) const;
	};
	
	


	class CompareIterator : public Batcher<CompareIterator>
	{
		public:
			enum CompareTypes{
				VALUE_EQUAL, GENERAL_EQUAL, NODE_EQUAL,
				VALUE_NOT_EQUAL, GENERAL_NOT_EQUAL, NODE_NOT_EQUAL,
				VALUE_LESS, GENERAL_LESS,
				VALUE_LESS_EQUAL, GENERAL_LESS_EQUAL,
				VALUE_GREATER, GENERAL_GREATER,
				VALUE_GREATER_EQUAL, GENERAL_GREATER_EQUAL
			};
			
		private:
			Iterator_t iter0;
			Iterator_t iter1;
			
			GenericCast* genericCast;
			CompareTypes compareType;

		public:
			CompareIterator ( yy::location loc, Iterator_t arg0, Iterator_t arg1, CompareTypes argCompType )
					:
					Batcher<CompareIterator> ( loc ), iter0 ( arg0 ), iter1 ( arg1 ), compareType(argCompType) {}

			

			Item_t nextImpl();
			void resetImpl();
			void releaseResourcesImpl();
			
			/**
			 * Atomic comparison of the two passed (atomic) items.
			 *
			 * @param item0 atomic item
			 * @param item1 atomic item
			 * @return -1 if item0 smaller item1
			 *					0 if item0 equal item1 
			 *					1 if item0 greater item1
			 */
			static int atomicCompare(Item_t item0, Item_t item1);
			
		private:
			void constructor();
			void deconstructor();
	}; /* class CompareIterator */

}

#endif
