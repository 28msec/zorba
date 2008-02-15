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

#include "runtime/base/unarybase.h" // TODO remove after changing the FnStringIterator
#include "runtime/base/narybase.h"

namespace xqp {

// 2.4 fn:data
class FnDataIteratorState : public PlanIteratorState {
public:
  Iterator_t theTypedValue;

  void init(PlanState& planState) 
  { 
    PlanIteratorState::init( planState );
    theTypedValue = NULL;
  }

  void reset(PlanState& planState) 
  {
    PlanIteratorState::reset( planState );
    theTypedValue = NULL;
  }
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


class FnStringIterator : public UnaryBaseIterator<FnStringIterator, FnStringIteratorState> {
  public:
    // TODO is the parameter theEmptyStringOnNULL needed?
    // otherwise we could replace this declaration with the macro
    FnStringIterator(const yy::location& loc, PlanIter_t& in)
      : UnaryBaseIterator<FnStringIterator, FnStringIteratorState>(loc, in), 
        theEmptyStringOnNULL(false) { }

    FnStringIterator(const yy::location& loc, PlanIter_t& in, bool emptyStringOnNULL)
      : UnaryBaseIterator<FnStringIterator, FnStringIteratorState>(loc, in), 
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
