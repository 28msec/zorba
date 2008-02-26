#include <zorba/item.h>

#include "runtime/core/sequencetypes.h"
#include "system/globalenv.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "types/casting.h"
#include "store/api/item_factory.h"

namespace xqp
{

/*******************************************************************************

********************************************************************************/
InstanceOfIterator::InstanceOfIterator(const QueryLoc& loc,
                                       PlanIter_t& aTreatExpr,
                                       xqtref_t aSequenceType)
  : UnaryBaseIterator<InstanceOfIterator, PlanIteratorState> ( loc, aTreatExpr ),
    theSequenceType (aSequenceType)
{ }

InstanceOfIterator::~InstanceOfIterator() 
{ }


Item_t
InstanceOfIterator::nextImpl(PlanState& planState) const
{
  Item_t lTreatItem;
  xqtref_t lTreatType;
  TypeConstants::quantifier_t lQuantifier;
  bool lResult;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lTreatItem = consumeNext(theChild.getp(), planState);

  lQuantifier = GENV_TYPESYSTEM.quantifier(*theSequenceType);

  if (lTreatItem != 0)
  {
    if (GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lTreatItem->getType(), 
                                    TypeConstants::QUANT_ONE), *theSequenceType)) {
      lTreatItem = consumeNext(theChild.getp(), planState);
      if (lTreatItem != 0) {
        if (lQuantifier == TypeConstants::QUANT_ONE || lQuantifier == TypeConstants::QUANT_QUESTION) {
          lResult = false;
        } else {
          lResult = true;
          do {
            if (!GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lTreatItem->getType(), TypeConstants::QUANT_ONE), *theSequenceType)) {
              lResult = false;
            }
            lTreatItem = consumeNext(theChild.getp(), planState);
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
    if ((lQuantifier == TypeConstants::QUANT_ONE
        || lQuantifier == TypeConstants::QUANT_PLUS)
        && !GENV_TYPESYSTEM.is_equal(*GENV_TYPESYSTEM.EMPTY_TYPE, *theSequenceType)) {
      lResult = false;
    } else {
      lResult = true;
    }
  }
    
  STACK_PUSH(Zorba::getItemFactory()->createBoolean(lResult), state);
  STACK_END();
}

  

/*******************************************************************************

********************************************************************************/

CastIterator::CastIterator(
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator, PlanIteratorState>(loc, aChild)
{
  theCastType = GENV_TYPESYSTEM.create_type(*aCastType, TypeConstants::QUANT_ONE);  
  theQuantifier = GENV_TYPESYSTEM.quantifier(*aCastType);
}

CastIterator::~CastIterator(){}


Item_t CastIterator::nextImpl(PlanState& aPlanState) const
{
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  if (lItem == 0)
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS ||
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION,
        "Empty sequences cannot be casted to a type with quantifier ONE or PLUS!"
      );
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_ONE ||
          theQuantifier == TypeConstants::QUANT_QUESTION)
  {
    if (consumeNext(theChild.getp(), aPlanState) != NULL)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION,
                        "Sequence with more than one item cannot be casted to a type with quantifier ONE or QUESTION!");
    }

    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
  }
  else
  {
    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);

    lItem = consumeNext(theChild.getp(), aPlanState);
    while (lItem != 0)
    {
      STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
      lItem = consumeNext(theChild.getp(), aPlanState);
    }
  }

  STACK_END();
}


/*******************************************************************************

********************************************************************************/

CastableIterator::CastableIterator(
  const QueryLoc& aLoc,
  PlanIter_t& aChild,
  const xqtref_t& aCastType)
:
  UnaryBaseIterator<CastableIterator, PlanIteratorState>(aLoc, aChild)
{
  theCastType = GENV_TYPESYSTEM.create_type(*aCastType, TypeConstants::QUANT_ONE);  
  theQuantifier = GENV_TYPESYSTEM.quantifier(*aCastType);
}

CastableIterator::~CastableIterator(){}

Item_t CastableIterator::nextImpl(PlanState& aPlanState) const 
{
  bool lBool;
  Item_t lItem;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);
  lItem = consumeNext(theChild.getp(), aPlanState);
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      lBool = false;
    } else {
      lBool = true;
    }
  } else {
    lBool = GenericCast::instance()->isCastable(lItem, theCastType);
    if (lBool) {
      lItem = consumeNext(theChild.getp(), aPlanState);
      if (lItem != 0) {
        if (theQuantifier == TypeConstants::QUANT_ONE || theQuantifier == TypeConstants::QUANT_QUESTION) {
          lBool = false;
        } else {
          do {
            lBool = GenericCast::instance()->isCastable(lItem, theCastType);
            if (lBool)
              lItem = consumeNext(theChild.getp(), aPlanState);
          } while (lBool && (lItem != 0));
        }
      }
    }
  }
  STACK_PUSH(Zorba::getItemFactory()->createBoolean(lBool), lState);
  STACK_END();
}

