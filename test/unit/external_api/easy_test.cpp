#include "zorba/zorba_easyapi.h"
#include <fstream>
#include <assert.h>
//#include "../error_display.h"

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);
void DisplayErrorListForCurrentThread(std::ostream &result_file);

int test_easy_api(const char *result_file_name)
{
	ofstream		result_file(make_absolute_file_name(result_file_name, __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;


	XQuerySimple_t		query;
	StaticQueryContext_t		sctx;
	DynamicQueryContext_t		dctx;
	XQueryResult_t		query_result;
	CollationInfo	*colinfo = NULL;

	result_file << "XQuerySimpleFactory::createQuery()" << endl;
	query = XQuerySimpleFactory::createQuery("1+2", "file://query.txt");
	if(query.isNull())
	{
		goto DisplayErrorsAndExit;
	}

	result_file << "getInternalStaticContext()" << endl;
	sctx = query->getInternalStaticContext();
	if(sctx.isNull())
	{
		goto DisplayErrorsAndExit;
	}
	result_file << "getInternalDynamicContext()" << endl;
	dctx = query->getInternalDynamicContext();
	if(dctx.isNull())
	{
		goto DisplayErrorsAndExit;
	}
	
  sctx->AddCollation("http://www.flworfound.org/apitest/coll1", "en");
	result_file << "AddCollation" << endl;
	colinfo = sctx->GetCollation("http://www.flworfound.org/apitest/coll1");
	if(!colinfo)
	{
		result_file << "query_sctx->GetCollation(\"http://www.flworfound.org/apitest/coll1\") failed" << endl;
	}
	else
	{
		result_file << "query_sctx->GetCollation(\"http://www.flworfound.org/apitest/coll1\") success " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (unsigned int)colinfo->coll << endl;
	}

	result_file << "dctx->SetVariable" << endl;
	dctx->SetVariable("varx", (long long)-134);

	result_file << "query->execute" << endl;
	query_result = query->execute();
	if(query_result.isNull())
	{
		goto DisplayErrorsAndExit;
	}
	result_file << "serializeXML" << endl;
	if(!query_result->serializeXML(result_file))
		result_file << endl << "error serializing the result ! " << endl;

	result_file << endl;
	result_file << "end easy api test" << endl;

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(make_absolute_file_name(result_file_name, __FILE__),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	DisplayErrorListForCurrentThread(result_file);

	result_file << "end easy api test" << endl;

	assert(false);
	return -1; 
}

//for CTEST
int easy_test(int argc, char* argv[])
{
	return test_easy_api("easy_test.txt");
}
