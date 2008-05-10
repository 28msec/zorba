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
#include "zorbatypes/representations.h"

#include <zorba/default_error_handler.h>
#include <zorba/error.h>
#include <zorba/exception.h>
#include <zorba/sax2.h>

#include "errors/errors.h"
#include "errors/error_manager.h"

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

namespace zorba {

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
    checkNotClosed();

    thePlan = 0;

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
  A clone query shares its error handler and plan iterator with the original
  query. The static and dynamic context of a clone query is a child of a static
  and dynamic context of the orginal query.
********************************************************************************/
XQuery_t
XQueryImpl::clone() const
{
  ZORBA_TRY
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
      theDynamicContextWrapper = new DynamicContextImpl(theDynamicContext,
                                                        theStaticContext, 
                                                        theErrorHandler);

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
    return thePlan->isUpdating();
  ZORBA_CATCH
  return false;
}


CompilerCB::config_t
XQueryImpl::getCompilerConfig(const XQuery::CompilerHints_t& aHints)
{
  checkNotClosed();
  CompilerCB::config_t lConfig;

  // set the optimization level
  lConfig.opt_level = (aHints.opt_level == XQuery::CompilerHints::O0 ?
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
  XQuery::SerializerOptions opt;
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
  return compile( aQuery, XQuery::CompilerHints() ); 
}


void
XQueryImpl::compile(const String& aQuery, const CompilerHints_t& aHints)
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
    const CompilerHints_t& aHints)
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
XQueryImpl::compile(std::istream& aQuery, const CompilerHints_t& aHints)
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
    const CompilerHints_t& aHints)
{
  ZORBA_TRY
    checkNotClosed();
    checkNotCompiled();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    doCompile(aQuery, aHints);
  ZORBA_CATCH
}


void
XQueryImpl::doCompile(std::istream& aQuery, const CompilerHints_t& aHints)
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

  theCompilerCB->m_sctx = theStaticContext;
  
  // set the compiler config
  theCompilerCB->m_config = getCompilerConfig(aHints);

  XQueryCompiler lCompiler(theCompilerCB);

  // let's compile
  thePlan = lCompiler.compile(aQuery, theFileName); 
}


/** 
 * various ways to execute a query
 */

void
XQueryImpl::serialize(std::ostream& os, const XQuery::SerializerOptions_t& opt)
{
  ZORBA_TRY
    checkNotClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);
    setSerializationParameters(&lSerializer, opt);
    
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
    serializer lSerializer(theErrorManager);

    try 
    { 
      lPlan->open();
      store::Item_t pul = lPlan->next();

      // updating expression might not return a pul because of vacuous expressions
      if (pul != 0)
      {
        if (!pul->isPul())
          ZORBA_ERROR_DESC(ZorbaError::XQP0019_INTERNAL_ERROR,
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
    return ResultIterator_t(new ResultIteratorImpl(lPlan,
                                                   theErrorManager,
                                                   theErrorHandler));
  ZORBA_CATCH
  return ResultIterator_t();
}


PlanWrapper_t
XQueryImpl::generateWrapper()
{
  PlanWrapper_t lPlan(new PlanWrapper(thePlan, theCompilerCB, theDynamicContext));
  return lPlan;
}


void
XQueryImpl::setSerializationParameters(
    serializer* ser,
    const XQuery::SerializerOptions_t& opt)
{
  switch (opt.ser_method) 
  {
  case XQuery::SerializerOptions::serialization_method::XML:
    ser->set_parameter("method", "xml"); break;
  case XQuery::SerializerOptions::serialization_method::HTML:
    ser->set_parameter("method", "html"); break;
  }

  switch (opt.byte_order_mark) 
  {
  case XQuery::SerializerOptions::byte_order_mark::YES:
    ser->set_parameter("byte-order-mark", "yes"); break;
  case XQuery::SerializerOptions::byte_order_mark::NO:
    ser->set_parameter("byte-order-mark", "no"); break;
  }

  switch (opt.include_content_type)
  {
  case XQuery::SerializerOptions::include_content_type::YES:
    ser->set_parameter("include-content-type", "yes"); break;
  case XQuery::SerializerOptions::include_content_type::NO:
    ser->set_parameter("include-content-type", "no"); break;
  }

  switch (opt.indent) 
  {
  case XQuery::SerializerOptions::indent::YES:
    ser->set_parameter("indent", "yes"); break;
  case XQuery::SerializerOptions::indent::NO:
    ser->set_parameter("indent", "no"); break;
  }

  switch (opt.omit_xml_declaration)
  {
  case XQuery::SerializerOptions::omit_xml_declaration::YES:
    ser->set_parameter("omit-xml-declaration", "yes"); break;
  case XQuery::SerializerOptions::omit_xml_declaration::NO:
    ser->set_parameter("omit-xml-declaration", "no"); break;
  }

  switch (opt.standalone)
  {
  case XQuery::SerializerOptions::standalone::YES:
    ser->set_parameter("standalone", "yes"); break;
  case XQuery::SerializerOptions::standalone::NO:
    ser->set_parameter("standalone", "no"); break;
  case XQuery::SerializerOptions::standalone::OMIT:
    ser->set_parameter("standalone", "omit"); break;
  }

  switch (opt.undeclare_prefixes)
  {
  case XQuery::SerializerOptions::undeclare_prefixes::YES:
    ser->set_parameter("undeclare-prefixes", "yes"); break;
  case XQuery::SerializerOptions::undeclare_prefixes::NO:
    ser->set_parameter("undeclare-prefixes", "no"); break;
  }    
}


void
XQueryImpl::checkNotClosed() const
{
  if (theIsClosed) {
    ZORBA_ERROR_DESC(ZorbaError::API0022_QUERY_ALREADY_CLOSED,
                     "Can't perform the operation because the query is already closed");
  }
}

  
void
XQueryImpl::checkCompiled() const
{
  if ( ! thePlan ) {
    ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
                     "Can't perform the operation because the query is not compiled");
  }
}
  

void
XQueryImpl::checkNotCompiled() const
{
  if ( thePlan ) {
    ZORBA_ERROR_DESC(ZorbaError::API0004_XQUERY_ALREADY_COMPILED, 
                     "Can't perform the operation because the query has already been compiled");
  }
}


std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
{
  aQuery->serialize(os); 
  return os;
}

} /* namespace zorba */
