/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "BooleanImpl.h"
#include "../types/casting.h"
#include "../runtime/zorba.h"
#include "../errors/Error.h"

namespace xqp
{

	/*______________________________________________________________________
	|
	|	15.1.1 fn:boolean
	|	fn:boolean($arg as item()*) as xs:boolean
	|
	|	Computes the effective boolean value of the sequence $arg.
	|_______________________________________________________________________*/
	std::ostream& FnBooleanIterator::_show ( std::ostream& os )
	const
	{
		this->arg0_->show ( os );
		return os;
	}

	Item_t FnBooleanIterator::nextImpl()
	{
		Item_t item;
		sequence_type_t type;
		string str;

		STACK_INIT();

		item = this->consumeNext ( this->arg0_ );

		if ( item == NULL )
		{
			STACK_PUSH ( this->zorp->getItemFactory()->createBoolean ( false ) );
		}
		else
		{
			STACK_PUSH(item->getEBV());
		}

		STACK_PUSH ( NULL );
		STACK_END();
	}

	void FnBooleanIterator::resetImpl()
	{
		this->resetChild ( this->arg0_ );
	}

	void FnBooleanIterator::releaseResourcesImpl()
	{
		this->releaseChildResources ( this->arg0_ );
	}

	/* begin class ComparisonIterator */
	Item_t CompareIterator::nextImpl()
	{
		Item_t item0;
		Item_t item1;
		TypeCode type0;
		TypeCode type1;
		TypeCode resultType;

		int compareResult;

		STACK_INIT();

		if ( this->compareType == NODE_EQUAL || this->compareType == NODE_NOT_EQUAL )
		{
			ZorbaErrorAlerts::error_alert (
			    error_messages::FOAR0001_Division_by_zero,
			    error_messages::RUNTIME_ERROR,
			    &loc,
			    false,
			    "Node comparison is not yet implemented!"
			);
		} /* end if */

		item0 = this->consumeNext ( this->iter0 );
		if ( item0 != NULL )
		{
			item1 = this->consumeNext ( this->iter1 );
			if ( item1 != NULL )
			{
				if ( item0->isAtomic() && item1->isAtomic() )
				{
					compareResult = CompareIterator::atomicCompare ( item0, item1 );
					switch ( this->compareType )
					{
						case ( VALUE_EQUAL ) :
									case ( GENERAL_EQUAL ) :
											if ( compareResult == 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						case ( VALUE_NOT_EQUAL ) :
									case ( GENERAL_NOT_EQUAL ) :
											if ( compareResult != 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						case ( VALUE_GREATER ) :
									case ( GENERAL_GREATER ) :
											if ( compareResult > 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						case ( VALUE_GREATER_EQUAL ) :
									case ( GENERAL_GREATER_EQUAL ) :
											if ( compareResult >= 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						case ( VALUE_LESS ) :
									case ( GENERAL_LESS ) :
											if ( compareResult < 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						case ( VALUE_LESS_EQUAL ) :
									case ( GENERAL_LESS_EQUAL ) :
											if ( compareResult <= 0 )
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true ) );
									}
									else
									{
										STACK_PUSH ( zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( false ) );
									}
							break;
						default:
							break;
					} /* end switch */
				}
				else
				{
					ZorbaErrorAlerts::error_alert (
					    error_messages::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
					    error_messages::SYSTEM_ERROR,
					    &loc,
					    false,
					    "Comparison for non-atomic items is not yet implemented!"
					);
				} /* end if */
				if ( ( this->consumeNext ( this->iter0 ) != NULL ) || ( this->consumeNext ( this->iter1 ) != NULL ) )
				{
					ZorbaErrorAlerts::error_alert (
					    error_messages::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
					    error_messages::SYSTEM_ERROR,
					    &loc,
					    false,
					    "Comparison for sequences is not yet implemented!"
					);
				}
			} /* end if */
		} /* end if */
		STACK_PUSH ( NULL );
		STACK_END();
	}

	void CompareIterator::resetImpl()
	{
		this->resetChild ( this->iter0 );
		this->resetChild ( this->iter1 );
	}

	void CompareIterator::releaseResourcesImpl()
	{
		this->releaseChildResources ( this->iter0 );
		this->releaseChildResources ( this->iter1 );
	}

	int CompareIterator::atomicCompare ( Item_t item0, Item_t item1 )
	{
		int i = 0;
		TypeCode type0 = item0->getType();
		TypeCode type1 = item1->getType();

		type0 = sequence_type::getTypeSubstituted ( type0 );
		type1 = sequence_type::getTypeSubstituted ( type1 );

		if ( sequence_type::comparable ( type0, type1 ) )
		{
			if ( type0 == type1 || ( sequence_type::isNumeric ( type0 ) && sequence_type::isNumeric ( type1 ) ) )
			{
				switch ( type0 )
				{
					case xs_string:
					case xs_untypedAtomicValue:
					case xs_anyType:
					case xs_anyURI:
						return item0->getStringValue().compare ( item1->getStringValue() );
						break;
					case xs_qname:
						// only used for equality => -1 == not equal, 0 == equal
						if ( item0->equals ( item1 ) )
							return 0;
						else
							return 1;
						break;
					case xs_boolean:
						if ( item0->getBooleanValue() == item1->getBooleanValue() )
							return 0;
						else
							return -1;
						break;
						// TODO following compare implementations:
					case xs_dateTime:
					case xs_date:
					case xs_time:
					case xs_dayTimeDuration:
					case xs_yearMonthDuration:
					case xs_duration:
					case xs_gDay:
					case xs_gMonth:
					case xs_gYear:
					case xs_gMonthDay:
					case xs_gYearMonth:
					case xs_hexBinary:
					case xs_base64Binary:
					default:
						if ( sequence_type::isNumeric ( type0 ) )
						{
							switch ( type0 )
							{
								case xs_float:
									switch ( type1 )
									{
										case xs_float:
											if ( item0->getFloatValue() < item1->getFloatValue() )
												i = -1;
											else if ( item0->getFloatValue() == item1->getFloatValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_double:
											if ( item0->getFloatValue() < item1->getDoubleValue() )
												i = -1;
											else if ( item0->getFloatValue() == item1->getDoubleValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_decimal:
											if ( item0->getFloatValue() < item1->getDecimalValue() )
												i = -1;
											else if ( item0->getFloatValue() == item1->getDecimalValue() )
												i = 0;
											else
												i = 1;
											break;
										default:
											break;
									} /* end switch */
								case xs_double:
									switch ( type1 )
									{
										case xs_float:
											if ( item0->getDoubleValue() < item1->getFloatValue() )
												i = -1;
											else if ( item0->getDoubleValue() == item1->getFloatValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_double:
											if ( item0->getDoubleValue() < item1->getDoubleValue() )
												i = -1;
											else if ( item0->getDoubleValue() == item1->getDoubleValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_decimal:
											if ( item0->getDoubleValue() < item1->getDecimalValue() )
												i = -1;
											else if ( item0->getDoubleValue() == item1->getDecimalValue() )
												i = 0;
											else
												i = 1;
											break;
										default:
											break;
									} /*end switch */
								case xs_decimal:
									switch ( type1 )
									{
										case xs_float:
											if ( item0->getDecimalValue() < item1->getFloatValue() )
												i = -1;
											else if ( item0->getDecimalValue() == item1->getFloatValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_double:
											if ( item0->getDecimalValue() < item1->getDoubleValue() )
												i = -1;
											else if ( item0->getDecimalValue() == item1->getDoubleValue() )
												i = 0;
											else
												i = 1;
											break;
										case xs_decimal:
											if ( item0->getDecimalValue() < item1->getDecimalValue() )
												i = -1;
											else if ( item0->getDecimalValue() == item1->getDecimalValue() )
												i = 0;
											else
												i = 1;
											break;
										default:
											break;
									} /* end switch */
								default:
									break;
							} /* end switch */
							return i;
						} /* end if */
				}
			}
			else
			{
				ZorbaErrorAlerts::error_alert (
				    error_messages::XQP0015_SYSTEM_NOT_YET_IMPLEMENTED,
				    error_messages::SYSTEM_ERROR,
				    NULL,
				    false,
				    "Comparison of two different types not yet implemented!"
				);
			}
		}
		ZorbaErrorAlerts::error_alert (
		    error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
		    error_messages::SYSTEM_ERROR,
		    NULL,
		    false,
		    "Not possible to compare the two passed values!"
		);
		return -2;
	}

	void CompareIterator::constructor()
	{
		this->genericCast = new GenericCast();
	}

	void CompareIterator::deconstructor()
	{
		delete this->genericCast;
	}
	/* end class ComparisonIterator */

}
