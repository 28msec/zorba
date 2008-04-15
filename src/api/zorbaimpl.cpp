#include "api/zorbaimpl.h"

#include <istream>

#include "errors/fatal.h"
#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"
#include "api/itemfactoryimpl.h"
#include "api/unmarshaller.h"
#include "api/xmldatamanagerimpl.h"

#include "errors/errors.h"
#include "system/globalenv.h"

namespace zorba {


  ZorbaImpl::ZorbaImpl() 
    : theIsInitialized(false) {}

  ZorbaImpl::~ZorbaImpl() 
  {
    shutdown();
  }

  /**
   * Implements Zorba::shutdown in the API.
   *
   * The function is either called explicitly by the user
   * or implicitly at destruction of the singleton instance.
   */
  void
  ZorbaImpl::shutdown() 
  {
    if ( ! theIsInitialized )
      return;
    GlobalEnvironment::destroy();
    theIsInitialized = false;
  }

  /**
   * Protected function to initialize the Zorba Engine.
   * It's called once during static initialization or
   * when calling getInstance after a former shutdown.
   */
  void
  ZorbaImpl::init() 
  {
    GlobalEnvironment::init();
    theIsInitialized = true;
  }

  XQuery_t
  ZorbaImpl::createQuery()
  {
    XQuery_t lXQuery(new XQueryImpl());
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::compileQuery(const String& aQuery, ErrorHandler* aErrorHandler)
  {
    return compileQuery(aQuery, XQuery::CompilerHints(), aErrorHandler);
  }

  XQuery_t
  ZorbaImpl::compileQuery(const String& aQuery, const StaticContext_t& aStaticContext, 
                         ErrorHandler* aErrorHandler)
  {
    return compileQuery(aQuery, aStaticContext, XQuery::CompilerHints(), aErrorHandler);
  }

  XQuery_t
  ZorbaImpl::compileQuery(std::istream& aQuery, ErrorHandler* aErrorHandler)
  {
    return compileQuery(aQuery, XQuery::CompilerHints(), aErrorHandler);
  }

  XQuery_t
  ZorbaImpl::compileQuery(std::istream& aQuery, const StaticContext_t& aStaticContext,
                         ErrorHandler* aErrorHandler)
  {
    return compileQuery(aQuery, aStaticContext, XQuery::CompilerHints(), aErrorHandler);
  }

  XQuery_t
  ZorbaImpl::compileQuery(const String& aQuery, const XQuery::CompilerHints_t& aHints, 
                          ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    lXQuery->compile(aQuery, aHints);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::compileQuery(const String& aQuery, const StaticContext_t& aStaticContext, 
                          const XQuery::CompilerHints_t& aHints, 
                          ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    lXQuery->compile(aQuery, aStaticContext, aHints);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::compileQuery(std::istream& aQuery, const XQuery::CompilerHints_t& aHints, 
                          ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    lXQuery->compile(aQuery, aHints);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::compileQuery(std::istream& aQuery, const StaticContext_t& aStaticContext, 
                          const XQuery::CompilerHints_t& aHints,
                          ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    lXQuery->compile(aQuery, aStaticContext, aHints);
    return lXQuery;
  }

  StaticContext_t
  ZorbaImpl::createStaticContext(ErrorHandler* aErrorHandler)
  {
    return StaticContext_t(new StaticContextImpl(aErrorHandler));
  }

  ItemFactory*
  ZorbaImpl::getItemFactory()
  {
    return ItemFactoryImpl::getInstance();
  }

  XmlDataManager*
  ZorbaImpl::getXmlDataManager()
  {
    return XmlDataManagerImpl::getInstance();
  }

  void
  ZorbaImpl::notifyError(ErrorHandler* aErrorHandler, error::ZorbaError& aError)
  {
    if (aError.isStaticError()) {
      StaticException lStaticException(aError.theErrorCode, String(aError.theDescription.theStrStore),
                                       String(aError.theQueryLocation.getFilenameBegin().theStrStore),
                                       aError.theQueryLocation.getLineBegin(),
                                       aError.theQueryLocation.getColumnBegin());
      aErrorHandler->staticError(lStaticException);
    } else if (aError.isDynamicError()) {
      DynamicException lDynamicException(aError.theErrorCode, String(aError.theDescription.theStrStore),
                                       String(aError.theQueryLocation.getFilenameBegin().theStrStore),
                                       aError.theQueryLocation.getLineBegin(),
                                       aError.theQueryLocation.getColumnBegin());
      aErrorHandler->dynamicError(lDynamicException);
    } else if (aError.isTypeError()) {
      TypeException lTypeException(aError.theErrorCode, String(aError.theDescription.theStrStore),
                                       String(aError.theQueryLocation.getFilenameBegin().theStrStore),
                                       aError.theQueryLocation.getLineBegin(),
                                       aError.theQueryLocation.getColumnBegin());
      aErrorHandler->typeError(lTypeException);
    } else if (aError.isSerializationError()) {
      SerializationException lSerException(aError.theErrorCode, String(aError.theDescription.theStrStore),
                                       String(aError.theQueryLocation.getFilenameBegin().theStrStore),
                                       aError.theQueryLocation.getLineBegin(),
                                       aError.theQueryLocation.getColumnBegin());
      aErrorHandler->serializationError(lSerException);
    } else if (aError.isInternalError()) {
      SystemException lSystemException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->systemError(lSystemException);
    }
    else 
    {
      ZORBA_FATAL(0, "Unexpected type of error");
    }
  }

  void
  ZorbaImpl::notifyError(ErrorHandler* aErrorHandler, const std::string& aDesc)
  {
    SystemException lSystemException(ZorbaError::XQP0019_INTERNAL_ERROR, 
        String(aDesc));
    aErrorHandler->systemError(lSystemException);
  }

  void
  ZorbaImpl::notifyError(ErrorHandler* aErrorHandler)
  {
    SystemException lSystemException(ZorbaError::XQP0019_INTERNAL_ERROR, 
                                     "An internal error occured.");
    aErrorHandler->systemError(lSystemException);
  }
} /* namespace zorba */
