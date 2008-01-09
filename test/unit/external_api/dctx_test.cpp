
#include "zorba/zorba_api.h"
#include <fstream>
#include <time.h>
#include <assert.h>
#include "zorba/types/representations.h"

//#include "../error_display.h"

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);
void DisplayErrorListForCurrentThread(std::ostream &result_file);

int test_api_dynamic_context(const char *result_file_name)
{
	ofstream		result_file(make_absolute_file_name(result_file_name, __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;

	///now start the zorba engine
	ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

	///thread specific
	zorba_factory.initThread();

	//do the test
	ZorbaAlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	///testing the dynamic context!
	DynamicQueryContext_t		dctx1;

	for(i=0;i<100;i++)
	{
		dctx1 = zorba_factory.createDynamicContext();
	}

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
			if(dctx1->SetVariable("external_vars:ix", values[j], int_types[i].type))
			{
				result_file << "SetVariables succeeded for "; 
			}
			else
			{
				result_file << "SetVariables FAILED for ";
			}
			result_file << hex << values[j] << " and type [" << dec << i << "] " << int_types[i].descr << endl;
		}
	}

	result_file << endl << "set variables with XQP_STRING values" << endl;
	for(i=0;i<sizeof(str_types)/sizeof(str_types[0]);i++)
	{
		xqp_string		values[] = {"", " var ", "ID", "external:internal:x", "prefix:local"};
		unsigned int		j;
		for(j=0;j<sizeof(values)/sizeof(xqp_string);j++)
		{
			if(dctx1->SetVariable("external_vars:sx", values[j], str_types[i].type))
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
			if(dctx1->SetVariable("external_vars:dx", values[j], double_types[i].type))
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
	if(dctx1->SetVariable("external_vars:bx", true))
	{
		result_file << "SetVariables succeeded for bool true" << endl;
	}
	else
	{
		result_file << "SetVariables FAILED for bool true" << endl;
	}
	if(dctx1->SetVariable("external_vars:bx", false))
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
		if(dctx1->SetVariable("external_vars:tmx", tmvalue, datetime_types[i].type))
		{
			result_file << "SetVariables succeeded for ";
		}
		else
		{
			result_file << "SetVariables failed for ";
		}
		result_file << "17/11/2007 16:27:03" << " and type [" << i << "] " << datetime_types[i].descr << endl;
	}

	if(dctx1->DeleteVariable("external_vars:tmx"))
	{
		result_file << "DeleteVariable succeeded for external_vars:tmx"<< endl;
	}
	else
	{
		result_file << "DeleteVariable failed for external_vars:tmx" << endl;
	}
	if(dctx1->DeleteVariable("external_vars:tmx"))
	{
		result_file << "DeleteVariable succeeded for external_vars:tmx"<< endl;
	}
	else
	{
		result_file << "DeleteVariable failed for external_vars:tmx" << endl;
	}

	result_file << "SetDefaultCollection" << endl;
	dctx1->SetDefaultCollection("http://www.flworfound.org/collections/collec0");
	dctx1->SetDefaultCollection("http://www.flworfound.org/collections/collec0");
	dctx1->SetDefaultCollection("http://www.flworfound.org/collections/collec0");


	dctx1 = NULL;//free now the dyn context

	result_file << "end of dynamic context test" << endl;
	zorba_factory.uninitThread();

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(make_absolute_file_name(result_file_name, __FILE__),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	DisplayErrorListForCurrentThread(result_file);

	zorba_factory.uninitThread();

	assert(false);

	return -1; 
}

//for CTEST
int dctx_test(int argc, char* argv[])
{
	ZorbaEngine& engine = ZorbaEngine::getInstance();
	test_api_dynamic_context("dctx_test.txt");
	engine.shutdown();
	return 0;
}
