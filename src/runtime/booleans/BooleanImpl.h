/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#ifndef ZORBA_BOOLEAN_IMPL_H
#define ZORBA_BOOLEAN_IMPL_H

#include <zorbatypes/xqpstring.h>

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/binarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/booleans/compare_types.h"

namespace zorba
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
      FnBooleanIterator ( const QueryLoc& loc, PlanIter_t& aIter, bool aNegate = false );
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
      static store::Item_t effectiveBooleanValue ( const QueryLoc& loc, PlanState& planState, const PlanIterator* , bool negate = false);

      store::Item_t nextImpl(PlanState& planState) const;

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
      LogicIterator ( const QueryLoc& loc, PlanIter_t aChild0, PlanIter_t aChild1, LogicType aLogicType);
      virtual ~LogicIterator();
      
      store::Item_t nextImpl(PlanState& planState) const;
      
      virtual void accept(PlanIterVisitor&) const;
  }; /* class LogicIterator */
  
  class CompareIterator : public BinaryBaseIterator<CompareIterator, PlanIteratorState>
  {
    private:
      CompareConsts::CompareType theCompType;

    public:
      CompareIterator ( const QueryLoc& loc, PlanIter_t theChild0, PlanIter_t theChild1, CompareConsts::CompareType aCompType );
      virtual ~CompareIterator();

      store::Item_t nextImpl(PlanState& planState) const;
      
      bool isValueComparison() const;
      bool isGeneralComparison() const;
      bool isNodeComparison() const;
      
    private:
      static std::pair<store::Item_t, store::Item_t> valueCasting(store::Item_t aItem0, store::Item_t aItem1);
      static std::pair<store::Item_t, store::Item_t> generalCasting(store::Item_t aItem0, store::Item_t aItem1);
      static std::pair<store::Item_t, store::Item_t> typePromotion(store::Item_t aItem0, store::Item_t aItem1);
      static bool boolResult(int8_t aCompValue, CompareConsts::CompareType aCompType);
      
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
      static int8_t compare(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Value Comparison on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return -1 (smaller), 0 (equal), 1 (bigger), 
       *          2 (not equal, not bigger, not smaller), -2 (value comparison not possible)
       */
      static int8_t valueCompare(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * General Comparison on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return -1 (smaller), 0 (equal), 1 (bigger), 
       *          2 (not equal, not bigger, not smaller), -2 (general comparison not possible)
       */
      static int8_t generalCompare(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
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
      static int8_t equal(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * Value Equal on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation optional collation parameter (passed as pointer to make it possible to be set to 0)
       * @return 0 (equal), 1 (not equal), -2 (value equal not possible)
       */
      static int8_t valueEqual(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
      /**
       * General Equal on the passed items
       * @param aItem0 
       * @param aItem1 
       * @param aCollation options collatino parameter (passed as pointer to make it possible to be set to 0)
       * @return 0 (equal), 1 (not equal), -2 (general equal not possible)
       */
      static int8_t generalEqual(const store::Item_t& aItem0, const store::Item_t& aItem1, xqpString* aCollation = 0);
      
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
      static bool valueComparison(const store::Item_t& aItem0, const store::Item_t& aItem1, 
                                  CompareConsts::CompareType aCompType, xqpString* aCollation = 0);
      
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
      static bool generalComparison(const store::Item_t& aItem0, const store::Item_t& aItem_1,
                                    CompareConsts::CompareType aCompType, xqpString* aCollation = 0);

      virtual void accept(PlanIterVisitor&) const;
  }; /* class CompareIterator */

  NARY_ITER(OpIsSameNodeIterator); 
  NARY_ITER(OpNodeBeforeIterator);
  NARY_ITER(OpNodeAfterIterator);

}

#endif
