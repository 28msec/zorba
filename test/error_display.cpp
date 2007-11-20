
#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "error_display.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace xqp;

void DisplayErrorListForCurrentThread()
{
	ZorbaFactory& zorba_factory = ZorbaFactory::getInstance();

	Zorba_AlertsManager& errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	///now display the alerts list and then clear the list

	std::list<Zorba_AlertMessage*>::const_iterator errit;

	for(errit = errmanager.begin(); errit != errmanager.end(); errit++)
	{
		DisplayOneAlert(*errit);
	}

	errmanager.clearAlertList();
}


void DisplayOneAlert(const Zorba_AlertMessage *alert)
{
	char	*str_talert;

	str_talert = asctime(localtime(&alert->time_of_alert));
	cerr << str_talert << " ";

	switch(alert->alert_type)
	{
	case Zorba_AlertMessage::ERROR_ALERT:
		DisplayError(reinterpret_cast<const Zorba_ErrorMessage*>(alert));
		break;
	case Zorba_AlertMessage::WARNING_ALERT:
		DisplayWarning(reinterpret_cast<const Zorba_WarningMessage*>(alert));
		break;
	case Zorba_AlertMessage::NOTIFICATION_ALERT:
		DisplayNotification(reinterpret_cast<const Zorba_NotifyMessage*>(alert));
		break;
	case Zorba_AlertMessage::FEEDBACK_REQUEST_ALERT:
		DisplayAskUser(reinterpret_cast<const Zorba_AskUserMessage*>(alert));
		break;

	case Zorba_AlertMessage::USER_ERROR_ALERT://fn:error
		DisplayFnUserError(reinterpret_cast<const Zorba_FnErrorMessage*>(alert));
		break;
	case Zorba_AlertMessage::USER_TRACE_ALERT://fn:trace
		DisplayFnUserTrace(reinterpret_cast<const Zorba_FnTraceMessage*>(alert));
		break;
	}
}


void DisplayError(const Zorba_ErrorMessage *err)
{
	if(err->is_fatal)
		cerr << "Fatal Error: ";
	else
		cerr << "Error: ";

	if(err->loc.line)
	{
		if(err->loc.filename)
			cerr << *err->loc.filename;
		cerr << "[line: " << err->loc.line << "][col: " << err->loc.column << "]";
	}	

	cerr << " : " << err->alert_description << std::endl;
}


void DisplayWarning(const Zorba_WarningMessage *warn)
{
	cerr << "Warning:";
	if(warn->loc.line)
	{
		if(warn->loc.filename)
			cerr << *warn->loc.filename;
		cerr << "[line: " << warn->loc.line << "][col: " << warn->loc.column << "]";
	}	

	cerr << " : " << warn->alert_description << std::endl;
}


void DisplayNotification(const Zorba_NotifyMessage *notif)
{
	cerr << "Notif: " << notif->alert_description << std::endl;
}


int DisplayAskUser(const Zorba_AskUserMessage *askuser)
{
	///not implemented
	cerr << "Ask user: " << askuser->alert_description << std::endl;
	return -1;///normaly return the user choice: 0, 1, 2, ...
}


void DumpItemsAsText( const std::vector<class Item*> *items)
{
	std::vector<class Item*>::const_iterator item_it;

	for ( item_it = items->begin( ) ; item_it != items->end( ) ; item_it++ )
	{
		cerr	<< " =-= " 
					<< (*item_it)->getStringProperty() 
					<< "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
	}

//	cerr << " =-= " << std::endl;
}


void DisplayFnUserError(const Zorba_FnErrorMessage *fn_err)
{
	cerr << "User Error: ";
	cerr << "[QName: " << fn_err->err_qname->getStringProperty() 
		<< "<decoded: " << fn_err->err_qname_decoded << " > ]";
	cerr << " : " <<  fn_err->alert_description << endl;
	DumpItemsAsText(&fn_err->items_error);
}


void DisplayFnUserTrace(const Zorba_FnTraceMessage *fn_trace)
{
	cerr << "User Trace: " << fn_trace->alert_description << endl;
	DumpItemsAsText(&fn_trace->items_trace);
}

