#include <zorba/zorba.h>

#include "timer.h"
#include <zorba/properties.h>

#include <fstream>
#include <iostream>
#include <iomanip>

using namespace zorba;
using namespace std;


void set_var (string name, string val, DynamicContext_t dctx)
{
  if (name [name.size () - 1] == ':') 
  {
    Item lItem = Zorba::getInstance()->getItemFactory()->createString(val);
		if(name != ".") {
			dctx->setVariable(name.substr (0, name.size () - 1), lItem);
		} else
			dctx->setContextItem(lItem);
  }
  else if (name[name.size () - 1] != ':')
  {
    ifstream is (val.c_str ());
    assert (is);
		if(name != ".")
			dctx->setVariableAsDocument(name, val.c_str(), is);
		else
			dctx->setContextItemAsDocument(val.c_str(), is);
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

  Zorba* zengine = Zorba::getInstance();

  XQuery_t query;
  try {
    query = zengine->createQuery(query_text.c_str());
  } catch (ZorbaException &e) {
    std::cerr << e << std::endl;
    return 1;
  }

  vector<pair <string, string> > ext_vars = lProp->getExternalVars ();
  DynamicContext_t dctx = query->getDynamicContext ();
  for (vector<pair <string, string> >::const_iterator iter = ext_vars.begin ();
       iter != ext_vars.end (); iter++) {
    set_var (iter->first, iter->second, dctx);
  }

  if (lProp->useSerializer()) {
    try {
      *resultFile << query;
    } catch (ZorbaException &e) {
      std::cerr << e << std::endl;
      return 2;
    }
  } else {
    try {
      ResultIterator_t result = query->iterator();
      result->open();
      Item lItem;
      while (result->next(lItem))
        *resultFile << lItem.getStringValue() << endl;
      result->close();
    } catch (ZorbaException &e) {
      std::cerr << e << std::endl;
      return 2;
    }
  }
  

  return 0;
}
