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

#include <zorba/diagnostic_list.h>
#include <zorba/iterator.h>
#include <zorba/item_sequence.h>
#include <zorba/properties.h>
#include <zorba/static_context_consts.h>
#include <zorba/store_consts.h>
#include <zorbatypes/URI.h>
#include <zorba/xmldatamanager.h>

#include "util/ascii_util.h"
#include "util/string_util.h"

#include "testdriverconfig.h"
#include "testdriver_common.h"
#include "specification.h"

static void set_var(
    DriverContext& driverCtx,
    zorba::DynamicContext* dctx,
    const zorba::StaticContext* sctx,
    bool inlineFile,
    std::string name,
    std::string val,
    bool enableDtd);

static void set_vars(
    DriverContext& driverCtx,
    zorba::DynamicContext* dctx,
    const zorba::StaticContext* sctx,
    bool enableDtd);


/*******************************************************************************

********************************************************************************/
DriverContext::DriverContext(zorba::Zorba* zorba)
  :
  theEngine(zorba),
  theSpec(NULL)
{
  theXmlDataMgr = theEngine->getXmlDataManager();
}


/*******************************************************************************

********************************************************************************/
void slurp_file (
    const char* fname,
    std::string& result,
    const std::string& rbkt_src_dir,
    const std::string& rbkt_bin_dir)
{
  std::ifstream qfile(fname, std::ios::binary | std::ios_base::in);
  assert (qfile);

  qfile.seekg (0, std::ios::end);
  unsigned int len = static_cast<unsigned int> (qfile.tellg ());
  qfile.seekg (0, std::ios::beg);

  char *str = new char [len];

  qfile.read (str, len);

  len = static_cast<unsigned int> (qfile.gcount());

  std::string sstr(str, len);

  if(sstr.find("$RBKT_SRC_DIR",0) != std::string::npos)
  {
    std::string rbkt_src_uri= zorba::URI::encode_file_URI(rbkt_src_dir);

#ifdef ZORBA_TEST_XQUERYX
    zorba::ascii::replace_all(rbkt_src_uri, "%3A", ":");
#endif
    zorba::ascii::replace_all(sstr, "$RBKT_SRC_DIR", rbkt_src_uri);
#ifdef MY_D_WIN32
    zorba::ascii::replace_all(sstr,
                           "w3c_testsuite/Queries/w3c_testsuite",
                           "w3c_testsuite/Queries");
#endif
  }

  if(sstr.find("$RBKT_BIN_DIR",0) != std::string::npos)
  {
    std::string rbkt_bin_uri = zorba::URI::encode_file_URI(rbkt_bin_dir);
    zorba::ascii::replace_all(sstr, "$RBKT_BIN_DIR", rbkt_bin_uri);
  }

  result.swap (sstr);
  delete [] str;
}


/*******************************************************************************
  Check if an error that was repored was expected by the given spec object.
********************************************************************************/
bool isErrorExpected(const TestDiagnosticHandler& errHandler, const Specification* aSpec)
{
  static std::string star("*");
  std::vector<std::string> const& qnames = errHandler.getErrorQNames();
  for(std::vector<std::string>::const_iterator actual = qnames.begin();
      actual != qnames.end();
      actual++)
  {
    for(std::vector<std::string>::const_iterator expect = aSpec->errorsBegin();
        expect != aSpec->errorsEnd();
        expect++)
    {
      if ((*actual == *expect) || (*expect == star))
        return true;
    }
  }
  return false;
}


