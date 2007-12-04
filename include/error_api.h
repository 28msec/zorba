#ifndef ERRORS_EXTERNAL_CPP_API_29_OCT_2007
#define ERRORS_EXTERNAL_CPP_API_29_OCT_2007

#include "errors/errors.h"
#include "types/representations.h"
#include "store/api/item.h"
#include <list>

namespace xqp{

//class Zorba_QName : public Item
//{
//};

class Zorba_Items : public std::vector<Item*>
{
};

class Zorba_ErrorLocation
{
public:
	Zorba_ErrorLocation();

public:

	xqp_string		module_name;///empty if is main module

	xqp_string		filename;
	unsigned int line;
	unsigned int column;

};

struct Zorba_AlertMessage
{
	virtual ~Zorba_AlertMessage();

	typedef enum Zorba_AlertType
	{
		ERROR_ALERT,
		WARNING_ALERT,
		NOTIFICATION_ALERT,
		FEEDBACK_REQUEST_ALERT,

		USER_ERROR_ALERT,//fn:error
		USER_TRACE_ALERT//fn:trace
	};
	
	Zorba_AlertType		alert_type;

	///the user readable description; can be in other languages than english
	std::string		alert_description;

	time_t			time_of_alert;
};
//for errors
struct Zorba_ErrorMessage : public Zorba_AlertMessage
{
	virtual ~Zorba_ErrorMessage();

	error_messages::errcode			error_code;
	error_messages::error_type	error_type;
	bool is_fatal;
	//location is valid only for errors and warnings
	Zorba_ErrorLocation loc;///may contain no location (zero values)
};

///for warnings
struct Zorba_WarningMessage: public Zorba_AlertMessage
{
	virtual ~Zorba_WarningMessage();

	error_messages::warning_code			warning_code;
	//location is valid only for errors and warnings
	Zorba_ErrorLocation loc;///may contain no location (zero values)
};
///for notifications
struct Zorba_NotifyMessage: public Zorba_AlertMessage
{
	virtual ~Zorba_NotifyMessage();

	error_messages::NotifyEvent_code	notif_code;
};
//for user interaction
struct Zorba_AskUserMessage: public Zorba_AlertMessage
{
	virtual ~Zorba_AskUserMessage();

	error_messages::AskUserString_code ask_string;
	error_messages::AskUserStringOptions_code ask_string_options;
};
//for user fn:error()
struct Zorba_FnErrorMessage: public Zorba_AlertMessage
{
	virtual ~Zorba_FnErrorMessage();
	
	QNameItem_t		err_qname;
	std::string		err_qname_decoded;
	Zorba_Items items_error;
};
//for user fn:trace()
struct Zorba_FnTraceMessage: public Zorba_AlertMessage
{
	virtual ~Zorba_FnTraceMessage();

	Zorba_Items items_trace;
};


class XQuery;
typedef rchandle<XQuery>		XQuery_t;
class XQueryResult;
typedef rchandle<XQueryResult>		XQueryResult_t;

///user might choose to receive the alerts through callback functions
typedef int alert_callback(Zorba_AlertMessage *alert_mess, 
													 XQuery*	current_xquery,
													 XQueryResult*	current_xqueryresult,
													 void *param);

class Zorba_AlertsManager : public std::list<Zorba_AlertMessage*>
{
public:
	virtual ~Zorba_AlertsManager();
	///register function to be called when error/warning/alert happens
	///if callback function is NULL, then alerts are put in list
	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
																		void *param) = 0;
	virtual error_messages&	getErrMessages() = 0;
	virtual	void clearAlertList() = 0;
};

//typedef rchandle<Zorba_AlertsManager>		Zorba_AlertsManager_t;

///alerts manager is a thread-specific global object
///each thread has its own error manager
//Zorba_AlertsManager_t		Zorba_getAlertsManagerForCurrentThread();


}//end namespace xqp

#endif
