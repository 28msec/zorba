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
    : thePlan(0),
      theStaticContext(0),
      theUserErrorHandler(false),
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

  /**
   * Error management
   */ 
  void
  XQueryImpl::registerErrorHandler(ErrorHandler* aErrorHandler)
  {
    checkClosed();
      
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
    checkClosed();

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
    checkClosed();

    xqpString lFileName = Unmarshaller::getInternalString( aFileName );
    theFileName = lFileName;
  }

  void
  XQueryImpl::close()
  {
    if (theIsClosed)
      checkClosed();

    // only destroy the plan if we compiled it successfully
    if (thePlan) {
      RCHelper::removeReference(thePlan); // may still be used by (cloned) xqueries
      thePlan = 0;
    }

    delete theErrorManager;

    if (!theUserErrorHandler) // see registerErrorHandler
      delete theErrorHandler;

    delete theStaticContext;;

    delete theDynamicContext;

    delete theCompilerCB;

    theIsClosed = true;
  }

  /**
   * various ways to compile a query
   */
  void
  XQueryImpl::compile(const String& aQuery)
  {
    checkClosed();
    compile( aQuery, XQuery::CompilerHints() ); 
  }

  void
  XQueryImpl::compile(const String& aQuery, const CompilerHints_t& aHints)
  {
    checkClosed();
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  }

  void
  XQueryImpl::compile(std::istream& aQuery, const CompilerHints_t& aHints)
  {
    checkClosed();
    doCompile(aQuery, aHints);
  }

  void
  XQueryImpl::compile(const String& aQuery, const StaticContext_t& aStaticContext, 
                      const CompilerHints_t& aHints)
  {
    checkClosed();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);
    xqpString lQuery = Unmarshaller::getInternalString(aQuery);
    std::istringstream lQueryStream(lQuery);
    doCompile(lQueryStream, aHints);
  }

  void
  XQueryImpl::compile(std::istream& aQuery, const StaticContext_t& aStaticContext, 
                      const CompilerHints_t& aHints)
  {
    checkClosed();
    theStaticContext = Unmarshaller::getInternalStaticContext(aStaticContext);

    doCompile(aQuery, aHints);
  }

  void
  XQueryImpl::doCompile(std::istream& aQuery, const CompilerHints_t& aHints)
  {
    if (thePlan) {
       try {
         ZORBA_ERROR_DESC(ZorbaError::API0004_XQUERY_ALREADY_COMPILED, 
                          "Can't compile the query because it is already compiled");
       } catch (error::ZorbaError &e) {
         ZorbaImpl::notifyError(theErrorHandler, e);
       }
    }

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
      PlanIter_t aPlan = lCompiler.compile(aQuery, theFileName); 
      thePlan = aPlan.getp();
      RCHelper::addReference(thePlan);
    } catch (error::ZorbaError &e) { 
      ZorbaImpl::notifyError(theErrorHandler, e);
    }
  }

   DynamicContext_t
   XQueryImpl::getDynamicContext()
   {
     checkClosed();
     checkCompiled();
      
     return DynamicContext_t(new DynamicContextImpl(theDynamicContext, theStaticContext, 
                                                    theErrorHandler));
   }

   const StaticContext_t
   XQueryImpl::getStaticContext() const
   {
     checkClosed();
     checkCompiled();
      
     return StaticContext_t(new StaticContextImpl(theStaticContext, theErrorHandler));
   }

  /** 
   * various ways to execute a query
   */
  bool
  XQueryImpl::isUpdateQuery() const
  { 
    checkClosed();
    return thePlan->isUpdateIterator();
  }

  PlanWrapper_t
  XQueryImpl::generateWrapper()
  {
    PlanWrapper_t lPlan(new PlanWrapper(thePlan, theCompilerCB, theDynamicContext));
    return lPlan;
  }

  void
  XQueryImpl::serialize(std::ostream& os, const XQuery::SerializerOptions_t& opt)
  {
    checkClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);
    setSerializationParameters(&lSerializer, opt);

    try { 
      lPlan->open();
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
    checkClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();
    serializer lSerializer(theErrorManager);

    try 
    { 
      lPlan->open();
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
      //pul->serializeUpdates(lSerializer, os);
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
    checkClosed();
    checkCompiled();

    PlanWrapper_t lPlan = generateWrapper();
    return ResultIterator_t(new ResultIteratorImpl(lPlan, theErrorManager, theErrorHandler));
  }

  CompilerCB::config_t
  XQueryImpl::getCompilerConfig(const XQuery::CompilerHints_t& aHints)
  {
    checkClosed();
    CompilerCB::config_t lConfig;

    // set the optimization level
    lConfig.opt_level = aHints.opt_level==XQuery::CompilerHints::O0 ? CompilerCB::config_t::O0 : CompilerCB::config_t::O1;

    return lConfig;
  }

  void
  XQueryImpl::setSerializationParameters(serializer* ser, const XQuery::SerializerOptions_t& opt)
  {
    switch (opt.ser_method) {
      case XQuery::SerializerOptions::serialization_method::XML: ser->set_parameter("method", "xml"); break;
      case XQuery::SerializerOptions::serialization_method::HTML: ser->set_parameter("method", "html"); break;
    }
    switch (opt.byte_order_mark) {
      case XQuery::SerializerOptions::byte_order_mark::YES: ser->set_parameter("byte-order-mark", "yes"); break;
      case XQuery::SerializerOptions::byte_order_mark::NO:  ser->set_parameter("byte-order-mark", "no"); break;
    }
    switch (opt.include_content_type) {
      case XQuery::SerializerOptions::include_content_type::YES: ser->set_parameter("include-content-type", "yes"); break;
      case XQuery::SerializerOptions::include_content_type::NO:  ser->set_parameter("include-content-type", "no"); break;
    }
    switch (opt.indent) {
      case XQuery::SerializerOptions::indent::YES: ser->set_parameter("indent", "yes"); break;
      case XQuery::SerializerOptions::indent::NO:  ser->set_parameter("indent", "no"); break;
    }
    switch (opt.omit_xml_declaration) {
      case XQuery::SerializerOptions::omit_xml_declaration::YES: ser->set_parameter("omit-xml-declaration", "yes"); break;
      case XQuery::SerializerOptions::omit_xml_declaration::NO:  ser->set_parameter("omit-xml-declaration", "no"); break;
    }
    switch (opt.standalone) {
      case XQuery::SerializerOptions::standalone::YES: ser->set_parameter("standalone", "yes"); break;
      case XQuery::SerializerOptions::standalone::NO:  ser->set_parameter("standalone", "no"); break;
      case XQuery::SerializerOptions::standalone::OMIT:ser->set_parameter("standalone", "omit"); break;
    }
    switch (opt.undeclare_prefixes) {
      case XQuery::SerializerOptions::undeclare_prefixes::YES: ser->set_parameter("undeclare-prefixes", "yes"); break;
      case XQuery::SerializerOptions::undeclare_prefixes::NO:  ser->set_parameter("undeclare-prefixes", "no"); break;
    }
    
  }

  void
  XQueryImpl::checkClosed() const
  {
    if (theIsClosed) {
      try {
        ZORBA_ERROR_DESC(ZorbaError::API0022_QUERY_ALREADY_CLOSED,
          "Can't perform the operation because the query is already closed");
      } catch(error::ZorbaError &e) {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }
    }
  }

  void
  XQueryImpl::checkCompiled() const
  {
    if ( ! thePlan ) {
      try {
        ZORBA_ERROR_DESC(ZorbaError::API0003_XQUERY_NOT_COMPILED, 
            "Can't perform the operation because the query is not compiled");
      } catch (error::ZorbaError &e) {
        ZorbaImpl::notifyError(theErrorHandler, e);
      }
    }
  }

  XQuery_t
  XQueryImpl::clone() const
  {
    checkClosed();

    XQuery_t lXQuery(new XQueryImpl());

    XQueryImpl* lImpl = static_cast<XQueryImpl*>(lXQuery.get());
    assert(lImpl);
    lImpl->registerErrorHandler(theErrorHandler);
    lImpl->thePlan = thePlan;
    RCHelper::addReference(lImpl->thePlan); 
    lImpl->theFileName = theFileName;

    // child static context
    lImpl->theStaticContext = theStaticContext->create_child_context();

    // child dynamic context
    delete lImpl->theDynamicContext;
    lImpl->theDynamicContext = new dynamic_context(theDynamicContext);

    return lXQuery;
  }



  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery)
  {
    aQuery->serialize(os); 
    return os;
  }

} /* namespace zorba */
