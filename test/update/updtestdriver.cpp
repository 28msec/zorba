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

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
#include "common/common.h"

#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>

#include <zorba/util/file.h>

#include <zorbautils/strutil.h>

#include <simplestore/simplestore.h>


void
printFile(std::ostream& os, std::string aInFile, std::string message)
{
  std::cout << message << " " << aInFile << ":" << std::endl;
  std::ifstream lInFileStream(aInFile.c_str());
  if (!lInFileStream) {
    std::cout << "Error: could not open " << aInFile << std::endl;
    assert(false);
  }

  os << lInFileStream.rdbuf() << std::endl;
}

// print parts of a file
// starting at aStartPos with the length of aLen
void
printPart(std::ostream& os, std::string aInFile, 
          int aStartPos, int aLen)
{
  char* buffer = new char [aLen];
  try {
    std::ifstream lIn(aInFile.c_str());
    lIn.seekg(aStartPos);

    int lCharsRead = lIn.readsome (buffer, aLen);
    os.write (buffer, lCharsRead);
    os.flush();
    delete[] buffer;
  } catch (...)
  {
    delete[] buffer;
  }
  return;
}

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
    assert (*is);
		if(name != ".")
			dctx->setVariableAsDocument (name, val.c_str(), std::auto_ptr<std::istream>(is));
		else
			dctx->setContextItemAsDocument (val.c_str(), std::auto_ptr<std::istream>(is));
  }
}

