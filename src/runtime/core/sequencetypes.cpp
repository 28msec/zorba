/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "runtime/core/sequencetypes.h"
#include "runtime/util/iterator_impl.h"
#include "system/globalenv.h"
#include "zorbaerrors/error_manager.h"
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


bool
InstanceOfIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lTreatItem;
  xqtref_t lTreatType;
  TypeConstants::quantifier_t lQuantifier;
  bool lResult;
  RootTypeManager& ts = GENV_TYPESYSTEM;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lQuantifier = TypeOps::quantifier(*theSequenceType);
  if (consumeNext(lTreatItem, theChild.getp(), planState))
  {
    if (TypeOps::is_treatable(lTreatItem, *theSequenceType))
    {
      if (consumeNext(lTreatItem, theChild.getp(), planState))
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
            if (!TypeOps::is_treatable(lTreatItem, *theSequenceType))
            {
              lResult = false;
            }
          } while (consumeNext(lTreatItem, theChild.getp(), planState));
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
    
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lResult), state);
  STACK_END (state);
}

  

/*******************************************************************************

********************************************************************************/
void
CastIteratorState::init(PlanState& aPlanState)
{
  PlanIteratorState::init(aPlanState);
  theIndex = 0;
}

void
CastIteratorState::reset(PlanState& aPlanState)
{
  PlanIteratorState::reset(aPlanState);
  theSimpleParseItems.clear();
  theIndex = 0;
}

CastIterator::CastIterator(
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const xqtref_t& aCastType)
  : UnaryBaseIterator<CastIterator, CastIteratorState>(loc, aChild)
{
  theCastType = TypeOps::prime_type (*aCastType);
  theQuantifier = TypeOps::quantifier(*aCastType);
  if (aCastType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* lType = static_cast<const UserDefinedXQType*>(aCastType.getp());
    theIsSimpleType = !lType->isComplex();
  }
  else
    theIsSimpleType = false;
}

CastIterator::~CastIterator(){}


bool CastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  bool valid = false;
  
  CastIteratorState* state;
  DEFAULT_STACK_INIT(CastIteratorState, state, planState);

  if (!consumeNext(lItem, theChild.getp(), planState))
  {
    if (theQuantifier == TypeConstants::QUANT_PLUS ||
        theQuantifier == TypeConstants::QUANT_ONE)
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, 
        "Empty sequences cannot be casted to a type with quantifier ONE or PLUS!"
      );
    }
  }
  else if (theQuantifier == TypeConstants::QUANT_ONE ||
          theQuantifier == TypeConstants::QUANT_QUESTION)
  {
    //--
    if (theIsSimpleType) {
      state->reset(planState); 
      valid = GenericCast::instance()->castToSimple(xqpString(lItem->getStringValue().getp()),
                                            theCastType,
                                            state->theSimpleParseItems);
    }
    else
      valid = GenericCast::instance()->castToAtomic(result, lItem, theCastType);
    //--
    if (consumeNext(lItem, theChild.getp(), planState))
    {
      ZORBA_ERROR_LOC_DESC( XPTY0004, loc, 
                        "Sequence with more than one item cannot be casted to a type with quantifier ONE or QUESTION!");
    }
    
    if (theIsSimpleType) {
      while(state->theIndex < state->theSimpleParseItems.size()) {
        result = state->theSimpleParseItems[state->theIndex++];
        STACK_PUSH(true, state);
      }
    } 
    else
      STACK_PUSH(valid, state);
  }
  else
  {
    //--
    if (theIsSimpleType) {
      state->reset(planState); 
      GenericCast::instance()->castToSimple(xqpString(lItem->getStringValue().getp()),
                                            theCastType,
                                            state->theSimpleParseItems);
      while(state->theIndex < state->theSimpleParseItems.size()) {
        result = state->theSimpleParseItems[state->theIndex++];
        STACK_PUSH(true, state);
      }
    }
    else
      STACK_PUSH(GenericCast::instance()->castToAtomic(result, lItem, theCastType), state);
    //--

    while (consumeNext(lItem, theChild.getp(), planState))
    {
      //--
      if (theIsSimpleType) {
        state->reset(planState); 
        GenericCast::instance()->castToSimple(xqpString(lItem->getStringValue().getp()),
                                              theCastType,
                                              state->theSimpleParseItems);
        while(state->theIndex < state->theSimpleParseItems.size()) {
          result = state->theSimpleParseItems[state->theIndex++];
          STACK_PUSH(true, state);
        }
      }
      else
        STACK_PUSH(GenericCast::instance()->castToAtomic(result, lItem, theCastType), state);
      //--
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

bool CastableIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  bool lBool;
  store::Item_t lItem;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);
  if (!consumeNext(lItem, theChild.getp(), planState)) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      lBool = false;
    } else {
      lBool = true;
    }
  } else {
    lBool = GenericCast::instance()->isCastable(lItem, theCastType);
    if (lBool) {
      if (consumeNext(lItem, theChild.getp(), planState)) {
        if (theQuantifier == TypeConstants::QUANT_ONE || theQuantifier == TypeConstants::QUANT_QUESTION) {
          lBool = false;
        } else {
          do {
            lBool = GenericCast::instance()->isCastable(lItem, theCastType);
          } while (lBool && consumeNext(lItem, theChild.getp(), planState));
        }
      }
    }
  }
  STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, lBool), lState);
  STACK_END (lState);
}

