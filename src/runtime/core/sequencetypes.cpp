#include "runtime/core/sequencetypes.h"
#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"

using namespace std;

namespace zorba
{

  static xqtref_t seq_target_type (xqtref_t type) {
    TypeManager &ts = GENV_TYPESYSTEM;
    if (TypeOps::is_equal (*type, *ts.create_empty_type ()))
      return type;
    else
      return TypeOps::prime_type (*type);
  }

/*******************************************************************************

********************************************************************************/
InstanceOfIterator::InstanceOfIterator(
   const QueryLoc& loc,
   PlanIter_t& aTreatExpr,
   xqtref_t aSequenceType)
  :
  UnaryBaseIterator<InstanceOfIterator, PlanIteratorState> ( loc, aTreatExpr ),
  theSequenceType (aSequenceType)
{ 
}


InstanceOfIterator::~InstanceOfIterator() 
{
}


store::Item_t
InstanceOfIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lTreatItem;
  xqtref_t lTreatType;
  TypeConstants::quantifier_t lQuantifier;
  bool lResult;
  RootTypeManager& ts = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lTreatItem = consumeNext(theChild.getp(), planState);

  lQuantifier = TypeOps::quantifier(*theSequenceType);

  if (lTreatItem != 0)
  {
    if (TypeOps::is_subtype(*ts.create_type (lTreatItem->getType()),
                      *theSequenceType))
    {
      lTreatItem = consumeNext(theChild.getp(), planState);
      if (lTreatItem != 0)
      {
        if (lQuantifier == TypeConstants::QUANT_ONE ||
            lQuantifier == TypeConstants::QUANT_QUESTION)
        {
          lResult = false;
        }
        else
        {
          lResult = true;
          do
          {
            if (!TypeOps::is_subtype(*ts.create_type(lTreatItem->getType()),
                               *theSequenceType))
            {
              lResult = false;
            }
            lTreatItem = consumeNext(theChild.getp(), planState);
          } while (lTreatItem != 0);
        }
      }
      else
      {
        lResult = true;
      }
    }
    else
    {
      lResult = false;
    }
  }
  else
  {
    if ((lQuantifier == TypeConstants::QUANT_ONE ||
         lQuantifier == TypeConstants::QUANT_PLUS) &&
        !TypeOps::is_equal(*ts.EMPTY_TYPE, *theSequenceType))
    {
      lResult = false;
    }
    else
    {
      lResult = true;
    }
  }
    
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(lResult), state);
  STACK_END (state);
}

  

/*******************************************************************************

********************************************************************************/

CastIterator::CastIterator(
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator, PlanIteratorState>(loc, aChild)
{
  theCastType = seq_target_type (aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}

CastIterator::~CastIterator(){}


store::Item_t CastIterator::nextImpl(PlanState& aPlanState) const
{
  store::Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  if (lItem == 0)
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS ||
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
        "Empty sequences cannot be casted to a type with quantifier ONE or PLUS!"
      );
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_ONE ||
          theQuantifier == TypeConstants::QUANT_QUESTION)
  {
    if (consumeNext(theChild.getp(), aPlanState) != NULL)
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
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

  STACK_END (state);
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
  theCastType = seq_target_type (aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}

CastableIterator::~CastableIterator(){}

store::Item_t CastableIterator::nextImpl(PlanState& aPlanState) const 
{
  bool lBool;
  store::Item_t lItem;

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
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(lBool), lState);
  STACK_END (lState);
}

PromoteIterator::PromoteIterator(const QueryLoc& aLoc, PlanIter_t& aChild, const xqtref_t& aPromoteType)
  : UnaryBaseIterator<PromoteIterator, PlanIteratorState>(aLoc, aChild)
{
  thePromoteType = seq_target_type (aPromoteType);
  theQuantifier = TypeOps::quantifier(*aPromoteType);
}

PromoteIterator::~PromoteIterator(){}

store::Item_t PromoteIterator::nextImpl(PlanState& aPlanState) const 
{
  store::Item_t lItem;
  store::Item_t lResult;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  
      "Empty seq cannot be promoted to QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if(consumeNext(theChild.getp(), aPlanState) != 0) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  
      "Seq with 2 or more items cannot be promotioned to a QUANT_QUESTION or QUANT_ONE type.");
    }
    lResult = GenericCast::instance()->promote(lItem, thePromoteType);
    if (lResult == 0) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  "Type Promotion not possible: " + TypeOps::toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " -> " + TypeOps::toString (*thePromoteType) );
    } else {
      STACK_PUSH(lResult, lState);
    }
  } else {
    do {
      lResult = GenericCast::instance()->promote(lItem, thePromoteType);
      if (lResult == 0) {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc,  "Type Promotion not possible: " + TypeOps::toString (*GENV_TYPESYSTEM.create_type (lItem->getType ())) + " -> " + TypeOps::toString (*thePromoteType) );
      } else{
        STACK_PUSH(lResult, lState);
      }
      lItem = consumeNext(theChild.getp(), aPlanState);
    } while (lItem != 0);
  }
  STACK_END (lState);
}

  TreatIterator::TreatIterator(const QueryLoc& aLoc, PlanIter_t& aChild, const xqtref_t& aTreatType, ZorbaError::ErrorCode aErrorCode)
  : UnaryBaseIterator<TreatIterator, PlanIteratorState>(aLoc, aChild), theErrorCode (aErrorCode)
{
  theTreatType = seq_target_type (aTreatType);
  theQuantifier = TypeOps::quantifier(*aTreatType);
}

TreatIterator::~TreatIterator(){}

store::Item_t TreatIterator::nextImpl(PlanState& aPlanState) const
{
  store::Item_t lItem;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, aPlanState);

  lItem = consumeNext(theChild.getp(), aPlanState);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  
      "Empty seq cannot be treated as QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if(consumeNext(theChild.getp(), aPlanState) != 0) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc, 
      "Seq with 2 or more items cannot treated as a QUANT_QUESTION or QUANT_ONE type.");
    }
    if ( !TypeOps::is_treatable(lItem, *theTreatType)) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " as " + TypeOps::toString (*theTreatType) );
    } else {
      STACK_PUSH(lItem, lState);
    }
  } else {
    do {
      if ( !TypeOps::is_treatable(lItem, *theTreatType)) {
        ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*GENV_TYPESYSTEM.create_type (lItem->getType (), TypeConstants::QUANT_ONE)) + " as " + TypeOps::toString (*theTreatType) );
      } else{
        STACK_PUSH(lItem, lState);
      }
      lItem = consumeNext(theChild.getp(), aPlanState);
    } while (lItem != 0);
  }
  STACK_END (lState);
}

/*******************************************************************************

********************************************************************************/


} /* namespace zorba */

