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
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testuriresolver.h"
#include "testdriver_common.h"

#include "util/properties.h"

#include <zorba/static_context.h>
#include <zorba/util/file.h>

#include <zorbatypes/URI.h>
#include <zorbautils/strutil.h>

#include "zorba_test_setting.h"

#ifndef ZORBA_MINIMAL_STORE
#include <simplestore/simplestore.h>
#include "store/naive/simple_store.h"
#else
#include "store/minimal/min_store.h"
#endif

#include "testdriver_comparator.h"

zorba::Properties *lProp;

#define EXPECTED_ERROR  0
#define UNEXPECTED_ERROR  6

std::string rbkt_src_dir = zorba::RBKT_SRC_DIR, rbkt_bin_dir = zorba::RBKT_BINARY_DIR;

void loadProperties () 
{
  zorba::Properties::load(0, NULL);
}



int analyzeError (const Specification &lSpec, const TestErrorHandler& errHandler) 
{
  if (isErrorExpected(errHandler, &lSpec)) {
    printErrors(errHandler, "The following execution error occurred as expected", false);
    return EXPECTED_ERROR;
  } else {
    printErrors(errHandler, "Unexpected error executing query", false);
    std::cout << "Expected error(s)";
    for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
         lIter != lSpec.errorsEnd(); ++lIter)
      {
        std::cout << " " << *lIter;
      }
    std::cout << std::endl;
    return UNEXPECTED_ERROR;
  }
}


