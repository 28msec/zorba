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
#ifndef WIN32
#include <sys/time.h>
#else
#include <time.h>
#endif


#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testuriresolver.h"
#include "testdriver_common.h"

#include "system/properties.h"

#include <zorba/static_context.h>
#include <zorba/util/file.h>

#include <zorbatypes/URI.h>
#include "util/ascii_util.h"

#include <zorba/store_manager.h>

#include "testdriver_comparator.h"


//#define ZORBA_TEST_PLAN_SERIALIZATION

#define EXPECTED_ERROR  0
#define UNEXPECTED_ERROR  6

std::string rbkt_src_dir = zorba::RBKT_SRC_DIR;
std::string rbkt_bin_dir = zorba::RBKT_BINARY_DIR;
std::string w3c_ts = "w3c_testsuite/";


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
    std::cout << "Expected error(s):";
    for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
         lIter != lSpec.errorsEnd(); ++lIter)
      {
        std::cout << " " << *lIter;
      }
    if (lSpec.errorsSize () == 0) { std::cout << " (none)"; }
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
  if ( argc < 2 )
  {
    std::cout << "\nusage:   testdriver [testfile_1] [testfile_2] ..." << std::endl;
    return 1;
  }

  int errors;
  Specification lSpec;
  std::string lModulePath;
  loadProperties ();

  // Instantiate the store and the zorba query processor
  void* store = zorba::StoreManager::getStore();
  if (store == NULL) return 20;

  zorba::Zorba * engine = zorba::Zorba::getInstance(store);
  if (engine == NULL) return 21;

  int i = 1;
  for (;;) 
  {
    if (strcmp (argv [i], "--rbkt-src") == 0) {
      rbkt_src_dir = argv [i + 1];
      i += 2;
    } else if (strcmp (argv [i], "--rbkt-bin") == 0) {
      rbkt_bin_dir = argv [i + 1];
      i += 2;
    } else if (strcmp (argv [i], "--module-path") == 0) {
      lModulePath = argv [i + 1];
      i += 2;
    } else break;
  }

  zorba::XQuery_t lQuery;
  TestErrorHandler errHandler;

  DriverContext driverContext;
  driverContext.theEngine = engine;
  driverContext.theRbktSourceDir = rbkt_src_dir;
  driverContext.theRbktBinaryDir = rbkt_bin_dir;
  driverContext.theSpec = &lSpec;

  for (int testcnt = 1; i < argc; ++i, ++testcnt)
  {
    std::string Queriesdir = "/Queries/";

    int path_flags = zorba::file::CONVERT_SLASHES | zorba::file::RESOLVE;

    std::string lQueryFileString = rbkt_src_dir + Queriesdir + argv[i];

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY
    // Form the full pathname for the file containing the query and make sure
    // that the file exists.
    zorba::file lQueryFile (lQueryFileString, path_flags);

    if ( (! lQueryFile.exists ()) || lQueryFile.is_directory () ) 
    {
      std::cout << "\n query file " << lQueryFile.get_path() 
                << " does not exist or is not a file" << std::endl;
      return 2;
    }
#endif//ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY

    // Check if this is w3c_testsuite test.
    std::string path = lQueryFileString;
    bool isW3CXQTStest = ( path.find ( "w3c_testsuite" ) != std::string::npos );
    bool isW3CFTtest = ( path.find ( "w3c_full_text_testsuite" ) != std::string::npos );
    bool isW3Ctest = isW3CFTtest || isW3CXQTStest;
    std::string lQueryWithoutSuffix = 
    std::string(argv[i]).substr( 0, std::string(argv[i]).rfind('.') );
    std::auto_ptr<zorba::TestSchemaURIResolver>      resolver;
    std::auto_ptr<zorba::TestModuleURIResolver>      mresolver;
    std::auto_ptr<zorba::TestCollectionURIResolver>  cresolver;
    std::auto_ptr<zorba::TestDocumentURIResolver>    dresolver;
    // Create the static context. If this is a w3c query, install special uri
    // resolvers in the static context.
    zorba::StaticContext_t lContext = engine->createStaticContext();

    if ( isW3Ctest ) 
    {
  #ifndef MY_D_WIN32
      std::string w3cDataDir = "/Queries/w3c_testsuite/TestSources/";
  #else
      std::string w3cDataDir = "/Queries/TestSources/";
  #endif
      std::string uri_map_file = rbkt_src_dir + w3cDataDir + "uri.txt";
      std::string mod_map_file = rbkt_src_dir + w3cDataDir + "module.txt";
      std::string col_map_file = rbkt_src_dir + w3cDataDir + "collection.txt";

      resolver.reset(new zorba::TestSchemaURIResolver(uri_map_file.c_str()));

      mresolver.reset(new zorba::TestModuleURIResolver(mod_map_file.c_str(),
                                                       lQueryWithoutSuffix));

      cresolver.reset(new zorba::TestCollectionURIResolver(col_map_file.c_str(),
                                                           rbkt_src_dir));
      lContext->addSchemaURIResolver ( resolver.get() );
      lContext->addModuleURIResolver ( mresolver.get() );
      lContext->setCollectionURIResolver ( cresolver.get() );

      // the w3c testsuite always uses xquery 1.0
      lContext->setXQueryVersion( xquery_version_1_0 );
    }

    // Form the full pathname for the files that will receive the result or the
    // errors of this query. Then, delete these files if they exist already from
    // previous runs of the query. Finaly, create (if necessary) all the dirs
    // in the pathname of the result and error files.

    std::cout << "test " << lQueryWithoutSuffix << std::endl;

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY
    zorba::file lResultFile (rbkt_bin_dir + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".xml.res", path_flags);

    zorba::file lErrorFile  (rbkt_bin_dir + "/" 
                             + lQueryWithoutSuffix + ".err", path_flags);

    if ( lResultFile.exists () ) { lResultFile.remove (); }
    if ( lErrorFile.exists () )  { lErrorFile.remove ();  }

    zorba::file lBucket (lResultFile.branch_path());
    if ( ! lBucket.exists () )
      lBucket.deep_mkdir (); // create deep directories

    // Form the full pathname for the .spec file that may be associated
    // with this query. If the .spec file exists, read its contents to
    // extract args to be passed to the query (e.g., external var bindings),
    // exprected errors, or the pathnames of reference-result files.
    zorba::file lSpecFile(rbkt_src_dir + "/Queries/" + lQueryWithoutSuffix + ".spec",
                          path_flags);

    if ( lSpecFile.exists ()) {
      bool lParsed = lSpec.parseFile(lSpecFile.get_path(), rbkt_src_dir,
        rbkt_bin_dir);
      if (!lParsed) {
        std::cout << "Spec file " << lSpecFile.get_path() << " is malformed!"
                  << std::endl;
        return 1;
      }
    }

    // If --enable-uritestresolver is specified, enable our document
    // URI resolver for test:// scheme URIs
    if (lSpec.getEnableUriTestResolver()) {
      dresolver.reset(new zorba::TestDocumentURIResolver(rbkt_src_dir));
      lContext->setDocumentURIResolver ( dresolver.get() );
    }

    // Bind any options from the .spec file to the static context
    setOptions(driverContext, lContext);

    // Bind any full-text URI resolvers from the .spec file to the
    // static context
    setFullTextResolvers(driverContext, lContext);

    // If command-line argument --module-path passed, set up module paths.
    setModulePaths(lModulePath, lContext);

    // Get the pathnames of the reference-result files found in the .spec
    // file (if any).
    std::vector<zorba::file> lRefFiles;
    bool lRefFileExists = false;
    for (std::vector<std::string>::const_iterator lIter = lSpec.resultsBegin();
         lIter != lSpec.resultsEnd();
         ++lIter) 
    {
      zorba::file lRefFile(*lIter, path_flags);
      if (lRefFile.exists()) 
      {
        lRefFileExists = true;
      }
      else
      {
        std::cout << "Warning: missing reference result file " 
                  << lRefFile.get_path () << std::endl;
      }
      lRefFiles.push_back(lRefFile);
    }

    // If no ref-results file was specified in the .spec file, create a default
    // finename for that file. For w3c tests, the ref file is the same for
    // xqueryx and xquery tests, hence, we remove the string xqueryx or xquery
    // from the path
    if (lRefFiles.size () == 0) 
    {
      std::string lRefFileTmpString = lQueryWithoutSuffix;

      if (isW3Ctest) 
      {
        size_t pos = lQueryWithoutSuffix.find("XQueryX");
        if (pos != std::string::npos)
          lRefFileTmpString = lRefFileTmpString.erase(pos, 8);
        pos = lQueryWithoutSuffix.find("XQuery");
        if (pos != std::string::npos)
          lRefFileTmpString = lRefFileTmpString.erase(pos, 7);
      }
  
      lRefFiles.push_back(zorba::file(rbkt_src_dir + "/ExpQueryResults/" +
                                      lRefFileTmpString + ".xml.res"));
      if (lRefFiles [0].exists())
        lRefFileExists = true;
    }
#endif//ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY
    // print the query
    std::cout << "=== Query: ===" << std::endl;
    zorba::printFile(std::cout, lQueryFile.get_path());
    std::cout << "=== end of Query ===" << std::endl;
#endif

    // Stopwatch starts now
    // QQQ this should use util/time.h
#ifndef WIN32
    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);
