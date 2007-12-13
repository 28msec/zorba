#include "runtime/core/sequencetypes.h"

#include "system/globalenv.h"

namespace xqp
{

/*******************************************************************************

********************************************************************************/
InstanceOfIterator::InstanceOfIterator(yy::location loc,
                                       PlanIter_t& aTreatExpr,
                                       TypeSystem::xqtref_t aSequenceType)
  : UnaryBaseIterator<InstanceOfIterator> ( loc, aTreatExpr ),
    theSequenceType (aSequenceType)
{ }

InstanceOfIterator::~InstanceOfIterator() 
{ }


// the implementation of this operator assumes the following
// - if the SequenceType is * or +, the query is normalized using 
//   every $x in TreatExpr satisfies $x.type == lTreatType
// - if the Sequencetype is empty-sequence the query is normalized
//   using the empty function
Item_t
InstanceOfIterator::nextImpl(PlanState& planState)
{
  Item_t lTreatItem;
  TypeSystem::xqtref_t lTreatType;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lTreatItem = consumeNext(theChild, planState);

  if (lTreatItem != NULL 
      && GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lTreatItem->getType(), 
                                    TypeSystem::QUANT_ONE), *theSequenceType))
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( true ), state);
  }
  else
  {
    STACK_PUSH (zorba::getItemFactory()->createBoolean ( false ), state);   
  }
    
  STACK_END();
}


void
InstanceOfIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<InstanceOfIterator>::releaseResourcesImpl(planState);
  
  PlanIteratorState* state;
  GET_STATE(PlanIteratorState, state, planState);

  state->reset();
}


void
InstanceOfIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<InstanceOfIterator>::releaseResourcesImpl(planState);
  
  PlanIteratorState* state;
  GET_STATE(PlanIteratorState, state, planState);

  state->reset();
}

  

/*******************************************************************************

********************************************************************************/

} /* namespace xqp */