/*******************************************************************************
  Print all errors that were raised
********************************************************************************/
void printErrors(
    const TestDiagnosticHandler& errHandler,
    const char* msg,
    bool printInFile,
    std::ostream& output)
{
  if (!errHandler.errors())
  {
    return;
  }

  std::ofstream errFile;

  if (printInFile)
  {
    errFile.open(errHandler.getErrorFile().c_str(), std::ios_base::app);
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
      output << msg << ":" << std::endl;
  }

  const std::vector<std::string>& qnames = errHandler.getErrorQNames();
  const std::vector<zorba::String>& descs = errHandler.getErrorDescs();

  std::vector<std::string>::const_iterator codeIter = qnames.begin();
  std::vector<zorba::String>::const_iterator descIter = descs.begin();

  for(; codeIter != qnames.end(); ++codeIter, ++descIter)
  {
    assert (descIter != descs.end());
    if (printInFile)
      errFile << *codeIter << ": " << *descIter << std::endl;
    else
      output << *codeIter << ": " << *descIter << std::endl;
  }
  return;
}


/*******************************************************************************

********************************************************************************/
Zorba_CompilerHints getCompilerHints()
{
  Zorba_CompilerHints lHints;

  // ZORBA_OPTLEVEL=O0 | O1 | O2
  char* lOptLevel = getenv("ZORBA_OPTLEVEL");
  if ( lOptLevel != NULL && strcmp(lOptLevel, "O0") == 0 )
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
    //std::cout << "testdriver is using optimization level O0" << std::endl;
  }
  else if ( lOptLevel != NULL && strcmp(lOptLevel, "O2") == 0) 
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O2;
    //std::cout << "testdriver is using optimization level O2" << std::endl;
  }
  else
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O1;
    //std::cout << "testdriver is using optimization level O1" << std::endl;
  }

  lHints.for_serialization_only = false;

#if 0
  if ( zorba::Properties::instance().getSerializeOnlyQuery() )
    lHints.for_serialization_only = true;
#endif

  return lHints;
}


/*******************************************************************************
  Tries to create a ZorbaItem given a string in the form xs:TYPE(VALUE)
********************************************************************************/
zorba::Item createItem(DriverContext& driverCtx, std::string strValue)
{
  zorba::ItemFactory* itemfactory = driverCtx.theEngine->getItemFactory();
  size_t              pos = strValue.find("xs:");

  if(pos == std::string::npos)
  {
    strValue = zorba::URI::encode_file_URI(strValue);
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
      std::cerr << "Type {" << type << "} not supported." << std::endl;
      return  NULL;
    }
    else if(type == "anyURI")
      return itemfactory->createAnyURI(val);
    else
      //only primitive types allowed, see http://www.w3.org/TR/xmlschema-2/#built-in-primitive-datatypes
      std::cerr << "Type {" << type
                << "} is not a primitive data type.\n Derived types not supported."
                << std::endl;
      return  NULL;
  }
}


/*******************************************************************************
  Create dynamic context and set in it the external variables, the current
  date & time, and the timezone.
********************************************************************************/
void createDynamicContext(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& aBaseSctx,
    zorba::XQuery_t& query,
    bool enableDtd,
    zorba::DiagnosticHandler& errHandler)
{
  try 
  {
    zorba::Zorba* engine = driverCtx.theEngine;
    Specification& spec = *driverCtx.theSpec;
    zorba::ItemFactory& factory = *engine->getItemFactory();

    zorba::DynamicContext* dctx = query->getDynamicContext();

    // Set the current date time such that tests that use fn:current-time
    // behave deterministically
    if (spec.hasDateSet())
    {
      zorba::Item lDateTimeItem = factory.createDateTime(spec.getDate());

      dctx->setCurrentDateTime(lDateTimeItem);
    }

    if (spec.hasTimezoneSet())
    {
      int lTimezone = atoi(spec.getTimezone().c_str());

      std::cerr << "timezone " << lTimezone << std::endl;
      dctx->setImplicitTimezone(lTimezone);
    }

    if (spec.getDefaultCollection().size() != 0)
    {
      zorba::Item lDefaultCollection = factory.createAnyURI(spec.getDefaultCollection());
      dctx->setDefaultCollection(lDefaultCollection);
    }

    const zorba::StaticContext* lQuerySctx = query->getStaticContext();
    // Set external vars
    set_vars(driverCtx, dctx, lQuerySctx, enableDtd);

    if (spec.hasInputQuery())
    {
      std::string inputqueryfile = spec.getInputQueryFile ();
#ifdef MY_D_WIN32
      zorba::ascii::replace_all(inputqueryfile, "rbkt/Queries/w3c_testsuite/", "w3c_testsuite/Queries/");
#endif

      std::ifstream inputquery ( inputqueryfile.c_str() );

      if (!inputquery.is_open())
        std::cerr << "Could not open input query file: " << inputqueryfile.c_str() << std::endl;

      assert(inputquery.is_open());

      zorba::XQuery_t inputQuery = engine->compileQuery(inputquery,
                                                        aBaseSctx,
                                                        getCompilerHints());

      zorba::Iterator_t riter = inputQuery->iterator();
      dctx->setVariable(zorba::String("x"), riter);
    }
  }
  catch (zorba::ZorbaException const& e)
  {
    errHandler.error(e);
  }
}


