/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Authors: Tim Kraska, David Graf
 */

#include "BooleanImpl.h"
#include "../types/casting.h"
#include "../runtime/zorba.h"

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
		Item_t n_h;
		sequence_type_t type;
		string str;

		STACK_INIT();

// 	n_h = this->consumeNext(this->arg0_);
//
// 	if ( n_h == NULL) {
// 		STACK_PUSH (this->zorp->getItemFactory()->createBoolean(false));
// 	} else {
// 		type = n_h->getType();
//
// 		if (int(type & ANY_NODE) > 0) {
// 			STACK_PUSH(this->zorp->getItemFactory()->createBoolean(true));
// 		} else if (int(type & BOOLEAN_TYPE) > 0) {
// 			STACK_PUSH(n_h);
// 		} else if (int(type & NUMERIC_TYPE) > 0) {
// 			// TODO FIXME this is wrong!!! E.g. an Integer does not support getDecimalValue
// 			if (n_h->getDecimalValue() == 0) {
// 				STACK_PUSH(this->zorp->getItemFactory()->createBoolean(false));
// 			} else {
// 				STACK_PUSH(this->zorp->getItemFactory()->createBoolean(true));
// 			}
// 		} else if (int(type & STRING_TYPE) > 0) {
// 			if (n_h->getStringValue().size() == 0) {
// 				STACK_PUSH(this->zorp->getItemFactory()->createBoolean(false));
// 			} else {
// 				STACK_PUSH(this->zorp->getItemFactory()->createBoolean(true));
// 			}
// 		} else if (int(type & ANY_URI_TYPE) > 0 || int(type & UNTYPED_ATOMIC_TYPE) > 0) {
// 			ZorbaErrorAlerts::error_alert(
// 				error_messages::XQP0004_SYSTEM_NOT_SUPPORTED,
// 				error_messages::SYSTEM_ERROR,
// 				NULL
// 			);
// 		} else {
// 			ZorbaErrorAlerts::error_alert(
// 				error_messages::FORG0006_INVALID_ARGUMENT_TYPE,
// 				error_messages::RUNTIME_ERROR,
// 				NULL
// 			);
// 		}
// 	}

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
	
	// TODO non-atomic compare
	Item_t CompareIterator::nextImpl()
	{
		Item_t item0;
		Item_t item1;
		TypeCode type0;
		TypeCode type1;
		TypeCode resultType;
		
		int compareResult;
		
		STACK_INIT();
		item0 = this->consumeNext(this->iter0);
		if (item0 != NULL)
		{
			item1 = this->consumeNext(this->iter1);
			if (item1 != NULL) 
			{
				compareResult = CompareIterator::atomicCompare(item0, item1);
				// TODO finishing the work!!
				switch(this->compareType) {
				case (VALUE_EQUAL):
				case (GENERAL_EQUAL):
					if (compareResult == 0){
						STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(true));
					} else {
						STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean(false));
					}
					break;
				default:
					break;
				}
				
			}
		}
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
	
	//TODO extend with non impelemented Datatypes!!
	int CompareIterator::atomicCompare(Item_t item0, Item_t item1)
	{
		int i = 0;
		TypeCode type0 = item0->getType();
		TypeCode type1 = item1->getType();
		
		type0 = sequence_type::getTypeSubstituted(type0);
		type1 = sequence_type::getTypeSubstituted(type1);
		
		if (sequence_type::comparable(type0, type1)) {
			if (type0 == type1) {
				switch(type0) {
				case xs_string:
				case xs_untypedAtomicValue:
				case xs_anyURI:
					return item0->getStringValue().compare(item1->getStringValue());
					break;
				case xs_qname:
				// only used for equality => -1 == not equal, 0 == equal
					if (item0->equals(item1))
						return 0;
					else
						return 1;
					break;
				case xs_boolean:
					if (item0->getBooleanValue() == item1->getBooleanValue())
						return 0;
					else
						return -1;
					break;	
				default:
					if (sequence_type::isNumeric(type0)) {
						i = -2;
						switch(type0) {
						case xs_float:
							switch(type1) {
								case xs_float:
									if (item0->getFloatValue() < item1->getFloatValue())
										i = -1;
									else if (item0->getFloatValue() == item1->getFloatValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_double:
									if (item0->getFloatValue() < item1->getDoubleValue())
										i = -1;
									else if (item0->getFloatValue() == item1->getDoubleValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_decimal:
									if (item0->getFloatValue() < item1->getDecimalValue())
										i = -1;
									else if (item0->getFloatValue() == item1->getDecimalValue())
										i = 0;
									else
										i = 1;
									break;
								default:
									break;
							} /* end switch */
						case xs_double:
							switch(type1) {
								case xs_float:
									if (item0->getDoubleValue() < item1->getFloatValue())
										i = -1;
									else if (item0->getDoubleValue() == item1->getFloatValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_double:
									if (item0->getDoubleValue() < item1->getDoubleValue())
										i = -1;
									else if (item0->getDoubleValue() == item1->getDoubleValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_decimal:
									if (item0->getDoubleValue() < item1->getDecimalValue())
										i = -1;
									else if (item0->getDoubleValue() == item1->getDecimalValue())
										i = 0;
									else
										i = 1;
									break;
								default:
									break;
							} /*end switch */
						case xs_decimal:
							switch(type1) {
								case xs_float:
									if (item0->getDecimalValue() < item1->getFloatValue())
										i = -1;
									else if (item0->getDecimalValue() == item1->getFloatValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_double:
									if (item0->getDecimalValue() < item1->getDoubleValue())
										i = -1;
									else if (item0->getDecimalValue() == item1->getDoubleValue())
										i = 0;
									else
										i = 1;
									break;
								case xs_decimal:
									if (item0->getDecimalValue() < item1->getDecimalValue())
										i = -1;
									else if (item0->getDecimalValue() == item1->getDecimalValue())
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
					if (i > -2) {
						return i;
					}
					} /* end if */
				}
			}
		}
		
	}
	
	void CompareIterator::constructor() {
		this->genericCast = new GenericCast();
	}
	
	void CompareIterator::deconstructor() {
		delete this->genericCast;
	}
	/* end class ComparisonIterator */

}
