
#include <zorba/zorba_api.h>
#include <fstream>
#include <time.h>
#include <assert.h>
#include <zorbatypes/representations.h>

//#include "../error_display.h"

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);

int test_api_dynamic_context(const char *result_file_name)
{
	ofstream		result_file(result_file_name);
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;

	///now start the zorba engine
	ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();

	///thread specific
	zorba_factory->initThread();

	//do the test
	ZorbaAlertsManager_t		errmanager = zorba_factory->getAlertsManagerForCurrentThread();

	///testing the dynamic context!
	DynamicQueryContext_t		dctx1;

	for(i=0;i<100;i++)
	{
		dctx1 = zorba_factory->createDynamicContext();
	}
/*
	struct int_types_descr
	{
		DynamicQueryContext::VAR_INT_TYPE	type;
		string				descr;
	}int_types[] = {		
		{DynamicQueryContext::XS_INTEGER,"XS_INTEGER"},//derived from XS_DECIMAL
		{DynamicQueryContext::XS_NON_POSITIVE_INTEGER,"XS_NON_POSITIVE_INTEGER"},//derived from XS_INTEGER
		{DynamicQueryContext::XS_NEGATIVE_INTEGER,"XS_NEGATIVE_INTEGER"},//derived from XS_NON_POSITIVE_INTEGER
		{DynamicQueryContext::XS_LONG,"XS_LONG"},//derived from XS_INTEGER
		{DynamicQueryContext::XS_INT,"XS_INT"},//derived from XS_LONG
		{DynamicQueryContext::XS_SHORT,"XS_SHORT"},//derived from XS_INT
		{DynamicQueryContext::XS_BYTE,"XS_BYTE"},//derived from XS_SHORT
		{DynamicQueryContext::XS_NON_NEGATIVE_INTEGER,"XS_NON_NEGATIVE_INTEGER"},//derived from XS_INTEGER
		{DynamicQueryContext::XS_UNSIGNED_LONG,"XS_UNSIGNED_LONG"},//derived from XS_NON_NEGATIVE_INTEGER
		{DynamicQueryContext::XS_UNSIGNED_INT,"XS_UNSIGNED_INT"},//derived from XS_UNSIGNED_LONG
		{DynamicQueryContext::XS_UNSIGNED_SHORT,"XS_UNSIGNED_SHORT"},//derived from XS_UNSIGNED_INT
		{DynamicQueryContext::XS_UNSIGNED_BYTE,"XS_UNSIGNED_BYTE"},//derived from XS_UNSIGNED_SHORT
		{DynamicQueryContext::XS_POSITIVE_INTEGER, "XS_POSITIVE_INTEGER"}//derived from XS_NON_NEGATIVE_INTEGER
		};
	struct str_types_descr
	{
		DynamicQueryContext::VAR_STR_TYPE	type;
		string				descr;
	}str_types[] = {
		{DynamicQueryContext::XS_STRING,"XS_STRING"},//derived from XS_ANY_ATOMIC_TYPE
		{DynamicQueryContext::XS_NORMALIZED_STRING,"XS_NORMALIZED_STRING"},//derived from XS_STRING
		{DynamicQueryContext::XS_TOKEN,"XS_TOKEN"},//derived from XS_NORMALIZED_STRING
		{DynamicQueryContext::XS_LANGUAGE,"XS_LANGUAGE"},//derived from XS_TOKEN
		{DynamicQueryContext::XS_NMTOKEN,"XS_NMTOKEN"},//derived from XS_TOKEN
		{DynamicQueryContext::XS_NAME,"XS_NAME"},//derived from XS_TOKEN
		{DynamicQueryContext::XS_NCNAME,"XS_NCNAME"},//derived from XS_NAME
		{DynamicQueryContext::XS_ID,"XS_ID"},//derived from XS_NCNAME
		{DynamicQueryContext::XS_IDREF,"XS_IDREF"},//derived from XS_NCNAME
		{DynamicQueryContext::XS_ENTITY,"XS_ENTITY"},//derived from XS_NCNAME
		{DynamicQueryContext::XS_NOTATION,"XS_NOTATION"},
		{DynamicQueryContext::XS_ANYURI,"XS_ANYURI"},
		{DynamicQueryContext::XS_UNTYPED_ATOMIC, "XS_UNTYPED_ATOMIC"}
	};
	struct double_types_descr
	{
		DynamicQueryContext::VAR_DOUBLE_TYPE		type;
		string			descr;
	}double_types[] = {
		{DynamicQueryContext::XS_DECIMAL,"XS_DECIMAL"},
		{DynamicQueryContext::XS_FLOAT,"XS_FLOAT"},
		{DynamicQueryContext::XS_DOUBLE, "XS_DOUBLE"}
	};
	struct datetime_types_descr
	{
		DynamicQueryContext::VAR_DATETIME_TYPE		type;
		string			descr;
	} datetime_types[] = {
		{DynamicQueryContext::XS_DATETIME,"XS_DATETIME"},
		{DynamicQueryContext::XS_DATE,"XS_DATE"},
		{DynamicQueryContext::XS_TIME,"XS_TIME"},
		{DynamicQueryContext::XS_GYEAR_MONTH,"XS_GYEAR_MONTH"},
		{DynamicQueryContext::XS_GYEAR,"XS_GYEAR"},
		{DynamicQueryContext::XS_GMONTH_DAY,"XS_GMONTH_DAY"},
		{DynamicQueryContext::XS_GDAY,"XS_GDAY"},
		{DynamicQueryContext::XS_GMONTH, "XS_GMONTH"}
	};


	result_file << endl << "set variables with INTEGER values" << endl;
	for(i=0;i<sizeof(int_types)/sizeof(int_types[0]);i++)
	{
		xqp_integer		values[] = {-0x8000000000ll, -0x10000000ll, -0x100ll, -10ll, 0ll, 10ll, +0x100ll, +0x10000000ll, +0x8000000000ll};
		unsigned int		j;
		for(j=0;j<sizeof(values)/sizeof(long long);j++)
		{
//			if(dctx1->SetVariableAsInteger("external_vars:ix", values[j], int_types[i].type))
//			{
//				result_file << "SetVariables succeeded for "; 
//			}
//		else
//		{
//			result_file << "SetVariables FAILED for ";
//		}
//		result_file << hex << values[j] << " and type [" << dec << i << "] " << int_types[i].descr << endl;
		}
	}

	result_file << endl << "set variables with XQP_STRING values" << endl;
	for(i=0;i<sizeof(str_types)/sizeof(str_types[0]);i++)
	{
		xqp_string		values[] = {"", " var ", "ID", "external:internal:x", "prefix:local"};
		unsigned int		j;
		for(j=0;j<sizeof(values)/sizeof(xqp_string);j++)
		{
			if(dctx1->SetVariableAsString("external_vars:sx", values[j], str_types[i].type))
			{
				result_file << "SetVariables succeeded for ";
			}
			else
			{
				result_file << "SetVariables FAILED for ";
			}
			result_file << (std::string)values[j] << " and type [" << i << "] " << str_types[i].descr << endl;
		}
	}

	result_file << endl << "set variables with DOUBLE values" << endl;
	for(i=0;i<sizeof(double_types)/sizeof(double_types[0]);i++)
	{
		long double		values[] = {-1e200, -32.5, 0, 32.5, 7e127, 14e233};
		unsigned int		j;
		for(j=0;j<sizeof(values)/sizeof(long double);j++)
		{
			if(dctx1->SetVariableAsDouble("external_vars:dx", values[j], double_types[i].type))
			{
				result_file << "SetVariables succeeded for ";
			}
			else
			{
				result_file << "SetVariables FAILED for ";
			}
			result_file << values[j] << " and type [" << i << "] " << double_types[i].descr << endl;
		}
	}

	result_file << endl << "set variables with BOOL values" << endl;
	if(dctx1->SetVariableAsBool("external_vars:bx", true))
	{
		result_file << "SetVariables succeeded for bool true" << endl;
	}
	else
	{
		result_file << "SetVariables FAILED for bool true" << endl;
	}
	if(dctx1->SetVariableAsBool("external_vars:bx", false))
	{
		result_file << "SetVariables succeeded for bool false" << endl;
	}
	else
	{
		result_file << "SetVariables FAILED for bool false" << endl;
	}

	result_file << endl << "set variables with DATETIME values" << endl;
	for(i=0;i<sizeof(datetime_types)/sizeof(datetime_types[0]);i++)
	{
		struct tm		tmvalue;
		tmvalue.tm_year = 107;//+1900=2007
		tmvalue.tm_mon = 11;//december
		tmvalue.tm_mday = 17;
		tmvalue.tm_wday = 0;//monday
		tmvalue.tm_yday = 340;
		tmvalue.tm_hour = 16;
		tmvalue.tm_min = 27;
		tmvalue.tm_sec = 03;
		tmvalue.tm_isdst = 0;
		if(dctx1->SetVariableAsDateTime("external_vars:tmx", tmvalue, datetime_types[i].type))
		{
			result_file << "SetVariables succeeded for ";
		}
		else
		{
			result_file << "SetVariables failed for ";
		}
		result_file << "17/11/2007 16:27:03" << " and type [" << i << "] " << datetime_types[i].descr << endl;
	}
*/

	assert(!dctx1->setVariableAsBigInteger( "..#$%", Integer::parseInt((int32_t)0), DynamicQueryContext::XS_INTEGER));
  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseInt((int32_t)0), DynamicQueryContext::XS_INTEGER));
  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseLongLong((long long)-1000000), DynamicQueryContext::XS_INTEGER));
