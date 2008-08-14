/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include <zorba/zorba.h>

#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <memory>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>

// tests are allowed to use internals
#include "api/unmarshaller.h"
#include "zorbatypes/xqpstring.h"
#include "util/properties.h"

#include "store/api/item.h"
#include "zorba_test_setting.h"
#ifndef ZORBA_MINIMAL_STORE
#include <simplestore/simplestore.h>
#include "store/naive/simple_store.h"
#else
#include "store/minimal/min_store.h"
#endif

using namespace zorba;
using namespace std;

namespace fs = boost::filesystem;


void set_var (string name, string val, DynamicContext* dctx)
{
  if (name [name.size () - 1] == ':') 
  {
    Item lItem = Zorba::getInstance(NULL)->getItemFactory()->createString(val);
		if(name != ".") {
			dctx->setVariable(name.substr (0, name.size () - 1), lItem);
		} else
			dctx->setContextItem(lItem);
  }
  else if (name[name.size () - 1] != ':')
  {
    ifstream* is = new ifstream(val.c_str ());
    assert (*is);
		if(name != ".")
			dctx->setVariableAsDocument(name, val.c_str(), std::auto_ptr<std::istream>(is));
		else
			dctx->setContextItemAsDocument(val.c_str(), std::auto_ptr<std::istream>(is));
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
  Zorba_CompilerHints chints;
  chints.opt_level = (lProp->useOptimizer () ?
                      ZORBA_OPT_LEVEL_O1:
                      ZORBA_OPT_LEVEL_O0);

  // output file (either a file or the standard out if no file is specified)
  auto_ptr<ostream> outputFile (lProp->useResultFile() ?
                                new ofstream (lProp->getResultFile().c_str()) :
                                NULL);
  ostream *resultFile = outputFile.get ();
  if (resultFile == NULL)
    resultFile = &cout;
  

  // input file (either from a file or given as parameter)
  const char* fname = lProp->getQuery().c_str();

  auto_ptr<istream> qfile;
  fs::path path;

  if (! lProp->inlineQuery()) {
    path = fs::system_complete (fname);
    qfile.reset (new ifstream (path.native_file_string ().c_str ()));
  } else {
    qfile.reset (new istringstream(fname));
  }
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

  // Instantiate the simple store
#ifdef ZORBA_MINIMAL_STORE
  zorba::storeminimal::SimpleStore* store = 
        zorba::storeminimal::SimpleStore::getInstance();
#else
  zorba::simplestore::SimpleStore* store = 
        zorba::simplestore::SimpleStoreManager::getStore();
#endif

  // start processing
  Zorba* zengine = Zorba::getInstance(store);

  // start parsing the query
  XQuery_t query = zengine->createQuery ();
  if (! lProp->inlineQuery())
    query->setFileName (path.string ());
  
  try {
    query->compile(*qfile, chints);
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
        if (query->isUpdateQuery()) {
          query->applyUpdates();
        } else {
          *resultFile << query;
        }
      } else {
        if (query->isUpdateQuery()) {
          query->applyUpdates();
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
      }
    } catch (QueryException &e) {
      query->close();
      zengine->shutdown();
      store->shutdown();
      cerr << "Execution error: " << e << endl;
      return 2;
    } catch (ZorbaException &e) {
      query->close();
      zengine->shutdown();
      store->shutdown();
      cerr << "Execution error: " << e << endl;
      return 2;
    }
  }

  query->close();
  zengine->shutdown();
  store->shutdown();
  return 0;
}
