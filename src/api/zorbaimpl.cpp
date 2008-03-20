#include "api/zorbaimpl.h"

#include <istream>

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
  ZorbaImpl::createQuery(const String& aQuery, ErrorHandler* aErrorHandler)
  {
    xqpString lQuery = Unmarshaller::getInternalString(aQuery); 
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    (static_cast<XQueryImpl*>(lXQuery.get()))->compile(lQuery);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::createQuery(const String& aQuery, const StaticContext_t& aStaticContext,
                         ErrorHandler* aErrorHandler)
  {
    xqpString lQuery = Unmarshaller::getInternalString(aQuery); 
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    (static_cast<XQueryImpl*>(lXQuery.get()))->compile(lQuery, aStaticContext);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::createQuery(std::istream& aQuery, ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    (static_cast<XQueryImpl*>(lXQuery.get()))->compile(aQuery);
    return lXQuery;
  }

  XQuery_t
  ZorbaImpl::createQuery(std::istream& aQuery, const StaticContext_t& aStaticContext,
                         ErrorHandler* aErrorHandler)
  {
    XQuery_t lXQuery(new XQueryImpl());
    if (aErrorHandler != 0)
      lXQuery->registerErrorHandler(aErrorHandler);
    (static_cast<XQueryImpl*>(lXQuery.get()))->compile(aQuery, aStaticContext);
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
      StaticException lStaticException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->staticError(lStaticException);
    } else if (aError.isDynamicError()) {
      DynamicException lDynamicException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->dynamicError(lDynamicException);
    } else if (aError.isTypeError()) {
      TypeException lTypeException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->typeError(lTypeException);
    } else if (aError.isSerializationError()) {
      SerializationException lSerException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->serializationError(lSerException);
    } else if (aError.isInternalError()) {
      SystemException lSystemException(aError.theErrorCode, String(aError.theDescription.theStrStore));
      aErrorHandler->systemError(lSystemException);
    }
  }
} /* namespace zorba */