//  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", "12345678901234567890123456789012345678901234567890", DynamicQueryContext::XS_INTEGER));
//  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", (double)-1000000.4343, DynamicQueryContext::XS_INTEGER));

	assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseInt((int32_t)0), DynamicQueryContext::XS_NON_POSITIVE_INTEGER));
  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseLongLong((long long)-1000000), DynamicQueryContext::XS_NON_POSITIVE_INTEGER));
//  assert(!dctx1->setVariableAsBigInteger( "external_vars:bigx", "12345678901234567890123456789012345678901234567890", DynamicQueryContext::XS_NON_POSITIVE_INTEGER));
//  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", (double)-1000000.4343, DynamicQueryContext::XS_NON_POSITIVE_INTEGER));

  assert(!dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseInt((int32_t)0), DynamicQueryContext::XS_NEGATIVE_INTEGER));
  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", Integer::parseLongLong((long long)-1000000), DynamicQueryContext::XS_NEGATIVE_INTEGER));
//  assert(!dctx1->setVariableAsBigInteger( "external_vars:bigx", "12345678901234567890123456789012345678901234567890", DynamicQueryContext::XS_NEGATIVE_INTEGER));
//  assert(dctx1->setVariableAsBigInteger( "external_vars:bigx", (double)-1000000.4343, DynamicQueryContext::XS_NEGATIVE_INTEGER));
	
	assert(!dctx1->setVariableAsBigUInteger( "..#$%", Integer::parseInt(0)));
  assert(dctx1->setVariableAsBigUInteger( "external_vars:ubigx", Integer::parseInt(0), DynamicQueryContext::XS_NON_NEGATIVE_INTEGER));
  assert(!dctx1->setVariableAsBigUInteger( "external_vars:ubigx", Integer::parseLongLong((long long)-1000000), DynamicQueryContext::XS_NON_NEGATIVE_INTEGER));
