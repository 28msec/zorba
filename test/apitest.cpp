

////using the C++ API

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"

//for debug
#include "compiler/parser/xquery_driver.h"
#include "util/logging/loggermanager.hh"
#include "timer.h"
//#include "api/serialization/serializer.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace xqp;

#ifdef _DEBUG
extern const char*		xqp::g_error_in_file;
extern int						xqp::g_error_at_line;
#endif

void DisplayOneAlert(const Zorba_AlertMessage *alert);
void DisplayError(const Zorba_ErrorMessage *err);
void DisplayWarning(const Zorba_WarningMessage *warn);
void DisplayNotification(const Zorba_NotifyMessage *notif);
int DisplayAskUser(const Zorba_AskUserMessage *askuser);
void DisplayFnUserError(const Zorba_FnErrorMessage *fn_err);
void DisplayFnUserTrace(const Zorba_FnTraceMessage *fn_trace);

void DisplayErrorListForCurrentThread()
{
	ZorbaFactory&		zorba_factory = ZorbaFactory::instance();

	Zorba_AlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	///now display the alerts list
	///and then clear the list

	std::list<Zorba_AlertMessage*>::const_iterator		errit;

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

//typedef int alert_callback(Zorba_AlertMessage *alert_mess, 
//													 XQuery_t	current_xquery,
//													 XQueryResult_t	current_xqueryresult,
//													 void *param);
//define one callback function for receiving the xquery alerts
int apitest_alert_callback(Zorba_AlertMessage *alert_mess, 
													 XQuery_t	current_xquery,
													 XQueryResult_t	current_xqueryresult,
													 void *param)
{
	if((alert_mess->alert_type != Zorba_AlertMessage::USER_ERROR_ALERT) &&
		(alert_mess->alert_type != Zorba_AlertMessage::USER_TRACE_ALERT))
	{
		cerr << g_error_in_file << " : " << g_error_at_line << endl;
	}
	cerr << "(param " << std::hex << param << " )" << endl;

	DisplayOneAlert(alert_mess);

	return -1;
}

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
	Timer timer;
	timer.start();

	xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  bool useResultFile = false, inline_query = false;
  bool useSerializer = false;
  std::string resultFileName;
  std::ofstream* resultFile = NULL;
	std::string		query_text = "1+1";///the default query if no file or query is specified

///pick up all the runtime options
#ifdef UNICODE
#define TEST_ARGV_FLAG( str ) (_tcscmp(*argv, _T(str)) == 0)
#else
#define TEST_ARGV_FLAG( str ) (*argv == std::string (str))
#endif

		for (++argv; argv[0]; ++argv) 
		{
			const char *fname;
			
			if (TEST_ARGV_FLAG ("-p")) {
				g_trace_parsing = true;
			} else if (TEST_ARGV_FLAG ("-s")) {
				g_trace_scanning = true;
			} else if (TEST_ARGV_FLAG ("-r")) {
				useSerializer = true;			
			} else if (TEST_ARGV_FLAG ("-o")) {
				useResultFile = true;
        resultFileName = *++argv;
      } else if (TEST_ARGV_FLAG ("-e")) {
        inline_query = true;
			} else {
        fname = *argv;
#ifndef UNICODE
        if (inline_query) {
        //  fname = "zorba_query.tmp";
        //  ofstream qf (fname);
        //  qf << *argv;
 					query_text = *argv;
       }
#endif
#ifdef UNICODE
        if(! inline_query)
				{
					char	testfile[1024];
					WideCharToMultiByte(CP_ACP, 0, // or CP_UTF8
															*argv, -1, 
															testfile, sizeof(testfile)/sizeof(char),
															NULL, NULL);
					fname = testfile;
				}
#endif
				if(!inline_query)
				{          
					///read the file
					std::ifstream	qfile(fname);
					//istringstream		iss;
          
          string temp;
          query_text = "";
          
          // warning: this method of reading a file will trim the 
          // whitespace at the end of lines
					while (qfile >> temp)
          {
            if (query_text != "")
              query_text += "\n";
            
            query_text += temp;
          }
				}
			}
		}

	///now start the zorba engine

	ZorbaFactory&		zorba_factory = ZorbaFactory::instance();

	///thread specific

	zorba_factory.InitThread();


	///register the alerts callback
	Zorba_AlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	errmanager.RegisterAlertCallback(apitest_alert_callback, (void*)101);

	XQuery_t		query;
	XQueryResult_t		result = NULL;
	Item_t		it;

	//create a compiled query
	query = zorba_factory.createQuery(query_text.c_str());

//	if(!query->compile())
//	{
//		goto DisplayErrorsAndExit;
//	}
	if(!query.get_ptr())
	{
		goto DisplayErrorsAndExit;
	}


	result = query->execute();
	if(!result.get_ptr())
	{
		goto DisplayErrorsAndExit;
	}

	result->setAlertsParam(result.get_ptr());///to be passed to alerts callback when error occurs

	if (useResultFile)
	{
		resultFile = new ofstream(resultFileName.c_str());
		//*resultFile << "Iterator run:" << std::endl << std::endl;
	}


 	if (useSerializer)
	{
		// *resultFile << i_p->show() << endl;
	//	serializer* ser = new serializer();
	//	ser->serialize(result, *resultFile);
		result->serializeXML(*resultFile);
		*resultFile << endl;
	}
	else
	{
		while( true )
		{
			it = result->next();
			if(it == NULL)
				break;

      if (resultFile != NULL)
				*resultFile << it->show() <<	endl;
			else
				cout << it->show() << endl;
		}
	}
	if(result->isError())
	{
		goto DisplayErrorsAndExit;
	}

	//delete result;
	//delete query;
//	zorba_factory.destroyQuery(query);

	zorba_factory.UninitThread();
	ZorbaFactory::shutdownZorbaEngine();

	timer.end();

  //if (resultFile != NULL)
  //{
  //  *resultFile << std::endl;
  //  timer.print(*resultFile);
  //}
  //else
    timer.print(cout);

	delete resultFile;

	return 0;

DisplayErrorsAndExit:
	cerr << endl << "Display all error list now:" << endl;

	DisplayErrorListForCurrentThread();

	zorba_factory.UninitThread();
	ZorbaFactory::shutdownZorbaEngine();

	timer.end();

	timer.print(cout);
	
	return -1;
}

