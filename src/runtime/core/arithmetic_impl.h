#ifndef XQP_ARITHMETIC_IMPL_H
#define XQP_ARITHMETIC_IMPL_H

#include "common/shared_types.h"
#include "types/typeconstants.h"
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring


namespace xqp {

/** Operations for Add
  */
class AddOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t AddOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

/** Operations for Subtract
  */
class SubtractOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t SubtractOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

/** Operations for Multiply
  */
class MultiplyOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t MultiplyOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

/** Operations for Division
  */
class DivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t DivideOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

/** Operations for Integer Division
  */
class IntegerDivideOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t IntegerDivideOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

/** Operations for Mod
  */
class ModOperation
{
public:
  template<TypeConstants::atomic_type_code_t ATC>
  static Item_t compute (const yy::location* , const Item*, const Item* );
};
template<TypeConstants::atomic_type_code_t ATC>
Item_t ModOperation::compute(const yy::location* loc, const Item* i0, const Item* i1) {
  return 0;
}

template < class Operation >
class GenericArithIterator 
  : public BinaryBaseIterator<GenericArithIterator<Operation>, PlanIteratorState>
{
  public:
    GenericArithIterator ( const yy::location&, PlanIter_t&, PlanIter_t& );
    virtual ~GenericArithIterator(){}

    Item_t nextImpl(PlanState&);
    
    virtual void accept(PlanIterVisitor&) const;

    static Item_t
    compute(const yy::location& loc, Item_t n0, Item_t n1);

}; /* class NumArithIterator */
}

#endif