PromoteIterator::PromoteIterator(const QueryLoc& aLoc, PlanIter_t& aChild, const xqtref_t& aPromoteType)
  : UnaryBaseIterator<PromoteIterator, PlanIteratorState>(aLoc, aChild)
{
  thePromoteType = TypeOps::prime_type (*aPromoteType);
  theQuantifier = TypeOps::quantifier(*aPromoteType);
}

PromoteIterator::~PromoteIterator(){}

bool PromoteIterator::nextImpl(store::Item_t& result, PlanState& planState) const 
{
  store::Item_t lItem;
  store::Item_t temp;
  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  if (!consumeNext(lItem, theChild.getp(), planState)) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC(  XPTY0004, loc,  
      "Empty seq cannot be promoted to QUANT_ONE or QUANT_PLUS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if (! GenericCast::instance()->promote(result, lItem, thePromoteType))
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "Type promotion not possible: " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (lItem)) + " -> " + TypeOps::toString (*thePromoteType) );
    if(consumeNext(temp, theChild.getp(), planState)) {
      ZORBA_ERROR_LOC_DESC(  XPTY0004, loc,  
      "Seq with 2 or more items cannot be promoted to a QUANT_QUESTION or QUANT_ONE type.");
    }
    STACK_PUSH(true, lState);
  } else {
    do {
      if (! GenericCast::instance()->promote(result, lItem, thePromoteType))
        ZORBA_ERROR_LOC_DESC( XPTY0004, loc,  "Type promotion not possible: " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (lItem)) + " -> " + TypeOps::toString (*thePromoteType) );
      else
        STACK_PUSH(true, lState);
    } while (consumeNext(lItem, theChild.getp(), planState));
  }
  STACK_END (lState);
}

TreatIterator::TreatIterator(const QueryLoc& aLoc, std::vector<PlanIter_t>& aChildren, const xqtref_t& aTreatType, bool check_prime_, XQUERY_ERROR aErrorCode)
  : NaryBaseIterator<TreatIterator, PlanIteratorState>(aLoc, aChildren),
    check_prime (check_prime_), theErrorCode (aErrorCode)
{
  theTreatType = TypeOps::prime_type (*aTreatType);
  theQuantifier = TypeOps::quantifier(*aTreatType);
}

bool TreatIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t temp;

  PlanIteratorState* lState;
  DEFAULT_STACK_INIT(PlanIteratorState, lState, planState);

  if (!CONSUME (result, 0)) {
    if (theQuantifier == TypeConstants::QUANT_PLUS || theQuantifier == TypeConstants::QUANT_ONE) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  
      "Empty seq cannot be treated as QUANT_ONE or QUANT_PLUS type.");
    }
  } else if(theQuantifier == TypeConstants::QUANT_QUESTION 
         || theQuantifier == TypeConstants::QUANT_ONE) {
    if (CONSUME (temp, 0)) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc, 
      "Seq with 2 or more items cannot treated as a QUANT_QUESTION or QUANT_ONE type.");
    }
    if ( check_prime && !TypeOps::is_treatable(result, *theTreatType)) {
      ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result)) + " as " + TypeOps::toString (*theTreatType) );
    } else {
      STACK_PUSH(true, lState);
    }
  } else {
    do {
      if ( check_prime && !TypeOps::is_treatable(result, *theTreatType)) {
        ZORBA_ERROR_LOC_DESC( theErrorCode, loc,  "Cannot treat " + TypeOps::toString (*planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type (result)) + " as " + TypeOps::toString (*theTreatType) );
      } else{
        STACK_PUSH(true, lState);
      }
    } while (CONSUME (result, 0));
  }
  STACK_END (lState);
}

bool EitherNodesOrAtomicsIterator::nextImpl(store::Item_t& result, PlanState& planState) const {
  store::Item_t item;

  EitherNodesOrAtomicsIteratorState *lState;
  DEFAULT_STACK_INIT(EitherNodesOrAtomicsIteratorState, lState, planState);

  if (CONSUME (result, 0)) {
    lState->atomics = item->isAtomic ();
    STACK_PUSH (true, lState);
    
    while (CONSUME (result, 0)) {
      if (lState->atomics != item->isAtomic ())
        ZORBA_ERROR (XPTY0018);
      STACK_PUSH (true, lState);
    }
  }
  
  STACK_END (lState);
}

/*******************************************************************************

********************************************************************************/


} /* namespace zorba */

