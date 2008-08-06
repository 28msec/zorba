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
#include "system/globalenv.h"
#include "runtime/booleans/BooleanImpl.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "runtime/api/runtimecb.h"
#include "zorbaerrors/error_manager.h"
#include "runtime/accessors//AccessorsImpl.h"
#include "store/api/temp_seq.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_cache.h"
#include "zorbatypes/collation_manager.h"
#include "zorbatypes/duration.h"
#include "zorbatypes/datetime.h"


namespace zorba
{

  /*______________________________________________________________________
  |
  | 15.1.1 fn:boolean
  | fn:boolean($arg as item()*) as xs:boolean
  |
  | Computes the effective boolean value of the sequence $arg.
  |_______________________________________________________________________*/
  FnBooleanIterator::FnBooleanIterator ( const QueryLoc& loc, PlanIter_t& aIter, bool aNegate )
  :
    UnaryBaseIterator<FnBooleanIterator, PlanIteratorState> ( loc, aIter ), theNegate ( aNegate ) {}
    
  FnBooleanIterator::~FnBooleanIterator() {}

  bool
  FnBooleanIterator::effectiveBooleanValue ( const QueryLoc& loc, PlanState& planState, const PlanIterator* iter, bool negate )
  {
    store::Item_t item;
    xqtref_t type;
    store::Item_t temp;
    bool result;

    if (!consumeNext(item, iter, planState))
    {
      // empty sequence => false
      result = negate ^ false;
    }
    else if ( item->isNode() )
    {
      // node => true
      result = negate ^ true;
    }
    else
    {
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type(item);
      if (( !consumeNext(temp, iter, planState))
          && (TypeOps::is_equal(*type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.STRING_TYPE_ONE )
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE )
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE )
              || TypeOps::is_numeric ( *type )))
      {
        // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
        // => effective boolean value is defined in the items
        temp = item->getEBV();
        result = negate ? (negate ^ temp->getBooleanValue()) : temp->getBooleanValue();
      }
      else
      {
        ZORBA_ERROR_LOC_DESC( FORG0006, loc,  
          "Wrong arguments in fn:boolean function.");
      }
    }

    return result;
  }

  bool
  FnBooleanIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  { 
    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);
    GENV_ITEMFACTORY->createBoolean(result, FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild, theNegate));
    STACK_PUSH (true, aState);
    STACK_END (aState);
  }
  /* end class FnBooleanIterator */
  
  /* begin class LogicIterator */
  LogicIterator::LogicIterator ( const QueryLoc& loc, PlanIter_t theChild0, PlanIter_t theChild1, LogicType aLogicType)
  :
    BinaryBaseIterator<LogicIterator, PlanIteratorState> ( loc, theChild0, theChild1), theLogicType(aLogicType) {}
  
  LogicIterator::~LogicIterator(){}
      
  bool
  LogicIterator::nextImpl(store::Item_t& result, PlanState& planState) const
  {
    bool bRes = false;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

    switch(theLogicType)
    {
    case AND:
      bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)
              && FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1);
      break;
    case OR:
      bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)
              || FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1);
      break;
    }
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(result, bRes), state);
    STACK_END (state);
  }
  /* end class LogicIterator */


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  CompareIterator                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


CompareIterator::CompareIterator (
     const QueryLoc& loc,
     PlanIter_t aChild0,
     PlanIter_t aChild1,
     CompareConsts::CompareType aCompType )
  :
  BinaryBaseIterator<CompareIterator, PlanIteratorState> ( loc, aChild0, aChild1 ), 
  theCompType(aCompType) 
{
}

  
CompareIterator::~CompareIterator()
{
}
  

