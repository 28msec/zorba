
////using the C++ API

#include "zorba/zorba_api.h"

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

int apitest_alert_callback(ZorbaAlert *alert_mess, 
                           XQuery*  current_xquery,
                           XQueryExecution* current_xqueryresult,
                           void *param)
{
#ifndef NDEBUG
  if((alert_mess->alert_type != ZorbaAlert::USER_ERROR_ALERT) &&
    (alert_mess->alert_type != ZorbaAlert::USER_TRACE_ALERT))
  {
    cerr << g_error_in_file << " : " << g_error_at_line << endl;
  }
#endif
  cerr << endl;

  DisplayOneAlert(alert_mess);

  cerr.flush();

  return -1;
}

void set_var (string name, string val, DynamicQueryContext_t dctx, XQueryExecution_t result) {
  if (name [name.size () - 1] == ':' && dctx != NULL) {
    dctx->SetVariable (name.substr (0, name.size () - 1), xqp_string (val));
  } else if (name [name.size () - 1] != ':' && result != NULL) {
    ifstream is (val.c_str ());
    assert (is);
    result->SetVariable (name, is);
  }
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
  if(! lProp->inlineQuery()) {
    // read the file
    ifstream  qfile(fname);
    assert (qfile);
 
    {
      string temp;
      query_text = "";
      
      // warning: this method of reading a file might trim the 
      // whitespace at the end of lines
      while (getline(qfile, temp)) {
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

  zorba_factory.initThread();

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

  vector<pair <string, string> > ext_vars = lProp->getExternalVars ();

  XQuery_t query;
  XQueryExecution_t result = NULL;

  DynamicQueryContext_t dctx = zorba_factory.createDynamicContext ();
  for (vector<pair <string, string> >::iterator iter = ext_vars.begin ();
       iter != ext_vars.end (); iter++)
    set_var (iter->first, iter->second, dctx, NULL);

  // create a compiled query
  query = zorba_factory.createQuery(query_text.c_str(), sctx1);

  if(query.isNull())
  {
    goto DisplayErrorsAndExit;
  }

  result = query->createExecution(dctx);
  if(result.isNull())
  {
    goto DisplayErrorsAndExit;
  }

  for (vector<pair <string, string> >::iterator iter = ext_vars.begin ();
       iter != ext_vars.end (); iter++)
    set_var (iter->first, iter->second, NULL, result);

  result->setAlertsParam(result.get_ptr());///to be passed to alerts callback when error occurs

  if (lProp->useResultFile())
    resultFile = new ofstream(lProp->getResultFile().c_str());


  if (lProp->useSerializer()) {
    if (lProp->useResultFile()) {
      result->serialize(*resultFile);
      // endl should not be sent when serializing!
    }
    else result->serialize(std::cout);
  }
  else {
    while( true )
    {
      Item_t it = result->next();
      if(it == NULL)
        break;

      if (resultFile != NULL)
        *resultFile << it->show() <<  endl;
      else
        cout << it->show() << endl;
    }
  }
  if(result->isError()) {
    goto DisplayErrorsAndExit;
  }

  // delete result;
  // delete query;
  // zorba_factory.destroyQuery(query);

  zorba_factory.uninitThread();
  zorba_factory.shutdown();

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

  zorba_factory.uninitThread();
  zorba_factory.shutdown();

  timer.end();
  if (lProp->printTime())
    timer.print(cout);
  
  return 0;
}

