///Created: Daniel Turcanu @ IPDevel 

#ifndef XQP_ZORBA_H
#define XQP_ZORBA_H

#include "util/rchandle.h"

#ifdef WIN32
#include "util/win32/compatib_defs.h"
#endif

#include <unicode/utypes.h>
#include <unicode/coll.h>
#include <unicode/ustring.h>
#include "store/api/item_factory.h"
#include "store/api/store.h"

#include "compiler/parser/location.hh"

#include <stack>
#include <map>
#ifdef WIN32
#include <windows.h>
#include "win32/pthread.h"
#endif

namespace xqp {

class ItemFactory;
class Zorba_XQueryBinary;
class PlanIterator;
class error_messages;
class Store;
class static_context;
class ZorbaAlertsManagerImpl;
class Zorba_XQueryExecution;
class serializer;
class CollationManager;


///Thread Local Storage: this object is global specific to each thread
class zorba
{
	friend class ZorbaEngine;

public:
	static Store				* theStore;
	static ItemFactory	* theItemFactory;
	static yy::location	  null_loc;
	
public:///things specific for each thread
	Zorba_XQueryBinary              * current_xquery;//current xquery executed for this thread
	Zorba_XQueryExecution           * current_xqueryresult;
	std::stack<const PlanIterator*>	  current_iterator;
	CollationManager                * coll_manager;

	std::string                       default_coll_string;
	::Collator::ECollationStrength    default_coll_strength;
	bool					                    is_user_set_coll;
	::Collator		                  * default_coll;

protected:
	ZorbaAlertsManagerImpl          * m_error_manager;

	serializer                      * m_item_serializer;///specific for serializing items
	serializer                      * m_doc_serializer;///specific for serializing complete xml

protected:

#ifdef WIN32
	static DWORD		                  tls_key;
#elif defined ZORBA_FOR_ONE_THREAD_ONLY
#elif defined ZORBA_USE_PTHREAD_LIBRARY
	static pthread_key_t		          tls_key;
	void static zorba_tls_destructor(void *tls_data);
#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY
	static thread_specific_ptr<zorba> tls_key;
#else
	static std::map<uint64_t, zorba*>	global_zorbas;
	static pthread_mutex_t						global_zorbas_mutex;
#endif

	///functions for accessing global zorba objects for each thread
protected:
	zorba();
	~zorba();

public:
  static inline ItemFactory* getItemFactory() { return theItemFactory; }
  static inline Store* getStore() { return theStore; }

public:
	ZorbaAlertsManagerImpl* getErrorManager();

	::Collator* getCollator(xqp_string collURI = "");

	yy::location& GetCurrentLocation();//from top iterator
	
	void setDefaultCollation(
        std::string  coll_string,
        ::Collator::ECollationStrength coll_strength = ::Collator::PRIMARY);

	void setDefaultCollation(::Collator *default_coll);

	void getDefaultCollation(
        std::string  *coll_string,
        ::Collator::ECollationStrength *coll_strength,
        ::Collator **default_coll);

	static_context* get_static_context();///of the current xquery

	serializer	*getItemSerializer();
	serializer	*getDocSerializer();

protected:
	static void initializeZorbaEngine_internal();//Store& store);
//	static void initializeThread_internal(zorba *new_zorba, 
//																			error_messages *em,
//																			char *collator_name,///="root"
//																			::Collator::ECollationStrength collator_strength);//=Collator::PRIMARY
	static void uninitializeZorbaEngine_internal();
public:
	static void		initializeZorbaEngine();//Store& store);
	static void		uninitializeZorbaEngine();

	static zorba* getZorbaForCurrentThread();
	
	static zorba*	allocateZorbaForCurrentThread();
	static void		destroyZorbaForCurrentThread();//when ending the thread

};

}	/* namespace xqp */
#endif /*	XQP_ZORBA_H */

