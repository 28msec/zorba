
////using the C++ API

#include "zorba_api.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"

//for debug
#include "compiler/parser/xquery_driver.h"
#include "util/logging/loggermanager.hh"
#include "timer.h"
#include "error_display.h"
#include "zorba/util/properties.h"

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace xqp;

int apitest_alert_callback(Zorba_AlertMessage *alert_mess, 
													 XQuery*	current_xquery,
													 XQueryExecution*	current_xqueryresult,
													 void *param)
{
	if((alert_mess->alert_type != Zorba_AlertMessage::USER_ERROR_ALERT) &&
		(alert_mess->alert_type != Zorba_AlertMessage::USER_TRACE_ALERT))
	{
		cerr << g_error_in_file << " : " << g_error_at_line << endl;
	}
	cerr << "(param " << hex << param << " )" << endl;

	DisplayOneAlert(alert_mess);

	cerr.flush();

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

	cout << "reading program options ..."<<endl;

  if (!Properties::load(argc,argv))
	{
	//	cerr << "Cannot find property file" << endl;
		return 1;
	}
	cout << "all program options processed..."<<endl;
  
  Properties* lProp = Properties::instance();
  
	xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  ofstream* resultFile = NULL;
	string		query_text = "1+2";  // the default query if no file or query is specified

///pick up all the runtime options
#ifdef UNICODE
#define TEST_ARGV_FLAG( str ) (_tcscmp(*argv, _T(str)) == 0)
#else
#define TEST_ARGV_FLAG( str ) (*argv == string (str))
#endif

//#ifdef _DEBUG
//  g_abort_when_fatal_error = true;
//#else
  g_abort_when_fatal_error = lProp->abortWhenFatalError();
//#endif

  g_trace_parsing = lProp->traceParsing();
  g_trace_scanning = lProp->traceScanning();
  const char* fname = lProp->getQuery().c_str();
#ifndef UNICODE
  if (lProp->inlineQuery())
    query_text = fname; 
#endif

#ifdef UNICODE
  if(! lProp->inlineQuery())
  {
    char	testfile[1024];
    WideCharToMultiByte(CP_ACP, 0, // or CP_UTF8
                        *argv, -1, 
                        testfile, sizeof(testfile)/sizeof(char),
                        NULL, NULL);
    fname = testfile;
  }
#endif
  if(! lProp->inlineQuery())
  {          
    // read the file
    ifstream	qfile(fname);
    
    if(!qfile.is_open())
    {
      query_text = fname;
    } else {
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



	///now start the zorba engine

	ZorbaFactory& zorba_factory = ZorbaFactory::getInstance();

	///thread specific

	zorba_factory.InitThread();


	///register the alerts callback
	Zorba_AlertsManager&		errmanager = zorba_factory.getAlertsManagerForCurrentThread();

	errmanager.RegisterAlertCallback(apitest_alert_callback, (void*)101);

	///testing the static context!
	StaticQueryContext_t		sctx1;

	sctx1 = zorba_factory.createStaticContext();
	sctx1->AddCollation("http://www.flworfound.org/apitest/coll1", "en");
	sctx1->AddCollation("http://www.flworfound.org/apitest/coll2", "de");
	sctx1->AddCollation("http://www.flworfound.org/apitest/coll2", "fr");
	sctx1->SetOrderingMode(StaticQueryContext::unordered);
	StaticQueryContext::xpath1_0compatib_mode_t		default_compatib_mode;
	default_compatib_mode = sctx1->GetXPath1_0CompatibMode();
	sctx1->AddNamespace("ulu1", "http://www.flworfound.org/apitest/test_ns1");
	sctx1->AddNamespace("ulu2", "http://www.flworfound.org/apitest/test_ns2");
	xqp_string		ns1_uri = sctx1->GetNamespaceURIByPrefix("ulu2");


	XQuery_t		query;
	XQueryExecution_t		result = NULL;
	Item_t		it;

	//create a compiled query
	query = zorba_factory.createQuery(query_text.c_str(), sctx1);

	if(!query.get_ptr())
	{
		goto DisplayErrorsAndExit;
	}


	result = query->createExecution();
	if(!result.get_ptr())
	{
		goto DisplayErrorsAndExit;
	}

	result->setAlertsParam(result.get_ptr());///to be passed to alerts callback when error occurs

	if (lProp->useResultFile())
	{
    resultFile = new ofstream(lProp->getResultFile().c_str());
		//*resultFile << "Iterator run:" << endl << endl;
	}


  if (lProp->useSerializer())
  {
    if (lProp->useResultFile())
	  {
      result->serialize(*resultFile);
      // endl should not be sent when serializing!
    }
    else
    {
      result->serialize(std::cout);
    }
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

  timer.print(cout);
	
  if (resultFile != NULL) {
    resultFile->close();
    delete resultFile;
  }

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

