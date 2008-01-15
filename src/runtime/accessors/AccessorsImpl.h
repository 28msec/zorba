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

#include "context/common.h"
#include "functions/function.h"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"

namespace xqp {

class FnDataIterator : public UnaryBaseIterator<FnDataIterator>
{
    
  // used to save the current typed value in the nextImpl method
//   Iterator_t curTypedValue;
  
public:
  FnDataIterator ( const yy::location& loc, PlanIter_t& aChild )
  :
    UnaryBaseIterator<FnDataIterator> ( loc, aChild ) {}
  
  virtual ~FnDataIterator() {}
    
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);
  
  virtual uint32_t getStateSize() const { return sizeof(FnDataIteratorState); }
  
  virtual void accept(PlanIterVisitor&) const;
  
  protected:
    class FnDataIteratorState : public PlanIteratorState {
      public:
        Iterator_t theTypedValue;
    };
}; /* class FnDateIterator */



class FnRootIterator : public UnaryBaseIterator<FnRootIterator>
{
public:
  FnRootIterator(const yy::location& loc, PlanIter_t& theIter)
    :
    UnaryBaseIterator<FnRootIterator>(loc, theIter) {}
    virtual ~FnRootIterator() {}
    
  Item_t nextImpl(PlanState& planState);
  
  virtual void accept(PlanIterVisitor&) const;
};

class FnNodeNameIterator : public UnaryBaseIterator<FnNodeNameIterator> {
  public:
    FnNodeNameIterator(const yy::location& loc, PlanIter_t& in)
      : UnaryBaseIterator<FnNodeNameIterator>(loc, in) { }
    virtual ~FnNodeNameIterator() { }

    Item_t nextImpl(PlanState& planState);

    virtual void accept(PlanIterVisitor& v) const;
};

class FnStringIterator : public UnaryBaseIterator<FnStringIterator> {
  public:
    FnStringIterator(const yy::location& loc, PlanIter_t& in)
      : UnaryBaseIterator<FnStringIterator>(loc, in), theEmptyStringOnNULL(false) { }

    FnStringIterator(const yy::location& loc, PlanIter_t& in, bool emptyStringOnNULL)
      : UnaryBaseIterator<FnStringIterator>(loc, in), theEmptyStringOnNULL(emptyStringOnNULL) { }

    virtual ~FnStringIterator() { }

    Item_t nextImpl(PlanState& planState);

    void resetImpl(PlanState& planState);

    void releaseResourcesImpl(PlanState& planState);

    virtual uint32_t getStateSize() const { return sizeof(FnStringIteratorState); }

    void setOffset(PlanState& planState, uint32_t& offset);

    virtual void accept(PlanIterVisitor& v) const;

  protected:
    class FnStringIteratorState : public PlanIteratorState {
      public:
        bool hasOutput;
        void init();
        void reset();
    };

    bool theEmptyStringOnNULL;
};

} /* namespace xqp */
#endif /* XQP_ACCESSORS_IMPL_H */
/* vim:set ts=2 sw=2: */
