/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "system/globalenv.h"
#include "runtime/booleans/BooleanImpl.h"
#include "types/casting.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "runtime/accessors//AccessorsImpl.h"
#include "store/api/temp_seq.h"

namespace xqp
{

  /*______________________________________________________________________
  |
  | 15.1.1 fn:boolean
  | fn:boolean($arg as item()*) as xs:boolean
  |
  | Computes the effective boolean value of the sequence $arg.
  |_______________________________________________________________________*/
  FnBooleanIterator::FnBooleanIterator ( const yy::location& loc, PlanIter_t& aIter, bool aNegate )
  :
    UnaryBaseIterator<FnBooleanIterator, PlanIteratorState> ( loc, aIter ), theNegate ( aNegate ) {}
    
  FnBooleanIterator::~FnBooleanIterator() {}

  Item_t
  FnBooleanIterator::effectiveBooleanValue ( const yy::location& loc, PlanState& planState, PlanIter_t& iter, bool negate )
  {
    Item_t item;
    TypeSystem::xqtref_t type;
    Item_t result;

    // TODO produceNext must be replaced to allow batching
    item = iter->produceNext(planState);

    if ( item == NULL )
    {
      // empty sequence => false
      result = Zorba::getItemFactory()->createBoolean ( negate ^ false );
    }
    else if ( item->isNode() )
    {
      // node => true
      result = Zorba::getItemFactory()->createBoolean ( negate ^ true );
    }
    else
    {
      rchandle<Item> lType = item->getType();
      std::string str = lType->getLocalName();
      str = lType->getPrefix();
      str = lType->getNamespace();
      type = GENV_TYPESYSTEM.create_type(lType, TypeSystem::QUANT_ONE);
      bool res = GENV_TYPESYSTEM.is_numeric ( *type );
      if (
          // TODO produceNext must be replaced to allow batching
          ( iter->produceNext(planState) == NULL )
          &&
          ( GENV_TYPESYSTEM.is_equal(*type, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
             || GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.STRING_TYPE_ONE )
             || GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE )
             || GENV_TYPESYSTEM.is_subtype ( *type, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE )
            || GENV_TYPESYSTEM.is_numeric ( *type )
          )
      )
      {
        // atomic type xs_boolean, xs_string, xs_anyURI, xs_untypedAtomic
        // => effective boolean value is defined in the items
        result = item->getEBV();
        if (negate)
          result = Zorba::getItemFactory()->createBoolean ( negate ^ result->getBooleanValue() );
      }
      else
      {
        ZORBA_ERROR_ALERT( ZorbaError::FORG0006,
            &loc, false, "Wrong arguments in fn:boolean function.");
      }
    }

