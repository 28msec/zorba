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
#include <stdio.h>
#include <stdlib.h>
#include <cstring>

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "testuriresolver.h"
#include "specification.h" // parsing spec files
#include "common/common.h"

#include <zorba/zorba.h>
#include <zorba/diagnostic_handler.h>
#include <zorba/zorba_exception.h>
#include <zorba/zorba_string.h>
#include <zorba/util/file.h>
#include <zorba/static_context_consts.h>
#include <zorba/store_consts.h>

#include "util/ascii_util.h"

#include <zorba/store_manager.h>

#include "system/properties.h"
#include "testdriver_comparator.h"

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
void
set_var (
    bool inlineFile,
    std::string name,
    std::string val,
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
    zorba::XmlDataManager* lXmlMgr =
    zorba::Zorba::getInstance(NULL)->getXmlDataManager();

    zorba::DocumentManager* lDocMgr = lXmlMgr->getDocumentManager();
        
    zorba::Item lDoc;
    if (lDocMgr->isAvailableDocument(name))
    {
      lDoc = lDocMgr->document(name);
    }
    else
    {
      lDoc = lXmlMgr->parseXML(is);
      sctx->validate(lDoc, lDoc, zorba::validate_lax);
      lDocMgr->add(name, lDoc);
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
int save_load_plan(zorba::Zorba* engine, zorba::XQuery_t &lQuery, zorba::URIMapper* smapper, std::string lQueryFileString)
{
  try
  {
    clock_t t0, t1;
  std::string binary_path = lQueryFileString;
  binary_path = binary_path.substr( 0, binary_path.rfind('.') );
  binary_path += ".plan";
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

  zorba::Properties::load (0, NULL);

  zorba::Zorba* engine = zorba::Zorba::getInstance(zorba::StoreManager::getStore());

  Specification lSpec;
  int flags = zorba::file::CONVERT_SLASHES | zorba::file::RESOLVE;

  std::string srcDir = zorba::UPDATE_SRC_DIR;
  std::string binDir = zorba::UPDATE_BINARY_DIR;

  std::string argString = std::string(argv[1]);
  std::string lSpecNoSuffix = argString.substr(0, argString.size()-5);

  std::string lSpecFileString  = srcDir + "/Queries/" + argv[1];
  zorba::file lSpecFile(lSpecFileString, flags);
  zorba::filesystem_path lSpecPath(lSpecFile.branch_path());

  if ( (! lSpecFile.exists ()) || lSpecFile.is_directory () ) 
  {
    std::cout << "\n spec file " << lSpecFile.get_path() 
              << " does not exist or is not a file" << std::endl;
    return 2;
  }

  std::cout << "test " << lSpecNoSuffix << std::endl;
  
  std::string lResultFileString = binDir+"/QueryResults/"+lSpecNoSuffix+".res";
  zorba::file lResultFile(lResultFileString, flags);
  if (!lResultFile.exists())
    zorba::file(lResultFile.branch_path()).deep_mkdir();

  std::string lRefFileString = srcDir+"/ExpectedTestResults/"+lSpecNoSuffix+".xml.res";
  zorba::file lRefFile(lRefFileString, flags);
  zorba::filesystem_path lRefPath(lRefFile.branch_path());

  // read the xargs and errors if the spec file exists
  lSpec.parseFile(lSpecFile.get_path()); 

  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  std::auto_ptr<zorba::TestSchemaURIMapper> smapper;

  std::vector<zorba::XQuery_t> lQueries;

  ulong numQueries = (ulong)lSpec.theStates.size();

  for(ulong curQuery = 0; curQuery < numQueries; ++curQuery)
  {
    State* lState = lSpec.theStates[curQuery];

    std::string qname_str;
    if(lSpecPath.get_path().find("XQueryX") == std::string::npos)
      qname_str = lState->theName + ".xq";
    else
      qname_str = lState->theName + ".xqx";

    std::cout << "qname_str " << qname_str << std::endl;

    zorba::filesystem_path lQueryName(qname_str,
                                      zorba::file::CONVERT_SLASHES);
    zorba::filesystem_path lQueryFile(lSpecPath, lQueryName);

    std::cout << std::endl << "Query (Run " << curQuery+1 << "):" << std::endl;
    std::cout << "Query file " << lQueryFile << ": " << std::endl;
    zorba::printFile(std::cout, lQueryFile);
    std::cout << std::endl;
    std::ifstream lQueryStream(lQueryFile.c_str());

    try 
    {
      zorba::StaticContext_t lContext = engine->createStaticContext();
      std::string path = lQueryFile.get_path();

      if (path.find("w3c_update_testsuite") != std::string::npos) 
      {
        lContext->setXQueryVersion(zorba::xquery_version_1_0);

        std::string uri_map_file = srcDir + "/Queries/w3c_update_testsuite/TestSources/uri.txt";
        smapper.reset(new zorba::TestSchemaURIMapper( uri_map_file.c_str() ));
        lContext->registerURIMapper( smapper.get() );

        zorba::Item lEnable
          = engine->getItemFactory()->createQName(
              "http://www.zorba-xquery.com/options", "", "enable-feature");
        zorba::Item lDisable
          = engine->getItemFactory()->createQName(
              "http://www.zorba-xquery.com/options", "", "disable-feature");
        lContext->declareOption(lEnable, "hof");
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
      
      zorba::XQuery_t lQuery = engine->createQuery();
      lQuery->setFileName (lQueryFile.c_str());
      lQuery->compile(lQueryStream, lContext, getCompilerHints());

#ifdef ZORBA_TEST_PLAN_SERIALIZATION
      int save_retval;
      if((save_retval = save_load_plan(engine, lQuery, smapper.get(), lResultFile.get_path())))
      {
        return save_retval;
      }
#endif

      lQueries.push_back(lQuery);
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
    

    try
    {
      zorba::DynamicContext* lDynCtx = lQueries.back()->getDynamicContext();
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
            lQueries.back()->getStaticContext(),
            lDynCtx);
      }
    }
    catch (zorba::ZorbaException &e) 
    {
      if (isErrorExpected(e, lState)) {
        std::cout << "Expected execution error:\n" << e << std::endl;
        continue;
      } else {
        std::cout << "Unexpected execution error:\n" << e << std::endl;
        return 6;
      }
    }
    
    try 
    {
      if (lResultFile.exists()) 
        lResultFile.remove();

      std::ofstream lResFileStream(lResultFile.get_path().c_str());
      lQueries.back()->execute(lResFileStream, &lSerOptions);
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
          size_t lPosOfW3C = lRefPath.get_path().find("w3c_update_testsuite");
          if (lPosOfW3C != std::string::npos) 
          {
            if (lRefPath.get_path().find("XQueryX", lPosOfW3C) != std::string::npos)
              lRefFileTmpString = lRefFileTmpString.erase(lPosOfW3C + 21, 8);
            else
              lRefFileTmpString = lRefFileTmpString.erase(lPosOfW3C + 21, 7);
          }
          
          zorba::filesystem_path lRefFile(lRefFileTmpString,
                                          zorba::filesystem_path(lState->theCompares[i],
                                                                 zorba::file::CONVERT_SLASHES));
          std::cout << std::endl << "Ref " << lRefFile.get_path()  << std::endl;
          
          int lLine, lCol;
          std::string lRefLine, lResultLine;
          lRes = zorba::fileEquals(lRefFile.get_path().c_str(),
                                   lResultFile.get_path().c_str(),
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
                      << "Actual Result " << lResultFile.get_path() << ": "
                      << std::endl << std::endl;
            
            zorba::printFile(std::cout, lResultFile.get_path());
            
            std::cout << std::endl << "Reference Result " << lRefFile.get_path() << ": "
                      << std::endl << std::endl;
            
            zorba::printFile(std::cout, lRefFile.get_path());
            
            std::cout << std::endl << std::endl;
            
            int lCanonicalRes =
            zorba::canonicalizeAndCompare(State::compareTypeStr(lState->theCompareTypes[i]),
                                          lRefFile.get_path().c_str(),
                                          lResultFile.get_path().c_str(),
                                          zorba::UPDATE_BINARY_DIR.c_str());
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
