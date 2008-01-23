///Created: Daniel Turcanu @ IPDevel 

#ifdef WIN32
#include <windows.h>
#include "util/win32/compatib_defs.h"
#endif

#ifdef ZORBA_USE_PTHREAD_LIBRARY
#include <pthread.h>
#endif

#ifdef ZORBA_USE_BOOST_THREAD_LIBRARY
#include <boost/thread/tss.hpp>
#endif

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "errors/error_messages.h"
#include "errors/error_manager.h"

#include "system/globalenv.h"
#include "system/zorba_engine.h"
#include "system/zorba.h"

#include "api/external/xquery.h"
#include "api/external/static_context_wrapper.h"
#include "api/external/dynamic_context_wrapper.h"
#include "api/serialization/serializer.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "api/external/xmldatamanager_impl.h"

namespace xqp{


rchandle<ZorbaEngineImpl>	 globalZorbaEngine = NULL;


void library_init();


ZorbaEngine& ZorbaEngine::getInstance()
{
	if(globalZorbaEngine == NULL)
	{
		globalZorbaEngine = new ZorbaEngineImpl(false);
		globalZorbaEngine->initialize();
        GlobalEnvironment::getInstance();
	}
	return *globalZorbaEngine;
}

ZorbaSingleThread& ZorbaSingleThread::getInstance()
{
	if(globalZorbaEngine == NULL)
	{
		globalZorbaEngine = new ZorbaEngineImpl(true);//single thread
		globalZorbaEngine->initialize();
		globalZorbaEngine->initThread();
	}
	return *globalZorbaEngine;
}

Zorba* ZORBA_FOR_CURRENT_THREAD()
{
	if(globalZorbaEngine == NULL)
		return NULL;
	return globalZorbaEngine->getZorbaForCurrentThread();
}

ZorbaEngineImpl::ZorbaEngineImpl(bool single_thread)
{
	for_single_thread_api = single_thread;
	theSingleThreadZorba = NULL;
	xml_data_manager = new XmlDataManager_Impl;
	xml_data_manager->addReference();
}


ZorbaEngineImpl::~ZorbaEngineImpl()
{
	try{
	xml_data_manager->removeReference();
//  assert(globalZorbaEngine == NULL);
	delete theSingleThreadZorba;

	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::initialize()
{
	try{
	if(!for_single_thread_api)
	{
#ifdef WIN32
  theThreadData = TlsAlloc();

#elif defined ZORBA_USE_PTHREAD_LIBRARY
  pthread_key_create(&theThreadData, NULL);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
  theThreadData = NULL;//new Zorba();

#else
  pthread_mutex_init(&theThreadDataMutex, NULL);

#endif
	}//end if(for_single_thread_api)

	static_context::init();
	dynamic_context::init();
	library_init();

	///optimize access to store
  Zorba::theStore = &Store::getInstance();
  Zorba::theItemFactory = &Zorba::theStore->getItemFactory();
  GlobalEnvironment::getInstance();

	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::shutdown()
{
	try{
  if (globalZorbaEngine != NULL)
  {
		if(!for_single_thread_api)
		{
#ifdef WIN32
    TlsFree(theThreadData);
    theThreadData = 0;

#elif defined ZORBA_USE_PTHREAD_LIBRARY
    pthread_key_delete(theThreadData);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
    delete theThreadData;
    theThreadData = 0;

#else
    pthread_mutex_destroy(&theThreadDataMutex);

#endif
		}//end if (for_single_thread_api)

    GlobalEnvironment::destroy();
		Zorba::theStore = NULL;
    Zorba::theItemFactory = NULL;

  //  ZorbaEngineImpl* temp = globalZorbaEngine;
  //  globalZorbaEngine = NULL;
  //  delete temp;
		globalZorbaEngine = NULL;//also deletes globalZorbaEngine
  }
	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::initThread()
{
	try{
	Zorba* zorba = this->getZorbaForCurrentThread();

	if(zorba == 0)
  {
		zorba = new Zorba();

		if(!for_single_thread_api)
		{
#ifdef WIN32
    TlsSetValue(theThreadData, zorba);

#elif defined ZORBA_USE_PTHREAD_LIBRARY
    pthread_setspecific(theThreadData, zorba);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
    theThreadData = zorba;

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
    //Assert(0);
		theThreadData = zorba;

#else
    pthread_mutex_lock(&theThreadDataMutex);
    theThreadData[(uint64_t)(uintptr_t)pthread_self()] = zorba;
    pthread_mutex_unlock(&theThreadDataMutex);
#endif
		}
		else//if (!for_single_thread_api)
		{
			theSingleThreadZorba = zorba;
		}
  }
	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::uninitThread()
{
	try{
	if(for_single_thread_api)
		return;//ignore for single threaded

	Zorba* zorba = getZorbaForCurrentThread();

	if(zorba)
		delete zorba;

#ifdef WIN32
  TlsSetValue(theThreadData, NULL);

#elif defined ZORBA_USE_PTHREAD_LIBRARY
  pthread_setspecific(theThreadData, NULL);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
  theThreadData.release();

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
	theThdreadData = NULL;
#else
	pthread_mutex_lock(&theThreadDataMutex);
	theThreadData.erase((uint64_t)(uintptr_t)pthread_self());
	pthread_mutex_unlock(&theThreadDataMutex);
#endif
	}CATCH_ALL_NO_RETURN(;);
}


Zorba* ZorbaEngineImpl::getZorbaForCurrentThread()
{
	if(for_single_thread_api)
		return theSingleThreadZorba;

#ifdef WIN32
  return (Zorba*)TlsGetValue(theThreadData);

#elif defined ZORBA_USE_PTHREAD_LIBRARY
  return (Zorba*)pthread_getspecific(theThreadData);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
  return theThreadData.get();

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
  return theThreadData;

#else
  std::map<uint64_t, Zorba*>::iterator	it_zorba;

	pthread_mutex_lock(&theThreadDataMutex);
	it_zorba = theThreadData.find((uint64_t)(uintptr_t)pthread_self());
	if(it_zorba == theThreadData.end())
	{
    ///not found, big error
		pthread_mutex_unlock(&theThreadDataMutex);
		return NULL;
	}
	else
	{
    Zorba* zorba = (*it_zorba).second; 
		pthread_mutex_unlock(&theThreadDataMutex);
		return zorba;
	}

#endif
}


XQuery_t ZorbaEngineImpl::createQuery(
    const char* aQueryString,
    StaticQueryContext_t sctx, 
    xqp_string	xquery_source_uri,
    bool routing_mode)
{
	try{
  std::auto_ptr<Zorba_XQueryBinary> xq(new Zorba_XQueryBinary(xquery_source_uri,
                                                              aQueryString));
	if (!xq->compile(sctx.get_ptr(), routing_mode))
	{
		return NULL;
	}

	return xq.release();
	}CATCH_ALL_RETURN_NULL;
}

XQuery_t ZorbaEngineImpl::createQueryFromFile(
      xqp_string xquery_file,
      StaticQueryContext_t sctx,
      bool routing_mode)
{
	try{
	FILE	*fquery;
	size_t	fsize;
	char	*xquerydata;
	XQuery_t	result_query;

	fquery = fopen(xquery_file.c_str(), "r");
	if(!fquery)
	{
		return NULL;
	}
	if(fseek(fquery, 0, SEEK_END))
	{
		fclose(fquery);
		return NULL;
	}
	fsize = ftell(fquery);
	if(fsize <= 0)
	{
		fclose(fquery);
		return NULL;
	}
	fseek(fquery, 0, SEEK_SET);
	xquerydata = (char*)malloc(fsize);
	if(fread(xquerydata, 1, fsize, fquery) < fsize)
	{
		::free(xquerydata);
		fclose(fquery);
		return NULL;
	}
	fclose(fquery);

	result_query = createQuery(xquerydata, sctx, xquery_file, routing_mode);
	::free(xquerydata);
	
	return result_query;

	}CATCH_ALL_RETURN_NULL;
}

ZorbaAlertsManager& ZorbaEngineImpl::getAlertsManagerForCurrentThread()
{
	Zorba* z = getZorbaForCurrentThread();

	return *z->getErrorManager();
}


void ZorbaEngineImpl::setDefaultCollation(
    std::string  coll_string,
    ::Collator::ECollationStrength coll_strength)
{
	try{

	getZorbaForCurrentThread()->setDefaultCollation(coll_string, coll_strength);
	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::setDefaultCollation(::Collator *default_coll)
{
	try{
	getZorbaForCurrentThread()->setDefaultCollation(default_coll);
	}CATCH_ALL_NO_RETURN(;);
}


void ZorbaEngineImpl::getDefaultCollation(
    std::string  *coll_string,
    ::Collator::ECollationStrength *coll_strength,
    ::Collator **default_coll)
{
	try{
	getZorbaForCurrentThread()->
    getDefaultCollation(coll_string, coll_strength, default_coll);
	}CATCH_ALL_NO_RETURN(;);
}


void	ZorbaEngineImpl::setItemSerializerParameter(
    xqp_string parameter_name,
    xqp_string value)
{
	try{
	getZorbaForCurrentThread()->
    getItemSerializer()->set_parameter(parameter_name, value);
	}CATCH_ALL_NO_RETURN(;);
}


void	ZorbaEngineImpl::setDocSerializerParameter(
    xqp_string parameter_name,
    xqp_string value)
{
	try{
	getZorbaForCurrentThread()->
    getDocSerializer()->set_parameter(parameter_name, value);
	}CATCH_ALL_NO_RETURN(;);
}


StaticQueryContext_t ZorbaEngineImpl::createStaticContext()
{
	return new StaticContextWrapper;
}


DynamicQueryContext_t ZorbaEngineImpl::createDynamicContext()
{
	return new DynamicContextWrapper;
}

XmlDataManager_t		ZorbaEngineImpl::getXmlDataManager()
{
	return xml_data_manager;
}


}//end namespace xqp
