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
#ifndef ZORBA_ARITHMETIC_IMPL_H
#define ZORBA_ARITHMETIC_IMPL_H

#include "common/shared_types.h"
#include "types/typeconstants.h"
#include "runtime/base/binarybase.h" 

namespace zorba {

/**
 * Functions that are used in all Arith Operations
 */
class ArithOperationsCommons {
public:
  static void createError(
      RuntimeCB* aRuntimeCB,
      const char* aOp, 
      const QueryLoc*, 
      TypeConstants::atomic_type_code_t aType0,
      TypeConstants::atomic_type_code_t aType1
  );
};

/** Operations for Add
  */
class AddOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return AddOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t AddOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "add", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Subtract
  */
class SubtractOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return SubtractOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t SubtractOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "sub", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Multiply
  */
class MultiplyOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return MultiplyOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t MultiplyOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "mul", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Division
  */
class DivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return DivideOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t DivideOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Integer Division
  */
class IntegerDivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return IntegerDivideOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t IntegerDivideOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "int-div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Mod
  */
class ModOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (RuntimeCB* aRuntimeCB, const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return ModOperation::compute<ATC,ATC>(aRuntimeCB, loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t ModOperation::compute(RuntimeCB* aRuntimeCB, const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError(aRuntimeCB, "mod", loc, ATC0, ATC1);
  return 0;
}


template < class Operation >
class GenericArithIterator 
  : public BinaryBaseIterator<GenericArithIterator<Operation>, PlanIteratorState>
{
  public:
    GenericArithIterator ( const QueryLoc&, PlanIter_t&, PlanIter_t& );
    virtual ~GenericArithIterator(){}

    store::Item_t nextImpl(PlanState&) const;
    
    virtual void accept(PlanIterVisitor&) const;

    static store::Item_t
    compute(RuntimeCB* aRuntimeCB, const QueryLoc& loc, store::Item_t n0, store::Item_t n1);

}; /* class NumArithIterator */
}

#endif
