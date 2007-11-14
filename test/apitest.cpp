

////using the C++ API

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"

//for debug
#include "compiler/parser/xquery_driver.h"
#include "util/logging/loggermanager.hh"
#include "timer.h"
#include "error_display.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace xqp;

#ifdef _DEBUG
extern const char*		xqp::g_error_in_file;
extern int						xqp::g_error_at_line;
#endif

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
					// read the file
					std::ifstream	qfile(fname);
          
					if(!qfile.is_open())
					{
						// couldn't open file, display error and exit
						cerr << "Error opening xquery file <" << fname << ">" << endl;
						return -1;
					}
          string temp;
          query_text = "";
          
          // warning: this method of reading a file might trim the 
          // whitespace at the end of lines
					while (getline(qfile, temp))
          {
            if (query_text != "")
              query_text += "\n";
            
            query_text += temp;
          }          
				}
			}
		}

	///now start the zorba engine

	ZorbaFactory& zorba_factory = ZorbaFactory::getInstance();

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

