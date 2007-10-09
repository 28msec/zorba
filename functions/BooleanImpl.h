/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_IMPL_H
#define XQP_BOOLEAN_IMPL_H

#include "context/common.h"
#include "types/sequence_type.h"
#include "runtime/batching.h"

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
			bool negate;

		public:
			FnBooleanIterator ( const yy::location& loc, Iterator_t& arg0, bool negate_arg = false );
			~FnBooleanIterator();

			/**
			 * Static function which computes the effective boolean value of a passed iterator.
			 *
			 * @param loc location of the iterator which invokes this function
			 * @param stateBlock
			 * @param iterator
			 * @param negate optinal parameter which negates the effective boolean value (default == false)
			 * @return effective boolean value
			 */
			static Item_t effectiveBooleanValue ( const yy::location& loc, int8_t* stateBlock, Iterator_t&, bool negate = false);

			Item_t nextImpl(int8_t* stateBlock);
			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);

			std::ostream&  _show ( std::ostream& ) const;
	};
	
	class LogicIterator : public Batcher<LogicIterator>
	{
	public:
		enum LogicType {
			AND, OR
		};
		
		private:
			Iterator_t iterLeft;
			Iterator_t iterRight;
			
			LogicType logicType;
			
		public:
			LogicIterator ( const yy::location& loc, Iterator_t arg0, Iterator_t arg1, LogicType lt);
			~LogicIterator();
			
			Item_t nextImpl(int8_t* stateBlock);
			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);
	}; /* class LogicIterator */
	
	class CompareIterator : public Batcher<CompareIterator>
	{
		public:
			enum CompareType{
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
			CompareType compareType;

		public:
			CompareIterator ( const yy::location& loc, Iterator_t arg0, Iterator_t arg1, CompareType argCompType );
			~CompareIterator();

			Item_t nextImpl(int8_t* stateBlock);
			void resetImpl(int8_t* stateBlock);
			void releaseResourcesImpl(int8_t* stateBlock);
			
			bool isValueComparison();
			bool isGeneralComparison();
			bool isNodeComparison();
			
			/**
			 * Compares two items
			 * @param item0 
			 * @param item1 
			 * @return -1, if item0 &lt; item1
			 *				  0, if item0 == item1
			 *				 	1, if item0 &gt; item1
			 *				 -2, if it is not possible to compare the two passed items
			 */
			static int32_t compare(const Item_t& item0, const Item_t& item1);
			
			/**
			 * Checks if the two passed items contains the same value
			 * @param item0 
			 * @param item1 
			 * @return 	0, if item0 == item1
			 *				  1, if item0 != item1
			 *				 -2, if it is not possible to compare the values of the passed items
			 */
			static int32_t equal(const Item_t& item0, const Item_t& item1);
		private:
			/**
			 * Value comparison of the passed two items with the operator 
			 * which is defined in the CompareIterator object.
			 *
			 * @param item0 
			 * @param item1 
			 * @return 
			 */
			bool valueComparison(Item_t item0, Item_t item1);
			
			/**
			 * General comparison of the passed two items with the operator 
			 * which is defined in the CompareIterator object.
			 *
			 * @param item0 
			 * @param item1 
			 * @return 
			 */
			bool generalComparison(Item_t item0, Item_t item_1);
	}; /* class CompareIterator */

}

#endif
