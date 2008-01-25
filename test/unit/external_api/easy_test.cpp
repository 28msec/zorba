#include "zorba/zorba_singlethread.h"
#include <fstream>
#include <assert.h>
//#include "../error_display.h"

//needed to call shutdown on single thread engine
#include "zorba/zorba_api.h"

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);

int test_easy_api(const char *result_file_name)
{
	ofstream		result_file(make_absolute_file_name(result_file_name, __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
	ostringstream		oss2;

	ZorbaSingleThread& zorba_factory = ZorbaSingleThread::getInstance();

	XQuery_t		query;
	StaticQueryContext_t		sctx;
	DynamicQueryContext_t		dctx;
//	XQueryExecution_t		query_result;
	CollationInfo	*colinfo = NULL;

	result_file << "zorba_factory.createStaticContext()" << endl;
	sctx = zorba_factory.createStaticContext();
	if(sctx == NULL)
	{
		goto DisplayErrorsAndExit;
	}
	result_file << "zorba_factory.createDynamicContext()" << endl;
	dctx = zorba_factory.createDynamicContext();
	if(dctx == NULL)
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
		result_file << "query_sctx->GetCollation(\"http://www.flworfound.org/apitest/coll1\") success " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (uint32_t)colinfo->coll << endl;
	}

	result_file << "zorba_factory.createQuery()" << endl;
  query = zorba_factory.createQuery("1+2", sctx, "file://query.txt");
	if(query == NULL)
	{
		goto DisplayErrorsAndExit;
	}

	

	result_file << "dctx->SetVariable" << endl;
	dctx->SetVariableAsInteger("varx", (long long)-134);

	result_file << "query->executeSerializeXML" << endl;
	if(!query->initExecution(dctx) ||
		!query->serializeXML(result_file))
	{
		result_file << endl << "error serializing the result ! " << endl;
		goto DisplayErrorsAndExit;
	}

	result_file << endl;
	result_file << "end easy api test" << endl;

	zorba_factory.shutdown();

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(make_absolute_file_name(result_file_name, __FILE__),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	zorba_factory.getAlertsManagerForCurrentThread().DumpAlerts(result_file);

	result_file << "end easy api test" << endl;

	assert(false);
	return -1; 
}

//for CTEST
int easy_test(int argc, char* argv[])
{
	return test_easy_api("easy_test.txt");
}
