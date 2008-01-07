#ifndef ERRORS_ERROR_MANAGER
#define ERRORS_ERROR_MANAGER

#include "error_api.h"

namespace xqp{

class Zorba;

class ZorbaAlertsManagerImpl : public ZorbaAlertsManager
{
public:
	ZorbaAlertsManagerImpl();

	virtual ~ZorbaAlertsManagerImpl();

	int sendAlertToUser(Zorba* z, ZorbaAlert* alert);

	void RegisterAlertCallback(alert_callback* user_alert_callback, void *param);

	AlertCodes& getAlertCodes();
  void setAlertCodes(AlertCodes* c, bool is_from_user);

	void clearAlertList();

protected:
	AlertCodes      * theAlertCodes;
	bool						is_from_user;

	//if ZorbaErrorAlertsImpl::xquery_registered_callback is not specified, call this callback
	alert_callback	* thread_registered_callback;
	void						* thread_registered_param;
};

}//end namespace xqp

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
