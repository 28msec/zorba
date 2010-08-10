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
#include <zorba/exception.h>
#include <zorba/sax2.h>

#include <zorbatypes/URI.h>

#include "zorbautils/lock.h"
#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"

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

#include "debugger/zorba_debugger_server.h"
#include "debugger/zorba_debugger_commons.h"

namespace zorba
{


#define QUERY_CATCH                                            \
  catch (error::ZorbaError& e)                                 \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler, e);                \
  }                                                            \
  catch (FlowCtlException&)                                    \
  {                                                            \
    ZorbaImpl::notifyError(theErrorHandler, "User interrupt"); \
  }                                                            \
  catch (std::exception& e)                                    \
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


void XQueryImpl::PlanProxy::serialize(::zorba::serialization::Archiver& ar)
{
  ar & theRootIter;
}



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
  thePlan(),
  theDynamicContext(0),
  theDynamicContextWrapper(0),
  theResultIterator(NULL),
  theExecuting(false),
  theIsClosed(false),
  theUserErrorHandler(false),
  theSAX2Handler(0),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0),
  theIsDebugMode(false),
  theProfileName("xquery_profile.out")
{
  theFileName = new xqpStringStore("");

  // TODO ideally, we will have to move the error handler into the error manager
  //      however, this is not possible yet because not all components of the system
  //      have a control block available.
  //      That is also the reason why we need static function in the error manager
  //      those should also go away and errors should be fired from the error manager
  //      into the error handler
  theErrorHandler = new DefaultErrorHandler();
  theErrorManager = new error::ErrorManager();

  theCompilerCB = new CompilerCB(theSctxMap, theErrorManager);

  theDynamicContext = new dynamic_context();
}


