
#include "zorba_api.h"
#include "Error.h"
#include "errors/errors.h"
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

  static const char *canonical_err_names [error_messages::MAX_ZORBA_ERROR_CODE + 1];
  static struct canonical_err_names_initializer {
    canonical_err_names_initializer () {
#define DEF_ERR_CODE( code, name ) canonical_err_names [ error_messages::code ] = #name
      DEF_ERR_CODE (XPST0001, XPST0001);
      DEF_ERR_CODE (XPDY0002, XPDY0002);
      DEF_ERR_CODE (XPST0003, XPST0003);
      DEF_ERR_CODE (XPTY0004, XPTY0004);
      DEF_ERR_CODE (XPST0005, XPST0005);
      DEF_ERR_CODE (FORG0006, FORG0006);
      DEF_ERR_CODE (XPST0008, XPST0008);
      DEF_ERR_CODE (XQST0009, XQST0009);
      DEF_ERR_CODE (XPST0010, XPST0010);
      DEF_ERR_CODE (XQST0012, XQST0012);
      DEF_ERR_CODE (XQST0013, XQST0013);
      DEF_ERR_CODE (XQST0016, XQST0016);
      DEF_ERR_CODE (XPST0017, XPST0017);
      DEF_ERR_CODE (XPTY0018, XPTY0018);
      DEF_ERR_CODE (XPTY0019, XPTY0019);
      DEF_ERR_CODE (XPTY0020, XPTY0020);
      DEF_ERR_CODE (XQST0022, XQST0022);
      DEF_ERR_CODE (XQTY0024, XQTY0024);
      DEF_ERR_CODE (XQDY0025, XQDY0025);
      DEF_ERR_CODE (XQDY0026, XQDY0026);
      DEF_ERR_CODE (XQDY0027, XQDY0027);
      DEF_ERR_CODE (XQTY0030, XQTY0030);
      DEF_ERR_CODE (XQST0031, XQST0031);
      DEF_ERR_CODE (XQST0032, XQST0032);
      DEF_ERR_CODE (XQST0033, XQST0033);
      DEF_ERR_CODE (XQST0034, XQST0034);
      DEF_ERR_CODE (XQST0035, XQST0035);
      DEF_ERR_CODE (XQST0036, XQST0036);
      DEF_ERR_CODE (XQST0038, XQST0038);
      DEF_ERR_CODE (XQST0039, XQST0039);
      DEF_ERR_CODE (XQST0040, XQST0040);
      DEF_ERR_CODE (XQDY0041, XQDY0041);
      DEF_ERR_CODE (XQDY0044, XQDY0044);
      DEF_ERR_CODE (XQST0045, XQST0045);
      DEF_ERR_CODE (XQST0046, XQST0046);
      DEF_ERR_CODE (XQST0047, XQST0047);
      DEF_ERR_CODE (XQST0048, XQST0048);
      DEF_ERR_CODE (XQST0049, XQST0049);
      DEF_ERR_CODE (XPDY0050, XPDY0050);
      DEF_ERR_CODE (XPST0051, XPST0051);
      DEF_ERR_CODE (XQST0054, XQST0054);
      DEF_ERR_CODE (XQST0055, XQST0055);
      DEF_ERR_CODE (XQST0057, XQST0057);
      DEF_ERR_CODE (XQST0058, XQST0058);
      DEF_ERR_CODE (XQST0059, XQST0059);
      DEF_ERR_CODE (XQST0060, XQST0060);
      DEF_ERR_CODE (XQDY0061, XQDY0061);
      DEF_ERR_CODE (XQDY0064, XQDY0064);
      DEF_ERR_CODE (XQST0065, XQST0065);
      DEF_ERR_CODE (XQST0066, XQST0066);
      DEF_ERR_CODE (XQST0067, XQST0067);
      DEF_ERR_CODE (XQST0068, XQST0068);
      DEF_ERR_CODE (XQST0069, XQST0069);
      DEF_ERR_CODE (XQST0070, XQST0070);
      DEF_ERR_CODE (XQST0071, XQST0071);
      DEF_ERR_CODE (XQDY0072, XQDY0072);
      DEF_ERR_CODE (XQST0073, XQST0073);
      DEF_ERR_CODE (XQDY0074, XQDY0074);
      DEF_ERR_CODE (XQST0075, XQST0075);
      DEF_ERR_CODE (XQST0076, XQST0076);
      DEF_ERR_CODE (XQST0079, XQST0079);
      DEF_ERR_CODE (XPST0080, XPST0080);
      DEF_ERR_CODE (XPST0081, XPST0081);
      DEF_ERR_CODE (XQDY0084, XQDY0084);
      DEF_ERR_CODE (XQST0085, XQST0085);
      DEF_ERR_CODE (XQTY0086, XQTY0086);
      DEF_ERR_CODE (XQST0087, XQST0087);
      DEF_ERR_CODE (XQST0088, XQST0088);
      DEF_ERR_CODE (XQST0089, XQST0089);
      DEF_ERR_CODE (XQST0090, XQST0090);
      DEF_ERR_CODE (FOER0000, FOER0000);
      DEF_ERR_CODE (FOAR0001, FOAR0001);
      DEF_ERR_CODE (FOAR0002, FOAR0002);
      DEF_ERR_CODE (FOCA0001, FOCA0001);
      DEF_ERR_CODE (FOCA0002, FOCA0002);
      DEF_ERR_CODE (FOCA0003, FOCA0003);
      DEF_ERR_CODE (FOCA0005, FOCA0005);
      DEF_ERR_CODE (FOCA0006, FOCA0006);
      DEF_ERR_CODE (FOCH0001, FOCH0001);
      DEF_ERR_CODE (FOCH0002, FOCH0002);
      DEF_ERR_CODE (FOCH0003, FOCH0003);
      DEF_ERR_CODE (FOCH0004, FOCH0004);
      DEF_ERR_CODE (FODC0001, FODC0001);
      DEF_ERR_CODE (FODC0002, FODC0002);
      DEF_ERR_CODE (FODC0003, FODC0003);
      DEF_ERR_CODE (FODC0004, FODC0004);
      DEF_ERR_CODE (FODC0005, FODC0005);
      DEF_ERR_CODE (FODT0001, FODT0001);
      DEF_ERR_CODE (FODT0002, FODT0002);
      DEF_ERR_CODE (FODT0003, FODT0003);
      DEF_ERR_CODE (FONS0004, FONS0004);
      DEF_ERR_CODE (FONS0005, FONS0005);
      DEF_ERR_CODE (FORG0001, FORG0001);
      DEF_ERR_CODE (FORG0002, FORG0002);
      DEF_ERR_CODE (FORG0003, FORG0003);
      DEF_ERR_CODE (FORG0004, FORG0004);
      DEF_ERR_CODE (FORG0005, FORG0005);
      DEF_ERR_CODE (FORG0006, FORG0006);
      DEF_ERR_CODE (FORG0008, FORG0008);
      DEF_ERR_CODE (FORG0009, FORG0009);
      DEF_ERR_CODE (FORX0001, FORX0001);
      DEF_ERR_CODE (FORX0002, FORX0002);
      DEF_ERR_CODE (FORX0003, FORX0003);
      DEF_ERR_CODE (FORX0004, FORX0004);
      DEF_ERR_CODE (FOTY0012, FOTY0012);
      DEF_ERR_CODE (SENR0001_Item_is_attribute_or_namespace_node, SENR0001);
      DEF_ERR_CODE (SEPM0016_Invalid_parameter_value, SEPM0016);
      DEF_ERR_CODE (XQP0000_DYNAMIC_RUNTIME_ERROR, XQP0000);
      DEF_ERR_CODE (XQP0001_DYNAMIC_ITERATOR_OVERRUN, XQP0001);
      DEF_ERR_CODE (XQP0002_DYNAMIC_ILLEGAL_NODE_CHILD, XQP0002);
      DEF_ERR_CODE (XQP0003_DYNAMIC_TARGET_NAMESPACE_NOT_FOUND, XQP0003);
      DEF_ERR_CODE (XQP0004_SYSTEM_NOT_SUPPORTED, XQP0004);
      DEF_ERR_CODE (XQP0005_SYSTEM_ASSERT_FAILED, XQP0005);
      DEF_ERR_CODE (XQP0006_SYSTEM_HASH_ERROR_KEYLEN_EXCEEDS_MAXKEYLEN, XQP0006);
      DEF_ERR_CODE (XQP0007_SYSTEM_VECTOR_OUT_OF_RANGE, XQP0007);
      DEF_ERR_CODE (XQP0008_SYSTEM_READ_LOCK_FAILED, XQP0008);
      DEF_ERR_CODE (XQP0009_SYSTEM_WRITE_LOCK_FAILED, XQP0009);
      DEF_ERR_CODE (XQP0010_SYSTEM_POP_FROM_EMPTY_LIST, XQP0010);
      DEF_ERR_CODE (XQP0011_SYSTEM_FILE_ERROR_IN_FUNCTION, XQP0011);
      DEF_ERR_CODE (XQP0012_SYSTEM_FXCHARHEAP_IOEXCEPTION, XQP0012);
      DEF_ERR_CODE (XQP0013_SYSTEM_MMFILE_IOEXCEPTION, XQP0013);
      DEF_ERR_CODE (XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED, XQP0014);
      DEF_ERR_CODE (XQP0015_SYSTEM_NOT_YET_IMPLEMENTED, XQP0015);
      DEF_ERR_CODE (XQP0016_LOADER_IO_ERROR, XQP0016);
      DEF_ERR_CODE (XQP0017_LOADER_NOT_WELL_FORMED_XML, XQP0017);
      DEF_ERR_CODE (XQP0018_NODEID_OUT_OF_RANGE, XQP0018);
      DEF_ERR_CODE (API0001_XQUERY_STRING_IS_EMPTY, API0001);
      DEF_ERR_CODE (API0002_COMPILE_FAILED, API0002);
      DEF_ERR_CODE (API0003_XQUERY_NOT_COMPILED, API0003);
      DEF_ERR_CODE (API0004_XQUERY_ALREADY_COMPILED, API0004);
      DEF_ERR_CODE (API0005_COLLECTION_ALREADY_EXISTS, API0005);
      DEF_ERR_CODE (API0006_COLLECTION_NOT_FOUND, API0006);
#undef DEF_ERR_CODE

    }
  } canonical_err_names_initializer_obj;

void ZorbaErrorAlerts::error_alert( 
    const error_messages::errcode e,
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
//	std::ostringstream strloc;

	err_decoded = err_manager->err_messages->err_decode(e);

	err_decoded += ": ";
	err_manager->err_messages->ApplyParams(&err_decoded, &param1, &param2);
  cerr << canonical_err_names [e] << ": " << err_decoded <<  "\n";

//	strloc << *ploc;

	///construct the error message for the user
	Zorba_ErrorMessage	*errmess = new Zorba_ErrorMessage;

	errmess->alert_type = Zorba_AlertMessage::ERROR_ALERT;
	errmess->error_code = e;
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
       NULL, false,
       what, where);
	}
}

}
