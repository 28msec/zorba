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
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "testuriresolver.h"
#include "updspecification.h" // parsing spec files
#include "common/common.h"

#include <zorba/zorba.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorba_string.h>
#include <zorba/static_context_consts.h>
#include <zorba/store_consts.h>
#include <zorba/internal/unique_ptr.h>

#include "util/ascii_util.h"
#include "util/fs_util.h"

#include <zorba/store_manager.h>

#include "testdriver_comparator.h"

//#define ZORBA_TEST_PLAN_SERIALIZATION


bool isErrorExpected(zorba::ZorbaException& e, State* aState) 
{
  if ( aState->hasErrors) 
  {
    std::ostringstream oss;
    oss << e.diagnostic().qname().ns() << ":" << e.diagnostic().qname().localname();
    zorba::String lError = oss.str();

    std::vector<std::string>::const_iterator lIter = aState->theErrors.begin();
    std::vector<std::string>::const_iterator lEnd  = aState->theErrors.end();

    for(;lIter!=lEnd;++lIter)
    {
      zorba::String lSpecError = *lIter;
      if (lError.compare(lSpecError) == 0) {
        return true;
      }
    }
  }
  return false;
}


Zorba_CompilerHints getCompilerHints()
{
  Zorba_CompilerHints lHints;

  // ZORBA_OPTLEVEL=O0 | O1
  char* lOptLevel = getenv("ZORBA_OPTLEVEL");
  if ( lOptLevel != NULL && strcmp(lOptLevel, "O0") == 0 ) {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
    std::cout << "testdriver is using optimization level O0" << std::endl;
  } else {
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    std::cout << "testdriver is using optimization level O1" << std::endl;
  }
  return lHints; 
}


// set a variable in the dynamic context
// inlineFile specifies whether the given parameter is a file and it's value should
// be inlined or not
void set_var(
    bool inlineFile,
    std::string name,
    std::string val,
    zorba::XmlDataManager* xmlDataMgr,
    const zorba::StaticContext* sctx,
    zorba::DynamicContext* dctx)
{
  zorba::ascii::replace_all(val, "$UPDATE_SRC_DIR", zorba::UPDATE_SRC_DIR);

  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(NULL)->getItemFactory();

  if (!inlineFile) 
  {
    zorba::Item lItem = lFactory->createString(val);
    if(name != ".")
      dctx->setVariable (name, lItem);
    else
      dctx->setContextItem (lItem);
  }
  else
  {
    std::ifstream is(val.c_str ());
    
    if ( !is )
      std::cout << "Error: Location not found: " << val.c_str() << std::endl;
    
    assert (is);

    zorba::DocumentManager* lDocMgr = xmlDataMgr->getDocumentManager();
        
    zorba::Item lDoc;
    if (lDocMgr->isAvailableDocument(name))
    {
      lDoc = lDocMgr->document(name);
    }
    else
    {
      lDoc = xmlDataMgr->parseXML(is);
      sctx->validate(lDoc, lDoc, zorba::validate_lax);
      lDocMgr->put(name, lDoc);
    }

    if(name != ".")
    {
      dctx->setVariable(name, lDoc);
    }
    else
    {
      dctx->setContextItem(lDoc);
    }
  }
}

