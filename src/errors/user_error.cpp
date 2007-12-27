
#include "user_error.h"
#include "error_manager.h"
#include "system/zorba.h"
#include "system/zorba_engine.h"

using namespace std;

namespace xqp {


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
    QNameItem* err_qname,///optional
    const std::string description,//optional
    const std::vector<class Item*> *items)//optional
{
	std::string err_decoded;
	Zorba	*z = ZORBA_FOR_CURRENT_THREAD();
	ZorbaAlertsManagerImpl* err_manager = z->getErrorManager();

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
			

			err_decoded = err_manager->getAlertCodes().
                    err_decode((enum AlertCodes::error_code)err_num);
			err_manager->getAlertCodes().ApplyParams(&err_decoded, NULL, NULL);

			///...send err_decoded, description and items to user
		}
	}

	///construct the ask user message for the user
	ZorbaFnErrorAlert* usererr_mess = new ZorbaFnErrorAlert;

	usererr_mess->alert_type = ZorbaAlert::USER_ERROR_ALERT;
	usererr_mess->err_qname = err_qname;
	(std::vector<Item*>)usererr_mess->items_error = *items;///copy the vector of pointers to items
	usererr_mess->alert_description = description;
	usererr_mess->err_qname_decoded = err_decoded;
	time(&usererr_mess->time_of_alert);

	err_manager->sendAlertToUser(z, usererr_mess);

//	cout << "User Error: " << err_decoded << " ( " <<  description << " ) " << endl;
//	DumpItemsAsText(items);
}


void fn_user_trace(
    const std::vector<class Item*> *items,
    const std::string label)
{
	///...send notification message label + items to user
	///construct the ask user message for the user
	ZorbaFnTraceAlert* usertrace_mess = new ZorbaFnTraceAlert;
	Zorba* z = ZORBA_FOR_CURRENT_THREAD();
	ZorbaAlertsManagerImpl* err_manager = z->getErrorManager();

	usertrace_mess->alert_type = ZorbaAlert::USER_TRACE_ALERT;
	(std::vector<Item*>)usertrace_mess->items_trace = *items;///copy the vector of poiters to items
	usertrace_mess->alert_description = label;
	time(&usertrace_mess->time_of_alert);

	err_manager->sendAlertToUser(z, usertrace_mess);

  //	cout << "User Trace: " << label << endl;
  //	DumpItemsAsText(items);
}

}
