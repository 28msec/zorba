
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

#ifdef UNICODE
#error apitest: UNICODE no longer supported
#endif

int apitest_alert_callback(ZorbaAlert *alert_mess, 
                           XQuery*  current_xquery,
                           XQueryExecution* current_xqueryresult,
                           void *param)
{
#ifndef NDEBUG
  if((alert_mess->alert_type != ZorbaAlert::USER_ERROR_ALERT) &&
    (alert_mess->alert_type != ZorbaAlert::USER_TRACE_ALERT))
  {
    cerr << g_error_in_file << ": " << g_error_at_line << endl;
  }
#endif
  cerr << endl;

  DisplayOneAlert(alert_mess);

  cerr.flush();

  return -1;
}


void set_var (string name, string val,
              DynamicQueryContext_t dctx,
              XQueryExecution_t result)
{
  if (name [name.size () - 1] == ':' && dctx != NULL) 
  {
    dctx->SetVariable(name.substr (0, name.size () - 1), xqp_string(val));
  }
  else if (name[name.size () - 1] != ':' && result != NULL)
  {
    ifstream is (val.c_str ());
    assert (is);
    result->SetVariable(name, val.c_str(), is);
  }
}

void slurp_file (const char *fname, string &result) {
  ifstream qfile(fname); assert (qfile);

  qfile.seekg (-1, ios_base::end);
  size_t len = qfile.tellg ();
  qfile.seekg (0, ios::beg);
  char *str = new char [len];
  qfile.read (str, len);
  
  string sstr (str, len);
  result.swap (sstr);
  delete [] str;
}

#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
  Timer timer;

  if (! Properties::load(argc,argv))
    return 1;
  
  Properties* lProp = Properties::instance();
  
  xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  auto_ptr<ostream> outputFile (lProp->useResultFile() ? new ofstream (lProp->getResultFile().c_str()) : NULL);
  ostream *resultFile = outputFile.get ();
  if (resultFile == NULL)
    resultFile = &cout;
  
  string   query_text = "1+2";  // the default query if no file or query is specified

  g_abort_when_fatal_error = lProp->abortWhenFatalError();

  const char* fname = lProp->getQuery().c_str();

  if (lProp->inlineQuery())
    query_text = fname; 
  else if (*fname != '\0')
    slurp_file (fname, query_text);
  
  if (lProp->printQuery())
    cout << query_text << endl;

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
  sctx1->AddCollation("http://www.flworfound.org/apitest/coll3", "fr");
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
    goto DisplayErrorsAndExit;

  result = query->createExecution(dctx);
  if(result.isNull())
  {
    goto DisplayErrorsAndExit;
  }

  for (vector<pair <string, string> >::iterator iter = ext_vars.begin ();
       iter != ext_vars.end (); iter++)
    set_var (iter->first, iter->second, NULL, result);

  result->setAlertsParam(result.get_ptr());  // to be passed to alerts callback when error occurs

  if (lProp->useSerializer())
  {
    result->serialize(*resultFile);
    // newline should not be sent when serializing!
  } else {
    Item_t it;
    while (NULL != (it = result->next ()).get_ptr ())
      *resultFile << it->show() << endl;
  }

  if (result->isError())
    goto DisplayErrorsAndExit;

  result->close();


DisplayErrorsAndExit:
  DisplayErrorListForCurrentThread();

  zorba_factory.uninitThread();
  zorba_factory.shutdown();

  timer.end();
  if (lProp->printTime())
    timer.print(cout);
  
  return 0;
}

