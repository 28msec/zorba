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

//#define ZORBA_TEST_PLAN_SERIALIZATION

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testuriresolver.h"
#include "testdriver_common.h"

#include <zorba/static_context.h>
#include <zorba/util/fs_util.h>
#include <zorba/internal/unique_ptr.h>

#include "zorbatypes/URI.h"
#include "util/ascii_util.h"

#include <zorba/store_manager.h>

#include "testdriver_comparator.h"


#define EXPECTED_ERROR  0
#define UNEXPECTED_ERROR  6

std::string rbkt_src_dir = zorba::RBKT_SRC_DIR;
std::string rbkt_src_dir_uri = zorba::RBKT_SRC_DIR_URI;
std::string rbkt_bin_dir = zorba::RBKT_BIN_DIR;
std::string rbkt_bin_dir_uri = zorba::RBKT_BIN_DIR_URI;
std::string w3c_ts = "w3c_testsuite/";



int analyzeError (const Specification &lSpec, const TestDiagnosticHandler& errHandler) 
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

  // Instantiate the store and the zorba query processor
  void* store = zorba::StoreManager::getStore();
  if (store == NULL) return 20;

  zorba::Zorba * engine = zorba::Zorba::getInstance(store);
  if (engine == NULL) return 21;

  int i = 1;
  while (i < argc)
  {
//     std::cout << "i: " << i << ", argc: " << argc << std::endl;
    if (strcmp (argv [i], "--rbkt-src") == 0)
    {
      rbkt_src_dir = argv [i + 1];
      i += 2;
    }
    else if (strcmp(argv[i], "--rbkt-src-uri") == 0)
    {
      rbkt_src_dir_uri = argv[i + 1];
      i += 2;
    }
    else if (strcmp (argv [i], "--rbkt-bin") == 0)
    {
      rbkt_bin_dir = argv [i + 1];
      i += 2;
    }
    else if (strcmp(argv[i], "--rbkt-bin-uri") == 0)
    {
      rbkt_bin_dir_uri = argv[i + 1];
      i += 2;
    }
    else if (strcmp (argv [i], "--module-path") == 0)
    {
      lModulePath = argv [i + 1];
      i += 2;
    } else break;
  }

  zorba::XQuery_t lQuery;
  TestDiagnosticHandler errHandler;

  DriverContext driverContext(engine);
  driverContext.theRbktSourceDir = rbkt_src_dir;
  driverContext.theRbktBinaryDir = rbkt_bin_dir;
  driverContext.theSpec = &lSpec;

  for (int testcnt = 1; i < argc; ++i, ++testcnt)
  {
    std::string lQueryFile( rbkt_src_dir );
    zorba::fs::append( lQueryFile, "Queries" );
    zorba::fs::append( lQueryFile, argv[i] );

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY
    if ( zorba::fs::get_type( lQueryFile ) != zorba::fs::file )
    {
      std::cout << "\n query file " << lQueryFile
                << " does not exist or is not a file" << std::endl;
      return 2;
    }
#endif /* ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY */

    // Check if this is w3c_testsuite test.
    std::string path = lQueryFile;
    bool isW3CXQTStest = path.find( "w3c_testsuite" ) != std::string::npos;
    bool isW3CFTtest = path.find( "w3c_full_text_testsuite" ) != std::string::npos;
    bool isW3Ctest = isW3CFTtest || isW3CXQTStest;
    std::string lQueryWithoutSuffix = 
    std::string(argv[i]).substr( 0, std::string(argv[i]).rfind('.') );
    std::unique_ptr<zorba::TestSchemaURIMapper>        smapper;
    std::unique_ptr<zorba::TestModuleURIMapper>        mmapper;
    std::unique_ptr<zorba::TestCollectionURIMapper>    cmapper;
    std::unique_ptr<zorba::TestSchemeURIMapper>        dmapper;
    std::unique_ptr<zorba::TestURLResolver>            tresolver;

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

      smapper.reset(new zorba::TestSchemaURIMapper(uri_map_file.c_str()));

      mmapper.reset(new zorba::TestModuleURIMapper
        (mod_map_file.c_str(), lQueryWithoutSuffix));

      cmapper.reset(
      new zorba::TestCollectionURIMapper(driverContext.theXmlDataMgr,
                                         col_map_file.c_str(),
                                         rbkt_src_dir));

      addURIMapper(driverContext, lContext, smapper.get() );
      addURIMapper(driverContext, lContext, mmapper.get() );
      addURIMapper(driverContext, lContext, cmapper.get() );

      // the w3c testsuite always uses xquery 1.0
      lContext->setXQueryVersion( zorba::xquery_version_1_0 );

      zorba::Item lEnable
        = engine->getItemFactory()->createQName(
            "http://zorba.io/options/features", "", "enable");
      zorba::Item lDisable
        = engine->getItemFactory()->createQName(
            "http://zorba.io/options/features", "", "disable");
      lContext->declareOption(lDisable, "scripting");
    }

    // Form the full pathname for the files that will receive the result or the
    // errors of this query. Then, delete these files if they exist already from
    // previous runs of the query. Finaly, create (if necessary) all the dirs
    // in the pathname of the result and error files.

    std::cout << "test " << lQueryWithoutSuffix << std::endl;

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY
    std::string lResultFile( rbkt_bin_dir );
    zorba::fs::append( lResultFile, "QueryResults" );
    zorba::fs::append( lResultFile, lQueryWithoutSuffix );
    lResultFile += ".xml.res";

    zorba::fs::remove( lResultFile, true );

    // Form the full pathname for the .spec file that may be associated
    // with this query. If the .spec file exists, read its contents to
    // extract args to be passed to the query (e.g., external var bindings),
    // exprected errors, or the pathnames of reference-result files.
    std::string lSpecFile( rbkt_src_dir );
    zorba::fs::append( lSpecFile, "Queries" );
    zorba::fs::append( lSpecFile, lQueryWithoutSuffix );
    lSpecFile += ".spec";

    if ( zorba::fs::get_type( lSpecFile ) )
    {
      bool lParsed = lSpec.parseFile(lSpecFile, rbkt_src_dir, rbkt_src_dir_uri, rbkt_bin_dir, rbkt_bin_dir_uri);
      if (!lParsed) {
        std::cout << "Spec file " << lSpecFile << " is malformed!" << std::endl;
        return 1;
      }
    }

    // If --enable-uritestresolver is specified, enable our document
    // URI resolver for test:// scheme URIs as well as a silly URLResolver
    if (lSpec.getEnableUriTestResolver())
    {
      dmapper.reset(new zorba::TestSchemeURIMapper(rbkt_src_dir));
      addURIMapper(driverContext, lContext, dmapper.get());
      tresolver.reset(new zorba::TestURLResolver());
      addURLResolver(driverContext, lContext, tresolver.get());
    }

    // Bind any options from the .spec file to the static context
    setOptions(driverContext, lContext);

    // Bind any full-text URI resolvers from the .spec file to the
    // static context
    setFullTextURIMappers(driverContext, lContext);

    // If command-line argument --module-path passed, set up module paths.
    setModulePaths(lModulePath, lContext);

    // Get the pathnames of the reference-result files found in the .spec
    // file (if any).
    std::vector<std::string> lRefFiles;
    bool lRefFileExists = false;
    for (std::vector<std::string>::const_iterator lIter = lSpec.resultsBegin();
         lIter != lSpec.resultsEnd();
         ++lIter) 
    {
      std::string lRefFile(*lIter);
      if ( zorba::fs::get_type( lRefFile ) )
      {
        lRefFileExists = true;
      }
      else
      {
        std::cout << "Warning: missing reference result file " 
                  << lRefFile << std::endl;
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
  
      std::string lRefFile( rbkt_src_dir );
      zorba::fs::append( lRefFile, "ExpQueryResults" );
      zorba::fs::append( lRefFile, lRefFileTmpString );
      lRefFile += ".xml.res";
      lRefFiles.push_back( lRefFile );
      if ( zorba::fs::get_type( lRefFiles[0] ) )
        lRefFileExists = true;
    }
#endif//ZORBA_TEST_PLAN_SERIALIZATION_COMPILE_ONLY

#ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY
    // print the query
    std::cout << "=== Query: ===" << std::endl;
    zorba::printFile(std::cout, lQueryFile);
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
    slurp_file(lQueryFile.c_str(), lQueryString, rbkt_src_dir, rbkt_bin_dir);

    lQuery = engine->createQuery(&errHandler);
    lQuery->setFileName(lQueryFile);

    bool lJSONiqMode = 
    (lQueryFile.rfind(".jq") == lQueryFile.size() - 3);

    if (lJSONiqMode) lContext->setJSONiqVersion(zorba::jsoniq_version_1_0);
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
      if(!lQuery->saveExecutionPlan(fbinary))
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
#endif // ZORBA_TEST_PLAN_SERIALIZATION

#endif // #ifndef ZORBA_TEST_PLAN_SERIALIZATION_EXECUTION_ONLY

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

      zorba::TestSerializationCallback serl_callback(driverContext.theURIMappers,
                                                     driverContext.theURLResolvers);

      load_ret = lQuery->loadExecutionPlan(ifbinary, &serl_callback);

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
    createDynamicContext(driverContext, lContext, lQuery, lSpec.getEnableDtd(),
                         errHandler);

    Zorba_SerializerOptions lSerOptions;

    if (errHandler.errors()) 
    {
      errors = analyzeError (lSpec, errHandler);
    }
    else 
    {
      errors = -1;
      {
        // serialize xml/txt
        std::ofstream lResFileStream(lResultFile.c_str());
        assert (lResFileStream.good());
        // QQQ all this code should be in testdriver_common and used by
        // testdriver_mt as well
        // Initialize default serialization method
        lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_JSON_XML_HYBRID;
        lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

        // Now set any options specified in .spec file
        std::vector<Specification::Option>::const_iterator lIter;
        for (lIter = lSpec.serializerOptionsBegin();
             lIter != lSpec.serializerOptionsEnd();
             ++lIter)
        {
          try
          {
            lSerOptions.set(lIter->theOptName.c_str(),
                            lIter->theOptValue.c_str());
          }
          catch ( std::exception const &e )
          {
            std::cerr << e.what() << std::endl;
            return -1;
          }
        }
        
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
        if (lSpec.getComparisonMethod() == "Ignore")
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
          zorba::fs::info fs_info;
          if ( zorba::fs::get_type( lResultFile, &fs_info ) && !fs_info.size )
          {
            std::cout << " but got empty result" << std::endl;
          }
          else 
          {
            std::cout << " but got result:" << std::endl;
            zorba::printFile(std::cout, lResultFile);
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
      zorba::printFile(std::cout, lResultFile);
      std::cout << "=== end of result ===" << std::endl;
      std::cout.flush();
      size_t i = 1;
      bool lResultMatches = false;
      for (std::vector<std::string>::const_iterator lIter = lRefFiles.begin();
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
        // can lead to false positives.
        if (lSerOptions.indent == ZORBA_INDENT_YES) {
          std::cout << "testdriver: skipping canonicalization "
            "when testing with indent==yes" << std::endl;
        }
        // Also skip canonicalization for tests using method==xhtml or html
        // (so we can test for correct serialization of empty elements)
        else if (lSerOptions.ser_method == ZORBA_SERIALIZATION_METHOD_XHTML ||
                 lSerOptions.ser_method == ZORBA_SERIALIZATION_METHOD_HTML) {
          std::cout << "testdriver: skipping canonicalization "
            "when testing with method=[x]html" << std::endl;
        }
        // Also skip canonicalization for tests using method==json
        else if (lSerOptions.ser_method == ZORBA_SERIALIZATION_METHOD_JSON) {
          std::cout << "testdriver: skipping canonicalization "
            "when testing with method=json" << std::endl;
        }
        else 
        {
          int lCanonicalRes = zorba::canonicalizeAndCompare(lSpec.getComparisonMethod(),
            lIter->c_str(),
            lResultFile.c_str());
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
/* vim:set et sw=2 ts=2: */
