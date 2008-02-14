#ifndef XQP_ARITHMETIC_IMPL_H
#define XQP_ARITHMETIC_IMPL_H

#include "common/shared_types.h"
#include "runtime/base/binarybase.h" // TODO remove after iterator refactoring


namespace xqp {

/** Operations for Add
  */
class AddOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

/** Operations for Subtract
  */
class SubtractOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

/** Operations for Multiply
  */
class MultiplyOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

/** Operations for Division
  */
class DivideOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

/** Operations for Integer Division
  */
class IntegerDivideOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

/** Operations for Mod
  */
class ModOperation
{
public:
  template<typename T>
  static Item_t compute (const yy::location* , Item_t, Item_t );
};

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
