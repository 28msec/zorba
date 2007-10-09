/** -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: context.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan, Paul Pedersen
 *
 */
#include <map>

#include "zorba.h"

#include "context/dynamic_context.h"
#include "context/static_context.h"
#include "../store/api/item_factory.h"


using namespace std;
namespace xqp {

/*
A hash containing global zorba objects for each thread ID
*/
std::map<uint64_t, zorba*>		zorba::global_zorbas;
pthread_mutex_t								zorba::global_zorbas_mutex;// = PTHREAD_MUTEX_INITIALIZER;

zorba::zorba()
  :
	theValueFactory(NULL),
  theSequenceTypeManager(NULL),
	theStore(NULL),
	theStaticContext(NULL),
	theDynamicContext(NULL),
	error_manager(NULL)
{
}


zorba::zorba(
	rchandle<ItemFactory> valueFactory,
  rchandle<SequenceTypeManager> seqMgr,
	rchandle<Store> store,
	rchandle<static_context> staticContext,
	rchandle<dynamic_context> dynamicContext,
	rchandle<ZorbaErrorAlerts> zorbaAlerts)
  :
	theValueFactory(valueFactory),
  theSequenceTypeManager(seqMgr),
	theStore(store),
	theStaticContext(staticContext),
	theDynamicContext(dynamicContext),
	error_manager(zorbaAlerts)
{
}


yy::location& zorba::GetCurrentLocation()//from top iterator
{
	if(current_iterator.empty())
		return null_loc;///no current location information
	else
		return (yy::location&)(current_iterator.top()->loc);
}


void		
zorba::initializeZorbaEngine()
{
	pthread_mutex_init(&global_zorbas_mutex, NULL);
}


void		
zorba::uninitializeZorbaEngine()
{
	pthread_mutex_destroy(&global_zorbas_mutex);
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
zorba::allocateZorbaForNewThread()
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

}	/* namespace xqp */



