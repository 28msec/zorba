/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

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
	|	15.1.1 fn:boolean
	|	fn:boolean($arg as item()*) as xs:boolean
	|
	|	Computes the effective boolean value of the sequence $arg.
	|_______________________________________________________________________*/
	FnBooleanIterator::FnBooleanIterator ( const yy::location& loc, PlanIter_t& arg0, bool negate_arg )
	:
		Batcher<FnBooleanIterator> ( loc ), arg0_ ( arg0 ), negate ( negate_arg ) {}
		
	FnBooleanIterator::~FnBooleanIterator() {}
			
	std::ostream&
	FnBooleanIterator::_show ( std::ostream& os ) const
	{
		this->arg0_->show ( os );
		return os;
	}

	Item_t
	FnBooleanIterator::effectiveBooleanValue ( const yy::location& loc, PlanState& planState, PlanIter_t& iter, bool negate )
	{
		Item_t item;
		TypeCode type;
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
			type = item->getType();
			if (
					// TODO produceNext must be replaced to allow batching
			    ( iter->produceNext(planState) == NULL )
			    &&
			    ( type == xs_boolean
			      || sequence_type::derives_from ( type, xs_string )
			      || sequence_type::derives_from ( type, xs_anyURI )
			      || sequence_type::derives_from ( type, xs_untypedAtomicValue )
			      || sequence_type::isNumeric ( type )
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
		STACK_INIT();
		STACK_PUSH ( FnBooleanIterator::effectiveBooleanValue ( this->loc, planState, this->arg0_, this->negate ) );
		STACK_END();
	}

	void
	FnBooleanIterator::resetImpl(PlanState& planState)
	{
		this->resetChild ( this->arg0_, planState );
	}

	void
	FnBooleanIterator::releaseResourcesImpl(PlanState& planState)
	{
		this->releaseChildResources ( this->arg0_, planState);
	}
	/* end class FnBooleanIterator */
	
	/* begin class LogicIterator */
	LogicIterator::LogicIterator ( const yy::location& loc, PlanIter_t arg0, PlanIter_t arg1, LogicType lt)
	:
		Batcher<LogicIterator> ( loc), iterLeft(arg0), iterRight(arg1), logicType(lt) {}
	LogicIterator::~LogicIterator(){}
			
	Item_t 
	LogicIterator::nextImpl(PlanState& planState)
	{
		bool bRes;
		
		STACK_INIT();
		switch(this->logicType)
		{
		case AND:
			bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, this->iterLeft)->getBooleanValue() 
							&& FnBooleanIterator::effectiveBooleanValue(this->loc, planState, this->iterRight)->getBooleanValue();
			break;
		case OR:
			bRes = FnBooleanIterator::effectiveBooleanValue(this->loc, planState, this->iterLeft)->getBooleanValue() 
							|| FnBooleanIterator::effectiveBooleanValue(this->loc, planState, this->iterRight)->getBooleanValue();;
			break;
		}
		STACK_PUSH(zorba::getItemFactory()->createBoolean(bRes));
		STACK_END();
	}
	
	void 
	LogicIterator::resetImpl(PlanState& planState)
	{
		this->resetChild( this->iterLeft, planState );
		this->resetChild( this->iterRight, planState );
	}
	
	void 
	LogicIterator::releaseResourcesImpl(PlanState& planState)
	{
		this->releaseChildResources( this->iterLeft, planState );
		this->releaseChildResources( this->iterRight, planState );
	}
	/* end class LogicIterator */

	/* begin class ComparisonIterator */
	CompareIterator::CompareIterator ( const yy::location& loc, PlanIter_t arg0, PlanIter_t arg1, CompareType argCompType )
	:
		Batcher<CompareIterator> ( loc ), compareType(argCompType) 
	{
		this->genericCast = new GenericCast();
		this->iter0 = new FnDataIterator ( loc, arg0 );
		this->iter1 = new FnDataIterator ( loc, arg1 );
	}
	
	CompareIterator::~CompareIterator()
	{
		delete this->genericCast;
	}
	
	Item_t
	CompareIterator::nextImpl(PlanState& planState)
	{
		Item_t item0;
		Item_t item1;
		Iterator_t lIter0;
		Iterator_t lIter1;
		TypeCode type0;
		TypeCode type1;
		TypeCode resultType;
		TempSeq_t temp0;
		TempSeq_t temp1;
		int32_t i0;
		int32_t i1;
		bool found;
		bool empty;
		int32_t compareResult;

		STACK_INIT();

		if (this->isGeneralComparison())
		{
			// TODO Optimizations for >, >=, < and <=
			lIter0 = new PlanIterWrapper(this->iter0, planState);
			lIter1 = new PlanIterWrapper(this->iter1, planState);
			temp0 = zorba::getStore()->createTempSeq(lIter0);
			temp1 = zorba::getStore()->createTempSeq(lIter1);
			i0 = 1;
			found = false;
			while (!found && temp0->containsItem(i0))
			{
				i1 = 1;
				while (!found && temp1->containsItem(i1))
				{
					if (CompareIterator::generalComparison(temp0->getItem( i0 ), temp1->getItem( i1 )))
						found = true;
					i1++;
				}
				i0++;
			}

			STACK_PUSH( zorba::getItemFactory()->createBoolean( found ) );
		} /* if general comparison */
		else if (this->isValueComparison())
		{
			if (( (item0 = this->consumeNext(this->iter0, planState)) != NULL ) 
						&& ((item1 = this->consumeNext(this->iter1, planState))!=NULL))
			{
				STACK_PUSH( zorba::getItemFactory()->createBoolean( CompareIterator::valueComparison(item0, item1) ) );
				if (this->consumeNext(this->iter0, planState) != NULL || this->consumeNext(this->iter1, planState) != NULL)
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
		else if (this->isNodeComparison())
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

	void
	CompareIterator::resetImpl(PlanState& planState)
	{
		this->resetChild ( this->iter0, planState );
		this->resetChild ( this->iter1, planState );
	}

	void
	CompareIterator::releaseResourcesImpl(PlanState& planState)
	{
		this->releaseChildResources ( this->iter0, planState );
		this->releaseChildResources ( this->iter1, planState );
	}
	
	bool 
	CompareIterator::isValueComparison()
	{
		bool retVal = false;
		switch(this->compareType)
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
		switch(this->compareType)
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
		switch(this->compareType)
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
	CompareIterator::generalComparison(Item_t item0, Item_t item1)
	{
		
		if (sequence_type::derives_from(item0->getType(), xs_untypedAtomicValue))
		{
			if (sequence_type::isNumeric(item1->getType()))
			{
				this->genericCast->setTarget(xs_double);
				item0 = this->genericCast->cast(item0);
			}
			else if (sequence_type::derives_from(item1->getType(), xs_untypedAtomicValue)
								|| sequence_type::derives_from(item1->getType(), xs_string))
			{
				this->genericCast->setTarget(xs_string);
				item0 = this->genericCast->cast(item0);
			}
			else
			{
				this->genericCast->setTarget(item1->getType());
				item0 = this->genericCast->cast(item0);
			}
		}
		
		if (sequence_type::derives_from(item1->getType(), xs_untypedAtomicValue))
		{
			if (sequence_type::isNumeric(item0->getType()))
			{
				this->genericCast->setTarget(xs_double);
				item1 = this->genericCast->cast(item1);
			}
			else if (sequence_type::derives_from(item0->getType(), xs_untypedAtomicValue)
								|| sequence_type::derives_from(item0->getType(), xs_string))
			{
				this->genericCast->setTarget(xs_string);
				item1 = this->genericCast->cast(item1);
			}
			else
			{
				this->genericCast->setTarget(item0->getType());
				item1 = this->genericCast->cast(item1);
			}
		}
		
		return CompareIterator::valueComparison(item0, item1);
	} /* end CompareIterator::generalComparison (...) */

	bool
	CompareIterator::valueComparison(Item_t item0, Item_t item1)
	{
		// all untyped Atomics to String
		if (sequence_type::derives_from(item0->getType(), xs_untypedAtomicValue))
		{
			this->genericCast->setTarget(xs_string);
			item0 = this->genericCast->cast(item0);
		}
		if  (sequence_type::derives_from(item1->getType(), xs_untypedAtomicValue))
		{
			this->genericCast->setTarget(xs_string);
			item1 = this->genericCast->cast(item1);
		}
		
		// TYPE PROMOTION
		// numeric promotion
		if (sequence_type::derives_from(item0->getType(), xs_float)) {
			if (sequence_type::derives_from(item1->getType(), xs_decimal))
			{
				this->genericCast->setTarget(xs_float);
				item1 = this->genericCast->cast(item1);
			}
		}
		else if (sequence_type::derives_from(item0->getType(), xs_double))
		{
			if (sequence_type::derives_from(item1->getType(), xs_decimal))
			{
				this->genericCast->setTarget(xs_double);
				item1 = this->genericCast->cast(item1);
			}
			else if (sequence_type::derives_from(item0->getType(), xs_float))
			{
				this->genericCast->setTarget(xs_double);
				item1 = this->genericCast->cast(item1);
			}
		}
		
		if (sequence_type::derives_from(item1->getType(), xs_float)) {
			if (sequence_type::derives_from(item0->getType(), xs_decimal))
			{
				this->genericCast->setTarget(xs_float);
				item0 = this->genericCast->cast(item0);
			}
		}
		else if (sequence_type::derives_from(item1->getType(), xs_double))
		{
			if (sequence_type::derives_from(item0->getType(), xs_decimal))
			{
				this->genericCast->setTarget(xs_double);
				item0 = this->genericCast->cast(item0);
			}
			else if (sequence_type::derives_from(item0->getType(), xs_float))
			{
				this->genericCast->setTarget(xs_double);
				item0 = this->genericCast->cast(item0);
			}
		}
		// uri promotion
		if (sequence_type::derives_from(item0->getType(), xs_string)
				&& sequence_type::derives_from(item1->getType(), xs_anyURI)) 
		{
			this->genericCast->setTarget(xs_string);
			item1 = this->genericCast->cast(item1);
		}
		if (sequence_type::derives_from(item1->getType(), xs_string)
				&& sequence_type::derives_from(item0->getType(), xs_anyURI)) 
		{
			this->genericCast->setTarget(xs_string);
			item0 = this->genericCast->cast(item0);
		}

		// computation of result
		int32_t compValue = -2;
		switch(this->compareType)
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
			switch(this->compareType)
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
			&loc,
			false,
			"Compare of declared collation operator and operators is not possible!"
		);
		return false;
	} /* end CompareIterator::valueComparison (...) */
	
	int32_t
	CompareIterator::equal(const Item_t& item0, const Item_t& item1)
	{
		// tries first normal compare
		int32_t compareRes = CompareIterator::compare(item0, item1);
		if (compareRes == 0)
			return 0;
		else if (compareRes == -1 || compareRes == 1)
			return 1;
			
		TypeCode type0 = item0->getType();
		TypeCode type1 = item1->getType();
		bool equal;
		if (sequence_type::derives_from(type0, xs_boolean) && sequence_type::derives_from(type1, xs_boolean))
				equal = item0->equals(item1);
		// TODO the rest
		else
			return -2;
		
		if (equal)
			return 0;
		else
			return 1;
	}
	
	int32_t 
	CompareIterator::compare(const Item_t& item0, const Item_t& item1)
	{
		TypeCode type0 = item0->getType();
		TypeCode type1 = item1->getType();
		int32_t ret = -2;
		if (sequence_type::derives_from(type0, xs_float) && sequence_type::derives_from(type1, xs_float))
			if ( item0->getFloatValue() < item1->getFloatValue())
				ret = -1;
			else if ( item0->getFloatValue() == item1->getFloatValue())
				ret = 0;
			else
				ret = 1;
		else if (sequence_type::derives_from(type0, xs_double) && sequence_type::derives_from(type1, xs_double))
			if ( item0->getDoubleValue() < item1->getDoubleValue())
				ret = -1;
			else if ( item0->getDoubleValue() == item1->getDoubleValue())
				ret = 0;
			else
				ret = 1;
		else if (sequence_type::derives_from(type0, xs_decimal) && sequence_type::derives_from(type1, xs_decimal))
			if ( item0->getDecimalValue() < item1->getDecimalValue())
				ret = -1;
			else if ( item0->getDecimalValue() == item1->getDecimalValue())
				ret = 0;
			else
				ret = 1;
		else if (sequence_type::derives_from(type0, xs_string) && sequence_type::derives_from(type1, xs_string))
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
