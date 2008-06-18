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

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/algorithm/string.hpp>

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>

#include <zorbatypes/URI.h>
#include <inmemorystore/inmemorystore.h>
#include "zorbautils/mutex.h"
#include "store/naive/simple_store.h"

namespace fs = boost::filesystem;


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

********************************************************************************/
class TestErrorHandler : public zorba::ErrorHandler 
{
public:
  void staticError(const zorba::StaticException& aStaticError)
  {
    registerError(aStaticError);
  }

  void dynamicError(const zorba::DynamicException& aDynamicError)
  {
    registerError(aDynamicError);
  }

  void typeError(const zorba::TypeException& aTypeError)
  {
    registerError(aTypeError);
  }

  void serializationError(const zorba::SerializationException& aSerializationError)
  {
    registerError(aSerializationError);
  }

  void systemError(const zorba::SystemException& aSystemError)
  {
    registerError(aSystemError);
  }

  bool errors() const
  {
    return !m_errors.empty();
  }

  const std::vector<std::string>& getErrorList() const
  {
    return m_errors;
  }

  const std::vector<zorba::String>& getErrorDescs() const
  {
    return m_desc;
  }

  void clear()
  {
    m_errors.clear();
    m_desc.clear();
  }

  const std::string& getErrorFile() const
  {
    return theErrorFile;
  }

  void setErrorFile(const std::string& file)
  {
    theErrorFile = file;
  }


private:
  std::vector<std::string>    m_errors;
  std::vector<zorba::String>  m_desc;
  std::string                 theErrorFile;

  void registerError(const zorba::ZorbaException& e)
  {
    m_errors.push_back(zorba::ZorbaException::getErrorCodeAsString(e.getErrorCode()).c_str());
    m_desc.push_back(e.getDescription());
  }
};


/*******************************************************************************
  Check if an error that was repored was expected by the given specification
  object.
********************************************************************************/
bool
isErrorExpected(const TestErrorHandler& errHandler, const Specification* aSpec)
{
  const std::vector<std::string>& errors = errHandler.getErrorList();
  for(std::vector<std::string>::const_iterator i = errors.begin(); i != errors.end(); ++i) 
  {
    for(std::vector<std::string>::const_iterator j = aSpec->errorsBegin();
        j != aSpec->errorsEnd();
        ++j) 
    {
      if (i->compare(*j) == 0)
        return true;
    }
  }
  return false;
}


/*******************************************************************************
  Print all errors that were raised
********************************************************************************/
void
printErrors(const TestErrorHandler& errHandler, const char *msg, bool printInFile)
{
  if (!errHandler.errors()) 
  {
    return;
  }

  std::ofstream errFile(errHandler.getErrorFile().c_str());

  if (msg)
  {
    if (printInFile)
      errFile << msg << ":" << std::endl;
    else
      std::cout << msg << ":" << std::endl;
  }

  const std::vector<std::string>& errors = errHandler.getErrorList();
  const std::vector<zorba::String>& descs = errHandler.getErrorDescs();

  std::vector<std::string>::const_iterator codeIter = errors.begin();
  std::vector<zorba::String>::const_iterator descIter = descs.begin();

  for(; codeIter != errors.end(); ++codeIter, ++descIter) 
  {
    assert (descIter != descs.end());
    if (printInFile)
      errFile << *codeIter << ": " << *descIter << std::endl;
    else
      std::cout << *codeIter << ": " << *descIter << std::endl;
  }
  return;
}


