#include <fstream>

#include <zorba/item.h>

#include "store/api/store.h"
#include "system/zorba.h"
#include "system/zorba_engine.h"
#include "dynamic_context_wrapper.h"
#include "store/api/item_factory.h"
#include "system/globalenv.h"
#include "runtime/core/item_iterator.h"
#include "errors/error_factory.h"

namespace zorba{

bool DynamicContextWrapper::setContextItemAsBigInteger( xqp_integer int_value, VAR_BIGINT_TYPE type)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();

	
	switch(type)
	{
	case XS_INTEGER://derived from XS_DECIMAL
			context_item = item_factory->createInteger(int_value);
			break;
	case XS_NON_POSITIVE_INTEGER://derived from XS_INTEGER
			if(int_value > Integer::parseInt(0))
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			context_item = item_factory->createNonPositiveInteger(int_value);
			break;
	case XS_NEGATIVE_INTEGER://derived from XS_NON_POSITIVE_INTEGER
			if(int_value >= Integer::parseInt(0))
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			context_item = item_factory->createNegativeInteger(int_value);
		break;
	}
	
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;
}

bool DynamicContextWrapper::setContextItemAsBigUInteger( xqp_uinteger uint_value, VAR_BIGUINT_TYPE type)
{
	try{
	
	ItemFactory* item_factory = Zorba::getItemFactory();

	
	switch(type)
	{
	case XS_NON_NEGATIVE_INTEGER://derived from XS_INTEGER
			if(uint_value < Integer::parseInt(0))
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			context_item = item_factory->createNonNegativeInteger(uint_value);
		break;
	case XS_POSITIVE_INTEGER://derived from XS_NON_NEGATIVE_INTEGER
			if(uint_value < Integer::parseInt(0))
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			context_item = item_factory->createPositiveInteger(uint_value);
		break;
	}
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;
}

bool DynamicContextWrapper::setContextItemAsDecimal( Decimal decimal_value)
{
	try{
	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDecimal(decimal_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsLong( xqp_long long_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createLong(long_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsULong( xqp_ulong ulong_value)
{
	try{
	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createUnsignedLong(ulong_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsInt( xqp_int int_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createInt(int_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsUInt( xqp_uint uint_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createUnsignedInt(uint_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsShort( xqp_short short_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createShort(short_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsUShort( xqp_ushort ushort_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createUnsignedShort(ushort_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsByte( xqp_byte byte_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createByte(byte_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsUByte( xqp_ubyte ubyte_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createUnsignedByte(ubyte_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsString( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createString(str_value.getStore());

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsNormalizedString( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createNormalizedString(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsToken( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createToken(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsLanguage( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createLanguage(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsNMToken( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createNMTOKEN(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsName( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createName(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsNCName( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createNCName(str_value.getStore());

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsID( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createID(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsIDREF( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createIDREF(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsEntity( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createENTITY(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsNotation( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createNOTATION(str_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsAnyURI( xqp_string str_value)
{
	try{
	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createAnyURI(str_value.getStore());

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsQName( xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createQName(namespace_value.getStore(),
                                           prefix_value.getStore(),
                                           local_value.getStore());

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsUntypedAtomic( xqp_string str_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createUntypedAtomic(str_value.getStore());

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsDouble( xqp_double double_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDouble(double_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsFloat( xqp_float float_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createFloat(float_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsBool( xqp_boolean bool_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createBoolean(bool_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsDateTime( struct ::tm datetime_value, long timezone_seconds)
{
	try{

	if((datetime_value.tm_sec < 0) || (datetime_value.tm_sec > 59) ||
		(datetime_value.tm_min < 0) || (datetime_value.tm_min > 59) ||
		(datetime_value.tm_hour < 0) || (datetime_value.tm_hour > 23) ||
		(datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31) ||
		(datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11) ||
		(datetime_value.tm_year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	if((timezone_seconds < -12*60*60) || (timezone_seconds > 13*60*60))
	{//Invalid timezone value.
		ZORBA_ERROR_ALERT(ZorbaError::FODT0003);
	}
	

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	
	context_item = item_factory->createDateTime(
					datetime_value.tm_year+1900, datetime_value.tm_mon, datetime_value.tm_mday,
					datetime_value.tm_hour + datetime_value.tm_isdst ? 1 : 0, datetime_value.tm_min, datetime_value.tm_sec,
					(short)timezone_seconds/60/60);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDateTime( xqp_dateTime datetime_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDateTime(datetime_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDateTime( short year , short month, short day, short hour, short minute, short second, short timeZone )
{
	try{

	if((second < 0) || (second > 59) ||
		(minute < 0) || (minute > 59) ||
		(hour < 0) || (hour > 23) ||
		(day < 1) || (day > 31) ||
		(month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	if((timeZone < -12) || (timeZone > 13))
	{//Invalid timezone value.
		ZORBA_ERROR_ALERT(ZorbaError::FODT0003);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDateTime(
					year, month, day,	hour, minute, second,	timeZone);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDuration( xqp_duration duration_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDuration(duration_value);
	
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDuration( short years, short months, short days, short hours, short minutes, short seconds)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDuration(years, months, days, hours, minutes, seconds);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDate( xqp_date date_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createDate(date_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsDate( short year , short month, short day)
{
	try{

	if((day < 1) || (day > 31) ||
		(month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	context_item = item_factory->createDate(year, month, day);

	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsTime( xqp_time time_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createTime(time_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsTime( short hour, short minute, short second, short timeZone )
{
	try{

	if((second < 0) || (second > 59) ||
		(minute < 0) || (minute > 59) ||
		(hour < 0) || (hour > 23))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createTime(hour, minute, second, timeZone);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGYearMonth( xqp_gYearMonth gyearmonth_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGYearMonth(gyearmonth_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGYearMonth( short year , short month)
{
	try{

	if((month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGYearMonth(year, month);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGYear( xqp_gYear gyear_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGYear(gyear_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGYear( short year)
{
	try{

	if((year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGYear(year);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGMonthDay( xqp_gMonthDay gmonthday_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGMonthDay(gmonthday_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGMonthDay( short month , short day)
{
	try{

	if((day < 1) || (day > 31) ||
		(month < 0) || (month > 11))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGMonthDay(month, day);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGDay( xqp_gDay gday_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGDay(gday_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGDay( short day)
{
	try{

	if((day < 1) || (day > 31))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGDay(day);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGMonth( xqp_gMonth gmonth_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createGMonth(gmonth_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsGMonth( short month)
{
	try{

	if((month < 0) || (month > 11))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	context_item = item_factory->createGMonth(month);

	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsItem( Item_t item)
{
	try{
	
	context_item = item;

	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsDocument( xqp_anyURI documentURI)
{
	try{
	
	Store		&store = GENV.getStore();
	context_item = store.getDocument(documentURI.getStore());
	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::FODC0002);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setContextItemAsDocumentFromFile(
		xqp_string		file_path,
    xqp_string    storeUri)
{
	try
  {
		std::ifstream			is(file_path.c_str ());
		if(!is.is_open())
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, file_path);
			return false;
		}
		Store		&store = GENV.getStore();

		if(storeUri == "")
			storeUri = file_path;

		//?store.deleteDocument(docUri);
		context_item = store.loadDocument(storeUri.getStore(), is);
		if(context_item == NULL)
		{//cannot upload document into store
			//or maybe is not valid xml
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, file_path);
			return false;
		}

   return true;
	}
	CATCH_ALL_RETURN_false;
}


bool DynamicContextWrapper::setContextItemAsHexBinary( xqp_hexBinary hex_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createHexBinary(hex_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setContextItemAsBase64Binary( xqp_base64Binary base64_value)
{
	try{

	ItemFactory* item_factory = Zorba::getItemFactory();
	
	context_item = item_factory->createBase64Binary(base64_value);

	if(context_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	
	return true;

	}CATCH_ALL_RETURN_false;

}

}//end namespace zorba
