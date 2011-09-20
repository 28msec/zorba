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

#include "zorbacmdproperties.h"

#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

#ifdef WIN32
#include <windows.h>
#define sleep(s) Sleep(s*1000)
#endif

#include <zorba/zorba.h>
#include <zorba/file.h>
#include <zorba/zorba_exception.h>
#include <zorba/xquery_exception.h>
#include <zorba/document_manager.h>
#include <zorba/item_sequence.h>
#include <zorba/iterator.h>
#include <zorba/xquery_functions.h>
#include <zorba/uri_resolvers.h>

#include <zorba/store_manager.h>

#include "error_printer.h"
#include "util.h"
#include "module_path.h"

// For setting the base URI from the current directory
#include <zorba/util/path.h>

// Timing utilities, including wall-clock timing
#include <zorba/util/time.h>

// toggle this to allow configuration via a system properties file
// (see src/system/properties.*)
#define ZORBACMD_LOAD_SYSTEM_PROPERTIES 1

#if ZORBACMD_LOAD_SYSTEM_PROPERTIES
#  include "system/properties.h"
#endif

using namespace zorba;
namespace zorbatm = zorba::time;

const char *copyright_str =
  "Copyright 2006-2009 The FLWOR Foundation.\n"
  "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>";

#define PATH_SEP (zorba::filesystem_path::get_directory_separator ())

#ifndef ZORBA_NO_FULL_TEXT
OneToOneURIMapper theStopWordsMapper(EntityData::STOP_WORDS);
OneToOneURIMapper theThesaurusMapper(EntityData::THESAURUS, URIMapper::COMPONENT);
#endif

bool
populateStaticContext(
    zorba::StaticContext_t& aStaticContext,
    const ZorbaCMDProperties& aProperties)
{
  try
  {
    // add the following module path to the static context (in this order)
    // 1. command-line properties
    // 2. environment ZORBA_MODULE_PATH
    // 3. current working directory
    {
      std::vector<String> lModulePaths;
      ModulePath::getModulePaths(aProperties, lModulePaths);

      aStaticContext->setModulePaths(lModulePaths);
    }

    if (aProperties.boundarySpace().size() != 0 )
      aStaticContext->setBoundarySpacePolicy(
                         (aProperties.boundarySpace().compare("preserve") == 0
                          ? preserve_space
                          : strip_space));

    if (aProperties.constructionMode().size() != 0)
      aStaticContext->setConstructionMode( aProperties.boundarySpace().compare("preserve") == 0
                                           ? preserve_cons
                                           : strip_cons );

    if (aProperties.orderingMode().size() != 0 )
    {
      aStaticContext->setOrderingMode( aProperties.boundarySpace().compare("ordered") == 0
                                       ? ordered
                                       : unordered );
    }

    if (aProperties.baseUri().size() != 0 )
      aStaticContext->setBaseURI( aProperties.baseUri() );
  }
  catch (zorba::ZorbaException const& ze) {
    std::cerr << ze << std::endl;
    return false;
  }

  if (aProperties.defaultCollation().size() != 0 )
  {
    try {
      aStaticContext->addCollation( aProperties.defaultCollation() );
    } catch (zorba::ZorbaException const&) {
      std::cerr << "the given collation {" << aProperties.defaultCollation() << "} is not a valid collation." << std::endl;
      return false;
    }
    aStaticContext->setDefaultCollation( aProperties.defaultCollation() );
  }

  {
    ZorbaCMDProperties::Options_t::const_iterator lIter = aProperties.optionsBegin();
    ZorbaCMDProperties::Options_t::const_iterator end = aProperties.optionsEnd();
    for (; lIter != end; ++lIter)
    {
      try {
        zorba::Zorba* lZorba = zorba::Zorba::getInstance(0);
        Item lQName = lZorba->getItemFactory()->createQName(lIter->clark_qname);
        aStaticContext->declareOption(lQName, lIter->value);
      } catch (zorba::ZorbaException const& /* e */) {
        std::cerr << "unable to set static context option with qname "
                  << lIter->clark_qname << std::endl;
        return false;
      }
    }
  }
#ifndef ZORBA_NO_FULL_TEXT
  {
    ZorbaCMDProperties::FullText_t::const_iterator lIter = aProperties.stopWordsBegin();
    ZorbaCMDProperties::FullText_t::const_iterator end = aProperties.stopWordsEnd();
    for (; lIter != end; ++lIter) {
      theStopWordsMapper.addMapping(lIter->uri, lIter->value);
    }
    aStaticContext->registerURIMapper(&theStopWordsMapper);
  }
  {
    ZorbaCMDProperties::FullText_t::const_iterator lIter = aProperties.thesaurusBegin();
    ZorbaCMDProperties::FullText_t::const_iterator end = aProperties.thesaurusEnd();
    for (; lIter != end; ++lIter) {
      theThesaurusMapper.addMapping(lIter->uri, lIter->value);
    }
    aStaticContext->registerURIMapper(&theThesaurusMapper);
  }
#endif
  return true;
}


