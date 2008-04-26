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
#include "common/common.h"
#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>

namespace fs = boost::filesystem;

void
printFile(std::ostream& os, std::string aInFile)
{
  std::ifstream lInFileStream(aInFile.c_str());
  assert(lInFileStream);

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
    zorba::String lError = zorba::ZorbaError::getErrorCode(e.getErrorCode());
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

zorba::XQuery::CompilerHints
getCompilerHints()
{
  zorba::XQuery::CompilerHints lHints;

  // ZORBA_OPTLEVEL=O0 | O1
  char* lOptLevel = getenv("ZORBA_OPTLEVEL");
  if ( lOptLevel != NULL && strcmp(lOptLevel, "O0") == 0 ) {
    lHints.opt_level = zorba::XQuery::CompilerHints::O0;
    std::cout << "testdriver is using optimization level O0" << std::endl;
  } else {
    lHints.opt_level = zorba::XQuery::CompilerHints::O1;
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
  boost::replace_all(val, "$UPDATE_SRC_DIR", zorba::UPDATE_SRC_DIR);

  zorba::ItemFactory* lFactory = zorba::Zorba::getInstance()->getItemFactory();

  if (!inlineFile) {
    zorba::Item lItem = lFactory->createString(val);
		if(name != ".")
			dctx->setVariable (name, lItem);
		else
			dctx->setContextItem (lItem);
  } else {
    std::ifstream is (val.c_str ());
    assert (is);
		if(name != ".")
			dctx->setVariableAsDocument (name, val.c_str(), is);
		else
			dctx->setContextItemAsDocument (val.c_str(), is);
  }
}

// return false if the files are not equal
// aLine contains the line number in which the first difference occurs
// aCol contains the column number in which the first difference occurs
// aPos is the character number off the first difference in the file
// -1 is returned for aLine, aCol, and aPos if the files are equal
bool
isEqual(fs::path aRefFile, fs::path aResFile, int& aLine, int& aCol, int& aPos)
{
  std::ifstream li(aRefFile.native_file_string().c_str());
  std::ifstream ri(aResFile.native_file_string().c_str()); 
  
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
  fs::path lSpecFile, lResultFile;
  fs::path lSpecPath, lRefPath, lResultPath;
  Specification lSpec;

  if (argc != 2)
  {
    std::cerr << "\nusage:   testdriver [testfile]" << std::endl;
    return 1;
  }

  // do initial stuff
  {
    std::string lSpecFileString  = zorba::UPDATE_SRC_DIR +"/Queries/" + argv[1];
    lSpecFile = fs::system_complete( fs::path( lSpecFileString, fs::native ) );
    lSpecPath = fs::system_complete(fs::path(lSpecFile.branch_path().string(), fs::native ));

    std::string lSpecWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-5 );
    std::cout << "test " << lSpecWithoutSuffix << std::endl;

    lResultFile = fs::system_complete(fs::path( zorba::UPDATE_BINARY_DIR +"/QueryResults/" 
                                      +lSpecWithoutSuffix + ".res", fs::native) );
    lResultPath = fs::system_complete(fs::path(lResultFile.branch_path().string(), fs::native ));

    fs::path lRefFile = fs::system_complete(fs::path( zorba::UPDATE_SRC_DIR +"/ExpectedTestResults/" 
                                     +lSpecWithoutSuffix +".xml.res", fs::native) );
    lRefPath = fs::system_complete(fs::path(lRefFile.branch_path().string(), fs::native ));
  }


  // does the spec file exists
  if ( (! fs::exists( lSpecFile )) || fs::is_directory( lSpecFile) ) {
    std::cerr << "\n spec file " << lSpecFile.native_file_string() 
              << " does not exist or is not a file" << std::endl;
    return 2;
  }

  // create the result directory
  if ( ! fs::exists( lResultPath ) )
    fs::create_directories(lResultPath); // create deep directories

  // read the xargs and errors if the spec file exists
  lSpec.parseFile(lSpecFile.native_file_string()); 

  zorba::Zorba *engine = zorba::Zorba::getInstance();

  std::vector<zorba::XQuery_t> lQueries;
  zorba::XQuery::SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = zorba::XQuery::SerializerOptions::omit_xml_declaration::YES;


  // create and compile the query
  {
    std::vector<State*>::const_iterator lIter = lSpec.statesBegin();
    std::vector<State*>::const_iterator lEnd = lSpec.statesEnd();

    int lRun = 0;

    for(;lIter!=lEnd;++lIter)
    {
      State* lState = *lIter;     

      std::string lQueryFile = lSpecPath.native_file_string() + "/" + (*lIter)->theName + ".xq";
      std::cout << std::endl << "Query (Run " << ++lRun << "):" << std::endl;
      printFile(std::cout, lQueryFile);
      std::cout << std::endl;
      std::ifstream lQueryStream(lQueryFile.c_str());

      try 
      {
        lQueries.push_back(engine->compileQuery(lQueryStream, getCompilerHints()));
      }
      catch (zorba::ZorbaException &e)
      {
        if (isErrorExpected(e, lState)) {
          return 0;
        } else {
          std::cerr << e << std::endl;
          return 3;
        }
      }

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

      for(;lVarIter!=lVarEnd;++lVarIter)
      {
        Variable* lVar = *lVarIter;  
        set_var(lVar->theInline, lVar->theName, lVar->theValue, lDynCtx);
      }

      try 
      {
        if (lQueries.back()->isUpdateQuery()) 
        {
          lQueries.back()->applyUpdates();
          std::cout << "Updating Query -> no Result" << std::endl;
        }
        else
        {
          if ( fs::exists(lResultFile)) { fs::remove (lResultFile); }
          std::ofstream lResFileStream(lResultFile.native_file_string().c_str());
          lQueries.back()->serialize(lResFileStream, lSerOptions);
          lResFileStream.flush();
          std::cout << "Result:" << std::endl;
          printFile(std::cout, lResultFile.native_file_string());

          if (lState->hasCompare)
          {
            bool lRes = false;
            ulong numRefs = lState->theCompares.size();
            for (ulong i = 0; i < numRefs && !lRes; i++)
            {
              fs::path lRefFile = fs::system_complete(fs::path(lRefPath.native_file_string() + "/" 
                                   + lState->theCompares[i], fs::native) );
              int lLine, lCol, lPos;
              lRes = isEqual(lRefFile, lResultFile, lLine, lCol, lPos);

              if (!lRes) 
              {
                std::cerr << std::endl << "Result does not match expected result : "
                          << std::endl;

                printFile(std::cerr, lRefFile.native_file_string());
                std::cerr << std::endl;

                std::cerr << "See line " << lLine << ", col " << lCol
                          << " of expected result. " << std::endl;
                std::cerr << "Got: " << std::endl; 
                printPart(std::cerr, lResultFile.native_file_string(), lPos, 15);
                std::cerr << std::endl << "Expected ";
                printPart(std::cerr, lRefFile.native_file_string(), lPos, 15);
                std::cerr <<  std::endl;
              }
            }

            if (!lRes) 
            {
              std::cerr << std::endl << "Result does not match any of the expected results"
                        << std::endl;
              return 4;
            }
          }
          else if (lState->hasErrors)
          {
            std::cerr << "Query must throw an error!" << std::endl;
            return 5; 
          }
          else
          {
            std::cerr << "Query returns result but no expected result defined!" << std::endl;
          }
        }
      }
      catch (zorba::ZorbaException &e)
      {
        if (isErrorExpected(e, lState)) {
          return 0;
        } else {
          std::cerr << e << std::endl;
          return 6;
        }
      }
    }


  }

  return 0;
}
