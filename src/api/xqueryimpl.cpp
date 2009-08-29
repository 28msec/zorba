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

#include "util/properties.h"

#include "system/globalenv.h"

#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/unmarshaller.h"
#include "api/serialization/serializer.h"
#include "api/zorbaimpl.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "types/schema/Utils.h"
#include "types/typemanagerimpl.h"
#include "types/root_typemanager.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"

#include "runtime/base/plan_iterator.h"  // maybe we can separate the batcher from the plan iterator
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/runtimecb.h"
#include "runtime/visitors/iterprinter.h"
#include "runtime/visitors/printervisitor.h"

#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/pul.h"
#include "store/api/store.h"

#include "zorbaserialization/xml_archiver.h"
#include "zorbaserialization/bin_archiver.h"
#include "zorbaserialization/class_serializer.h"

#include "debugger/zorba_debugger_server.h"
#include "debugger/zorba_debugger_commons.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(XQueryImpl::PlanProxy)
END_SERIALIZABLE_CLASS_VERSIONS(XQueryImpl::PlanProxy)

SERIALIZABLE_CLASS_VERSIONS(XQueryImpl)
END_SERIALIZABLE_CLASS_VERSIONS(XQueryImpl)


void XQueryImpl::PlanProxy::serialize(::zorba::serialization::Archiver &ar)
{
  ar & theRootIter;
}



XQueryImpl::PlanProxy::PlanProxy(PlanIter_t& root)
  :
  theRootIter(root.getp())
{
}


XQueryImpl::XQueryImpl()
  :
  thePlan(0),
  theStaticContext(0),
  theDynamicContext(0),
  theDynamicContextWrapper(0),
  theStaticContextWrapper(0),
  theUserErrorHandler(false),
  theSAX2Handler(0),
  theIsClosed(false),
  theDocLoadingUserTime(0.0),
  theDocLoadingTime(0),
  theIsDebugMode(false),
  theProfileName("xquery_profile.out")
{ 
  theCompilerCB = new CompilerCB(theSctxMap);

  theDynamicContext = new dynamic_context();

  // TODO ideally, we will have to move the error handler into the error manager
  //      however, this is not possible yet because not all components of the system
  //      have a control block available.
  //      That is also the reason why we need static function in the error manager
  //      those should also go away and errors should be fired from the error manager
  //      into the error handler
  theErrorHandler = new DefaultErrorHandler();
  theErrorManager = new error::ErrorManager();
  theCompilerCB->m_error_manager = theErrorManager;
}


XQueryImpl::~XQueryImpl()
{
  // only release resouces if not already released
  // be careful with having non-pointers/rchandles as members in xqueryimpl 
  if (!theIsClosed)
    close();
}
  

void
XQueryImpl::close()
{
  ZORBA_TRY

    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    checkNotClosed();

    if (!theResultIterators.empty())
      ZORBA_ERROR(API0026_CANNOT_CLOSE_QUERY_WITH_ITERATORS);

    thePlan = 0;

    theSctxMap.clear();

    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    if (theStaticContext)
      RCHelper::removeReference(theStaticContext);

    delete theDynamicContext;

    delete theDynamicContextWrapper;

    delete theStaticContextWrapper;

    delete theCompilerCB->theDebuggerCommons;
    delete theCompilerCB;

    theIsClosed = true;

  ZORBA_CATCH
}


/*******************************************************************************
  A clone query shares its error handler and plan iterator tree with the original
  query. The static and dynamic context of a clone query is a child of a static
  and dynamic context of the orginal query.
********************************************************************************/
XQuery_t
XQueryImpl::clone() const
{
  ZORBA_TRY

    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    checkNotClosed();
    checkCompiled();

    XQuery_t lXQuery(new XQueryImpl());

    XQueryImpl* lImpl = static_cast<XQueryImpl*>(lXQuery.get());
    assert(lImpl);
    lImpl->registerErrorHandler(theErrorHandler);
    lImpl->thePlan = thePlan;
    lImpl->theFileName = theFileName;
    
    // child static context
    lImpl->theStaticContext = theStaticContext->create_child_context();
    RCHelper::addReference(lImpl->theStaticContext);

    lImpl->theCompilerCB->m_sctx = lImpl->theStaticContext;
    lImpl->theCompilerCB->m_context_map = theCompilerCB->m_context_map;

    // child dynamic context
    delete lImpl->theDynamicContext;
    lImpl->theDynamicContext = new dynamic_context(theDynamicContext);

    return lXQuery;

  ZORBA_CATCH
  return XQuery_t();
}


