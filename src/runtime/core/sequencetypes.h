#ifndef XQP_SEQUENCETYPES_H
#define XQP_SEQUENCETYPES_H

#include "zorba/common.h"

#include "util/rchandle.h"
#include "util/tracer.h"
#include "compiler/parser/location.hh"
#include "runtime/base/iterator.h"
#include "runtime/base/unarybase.h"
#include "types/typesystem.h"

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
class InstanceOfIterator : public UnaryBaseIterator<InstanceOfIterator>
{

private:
  TypeSystem::xqtref_t theSequenceType;

public:
  InstanceOfIterator(yy::location loc, 
                     PlanIter_t& aTreatExpr, 
                     TypeSystem::xqtref_t aSequenceType);
 
  ~InstanceOfIterator();
  
  Item_t nextImpl(PlanState& planState);
  void resetImpl(PlanState& planState);
  void releaseResourcesImpl(PlanState& planState);

  virtual uint32_t getStateSize() const { return sizeof(PlanIterator::PlanIteratorState); }

  virtual void accept(PlanIterVisitor&) const;
};

} /* namespace xqp */
#endif  /* XQP_SEQUENCETYPES_H */
