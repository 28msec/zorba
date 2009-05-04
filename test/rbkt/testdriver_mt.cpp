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

#include <simplestore/simplestore.h>

#include "zorbautils/mutex.h"

#include "util/properties.h"

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "testdriver_common.h"

namespace fs = boost::filesystem;


std::string rbkt_src_dir = zorba::RBKT_SRC_DIR;
std::string rbkt_bin_dir = zorba::RBKT_BINARY_DIR;


zorba::Properties *lProp;

void loadProperties() 
{
  zorba::Properties::load(0, NULL);
}


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

  long                          theNumQueries;

  long                          theNumRunsPerQuery;

  std::vector<long>             theNumQueryRuns;

  std::vector<zorba::XQuery_t>  theQueryObjects;

  std::vector<bool>             theQueryStates;

  volatile bool                 theHaveErrors;

  long                          theNumThreads;

  std::vector<zorba::Mutex*>    theQueryLocks;
  zorba::Mutex                  theGlobalLock;

public:
  Queries() : theHaveErrors(false) {}

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
    printErrors(errHandler, "The following execution errors occurred as expected",
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
  Open the file with name "filename" and, starting from position "startPos", 
  print up to "len" bytes from that file into "os".
********************************************************************************/
void printPart(std::ostream& os, std::string filename, int startPos, int len)
{
  char* buffer = new char [len];
  try 
  {
    std::ifstream lIn(filename.c_str());
    lIn.seekg(startPos);

    int charsRead = lIn.readsome(buffer, len);
    os.write(buffer, charsRead);
    os.flush();
    delete[] buffer;
  }
  catch (...)
  {
    delete[] buffer;
  }
  return;
}


/*******************************************************************************
  Return false if the files are not equal.
  aLine contains the line number in which the first difference occurs
  aCol contains the column number in which the first difference occurs
  aPos is the character number off the first difference in the file
  -1 is returned for aLine, aCol, and aPos if the files are equal
********************************************************************************/
bool isEqual(fs::path aRefFile, fs::path aResFile, int& aLine, int& aCol, int& aPos)
{
  std::ifstream li(aRefFile.native_file_string().c_str());
  std::ifstream ri(aResFile.native_file_string().c_str()); 
  
  std::string lLine, rLine;

  aLine = 1; aCol = 0; aPos = -1;
  while (! li.eof() )
  {
    if ( ri.eof() ) 
    {
      std::getline(li, lLine);
      if (li.peek() == -1) // ignore end-of-line in the ref result
        return true;
      else 
        return false;
    }
    std::getline(li, lLine);
    std::getline(ri, rLine);
    if ( (aCol = lLine.compare(rLine)) != 0) {
      return false;
    }
    ++aLine;
  }

  return true;
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

  long queryNo;

  std::string relativeQueryFile;
  fs::path queryPath;
  fs::path specPath;
  fs::path refFilePath;
  fs::path resultFilePath;
  fs::path errorFilePath;

  std::string queryString;

  while (1)
  {
    queries->theGlobalLock.lock();

    //
    // Choose a query to run. If no query is available, the thread finishes. 
    //
    queryNo = queries->getQuery();

    if (queryNo < 0)
    {
      std::cout << "Thread " << tno << " finished " << std::endl;
      queries->theGlobalLock.unlock();
      return 0;
    }

    std::cout << "*** " << queryNo << " in file " 
              << queries->theQueryFilenames[queryNo]
              << " by thread " << tno << std::endl << std::endl;

    //
    // Release the global lock on the queries container and acquire the 
    // query-specific lock for the chosen query. The query lock is needed
    // to protect the queries->theQueryObjects[queryNo] position and to
    // make sure that the query will be compiled only once.
    //
    queries->theQueryLocks[queryNo]->lock();
    queries->theGlobalLock.unlock();
    sched_yield();

    //
    // Determine the full pathnames for the spec, ref, result, and error files.
    // Then, delete previous result and error files, if they exist, and create
    // new (empty) instance of them.
    //
    relativeQueryFile = queries->theQueryFilenames[queryNo];

    queryPath = fs::path(queries->theQueriesDir) / (relativeQueryFile);
    specPath = fs::change_extension(queryPath, ".spec");
    refFilePath = fs::path(queries->theRefsDir) / (relativeQueryFile);
    refFilePath = fs::change_extension(refFilePath, ".xml.res");
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

    //
    // Set the error file to be used by the error handler for the current query
    //
    errHandler.setErrorFile(errorFilePath.native_file_string());

    //
    // Read the xargs and expected errors from the spec file, if it exists
    //
    Specification querySpec;
    if (fs::exists(specPath))
      querySpec.parseFile(specPath.native_file_string()); 

    //
    // Compile the current query, if it has not been compiled already. 
    //
    if (queries->theQueryObjects[queryNo] == 0)
    {
      // Read the query string from the query file
      slurp_file(queryPath.native_file_string().c_str(),
                 queryString,
                 rbkt_src_dir,
                 rbkt_bin_dir);

      zorba::XQuery_t query;

      // Compile the query
      try
      {
        query = zorba->createQuery(&errHandler);
        query->setFileName(queryPath.native_file_string());
        query->compile(queryString.c_str(), getCompilerHints());
      }
      catch(...)
      {
        std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                  << " : " << queries->theQueryFilenames[queryNo]
                  << std::endl << std::endl 
                  << "Reason: received an unexpected exception during compilation"
                  << std::endl << std::endl;

        queries->theHaveErrors = true;
        queries->theQueryStates[queryNo] = false;
        queries->theQueryLocks[queryNo]->unlock();
        errHandler.clear();
        continue;
      }

      if (errHandler.errors())
      {
        if (checkErrors(querySpec, errHandler))
        {
          queries->theQueryLocks[queryNo]->unlock();
          errHandler.clear();
          continue;
        }
        else
        {
          std::cout << "FAILURE : thread " << tno << " query " << queryNo
                    << " : " << queries->theQueryFilenames[queryNo]
                    << std::endl << std::endl 
                    << "Reason: received the following unexpected compilation errors : ";
          printErrors(errHandler, NULL, false);
          std::cerr << std::endl << std::endl;

          queries->theHaveErrors = true;
          queries->theQueryStates[queryNo] = false;
          queries->theQueryLocks[queryNo]->unlock();
          errHandler.clear();
          continue;
        }
      }

      queries->theQueryObjects[queryNo] = query;
    }

    queries->theQueryLocks[queryNo]->unlock();

    //
    // Clone the compiled query and register with it the error handler of the
    // current thread.
    // 
    zorba::XQuery_t query = queries->theQueryObjects[queryNo]->clone();

    query->registerErrorHandler(&errHandler);


    //
    // Execute the query
    //

    // set the variables in the dynamic context
    zorba::DynamicContext* lDynCtxt = query->getDynamicContext();

    if (querySpec.hasDateSet()) 
    {
      // set the current date time such that tests that use fn:current-time
      // behave deterministically
      zorba::Item lDateTimeItem = zorba->getItemFactory()->
                                  createDateTime(querySpec.getDate());

      lDynCtxt->setCurrentDateTime(lDateTimeItem);
    }

    if (querySpec.hasTimezoneSet()) 
    {
      int lTimezone = atoi(querySpec.getTimezone().c_str());

      std::cout << "timezone " << lTimezone << std::endl;
      lDynCtxt->setImplicitTimezone(lTimezone);
    }

    // Set external vars
    set_vars(&querySpec, lDynCtxt, rbkt_src_dir);

    try
    {
      resFileStream << query;
      resFileStream.flush();
    }
    catch(...)
    {
      std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                << " : " << queries->theQueryFilenames[queryNo]
                << std::endl << std::endl 
                << "Reason: received an unexpected exception during execution"
                << std::endl << std::endl;
      
      continue;
    }

    //
    // Check result agains expected result
    //
    if (errHandler.errors())
    {
      if (checkErrors(querySpec, errHandler))
      {
        errHandler.clear();
        continue;
      }
      else
      {
        std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                  << " : " << queries->theQueryFilenames[queryNo]
                  << std::endl << std::endl 
                  << "Reason: received the following unexpected errors : ";
        printErrors(errHandler, NULL, false);
        std::cerr << std::endl << std::endl;

        zorba::AutoMutex(queries->theQueryLocks[queryNo]);
        queries->theHaveErrors = true;
        queries->theQueryStates[queryNo] = false;
        errHandler.clear();
        continue;
      }
    }
    else if (querySpec.errorsSize() > 0 && !fs::exists(refFilePath))
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

      zorba::AutoMutex(queries->theQueryLocks[queryNo]);
      queries->theHaveErrors = true;
      queries->theQueryStates[queryNo] = false;
      errHandler.clear();
      continue;
    }
    else if (!fs::exists(refFilePath))
    {
      std::cout << "FAILURE : thread " << tno << " query " << queryNo
                << " : " << queries->theQueryFilenames[queryNo]
                << std::endl << std::endl
                << "Reason: reference result file : " << refFilePath
                << " does not exist" << std::endl << std::endl;

      zorba::AutoMutex(queries->theQueryLocks[queryNo]);
      queries->theHaveErrors = true;
      queries->theQueryStates[queryNo] = false;
      errHandler.clear();
      continue;
    }
    else
    {
      int lLine, lCol, lPos;
      bool success = isEqual(refFilePath, resultFilePath, lLine, lCol, lPos);
      if (!success)
      {
        std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                  << " : " << queries->theQueryFilenames[queryNo]
                  << std::endl << std::endl
                  << "Reason: did not receive the expected result"
                  << std::endl << std::endl;

        zorba::AutoMutex(queries->theQueryLocks[queryNo]);
        queries->theHaveErrors = true;
        queries->theQueryStates[queryNo] = false;
        errHandler.clear();
        continue;
      }
    }

    errHandler.clear();
  } // choose and process next query
}