    return result;
  }

  Item_t
  FnBooleanIterator::nextImpl(PlanState& planState)
  { 
    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, planState);
    STACK_PUSH ( 
      FnBooleanIterator::effectiveBooleanValue ( this->loc, planState, theChild, theNegate ),
      aState
    );
    STACK_END();
  }
  /* end class FnBooleanIterator */
  
  /* begin class LogicIterator */
  LogicIterator::LogicIterator ( const yy::location& loc, PlanIter_t theChild0, PlanIter_t theChild1, LogicType aLogicType)
  :
    BinaryBaseIterator<LogicIterator, PlanIteratorState> ( loc, theChild0, theChild1), theLogicType(aLogicType) {}
  
  LogicIterator::~LogicIterator(){}
      
  Item_t 
  LogicIterator::nextImpl(PlanState& planState)
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
    STACK_PUSH(Zorba::getItemFactory()->createBoolean(bRes), state);
    STACK_END();
  }
  /* end class LogicIterator */

  /* begin class ComparisonIterator */
  CompareIterator::CompareIterator ( const yy::location& loc, PlanIter_t aChild0, PlanIter_t aChild1, CompareType aCompType )
  :
    BinaryBaseIterator<CompareIterator, PlanIteratorState> ( loc, aChild0, aChild1 ), 
    theCompType(aCompType) 
  { }
  
  CompareIterator::~CompareIterator()
  { }
  
  Item_t
  CompareIterator::nextImpl ( PlanState& planState )
  {
    Item_t lItem0;
    Item_t lItem1;
    Iterator_t lIter0;
    Iterator_t lIter1;
    TempSeq_t temp0;
    TempSeq_t temp1;
    int32_t i0;
    int32_t i1;
    bool found;
    bool empty;
    int8_t compareResult;
  
    PlanIteratorState* state;
    DEFAULT_STACK_INIT ( PlanIteratorState, state, planState );
  
    if ( this->isGeneralComparison() )
    {
      // TODO Optimizations for >, >=, < and <=
      lIter0 = new PlanIteratorWrapper ( theChild0, planState );
      lIter1 = new PlanIteratorWrapper ( theChild1, planState );
      temp0 = Zorba::getStore()->createTempSeq ( lIter0 );
      temp1 = Zorba::getStore()->createTempSeq ( lIter1 );
      i0 = 1;
      found = false;
      while ( !found && temp0->containsItem ( i0 ) )
      {
        i1 = 1;
        while ( !found && temp1->containsItem ( i1 ) )
        {
          lItem0 = temp0->getItem(i0);
          lItem1 = temp1->getItem(i1);
          if ( CompareIterator::generalComparison ( lItem0, lItem1, theCompType ) )
            found = true;
          i1++;
        }
        i0++;
      }
  
      STACK_PUSH ( Zorba::getItemFactory()->createBoolean ( found ), state );
    } /* if general comparison */
    else if ( this->isValueComparison() )
    {
      if ( ( ( lItem0 = this->consumeNext ( theChild0, planState ) ) != NULL )
              && ( ( lItem1 = this->consumeNext ( theChild1, planState ) ) !=NULL ) )
      {
        STACK_PUSH ( Zorba::getItemFactory()->createBoolean ( CompareIterator::valueComparison ( lItem0, lItem1, theCompType ) ), state );
        if ( this->consumeNext ( theChild0, planState ) != NULL || this->consumeNext ( theChild1, planState ) != NULL )
        {
          ZORBA_ERROR_ALERT( ZorbaError::XPTY0004,
              &loc, false, "Value comparions must not be made with sequences with length greater 1.");
        }
      }
    } /* if value comparison */
    else if ( this->isNodeComparison() )
    {
      ZORBA_ERROR_ALERT( ZorbaError::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
          &loc, false, "Node comparison is not yet implemented.");
    } /* if node comparison */
  
    STACK_END();
  }
  
  bool 
  CompareIterator::isValueComparison()
  {
    bool retVal = false;
    switch(theCompType)
    {
    case VALUE_EQUAL:
    case VALUE_NOT_EQUAL:
    case VALUE_LESS:
    case VALUE_LESS_EQUAL:
    case VALUE_GREATER:
    case VALUE_GREATER_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  
  bool 
  CompareIterator::isGeneralComparison()
  {
    bool retVal = false;
    switch(theCompType)
    {
    case GENERAL_EQUAL:
    case GENERAL_NOT_EQUAL:
    case GENERAL_LESS:
    case GENERAL_LESS_EQUAL:
    case GENERAL_GREATER:
    case GENERAL_GREATER_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  
  bool
  CompareIterator::isNodeComparison()
  {
    bool retVal = false;
    switch(theCompType)
    {
    case NODE_EQUAL:
    case NODE_NOT_EQUAL:
      retVal = true;
      break;
    default:
      retVal = false;
      break;
    }
    return retVal;
  }
  
  std::pair<Item_t, Item_t> CompareIterator::valueCasting(Item_t aItem0, Item_t aItem1) {
    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(aItem0->getType(), TypeSystem::QUANT_ONE);
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(aItem1->getType(), TypeSystem::QUANT_ONE);
    // all untyped Atomics to String
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    if  (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    
    return std::pair<Item_t,Item_t>(aItem0, aItem1);
  }
  
  std::pair<Item_t, Item_t> CompareIterator::generalCasting(Item_t aItem0, Item_t aItem1) {
    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(aItem0->getType(), TypeSystem::QUANT_ONE);
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(aItem1->getType(), TypeSystem::QUANT_ONE);
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_numeric(*type1))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        aItem0 = GenericCast::instance()->cast(aItem0, type1);
      }
    }
    
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_numeric(*type0))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        aItem1 = GenericCast::instance()->cast(aItem1, type0);
      }
    }
    return std::pair<Item_t,Item_t>(aItem0, aItem1);
  }
  
