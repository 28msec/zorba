#include <zorba/zorba_api.h>
#include <fstream>
//#include "../error_display.h"
#ifdef HAVE_PTHREAD_H
# include <pthread.h>
#else
# include "win32_pthread/pthread.h"
#endif

#include <assert.h>

using namespace std;
using namespace zorba;

string make_absolute_file_name(const char *result_file_name, const char *this_file_name);
bool verify_expected_result(string result_file_name, string expected_file);
void DisplayErrorListForCurrentThread(std::ostream &result_file);

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
	ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();
  zorba_factory->shutdown();
  zorba_factory = ZorbaEngine::getInstance();

	zorba_factory->initThread();
	query = zorba_factory->createQuery("1+2");
  if(query == NULL)
  {
		zorba_factory->uninitThread();
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
	int32_t			thread_result_total = 0;

	for(i=0;i<NR_THREADS;i++)
	{
		pthread_join(pt[i], &thread_result);
		thread_result_total += (int32_t)thread_result;
	}
	zorba_factory->uninitThread();
	zorba_factory->shutdown();

	cout << "compare expected results" << endl;

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

		assert(verify_expected_result(oss.str().c_str(),
																make_absolute_file_name(oss2.str().c_str(), __FILE__)));
	}

	return (int)thread_result_total;
}


void* query_thread(void *param)
{
	QUERY_THREAD_PARAM	*query_param = (QUERY_THREAD_PARAM*)param;
	ofstream		result_file(query_param->result_file_name.c_str());
	unsigned int		i;
	unsigned int	max;
  XQuery_t    prev_query;


	///now start the zorba engine
	ZorbaEngine_t zorba_factory = ZorbaEngine::getInstance();

	result_file << "InitThread" << endl;
	zorba_factory->initThread();


	//do the test
	prev_query = query_param->query->clone();
	prev_query->initExecution();
	for(i=0;i<100;i++)
	{
		XQuery_t    query;
	//	XQueryExecution_t   execution;
		DynamicQueryContext_t    dctx1;

		// create a compiled query
		result_file << "CreateQuery" << endl;
		query = zorba_factory->createQuery("2+3");
		if(query == NULL)
		{
			goto DisplayErrorsAndExit;
		}

		dctx1 = zorba_factory->createDynamicContext();

		result_file << "CreateExecution" << endl;
		if(!query->initExecution(dctx1))
		{
			goto DisplayErrorsAndExit;
		}
		ResultIterator_t	prev_result = prev_query->getIterator();
		if(!query->setVariableAsXQueryResult("external_var_name", prev_result))
		{
			result_file << "SetVariable with prev_execution FAILED" << endl;
		}
		else
		{
			result_file << "SetVariable with prev_execution succeeded" << endl;
		}
		prev_query = query;
	}

	result_file << "serialize" << endl;
  prev_query->serializeXML(result_file);
	result_file << endl;
	if(prev_query->isError())
  {
    goto DisplayErrorsAndExit;
  }


	result_file << "UninitThread" << endl;
	zorba_factory->uninitThread();

	delete query_param;
	return (void*)0;

DisplayErrorsAndExit:
	result_file << endl << "Display all error list now:" << endl;

	zorba_factory->getAlertsManagerForCurrentThread()->dumpAlerts(result_file);

	result_file << "UninitThread" << endl;
	zorba_factory->uninitThread();

	delete query_param;
	return (void*)-1; 
}


//for CTEST
int query_multithread_test(int argc, char* argv[])
{
//	ZorbaEngine_t engine = ZorbaEngine::getInstance();
	test_api_query_multithread("query_mt_test");//0,1,2,3...19.txt
//	engine.shutdown();
	return 0;
}
