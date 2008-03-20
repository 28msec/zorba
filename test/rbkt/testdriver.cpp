#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/convenience.hpp>
#include <boost/algorithm/string.hpp>

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files
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

class TestErrorHandler : public zorba::ErrorHandler {
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

    bool errors()
    {
      return !m_errors.empty();
    }

    const std::vector<std::string>& getErrorList()
    {
      return m_errors;
    }

  private:
    std::vector<std::string> m_errors;

    void registerError(const zorba::ZorbaException& e)
    {
      m_errors.push_back(zorba::ZorbaError::getErrorCode(e.getErrorCode()).c_str());
    }
};

// check of an error that was repored was expected 
// by the given specification object
bool
isErrorExpected(TestErrorHandler& errHandler, Specification* aSpec)
{
  const std::vector<std::string>& errors = errHandler.getErrorList();
  for(std::vector<std::string>::const_iterator i = errors.begin(); i != errors.end(); ++i) {
    for(std::vector<std::string>::const_iterator j = aSpec->errorsBegin(); j != aSpec->errorsEnd(); ++j) {
      if (i->compare(*j) == 0) {
        return true;
      }
    }
  }
  return false;
}

// print all errors that were raised
void
printErrors(TestErrorHandler& errHandler)
{
  if (!errHandler.errors()) {
    return;
  }
  std::cerr << "Errors:" << std::endl;
  
  const std::vector<std::string>& errors = errHandler.getErrorList();

  for(std::vector<std::string>::const_iterator i = errors.begin(); i != errors.end(); ++i) {
    std::cerr << *i << std::endl;
  }
  return;
}

