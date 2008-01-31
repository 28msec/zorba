#include "runtime/core/sequencetypes.h"

#include "system/globalenv.h"
#include "errors/error_factory.h"

namespace xqp
{

/*******************************************************************************

********************************************************************************/
InstanceOfIterator::InstanceOfIterator(yy::location loc,
                                       PlanIter_t& aTreatExpr,
                                       TypeSystem::xqtref_t aSequenceType,
                                       bool aMustBeInstance)
  : UnaryBaseIterator<InstanceOfIterator, PlanIteratorState> ( loc, aTreatExpr ),
    theSequenceType (aSequenceType),
    mustBeInstance (aMustBeInstance)
{ }

InstanceOfIterator::~InstanceOfIterator() 
{ }


Item_t
InstanceOfIterator::nextImpl(PlanState& planState)
{
  Item_t lTreatItem;
  TypeSystem::xqtref_t lTreatType;
  TypeSystem::quantifier_t lQuantifier;
  bool lResult;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lTreatItem = consumeNext(theChild, planState);

  lQuantifier = GENV_TYPESYSTEM.quantifier(*theSequenceType);

  if (lTreatItem != 0)
  {
    if (GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lTreatItem->getType(), 
                                    TypeSystem::QUANT_ONE), *theSequenceType)) {
      lTreatItem = consumeNext(theChild, planState);
      if (lTreatItem != 0) {
        if (lQuantifier == TypeSystem::QUANT_ONE || lQuantifier == TypeSystem::QUANT_QUESTION) {
          lResult = false;
        } else {
          lResult = true;
          do {
            if (!GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lTreatItem->getType(), TypeSystem::QUANT_ONE), *theSequenceType)) {
              lResult = false;
            }
            lTreatItem = consumeNext(theChild, planState);
          } while (lTreatItem != 0);
        }
      } else {
        lResult = true;
      }
    } else {
      lResult = false;
    }
  }
  else
  {
    if ((lQuantifier == TypeSystem::QUANT_ONE
        || lQuantifier == TypeSystem::QUANT_PLUS)
        && !GENV_TYPESYSTEM.is_equal(*GENV_TYPESYSTEM.EMPTY_TYPE, *theSequenceType)) {
      lResult = false;
    } else {
      lResult = true;
    }
  }
    
  if (mustBeInstance && ! lResult)
    ZORBA_ERROR_ALERT (ZorbaError::XPDY0050, NULL, false);
  STACK_PUSH(Zorba::getItemFactory()->createBoolean(lResult), state);
  STACK_END();
}

  

/*******************************************************************************

********************************************************************************/

CastIterator::CastIterator(
    const yy::location& loc,
    PlanIter_t& aChild,
    const TypeSystem::xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator, PlanIteratorState>(loc, aChild), theCastType(aCastType)
{
  theQuantifier = GENV_TYPESYSTEM.quantifier(*theCastType);
}


Item_t CastIterator::nextImpl(PlanState& aPlanState) 
{
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  lItem = consumeNext(theChild, aPlanState);
  if (lItem == 0)
  {
    if (theQuantifier == TypeSystem::QUANT_PLUS ||
        theQuantifier == TypeSystem::QUANT_ONE)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, false,
        "Empty sequences cannot be casted to a type with quantifier ONE or PLUS!"
      );
    }
  }
  else if (theQuantifier == TypeSystem::QUANT_ONE ||
          theQuantifier == TypeSystem::QUANT_QUESTION)
  {
    if (consumeNext(theChild, aPlanState) != NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, false,
                        "Sequence wiht more than one item cannot be casted to a type with quantifier ONE or QUESTION!");
    }

    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
  }
  else
  {
    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);

    lItem = consumeNext(theChild, aPlanState);
    if (lItem != 0)
    {
      if (theQuantifier == TypeSystem::QUANT_ONE ||
          theQuantifier == TypeSystem::QUANT_QUESTION)
      {
        ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, false,
                          "Sequence wiht more than one item cannot be casted to a type with quantifier ONE or QUESTION!"
         );
      }

      do
      {
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
  UnaryBaseIterator<CastableIterator, PlanIteratorState>(aLoc, aChild), theCastType(aCastType)
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
  STACK_PUSH(Zorba::getItemFactory()->createBoolean(lBool), lState);
  STACK_END();
}

/*******************************************************************************

********************************************************************************/


} /* namespace xqp */

