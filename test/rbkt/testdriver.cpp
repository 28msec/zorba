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

zorba::Properties *lProp;

#define EXPECTED_ERROR  0
#define UNEXPECTED_ERROR  6

std::string rbkt_src_dir = zorba::RBKT_SRC_DIR, rbkt_bin_dir = zorba::RBKT_BINARY_DIR;

void loadProperties () 
{
  zorba::Properties::load(0, NULL);
}



// print parts of a file
// starting at aStartPos with the length of aLen
void printPart(std::ostream& os, std::string aInFile, int aStartPos, int aLen)
{
  char* buffer = new char [aLen];
  try {
    std::ifstream lIn(aInFile.c_str());
    lIn.seekg(aStartPos);

#ifdef WIN32
    int lCharsRead = lIn._Readsome_s (buffer, aLen, aLen);
#else
    int lCharsRead = lIn.readsome (buffer, aLen);
#endif
    os.write (buffer, lCharsRead);
    os.flush();
    delete[] buffer;
  } catch (...)
  {
    delete[] buffer;
  }
  return;
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


void
trim(std::string& str) {

  std::string::size_type  notwhite = str.find_first_not_of(" \r\t\n");
  str.erase(0,notwhite);

  notwhite = str.find_last_not_of(" \t\n\r"); 
  str.erase(notwhite+1); 
}

// return false if the files are not equal
// aLine contains the line number in which the first difference occurs
// aCol contains the column number in which the first difference occurs
// aPos is the character number off the first difference in the file
// -1 is returned for aLine, aCol, and aPos if the files are equal
bool
fileEquals(zorba::file aRefFile, zorba::file aResFile, int& aLine, int& aCol, int& aPos,
        std::string& aRefLine, std::string& aResLine)
{
  std::ifstream li(aRefFile.get_path().c_str());
  std::ifstream ri(aResFile.get_path().c_str()); 
#ifdef ENABLE_SAXON_COMPARE
  
  std::ofstream refwrapped ( "/tmp/ref.xml" );
  std::ofstream reswrapped ( "/tmp/res.xml" );
  li.seekg( 0, std::ifstream::end );
  long size = li.tellg();
  li.seekg( 0 );
  refwrapped << "<root>" << std::endl;
  char * buffer = new char [size ];
  li.read ( buffer, size );
  refwrapped.write ( buffer, size );
  refwrapped << "</root>" << std::endl;
  refwrapped.close();
  delete [] buffer;
  ri.seekg ( 0, std::ifstream::end );
  size = ri.tellg();
  ri.seekg ( 0 );
  reswrapped << "<root>" << std::endl;
  buffer = new char [size];
  ri.read ( buffer, size );
  reswrapped.write ( buffer, size );
  reswrapped << "</root>" << std::endl;
  reswrapped.close ();
  delete [] buffer;
  return true;
#endif
  std::string filepath = aResFile.get_path ();
  std::string::size_type pos = filepath.find ( "w3c_testsuite" );
  bool w3ctest = pos != std::string::npos;
  std::string lLine, rLine;
  std::string xmldecl ( "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");

  if (w3ctest) std::cout << "This is a w3c test.\n";
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
    if ( w3ctest && (rLine.compare ( xmldecl ) == 0)  ) {
      std::getline ( ri, rLine );
    }
    if ( w3ctest && (lLine.compare ( xmldecl ) == 0)  ) {
      std::getline ( li, lLine );
    }
    trim ( lLine );
    trim ( rLine );
    if ( (aCol = lLine.compare(rLine)) != 0) {
      aRefLine = lLine;
      aResLine = rLine;
      return false;
    }
    ++aLine;
  }

  return true;
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
    std::cout << "test " << lQueryWithoutSuffix << std::endl;

    zorba::file lResultFile (rbkt_bin_dir + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".xml.res", path_flags);

    zorba::file lErrorFile  (rbkt_bin_dir + "/" 
                             + lQueryWithoutSuffix + ".err", path_flags);

    zorba::file lRefFile (rbkt_src_dir + "/ExpQueryResults/" 
                          + lQueryWithoutSuffix +".xml.res", path_flags);

#ifndef ZORBA_XQUERYX
    zorba::file lSpecFile (rbkt_src_dir + "/Queries/"
                           + lQueryWithoutSuffix +".spec", path_flags);
#else
    std::string   w3c_str;
    int xqueryx_off = 0;
    if(!strcmp(lQueryWithoutSuffix.substr(0, 7).c_str(), "XQueryX"))
    {
      w3c_str = "w3c_testsuite";
      xqueryx_off = 7;
    }
    std::string   spec_fname = rbkt_src_dir + "/Queries/" + w3c_str
                           + lQueryWithoutSuffix.substr(xqueryx_off) +".spec";
    zorba::file lSpecFile (spec_fname, path_flags);
    std::cout << "lSpecFile " << spec_fname << " exists " << lSpecFile.exists() << std::endl; 

    std::string   ref_fname = rbkt_src_dir + "/ExpQueryResults/" 
                          + lQueryWithoutSuffix +".xml.res";
    std::cout << "lRefFile " << ref_fname << std::endl; 

#endif
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
    printFile(std::cout, lQueryFile.get_path());
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
    std::string path = lQueryFile.get_path();
    zorba::TestSchemaURIResolver  * resolver = 0;
    zorba::TestModuleURIResolver  * mresolver = 0;
    std::string uri_map_file = rbkt_src_dir + "/Queries/uri.txt";
    std::string mod_map_file = rbkt_src_dir + "/Queries/module.txt";
    if ( path.find ( "w3c_testsuite" ) != std::string::npos ) {
      resolver = new zorba::TestSchemaURIResolver ( uri_map_file.c_str() );
      mresolver = new zorba::TestModuleURIResolver ( mod_map_file.c_str() );
      lContext->setSchemaURIResolver ( resolver );
      lContext->setModuleURIResolver ( mresolver );
    }
    TestErrorHandler errHandler;

    // create and compile the query
    std::string lQueryString;
    slurp_file(lQueryFile.get_path().c_str(), lQueryString, rbkt_src_dir, rbkt_bin_dir);
    zorba::XQuery_t lQuery = engine->createQuery (&errHandler);
    lQuery->setFileName (lQueryFile.get_path ());
    lQuery->compile (lQueryString.c_str(), lContext, getCompilerHints());

    if (resolver != 0 ) {
      delete resolver;
    }
    if (mresolver != 0 ) {
      delete mresolver;
    }
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

      if (lSpec.hasTimezoneSet()) {
        int lTimezone = atoi(lSpec.getTimezone().c_str());
        std::cout << "timezone " << lTimezone << std::endl;
        lDynCtxt->setImplicitTimezone(lTimezone);
      }

      set_vars(&lSpec, lDynCtxt, rbkt_src_dir);
      if ( lSpec.hasInputQuery () ) {
	const std::string & inputqueryfile = lSpec.getInputQueryFile ();
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
          lResFileStream << lQuery;
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
              printFile(std::cout, lResultFile.get_path());
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
        printFile(std::cout, lResultFile.get_path());
        std::cout << "=== end of result ===" << std::endl;
        std::cout.flush();

        // last, we have to diff the result
        int lLine, lCol, lPos; // where do the files differ
        std::string lRefLine, lResultLine;
        bool lRes = fileEquals(lRefFile, lResultFile, lLine, lCol, lPos, lRefLine, lResultLine);
        if ( !lRes ) {  // results differ
          std::cout << std::endl << "Result does not match expected result:" << std::endl;
          printFile(std::cout, lRefFile.get_path());
          std::cout << "=== end of expected result ===" << std::endl;

          std::cout << "See line " << lLine << ", col " << lCol << " of expected result. " << std::endl;
          std::cout << "Actual:   <";
          if( -1 != lPos )
            printPart(std::cout, lResultFile.get_path(), lPos, 15);
          else
            std::cout << lResultLine;
          std::cout << ">" << std::endl;
          std::cout << "Expected: <";
          if( -1 != lPos )
            printPart(std::cout, lRefFile.get_path(), lPos, 15);
          else
            std::cout << lRefLine;
          std::cout << ">" << std::endl;

          return 8;
        }
      }
    }
  }
  std::cout << "testdriver: success" << std::endl;
  return 0;
}
