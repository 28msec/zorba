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

#include <zorbatypes/URI.h>
#include <zorbautils/strutil.h>

#include "testdriverconfig.h"
#include "testdriver_common.h"
#include "specification.h"


/*******************************************************************************

********************************************************************************/
void slurp_file (const char *fname, std::string &result, const std::string &rbkt_src_dir, const std::string &rbkt_bin_dir) {
  std::ifstream qfile(fname, std::ios::binary | std::ios_base::in);
  assert (qfile);

  qfile.seekg (0, std::ios::end);
  size_t len = qfile.tellg ();
  qfile.seekg (0, std::ios::beg);

  char *str = new char [len];

  qfile.read (str, len);

  len = qfile.gcount();

  std::string sstr (str, len);

  if(sstr.find("$RBKT_SRC_DIR",0) != std::string::npos)
  {
    std::string rbkt_src_uri = zorba::URI::encode_file_URI (rbkt_src_dir)->str ();
    zorba::str_replace_all(sstr, "$RBKT_SRC_DIR", rbkt_src_uri);
  }

  if(sstr.find("$RBKT_BINARY_DIR",0) != std::string::npos)
  {
    std::string rbkt_bin_uri = zorba::URI::encode_file_URI(rbkt_bin_dir)->str();
    zorba::str_replace_all(sstr, "$RBKT_BINARY_DIR", rbkt_bin_uri);
  }

  result.swap (sstr);
  delete [] str;
}


/*******************************************************************************
  Check if an error that was repored was expected by the given spec object.
********************************************************************************/
bool isErrorExpected(const TestErrorHandler& errHandler, const Specification* aSpec)
{
  std::string star("*");
  const std::vector<std::string>& errors = errHandler.getErrorList();
  for(std::vector<std::string>::const_iterator i = errors.begin();
      i != errors.end();
      ++i) 
  {
    for(std::vector<std::string>::const_iterator j = aSpec->errorsBegin();
        j != aSpec->errorsEnd();
        ++j) 
    {
      if ((i->compare(*j) == 0) || (j->compare(star)) == 0)
        return true;
    }
  }
  return false;
}


/*******************************************************************************
  Print all errors that were raised
********************************************************************************/
void printErrors(const TestErrorHandler& errHandler, const char* msg, bool printInFile)
{
  if (!errHandler.errors()) 
  {
    return;
  }

  std::ofstream errFile;

  if (printInFile)
  {
    errFile.open(errHandler.getErrorFile().c_str());
    if (!errFile.good())
    {
      std::cerr << "Failed to open file : " << errHandler.getErrorFile().c_str()
                << std::endl;
      abort();
    }
  }

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
Zorba_CompilerHints getCompilerHints()
{
  Zorba_CompilerHints lHints;

  // ZORBA_OPTLEVEL=O0 | O1
  char* lOptLevel = getenv("ZORBA_OPTLEVEL");
  if ( lOptLevel != NULL && strcmp(lOptLevel, "O0") == 0 ) 
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
    //std::cout << "testdriver is using optimization level O0" << std::endl;
  }
  else
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    //std::cout << "testdriver is using optimization level O1" << std::endl;
  }
  return lHints; 
}


/*******************************************************************************
  Tries to create a ZorbaItem given a string in the form xs:TYPE(VALUE)
********************************************************************************/
zorba::Item createItem(std::string strValue)
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
      std::cout << "Type {" << type
                << "} is not a primitive data type.\n Derived types not supported."
                << std::endl;
      return  NULL;
  }
}


/*******************************************************************************
  Set a variable in the dynamic context
  inlineFile specifies whether the given parameter is a file and its value
  should be inlined or not
********************************************************************************/
void
set_var(bool inlineFile, std::string name, std::string val, zorba::DynamicContext* dctx, const std::string &rbkt_src_dir) {
  zorba::str_replace_all (val, "$RBKT_SRC_DIR", rbkt_src_dir);

  if (!inlineFile) 
  {
    zorba::Item lItem = createItem(val);
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
      std::cout << "Could not open file `" << val_fname << "' for variable `"
                << name << "'" << std::endl;
      assert (false);
    }
		if(name != ".")
			dctx->setVariableAsDocument (name, val.c_str(), std::auto_ptr<std::istream>(is));
		else
			dctx->setContextItemAsDocument (val.c_str(), std::auto_ptr<std::istream>(is));
  }
}


/*******************************************************************************

********************************************************************************/
void set_vars(Specification* aSpec, zorba::DynamicContext* dctx, const std::string &rbkt_src_dir) {
  std::vector<Specification::Variable>::const_iterator lIter;
  for (lIter = aSpec->variablesBegin(); lIter != aSpec->variablesEnd(); ++lIter)
  {
    set_var((*lIter).theInline, (*lIter).theVarName, (*lIter).theVarValue, dctx, rbkt_src_dir);
  }
}