/*******************************************************************************

********************************************************************************/
void set_vars(
    DriverContext& driverCtx,
    zorba::DynamicContext* dctx,
    const zorba::StaticContext* sctx,
    bool enableDtd)
{
  Specification& spec = *driverCtx.theSpec;

  //std::cout << "=== Setting variables from .spec file===" << std::endl;
  std::vector<Specification::Variable>::const_iterator lIter;
  for (lIter = spec.variablesBegin(); lIter != spec.variablesEnd(); ++lIter)
  {
    set_var(driverCtx,
            dctx, sctx,
            (*lIter).theInline,
            (*lIter).theVarName,
            (*lIter).theVarValue,
            enableDtd);
  }
  //std::cout << "=== end of setting variables ==" << std::endl;
}


/*******************************************************************************
  Set a variable in the dynamic context
  inlineFile specifies whether the given parameter is a file and its value
  should be inlined or not
********************************************************************************/
void set_var(
    DriverContext& driverCtx,
    zorba::DynamicContext* dctx,
    const zorba::StaticContext* sctx,
    bool inlineFile,
    std::string name,
    std::string val,
    bool enableDtd)
{
#ifdef MY_D_WIN32
  zorba::ascii::replace_all(val, "rbkt/Queries/w3c_testsuite/", "w3c_testsuite/Queries/");
  //zorba::ascii::replace_all(val, "/", "\\");
#endif
  //std::cout << "Setting variable " << name << " to value '" << val <<"'" << std::endl;
  if (!inlineFile)
  {
    zorba::Item lItem = createItem(driverCtx, val);
    if(name != ".")
      dctx->setVariable(name, lItem);
    else
      dctx->setContextItem(lItem);
  }
  else
  {
#ifdef MY_D_WIN32
    std::cout << "Load xml " << val << std::endl;
#endif

    zorba::DocumentManager* lDocMgr = driverCtx.theXmlDataMgr->getDocumentManager();

    zorba::Item lDoc;
    zorba::Item lValidatedDoc;

    {
      const char* val_fname = val.c_str();
      std::ifstream ifile(val_fname);
      if (! ifile || !ifile.is_open() )
      {
        std::cerr << "Could not open file `" << val_fname << "' for variable `"
                  << name << "'" << std::endl;
        assert (false);
      }

      zorba::XmlDataManager::ParseOptions lOptions;
      lOptions.setDtdValidation(enableDtd);

#ifndef WIN32
      std::string file_scheme = "file://";
#else
      std::string file_scheme = "file:///";
#endif
      zorba::ItemSequence_t lSeq =
      driverCtx.theXmlDataMgr->parseXML(ifile, file_scheme + val, lOptions);

      zorba::Iterator_t lIter = lSeq->getIterator();
      lIter->open();
      lIter->next(lDoc);
      lIter->close();

      assert (lDoc.getNodeKind() == zorba::store::StoreConsts::documentNode);

      zorba::validation_mode_t validationMode =
      (enableDtd ? zorba::validate_lax_dtd : zorba::validate_lax);

      sctx->validate(lDoc, lValidatedDoc, validationMode);

      bool done;

      do
      {
        done = true;

        try
        {
          lDocMgr->put(val, lValidatedDoc);
        }
        catch (const zorba::ZorbaException& e)
        {
          if (e.diagnostic() != zorba::zerr::ZAPI0020_DOCUMENT_ALREADY_EXISTS)
            throw;

          // The doc exists already. Remove it and try again, because the current
          // versionmay bea validated doc whereas the existing version may not be.
          try
          {
            lDocMgr->remove(val);
          }
          catch (const zorba::ZorbaException& e)
          {
            if (e.diagnostic() != zorba::zerr::ZXQD0002_DOCUMENT_NOT_VALID)
              throw;
          }

          done = false;
        }
      }
      while (!done);
    }

    if (name != ".")
    {
      dctx->setVariable(name, lValidatedDoc);
    }
    else
    {
      dctx->setContextItem(lValidatedDoc);
    }
  }
}