bool
CompareIterator::nextImpl ( store::Item_t& result, PlanState& planState ) const
{
  store::Item_t lItem0;
  store::Item_t lItem1;
  store::Item_t tItem0;
  store::Item_t tItem1;
  bool c0Done = false;
  bool c1Done = false;
  bool done = false;
  bool found = false;
  std::vector<store::Item_t> seq0;
  std::vector<store::Item_t> seq1;
  store::TempSeq_t tSeq0;
  store::TempSeq_t tSeq1;
    
  PlanIteratorState* state;
  DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  
  if ( this->isGeneralComparison() )
  {
    if (consumeNext(lItem0, theChild0.getp(), planState)) {
      if (consumeNext(tItem0, theChild0.getp(), planState)) {
        seq0.push_back(lItem0);
        seq0.push_back(tItem0);
      } else {
        c0Done = true;
        if (consumeNext(lItem1, theChild1.getp(), planState)) {
          if (consumeNext(tItem1, theChild1.getp(), planState)) {
            seq0.push_back(lItem0);
            seq1.push_back(lItem1);
            seq1.push_back(tItem1);
          } else {
            c1Done = true;
            found = CompareIterator::generalComparison(planState.theRuntimeCB,
                                                       lItem0, lItem1,
                                                       theCompType);
            done = true;
          }
        } else {
          c1Done = true;
          found = false;
          done = true;
        }
      }
    } else {
      c0Done = true;
      found = false;
      done = true;
    }
    
    if (!done) 
    {
      store::Iterator_t lIter0;
      store::Iterator_t lIter1;
      tSeq0 = GENV_STORE.createTempSeq(seq0);
      tSeq1 = GENV_STORE.createTempSeq(seq1);

      if (!c0Done) 
      {
        lIter0 = new PlanIteratorWrapper ( theChild0, planState );
        tSeq0->append(lIter0, false);
      }
      if (!c1Done) 
      {
        lIter1 = new PlanIteratorWrapper ( theChild1, planState );
        tSeq1->append(lIter1, false);
      }

      int i0 = 1;
      while(!found && tSeq0->containsItem(i0)) 
      {
        int i1 = 1;
        while(!found && tSeq1->containsItem(i1)) 
        {
          if (CompareIterator::generalComparison(planState.theRuntimeCB, tSeq0->getItem(i0), tSeq1->getItem(i1), theCompType)) 
          {
            found = true;
          }
          ++i1;
        }
        ++i0;
      }
    }
 
    STACK_PUSH ( GENV_ITEMFACTORY->createBoolean ( result, found ), state );
  } /* if general comparison */
  else if ( this->isValueComparison() )
  {
    if ( consumeNext ( lItem0, theChild0.getp(), planState )
         && consumeNext ( lItem1, theChild1.getp(), planState ) )
    {
      STACK_PUSH ( GENV_ITEMFACTORY->createBoolean ( result, CompareIterator::valueComparison ( planState.theRuntimeCB, lItem0, lItem1, theCompType ) ), state );
      if ( consumeNext ( lItem0, theChild0.getp(), planState )
           || consumeNext ( lItem1, theChild1.getp(), planState ) )
      {
        ZORBA_ERROR_LOC_DESC(  XPTY0004, loc, 
                               "Value comparions must not be made with sequences with length greater 1.");
      }
    }
  } /* if value comparison */
  else if ( this->isNodeComparison() )
  {
    ZORBA_ERROR_LOC_DESC(  XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                           loc,  "Node comparison is not yet implemented.");
  } /* if node comparison */
  
  STACK_END (state);
}
  

void CompareIterator::valueCasting(
    RuntimeCB*     aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type(aItem0);
  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type(aItem1);

  // all untyped Atomics to String
  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                  &*GENV_TYPESYSTEM.STRING_TYPE_ONE);

    if  (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                    &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    else
    {
      GenericCast::instance()->promote(const_cast<store::Item_t&>(castItem0),
                                       castItem0,
                                       &*type1);

      if (!GenericCast::instance()->promote(castItem1, aItem1,
                                            &*GENV_TYPESYSTEM.STRING_TYPE_ONE))
        castItem1 = aItem1;
    }  
  }
  else if  (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (!GenericCast::instance()->promote(const_cast<store::Item_t&>(castItem0),
                                          aItem0,
                                          &*GENV_TYPESYSTEM.STRING_TYPE_ONE))
      castItem0 = aItem0;

    GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                  &*GENV_TYPESYSTEM.STRING_TYPE_ONE);

    GenericCast::instance()->promote(castItem1, castItem1, &*type0);
  }
  else
  {
    if (!GenericCast::instance()->promote(castItem0, aItem0, &*type1))
      castItem0 = aItem0;

    if (!GenericCast::instance()->promote(castItem1, aItem1, &*type0))
      castItem1 = aItem1;
  }
}
  

