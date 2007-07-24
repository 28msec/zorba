

#include "Error.h"
#include <iostream>
#include <iomanip>
#include <stdlib.h>

using namespace std;
namespace xqp {

///static members from ZorbaErrorAlerts
rchandle<error_messages> ZorbaErrorAlerts::err_messages;
zorba*	ZorbaErrorAlerts::zorp;

ZorbaErrorAlerts::ZorbaErrorAlerts( class error_messages *_err_messages,
																	 zorba*	_zorp)
{
	err_messages = _err_messages;
	zorp = _zorp;
}

ZorbaErrorAlerts::~ZorbaErrorAlerts()
{
	(*err_messages).removeReference();
}


void ZorbaErrorAlerts::error_alert( 
														const error_messages::errcode e,///one of predefined error messages in errors.h
														error_messages::error_type errtype,
														const yy::location *ploc, 
														bool continue_execution, ///recoverable (continue execution) ? fatal (throw error)?
														const std::string param1,
														const std::string param2
													 )
{
	if(!ploc)
	{
		if(zorp->current_iterator.empty())
		{
			error_alert_withoutlocation(e, errtype, continue_execution, param1, param2);
			return;
		}
		ploc = &zorp->current_iterator.top()->loc;///get location of current iterator
	}

	std::string err_decoded;
	std::string errtype_decoded;
	std::ostringstream strloc;

	err_decoded = err_messages->err_decode(e);
	errtype_decoded = err_messages->errtype_decode(errtype);

	err_decoded += ": ";
	err_decoded += errtype_decoded;
	err_messages->ApplyParam(&err_decoded, &param1);
	err_messages->ApplyParam(&err_decoded, &param2);

	strloc << *ploc;


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
														const error_messages::errcode e,///one of predefined error messages in errors.h
														error_messages::error_type errtype,
														bool continue_execution, ///recoverable (continue execution) ? fatal (throw error)?
														const std::string param1,
														const std::string param2
													 )
{
	std::string err_decoded;
	std::string errtype_decoded;

	err_decoded = err_messages->err_decode(e);
	errtype_decoded = err_messages->errtype_decode(errtype);

	err_decoded += ": ";
	err_decoded += errtype_decoded;
	err_messages->ApplyParam(&err_decoded, &param1);
	err_messages->ApplyParam(&err_decoded, &param2);



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

void ZorbaErrorAlerts::warning_alert( const error_messages::warning_code warn,
																		 const yy::location *ploc, 
																		 const string param1,
																		 const string param2
																		 )
{
	if(!ploc)
	{
		if(zorp->current_iterator.empty())
		{
			warning_alert_withoutlocation(warn, param1, param2);
			return;
		}
		ploc = &zorp->current_iterator.top()->loc;///get location of current iterator
	}

	std::string warning_decoded;
	std::ostringstream strloc;

	warning_decoded = err_messages->warning_decode(warn);
	err_messages->ApplyParam(&warning_decoded, &param1);
	err_messages->ApplyParam(&warning_decoded, &param2);

	strloc << *ploc;

	//... send error to user app
	cout << "Warning:" << strloc << " : " << warning_decoded << std::endl;

}

void ZorbaErrorAlerts::warning_alert_withoutlocation( 
																		const error_messages::warning_code warn,
																		const string param1,
																		const string param2
																		 )
{
	std::string warning_decoded;

	warning_decoded = err_messages->warning_decode(warn);
	err_messages->ApplyParam(&warning_decoded, &param1);
	err_messages->ApplyParam(&warning_decoded, &param2);

	//... send error to user app
	cout << "Warning:" << "[somewhere.]" << " : " << warning_decoded << std::endl;

}

void ZorbaErrorAlerts::notify_event( const error_messages::NotifyEvent_code notif_event,
													//	const yy::location loc, 
													 const string param1,
													 const string param2
													 )
{
	std::string notif_decoded;

	notif_decoded = err_messages->notify_event_decode(notif_event);
	err_messages->ApplyParam(&notif_decoded, &param1);
	err_messages->ApplyParam(&notif_decoded, &param2);

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

	ask_user_decoded = err_messages->ask_user_decode(ask_string);
	err_messages->ApplyParam(&ask_user_decoded, &param1);
	err_messages->ApplyParam(&ask_user_decoded, &param2);

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
void ZorbaErrorAlerts::user_error (class qname *err_qname,///optional
													const std::string description,//optional
													zorba* zorp,
													const std::vector<class item*> *items)//optional
{
	std::string err_decoded;

	if(err_qname)
	{
		std::string	err_uri;
		std::string	err_localname;

		err_uri = err_qname->uri();
		err_localname = err_qname->localname();

		if(err_uri == "http://www.w3.org/2005/xqt-errors")///a standard error
		{
			///try to identify its description
			int		err_num;

			err_num = atoi(err_localname.substr(4,4).c_str());
			

			err_decoded = err_messages->err_decode((enum error_messages::errcode)err_num);
			err_messages->ApplyParam(&err_decoded, NULL);
			err_messages->ApplyParam(&err_decoded, NULL);

			///...send err_decoded, description and items to user
		}
	}

	cout << "User Error: " << err_decoded << " ( " <<  description << " ) " << endl;
	DumpItemsAsText(zorp, items);

}

void ZorbaErrorAlerts::user_trace ( zorba* zorp,
																		const std::vector<class item*> *items,
																		const std::string label)
{
	///...send notification message label + items to user
	cout << "User Trace: " << label << endl;
	DumpItemsAsText(zorp, items);
}

void ZorbaErrorAlerts::DumpItemsAsText(zorba* zorp, 
										 const std::vector<class item*> *items)
{
	std::vector<class item*>::const_iterator item_it;

	for ( item_it = items->begin( ) ; item_it != items->end( ) ; item_it++ )
	{
		cout	<< " =-= " 
					<< (*item_it)->describe(zorp) 
					<< "[0x" << hex << (void*)(*item_it) << "]";
	}

	cout << " =-= " << endl;
}

}


