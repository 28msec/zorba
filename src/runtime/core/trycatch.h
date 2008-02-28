#ifndef XQP_TRYCATCH_H
#define XQP_TRYCATCH_H

#include <vector>

#include "common/shared_types.h"
#include "runtime/base/unarybase.h"

namespace xqp
{

  class TryCatchIteratorState : public  PlanIteratorState {
    public:
      TryCatchIteratorState();
      ~TryCatchIteratorState();
      
      void init(PlanState&);
      void reset(PlanState&);

      // used for evaluating the target expression eagerly
      TempSeq_t  theTargetSequence;
      Iterator*  theIterator; 
  };

  class TryCatchIterator : public UnaryBaseIterator<TryCatchIterator, TryCatchIteratorState> {
  public:
    struct CatchClause {
      NodeNameTest_t node_name;
      
    };

    TryCatchIterator(const QueryLoc& loc, PlanIter_t& aBlock, std::vector<CatchClause>& aCatchClauses);
    virtual ~TryCatchIterator();
  
    Item_t nextImpl(PlanState& aPlanState) const;

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    std::vector<CatchClause> theCatchClauses;
  };



} /* namespace xqp */

#endif /* XQP_TRYCATCH_H */
/* vim:set ts=2 sw=2: */
