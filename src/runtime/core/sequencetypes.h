#ifndef XQP_SEQUENCETYPES_H
#define XQP_SEQUENCETYPES_H

#include "zorba/common.h"

#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"
#include "types/typesystem.h"
#include "types/casting.h"

#include <assert.h>
#include <iostream>
#include <vector>

namespace xqp {

/*******************************************************************************
  Implement 3.12.1: Instance Of

  The boolean operator instance of returns true if the value of its first 
  operand matches the SequenceType in its second operand, according to the rules
  for SequenceType matching; otherwise it returns false.
********************************************************************************/
class InstanceOfIterator : public UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>
{

private:
  TypeSystem::xqtref_t theSequenceType;

public:
  InstanceOfIterator(yy::location loc, 
                     PlanIter_t& aTreatExpr, 
                     TypeSystem::xqtref_t aSequenceType);
 
  ~InstanceOfIterator();
  
  Item_t nextImpl(PlanState& planState);

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************
  Implement 3.12.3: Cast

  http://www.w3.org/TR/xquery/#id-cast
********************************************************************************/
class CastIterator : public UnaryBaseIterator<CastIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  TypeSystem::xqtref_t theCastType;
  TypeSystem::quantifier_t theQuantifier;

public:
  CastIterator(const yy::location& loc,
               PlanIter_t& aChild,
               const TypeSystem::xqtref_t& aCastType);
  
  Item_t nextImpl(PlanState& aPlanState);
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Implement 3.12.4: Castable

  http://www.w3.org/TR/xquery/#id-castable
********************************************************************************/
class CastableIterator : public UnaryBaseIterator<CastableIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  TypeSystem::xqtref_t theCastType;
  TypeSystem::quantifier_t theQuantifier;

public:
  CastableIterator(const yy::location& aLoc,
                   PlanIter_t& aChild,
                   const TypeSystem::xqtref_t& aCastType);

  Item_t nextImpl(PlanState& aPlanState);
  virtual void accept(PlanIterVisitor&) const;
};

/**
 * Iterator which tries to promote an item to the passed target type. If it is not possible,
 * a type error is thrown.
 **/
class PromoteIterator : public UnaryBaseIterator<PromoteIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  TypeSystem::xqtref_t thePromoteType;
  TypeSystem::quantifier_t theQuantifier;

public:
  PromoteIterator(const yy::location&, PlanIter_t&, const TypeSystem::xqtref_t& aPromoteType);
  Item_t nextImpl(PlanState& aPlanState);
  virtual void accept(PlanIterVisitor&) const;
};

/**
 * Iterator which tries to promote an item to the passed target type. If it is not possible,
 * a type error is thrown.
 **/
class TreatIterator : public UnaryBaseIterator<TreatIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  TypeSystem::xqtref_t theTreatType;
  TypeSystem::quantifier_t theQuantifier;
  ZorbaError::ErrorCodes theErrorCode;

public:
  TreatIterator(const yy::location&, PlanIter_t&, const TypeSystem::xqtref_t& aTreatType, enum ZorbaError::ErrorCodes);
  Item_t nextImpl(PlanState& aPlanState);
  virtual void accept(PlanIterVisitor&) const;
};

} /* namespace xqp */
#endif  /* XQP_SEQUENCETYPES_H */
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
