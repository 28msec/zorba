/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef XQP_BOOLEAN_IMPL_H
#define XQP_BOOLEAN_IMPL_H

#include "context/common.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"

namespace xqp
{

  class zorba;
  class GenericCast;

  /*______________________________________________________________________
  |
  | 15.1.1 fn:boolean
  | fn:boolean($arg as item()*) as xs:boolean
  |
  | Computes the effective boolean value of the sequence $arg.
  |_______________________________________________________________________*/
  class FnBooleanIterator : public UnaryBaseIterator<FnBooleanIterator, PlanIteratorState>
  {
    private:
      bool theNegate;

    public:
      FnBooleanIterator ( const yy::location& loc, PlanIter_t& aIter, bool aNegate = false );
      virtual ~FnBooleanIterator();

      /**
       * Static function which computes the effective boolean value of a passed iterator.
       *
       * @param loc location of the iterator which invokes this function
       * @param planState
       * @param iterator
       * @param negate optinal parameter which negates the effective boolean value (default == false)
       * @return effective boolean value
       */
      static Item_t effectiveBooleanValue ( const yy::location& loc, PlanState& planState, PlanIter_t&, bool negate = false);

      Item_t nextImpl(PlanState& planState);

      virtual void accept(PlanIterVisitor&) const;
  };
  
  class LogicIterator : public BinaryBaseIterator<LogicIterator, PlanIteratorState>
  {
  public:
    enum LogicType {
      AND, OR
    };
    
    private:
      LogicType theLogicType;
      
    public:
      LogicIterator ( const yy::location& loc, PlanIter_t aChild0, PlanIter_t aChild1, LogicType aLogicType);
      virtual ~LogicIterator();
      
      Item_t nextImpl(PlanState& planState);
      
      virtual void accept(PlanIterVisitor&) const;
  }; /* class LogicIterator */
  
  class CompareIterator : public BinaryBaseIterator<CompareIterator, PlanIteratorState>
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
      CompareType theCompType;

    public:
      CompareIterator ( const yy::location& loc, PlanIter_t theChild0, PlanIter_t theChild1, CompareType aCompType );
      virtual ~CompareIterator();

      Item_t nextImpl(PlanState& planState);
      
      bool isValueComparison();
      bool isGeneralComparison();
      bool isNodeComparison();
      
    private:
      static std::pair<Item_t, Item_t> valueCasting(Item_t aItem0, Item_t aItem1);
      static std::pair<Item_t, Item_t> generalCasting(Item_t aItem0, Item_t aItem1);
      static std::pair<Item_t, Item_t> typePromotion(Item_t aItem0, Item_t aItem1);
      static bool boolResult(int8_t aCompValue, CompareType aCompType);
      
    public:
      /**
       * Compares two items (without castings and promotions which are used in general 
       * and value comparison).
       * @param item0 
       * @param item1 
       * @param aCollation optional collation parameter (passed as pointer to make it possible to be set to 0)
       * @return -1, if item0 &lt; item1
       *          0, if item0 == item1
       *          1, if item0 &gt; item1
       *          2, if item0 not equal, not bigger, not smaller item1 (special case when an Item has the value NaN)
       *         -2, if it is not possible to compare the values the two passed items
       */
      static int8_t compare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Value Comparison on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return -1 (smaller), 0 (equal), 1 (bigger), 
       *          2 (not equal, not bigger, not smaller), -2 (value comparison not possible)
       */
      static int8_t valueCompare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * General Comparison on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return -1 (smaller), 0 (equal), 1 (bigger), 
       *          2 (not equal, not bigger, not smaller), -2 (general comparison not possible)
       */
      static int8_t generalCompare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Checks if the two passed items contains the same value (without castings and promotions which are used in general 
       * and value comparison).
       * @param item0 
       * @param item1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return  0, if item0 == item1
       *          1, if item0 != item1
       *         -2, if it is not possible to compare the values of the passed items
       */
      static int8_t equal(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Value Equal on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation optional collation parameter (passed as pointer to make it possible to be set to 0)
       * @return 0 (equal), 1 (not equal), -2 (value equal not possible)
       */
      static int8_t valueEqual(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * General Equal on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return 0 (equal), 1 (not equal), -2 (general equal not possible)
       */
      static int8_t generalEqual(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Value comparison of the passed two items with the operator 
       * which is defined in the CompareIterator object.
       *
       * @param item0 
       * @param item1 
       * @param aCompType
       * @param aCollation optional collation parameter
       * @return 
       */
      static bool valueComparison(const Item_t& aItem0, const Item_t& aItem1, 
                                  CompareType aCompType, xqpString* aCollation = 0);
      
      /**
       * General comparison of the passed two items with the operator 
       * which is defined in the CompareIterator object.
       *
       * @param item0 
       * @param item1 
       * @param aCompType
       * @param aCollation optional collation parameter
       * @return 
       */
      static bool generalComparison(const Item_t& aItem0, const Item_t& aItem_1,
                                    CompareType aCompType, xqpString* aCollation = 0);

      virtual void accept(PlanIterVisitor&) const;
  }; /* class CompareIterator */

  NARY_ITER(OpIsSameNodeIterator); 
  NARY_ITER(OpNodeBeforeIterator);
  NARY_ITER(OpNodeAfterIterator);

}

#endif