#else
    clock_t   start_time, end_time;
    start_time = clock();
#endif

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY
    // create and compile the query
    std::string lQueryString;
    slurp_file(lQueryFile.get_path().c_str(), lQueryString, rbkt_src_dir, rbkt_bin_dir);

    lQuery = engine->createQuery(&errHandler);
    lQuery->setFileName(lQueryFile.get_path());

    lQuery->compile(lQueryString.c_str(), lContext, getCompilerHints());

    errors = -1;
    if ( errHandler.errors() )
    {
      errors = analyzeError (lSpec, errHandler);
      if( errors == UNEXPECTED_ERROR )
        return 6;
      std::cout << "testdriver: success" << std::endl;
      continue;
    } 
    // no compilation errors

#ifdef ZORBA_TEST_PLAN_SERIALIZATION
    try
    {
      clock_t t0, t1;
      std::string binary_path;
      binary_path = rbkt_bin_dir + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".plan";
      t0 = clock();
      std::ofstream fbinary(binary_path.c_str(), std::ios_base::binary);
      if(!lQuery->saveExecutionPlan(fbinary, ZORBA_USE_BINARY_ARCHIVE))
      {
        printf("save execution plan FAILED\n");
        return 0x0badc0de;
      }
      fbinary.close();
      t1 = clock();
      printf("save execution plan in %f sec\n", (float)(t1-t0)/CLOCKS_PER_SEC);
    }
    catch(zorba::ZorbaException &err)
    {
      std::cout << err << std::endl;
      return -1;
    }
