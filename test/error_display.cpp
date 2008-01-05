
#include "zorba/zorba_api.h"
#include "error_display.h"

#include <fstream>
#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;
using namespace xqp;

void DisplayErrorListForCurrentThread()
{
  ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

  ZorbaAlertsManager& errmanager = zorba_factory.getAlertsManagerForCurrentThread();

  ///now display the alerts list and then clear the list

  std::list<ZorbaAlert*>::const_iterator errit;

  for(errit = errmanager.begin(); errit != errmanager.end(); errit++)
  {
    if (errit == errmanager.begin())
      cerr << endl << "Error list:" << endl;
    
    DisplayOneAlert(*errit);
  }

  errmanager.clearAlertList();
}


void DisplayOneAlert(const ZorbaAlert *alert)
{
  char  *str_talert;

  str_talert = asctime(localtime(&alert->time_of_alert));
  cerr << str_talert << " ";

  switch(alert->alert_type)
  {
  case ZorbaAlert::ERROR_ALERT:
    DisplayError(reinterpret_cast<const ZorbaErrorAlert*>(alert));
    break;
  case ZorbaAlert::WARNING_ALERT:
    DisplayWarning(reinterpret_cast<const ZorbaWarningAlert*>(alert));
    break;
  case ZorbaAlert::NOTIFICATION_ALERT:
    DisplayNotification(reinterpret_cast<const ZorbaNotifyAlert*>(alert));
    break;
  case ZorbaAlert::FEEDBACK_REQUEST_ALERT:
    DisplayAskUser(reinterpret_cast<const ZorbaAskUserAlert*>(alert));
    break;

  case ZorbaAlert::USER_ERROR_ALERT://fn:error
    DisplayFnUserError(reinterpret_cast<const ZorbaFnErrorAlert*>(alert));
    break;
  case ZorbaAlert::USER_TRACE_ALERT://fn:trace
    DisplayFnUserTrace(reinterpret_cast<const ZorbaFnTraceAlert*>(alert));
    break;
  }
}


void DisplayError(const ZorbaErrorAlert *err)
{
  if(err->is_fatal)
    cerr << "Fatal Error: ";
  else
    cerr << "Error: ";

  if(err->loc.line)
  {
    if(!err->loc.filename.empty())
      cerr << err->loc.filename;
    cerr << "[line: " << err->loc.line << "][col: " << err->loc.column << "]: ";
  } 

  cerr << err->alert_description << std::endl;
}


void DisplayWarning(const ZorbaWarningAlert *warn)
{
  cerr << "Warning:";
  if(warn->loc.line)
  {
    if(!warn->loc.filename.empty())
      cerr << warn->loc.filename;
    cerr << "[line: " << warn->loc.line << "][col: " << warn->loc.column << "]";
  } 

  cerr << " : " << warn->alert_description << std::endl;
}


void DisplayNotification(const ZorbaNotifyAlert *notif)
{
  cerr << "Notif: " << notif->alert_description << std::endl;
}


int DisplayAskUser(const ZorbaAskUserAlert *askuser)
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
    cerr  << " =-= " 
          << (*item_it)->getStringProperty() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }

//  cerr << " =-= " << std::endl;
}


void DisplayFnUserError(const ZorbaFnErrorAlert *fn_err)
{
  cerr << "User Error: ";
  cerr << "[QName: " << fn_err->err_qname->getStringProperty() 
    << "<decoded: " << fn_err->err_qname_decoded << " > ]";
  cerr << " : " <<  fn_err->alert_description << endl;
  DumpItemsAsText(&fn_err->items_error);
}


void DisplayFnUserTrace(const ZorbaFnTraceAlert *fn_trace)
{
  cerr << "User Trace: " << fn_trace->alert_description << endl;
  DumpItemsAsText(&fn_trace->items_trace);
}

