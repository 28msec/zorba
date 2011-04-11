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
#include "api/xqueryimpl.h"

#include <vector>
#include <sstream>
#include <algorithm>
#include "zorbatypes/representations.h"

#include <zorba/default_error_handler.h>
#include <zorba/error.h>
#include <zorba/error_list.h>
#include <zorba/sax2.h>

#include <zorbatypes/URI.h>

#include "zorbaerrors/error_manager.h"
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

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "types/root_typemanager.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"

#include "runtime/base/plan_iterator.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/visitors/printer_visitor_api.h"
#include "runtime/util/flowctl_exception.h"

#include "store/api/item.h"
#include "store/api/store.h"

#include "zorbaserialization/xml_archiver.h"
#include "zorbaserialization/bin_archiver.h"
#include "zorbaserialization/class_serializer.h"

#include "debugger/debugger_server.h"
#include "debugger/debugger_commons.h"

namespace zorba
{


#define QUERY_CATCH                                            \
  catch (ZorbaException const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler, e);                \
  }                                                            \
  catch (FlowCtlException&)                                    \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler, "User interrupt"); \
  }                                                            \
  catch (std::exception const& e)                              \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler, e.what());         \
  }                                                            \
  catch (...)                                                  \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler);                   \
  }           


SERIALIZABLE_CLASS_VERSIONS(XQueryImpl::PlanProxy)
END_SERIALIZABLE_CLASS_VERSIONS(XQueryImpl::PlanProxy)

SERIALIZABLE_CLASS_VERSIONS(XQueryImpl)
END_SERIALIZABLE_CLASS_VERSIONS(XQueryImpl)


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
  theUserErrorHandler(false),
  theSAX2Handler(0),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0.0),
  theIsDebugMode(false),
  theProfileName("xquery_profile.out")
{
  // TODO ideally, we will have to move the error handler into the error manager
  //      however, this is not possible yet because not all components of the system
  //      have a control block available.
  //      That is also the reason why we need static function in the error manager
  //      those should also go away and errors should be fired from the error manager
  //      into the error handler
  theErrorHandler = new DefaultErrorHandler();
  theErrorManager = new ErrorManager();

  theCompilerCB = new CompilerCB(theErrorManager);

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
    ar.compiler_cb = theCompilerCB;
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

    theCompilerCB->theErrorManager = theErrorManager;
  }
  
  ar & theIsDebugMode;
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


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setProfileName(std::string aProfileName)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  checkIsDebugMode();
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
void XQueryImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotExecuting();

    assert(theErrorHandler);
    if ( ! theUserErrorHandler )
    {
      delete theErrorHandler;
    }

    theErrorHandler = aErrorHandler;
    theUserErrorHandler = true;
  }
  QUERY_CATCH
}


/*******************************************************************************
  Returns NULL if no user ErrorHandler is registered
********************************************************************************/
ErrorHandler* XQueryImpl::getRegisteredErrorHandler()
{
  ErrorHandler* result = NULL;

  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();

    if (theUserErrorHandler)
      result = theErrorHandler;
  }
  QUERY_CATCH
  return result;
}


