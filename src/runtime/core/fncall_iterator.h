#ifndef ZORBA_FNCALL_ITERATOR_H
#define ZORBA_FNCALL_ITERATOR_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"
#include <vector>

namespace zorba {

class UDFunctionCallIteratorState : public PlanIteratorState {
  public:
    PlanState *theFnBodyStateBlock;
    PlanIterator *thePlan;
    uint32_t thePlanStateSize;
    std::vector<Iterator_t> theChildIterators;
    bool thePlanOpen;

    UDFunctionCallIteratorState();
    ~UDFunctionCallIteratorState();

    void openPlan();
    void closePlan();
    void resetPlan();
    void resetChildIters();
};

class UDFunctionCallIterator : public NaryBaseIterator<UDFunctionCallIterator, 
                                                       UDFunctionCallIteratorState> {
  public:
    UDFunctionCallIterator(const QueryLoc& loc, 
                           std::vector<PlanIter_t>& args, 
                           const user_function *aUDF)
      : NaryBaseIterator<UDFunctionCallIterator, UDFunctionCallIteratorState>(loc, args), 
        theUDF(aUDF) { }

    virtual ~UDFunctionCallIterator() { }

    void openImpl(PlanState& planState, uint32_t& offset);
    Item_t nextImpl(PlanState& planState) const;
    void resetImpl(PlanState& planState) const;
    void closeImpl(PlanState& planState);

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    const user_function *theUDF;
};

class StatelessExtFunctionCallIteratorState : public PlanIteratorState {
  public:
    StatelessExtFunctionCallIteratorState();
    ~StatelessExtFunctionCallIteratorState();

    std::vector<ItemSequence_t> m_extArgs;
    ItemSequence_t m_result;

    void reset(PlanState&);
};

class StatelessExtFunctionCallIterator
  : public NaryBaseIterator
      <StatelessExtFunctionCallIterator, StatelessExtFunctionCallIteratorState> {
  public:
    StatelessExtFunctionCallIterator(const QueryLoc& loc,
                                     std::vector<PlanIter_t>& args,
                                     const StatelessExternalFunction *function);
    virtual ~StatelessExtFunctionCallIterator() { }

    void openImpl(PlanState& planState, uint32_t& offset);

    Item_t nextImpl(PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    const StatelessExternalFunction *m_function;
};

}

#endif /* ZORBA_FNCALL_ITERATOR_H */
/* vim:set ts=2 sw=2: */