/**
 * Error management
 */ 
void
XQueryImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
{
  ZORBA_TRY

    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    checkNotClosed();
        
    assert (theErrorHandler);
    if ( ! theUserErrorHandler ) {
      delete theErrorHandler;
    }

    theErrorHandler = aErrorHandler;
    theUserErrorHandler = true;

  ZORBA_CATCH
}


void
XQueryImpl::resetErrorHandler()
{
  ZORBA_TRY

    SYNC_CODE(AutoMutex lock(&theCloningMutex);)

    checkNotClosed();

    assert (theErrorHandler);
    if ( ! theUserErrorHandler ) 
      return;

    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;

  ZORBA_CATCH
}


/**
 * Set the filename
 */
void
XQueryImpl::setFileName( const String& aFileName )
{
  xqpString lFileName = Unmarshaller::getInternalString( aFileName );
  theFileName = lFileName;
}

/**
 * Get the filename
 */
String
XQueryImpl::getFileName()
{
  return String(theFileName);
}


/**
 * Give to the caller read-only access to the static context of the query
 */
const StaticContext*
XQueryImpl::getStaticContext() const
{
  ZORBA_TRY

    checkNotClosed();
    checkCompiled();

    if (!theStaticContextWrapper)
      theStaticContextWrapper = new StaticContextImpl(theStaticContext,
                                                      theErrorHandler);

    return theStaticContextWrapper;

  ZORBA_CATCH
  return 0;
}


DynamicContext*
XQueryImpl::getDynamicContext() const
{
  ZORBA_TRY

    checkNotClosed();
    checkCompiled();

    if (!theDynamicContextWrapper)
      theDynamicContextWrapper = new DynamicContextImpl(this);

    return theDynamicContextWrapper;
        
  ZORBA_CATCH
  return 0;
}


bool
XQueryImpl::isUpdateQuery() const
{ 
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();
    return static_cast<PlanIterator*>(thePlan->theRootIter.getp())->isUpdating();
  ZORBA_CATCH
  return false;
}


CompilerCB::config_t
XQueryImpl::getCompilerConfig(const Zorba_CompilerHints_t& aHints)
{
  checkNotClosed();
  CompilerCB::config_t lConfig;

  // set the optimization level
  lConfig.opt_level = (aHints.opt_level == ZORBA_OPT_LEVEL_O0 ?
                       CompilerCB::config_t::O0 :
                       CompilerCB::config_t::O1);

  // if lib_module is set to true the query will be considered a library module
  lConfig.lib_module = aHints.lib_module;

  return lConfig;
}


/**
 * Set the SAX handler
 */
void
XQueryImpl::registerSAXHandler( SAX2_ContentHandler * aSAXHandler )
{
  theSAX2Handler = aSAXHandler;
}


/**
 * Execute the query with the given SAX handler
 */
void
XQueryImpl::executeSAX( SAX2_ContentHandler * aSAXHandler )
{
  registerSAXHandler( aSAXHandler );
  executeSAX();
}


/**
 *  Execute the query
 */
void
XQueryImpl::executeSAX()
{
  checkNotClosed();
  checkCompiled();

  PlanWrapper_t lPlan = generateWrapper();
  serializer lSerializer(theErrorManager);
  Zorba_SerializerOptions_t opt;
  setSerializationParameters(&lSerializer, &opt);

  try { 
    lPlan->open();
    if (theSAX2Handler != NULL) {
    lSerializer.serializeSAX2(&*lPlan, std::cerr, theSAX2Handler );
    std::cerr << std::endl;
    } else {
      store::Item_t item;
      while (lPlan->next(item)){};
    }
  } catch (error::ZorbaError& e) {
    lPlan->close();
    ZorbaImpl::notifyError(theErrorHandler, e);
    return;
  }

  theDocLoadingUserTime = lPlan->getRuntimeCB ()->docLoadingUserTime;
  theDocLoadingTime = lPlan->getRuntimeCB()->docLoadingTime;

  lPlan->close();
  //SAX2_XMLReaderNative xmlreader( theSAXHandler, 0, 0, 0, 0 );
  //xmlreader.parse( this, theErrorHandler );
}

