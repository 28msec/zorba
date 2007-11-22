/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "system/globalenv.h"
#include "runtime/booleans/BooleanImpl.h"
#include "types/casting.h"
#include "util/zorba.h"
#include "errors/Error.h"
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
    UnaryBaseIterator<FnBooleanIterator> ( loc, aIter ), theNegate ( aNegate ) {}
    
  FnBooleanIterator::~FnBooleanIterator() {}
      
  std::ostream&
  FnBooleanIterator::_show ( std::ostream& os ) const
  {
    theChild->show ( os );
    return os;
  }

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
      result = zorba::getItemFactory()->createBoolean ( negate ^ false );
    }
    else if ( item->isNode() )
    {
      // node => true
      result = zorba::getItemFactory()->createBoolean ( negate ^ true );
    }
    else
    {
      rchandle<QNameItem> lType = item->getType();
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
          result = zorba::getItemFactory()->createBoolean ( negate ^ result->getBooleanValue() );
      }
      else
      {
        // else error => fn:boolean not defined
        ZorbaErrorAlerts::error_alert (
            error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
            error_messages::RUNTIME_ERROR,
            &loc,
            false,
            "Wrong arguments in fn:boolean function!"
        );
      }
    }

    return result;
  }

  Item_t
  FnBooleanIterator::nextImpl(PlanState& planState)
  { 
    PlanIterator::PlanIteratorState* aState;
    STACK_INIT(PlanIterator::PlanIteratorState, aState, planState);
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
    BinaryBaseIterator<LogicIterator> ( loc, theChild0, theChild1), theLogicType(aLogicType) {}
  
  LogicIterator::~LogicIterator(){}
      
  Item_t 
  LogicIterator::nextImpl(PlanState& planState)
  {
    bool bRes;
    
    PlanIterator::PlanIteratorState* state;
    STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
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
    STACK_PUSH(zorba::getItemFactory()->createBoolean(bRes), state);
    STACK_END();
  }
  /* end class LogicIterator */

  /* begin class ComparisonIterator */
  CompareIterator::CompareIterator ( const yy::location& loc, PlanIter_t aChild0, PlanIter_t aChild1, CompareType aCompType )
  :
    BinaryBaseIterator<CompareIterator> ( loc, aChild0, aChild1 ), 
    theCompType(aCompType) 
  {
    theChild0 = new FnDataIterator ( loc, aChild0 );
    theChild1 = new FnDataIterator ( loc, aChild1 );
  }
  
  CompareIterator::~CompareIterator()
  { }
  
  Item_t
  CompareIterator::nextImpl ( PlanState& planState )
  {
    Item_t item0;
    Item_t item1;
    Iterator_t lIter0;
    Iterator_t lIter1;
    TempSeq_t temp0;
    TempSeq_t temp1;
    int32_t i0;
    int32_t i1;
    bool found;
    bool empty;
    int8_t compareResult;
  
    PlanIterator::PlanIteratorState* state;
    STACK_INIT ( PlanIterator::PlanIteratorState, state, planState );
  
    if ( this->isGeneralComparison() )
    {
      // TODO Optimizations for >, >=, < and <=
      lIter0 = new PlanIterWrapper ( theChild0, planState );
      lIter1 = new PlanIterWrapper ( theChild1, planState );
      temp0 = zorba::getStore()->createTempSeq ( lIter0 );
      temp1 = zorba::getStore()->createTempSeq ( lIter1 );
      i0 = 1;
      found = false;
      while ( !found && temp0->containsItem ( i0 ) )
      {
        i1 = 1;
        while ( !found && temp1->containsItem ( i1 ) )
        {
          if ( CompareIterator::generalComparison ( temp0->getItem ( i0 ), temp1->getItem ( i1 ), theCompType ) )
            found = true;
          i1++;
        }
        i0++;
      }
  
      STACK_PUSH ( zorba::getItemFactory()->createBoolean ( found ), state );
    } /* if general comparison */
    else if ( this->isValueComparison() )
    {
      if ( ( ( item0 = this->consumeNext ( theChild0, planState ) ) != NULL )
              && ( ( item1 = this->consumeNext ( theChild1, planState ) ) !=NULL ) )
      {
        STACK_PUSH ( zorba::getItemFactory()->createBoolean ( CompareIterator::valueComparison ( item0, item1, theCompType ) ), state );
        if ( this->consumeNext ( theChild0, planState ) != NULL || this->consumeNext ( theChild1, planState ) != NULL )
        {
          ZorbaErrorAlerts::error_alert (
              error_messages::FOCH0004_Collation_does_not_support_collation_units,
              error_messages::RUNTIME_ERROR,
              &loc,
              false,
              "Value comparions must not be made with sequences with length greater 1!"
          );
        }
      }
    } /* if value comparison */
    else if ( this->isNodeComparison() )
    {
      ZorbaErrorAlerts::error_alert (
          error_messages::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
          error_messages::RUNTIME_ERROR,
          &loc,
          false,
          "Node comparison is not yet implemented!"
      );
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
  
  bool
  CompareIterator::generalComparison(Item_t item0, Item_t item1, CompareType aCompType)
  {
        TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(item0->getType(), TypeSystem::QUANT_ONE);
        TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(item1->getType(), TypeSystem::QUANT_ONE);
        if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_numeric(*type1))
      {
        item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        item0 = GenericCast::instance()->cast(item0, type1);
      }
    }
    
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_numeric(*type0))
      {
        item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
               || GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      {
        item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
      }
      else
      {
        item1 = GenericCast::instance()->cast(item1, type0);
      }
    }
    
    return CompareIterator::valueComparison(item0, item1, aCompType);
  } /* end CompareIterator::generalComparison (...) */
  
  bool CompareIterator::valueComparison(Item_t item0, Item_t item1, CompareType aCompType)
  {
        TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(item0->getType(), TypeSystem::QUANT_ONE);
        TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(item1->getType(), TypeSystem::QUANT_ONE);
    // all untyped Atomics to String
        if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    if  (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
    {
      item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    
    // TYPE PROMOTION
    // numeric promotion
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.FLOAT_TYPE_ONE);
      }
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
      {
        item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
    }
    
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
      if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.FLOAT_TYPE_ONE);
      }
    }
    else if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
    {
      if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      {
        item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
      {
        item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.DOUBLE_TYPE_ONE);
      }
    }
    // uri promotion
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE))
    {
      item1 = GenericCast::instance()->cast(item1, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }
    if (GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.ANY_URI_TYPE_ONE)) 
    {
      item0 = GenericCast::instance()->cast(item0, GENV_TYPESYSTEM.STRING_TYPE_ONE);
    }

    // computation of result
    int8_t compValue = -2;
    switch(aCompType)
    {
      case VALUE_EQUAL:
      case GENERAL_EQUAL:
      case VALUE_NOT_EQUAL:
      case GENERAL_NOT_EQUAL:
        compValue = CompareIterator::equal(item0, item1);
        break;
      case VALUE_GREATER:
      case GENERAL_GREATER:
      case VALUE_GREATER_EQUAL:
      case GENERAL_GREATER_EQUAL:
      case VALUE_LESS:
      case GENERAL_LESS:
      case VALUE_LESS_EQUAL:
      case GENERAL_LESS_EQUAL:
        compValue = CompareIterator::compare(item0, item1);
      default:
        break;
    }
    
    if (compValue > -2)
      switch(aCompType)
      {
        case VALUE_EQUAL:
        case GENERAL_EQUAL:
          return compValue == 0;
          break;
        case VALUE_NOT_EQUAL:
        case GENERAL_NOT_EQUAL:
          return compValue != 0;
          break;
        case VALUE_GREATER:
        case GENERAL_GREATER:
          return compValue > 0;
          break;
        case VALUE_GREATER_EQUAL:
        case GENERAL_GREATER_EQUAL:
          return compValue >= 0;
          break;
        case VALUE_LESS:
        case GENERAL_LESS:
          return compValue < 0;
          break;
        case VALUE_LESS_EQUAL:
        case GENERAL_LESS_EQUAL:
          return compValue <= 0;
          break;
        default:
          break;
      }
      
    ZorbaErrorAlerts::error_alert (
      error_messages::FOCH0004_Collation_does_not_support_collation_units,
      error_messages::RUNTIME_ERROR,
      0,
      false,
      "Compare of declared collation operator and operators is not possible!"
    );
    return false;
  } /* end CompareIterator::valueComparison (...) */
  
  int8_t
  CompareIterator::equal(const Item_t& item0, const Item_t& item1)
  {
    // tries first normal compare
    int8_t compareRes = CompareIterator::compare(item0, item1);
    if (compareRes == 0)
      return 0;
    else if (compareRes == -1 || compareRes == 1)
      return 1;
      
        TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(item0->getType(), TypeSystem::QUANT_ONE);
        TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(item1->getType(), TypeSystem::QUANT_ONE);
    bool equal;
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.BOOLEAN_TYPE_ONE))
        equal = item0->equals(item1);
    // TODO the rest
    else
      return -2;
    
    if (equal)
      return 0;
    else
      return 1;
  }
  
  int8_t 
  CompareIterator::compare(const Item_t& item0, const Item_t& item1)
  {
        TypeSystem::xqtref_t type0 = GENV_TYPESYSTEM.create_type(item0->getType(), TypeSystem::QUANT_ONE);
        TypeSystem::xqtref_t type1 = GENV_TYPESYSTEM.create_type(item1->getType(), TypeSystem::QUANT_ONE);
    int8_t ret = -2;
    if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
        && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE))
      if ( item0->getFloatValue() < item1->getFloatValue())
        ret = -1;
      else if ( item0->getFloatValue() == item1->getFloatValue())
        ret = 0;
      else
        ret = 1;
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
               && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE))
      if ( item0->getDoubleValue() < item1->getDoubleValue())
        ret = -1;
      else if ( item0->getDoubleValue() == item1->getDoubleValue())
        ret = 0;
      else
        ret = 1;
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
               && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
      if ( item0->getDecimalValue() < item1->getDecimalValue())
        ret = -1;
      else if ( item0->getDecimalValue() == item1->getDecimalValue())
        ret = 0;
      else
        ret = 1;
      else if (GENV_TYPESYSTEM.is_subtype(*type0, *GENV_TYPESYSTEM.STRING_TYPE_ONE)
               && GENV_TYPESYSTEM.is_subtype(*type1, *GENV_TYPESYSTEM.STRING_TYPE_ONE))
      if ( item0->getStringValue() < item1->getStringValue())
        ret = -1;
      else if ( item0->getStringValue() == item1->getStringValue())
        ret = 0;
      else
        ret = 1;
    // TODO comparisons for all types

    return ret;
  }
  /* end class ComparisonIterator */

}
