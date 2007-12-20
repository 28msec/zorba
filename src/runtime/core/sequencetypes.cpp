#include "runtime/core/sequencetypes.h"

#include "system/globalenv.h"
#include "errors/Error.h"

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

  

/*******************************************************************************

********************************************************************************/

CastIterator::CastIterator(
    const yy::location& loc,
    PlanIter_t& aChild,
    const TypeSystem::xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator>(loc, aChild), theCastType(aCastType)
{
  theQuantifier = GENV_TYPESYSTEM.quantifier(*theCastType);
}

Item_t CastIterator::nextImpl(PlanState& aPlanState) {
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);
  


  lItem = consumeNext(theChild, aPlanState);
  if (lItem == 0) {
    if (theQuantifier == TypeSystem::QUANT_PLUS || theQuantifier == TypeSystem::QUANT_ONE) {
      ZorbaErrorAlerts::error_alert (
        error_messages::XPTY0004_STATIC_TYPE_ERROR,
        error_messages::STATIC_ERROR,
        false,
        "Empty sequences cannot be casted to a type with quantifier ONE or PLUS!"
      );
    }
  } else {
    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
    lItem = consumeNext(theChild, aPlanState);
    if (lItem != 0) {
      if (theQuantifier == TypeSystem::QUANT_ONE
       || theQuantifier == TypeSystem::QUANT_QUESTION) {
         ZorbaErrorAlerts::error_alert (
           error_messages::XPTY0004_STATIC_TYPE_ERROR,
           error_messages::STATIC_ERROR,
           false,
           "Sequence wiht more than one item cannot be casted to a type with quantifier ONE or QUESTION!"
         );
      }
      do {
        STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
        lItem = consumeNext(theChild, aPlanState);
      } while (lItem != 0);
    }
  }
  STACK_END();
}

/*******************************************************************************

********************************************************************************/

CastableIterator::CastableIterator(
  const yy::location& aLoc,
  PlanIter_t& aChild,
  const TypeSystem::xqtref_t& aCastType)
:
  UnaryBaseIterator<CastableIterator>(aLoc, aChild), theCastType(aCastType)
{
  theQuantifier = GENV_TYPESYSTEM.quantifier(*theCastType);
}

Item_t CastableIterator::nextImpl(PlanState& aPlanState) {
  bool lBool;
  Item_t lItem;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  lItem = consumeNext(theChild, aPlanState);
  if (lItem == 0) {
    if (theQuantifier == TypeSystem::QUANT_PLUS || theQuantifier == TypeSystem::QUANT_ONE) {
      lBool = false;
    } else {
      lBool = true;
    }
  } else {
    lBool = GenericCast::instance()->isCastable(lItem, theCastType);
    if (lBool) {
      lItem = consumeNext(theChild, aPlanState);
      if (lItem != 0) {
        if (theQuantifier == TypeSystem::QUANT_ONE || theQuantifier == TypeSystem::QUANT_QUESTION) {
          lBool = false;
        } else {
          do {
            lBool = GenericCast::instance()->isCastable(lItem, theCastType);
            if (lBool)
              lItem = consumeNext(theChild, aPlanState);
          } while (lBool && (lItem != 0));
        }
      }
    }
  }
  STACK_PUSH(zorba::getItemFactory()->createBoolean(lBool), lState);
  STACK_END();
}

/*******************************************************************************

********************************************************************************/


} /* namespace xqp */

