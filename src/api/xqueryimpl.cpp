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
#include "stdafx.h"

#include "api/xqueryimpl.h"

#include <vector>
#include <sstream>
#include <algorithm>
#include "zorbatypes/schema_types.h"

#include <zorba/diagnostic_handler.h>
#include <zorba/error.h>
#include <zorba/diagnostic_list.h>
#include <zorba/sax2.h>
#include <zorba/audit_scoped.h>

#include <zorbatypes/URI.h>

#include "diagnostics/xquery_diagnostics.h"
#include "zorbatypes/zstring.h"
#include "zorbautils/lock.h"

#include "system/globalenv.h"

#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/unmarshaller.h"
#include "api/serialization/serializer.h"
#include "api/serialization/serializable.h"
#include "api/zorbaimpl.h"
#include "api/serializerimpl.h"
#include "api/auditimpl.h"
#include "api/staticcollectionmanagerimpl.h"
#include "api/vectoriterator.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "types/root_typemanager.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "compiler/expression/var_expr.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/util/flowctl_exception.h"

#include "store/api/temp_seq.h"
#include "store/api/item.h"
#include "store/api/store.h"
#include "store/api/item_factory.h"

//#include "zorbaserialization/xml_archiver.h"
#include "zorbaserialization/bin_archiver.h"
#include "zorbaserialization/class_serializer.h"
#include "zorbaserialization/serialize_zorba_types.h"

#ifdef ZORBA_WITH_DEBUGGER
#include "debugger/debugger_server.h"
#include "debugger/debugger_commons.h"
#endif

namespace zorba
{


#define QUERY_CATCH                                                 \
  catch (ZorbaException const& e)                                   \
  {                                                                 \
    ZorbaImpl::notifyError(theDiagnosticHandler, e);                \
  }                                                                 \
  catch (FlowCtlException&)                                         \
  {                                                                 \
    ZorbaImpl::notifyError(theDiagnosticHandler, "User interrupt"); \
  }                                                                 \
  catch (std::exception const& e)                                   \
  {                                                                 \
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());         \
  }                                                                 \
  catch (...)                                                       \
  {                                                                 \
    ZorbaImpl::notifyError(theDiagnosticHandler);                   \
  }                                                                 \
                                                                    \
  notifyAllWarnings();


SERIALIZABLE_CLASS_VERSIONS_2(XQueryImpl::PlanProxy, TYPE_PLAN_PROXY)

SERIALIZABLE_CLASS_VERSIONS(XQueryImpl)

XQueryImpl::XQueryImpl(::zorba::serialization::Archiver& ar)
  :
  ::zorba::serialization::SerializeBaseClass(),
  theCollMgr(0)
{
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::PlanProxy::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theRootIter;
}


/*******************************************************************************

********************************************************************************/
XQueryImpl::PlanProxy::PlanProxy(PlanIter_t& root)
  :
  theRootIter(root.getp())
{
}


/*******************************************************************************

********************************************************************************/
XQueryImpl::XQueryImpl()
  :
  theStaticContext(0),
  theStaticContextWrapper(0),
  theDynamicContext(0),
  theDynamicContextWrapper(0),
  theResultIterator(NULL),
  theExecuting(false),
  theIsClosed(false),
  theUserDiagnosticHandler(false),
  theSAX2Handler(0),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0.0),
#ifdef ZORBA_WITH_DEBUGGER
  theIsDebugMode(false),
#endif
  theProfileName("xquery_profile.out"),
  theCollMgr(0)
{
  // TODO ideally, we will have to move the error handler into the error manager
  //      however, this is not possible yet because not all components of the system
  //      have a control block available.
  //      That is also the reason why we need static function in the error manager
  //      those should also go away and errors should be fired from the error manager
  //      into the error handler
  theDiagnosticHandler = new DiagnosticHandler();
  theXQueryDiagnostics = new XQueryDiagnostics();

  theCompilerCB = new CompilerCB(theXQueryDiagnostics);

  theDynamicContext = new dynamic_context();
}


/*******************************************************************************

********************************************************************************/
XQueryImpl::~XQueryImpl()
{
  close();
}

