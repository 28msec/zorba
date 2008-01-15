
////using the C++ API

#include "zorba/zorba_api.h"

//for debug
//#include "../src/compiler/parser/xquery_driver.h"
#include "../src/util/logging/loggermanager.hh"
#include "timer.h"
#include "error_display.h"
//#include "errors/error_factory.h"
#include "zorba/util/properties.h"

#ifdef WIN32
	#include "../src/util/win32/compatib_defs.h"
#endif

#include <fstream>
#include <iostream>
#include <iomanip>

namespace xqp{
#ifndef NDEBUG
extern const char*		g_error_in_file;
extern int						g_error_at_line;
extern bool						g_abort_when_fatal_error;
#endif
}

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
  if ((alert_mess->theKind != ZorbaAlert::USER_ERROR_ALERT) &&
      (alert_mess->theKind != ZorbaAlert::USER_TRACE_ALERT) &&
      g_error_in_file != NULL)
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
	//	XmlDataManager_t		store = ZorbaEngine::getInstance().getXmlDataManager();
	//	store->loadDocument(val.c_str (), is);
	//	dctx->SetVariableAsDocument(name, val.c_str());
  }
}

void slurp_file (const char *fname, string &result) {
  ifstream qfile(fname); assert (qfile);

  qfile.seekg (0, ios::end);
  size_t len = qfile.tellg ();
  qfile.seekg (0, ios::beg);
  char *str = new char [len];
  qfile.read (str, len);
  
  string sstr (str, len);
  result.swap (sstr);
  delete [] str;
}

class ZorbaEngineWrapper {
public:
  ZorbaEngine &factory;
  StaticQueryContext_t sctx;

  ZorbaEngineWrapper (alert_callback alert_cb = NULL, void *alert_param = NULL)
    : factory (ZorbaEngine::getInstance())
  {
    factory.initThread();
    /// register the alerts callback
    ZorbaAlertsManager& errmanager = factory.getAlertsManagerForCurrentThread();
    
    if (alert_cb != NULL)
      errmanager.RegisterAlertCallback(alert_cb, alert_param);

    sctx = factory.createStaticContext();
    sctx->AddCollation("http://www.flworfound.org/apitest/coll1", "en");
    sctx->AddCollation("http://www.flworfound.org/apitest/coll2", "de");
    sctx->AddCollation("http://www.flworfound.org/apitest/coll3", "fr");
    sctx->SetOrderingMode(StaticQueryContext::unordered);
  }
  ~ZorbaEngineWrapper () {
    DisplayErrorListForCurrentThread();

    factory.uninitThread();
    factory.shutdown();
  }

  XQueryExecution_t createExecution (XQuery_t query, const vector< pair <string, string> > &vars) {
    DynamicQueryContext_t dctx = factory.createDynamicContext ();
    for (vector<pair <string, string> >::const_iterator iter = vars.begin ();
         iter != vars.end (); iter++)
      set_var (iter->first, iter->second, dctx, NULL);
    
    XQueryExecution_t result = query->createExecution(dctx);

    if(! result.isNull()) {
      for (vector<pair <string, string> >::const_iterator iter = vars.begin ();
           iter != vars.end (); iter++)
        set_var (iter->first, iter->second, NULL, result);
    }
    
    return result;
  }
};

class TimePrinter {
  Timer timer;
public:
  TimePrinter () {}
  ~TimePrinter () {
    timer.end();
    timer.print(cout);    
  }
};

// TODO: for now apitest users expect 0 even for error results; this should change
#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{
  if (! Properties::load(argc,argv))
    return 1;  
  Properties* lProp = Properties::instance();

  // start timer as soon as possible, if enabled
  auto_ptr<TimePrinter> timer (lProp->printTime() ? new TimePrinter : NULL);
  
#ifndef NDEBUG
  g_abort_when_fatal_error = lProp->abortWhenFatalError();
#endif

  xqp::LoggerManager::logmanager()->setLoggerConfig("#1#logging.log");

  // output file
  auto_ptr<ostream> outputFile (lProp->useResultFile() ?
                                new ofstream (lProp->getResultFile().c_str()) :
                                NULL);
  ostream *resultFile = outputFile.get ();
  if (resultFile == NULL)
    resultFile = &cout;
  
  // query text
  const char* fname = lProp->getQuery().c_str();
  string query_text = "1+2";  // the default query if no file or query is specified
  if (lProp->inlineQuery())
    query_text = fname; 
  else if (*fname != '\0')
    slurp_file (fname, query_text);
  if (lProp->printQuery())
    cout << query_text << endl;

  // start the zorba engine
  ZorbaEngineWrapper zengine (apitest_alert_callback, (void*) 101);

  // compile query
  XQuery_t query = zengine.factory.createQuery(query_text.c_str(), zengine.sctx);
  if (query.isNull ())
    return 0;

  // create dynamic context and execution
  vector<pair <string, string> > ext_vars = lProp->getExternalVars ();
  XQueryExecution_t result = zengine.createExecution (query, ext_vars);

  result->setAlertsParam(result.get_ptr());  // to be passed to alerts callback when error occurs

  if (lProp->useSerializer()) {
    result->serialize(*resultFile);
    // newline should not be sent when serializing!
  } else {
    Item_t it;
    while (NULL != (it = result->next ()).get_ptr ())
      *resultFile << it->show() << endl;
  }
  
  result->close ();

  if (result->isError ())
    return 0;

  return 0;
}