/**
 * Parse a query.
 */
void
XQueryImpl::parse(std::istream& aQuery)
{
  ZORBA_TRY
    if ( ! theStaticContext ) {
      // no context given => use the default one (i.e. a child of the root static context)
      theStaticContext = GENV.getRootStaticContext().create_child_context();
    } else {
      // otherwise create a child and we have ownership over that one
      theStaticContext = theStaticContext->create_child_context();
    }
    RCHelper::addReference (theStaticContext);


    theStaticContext->set_entity_retrieval_url(xqp_string (&*URI::encode_file_URI (theFileName)));

    theCompilerCB->m_sctx = theStaticContext;

    XQueryCompiler lCompiler(theCompilerCB);
    lCompiler.parseOnly(aQuery, theFileName);
  ZORBA_CATCH
}

/**
 * various ways to compile a query
 */

void
XQueryImpl::compile(const String& aQuery)
{
  Zorba_CompilerHints_t lHints;
  return compile( aQuery, lHints ); 
}


void
XQueryImpl::compile(const String& aQuery, const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  ZORBA_CATCH
}


void
XQueryImpl::compile(
    const String& aQuery,
    const StaticContext_t& aStaticContext, 
    const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);

    // if the static context results from loadProlog, we need all the contexts
    // that were created when compiling the query
    theSctxMap = static_cast<StaticContextImpl*>(aStaticContext.get())->theCtxMap;
    theCompilerCB->m_context_map = &theSctxMap;

    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  ZORBA_CATCH
}


void XQueryImpl::compile(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    doCompile(aQuery, aHints);
  ZORBA_CATCH
}


void XQueryImpl::compile(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext, 
    const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    // if the static context results from loadProlog, we need all the context
    // that were created when compiling the query
    theSctxMap = static_cast<StaticContextImpl*>(aStaticContext.get())->theCtxMap;
    theCompilerCB->m_context_map = &theSctxMap;

    doCompile(aQuery, aHints);
  ZORBA_CATCH
}


void XQueryImpl::loadProlog(
    const String& aQuery,
    const StaticContext_t& aStaticContext, 
    const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();

    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery + "()");

    theCompilerCB->setLoadPrologQuery();

    doCompile(lQueryStream, aHints, false);
  ZORBA_CATCH
}


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

    // otherwise create a child and we have ownership over that one
    if (fork_sctx)
      theStaticContext = theStaticContext->create_child_context();
  }

  RCHelper::addReference (theStaticContext);

  theStaticContext->set_entity_retrieval_url(xqp_string(&*URI::encode_file_URI(theFileName)));

  theCompilerCB->m_sctx = theStaticContext;
  theCompilerCB->m_cur_sctx = theCompilerCB->m_context_map->size() + 1;
  (*theCompilerCB->m_context_map)[theCompilerCB->m_cur_sctx] = theStaticContext;

  // set the compiler config
  theCompilerCB->m_config = getCompilerConfig(aHints);

  XQueryCompiler lCompiler(theCompilerCB);

  //theCompilerCB->m_debugger = theDebugger;
  //if the debug mode is set, we force the gflwor, we set the query input stream
  if ( theIsDebugMode){
    theCompilerCB->m_config.force_gflwor = true;
    theCompilerCB->theDebuggerCommons = new ZorbaDebuggerCommons();
    theCompilerCB->m_config.opt_level = CompilerCB::config_t::O0;
  }
  // let's compile
  PlanIter_t planRoot = lCompiler.compile(aQuery, theFileName); 

  SYNC_CODE(AutoMutex lock(&theCloningMutex);)

  thePlan = new PlanProxy(planRoot);
}


/** 
 * various ways to execute a query
 */

