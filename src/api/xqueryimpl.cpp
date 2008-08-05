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

#include "zorbautils/latch.h"
#include "zorbaerrors/errors.h"
#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"
#include "api/staticcontextimpl.h"
#include "api/dynamiccontextimpl.h"
#include "api/resultiteratorimpl.h"
#include "api/unmarshaller.h"
#include "api/serialization/serializer.h"
#include "api/zorbaimpl.h"

#include "compiler/api/compiler_api.h"
#include "compiler/api/compilercb.h"
#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "runtime/api/plan_wrapper.h"
#include "runtime/base/plan_iterator.h"  // maybe we can separate the batcher from the plan iterator
#include "runtime/api/plan_wrapper.h"

#include "util/properties.h"

#include "store/api/item.h"
#include "store/api/store.h"

#ifdef ZORBA_DEBUGGER
#include "debugger/debugger_server.h"
#endif

namespace zorba {


XQueryImpl::PlanProxy::PlanProxy(PlanIter_t& root)
  :
  theRootIter(root)
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
  theIsClosed(false)
#ifdef ZORBA_DEBUGGER
  , theDebugger(0)
#endif
{ 
  theCompilerCB = new CompilerCB();

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

#ifdef ZORBA_DEBUGGER
    delete theDebugger;
#endif

    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    delete theStaticContext;;

    delete theDynamicContext;

    if (theDynamicContextWrapper)
      delete theDynamicContextWrapper;

    if (theStaticContextWrapper)
      delete theStaticContextWrapper;

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
    lImpl->theCompilerCB->m_sctx = lImpl->theStaticContext;

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
    return thePlan->theRootIter->isUpdating();
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
  Zorba_SerializerOptions opt;
  setSerializationParameters(&lSerializer, opt);

  try { 
    lPlan->open();
    lSerializer.serializeSAX2(&*lPlan, std::cerr, theSAX2Handler );
    std::cerr << std::endl;
  } catch (error::ZorbaError& e) {
    lPlan->close();
    ZorbaImpl::notifyError(theErrorHandler, e);
    return;
  }

  lPlan->close();
  //SAX2_XMLReaderNative xmlreader( theSAXHandler, 0, 0, 0, 0 );
  //xmlreader.parse( this, theErrorHandler );
}


/**
 * various ways to compile a query
 */

void
XQueryImpl::compile(const String& aQuery)
{
  return compile( aQuery, Zorba_CompilerHints_default() ); 
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
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  ZORBA_CATCH
}


void
XQueryImpl::compile(std::istream& aQuery, const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    doCompile(aQuery, aHints);
  ZORBA_CATCH
}


void
XQueryImpl::compile(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext, 
    const Zorba_CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    doCompile(aQuery, aHints);
  ZORBA_CATCH
}


void
XQueryImpl::doCompile(std::istream& aQuery, const Zorba_CompilerHints_t& aHints)
{
  checkNotClosed();
  checkNotCompiled();

  if ( ! theStaticContext ) {
    // no context given => use the default one (i.e. a child of the root static context)
    theStaticContext = GENV.getRootStaticContext().create_child_context();
  } else {
    // otherwise create a child and we have ownership over that one
    theStaticContext = theStaticContext->create_child_context();
  }

  theStaticContext->set_entity_retrieval_url (xqp_string (&*URI::encode_file_URI (theFileName)));

  theCompilerCB->m_sctx = theStaticContext;

#ifdef ZORBA_DEBUGGER
  theCompilerCB->m_debugger = theDebugger;
#endif

  // set the compiler config
  theCompilerCB->m_config = getCompilerConfig(aHints);

  XQueryCompiler lCompiler(theCompilerCB);

  // let's compile
  PlanIter_t planRoot = lCompiler.compile(aQuery, theFileName); 

  SYNC_CODE(AutoMutex lock(&theCloningMutex);)

  thePlan = new PlanProxy(planRoot);
}


/** 
 * various ways to execute a query
 */

void
XQueryImpl::serialize(std::ostream& os, const Zorba_SerializerOptions_t& opt)
{
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);
    setSerializationParameters(&lSerializer, opt);
    
    SYNC_CODE(AutoLatch(GENV_STORE.getGlobalLock(), Latch::READ);)

    try 
    {
      lPlan->open();
      lSerializer.serialize(&*lPlan, os);
    }
    catch (error::ZorbaError&)
    {
      lPlan->close();
      throw;
    }

    lPlan->close();
  ZORBA_CATCH
}


