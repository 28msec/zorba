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
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>

#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>

#include <zorbatypes/URI.h>

#include <zorbautils/strutil.h>

#include <zorba/store_manager.h>

#include "zorbautils/mutex.h"

#include "util/properties.h"

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testuriresolver.h"
#include "testdriver_comparator.h"
#include "testdriver_common.h"

namespace fs = boost::filesystem;


std::string rbkt_src_dir = zorba::RBKT_SRC_DIR;
std::string rbkt_bin_dir = zorba::RBKT_BINARY_DIR;


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

  theHaveErrors      : True if at least one query run was not successful.

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

  volatile bool                 theHaveErrors;

  std::vector<zorba::Mutex*>    theQueryLocks;
  zorba::Mutex                  theGlobalLock;

public:
  Queries() : theNumRunsPerQuery(1), theNumThreads(1), theHaveErrors(false) {}

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
  fileStream.open(filePath.native_file_string().c_str());
  if (!fileStream.good())
  {
    fs::path dirPath = filePath;
    dirPath = dirPath.remove_leaf();
    
    if (!fs::exists(dirPath))
    {
      fs::create_directories(dirPath);

      fileStream.open(filePath.native_file_string().c_str());
    }

    if (!fileStream.good())
    {
      std::cout << "Could not open file: " 
                << filePath.native_file_string().c_str() << std::endl;
      abort();
    }
  }
}


