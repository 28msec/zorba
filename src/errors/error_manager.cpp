
#include "zorba_api.h"
#include "Error.h"
#include "errors/errors.h"
#include "user_error.h"
#include "error_manager.h"
#include "util/Assert.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "util/zorba.h"
#include "store/api/item.h"
#include "runtime/base/iterator.h"
#include <time.h>
#include "api/external/xquerybinary.h"

using namespace std;
namespace xqp {


ZorbaAlertsManager::~ZorbaAlertsManager()
{
}


ZorbaAlertsManagerImpl::ZorbaAlertsManagerImpl( )
{
	thread_registered_callback = NULL;
	thread_registered_param = NULL;
}


ZorbaAlertsManagerImpl::~ZorbaAlertsManagerImpl()
{
	clearAlertList();
}


void ZorbaAlertsManagerImpl::clearAlertList()
{
	std::list<Zorba_AlertMessage*>::const_iterator errit;
	
	for(errit = begin(); errit != end(); errit++)
		delete *errit;

	clear();
}


/*
	Register the callback for the thread specific error manager
*/
void ZorbaAlertsManagerImpl::RegisterAlertCallback(
    alert_callback* user_alert_callback,
    void* param)
{
	thread_registered_callback = user_alert_callback;
	thread_registered_param = param;

  #if 0	
	ZORBA_NOTIFY_EVENT_OSS(error_messages::NOTIF_EXECUTION_STEP,
		"RegisterAlertCallback with param " << std::hex << param, "");
  #endif
}


error_messages&	ZorbaAlertsManagerImpl::getErrMessages()
{
	return *err_messages;
}


int ZorbaAlertsManagerImpl::sendAlertToUser(zorba *z, Zorba_AlertMessage *alertmess)
{
	int		retval;
//	if(z->current_xquery && z->current_xquery->xquery_registered_callback)
//	{
//		if(z->current_xqueryresult && z->current_xqueryresult->alert_callback_param)
//			retval = z->current_xquery->xquery_registered_callback(alertmess, z->current_xqueryresult->alert_callback_param);
//		else
//			retval = z->current_xquery->xquery_registered_callback(alertmess, z->current_xquery->xquery_registered_param);
//		delete alertmess;
//		return retval;
//	}
//	else 
	if(thread_registered_callback)
	{
		if(z->current_xqueryresult && z->current_xqueryresult->alert_callback_param)
			retval = thread_registered_callback(alertmess, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			z->current_xqueryresult->alert_callback_param);
		else
			retval = thread_registered_callback(alertmess, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			thread_registered_param);
		delete alertmess;
		return retval;
	}
	else
	{
		///if no callback was registered, then put the error in list
		push_back(alertmess);
	}

	return -1;
}

}