void
XQueryImpl::serialize(std::ostream& os, const Zorba_SerializerOptions_t* opt)
{
  checkNotClosed();
  checkCompiled();

  PlanWrapper_t lPlan = generateWrapper();
  
  SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)

  try {
    lPlan->open();
    serialize(os, lPlan, opt);
  }
  catch (...) {
    lPlan->close();
    throw;
  }

  theDocLoadingUserTime = lPlan->getRuntimeCB ()->docLoadingUserTime;
  theDocLoadingTime = lPlan->getRuntimeCB()->docLoadingTime;

  lPlan->close();
}

void
XQueryImpl::serialize(std::ostream& os, PlanWrapper_t& aWrapper, const Zorba_SerializerOptions_t* opt)
{
  ZORBA_TRY
    serializer lSerializer(theErrorManager);
    if (opt != NULL)
      setSerializationParameters(&lSerializer, opt);
    
    lSerializer.serialize(&*aWrapper, os);
  ZORBA_CATCH
}

void
XQueryImpl::applyUpdates(PlanWrapper_t& aWrapper)
{
  ZORBA_TRY
    store::Item_t pul;

    // updating expression might not return a pul because of vacuous expressions
    if (aWrapper->next(pul))
    {
      if (!pul->isPul())
        ZORBA_ERROR_DESC(XQP0019_INTERNAL_ERROR,
                         "Query does not return a pending update list");

      std::set<zorba::store::Item*> validationNodes;

      pul->applyUpdates(validationNodes);
      /*
      std::set<zorba::store::Item*>::const_iterator it = validationNodes.begin();
      std::set<zorba::store::Item*>::const_iterator end = validationNodes.end();
      for (; it != end; it++)
      {
        std::cout << "     Validating node " << *it << std::endl;
      }
      */
      QueryLoc loc;
      store::Item_t validationPul = GENV_ITEMFACTORY->createPendingUpdateList();

#ifndef ZORBA_NO_XMLSCHEMA
      validateAfterUpdate(validationNodes, validationPul, theStaticContext, loc);
#endif
      validationPul->applyUpdates(validationNodes);
    }
  ZORBA_CATCH
}

void 
XQueryImpl::applyUpdates()
{
  checkNotClosed();
  checkCompiled();

  PlanWrapper_t lPlan = generateWrapper();

  SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::WRITE);)

  try 
  { 
    lPlan->open();
    applyUpdates(lPlan);
  }
  catch (...)
  {
    lPlan->close();
    throw;
  }

  theDocLoadingUserTime = lPlan->getRuntimeCB()->docLoadingUserTime;
  theDocLoadingTime = lPlan->getRuntimeCB()->docLoadingTime;

  lPlan->close();
}


ResultIterator_t
XQueryImpl::iterator()
{
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();

    ulong numIters = theResultIterators.size();
    theResultIterators.push_back(new ResultIteratorImpl(this, lPlan));
    return ResultIterator_t(theResultIterators[numIters]);

  ZORBA_CATCH
  return ResultIterator_t();;
}


void
XQueryImpl::removeResultIterator(const ResultIterator* iter)
{
  std::vector<ResultIteratorImpl*>::iterator it =
    std::find(theResultIterators.begin(),
              theResultIterators.end(),
              iter);

  ZORBA_ASSERT(it != theResultIterators.end());
  theResultIterators.erase(it);
}


PlanWrapper_t
XQueryImpl::generateWrapper()
{
  PlanWrapper_t lPlan = 
  new PlanWrapper(static_cast<PlanIterator*>(thePlan->theRootIter.getp()),
                  theCompilerCB,
                  theDynamicContext);
  return lPlan;
}


