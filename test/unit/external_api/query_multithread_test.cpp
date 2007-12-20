#include "zorba/zorba_api.h"
#include <fstream>
//#include "../error_display.h"
#include <pthread.h>

#include <assert.h>

using namespace std;
using namespace xqp;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);

void* query_thread( void *param );

typedef struct
{
  XQuery_t    query;
	std::string	result_file_name;
}QUERY_THREAD_PARAM;

#define				NR_THREADS		20

int test_api_query_multithread(const char *result_file_name)
{
	unsigned int		i;
	pthread_t		pt[NR_THREADS];

  XQuery_t    query;
	ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

	zorba_factory.InitThread();
	query = zorba_factory.createQuery("1+2");
  if(query.isNull())
  {
		zorba_factory.UninitThread();
		return 0;
  }
	//now execute this query in paralel in 20 threads

	for(i=0;i<NR_THREADS;i++)
	{
		ostringstream		oss;
		oss << result_file_name;
		oss << i;
		oss << ".txt";
		QUERY_THREAD_PARAM		*param;
		param = new QUERY_THREAD_PARAM;
		param->query = query;
		param->result_file_name = oss.str();
	
		pthread_create(&pt[i], NULL, query_thread, param);
	}

	void	*thread_result;
	int			thread_result_total = 0;

	for(i=0;i<NR_THREADS;i++)
	{
		pthread_join(pt[i], &thread_result);
		thread_result_total += (int)thread_result;
	}
	zorba_factory.UninitThread();

	//compare the results with expected result
	ostringstream		oss2;
	oss2 << "expected_";
	oss2 << result_file_name;
	oss2 << ".txt";
	for(i=0;i<NR_THREADS;i++)
	{
		ostringstream		oss;
		oss << result_file_name;
		oss << i;
		oss << ".txt";

		ifstream		ithreadfile(make_absolute_file_name(oss.str().c_str(), __FILE__).c_str());
		ifstream		ifexpected(make_absolute_file_name(oss2.str().c_str(), __FILE__).c_str());
		string			str_thread;
		string			str_expected;
		string			temp;
    // warning: this method of reading a file might trim the 
    // whitespace at the end of lines
    while (getline(ithreadfile, temp))
    {
      if (str_thread != "")
        str_thread += "\n";
      
      str_thread += temp;
    }      
    while (getline(ifexpected, temp))
    {
      if (str_expected != "")
        str_expected += "\n";
      
      str_expected += temp;
    }      
		assert(str_thread == str_expected);
	}

	return thread_result_total;
}

void* query_thread( void *param )
{
	QUERY_THREAD_PARAM	*query_param = (QUERY_THREAD_PARAM*)param;
	ofstream		result_file(make_absolute_file_name(query_param->result_file_name.c_str(), __FILE__).c_str());
	unsigned int		i;
	unsigned int	max;
  XQueryExecution_t    prev_execution;


	///now start the zorba engine
	ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

	result_file << "InitThread" << endl;
	zorba_factory.InitThread();


	//do the test
	prev_execution = query_param->query->createExecution();
	for(i=0;i<100;i++)
	{
		XQuery_t    query;
		XQueryExecution_t   execution;
		DynamicQueryContext_t    dctx1;

		// create a compiled query
		result_file << "CreateQuery" << endl;
		query = zorba_factory.createQuery("2+3");
		if(query.isNull())
		{
			goto DisplayErrorsAndExit;
		}

		dctx1 = zorba_factory.createDynamicContext();

		result_file << "CreateExecution" << endl;
		execution = query->createExecution(dctx1);
		if(execution.isNull())
		{
			goto DisplayErrorsAndExit;
		}
		execution->SetVariable("external_var_name", prev_execution);
		prev_execution = execution;
	}

	result_file << "serialize" << endl;
  prev_execution->serializeXML(result_file);
	result_file << endl;
	if(prev_execution->isError())
  {
    goto DisplayErrorsAndExit;
  }


	result_file << "UninitThread" << endl;
	zorba_factory.UninitThread();

	delete query_param;
	return (void*)0;

DisplayErrorsAndExit:
	cerr << endl << "Display all error list now:" << endl;

	//DisplayErrorListForCurrentThread();

	result_file << "UninitThread" << endl;
	zorba_factory.UninitThread();

	delete query_param;
	return (void*)-1; 
}

//for CTEST
int query_multithread_test(int argc, char* argv[])
{
	ZorbaEngine::startupZorbaEngine();
	test_api_query_multithread("query_mt_test");//0,1,2,3...19.txt
	ZorbaEngine::shutdownZorbaEngine();
	return 0;
}