/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::serialize(::zorba::serialization::Archiver& ar)
{
  // static stuff
  ar & theFileName;

  if (!ar.is_serializing_out())
  {
    delete theCompilerCB;
    theCompilerCB = NULL;
  }
  else
  {
    ar.set_ccb(theCompilerCB);
  }

  ar & theCompilerCB;
  ar & thePlanProxy;
  ar & theStaticContext;

  if (!ar.is_serializing_out())
  {
    theDynamicContextWrapper = NULL;
    theStaticContextWrapper = NULL;

    theResultIterator = NULL;

    theExecuting = false;
    theIsClosed = false;

    theCompilerCB->theXQueryDiagnostics = theXQueryDiagnostics;
  }

#ifdef ZORBA_WITH_DEBUGGER
  ar & theIsDebugMode;
#endif
}


/*******************************************************************************
  Set the filename
********************************************************************************/
void XQueryImpl::setFileName(const String& aFileName)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  theFileName = Unmarshaller::getInternalString(aFileName);
}


/*******************************************************************************
  Get the filename
********************************************************************************/
String XQueryImpl::getFileName()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  return Unmarshaller::newString(theFileName);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setTimeout(long aTimeout /* = -1 */)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  theCompilerCB->theTimeout = aTimeout;
}


/*******************************************************************************

********************************************************************************/
double XQueryImpl::getDocLoadingUserTime() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  return theDocLoadingUserTime;
}


double XQueryImpl::getDocLoadingTime() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  return theDocLoadingTime;
}


#ifdef ZORBA_WITH_DEBUGGER
/*******************************************************************************

********************************************************************************/
void XQueryImpl::setDebugMode( bool aDebugMode )
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  //check if the query is not compiled already
  checkNotCompiled();
  theIsDebugMode = aDebugMode;
}


bool XQueryImpl::isDebugMode() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  return theIsDebugMode;
}
#endif


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setProfileName(std::string aProfileName)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

#ifdef ZORBA_WITH_DEBUGGER
  checkIsDebugMode();
#endif
  theProfileName = aProfileName;
}


std::string XQueryImpl::getProfileName() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  return theProfileName;
}


/*******************************************************************************
  Make the given user-provided error handler the error handler of this query
********************************************************************************/
void XQueryImpl::registerDiagnosticHandler(DiagnosticHandler* aDiagnosticHandler)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotExecuting();

    assert(theDiagnosticHandler);
    if ( ! theUserDiagnosticHandler )
    {
      delete theDiagnosticHandler;
    }

    theDiagnosticHandler = aDiagnosticHandler;
    theUserDiagnosticHandler = true;

    if (theCollMgr) 
    {
      theCollMgr->registerDiagnosticHandler(theDiagnosticHandler);
    }
  }
  QUERY_CATCH
}


/*******************************************************************************
  Returns NULL if no user DiagnosticHandler is registered
********************************************************************************/
DiagnosticHandler* XQueryImpl::getRegisteredDiagnosticHandler()
{
  DiagnosticHandler* result = NULL;

  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();

    if (theUserDiagnosticHandler)
      result = theDiagnosticHandler;
  }
  QUERY_CATCH
  return result;
}


