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
#include <zorba/serialization_callback.h>
#include <zorba/audit.h>
#include <zorba/audit_scoped.h>

#include <zorba/store_manager.h>

//#define DO_AUDIT

#ifdef DO_AUDIT
#include <zorba/audit.h>
#include <zorba/audit_scoped.h>
#endif

#include "error_printer.h"
#include "util.h"
#include "path_util.h"

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

//#define DO_AUDIT

using namespace zorba;
namespace zorbatm = zorba::time;

const char *copyright_str =
  "Copyright 2006-2009 The FLWOR Foundation.\n"
  "License: Apache License 2.0: <http://www.apache.org/licenses/LICENSE-2.0>";

#define PATH_SEP (zorba::filesystem_path::get_directory_separator ())

#ifndef ZORBA_NO_FULL_TEXT
OneToOneURIMapper theStopWordsMapper(EntityData::STOP_WORDS);
OneToOneURIMapper theThesaurusMapper(EntityData::THESAURUS);
#endif


/*******************************************************************************

********************************************************************************/
class URIMapperSerializationCallback : public SerializationCallback
{
private:
  std::vector<URIMapper*>   theURIMappers;

public:
  void addURIMapper(URIMapper* mapper) { theURIMappers.push_back(mapper); }

  URIMapper* getURIMapper(size_t i) const { return theURIMappers[i]; }
};


URIMapperSerializationCallback theSerializationCallback;


/*******************************************************************************

********************************************************************************/
bool populateStaticContext(
    Zorba* zorba,
    zorba::StaticContext_t& sctx,
    const ZorbaCMDProperties& props)
{
  try
  {
    // add the following module path to the static context (in this order)
    // 1. command-line properties
    // 2. environment ZORBA_MODULE_PATH
    // 3. current working directory
    {
      std::vector<String> lModulePath;
      PathUtil::setPathsOnContext(props, sctx);
    }

    if (props.boundarySpace().size() != 0 )
    {
      sctx->setBoundarySpacePolicy(props.boundarySpace().compare("preserve") == 0 ?
                                   preserve_space : 
                                   strip_space);
    }

    if (props.constructionMode().size() != 0)
    {
      sctx->setConstructionMode(props.boundarySpace().compare("preserve") == 0 ? 
                                preserve_cons :
                                strip_cons);
    }

    if (props.orderingMode().size() != 0 )
    {
      sctx->setOrderingMode(props.boundarySpace().compare("ordered") == 0 ?
                            ordered :
                            unordered);
    }

    if (props.baseUri().size() != 0 )
      sctx->setBaseURI( props.baseUri() );
  }
  catch (const zorba::ZorbaException& ze) 
  {
    std::cerr << ze << std::endl;
    return false;
  }

  if (props.defaultCollation().size() != 0 )
  {
    try 
    {
      sctx->addCollation( props.defaultCollation() );
    }
    catch (zorba::ZorbaException const&)
    {
      std::cerr << "the given collation {" << props.defaultCollation()
                << "} is not a valid collation." << std::endl;
      return false;
    }

    sctx->setDefaultCollation( props.defaultCollation() );
  }

  ZorbaCMDProperties::Options_t::const_iterator lIter = props.optionsBegin();
  ZorbaCMDProperties::Options_t::const_iterator end = props.optionsEnd();
  for (; lIter != end; ++lIter)
  {
    try 
    {
      Item lQName = zorba->getItemFactory()->createQName(lIter->clark_qname);
      sctx->declareOption(lQName, lIter->value);
    }
    catch (zorba::ZorbaException const& /* e */) 
    {
      std::cerr << "unable to set static context option with qname "
                << lIter->clark_qname << std::endl;
      return false;
    }
  }

#ifdef DO_AUDIT
  zorba::audit::Provider* lAuditProvider = zorba->getAuditProvider();
  zorba::audit::Configuration* config = lAuditProvider->createConfiguration();
  std::vector<zorba::String> property_names;
  zorba::audit::Configuration::getPropertyNames(property_names);

  bool lIsStatic;

  lIsStatic = zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/parse-duration");
  assert(lIsStatic);

  lIsStatic = zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/translation-duration");
  assert(lIsStatic);

  lIsStatic = zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/optimization-duration");
  assert(lIsStatic);

  lIsStatic = zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/codegeneration-duration");
  assert(lIsStatic);

  zorba::audit::Event* event = lAuditProvider->createEvent(config);

  sctx->setAuditEvent(event);
#endif // DO_AUDIT

#ifndef ZORBA_NO_FULL_TEXT
  {
    ZorbaCMDProperties::FullText_t::const_iterator lIter = props.stopWordsBegin();
    ZorbaCMDProperties::FullText_t::const_iterator end = props.stopWordsEnd();
    for (; lIter != end; ++lIter) 
    {
      theStopWordsMapper.addMapping(lIter->uri, lIter->value);
    }

    if (props.serializePlan() || props.loadPlan()) 
    {
      theSerializationCallback.addURIMapper(&theStopWordsMapper);
    }
    else
    {
      sctx->registerURIMapper(&theStopWordsMapper);
    }
  }

  {
    ZorbaCMDProperties::FullText_t::const_iterator lIter = props.thesaurusBegin();
    ZorbaCMDProperties::FullText_t::const_iterator end = props.thesaurusEnd();
    for (; lIter != end; ++lIter) 
    {
      theThesaurusMapper.addMapping(lIter->uri, lIter->value);
    }

    if (props.serializePlan() || props.loadPlan())
    {
      theSerializationCallback.addURIMapper(&theStopWordsMapper);
    }
    else
    {
      sctx->registerURIMapper(&theThesaurusMapper);
    }
  }
#endif
  return true;
}


