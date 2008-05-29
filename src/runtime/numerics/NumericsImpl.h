/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_NUMERICS_IMPL_H
#define ZORBA_NUMERICS_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/noarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/unarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring
#include "runtime/base/narybase.h"

namespace zorba
{
  class RuntimeCB;

  /**
    * Generic Iterator for Numeric Arithmetic Operations. Specific operation (add, mod, etc.) is passed over the template parameter.
    */
  template < class Operation >
  class NumArithIterator 
    : public BinaryBaseIterator<NumArithIterator<Operation>, PlanIteratorState>
  {
    public:
      NumArithIterator ( const QueryLoc&, PlanIter_t&, PlanIter_t& );
      virtual ~NumArithIterator(){}

      bool nextImpl(store::Item_t& result, PlanState&) const;
      
      virtual void accept(PlanIterVisitor&) const;

      /**
       * Computes Operation on passed items.
       *
       * @param loc
       * @param item0
       * @param item1
       */
      static bool
      compute(store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc& loc, store::Item *item0, store::Item *item1);
      
      /**
       * Computes Operation on passed items.
       *
       * @param loc
       * @param item0 Atomized Item
       * @param type0 Type of item0
       * @param item1 Atomized Item
       * @param type1 Type of item1
       */
      static bool
      computeAtomic
        (store::Item_t& result, RuntimeCB* aRuntimeCB, const QueryLoc&, store::Item *item0, xqtref_t type0, store::Item *item1, xqtref_t type1);

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

// 6.2.8 op:numeric-unary-minus
// ----------------------------
  class OpNumericUnaryIterator : public UnaryBaseIterator<OpNumericUnaryIterator, PlanIteratorState>
  {
    private:
      bool thePlus;

    public:
      OpNumericUnaryIterator ( const QueryLoc& loc, PlanIter_t& aChild, bool aPlus);
      virtual ~OpNumericUnaryIterator();

    public: // iterator interface
      bool nextImpl(store::Item_t& result, PlanState& planState) const;
      
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
  NARY_ITER(FnRoundHalfToEvenIterator);

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
    ZorNumGen ( const QueryLoc& loc);
    ~ZorNumGen();

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor&) const;
  };

} /* namespace zorba */
#endif  /* ZORBA_NUMERICS_H */