/*******************************************************************************
  Returns NULL if no user DiagnosticHandler is registered
********************************************************************************/
DiagnosticHandler* XQueryImpl::getRegisteredDiagnosticHandlerNoSync()
{
  DiagnosticHandler* result = NULL;

  try
  {
    checkNotClosed();

    if (theUserDiagnosticHandler)
      result = theDiagnosticHandler;
  }
  QUERY_CATCH
  return result;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::resetDiagnosticHandler()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotExecuting();

    assert (theDiagnosticHandler);

    if ( ! theUserDiagnosticHandler )
      return;

    theDiagnosticHandler = new DiagnosticHandler();
    theUserDiagnosticHandler = false;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::compile(const String& aQuery)
{
  Zorba_CompilerHints_t lHints;
  return compile(aQuery, lHints);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::compile(const String& aQuery, const Zorba_CompilerHints_t& aHints)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    std::istringstream lQueryStream(aQuery.c_str());

    // 0 is reserved as an invalid var id, and 1 is taken by the context item
    // in the main module.
    ulong nextVarId = 2;

    doCompile(lQueryStream, aHints, true, nextVarId);
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::compile(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    // 0 is reserved as an invalid var id, and 1 is taken by the context item
    // in the main module.
    ulong nextVarId = 2;

    doCompile(aQuery, aHints, true, nextVarId);
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::compile(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    // Note: unless this is a load-prolog query, the doCompile method invoked
    // below will create a child sctx and set theStaticContext to that child.

    // If the static context results from loadProlog, we need all the contexts
    // that were created when compiling the load-prolog query
    theCompilerCB->theSctxMap =
    static_cast<StaticContextImpl*>(aStaticContext.get())->theSctxMap;

    ulong nextVarId = 
    static_cast<StaticContextImpl*>(aStaticContext.get())->getMaxVarId();

    std::istringstream lQueryStream(aQuery.c_str());

    doCompile(lQueryStream, aHints, true, nextVarId);
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::compile(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    // if the static context results from loadProlog, we need all the context
    // that were created when compiling the load-prolog query
    theCompilerCB->theSctxMap =
    static_cast<StaticContextImpl*>(aStaticContext.get())->theSctxMap;

    ulong nextVarId = 
    static_cast<StaticContextImpl*>(aStaticContext.get())->getMaxVarId();

    doCompile(aQuery, aHints, true, nextVarId);
  }
  QUERY_CATCH
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::doCompile(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints,
    bool fork_sctx,
    ulong& nextDynamicVarId)
{
  if ( ! theStaticContext )
  {
    // no context given => use the default one (i.e. a child of the root static context)
    theStaticContext = GENV.getRootStaticContext().create_child_context();

    theStaticContext->set_typemanager(new TypeManagerImpl(&GENV_TYPESYSTEM));
  }
  else
  {
    if (theStaticContext->get_local_typemanager() == NULL)
      theStaticContext->set_typemanager(new TypeManagerImpl(&GENV_TYPESYSTEM));

    // otherwise, unless this is a load-prolog query, create a child and we have
    // ownership over that one
    if (fork_sctx)
    {
      theStaticContext = theStaticContext->create_child_context();
    }
  }

  zstring url;
  URI::encode_file_URI(theFileName, url);

  theStaticContext->set_entity_retrieval_uri(url);

  theCompilerCB->theRootSctx = theStaticContext;
  int sctxid = (int)theCompilerCB->theSctxMap.size() + 1;
  (theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

  // Set the compiler config.
  // If lib_module is set to true the query will be considered a library module
  theCompilerCB->theConfig.lib_module = aHints.lib_module;
  theCompilerCB->theConfig.for_serialization_only = aHints.for_serialization_only;
  CompilerCB::config::opt_level_t optLevel;
  if (aHints.opt_level == ZORBA_OPT_LEVEL_O0)
    optLevel = CompilerCB::config::O0;
  else if (aHints.opt_level == ZORBA_OPT_LEVEL_O2)
    optLevel = CompilerCB::config::O2;
  else
    optLevel = CompilerCB::config::O1;
  theCompilerCB->theConfig.opt_level = optLevel;

  XQueryCompiler lCompiler(theCompilerCB);

#ifdef ZORBA_WITH_DEBUGGER
  // if the debug mode is set, we force the gflwor, we set the query input stream
  if (theIsDebugMode) 
  {
    theCompilerCB->theConfig.force_gflwor = true;
    theCompilerCB->theDebuggerCommons = new DebuggerCommons(theCompilerCB->theRootSctx);
    theCompilerCB->theConfig.opt_level = CompilerCB::config::O0;
  }
#endif

  PlanIter_t planRoot = lCompiler.compile(aQuery, theFileName, nextDynamicVarId);

  thePlanProxy = new PlanProxy(planRoot);
}


/*******************************************************************************
  This method is not part of the XQuery public API. Instead it is invoked from
  the StaticContextImpl::loadProlog() method, which is also the one that creates
  "this" XQuery obj.
********************************************************************************/
void XQueryImpl::loadProlog(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    zstring lQuery = Unmarshaller::getInternalString(aQuery);
    lQuery += "()";
    std::istringstream lQueryStream(lQuery.c_str());

    theCompilerCB->setLoadPrologQuery();

    StaticContextImpl* sctx = static_cast<StaticContextImpl*>(aStaticContext.get());

    ulong nextVarId = sctx->getMaxVarId();

    doCompile(lQueryStream, aHints, false, nextVarId);

    sctx->setMaxVarId(nextVarId);
  }
  QUERY_CATCH
}


/*******************************************************************************
  Parse a query.
********************************************************************************/
void XQueryImpl::parse(std::istream& aQuery)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    if ( ! theStaticContext )
    {
      // no context given => use the default one (i.e. a child of the root sctx)
      theStaticContext = GENV.getRootStaticContext().create_child_context();
    }
    else
    {
      // otherwise create a child and we have ownership over that one
      theStaticContext = theStaticContext->create_child_context();
    }

    zstring url;
    URI::encode_file_URI(theFileName, url);

    theStaticContext->set_entity_retrieval_uri(url);

    theCompilerCB->theRootSctx = theStaticContext;

    XQueryCompiler lCompiler(theCompilerCB);
    lCompiler.parseOnly(aQuery, theFileName);
  }
  QUERY_CATCH
}


/*******************************************************************************
  A clone query shares its error handler and plan iterator tree with the original
  query. The static and dynamic context of a clone query is a child of a static
  and dynamic context of the orginal query.
********************************************************************************/
XQuery_t XQueryImpl::clone() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    XQuery_t lXQuery(new XQueryImpl());

    XQueryImpl* clone = static_cast<XQueryImpl*>(lXQuery.get());

    clone->theFileName = theFileName;

    if (theUserDiagnosticHandler)
      clone->registerDiagnosticHandler(theDiagnosticHandler);

    clone->theStaticContext = theStaticContext->create_child_context();
    clone->theCompilerCB->theRootSctx = clone->theStaticContext;
    clone->theCompilerCB->theSctxMap = theCompilerCB->theSctxMap;

    int sctxid = (int)clone->theCompilerCB->theSctxMap.size() + 1;
    (clone->theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

    clone->thePlanProxy = thePlanProxy;

    return lXQuery;
  }
  QUERY_CATCH
  return XQuery_t();
}


/*******************************************************************************

********************************************************************************/
StaticCollectionManager*
XQueryImpl::getStaticCollectionManager() const
{
  checkNotClosed();
  checkCompiled();

  if (!theCollMgr) 
  {
    std::vector<StaticCollectionManagerImpl*> lMgrs;

    Zorba* lZorba = Zorba::getInstance(0);
    ItemFactory* lFactory = lZorba->getItemFactory();

    for (CompilerCB::SctxMap::iterator lIter = theCompilerCB->theSctxMap.begin();
        lIter != theCompilerCB->theSctxMap.end();
         ++lIter) 
    {
      // this object is only need to construct the StaticCollectionManagerImpl
      // but it's not used after the construction anymore
      std::auto_ptr<StaticContextImpl> lCtx(
      new StaticContextImpl(lIter->second.getp(), theDiagnosticHandler));

      lMgrs.push_back(new StaticCollectionManagerImpl(lCtx.get(),
                                                      lFactory,
                                                      theDiagnosticHandler));
    }
    // transfer ownership over all managers to the set
    theCollMgr = new StaticCollectionManagerSetImpl(lMgrs);
  }
  return theCollMgr;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::getExternalVariables(Iterator_t& aVarsIter) const
{
  try
  {
    checkNotClosed();
    checkCompiled();

    std::vector<var_expr_t> lVars;

    CompilerCB::SctxMap::const_iterator lIte = theCompilerCB->theSctxMap.begin();
    CompilerCB::SctxMap::const_iterator lEnd = theCompilerCB->theSctxMap.end();

    for(; lIte != lEnd; ++lIte)
    {
      lIte->second.getp()->getVariables(lVars, false, false, true);
    }
    
    std::vector<var_expr_t>::const_iterator lVarIte = lVars.begin();
    std::vector<var_expr_t>::const_iterator lVarEnd = lVars.end();
    std::vector<store::Item_t> lExVars;
   
    for(; lVarIte != lVarEnd; ++lVarIte)
    { 
      lExVars.push_back((*lVarIte)->get_name());
    } 

   Iterator_t vIter = new VectorIterator(lExVars, theDiagnosticHandler);

    aVarsIter = vIter; 
    
  }
  QUERY_CATCH
}

/*******************************************************************************

********************************************************************************/
bool XQueryImpl::isBoundVariable(
    const String& aNamespace,
    const String& aLocalname) const
{
  try
  {
    checkNotClosed();
    checkCompiled();

    var_expr* var = NULL;

    zstring& nameSpace = Unmarshaller::getInternalString(aNamespace);
    zstring& localName = Unmarshaller::getInternalString(aLocalname);
    
    store::Item_t qname;
    GENV_ITEMFACTORY->createQName(qname, nameSpace, zstring(), localName);
    
    CompilerCB::SctxMap& lMap = theCompilerCB->theSctxMap;
    CompilerCB::SctxMap::const_iterator lIte = lMap.begin();
    CompilerCB::SctxMap::const_iterator lEnd = lMap.end();

    for (; lIte != lEnd; ++lIte)
    {
      var = lIte->second->lookup_var(qname, QueryLoc::null, zerr::ZXQP0000_NO_ERROR);
      
      if(var)
        break;
    }
    
    if(var == NULL)
      throw XQUERY_EXCEPTION(zerr::ZAPI0011_ELEMENT_NOT_DECLARED,
      ERROR_PARAMS(BUILD_STRING('{', qname->getNamespace(), '}', qname->getLocalName()), ZED(Variable)));

    if (var->hasInitializer())
      return true;
    
    ulong varId = var->get_unique_id();

    if (theDynamicContext->is_set_variable(varId))
      return true;

    return false;
  }
  QUERY_CATCH
  return true;
}


/*******************************************************************************
  Give to the caller read-only access to the static context of the query
********************************************************************************/
const StaticContext* XQueryImpl::getStaticContext() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    if (!theStaticContextWrapper)
      theStaticContextWrapper = new StaticContextImpl(theStaticContext.getp(),
                                                      theDiagnosticHandler);

    return theStaticContextWrapper;
  }
  QUERY_CATCH
  return 0;
}


