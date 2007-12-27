///Created: Daniel Turcanu @ IPDevel 

#ifdef WIN32
#include <windows.h>
#include "win32/compatib_defs.h"
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

namespace xqp{


ZorbaEngineImpl* globalZorbaEngine = NULL;


void library_init();


ZorbaEngine& ZorbaEngine::getInstance()
{
	if(!globalZorbaEngine)
	{
		globalZorbaEngine = new ZorbaEngineImpl;
		globalZorbaEngine->initialize();
	}
	return *globalZorbaEngine;
}


ZorbaEngineImpl::ZorbaEngineImpl()
{
}


ZorbaEngineImpl::~ZorbaEngineImpl()
{
  assert(globalZorbaEngine == NULL);
}


void ZorbaEngineImpl::initialize()
{
#ifdef WIN32
  theThreadData = TlsAlloc();

#elif defined ZORBA_USE_PTHREAD_LIBRARY
  pthread_key_create(&theThreadData, NULL);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
  theThreadData = new Zorba();

#else
  pthread_mutex_init(&theThreadDataMutex, NULL);

#endif

	static_context::init();
	dynamic_context::init();
	library_init();

	///optimize access to store
  Zorba::theStore = &Store::getInstance();
  Zorba::theItemFactory = &Zorba::theStore->getItemFactory();
}


void ZorbaEngineImpl::shutdown()
{
  if (globalZorbaEngine != NULL)
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

    Zorba::theStore = NULL;
    Zorba::theItemFactory = NULL;

    ZorbaEngineImpl* temp = globalZorbaEngine;
    globalZorbaEngine = NULL;
    delete temp;
  }
}


void ZorbaEngineImpl::initThread(AlertCodes* codes)
{
	Zorba* zorba = this->getZorbaForCurrentThread();

	if(zorba == 0)
  {
    zorba = new Zorba();

#ifdef WIN32
    TlsSetValue(theThreadData, zorba);

#elif defined ZORBA_USE_PTHREAD_LIBRARY
    pthread_setspecific(theThreadData, zorba);

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
    theThreadData = zorba;

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
    Assert(0);

#else
    pthread_mutex_lock(&theThreadDataMutex);
    theThreadData[(uint64_t)(uintptr_t)pthread_self()] = zorba;
    pthread_mutex_unlock(&theThreadDataMutex);
#endif

    if(!codes)
	  {
      errors_english* codes = new errors_english;
      zorba->m_error_manager->setAlertCodes(codes);
    }
    else
    {
      zorba->m_error_manager->setAlertCodes(codes);
    }
  }
}


void ZorbaEngineImpl::uninitThread()
{
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

#else
	pthread_mutex_lock(&theThreadDataMutex);
	theThreadData.erase((uint64_t)(uintptr_t)pthread_self());
	pthread_mutex_unlock(&theThreadDataMutex);
#endif
}


Zorba* ZorbaEngineImpl::getZorbaForCurrentThread()
{
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
  std::auto_ptr<Zorba_XQueryBinary> xq(new Zorba_XQueryBinary(xquery_source_uri,
                                                              aQueryString));
	if (!xq->compile(sctx.get_ptr(), routing_mode))
	{
		return NULL;
	}

	return xq.release();
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
	getZorbaForCurrentThread()->setDefaultCollation(coll_string, coll_strength);
}


void ZorbaEngineImpl::setDefaultCollation(::Collator *default_coll)
{
	getZorbaForCurrentThread()->setDefaultCollation(default_coll);
}


void ZorbaEngineImpl::getDefaultCollation(
    std::string  *coll_string,
    ::Collator::ECollationStrength *coll_strength,
    ::Collator **default_coll)
{
	getZorbaForCurrentThread()->
    getDefaultCollation(coll_string, coll_strength, default_coll);
}


void	ZorbaEngineImpl::setItemSerializerParameter(
    xqp_string parameter_name,
    xqp_string value)
{
	getZorbaForCurrentThread()->
    getItemSerializer()->set_parameter(parameter_name, value);
}


void	ZorbaEngineImpl::setDocSerializerParameter(
    xqp_string parameter_name,
    xqp_string value)
{
	getZorbaForCurrentThread()->
    getDocSerializer()->set_parameter(parameter_name, value);
}


StaticQueryContext_t ZorbaEngineImpl::createStaticContext()
{
	return new StaticContextWrapper;
}


DynamicQueryContext_t ZorbaEngineImpl::createDynamicContext()
{
	return new DynamicContextWrapper;
}

}//end namespace xqp