/*******************************************************************************

********************************************************************************/
XQueryImpl::~XQueryImpl()
{
  // only release resouces if not already released
  // be careful with having non-pointers/rchandles as members in xqueryimpl
  if (!theIsClosed)
    close();
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::serialize(::zorba::serialization::Archiver& ar)
{
  // static stuff
  ar & theFileName;
  if(!ar.is_serializing_out())
  {
    delete theCompilerCB;
    //ar.xquery_impl = this;
  }
  else
  {
    ar.compiler_cb = theCompilerCB;
  }

  ar & theCompilerCB;
  ar & theSctxMap;
  ar & thePlan;
  ar & theStaticContext;
  if(!ar.is_serializing_out())
  {
    theDynamicContextWrapper = NULL;
    theStaticContextWrapper = NULL;

    theResultIterator = NULL;

    theExecuting = false;
    theIsClosed = false;

    theCompilerCB->theErrorManager = theErrorManager;
  }
}


/*******************************************************************************
  Set the filename
********************************************************************************/
void XQueryImpl::setFileName(const String& aFileName)
{
  theFileName = Unmarshaller::getInternalString(aFileName);
  if (theFileName == NULL)
    theFileName = new xqpStringStore("");
}


/*******************************************************************************
  Get the filename
********************************************************************************/
String XQueryImpl::getFileName()
{
  return String(theFileName);
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setTimeout(long aTimeout /* = -1 */)
{
  theCompilerCB->theTimeout = aTimeout;
}


/*******************************************************************************

********************************************************************************/
double XQueryImpl::getDocLoadingUserTime() const
{
  return theDocLoadingUserTime;
}


long XQueryImpl::getDocLoadingTime() const
{
  return theDocLoadingTime;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setDebugMode( bool aDebugMode )
{
  //check if the query is not compiled already
  checkNotCompiled();
  theIsDebugMode = aDebugMode;
}


bool XQueryImpl::isDebugMode() const
{
  return theIsDebugMode;
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::setProfileName(std::string aProfileName)
{
  checkIsDebugMode();
  theProfileName = aProfileName;
}


std::string XQueryImpl::getProfileName() const
{
  return theProfileName;
}


/*******************************************************************************
  Make the given user-provided error handler the error handler of this query
********************************************************************************/
void XQueryImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
{
  try
  {
    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

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

  try
  {
    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

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
  try
  {
    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

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
  try
  {
    checkNotClosed();
    checkNotCompiled();

    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);

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
  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);

    // if the static context results from loadProlog, we need all the contexts
    // that were created when compiling the query
    theSctxMap = static_cast<StaticContextImpl*>(aStaticContext.get())->theSctxMap;
    theCompilerCB->theSctxMap = &theSctxMap;

    std::istringstream lQueryStream(lQuery);

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
  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    // if the static context results from loadProlog, we need all the context
    // that were created when compiling the query
    theSctxMap = static_cast<StaticContextImpl*>(aStaticContext.get())->theSctxMap;
    theCompilerCB->theSctxMap = &theSctxMap;

    doCompile(aQuery, aHints);
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::doCompile(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints,
    bool fork_sctx)
{
  checkNotClosed();
  checkNotCompiled();

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

  xqpStringStore_t url;
  URI::encode_file_URI(theFileName, url);

  theStaticContext->set_entity_retrieval_uri(url);

  theCompilerCB->theRootSctx = theStaticContext;
  const short sctxid = theCompilerCB->theSctxMap->size() + 1;
  (*theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

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
      new ZorbaDebuggerCommons(theCompilerCB->theRootSctx);
    theCompilerCB->theConfig.opt_level = CompilerCB::config::O0;
  }

  // let's compile
  PlanIter_t planRoot = lCompiler.compile(aQuery, theFileName);

  SYNC_CODE(AutoMutex lock(&theCloningMutex);)

  thePlan = new PlanProxy(planRoot);
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
  try
  {
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery + "()");

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

    xqpStringStore_t url;
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
  try
  {
    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    checkNotClosed();
    checkCompiled();

    XQuery_t lXQuery(new XQueryImpl());

    XQueryImpl* clone = static_cast<XQueryImpl*>(lXQuery.get());

    clone->registerErrorHandler(theErrorHandler);
    clone->thePlan = thePlan;
    clone->theFileName = theFileName;

    clone->theStaticContext = theStaticContext->create_child_context();

    clone->theCompilerCB->theRootSctx = clone->theStaticContext;
    clone->theCompilerCB->theSctxMap = theCompilerCB->theSctxMap;

    const short sctxid = clone->theCompilerCB->theSctxMap->size() + 1;
    (*clone->theCompilerCB->theSctxMap)[sctxid] = theStaticContext;

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
  try
  {
    checkNotClosed();
    checkCompiled();

    theCompilerCB->theIsSerializingOut = true;

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

    theCompilerCB->theIsSerializingOut = false;
    return true;
  }
  catch (error::ZorbaError& e)
  {                           
    theCompilerCB->theIsSerializingOut = false;
    ZorbaImpl::notifyError(theErrorHandler, e);
  }                           
  catch (FlowCtlException&)   
  {
    theCompilerCB->theIsSerializingOut = false;
    ZorbaImpl::notifyError(theErrorHandler, "User interrupt");
  }                           
  catch (std::exception& e)   
  {
    theCompilerCB->theIsSerializingOut = false;
    ZorbaImpl::notifyError(theErrorHandler, e.what());
  }                           
  catch (...)                 
  {
    theCompilerCB->theIsSerializingOut = false;
    ZorbaImpl::notifyError(theErrorHandler);   
  }           

  return false;
}


/*******************************************************************************

********************************************************************************/
bool XQueryImpl::loadExecutionPlan(std::istream& is, SerializationCallback* aCallback)
{
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
    catch(error::ZorbaError &er)
    {
      if(er.theErrorCode != SRL0011_INPUT_ARCHIVE_NOT_ZORBA_ARCHIVE)
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
  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    if (isUpdating())
    {
      ZORBA_ERROR_DESC(API0007_CANNOT_SERIALIZE_PUL,
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
        lSerializer.serialize((intern::Serializable*)&*lPlan, std::cerr, theSAX2Handler);
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
  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    if (!isUpdating())
    {
      ZORBA_ERROR_DESC(API0008_NOT_AN_UPDATE_XQUERY,
                       "Cannot execute a non-updating query.");
    }

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
  try
  {
    checkNotClosed();
    checkCompiled();
    checkNotExecuting();

    PlanWrapper_t lPlan = generateWrapper();

    theResultIterator = new ResultIteratorImpl(this, lPlan);
    return Iterator_t(theResultIterator);
  }
  QUERY_CATCH
  return Iterator_t();
}


/*******************************************************************************
  Called from ResultIteratorImpl::closeInternal() or from ResultIteratorImpl
  destructor.
********************************************************************************/
void XQueryImpl::removeResultIterator(const ResultIteratorImpl* iter)
{
  try
  {
    if (theResultIterator == iter)
    {
      theResultIterator = NULL;
      theExecuting = false;
    }
  }
  QUERY_CATCH
}


/*******************************************************************************

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

  lSerializer.serialize((intern::Serializable*)aWrapper, os);
}


/*******************************************************************************

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

  lSerializer.serialize((intern::Serializable*)aWrapper,
                        os, aHandler, aHandlerData);
}


/*******************************************************************************

********************************************************************************/
PlanWrapper_t XQueryImpl::generateWrapper()
{
  PlanWrapper_t lPlan = new PlanWrapper(
      static_cast<PlanIterator*>(thePlan->theRootIter.getp()),
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

    ZorbaDebuggerServer aDebuggerServer(this, aSerOptions, aOutStream,
                                        aCallbackFunction, aCallbackData,
                                        aHost, aCommandPort, anEventPort);
    aDebuggerServer.run();

    theExecuting = false;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::close()
{
  try
  {
    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    if (theIsClosed)
      return;
 
    if (theResultIterator != NULL)
    {
      theResultIterator->closeInternal();
      theResultIterator = NULL;
    }

    theExecuting = false;

    thePlan = 0;

    theSctxMap.clear();

    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    delete theDynamicContext;

    delete theDynamicContextWrapper;

    delete theStaticContextWrapper;

    theStaticContext = NULL;

    delete theCompilerCB->theDebuggerCommons;
    delete theCompilerCB;

    theIsClosed = true;
  }
  QUERY_CATCH
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::checkIsDebugMode() const
{
  if ( ! isDebugMode() ) 
  {
    ZORBA_ERROR_DESC(API0009_XQUERY_NOT_COMPILED_IN_DEBUG_MODE,
                     "Can't perform the operation because the debug mode is not set to true");
  }
}


/*******************************************************************************
  check whether the query is open, and if not, fire an error
********************************************************************************/
void XQueryImpl::checkNotClosed() const
{
  if (theIsClosed)
  {
    ZORBA_ERROR_DESC(API0006_XQUERY_ALREADY_CLOSED,
                     "Can't perform the operation because the query is already closed");
  }
}


/*******************************************************************************
  Check whether the query has been compiled successfully; if not, fire an error
********************************************************************************/
void XQueryImpl::checkCompiled() const
{
  if ( ! thePlan )
  {
    ZORBA_ERROR_DESC(API0003_XQUERY_NOT_COMPILED,
                     "Can't perform the operation because the query is not compiled");
  }
}


/*******************************************************************************
  Check whether the query has not been compiled, and if not, fire an error
********************************************************************************/
void XQueryImpl::checkNotCompiled() const
{
  if ( thePlan )
  {
    ZORBA_ERROR_DESC(API0004_XQUERY_ALREADY_COMPILED,
                     "Can't perform the operation because the query has already been compiled");
  }
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::checkNotExecuting() const
{
  if ( theExecuting )
  {
    ZORBA_ERROR_DESC(API0005_XQUERY_ALREADY_EXECUTING,
                     "Can't perform the operation because the query is executing already.");
  }
}


/*******************************************************************************

********************************************************************************/
void XQueryImpl::printPlan(std::ostream& aStream, bool aDotFormat) const
{
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
                    static_cast<PlanIterator*>(thePlan->theRootIter.getp()));
  }
  QUERY_CATCH
}


std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
{
  aQuery->execute(os);
  return os;
}


std::ostream& operator<< (std::ostream& os, XQuery* aQuery)
{
  XQueryImpl* lQuery = dynamic_cast<XQueryImpl*>(aQuery);
  ZORBA_ASSERT (lQuery != NULL);
  lQuery->execute(os);
  return os;
}


} /* namespace zorba */