/*******************************************************************************

********************************************************************************/
bool checkErrors(const Specification &lSpec, const TestErrorHandler& errHandler) 
{
  if (isErrorExpected(errHandler, &lSpec)) 
  {
    printErrors(errHandler, "The following execution errors occurred as expected", true);
    return true;
  }
  else
  {
    printErrors(errHandler, "Unexpected errors executing query", true);
    std::cerr << "Expected error(s)";
    for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
         lIter != lSpec.errorsEnd(); ++lIter)
    {
      std::cerr << " " << *lIter;
    }
    std::cerr << std::endl;
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
void
printFile(std::ostream& os, std::string filename)
{
  std::ifstream lInFileStream(filename.c_str());
  assert(lInFileStream);

  os << lInFileStream.rdbuf() << std::endl;
}


/*******************************************************************************
  Open the file with name "filename" and, starting from position "startPos", 
  print up to "len" bytes from that file into "os".
********************************************************************************/
void
printPart(std::ostream& os, std::string filename, int startPos, int len)
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

********************************************************************************/
void 
slurp_file (const char* fname, std::string& result) 
{
  std::ifstream qfile(fname, std::ios::binary | std::ios_base::in);
  assert (qfile);

  qfile.seekg(0, std::ios::end);
  size_t len = qfile.tellg();

  char* str = new char [len];

  qfile.seekg (0, std::ios::beg);
  qfile.read(str, len);

  len = qfile.gcount();

  std::string sstr(str, len);
  std::string rbkt_src_uri = zorba::URI::encode_file_URI(zorba::RBKT_SRC_DIR)->str();
  boost::replace_all(sstr, "$RBKT_SRC_DIR", rbkt_src_uri);
  result.swap(sstr);

  delete [] str;
}


/*******************************************************************************

********************************************************************************/
Zorba_CompilerHints
getCompilerHints()
{
  Zorba_CompilerHints lHints;

  // ZORBA_OPTLEVEL=O0 | O1
  char* lOptLevel = getenv("ZORBA_OPTLEVEL");
  if ( lOptLevel != NULL && strcmp(lOptLevel, "O0") == 0 ) 
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
    //std::cout << "testdriver_mt is using optimization level O0" << std::endl;
  }
  else
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    //std::cout << "testdriver_mt is using optimization level O1" << std::endl;
  }
  return lHints; 
}


/*******************************************************************************
  Set a variable in the dynamic context
  inlineFile specifies whether the given parameter is a file and its value
  should be inlined or not
********************************************************************************/
void
set_var(bool inlineFile, std::string name, std::string val, zorba::DynamicContext* dctx)
{
  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(NULL)->getItemFactory();

  boost::replace_all(val, "$RBKT_SRC_DIR", zorba::RBKT_SRC_DIR);
  if (!inlineFile)
  {
    val = zorba::URI::encode_file_URI (val)->str ();
    zorba::Item lItem = lFactory->createString(val);
		if(name != ".")
			dctx->setVariable (name, lItem);
		else
			dctx->setContextItem (lItem);
  }
  else
  {
    const char *val_fname = val.c_str ();
    std::ifstream* is = new std::ifstream(val_fname);
    if (! is) 
    {
      std::cerr << "Could not open file `" << val_fname << "' for variable `"
                << name << "'" << std::endl;
      assert (false);
    }
		if(name != ".")
			dctx->setVariableAsDocument (name, val.c_str(), std::auto_ptr<std::istream>(is));
		else
			dctx->setContextItemAsDocument (val.c_str(), std::auto_ptr<std::istream>(is));
  }
}


void 
set_vars (Specification* aSpec, zorba::DynamicContext* dctx) 
{
  std::vector<Specification::Variable>::const_iterator lIter;
  for (lIter = aSpec->variablesBegin();
       lIter != aSpec->variablesEnd();
       ++lIter)
  {
    set_var((*lIter).theInline, (*lIter).theVarName, (*lIter).theVarValue, dctx);
  }
}