/*******************************************************************************

********************************************************************************/
bool checkErrors(const Specification& lSpec, const TestErrorHandler& errHandler) 
{
  if (isErrorExpected(errHandler, &lSpec)) 
  {
    printErrors(errHandler,
                "The following execution errors occurred as expected",
                true);
    return true;
  }
  else
  {
    printErrors(errHandler, "Unexpected errors executing query", true);

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
void* thread_main(void* param)
{
  ThreadParams* params = (ThreadParams*)param;

  zorba::Zorba* zorba = params->theZorba;
  Queries* queries = params->theQueries;
  long tno = params->theThreadNo;

  std::ostringstream tmp;
  tmp << tno;
  std::string tnoStr = tmp.str();

  TestErrorHandler errHandler;

  ulong numCanon = 0;

  long queryNo;

  std::string w3cDataDir = "/Queries/w3c_testsuite/TestSources/";
  std::string uri_map_file = rbkt_src_dir + w3cDataDir + "uri.txt";
  std::string mod_map_file = rbkt_src_dir + w3cDataDir + "module.txt";
  std::string col_map_file = rbkt_src_dir + w3cDataDir + "collection.txt";

  std::auto_ptr<zorba::TestSchemaURIResolver>      resolver;
  std::auto_ptr<zorba::TestModuleURIResolver>      mresolver;
  std::auto_ptr<zorba::TestCollectionURIResolver>  cresolver;

  resolver.reset(new zorba::TestSchemaURIResolver(uri_map_file.c_str(), false));

  cresolver.reset(new zorba::TestCollectionURIResolver(col_map_file.c_str(),
                                                       rbkt_src_dir));

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
      std::cout << "Thread " << tno << " finished " << std::endl;
      std::cout << std::endl << "Number of canonicaliations = " << numCanon << std::endl;
      queries->theGlobalLock.unlock();
      return 0;
    }

    queries->theQueryLocks[queryNo]->lock();
    queries->theGlobalLock.unlock();
    sched_yield();

    // Form the full pathname for the file containing the query.
    relativeQueryFile = queries->theQueryFilenames[queryNo];
    queryPath = fs::path(queries->theQueriesDir) / (relativeQueryFile);

    std::string testName = fs::change_extension(queryPath, "").native_file_string();
    ulong pos = testName.find("Queries");
    testName = testName.substr(pos + 8);

    std::cout << "*** " << queryNo << " : " << testName
              << " by thread " << tno << std::endl << std::endl;

    // Form the full pathname for the .spec file that may be associated
    // with this query. If the .spec file exists, read its contents to
    // extract args to be passed to the query (e.g., external var bindings),
    // exprected errors, or the pathnames of reference-result files.
    specPath = fs::change_extension(queryPath, ".spec");
    if (fs::exists(specPath))
      querySpec.parseFile(specPath.native_file_string()); 

    // Get the pathnames of the ref-result files found in the .spec file (if any).
    // If no ref-results file was specified in the .spec file, create a default
    // finename for that file. For w3c tests, the ref file is the same for
    // xqueryx and xquery tests, hence, we remove the string xqueryx or xquery
    // from the path
    for (std::vector<std::string>::const_iterator iter = querySpec.resultsBegin();
         iter != querySpec.resultsEnd();
         ++iter) 
    {
      std::string tmp = *iter;
      zorba::str_replace_all(tmp, "$RBKT_SRC_DIR", rbkt_src_dir);
      fs::path refFilePath(tmp);
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
      mresolver.reset(new zorba::TestModuleURIResolver(mod_map_file.c_str(),
                                                       testName,
                                                       false));
      sctx->addSchemaURIResolver(resolver.get());
      sctx->addModuleURIResolver(mresolver.get());
      sctx->setCollectionURIResolver(cresolver.get());

      sctx->setXQueryVersion(xquery_version_1_0);
    }

    // Set the error file to be used by the error handler for the current query
    errHandler.setErrorFile(errorFilePath.native_file_string());

    //
    // Compile the query, if it has not been compiled already. 
    //
    if (queries->theQueryObjects[queryNo] == 0)
    {
      slurp_file(queryPath.native_file_string().c_str(),
                 queryString,
                 rbkt_src_dir,
                 rbkt_bin_dir);

      try
      {
        query = zorba->createQuery(&errHandler);
        query->setFileName(queryPath.native_file_string());
        query->compile(queryString.c_str(), sctx, getCompilerHints());
      }
      catch(...)
      {
        std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                  << " : " << queries->theQueryFilenames[queryNo]
                  << std::endl << std::endl 
                  << "Reason: received an unexpected exception during compilation"
                  << std::endl << std::endl;

        queries->theQueryLocks[queryNo]->unlock();
        failure = true;
        goto done;
      }

      if (errHandler.errors())
      {
        if (checkErrors(querySpec, errHandler))
        {
          queries->theQueryLocks[queryNo]->unlock();
          goto done;
        }
        else
        {
          std::cout << "FAILURE : thread " << tno << " query " << queryNo
                    << " : " << queries->theQueryFilenames[queryNo]
                    << std::endl << std::endl 
                    << "Reason: received the following unexpected compilation errors : ";
          printErrors(errHandler, NULL, false);
          std::cerr << std::endl << std::endl;

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

    query->registerErrorHandler(&errHandler);


    //
    // Execute the query
    //
    try
    {
      createDynamicContext(driverContext, sctx, query);
      
      Zorba_SerializerOptions lSerOptions;
      lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_XML;
      lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
      lSerOptions.indent = ZORBA_INDENT_NO;

      query->execute(resFileStream, &lSerOptions);
      resFileStream.close();
    }
    catch(...)
    {
      std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                << " : " << queries->theQueryFilenames[queryNo]
                << std::endl << std::endl 
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
      if (!checkErrors(querySpec, errHandler))
      {
        std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                  << " : " << queries->theQueryFilenames[queryNo]
                  << std::endl << std::endl 
                  << "Reason: received the following unexpected errors : ";
        printErrors(errHandler, NULL, false);
        std::cerr << std::endl << std::endl;

        failure = true;
        goto done;
      }
    }
    else if (querySpec.errorsSize() > 0 && !refFileSpecified)
    {
      std::cout << "FAILURE : thread " << tno << " query " << queryNo
                << " : " << queries->theQueryFilenames[queryNo]
                << std::endl << std::endl
                << "Reason: should have received one of the following expected errors : ";

      for (std::vector<std::string>::const_iterator lIter = querySpec.errorsBegin();
           lIter != querySpec.errorsEnd();
           ++lIter)
      {
        std::cerr << " " << *lIter;
      }
      std::cerr << std::endl << std::endl;

      failure = true;
      goto done;
    }
    else 
    {
      bool foundRefFile = false;
      ulong i;
      for (i = 0; i < refFilePaths.size(); i++) 
      {
        const char* refFilePath = refFilePaths[i].native_file_string().c_str();
        const char* resFilePath = resultFilePath.native_file_string().c_str();

        int lLine, lCol, lPos; 
        std::string lRefLine, lResultLine;
        bool success = zorba::fileEquals(refFilePath, resFilePath,
                                         lLine, lCol, lPos,
                                         lRefLine, lResultLine);
        if (success)
        {
          foundRefFile = true;
          break;
        }

        ++numCanon;
        int lCanonicalRes = zorba::canonicalizeAndCompare(querySpec.getComparisonMethod(),
                                                          refFilePath,
                                                          resFilePath,
                                                          rbkt_bin_dir);
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
          std::cout << "FAILURE : thread " << tno << " query " << queryNo
                    << " : " << queries->theQueryFilenames[queryNo]
                    << std::endl << std::endl
                    << "Reason: no reference result files exist."
                    << std::endl << std::endl;
        }
        else
        {
          std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                    << " : " << queries->theQueryFilenames[queryNo]
                    << std::endl << std::endl
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
      queries->theHaveErrors = true;
      queries->theQueryStates[queryNo] = false;
    }

    errHandler.clear();
  } // choose and process next query
}


void usage()
{
  std::cerr << "\nusage: testdriver_mt -b <bucket> [-t <numThreads>] [-n <runsPerQuery>]"
            << std::endl;
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
  std::string queriesDir;
  std::string resultsDir;
  std::string refsDir;
  std::string reportFilename = "mt.log";
  std::string reportFilepath;

  fs::path bucketPath;

  long numThreads = 1;

  Queries queries;

  signal(SIGSEGV, sigHandler);

  // Parse the arg list
  if ( argc < 3 || argc > 7)
    usage();

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
      queries.theNumRunsPerQuery = atol(argv[arg]);
      if (queries.theNumRunsPerQuery <= 0)
        usage();
    }
    else if (!strcmp(argv[arg], "-b"))
    {
      arg++;
      bucketName = argv[arg]; 
    }
    else if (!strcmp(argv[arg], "-o"))
    {
      arg++;
      reportFilename = argv[arg]; 
    }
    else
    {
      usage();
    }

    arg++;
  }

  queries.theNumThreads = numThreads;

  //
  // Create the full pathname for the top-level query, results, and ref-results
  // directories
  //
  queriesDir = zorba::RBKT_SRC_DIR + "/Queries/" + bucketName;
  resultsDir = zorba::RBKT_BINARY_DIR + "/QueryResults/" + bucketName;
  refsDir = zorba::RBKT_SRC_DIR + "/ExpQueryResults/" + bucketName;

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
  bucketPath = fs::system_complete(fs::path(queriesDir, fs::native));
  if (!fs::is_directory(bucketPath))
  {
    std::cerr << "The directory " << queriesDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theQueriesDir = bucketPath.native_directory_string();

  bucketPath = fs::system_complete(fs::path(refsDir, fs::native));
  if (!fs::is_directory(bucketPath))
  {
    std::cerr << "The directory " << refsDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theRefsDir = bucketPath.native_directory_string();

  bucketPath = fs::system_complete(fs::path(resultsDir, fs::native));
  if (!fs::exists(bucketPath))
  {
    fs::create_directories(bucketPath);
  }
  else if (!fs::is_directory(bucketPath))
  {
    std::cerr << "The pathname " << resultsDir << " is not a directory" << std::endl;
    exit(2);
  }
  queries.theResultsDir = bucketPath.native_directory_string();

  //
  // Search and collect all the query files in the bucket.
  //
  std::cout << "Searching for queries in directory " << queries.theQueriesDir
            << std::endl << std::endl;

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

  queries.theNumQueries = queries.theQueryFilenames.size();

  std::cout << queries.theNumQueries << " queries were found in directory "
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

  //
  // Produce report about failed tests
  //
  std::ofstream reportFile(reportFilepath.c_str());

  std::ostringstream tmp;
  long numFailures = 0;
  
  if (queries.theHaveErrors)
  {
    std::string pathPrefix = "test/rbkt/" + bucketName;

    for (long i = 0; i < queries.theNumQueries; i++)
    {
      if (queries.theQueryStates[i] == false)
      {
        numFailures++;

        fs::path queryPath = fs::path(pathPrefix) /
                             (queries.theQueryFilenames[i]);

        fs::path queryName = fs::change_extension(queryPath, "");

        tmp << i << ":" << queryName.file_string() << std::endl;
        reportFile << i << ":" << queryName.file_string() << std::endl;
      }
    }
  }

  std::cout << std::endl << std::endl
            << "***********************************************************************"
            << std::endl << std::endl << "Number of queries run = " 
            << queries.theNumQueries << std::endl << "Number of failures = " 
            << numFailures << std::endl;

  if (numFailures > 0)
    std::cout << std::endl << "Failed queries: " << std::endl << tmp.str() << std::endl;

  //
  // shutdown
  //
  delete [] threads;
  queries.clear();
  zorba->shutdown();
  zorba::StoreManager::shutdownStore(store);

  if (queries.theHaveErrors)
    return 1;
  else
    return 0;
}
