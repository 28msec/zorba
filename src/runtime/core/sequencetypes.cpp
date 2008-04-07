#include "runtime/core/sequencetypes.h"
#include "runtime/util/iterator_impl.h"
#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "store/api/item_factory.h"
#include "context/static_context.h"

using namespace std;

namespace zorba
{

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
    if (TypeOps::is_subtype(*ts.item_type (lTreatItem),
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
            if (!TypeOps::is_subtype(*ts.item_type (lTreatItem),
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
  theCastType = TypeOps::prime_type (*aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}

CastIterator::~CastIterator(){}


store::Item_t CastIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lItem = consumeNext(theChild.getp(), planState);
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
    if (consumeNext(theChild.getp(), planState) != NULL)
    {
      ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
                        "Sequence with more than one item cannot be casted to a type with quantifier ONE or QUESTION!");
    }

    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
  }
  else
  {
    STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);

    lItem = consumeNext(theChild.getp(), planState);
    while (lItem != 0)
    {
      STACK_PUSH(GenericCast::instance()->cast(lItem, theCastType), state);
      lItem = consumeNext(theChild.getp(), planState);
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
  theCastType = TypeOps::prime_type (*aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
}

CastableIterator::~CastableIterator(){}

store::Item_t CastableIterator::nextImpl(PlanState& planState) const 
{
  bool lBool;
  store::Item_t lItem;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);
  lItem = consumeNext(theChild.getp(), planState);
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      lBool = false;
    } else {
      lBool = true;
    }
  } else {
    lBool = GenericCast::instance()->isCastable(lItem, theCastType);
    if (lBool) {
      lItem = consumeNext(theChild.getp(), planState);
      if (lItem != 0) {
        if (theQuantifier == TypeConstants::QUANT_ONE || theQuantifier == TypeConstants::QUANT_QUESTION) {
          lBool = false;
        } else {
          do {
            lBool = GenericCast::instance()->isCastable(lItem, theCastType);
            if (lBool)
              lItem = consumeNext(theChild.getp(), planState);
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
  thePromoteType = TypeOps::prime_type (*aPromoteType);
  theQuantifier = TypeOps::quantifier(*aPromoteType);
}

PromoteIterator::~PromoteIterator(){}

store::Item_t PromoteIterator::nextImpl(PlanState& planState) const 
{
  store::Item_t lItem;
  store::Item_t lResult;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  lItem = consumeNext(theChild.getp(), planState);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  
      "Empty seq cannot be promoted to QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if(consumeNext(theChild.getp(), planState) != 0) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  
      "Seq with 2 or more items cannot be promotioned to a QUANT_QUESTION or QUANT_ONE type.");
    }
    lResult = GenericCast::instance()->promote(lItem, thePromoteType);
    if (lResult == 0) {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc,  "Type Promotion not possible: " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->item_type (lItem)) + " -> " + TypeOps::toString (*thePromoteType) );
    } else {
      STACK_PUSH(lResult, lState);
    }
  } else {
    do {
      lResult = GenericCast::instance()->promote(lItem, thePromoteType);
      if (lResult == 0) {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc,  "Type Promotion not possible: " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->item_type (lItem)) + " -> " + TypeOps::toString (*thePromoteType) );
      } else{
        STACK_PUSH(lResult, lState);
      }
      lItem = consumeNext(theChild.getp(), planState);
    } while (lItem != 0);
  }
  STACK_END (lState);
}

TreatIterator::TreatIterator(const QueryLoc& aLoc, std::vector<PlanIter_t>& aChildren, const xqtref_t& aTreatType, bool check_prime_, ZorbaError::ErrorCode aErrorCode)
  : NaryBaseIterator<TreatIterator, PlanIteratorState>(aLoc, aChildren),
    check_prime (check_prime_), theErrorCode (aErrorCode)
{
  theTreatType = TypeOps::prime_type (*aTreatType);
  theQuantifier = TypeOps::quantifier(*aTreatType);
}

store::Item_t TreatIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  lItem = CONSUME (0);
  
  if (lItem == 0) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  
      "Empty seq cannot be treated as QUANT_ONE or QUANT_PULS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if (CONSUME (0) != 0) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc, 
      "Seq with 2 or more items cannot treated as a QUANT_QUESTION or QUANT_ONE type.");
    }
    if ( check_prime && !TypeOps::is_treatable(lItem, *theTreatType)) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->item_type (lItem)) + " as " + TypeOps::toString (*theTreatType) );
    } else {
      STACK_PUSH(lItem, lState);
    }
  } else {
    do {
      if ( check_prime && !TypeOps::is_treatable(lItem, *theTreatType)) {
        ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->item_type (lItem)) + " as " + TypeOps::toString (*theTreatType) );
      } else{
        STACK_PUSH(lItem, lState);
      }
      lItem = CONSUME (0);
    } while (lItem != 0);
  }
  STACK_END (lState);
}

store::Item_t EitherNodesOrAtomicsIterator::nextImpl (PlanState& planState) const {
  store::Item_t item;

  EitherNodesOrAtomicsIteratorState *lState;
  DEFAULT_STACK_INIT(EitherNodesOrAtomicsIteratorState, lState, planState);

  if (NULL != (item = CONSUME (0))) {
    lState->atomics = item->isAtomic ();
    STACK_PUSH (item, lState);
    
    while (NULL != (item = CONSUME (0))) {
      if (lState->atomics != item->isAtomic ())
        ZORBA_ERROR (ZorbaError::XPTY0018);
      STACK_PUSH (item, lState);
    }
  }
  
  STACK_END (lState);
}

/*******************************************************************************

********************************************************************************/


} /* namespace zorba */