/*******************************************************************************
  Return false if the files are not equal.
  aLine contains the line number in which the first difference occurs
  aCol contains the column number in which the first difference occurs
  aPos is the character number off the first difference in the file
  -1 is returned for aLine, aCol, and aPos if the files are equal
********************************************************************************/
bool
isEqual(fs::path aRefFile, fs::path aResFile, int& aLine, int& aCol, int& aPos)
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
    ++aLine;
    if ( (aCol = lLine.compare(rLine)) != 0) {
      return false;
    }
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
  fs::path refPath;
  fs::path resultPath;
  fs::path errorPath;

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

    std::cout << "**********************************************************************"
              << std::endl << std::endl << "Thread " << tno << " starting query "
              << queryNo << std::endl << "in file " << queries->theQueryFilenames[queryNo]
              << std::endl << std::endl;

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
    // Then, delete previous result and error files, if they exist.
    //
    relativeQueryFile = queries->theQueryFilenames[queryNo];

    queryPath = fs::path(queries->theQueriesDir) / (relativeQueryFile);
    specPath = fs::change_extension(queryPath, ".spec");
    refPath = fs::path(queries->theRefsDir) / (relativeQueryFile);
    refPath = fs::change_extension(refPath, ".xml.res");
    resultPath = fs::path(queries->theResultsDir) / (relativeQueryFile);
    resultPath = fs::change_extension(resultPath, (".res_" + tnoStr));
    errorPath = fs::path(queries->theResultsDir) / (relativeQueryFile);
    errorPath = fs::change_extension(errorPath, (".err_" + tnoStr));

    if (fs::exists(resultPath)) fs::remove(resultPath);
    if (fs::exists(errorPath)) fs::remove(errorPath);

    //
    // Set the error file to be used by the error handler for the current query
    //
    errHandler.setErrorFile(errorPath.file_string());

    //
    // Read the xargs and expected errors from the spec file, if it exists
    //
    Specification querySpec;
    if (fs::exists(specPath)) 
      querySpec.parseFile(specPath.file_string()); 


    //
    // Compile the current query, if it has not been compiled already. 
    //
    if (queries->theQueryObjects[queryNo] == 0)
    {
      // Read the query string from the query file
      slurp_file(queryPath.file_string().c_str(), queryString);

      // Compile the query
      zorba::XQuery_t query = zorba->createQuery(&errHandler);
      query->setFileName(queryPath.file_string());
      query->compile(queryString.c_str(), getCompilerHints());

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
          std::cerr << "FAILURE : thread " << tno << " query " << queryNo
                    << " : " << queries->theQueryFilenames[queryNo]
                    << std::endl << std::endl 
                    << "Reason: received the following unexpected compilation errors : ";
          printErrors(errHandler, NULL, false);
          std::cerr << std::endl << std::endl;

          queries->theHaveErrors = true;
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

    set_vars(&querySpec, lDynCtxt);

    std::ofstream resFileStream(resultPath.native_file_string().c_str());
    assert (resFileStream.good());

    resFileStream << query << std::endl;
    resFileStream.flush();

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
    else if (querySpec.errorsSize() > 0 && !fs::exists(refPath))
    {
      std::cerr << "FAILURE : thread " << tno << " query " << queryNo
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
    else
    {
      int lLine, lCol, lPos;
      bool success = isEqual(refPath, resultPath, lLine, lCol, lPos);
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
  std::string bucketName;
  std::string queriesDir;
  std::string resultsDir;
  std::string refsDir;

  fs::path bucketPath;

  long numThreads = 0;

  Queries queries;

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
    else
    {
      usage();
    }

    arg++;
  }

  //
  // Create the full pathnames for the bucket query, results, and ref-results directories
  //
  queriesDir = zorba::RBKT_SRC_DIR +"/Queries/" + bucketName;
  refsDir = zorba::RBKT_SRC_DIR +"/ExpQueryResults/" + bucketName;
  resultsDir = zorba::RBKT_BINARY_DIR +"/QueryResults/" + bucketName;

  //
  // Make sure the directories exists
  //
  bucketPath = fs::system_complete(fs::path(queriesDir, fs::native));
  if (!fs::is_directory(bucketPath))
  {
    std::cerr << "The directory " << queriesDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theQueriesDir = bucketPath.directory_string();

  bucketPath = fs::system_complete(fs::path(refsDir, fs::native));
  if (!fs::is_directory(bucketPath))
  {
    std::cerr << "The directory " << refsDir << " could not be found" << std::endl;
    exit(2);
  }
  queries.theRefsDir = bucketPath.directory_string();

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
  queries.theResultsDir = bucketPath.directory_string();

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
  zorba::store::SimpleStore* store = zorba::inmemorystore::InMemoryStore::getInstance();
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

  std::ostringstream tmp;
  long numFailures = 0;
  
  if (queries.theHaveErrors)
  {
    for (long i = 0; i < queries.theNumQueries; i++)
    {
      if (queries.theQueryStates[i] == false)
      {
        numFailures++;

        fs::path queryPath = fs::path(queries.theQueriesDir) /
                             (queries.theQueryFilenames[i]);

        tmp << queryPath.file_string() << std::endl;
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
  zorba::inmemorystore::InMemoryStore::shutdown(store);

  if (queries.theHaveErrors)
    return 1;
  else
    return 0;
}