bool
populateDynamicContext(
  Zorba* zorba,
  zorba::DynamicContext* aDynamicContext,
  const ZorbaCMDProperties& aProperties)
{
  XmlDataManager* lXmlMgr = zorba->getXmlDataManager();
  if ( aProperties.contextItem().size() != 0 ) {
    std::ifstream lInStream(aProperties.contextItem().c_str());
    Item lDoc = lXmlMgr->parseXML(lInStream);
    aDynamicContext->setContextItem(lDoc);
  }

  ZorbaCMDProperties::ExternalVars_t::const_iterator lIter;
  ZorbaCMDProperties::ExternalVars_t::const_iterator end = aProperties.externalVarsEnd();
  for (lIter = aProperties.externalVarsBegin();
       lIter != end;
       ++lIter)
  {
    try
    {
      if ((*lIter).inline_file)
      {
        std::ifstream lInStream((*lIter).var_value.c_str());
        Item lDoc = lXmlMgr->parseXML(lInStream);
        aDynamicContext->setVariable((*lIter).var_name, lDoc);
      }
      else
      {
        zorba::Item lItem = zorba->getItemFactory()->createString((*lIter).var_value);
        aDynamicContext->setVariable((*lIter).var_name, lItem);
      }
    }
    catch (...)
    {
      // Let normal exception handling display the error message; here we
      // just want to tell the user what variable binding caused the problem
      std::cerr << "While binding external variable $"
                << lIter->var_name << ": ";
      throw;
    }
  }
  return true;
}