void CompareIterator::generalCasting(
    RuntimeCB*     aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    store::Item_t& castItem0,
    store::Item_t& castItem1)
{
  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem0);

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem1);

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(*type1))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                    &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);

      GenericCast::instance()->promote(castItem1, aItem1,
                                       &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                    &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                    &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0,
                                    &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      castItem1 = aItem1;
    }
    else
    {
      GenericCast::instance()->castToAtomic(castItem0, aItem0, &*type1);
      castItem1 = aItem1;
    }
  }
  else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    if (TypeOps::is_numeric(*type0))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                    &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      GenericCast::instance()->promote(castItem0, aItem0,
                                       &*GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      //castItem0 = aItem0;
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1,
                                    &*GENV_TYPESYSTEM.STRING_TYPE_ONE);
      castItem0 = aItem0;
    }
    else
    {
      GenericCast::instance()->castToAtomic(castItem1, aItem1, &*type0);
      castItem0 = aItem0;
    }
  }
  else
  {
    if (!GenericCast::instance()->promote(castItem0, aItem0, &*type1))
      castItem0 = aItem0;

    if (!GenericCast::instance()->promote(castItem1, aItem1, &*type0))
      castItem1 = aItem1;
  }  
}
  

bool CompareIterator::boolResult (
    RuntimeCB* aRuntimeCB,
    int8_t aCompValue,
    CompareConsts::CompareType aCompType )
{
  if ( aCompValue > -2 )
    switch ( aCompType )
    {
      case CompareConsts::VALUE_EQUAL:
      case CompareConsts::GENERAL_EQUAL:
        return aCompValue == 0;
        break;
      case CompareConsts::VALUE_NOT_EQUAL:
      case CompareConsts::GENERAL_NOT_EQUAL:
        return aCompValue != 0;
        break;
      case CompareConsts::VALUE_GREATER:
      case CompareConsts::GENERAL_GREATER:
        return aCompValue == 1;
        break;
      case CompareConsts::VALUE_GREATER_EQUAL:
      case CompareConsts::GENERAL_GREATER_EQUAL:
        return (aCompValue == 0) || (aCompValue == 1);
        break;
      case CompareConsts::VALUE_LESS:
      case CompareConsts::GENERAL_LESS:
        return aCompValue == -1;
        break;
      case CompareConsts::VALUE_LESS_EQUAL:
      case CompareConsts::GENERAL_LESS_EQUAL:
        return (aCompValue == -1) || (aCompValue == 0);
        break;
      default:
        break;
    }

    ZORBA_ERROR_DESC(  XPTY0004, "Dynamic type of a value does not match a required type.");
  return false;
}


bool
CompareIterator::generalComparison(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    CompareConsts::CompareType aCompType,
    XQPCollator* aCollation)
{
  int8_t compValue = -2;
  switch(aCompType)
  {
  case CompareConsts::VALUE_EQUAL:
  case CompareConsts::GENERAL_EQUAL:
  case CompareConsts::VALUE_NOT_EQUAL:
  case CompareConsts::GENERAL_NOT_EQUAL:
    compValue = CompareIterator::generalEqual(aRuntimeCB, aItem0, aItem1, aCollation);
    break;
  case CompareConsts::VALUE_GREATER:
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::VALUE_GREATER_EQUAL:
  case CompareConsts::GENERAL_GREATER_EQUAL:
  case CompareConsts::VALUE_LESS:
  case CompareConsts::GENERAL_LESS:
  case CompareConsts::VALUE_LESS_EQUAL:
  case CompareConsts::GENERAL_LESS_EQUAL:
    compValue = CompareIterator::generalCompare(aRuntimeCB, aItem0, aItem1, aCollation);
    break;
  default:
    break;
  }
    
  return boolResult(aRuntimeCB, compValue, aCompType);
}
  

bool CompareIterator::valueComparison(
    RuntimeCB* aRuntimeCB, 
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    CompareConsts::CompareType aCompType,
    XQPCollator* aCollation)
{
  int8_t compValue = -2;
  switch(aCompType)
  {
  case CompareConsts::VALUE_EQUAL:
  case CompareConsts::GENERAL_EQUAL:
  case CompareConsts::VALUE_NOT_EQUAL:
  case CompareConsts::GENERAL_NOT_EQUAL:
    compValue = CompareIterator::valueEqual(aRuntimeCB, aItem0, aItem1, aCollation);
    break;
  case CompareConsts::VALUE_GREATER:
  case CompareConsts::GENERAL_GREATER:
  case CompareConsts::VALUE_GREATER_EQUAL:
  case CompareConsts::GENERAL_GREATER_EQUAL:
  case CompareConsts::VALUE_LESS:
  case CompareConsts::GENERAL_LESS:
  case CompareConsts::VALUE_LESS_EQUAL:
  case CompareConsts::GENERAL_LESS_EQUAL:
    compValue = CompareIterator::valueCompare(aRuntimeCB, aItem0, aItem1, aCollation);
  default:
    break;
  }
  
  return boolResult(aRuntimeCB, compValue, aCompType);
}
  

