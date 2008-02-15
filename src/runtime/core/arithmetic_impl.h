#ifndef XQP_ARITHMETIC_IMPL_H
#define XQP_ARITHMETIC_IMPL_H

#include "common/shared_types.h"
#include "types/typeconstants.h"
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring


namespace xqp {

/**
 * Functions that are used in all Arith Operations
 */
class ArithOperationsCommons {
public:
  static void createError(
      const char* aOp, 
      const yy::location*, 
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
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return AddOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t AddOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("add", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Subtract
  */
class SubtractOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return SubtractOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t SubtractOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("sub", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Multiply
  */
class MultiplyOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return MultiplyOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t MultiplyOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("mul", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Division
  */
class DivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return DivideOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t DivideOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Integer Division
  */
class IntegerDivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return IntegerDivideOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t IntegerDivideOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("int-div", loc, ATC0, ATC1);
  return 0;
}

/** Operations for Mod
  */
class ModOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
  static Item_t compute (const yy::location*, const Item*, const Item*);

  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t computeSingleType (const yy::location* loc, const Item* i0, const Item* i1) 
  {
    return ModOperation::compute<ATC,ATC>(loc, i0, i1);
  }
};
template<TypeConstants::atomic_type_code_t ATC0, TypeConstants::atomic_type_code_t ATC1>
inline Item_t ModOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  ArithOperationsCommons::createError("mod", loc, ATC0, ATC1);
  return 0;
}


template < class Operation >
class GenericArithIterator 
  : public BinaryBaseIterator<GenericArithIterator<Operation>, PlanIteratorState>
{
  public:
    GenericArithIterator ( const yy::location&, PlanIter_t&, PlanIter_t& );
    virtual ~GenericArithIterator(){}

    Item_t nextImpl(PlanState&) const;
    
    virtual void accept(PlanIterVisitor&) const;

    static Item_t
    compute(const yy::location& loc, Item_t n0, Item_t n1);

}; /* class NumArithIterator */
}

#endif
