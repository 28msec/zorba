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

// used for Canonical XML
#define LIBXML_C14N_ENABLED
#define LIBXML_OUTPUT_ENABLED
#include <libxml/c14n.h>
#include <libxml/tree.h>


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
fileEquals(const char* aRefFile, const char* aResFile, int& aLine, int& aCol, int& aPos,
        std::string& aRefLine, std::string& aResLine)
{
  std::ifstream li(aRefFile);
  std::ifstream ri(aResFile); 
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

    trim ( lLine );
    trim ( rLine );
    if ( (aCol = lLine.compare(rLine)) != 0) 
    {
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
    std::auto_ptr<zorba::TestSchemaURIResolver>      resolver;
    std::auto_ptr<zorba::TestModuleURIResolver>      mresolver;
    std::auto_ptr<zorba::TestCollectionURIResolver>  cresolver;
    std::string uri_map_file = rbkt_src_dir + "/Queries/uri.txt";
    std::string mod_map_file = rbkt_src_dir + "/Queries/module.txt";
    std::string col_map_file = rbkt_src_dir + "/Queries/collection.txt";

    if ( path.find ( "w3c_testsuite" ) != std::string::npos ) 
    {
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
        {
          int lLine, lCol, lPos; // where do the files differ
          std::string lRefLine, lResultLine;
          bool lRes = fileEquals(lRefFile.c_str(), lResultFile.c_str(), lLine, lCol, lPos, lRefLine, lResultLine);
          if (lRes) {
            std::cout << "testdriver: success (non-canonical result matches)" << std::endl;
            return 0;
          }
        }

        // canonicalize XML and perform comparison
        {
          xmlDocPtr lRefResult_ptr;
          xmlDocPtr lResult_ptr;
  
          LIBXML_TEST_VERSION

          std::string lComparisonMethod = lSpec.getComparisonMethod();
          if (lComparisonMethod.compare("XML") == 0) {
            lRefResult_ptr = xmlReadFile(lRefFile.c_str(), 0, 0);
            lResult_ptr    = xmlReadFile(lResultFile.c_str(), 0, 0);
          } else if (lComparisonMethod.compare("Text") == 0 || lComparisonMethod.compare("Fragment") == 0) {
            // prepend and append an artifical root tag as requested by the guidelines
            std::ostringstream lTmpRefResult;
            lTmpRefResult << "<root>" << std::endl;
            std::ifstream lRefInStream(lRefFile.c_str());
            char buf[1024];

            while (!lRefInStream.eof()) {
              lRefInStream.read(buf, 1024);
              lTmpRefResult.write(buf, lRefInStream.gcount());
            }
            if (buf[lRefInStream.gcount()-1] != '\n')
              lTmpRefResult << std::endl;
            lTmpRefResult << "</root>";
            lRefResult_ptr = xmlReadMemory(lTmpRefResult.str().c_str(), lTmpRefResult.str().size(), "ref_result.xml", 0, 0);

            // prepend and append an artifical root tag as requested by the guidelines
            std::ostringstream lTmpResult;
            lTmpResult << "<root>" << std::endl;
            std::ifstream lInStream(lResultFile.c_str());

            while (!lInStream.eof()) {
              lInStream.read(buf, 1024);
              lTmpResult.write(buf, lInStream.gcount());
            }
            lTmpResult << std::endl << "</root>";
            lResult_ptr = xmlReadMemory(lTmpResult.str().c_str(), lTmpResult.str().size(), "result.xml", 0, 0);
            
          } else if (lComparisonMethod.compare("Error") == 0 ) {
            std::cout << "an error was expected but we got a result" << std::endl;
            return 8;
          } else if (lComparisonMethod.compare("Inspect") == 0 ) {
            std::cout << "result must be inspected by humans." << std::endl;
            return 0;
          } else if (lComparisonMethod.compare("Ignore") == 0 ) {
            // safely return no error here
            return 0;
          }

          if (lRefResult_ptr == NULL || lResult_ptr == NULL) {
              std::cerr << "couldn't read reference result or result file" << std::endl;
              return 8;
          }

          std::string lCanonicalRefFile = rbkt_bin_dir + "/canonical_ref.xml";
          std::string lCanonicalResFile = rbkt_bin_dir + "/canonical_res.xml";

          int lRefResultRes = xmlC14NDocSave(lRefResult_ptr, 0, 0, NULL, 0, lCanonicalRefFile.c_str(), 0);
          int lResultRes    = xmlC14NDocSave(lResult_ptr, 0, 0, NULL, 0, lCanonicalResFile.c_str(), 0);

          xmlFreeDoc(lRefResult_ptr);
          xmlFreeDoc(lResult_ptr);

          if (lRefResultRes < 0) {
            std::cerr << "error canonicalizing reference result" << std::endl;
            return 10;
          }
      
          if (lResultRes < 0) {
            std::cerr << "error canonicalizing result" << std::endl;
            return 10;
          }

          // last, we have to diff the result
          int lLine, lCol, lPos; // where do the files differ
          std::string lRefLine, lResultLine;
          bool lRes = fileEquals(lCanonicalRefFile.c_str(), lCanonicalResFile.c_str(), lLine, lCol, lPos, lRefLine, lResultLine);
          if (!lRes) {
            std::cout << std::endl << "Canonical result does not match canonical expected result:" << std::endl;
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
  }
  std::cout << "testdriver: success" << std::endl;
  return 0;
}
