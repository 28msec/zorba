
#include "zorba_api.h"
#include "Error.h"
#include "user_error.h"
#include "Error_impl.h"
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

//debug
#ifndef NDEBUG
const char*		g_error_in_file = NULL;
int						g_error_at_line = 0;
bool					g_abort_when_fatal_error = false;
#endif
//end debug

void ZorbaErrorAlerts::error_alert( 
    // const char *file,
    // const int line,
    const error_messages::errcode e,
    error_messages::error_type errtype,
    const yy::location *ploc, 
    bool continue_execution,
    const std::string param1,
    const std::string param2)
{
	zorba*	z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();
	if(!ploc)
	{
		if(z->current_iterator.empty())
		{
		//	error_alert_withoutlocation(e, errtype, continue_execution, param1, param2);
		//	return;
		}
		else
			ploc = &z->current_iterator.top()->loc;///get location of current iterator
	}

	std::string err_decoded;
	std::string errtype_decoded;
//	std::ostringstream strloc;

	err_decoded = err_manager->err_messages->err_decode(e);
	errtype_decoded = err_manager->err_messages->errtype_decode(errtype);

	err_decoded += ": ";
	err_decoded += errtype_decoded;
	err_manager->err_messages->ApplyParams(&err_decoded, &param1, &param2);
  cerr << err_decoded << errtype_decoded << "\n";

//	strloc << *ploc;

	///construct the error message for the user
	Zorba_ErrorMessage	*errmess = new Zorba_ErrorMessage;

	errmess->alert_type = Zorba_AlertMessage::ERROR_ALERT;
	errmess->error_code = e;
	errmess->error_type = errtype;
	errmess->is_fatal = !continue_execution;
	if(ploc)
	{
		if(ploc->begin.filename)
			errmess->loc.filename = *ploc->begin.filename;
		errmess->loc.line = ploc->begin.line;
		errmess->loc.column = ploc->begin.column;
	}
	errmess->alert_description = err_decoded;
	time(&errmess->time_of_alert);

	err_manager->sendAlertToUser(z, errmess);

	if(!continue_execution)
	{
	//	cout << "Fatal Error:" << strloc << " : " << err_decoded << std::endl;
#ifndef NDEBUG
		if(g_abort_when_fatal_error)
			abort ();
		else
#endif
      throw xqp_exception(e,
                          "",//strloc.str(), 
                          err_decoded);
	}
	else
	{
	//	cout << "Error:" << strloc << " : " << err_decoded << std::endl;
	}
}


void ZorbaErrorAlerts::warning_alert( 
    // const char *file,
    // const int line,
    const error_messages::warning_code warn,
    const yy::location *ploc, 
    const string param1,
    const string param2)
{
	zorba	*z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();
	if(!ploc)
	{
		if(z->current_iterator.empty())
		{
		//	warning_alert_withoutlocation(warn, param1, param2);
		//	return;
		}
		else
			ploc = &z->current_iterator.top()->loc;///get location of current iterator
	}

	std::string warning_decoded;
//	std::ostringstream strloc;

	warning_decoded = err_manager->err_messages->warning_decode(warn);
	err_manager->err_messages->ApplyParams(&warning_decoded, &param1, &param2);

	///construct the warning message for the user
	Zorba_WarningMessage	*warnmess = new Zorba_WarningMessage;

	warnmess->alert_type = Zorba_AlertMessage::WARNING_ALERT;
	warnmess->warning_code = warn;
	if(ploc)
	{
		if(ploc->begin.filename)
			warnmess->loc.filename = *ploc->begin.filename;
		warnmess->loc.line = ploc->begin.line;
		warnmess->loc.column = ploc->begin.column;
	}
	warnmess->alert_description = warning_decoded;
	time(&warnmess->time_of_alert);

	err_manager->sendAlertToUser(z, warnmess);

//	strloc << *ploc;

  //	cout << file << "[" << line << "]:" << endl;

	//... send error to user app
//	cout << "Warning:" << strloc << " : " << warning_decoded << std::endl;

}


