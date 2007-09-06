/**
 *
 * @copyright
 * ========================================================================
 *	Copyright 2007 FLWOR Foundation
 *
 *	Licensed under the Apache License, Version 2.0 (the "License");
 *	you may not use this file except in compliance with the License.
 *	You may obtain a copy of the License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the License is distributed on an "AS IS" BASIS,
 *	WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *	See the License for the specific language governing permissions and
 *	limitations under the License.
 * ========================================================================
 *
 * @author David Graf (tim.kraska@28msec.com)
 * @file types/casting.cpp
 *
 */

#include "casting.h"
#include "../types/sequence_type.h"
#include "../store/api/item.h"
#include "../store/api/item_factory.h"
#include "../runtime/zorba.h"

namespace xqp
{

	/* begin class GenericCast */
	GenericCast::GenericCast():targetType(xs_anyType){}
	
	void GenericCast::setTarget(TypeCode targetType) {
		this->targetType = targetType;
	}
	
	// TODO do be extended!!
	Item_t GenericCast::cast(Item_t item) {
		Item_t result;
		sequence_type_t itemType = item->getType();
		ItemFactory* itemFactory = zorba::getZorbaForCurrentThread()->getItemFactory();
		if ( sequence_type::derives_from ( this->targetType, itemType ) )
			return item;

		switch ( this->targetType )
		{
			case xs_double:
				double doubleVal;
				if ( itemType == xs_float )
				{
					doubleVal = static_cast<double> ( item->getFloatValue() );
				}
				else if ( sequence_type::derives_from ( itemType, xs_decimal ) )
				{
					double doubleVal = static_cast<double> ( item->getDecimalValue() );
				}
				else
				{
					const char* pStart = item->getStringValue().c_str();
					char* pEnd;
					doubleVal = strtod ( pStart, &pEnd );
					if (pStart == pEnd) {
						ZorbaErrorAlerts::error_alert (
					    error_messages::XPST0080_STATIC_BAD_CAST_EXPR,
					    error_messages::RUNTIME_ERROR,
					    NULL,
					    false,
					    "Cannot convert \"" + item->getStringValue() + "\" to a double!"
						);
					}
				}
				result = itemFactory->createDouble ( doubleVal );
				break;
			case xs_float:
				if ( sequence_type::derives_from ( itemType, xs_decimal ) )
				{
					result = itemFactory->createFloat ( static_cast<float> ( item->getDecimalValue() ) );
				}
				else
				{
					ZorbaErrorAlerts::error_alert (
					    error_messages::XPST0080_STATIC_BAD_CAST_EXPR,
					    error_messages::RUNTIME_ERROR,
					    NULL,
					    false,
					    "Numeric casting of a non numeric type"
					);
				}
				break;
			default:
				ZorbaErrorAlerts::error_alert (
				    error_messages::XPST0080_STATIC_BAD_CAST_EXPR,
				    error_messages::RUNTIME_ERROR,
				    false,
				    "Item cannot be parsed to the declared type!"
				);
				break;
		}
		return result;
	}
	/* end class GenericCast */

} /* namespace xqp */
