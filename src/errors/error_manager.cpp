
#include "errors/error_messages.h"
#include "error_manager.h"
#include "system/zorba.h"
#include "errors/errors.h"
#include "api/external/xquery.h"

using namespace std;
namespace xqp {


ZorbaAlertsManager::~ZorbaAlertsManager()
{
}


AlertsManagerImpl::AlertsManagerImpl( )
{
	thread_registered_callback = NULL;
	thread_registered_param = NULL;
	theIsFromUser = true;
//	theAlertMessages = NULL;
  AlertMessagesEnglish* codes = new AlertMessagesEnglish;
	setAlertMessages(codes, false);
	is_error = false;
	throw_exceptions = false;
}


AlertsManagerImpl::~AlertsManagerImpl()
{
	clearAlertList();

  if (!theIsFromUser && theAlertMessages != NULL)
    delete theAlertMessages;
}


void AlertsManagerImpl::clearAlertList()
{
	std::list<ZorbaAlert*>::const_iterator errit;
	
	for(errit = begin(); errit != end(); errit++)
		delete *errit;

	clear();
	is_error = false;
}


/*
	Register the callback for the thread specific error manager
*/
void AlertsManagerImpl::RegisterAlertCallback(
    alert_callback* user_alert_callback,
    void* param)
{
	thread_registered_callback = user_alert_callback;
	thread_registered_param = param;
}


AlertMessages& AlertsManagerImpl::getAlertMessages()
{
	return *theAlertMessages;
}


void AlertsManagerImpl::setAlertMessages(AlertMessages* c, bool is_from_user)
{
	if(!theIsFromUser)
		delete theAlertMessages;
	theAlertMessages = c;
	theIsFromUser = is_from_user;
}


int AlertsManagerImpl::sendAlertToUser(Zorba* z, ZorbaAlert* alert)
{
	int		retval;

	if(alert->theKind == ZorbaAlert::ERROR_ALERT)
		setIsError();

	if(thread_registered_callback)
	{
		if(z->current_xqueryresult && z->current_xqueryresult->alert_callback_param)
    {
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			z->current_xqueryresult->alert_callback_param);
    }
		else
    {
			retval = thread_registered_callback(alert, 
																			z->current_xquery,
																			z->current_xqueryresult,
																			thread_registered_param);
    }
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

bool AlertsManagerImpl::isError()
{
	return is_error;
}

void AlertsManagerImpl::setIsError()
{
	is_error = true;
}

void AlertsManagerImpl::setThrowExceptionsMode(bool throw_exceptions)
{
	this->throw_exceptions = throw_exceptions;
}

bool AlertsManagerImpl::getThrowExceptionsMode()
{
	return throw_exceptions;
}


}
