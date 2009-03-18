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

#include "testdriverconfig.h" // SRC and BIN dir definitions
#include "specification.h" // parsing spec files

#include <zorba/zorba.h>
#include <zorba/error_handler.h>
#include <zorba/exception.h>

#include "util/properties.h"

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

void loadProperties () {
  zorba::Properties::load (NULL, NULL);
}

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

  private:
    std::vector<std::string> m_errors;
    std::vector<zorba::String> m_desc;

    void registerError(const zorba::ZorbaException& e)
    {
      m_errors.push_back(zorba::ZorbaException::getErrorCodeAsString(e.getErrorCode()).c_str());
      m_desc.push_back(e.getDescription());
    }
};

// check of an error that was repored was expected 
// by the given specification object
bool
isErrorExpected(const TestErrorHandler& errHandler, const Specification* aSpec)
{
  char star = '*';
  const std::vector<std::string>& errors = errHandler.getErrorList();
  for(std::vector<std::string>::const_iterator i = errors.begin(); i != errors.end(); ++i) {
    for(std::vector<std::string>::const_iterator j = aSpec->errorsBegin(); j != aSpec->errorsEnd(); ++j) {
      if ((i->compare(*j) == 0)
           || (j->compare(&star)) == 0)
        return true;
    }
  }
  return false;
}

// print all errors that were raised
void
printErrors (const TestErrorHandler& errHandler, const char *msg)
{
  if (!errHandler.errors()) {
    return;
  }
  std::cout << msg << ":" << std::endl;
  
  const std::vector<std::string>& errors = errHandler.getErrorList();
  const std::vector<zorba::String>& descs = errHandler.getErrorDescs();

  std::vector<std::string>::const_iterator codeIter = errors.begin();
  std::vector<zorba::String>::const_iterator descIter = descs.begin();

    for(; codeIter != errors.end(); ++codeIter, ++descIter) {
      assert (descIter != descs.end());
      std::cout << *codeIter << ": " << *descIter << std::endl;
  }
  return;
}