void 
XQueryImpl::applyUpdates()
{
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();

    SYNC_CODE(AutoLatch(GENV_STORE.getGlobalLock(), Latch::WRITE);)

    store::Item_t pul;
    try 
    { 
      lPlan->open();

      // updating expression might not return a pul because of vacuous expressions
      if (lPlan->next(pul))
      {
        if (!pul->isPul())
          ZORBA_ERROR_DESC(XQP0019_INTERNAL_ERROR,
                           "Query does not return a pending update list");
        pul->applyUpdates();
      }
    }
    catch (error::ZorbaError&)
    {
      lPlan->close();
      throw;
    }

    lPlan->close();
  ZORBA_CATCH
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
  PlanWrapper_t lPlan(new PlanWrapper(thePlan->theRootIter,
                                      theCompilerCB,
                                      theDynamicContext));
  return lPlan;
}


void
XQueryImpl::setSerializationParameters(
    serializer* ser,
    const Zorba_SerializerOptions_t& opt)
{
  switch (opt.ser_method) 
  {
  case ZORBA_SERIALIZATION_METHOD_XML:
    ser->set_parameter("method", "xml"); break;
  case ZORBA_SERIALIZATION_METHOD_HTML:
    ser->set_parameter("method", "html"); break;
  }

  switch (opt.byte_order_mark) 
  {
  case ZORBA_BYTE_ORDER_MARK_YES:
    ser->set_parameter("byte-order-mark", "yes"); break;
  case ZORBA_BYTE_ORDER_MARK_NO:
    ser->set_parameter("byte-order-mark", "no"); break;
  }

  switch (opt.include_content_type)
  {
  case ZORBA_INCLUDE_CONTENT_TYPE_YES:
    ser->set_parameter("include-content-type", "yes"); break;
  case ZORBA_INCLUDE_CONTENT_TYPE_NO:
    ser->set_parameter("include-content-type", "no"); break;
  }

  switch (opt.indent) 
  {
  case ZORBA_INDENT_YES:
    ser->set_parameter("indent", "yes"); break;
  case ZORBA_INDENT_NO:
    ser->set_parameter("indent", "no"); break;
  }

  switch (opt.omit_xml_declaration)
  {
  case ZORBA_OMIT_XML_DECLARATION_YES:
    ser->set_parameter("omit-xml-declaration", "yes"); break;
  case ZORBA_OMIT_XML_DECLARATION_NO:
    ser->set_parameter("omit-xml-declaration", "no"); break;
  }

  switch (opt.standalone)
  {
  case ZORBA_STANDALONE_YES:
    ser->set_parameter("standalone", "yes"); break;
  case ZORBA_STANDALONE_NO:
    ser->set_parameter("standalone", "no"); break;
  case ZORBA_STANDALONE_OMIT:
    ser->set_parameter("standalone", "omit"); break;
  }

  switch (opt.undeclare_prefixes)
  {
  case ZORBA_UNDECLARE_PREFIXES_YES:
    ser->set_parameter("undeclare-prefixes", "yes"); break;
  case ZORBA_UNDECLARE_PREFIXES_NO:
    ser->set_parameter("undeclare-prefixes", "no"); break;
  }    
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

#ifdef ZORBA_DEBUGGER
void XQueryImpl::setDebugMode( bool aDebugMode )
{
  //check if the query is not compiled already
  checkNotCompiled();
  if ( aDebugMode && theDebugger == 0 )
  {
    theDebugger = new ZorbaDebugger(); 
  } else if ( ! aDebugMode ) {
    delete theDebugger;
  }
}

bool XQueryImpl::getDebugMode() const
{
  if ( theDebugger == 0 )
  {
    return false;
  }
  return true;
}

void XQueryImpl::checkIsDebugMode() const
{
  if ( theDebugger == 0 )
  {
    ZORBA_ERROR_DESC( API0032_QUERY_NOT_COMPILED_IN_DEBUG_MODE,
                      "Can't perform the operation because the debug mode is not set to true");
  }
}

void XQueryImpl::debug( unsigned short aCommandPort, unsigned short anEventPort )
{
  //check if the query is compiled and not closed
  checkCompiled();
  checkNotClosed();
  //check if the debug mode is enabled
  checkIsDebugMode();
  theDebugger->start( this, aCommandPort, anEventPort );
}
#endif

std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
{
  aQuery->serialize(os); 
  return os;
}

std::ostream& operator<< (std::ostream& os, XQuery* aQuery)
{
#ifndef NDEBUG
  XQueryImpl* lQuery = static_cast<XQueryImpl*>(aQuery);
  assert(lQuery);
  lQuery->serialize(os); 
#else
  dynamic_cast<XQueryImpl*>(aQuery)->serialize(os); 
#endif
  return os;
}

} /* namespace zorba */