void usage()
{
  std::cerr << "\nusage: testdriver_mt -b <bucket> -t <numThreads> -n <runsPerQuery>"
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
  loadProperties();

  std::string bucketName;
  std::string queriesDir;
  std::string resultsDir;
  std::string refsDir;
  std::string reportFilename = "mt.log";
  std::string reportFilepath;

  fs::path bucketPath;

  long numThreads = 0;

  Queries queries;

  signal(SIGSEGV, sigHandler);

  // Parse the arg list
  if ( argc != 7 )
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
  // Create the full pathnames for the bucket query, results, and ref-results directories
  //
  queriesDir = zorba::RBKT_SRC_DIR +"/Queries/" + bucketName;
  refsDir = zorba::RBKT_SRC_DIR +"/ExpQueryResults/" + bucketName;
  resultsDir = zorba::RBKT_BINARY_DIR +"/QueryResults/" + bucketName;

  reportFilepath = zorba::RBKT_BINARY_DIR + "/../../Testing/" + reportFilename;

  //
  // Make sure the directories exists
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
    std::cerr << "The pathname " << refsDir << " is not a directory" << std::endl;
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
  zorba::simplestore::SimpleStore* store =
    zorba::simplestore::SimpleStoreManager::getStore();

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
  zorba::simplestore::SimpleStoreManager::shutdownStore(store);

  if (queries.theHaveErrors)
    return 1;
  else
    return 0;
}
