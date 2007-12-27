
////using the C++ API

#include "zorba/zorba_api.h"
//#include "store/naive/basic_item_factory.h"
//#include "store/naive/simple_store.h"

//for debug
//#include "../src/compiler/parser/xquery_driver.h"
#include "../src/util/logging/loggermanager.hh"
#include "timer.h"
#include "error_display.h"
#include "zorba/util/properties.h"

#ifdef WIN32
	#include "../src/util/win32/compatib_defs.h"
#endif

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace xqp;
using namespace std;

int apitest_alert_callback(Zorba_AlertMessage *alert_mess, 
                           XQuery*  current_xquery,
                           XQueryExecution* current_xqueryresult,
                           void *param)
{
#ifndef NDEBUG
  if((alert_mess->alert_type != Zorba_AlertMessage::USER_ERROR_ALERT) &&
    (alert_mess->alert_type != Zorba_AlertMessage::USER_TRACE_ALERT))
  {
    cerr << g_error_in_file << " : " << g_error_at_line << endl;
  }
#endif
  cerr << endl;

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


  if (!Properties::load(argc,argv))
    return 1;
  
  Properties* lProp = Properties::instance();
  
  xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  ofstream* resultFile = NULL;
  string    query_text = "1+2";  // the default query if no file or query is specified

// pick up all the runtime options
#ifdef UNICODE
#define TEST_ARGV_FLAG( str ) (_tcscmp(*argv, _T(str)) == 0)
#else
#define TEST_ARGV_FLAG( str ) (*argv == string (str))
#endif

#ifndef NDEBUG
  g_abort_when_fatal_error = lProp->abortWhenFatalError();
#endif

  const char* fname = lProp->getQuery().c_str();
#ifndef UNICODE
  if (lProp->inlineQuery())
    query_text = fname; 
#endif

#ifdef UNICODE
  if(! lProp->inlineQuery())
  {
    char  testfile[1024];
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
    ifstream  qfile(fname);
    
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
  
  if (lProp->printQuery())
    std::cout << query_text << std::endl;


  /// now start the zorba engine

  ZorbaEngine& zorba_factory = ZorbaEngine::getInstance();

  /// thread specific

  zorba_factory.InitThread();

  /// register the alerts callback
  ZorbaAlertsManager& errmanager = zorba_factory.getAlertsManagerForCurrentThread();

  errmanager.RegisterAlertCallback(apitest_alert_callback, (void*)101);

  StaticQueryContext_t sctx1;

  sctx1 = zorba_factory.createStaticContext();
  sctx1->AddCollation("http://www.flworfound.org/apitest/coll1", "en");
  sctx1->AddCollation("http://www.flworfound.org/apitest/coll2", "de");
  sctx1->AddCollation("http://www.flworfound.org/apitest/coll2", "fr");
  sctx1->SetOrderingMode(StaticQueryContext::unordered);
  StaticQueryContext::xpath1_0compatib_mode_t   default_compatib_mode;
  default_compatib_mode = sctx1->GetXPath1_0CompatibMode();

  XQuery_t    query;
  XQueryExecution_t   result = NULL;
  Item_t    it;

  // create a compiled query
  query = zorba_factory.createQuery(query_text.c_str(), sctx1);

  if(query.isNull())
  {
    goto DisplayErrorsAndExit;
  }


  result = query->createExecution();
  if(result.isNull())
  {
    goto DisplayErrorsAndExit;
  }

  {
    vector<pair <string, string> > ext_vars = lProp->getExternalVars ();
    for (vector<pair <string, string> >::iterator iter = ext_vars.begin ();
         iter != ext_vars.end (); iter++) {
      pair<string, string> b = *iter;
      ifstream is (b.second.c_str ());
      result->SetVariable (b.first, is);
    }
  }

  result->setAlertsParam(result.get_ptr());///to be passed to alerts callback when error occurs

  if (lProp->useResultFile())
  {
    resultFile = new ofstream(lProp->getResultFile().c_str());
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
        *resultFile << it->show() <<  endl;
      else
        cout << it->show() << endl;
    }
  }
  if(result->isError())
  {
    goto DisplayErrorsAndExit;
  }

  // delete result;
  // delete query;
  // zorba_factory.destroyQuery(query);

  zorba_factory.UninitThread();
  ZorbaEngine::shutdownZorbaEngine();

  timer.end();

  if (lProp->printTime())
    timer.print(cout);
  
  if (resultFile != NULL) {
    resultFile->close();
    delete resultFile;
  }

  return 0;

DisplayErrorsAndExit:
  cerr << endl << "Error list:" << endl;

  DisplayErrorListForCurrentThread();

  zorba_factory.UninitThread();
  ZorbaEngine::shutdownZorbaEngine();

  timer.end();
  if (lProp->printTime())
    timer.print(cout);
  
  return 0;
}

