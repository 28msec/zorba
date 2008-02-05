#include <time.h>
#include <iostream>
#include <iomanip>
#include <stdlib.h>

#include "errors/errors.h"

#include "error_messages.h"
#include "error_factory.h"
#include "error_manager.h"

#include "system/zorba.h"
#include "store/api/item.h"
#include "runtime/base/iterator.h"
#include "system/zorba_engine.h"
#include "api/external/xquery.h"

using namespace std;
namespace xqp {


#ifndef NDEBUG
const char* g_error_in_file = NULL;
int         g_error_at_line = 0;
bool        g_abort_when_fatal_error = false;
#endif


/*******************************************************************************

********************************************************************************/
void ZorbaAlertFactory::error_alert( 
    const ZorbaError::ErrorCodes code,
    const yy::location* ploc, 
    bool continue_execution,
    const std::string param1,
    const std::string param2)
{
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();

  //If there is no Zorba obj, we cannot generate a detailed description of the error
	if(!z)
	{
		if(!continue_execution)
		{
	#ifndef NDEBUG
			if(g_abort_when_fatal_error)
				abort ();
			else
	#endif
				throw xqp_exception(code);
		}
		else
			return;
	}

  AlertsManagerImpl_t err_manager = z->getErrorManager();

	if(!ploc)
	{
		if(!z->current_iterator.empty())
			ploc = &z->current_iterator.top()->loc;
	}

	std::string description;
	description = err_manager->getAlertMessages().error_decode(code);
	err_manager->getAlertMessages().applyParams(&description, &param1, &param2);
	description = ZorbaError::toString (code) + ": " + description;

	ZorbaError* error = new ZorbaError;
	error->theKind = ZorbaAlert::ERROR_ALERT;
	error->theCode = code;
//	error->theIsFatal = !continue_execution;
	if(ploc)
	{
		if(ploc->begin.filename)
			error->theLocation.filename = *ploc->begin.filename;
		error->theLocation.line = ploc->begin.line;
		error->theLocation.column = ploc->begin.column;
	}
	error->theDescription = description;
	time(&error->theTime);

//	if(z->current_xqueryresult)
//		z->current_xqueryresult->is_error = true;

	xqp_exception		x(*error);

	err_manager->sendAlertToUser(z, error);

	if(!continue_execution)
	{
#ifndef NDEBUG
		if(g_abort_when_fatal_error)
			abort ();
		else
#endif
      throw x;
	}
}


/*******************************************************************************

********************************************************************************/
void ZorbaAlertFactory::warning_alert( 
    const ZorbaWarning::WarningCodes code,
    const yy::location* ploc, 
    const string param1,
    const string param2)
{
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();

	if(!z)
		return;

  AlertsManagerImpl_t err_manager = z->getErrorManager();

	if(!ploc)
	{
		if (!z->current_iterator.empty())
			ploc = &z->current_iterator.top()->loc;
	}

	std::string description;
	description = err_manager->getAlertMessages().warning_decode(code);
	err_manager->getAlertMessages().applyParams(&description, &param1, &param2);

	ZorbaWarning* warning = new ZorbaWarning;
	warning->theKind = ZorbaAlert::WARNING_ALERT;
	warning->theCode = code;
	if(ploc)
	{
		if(ploc->begin.filename)
			warning->theLocation.filename = *ploc->begin.filename;
		warning->theLocation.line = ploc->begin.line;
		warning->theLocation.column = ploc->begin.column;
	}
	warning->theDescription = description;
	time(&warning->theTime);

	err_manager->sendAlertToUser(z, warning);
}


/*******************************************************************************

********************************************************************************/
void ZorbaAlertFactory::notify_event( 
    const ZorbaNotify::NotifyCodes code,
    const string param1,
    const string param2)
{
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();
	if(!z)
		return;

  AlertsManagerImpl_t err_manager = z->getErrorManager();

	std::string description;
	description = err_manager->getAlertMessages().notify_event_decode(code);
	err_manager->getAlertMessages().applyParams(&description, &param1, &param2);

	ZorbaNotify* notification = new ZorbaNotify;
	notification->theKind = ZorbaAlert::NOTIFICATION_ALERT;
	notification->theCode = code;
	notification->theDescription = description;
	time(&notification->theTime);

	err_manager->sendAlertToUser(z, notification);
}


/*******************************************************************************
  returns the index of the option chosen by user
********************************************************************************/
int ZorbaAlertFactory::ask_user(
    const ZorbaAskUser::UserQuestionCodes questionCode,
    const ZorbaAskUser::UserReplyOptionsCodes replyCode,
    const string param1,
    const string param2)
{
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();
	if(!z)
		return -1;

  AlertsManagerImpl_t err_manager = z->getErrorManager();

	std::string description;
  description = err_manager->getAlertMessages().ask_user_decode(questionCode);
	err_manager->getAlertMessages().applyParams(&description, &param1, &param2);

	ZorbaAskUser* askuser = new ZorbaAskUser;
	askuser->theKind = ZorbaAlert::FEEDBACK_REQUEST_ALERT;
	askuser->theQuestionCode = questionCode;
	askuser->theReplyOptionsCode = replyCode;
	askuser->theDescription = description;
	time(&askuser->theTime);

	int retval = err_manager->sendAlertToUser(z, askuser);

	return retval;
}


/*******************************************************************************

 Extract from XQuery spec 2.3 Error Handling:

 The errors defined in this specification are identified by QNames that have the
 form err:XXYYnnnn, where:

 - err denotes the namespace for XPath and XQuery errors (i.e.,
   http://www.w3.org/2005/xqt-errors). This binding of the namespace prefix err
   is used for convenience in this document, and is not normative.

 - XX denotes the language in which the error is defined, using the following
   encoding:

   XP denotes an error defined by XPath. Such an error may also occur XQuery
   since XQuery includes XPath as a subset.

   XQ denotes an error defined by XQuery.

 - YY denotes the error category, using the following encoding:

   ST denotes a static error.

   DY denotes a dynamic error.

   TY denotes a type error.

 - nnnn is a unique numeric code.

********************************************************************************/

void fn_user_error(
    Item* err_qname,///optional
    const std::string description,//optional
    const std::vector<class Item*>* items)//optional
{
	Zorba	*z = ZORBA_FOR_CURRENT_THREAD();

	AlertsManagerImpl_t err_manager = z->getErrorManager();

	std::string err_decoded;

	if(err_qname)
	{
		std::string	err_uri = err_qname->getNamespace();
		std::string	err_localname = err_qname->getLocalName();

		if(err_uri == "http://www.w3.org/2005/xqt-errors")///a standard error
		{
			///try to identify its description
			int	err_num = atoi(err_localname.substr(4,4).c_str());

			err_decoded = err_manager->getAlertMessages().
        error_decode((enum ZorbaError::ErrorCodes)err_num);
			err_manager->getAlertMessages().applyParams(&err_decoded, NULL, NULL);
		}
	}

	ZorbaFnError* usererror = new ZorbaFnError;
	usererror->theKind = ZorbaAlert::USER_ERROR_ALERT;
	usererror->theErrorQName = err_qname;
	if(items)
		usererror->theItems = *items;
	usererror->theUserDescription = description;
	usererror->theDescription = err_decoded;
	time(&usererror->theTime);

	err_manager->sendAlertToUser(z, usererror);
}


/*******************************************************************************

********************************************************************************/
void fn_user_trace(
    const std::vector<class Item*>* items,
    const std::string label)
{
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();
	AlertsManagerImpl_t err_manager = z->getErrorManager();

	///...send notification message label + items to user

	ZorbaFnTrace* usertrace = new ZorbaFnTrace;
	usertrace->theKind = ZorbaAlert::USER_TRACE_ALERT;
	if(items)
		(std::vector<Item*>)usertrace->items_trace = *items;
	usertrace->theDescription = label;
	time(&usertrace->theTime);

	err_manager->sendAlertToUser(z, usertrace);
}


/*******************************************************************************

********************************************************************************/
void ZorbaAssert(const char *where, const char *fun, const char *what)
{
  string where_fun (where);
  where_fun += ": "; where_fun += fun;
  ZorbaAlertFactory::error_alert(ZorbaError::XQP0005_SYSTEM_ASSERT_FAILED,
                                 NULL, false, what, where_fun);
}

}
