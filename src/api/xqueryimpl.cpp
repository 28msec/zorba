#include "api/xqueryimpl.h"

#include <vector>
#include <sstream>
#include "zorbatypes/representations.h"

#include <zorba/default_error_handler.h>
#include <zorba/error.h>
#include <zorba/exception.h>
#include "errors/errors.h"

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
#include "errors/error_manager.h"
#include "runtime/api/plan_wrapper.h"


namespace zorba {

	XQueryImpl::XQueryImpl()
    : theStaticContext(0),
      theUserStaticContext(false),
      theUserErrorHandler(false)
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
    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    if (!theUserStaticContext)
      delete theStaticContext;;

    delete theDynamicContext;

    delete theCompilerCB;
  }

  /**
   * Error management
   */ 
  void
  XQueryImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
  {
    assert (theErrorHandler);
    if ( ! theUserErrorHandler ) {
      delete theErrorHandler;
    }
    theErrorHandler = aErrorHandler;
    theUserErrorHandler = true;
  }

  /**
   * various ways to compile a query
   */
  void
  XQueryImpl::compile(const xqpString& aQuery)
  {
    std::istringstream lQueryStream(aQuery);
    doCompile(lQueryStream);
  }

  void
  XQueryImpl::compile(std::istream& aQuery)
  {
    doCompile(aQuery);
  }

  void
  XQueryImpl::compile(const xqpString& aQuery, const StaticContext_t& aStaticContext)
  {
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    theUserStaticContext = true; // rememeber that we do not have the ownership

    std::istringstream lQueryStream(aQuery);
    doCompile(lQueryStream);
  }

  void
  XQueryImpl::compile(std::istream& aQuery, const StaticContext_t& aStaticContext)
  {
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    theUserStaticContext = true; // rememeber that we do not have the ownership
  }

  void
  XQueryImpl::doCompile(std::istream& aQuery)
  {
    if ( ! theStaticContext ) {
      // no context given => use the default one (i.e. a child of the root static context)
      theStaticContext = GENV.getRootStaticContext().create_child_context();
    }

    theCompilerCB->m_sctx = theStaticContext;
    
    XQueryCompiler lCompiler(theCompilerCB);

    try {
      // let's ompile
      thePlan = lCompiler.compile(aQuery); 
    } catch (error::ZorbaError &e) { // TODO this can be removed (see comment in the constructor)
      ZorbaImpl::notifyError(theErrorHandler, e);
    }

  }

   DynamicContext_t
   XQueryImpl::getDynamicContext()
   {
     // make sure the query is compiled, we should gunarantee this, since only we can call compile internally
     assert(theStaticContext); 
      
     return DynamicContext_t(new DynamicContextImpl(theDynamicContext, theStaticContext, theErrorHandler));
   }

   StaticContext_t
   XQueryImpl::getStaticContext()
   {
     // make sure the query is compiled, we should gunarantee this, since only we can call compile internally
     assert(theStaticContext); 
      
     return StaticContext_t(new StaticContextImpl(theStaticContext, theErrorHandler));
   }

  /** 
   * various ways to execute a query
   */
  PlanWrapper_t
  XQueryImpl::generateWrapper()
  {
    PlanWrapper_t lPlan(new PlanWrapper(thePlan, theCompilerCB, theDynamicContext));
    return lPlan;
  }

  void
  XQueryImpl::serialize(std::ostream& os)
  {
    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);

    lPlan->open();
    try { 
      lSerializer.serialize(&*lPlan, os);
    } catch (error::ZorbaError& e) {
      lPlan->close();
      ZorbaImpl::notifyError(theErrorHandler, e);
      return;
    }

    lPlan->close();
  }

  ResultIterator_t
  XQueryImpl::iterator()
  {
    PlanWrapper_t lPlan = generateWrapper();
    return ResultIterator_t(new ResultIteratorImpl(lPlan, theErrorManager, theErrorHandler));
  }



  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
  {
    aQuery->serialize(os); 
    return os;
  }

} /* namespace zorba */