/*******************************************************************************
  Return true, iff the root expr of the query is an updating expr.
********************************************************************************/
bool XQueryImpl::isUpdating() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    return theCompilerCB->isUpdating();
  }
  QUERY_CATCH
  return false;
}


/*******************************************************************************
 Return true, if the root expr of the query is a sequential expr.
********************************************************************************/
bool XQueryImpl::isSequential() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    return theCompilerCB->isSequential();
  }
  QUERY_CATCH
  return false;
}


/*******************************************************************************
  Serialize the execution plan into the given output stream.
********************************************************************************/
bool XQueryImpl::saveExecutionPlan(
    std::ostream& os,
    Zorba_binary_plan_format_t archive_format,
    Zorba_save_plan_options_t save_options)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    if (archive_format == ZORBA_USE_XML_ARCHIVE)
    {
      ZORBA_ASSERT(false);
    /*
      zorba::serialization::XmlArchiver xmlar(&os);

      if ((save_options & 0x01) != DONT_SAVE_UNUSED_FUNCTIONS)
        xmlar.set_serialize_everything();

      serialize(xmlar);
      xmlar.serialize_out();
    */
    }
    else//ZORBA_USE_BINARY_ARCHIVE
    {
      zorba::serialization::BinArchiver bin_ar(&os);

      if ((save_options & 0x01) != DONT_SAVE_UNUSED_FUNCTIONS)
        bin_ar.set_serialize_everything();

      serialize(bin_ar);
      bin_ar.serialize_out();
    }

    return true;
  }
  catch (ZorbaException const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e);
  }
  catch (FlowCtlException const&)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, "User interrupt");
  }
  catch (std::exception const& e)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());
  }
  catch (...)
  {
    ZorbaImpl::notifyError(theDiagnosticHandler);
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool XQueryImpl::loadExecutionPlan(std::istream& is, SerializationCallback* aCallback)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotCompiled();

    try
    {
      // try the binary format first
      zorba::serialization::BinArchiver bin_ar(&is);
      bin_ar.setUserCallback(aCallback);
      serialize(bin_ar);
      bin_ar.finalize_input_serialization();
      return true;
    }
    catch(ZorbaException const &ex)
    {
      if ( ex.diagnostic() != zerr::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE )
        throw;
      //else go try xml archive reader
    }

#if 0
    is.seekg(0);

    zorba::serialization::XmlArchiver xmlar(&is);
    xmlar.setUserCallback(aCallback);
    serialize(xmlar);
    xmlar.finalize_input_serialization();
    return true;
#endif
  }
  QUERY_CATCH
  return false;
}


