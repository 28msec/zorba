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
      Iterator_t theIterator; 
  };

  class TryCatchIterator : public UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> {
  public:
    struct CatchClause {
      NodeNameTest_t node_name;
      PlanIter_t     catch_expr;
      // TODO        need an error var here
    };

    TryCatchIterator(const QueryLoc& loc, PlanIter_t& aBlock, std::vector<CatchClause>& aCatchClauses);
    virtual ~TryCatchIterator();
  
    store::Item_t nextImpl(PlanState& aPlanState) const;

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    std::vector<CatchClause> theCatchClauses;
  };



} /* namespace zorba */

#endif /* ZORBA_TRYCATCH_H */
/* vim:set ts=2 sw=2: */
