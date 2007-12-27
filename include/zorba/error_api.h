#ifndef ERRORS_EXTERNAL_CPP_API_29_OCT_2007
#define ERRORS_EXTERNAL_CPP_API_29_OCT_2007

#include "errors/error_codes.h"
#include "types/representations.h"
#include "store/api/item.h"
#include <list>

namespace xqp{


class Zorba_Items : public std::vector<Item*>
{
};


class ZorbaAlertLocation
{
public:
	ZorbaAlertLocation();

public:

	xqp_string   module_name;///empty if is main module

	xqp_string   filename;
	unsigned int line;
	unsigned int column;

};


struct ZorbaAlert
{
	virtual ~ZorbaAlert();

	typedef enum Zorba_AlertType
	{
		ERROR_ALERT,
		WARNING_ALERT,
		NOTIFICATION_ALERT,
		FEEDBACK_REQUEST_ALERT,

		USER_ERROR_ALERT,//fn:error
		USER_TRACE_ALERT//fn:trace
	};
	
	Zorba_AlertType alert_type;

	///the user readable description; can be in other languages than english
	std::string     alert_description;

	time_t          time_of_alert;
};


//for errors
struct ZorbaErrorAlert : public ZorbaAlert
{
	virtual ~ZorbaErrorAlert();

	AlertCodes::error_code  error_code;
	AlertCodes::error_type  error_type;
	bool                    is_fatal;
	//location is valid only for errors and warnings
	ZorbaAlertLocation      loc;///may contain no location (zero values)
};


///for warnings
struct ZorbaWarningAlert: public ZorbaAlert
{
	virtual ~ZorbaWarningAlert();

	AlertCodes::warning_code warning_code;
	//location is valid only for errors and warnings
	ZorbaAlertLocation       loc;///may contain no location (zero values)
};


///for notifications
struct ZorbaNotifyAlert: public ZorbaAlert
{
	virtual ~ZorbaNotifyAlert();

	AlertCodes::NotifyEvent_code	notif_code;
};


//for user interaction
struct ZorbaAskUserAlert: public ZorbaAlert
{
	virtual ~ZorbaAskUserAlert();

	AlertCodes::AskUserString_code         ask_string;
	AlertCodes::AskUserStringOptions_code  ask_string_options;
};


//for user fn:error()
struct ZorbaFnErrorAlert: public ZorbaAlert
{
	virtual ~ZorbaFnErrorAlert();
	
	QNameItem_t  err_qname;
	std::string  err_qname_decoded;
	Zorba_Items  items_error;
};


//for user fn:trace()
struct ZorbaFnTraceAlert: public ZorbaAlert
{
	virtual ~ZorbaFnTraceAlert();

	Zorba_Items items_trace;
};


class XQuery;
typedef rchandle<XQuery> XQuery_t;

class XQueryExecution;
typedef rchandle<XQueryExecution> XQueryExecution_t;


///user might choose to receive the alerts through callback functions
typedef int alert_callback(ZorbaAlert*       alert, 
													 XQuery*           current_xquery,
													 XQueryExecution*  current_xqueryresult,
													 void*             param);


class ZorbaAlertsManager : public std::list<ZorbaAlert*>
{
public:
	virtual ~ZorbaAlertsManager();

	///register function to be called when error/warning/alert happens
	///if callback function is NULL, then alerts are put in list
	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
																		void *param) = 0;

  virtual	void clearAlertList() = 0;
};


}//end namespace xqp

#endif
