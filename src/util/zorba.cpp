///Created: Daniel Turcanu @ IPDevel 

#include <map>

#include "zorba_api.h"
#include "zorba.h"

#include "context/common.h"
#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "api/external/xquerybinary.h"
#include "errors/Error_impl.h"

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

SequenceTypeManager		zorba::theSequenceTypeManager;///a global var
ItemFactory*	zorba::itemFactory;///global per application
Store*				zorba::theStore;



zorba::zorba()
{
	coll = NULL;
	current_xquery = NULL;
	current_xqueryresult = NULL;

	m_error_manager = new ZorbaErrorAlertsImpl;
}


zorba::~zorba()
{
	if(coll)
		delete coll;

	delete m_error_manager;
}


///some common functions for TLS

void zorba::initializeZorbaEngine_internal(
    ItemFactory *item_factory,
    Store *store)
{
	static_context::init();
	dynamic_context::init();

	zorba::itemFactory = item_factory;
	zorba::theStore = store;
}


void zorba::uninitializeZorbaEngine_internal()
{
	theStore = NULL;
	itemFactory = NULL;
}


::Collator	*zorba::getCollator()
{
	if(!coll)
	{///this is the first use
		//create the collator object
		UErrorCode status = U_ZERO_ERROR;

		//NOTE For default: By passing "root" as a locale parameter the root locale is used.
		//Root locale implements the UCA rules
		//(see DUCET from http://www.unicode.org/Public/UCA/5.0.0/allkeys.txt)
		coll = ::Collator::createInstance(Locale(coll_string.c_str()), status);

		if(U_FAILURE(status)) 
		{
			ZORBA_ERROR_ALERT(
					error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
					error_messages::SYSTEM_ERROR,
					NULL
				);
			return NULL;
		}

		//by default set level 1 comparison for the collator
		coll->setStrength(coll_strength);
	}

	return coll;
}

yy::location& zorba::GetCurrentLocation()//from top iterator
{
	if(current_iterator.empty())
		return null_loc;///no current location information
	else
		return (yy::location&)(current_iterator.top()->loc);
}

ItemFactory* zorba::getItemFactory()
{
	return &*itemFactory;
}

Store* zorba::getStore()
{
	return &*theStore;
}

SequenceTypeManager* zorba::getSequenceTypeManager()
{
	return &theSequenceTypeManager;
}

static_context* zorba::get_static_context()///of the current xquery
{
	if(!current_xquery)
		return NULL;
	return &current_xquery->internal_static_context;
}

ZorbaErrorAlertsImpl* zorba::getErrorManager()
{ 
	return m_error_manager;
}

//library*	zorba::get_library()
//{
//	return &*theFunctionLibrary;
//}



///define the Thread Specific Storage object zorba

#ifdef WIN32


DWORD		zorba::tls_key = 0;


void		
zorba::initializeZorbaEngine(ItemFactory *itemFactory, Store *store)
{
	zorba::tls_key = TlsAlloc();

	initializeZorbaEngine_internal( itemFactory, store );

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
zorba::initializeZorbaEngine(ItemFactory *itemFactory,
																					 Store *store)
{
	initializeZorbaEngine_internal( itemFactory, store );
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
zorba::initializeZorbaEngine(ItemFactory *itemFactory,
														 Store *store)
{
	pthread_key_create( &zorba::tls_key, zorba_tls_destructor);
	initializeZorbaEngine_internal( itemFactory, store );
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
zorba::initializeZorbaEngine(ItemFactory *itemFactory, Store *store)
{
	initializeZorbaEngine_internal( itemFactory, store );
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
zorba::initializeZorbaEngine(ItemFactory *itemFactory,
															Store *store)
{
	pthread_mutex_init(&global_zorbas_mutex, NULL);
	initializeZorbaEngine_internal( itemFactory, store );
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