#endif//ZORBA_TEST_PLAN_SERIALIZATION

#endif//#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY

#ifdef ZORBA_TEST_PLAN_SERIALIZATION
    try
    {
      clock_t t0, t1;
      std::string binary_path;
      binary_path = rbkt_bin_dir + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".plan";
      lQuery = engine->createQuery (&errHandler);
      t0 = clock();
      std::ifstream   ifbinary(binary_path.c_str(), std::ios_base::binary);
      if(!ifbinary.is_open())
      {
        std::cout << "cannot open plan " << binary_path << std::endl;
        return 15;
      }
      bool load_ret;
      if ( isW3Ctest ) 
      {
        zorba::TestSerializationCallback   serl_callback(cresolver.get(), mresolver.get());
        load_ret = lQuery->loadExecutionPlan(ifbinary, &serl_callback);//, NULL, cresolver.get(), resolver.get(), mresolver.get());
      }
      else
      {
        load_ret = lQuery->loadExecutionPlan(ifbinary);
      }
      if(!load_ret)
      {
        std::cout << "cannot load plan " << binary_path << std::endl;
        return 16;
      }
      t1 = clock();
      printf("load execution plan in %f sec\n", (float)(t1-t0)/CLOCKS_PER_SEC);
    }
    catch(zorba::ZorbaException &err)
    {
      std::cout << err << std::endl;
      return -1;
    }
