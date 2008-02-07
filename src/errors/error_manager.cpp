
#include "errors/error_messages.h"
#include "error_manager.h"
#include "system/zorba.h"
#include "errors/errors.h"
#include "api/external/xquery.h"
#include "api/external/result_iterator_wrapper.h"

using namespace std;
namespace xqp {

static bool g_throw_exceptions = false;

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
}


AlertsManagerImpl::~AlertsManagerImpl()
{
	clearAlertList();

  if (!theIsFromUser && theAlertMessages != NULL)
    delete theAlertMessages;
}


void AlertsManagerImpl::clearAlertList()
{
	std::list<ZorbaAlert_t>::const_iterator errit;
	
//	for(errit = begin(); errit != end(); errit++)
//		delete *errit;

	clear();
	is_error = false;
}


/*
	Register the callback for the thread specific error manager
*/
void AlertsManagerImpl::registerAlertCallback(
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


int AlertsManagerImpl::sendAlertToUser(Zorba* z, ZorbaAlert_t alert,
																			 bool dont_send_callback)
{
	int		retval = -1;

	if(alert->theKind == ZorbaAlert::ERROR_ALERT)
		setIsError();

	if(!sendAlertByCallback(z, alert, dont_send_callback, &retval))
	{
		///if no callback was registered, then put the error in list
		push_back(alert);
	}

	return retval;
}

bool AlertsManagerImpl::sendAlertByCallback(Zorba* z, 
																						ZorbaAlert_t alert, 
																						bool dont_send_callback,
																						int *retval)
{
	if(thread_registered_callback)
	{
		if(!dont_send_callback)
		{
			if(z->current_xquery && z->current_xquery->alert_callback_param)
			{
				*retval = thread_registered_callback(alert, 
																				z->current_xquery,
																				z->current_xqueryresult,
																				z->current_xquery->alert_callback_param);
			}
			else
			{
				*retval = thread_registered_callback(alert, 
																				z->current_xquery,
																				z->current_xqueryresult,
																				thread_registered_param);
			}
			//delete alert;
		}
		return true;
	}
	return false;
}
bool AlertsManagerImpl::isError()
{
	return is_error;
}

void AlertsManagerImpl::setIsError()
{
	is_error = true;
}

bool ZorbaAlertsManager::setThrowExceptionsMode(bool throw_exceptions)
{
	bool original_throw_mode = g_throw_exceptions;
	g_throw_exceptions = throw_exceptions;
	return original_throw_mode;
}

bool ZorbaAlertsManager::getThrowExceptionsMode()
{
	return g_throw_exceptions;
}

void AlertsManagerImpl::dumpAlerts(std::ostream &os)
{

  std::list<ZorbaAlert_t>::const_iterator errit;

  for(errit = this->begin(); errit != this->end(); errit++)
  {
    if (errit == this->begin())
      os << endl << "Error list:" << endl;
    
    (*errit)->dumpAlert(os);
  }

  clearAlertList();
}

}