// set a variable in the dynamic context
// inlineFile specifies whether the given parameter is a file and it's value should
// be inlined or not
void
set_var (bool inlineFile, std::string name, std::string val, zorba::DynamicContext_t dctx)
{
  boost::replace_all(val, "$RBKT_SRC_DIR", zorba::RBKT_SRC_DIR);

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

void 
set_vars (Specification* aSpec, zorba::DynamicContext_t dctx) 
{
  for (std::vector<Specification::Variable>::const_iterator lIter = aSpec->variablesBegin();
       lIter != aSpec->variablesEnd(); ++lIter)
  {
    set_var ((*lIter).theInline, (*lIter).theVarName, (*lIter).theVarValue, dctx);
  }
}


void
trim(std::string& str) {

  std::string::size_type  notwhite = str.find_first_not_of(" \t\n");
  str.erase(0,notwhite);

  notwhite = str.find_last_not_of(" \t\n"); 
  str.erase(notwhite+1); 
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

void 
slurp_file (const char *fname, std::string &result) {
  std::ifstream qfile(fname, std::ios::binary | std::ios_base::in); assert (qfile);

  qfile.seekg (0, std::ios::end);
  size_t len = qfile.tellg ();
  qfile.seekg (0, std::ios::beg);
  char *str = new char [len];
  qfile.read (str, len);
  len = qfile.gcount();
  
  std::string sstr (str, len);
  result.swap (sstr);
  delete [] str;
}

int
#ifdef _WIN32_WCE
_tmain(int argc, _TCHAR* argv[])
#else
main(int argc, char** argv)
#endif
{
  fs::path lQueryFile, lResultFile, lErrorFile, lRefFile, lSpecFile;
  Specification lSpec;

  // do initial stuff
  if ( argc == 2 )
  {
    std::string lQueryFileString  = zorba::RBKT_SRC_DIR +"/Queries/" + argv[1];
    lQueryFile = fs::system_complete( fs::path( lQueryFileString, fs::native ) );

    std::string lQueryWithoutSuffix = std::string(argv[1]).substr( 0, std::string(argv[1]).size()-3 );
    std::cout << "test " << lQueryWithoutSuffix << std::endl;
    lResultFile = fs::system_complete(fs::path( zorba::RBKT_BINARY_DIR +"/QueryResults/" 
                                      +lQueryWithoutSuffix + ".res", fs::native) );
    lErrorFile = fs::system_complete(fs::path(zorba::RBKT_BINARY_DIR +"/" 
                                     +lQueryWithoutSuffix + ".err", fs::native) );
    lRefFile   = fs::system_complete(fs::path( zorba::RBKT_SRC_DIR +"/ExpQueryResults/" 
                                     +lQueryWithoutSuffix +".xml.res", fs::native) );
    lSpecFile  = fs::system_complete(fs::path(zorba::RBKT_SRC_DIR+ "/Queries/" 
                                     +lQueryWithoutSuffix +".spec", fs::native) );
  }
  else
  {
    std::cerr << "\nusage:   testdriver [testfile]" << std::endl;
    return 1;
  }

  // does the query file exists
  if ( (! fs::exists( lQueryFile )) || fs::is_directory( lQueryFile) ) {
    std::cerr << "\n query file " << lQueryFile.native_file_string() 
              << " does not exist or is not a file" << std::endl;
    return 2;
  }

  // delete previous files if they exists
  if ( fs::exists ( lResultFile ) ) { fs::remove (lResultFile); }
  if ( fs::exists ( lErrorFile ) )  { fs::remove (lErrorFile);  }

  // create the result directory
  fs::path lBucket = fs::system_complete(fs::path( lResultFile.branch_path().string(), fs::native ));
  if ( ! fs::exists( lBucket ) )
    fs::create_directories(lBucket); // create deep directories

  // read the xargs and errors if the spec file exists
  if ( fs::exists( lSpecFile )) 
  { 
    lSpec.parseFile(lSpecFile.native_file_string()); 
  }

  // we must either have a reference file or an expected error code
  if ( (lSpec.errorsSize() == 0) && ((! fs::exists( lRefFile )) || fs::is_directory( lRefFile)))
  {
    std::cerr << "No reference result and no expected errors." << std::endl;
    return 3;
  }

  // print the query
  std::cout << "Query:" << std::endl;
  printFile(std::cout, lQueryFile.native_file_string());
  std::cout << std::endl;

  zorba::Zorba *engine = zorba::Zorba::getInstance();

  TestErrorHandler errHandler;

  // create and compile the query
  std::string lQueryString;
  slurp_file(lQueryFile.native_file_string().c_str(), lQueryString);
  zorba::XQuery_t lQuery = engine->createQuery(lQueryString.c_str(), &errHandler);

  if (errHandler.errors())
  {
    if (isErrorExpected(errHandler, &lSpec)) 
    { 
      // done, we expected an error during compile
      return 0; 
    } 
    else 
    { 
      std::cerr << "Error compiling query" << std::endl;
      printErrors(errHandler); return 4;
    }
  }


  // set the variables in the dynamic context
  zorba::DynamicContext_t lDynCtxt = lQuery->getDynamicContext();
  set_vars(&lSpec, lDynCtxt);

  {
    // serialize xml
    std::ofstream lResFileStream(lResultFile.native_file_string().c_str());
    assert (lResFileStream.good());

    lResFileStream << lQuery;

    if (errHandler.errors())
    {
      if (isErrorExpected(errHandler, &lSpec)) { return 0; } // again done, we expected this error
      else 
      { 
        std::cerr << "Error executing query" << std::endl;
        printErrors(errHandler); 
        return 6;
      }
    }
    else if ( lSpec.errorsSize() > 0 )
    {
      if ( ! fs::exists(lRefFile) )
      {
        std::cerr << "Expected error(s)";
        for (std::vector<std::string>::const_iterator lIter = lSpec.errorsBegin();
            lIter != lSpec.errorsEnd(); ++lIter)
        {
          std::cerr << " " << *lIter;
        }
        if ( fs::exists(lResultFile) && fs::file_size(lResultFile) == 0)
          std::cerr << " but got empty result" << std::endl;
        else
        {
          std::cerr << " but got result:" << std::endl;
          printFile(std::cerr, lResultFile.native_file_string());
          std::cerr<< std::endl;
        } 
        return 7;
      }
    }
  }
  std::cout << "Result:" << std::endl;
  printFile(std::cout, lResultFile.native_file_string());
  std::cout.flush();
  std::cout << std::endl;


  // last, we have to diff the result
  int lLine, lCol, lPos; // where do the files differ
  bool lRes = isEqual(lRefFile, lResultFile, lLine, lCol, lPos);
  if ( !lRes )  // results differ
  {
    std::cerr << std::endl << "Result does not match expected result" << std::endl;
    printFile(std::cerr, lRefFile.native_file_string());
    std::cerr << std::endl;

    std::cerr << "See line " << lLine << ", col " << lCol << " of expected result. " << std::endl;
    std::cerr << "Got "; 
    printFile(std::cerr, lRefFile.native_file_string());
    printPart(std::cerr, lResultFile.native_file_string(), lPos, 15);
    std::cerr << std::endl << "Expected ";
    printPart(std::cerr, lRefFile.native_file_string(), lPos, 15);
    std::cerr <<  std::endl;

    return 8;
  }


  return 0;
}