void ZorbaErrorAlerts::notify_event( 
    // const char *file,
    // const int line,
    const error_messages::NotifyEvent_code notif_event,
    //	const yy::location loc, 
    const string param1,
    const string param2)
{
	std::string notif_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();

	notif_decoded = err_manager->err_messages->notify_event_decode(notif_event);
	err_manager->err_messages->ApplyParams(&notif_decoded, &param1, &param2);

	///construct the notify message for the user
	Zorba_NotifyMessage		*notifymess = new Zorba_NotifyMessage;

	notifymess->alert_type = Zorba_AlertMessage::NOTIFICATION_ALERT;
	notifymess->notif_code = notif_event;
	notifymess->alert_description = notif_decoded;
	time(&notifymess->time_of_alert);
	err_manager->sendAlertToUser(z, notifymess);


	//	cout << file << "[" << line << "]:" << endl;

//	cout << " --> " << notif_decoded << std::endl;

}


//return the index of the option chosen by user
int ZorbaErrorAlerts::ask_user(
    const error_messages::AskUserString_code ask_string,
    const error_messages::AskUserStringOptions_code ask_string_options,
    const string param1,
    const string param2)
{
	std::string ask_user_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();

	ask_user_decoded = err_manager->err_messages->ask_user_decode(ask_string);
	err_manager->err_messages->ApplyParams(&ask_user_decoded, &param1, &param2);

	///construct the ask user message for the user
	Zorba_AskUserMessage		*askmess = new Zorba_AskUserMessage;

	askmess->alert_type = Zorba_AlertMessage::FEEDBACK_REQUEST_ALERT;
	askmess->ask_string = ask_string;
	askmess->ask_string_options = ask_string_options;
	askmess->alert_description = ask_user_decoded;
	time(&askmess->time_of_alert);

	int		retval;
	retval = err_manager->sendAlertToUser(z, askmess);

//	cout << "[]Ask User " << ask_user_decoded << "(not implemented)" << endl;

	return retval;
}


///from user_error.h

/*
void DumpItemsAsText( const std::vector<class Item*> *items)
{
	std::vector<class Item*>::const_iterator item_it;

	for ( item_it = items->begin( ) ; item_it != items->end( ) ; item_it++ )
	{
		cout	<< " =-= " 
					<< (*item_it)->getStringProperty() 
					<< "[0x" << hex << (void*)(*item_it) << "]";
	}

	cout << " =-= " << endl;
}
*/


/*
Extract from XQuery spec 2.3 Error Handling:

The errors defined in this specification are identified by QNames that have the form err:XXYYnnnn, where:

err denotes the namespace for XPath and XQuery errors, http://www.w3.org/2005/xqt-errors. This binding of the namespace prefix err is used for convenience in this document, and is not normative.

XX denotes the language in which the error is defined, using the following encoding:

	XP denotes an error defined by XPath. Such an error may also occur XQuery since XQuery includes XPath as a subset.

	XQ denotes an error defined by XQuery.

YY denotes the error category, using the following encoding:

	ST denotes a static error.

	DY denotes a dynamic error.

	TY denotes a type error.

nnnn is a unique numeric code.

*/
void fn_user_error (QNameItem* err_qname,///optional
									const std::string description,//optional
									const std::vector<class Item*> *items)//optional
{
	std::string err_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();

	if(err_qname)
	{
		std::string	err_uri;
		std::string	err_localname;

		err_uri = err_qname->getNamespace();
		err_localname = err_qname->getLocalName();

		if(err_uri == "http://www.w3.org/2005/xqt-errors")///a standard error
		{
			///try to identify its description
			int		err_num;

			err_num = atoi(err_localname.substr(4,4).c_str());
			

			err_decoded = err_manager->err_messages->err_decode((enum error_messages::errcode)err_num);
			err_manager->err_messages->ApplyParams(&err_decoded, NULL, NULL);

			///...send err_decoded, description and items to user
		}
	}

	///construct the ask user message for the user
	Zorba_FnErrorMessage		*usererr_mess = new Zorba_FnErrorMessage;

	usererr_mess->alert_type = Zorba_AlertMessage::USER_ERROR_ALERT;
	usererr_mess->err_qname = err_qname;
	(std::vector<Item*>)usererr_mess->items_error = *items;///copy the vector of pointers to items
	usererr_mess->alert_description = description;
	usererr_mess->err_qname_decoded = err_decoded;
	time(&usererr_mess->time_of_alert);

	err_manager->sendAlertToUser(z, usererr_mess);

//	cout << "User Error: " << err_decoded << " ( " <<  description << " ) " << endl;
//	DumpItemsAsText(items);

}

