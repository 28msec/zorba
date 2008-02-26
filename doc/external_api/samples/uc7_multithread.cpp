
#include <zorba/zorba_api.h>
#ifdef HAVE_PTHREAD_H
# include <pthread.h>
#else
# include "win32_pthread/pthread.h"
#endif

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in full api mode.
	Init the engine, create a query in main thread and execute it in parallel threads.
	This way we optimize on compiling time.
	The xquery from main thread is cloned in the parallel threads.
  Each function is checked for errors. No try catch mechanism is demonstrated here.
*/

void* query_thread(void *param);
string make_absolute_file_name(const char *target_file_name, const char *this_file_name);

#define				NR_THREADS		20

static XQuery_t				xquery;

int uc7_multithread(int argc, char* argv[])
{
	//init the engine in full api mode
	ZorbaEngine_t		zorba_engine = ZorbaEngine::getInstance();
	unsigned int		i;
	pthread_t		pt[NR_THREADS];

  //ensure the single thread engine is shutdown
  zorba_engine->shutdown();
  zorba_engine = ZorbaEngine::getInstance();

	//in full api mode you have to call initThread() / uninitThread()
	zorba_engine->initThread();

	//create and compile a query with the static context
	xquery = zorba_engine->createQuery("declare variable $var1 external; .//chapter[@id=$var1]");
	if(xquery == NULL)
	{
		cout << "Error creating and compiling query1" << endl;
		exit(1);
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
	zorba_engine->uninitThread();
	zorba_engine->shutdown();

	return 0;
}

void* query_thread(void *param)
{
	//ZorbaEngine::getInstance can be called at any time
	//only first call initializes the engine
	ZorbaEngine_t		zorba_engine = ZorbaEngine::getInstance();
	DynamicQueryContext_t		dctx;
	unsigned int			iparam = (unsigned int)param;
	XQuery_t				xquery_clone;

	//must call initThread before using any of Zorba features (other than getInstance())
	zorba_engine->initThread();

	xquery_clone = xquery->clone();
	if(xquery_clone == NULL)
	{
		cout << "cannot clone xquery object" << endl;
		exit(1);
		zorba_engine->uninitThread();
		return (void*)1;
	}

	XmlDataManager_t		zorba_store = zorba_engine->getXmlDataManager();

	//load a document into xml data manager
	//and then load it into a variable
	zorba_store->loadDocument(make_absolute_file_name("books.xml", __FILE__));

	dctx = zorba_engine->createDynamicContext();
	//context item is set as variable with reserved name "."
	if(!dctx->setContextItemAsDocument(make_absolute_file_name("books.xml", __FILE__)))
	{
		cout << "cannot load document into context item" << endl;
		exit(1);
		zorba_engine->uninitThread();
		return (void*)1;
	}
	if(!dctx->setVariableAsInt("var1", iparam))
	{
		cout << "cannot set var1 to iparam " << iparam << endl;
		exit(1);
		zorba_engine->uninitThread();
		return (void*)1;
	}

	//execute the query and serialize its result
	if(!xquery_clone->initExecution(dctx) ||
		!xquery_clone->serializeXML(std::cout))//output will be a little scrammbled
	{
		cout << "Error executing and serializing query" << endl;
		exit(1);
		zorba_engine->uninitThread();
		return (void*)1;
	}

	//must uninit the thread
	zorba_engine->uninitThread();
	//using zorba objects after this moment is prohibited

	return (void*)0;
}