/*******************************************************************************

********************************************************************************/
bool populateDynamicContext(
    Zorba* zorba,
    zorba::DynamicContext* aDynamicContext,
    const ZorbaCMDProperties& props)
{
  if ( props.contextItem().size() != 0 ) 
  {
    XmlDataManager* lXmlMgr = zorba->getXmlDataManager();
    std::ifstream lInStream(props.contextItem().c_str());
    Item lDoc = lXmlMgr->parseXML(lInStream);
    aDynamicContext->setContextItem(lDoc);
  }

  ZorbaCMDProperties::ExternalVars_t::const_iterator lIter;
  ZorbaCMDProperties::ExternalVars_t::const_iterator end = props.externalVarsEnd();
  for (lIter = props.externalVarsBegin();
       lIter != end;
       ++lIter)
  {
    try
    {
      if ((*lIter).inline_file)
      {
        XmlDataManager* lXmlMgr = zorba->getXmlDataManager();
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


/*******************************************************************************

********************************************************************************/
bool createSerializerOptions(
    Zorba_SerializerOptions_t& lSerOptions,
    const ZorbaCMDProperties& props)
{
  if ( props.indent() )
    lSerOptions.indent = ZORBA_INDENT_YES;

  if ( props.omitXmlDeclaration() )
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;

  if ( props.byteOrderMark() )
    lSerOptions.byte_order_mark = ZORBA_BYTE_ORDER_MARK_YES;

  if ( props.serializeHtml() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_HTML;
  else if ( props.serializeText() )
    lSerOptions.ser_method = ZORBA_SERIALIZATION_METHOD_TEXT;

  return true;
}


/*******************************************************************************
  Fullfills the command-line "as-file" (-f) switch, or if not requested, infers
  -f for file:// queries. Returns an URI or the empty string.
********************************************************************************/
std::string parseFileURI(bool asPath, const std::string &str)
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
    PLAN_SAVE_TIMER,
    PLAN_LOAD_TIMER,
    TOTAL_TIMER
  } TimerKind;

  unsigned long numExecs;

  DECLARE_TIMER(Init);
  DECLARE_TIMER(Deinit);
  DECLARE_TIMER(Comp);
  DECLARE_TIMER(Exec);
  DECLARE_TIMER(Load);
  DECLARE_TIMER(Unload);
  DECLARE_TIMER(PlanSave);
  DECLARE_TIMER(PlanLoad);
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

    elapsedPlanSaveWalltime(0),
    elapsedPlanSaveCputime(0),

    elapsedPlanLoadWalltime(0),
    elapsedPlanLoadCputime(0),

    elapsedTotalWalltime(0),
    elapsedTotalCputime(0)
  {
  }

  void startTimer(TimerKind kind, unsigned long iteration);
  void stopTimer(TimerKind kind, unsigned long iteration);

  std::ostream& print(std::ostream& os, bool);
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

  case PLAN_SAVE_TIMER:
    START_TIMER(PlanSave);
    break;

  case PLAN_LOAD_TIMER:
    START_TIMER(PlanLoad);
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
  case PLAN_SAVE_TIMER:
  {
    STOP_TIMER(PlanSave);
    break;
  }
  case PLAN_LOAD_TIMER:
  {
    STOP_TIMER(PlanLoad);
    break;
  }
  }
}


std::ostream&
TimingInfo::print(std::ostream& os, bool serializePlan)
{
  os.precision(3);
  os.setf(std::ios::fixed);

  os << "\nNumber of executions = " << numExecs << std::endl;

  unsigned long timeDiv = numExecs == 1 ? 1 : (numExecs - 1);
  double cWalltime = elapsedCompWalltime / timeDiv;
  double eWalltime = elapsedExecWalltime / timeDiv;
  double lWalltime = elapsedLoadWalltime / timeDiv;
  double uWalltime = elapsedUnloadWalltime / timeDiv;
  double psWalltime = elapsedPlanSaveWalltime / timeDiv;
  double plWalltime = elapsedPlanLoadWalltime / timeDiv;
  double tWalltime = elapsedTotalWalltime / timeDiv;

  double cCputime = elapsedCompCputime / timeDiv;
  double eCputime = elapsedExecCputime / timeDiv;
  double lCputime = elapsedLoadCputime / timeDiv;
  double uCputime = elapsedUnloadCputime / timeDiv;
  double psCputime = elapsedPlanSaveCputime / timeDiv;
  double plCputime = elapsedPlanLoadCputime / timeDiv;
  double tCputime = elapsedTotalCputime / timeDiv;

  os << "Engine Startup Time     : " << elapsedInitWalltime
     << " (user: " << elapsedInitCputime << ")"
     << " milliseconds" << std::endl;

  os << "Average Compilation Time: " << cWalltime
     << " (user: " << cCputime << ")"
     << " milliseconds" << std::endl;

  if (serializePlan)
  {
    os << "Average Plan Saving Time: " << psWalltime
       << " (user: " << psCputime << ")"
       << " milliseconds" << std::endl;
    
    os << "Average Plan Loading Time: " << plWalltime
       << " (user: " << plCputime << ")"
       << " milliseconds" << std::endl;
  }

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
  bool serializePlan = properties.serializePlan();
  bool savePlan = properties.savePlan();
  bool loadPlan = properties.loadPlan();
  std::ostringstream lOut;
  Zorba_CompilerHints lHints;

  std::auto_ptr<std::fstream> planFile;
  std::fstream* planFilep = NULL;

  if (serializePlan)
  {
    if (savePlan || loadPlan)
    {
      std::cerr << "The --serialize-plan option cannot be used together with the --compile-plan or --execute-plan options" << std::endl;
      exit(1);
    }

    std::string planFilePath = qfilepath;
    planFilePath += ".plan";
    planFile.reset(new std::fstream(planFilePath.c_str(), 
                                    std::fstream::in | 
                                    std::fstream::out |
                                    std::fstream::trunc |
                                    std::fstream::binary));
    planFilep = planFile.get();
    assert(planFilep->good());
  }

  if (savePlan && loadPlan)
  {
    std::cerr << "The --compile-plan and --execute-plan options cannot be used together" << std::endl;
    exit(1);
  }

  // default is O1 in the Zorba_CompilerHints constructor
  if (properties.optimizationLevel() == "O0") 
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O0;
  }
  else if (properties.optimizationLevel() == "O2") 
  {
    lHints.opt_level = ZORBA_OPT_LEVEL_O2;
  }

  lHints.for_serialization_only = true;

#if ZORBACMD_LOAD_SYSTEM_PROPERTIES
  if (Properties::instance()->serializeOnlyQuery() == 0)
  {
    lHints.for_serialization_only = false;
  }
#endif

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
    // start the total timer
    if (doTiming)
      timing.startTimer(TimingInfo::TOTAL_TIMER, i);
    
    //
    // Compile the query
    // Compilation is done only once, unless timing is needed
    //
    if (doTiming || i == 0)
    {
      // go back to the beginning of the stream
      qfile.clear();
      qfile.seekg(0);
      assert (qfile.tellg() >= 0);

      try
      {
        // start the compilation timer
        if (doTiming)
          timing.startTimer(TimingInfo::COMP_TIMER, i);

        // Create and compile the query
        query = zorbaInstance->createQuery();
        query->registerDiagnosticHandler(&diagnosticHandler);
        query->setFileName(qfilepath);

        if (loadPlan) 
        {
          query->loadExecutionPlan(qfile, &theSerializationCallback);

          // stop the compilation timer
          if (doTiming)
            timing.stopTimer(TimingInfo::COMP_TIMER, i);
        }
        else
        {
          query->compile(qfile, staticContext, lHints);

          // stop the compilation timer
          if (doTiming)
            timing.stopTimer(TimingInfo::COMP_TIMER, i);

          // Serialize the execution plan, if requested
          if (serializePlan) 
          {
            planFilep->clear();
            planFilep->seekp(0);

            // start the plan-save timer
            if (doTiming)
              timing.startTimer(TimingInfo::PLAN_SAVE_TIMER, i);

            query->saveExecutionPlan(*planFilep, ZORBA_USE_BINARY_ARCHIVE);

            // stop the plan-save timer
            if (doTiming)
              timing.stopTimer(TimingInfo::PLAN_SAVE_TIMER, i);

            planFilep->flush();
          }
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
    } // if (doTiming || i == 0)

    //
    // Run the query, unless compileOnly has been requested.
    //
    if ( ! properties.compileOnly() && ! properties.libModule() )
    {
      try
      {
        // load the execution plan, if requested
        if (serializePlan) 
        {
          planFilep->seekg(0);
          assert(planFilep->good());
          
          // start the plan-load timer
          if (doTiming)
            timing.startTimer(TimingInfo::PLAN_LOAD_TIMER, i);

          query = zorbaInstance->createQuery();
          query->loadExecutionPlan(*planFilep, &theSerializationCallback);

          // stop the plan-load timer
          if (doTiming)
            timing.stopTimer(TimingInfo::PLAN_LOAD_TIMER, i);
        }

        // start the execution timer
        if (doTiming)
          timing.startTimer(TimingInfo::EXEC_TIMER, i);

        // Populate the dynamic context
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

        // run the query
        if (properties.noSerializer())
        {
          query->executeSAX();
        }
        else if (savePlan)
        {
          query->saveExecutionPlan(outputStream,
                                   ZORBA_USE_BINARY_ARCHIVE,
                                   SAVE_UNUSED_FUNCTIONS);
        }
        else
        {
          query->execute(outputStream, &lSerOptions);
        }

        if (properties.trailingNl()) 
          outputStream << std::endl;
 
        query->close();

         // stop the execution timer
        if (doTiming)
          timing.stopTimer(TimingInfo::EXEC_TIMER, i);

        if (i > 0 || lNumExecutions == 1) 
        {
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

    //
    // Delete all loaded docs from the store, if timing has been requested
    //
    if (doTiming)
    {
      XmlDataManager* store = zorbaInstance->getXmlDataManager();

      timing.startTimer(TimingInfo::UNLOAD_TIMER, i);

      DocumentManager* lMgr = store->getDocumentManager();
      ItemSequence_t lSeq = lMgr->availableDocuments();
      Iterator_t lIter = lSeq->getIterator();
      lIter->open();
      Item lURI;
      while (lIter->next(lURI)) 
      {
        lMgr->remove(lURI.getStringValue());
      }

      timing.stopTimer(TimingInfo::UNLOAD_TIMER, i);
    }

    // stop the total timer
    if (doTiming)
      timing.stopTimer(TimingInfo::TOTAL_TIMER, i);

#ifdef DO_AUDIT
    audit::Event* event = staticContext->getAuditEvent(); 
    std::cerr << *event << std::endl;
#endif
  } // for each execution

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
  ZorbaCMDProperties properties;
  if (!properties.loadProperties(argc, argv))
  {
    return 1;
  }

  TimingInfo engineTiming(properties.multiple());

  bool doTiming = properties.timing();
  bool debug = false;
#ifdef ZORBA_WITH_DEBUGGER
  debug = (properties.debug());
#endif

  // libModule assumes compileOnly even if compileOnly is false
  bool compileOnly = (properties.compileOnly() || properties.libModule() );

  // write to file or standard out
  std::auto_ptr<std::ostream> 
  lFileStream(properties.outputFile().size() > 0 ?
              new std::ofstream(properties.outputFile().c_str()) : 0);

  std::ostream* lOutputStream = lFileStream.get();
  if ( lOutputStream == 0 )
  {
    lOutputStream = &std::cout;
  }
  else if ( !lOutputStream->good() )
  {
    std::cerr << "could not write to output file {" << properties.outputFile()
              << "}" << std::endl;
    return 2;
  }

  if (properties.queriesOrFilesBegin() == properties.queriesOrFilesEnd())
  {
    std::cerr << "no queries submitted." << std::endl;
    properties.printHelp(std::cout);
    return 3;
  }

  // Add command line --classpath option in front of config/env CLASSPATH
  Properties* globaproperties = Properties::instance();
  std::string cmdJvmClassPath;
  properties.getJVMClassPath(cmdJvmClassPath);
  std::string configJvmClassPath;
  globaproperties->getJVMClassPath(configJvmClassPath);
  globaproperties->setJVMClassPath(cmdJvmClassPath +
      filesystem_path::get_path_separator() + configJvmClassPath);

  // Start the engine

  engineTiming.startTimer(TimingInfo::INIT_TIMER, 2);

  void* store = zorba::StoreManager::getStore();

  zorba::Zorba* lZorbaInstance = zorba::Zorba::getInstance(store);

#ifdef DO_AUDIT
  zorba::audit::Provider* lAuditProvider = lZorbaInstance->getAuditProvider();

  zorba::audit::Configuration* config = lAuditProvider->createConfiguration();

  std::vector<zorba::String> property_names;
  zorba::audit::Configuration::getPropertyNames(property_names);

  zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/parse-duration");

  zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/translation-duration");

  zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/optimization-duration");

  zorba::audit::Configuration::
  enableProperty(config, property_names, "xquery/compilation/codegeneration-duration");
#endif

  {
  engineTiming.stopTimer(TimingInfo::INIT_TIMER, 2);

  // For each query ...

  int queryNo;
  ZorbaCMDProperties::QueriesOrFiles_t::const_iterator lIter;
  for (queryNo = 1, lIter = properties.queriesOrFilesBegin();
       lIter != properties.queriesOrFilesEnd();
       ++queryNo, ++lIter)
  {
    //
    // Read the query (either from a file or given as parameter)
    //
    std::string fURI = *lIter;
    std::string fname = parseFileURI (properties.asFiles (), fURI);
    zorba::filesystem_path path (fname);
    bool asFile = ! fname.empty ();
    std::auto_ptr<std::istream> qfile;

    if (asFile)
    {
      path.resolve_relative ();
      qfile.reset(new std::ifstream (path.c_str ()));
    }
    else
    {
      qfile.reset(new std::istringstream(fURI));
    }

    if (asFile && (!qfile->good() || qfile->eof()))
    {
      std::cerr << "file {" << fname << "} not found or not readable." << std::endl;
      properties.printHelp(std::cout);
      return 3;
    }
    else if (fURI.empty ())
    {
      std::cerr << "empty query." << std::endl;
      properties.printHelp(std::cout);
      return 3;
    }

    //
    // Print the query if requested
    //
    if (properties.printQuery()) 
    {
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

    if (! populateStaticContext(lZorbaInstance, lStaticContext, properties) )
    {
      properties.printHelp(std::cout);
      return 3;
    }

#ifdef DO_AUDIT
    zorba::audit::Event* event = lAuditProvider->createEvent(config);
    lStaticContext->setAuditEvent(event);
#endif // DO_AUDIT

    if (!asFile && properties.baseUri().size() == 0 )
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
    if (properties.parseOnly()) 
    {
      try 
      {
        zorba::XQuery_t lQuery = lZorbaInstance->createQuery();
        if (asFile)
        {
          lQuery->setFileName(path.get_path());
        }

        lQuery->parse (*qfile);
      }
      catch (zorba::ZorbaException const& ze) 
      {
        std::cerr << ze << std::endl;
        return 6;
      }
    }

    // Compile and run it if necessary.
    // Print timing information if requested.
    else if (!debug) 
    {
      if (compileOnly) 
      {
        try 
        {
          zorba::XQuery_t aQuery = lZorbaInstance->createQuery();
          if (asFile) 
          {
            aQuery->setFileName(path.get_path());
          }

          aQuery->parse(*qfile);

          qfile->clear();
          qfile->seekg(0); // go back to the beginning
        }
        catch (zorba::XQueryException const& qe)
        {
          ErrorPrinter::print(qe,
                              std::cerr,
                              properties.printErrorsAsXml(),
                              properties.indent());
          return 6;
        }
      }

      TimingInfo queryTiming(properties.multiple());

      int status = compileAndExecute(lZorbaInstance,
                                     properties,
                                     lStaticContext,
                                     path.get_path(),
                                     *qfile,
                                     *lOutputStream,
                                     queryTiming);
      if (status != 0) 
      {
        // reset the file handler (in case output option was provided)
        // in order to delete the created output file
        lFileStream.reset();
        removeOutputFileIfNeeded(properties);
        return status;
      }

      if (doTiming) 
      {
        bool serializePlan = properties.serializePlan();
        queryTiming.print(std::cout, serializePlan);
      }
    }

#ifdef ZORBA_WITH_DEBUGGER
    // Debug the query. Do not allow "compileOnly" flags and inline queries
    else if (debug) 
    {
      if (compileOnly) 
      {
        std::cerr << "cannot debug a query if the compileOnly option is specified"
                  << std::endl;
        return 7;
      }

      if (!asFile) 
      {
        std::cerr << "Cannot debug inline queries." << std::endl;
        return 8;
      }

      std::auto_ptr<std::istream> lXQ(new std::ifstream(path.c_str()));
      std::string lFileName(path.get_path());

      zorba::XQuery_t lQuery;

      try 
      {
        lQuery = lZorbaInstance->createQuery();
        lQuery->setFileName(lFileName);
        lQuery->setDebugMode(true);

        Zorba_CompilerHints lHints;
        lHints.opt_level = ZORBA_OPT_LEVEL_O0;

        lQuery->compile(*lXQ.get(), lHints);
        zorba::DynamicContext* lDynamicContext = lQuery->getDynamicContext();
        if (!populateDynamicContext(lZorbaInstance, lDynamicContext, properties)) {
          return 9;
        }

        std::string lHost = properties.debugHost();
        if (lHost == "") {
          lHost = "127.0.0.1";
        }

        Zorba_SerializerOptions lSerOptions =
            Zorba_SerializerOptions::SerializerOptionsFromStringParams(
            properties.getSerializerParameters());
        createSerializerOptions(lSerOptions, properties);

        if (!properties.hasNoLogo()) 
        {
          std::cout << "Zorba XQuery Debugger Server\n" << copyright_str << std::endl;
        }

        lQuery->debug(*lOutputStream, lSerOptions, lHost, properties.getDebugPort());
      }
      catch (zorba::XQueryException const& qe)
      {
        ErrorPrinter::print(qe,
                            std::cerr,
                            properties.printErrorsAsXml(),
                            properties.indent());
        return 5;
      }
      catch (zorba::ZorbaException const& ze)
      {
        std::cerr << ze << std::endl;
        return 6;
      }
    } // else if (debug)
#endif

#ifdef DO_AUDIT
    lAuditProvider->submitEvent(event);
#endif

  } // for each query

  }

  if (doTiming)
  {
    engineTiming.startTimer(TimingInfo::DEINIT_TIMER, 2);
  }

#ifdef DO_AUDIT
  lAuditProvider->destroyConfiguration(config);
#endif

  lZorbaInstance->shutdown();
  zorba::StoreManager::shutdownStore(store);

  if (doTiming)
  {
    engineTiming.stopTimer(TimingInfo::DEINIT_TIMER, 2);

    std::cout << std::endl << "Engine Shutdown Time     : "
              << engineTiming.elapsedDeinitWalltime
              << " (user: " << engineTiming.elapsedDeinitCputime << ")"
              << " milliseconds" << std::endl;
  }
  return 0;
}