int8_t CompareIterator::generalEqual(
    RuntimeCB*     aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator*   aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(aRuntimeCB, aItem0, aItem1, castItem0, castItem1);
  return equal(aRuntimeCB, castItem0, castItem1, aCollation);
}


int8_t CompareIterator::valueEqual(
    RuntimeCB*           aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator*         aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(aRuntimeCB, aItem0, aItem1, castItem0, castItem1);
  return equal(aRuntimeCB, castItem0, castItem1, aCollation);
}


int8_t
CompareIterator::equal(
    RuntimeCB* aRuntimeCB, 
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    XQPCollator* aCollation)
{
  int equal = -2;

  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type(aItem0.getp());

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type(aItem1.getp());

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE) &&
      TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) 
  {
    if (aCollation == 0)
      aCollation =  aRuntimeCB->theCollationCache->getDefaultCollator();

    if (aCollation->doMemCmp())
    {
      return (aItem0->getStringValue()->byteEqual(*aItem1->getStringValue()) ? 0 : 1);
    }
    else
    {
      return (aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation) != 0 ? 1 : 0);
    }
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) 
  {
    return (aItem0->getDoubleValue() == aItem1->getDoubleValue() ? 0 : 1);
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
  {
    return (aItem0->getFloatValue() == aItem1->getFloatValue() ? 0 : 1);
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) 
  {
    return (aItem0->getDecimalValue() == aItem1->getDecimalValue() ? 0 : 1);
   }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
  {
    if (aCollation == 0)
      aCollation = aRuntimeCB->theCollationCache->getDefaultCollator();

    if (aCollation->doMemCmp())
    {
      return (aItem0->getStringValue()->byteEqual(*aItem1->getStringValue()) ? 0 : 1);
    }
    else
    {
      return (aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation) != 0 ? 1 : 0);
    }
  } 
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
  {
    return (aItem0->getBooleanValue() == aItem1->getBooleanValue() ? 0 : 1);
  }

  // catch InvalidTimezoneException
  try 
  {
    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE) &&
        TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
    {
      return aItem0->getDateValue().compare(&aItem1->getDateValue(),
                                            aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
    {
      return aItem0->getTimeValue().compare(&aItem1->getTimeValue(),
                                            aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
    {
      return aItem0->getDateTimeValue().compare(&aItem1->getDateTimeValue(),
                                                aRuntimeCB->theDynamicContext->get_implicit_timezone());
      
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE))
    {
      return aItem0->getGYearMonthValue().compare(&aItem1->getGYearMonthValue(),
                                                  aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE))
    {
      return aItem0->getGYearValue().compare(&aItem1->getGYearValue(),
                                             aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE))
    {
      return aItem0->getGMonthDayValue().compare(&aItem1->getGMonthDayValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE))
    {
      return aItem0->getGMonthValue().compare(&aItem1->getGMonthValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GDAY_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GDAY_TYPE_ONE))
    {
      return aItem0->getGDayValue().compare(&aItem1->getGDayValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
             (!TypeOps::is_equal(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)) &&
             (!TypeOps::is_equal(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)) &&
             TypeOps::is_equal(*type0, *type1))
    {
      return aItem0->getDurationValue().compare(aItem1->getDurationValue());
    }
  } 
  catch (InvalidTimezoneException)
  {
    ZORBA_ERROR(FODT0003);
  }
  

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE) &&
      TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
  {
    equal = (aItem0->getDurationValue() == aItem1->getDurationValue());
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.QNAME_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
  {
    equal = 0;
    if(aItem0->getLocalName()->equals(aItem1->getLocalName()))
      if((aItem0->getNamespace()->empty() && aItem1->getNamespace()->empty()) ||
         (aItem0->getNamespace()->equals(aItem1->getNamespace())))
        equal = 1;
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE))
  {
    if (aItem0->equals(aItem1))
      equal = 1;
    else
      equal = 0;
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.HEXBINARY_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.HEXBINARY_TYPE_ONE))
  {
    if (aItem0->equals(aItem1))
      equal = 1;
    else
      equal = 0;
    return (equal==-2)?-2:(equal==0?1:0);
  }

  return -2;
}