// return false if the files are not equal
// aLine contains the line number in which the first difference occurs
// aCol contains the column number in which the first difference occurs
// aPos is the character number off the first difference in the file
// -1 is returned for aLine, aCol, and aPos if the files are equal
bool
isEqual(zorba::file aRefFile, zorba::file aResFile, int& aLine, int& aCol, int& aPos)
{
  std::ifstream li(aRefFile.get_path().c_str());
  std::ifstream ri(aResFile.get_path().c_str()); 
  
  std::string lLine, rLine;

  aLine = 1; aCol = 0; aPos = -1;
  while (! li.eof() )
  {
    if ( ri.eof() ) {
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

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  Specification lSpec;
  int flags = zorba::file::CONVERT_SLASHES | zorba::file::RESOLVE;

  if (argc != 2)
  {
    std::cout << "\nusage:   testdriver [testfile]" << std::endl;
    return 1;
  }

  std::string lSpecFileString  = zorba::UPDATE_SRC_DIR +"/Queries/" + argv[1];
  zorba::file lSpecFile (lSpecFileString, flags);
  zorba::filesystem_path lSpecPath (lSpecFile.branch_path());
  
  std::string lSpecWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-5 );
  std::cout << "test " << lSpecWithoutSuffix << std::endl;
  
  zorba::file lResultFile (zorba::UPDATE_BINARY_DIR +"/QueryResults/" 
                           + lSpecWithoutSuffix + ".res", flags);
  
  zorba::file lRefFile (zorba::UPDATE_SRC_DIR +"/ExpectedTestResults/" 
                        + lSpecWithoutSuffix +".xml.res", flags);
  zorba::filesystem_path lRefPath (lRefFile.branch_path());

  if ( (! lSpecFile.exists ()) || lSpecFile.is_directory () ) {
    std::cout << "\n spec file " << lSpecFile.get_path() 
              << " does not exist or is not a file" << std::endl;
    return 2;
  }

  if ( ! lResultFile.exists () )
    lResultFile.deep_mkdir ();

  // read the xargs and errors if the spec file exists
  lSpec.parseFile(lSpecFile.get_path()); 

  zorba::Zorba* engine = zorba::Zorba::getInstance(zorba::simplestore::SimpleStoreManager::getStore());

  std::vector<zorba::XQuery_t> lQueries;
  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;


  // create and compile the query
  {
    std::vector<State*>::const_iterator lIter = lSpec.statesBegin();
    std::vector<State*>::const_iterator lEnd = lSpec.statesEnd();

    int lRun = 0;

    for(;lIter!=lEnd;++lIter)
    {
      State* lState = *lIter;

      zorba::filesystem_path lQueryFile
        (lSpecPath, zorba::filesystem_path ((*lIter)->theName + ".xq",
                                            zorba::file::CONVERT_SLASHES));
      std::cout << std::endl << "Query (Run " << ++lRun << "):" << std::endl;
      printFile(std::cout, lQueryFile, "Query file");
      std::cout << std::endl;
      std::ifstream lQueryStream(lQueryFile.c_str());

      try {
        lQueries.push_back(engine->compileQuery(lQueryStream, getCompilerHints()));
      }
      catch (zorba::ZorbaException &e) {
        if (isErrorExpected(e, lState)) {
          std::cout << "Expected compiler error " << e << " caught " << std::endl;
          return 0;
        } else {
          std::cout << e << std::endl;
          return 3;
        }
      }

      zorba::DynamicContext* lDynCtx = lQueries.back()->getDynamicContext();
      if (lState->hasDate) {
        std::string lDateTime = lState->theDate; 
        if (lDateTime.find("T") == std::string::npos) {
          lDateTime += "T00:00:00";
        }
        lDynCtx->setCurrentDateTime(engine->getItemFactory()->createDateTime(lDateTime));
      }

      std::vector<Variable*>::const_iterator lVarIter = (*lIter)->varsBegin();
      std::vector<Variable*>::const_iterator lVarEnd = (*lIter)->varsEnd();

      for(;lVarIter!=lVarEnd;++lVarIter) {
        Variable* lVar = *lVarIter;  
        set_var(lVar->theInline, lVar->theName, lVar->theValue, lDynCtx);
      }

      try 
      {
        if (lQueries.back()->isUpdateQuery()) {
          lQueries.back()->applyUpdates();
          std::cout << "Updating Query -> no Result" << std::endl;
        } else {
          if ( lResultFile.exists ()) { lResultFile.remove (); }
          std::ofstream lResFileStream(lResultFile.get_path().c_str());
          lQueries.back()->serialize(lResFileStream, lSerOptions);
          lResFileStream.flush();
          printFile(std::cout, lResultFile.get_path(), "Result ");

          if (lState->hasCompare) {
            bool lRes = false;
            ulong numRefs = lState->theCompares.size();
            for (ulong i = 0; i < numRefs && !lRes; i++) {
              zorba::filesystem_path lRefFile
                (lRefPath, zorba::filesystem_path (lState->theCompares[i],
                                                   zorba::file::CONVERT_SLASHES));
              int lLine, lCol, lPos;
              lRes = isEqual(lRefFile, lResultFile, lLine, lCol, lPos);

              if (!lRes) {
                printFile(std::cout, lRefFile.get_path(), "Result does not match expected result");
                std::cout << std::endl;

                std::cout << "See line " << lLine << ", col " << lCol
                          << " of expected result. " << std::endl;
                std::cout << "Got: " << std::endl; 
                printPart(std::cout, lResultFile.get_path(), lPos, 15);
                std::cout << std::endl << "Expected ";
                printPart(std::cout, lRefFile.get_path(), lPos, 15);
                std::cout <<  std::endl;
              }
            }

            if (!lRes) {
              std::cout << std::endl << "Result does not match any of the expected results"
                        << std::endl;
              return 4;
            }
          } else if (lState->hasErrors) {
            std::cout << "Query must throw an error!" << std::endl;
            return 5; 
          }
          else {
            std::cout << "Query returns result but no expected result defined!" << std::endl;
          }
        }
      } catch (zorba::ZorbaException &e) {
        if (isErrorExpected(e, lState)) {
          std::cout << "Expected execution error " << e << " caught " << std::endl;
          continue;
        } else {
          std::cout << e << std::endl;
          return 6;
        }
      }
    }


  }

  std::cout << "updtestdriver: success" << std::endl;
  return 0;
}