void
XQueryImpl::setSerializationParameters(
    serializer* ser,
    const Zorba_SerializerOptions_t* opt)
{
  if (opt == NULL)
    return;
  
  switch (opt->ser_method) 
  {
  case ZORBA_SERIALIZATION_METHOD_XML:
    ser->set_parameter("method", "xml"); break;
  case ZORBA_SERIALIZATION_METHOD_HTML:
    ser->set_parameter("method", "html"); break;
  case ZORBA_SERIALIZATION_METHOD_XHTML:
    ser->set_parameter("method", "xhtml"); break;
  case ZORBA_SERIALIZATION_METHOD_TEXT:
    ser->set_parameter("method", "text"); break;
  case ZORBA_SERIALIZATION_METHOD_JSON:
    ser->set_parameter("method", "json"); break;
  case ZORBA_SERIALIZATION_METHOD_JSONML:
    ser->set_parameter("method", "jsonml"); break;
  }

  switch (opt->byte_order_mark) 
  {
  case ZORBA_BYTE_ORDER_MARK_YES:
    ser->set_parameter("byte-order-mark", "yes"); break;
  case ZORBA_BYTE_ORDER_MARK_NO:
    ser->set_parameter("byte-order-mark", "no"); break;
  }

  switch (opt->include_content_type)
  {
  case ZORBA_INCLUDE_CONTENT_TYPE_YES:
    ser->set_parameter("include-content-type", "yes"); break;
  case ZORBA_INCLUDE_CONTENT_TYPE_NO:
    ser->set_parameter("include-content-type", "no"); break;
  }

  switch (opt->indent) 
  {
  case ZORBA_INDENT_YES:
    ser->set_parameter("indent", "yes"); break;
  case ZORBA_INDENT_NO:
    ser->set_parameter("indent", "no"); break;
  }

  switch (opt->omit_xml_declaration)
  {
  case ZORBA_OMIT_XML_DECLARATION_YES:
    ser->set_parameter("omit-xml-declaration", "yes"); break;
  case ZORBA_OMIT_XML_DECLARATION_NO:
    ser->set_parameter("omit-xml-declaration", "no"); break;
  }

  switch (opt->standalone)
  {
  case ZORBA_STANDALONE_YES:
    ser->set_parameter("standalone", "yes"); break;
  case ZORBA_STANDALONE_NO:
    ser->set_parameter("standalone", "no"); break;
  case ZORBA_STANDALONE_OMIT:
    ser->set_parameter("standalone", "omit"); break;
  }

  switch (opt->undeclare_prefixes)
  {
  case ZORBA_UNDECLARE_PREFIXES_YES:
    ser->set_parameter("undeclare-prefixes", "yes"); break;
  case ZORBA_UNDECLARE_PREFIXES_NO:
    ser->set_parameter("undeclare-prefixes", "no"); break;
  }

  if (opt->media_type != "")
    ser->set_parameter("media-type", opt->media_type.c_str());

  if (opt->doctype_system != "")
    ser->set_parameter("doctype-system", opt->doctype_system.c_str());

  if (opt->doctype_public != "")
    ser->set_parameter("doctype-public", opt->doctype_public.c_str());
  
  if (opt->cdata_section_elements != "")
    ser->set_parameter("cdata-section-elements", opt->cdata_section_elements.c_str());
}


void
XQueryImpl::checkNotClosed() const
{
  if (theIsClosed) {
    ZORBA_ERROR_DESC(API0022_QUERY_ALREADY_CLOSED,
                     "Can't perform the operation because the query is already closed");
  }
}

  
void
XQueryImpl::checkCompiled() const
{
  if ( ! thePlan ) {
    ZORBA_ERROR_DESC(API0003_XQUERY_NOT_COMPILED, 
                     "Can't perform the operation because the query is not compiled");
  }
}
  

void
XQueryImpl::checkNotCompiled() const
{
  if ( thePlan ) {
    ZORBA_ERROR_DESC(API0004_XQUERY_ALREADY_COMPILED, 
                     "Can't perform the operation because the query has already been compiled");
  }
}

double
XQueryImpl::getDocLoadingUserTime() const
{
  return theDocLoadingUserTime;
}


long
XQueryImpl::getDocLoadingTime() const
{
  return theDocLoadingTime;
}

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

void XQueryImpl::setProfileName(std::string aProfileName)
{
  checkIsDebugMode();
  theProfileName = aProfileName;
}

std::string XQueryImpl::getProfileName() const
{
  return theProfileName;
}

void XQueryImpl::checkIsDebugMode() const
{
  if ( ! isDebugMode() ) {
    ZORBA_ERROR_DESC( API0032_QUERY_NOT_COMPILED_IN_DEBUG_MODE,
                      "Can't perform the operation because the debug mode is not set to true");
  }
}

