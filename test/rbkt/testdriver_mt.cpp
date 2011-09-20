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
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
#include <set>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <zorba/zorba.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/zorba_exception.h>

#include <zorbatypes/URI.h>

#include "util/ascii_util.h"

#include <zorba/store_manager.h>

#include "zorbautils/mutex.h"

#include "system/properties.h"

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testuriresolver.h"
#include "testdriver_comparator.h"
#include "testdriver_common.h"

#define BOOST_FILESYSTEM_VERSION 2

// These are included last because they define the <stdint.h>'s INTMAX_C and UINTMAX_C
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>


namespace fs = boost::filesystem;


std::string rbkt_src_dir = zorba::RBKT_SRC_DIR;
std::string rbkt_bin_dir = zorba::RBKT_BINARY_DIR;
std::string module_path;

/*******************************************************************************
  theQueriesDir      : The full pathname of the dir that contains the queries
                       to run. It is created by appending the user-provided
                       bucket name to RBKT_SRC_DIR/Queries (for example,
                       RBKT_SRC_DIR/Queries/w3c_testsuite/Expressions).
  theRefsDir         : The full pathname of the dir that contains the expected
                       results of the queries. It is created by appending the
                       user-provided bucket name to RBKT_SRC_DIR/ExpQueryResults.
  theResultsDir      : The full pathname of the directory under which the result
                       and error files of the queries will be placed. It is
                       created by appending the user-provided bucket name to
                       RBKT_BINARY_DIR/QueryResults.

  theQueryFilenames  : The relative pathnames of the queries found under
                       theQueriesDir. The pathname are relative to theQueriesDir.

  theNumQueries      : The number of queries found under theQueriesDir.

  theNumRunsPerQuery : The number of times to run each query.

  theNumQueryRuns    : How many times has each query being run so far.

  theQueryObjects    : Pointers to the compiled query object for each query.

  theQueryStates     : For each query, whether the query was run successfuly or not.

  theQueryLocks      :
  theGlobalLock      :

********************************************************************************/
class Queries
{
public:
  std::string                   theQueriesDir;
  std::string                   theRefsDir;
  std::string                   theResultsDir;

  std::vector<std::string>      theQueryFilenames;

  bool                          theIsW3Cbucket;

  long                          theNumQueries;

  long                          theNumRunsPerQuery;

  std::vector<long>             theNumQueryRuns;

  std::vector<zorba::XQuery_t>  theQueryObjects;

  std::vector<bool>             theQueryStates;

  long                          theNumThreads;

  std::ostream&                 theOutput;

  std::vector<zorba::Mutex*>    theQueryLocks;
  zorba::Mutex                  theGlobalLock;

public:
  Queries(std::ostream& lOutput)
    : theNumRunsPerQuery(1), theNumThreads(1), theOutput(lOutput) {}

  ~Queries();

  void clear();

  long getQuery();
};


Queries::~Queries()
{
  clear();
}


void Queries::clear()
{
  for (long i = 0; i < theNumQueries; i++)
  {
    theQueryObjects[i] = NULL;
    delete theQueryLocks[i];
  }

  theQueryFilenames.clear();
  theNumQueryRuns.clear();
  theQueryObjects.clear();

  theNumQueries = 0;
}


long Queries::getQuery()
{
  static long nextQuery = 0;

  if (theNumThreads == 1)
  {
    if (nextQuery == theNumQueries)
      return -1;

    if (theNumQueryRuns[nextQuery] == theNumRunsPerQuery)
    {
      ++nextQuery;

      if (nextQuery == theNumQueries)
        return -1;
    }

    theNumQueryRuns[nextQuery]++;
    return nextQuery;
  }

  long randomNum = rand();

  long q1 = randomNum % theNumQueries;
  long q = q1;

  if (theNumQueryRuns[q1] == theNumRunsPerQuery)
  {
    for (; q != theNumQueries && theNumQueryRuns[q] == theNumRunsPerQuery; q++) ;

    if (q == theNumQueries)
    {
      for (q = 0; q < q1 && theNumQueryRuns[q] == theNumRunsPerQuery; q++) ;

      if (q == q1)
        return -1;
    }
  }

  theNumQueryRuns[q]++;
  return q;
}


