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
 * @author Vinayak R. Borkar (vborky@yahoo.com)
 * @file types/casting.cpp
 *
 */

#include "casting.h"
#include "system/globalenv.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "util/zorba.h"

using namespace xqp;

/* begin class GenericCast */
GenericCast::GenericCast()
    :targetType(GENV_TYPESYSTEM.create_item_type(TypeSystem::QUANT_STAR))
{
}

void GenericCast::setTarget(TypeSystem::xqtref_t& targetType) {
	this->targetType = targetType;
}

// TODO do be extended!!
Item_t GenericCast::cast(Item_t item) {
	Item_t result;
    TypeSystem::xqtref_t itemType = GENV_TYPESYSTEM.create_type(item->getType(), TypeSystem::QUANT_ONE);
	ItemFactory* itemFactory = zorba::getItemFactory();

    if (GENV_TYPESYSTEM.is_subtype(*itemType, *targetType)) {
        return item;
    }

    if (!GENV_TYPESYSTEM.is_atomic(*targetType)) {
        ZorbaErrorAlerts::error_alert (
                error_messages::FORG0001_Invalid_value_for_cast_constructor,
                error_messages::STATIC_ERROR,
                false,
                "Item cannot be casted to the declared type!"
                );
    }
	
	switch ( GENV_TYPESYSTEM.get_atomic_type_code(*targetType) )
	{
		case TypeSystem::XS_DOUBLE:
			double doubleVal;
			if ( GENV_TYPESYSTEM.is_subtype( *GENV_TYPESYSTEM.FLOAT_TYPE_ONE, *itemType) )
			{
				doubleVal = static_cast<double> ( item->getFloatValue() );
			}
			else if ( GENV_TYPESYSTEM.is_subtype( *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE, *itemType ) )
			{
				doubleVal = static_cast<double> ( item->getDecimalValue() );
			}
			else
			{
				const char* pStart = item->getStringValue().c_str();
				char* pEnd;
				doubleVal = strtod ( pStart, &pEnd );
				if (*pEnd != '\0') {
					ZorbaErrorAlerts::error_alert (
				    error_messages::FORG0001_Invalid_value_for_cast_constructor,
				    error_messages::STATIC_ERROR,
				    NULL,
				    false,
				    "Cannot convert \"" + item->getStringValue() + "\" to a double!"
					);
				}
			}
			result = itemFactory->createDouble ( doubleVal );
			break;
		case TypeSystem::XS_FLOAT:
			if ( GENV_TYPESYSTEM.is_subtype( *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE, *itemType ) )
			{
				result = itemFactory->createFloat ( static_cast<float> ( item->getDecimalValue() ) );
			}
			else
			{
				ZorbaErrorAlerts::error_alert (
				    error_messages::FORG0001_Invalid_value_for_cast_constructor,
				    error_messages::STATIC_ERROR,
				    NULL,
				    false,
				    "Numeric casting of a non numeric type"
				);
			}
			break;
		case TypeSystem::XS_STRING:
			result = itemFactory->createString( item->getStringProperty() );
			break;
		default:
			ZorbaErrorAlerts::error_alert (
			    error_messages::FORG0001_Invalid_value_for_cast_constructor,
			    error_messages::STATIC_ERROR,
			    false,
			    "Item cannot be casted to the declared type!"
			);
			break;
	}
	return result;
}
/* end class GenericCast */
