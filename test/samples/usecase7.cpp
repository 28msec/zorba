
#include "zorba/zorba_api.h"
#include <pthread.h>

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in full api mode.
	Init the engine, create a query in main thread and execute it in parallel threads.
	This way we optimize on compiling time.
*/

void DisplayErrorListForCurrentThread(std::ostream &result_file);
void* query_thread(void *param);

#define				NR_THREADS		20

static XQuery_t				xquery;

int usecase7(int argc, char* argv[])
{
	//init the engine in full api mode
	ZorbaEngine		&zorba_engine = ZorbaEngine::getInstance();
	unsigned int		i;
	pthread_t		pt[NR_THREADS];

	///in full api mode you have to call initThread() / uninitThread()
	zorba_engine.initThread();

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery(".//chapter[@id=$var1]");
	if(xquery.isNull())
	{
		cout << "Error creating and compiling query1" << endl;
		assert(false);
		return 1;
	}


	for(i=0;i<NR_THREADS;i++)
	{
		pthread_create(&pt[i], NULL, query_thread, (void*)i);
	}

	///now wait for threads to finish
	for(i=0;i<NR_THREADS;i++)
	{
		void	*thread_result;
		pthread_join(pt[i], &thread_result);
	}
	
	//close the engine for this thread and shutdown completely
	zorba_engine.uninitThread();
	zorba_engine.shutdown();

	return 0;
}

void* query_thread(void *param)
{
	//ZorbaEngine::getInstance can be called at any time
	//only first call initializes the engine
	ZorbaEngine		&zorba_engine = ZorbaEngine::getInstance();
	DynamicQueryContext_t		dctx;
	unsigned int			iparam = (unsigned int)param;

	//must call initThread before using any of Zorba features (other than getInstance())
	zorba_engine.initThread();
	dctx = zorba_engine.createDynamicContext();
	//context item is set as variable with reserved name "."
	if(!dctx->SetVariableAsDocument(".", "books.xml"))
	{
		cout << "cannot load document into context item" << endl;
		assert(false);
		return (void*)1;
	}
	if(!dctx->SetVariableAsInteger("var1", iparam))
	{
		cout << "cannot set var1 to iparam " << iparam << endl;
		assert(false);
		return (void*)1;
	}

	//execute the query and serialize its result
	if(!xquery->executeSerializeXML(std::cout, dctx))//output will be a little scrammbled
	{
		cout << "Error executing and serializing query" << endl;
		assert(false);
		return (void*)1;
	}

	//must uninit the thread
	zorba_engine.uninitThread();
	//using zorba objects after this moment is prohibited

	return (void*)0;
}
