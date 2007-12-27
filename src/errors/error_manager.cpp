
#include "errors/error_codes.h"
#include "error_manager.h"
#include "system/zorba.h"
#include "zorba_api.h"
#include "api/external/xquery.h"

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

  if (theAlertCodes != NULL)
    delete theAlertCodes;
}


void ZorbaAlertsManagerImpl::clearAlertList()
{
	std::list<ZorbaAlert*>::const_iterator errit;
	
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
	ZORBA_NOTIFY_EVENT_OSS(AlertCodes::NOTIF_EXECUTION_STEP,
		"RegisterAlertCallback with param " << std::hex << param, "");
  #endif
}


AlertCodes& ZorbaAlertsManagerImpl::getAlertCodes()
{
	return *theAlertCodes;
}


void ZorbaAlertsManagerImpl::setAlertCodes(AlertCodes* c)
{
	theAlertCodes = c;
}


int ZorbaAlertsManagerImpl::sendAlertToUser(Zorba* z, ZorbaAlert* alert)
{
	int		retval;

	if(thread_registered_callback)
	{
		if(z->current_xqueryresult && z->current_xqueryresult->alert_callback_param)
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			z->current_xqueryresult->alert_callback_param);
		else
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			thread_registered_param);
		delete alert;
		return retval;
	}
	else
	{
		///if no callback was registered, then put the error in list
		push_back(alert);
	}

	return -1;
}

}
