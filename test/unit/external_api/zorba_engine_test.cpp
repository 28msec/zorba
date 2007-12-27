#include "zorba/zorba_api.h"
#include <fstream>
//#include "../error_display.h"
#include <assert.h>

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);

int test_api_zorba_engine(const char *result_file_name)
{
	ofstream		result_file(make_absolute_file_name(result_file_name, __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
	ostringstream	oss2;
	CollationInfo	*colinfo = NULL;

	for(i=0;i<100;i++)
	{
		ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();
		///thread specific
		zorba_factory.initThread();
		zorba_factory.uninitThread();
	}

	///now start the zorba engine
	ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

	zorba_factory.initThread();

	result_file << "InitThread" << endl;

	//do the test
	ZorbaAlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();
  StaticQueryContext_t    sctx1;

  sctx1 = zorba_factory.createStaticContext();
  sctx1 = zorba_factory.createStaticContext();
  sctx1 = zorba_factory.createStaticContext();
	result_file << "createStaticContext()" << endl;
  sctx1->AddCollation("http://www.flworfound.org/apitest/coll1", "en");
	result_file << "AddCollation" << endl;

	zorba_factory.setDefaultCollation("en");
	std::string	def_coll_str;
	::Collator::ECollationStrength def_coll_strength;
	::Collator *default_coll;
	zorba_factory.getDefaultCollation(&def_coll_str, &def_coll_strength, &default_coll);
	assert(default_coll == NULL);
	result_file << "zorba engine default collation" << def_coll_str << "," << def_coll_strength << "," << endl;


  XQuery_t    query;
  XQueryExecution_t   result;
  Item_t    it;
	std::string		query_text = "1+2";
  DynamicQueryContext_t    dctx1;
	StaticQueryContext_t		query_sctx;

  // create a compiled query
  query = zorba_factory.createQuery(query_text.c_str(), sctx1);
  query = zorba_factory.createQuery(query_text.c_str(), sctx1);
  query = zorba_factory.createQuery(query_text.c_str(), sctx1);
	result_file << "CreateQuery" << endl;

  if(query.isNull())
  {
    goto DisplayErrorsAndExit;
  }

	query_sctx = query->getInternalStaticContext();
	colinfo = query_sctx->GetCollation("http://www.flworfound.org/apitest/coll1");
	if(!colinfo)
	{
		result_file << "query_sctx->GetCollation(\"http://www.flworfound.org/apitest/coll1\") failed" << endl;
	}
	else
	{
		result_file << "query_sctx->GetCollation(\"http://www.flworfound.org/apitest/coll1\") success " << (std::string)colinfo->URI << " " << colinfo->coll_string << " " << colinfo->coll_strength << " " << (unsigned int)colinfo->coll << endl;
	}
	


  dctx1 = zorba_factory.createDynamicContext();

  result = query->createExecution(dctx1);
  result = query->createExecution(dctx1);
	result_file << "CreateExecution" << endl;
  if(result.isNull())
  {
    goto DisplayErrorsAndExit;
  }

	{
		ifstream		xml_stream(make_absolute_file_name("test_xml.txt", __FILE__).c_str());
		if(!xml_stream.is_open() || !result->SetVariable("var2", xml_stream))
		{
			result_file << "SetVariable with istream failed" << endl;
			result_file << "file test_xml.txt exists: " << xml_stream.is_open() << endl;
		}
		else
		{
			result_file << "SetVariable with istream succeeded" << endl;
		}
	}

	result_file << "serialize" << endl;
  result->serialize(result_file);
  if(result->isError())
  {
    goto DisplayErrorsAndExit;
  }





	zorba_factory.uninitThread();
	result_file << endl;
	result_file << "UninitThread" << endl;

	//compare the results with expected result
	oss2 << "expected_";
	oss2 << result_file_name;
	assert(verify_expected_result(make_absolute_file_name(result_file_name, __FILE__),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	return 0;

DisplayErrorsAndExit:
	cerr << endl << "Display all error list now:" << endl;

	//DisplayErrorListForCurrentThread();

	zorba_factory.uninitThread();

	assert(false);
	return -1; 
}

//for CTEST
int zorba_engine_test(int argc, char* argv[])
{
  ZorbaEngine& engine = ZorbaEngine::getInstance();
	test_api_zorba_engine("zorba_engine_test.txt");
	engine.shutdown();
	return 0;
}
