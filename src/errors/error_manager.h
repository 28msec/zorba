#ifndef ALERTS_ALERTS_MANAGER
#define ALERTS_ALERTS_MANAGER

#include "errors/errors.h"

namespace xqp
{

class Zorba;
class AlertMessages;

/*******************************************************************************

********************************************************************************/
class AlertsManagerImpl : public ZorbaAlertsManager
{
public:
	AlertsManagerImpl();

	virtual ~AlertsManagerImpl();

	int sendAlertToUser(Zorba* z, ZorbaAlert* alert);

	void registerAlertCallback(alert_callback* user_alert_callback, void *param);

	AlertMessages& getAlertMessages();
  void setAlertMessages(AlertMessages* c, bool is_from_user);

	virtual void dumpAlerts(std::ostream &os);
	void clearAlertList();

	virtual bool isError();
	void				setIsError();

//	virtual void setThrowExceptionsMode(bool throw_exceptions);
//	virtual bool	getThrowExceptionsMode();
protected:
	AlertMessages   * theAlertMessages;
	bool			        theIsFromUser;

	//if ZorbaErrorAlertsImpl::xquery_registered_callback is not specified, call this callback
	alert_callback	* thread_registered_callback;
	void						* thread_registered_param;

	bool						is_error;
};

typedef rchandle<AlertsManagerImpl>		AlertsManagerImpl_t;

}//end namespace xqp

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