/*******************************************************************************
  Note: this method is allowed to be called while the query is executing.
  This is required to invoke external function that need access to the dynamic
  context.
********************************************************************************/
DynamicContext* XQueryImpl::getDynamicContext() const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    if (!theDynamicContextWrapper)
      theDynamicContextWrapper = new DynamicContextImpl(this);

    return theDynamicContextWrapper;
  }
  QUERY_CATCH
  return 0;
}


/*******************************************************************************
  Set the SAX handler
********************************************************************************/
void XQueryImpl::registerSAXHandler(SAX2_ContentHandler * aSAXHandler)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  theSAX2Handler = aSAXHandler;
}


/*******************************************************************************
  Execute the query with the given SAX handler
********************************************************************************/
void XQueryImpl::executeSAX(SAX2_ContentHandler * aSAXHandler)
{
  registerSAXHandler(aSAXHandler);
  executeSAX();
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::executeSAX()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    if (theCompilerCB->isUpdating())
    {
      throw ZORBA_EXCEPTION( zerr::ZAPI0007_CANNOT_SERIALIZE_PUL );
    }

    theExecuting = true;

    serializer lSerializer(theXQueryDiagnostics);
    Zorba_SerializerOptions_t opt;
    SerializerImpl::setSerializationParameters(lSerializer, opt);

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    PlanWrapper_t lPlan = generateWrapper();

    try
    {
      lPlan->open();

      if (theSAX2Handler != NULL)
      {
        lSerializer.serialize(lPlan.getp(), std::cerr, theSAX2Handler);
        std::cerr << std::endl;
      }
      else
      {
        store::Item_t item;
        while (lPlan->next(item)){};
      }
    }
    catch (...)
    {
      lPlan->close();
      theExecuting = false;
      throw;
    }

    lPlan->close();
    theExecuting = false;

    theDocLoadingUserTime = theDynamicContext->theDocLoadingUserTime;
    theDocLoadingTime = theDynamicContext->theDocLoadingTime;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::execute(
    std::ostream& os,
    const Zorba_SerializerOptions_t* opt)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    theExecuting = true;

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    PlanWrapper_t lPlan = generateWrapper();

    try
    {
      lPlan->open();

      serialize(os, lPlan, opt);
    }
    catch (...)
    {
      lPlan->close();
      theExecuting = false;
      throw;
    }

    lPlan->close();
    theExecuting = false;

    theDocLoadingUserTime = theDynamicContext->theDocLoadingUserTime;
    theDocLoadingTime = theDynamicContext->theDocLoadingTime;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::execute(
    std::ostream& aOutStream,
    itemHandler aCallbackFunction,
    void* aCallbackData,
    const Zorba_SerializerOptions_t* aSerOptions /*= NULL*/)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    theExecuting = true;

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    PlanWrapper_t lPlan = generateWrapper();

    try
    {
      lPlan->open();

      serialize(aOutStream, lPlan, aCallbackFunction, aCallbackData, aSerOptions);
    }
    catch (...)
    {
      lPlan->close();
      theExecuting = false;
      throw;
    }

    lPlan->close();
    theExecuting = false;

    theDocLoadingUserTime = theDynamicContext->theDocLoadingUserTime;
    theDocLoadingTime = theDynamicContext->theDocLoadingTime;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::execute()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    if (!theCompilerCB->isUpdating())
      throw ZORBA_EXCEPTION( zerr::ZAPI0008_NOT_AN_UPDATE_XQUERY );

    theExecuting = true;

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

    PlanWrapper_t lPlan = generateWrapper();

    try
    {
      // call next once in order to apply updates
      lPlan->open();

      store::Item_t lItem;
      bool more = lPlan->next(lItem);
      assert(more == false);
      (void)more; // to avoid compiler warning in release mode
    }
    catch (...)
    {
      lPlan->close();
      theExecuting = false;
      throw;
    }

    lPlan->close();
    theExecuting = false;

    theDocLoadingUserTime = theDynamicContext->theDocLoadingUserTime;
    theDocLoadingTime = theDynamicContext->theDocLoadingTime;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
Iterator_t XQueryImpl::iterator()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    if (theResultIterator)
      throw ZORBA_EXCEPTION(zerr::ZAPI0039_XQUERY_HAS_ITERATOR_ALREADY);

    PlanWrapper_t lPlan = generateWrapper();

    theResultIterator = new ResultIteratorImpl(this, lPlan);
    return Iterator_t(theResultIterator);
  }
  QUERY_CATCH
  return Iterator_t();
}


