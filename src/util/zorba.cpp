///Created: Daniel Turcanu @ IPDevel 

#include <map>

#include "zorba_api.h"
#include "zorba.h"

#include "context/common.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "api/external/xquerybinary.h"
#include "errors/Error_impl.h"
#include "runtime/base/iterator.h"
#include "api/serialization/serializer.h"
#include "context/collation_manager.h"

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



using namespace std;
namespace xqp {

Store*				zorba::theStore = NULL;
ItemFactory	*	zorba::theItemFactory = NULL;
yy::location	zorba::null_loc;

void library_init();

zorba::zorba()
{
//	coll = NULL;
	current_xquery = NULL;
	current_xqueryresult = NULL;

	m_error_manager = new ZorbaErrorAlertsImpl;
	m_item_serializer = NULL;
	m_doc_serializer = NULL;
	coll_manager = new CollationManager;

	default_coll_string = "root";
	default_coll_strength = ::Collator::PRIMARY;
	is_user_set_coll = true;//do not try to free
	default_coll = NULL;
}


zorba::~zorba()
{
//	if(coll)
//		delete coll;

	delete m_error_manager;
	delete m_item_serializer;
	delete m_doc_serializer;
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	delete coll_manager;

}


///some common functions for TLS

void zorba::initializeZorbaEngine_internal()//Store& store)
{
	static_context::init();
	dynamic_context::init();
	library_init();

	///optimize access to store
	zorba::theStore = &Store::getInstance();
	zorba::theItemFactory = &theStore->getItemFactory();
}


void zorba::uninitializeZorbaEngine_internal()
{
	theStore = NULL;
}

void zorba::setDefaultCollation(std::string coll_string, ::Collator::ECollationStrength coll_strength)
{
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	default_coll_string = coll_string;
	default_coll_strength = coll_strength;
	is_user_set_coll = false;
	this->default_coll = NULL;
}

void		zorba::setDefaultCollation(::Collator *default_coll)
{
	if(!is_user_set_coll)
		coll_manager->removeReference(default_coll_string, default_coll_strength);
	is_user_set_coll = true;
	this->default_coll = default_coll;
}

void		zorba::getDefaultCollation(std::string  *coll_string, ::Collator::ECollationStrength *coll_strength, ::Collator **default_coll)
{
	*coll_string = default_coll_string;
	*coll_strength = default_coll_strength;
	*default_coll = this->default_coll;
}

::Collator	*zorba::getCollator(xqp_string collURI)
{
	if(!current_xquery)
	{//get the zorba default collation, or a hardcoded one
		if(!collURI.empty())
		{
			const CollationManager::COLLATION_DESCR		*coll_descr;
			coll_descr = CollationManager::getHardcodedCollator(collURI);
			if(!coll_descr)
			{
				ZORBA_ERROR_ALERT(error_messages::XQST0076, NULL);
				return NULL;
			}
			return coll_manager->getCollation(coll_descr->coll_string, coll_descr->coll_strength);
		}
		else
		{
			if(default_coll)
				return default_coll;
			default_coll = coll_manager->getCollation(default_coll_string, default_coll_strength);
			if(!default_coll)
			{
				ZORBA_ERROR_ALERT( error_messages::XQST0076, NULL);
				return NULL;
			}
			return default_coll;
		}
	}
	
	//redirect to static context wrapper from current_xquery
	if(collURI.empty())///get default collator
	{
		if(current_xquery->default_collator)
			return current_xquery->default_collator;
		current_xquery->default_collator = get_static_context()->getDefaultCollation();
		return current_xquery->default_collator;
	}
	else
		return get_static_context()->get_collation(collURI);

}

yy::location& zorba::GetCurrentLocation()//from top iterator
{
	if(current_iterator.empty())
		return null_loc;///no current location information
	else
		return (yy::location&)(current_iterator.top()->loc);
}


static_context* zorba::get_static_context()///of the current xquery
{
	if(!current_xquery)
		return NULL;
	return current_xquery->internal_sctx;
}

ZorbaErrorAlertsImpl* zorba::getErrorManager()
{ 
	return m_error_manager;
}

//library*	zorba::get_library()
//{
//	return &*theFunctionLibrary;
//}

serializer	*zorba::getItemSerializer()
{
	if(!m_item_serializer)
	{
		m_item_serializer = new serializer;
		m_item_serializer->set_parameter("omit-xml-declaration", "yes");
	}

	return m_item_serializer;
}

serializer	*zorba::getDocSerializer()
{
	if(!m_doc_serializer)
	{
		m_doc_serializer = new serializer;
	}

	return m_doc_serializer;
}


///define the Thread Specific Storage object zorba

#ifdef WIN32


DWORD		zorba::tls_key = 0;


void		
zorba::initializeZorbaEngine()//Store& store)
{
	zorba::tls_key = TlsAlloc();

	initializeZorbaEngine_internal();//store);

}

void		
zorba::uninitializeZorbaEngine()
{
	TlsFree(zorba::tls_key);
	zorba::tls_key = 0;

	uninitializeZorbaEngine_internal();
}

zorba* 
zorba::getZorbaForCurrentThread()
{
	return (zorba*)TlsGetValue( zorba::tls_key );
}

zorba*		
zorba::allocateZorbaForCurrentThread()
{
	zorba*	new_zorba;

	new_zorba = getZorbaForCurrentThread();
	if(new_zorba)
		return new_zorba;///thread already initialized
	new_zorba = new zorba();

	TlsSetValue( zorba::tls_key, new_zorba );


	return new_zorba;
}


void		
zorba::destroyZorbaForCurrentThread()//when ending the thread
{
	zorba *z;
	z = getZorbaForCurrentThread();
	if(z)
		delete z;
	TlsSetValue( zorba::tls_key, NULL );
}



#elif defined ZORBA_FOR_ONE_THREAD_ONLY


zorba		g_zorba;


void		
zorba::initializeZorbaEngine()//Store& store)
{
	initializeZorbaEngine_internal();//store);
}

void		
zorba::uninitializeZorbaEngine()
{
	uninitializeZorbaEngine_internal();
}

zorba* 
zorba::getZorbaForCurrentThread()
{
	return &g_zorba;
}

zorba*		
zorba::allocateZorbaForCurrentThread()
{
	return &g_zorba;
}


void		
zorba::destroyZorbaForCurrentThread()//when ending the thread
{
}



#elif defined ZORBA_USE_PTHREAD_LIBRARY


pthread_key_t		zorba::tls_key;

///called automatically by pthreads when ending the thread
void 
zorba::zorba_tls_destructor( void *tls_data)
{
	zorba	*z = (zorba*)tls_data;
	delete z;
	pthread_setspecific(zorba::tls_key, NULL);
}

void		
zorba::initializeZorbaEngine()//Store& store)
{
	pthread_key_create( &zorba::tls_key, zorba_tls_destructor);
	initializeZorbaEngine_internal();//store);
}

void		
zorba::uninitializeZorbaEngine()
{
	pthread_key_delete( zorba::tls_key );
	uninitializeZorbaEngine_internal();
}

zorba* 
zorba::getZorbaForCurrentThread()
{
	return (zorba*)pthread_getspecific( zorba::tls_key );
}

zorba*		
zorba::allocateZorbaForCurrentThread()
{
	zorba*	new_zorba;

	new_zorba = new zorba();

	pthread_setspecific( zorba::tls_key, new_zorba );


	return new_zorba;
}


void		
zorba::destroyZorbaForCurrentThread()//when ending the thread
{
	zorba	*z = getZorbaForCurrentThread();
	delete z;
	pthread_setspecific(zorba::tls_key, NULL);
}




#elif defined ZORBA_USE_BOOST_THREAD_LIBRARY

thread_specific_ptr<zorba>			zorba::tls_key;

void		
zorba::initializeZorbaEngine()//Store& store)
{
	initializeZorbaEngine_internal();//store);
}

void		
zorba::uninitializeZorbaEngine()
{
	uninitializeZorbaEngine_internal();
}

zorba* 
zorba::getZorbaForCurrentThread()
{
	return zorba::tls_key.get();
}

zorba*		
zorba::allocateZorbaForCurrentThread()
{
	zorba*	new_zorba;

	new_zorba = new zorba();

	zorba::tls_key = new_zorba;

	return new_zorba;
}


void		
zorba::destroyZorbaForCurrentThread()//when ending the thread
{
	zorba::tls_key.release();
}


#else

///for pthreads, use our internal mechanism of Thread Specific Storage

std::map<uint64_t, zorba*>		zorba::global_zorbas;
pthread_mutex_t								zorba::global_zorbas_mutex;// = PTHREAD_MUTEX_INITIALIZER;

void		
zorba::initializeZorbaEngine()//Store& store)
{
	pthread_mutex_init(&global_zorbas_mutex, NULL);
	initializeZorbaEngine_internal();//store);
}

void		
zorba::uninitializeZorbaEngine()
{
	pthread_mutex_destroy(&global_zorbas_mutex);
	uninitializeZorbaEngine_internal();
}

zorba* 
zorba::getZorbaForCurrentThread()
{
	std::map<uint64_t, zorba*>::iterator	it_zorba;

	pthread_mutex_lock(&global_zorbas_mutex);
	it_zorba = global_zorbas.find((uint64_t)(uintptr_t)pthread_self());
	if(it_zorba == global_zorbas.end())
	{///not found, big error
		pthread_mutex_unlock(&global_zorbas_mutex);
		return NULL;
	}
	else
	{
		pthread_mutex_unlock(&global_zorbas_mutex);
		return (*it_zorba).second;
	}
}

zorba*		
zorba::allocateZorbaForCurrentThread()
{
	zorba*	new_zorba;

	new_zorba = new zorba();

	pthread_mutex_lock(&global_zorbas_mutex);
	global_zorbas[(uint64_t)(uintptr_t)pthread_self()] = new_zorba;
	pthread_mutex_unlock(&global_zorbas_mutex);

	return new_zorba;
}


void		
zorba::destroyZorbaForCurrentThread()//when ending the thread
{
	pthread_mutex_lock(&global_zorbas_mutex);
	global_zorbas.erase((uint64_t)(uintptr_t)pthread_self());
	pthread_mutex_unlock(&global_zorbas_mutex);
}


#endif


}	/* namespace xqp */



