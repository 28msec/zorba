
#include "dynamic_context_wrapper.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "util/zorba.h"
#include "runtime/core/item_iterator.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"


namespace xqp {

DynamicContextWrapper::DynamicContextWrapper()
{
	current_date_time = 0;
	implicit_timezone = 0;
}

DynamicContextWrapper::~DynamicContextWrapper( )
{
	DeleteAllVariables();
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
			if((int_value <= -((long long)1<<(sizeof(xqp_long)*8-1))) || 
				(int_value >= ((long long)1<<(sizeof(xqp_long)*8-1))))
				return false;//inappropriate value
			break;
	case XS_INT://derived from XS_LONG
			if((int_value <= -((long long)1<<(sizeof(xqp_int)*8-1))) || 
				(int_value >= ((long long)1<<(sizeof(xqp_int)*8-1))))
				return false;//inappropriate value
			break;
	case XS_SHORT://derived from XS_INT
			if((int_value <= -((long long)1<<(sizeof(xqp_short)*8-1))) || 
				(int_value >= ((long long)1<<(sizeof(xqp_short)*8-1))))
				return false;//inappropriate value
			break;
	case XS_BYTE://derived from XS_SHORT
			if((int_value <= -((long long)1<<(sizeof(xqp_byte)*8-1))) || 
				(int_value >= ((long long)1<<(sizeof(xqp_byte)*8-1))))
				return false;//inappropriate value
			break;
	case XS_NON_NEGATIVE_INTEGER://derived from XS_INTEGER
			if(int_value < 0)
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_LONG://derived from XS_NON_NEGATIVE_INTEGER
			if((int_value < 0) || (int_value >= ((long long)1<<(sizeof(xqp_ulong)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_INT://derived from XS_UNSIGNED_LONG
			if((int_value < 0) || (int_value >= ((long long)1<<(sizeof(xqp_uint)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_SHORT://derived from XS_UNSIGNED_INT
			if((int_value < 0) || (int_value >= ((long long)1<<(sizeof(xqp_unsignedShort)*8))))
				return false;//inappropriate value
		break;
	case XS_UNSIGNED_BYTE://derived from XS_UNSIGNED_SHORT
			if((int_value < 0) || (int_value >= ((long long)1<<(sizeof(xqp_unsignedByte)*8))))
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
	var.str_value = &str_value.getStore();
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

bool DynamicContextWrapper::SetVariable( xqp_string varname, struct tm datetime_value, VAR_DATETIME_TYPE type)
{
	if(!checkQName(varname))
		return false;
	DeleteVariable(varname);

	dctx_extern_var_t		var;
	var.varname = varname;
	var.vartype = VAR_DATETIME;
	var.datetime_type = type;
	var.datetime_value = datetime_value;

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
	ItemFactory		*item_factory = zorba::getItemFactory();
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
				atomic_item = item_factory->createNonPositiveInteger((xqp_nonPositiveInteger)(*it).int_value);
				break;
			case XS_NEGATIVE_INTEGER://derived from XS_NON_POSITIVE_INTEGER
				atomic_item = item_factory->createNegativeInteger((xqp_negativeInteger)(*it).int_value);
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
				atomic_item = item_factory->createNonNegativeInteger((xqp_nonNegativeInteger)(*it).int_value);
				break;
			case XS_UNSIGNED_LONG://derived from XS_NON_NEGATIVE_INTEGER
				atomic_item = item_factory->createUnsignedLong((xqp_ulong)(*it).int_value);
				break;
			case XS_UNSIGNED_INT://derived from XS_UNSIGNED_LONG
				atomic_item = item_factory->createUnsignedInt((xqp_uint)(*it).int_value);
				break;
			case XS_UNSIGNED_SHORT://derived from XS_UNSIGNED_INT
				atomic_item = item_factory->createUnsignedShort((xqp_unsignedShort)(*it).int_value);
				break;
			case XS_UNSIGNED_BYTE://derived from XS_UNSIGNED_SHORT
				atomic_item = item_factory->createUnsignedByte((xqp_unsignedByte)(*it).int_value);
				break;
			case XS_POSITIVE_INTEGER://derived from XS_NON_NEGATIVE_INTEGER
				atomic_item = item_factory->createPositiveInteger((xqp_positiveInteger)(*it).int_value);
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
					(*it).datetime_value.tm_year+1900, (*it).datetime_value.tm_mon, (*it).datetime_value.tm_mday,
					(*it).datetime_value.tm_hour + (*it).datetime_value.tm_isdst ? 1 : 0, (*it).datetime_value.tm_min, (*it).datetime_value.tm_sec,
					implicit_timezone);
				break;
			case XS_DATE:
				atomic_item = item_factory->createDate(
					(*it).datetime_value.tm_year+1900, (*it).datetime_value.tm_mon, (*it).datetime_value.tm_mday);
				break;
			case XS_TIME:
				atomic_item = item_factory->createTime(
					(*it).datetime_value.tm_hour + (*it).datetime_value.tm_isdst ? 1 : 0, (*it).datetime_value.tm_min, (*it).datetime_value.tm_sec);
				break;
			case XS_GYEAR_MONTH:
				atomic_item = item_factory->createGYearMonth(
					(*it).datetime_value.tm_year+1900, (*it).datetime_value.tm_mon);
				break;
			case XS_GYEAR:
				atomic_item = item_factory->createGYear(
					(*it).datetime_value.tm_year+1900);
				break;
			case XS_GMONTH_DAY:
				atomic_item = item_factory->createGMonthDay(
					(*it).datetime_value.tm_mon, (*it).datetime_value.tm_mday);
				break;
			case XS_GDAY:
				atomic_item = item_factory->createGDay(
					(*it).datetime_value.tm_mday);
				break;
			case XS_GMONTH:
				atomic_item = item_factory->createGMonth(
					(*it).datetime_value.tm_mon);
				break;
			}
			break;
		}
		
		one_item_iterator = new SingletonIterator(zorba::null_loc, atomic_item);
		PlanIter_t		iter_t(one_item_iterator);
		iterator_plus_state = new PlanWrapper(iter_t);
		xqp_string		expanded_name;
		expanded_name = new_dctx->expand_varname(sctx, (*it).varname);
		new_dctx->add_variable(expanded_name, iterator_plus_state);
	}

	new_dctx->set_implicit_timezone(implicit_timezone);
	new_dctx->set_execution_date_time(current_date_time);
	new_dctx->set_default_collection(default_collection_uri);

	return new_dctx;
}

}//end namespace xqp