void fn_user_trace (const std::vector<class Item*> *items,
										const std::string label)
{
	///...send notification message label + items to user
	///construct the ask user message for the user
	Zorba_FnTraceMessage		*usertrace_mess = new Zorba_FnTraceMessage;
	zorba	*z = zorba::getZorbaForCurrentThread();
	ZorbaErrorAlertsImpl		*err_manager = z->getErrorManager();

	usertrace_mess->alert_type = Zorba_AlertMessage::USER_TRACE_ALERT;
	(std::vector<Item*>)usertrace_mess->items_trace = *items;///copy the vector of poiters to items
	usertrace_mess->alert_description = label;
	time(&usertrace_mess->time_of_alert);

	err_manager->sendAlertToUser(z, usertrace_mess);

//	cout << "User Trace: " << label << endl;
//	DumpItemsAsText(items);
}

///from error_api.h
Zorba_ErrorLocation::Zorba_ErrorLocation()
{
	filename = "";
//	module_name = "";
	line = 0;
	column = 0;
}


Zorba_AlertMessage::~Zorba_AlertMessage() {}
Zorba_ErrorMessage::~Zorba_ErrorMessage() {}
Zorba_WarningMessage::~Zorba_WarningMessage() {}
Zorba_NotifyMessage::~Zorba_NotifyMessage() {}
Zorba_AskUserMessage::~Zorba_AskUserMessage() {}
Zorba_FnErrorMessage::~Zorba_FnErrorMessage() {}
Zorba_FnTraceMessage::~Zorba_FnTraceMessage() {}


/*
	Register the callback for the thread specific error manager
*/
void ZorbaErrorAlertsImpl::RegisterAlertCallback(
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

error_messages&	ZorbaErrorAlertsImpl::getErrMessages()
{
	return *err_messages;
}

//from Error_impl.h

ZorbaErrorAlertsImpl::ZorbaErrorAlertsImpl( )//class error_messages *_err_messages)
{
//	err_messages = _err_messages;
//	errmanager_api = new Zorba_AlertsManager;///ref counted
	thread_registered_callback = NULL;
	thread_registered_param = NULL;
}
Zorba_AlertsManager::~Zorba_AlertsManager()
{
}

ZorbaErrorAlertsImpl::~ZorbaErrorAlertsImpl()
{
	clearAlertList();
}

void ZorbaErrorAlertsImpl::clearAlertList()
{
	std::list<Zorba_AlertMessage*>::const_iterator		errit;
	
	for(errit = begin(); errit != end(); errit++)
		delete *errit;
	clear();
}

int ZorbaErrorAlertsImpl::sendAlertToUser(zorba *z, Zorba_AlertMessage *alertmess)
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

///from Assert.h
void ZorbaAssert(bool assertion, const char *where, const char *what)
{
	if (!assertion) {
    ZorbaErrorAlerts::error_alert
      (error_messages::XQP0005_SYSTEM_ASSERT_FAILED,
       error_messages::SYSTEM_ERROR,
       NULL, false,
       what, where);
	}
}

}
