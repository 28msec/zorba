#include <zorba/zorba.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

// tests are allowed to use internals
#include "api/unmarshaller.h"
#include "store/api/item.h"
#include "zorbatypes/xqpstring.h"
#include "util/properties.h"

using namespace zorba;
using namespace std;

void set_var (string name, string val, DynamicContext* dctx)
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


// TODO: for now apitest users expect 0 even for error results; this should change
#ifndef _WIN32_WCE
int main(int argc, char* argv[])
#else
int _tmain(int argc, _TCHAR* argv[])
#endif
{

  // read the command file properties
  if (! Properties::load(argc,argv))
    return 4;  
  Properties* lProp = Properties::instance();
  zorba::XQuery::CompilerHints chints;
  chints.opt_level = lProp->useOptimizer () ? XQuery::CompilerHints::O1 : XQuery::CompilerHints::O0;

  // output file (either a file or the standard out if no file is specified)
  auto_ptr<ostream> outputFile (lProp->useResultFile() ?
                                new ofstream (lProp->getResultFile().c_str()) :
                                NULL);
  ostream *resultFile = outputFile.get ();
  if (resultFile == NULL)
    resultFile = &cout;
  

  // input file (either from a file or given as parameter)
  const char* fname = lProp->getQuery().c_str();
  auto_ptr<istream> qfile(!lProp->inlineQuery()&&*fname!='\0' ?
                               (istream*) new ifstream(fname) :
                               (istream*) new istringstream(fname));
  if (!qfile->good() || qfile->eof()) {
    cerr << "no query given or not readable " << fname  << endl;
    return 3;
  }
  
  // print the query if requested
  if (lProp->printQuery()) {
    cout << "Query text:\n";
    copy (istreambuf_iterator<char> (*qfile), istreambuf_iterator<char> (), ostreambuf_iterator<char> (cout));
    cout << "\n" << endl;
    qfile->seekg(0); // go back to the beginning
  }

  // start processing
  Zorba* zengine = Zorba::getInstance();

  // start parsing the query
  XQuery_t query;
  try {
    query = zengine->compileQuery(*qfile, chints);
  } catch (QueryException &e) {
    // no need to close because the object is not valid
    cerr << "Compilation error: " << e << endl;
    return 1;
  }

  // set external variables
  vector<pair <string, string> > ext_vars = lProp->getExternalVars ();
  DynamicContext* dctx = query->getDynamicContext ();
  dctx->setImplicitTimezone (lProp->timezone ());
  for (vector<pair <string, string> >::const_iterator iter = ext_vars.begin ();
       iter != ext_vars.end (); iter++) {
    set_var (iter->first, iter->second, dctx);
  }

  if (! lProp->compileOnly ()) {
    // output the result (either using xml serialization or using show)
    // cout << "Running query and printing result..." << endl;
  
    try {
      if (lProp->useSerializer()) {
        if (query->isUpdateQuery())
          query->applyUpdates();
        else
          *resultFile << query;
      } else {
        ResultIterator_t result = query->iterator();
        result->open();
        Item lItem;
        while (result->next(lItem)) {
          // unmarshall the store item from the api item
          store::Item_t lStoreItem = Unmarshaller::getInternalItem(lItem);
          *resultFile << lStoreItem->show() << endl;
      }
        result->close();
      }
    } catch (QueryException &e) {
      query->close();
      zengine->shutdown();
      cerr << "Execution error: " << e << endl;
      return 2;
    } catch (ZorbaException &e) {
      query->close();
      zengine->shutdown();
      cerr << "Execution error: " << e << endl;
      return 2;
    }
  }

  query->close();
  zengine->shutdown();
  return 0;
}
