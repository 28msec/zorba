#ifndef ALERTS_ALERTS_MANAGER
#define ALERTS_ALERTS_MANAGER

#include <zorba/errors.h>

namespace xqp
{

class Zorba;
class AlertMessages;

class AlertListImpl : public AlertList
{
public:
	bool		is_error;
public:
	AlertListImpl();
	virtual ~AlertListImpl();
	virtual void dumpAlerts(std::ostream &os);
  virtual void clearAlertList();

	virtual bool isError();
	void setIsError();
};

/*******************************************************************************

********************************************************************************/
class AlertsManagerImpl : public ZorbaAlertsManager
{
public:
	AlertsManagerImpl();

	virtual ~AlertsManagerImpl();

	int sendAlertToUser(Zorba* z, ZorbaAlert_t alert, bool dont_send_callback = false);
	bool sendAlertByCallback(Zorba* z, 
														ZorbaAlert_t alert, 
														bool dont_send_callback,
														int *retval);

	void registerAlertCallback(alert_callback* user_alert_callback, void *param);

	AlertMessages& getAlertMessages();
  void setAlertMessages(AlertMessages* c, bool is_from_user);

	virtual AlertList_t		getAlertList();
	virtual void dumpAlerts(std::ostream &os);
	void clearAlertList();

	virtual bool isError();
	void				setIsError();

//	virtual void setThrowExceptionsMode(bool throw_exceptions);
//	virtual bool	getThrowExceptionsMode();
protected:
	AlertMessages   * theAlertMessages;
	bool			        theIsFromUser;
	
	rchandle<AlertListImpl>			alert_list;

	//if ZorbaErrorAlertsImpl::xquery_registered_callback is not specified, call this callback
	alert_callback	* thread_registered_callback;
	void						* thread_registered_param;

	//bool						is_error;
};

typedef rchandle<AlertsManagerImpl>		AlertsManagerImpl_t;

}//end namespace xqp

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