bool CompareIterator::boolResult ( int8_t aCompValue, CompareType aCompType )
{
  if ( aCompValue > -2 )
    switch ( aCompType )
    {
      case VALUE_EQUAL:
      case GENERAL_EQUAL:
        return aCompValue == 0;
        break;
      case VALUE_NOT_EQUAL:
      case GENERAL_NOT_EQUAL:
        return aCompValue != 0;
        break;
      case VALUE_GREATER:
      case GENERAL_GREATER:
        return aCompValue == 1;
        break;
      case VALUE_GREATER_EQUAL:
      case GENERAL_GREATER_EQUAL:
        return (aCompValue == 0) || (aCompValue == 1);
        break;
      case VALUE_LESS:
      case GENERAL_LESS:
        return aCompValue == -1;
        break;
      case VALUE_LESS_EQUAL:
      case GENERAL_LESS_EQUAL:
        return (aCompValue == -1) || (aCompValue == 0);
        break;
      default:
        break;
    }

  ZORBA_ERROR_ALERT( ZorbaError::FORG0006, NULL, false, "Dynamic type of a value does not match a required type.");
  return false;
}
  
  std::pair<Item_t, Item_t> CompareIterator::typePromotion(Item_t aItem0, Item_t aItem1) {
    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(aItem0->getType(), TypeSystem::QUANT_ONE);
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(aItem1->getType(), TypeSystem::QUANT_ONE);
    
    // numeric promotion
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.FLOAT_TYPE_ONE);
      }
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
      {
        aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
    }
    
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.FLOAT_TYPE_ONE);
      }
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
      {
        aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
    }
    // uri promotion
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
    {
      aItem1 = GenericCast::instance()->cast(aItem1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) 
    {
      aItem0 = GenericCast::instance()->cast(aItem0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    
    return std::pair<Item_t,Item_t>(aItem0, aItem1);
  }
  
  bool
  CompareIterator::generalComparison(const Item_t& aItem0, const Item_t& aItem1, 
                                     CompareType aCompType, xqpString* aCollation)
  {
    int8_t compValue = -2;
    switch(aCompType)
    {
      case VALUE_EQUAL:
      case GENERAL_EQUAL:
      case VALUE_NOT_EQUAL:
      case GENERAL_NOT_EQUAL:
        if (aCollation == 0)
          compValue = CompareIterator::generalEqual(aItem0, aItem1);
        else
          compValue = CompareIterator::generalEqual(aItem0, aItem1, aCollation);
        break;
      case VALUE_GREATER:
      case GENERAL_GREATER:
      case VALUE_GREATER_EQUAL:
      case GENERAL_GREATER_EQUAL:
      case VALUE_LESS:
      case GENERAL_LESS:
      case VALUE_LESS_EQUAL:
      case GENERAL_LESS_EQUAL:
        if (aCollation == 0)
          compValue = CompareIterator::generalCompare(aItem0, aItem1);
        else
          compValue = CompareIterator::generalCompare(aItem0, aItem1, aCollation);
      default:
        break;
    }
    
    return boolResult(compValue, aCompType);
  } /* end CompareIterator::generalComparison (...) */
  
  bool CompareIterator::valueComparison(const Item_t& aItem0, const Item_t& aItem1, 
                                        CompareType aCompType, xqpString* aCollation)
  {
    int8_t compValue = -2;
    switch(aCompType)
    {
      case VALUE_EQUAL:
      case GENERAL_EQUAL:
      case VALUE_NOT_EQUAL:
      case GENERAL_NOT_EQUAL:
        if (aCollation == 0)
          compValue = CompareIterator::valueEqual(aItem0, aItem1);
        else
          compValue = CompareIterator::valueEqual(aItem0, aItem1, aCollation);
        break;
      case VALUE_GREATER:
      case GENERAL_GREATER:
      case VALUE_GREATER_EQUAL:
      case GENERAL_GREATER_EQUAL:
      case VALUE_LESS:
      case GENERAL_LESS:
      case VALUE_LESS_EQUAL:
      case GENERAL_LESS_EQUAL:
        if (aCollation == 0)
          compValue = CompareIterator::valueCompare(aItem0, aItem1);
        else
          compValue = CompareIterator::valueCompare(aItem0, aItem1, aCollation);
      default:
        break;
    }
    
    return boolResult(compValue, aCompType);
  }
  
  int8_t
  CompareIterator::equal(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation)
  {
    // tries first normal compare
    int8_t compareRes = CompareIterator::compare(aItem0, aItem1, aCollation);
    if (compareRes == 0)
      return 0;
    else if (compareRes == -1 || compareRes == 1 || compareRes == 2)
      return 1;
    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(aItem0->getType(), TypeSystem::QUANT_ONE);
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(aItem1->getType(), TypeSystem::QUANT_ONE);
    bool equal;
//     if (false)
      // TODO, equal implementation for types which do not support compare
//     else
      return -2;
    
    if (equal)
      return 0;
    else
      return 1;
  }
  
  int8_t CompareIterator::valueEqual(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation) {
    std::pair<Item_t, Item_t> lPair;
    lPair = valueCasting(aItem0, aItem1);
    lPair = typePromotion(lPair.first, lPair.second);
    return equal(lPair.first, lPair.second, aCollation);
  }
  
  int8_t CompareIterator::generalEqual(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation) {
    std::pair<Item_t, Item_t> lPair;
    lPair = generalCasting(aItem0, aItem1);
    lPair = typePromotion(lPair.first, lPair.second);
    return equal(lPair.first, lPair.second, aCollation);
  }
  
  int8_t 
  CompareIterator::compare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation)
  {
    TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(aItem0->getType(), TypeSystem::QUANT_ONE);
    TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(aItem1->getType(), TypeSystem::QUANT_ONE);
    int8_t ret = -2;
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)) {
      if (aItem0->getBooleanValue() == aItem1->getBooleanValue())
        ret = 0;
      else if (aItem0->getBooleanValue() < aItem1->getBooleanValue())
        return -1;
      else
        return 1;
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      if ( aItem0->getFloatValue() < aItem1->getFloatValue())
        ret = -1;
      else if ( aItem0->getFloatValue() == aItem1->getFloatValue())
        ret = 0;
      else if (aItem0->getFloatValue() > aItem1->getFloatValue())
        ret = 1;
      else
        ret = 2;
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
      if ( aItem0->getDoubleValue() < aItem1->getDoubleValue())
        ret = -1;
      else if ( aItem0->getDoubleValue() == aItem1->getDoubleValue())
        ret = 0;
      else if (aItem0->getDoubleValue() > aItem1->getDoubleValue())
        ret = 1;
      else
        ret = 2;
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
    && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)) {
      if ( aItem0->getDecimalValue() < aItem1->getDecimalValue())
        ret = -1;
      else if ( aItem0->getDecimalValue() == aItem1->getDecimalValue())
        ret = 0;
      else
        ret = 1;
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)) {
      if (aCollation == 0)
        ret = aItem0->getStringValue().compare(aItem1->getStringValue());
      else
        ret = aItem0->getStringValue().compare(aItem1->getStringValue(), *aCollation);
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) {
      if (aCollation == 0)
        ret = aItem0->getStringValue().compare(aItem1->getStringValue());
      else
        ret = aItem0->getStringValue().compare(aItem1->getStringValue(), *aCollation);
    } else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DATE_TYPE_ONE)
               &&
              GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DATE_TYPE_ONE))
    {
      ret = aItem0->getDateValue()->compare(*aItem1->getDateValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.TIME_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.TIME_TYPE_ONE))
    {
      ret = aItem0->getTimeValue()->compare(*aItem1->getTimeValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DATETIME_TYPE_ONE))
    {
      ret = aItem0->getDateTimeValue()->compare(*aItem1->getDateTimeValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DURATION_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DURATION_TYPE_ONE))
    {
      ret = aItem0->getDurationValue()->compare(*aItem1->getDurationValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_MONTH_TYPE_ONE))
    {
      ret = aItem0->getGYearMonthValue()->compare(*aItem1->getGYearMonthValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.GYEAR_TYPE_ONE))
    {
      ret = aItem0->getGYearValue()->compare(*aItem1->getGYearValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_DAY_TYPE_ONE))
    {
      ret = aItem0->getGMonthDayValue()->compare(*aItem1->getGMonthDayValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.GMONTH_TYPE_ONE))
    {
      ret = aItem0->getGMonthValue()->compare(*aItem1->getGMonthValue());
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.GDAY_TYPE_ONE)
             &&
             GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.GDAY_TYPE_ONE))
    {
      ret = aItem0->getGDayValue()->compare(*aItem1->getGDayValue());
    }

    
    // TODO comparisons for all types

    return ret;
  }
  
  int8_t CompareIterator::valueCompare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation) {
    std::pair<Item_t, Item_t> lPair;
    lPair = valueCasting(aItem0, aItem1);
    lPair = typePromotion(lPair.first, lPair.second);
    return compare(lPair.first, lPair.second, aCollation);
  }
  
  int8_t CompareIterator::generalCompare(const Item_t& aItem0, const Item_t& aItem1, xqpString* aCollation) {
    std::pair<Item_t, Item_t> lPair;
    lPair = generalCasting(aItem0, aItem1);
    lPair = typePromotion(lPair.first, lPair.second);
    return compare(lPair.first, lPair.second, aCollation);
  }
  /* end class ComparisonIterator */

  Item_t
  OpIsSameNodeIterator::nextImpl(PlanState& aPlanState)
  { 
    bool lBool;
    Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0], aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1], aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_ALERT( ZorbaError::XPTY0004,
             &loc, false, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (Zorba::getStore()->compare(lItem0, lItem1) == 0); 
        STACK_PUSH ( 
          Zorba::getItemFactory()->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END();
  }

  Item_t
  OpNodeBeforeIterator::nextImpl(PlanState& aPlanState)
  { 
    bool lBool;
    Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0], aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1], aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_ALERT( ZorbaError::XPTY0004,
             &loc, false, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (Zorba::getStore()->compare(lItem0, lItem1) == -1); 
        STACK_PUSH ( 
          Zorba::getItemFactory()->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END();
  }

  Item_t
  OpNodeAfterIterator::nextImpl(PlanState& aPlanState)
  { 
    bool lBool;
    Item_t lItem0, lItem1;

    PlanIteratorState* aState;
    DEFAULT_STACK_INIT(PlanIteratorState, aState, aPlanState);

    lItem0 = consumeNext(theChildren[0], aPlanState);
    if (lItem0 != 0) {
      lItem1 = consumeNext(theChildren[1], aPlanState);
      if (lItem1 != 0) {
        if (!lItem0->isNode() || !lItem0->isNode()) {
           ZORBA_ERROR_ALERT( ZorbaError::XPTY0004,
             &loc, false, "The IsSameNode function must have nodes as parameters.");
        }
        lBool = (Zorba::getStore()->compare(lItem0, lItem1) == 1); 
        STACK_PUSH ( 
          Zorba::getItemFactory()->createBoolean(lBool),
          aState
        );
      }
    }
    STACK_END();
  }

}