//  assert(dctx1->setVariableAsBigUInteger( "external_vars:ubigx", "12345678901234567890123456789012345678901234567890", DynamicQueryContext::XS_NON_NEGATIVE_INTEGER));
//  assert(!dctx1->setVariableAsBigUInteger( "external_vars:ubigx", (double)-1000000.4343, DynamicQueryContext::XS_NON_NEGATIVE_INTEGER));

  assert(!dctx1->setVariableAsBigUInteger( "external_vars:ubigx", Integer::parseInt(0), DynamicQueryContext::XS_POSITIVE_INTEGER));
  assert(!dctx1->setVariableAsBigUInteger( "external_vars:ubigx", Integer::parseLongLong((long long)-1000000), DynamicQueryContext::XS_POSITIVE_INTEGER));
//  assert(dctx1->setVariableAsBigUInteger( "external_vars:ubigx", "12345678901234567890123456789012345678901234567890", DynamicQueryContext::XS_POSITIVE_INTEGER));
//  assert(!dctx1->setVariableAsBigUInteger( "external_vars:ubigx", (double)-1000000.4343, DynamicQueryContext::XS_POSITIVE_INTEGER));

	assert(!dctx1->setVariableAsDecimal( "..#$%", Decimal::parseInt(0)));
  assert(dctx1->setVariableAsDecimal( "external_vars:decx", Decimal::parseInt(0)));
  assert(dctx1->setVariableAsDecimal( "external_vars:decx", Decimal::parseLongLong((long long)-1000000)));