bool
createSerializerOptions(
    Zorba_SerializerOptions_t& lSerOptions,
    const ZorbaCMDProperties& aProperties)
{
  if ( aProperties.indent() )
    lSerOptions.indent = ZORBA_INDENT_YES;

  if ( aProperties.omitXmlDeclaration() )
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  if ( aProperties.byteOrderMark() )
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;

  if ( aProperties.serializeHtml() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
  else if ( aProperties.serializeText() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;

  return true;
}


/// Fullfills the command-line "as-file" (-f) switch,
/// or if not requested, infers -f for file:// queries.
/// Returns an URI or the empty string.
std::string
parseFileURI (bool asPath, const std::string &str)
{
  if (asPath)
    return str;

  // otherwise, the user still might have meant a file
#ifdef WIN32
  // file:///c:/ returns c:<backslash>
  // file://localhost returns \\localhost
  // BUG: it seems that <a>/x returns <a>\x
  static const char *file3 = "file:///";
  static const char *file2 = "file://";
  std::string fpath;
  if(str.compare(0, strlen(file3), file3) == 0) {
    fpath = str.substr(strlen(file3));
  } else if(str.compare(0, strlen(file2), file2) == 0) {
    fpath = PATH_SEP;
    fpath += str.substr(strlen(file2));
  }
  // replace all slash with backslash
  std::string::size_type off=0;
  while ((off=fpath.find('/', off)) != std::string::npos)
    fpath.replace(off, 1, PATH_SEP);
  return fpath;

#else // for UNIX

  static const char *pfx = "file://";
  static unsigned plen = strlen (pfx);
  if (str.compare (0, plen, pfx) == 0)
    return str.substr (plen);
  else
    return "";
#endif
}


//
// Timing utilities and class
//

#define DECLARE_TIMER(kind)                               \
  zorbatm::walltime start##kind##Walltime;                    \
  zorbatm::walltime stop##kind##Walltime;                     \
  zorbatm::cputime start##kind##Cputime;                    \
  zorbatm::cputime stop##kind##Cputime;                     \
  double elapsed##kind##Walltime;                             \
  double elapsed##kind##Cputime

#define START_TIMER(kind)                             \
  zorbatm::get_current_walltime(start##kind##Walltime);   \
  zorbatm::get_current_cputime(start##kind##Cputime);

#define STOP_TIMER(kind)                                                \
  zorbatm::get_current_walltime(stop##kind##Walltime);                      \
  elapsed##kind##Walltime += zorbatm::get_walltime_elapsed(start##kind##Walltime, \
    stop##kind##Walltime);                                                  \
                                                                        \
  zorbatm::get_current_cputime(stop##kind##Cputime);                      \
  elapsed##kind##Cputime += zorbatm::get_cputime_elapsed(start##kind##Cputime, \
    stop##kind##Cputime);



struct TimingInfo
{
  typedef enum
  {
    INIT_TIMER,
    DEINIT_TIMER,
    COMP_TIMER,
    EXEC_TIMER,
    UNLOAD_TIMER,
    TOTAL_TIMER
  } TimerKind;

  unsigned long numExecs;

  DECLARE_TIMER(Init);
  DECLARE_TIMER(Deinit);
  DECLARE_TIMER(Comp);
  DECLARE_TIMER(Exec);
  DECLARE_TIMER(Load);
  DECLARE_TIMER(Unload);
  DECLARE_TIMER(Total);

  TimingInfo(unsigned long num)
    :
    numExecs(num),
    elapsedInitWalltime(0),
    elapsedInitCputime(0),
    elapsedDeinitWalltime(0),
    elapsedDeinitCputime(0),
    elapsedCompWalltime(0),
    elapsedCompCputime(0),
    elapsedExecWalltime(0),
    elapsedExecCputime(0),
    elapsedLoadWalltime(0),
    elapsedLoadCputime(0),
    elapsedUnloadWalltime(0),
    elapsedUnloadCputime(0),
    elapsedTotalWalltime(0),
    elapsedTotalCputime(0)
  {
  }

  void startTimer(TimerKind kind, unsigned long iteration);
  void stopTimer(TimerKind kind, unsigned long iteration);

  std::ostream& print(std::ostream& os);
};


void
TimingInfo::startTimer(TimerKind kind, unsigned long iteration)
{
  if (iteration == 0 && numExecs > 1)
    return;

  switch (kind)
  {
  case INIT_TIMER:
    START_TIMER(Init);
    break;

  case DEINIT_TIMER:
    START_TIMER(Deinit);
    break;

  case TOTAL_TIMER:
    START_TIMER(Total);
    break;

  case COMP_TIMER:
    START_TIMER(Comp);
    break;

  case EXEC_TIMER:
    START_TIMER(Exec);
    break;

  case UNLOAD_TIMER:
    START_TIMER(Unload);
    break;
  }
}


void
TimingInfo::stopTimer(TimerKind kind, unsigned long iteration)
{
  if (iteration == 0 && numExecs > 1)
    return;

  switch (kind)
  {
  case INIT_TIMER:
  {
    STOP_TIMER(Init);
    break;
  }
  case DEINIT_TIMER:
  {
    STOP_TIMER(Deinit);
    break;
  }
  case TOTAL_TIMER:
  {
    STOP_TIMER(Total);
    break;
  }
  case COMP_TIMER:
  {
    STOP_TIMER(Comp);
    break;
  }
  case EXEC_TIMER:
  {
    STOP_TIMER(Exec);
    break;
  }
  case UNLOAD_TIMER:
  {
    STOP_TIMER(Unload);
    break;
  }
  }
}


std::ostream&
TimingInfo::print(std::ostream& os)
{
  os.precision(3);
  os.setf(std::ios::fixed);

  os << "\nNumber of executions = " << numExecs << std::endl;

  unsigned long timeDiv = numExecs == 1 ? 1 : (numExecs - 1);
  double cWalltime = elapsedCompWalltime / timeDiv;
  double eWalltime = elapsedExecWalltime / timeDiv;
  double lWalltime = elapsedLoadWalltime / timeDiv;
  double uWalltime = elapsedUnloadWalltime / timeDiv;
  double tWalltime = elapsedTotalWalltime / timeDiv;

  double cCputime = elapsedCompCputime / timeDiv;
  double eCputime = elapsedExecCputime / timeDiv;
  double lCputime = elapsedLoadCputime / timeDiv;
  double uCputime = elapsedUnloadCputime / timeDiv;
  double tCputime = elapsedTotalCputime / timeDiv;

  os << "Engine Startup Time     : " << elapsedInitWalltime
     << " (user: " << elapsedInitCputime << ")"
     << " milliseconds" << std::endl;

  os << "Average Compilation Time: " << cWalltime
     << " (user: " << cCputime << ")"
     << " milliseconds" << std::endl;

  os << "Average Execution Time  : " << eWalltime - lWalltime
     << " (user: " << eCputime - lCputime  << ")"
     << " milliseconds" << std::endl;

  os << "Average Loading Time    : " << lWalltime
     << " (user: " << lCputime << ")"
     << " milliseconds" << std::endl;

  os << "Average Unloading Time  : " << uWalltime
     << " (user: " << uCputime << ")"
     << " milliseconds" << std::endl;

  os << "Average Total Time      : " << tWalltime
     << " (user: " << tCputime << ")"
     << " milliseconds" << std::endl;

  return os;
}


void
removeOutputFileIfNeeded(const ZorbaCMDProperties& lProperties)
{
  if (lProperties.outputFile().size() > 0)
  {
    File_t lFile = zorba::File::createFile(lProperties.outputFile());
    if (lFile->exists())
    {
      lFile->remove();
    }
  }
}


int
compileAndExecute(
    zorba::Zorba* zorbaInstance,
    const ZorbaCMDProperties& properties,
    zorba::StaticContext_t& staticContext,
    const std::string& qfilepath,
    std::istream& qfile,
    std::ostream& outputStream,
    TimingInfo& timing)
{
  unsigned long lNumExecutions = properties.multiple();
  bool lIndent = properties.indent();
  bool doTiming = properties.timing();

  Zorba_CompilerHints lHints;

  // default is O1 in the Zorba_CompilerHints constructor
  if (properties.optimizationLevel() == "O0") {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
  } else if (properties.optimizationLevel() == "O2") {
    lHints.opt_level = ZORBA_OPT_LEVEL_O2;
  }

  // default is false
  if (properties.libModule())
  {
    lHints.lib_module = true;
  }

  Zorba_SerializerOptions lSerOptions = Zorba_SerializerOptions::SerializerOptionsFromStringParams(properties.getSerializerParameters());
  createSerializerOptions(lSerOptions, properties);

  zorba::XQuery_t query;
  DiagnosticHandler diagnosticHandler;

  for (unsigned long i = 0; i < lNumExecutions; ++i)
  {
    // Perform compilation and create dynamic context only once, unless timing is needed
    if (doTiming || i == 0)
    {
      // go back to the beginning of the stream
      qfile.clear();
      qfile.seekg(0);
      assert (qfile.tellg() >= 0);

      if (doTiming)
      {
        // start the total timer
        timing.startTimer(TimingInfo::TOTAL_TIMER, i);
      }

      //
      // Compile the query
      //
      try
      {
        if (doTiming)
        {
          // start the compilation timer
          timing.startTimer(TimingInfo::COMP_TIMER, i);
        }

        query = zorbaInstance->createQuery();
        query->registerDiagnosticHandler(&diagnosticHandler);
        query->setFileName(qfilepath);

        query->compile(qfile, staticContext, lHints);

        if (doTiming)
        {
          // stop the compilation timer
          timing.stopTimer(TimingInfo::COMP_TIMER, i);
        }
      }
      catch (zorba::XQueryException const& qe)
      {
        ErrorPrinter::print(qe, std::cerr, properties.printErrorsAsXml(), lIndent);
        return 11;
      }
      catch (zorba::ZorbaException const& ze)
      {
        std::cerr << ze << std::endl;
        return 12;
      }

      // if (diagnosticHandler.

      //
      // Create and populate the dynamic context
      //
      zorba::DynamicContext* lDynamicContext = query->getDynamicContext();
      try
      {
        if ( ! populateDynamicContext(zorbaInstance, lDynamicContext, properties) )
        {
          properties.printHelp(std::cout);
          return 21;
        }
      }
      catch (zorba::XQueryException const& qe)
      {
        ErrorPrinter::print(qe, std::cerr, properties.printErrorsAsXml(), lIndent);
        return 22;
      }
      catch (zorba::ZorbaException const& ze)
      {
        std::cerr << ze << std::endl;
        return 23;
      }
    } // if (doTiming || i == 0)

    // libModule assumes compileOnly even if compileOnly is false
    if ( ! properties.compileOnly() && ! properties.libModule() )
    {
      //
      // Run the query
      //
      try
      {
        if (doTiming)
        {
          // start the execution timer
          timing.startTimer(TimingInfo::EXEC_TIMER, i);
        }

        if (properties.noSerializer())
        {
          query->executeSAX();
        }
        else
        {
          query->execute(outputStream, &lSerOptions);
          if (properties.trailingNl()) {
            outputStream << std::endl;
          }
        }

        if (doTiming)
        {
          // stop the execution timer
          timing.stopTimer(TimingInfo::EXEC_TIMER, i);
        }

        if (i > 0 || lNumExecutions == 1) {
          timing.elapsedLoadWalltime += query->getDocLoadingTime();
          timing.elapsedLoadCputime += query->getDocLoadingUserTime();
        }
      }
      catch (zorba::XQueryException const& qe)
      {
        ErrorPrinter::print(qe, std::cerr, properties.printErrorsAsXml(), lIndent);
        return 31;
      }
      catch (zorba::ZorbaException const& ze)
      {
        std::cerr << ze << std::endl;
        return 32;
      }
    }

    // only delete the docs from the store if timing is needed
    if (doTiming)
    {
      //
      // Delete all loaded docs from the store
      //
      XmlDataManager* store = zorbaInstance->getXmlDataManager();

      timing.startTimer(TimingInfo::UNLOAD_TIMER, i);
      DocumentManager* lMgr = store->getDocumentManager();
      ItemSequence_t lSeq = lMgr->availableDocuments();
      Iterator_t lIter = lSeq->getIterator();
      lIter->open();
      Item lURI;
      while (lIter->next(lURI)) {
        lMgr->remove(lURI.getStringValue());
      }
      timing.stopTimer(TimingInfo::UNLOAD_TIMER, i);

      timing.stopTimer(TimingInfo::TOTAL_TIMER, i);
    }
  }

  return 0;
}

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Main                                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

#ifndef _WIN32_WCE
int
main(int argc, char* argv[])
#else
int
_tmain(int argc, _TCHAR* argv[])
#endif
{
#if ZORBACMD_LOAD_SYSTEM_PROPERTIES
  // only configurable via a config file or environment vars
  zorba::Properties::load(0, NULL);
#endif

  // parse the command line and/or the properties file
  ZorbaCMDProperties lProperties;
  if (!lProperties.loadProperties(argc, argv))
  {
    return 1;
  }

  TimingInfo timing(lProperties.multiple());

  bool doTiming = lProperties.timing();
  bool debug = false;
#ifdef ZORBA_WITH_DEBUGGER
  debug = (lProperties.debug());
#endif

  // libModule assumes compileOnly even if compileOnly is false
  bool compileOnly = (lProperties.compileOnly() || lProperties.libModule() );

  // write to file or standard out
  std::auto_ptr<std::ostream> lFileStream(lProperties.outputFile().size() > 0 ?
                                           new std::ofstream(lProperties.outputFile().c_str())
                                          : 0 );
  std::ostream* lOutputStream = lFileStream.get();
  if ( lOutputStream == 0 )
  {
    lOutputStream = &std::cout;
  }
  else if ( !lOutputStream->good() )
  {
    std::cerr << "could not write to output file {" << lProperties.outputFile()
              << "}" << std::endl;
    return 2;
  }

  if(lProperties.queriesOrFilesBegin() == lProperties.queriesOrFilesEnd())
  {
    std::cerr << "no queries submitted." << std::endl;
    lProperties.printHelp(std::cout);
    return 3;
  }


  // Start the engine

  timing.startTimer(TimingInfo::INIT_TIMER, 2);

  void* store = zorba::StoreManager::getStore();

  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance(store);

  {
  timing.stopTimer(TimingInfo::INIT_TIMER, 2);

  // For each query ...

  int queryNo;
  ZorbaCMDProperties::QueriesOrFiles_t::const_iterator lIter;
  for (queryNo = 1, lIter = lProperties.queriesOrFilesBegin();
       lIter != lProperties.queriesOrFilesEnd();
       ++queryNo, ++lIter)
  {
    //
    // Read the query (either from a file or given as parameter)
    //
    std::string fURI = *lIter;
    std::string fname = parseFileURI (lProperties.asFiles (), fURI);
    zorba::filesystem_path path (fname);
    bool asFile = ! fname.empty ();
    std::auto_ptr<std::istream> qfile;

    if (asFile)
    {
      path.resolve_relative ();
      qfile.reset (new std::ifstream (path.c_str ()));
    }
    else
    {
      qfile.reset (new std::istringstream(fURI));
    }

    if ( asFile && (!qfile->good() || qfile->eof()) )
    {
      std::cerr << "file {" << fname << "} not found or not readable." << std::endl;
      lProperties.printHelp(std::cout);
      return 3;
    }
    else if (fURI.empty ())
    {
      std::cerr << "empty query." << std::endl;
      lProperties.printHelp(std::cout);
      return 3;
    }

    //
    // Print the query if requested
    //
    if (lProperties.printQuery()) {
      *lOutputStream << "\nQuery number " << queryNo << " :\n";
      std::copy (std::istreambuf_iterator<char> (*qfile),
                 std::istreambuf_iterator<char> (),
                 std::ostreambuf_iterator<char> (*lOutputStream));
      *lOutputStream << std::endl;
      // go back to the beginning
      qfile->seekg(0);
    }

    //
    // Create the static context and populate it with info taken from the properties
    //
    zorba::StaticContext_t lStaticContext = lZorbaInstance->createStaticContext();
    if (! populateStaticContext(lStaticContext, lProperties) )
    {
      lProperties.printHelp(std::cout);
      return 3;
    }

    if (!asFile && lProperties.baseUri().size() == 0 )
    {
      // No user set base URI. Set the cwd to be used as base-uri in order
      // to make the doc function doc("mydoc.xml") work
      zorba::filesystem_path p;
      std::stringstream lTmp;
      std::vector<std::string> lTokens;
      Util::tokenize(p.c_str(), PATH_SEP, lTokens);

      lTmp << "file://";
      for (std::vector<std::string>::const_iterator lIter = lTokens.begin();
           lIter != lTokens.end(); ++lIter)
      {
        zorba::String lTmpString(*lIter);
        lTmp << '/' << fn::encode_for_uri( lTmpString );
      }

      lTmp << '/';

      lStaticContext->setBaseURI(lTmp.str());
    }

    // Parse the query
    if (lProperties.parseOnly()) {
      try {
        zorba::XQuery_t lQuery = lZorbaInstance->createQuery();
        if (asFile) {
          lQuery->setFileName(path.get_path());
        }

        lQuery->parse (*qfile);
      }
      catch (zorba::ZorbaException const& ze) {
        std::cerr << ze << std::endl;
        return 6;
      }
    }

    // Compile and run it if necessary.
    // Print timing information if requested.
    else if (!debug) {
      if (compileOnly) {
        try {
          zorba::XQuery_t aQuery = lZorbaInstance->createQuery();
          if (asFile) {
            aQuery->setFileName(path.get_path());
          }
          aQuery->parse(*qfile);
          qfile->clear();
          qfile->seekg(0); // go back to the beginning
        } catch (zorba::XQueryException const& qe) {
          ErrorPrinter::print(qe, std::cerr, lProperties.printErrorsAsXml(), lProperties.indent());
          return 6;
        }
      }

      int status = compileAndExecute(lZorbaInstance,
                                     lProperties,
                                     lStaticContext,
                                     path.get_path(),
                                     *qfile,
                                     *lOutputStream,
                                     timing);
      if (status != 0) {
        // reset the file handler (in case output option was provided)
        // in order to delete the created output file
        lFileStream.reset();
        removeOutputFileIfNeeded(lProperties);
        return status;
      }

      if (doTiming) {
        timing.print(std::cout);
      }
    }

#ifdef ZORBA_WITH_DEBUGGER
    // Debug the query. Do not allow "compileOnly" flags and inline queries
    else if (debug) {
      if (compileOnly) {
        std::cerr << "cannot debug a query if the compileOnly option is specified"
                  << std::endl;
        return 7;
      }

      if (!asFile) {
        std::cerr << "Cannot debug inline queries." << std::endl;
        return 8;
      }

      std::auto_ptr<std::istream> lXQ(new std::ifstream(path.c_str()));
      std::string lFileName(path.get_path());

      zorba::XQuery_t lQuery;

      try {
        lQuery = lZorbaInstance->createQuery();
        lQuery->setFileName(lFileName);
        lQuery->setDebugMode(true);

        Zorba_CompilerHints lHints;
        lHints.opt_level = ZORBA_OPT_LEVEL_O0;

        lQuery->compile(*lXQ.get(), lHints);
        zorba::DynamicContext* lDynamicContext = lQuery->getDynamicContext();
        if (!populateDynamicContext(lZorbaInstance, lDynamicContext, lProperties)) {
          return 9;
        }

        std::string lHost = lProperties.debugHost();
        if (lHost == "") {
          lHost = "127.0.0.1";
        }

        if (lProperties.debug()) {
          Zorba_SerializerOptions lSerOptions =
              Zorba_SerializerOptions::SerializerOptionsFromStringParams(
              lProperties.getSerializerParameters());
          createSerializerOptions(lSerOptions, lProperties);

          if (!lProperties.hasNoLogo() && !lProperties.debug()) {
            std::cout << "Zorba XQuery Debugger Server\n" << copyright_str << std::endl;
          }
          lQuery->debug(*lOutputStream, lSerOptions, lHost, lProperties.getDebugPort());
        }
      }
      catch (zorba::XQueryException const& qe)
      {
        ErrorPrinter::print(qe, std::cerr, lProperties.printErrorsAsXml(), lProperties.indent());
        return 5;
      }
      catch (zorba::ZorbaException const& ze)
      {
        std::cerr << ze << std::endl;
        return 6;
      }
    } // else if (debug)
#endif

  } // for each query

  }

  if (doTiming)
  {
    timing.startTimer(TimingInfo::DEINIT_TIMER, 2);
  }

  lZorbaInstance->shutdown();
  zorba::StoreManager::shutdownStore(store);

  if (doTiming)
  {
    timing.stopTimer(TimingInfo::DEINIT_TIMER, 2);

    std::cout << std::endl << "Engine Shutdown Time     : "
              << timing.elapsedDeinitWalltime
              << " (user: " << timing.elapsedDeinitCputime << ")"
              << " milliseconds" << std::endl;
  }
  return 0;
}