#ifdef ZORBA_TEST_PLAN_SERIALIZATION
int save_load_plan(
    zorba::Zorba* engine,
    zorba::XQuery_t &lQuery,
    zorba::URIMapper* smapper,
    std::string lQueryFileString)
{
  try
  {
    clock_t t0, t1;
  std::string binary_path = lQueryFileString;
  binary_path = binary_path.substr( 0, binary_path.rfind('.') );
  binary_path += ".plan";
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

  //now load back
  try
  {
    clock_t t0, t1;
    std::string binary_path = lQueryFileString;
    binary_path = binary_path.substr( 0, binary_path.rfind('.') );
    binary_path += ".plan";
    lQuery = engine->createQuery ();
    t0 = clock();
    std::ifstream   ifbinary(binary_path.c_str(), std::ios_base::binary);
    if(!ifbinary.is_open())
    {
      std::cout << "cannot open plan " << binary_path << std::endl;
      return 15;
    }
    bool load_ret;
    std::vector<zorba::URIMapper*> my_uri_mappers;
    my_uri_mappers.push_back(smapper);
    std::vector<zorba::URLResolver*> my_url_resolvers;
    zorba::TestSerializationCallback  serl_callback(my_uri_mappers, my_url_resolvers);
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


  return 0;
}
#endif//ZORBA_TEST_PLAN_SERIALIZATION

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  if (argc != 2)
  {
    std::cout << "\nusage:   testdriver [testfile]" << std::endl;
    return 1;
  }

  zorba::Zorba* engine = zorba::Zorba::getInstance(zorba::StoreManager::getStore());

  zorba::XmlDataManager_t xmlDataMgr = engine->getXmlDataManager();

  Specification lSpec;

  /*
   * Sanitize paths
   */
  std::string srcDir = zorba::fs::normalize_path(zorba::UPDATE_SRC_DIR);
  std::string binDir = zorba::fs::normalize_path(zorba::UPDATE_BINARY_DIR);
  std::string argString = zorba::fs::normalize_path(std::string(argv[1]));

  std::string lSpecNoSuffix = argString.substr(0, argString.size()-5);

  std::string lSpecFile( srcDir );
  zorba::fs::append( lSpecFile, "Queries" );
  zorba::fs::append(lSpecFile, argString);
  std::string lSpecPath( zorba::fs::dir_name( lSpecFile ) );

  if ( zorba::fs::get_type( lSpecFile ) != zorba::fs::file )
  {
    std::cout << "\n spec file " << lSpecFile
              << " does not exist or is not a file" << std::endl;
    return 2;
  }

  std::cout << "test " << lSpecNoSuffix << std::endl;
  
  std::string lResultFile( binDir );
  zorba::fs::append( lResultFile, "QueryResults" );
  zorba::fs::append( lResultFile, lSpecNoSuffix );
  lResultFile += ".res";

  std::string lRefFile( srcDir );
  zorba::fs::append( lRefFile, "ExpectedTestResults" );
  zorba::fs::append( lRefFile, lSpecNoSuffix );
  lRefFile += ".xml.res";
  std::string lRefPath( zorba::fs::dir_name( lRefFile ) );

  // read the xargs and errors if the spec file exists
  lSpec.parseFile(lSpecFile); 

  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  std::unique_ptr<zorba::TestSchemaURIMapper> smapper;

  ulong numQueries = (ulong)lSpec.theStates.size();

  //
  // For each query in the spec file
  //
  for(ulong curQuery = 0; curQuery < numQueries; ++curQuery)
  {
    State* lState = lSpec.theStates[curQuery];

    zorba::XQuery_t lQuery;

    //
    // Open the query file
    //
    std::string qname_str;
    if(lSpecPath.find("XQueryX") == std::string::npos)
      qname_str = lState->theName + ".xq";
    else
      qname_str = lState->theName + ".xqx";

    std::cout << "query name = " << qname_str << std::endl;

    std::string lQueryFile(lSpecPath);
    zorba::fs::append( lQueryFile, qname_str );

    std::cout << std::endl << "Query (Run " << curQuery+1 << "):" << std::endl;
    std::cout << "Query file " << lQueryFile << ": " << std::endl;
    zorba::printFile(std::cout, lQueryFile);
    std::cout << std::endl;
    std::ifstream lQueryStream(lQueryFile.c_str());

    //
    // Create static context and set it up. 
    // Create and compile the query object.
    //
    try 
    {
      zorba::StaticContext_t lContext = engine->createStaticContext();
      std::string path = lQueryFile;

      if (path.find("w3c_update_testsuite") != std::string::npos) 
      {
        lContext->setXQueryVersion(zorba::xquery_version_1_0);

        std::string uri_map_file = zorba::fs::normalize_path(srcDir + "/Queries/w3c_update_testsuite/TestSources/uri.txt");
        smapper.reset(new zorba::TestSchemaURIMapper( uri_map_file.c_str() ));
        lContext->registerURIMapper( smapper.get() );

        zorba::Item lEnable = engine->getItemFactory()->
        createQName("http://zorba.io/options/features", "", "enable");

        zorba::Item lDisable = engine->getItemFactory()->
        createQName("http://zorba.io/options/features", "", "disable");

        lContext->declareOption(lDisable, "scripting");
#if 1
        if (path.find("Val") != std::string::npos)
          lContext->setBoundarySpacePolicy(zorba::preserve_space);
#endif
#if 1
        zorba::String lProlog = zorba::String(std::string("import schema 'http://www.w3.org/XML/1998/namespace';\n"));
  
        lContext->loadProlog(lProlog, getCompilerHints());
#endif
      }
      
      lQuery = engine->createQuery();
      lQuery->setFileName (lQueryFile.c_str());
      lQuery->compile(lQueryStream, lContext, getCompilerHints());

#ifdef ZORBA_TEST_PLAN_SERIALIZATION
      int save_retval;
      if((save_retval = save_load_plan(engine, lQuery, smapper.get(), lResultFile)))
      {
        return save_retval;
      }
#endif
    }
    catch (zorba::ZorbaException &e) 
    {
      if (isErrorExpected(e, lState)) 
      {
        std::cout << "Expected compiler error:\n" << e << std::endl;
        std::cout << "updtestdriver: success" << std::endl;
        return 0;
      }
      else 
      {
        std::cout << "Unexpected compiler error:\n" << e << std::endl;
        return 3;
      }
    }

    //
    //
    //    
    try
    {
      zorba::DynamicContext* lDynCtx = lQuery->getDynamicContext();
      if (lState->hasDate) 
      {
        std::string lDateTime = lState->theDate; 
        if (lDateTime.find("T") == std::string::npos) {
          lDateTime += "T00:00:00";
        }
        lDynCtx->setCurrentDateTime(engine->getItemFactory()->createDateTime(lDateTime));
      }
      
      std::vector<Variable*>::const_iterator lVarIter = lState->varsBegin();
      std::vector<Variable*>::const_iterator lVarEnd = lState->varsEnd();
    
      for(; lVarIter != lVarEnd; ++lVarIter) 
      {
        Variable* lVar = *lVarIter;  
        set_var(
            lVar->theInline,
            lVar->theName,
            lVar->theValue,
            xmlDataMgr.get(),
            lQuery->getStaticContext(),
            lDynCtx);
      }
    }
    catch (zorba::ZorbaException &e) 
    {
      if (isErrorExpected(e, lState)) 
      {
        std::cout << "Expected execution error:\n" << e << std::endl;
        continue;
      }
      else
      {
        std::cout << "Unexpected execution error:\n" << e << std::endl;
        return 6;
      }
    }
    
    //
    //
    //
    try 
    {
      zorba::fs::remove( lResultFile, true );

      std::ofstream lResFileStream(lResultFile.c_str());
      lQuery->execute(lResFileStream, &lSerOptions);
      lResFileStream.flush();
        
      if (lState->hasCompare) 
      {
        bool lRes = false;
        bool anyMatch = false;
        ulong numRefs = (ulong)lState->theCompares.size();
        
        for (ulong i = 0; i < numRefs && !lRes; i++) 
        {
          std::string lRefFileTmpString = lRefPath;
          
          // the ref file is the same for xqueryx and xquery tests
          // hence, we remove the string xqueryx or xquery from the path
          size_t lPosOfW3C = lRefPath.find("w3c_update_testsuite");
          if (lPosOfW3C != std::string::npos) 
          {
            if (lRefPath.find("XQueryX", lPosOfW3C) != std::string::npos)
              lRefFileTmpString = lRefFileTmpString.erase(lPosOfW3C + 21, 8);
            else
              lRefFileTmpString = lRefFileTmpString.erase(lPosOfW3C + 21, 7);
          }
          
          std::string lRefFile( lRefFileTmpString );
          zorba::fs::append( lRefFile, lState->theCompares[i] );
          std::cout << std::endl << "Ref " << lRefFile << std::endl;
          
          int lLine, lCol;
          std::string lRefLine, lResultLine;
          lRes = zorba::fileEquals(lRefFile.c_str(),
                                   lResultFile.c_str(),
                                   lLine, lCol, lRefLine, lResultLine);
          
          // if the simple comparison doesn't work, we do the full-fledged
          // xml canonical comparison
          if (lRes) 
          {
            std::cout << std::endl;
            std::cout << "updtestdriver: success (non-canonical result matches)"
                      << std::endl;
            anyMatch = true;
            break;
          } 
          else 
          {
            std::cout << std::endl;
            std::cout << "Actual and Reference results are not identical"
                      << std::endl << std::endl
                      << "Actual Result " << lResultFile << ": "
                      << std::endl << std::endl;
            
            zorba::printFile(std::cout, lResultFile);
            
            std::cout << std::endl << "Reference Result " << lRefFile << ": "
                      << std::endl << std::endl;
            
            zorba::printFile(std::cout, lRefFile);
            
            std::cout << std::endl << std::endl;
            
            int lCanonicalRes =
            zorba::canonicalizeAndCompare(State::compareTypeStr(lState->theCompareTypes[i]),
                                          lRefFile.c_str(),
                                          lResultFile.c_str());
            if (lCanonicalRes == 0) 
            {
              anyMatch = true;
              break;
            }
          }
        } // multiple compare possible
        
        if (!anyMatch) 
        {
          return 4;
        } 
      }
      else if (lState->hasErrors && curQuery == numQueries-1) 
      {
        std::cout << std::endl;
        std::cout << "Query must throw an error!" << std::endl;
        return 5; 
      }
      else 
      {
        std::cout << std::endl;
        std::cout << "Query returns result but no expected result defined!"
                  << std::endl;
        zorba::printFile(std::cout, lResultFile);
      }
    }
    catch (zorba::ZorbaException &e) 
    {
      if (isErrorExpected(e, lState))
      {
        std::cout << std::endl;
        std::cout << "Expected execution error:\n" << e << std::endl;
        continue;
      }
      else
      {
        std::cout << std::endl;
        std::cout << "Unexpected execution error:\n" << e << std::endl;
        return 6;
      }
    }
  } // for each query described in the spec file
  
  std::cout << std::endl;
  std::cout << "updtestdriver: success" << std::endl;
  return 0;
}
/* vim:set et sw=2 ts=2: */