#endif

    // Create dynamic context and set in it the external variables, the current
    // date & time, and the timezone.
    createDynamicContext(driverContext, lContext, lQuery, lSpec.getEnableDtd());


    errors = -1;
    {
      { // serialize xml/txt
        std::ofstream lResFileStream(lResultFile.get_path().c_str());
        assert (lResFileStream.good());
        Zorba_SerializerOptions lSerOptions;
        lSerOptions.ser_method = 
          lSpec.getSerializationMethod() == "XML" ? ZORBA_SERIALIZATION_METHOD_XML :
          lSpec.getSerializationMethod() == "TXT" ? ZORBA_SERIALIZATION_METHOD_TEXT :
                                                  ZORBA_SERIALIZATION_METHOD_XML;
        lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
        lSerOptions.indent = lSpec.getUseIndent() ?
          ZORBA_INDENT_YES : ZORBA_INDENT_NO;
        
        lQuery->execute(lResFileStream, &lSerOptions);
      }

      // Stopwatch ends here
#ifndef WIN32
      gettimeofday(&end_time, NULL);
#else
      end_time = clock();
#endif
      
      if (! lRefFileExists )
      {
        if(lSpec.getComparisonMethod() == "Ignore")
        {
          std::cout << "Since the comparison method is set to 'Ignore' the test is considered successful." << std::endl;
          return 0;
        }
        if(lSpec.errorsSize() == 0)
        {
          std::cout << "No reference result and no expected errors." << std::endl;
          return 3;
        }
      }
      
      if (errHandler.errors())
      {
        errors = analyzeError (lSpec, errHandler);
      }
      else if ( lSpec.errorsSize() > 0 ) 
      {
        if ( ! lRefFileExists ) 
        {
          std::cout << "Expected error(s)";
          for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
               lIter != lSpec.errorsEnd(); ++lIter)
          {
            std::cout << " " << *lIter;
          }
          if ( lResultFile.exists () && lResultFile.get_size () == 0)
          {
            std::cout << " but got empty result" << std::endl;
          }
          else 
          {
            std::cout << " but got result:" << std::endl;
            zorba::printFile(std::cout, lResultFile.get_path());
            std::cout << "=== end of result ===" << std::endl;
          }
          return 7;
        }
      }
    }

    if( errors == UNEXPECTED_ERROR)
    {
      return 6;
    }
    else if( errors == -1 ) 
    {
      std::cout << "=== Result: ===" << std::endl;
      zorba::printFile(std::cout, lResultFile.get_path());
      std::cout << "=== end of result ===" << std::endl;
      std::cout.flush();
      size_t i = 1;
      bool lResultMatches = false;
      for (std::vector<zorba::file>::const_iterator lIter = lRefFiles.begin();
           lIter != lRefFiles.end(); ++lIter) 
      {
        int lLine, lCol; // where do the files differ
        std::string lRefLine, lResultLine;
        bool lRes = zorba::fileEquals(lIter->c_str(),
                                      lResultFile.c_str(),
                                      lLine, lCol,
                                      lRefLine, lResultLine);
        if (lRes) 
        {
          std::cout << "testdriver: success (non-canonical result # " << i 
                    << " matches)" << std::endl;
          lResultMatches = true;
          break;
        }

        std::cout << "testdriver: non-canonical result for reference result # " 
                  << i << " doesn't match." << std::endl;

        // Don't attempt canonical comparison for test cases using --indent;
        // can lead to false positives
        if (lSpec.getUseIndent()) {
          std::cout << "testdriver: skipping canonicalization "
            "when testing with --indent" << std::endl;
        }
        else {
          int lCanonicalRes = zorba::canonicalizeAndCompare(lSpec.getComparisonMethod(),
            lIter->c_str(),
            lResultFile.c_str(),
            rbkt_bin_dir);
          if (lCanonicalRes == 0) 
          {
            std::cout << "testdriver: success (canonical result # " << i  
                      << " matches)" << std::endl;
            lResultMatches = true;
            break;
          }
          std::cout << "testdriver: canonical result for reference result # " << i 
                    << " doesn't match." << std::endl;
        }
 
        ++i;
      } // for 

      if (!lResultMatches) {
        std::cout << "testdriver: none of the reference results matched" << std::endl;
        return 8;
      }
    }

    // Check timing
    // QQQ only do this if .spec file says to
#ifndef WIN32
    long mstime = ( (end_time.tv_sec - start_time.tv_sec) * 1000000
      + (end_time.tv_usec - start_time.tv_usec) );
#else
    long mstime = (long)(((double)(end_time - start_time)) / CLOCKS_PER_SEC * 1000000);
#endif
    std::cout << "testdriver: test runtime was " << mstime << "us" << std::endl;

#endif//ifndef ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY

  } // for (int testcnt = 1; i < argc; ++i, ++testcnt)
  std::cout << "testdriver: success" << std::endl;
  return 0;
}
