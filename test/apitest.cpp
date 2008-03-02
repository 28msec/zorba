
////using the C++ API

#include <zorba/zorba_api.h>

#include "../src/util/logging/loggermanager.hh"
#include "timer.h"
#include <zorba/properties.h>


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

int apitest_alert_callback(ZorbaAlert_t alert_mess, 
                           XQuery *current_xquery,
													 ResultIterator	*current_result,
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

//  DisplayOneAlert(alert_mess);
	alert_mess->dumpAlert(cerr);

  cerr.flush();

  return -1;
}


void set_var (string name, string val,
              DynamicQueryContext_t dctx,
              XQuery_t query)
{
  if (name [name.size () - 1] == ':' && dctx != NULL) 
  {
		bool result;
		if(name != ".")
			result = dctx->setVariableAsString(name.substr (0, name.size () - 1), xqp_string(val));
		else
			result = dctx->setContextItemAsString(xqp_string(val));
    assert (result);
  }
  else if (name[name.size () - 1] != ':' && query != NULL)
  {
    ifstream is (val.c_str ());
    assert (is);
		if(name != ".")
			query->setVariableAsDocumentFromStream(name, val.c_str(), is);
		else
			query->setContextItemAsDocumentFromStream(val.c_str(), is);
  }
}

void slurp_file (const char *fname, string &result) {
  ifstream qfile(fname, ios::binary | ios_base::in); assert (qfile);

  qfile.seekg (0, ios::end);
  size_t len = qfile.tellg ();
  qfile.seekg (0, ios::beg);
  char *str = new char [len];
  qfile.read (str, len);
  len = qfile.gcount();
  
  string sstr (str, len);
  result.swap (sstr);
  delete [] str;
}

class ZorbaEngineWrapper {
public:
  ZorbaEngine_t factory;
  StaticQueryContext_t sctx;

  ZorbaEngineWrapper (alert_callback alert_cb = NULL, void *alert_param = NULL)
    : factory (ZorbaEngine::getInstance())
  {
    factory->initThread();
    /// register the alerts callback
    ZorbaAlertsManager_t errmanager = factory->getAlertsManagerForCurrentThread();
    
    if (alert_cb != NULL)
      errmanager->registerAlertCallback(alert_cb, alert_param);

    sctx = factory->createStaticContext();
    sctx->addCollation("http://www.flworfound.org/apitest/coll1", "en");
    sctx->addCollation("http://www.flworfound.org/apitest/coll2", "de");
    sctx->addCollation("http://www.flworfound.org/apitest/coll3", "fr");
    sctx->setOrderingMode(StaticContextConsts::unordered);
  }
  ~ZorbaEngineWrapper () {
    //DisplayErrorListForCurrentThread();
		factory->getAlertsManagerForCurrentThread()->dumpAlerts(cerr);

    factory->uninitThread();
    factory->shutdown();
  }

  bool initExecution (XQuery_t query, const vector< pair <string, string> > &vars) {
    DynamicQueryContext_t dctx = factory->createDynamicContext ();
    for (vector<pair <string, string> >::const_iterator iter = vars.begin ();
         iter != vars.end (); iter++) {
      set_var (iter->first, iter->second, dctx, NULL);
    }
    
    bool result = query->initExecution(dctx);

    if( result != false) {
      for (vector<pair <string, string> >::const_iterator iter = vars.begin ();
           iter != vars.end (); iter++) {
        set_var (iter->first, iter->second, NULL, query);
      }
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
  XQuery_t query = zengine.factory->createQuery(query_text.c_str(), zengine.sctx);
  if (query == NULL)
    return 0;

  // create dynamic context and execution
  vector<pair <string, string> > ext_vars = lProp->getExternalVars ();
  bool result = zengine.initExecution (query, ext_vars);

	query->setAlertsParam(query.getp());  // to be passed to alerts callback when error occurs

  if (lProp->useSerializer()) {
    query->serialize(*resultFile);
    // newline should not be sent when serializing!
  } else {
		ResultIterator_t	result;
    Item_t it;
		result = query->getIterator();
    while (NULL != (it = result->nextItem ()).getp ())
      *resultFile << it->show() << endl;
		result->closeIterator();
  }
  
  if (query->isError ())
  {
    query = 0;
    return 0;
  }

  //  query = 0;
  return 0;
}
