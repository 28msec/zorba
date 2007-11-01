#ifndef ZORBA_INTERNAL_ERROR_PROCESSING_IMPLEMENTATION_30_OCT_2007
#define ZORBA_INTERNAL_ERROR_PROCESSING_IMPLEMENTATION_30_OCT_2007

#include "error_api.h"

namespace xqp{

class zorba;

class ZorbaErrorAlertsImpl : public Zorba_AlertsManager
{
public:
	ZorbaErrorAlertsImpl ();
	virtual ~ZorbaErrorAlertsImpl ();

	int sendAlertToUser(zorba *z, Zorba_AlertMessage *alertmess);
	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
														void *param);
	virtual error_messages&	getErrMessages();
	virtual	void clearAlertList();

public:
	error_messages*	 err_messages;
//	Zorba_AlertsManager_t errmanager_api;

	//if ZorbaErrorAlertsImpl::xquery_registered_callback is not specified, call this callback
public:
	alert_callback	*thread_registered_callback;
	void						*thread_registered_param;

};

}//end namespace xqp

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
