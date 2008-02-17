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

#include "common/shared_types.h"
#include "runtime/base/noarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/unarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/narybase.h"

namespace xqp
{
  /**
    * Generic Iterator for Numeric Arithmetic Operations. Specific operation (add, mod, etc.) is passed over the template parameter.
    */
  template < class Operation >
  class NumArithIterator 
    : public BinaryBaseIterator<NumArithIterator<Operation>, PlanIteratorState>
  {
    public:
      NumArithIterator ( const yy::location&, PlanIter_t&, PlanIter_t& );
      virtual ~NumArithIterator(){}

      Item_t nextImpl(PlanState&) const;
      
      virtual void accept(PlanIterVisitor&) const;

      /**
       * Computes Operation on passed items.
       *
       * @param loc
       * @param item0
       * @param item1
       */
      static Item_t
      compute(const yy::location& loc, Item_t item0, Item_t item1);
      
      /**
       * Computes Operation on passed items.
       *
       * @param loc
       * @param item0 Atomized Item
       * @param type0 Type of item0
       * @param item1 Atomized Item
       * @param type1 Type of item1
       */
      static Item_t
      computeAtomic
        (const yy::location&, Item_t item0, xqtref_t type0, Item_t item1, xqtref_t type1);

  }; /* class NumArithIterator */

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

  /* begin 10.6 Arithmetic Operators on Durations
  10.6 Arithmetic Operators on Durations
  10.6.1 op:add-yearMonthDurations
  10.6.2 op:subtract-yearMonthDurations
  10.6.3 op:multiply-yearMonthDuration
  10.6.4 op:divide-yearMonthDuration
  10.6.5 op:divide-yearMonthDuration-by-yearMonthDuration
  10.6.6 op:add-dayTimeDurations
  10.6.7 op:subtract-dayTimeDurations
  10.6.8 op:multiply-dayTimeDuration
  10.6.9 op:divide-dayTimeDuration
  10.6.10 op:divide-dayTimeDuration-by-dayTimeDuration
  - end 10.6 Arithmetic Operators on Durations*/
  

// 6.2.8 op:numeric-unary-minus
// ----------------------------
  class OpNumericUnaryIterator : public UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>
  {
    private:
      bool thePlus;

    public:
      OpNumericUnaryIterator ( const yy::location& loc, PlanIter_t& aChild, bool aPlus);
      virtual ~OpNumericUnaryIterator();

    public: // iterator interface
      Item_t nextImpl(PlanState& planState) const;
      
      virtual void accept(PlanIterVisitor&) const;
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
  NARY_ITER(FnAbsIterator);

// 6.4.2 fn:ceiling
  NARY_ITER(FnCeilingIterator);

// 6.4.3 fn:floor
  NARY_ITER(FnFloorIterator);
  
// 6.4.4 fn:round   
  NARY_ITER(FnRoundIterator);
  
// 6.4.5 fn:round-half-to-even
  class FnRoundHalfToEvenIterator : public BinaryBaseIterator<FnRoundHalfToEvenIterator, PlanIteratorState>
  {
    public:
      FnRoundHalfToEvenIterator(const yy::location&, PlanIter_t&, PlanIter_t&);
      virtual ~FnRoundHalfToEvenIterator();

      Item_t nextImpl(PlanState&) const;
      virtual void accept(PlanIterVisitor&) const;
  };

  class ZorNumGenState : public PlanIteratorState
  {
  private:
    int32_t curNumber;
  public:
    void init(PlanState&);
    void reset(PlanState&);
    
    int32_t getCurNumber();
    void setCurNumber(int32_t);
  };
  
  /**
   * Helper Iterator to produce a defined amount of integer items
   */
  class ZorNumGen : public NoaryBaseIterator<ZorNumGen, ZorNumGenState> 
  {
  public:
    ZorNumGen ( const yy::location& loc);
    ~ZorNumGen();

    Item_t nextImpl(PlanState& planState) const;

    virtual void accept(PlanIterVisitor&) const;
  };

} /* namespace xqp */
#endif  /* XQP_NUMERICS_H */