/*******************************************************************************
  Returns NULL if no user ErrorHandler is registered
********************************************************************************/
ErrorHandler* XQueryImpl::getRegisteredErrorHandlerNoSync()
{
  ErrorHandler* result = NULL;

  try
  {
    checkNotClosed();

    if (theUserErrorHandler)
      result = theErrorHandler;
  }
  QUERY_CATCH
  return result;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::resetErrorHandler()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    checkNotClosed();
    checkNotExecuting();

    assert (theErrorHandler);

    if ( ! theUserErrorHandler )
      return;

    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;
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

    doCompile(lQueryStream, aHints);
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

    doCompile(aQuery, aHints);
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

    std::istringstream lQueryStream(aQuery.c_str());

    doCompile(lQueryStream, aHints);
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

    doCompile(aQuery, aHints);
  }
  QUERY_CATCH
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::doCompile(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints,
    bool fork_sctx)
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
      theStaticContext = theStaticContext->create_child_context();
  }

  zstring url;
  URI::encode_file_URI(theFileName, url);

  theStaticContext->set_entity_retrieval_uri(url);

  theCompilerCB->theRootSctx = theStaticContext;
  const short sctxid = (short)theCompilerCB->theSctxMap.size() + 1;
  (theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

  // Set the compiler config.
  // If lib_module is set to true the query will be considered a library module
  theCompilerCB->theConfig.lib_module = aHints.lib_module;
  CompilerCB::config::opt_level_t optLevel;
  if (aHints.opt_level == ZORBA_OPT_LEVEL_O0)
    optLevel = CompilerCB::config::O0;
  else if (aHints.opt_level == ZORBA_OPT_LEVEL_O2)
    optLevel = CompilerCB::config::O2;
  else
    optLevel = CompilerCB::config::O1;
  theCompilerCB->theConfig.opt_level = optLevel;

  XQueryCompiler lCompiler(theCompilerCB);

  //theCompilerCB->m_debugger = theDebugger;
  //if the debug mode is set, we force the gflwor, we set the query input stream
  if ( theIsDebugMode)
  {
    theCompilerCB->theConfig.force_gflwor = true;
    theCompilerCB->theDebuggerCommons =
      new DebuggerCommons(theCompilerCB->theRootSctx);
    theCompilerCB->theConfig.opt_level = CompilerCB::config::O0;
  }

  // 0 is reserved as an invalid var id, and 1 is taken by the context item
  // in the main module.
  ulong nextDynamicVarId = 2;

  // let's compile
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

    doCompile(lQueryStream, aHints, false);
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

    if (theUserErrorHandler)
      clone->registerErrorHandler(theErrorHandler);

    clone->theStaticContext = theStaticContext->create_child_context();
    clone->theCompilerCB->theRootSctx = clone->theStaticContext;
    clone->theCompilerCB->theSctxMap = theCompilerCB->theSctxMap;

    const short sctxid = (short)clone->theCompilerCB->theSctxMap.size() + 1;
    (clone->theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

    clone->thePlanProxy = thePlanProxy;

    return lXQuery;
  }
  QUERY_CATCH
  return XQuery_t();
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
                                                      theErrorHandler);

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
  Serialize the execution plan inot the given output stream.
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
      zorba::serialization::XmlArchiver   xmlar(&os);

      if((save_options & 0x01) != DONT_SAVE_UNUSED_FUNCTIONS)
        xmlar.set_serialize_everything();

      serialize(xmlar);
      xmlar.serialize_out();
    }
    else//ZORBA_USE_BINARY_ARCHIVE
    {
      zorba::serialization::BinArchiver   bin_ar(&os);

      if((save_options & 0x01) != DONT_SAVE_UNUSED_FUNCTIONS)
        bin_ar.set_serialize_everything();

      serialize(bin_ar);
      bin_ar.serialize_out();
    }

    return true;
  }
  catch (ZorbaException const& e)
  {                           
    ZorbaImpl::notifyError(theErrorHandler, e);
  }                           
  catch (FlowCtlException const&)   
  {
    ZorbaImpl::notifyError(theErrorHandler, "User interrupt");
  }                           
  catch (std::exception const& e)   
  {
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }                           
  catch (...)                 
  {
    ZorbaImpl::notifyError(theErrorHandler);   
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
      zorba::serialization::BinArchiver   bin_ar(&is);
      bin_ar.setUserCallback(aCallback);
      serialize(bin_ar);
      bin_ar.finalize_input_serialization();
      return true;
    }
    catch(ZorbaException const &ex)
    {
      if ( ex.error() != err::ZCSE0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE )
        throw;
      //else go try xml archive reader
    }
    is.seekg(0);
    zorba::serialization::XmlArchiver   xmlar(&is);
    xmlar.setUserCallback(aCallback);
    serialize(xmlar);
    xmlar.finalize_input_serialization();
    return true;
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
      ZORBA_ERROR_DESC(ZAPI0007_CANNOT_SERIALIZE_PUL,
                       "Can't perform SAX serialization with an updating query.");
    }

    theExecuting = true;

    serializer lSerializer(theErrorManager);
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
      throw ZORBA_EXCEPTION( ZAPI0008_NOT_AN_UPDATE_XQUERY );

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
      throw ZORBA_EXCEPTION(ZAPI0039_XQUERY_HAS_ITERATOR_ALREADY);

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
  serializer lSerializer(theErrorManager);

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
  serializer lSerializer(theErrorManager);
  
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
      theCompilerCB->theTimeout);

  return lPlan;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(unsigned short aCommandPort, unsigned short anEventPort)
{
  Zorba_SerializerOptions lSerOptions;
  lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;
  debug(std::cout, lSerOptions, aCommandPort, anEventPort);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(
    std::ostream& aOutStream,
    Zorba_SerializerOptions& aSerOptions,
    unsigned short aCommandPort,
    unsigned short anEventPort)
{
  std::string lHost = "127.0.0.1";
  debug(aOutStream, aSerOptions, lHost, aCommandPort, anEventPort);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(
    std::ostream& aOutStream,
    Zorba_SerializerOptions& aSerOptions,
    const std::string& aHost,
    unsigned short aCommandPort,
    unsigned short anEventPort)
{
  debug(aOutStream, 0, 0, aSerOptions, aHost, aCommandPort, anEventPort);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::debug(
    std::ostream& aOutStream,
    itemHandler aCallbackFunction,
    void* aCallbackData,
    Zorba_SerializerOptions& aSerOptions,
    const std::string& aHost,
    unsigned short aCommandPort /*= 8000*/,
    unsigned short anEventPort /*= 9000*/)
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

    DebuggerServer aDebuggerServer(
      this, aSerOptions, aOutStream, aCallbackFunction,
      aCallbackData, aHost, aCommandPort, anEventPort);
    aDebuggerServer.run();

    theExecuting = false;
  }
  QUERY_CATCH
}


/*******************************************************************************
  May be called explicitly by the application or from ~XQueryImpl().
********************************************************************************/
void XQueryImpl::close()
{
  SYNC_CODE(AutoMutex lock(&theMutex);)

  try
  {
    if (theIsClosed)
      return;
 
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

    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    delete theDynamicContext;

    delete theDynamicContextWrapper;

    delete theStaticContextWrapper;

    theStaticContext = NULL;

    // theCompilerCB may be NULL if an error occured while serializing "this" in.
    if (theCompilerCB)
    {
      delete theCompilerCB->theDebuggerCommons;
      delete theCompilerCB;
    }

    theIsClosed = true;
  }
  QUERY_CATCH
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkIsDebugMode() const
{
  if (!theIsDebugMode) 
    throw ZORBA_EXCEPTION( ZAPI0009_XQUERY_NOT_COMPILED_IN_DEBUG_MODE );
}


/*******************************************************************************
  check whether the query is open, and if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotClosed() const
{
  if (theIsClosed)
    throw ZORBA_EXCEPTION( ZAPI0006_XQUERY_ALREADY_CLOSED );
}


/*******************************************************************************
  Check whether the query has been compiled successfully; if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkCompiled() const
{
  if ( ! thePlanProxy )
    throw ZORBA_EXCEPTION( ZAPI0003_XQUERY_NOT_COMPILED );
}


/*******************************************************************************
  Check whether the query has not been compiled, and if not, fire an error.
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotCompiled() const
{
  if ( thePlanProxy )
    throw ZORBA_EXCEPTION( ZAPI0004_XQUERY_ALREADY_COMPILED );
}


/*******************************************************************************
  Always called while holding theMutex
********************************************************************************/
void XQueryImpl::checkNotExecuting() const
{
  if ( theExecuting )
    throw ZORBA_EXCEPTION( ZAPI0005_XQUERY_ALREADY_EXECUTING );
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
