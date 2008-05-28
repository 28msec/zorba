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
#ifndef ZORBA_SEQUENCETYPES_H
#define ZORBA_SEQUENCETYPES_H

#include "zorbaerrors/errors.h"
#include "common/shared_types.h"
#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"
#include "runtime/util/iterator_impl.h"
#include "types/typeconstants.h"

namespace zorba {

/*******************************************************************************
  Implement 3.12.1: Instance Of

  The boolean operator instance of returns true if the value of its first 
  operand matches the SequenceType in its second operand, according to the rules
  for SequenceType matching; otherwise it returns false.
********************************************************************************/
class InstanceOfIterator : public UnaryBaseIterator<InstanceOfIterator, PlanIteratorState>
{

private:
  xqtref_t theSequenceType;

public:
  InstanceOfIterator(const QueryLoc& loc, 
                     PlanIter_t& aTreatExpr, 
                     xqtref_t aSequenceType);
 
  ~InstanceOfIterator();
  
  store::Item_t nextImpl(PlanState& planState) const;

  virtual void accept(PlanIterVisitor&) const;
};

/*******************************************************************************
  Implement 3.12.3: Cast

  http://www.w3.org/TR/xquery/#id-cast
********************************************************************************/
class CastIterator : public UnaryBaseIterator<CastIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  xqtref_t theCastType;
  TypeConstants::quantifier_t theQuantifier;

public:
  CastIterator(const QueryLoc& loc,
               PlanIter_t& aChild,
               const xqtref_t& aCastType);
  ~CastIterator();
  
  store::Item_t nextImpl(PlanState& aPlanState) const;
  virtual void accept(PlanIterVisitor&) const;
};


/*******************************************************************************
  Implement 3.12.4: Castable

  http://www.w3.org/TR/xquery/#id-castable
********************************************************************************/
class CastableIterator : public UnaryBaseIterator<CastableIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  xqtref_t theCastType;
  TypeConstants::quantifier_t theQuantifier;

public:
  CastableIterator(const QueryLoc& aLoc,
                   PlanIter_t& aChild,
                   const xqtref_t& aCastType);
  virtual ~CastableIterator();

  store::Item_t nextImpl(PlanState& aPlanState) const;
  virtual void accept(PlanIterVisitor&) const;
};

/**
 * Iterator which tries to promote an item to the passed target type. If it is not possible,
 * a type error is thrown.
 **/
class PromoteIterator : public UnaryBaseIterator<PromoteIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  xqtref_t thePromoteType;
  TypeConstants::quantifier_t theQuantifier;

public:
  PromoteIterator(const QueryLoc&, PlanIter_t&, const xqtref_t& aPromoteType);
  virtual ~PromoteIterator();
  store::Item_t nextImpl(PlanState& aPlanState) const;
  virtual void accept(PlanIterVisitor&) const;
};

/**
 * Iterator which checks if a sequence is an instance of the target type. If not,
 * an error is thrown.
 **/
class TreatIterator : public NaryBaseIterator<TreatIterator, PlanIteratorState> {
  friend class PrinterVisitor;
private:
  xqtref_t theTreatType;
  TypeConstants::quantifier_t theQuantifier;
  bool check_prime;
  XQUERY_ERROR theErrorCode;

public:
  TreatIterator(const QueryLoc&, std::vector<PlanIter_t>&, const xqtref_t& aTreatType,
                bool check_prime, XQUERY_ERROR);
  
  NARY_ITER_METHODS
};

class EitherNodesOrAtomicsIteratorState : public PlanIteratorState {
public:
  bool atomics;
};

NARY_ITER_STATE(EitherNodesOrAtomicsIterator, EitherNodesOrAtomicsIteratorState);

} /* namespace zorba */
#endif  /* ZORBA_SEQUENCETYPES_H */
  
/*
 * Local variables:
 * mode: c++
 * End:
 */
