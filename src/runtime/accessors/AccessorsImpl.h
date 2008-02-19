/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf
 *
 */

#ifndef XQP_ACCESSORS_IMPL_H
#define XQP_ACCESSORS_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace xqp {

// 2.4 fn:data
class FnDataIteratorState : public PlanIteratorState {
public:
  Iterator_t theTypedValue;
  FnDataIteratorState();
  ~FnDataIteratorState();

  void init(PlanState& planState);
  void reset(PlanState& planState);
};

NARY_ITER_STATE(FnDataIterator, FnDataIteratorState);

// 14.9 fn:root
NARY_ITER(FnRootIterator);

// 2.1 fn:node-name
NARY_ITER(FnNodeNameIterator);

// 2.3 fn:string
class FnStringIteratorState : public PlanIteratorState {
  public:
    bool hasOutput;
    void init(PlanState& planState)
    {
      PlanIteratorState::init(planState);
      hasOutput = false;
    }

    void reset(PlanState& planState)
    {
      PlanIteratorState::reset(planState);
      hasOutput = false;
    }
};


class FnStringIterator : public NaryBaseIterator<FnStringIterator, FnStringIteratorState> {
  public:
    // TODO is the parameter theEmptyStringOnNULL needed?
    // otherwise we could replace this declaration with the macro
    FnStringIterator(const yy::location& loc, std::vector<PlanIter_t>& aChildren)
      : NaryBaseIterator<FnStringIterator, FnStringIteratorState>(loc, aChildren), 
        theEmptyStringOnNULL(false) { }

    FnStringIterator(const yy::location& loc, std::vector<PlanIter_t>& aChildren, bool emptyStringOnNULL)
      : NaryBaseIterator<FnStringIterator, FnStringIteratorState>(loc, aChildren), 
        theEmptyStringOnNULL(emptyStringOnNULL) { }

    virtual ~FnStringIterator() { }

    Item_t nextImpl(PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    bool theEmptyStringOnNULL;
};

} /* namespace xqp */
#endif /* XQP_ACCESSORS_IMPL_H */
/* vim:set ts=2 sw=2: */