/**
 * Set all options on the provided static context.
 */
void setOptions(DriverContext& driverCtx, const zorba::StaticContext_t& sctx)
{
  Specification& spec = * (driverCtx.theSpec);
  std::vector<Specification::Option>::const_iterator lIter;
  for (lIter = spec.optionsBegin(); lIter != spec.optionsEnd(); ++lIter)
  {
    zorba::Item lQName = driverCtx.theEngine->getItemFactory()->
    createQName(lIter->theOptName);

    std::string lValue = lIter->theOptValue;
    sctx->declareOption(lQName, lValue);
  }
  
  if ( spec.getEnableDtd() )
  {
    zorba::Item lQName = driverCtx.theEngine->getItemFactory()->
    createQName("http://zorba.io/options/features", "", "enable");

    sctx->declareOption(lQName, "dtd");
  }
}


/**
 * Register a URIMapper on the provided static context, and save it
 * in the DriverContext for later reference.
 */
void addURIMapper(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx,
    zorba::URIMapper* mapper)
{
  sctx->registerURIMapper(mapper);
  driverCtx.theURIMappers.push_back(mapper);
}


/**
 * Register a URLResolver on the provided static context, and save it
 * in the DriverContext for later reference.
 */
void addURLResolver(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx,
    zorba::URLResolver* resolver)
{
  sctx->registerURLResolver(resolver);
  driverCtx.theURLResolvers.push_back(resolver);
}


/**
 * Set all full-text URI mappers on the provided static context.
 */
void setFullTextURIMappers(
    DriverContext& driverCtx,
    const zorba::StaticContext_t& sctx)
{
#ifndef ZORBA_NO_FULL_TEXT
  Specification& spec = * (driverCtx.theSpec);
  addURIMapper(driverCtx, sctx, spec.getStopWordsMapper());
  addURIMapper(driverCtx, sctx, spec.getThesaurusMapper());
#endif
}


/**
 * Set the module paths based on a :- or ;-separated list of paths.
 */
void setModulePaths(std::string paths, zorba::StaticContext_t& sctx)
{
  std::vector<zorba::String> lModulePaths;
  std::string lPath;
#ifdef WIN32
  char lDelim = ',';
#else
  char lDelim = ':';
#endif

  while (zorba::ztd::split(paths, lDelim, &lPath, &paths))
  {
    lModulePaths.push_back(lPath);
  }

  lModulePaths.push_back(paths);

  // Add the default paths for test modules.
  zorba::String lDefPath = zorba::CMAKE_BINARY_DIR + "/TEST_URI_PATH";
  lModulePaths.push_back(lDefPath);

  lDefPath = zorba::CMAKE_BINARY_DIR + "/TEST_LIB_PATH";
  lModulePaths.push_back(lDefPath);

  sctx->setModulePaths(lModulePaths);
}
