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
      Iterator_t theTempIterator;
      PlanIter_t theCatchIterator;
  };

  class TryCatchIterator : public UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> {
  public:
    class CatchClause {
    public:
      ~CatchClause();
      NodeNameTest_t node_name;
      PlanIter_t     catch_expr;
      std::vector<ref_iter_t> errorcode_var;
      std::vector<ref_iter_t> errordesc_var;
      std::vector<ref_iter_t> errorobj_var;
    };

    TryCatchIterator(const QueryLoc& loc, PlanIter_t& aBlock, std::vector<CatchClause>& aCatchClauses);
    virtual ~TryCatchIterator();
  
    void openImpl(PlanState& planState, uint32_t& offset);
    store::Item_t nextImpl(PlanState& aPlanState) const;
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