void XQueryImpl::debug( unsigned short aCommandPort, unsigned short anEventPort )
{
  ZORBA_TRY
    Zorba_SerializerOptions_t lSerOptions;
    lSerOptions.omit_xml_declaration = ZORBA_OMIT_XML_DECLARATION_YES;  
    debug(std::cout, &lSerOptions, aCommandPort, anEventPort);
  ZORBA_CATCH
}

void XQueryImpl::debug(std::ostream& aOutStream,
                        const Zorba_SerializerOptions_t* aSerOptions,
                        unsigned short aCommandPort, unsigned short anEventPort)
{
  SYNC_CODE(AutoLock lock(GENV_STORE.getGlobalLock(), Lock::READ);)
  ZORBA_TRY
    //check if the query is compiled and not closed
    checkCompiled();
    checkNotClosed();
    //check if the debug mode is enabled
    checkIsDebugMode();
    ZorbaDebuggerServer aDebuggerServer(this, aSerOptions, 
                                        aOutStream, aCommandPort,
                                        anEventPort);
    aDebuggerServer.run();
  ZORBA_CATCH
}

void
XQueryImpl::printPlan( std::ostream& aStream, bool aDotFormat ) const
{
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();
    std::auto_ptr<IterPrinter> lPrinter;
    if (aDotFormat)
      lPrinter.reset(new DOTIterPrinter(aStream));
    else
      lPrinter.reset(new XMLIterPrinter(aStream));
    print_iter_plan(*(lPrinter.get()),
                    static_cast<PlanIterator*>(thePlan->theRootIter.getp()));
  ZORBA_CATCH
}


std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
{
  aQuery->serialize(os); 
  return os;
}

std::ostream& operator<< (std::ostream& os, XQuery* aQuery)
{
  XQueryImpl* lQuery = dynamic_cast<XQueryImpl*>(aQuery);
  ZORBA_ASSERT (lQuery != NULL);
  lQuery->serialize(os); 
  return os;
}

bool XQueryImpl::saveExecutionPlan(std::ostream &os, Zorba_binary_plan_format_t archive_format)
{
  ZORBA_TRY
  if(archive_format == ZORBA_USE_XML_ARCHIVE)
  {
    zorba::serialization::XmlArchiver   xmlar(&os);
    serialize(xmlar);
    xmlar.serialize_out();
  }
  else//ZORBA_USE_BINARY_ARCHIVE
  {
    zorba::serialization::BinArchiver   bin_ar(&os);
    serialize(bin_ar);
    bin_ar.serialize_out();
  }
  return true;
  ZORBA_CATCH
  return false;
}

bool XQueryImpl::loadExecutionPlan(std::istream &is)
{
  ZORBA_TRY
  try{//try the binary format first
    zorba::serialization::BinArchiver   bin_ar(&is);
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
  zorba::serialization::XmlArchiver   xmlar(&is);
  serialize(xmlar);
  xmlar.finalize_input_serialization();
  return true;
  ZORBA_CATCH
  return false;
}

bool
XQueryImpl::loadExecutionPlan(std::istream &is, 
                  DocumentURIResolver* aDocumentURIResolver,
                  CollectionURIResolver* aCollectionUriResolver,
                  SchemaURIResolver* aSchemaUriResolver,
                  ModuleURIResolver* aModuleUriResolver,
                  std::ostream*      theTraceStream)
{
  if(!loadExecutionPlan(is))
    return false;

  getStaticContext();
  if(aDocumentURIResolver)
    theStaticContextWrapper->setDocumentURIResolver(aDocumentURIResolver);
  if(aCollectionUriResolver)
    theStaticContextWrapper->setCollectionURIResolver(aCollectionUriResolver);
  if(aSchemaUriResolver)
    theStaticContextWrapper->setSchemaURIResolver(aSchemaUriResolver);
  if(aModuleUriResolver)
    theStaticContextWrapper->setModuleURIResolver(aModuleUriResolver);
  if(theTraceStream)
    theStaticContextWrapper->setTraceStream(*theTraceStream);
  return true;
}

} /* namespace zorba */
