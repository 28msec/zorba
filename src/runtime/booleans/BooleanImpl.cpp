/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "system/globalenv.h"
#include "runtime/booleans/BooleanImpl.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "runtime/api/runtimecb.h"
#include "errors/error_manager.h"
#include "runtime/accessors//AccessorsImpl.h"
#include "store/api/temp_seq.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "context/collation_cache.h"
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

  store::Item_t
  FnBooleanIterator::effectiveBooleanValue ( const QueryLoc& loc, PlanState& planState, const PlanIterator* iter, bool negate )
  {
    store::Item_t item;
    xqtref_t type;
    store::Item_t result;

    item = consumeNext(iter, planState);

    if ( item == NULL )
    {
      // empty sequence => false
      result = GENV_ITEMFACTORY->createBoolean ( negate ^ false );
    }
    else if ( item->isNode() )
    {
      // node => true
      result = GENV_ITEMFACTORY->createBoolean ( negate ^ true );
    }
    else
    {
      type = planState.theCompilerCB->m_sctx->get_typemanager()->create_value_type(item);
      if (( consumeNext(iter, planState) == NULL )
          && (TypeOps::is_equal(*type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.STRING_TYPE_ONE )
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE )
              || TypeOps::is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE )
              || TypeOps::is_numeric ( *type )))
      {
        // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
        // => effective boolean value is defined in the items
        result = item->getEBV();
        if (negate)
          result = GENV_ITEMFACTORY->createBoolean ( negate ^ result->getBooleanValue() );
      }
      else
      {
        ZORBA_ERROR_LOC_DESC( ZorbaError::FORG0006, loc,  
          "Wrong arguments in fn:boolean function.");
      }
    }

    return result;
  }

  store::Item_t
  FnBooleanIterator::nextImpl(PlanState& planState) const
  { 
    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);
    STACK_PUSH ( 
      FnBooleanIterator::effectiveBooleanValue ( this->loc, planState, theChild, theNegate ),
      aState
    );
    STACK_END (aState);
  }
  /* end class FnBooleanIterator */
  
  /* begin class LogicIterator */
  LogicIterator::LogicIterator ( const QueryLoc& loc, PlanIter_t theChild0, PlanIter_t theChild1, LogicType aLogicType)
  :
    BinaryBaseIterator<LogicIterator, PlanIteratorState> ( loc, theChild0, theChild1), theLogicType(aLogicType) {}
  
  LogicIterator::~LogicIterator(){}
      
  store::Item_t 
  LogicIterator::nextImpl(PlanState& planState) const
  {
    bool bRes = false;
    
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );

    switch(theLogicType)
    {
    case AND:
      bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)->getBooleanValue() 
              && FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1)->getBooleanValue();
      break;
    case OR:
      bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild0)->getBooleanValue() 
              || FnBooleanIterator::effectiveBooleanValue(this->loc, planState, theChild1)->getBooleanValue();;
      break;
    }
    STACK_PUSH(GENV_ITEMFACTORY->createBoolean(bRes), state);
    STACK_END (state);
  }
  /* end class LogicIterator */

  /* begin class ComparisonIterator */
  CompareIterator::CompareIterator ( const QueryLoc& loc, PlanIter_t aChild0, PlanIter_t aChild1, CompareConsts::CompareType aCompType )
  :
    BinaryBaseIterator<CompareIterator, PlanIteratorState> ( loc, aChild0, aChild1 ), 
    theCompType(aCompType) 
  { }
  
  CompareIterator::~CompareIterator()
  { }
  
  store::Item_t
  CompareIterator::nextImpl ( PlanState& planState ) const
  {
    store::Item_t lItem0;
    store::Item_t lItem1;
    Iterator_t lIter0;
    Iterator_t lIter1;
    store::TempSeq_t temp0;
    store::TempSeq_t temp1;
    int32_t i0;
    int32_t i1;
    bool found;
  
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  
    if ( this->isGeneralComparison() )
    {
      // TODO Optimizations for >, >=, < and <=
      lIter0 = new PlanIteratorWrapper ( theChild0, planState );
      lIter1 = new PlanIteratorWrapper ( theChild1, planState );
      temp0 = GENV_STORE.createTempSeq ( lIter0 );
      temp1 = GENV_STORE.createTempSeq ( lIter1 );
      i0 = 1;
      found = false;
      while ( !found && temp0->containsItem ( i0 ) )
      {
        i1 = 1;
        while ( !found && temp1->containsItem ( i1 ) )
        {
          lItem0 = temp0->getItem(i0);
          lItem1 = temp1->getItem(i1);
          if ( CompareIterator::generalComparison ( planState.theRuntimeCB, 
                                                    lItem0, lItem1, theCompType ) )
            found = true;
          i1++;
        }
        i0++;
      }
  
      STACK_PUSH ( GENV_ITEMFACTORY->createBoolean ( found ), state );
    } /* if general comparison */
    else if ( this->isValueComparison() )
    {
      if ( ( ( lItem0 = consumeNext ( theChild0.getp(), planState ) ) != NULL )
              && ( ( lItem1 = consumeNext ( theChild1.getp(), planState ) ) !=NULL ) )
      {
        STACK_PUSH ( GENV_ITEMFACTORY->createBoolean ( CompareIterator::valueComparison ( planState.theRuntimeCB, lItem0, lItem1, theCompType ) ), state );
        if ( consumeNext ( theChild0.getp(), planState ) != NULL 
             || consumeNext ( theChild1.getp(), planState ) != NULL )
        {
          ZORBA_ERROR_LOC_DESC(  ZorbaError::XPTY0004, loc, 
                             "Value comparions must not be made with sequences with length greater 1.");
        }
      }
    } /* if value comparison */
    else if ( this->isNodeComparison() )
    {
      ZORBA_ERROR_LOC_DESC(  ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
                            loc,  "Node comparison is not yet implemented.");
    } /* if node comparison */
  
    STACK_END (state);
  }
  
  bool 
  CompareIterator::isValueComparison() const
  {
    bool retVal = false;
    switch(theCompType)
    {
    case CompareConsts::VALUE_EQUAL:
    case CompareConsts::VALUE_NOT_EQUAL:
    case CompareConsts::VALUE_LESS:
    case CompareConsts::VALUE_LESS_EQUAL:
    case CompareConsts::VALUE_GREATER:
    case CompareConsts::VALUE_GREATER_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  
  bool 
  CompareIterator::isGeneralComparison() const
  {
    bool retVal = false;
    switch(theCompType)
    {
    case CompareConsts::GENERAL_EQUAL:
    case CompareConsts::GENERAL_NOT_EQUAL:
    case CompareConsts::GENERAL_LESS:
    case CompareConsts::GENERAL_LESS_EQUAL:
    case CompareConsts::GENERAL_GREATER:
    case CompareConsts::GENERAL_GREATER_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  
  bool
  CompareIterator::isNodeComparison() const
  {
    bool retVal = false;
    switch(theCompType)
    {
    case CompareConsts::NODE_EQUAL:
    case CompareConsts::NODE_NOT_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  

  std::pair<store::Item_t, store::Item_t>
  CompareIterator::valueCasting(
    RuntimeCB* aRuntimeCB,
    store::Item_t aItem0,
    store::Item_t aItem1)
  {
    xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type(aItem0);
    xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type(aItem1);

    // all untyped Atomics to String
    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    if  (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    
    return std::pair<store::Item_t,store::Item_t>(aItem0, aItem1);
  }
  

  std::pair<store::Item_t, store::Item_t>
  CompareIterator::generalCasting(
    RuntimeCB* aRuntimeCB,
    store::Item_t aItem0,
    store::Item_t aItem1)
  {
    xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type (aItem0);

    xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                     create_value_type (aItem1);

    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (TypeOps::is_numeric(*type1))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        aItem0 = GenericCast::instance()->cast(aItem0, type1);
      }
    }
    
    if (TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (TypeOps::is_numeric(*type0))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        aItem1 = GenericCast::instance()->cast(aItem1, type0);
      }
    }
    return std::pair<store::Item_t,store::Item_t>(aItem0, aItem1);
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

    ZORBA_ERROR_DESC(  ZorbaError::XPTY0004, "Dynamic type of a value does not match a required type.");
  return false;
}
  

std::pair<store::Item_t, store::Item_t>
CompareIterator::typePromotion(
    RuntimeCB* aRuntimeCB, 
    store::Item_t aItem0, store::Item_t aItem1)
{
  xqtref_t aType0 = aRuntimeCB->theStaticContext->get_typemanager()->
                    create_value_type (aItem0);
  
  xqtref_t aType1 = aRuntimeCB->theStaticContext->get_typemanager()->
                    create_value_type (aItem1);
    
  store::Item_t lResult = GenericCast::instance()->promote(aItem0, aType1); 
  if (lResult != 0) {
    aItem0 = lResult;
  }
  lResult = GenericCast::instance()->promote(aItem1, aType0);
  if (lResult != 0) {
    aItem1 = lResult;
  }
    
  return std::pair<store::Item_t,store::Item_t>(aItem0, aItem1);
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
  } /* end CompareIterator::generalComparison (...) */
  

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
  

int8_t
CompareIterator::equal(
    RuntimeCB* aRuntimeCB, 
    const store::Item_t& aItem0,
    const store::Item_t& aItem1,
    XQPCollator* aCollation)
{
  int result;
  // tries first normal compare
  result = CompareIterator::compare(aRuntimeCB, aItem0, aItem1, aCollation);
  if (result == 0)
    return 0;
  else if (result == -1 || result == 1 || result == 2)
    return 1;

  int equal = -2;
  xqtref_t type0 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem0.getp());

  xqtref_t type1 = aRuntimeCB->theStaticContext->get_typemanager()->
                   create_value_type (aItem1.getp());

  // TODO, equal implementation for types which do not support compare

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)
        &&
        TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
  {
    equal = (*aItem0->getDurationValue() == *aItem1->getDurationValue());
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.QNAME_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
  {
    equal = 0;
    if(aItem0->getLocalName() == aItem1->getLocalName())
      if((aItem0->getNamespace().empty() && aItem1->getNamespace().empty()) ||
         (aItem0->getNamespace() == aItem1->getNamespace()))
        equal = 1;
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.BASE64BINARY_TYPE_ONE))
  {
    if (aItem0->equals(aItem1, aRuntimeCB))
      equal = 1;
    else
      equal = 0;
    return (equal==-2)?-2:(equal==0?1:0);
  }
  else if(TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.HEXBINARY_TYPE_ONE) &&
          TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.HEXBINARY_TYPE_ONE))
  {
    if (aItem0->equals(aItem1, aRuntimeCB))
      equal = 1;
    else
      equal = 0;
    return (equal==-2)?-2:(equal==0?1:0);
  }
  return -2;
}

  
int8_t CompareIterator::valueEqual(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator* aCollation)
{
  std::pair<store::Item_t, store::Item_t> lPair;
  lPair = valueCasting(aRuntimeCB, aItem0, aItem1);
  lPair = typePromotion(aRuntimeCB, lPair.first, lPair.second);
  return equal(aRuntimeCB, lPair.first, lPair.second, aCollation);
}

  
int8_t CompareIterator::generalEqual(
    RuntimeCB* aRuntimeCB,
    const store::Item_t& aItem0,
    const store::Item_t& aItem1, 
    XQPCollator* aCollation)
{
  std::pair<store::Item_t, store::Item_t> lPair;
  lPair = generalCasting(aRuntimeCB, aItem0, aItem1);
  lPair = typePromotion(aRuntimeCB, lPair.first, lPair.second);
  return equal(aRuntimeCB, lPair.first, lPair.second, aCollation);
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

  if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
      && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)) {
    if (aItem0->getBooleanValue() == aItem1->getBooleanValue())
      return 0;
    else if (aItem0->getBooleanValue() < aItem1->getBooleanValue())
      return -1;
    else
      return 1;
  } else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
             && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
    if ( aItem0->getFloatValue() < aItem1->getFloatValue())
      return -1;
    else if ( aItem0->getFloatValue() == aItem1->getFloatValue())
      return 0;
    else if (aItem0->getFloatValue() > aItem1->getFloatValue())
      return 1;
    else
      return 2;
  } else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
             && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
    if ( aItem0->getDoubleValue() < aItem1->getDoubleValue())
      return -1;
    else if ( aItem0->getDoubleValue() == aItem1->getDoubleValue())
      return 0;
    else if (aItem0->getDoubleValue() > aItem1->getDoubleValue())
      return 1;
    else
      return 2;
  } else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
             && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) {
    if ( aItem0->getDecimalValue() < aItem1->getDecimalValue())
      return -1;
    else if ( aItem0->getDecimalValue() == aItem1->getDecimalValue())
      return 0;
    else
      return 1;
  } else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
             && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) {
    if (aCollation == 0) {
      aCollation =  aRuntimeCB->theCollationCache->getDefaultCollator();
    }
    return aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation);
  } else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)
             && TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
    if (aCollation == 0) {
      aCollation = aRuntimeCB->theCollationCache->getDefaultCollator();
    }
    return aItem0->getStringValue()->compare(aItem1->getStringValue(), aCollation);
  } 
    
  // catch InvalidTimezoneException
  try {
    if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE)
        &&
        TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
    {
      return aItem0->getDateValue()->compare(*aItem1->getDateValue(),
                                             aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
    {
      return aItem0->getTimeValue()->compare(*aItem1->getTimeValue(),
                                             aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
    {
      return aItem0->getDateTimeValue()->compare(*aItem1->getDateTimeValue(),
                                                 aRuntimeCB->theDynamicContext->get_implicit_timezone());
      
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE))
    {
      return aItem0->getGYearMonthValue()->compare(*aItem1->getGYearMonthValue(),
                                                   aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE))
    {
      return aItem0->getGYearValue()->compare(*aItem1->getGYearValue(),
                                              aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE))
    {
      return aItem0->getGMonthDayValue()->compare(*aItem1->getGMonthDayValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE))
    {
      return aItem0->getGMonthValue()->compare(*aItem1->getGMonthValue(),
                                       aRuntimeCB->theDynamicContext->get_implicit_timezone());
    }
    else if (TypeOps::is_subtype(*type0, *GENV_TYPESYSTEM.GDAY_TYPE_ONE)
             &&
             TypeOps::is_subtype(*type1, *GENV_TYPESYSTEM.GDAY_TYPE_ONE))
    {
      return aItem0->getGDayValue()->compare(*aItem1->getGDayValue(),
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
      return aItem0->getDurationValue()->compare(*aItem1->getDurationValue());
    }
  } 
  catch (InvalidTimezoneException)
  {
    ZORBA_ERROR(ZorbaError::FODT0003);
  }
  
  // TODO comparisons for all types

  return -2;
}

  
  int8_t CompareIterator::valueCompare(RuntimeCB* aRuntimeCB,
                                       const store::Item_t& aItem0, const store::Item_t& aItem1, 
                                       XQPCollator* aCollation) {
    std::pair<store::Item_t, store::Item_t> lPair;
    lPair = valueCasting(aRuntimeCB, aItem0, aItem1);
    lPair = typePromotion(aRuntimeCB, lPair.first, lPair.second);
    return compare(aRuntimeCB, lPair.first, lPair.second, aCollation);
  }
  
  int8_t CompareIterator::generalCompare(RuntimeCB* aRuntimeCB,
                                         const store::Item_t& aItem0, const store::Item_t& aItem1, 
                                         XQPCollator* aCollation) {
    std::pair<store::Item_t, store::Item_t> lPair;
    lPair = generalCasting(aRuntimeCB, aItem0, aItem1);
    lPair = typePromotion(aRuntimeCB, lPair.first, lPair.second);
    return compare(aRuntimeCB, lPair.first, lPair.second, aCollation);
  }
  /* end class ComparisonIterator */

  store::Item_t
  OpIsSameNodeIterator::nextImpl(PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0].getp(), aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1].getp(), aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 0); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

  store::Item_t
  OpNodeBeforeIterator::nextImpl(PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0].getp(), aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1].getp(), aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == -1); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

  store::Item_t
  OpNodeAfterIterator::nextImpl(PlanState& aPlanState) const
  { 
    bool lBool;
    store::Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0].getp(), aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1].getp(), aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (GENV_STORE.compareNodes(lItem0, lItem1) == 1); 
        STACK_PUSH ( 
          GENV_ITEMFACTORY->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END (aState);
  }

}
