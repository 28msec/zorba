
#ifndef SYSTEM_ZORBA_ENGINE
#define SYSTEM_ZORBA_ENGINE

#define ZORBA_USE_PTHREAD_LIBRARY

#include "store/api/store_api.h"
#include "system/zorba_engine_api.h"

namespace xqp
{

class Zorba;
class XmlDataManager_Impl;

/*daniel: getInstance cannot be called by system after user calls shutdown()
this generates memory leaks

#define ZORBA_FOR_CURRENT_THREAD()                             \
  static_cast<ZorbaEngineImpl*>(&ZorbaEngine::getInstance())-> \
    getZorbaForCurrentThread()
*/

Zorba* ZORBA_FOR_CURRENT_THREAD();

/*******************************************************************************

  theThreadData      : The container of the per-thread global data. The global
                       data of each thread are encapsulated in instances of the
                       zorba class, so theThreadData actually contains one zorba
                       object per thread. The implementation of this container
                       differs according to the operating systme and/or the
                       thread library used.
  theThreadDataMutex : Semaphore to protect theThreadData, when this is not
                       done automatically by the underlying thread library.

********************************************************************************/
class ZorbaEngineImpl : public ZorbaSingleThread, public ZorbaEngine
{
private:

#ifdef WIN32
  DWORD                      theThreadData;

#elif defined ZORBA_FOR_ONE_THREAD_ONLY
  Zorba*                    theThreadData;

#elif defined ZORBA_USE_PTHREAD_LIBRARY

  pthread_key_t		           theThreadData;

#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY

  thread_specific_ptr<zorba> theThreadData;

#else
  std::map<uint64_t, Zorba*> theThreadData;
  pthread_mutex_t						 theThreadDataMutex;
#endif

	//the store wrapper
	XmlDataManager_Impl		*xml_data_manager;
	bool									for_single_thread_api;
	Zorba									*theSingleThreadZorba;

public:
	ZorbaEngineImpl(bool single_thread);

  ~ZorbaEngineImpl();

  void initialize();

  void shutdown();

	void initThread();

	void uninitThread();

  Zorba* getZorbaForCurrentThread();

  XQuery_t createQuery(
        xqp_string aQueryString,
        StaticQueryContext_t = 0, 
				xqp_string	xquery_source_uri = "",
        bool routing_mode = false);

  virtual XQuery_t createQueryFromFile(
        xqp_string xquery_file,
        StaticQueryContext_t = 0, 
        bool routing_mode = false);

	ZorbaAlertsManager& getAlertsManagerForCurrentThread();

	void setDefaultCollation(
        std::string coll_string,
        ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);

	void setDefaultCollation(::Collator *default_coll);

	void getDefaultCollation(
        std::string* coll_string,
        ::Collator::ECollationStrength* coll_strength,
        ::Collator** default_coll);

	void setItemSerializerParameter(xqp_string parameter_name, xqp_string value);
	void setDocSerializerParameter(xqp_string parameter_name, xqp_string value);

	StaticQueryContext_t createStaticContext();
	DynamicQueryContext_t createDynamicContext();

	virtual	XmlDataManager_t		getXmlDataManager();

protected:
#if defined ZORBA_USE_PTHREAD_LIBRARY
	static void threadDataDestructor(void *data);
#endif
};



}//end namespace xqp

#endif

