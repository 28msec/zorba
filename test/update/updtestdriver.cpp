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
#include <zorba/error_handler.h>
#include <zorba/exception.h>
#include <zorba/zorbastring.h>
#include <zorba/util/file.h>

#include <zorbautils/strutil.h>

#include <simplestore/simplestore.h>

#include "util/properties.h"
#include "testdriver_comparator.h"

bool isErrorExpected(zorba::ZorbaException& e, State* aState) {
  if ( aState->hasErrors) {
    std::vector<std::string>::const_iterator lIter = aState->theErrors.begin();
    std::vector<std::string>::const_iterator lEnd  = aState->theErrors.end();
    zorba::String lError = zorba::ZorbaException::getErrorCodeAsString(e.getErrorCode());
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

Zorba_CompilerHints
getCompilerHints()
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
set_var (bool inlineFile, std::string name, std::string val, zorba::DynamicContext* dctx)
{
  zorba::str_replace_all(val, "$UPDATE_SRC_DIR", zorba::UPDATE_SRC_DIR);

  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance(NULL)->getItemFactory();

  if (!inlineFile) {
    zorba::Item lItem = lFactory->createString(val);
		if(name != ".")
			dctx->setVariable (name, lItem);
		else
			dctx->setContextItem (lItem);
  } else {
    std::ifstream* is = new std::ifstream(val.c_str ());
    
    if ( *is==NULL )
        std::cout << "Error: Location not found: " << val.c_str() << std::endl;
    
    assert (*is);
	if(name != ".")
		dctx->setVariableAsDocument (name, val.c_str(), std::auto_ptr<std::istream>(is));
	else
		dctx->setContextItemAsDocument (val.c_str(), std::auto_ptr<std::istream>(is));
  }
}

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

  zorba::Properties::load (NULL, NULL);

  zorba::Zorba* engine = zorba::Zorba::getInstance(zorba::simplestore::SimpleStoreManager::getStore());

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

  int lRun = 0;
  std::vector<State*>::const_iterator lIter = lSpec.statesBegin();
  std::vector<State*>::const_iterator lEnd = lSpec.statesEnd();

  std::vector<zorba::XQuery_t> lQueries;

  for(; lIter != lEnd; ++lIter)
  {
    State* lState = *lIter;

    std::string   qname_str;
    if(lSpecPath.get_path().find("XQueryX") == std::string::npos)
      qname_str = (*lIter)->theName + ".xq";
    else
      qname_str = (*lIter)->theName + ".xqx";
    std::cout << "qname_str " << qname_str << std::endl;

    zorba::filesystem_path lQueryName(qname_str,
                                      zorba::file::CONVERT_SLASHES);
    zorba::filesystem_path lQueryFile(lSpecPath, lQueryName);

    std::cout << std::endl << "Query (Run " << ++lRun << "):" << std::endl;
    std::cout << "Query file " << lQueryFile << ": " << std::endl;
    zorba::printFile(std::cout, lQueryFile);
    std::cout << std::endl;
    std::ifstream lQueryStream(lQueryFile.c_str());

    try 
    {
      zorba::StaticContext_t lContext = engine->createStaticContext();
      std::string path = lQueryFile.get_path();

      std::auto_ptr<zorba::TestSchemaURIResolver> resolver;
      if ( path.find ( "w3c_update_testsuite" ) != std::string::npos ) 
      {
        std::string uri_map_file = srcDir + "/Queries/w3c_update_testsuite/TestSources/uri.txt";
        resolver.reset(new zorba::TestSchemaURIResolver ( uri_map_file.c_str() ));
        lContext->setSchemaURIResolver ( resolver.get() );

        if (path.find("ValSkip") != std::string::npos ||
            path.find("ValLax") != std::string::npos) 
          lContext->setBoundarySpacePolicy(preserve_space);

      	zorba::String lProlog = zorba::String(
	  std::string("import schema 'http://www.w3.org/XML/1998/namespace';\n"));
	
	lContext->loadProlog(lProlog, getCompilerHints());
      }
      
      zorba::XQuery_t lQuery = engine->createQuery();
      lQuery->setFileName (lQueryFile.c_str());
      lQuery->compile(lQueryStream, lContext, getCompilerHints());
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
      
      std::vector<Variable*>::const_iterator lVarIter = (*lIter)->varsBegin();
      std::vector<Variable*>::const_iterator lVarEnd = (*lIter)->varsEnd();
    
      for(; lVarIter != lVarEnd; ++lVarIter) 
      {
        Variable* lVar = *lVarIter;  
        set_var(lVar->theInline, lVar->theName, lVar->theValue, lDynCtx);
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
      if (lQueries.back()->isUpdateQuery()) 
      {
        zorba::XQuery_t query = lQueries.back();
        query->applyUpdates();
          
        std::cout << "Updating Query -> no Result" << std::endl;
      }
      else 
      {
        if ( lResultFile.exists ()) 
          lResultFile.remove();

        std::ofstream lResFileStream(lResultFile.get_path().c_str());
        lQueries.back()->serialize(lResFileStream, &lSerOptions);
        lResFileStream.flush();
        
        if (lState->hasCompare) 
        {
          bool lRes = false;
          bool anyMatch = false;
          ulong numRefs = lState->theCompares.size();
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

            int lLine, lCol, lPos;
            std::string lRefLine, lResultLine;
            lRes = zorba::fileEquals(lRefFile.get_path().c_str(),
                                     lResultFile.get_path().c_str(),
                                     lLine, lCol, lPos, lRefLine, lResultLine);
            
            // if the simple comparison doesn't work, we do the full-fledged
            // xml canonical comparison
            if (lRes) 
            {
              std::cout << "updtestdriver: success (non-canonical result matches)"
                        << std::endl;
              anyMatch = true;
              break;
            } 
            else 
            {
              std::cout << "Actual and Reference results are not identical"
                        << std::endl << std::endl
                        << "Actual Result " << lResultFile.get_path() << ": "
                        << std::endl << std::endl;

              zorba::printFile(std::cout, lResultFile.get_path());

              std::cout << "Reference Result " << lRefFile.get_path() << ": "
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
        else if (lState->hasErrors) 
        {
          std::cout << "Query must throw an error!" << std::endl;
          return 5; 
        }
        else 
        {
          std::cout << "Query returns result but no expected result defined!"
                    << std::endl;
        }
      } // if non-updating query
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
  } // for each query described in the spec file
  
  std::cout << "updtestdriver: success" << std::endl;
  return 0;
}