PromoteIterator::PromoteIterator(const QueryLoc& aLoc, PlanIter_t& aChild, const xqtref_t& aPromoteType)
  : UnaryBaseIterator<PromoteIterator, PlanIteratorState>(aLoc, aChild)
{
  thePromoteType = GENV_TYPESYSTEM.create_type(*aPromoteType, TypeConstants::QUANT_ONE);  
  theQuantifier = GENV_TYPESYSTEM.quantifier(*aPromoteType);
}

PromoteIterator::~PromoteIterator(){}

Item_t PromoteIterator::nextImpl(PlanState& aPlanState) const 
{
  Item_t lItem;
  Item_t lResult;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_ALERT( ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION, 
      "Empty seq cannot be promoted to QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if(consumeNext(theChild.getp(), aPlanState) != 0) {
      ZORBA_ERROR_ALERT( ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION, 
      "Seq with 2 or more items cannot be promotioned to a QUANT_QUESTION or QUANT_ONE type.");
    }
    lResult = GenericCast::instance()->promote(lItem, thePromoteType);
    if (lResult == 0) {
      ZORBA_ERROR_ALERT( ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION, "Type Promotion not possible: " + GENV_TYPESYSTEM.toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " -> " + GENV_TYPESYSTEM.toString (*thePromoteType) );
    } else {
      STACK_PUSH(lResult, lState);
    }
  } else {
    do {
      lResult = GenericCast::instance()->promote(lItem, thePromoteType);
      if (lResult == 0) {
        ZORBA_ERROR_ALERT( ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION, "Type Promotion not possible: " + GENV_TYPESYSTEM.toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " -> " + GENV_TYPESYSTEM.toString (*thePromoteType) );
      } else{
        STACK_PUSH(lResult, lState);
      }
      lItem = consumeNext(theChild.getp(), aPlanState);
    } while (lItem != 0);
  }
  STACK_END();
}

  TreatIterator::TreatIterator(const QueryLoc& aLoc, PlanIter_t& aChild, const xqtref_t& aTreatType, ZorbaError::ErrorCodes aErrorCode)
  : UnaryBaseIterator<TreatIterator, PlanIteratorState>(aLoc, aChild), theErrorCode (aErrorCode)
{
  theTreatType = GENV_TYPESYSTEM.create_type(*aTreatType, TypeConstants::QUANT_ONE);  
  theQuantifier = GENV_TYPESYSTEM.quantifier(*aTreatType);
}

TreatIterator::~TreatIterator(){}

Item_t TreatIterator::nextImpl(PlanState& aPlanState) const
{
  Item_t lItem;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_ALERT( theErrorCode, &loc, DONT_CONTINUE_EXECUTION, 
      "Empty seq cannot be treated as QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if(consumeNext(theChild.getp(), aPlanState) != 0) {
      ZORBA_ERROR_ALERT( theErrorCode, &loc, DONT_CONTINUE_EXECUTION,
      "Seq with 2 or more items cannot treated as a QUANT_QUESTION or QUANT_ONE type.");
    }
    if (!GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lItem->getType(), TypeConstants::QUANT_ONE), *theTreatType)) {
      ZORBA_ERROR_ALERT( theErrorCode, &loc, DONT_CONTINUE_EXECUTION, "Cannot treat " + GENV_TYPESYSTEM.toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " as " + GENV_TYPESYSTEM.toString (*theTreatType) );
    } else {
      STACK_PUSH(lItem, lState);
    }
  } else {
    do {
      if (!GENV_TYPESYSTEM.is_subtype(*GENV_TYPESYSTEM.create_type(lItem->getType(), TypeConstants::QUANT_ONE), *theTreatType)) {
        ZORBA_ERROR_ALERT( theErrorCode, &loc, DONT_CONTINUE_EXECUTION, "Cannot treat " + GENV_TYPESYSTEM.toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " as " + GENV_TYPESYSTEM.toString (*theTreatType) );
      } else{
        STACK_PUSH(lItem, lState);
      }
      lItem = consumeNext(theChild.getp(), aPlanState);
    } while (lItem != 0);
  }
  STACK_END();
}

/*******************************************************************************

********************************************************************************/


} /* namespace xqp */

