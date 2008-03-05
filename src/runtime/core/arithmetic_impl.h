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
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return AddOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t AddOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("add", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Subtract
  */
class SubtractOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return SubtractOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t SubtractOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("sub", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Multiply
  */
class MultiplyOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return MultiplyOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t MultiplyOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("mul", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Division
  */
class DivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return DivideOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t DivideOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Integer Division
  */
class IntegerDivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return IntegerDivideOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t IntegerDivideOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("int-div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Mod
  */
class ModOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static store::Item_t compute (const QueryLoc*, const store::Item*, const store::Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static store::Item_t computeSingleType (const QueryLoc* loc, const store::Item* i0, const store::Item* i1) 
  {
    return ModOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline store::Item_t ModOperation::compute(const QueryLoc* loc, const store::Item*, const store::Item*) {
  ArithOperationsCommons::createError("mod", loc, ATC0, ATC1);
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
    compute(const QueryLoc& loc, store::Item_t n0, store::Item_t n1);

}; /* class NumArithIterator */
}

#endif