int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  loadProperties ();
  Specification lSpec;
  if ( argc < 2 )
  {
    std::cout << "\nusage:   testdriver [testfile_1] [testfile_2] ..." << std::endl;
    return 1;
  }

  int errors;
  zorba::Zorba * engine = NULL;

  int i = 1;
  for (;;) {
    if (strcmp (argv [i], "--rbkt-src") == 0) {
      rbkt_src_dir = argv [i + 1];
      i += 2;
    } else if (strcmp (argv [i], "--rbkt-bin") == 0) {
      rbkt_bin_dir = argv [i + 1];
      i += 2;
    } else break;
  }

  for (int testcnt = 1; i < argc; ++i, ++testcnt)
  {
    std::string   Queriesdir = "/Queries/";

    int path_flags = zorba::file::CONVERT_SLASHES | zorba::file::RESOLVE;
    zorba::file lQueryFile (rbkt_src_dir + Queriesdir + argv[i], path_flags);

    std::string lQueryWithoutSuffix = std::string(argv[i]).substr( 0, std::string(argv[i]).rfind('.') );

    zorba::file lResultFile (rbkt_bin_dir + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".xml.res", path_flags);

    zorba::file lErrorFile  (rbkt_bin_dir + "/" 
                             + lQueryWithoutSuffix + ".err", path_flags);

    std::string lRefFileTmpString = lQueryWithoutSuffix;
    // the ref file is the same for xqueryx and xquery tests
    // hence, we remove the string xqueryx or xquery from the path
    if (lQueryWithoutSuffix.find("w3c_testsuite") == 0) {
      if (lQueryWithoutSuffix.find("XQueryX") != std::string::npos)
        lRefFileTmpString = lRefFileTmpString.erase(14, 8);
      else
        lRefFileTmpString = lRefFileTmpString.erase(14, 7);
    }
    zorba::file lRefFile(zorba::RBKT_SRC_DIR + "/ExpQueryResults/"
                         + lRefFileTmpString +".xml.res", path_flags);

    zorba::file lSpecFile (zorba::RBKT_SRC_DIR + "/Queries/"
                           + lQueryWithoutSuffix +".spec", path_flags);

    // does the query file exists
    if ( (! lQueryFile.exists ()) || lQueryFile.is_directory () ) 
    {
      std::cout << "\n query file " << lQueryFile.get_path() 
                << " does not exist or is not a file" << std::endl;
      return 2;
    }

    // delete previous files if they exists
    if ( lResultFile.exists () ) { lResultFile.remove (); }
    if ( lErrorFile.exists () )  { lErrorFile.remove ();  }

    // create the result directory
    zorba::file lBucket (lResultFile.branch_path());

    if ( ! lBucket.exists () )
      lBucket.deep_mkdir (); // create deep directories

    // read the xargs and errors if the spec file exists
    if ( lSpecFile.exists ()) 
      lSpec.parseFile(lSpecFile.get_path());

    // print the query
    std::cout << "Query:" << std::endl;
    zorba::printFile(std::cout, lQueryFile.get_path());
    std::cout << std::endl;

    if( testcnt == 1 ) {  // Instantiate the store
#ifdef ZORBA_MINIMAL_STORE
      zorba::storeminimal::SimpleStore* store =
      zorba::storeminimal::SimpleStore::getInstance();
#else
      zorba::simplestore::SimpleStore* store =
      zorba::simplestore::SimpleStoreManager::getStore();
#endif

      if (store == NULL) return 20;
      // Instantiate zorba query processor
      engine = zorba::Zorba::getInstance(store);
      if (engine == NULL) return 21;
    }

    zorba::StaticContext_t lContext = engine->createStaticContext();
    // Install special resolver only for w3c_testsuite ...
    std::auto_ptr<zorba::TestSchemaURIResolver>      resolver;
    std::string path = lQueryFile.get_path();
    std::auto_ptr<zorba::TestModuleURIResolver>      mresolver;
    std::auto_ptr<zorba::TestCollectionURIResolver>  cresolver;

    if ( path.find ( "w3c_testsuite" ) != std::string::npos ) 
    {
      std::string uri_map_file = rbkt_src_dir + "/Queries/w3c_testsuite/TestSources/uri.txt";
      std::string mod_map_file = rbkt_src_dir + "/Queries/w3c_testsuite/TestSources/module.txt";
      std::string col_map_file = rbkt_src_dir + "/Queries/w3c_testsuite/TestSources/collection.txt";
      resolver.reset(new zorba::TestSchemaURIResolver ( uri_map_file.c_str() ));
      mresolver.reset(new zorba::TestModuleURIResolver ( mod_map_file.c_str() ));
      cresolver.reset(new zorba::TestCollectionURIResolver ( col_map_file.c_str(), rbkt_src_dir));
      lContext->setSchemaURIResolver ( resolver.get() );
      lContext->setModuleURIResolver ( mresolver.get() );
      lContext->setCollectionURIResolver ( cresolver.get() );
    }

    TestErrorHandler errHandler;

    // create and compile the query
    std::string lQueryString;
    slurp_file(lQueryFile.get_path().c_str(), lQueryString, rbkt_src_dir, rbkt_bin_dir);
    zorba::XQuery_t lQuery = engine->createQuery (&errHandler);
    lQuery->setFileName (lQueryFile.get_path ());
    lQuery->compile (lQueryString.c_str(), lContext, getCompilerHints());

    errors = -1;
    if ( errHandler.errors() )
    {
      errors = analyzeError (lSpec, errHandler);
      if( errors == UNEXPECTED_ERROR )
        return 6;
    } else {  // no compilation errors

      // set the variables in the dynamic context
      zorba::DynamicContext* lDynCtxt = lQuery->getDynamicContext();

      if (lSpec.hasDateSet()) {
        // set the current date time such that tests that use fn:current-time behave deterministically
        zorba::Item lDateTimeItem = engine->getItemFactory()->createDateTime(lSpec.getDate());
        lDynCtxt->setCurrentDateTime(lDateTimeItem);
      }

      if (lSpec.getDefaultCollection().size() != 0) {
        zorba::Item lDefaultCollection = engine->getItemFactory()->createAnyURI(lSpec.getDefaultCollection());
        lDynCtxt->setDefaultCollection(lDefaultCollection);
      }

      if (lSpec.hasTimezoneSet()) {
        int lTimezone = atoi(lSpec.getTimezone().c_str());
        std::cout << "timezone " << lTimezone << std::endl;
        lDynCtxt->setImplicitTimezone(lTimezone);
      }

      set_vars(&lSpec, lDynCtxt, rbkt_src_dir);
      if ( lSpec.hasInputQuery () ) {
        std::string  inputqueryfile = lSpec.getInputQueryFile ();
        zorba::str_replace_all(inputqueryfile, "$RBKT_SRC_DIR", rbkt_src_dir);

        std::ifstream inputquery ( inputqueryfile.c_str() );
        zorba::XQuery_t inputQuery = engine -> compileQuery ( inputquery, lContext, getCompilerHints () );
        zorba::ResultIterator_t riter = inputQuery -> iterator ();
        lDynCtxt -> setVariable ( zorba::String ("x"), riter );
    }

      errors = -1;
      {
        { // serialize xml
          std::ofstream lResFileStream(lResultFile.get_path().c_str());
          assert (lResFileStream.good());
          Zorba_SerializerOptions lSerOptions;
          lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
          lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
          lSerOptions.indent = ZORBA_INDENT_NO;

          lQuery->serialize(lResFileStream, &lSerOptions);
        }
        
        if ( (lSpec.errorsSize() == 0) && ((! lRefFile.exists ()) || lRefFile.is_directory ()))
        {
          std::cout << "No reference result and no expected errors." << std::endl;
          return 3;
        }

        if (errHandler.errors())
        {
          errors = analyzeError (lSpec, errHandler);
        }
        else if ( lSpec.errorsSize() > 0 ) 
        {
          if ( ! lRefFile.exists () ) 
          {
            std::cout << "Expected error(s)";
            for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
                lIter != lSpec.errorsEnd(); ++lIter)
            {
              std::cout << " " << *lIter;
            }
            if ( lResultFile.exists () && lResultFile.get_size () == 0)
              std::cout << " but got empty result" << std::endl;
            else {
              std::cout << " but got result:" << std::endl;
              zorba::printFile(std::cout, lResultFile.get_path());
              std::cout << "=== end of result ===" << std::endl;
            }
            return 7;
          }
        }
      }
      if( errors == UNEXPECTED_ERROR)
        return 6;
      else if( errors == -1 ) {
        std::cout << "Result:" << std::endl;
        zorba::printFile(std::cout, lResultFile.get_path());
        std::cout << "=== end of result ===" << std::endl;
        std::cout.flush();
        {
          int lLine, lCol, lPos; // where do the files differ
          std::string lRefLine, lResultLine;
          bool lRes = zorba::fileEquals(lRefFile.c_str(), lResultFile.c_str(), lLine, lCol, lPos, lRefLine, lResultLine);
          if (lRes) {
            std::cout << "testdriver: success (non-canonical result matches)" << std::endl;
            return 0;
          }
        }

        int lCanonicalRes = zorba::canonicalizeAndCompare(lSpec.getComparisonMethod(),
                                                          lRefFile.c_str(), lResultFile.c_str(), rbkt_bin_dir);
        if (lCanonicalRes != 0) {
          return lCanonicalRes;
        }
        std::cout << "testdriver: success (canonical result matches)" << std::endl;
        return 0;
      }
    }
  }
  std::cout << "testdriver: success" << std::endl;
  return 0;
}
