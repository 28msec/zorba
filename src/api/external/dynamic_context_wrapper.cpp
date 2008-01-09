
#include "dynamic_context_wrapper.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "system/zorba.h"
#include "runtime/core/item_iterator.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"
#include <time.h>

namespace xqp {


DynamicContextWrapper::DynamicContextWrapper()
{
	memset((void*)&current_date_time, 0, sizeof(current_date_time));
	current_timezone_seconds = 0;
	is_datetime_initialized = false;
	implicit_timezone_seconds = 0;
}

DynamicContextWrapper::~DynamicContextWrapper( )
{
	DeleteAllVariables();
}

void		DynamicContextWrapper::SetCurrentDateTime( struct ::tm datetime, long timezone_seconds )
{
	this->current_date_time = datetime;
	this->current_timezone_seconds = timezone_seconds;
	is_datetime_initialized = true;
}

struct ::tm	DynamicContextWrapper::GetCurrentDateTime( long *ptimezone_seconds )
{
	if(ptimezone_seconds)
		*ptimezone_seconds = this->current_timezone_seconds;
	return current_date_time;
}

//check if var name is well formed
bool	DynamicContextWrapper::checkQName(xqp_string varname)
{
	std::string::size_type n = static_cast<std::string> (varname).find (':');
  if(n == string::npos)
		return true;//no prefix
	n = static_cast<std::string>(varname.substr (n+1)).find(':');
  if(n == string::npos)
		return true;//one prefix
	return false;//two prefixes!
}

bool DynamicContextWrapper::SetVariable( xqp_string varname, long long int_value, VAR_INT_TYPE type)
{
	if(!checkQName(varname))
		return false;
	switch(type)
	{
	case XS_INTEGER://derived from XS_DECIMAL
			break;
	case XS_NON_POSITIVE_INTEGER://derived from XS_INTEGER
			if(int_value > 0)
				return false;//inappropriate value
			break;
	case XS_NEGATIVE_INTEGER://derived from XS_NON_POSITIVE_INTEGER
			if(int_value >= 0)
				return false;//inappropriate value
		break;
	case XS_LONG://derived from XS_INTEGER
			if((int_value <= -((long long)1ll<<(sizeof(xqp_long)*8-1))) || 
				(int_value >= ((long long)1ll<<(sizeof(xqp_long)*8-1))))
				return false;//inappropriate value
			break;
	case XS_INT://derived from XS_LONG
			if((int_value <= -((long long)1ll<<(sizeof(xqp_int)*8-1))) || 
				(int_value >= ((long long)1ll<<(sizeof(xqp_int)*8-1))))
				return false;//inappropriate value
			break;
	case XS_SHORT://derived from XS_INT
			if((int_value <= -((long long)1ll<<(sizeof(xqp_short)*8-1))) || 
				(int_value >= ((long long)1ll<<(sizeof(xqp_short)*8-1))))
				return false;//inappropriate value
			break;
	case XS_BYTE://derived from XS_SHORT
			if((int_value <= -((long long)1ll<<(sizeof(xqp_byte)*8-1))) || 
				(int_value >= ((long long)1ll<<(sizeof(xqp_byte)*8-1))))
				return false;//inappropriate value
			break;
	case XS_NON_NEGATIVE_INTEGER://derived from XS_INTEGER
			if(int_value < 0)
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_LONG://derived from XS_NON_NEGATIVE_INTEGER
			if((int_value < 0) || (int_value >= ((long long)1ll<<(sizeof(xqp_ulong)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_INT://derived from XS_UNSIGNED_LONG
			if((int_value < 0) || (int_value >= ((long long)1ll<<(sizeof(xqp_uint)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_SHORT://derived from XS_UNSIGNED_INT
			if((int_value < 0) || (int_value >= ((long long)1ll<<(sizeof(xqp_ushort)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_BYTE://derived from XS_UNSIGNED_SHORT
			if((int_value < 0) || (int_value >= ((long long)1ll<<(sizeof(xqp_ubyte)*8))))
				return false;//inappropriate value
		break;
	case XS_POSITIVE_INTEGER://derived from XS_NON_NEGATIVE_INTEGER
			if(int_value < 0)
				return false;//inappropriate value
		break;
	}
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_INT;
	var.int_type = type;
	var.int_value = int_value;

	vars.push_back(var);
	return true;
}

bool DynamicContextWrapper::SetVariable( xqp_string varname, xqp_string str_value, VAR_STR_TYPE type)
{
	if(!checkQName(varname))
		return false;
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_STR;
	var.str_type = type;
	var.str_value = str_value.getStore();
	var.str_value->addReference();

	vars.push_back(var);
	return true;
}

bool DynamicContextWrapper::SetVariable( xqp_string varname, long double double_value, VAR_DOUBLE_TYPE type)
{
	if(!checkQName(varname))
		return false;
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_DOUBLE;
	var.double_type = type;
	var.double_value = double_value;

	vars.push_back(var);
	return true;
}

bool DynamicContextWrapper::SetVariable( xqp_string varname, bool bool_value)
{
	if(!checkQName(varname))
		return false;
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_BOOL;
	var.bool_value = bool_value;

	vars.push_back(var);
	return true;
}

bool DynamicContextWrapper::SetVariable( xqp_string varname, struct ::tm datetime_value, long timezone_seconds, VAR_DATETIME_TYPE type)
{
	if(!checkQName(varname))
		return false;

	//validate the time
	switch(type)
	{
	case XS_DATETIME:
//				atomic_item = item_factory->createDateTime(
//					(*it).dtt_value.datetime_value.tm_year+1900, (*it).dtt_value.datetime_value.tm_mon, (*it).dtt_value.datetime_value.tm_mday,
//					(*it).dtt_value.datetime_value.tm_hour + (*it).dtt_value.datetime_value.tm_isdst ? 1 : 0, (*it).dtt_value.datetime_value.tm_min, (*it).dtt_value.datetime_value.tm_sec,
//					(*it).dtt_value.timezone_seconds);
		if((datetime_value.tm_sec < 0) || (datetime_value.tm_sec > 59) ||
			(datetime_value.tm_min < 0) || (datetime_value.tm_min > 59) ||
			(datetime_value.tm_hour < 0) || (datetime_value.tm_hour > 23) ||
			(datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31) ||
			(datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11) ||
			(datetime_value.tm_year < 0))
			return false;
		break;
	case XS_DATE:
//		atomic_item = item_factory->createDate(
//			(*it).datetime_value.tm_year+1900, (*it).datetime_value.tm_mon, (*it).datetime_value.tm_mday);
		if((datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31) ||
			(datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11) ||
			(datetime_value.tm_year < 0))
			return false;
		break;
	case XS_TIME:
//		atomic_item = item_factory->createTime(
//			(*it).datetime_value.tm_hour + (*it).datetime_value.tm_isdst ? 1 : 0, (*it).datetime_value.tm_min, (*it).datetime_value.tm_sec);
		if((datetime_value.tm_sec < 0) || (datetime_value.tm_sec > 59) ||
			(datetime_value.tm_min < 0) || (datetime_value.tm_min > 59) ||
			(datetime_value.tm_hour < 0) || (datetime_value.tm_hour > 23))
			return false;
		break;
	case XS_GYEAR_MONTH:
//		atomic_item = item_factory->createGYearMonth(
//			(*it).datetime_value.tm_year+1900, (*it).datetime_value.tm_mon);
		if((datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11) ||
			(datetime_value.tm_year < 0))
			return false;
		break;
	case XS_GYEAR:
//		atomic_item = item_factory->createGYear(
//			(*it).datetime_value.tm_year+1900);
		if((datetime_value.tm_year < 0))
			return false;
		break;
	case XS_GMONTH_DAY:
//		atomic_item = item_factory->createGMonthDay(
//			(*it).datetime_value.tm_mon, (*it).datetime_value.tm_mday);
		if((datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31) ||
			(datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11))
			return false;
		break;
	case XS_GDAY:
//		atomic_item = item_factory->createGDay(
//			(*it).datetime_value.tm_mday);
		if((datetime_value.tm_mday < 1) || (datetime_value.tm_mday > 31))
			return false;
		break;
	case XS_GMONTH:
//		atomic_item = item_factory->createGMonth(
//			(*it).datetime_value.tm_mon);
		if((datetime_value.tm_mon < 0) || (datetime_value.tm_mon > 11))
			return false;
		break;
	}

	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_DATETIME;
	var.datetime_type = type;
	var.dtt_value.datetime_value = datetime_value;
	var.dtt_value.timezone_seconds = timezone_seconds;

	vars.push_back(var);
	return true;
}

bool DynamicContextWrapper::SetVariableAsDocument( xqp_string varname, xqp_anyURI documentURI)
{
	if(!checkQName(varname))
		return false;
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_DOCUMENT_URI;
	var.document_uri_value = documentURI.getStore();
	var.document_uri_value->addReference();

	vars.push_back(var);
	return true;
}


bool DynamicContextWrapper::DeleteVariable( xqp_string varname )
{
	std::vector<dctx_extern_var_t>::iterator		it;
	for(it = vars.begin(); it != vars.end(); it++)
	{
		if((*it).varname == varname)
		{
			if((*it).vartype == VAR_STR)
			{
				(*it).str_value->removeReference();
			}
			else if((*it).vartype == VAR_DOCUMENT_URI)
			{
				(*it).document_uri_value->removeReference();
			}
			vars.erase(it);
			return true;
		}
	}

	return false;
}

void DynamicContextWrapper::DeleteAllVariables( )
{
	std::vector<dctx_extern_var_t>::iterator		it;
	for(it = vars.begin(); it != vars.end(); it++)
	{
		if((*it).vartype == VAR_STR)
		{
			(*it).str_value->removeReference();
		}
		else if((*it).vartype == VAR_DOCUMENT_URI)
		{
			(*it).document_uri_value->removeReference();
		}
	}
	vars.clear();
}


void DynamicContextWrapper::SetDefaultCollection( xqp_string collectionURI )
{
	this->default_collection_uri = collectionURI;
}

dynamic_context*	DynamicContextWrapper::create_dynamic_context(static_context *sctx)//and fill in with the values
{
	///call for store to give iterators for accessing docs and collections...
	dynamic_context*	new_dctx;

	new_dctx = new dynamic_context;
	
	///fill in with values
	//for variables with atomic values, create singleton iterators with one item
	Item_t		atomic_item;
	ItemFactory* item_factory = Zorba::getItemFactory();
	SingletonIterator		*one_item_iterator;
	PlanWrapper					*iterator_plus_state;

	std::vector<dctx_extern_var_t>::iterator		it;
	for(it = vars.begin(); it != vars.end(); it++)
	{
		atomic_item = NULL;
		switch((*it).vartype)
		{
		case VAR_INT :
			switch((*it).int_type)
			{
			case XS_INTEGER://derived from XS_DECIMAL
				atomic_item = item_factory->createInteger((*it).int_value);
				break;
			case XS_NON_POSITIVE_INTEGER://derived from XS_INTEGER
				atomic_item = item_factory->createNonPositiveInteger((xqp_integer)(*it).int_value);
				break;
			case XS_NEGATIVE_INTEGER://derived from XS_NON_POSITIVE_INTEGER
				atomic_item = item_factory->createNegativeInteger((xqp_uinteger)(*it).int_value);
				break;
			case XS_LONG://derived from XS_INTEGER
				atomic_item = item_factory->createLong((xqp_long)(*it).int_value);
				break;
			case XS_INT://derived from XS_LONG
				atomic_item = item_factory->createInt((xqp_int)(*it).int_value);
				break;
			case XS_SHORT://derived from XS_INT
				atomic_item = item_factory->createShort((xqp_short)(*it).int_value);
				break;
			case XS_BYTE://derived from XS_SHORT
				atomic_item = item_factory->createByte((xqp_byte)(*it).int_value);
				break;
			case XS_NON_NEGATIVE_INTEGER://derived from XS_INTEGER
				atomic_item = item_factory->createNonNegativeInteger((xqp_uinteger)(*it).int_value);
				break;
			case XS_UNSIGNED_LONG://derived from XS_NON_NEGATIVE_INTEGER
				atomic_item = item_factory->createUnsignedLong((xqp_ulong)(*it).int_value);
				break;
			case XS_UNSIGNED_INT://derived from XS_UNSIGNED_LONG
				atomic_item = item_factory->createUnsignedInt((xqp_uint)(*it).int_value);
				break;
			case XS_UNSIGNED_SHORT://derived from XS_UNSIGNED_INT
				atomic_item = item_factory->createUnsignedShort((xqp_ushort)(*it).int_value);
				break;
			case XS_UNSIGNED_BYTE://derived from XS_UNSIGNED_SHORT
				atomic_item = item_factory->createUnsignedByte((xqp_ubyte)(*it).int_value);
				break;
			case XS_POSITIVE_INTEGER://derived from XS_NON_NEGATIVE_INTEGER
				atomic_item = item_factory->createPositiveInteger((xqp_uinteger)(*it).int_value);
				break;
			}
			break;
		case VAR_STR :
		{
			xqpStringStore_t	sst((*it).str_value);
			xqp_string				xqpstr(sst);
			switch((*it).str_type)
			{
			case XS_STRING://derived from XS_ANY_ATOMIC_TYPE
				atomic_item = item_factory->createString(xqpstr);
				break;
			case XS_NORMALIZED_STRING://derived from XS_STRING
				atomic_item = item_factory->createNormalizedString(xqpstr);
				break;
			case XS_TOKEN://derived from XS_NORMALIZED_STRING
				atomic_item = item_factory->createToken(xqpstr);
				break;
			case XS_LANGUAGE://derived from XS_TOKEN
				atomic_item = item_factory->createLanguage(xqpstr);
				break;
			case XS_NMTOKEN://derived from XS_TOKEN
				atomic_item = item_factory->createNMTOKEN(xqpstr);
				break;
			case XS_NAME://derived from XS_TOKEN
				atomic_item = item_factory->createName(xqpstr);
				break;
			case XS_NCNAME://derived from XS_NAME
				atomic_item = item_factory->createNCName(xqpstr);
				break;
			case XS_ID://derived from XS_NCNAME
				atomic_item = item_factory->createID(xqpstr);
				break;
			case XS_IDREF://derived from XS_NCNAME
				atomic_item = item_factory->createIDREF(xqpstr);
				break;
			case XS_ENTITY://derived from XS_NCNAME
				atomic_item = item_factory->createENTITY(xqpstr);
				break;
			case XS_NOTATION:
				atomic_item = item_factory->createNOTATION(xqpstr);
				break;
			case XS_ANYURI:
				atomic_item = item_factory->createAnyURI(xqpstr);
				break;
			case XS_UNTYPED_ATOMIC:
				atomic_item = item_factory->createUntypedAtomic(xqpstr);
				break;
			}
		}break;
		case VAR_DOUBLE :
			switch((*it).double_type)
			{
			case XS_DECIMAL:
				atomic_item = item_factory->createDecimal((xqp_decimal)(*it).double_value);
				break;
			case XS_FLOAT:
				atomic_item = item_factory->createFloat((xqp_float)(*it).double_value);
				break;
			case XS_DOUBLE:
				atomic_item = item_factory->createDouble((xqp_double)(*it).double_value);
				break;
			}
			break;
		case VAR_BOOL :
			atomic_item = item_factory->createBoolean((*it).bool_value);
			break;
		case VAR_DATETIME :
			switch((*it).datetime_type)
			{
			case XS_DATETIME:
				atomic_item = item_factory->createDateTime(
					(*it).dtt_value.datetime_value.tm_year+1900, (*it).dtt_value.datetime_value.tm_mon, (*it).dtt_value.datetime_value.tm_mday,
					(*it).dtt_value.datetime_value.tm_hour + (*it).dtt_value.datetime_value.tm_isdst ? 1 : 0, (*it).dtt_value.datetime_value.tm_min, (*it).dtt_value.datetime_value.tm_sec,
					(*it).dtt_value.timezone_seconds/60/60);
				break;
			case XS_DATE:
				atomic_item = item_factory->createDate(
					(*it).dtt_value.datetime_value.tm_year+1900, (*it).dtt_value.datetime_value.tm_mon, (*it).dtt_value.datetime_value.tm_mday);
				break;
			case XS_TIME:
				atomic_item = item_factory->createTime(
					(*it).dtt_value.datetime_value.tm_hour + (*it).dtt_value.datetime_value.tm_isdst ? 1 : 0, (*it).dtt_value.datetime_value.tm_min, (*it).dtt_value.datetime_value.tm_sec);
				break;
			case XS_GYEAR_MONTH:
				atomic_item = item_factory->createGYearMonth(
					(*it).dtt_value.datetime_value.tm_year+1900, (*it).dtt_value.datetime_value.tm_mon);
				break;
			case XS_GYEAR:
				atomic_item = item_factory->createGYear(
					(*it).dtt_value.datetime_value.tm_year+1900);
				break;
			case XS_GMONTH_DAY:
				atomic_item = item_factory->createGMonthDay(
					(*it).dtt_value.datetime_value.tm_mon, (*it).dtt_value.datetime_value.tm_mday);
				break;
			case XS_GDAY:
				atomic_item = item_factory->createGDay(
					(*it).dtt_value.datetime_value.tm_mday);
				break;
			case XS_GMONTH:
				atomic_item = item_factory->createGMonth(
					(*it).dtt_value.datetime_value.tm_mon);
				break;
			}
			break;
		case VAR_DOCUMENT_URI:
			Store		*pStore = Zorba::getStore();
			xqpStringStore_t	sst((*it).document_uri_value);
			xqp_string				xqpstr(sst);
			atomic_item = pStore->getDocument(xqpstr);
			break;
		}
		
		one_item_iterator = new SingletonIterator(Zorba::null_loc, atomic_item);
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

	return new_dctx;
}

}//end namespace xqp
