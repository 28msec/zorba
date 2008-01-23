
#include "zorba/zorba_singlethread.h"
#include "zorba/zorba_api.h"

#include <iostream>

using namespace std;
using namespace xqp;

/*
	Using Zorba in single thread mode.
	Init the engine, create a query and execute it.
	How to retrieve and print error messages.
	The error printing functions use zorba in full api mode.
	You can find the error codes and error classes in zorba/errors/errors.h.
*/



extern void DisplayOneAlert(const xqp::ZorbaAlert *alert, std::ostream &result_file);
extern void DisplayError(const xqp::ZorbaError *err, std::ostream &result_file);
extern void DisplayWarning(const xqp::ZorbaWarning *warn, std::ostream &result_file);
extern void DisplayNotification(const xqp::ZorbaNotify *notif, std::ostream &result_file);
extern int DisplayAskUser(const xqp::ZorbaAskUser *askuser, std::ostream &result_file);
extern void DisplayFnUserError(const xqp::ZorbaFnError *fn_err, std::ostream &result_file);
extern void DisplayFnUserTrace(const xqp::ZorbaFnTrace *fn_trace, std::ostream &result_file);

void DisplayErrorListForCurrentThread(std::ostream &result_file)
{
  ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

  ZorbaAlertsManager& errmanager = zorba_factory.getAlertsManagerForCurrentThread();

  ///now display the alerts list and then clear the list

  std::list<ZorbaAlert*>::const_iterator errit;

  for(errit = errmanager.begin(); errit != errmanager.end(); errit++)
  {
    if (errit == errmanager.begin())
      result_file << endl << "Error list:" << endl;
    
    DisplayOneAlert(*errit, result_file);
  }

  errmanager.clearAlertList();
}


void DisplayOneAlert(const ZorbaAlert *alert, std::ostream &result_file)
{
  char  *str_talert;

  str_talert = asctime(localtime(&alert->theTime));
  result_file << str_talert << " ";

  switch(alert->theKind)
  {
  case ZorbaAlert::ERROR_ALERT:
    DisplayError(reinterpret_cast<const ZorbaError*>(alert), result_file);
    break;
  case ZorbaAlert::WARNING_ALERT:
    DisplayWarning(reinterpret_cast<const ZorbaWarning*>(alert), result_file);
    break;
  case ZorbaAlert::NOTIFICATION_ALERT:
    DisplayNotification(reinterpret_cast<const ZorbaNotify*>(alert), result_file);
    break;
  case ZorbaAlert::FEEDBACK_REQUEST_ALERT:
    DisplayAskUser(reinterpret_cast<const ZorbaAskUser*>(alert), result_file);
    break;

  case ZorbaAlert::USER_ERROR_ALERT://fn:error
    DisplayFnUserError(reinterpret_cast<const ZorbaFnError*>(alert), result_file);
    break;
  case ZorbaAlert::USER_TRACE_ALERT://fn:trace
    DisplayFnUserTrace(reinterpret_cast<const ZorbaFnTrace*>(alert), result_file);
    break;
  }
}


void DisplayError(const ZorbaError *err, std::ostream &result_file)
{
//  if(err->theIsFatal)
//    result_file << "Fatal Error: ";
//  else
    result_file << "Error: ";

  if(err->theLocation.line)
  {
    if(!err->theLocation.filename.empty())
      result_file << err->theLocation.filename;

    result_file << "[line: " << err->theLocation.line
                << "][col: " << err->theLocation.column << "]: ";
  } 

  result_file << err->theDescription << std::endl;
}


void DisplayWarning(const ZorbaWarning *warn, std::ostream &result_file)
{
  result_file << "Warning:";
  if(warn->theLocation.line)
  {
    if(!warn->theLocation.filename.empty())
      result_file << warn->theLocation.filename;

    result_file << "[line: " << warn->theLocation.line << "][col: "
                << warn->theLocation.column << "]";
  } 

  result_file << " : " << warn->theDescription << std::endl;
}


void DisplayNotification(const ZorbaNotify *notif, std::ostream &result_file)
{
  result_file << "Notif: " << notif->theDescription << std::endl;
}


int DisplayAskUser(const ZorbaAskUser *askuser, std::ostream &result_file)
{
  ///not implemented
  result_file << "Ask user: " << askuser->theDescription << std::endl;
  return -1;///normaly return the user choice: 0, 1, 2, ...
}


void DumpItemsAsText( const std::vector<class Item*> *items, std::ostream &result_file)
{
  std::vector<class Item*>::const_iterator item_it;

  for ( item_it = items->begin( ) ; item_it != items->end( ) ; item_it++ )
  {
    result_file  << " =-= " 
          << (*item_it)->getStringProperty() 
          << "  [0x" << std::hex << (void*)(*item_it) << "]" << endl;
  }

//  result_file << " =-= " << std::endl;
}


void DisplayFnUserError(const ZorbaFnError *fn_err, std::ostream &result_file)
{
  result_file << "User Error: ";
  result_file << "[QName: " << fn_err->theErrorQName->getStringProperty() 
    << "<decoded: " << fn_err->theDescription << " > ]";
  result_file << " : " <<  fn_err->theUserDescription << endl;
  DumpItemsAsText(&fn_err->theItems, result_file);
}


void DisplayFnUserTrace(const ZorbaFnTrace *fn_trace, std::ostream &result_file)
{
  result_file << "User Trace: " << fn_trace->theDescription << endl;
  DumpItemsAsText(&fn_trace->items_trace, result_file);
}


string make_absolute_file_name(const char *target_file_name, const char *this_file_name);


int usecase5(int argc, char* argv[])
{
	//init the engine
	ZorbaSingleThread		&zorba_engine = ZorbaSingleThread::getInstance();
	XQuery_t				xquery;
	DynamicQueryContext_t		dctx;

	//create and compile a query with the static context
	xquery = zorba_engine.createQuery(".//book");
	if(xquery == NULL)
	{
		cout << "Error creating and compiling query" << endl;
		goto DisplayErrorsAndExit;
		return 1;
	}
	dctx = zorba_engine.createDynamicContext();
/*forget to set the context item
	//context item is set as variable with reserved name "."
	if(!dctx->SetVariableAsDocument(".", make_absolute_file_name("books.xml", __FILE__)))
	{
		assert(false);
		return 1;
	}
*/

	//execute the query and serialize its result
	if(!xquery->executeSerializeXML(std::cout, dctx))
	{
		cout << "Error executing and serializing query" << endl;
		goto DisplayErrorsAndExit;
		return 1;
	}

	//shutdown the engine, just for exercise
	zorba_engine.shutdown();
	//using zorba objects after this moment is prohibited

	assert(false);//unreachable, should exit on error way

	return 0;

DisplayErrorsAndExit:
	
	DisplayErrorListForCurrentThread(std::cout);

	zorba_engine.shutdown();

	return -1; 

}