//  assert(dctx1->setVariableAsDecimal( "external_vars:decx", "12345678901234567890123456789012345678901234567890.1314"));
//  assert(dctx1->setVariableAsDecimal( "external_vars:decx", (double)-1000000.4343));

	assert(!dctx1->setVariableAsLong( "a:b:c", 0));
  assert(dctx1->setVariableAsLong( "external_vars:longx", -1112131415161718ll));

  assert(!dctx1->setVariableAsULong( "a:b:c", 0));
  assert(dctx1->setVariableAsULong( "external_vars:ulongx", 1112131415161718ll));

  assert(!dctx1->setVariableAsInt( "a:b:c", 0));
  assert(dctx1->setVariableAsInt( "external_vars:intx", -1213141516));

  assert(!dctx1->setVariableAsUInt( "a:b:c", 0));
	assert(dctx1->setVariableAsUInt( "external_vars:uintx", 1213141516));

  assert(!dctx1->setVariableAsShort( "a:b:c", 0));
	assert(dctx1->setVariableAsShort( "external_vars:shx", -30000));

  assert(!dctx1->setVariableAsUShort( "a:b:c", 0));
	assert(dctx1->setVariableAsUShort( "external_vars:ushx", 60000));
  
  assert(!dctx1->setVariableAsByte( "a:b:c", 0));
	assert(dctx1->setVariableAsByte( "external_vars:bytex", -60));

  assert(!dctx1->setVariableAsUByte( "a:b:c", 0));
	assert(dctx1->setVariableAsUByte( "external_vars:ubytex", 255));




  assert(!dctx1->setVariableAsString( "a:b:c", ""));
  assert(dctx1->setVariableAsString( "external_vars:strx", ""));
  assert(dctx1->setVariableAsString( "external_vars:strx", "11"));
  assert(dctx1->setVariableAsString( "external_vars:strx", "test string"));

  assert(!dctx1->setVariableAsNormalizedString( "a:b:c", ""));
	assert(dctx1->setVariableAsNormalizedString( "external_vars:strx", ""));
	assert(dctx1->setVariableAsNormalizedString( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsNormalizedString( "external_vars:strx", "test string"));

  assert(!dctx1->setVariableAsToken( "a:b:c", ""));
	assert(dctx1->setVariableAsToken( "external_vars:strx", ""));
	assert(dctx1->setVariableAsToken( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsToken( "external_vars:strx", "toKen"));

  assert(!dctx1->setVariableAsLanguage( "a:b:c", ""));
	assert(dctx1->setVariableAsLanguage( "external_vars:strx", ""));
	assert(dctx1->setVariableAsLanguage( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsLanguage( "external_vars:strx", "Language"));

  assert(!dctx1->setVariableAsNMToken( "a:b:c", ""));
	assert(dctx1->setVariableAsNMToken( "external_vars:strx", ""));
	assert(dctx1->setVariableAsNMToken( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsNMToken( "external_vars:strx", "NMToken"));

  assert(!dctx1->setVariableAsName( "a:b:c", ""));
	assert(dctx1->setVariableAsName( "external_vars:strx", ""));
	assert(dctx1->setVariableAsName( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsName( "external_vars:strx", "Name"));

  assert(!dctx1->setVariableAsNCName( "a:b:c", ""));
	assert(dctx1->setVariableAsNCName( "external_vars:strx", ""));
	assert(!dctx1->setVariableAsNCName( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsNCName( "external_vars:strx", "NCName"));

  assert(!dctx1->setVariableAsID( "a:b:c", ""));
	assert(dctx1->setVariableAsID( "external_vars:strx", ""));
	assert(dctx1->setVariableAsID( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsID( "external_vars:strx", "ID"));

  assert(!dctx1->setVariableAsIDREF( "a:b:c", ""));
	assert(dctx1->setVariableAsIDREF( "external_vars:strx", ""));
	assert(dctx1->setVariableAsIDREF( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsIDREF( "external_vars:strx", "IDREF"));

  assert(!dctx1->setVariableAsEntity( "a:b:c", ""));
	assert(dctx1->setVariableAsEntity( "external_vars:strx", ""));
	assert(dctx1->setVariableAsEntity( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsEntity( "external_vars:strx", "Entity"));

  assert(!dctx1->setVariableAsNotation( "a:b:c", ""));
	assert(dctx1->setVariableAsNotation( "external_vars:strx", ""));
	assert(dctx1->setVariableAsNotation( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsNotation( "external_vars:strx", "Notation"));

  assert(!dctx1->setVariableAsAnyURI( "a:b:c", ""));
	assert(dctx1->setVariableAsAnyURI( "external_vars:strx", ""));
	assert(!dctx1->setVariableAsAnyURI( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsAnyURI( "external_vars:strx", "c:/file.xml"));
	assert(dctx1->setVariableAsAnyURI( "external_vars:strx", "file://c:/file.xml"));

  assert(!dctx1->setVariableAsQName( "a:b:c", "", "", ""));
	assert(dctx1->setVariableAsQName( "external_vars:strx", "", "", ""));
	assert(dctx1->setVariableAsQName( "external_vars:strx", "11", "22", "33"));
	assert(dctx1->setVariableAsQName( "external_vars:strx", "ns", "prefix", "local"));

  assert(!dctx1->setVariableAsUntypedAtomic( "a:b:c", ""));
	assert(dctx1->setVariableAsUntypedAtomic( "external_vars:strx", ""));
	assert(dctx1->setVariableAsUntypedAtomic( "external_vars:strx", "11"));
	assert(dctx1->setVariableAsUntypedAtomic( "external_vars:strx", "Untyped Atomic"));



  assert(!dctx1->setVariableAsDouble( "a:b:c", xqp_double::parseInt(0)));
  assert(dctx1->setVariableAsDouble( "external_vars:dblx", xqp_double::parseFloatType(0.0)));
  assert(dctx1->setVariableAsDouble( "external_vars:dblx", xqp_double::parseFloatType(-1000000.0)));
  assert(dctx1->setVariableAsDouble( "external_vars:dblx", xqp_double::parseFloatType(12134.32948075)));

  assert(!dctx1->setVariableAsFloat( "a:b:c", xqp_float::parseInt(0)));
	assert(dctx1->setVariableAsFloat( "external_vars:fltx", xqp_float::parseFloatType(0.0)));
	assert(dctx1->setVariableAsFloat( "external_vars:fltx", xqp_float::parseFloatType(-1000000.0f)));
	assert(dctx1->setVariableAsFloat( "external_vars:fltx", xqp_float::parseFloatType(12134.329f)));

  assert(!dctx1->setVariableAsBool( "a:b:c", 0));
  assert(dctx1->setVariableAsBool( "external_vars:boolx", true));
  assert(dctx1->setVariableAsBool( "external_vars:boolx", false));

	struct tm		tmvalue;
		tmvalue.tm_year = 107;//+1900=2007
		tmvalue.tm_mon = 11;//december
		tmvalue.tm_mday = 17;
		tmvalue.tm_wday = 0;//monday
		tmvalue.tm_yday = 340;
		tmvalue.tm_hour = 16;
		tmvalue.tm_min = 27;
		tmvalue.tm_sec = 03;
		tmvalue.tm_isdst = 0;
  assert(!dctx1->setVariableAsDateTime( "a:b:c", 0));
  assert(dctx1->setVariableAsDateTime( "external_vars:timex", tmvalue, +2*60*60));
	tmvalue.tm_year = -107;
  assert(!dctx1->setVariableAsDateTime( "external_vars:timex", tmvalue, +22*60*60));

	//yyyy-mm-ddThh:mm:ss.msss
	xqp_dateTime		dtt;
	DateTime::parse_string("2007-12-1T14:58:43", dtt);
  assert(!dctx1->setVariableAsDateTime( "a:b:c", 0));
	assert(dctx1->setVariableAsDateTime( "external_vars:dttx", dtt));

  assert(!dctx1->setVariableAsDateTime( "a:b:c", 0));
	assert(dctx1->setVariableAsDateTime( "external_vars:timex", 2008, 2, 1, 12, 56, 49, +2));
	assert(!dctx1->setVariableAsDateTime( "external_vars:timex", -2008, 2, 1, 12, 56, 49, +22));

	YearMonthDuration		ymd(14);
  assert(!dctx1->setVariableAsDuration( "a:b:c", 0));
	assert(dctx1->setVariableAsDuration( "external_vars:durx", &ymd));

  assert(!dctx1->setVariableAsDuration( "a:b:c", 0));
	assert(dctx1->setVariableAsDuration( "external_vars:durx", 10, 1, 2, 4, 1, 0));
	assert(dctx1->setVariableAsDuration( "external_vars:durx", -10, 1, 2, 4, 1, 0));

	xqp_date		dt;
	Date::parse_string("2007-11-1", dt);
  assert(!dctx1->setVariableAsDate( "a:b:c", 0));
	assert(dctx1->setVariableAsDate( "external_vars:datex", dt));

  assert(!dctx1->setVariableAsDate( "a:b:c", 0));
	assert(dctx1->setVariableAsDate( "external_vars:datex", 2008 , 2, 1));
	assert(!dctx1->setVariableAsDate( "external_vars:datex", 2008 , 22, 100));

	xqp_time		tt;
	Time::parse_string("10:10:10", tt);
  assert(!dctx1->setVariableAsTime( "a:b:c", 0));
	assert(dctx1->setVariableAsTime( "external_vars:timex", tt));

  assert(!dctx1->setVariableAsTime( "a:b:c", 0));
	assert(dctx1->setVariableAsTime( "external_vars:timex", 10, 10, 10, +2));
	assert(!dctx1->setVariableAsTime( "external_vars:timex", 100, 100, 100, +200));

	xqp_gYearMonth		gymt;
	GYearMonth::parse_string("2007-11", gymt);
  assert(!dctx1->setVariableAsGYearMonth( "a:b:c", 0));
	assert(dctx1->setVariableAsGYearMonth( "external_vars:gymx", gymt));

  assert(!dctx1->setVariableAsGYearMonth( "a:b:c", 0));
	assert(dctx1->setVariableAsGYearMonth( "external_vars:gymx", 2008 , 2));
	assert(!dctx1->setVariableAsGYearMonth( "external_vars:gymx", 2008 , -2));

	xqp_gYear		gyt;
	GYear::parse_string("2008", gyt);
  assert(!dctx1->setVariableAsGYear( "a:b:c", 0));
	assert(dctx1->setVariableAsGYear( "external_vars:gyx", gyt));

  assert(!dctx1->setVariableAsGYear( "a:b:c", 0));
	assert(dctx1->setVariableAsGYear( "external_vars:gyx", 2008));
	assert(!dctx1->setVariableAsGYear( "external_vars:gyx", -2008));

	xqp_gMonthDay		gmdt;
	GMonthDay::parse_string("10-30", gmdt);
  assert(!dctx1->setVariableAsGMonthDay( "a:b:c", 0));
	assert(dctx1->setVariableAsGMonthDay( "external_vars:gmdx", gmdt));

  assert(!dctx1->setVariableAsGMonthDay( "a:b:c", 0));
	assert(dctx1->setVariableAsGMonthDay( "external_vars:gmdx", 10, 30));
	assert(!dctx1->setVariableAsGMonthDay( "external_vars:gmdx", 20, 130));

	xqp_gDay		gdt;
	GDay::parse_string("30", gdt);
  assert(!dctx1->setVariableAsGDay( "a:b:c", 0));
	assert(dctx1->setVariableAsGDay( "external_vars:gdx", gdt));

  assert(!dctx1->setVariableAsGDay( "a:b:c", 0));
	assert(dctx1->setVariableAsGDay( "external_vars:gdx", 30));
	assert(dctx1->setVariableAsGDay( "external_vars:gdx", -30));
  
	xqp_gMonth		gmt;
	GMonth::parse_string("10", gmt);
  assert(!dctx1->setVariableAsGMonth( "a:b:c", 0));
	assert(dctx1->setVariableAsGMonth( "external_vars:gmx", gmt));
  
  assert(!dctx1->setVariableAsGMonth( "a:b:c", 0));
	assert(dctx1->setVariableAsGMonth( "external_vars:gmx", 12));
	assert(!dctx1->setVariableAsGMonth( "external_vars:gmx", 13));

	Item_t		docitem;
	XmlDataManager_t		store = zorba_factory->getXmlDataManager();
	docitem = store->loadDocument(make_absolute_file_name("test_xml.txt", __FILE__));
  assert(!dctx1->setVariableAsItem( "a:b:c", 0));
  assert(!dctx1->setVariableAsItem( "external_vars:itx", NULL));
  assert(dctx1->setVariableAsItem( "external_vars:itx", docitem));

  assert(!dctx1->setVariableAsDocument( "a:b:c", ""));
	assert(!dctx1->setVariableAsDocument( "external_vars:docx", ""));
	assert(dctx1->setVariableAsDocument( "external_vars:docx", make_absolute_file_name("test_xml.txt", __FILE__)));

	char	strtemp[] = "So test so test";
  assert(!dctx1->setVariableAsHexBinary( "a:b:c", 0));
	assert(!dctx1->setVariableAsHexBinary( "external_vars:hexx", NULL));
	assert(dctx1->setVariableAsHexBinary( "external_vars:hexx", strtemp));

  assert(!dctx1->setVariableAsBase64Binary( "a:b:c", 0));
	assert(!dctx1->setVariableAsBase64Binary( "external_vars:base64x", NULL));
	assert(dctx1->setVariableAsBase64Binary( "external_vars:base64x", strtemp));








	if(dctx1->deleteVariable("external_vars:tmx"))
	{
		result_file << "DeleteVariable succeeded for external_vars:tmx"<< endl;
	}
	else
	{
		result_file << "DeleteVariable failed for external_vars:tmx" << endl;
	}
	if(dctx1->deleteVariable("external_vars:tmx"))
	{
		result_file << "DeleteVariable succeeded for external_vars:tmx"<< endl;
	}
	else
	{
		result_file << "DeleteVariable failed for external_vars:tmx" << endl;
	}

	result_file << "SetDefaultCollection" << endl;
	dctx1->setDefaultCollection("http://www.flworfound.org/collections/collec0");
	dctx1->setDefaultCollection("http://www.flworfound.org/collections/collec0");
	dctx1->setDefaultCollection("http://www.flworfound.org/collections/collec0");


	dctx1 = NULL;//free now the dyn context

	result_file << "end of dynamic context test" << endl;
	zorba_factory->uninitThread();
	zorba_factory->shutdown();

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(result_file_name,
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	errmanager->dumpAlerts(result_file);

	zorba_factory->uninitThread();
	zorba_factory->shutdown();

	exit(1);

	return -1; 
}

//for CTEST
int dctx_test(int argc, char* argv[])
{
//	ZorbaEngine_t engine = ZorbaEngine::getInstance();
	test_api_dynamic_context("dctx_test.txt");
//	engine.shutdown();
	return 0;
}
