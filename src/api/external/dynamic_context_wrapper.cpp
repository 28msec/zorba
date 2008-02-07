
#include "dynamic_context_wrapper.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/zorba.h"
#include "runtime/core/item_iterator.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "runtime/sequences/SequencesImpl.h"
#include <time.h>
#include "types/casting.h"
#include "types/typesystem.h"
#include "system/globalenv.h"
#include <fstream>

namespace xqp {


DynamicContextWrapper::DynamicContextWrapper()
{
	try{

	memset((void*)&current_date_time, 0, sizeof(current_date_time));
	current_timezone_seconds = 0;
	is_datetime_initialized = false;
	implicit_timezone_seconds = 0;

	}CATCH_ALL_NO_RETURN(;);
}

DynamicContextWrapper::~DynamicContextWrapper( )
{
	try{

	deleteAllVariables();

	}	CATCH_ALL_NO_RETURN(;);

}

void		DynamicContextWrapper::setCurrentDateTime( struct ::tm datetime, long timezone_seconds )
{
	try{

	this->current_date_time = datetime;
	this->current_timezone_seconds = timezone_seconds;
	is_datetime_initialized = true;

	}	CATCH_ALL_NO_RETURN(;);

}

struct ::tm	DynamicContextWrapper::getCurrentDateTime( long *ptimezone_seconds )
{
	if(ptimezone_seconds)
		*ptimezone_seconds = this->current_timezone_seconds;
	return current_date_time;
}

//check if var name is well formed
//throw error if not
void	DynamicContextWrapper::checkVarName(xqp_string varname)
{
/*	std::string::size_type n1 = static_cast<std::string> (varname).find (':');
  if(n1 != string::npos)
	{//has prefix
		std::string::size_type n2 = static_cast<std::string>(varname.substr (n1+1)).find(':');
		if(n2 != string::npos)
			goto CheckVarNameError;//has two prefixes !!
	}
	else
	{//has no prefix
	}
*/
	if(GenericCast::instance()->isCastable(varname, GENV_TYPESYSTEM.QNAME_TYPE_ONE))
		return;//all ok

CheckVarNameError:
	ZORBA_ERROR_ALERT(ZorbaError::API0011_INVALID_VARIABLE_QNAME, NULL, DONT_CONTINUE_EXECUTION, varname);
	return ;//false;//no good
}

bool DynamicContextWrapper::setVariableAsBigInteger( xqp_string varname, xqp_integer int_value, VAR_BIGINT_TYPE type)
{
	try{

	checkVarName(varname);

	dctx_extern_var_t		var;
	ItemFactory* item_factory = Zorba::getItemFactory();

	var.varname = varname;
	switch(type)
	{
	case XS_INTEGER://derived from XS_DECIMAL
			var.atomic_item = item_factory->createInteger(int_value);
			break;
	case XS_NON_POSITIVE_INTEGER://derived from XS_INTEGER
			if(int_value > (int32_t)0)
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			var.atomic_item = item_factory->createNonPositiveInteger(int_value);
			break;
	case XS_NEGATIVE_INTEGER://derived from XS_NON_POSITIVE_INTEGER
			if(int_value >= (int32_t)0)
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			var.atomic_item = item_factory->createNegativeInteger(int_value);
		break;
	}
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	deleteVariable(varname);

	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;
}

bool DynamicContextWrapper::setVariableAsBigUInteger( xqp_string varname, xqp_uinteger uint_value, VAR_BIGUINT_TYPE type)
{
	try{

	checkVarName(varname);

	dctx_extern_var_t		var;
	ItemFactory* item_factory = Zorba::getItemFactory();

	var.varname = varname;
	switch(type)
	{
	case XS_NON_NEGATIVE_INTEGER://derived from XS_INTEGER
			if(uint_value < (int32_t)0)
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			var.atomic_item = item_factory->createNonNegativeInteger(uint_value);
		break;
	case XS_POSITIVE_INTEGER://derived from XS_NON_NEGATIVE_INTEGER
			if(uint_value < (int32_t)0)
			{
				ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
				return false;//inappropriate value
			}
			var.atomic_item = item_factory->createPositiveInteger(uint_value);
		break;
	}
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}
	deleteVariable(varname);

	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;
}

bool DynamicContextWrapper::setVariableAsDecimal( xqp_string varname, Decimal decimal_value)
{
	try{

	checkVarName(varname);


	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDecimal(decimal_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsLong( xqp_string varname, xqp_long long_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createLong(long_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsULong( xqp_string varname, xqp_ulong ulong_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createUnsignedLong(ulong_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsInt( xqp_string varname, xqp_int int_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createInt(int_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsUInt( xqp_string varname, xqp_uint uint_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createUnsignedInt(uint_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsShort( xqp_string varname, xqp_short short_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createShort(short_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsUShort( xqp_string varname, xqp_ushort ushort_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createUnsignedShort(ushort_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsByte( xqp_string varname, xqp_byte byte_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createByte(byte_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsUByte( xqp_string varname, xqp_ubyte ubyte_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createUnsignedByte(ubyte_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsString( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createString(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsNormalizedString( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createNormalizedString(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsToken( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createToken(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsLanguage( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createLanguage(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsNMToken( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createNMTOKEN(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsName( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createName(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsNCName( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createNCName(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsID( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createID(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsIDREF( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createIDREF(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsEntity( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createENTITY(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsNotation( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createNOTATION(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsAnyURI( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createAnyURI(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsQName( xqp_string varname, xqp_string namespace_value, xqp_string prefix_value, xqp_string local_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createQName(namespace_value, prefix_value, local_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsUntypedAtomic( xqp_string varname, xqp_string str_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createUntypedAtomic(str_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsDouble( xqp_string varname, xqp_double double_value)
{
	try{

	checkVarName(varname);

//	if(_isnan(double_value))
//	{//NaN supplied as float/double value.
//		ZORBA_ERROR_ALERT(ZorbaError::FOCA0005);
//	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDouble(double_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsFloat( xqp_string varname, xqp_float float_value)
{
	try{

	checkVarName(varname);

//	if(_isnan(float_value))
//	{//NaN supplied as float/double value.
//		ZORBA_ERROR_ALERT(ZorbaError::FOCA0005);
//	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createFloat(float_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsBool( xqp_string varname, xqp_boolean bool_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createBoolean(bool_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsDateTime( xqp_string varname, struct ::tm datetime_value, long timezone_seconds)
{
	try{

	checkVarName(varname);

	if((datetime_value.tm_sec < 0) || (datetime_value.tm_sec > 59) ||
		(datetime_value.tm_min < 0) || (datetime_value.tm_min > 59) ||
		(datetime_value.tm_hour < 0) || (datetime_value.tm_hour > 23) ||
		(datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31) ||
		(datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11) ||
		(datetime_value.tm_year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	if((timezone_seconds < -12*60*60) || (timezone_seconds > 13*60*60))
	{//Invalid timezone value.
		ZORBA_ERROR_ALERT(ZorbaError::FODT0003);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDateTime(
					datetime_value.tm_year+1900, datetime_value.tm_mon, datetime_value.tm_mday,
					datetime_value.tm_hour + datetime_value.tm_isdst ? 1 : 0, datetime_value.tm_min, datetime_value.tm_sec,
					(short)timezone_seconds/60/60);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDateTime( xqp_string varname, xqp_dateTime datetime_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDateTime(datetime_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDateTime( xqp_string varname, short year , short month, short day, short hour, short minute, short second, short timeZone )
{
	try{

	checkVarName(varname);

	if((second < 0) || (second > 59) ||
		(minute < 0) || (minute > 59) ||
		(hour < 0) || (hour > 23) ||
		(day < 1) || (day > 31) ||
		(month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}
	if((timeZone < -12) || (timeZone > 13))
	{//Invalid timezone value.
		ZORBA_ERROR_ALERT(ZorbaError::FODT0003);
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDateTime(
					year, month, day,	hour, minute, second,	timeZone);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDuration( xqp_string varname, xqp_duration duration_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDuration(duration_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDuration( xqp_string varname, short years, short months, short days, short hours, short minutes, short seconds)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDuration(years, months, days, hours, minutes, seconds);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDate( xqp_string varname, xqp_date date_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDate(date_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsDate( xqp_string varname, short year , short month, short day)
{
	try{

	checkVarName(varname);

	if((day < 1) || (day > 31) ||
		(month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createDate(year, month, day);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsTime( xqp_string varname, xqp_time time_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createTime(time_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsTime( xqp_string varname, short hour, short minute, short second, short timeZone )
{
	try{

	checkVarName(varname);

	if((second < 0) || (second > 59) ||
		(minute < 0) || (minute > 59) ||
		(hour < 0) || (hour > 23))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createTime(hour, minute, second, timeZone);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGYearMonth( xqp_string varname, xqp_gYearMonth gyearmonth_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGYearMonth(gyearmonth_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGYearMonth( xqp_string varname, short year , short month)
{
	try{

	checkVarName(varname);

	if((month < 0) || (month > 11) ||
		(year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGYearMonth(year, month);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGYear( xqp_string varname, xqp_gYear gyear_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGYear(gyear_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGYear( xqp_string varname, short year)
{
	try{

	checkVarName(varname);

	if((year < 0))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGYear(year);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGMonthDay( xqp_string varname, xqp_gMonthDay gmonthday_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGMonthDay(gmonthday_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGMonthDay( xqp_string varname, short month , short day)
{
	try{

	checkVarName(varname);

	if((day < 1) || (day > 31) ||
		(month < 0) || (month > 11))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGMonthDay(month, day);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGDay( xqp_string varname, xqp_gDay gday_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGDay(gday_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGDay( xqp_string varname, short day)
{
	try{

	checkVarName(varname);

	if((day < 1) || (day > 31))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGDay(day);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGMonth( xqp_string varname, xqp_gMonth gmonth_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGMonth(gmonth_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsGMonth( xqp_string varname, short month)
{
	try{

	checkVarName(varname);

	if((month < 0) || (month > 11))
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
		return false;
	}

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createGMonth(month);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsItem( xqp_string varname, Item_t item)
{
	try{

	checkVarName(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item;
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsDocument( xqp_string varname, xqp_anyURI documentURI)
{
	try{

	checkVarName(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	Store		&store = Store::getInstance();
	var.atomic_item = store.getDocument(documentURI);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::FODC0002);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}

bool DynamicContextWrapper::setVariableAsDocumentFromFile(
		xqp_string		varname,
		xqp_string		file_path,
    xqp_string    storeUri)
{
	try
  {
		checkVarName(varname);
		dctx_extern_var_t		var;
		var.varname = varname;
  
		std::ifstream			is(file_path.c_str ());
		if(!is.is_open())
		{
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, file_path);
			return false;
		}
		Store		&store = Store::getInstance();

		if(storeUri == "")
			storeUri = file_path;

		//?store.deleteDocument(docUri);
		var.atomic_item = store.loadDocument(storeUri, is);
		if(var.atomic_item == NULL)
		{//cannot upload document into store
			//or maybe is not valid xml
			ZORBA_ERROR_ALERT(ZorbaError::API0017_CANNOT_LOAD_DOCUMENT, NULL, DONT_CONTINUE_EXECUTION, file_path);
			return false;
		}

		deleteVariable(varname);
		vars.push_back(var);
   return true;
	}
	CATCH_ALL_RETURN_false;
  return false;
}


bool DynamicContextWrapper::setVariableAsHexBinary( xqp_string varname, xqp_hexBinary hex_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createHexBinary(hex_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}
bool DynamicContextWrapper::setVariableAsBase64Binary( xqp_string varname, xqp_base64Binary base64_value)
{
	try{

	checkVarName(varname);

	ItemFactory* item_factory = Zorba::getItemFactory();
	dctx_extern_var_t		var;
	var.varname = varname;
	var.atomic_item = item_factory->createBase64Binary(base64_value);
	if(var.atomic_item == NULL)
	{
		ZORBA_ERROR_ALERT(ZorbaError::API0013_INAPPROPRIATE_VARIABLE_VALUE);
	}

	deleteVariable(varname);
	vars.push_back(var);
	return true;

	}CATCH_ALL_RETURN_false;

}


bool DynamicContextWrapper::deleteVariable( xqp_string varname )
{
	try{
	std::vector<dctx_extern_var_t>::iterator		it;
	for(it = vars.begin(); it != vars.end(); it++)
	{
		if((*it).varname == varname)
		{
			vars.erase(it);
			return true;
		}
	}

	return false;
	}CATCH_ALL_RETURN_false;
}

void DynamicContextWrapper::deleteAllVariables( )
{
	try{
	vars.clear();
	
	}CATCH_ALL_NO_RETURN(;);
}


void DynamicContextWrapper::setDefaultCollection( xqp_string collectionURI )
{
	this->default_collection_uri = collectionURI;
}

dynamic_context*	DynamicContextWrapper::create_dynamic_context(static_context *sctx)//and fill in with the values
{
	try{
	///call for store to give iterators for accessing docs and collections...
	dynamic_context*	new_dctx;

	new_dctx = new dynamic_context;
	
	///fill in with values
	//for variables with atomic values, create singleton iterators with one item
	SingletonIterator		*one_item_iterator;
	PlanWrapper					*iterator_plus_state;

	std::vector<dctx_extern_var_t>::iterator		it;
	for(it = vars.begin(); it != vars.end(); it++)
	{
		one_item_iterator = new SingletonIterator(Zorba::null_loc, (*it).atomic_item);
		PlanIter_t		iter_t(one_item_iterator);
		iterator_plus_state = new PlanWrapper(iter_t);
		xqp_string		expanded_name;
		expanded_name = new_dctx->expand_varname(sctx, (*it).varname);
		new_dctx->add_variable(expanded_name, iterator_plus_state);
	}

	new_dctx->set_implicit_timezone(implicit_timezone_seconds);
	if(is_datetime_initialized)
		new_dctx->set_execution_date_time(current_date_time, current_timezone_seconds);
	new_dctx->set_default_collection(default_collection_uri);

	if(this->context_item != NULL)
	{
		new_dctx->set_context_item(this->context_item, 1);
	}

	return new_dctx;

	}CATCH_ALL_RETURN_NULL;

}

}//end namespace xqp
