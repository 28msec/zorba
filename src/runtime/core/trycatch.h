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
#ifndef ZORBA_TRYCATCH_H
#define ZORBA_TRYCATCH_H

#include <vector>

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"

namespace zorba
{

  class TryCatchIteratorState : public  PlanIteratorState {
    public:
      TryCatchIteratorState();
      ~TryCatchIteratorState();
      
      void init(PlanState&);
      void reset(PlanState&);

      // used for evaluating the target expression eagerly
      store::TempSeq_t  theTargetSequence;
      store::Iterator_t theTempIterator;
      PlanIter_t theCatchIterator;

      std::vector<store::Iterator_t> theErrorIters;
  };

  class TryCatchIterator : public UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> {
  public:
    class CatchClause {
    public:
      ~CatchClause();
      NodeNameTest_t node_name;
      PlanIter_t     catch_expr;
      std::vector<LetVarIter_t> errorcode_var;
      std::vector<LetVarIter_t> errordesc_var;
      std::vector<LetVarIter_t> errorobj_var;
    };

    TryCatchIterator(const QueryLoc& loc, PlanIter_t& aBlock, std::vector<CatchClause>& aCatchClauses);
    virtual ~TryCatchIterator();
  
    void openImpl(PlanState& planState, uint32_t& offset);
    bool nextImpl(store::Item_t& result, PlanState& aPlanState) const;
    void resetImpl(PlanState& planState) const;
    void closeImpl(PlanState& planState);

    virtual void accept(PlanIterVisitor& v) const;
    virtual uint32_t getStateSizeOfSubtree() const;

  protected:
    bool matchedCatch(error::ZorbaError& e, TryCatchIteratorState* state, PlanState&) const;
    void bindErrorVars(error::ZorbaError& e, const CatchClause* state, PlanState&) const;
    std::vector<CatchClause> theCatchClauses;
  };



} /* namespace zorba */

#endif /* ZORBA_TRYCATCH_H */
/* vim:set ts=2 sw=2: */