/*******************************************************************************

********************************************************************************/
struct ThreadParams
{
  zorba::Zorba   * theZorba;
  Queries        * theQueries;
  long             theThreadNo;

  ThreadParams(zorba::Zorba* zorba, Queries* queries, long tno)
    :
    theZorba(zorba),
    theQueries(queries),
    theThreadNo(tno)
  {
  }
};



/*******************************************************************************
  Signal handler function
********************************************************************************/
void sigHandler(int sigNum)
{
  signal(SIGSEGV, sigHandler);

  std::cerr << "Received signal " << sigNum << std::endl;
  abort();
}


/*******************************************************************************
  Create all the directories in a filepath, if thehy don't exist already, and
  make sure the file can be created/opened. 
********************************************************************************/
void createPath(const fs::path& filePath, std::ofstream& fileStream)
{
  fileStream.open(filePath.file_string().c_str());
  if (!fileStream.good())
  {
    fs::path dirPath = filePath;
    dirPath = dirPath.remove_leaf();
    
    if (!fs::exists(dirPath.file_string()))
    {
      fs::create_directories(dirPath.file_string());

      // clear the bad flag on windows, which for some unknown reason doesn't reset when opening a file again
      fileStream.clear(); 
      fileStream.open(filePath.file_string().c_str());
    }

    if (!fileStream.good())
    {
      std::cerr << "Could not open file: " 
                << filePath.file_string() << std::endl;
      abort();
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool checkErrors(const Specification& lSpec, const TestDiagnosticHandler& errHandler, std::ostream& lOutput) 
{
  if (isErrorExpected(errHandler, &lSpec)) 
  {
    printErrors(errHandler,
      "The following execution errors occurred as expected",
      true,
      lOutput);
    return true;
  }
  else
  {
    printErrors(errHandler, "Unexpected errors executing query", true, lOutput);

    std::ofstream errFile(errHandler.getErrorFile().c_str());

    errFile << "Expected error(s)";
    for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
         lIter != lSpec.errorsEnd(); ++lIter)
    {
      errFile << " " << *lIter;
    }
    errFile << std::endl;
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
#ifndef WIN32
void* thread_main(void* param)
#else
DWORD WINAPI thread_main(LPVOID param)
#endif
{
  ThreadParams* params = (ThreadParams*)param;

  zorba::Zorba* zorba = params->theZorba;
  Queries* queries = params->theQueries;
  long tno = params->theThreadNo;

  std::ostringstream tmp;
  tmp << tno;
  std::string tnoStr = tmp.str();

  TestDiagnosticHandler errHandler;

  ulong numCanon = 0;

  long queryNo;

  std::string w3cDataDir = "/Queries/w3c_testsuite/TestSources/";
  std::string uri_map_file = rbkt_src_dir + w3cDataDir + "uri.txt";
  std::string mod_map_file = rbkt_src_dir + w3cDataDir + "module.txt";
  std::string col_map_file = rbkt_src_dir + w3cDataDir + "collection.txt";

  std::auto_ptr<zorba::TestSchemaURIMapper> smapper
    (new zorba::TestSchemaURIMapper(uri_map_file.c_str(), false));
  std::auto_ptr<zorba::TestModuleURIMapper> mmapper;
  std::auto_ptr<zorba::TestCollectionURIMapper>    cmapper;
  std::auto_ptr<zorba::TestSchemeURIMapper>    dmapper;
  std::auto_ptr<zorba::TestURLResolver> tresolver;

  while (1)
  {
    Specification querySpec;

    std::string relativeQueryFile;
    fs::path queryPath;
    fs::path specPath;
    std::vector<fs::path> refFilePaths;
    bool refFileSpecified = false;
    fs::path resultFilePath;
    fs::path errorFilePath;

    std::string queryString;

    bool failure = false;

    DriverContext driverContext;
    driverContext.theEngine = zorba;
    driverContext.theRbktSourceDir = rbkt_src_dir;
    driverContext.theRbktBinaryDir = rbkt_bin_dir;
    driverContext.theSpec = &querySpec;

    zorba::XQuery_t query;

    // Choose a query to run. If no query is available, the thread finishes. 
    // To choose the next query, the whole query container must be locked.
    // After the query is chosen, we release the global container lock and
    // acquire the query-specific lock for the chosen query. The query lock
    // is needed to protect the queries->theQueryObjects[queryNo] position and
    // to make sure that the query will be compiled only once.
    queries->theGlobalLock.lock();

    queryNo = queries->getQuery();

    if (queryNo < 0)
    {
      queries->theOutput << "Thread " << tno << " finished " << std::endl;
      queries->theOutput << std::endl << "Number of canonicaliations = " << numCanon << std::endl;
      queries->theGlobalLock.unlock();
      return 0;
    }

    queries->theQueryLocks[queryNo]->lock();
    queries->theGlobalLock.unlock();
#ifndef WIN32
    sched_yield();
#else
    // SwitchToThread();
#endif

    // Form the full pathname for the file containing the query.
    relativeQueryFile = queries->theQueryFilenames[queryNo];
    queryPath = fs::path(queries->theQueriesDir) / (relativeQueryFile);

    std::string testName = fs::change_extension(queryPath, "").file_string();
    ulong pos = testName.find("Queries");
    testName = testName.substr(pos + 8);

    queries->theOutput << "*** " << queryNo << " : " << testName
                       << " by thread " << tno << std::endl << std::endl;

    // Form the full pathname for the .spec file that may be associated
    // with this query. If the .spec file exists, read its contents to
    // extract args to be passed to the query (e.g., external var bindings),
    // exprected errors, or the pathnames of reference-result files.
    specPath = fs::change_extension(queryPath, ".spec");
    if (fs::exists(specPath))
      querySpec.parseFile(specPath.file_string(), rbkt_src_dir, rbkt_bin_dir); 

    // Get the pathnames of the ref-result files found in the .spec file (if any).
    // If no ref-results file was specified in the .spec file, create a default
    // finename for that file. For w3c tests, the ref file is the same for
    // xqueryx and xquery tests, hence, we remove the string xqueryx or xquery
    // from the path
    for (std::vector<std::string>::const_iterator iter = querySpec.resultsBegin();
         iter != querySpec.resultsEnd();
         ++iter) 
    {
      fs::path refFilePath(*iter);
      refFileSpecified = true;
      refFilePaths.push_back(refFilePath);
    }

    if (refFilePaths.size() == 0) 
    {
      std::string relativeRefFile = relativeQueryFile;
      if (queries->theIsW3Cbucket)
      {
        ulong pos;
        if ((pos = relativeRefFile.find("XQueryX")) != std::string::npos)
          relativeRefFile = relativeRefFile.erase(pos, 8);
        else if ((pos = relativeRefFile.find("XQuery")) != std::string::npos)
          relativeRefFile = relativeRefFile.erase(pos, 7);
      }

      fs::path refFilePath = fs::path(queries->theRefsDir) / (relativeRefFile);
      refFilePath = fs::change_extension(refFilePath, ".xml.res");

      if (fs::exists(refFilePath)) 
        refFileSpecified = true;

      refFilePaths.push_back(refFilePath);
    }

    // Form the full pathname for the files that will receive the result or the
    // errors of this query. Then, delete these files if they exist already from
    // previous runs of the query. Finaly, create (if necessary) all the dirs
    // in the pathname of the result and error files.
    resultFilePath = fs::path(queries->theResultsDir) / (relativeQueryFile);
    resultFilePath = fs::change_extension(resultFilePath, (".res_" + tnoStr));
    errorFilePath = fs::path(queries->theResultsDir) / (relativeQueryFile);
    errorFilePath = fs::change_extension(errorFilePath, (".err_" + tnoStr));

    if (fs::exists(resultFilePath)) fs::remove(resultFilePath);
    if (fs::exists(errorFilePath)) fs::remove(errorFilePath);

    std::ofstream resFileStream;
    std::ofstream errFileStream;
    createPath(resultFilePath, resFileStream);
    createPath(errorFilePath, errFileStream);

    // Create the static context. If this is a w3c query, install special uri
    // resolvers in the static context.
    zorba::StaticContext_t sctx = zorba->createStaticContext();

    if (queries->theIsW3Cbucket) 
    {
      mmapper.reset
        (new zorba::TestModuleURIMapper(mod_map_file.c_str(),
          testName, false));
      cmapper.reset(new zorba::TestCollectionURIMapper(
            col_map_file.c_str(), rbkt_src_dir));
      addURIMapper(driverContext, sctx, smapper.get());
      addURIMapper(driverContext, sctx, mmapper.get());
      addURIMapper(driverContext, sctx, cmapper.get());

      sctx->setXQueryVersion(zorba::xquery_version_1_0);
      zorba::Item lEnable
        = zorba->getItemFactory()->createQName(
              "http://www.zorba-xquery.com/options/features", "", "enable");
      zorba::Item lDisable
        = zorba->getItemFactory()->createQName(
            "http://www.zorba-xquery.com/options/features", "", "disable");
      sctx->declareOption(lEnable, "hof");
      sctx->declareOption(lDisable, "scripting");
      sctx->setTraceStream(queries->theOutput);
    }

    // If --enable-uritestresolver is specified, enable our document
    // URI resolver for test:// scheme URIs as well as a silly URLResolver
    if (querySpec.getEnableUriTestResolver()) {
      dmapper.reset(new zorba::TestSchemeURIMapper(rbkt_src_dir));
      addURIMapper(driverContext, sctx, dmapper.get());
      tresolver.reset(new zorba::TestURLResolver());
      addURLResolver(driverContext, sctx, tresolver.get());
    }

    // Set any options on the static context
    setOptions(driverContext, sctx);

    // Bind any full-text URI resolvers from the .spec file to the
    // static context
    setFullTextURIMappers(driverContext, sctx);

    // If command-line argument --module-path passed, set up module paths.
    setModulePaths(module_path, sctx);

    // Set the error file to be used by the error handler for the current query
    errHandler.setErrorFile(errorFilePath.file_string());

    //
    // Compile the query, if it has not been compiled already. 
    //
    if (queries->theQueryObjects[queryNo] == 0)
    {
      slurp_file(queryPath.file_string().c_str(),
                 queryString,
                 rbkt_src_dir,
                 rbkt_bin_dir);

      try
      {
        query = zorba->createQuery(&errHandler);
        query->setFileName(queryPath.file_string());
        query->compile(queryString.c_str(), sctx, getCompilerHints());
      }
      catch(...)
      {
        queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                           << " : " << queries->theQueryFilenames[queryNo]
                           << std::endl
                           << "Reason: received an unexpected exception during compilation"
                           << std::endl << std::endl;

        queries->theQueryLocks[queryNo]->unlock();
        failure = true;
        goto done;
      }

      if (errHandler.errors())
      {
        if (checkErrors(querySpec, errHandler, queries->theOutput))
        {
          queries->theQueryLocks[queryNo]->unlock();
          goto done;
        }
        else
        {
          queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                             << " : " << queries->theQueryFilenames[queryNo]
                             << std::endl
                             << "Reason: received the following unexpected compilation errors : ";
          printErrors(errHandler, NULL, false, queries->theOutput);
          queries->theOutput << std::endl << std::endl;

          queries->theQueryLocks[queryNo]->unlock();
          failure = true;
          goto done;
        }
      }

      queries->theQueryObjects[queryNo] = query;
    }

    queries->theQueryLocks[queryNo]->unlock();

    //
    // Clone the compiled query and register with it the error handler of the
    // current thread.
    // 
    query = queries->theQueryObjects[queryNo]->clone();

    query->registerDiagnosticHandler(&errHandler);


    //
    // Execute the query
    //
    try
    {
      createDynamicContext(driverContext, sctx, query, querySpec.getEnableDtd(),
                           errHandler);
      if (!errHandler.errors()) {
        Zorba_SerializerOptions lSerOptions;
        lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
        lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
        lSerOptions.indent = ZORBA_INDENT_NO;

        query->execute(resFileStream, &lSerOptions);
        resFileStream.close();
      }
    }
    catch(...)
    {
      queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                         << " : " << queries->theQueryFilenames[queryNo]
                         << std::endl
                         << "Reason: received an unexpected exception during execution"
                         << std::endl << std::endl;
      failure = true;
      goto done;
    }

    //
    // Check result agains expected result
    //
    if (errHandler.errors())
    {
      if (!checkErrors(querySpec, errHandler, queries->theOutput))
      {
        queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                           << " : " << queries->theQueryFilenames[queryNo]
                           << std::endl
                           << "Reason: received the following unexpected errors : ";
        printErrors(errHandler, NULL, false, queries->theOutput);
        queries->theOutput << std::endl << std::endl;

        failure = true;
        goto done;
      }
    }
    else if (querySpec.getComparisonMethod() != "Ignore" 
             && querySpec.errorsSize() > 0 && !refFileSpecified)
    {
      queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                         << " : " << queries->theQueryFilenames[queryNo]
                         << std::endl
                         << "Reason: should have received one of the following expected errors : ";

      for (std::vector<std::string>::const_iterator lIter = querySpec.errorsBegin();
           lIter != querySpec.errorsEnd();
           ++lIter)
      {
        queries->theOutput << " " << *lIter;
      }
      queries->theOutput << std::endl << std::endl;

      failure = true;
      goto done;
    }
    else 
    {
      bool foundRefFile = false;
      ulong i;
      for (i = 0; i < refFilePaths.size(); i++) 
      {
        std::string refFilePath = refFilePaths[i].file_string();
        std::string resFilePath = resultFilePath.file_string();

        int lLine, lCol; 
        std::string lRefLine, lResultLine;
        bool success = zorba::fileEquals(refFilePath.c_str(), resFilePath.c_str(),
                                         lLine, lCol,
                                         lRefLine, lResultLine,
                                         queries->theOutput);
        if (success)
        {
          foundRefFile = true;
          break;
        }

        ++numCanon;
        int lCanonicalRes = zorba::canonicalizeAndCompare(querySpec.getComparisonMethod(),
                                                          refFilePath.c_str(),
                                                          resFilePath.c_str(),
                                                          rbkt_bin_dir,
                                                          queries->theOutput);
        if (lCanonicalRes == 0)
        {
          foundRefFile = true;
          break;
        }

        if (fs::exists(refFilePaths[i]))
          foundRefFile = true;
      }

      if (!foundRefFile || i == refFilePaths.size())
      {
        if (!foundRefFile)
        {
          queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                             << " : " << queries->theQueryFilenames[queryNo]
                             << std::endl
                             << "Reason: no reference result files exist."
                             << std::endl << std::endl;
        }
        else
        {
          queries->theOutput << "FAILURE : thread " << tno << " query " << queryNo
                             << " : " << queries->theQueryFilenames[queryNo]
                             << std::endl
                             << "Reason: result does not match any of the expected results"
                             << std::endl << std::endl;
        }

        failure = true;
        goto done;
      }
    }

done:
    if (failure)
    {
      zorba::AutoMutex(queries->theQueryLocks[queryNo]);
      queries->theQueryStates[queryNo] = false;
    }

    errHandler.clear();
  } // choose and process next query
}


void usage()
{
  std::cerr << "\nusage: testdriver_mt -b <bucket> [options]       OR" << std::endl
            << "       testdriver_mt -p <path-to-bucket> [options]" << std::endl
            << "Options:" << std::endl
            << "  [-t <numThreads>] [-n <runsPerQuery>] [-e test-name] [-q]" << std::endl
            << "  [-k <known-failures file>] [-o <report logfile>]" << std::endl
            << "  -q - Quiet; only a summary report will be displayed." << std::endl;
  exit(1);
}


int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
  main(int argc, char** argv)
#endif
{
  zorba::Properties::load(0, NULL);

  std::string bucketName;
  std::string bucketPath;
  std::string queriesDir;
  std::string resultsDir;
  std::string refsDir;
  std::string modulePath;
  std::string reportFilename = "mt.log";
  std::string reportFilepath;
  std::string knownFailuresFilepath;
  bool haveKnownFailures = false;
  bool quiet = false;

  fs::path path;
  std::set<std::string> knownFailures;

  std::vector<std::string> testNames;

  long numThreads = 1;
  long numRunsPerQuery = 1;

  signal(SIGSEGV, sigHandler);

  // Parse the arg list
  long arg = 1;
 
  while (arg < argc)
  {
    if (!strcmp(argv[arg], "-t"))
    {
      arg++;
      numThreads = atol(argv[arg]);
      if (numThreads <= 0)
        usage();
    }
    else if (!strcmp(argv[arg], "-n"))
    {
      arg++;
      numRunsPerQuery = atol(argv[arg]);
      if (numRunsPerQuery <= 0)
        usage();
    }
    else if (!strcmp(argv[arg], "-b"))
    {
      arg++;
      bucketName = argv[arg]; 
    }
    else if (!strcmp(argv[arg], "-p"))
    {
      arg++;
      bucketPath = argv[arg];
    }
    else if (!strcmp(argv[arg], "-e"))
    {
      arg++;
      testNames.push_back(argv[arg]);
    }
    else if (!strcmp(argv[arg], "-o"))
    {
      arg++;
      reportFilename = argv[arg]; 
    }
    else if (!strcmp(argv[arg], "-k"))
    {
      arg++;
      knownFailuresFilepath = argv[arg];
      haveKnownFailures = true;
    }
    else if (!strcmp(argv[arg], "-q"))
    {
      quiet = true;
    }
    else if (!strcmp(argv[arg], "--module-path"))
    {
      arg++;
      module_path = argv[arg];
    }
    else
    {
      usage();
    }

    arg++;
  }

  if (bucketName == "" && bucketPath == "") 
  {
    usage();
  }

  // This is a cheap and easy way to make a "null" ostream:
  std::ostringstream nullstream;
  nullstream.clear(std::ios::badbit);
  Queries queries(quiet ? nullstream : std::cout);
  queries.theNumRunsPerQuery = numRunsPerQuery;
  queries.theNumThreads = numThreads;

  // Unfortunately there are still places SOMEwhere (in zorba? in a
  // dependent library?) that output to stderr. It's important for the
  // remote queue in particular that -q actually work, so we attempt
  // to shut them up here. QQQ if we can figure out where those
  // messages are coming from it would be better to fix those than
  // take this heavy-handed approach.
  if (quiet) {
#ifndef WIN32
    close(2);
#else
    fclose(stderr);
#endif
  }

  //
  // Create the full pathname for the top-level query, results, and ref-results
  // directories
  //
  if (bucketPath == "") {
    bucketPath = zorba::RBKT_SRC_DIR;
    // QQQ Probably should have an option for specifying alternative
    // resultsDir too
  }
  else {
    rbkt_src_dir = bucketPath;
  }
  queriesDir = bucketPath + "/Queries/" + bucketName;
  resultsDir = zorba::RBKT_BINARY_DIR + "/QueryResults/" + bucketName;
  refsDir = bucketPath + "/ExpQueryResults/" + bucketName;

  queries.theIsW3Cbucket = (bucketName.find("w3c_testsuite") != std::string::npos);

  if (queries.theIsW3Cbucket)
  {
    ulong pos;
    if ((pos = refsDir.find("XQueryX")) != std::string::npos)
      refsDir = refsDir.erase(pos, 8);
    else if ((pos = refsDir.find("XQuery")) != std::string::npos)
      refsDir = refsDir.erase(pos, 7);
  }

  reportFilepath = zorba::RBKT_BINARY_DIR + "/../../Testing/" + reportFilename;

  //
  // Make sure the directories exist. For the results dir, if it doesn't exist,
  // it is created.
  //
  path = fs::system_complete(fs::path(queriesDir, fs::native));
  if (!fs::is_directory(path))
  {
    std::cerr << "The directory " << queriesDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theQueriesDir = path.native_directory_string();

  path = fs::system_complete(fs::path(refsDir, fs::native));
  if (!fs::is_directory(path))
  {
    std::cerr << "The directory " << refsDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theRefsDir = path.native_directory_string();

  path = fs::system_complete(fs::path(resultsDir, fs::native));
  if (!fs::exists(path))
  {
    fs::create_directories(path);
  }
  else if (!fs::is_directory(path))
  {
    std::cerr << "The pathname " << resultsDir << " is not a directory" << std::endl;
    exit(2);
  }
  queries.theResultsDir = path.native_directory_string();

  //
  // Search and collect all the query files in the bucket, unless some
  // specific test names were mentioned.
  //
  if (testNames.size() == 0) {
    queries.theOutput << "Searching for queries in directory "
                      << queries.theQueriesDir << std::endl << std::endl;

    fs::recursive_directory_iterator endDirIte;
    fs::recursive_directory_iterator dirIte(queries.theQueriesDir);

    for (; dirIte != endDirIte; dirIte++)
    {
      fs::path queryPath = *dirIte;

      if (!fs::is_regular(queryPath))
      {
        //std::cerr << "Found non-regular file " << queryPath.string() << std::endl;
        continue;
      }

      if (fs::extension(queryPath) != ".xq")
      {
        //std::cerr << "Found no-query file " << queryPath.string() << std::endl;
        continue;
      }

      std::string queryFile = queryPath.file_string();
      std::string relativeQueryFile = queryFile.substr(queries.theQueriesDir.size());

      queries.theQueryFilenames.push_back(relativeQueryFile);
    }
  }
  else 
  {
    queries.theQueryFilenames = testNames;
  }

  queries.theNumQueries = queries.theQueryFilenames.size();

  queries.theOutput << queries.theNumQueries
                    << " queries were found in directory "
                    << queries.theQueriesDir << std::endl << std::endl;

  //
  // Prepare the Queries container
  //
  queries.theNumQueryRuns.resize(queries.theNumQueries);
  queries.theQueryObjects.resize(queries.theNumQueries);
  queries.theQueryLocks.resize(queries.theNumQueries);
  queries.theQueryStates.resize(queries.theNumQueries);

  for (long i = 0; i < queries.theNumQueries; i++)
  {
    queries.theNumQueryRuns[i] = 0;
    queries.theQueryLocks[i] = new zorba::Mutex();
    queries.theQueryStates[i] = true;
  }

  //
  // Start the store and zorba
  //
  void* store = zorba::StoreManager::getStore();

  zorba::Zorba* zorba = zorba::Zorba::getInstance(store);

  //
  // Create and start the threads, then wait for all the threads to finish
  //
#ifndef WIN32
  pthread_t* threads = new pthread_t[numThreads];
  for (long i = 0; i < numThreads; i++)
  {
    ThreadParams* params = new ThreadParams(zorba, &queries, i);
    pthread_create(&threads[i], NULL, thread_main, (void*)params);
  }

  for(long i = 0; i < numThreads; i++)
  {
    void* thread_result;
    pthread_join(threads[i], &thread_result);
  }
  // shutdown
  delete[] threads;

#else  

  // Windows code
  HANDLE* threads = new HANDLE[numThreads]; // pthread_t* threads = new pthread_t[numThreads];
  DWORD* thread_ids = new DWORD[numThreads];

  for (long i = 0; i < numThreads; i++)
  {
    ThreadParams* params = new ThreadParams(zorba, &queries, i);
    CreateThread(NULL, 0, thread_main, (void*)params, 0, &thread_ids[i]);
  }

  WaitForMultipleObjects(numThreads, threads, TRUE, INFINITE);
  
  // shutdown
  delete[] threads;
  delete[] thread_ids;
#endif

  queries.theOutput << std::endl
                    << "***********************************************************************"
                    << std::endl;

  //
  // If known-failures file specified, load it into a map for quick lookups.
  //
  if (haveKnownFailures) 
  {
    queries.theOutput << std::endl << "Loading known failures file "
                      << knownFailuresFilepath << "..." << std::endl;
    std::ifstream knownFailuresFile(knownFailuresFilepath.c_str());
    while (knownFailuresFile.good()) 
    {
      std::string testname;
      getline(knownFailuresFile, testname);
      knownFailures.insert(testname);
    }
    queries.theOutput << "Loaded " << knownFailures.size() 
                      << " known failures" << std::endl << std::endl;
  }

  //
  // Produce report about failed tests - report will look different
  // depending on whether we have a known-failures file and can report
  // on regressions/progressions or not. Also keep a running list of
  // failed tests.
  //
  std::ostringstream report;
  std::ostringstream failedTests;
  long numFailures = 0;
  long numRegressions = 0;
  long numProgressions = 0;

  std::string pathPrefix = "test/rbkt/" + bucketName;

  for (long i = 0; i < queries.theNumQueries; i++)
  {
    fs::path queryPath = fs::path(pathPrefix) / (queries.theQueryFilenames[i]);
    fs::path queryName = fs::change_extension(queryPath, "");
    bool queryWasKnownToFail = false;
    if (haveKnownFailures) 
    {
      queryWasKnownToFail = (knownFailures.count(queryName.file_string()) != 0);
    }

    if (queries.theQueryStates[i] == false)
    {
      numFailures++;
      failedTests << queryName.file_string() << std::endl;

      if (haveKnownFailures && !queryWasKnownToFail)
      {
        numRegressions++;
        report << "REGRESSION:" << i << ":"
               << queryName.file_string() << std::endl;
      }
      else if (!haveKnownFailures)
      {
        report << i << ":" << queryName.file_string() << std::endl;
      }
    }
    else
    {
      if (haveKnownFailures && queryWasKnownToFail)
      {
        numProgressions++;
        report << "Progression:" << i << ":"
               << queryName.file_string() << std::endl;
      }
    }
  }

  std::ofstream reportFile(reportFilepath.c_str());
  reportFile << report.str();

  // Don't use theOutput here - this is the summary we always want to
  // see
  std::cout << "Number of queries run = " 
            << queries.theNumQueries << std::endl << "Number of failures = " 
            << numFailures << std::endl;

  if (haveKnownFailures)
  {
    std::cout << "Number of regressions = " << numRegressions << std::endl;
    std::cout << "Number of progressions = " << numProgressions << std::endl;
    if (report.str().length() > 0) 
    {
      std::cout << std::endl << "Individual test reports:" << std::endl
                << report.str() << std::endl;
    }
    if (numRegressions == 0 && numProgressions > 0) 
    {
      std::cout << "No regressions and some progressions!" << std::endl
                << "Updating known failures file "
                << knownFailuresFilepath << std::endl;
      std::ofstream knownFailuresFile(knownFailuresFilepath.c_str());
      knownFailuresFile << failedTests.str();
    }
  }
  else
  {
    if (report.str().length() > 0)
      std::cout << std::endl << "Failed queries: " << std::endl
                << report.str() << std::endl;
  }
  
  queries.clear();
  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);

  if (haveKnownFailures)
  {
    return (numRegressions == 0) ? 0 : 1;
  }
  else
  {
    return (numFailures == 0) ? 0 : 1;
  }
}