/*******************************************************************************
  Called only from ~ResultIteratorImpl()
********************************************************************************/
void XQueryImpl::removeResultIterator(const ResultIteratorImpl* iter)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  assert(theResultIterator == iter);

  try
  {
    theResultIterator = NULL;
    theExecuting = false;
  }
  QUERY_CATCH
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::serialize(
    std::ostream& os,
    PlanWrapper_t& aWrapper,
    const Zorba_SerializerOptions_t* opt)
{
  serializer lSerializer(theXQueryDiagnostics);

  if (opt != NULL)
  {
    const Zorba_SerializerOptions_t lOptions = *opt;
    SerializerImpl::setSerializationParameters(lSerializer, lOptions);
  }

  lSerializer.serialize(aWrapper.getp(), os);
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::serialize(
    std::ostream& os,
    PlanWrapper_t& aWrapper,
    itemHandler aHandler,
    void* aHandlerData,
    const Zorba_SerializerOptions_t* opt /*= NULL*/)
{
  serializer lSerializer(theXQueryDiagnostics);

  if (opt != NULL)
  {
    const Zorba_SerializerOptions_t lOptions = *opt;
    SerializerImpl::setSerializationParameters(lSerializer, lOptions);
  }

  lSerializer.serialize(aWrapper.getp(),
                        os, aHandler, aHandlerData);
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
PlanWrapper_t XQueryImpl::generateWrapper()
{
  theDynamicContext->reset_current_date_time();

  PlanWrapper_t lPlan = new PlanWrapper(
      static_cast<PlanIterator*>(thePlanProxy->theRootIter.getp()),
      theCompilerCB,
      theDynamicContext,
      this,
      0, // stack depth
      theCompilerCB->theHaveTimeout,
      theCompilerCB->theTimeout);

  return lPlan;
}


#ifdef ZORBA_WITH_DEBUGGER
/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(const std::string& aHost, unsigned short aPort)
{
  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  debug(std::cout, lSerOptions, aHost, aPort);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(
  std::ostream& aOutStream,
  Zorba_SerializerOptions& aSerOptions,
  const std::string& aHost,
  unsigned short aPort)
{
  debug(aOutStream, 0, 0, aSerOptions, aHost, aPort);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(
    std::ostream& aOutStream,
    itemHandler aCallbackFunction,
    void* aCallbackData,
    Zorba_SerializerOptions& aSerOptions,
    const std::string& aHost,
    unsigned short aPort)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    //check if the query is compiled and not closed
    checkCompiled();
    checkNotClosed();
    checkNotExecuting();

    //check if the debug mode is enabled
    checkIsDebugMode();

    SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

    theExecuting = true;

    DebuggerServer aDebuggerServer(this,
                                   aSerOptions,
                                   aOutStream,
                                   aCallbackFunction,
                                   aCallbackData,
                                   aHost,
                                   aPort);
    if (!aDebuggerServer.run()) 
    {
      aDebuggerServer.throwError();
    }

    theExecuting = false;
  }
  QUERY_CATCH
}
#endif


/*******************************************************************************
  May be called explicitly by the application or from ~XQueryImpl().
********************************************************************************/
void XQueryImpl::close()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try 
  {
    if (theIsClosed) 
    {
      return;
    }

    if (theResultIterator != NULL) 
    {
      theResultIterator->closeInternal();
      theResultIterator = NULL;
    }

    theExecuting = false;

    if (thePlanProxy) 
    {
      thePlanProxy = NULL;
    }

    delete theXQueryDiagnostics;
    theXQueryDiagnostics = NULL;

    // see registerDiagnosticHandler
    if (!theUserDiagnosticHandler) 
    {
      delete theDiagnosticHandler;
      theDiagnosticHandler = NULL;
    }

    delete theDynamicContext;

    delete theDynamicContextWrapper;

    delete theStaticContextWrapper;

    theStaticContext = NULL;

    // theCompilerCB may be NULL if an error occured while serializing "this" in.
    if (theCompilerCB) 
    {
#ifdef ZORBA_WITH_DEBUGGER
      delete theCompilerCB->theDebuggerCommons;
#endif
      delete theCompilerCB;
    }

    delete theCollMgr;

    theIsClosed = true;
  }
  QUERY_CATCH
}


#ifdef ZORBA_WITH_DEBUGGER
/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkIsDebugMode() const
{
  if (!theIsDebugMode) 
  {
    throw ZORBA_EXCEPTION( zerr::ZAPI0009_XQUERY_NOT_COMPILED_IN_DEBUG_MODE );
  }
}
#endif


/*******************************************************************************
  check whether the query is open, and if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotClosed() const
{
  if (theIsClosed)
    throw ZORBA_EXCEPTION( zerr::ZAPI0006_XQUERY_ALREADY_CLOSED );
}


/*******************************************************************************
  Check whether the query has been compiled successfully; if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkCompiled() const
{
  if ( ! thePlanProxy )
    throw ZORBA_EXCEPTION( zerr::ZAPI0003_XQUERY_NOT_COMPILED );
}


/*******************************************************************************
  Check whether the query has not been compiled, and if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotCompiled() const
{
  if ( thePlanProxy )
    throw ZORBA_EXCEPTION( zerr::ZAPI0004_XQUERY_ALREADY_COMPILED );
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotExecuting() const
{
  if ( theExecuting )
    throw ZORBA_EXCEPTION( zerr::ZAPI0005_XQUERY_ALREADY_EXECUTING );
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::printPlan(std::ostream& aStream, bool aDotFormat) const
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkCompiled();

    std::auto_ptr<IterPrinter> lPrinter;
    if (aDotFormat)
      lPrinter.reset(new DOTIterPrinter(aStream));
    else
      lPrinter.reset(new XMLIterPrinter(aStream));
    print_iter_plan(*(lPrinter.get()),
                    static_cast<PlanIterator*>(thePlanProxy->theRootIter.getp()));
  }
  QUERY_CATCH
}

/*******************************************************************************

********************************************************************************/
void XQueryImpl::notifyAllWarnings() const
{
  if (theDiagnosticHandler == NULL || theXQueryDiagnostics == NULL)
    return;

  XQueryDiagnostics::warnings_type warnings = theXQueryDiagnostics->warnings();
  for (unsigned int i = 0; i<warnings.size(); i++)
  {
    if ( theStaticContext->isWarningAnError(
          warnings[i]->diagnostic().qname().ns(),
          warnings[i]->diagnostic().qname().localname()) )
    {
      ZorbaImpl::notifyError(theDiagnosticHandler, *warnings[i]);
    }
    else if ( ! theStaticContext->isWarningDisabled(
                  warnings[i]->diagnostic().qname().ns(),
                  warnings[i]->diagnostic().qname().localname()))
    {
      ZorbaImpl::notifyWarning(theDiagnosticHandler, *warnings[i]);
    }
  }

  // Warnings should be notified only once
  theXQueryDiagnostics->clear_warnings();
}

/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, const XQuery_t& aQuery)
{
  aQuery->execute(os);
  return os;
}


/*******************************************************************************

********************************************************************************/
std::ostream& operator<<(std::ostream& os, XQuery* aQuery)
{
  XQueryImpl* lQuery = dynamic_cast<XQueryImpl*>(aQuery);
  ZORBA_ASSERT (lQuery != NULL);
  lQuery->execute(os);
  return os;
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