int8_t CompareIterator::generalCompare(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  generalCasting(aRuntimeCB, aItem0, aItem1, castItem0, castItem1);
  return compare(aRuntimeCB, castItem0, castItem1, aCollation);
}


int8_t CompareIterator::valueCompare(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator* aCollation)
{
  store::Item_t castItem0, castItem1;
  valueCasting(aRuntimeCB, aItem0, aItem1, castItem0, castItem1);
  return compare(aRuntimeCB, castItem0, castItem1, aCollation);
}


int8_t 
CompareIterator::compare(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator* aCollation)
{
  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem0.getp());

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem1.getp());

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE) &&
      TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) 
  {
    if (aCollation == 0) {
      aCollation =  aRuntimeCB->theCollationCache->getDefaultCollator();
    }
    int res = aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation);
    if (res < 0)
      return -1;
    else if (res > 0)
      return 1;
    else
      return 0;
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) 
  {
    if ( aItem0->getDoubleValue() < aItem1->getDoubleValue())
      return -1;
    else if ( aItem0->getDoubleValue() == aItem1->getDoubleValue())
      return 0;
    else if (aItem0->getDoubleValue() > aItem1->getDoubleValue())
      return 1;
    else
      return 2;
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
  {
    if ( aItem0->getFloatValue() < aItem1->getFloatValue())
      return -1;
    else if ( aItem0->getFloatValue() == aItem1->getFloatValue())
      return 0;
    else if (aItem0->getFloatValue() > aItem1->getFloatValue())
      return 1;
    else
      return 2;
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) 
  {
    if ( aItem0->getDecimalValue() < aItem1->getDecimalValue())
      return -1;
    else if ( aItem0->getDecimalValue() == aItem1->getDecimalValue())
      return 0;
    else
      return 1;
  }
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
  {
    if (aCollation == 0) {
      aCollation = aRuntimeCB->theCollationCache->getDefaultCollator();
    }
    int res = aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation);
    if (res < 0)
      return -1;
    else if (res > 0)
      return 1;
    else
      return 0;
  } 
  else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE) &&
           TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
  {
    if (aItem0->getBooleanValue() == aItem1->getBooleanValue())
      return 0;
    else if (aItem0->getBooleanValue() < aItem1->getBooleanValue())
      return -1;
    else
      return 1;
  }

  // catch InvalidTimezoneException
  try 
  {
    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE)
        &&
        TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
    {
      return aItem0->getDateValue().compare(&aItem1->getDateValue(),
                                            aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
    {
      return aItem0->getTimeValue().compare(&aItem1->getTimeValue(),
                                            aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
    {
      return aItem0->getDateTimeValue().compare(&aItem1->getDateTimeValue(),
                                                aRuntimeCB->theDynamicContext->get_implicit_timezone());
      
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE))
    {
      return aItem0->getGYearMonthValue().compare(&aItem1->getGYearMonthValue(),
                                                  aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE))
    {
      return aItem0->getGYearValue().compare(&aItem1->getGYearValue(),
                                             aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE))
    {
      return aItem0->getGMonthDayValue().compare(&aItem1->getGMonthDayValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE))
    {
      return aItem0->getGMonthValue().compare(&aItem1->getGMonthValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GDAY_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GDAY_TYPE_ONE))
    {
      return aItem0->getGDayValue().compare(&aItem1->getGDayValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)
             &&
             (!TypeOps::is_equal(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
             &&
             (!TypeOps::is_equal(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
             &&
             TypeOps::is_equal(*type0, *type1))
    {
      return aItem0->getDurationValue().compare(aItem1->getDurationValue());
    }
  } 
  catch (InvalidTimezoneException)
  {
    ZORBA_ERROR(FODT0003);
  }
  
  // TODO comparisons for all types

  return -2;
}

  
/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  IsSameNodeIterator                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


  bool
  OpIsSameNodeIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
      if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 0); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(result, lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

  bool
  OpNodeBeforeIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
      if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == -1); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(result, lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

  bool
  OpNodeAfterIterator::nextImpl(store::Item_t& result, PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    if (consumeNext(lItem0, theChildren[0].getp(), aPlanState)) {
      if (consumeNext(lItem1, theChildren[1].getp(), aPlanState)) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 1); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(result, lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

}