int analyzeError (const Specification &lSpec, const TestErrorHandler& errHandler) {
  if (isErrorExpected(errHandler, &lSpec)) {
    printErrors(errHandler, "The following execution error occurred as expected");
    return EXPECTED_ERROR;
  } else {
    printErrors(errHandler, "Unexpected error executing query");
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


/*tries to create a ZorbaItem given a string in the form xs:TYPE(VALUE)*/
zorba::Item
createItem(std::string strValue)
{
  std::cout << strValue << std::endl;
  zorba::ItemFactory* itemfactory = zorba::Zorba::getInstance(NULL)->getItemFactory();
  size_t              pos = strValue.find("xs:");

  if(pos == std::string::npos)
  {
    strValue = zorba::URI::encode_file_URI (strValue)->str ();
    return  itemfactory->createString(strValue);
  }
  else
  {
    pos += 3;
    std::string type = strValue.substr(pos, (strValue.find("(") - pos));
    pos += type.length() + 1;
    std::string val = strValue.substr(pos, (strValue.length() - 1 - pos));
    if(type == "string")
      return itemfactory->createString(val);
    else if(type == "boolean")
      return itemfactory->createBoolean(((val == "true" || val == "1")? true: false));
    else if(type == "decimal")
      return itemfactory->createDecimal(val);
    else if(type == "integer")
      return itemfactory->createInteger(val);
    else if(type == "float")
      return itemfactory->createFloat(val);
    else if(type == "double")
      return itemfactory->createDouble(val);
    else if(type == "duration")
      return itemfactory->createDuration(val);
    else if(type == "dateTime")
      return itemfactory->createDateTime(val);
    else if(type == "time")
      return itemfactory->createTime(val);
    else if(type == "date")
      return itemfactory->createDate(val);
    else if(type == "gYearMonth")
      return itemfactory->createGYearMonth(val);
    else if(type == "gYear")
      return itemfactory->createGYear(val);
    else if(type == "gMonthDay")
      return itemfactory->createGMonthDay(val);
    else if(type == "gDay")
      return itemfactory->createGDay(val);
    else if(type == "gMonth")
      return itemfactory->createGDay(val);
    else if(type == "hexBinary" ||
            type == "base64Binary" ||
            type == "QName" ||
            type == "NOTATION")
    {
      //not supported
      std::cout << "Type {" << type << "} not supported." << std::endl;
      return  NULL; 
    }
    else if(type == "anyURI")
      return itemfactory->createAnyURI(val);
    else
      //only primitive types allowed, see http://www.w3.org/TR/xmlschema-2/#built-in-primitive-datatypes
      std::cout << "Type {" << type << "} is not a primitive data type.\n Derived types not supported." << std::endl;
      return  NULL;
  }
}

// set a variable in the dynamic context
// inlineFile specifies whether the given parameter is a file and its value should
// be inlined or not
void
set_var (bool inlineFile, std::string name, std::string val, zorba::DynamicContext* dctx)
{
  zorba::str_replace_all (val, "$RBKT_SRC_DIR", zorba::RBKT_SRC_DIR);
  if (!inlineFile) {
    zorba::Item lItem = createItem(val);
		if(name != ".")
			dctx->setVariable (name, lItem);
		else
			dctx->setContextItem (lItem);
  } else {
    const char *val_fname = val.c_str ();
    std::ifstream* is = new std::ifstream(val_fname);
    if (! is) {
      std::cout << "Could not open file `" << val_fname << "' for variable `" << name << "'" << std::endl;
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
isEqual(zorba::file aRefFile, zorba::file aResFile, int& aLine, int& aCol, int& aPos,
        std::string& aRefLine, std::string& aResLine)
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
    if ( (aCol = lLine.compare(rLine)) != 0) {
      aRefLine = lLine;
      aResLine = rLine;
      return false;
    }
    ++aLine;
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

  if(sstr.find("$RBKT_SRC_DIR",0) != std::string::npos)
  {
    std::string rbkt_src_uri = zorba::URI::encode_file_URI (zorba::RBKT_SRC_DIR)->str ();
    zorba::str_replace_all(sstr, "$RBKT_SRC_DIR", rbkt_src_uri);
  }

  if(sstr.find("$RBKT_BINARY_DIR",0) != std::string::npos)
  {
    std::string rbkt_binary_uri = zorba::URI::encode_file_URI (zorba::RBKT_BINARY_DIR)->str ();
    zorba::str_replace_all(sstr, "$RBKT_BINARY_DIR", rbkt_binary_uri);
  }

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
  loadProperties ();

  Specification lSpec;
  if ( argc < 2 )
  {
    std::cout << "\nusage:   testdriver [testfile_1] [testfile_2] ..." << std::endl;
    return 1;
  }

  zorba::Zorba *  engine;
  int             errors;

  for( int i=1; i < argc; i++ )
  {
#ifndef ZORBA_XQUERYX
    std::string   Queriesdir = "/Queries/";
#else
    std::string   Queriesdir = "/";//"/XQueryX/";
#endif
    int path_flags = zorba::file::CONVERT_SLASHES | zorba::file::RESOLVE;
    zorba::file lQueryFile (zorba::RBKT_SRC_DIR + Queriesdir + argv[i], path_flags);
    
    std::string lQueryWithoutSuffix = std::string(argv[i]).substr( 0, std::string(argv[i]).rfind('.') );
    std::cout << "test " << lQueryWithoutSuffix << std::endl;

    zorba::file lResultFile (zorba::RBKT_BINARY_DIR + "/QueryResults/" 
                             + lQueryWithoutSuffix + ".res", path_flags);

    zorba::file lErrorFile  (zorba::RBKT_BINARY_DIR + "/" 
                             + lQueryWithoutSuffix + ".err", path_flags);

    zorba::file lRefFile (zorba::RBKT_SRC_DIR + "/ExpQueryResults/" 
                          + lQueryWithoutSuffix +".xml.res", path_flags);

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

    // we must either have a reference file or an expected error code
    if ( (lSpec.errorsSize() == 0) && ((! lRefFile.exists ()) || lRefFile.is_directory ()))
    {
      std::cout << "No reference result and no expected errors." << std::endl;
      return 3;
    }

    // print the query
    std::cout << "Query:" << std::endl;
    printFile(std::cout, lQueryFile.get_path());
    std::cout << std::endl;

    if( i == 1 )
    {
      // Instantiate the simple store
#ifdef ZORBA_MINIMAL_STORE
      zorba::storeminimal::SimpleStore* store =
      zorba::storeminimal::SimpleStore::getInstance();
#else
      zorba::simplestore::SimpleStore* store =
      zorba::simplestore::SimpleStoreManager::getStore();
#endif

      // Instantiate zorba query processor
      engine = zorba::Zorba::getInstance(store);
    }

    TestErrorHandler errHandler;

    // create and compile the query
    std::string lQueryString;
    slurp_file(lQueryFile.get_path().c_str(), lQueryString);
    zorba::XQuery_t lQuery = engine->createQuery (&errHandler);
    lQuery->setFileName (lQueryFile.get_path ());
    lQuery->compile (lQueryString.c_str(), getCompilerHints());

    errors = -1;
    if ( errHandler.errors() )
    {
      errors = analyzeError (lSpec, errHandler);
      if( errors == UNEXPECTED_ERROR )
        return 6;
    }
    else
    {
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

      set_vars(&lSpec, lDynCtxt);

      errors = -1;
      {
        // serialize xml
        {
          std::ofstream lResFileStream(lResultFile.get_path().c_str());
          assert (lResFileStream.good());

          lResFileStream << lQuery;
        }

        if (errHandler.errors())
          errors = analyzeError (lSpec, errHandler);
        else if ( lSpec.errorsSize() > 0 ) {
          if ( ! lRefFile.exists () ) {
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
      else if( errors == -1 )
      {
        std::cout << "Result:" << std::endl;
        printFile(std::cout, lResultFile.get_path());
        std::cout << "=== end of result ===" << std::endl;
        std::cout.flush();

        // last, we have to diff the result
        int lLine, lCol, lPos; // where do the files differ
        std::string lRefLine, lResultLine;
        bool lRes = isEqual(lRefFile, lResultFile, lLine, lCol, lPos, lRefLine, lResultLine);
        if ( !lRes )  // results differ
        {
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
