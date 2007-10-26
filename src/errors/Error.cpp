

#include "Error.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "util/zorba.h"
#include "../store/api/item.h"
#include "zorba_api.h"
#include "runtime/base/iterator.h"

using namespace std;
namespace xqp {


ZorbaErrorAlerts::ZorbaErrorAlerts( )//class error_messages *_err_messages)
{
//	err_messages = _err_messages;
	errmanager_api = new Zorba_AlertsManager;
}

ZorbaErrorAlerts::~ZorbaErrorAlerts()
{
	(*err_messages).removeReference();
	errmanager_api->removeReference();
}


void ZorbaErrorAlerts::error_alert( 
												//		const char *file,
												//		const int line,
														const error_messages::errcode e,///one of predefined error messages in errors.h
														error_messages::error_type errtype,
														const yy::location *ploc, 
														bool continue_execution, ///recoverable (continue execution) ? fatal (throw error)?
														const std::string param1,
														const std::string param2
													 )
{
	zorba*	z = zorba::getZorbaForCurrentThread();
	if(!ploc)
	{
		if(z->current_iterator.empty())
		{
			error_alert_withoutlocation(e, errtype, continue_execution, param1, param2);
			return;
		}
		ploc = &z->current_iterator.top()->loc;///get location of current iterator
	}

	std::string err_decoded;
	std::string errtype_decoded;
	std::ostringstream strloc;

	err_decoded = z->getErrorManager()->err_messages->err_decode(e);
	errtype_decoded = z->getErrorManager()->err_messages->errtype_decode(errtype);

	err_decoded += ": ";
	err_decoded += errtype_decoded;
	z->getErrorManager()->err_messages->ApplyParam(&err_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&err_decoded, &param2);

	strloc << *ploc;


//	cout << file << "[" << line << "]:" << endl;

	if(!continue_execution)
	{
		cout << "Fatal Error:" << strloc << " : " << err_decoded << std::endl;
		throw xqp_exception(strloc.str(), err_decoded);
	}
	else
	{
		//... send error to user app

		cout << "Error:" << strloc << " : " << err_decoded << std::endl;
	}
}

void ZorbaErrorAlerts::error_alert_withoutlocation( 
													//	const char *file,
													//	const int line,
														const error_messages::errcode e,///one of predefined error messages in errors.h
														error_messages::error_type errtype,
														bool continue_execution, ///recoverable (continue execution) ? fatal (throw error)?
														const std::string param1,
														const std::string param2
													 )
{
	std::string err_decoded;
	std::string errtype_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();

	err_decoded = z->getErrorManager()->err_messages->err_decode(e);
	errtype_decoded = z->getErrorManager()->err_messages->errtype_decode(errtype);

	err_decoded += ": ";
	err_decoded += errtype_decoded;
	z->getErrorManager()->err_messages->ApplyParam(&err_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&err_decoded, &param2);


//	cout << file << "[" << line << "]:" << endl;

	if(!continue_execution)
	{
		cout << "Fatal Error:" << "[somewhere.]" << " : " << err_decoded << std::endl;
		throw xqp_exception("[somewhere.]", err_decoded);
	}
	else
	{
		//... send error to user app

		cout << "Error:" << "[somewhere.]" << " : " << err_decoded << std::endl;
	}
}

void ZorbaErrorAlerts::warning_alert( 
																		//	const char *file,
																		//	const int line,
																			const error_messages::warning_code warn,
																			const yy::location *ploc, 
																			const string param1,
																			const string param2
																		 )
{
	zorba	*z = zorba::getZorbaForCurrentThread();
	if(!ploc)
	{
		if(z->current_iterator.empty())
		{
			warning_alert_withoutlocation(warn, param1, param2);
			return;
		}
		ploc = &z->current_iterator.top()->loc;///get location of current iterator
	}

	std::string warning_decoded;
	std::ostringstream strloc;

	warning_decoded = z->getErrorManager()->err_messages->warning_decode(warn);
	z->getErrorManager()->err_messages->ApplyParam(&warning_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&warning_decoded, &param2);

	strloc << *ploc;

//	cout << file << "[" << line << "]:" << endl;

	//... send error to user app
	cout << "Warning:" << strloc << " : " << warning_decoded << std::endl;

}

void ZorbaErrorAlerts::warning_alert_withoutlocation( 
																	//	const char *file,
																	//	const int line,
																		const error_messages::warning_code warn,
																		const string param1,
																		const string param2
																		 )
{
	std::string warning_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();

	warning_decoded = z->getErrorManager()->err_messages->warning_decode(warn);
	z->getErrorManager()->err_messages->ApplyParam(&warning_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&warning_decoded, &param2);

//	cout << file << "[" << line << "]:" << endl;

	//... send error to user app
	cout << "Warning:" << "[somewhere.]" << " : " << warning_decoded << std::endl;

}

void ZorbaErrorAlerts::notify_event( 
													//	const char *file,
													//	const int line,
														const error_messages::NotifyEvent_code notif_event,
													//	const yy::location loc, 
														const string param1,
														const string param2
													 )
{
	std::string notif_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();

	notif_decoded = z->getErrorManager()->err_messages->notify_event_decode(notif_event);
	z->getErrorManager()->err_messages->ApplyParam(&notif_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&notif_decoded, &param2);

//	cout << file << "[" << line << "]:" << endl;

	cout << " --> " << notif_decoded << std::endl;

}


	///return the index of the option chosen by user
int ZorbaErrorAlerts::ask_user( const error_messages::AskUserString_code ask_string,
												const error_messages::AskUserStringOptions_code ask_string_options,
												const string param1,
												const string param2
												)
{
	std::string ask_user_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();

	ask_user_decoded = z->getErrorManager()->err_messages->ask_user_decode(ask_string);
	z->getErrorManager()->err_messages->ApplyParam(&ask_user_decoded, &param1);
	z->getErrorManager()->err_messages->ApplyParam(&ask_user_decoded, &param2);

	cout << "[]Ask User " << ask_user_decoded << "(not implemented)" << endl;

	return -1;///not implemented
}



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
void ZorbaErrorAlerts::user_error (Item* err_qname,///optional
													const std::string description,//optional
													const std::vector<class Item*> *items)//optional
{
	std::string err_decoded;
	zorba	*z = zorba::getZorbaForCurrentThread();

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
			

			err_decoded = z->getErrorManager()->err_messages->err_decode((enum error_messages::errcode)err_num);
			z->getErrorManager()->err_messages->ApplyParam(&err_decoded, NULL);
			z->getErrorManager()->err_messages->ApplyParam(&err_decoded, NULL);

			///...send err_decoded, description and items to user
		}
	}

	cout << "User Error: " << err_decoded << " ( " <<  description << " ) " << endl;
	DumpItemsAsText(items);

}

void ZorbaErrorAlerts::user_trace ( 
																		const std::vector<class Item*> *items,
																		const std::string label)
{
	///...send notification message label + items to user
	cout << "User Trace: " << label << endl;
	DumpItemsAsText(items);
}

void ZorbaErrorAlerts::DumpItemsAsText( const std::vector<class Item*> *items)
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

}


