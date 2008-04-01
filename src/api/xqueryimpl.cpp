#include "api/xqueryimpl.h"

#include <vector>
#include <sstream>
#include "zorbatypes/representations.h"

#include <zorba/default_error_handler.h>
#include <zorba/error.h>
#include <zorba/exception.h>

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
    : theStaticContext(0),
      theQueryIsCompiled(false),
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

  void
  XQueryImpl::resetErrorHandler()
  {
    assert (theErrorHandler);
    if ( ! theUserErrorHandler ) 
      return;

    theErrorHandler = new DefaultErrorHandler();
    theUserErrorHandler = false;
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
   * various ways to compile a query
   */
  void
  XQueryImpl::compile(const String& aQuery)
  {
    compile( aQuery, XQuery::CompilerHints() ); 
  }

  void
  XQueryImpl::compile(const String& aQuery, const CompilerHints_t& aHints)
  {
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  }

  void
  XQueryImpl::compile(std::istream& aQuery, const CompilerHints_t& aHints)
  {
    doCompile(aQuery, aHints);
  }

  void
  XQueryImpl::compile(const String& aQuery, const StaticContext_t& aStaticContext, const CompilerHints_t& aHints)
  {
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  }

  void
  XQueryImpl::compile(std::istream& aQuery, const StaticContext_t& aStaticContext, 
                      const CompilerHints_t& aHints)
  {
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    doCompile(aQuery, aHints);
  }

  void
  XQueryImpl::doCompile(std::istream& aQuery, const CompilerHints_t& aHints)
  {
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

    try {
      // let's ompile
      thePlan = lCompiler.compile(aQuery, theFileName); 
    } catch (error::ZorbaError &e) { // TODO this can be removed (see comment in the constructor)
      ZorbaImpl::notifyError(theErrorHandler, e);
    }

    theQueryIsCompiled = true;
  }

   DynamicContext_t
   XQueryImpl::getDynamicContext()
   {
     if ( ! theQueryIsCompiled ) {
       try {
         ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
                          "Error getting the dynamic context because the query is not compiled");
       } catch (error::ZorbaError &e) {
         ZorbaImpl::notifyError(theErrorHandler, e);
       }
     }
      
     return DynamicContext_t(new DynamicContextImpl(theDynamicContext, theStaticContext, 
                                                    theErrorHandler));
   }

   StaticContext_t
   XQueryImpl::getStaticContext()
   {
     if ( ! theQueryIsCompiled ) {
       try {
         ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
                          "Error getting the static context because the query is not compiled");
       } catch (error::ZorbaError &e) {
         ZorbaImpl::notifyError(theErrorHandler, e);
       }
     }
      
     return StaticContext_t(new StaticContextImpl(theStaticContext, theErrorHandler));
   }

  /** 
   * various ways to execute a query
   */
  bool
  XQueryImpl::isUpdateQuery() const
  {
    return thePlan->isUpdateIterator();
  }

  PlanWrapper_t
  XQueryImpl::generateWrapper()
  {
    PlanWrapper_t lPlan(new PlanWrapper(thePlan, theCompilerCB, theDynamicContext));
    return lPlan;
  }

  void
  XQueryImpl::serialize(std::ostream& os, XQuery::SerializerOptions_t)
  {
    if ( ! theQueryIsCompiled ) {
      try {
        ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
                         "Error executing query because it is not compiled");
      } catch (error::ZorbaError &e) {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }
    }

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

  void XQueryImpl::applyUpdates(std::ostream& os)
  {
    if ( ! theQueryIsCompiled ) 
    {
      try
      {
        ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
                         "Error executing query because it is not compiled");
      } catch (error::ZorbaError &e) {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }
    }

    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);

    lPlan->open();
    try 
    { 
      store::Item_t pul = lPlan->next();

      try
      {
        if (!pul->isPul())
          ZORBA_ERROR_DESC(ZorbaError::XQP0019_INTERNAL_ERROR,
                           "Query does not return a pending update list");
      }
      catch (error::ZorbaError &e)
      {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }

      pul->applyUpdates();
      pul->serializeUpdates(lSerializer, os);
    }
    catch (error::ZorbaError& e)
    {
      lPlan->close();
      ZorbaImpl::notifyError(theErrorHandler, e);
      return;
    }

    lPlan->close();
  }

  ResultIterator_t
  XQueryImpl::iterator()
  {
    if ( ! theQueryIsCompiled )
    {
      try
      {
        ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED,
          "Error executing query because it is not compiled");
      } catch(error::ZorbaError &e) {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }
    }
    PlanWrapper_t lPlan = generateWrapper();
    return ResultIterator_t(new ResultIteratorImpl(lPlan, theErrorManager, theErrorHandler));
  }

  CompilerCB::config_t
  XQueryImpl::getCompilerConfig(const XQuery::CompilerHints_t& aHints)
  {
    CompilerCB::config_t lConfig;

    // set the optimization level
    lConfig.opt_level = aHints.opt_level==XQuery::CompilerHints::O0 ? CompilerCB::config_t::O0 : CompilerCB::config_t::O1;

    return lConfig;
  }


  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
  {
    aQuery->serialize(os); 
    return os;
  }

} /* namespace zorba */
