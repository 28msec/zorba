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
#include "api/zorbaimpl.h"

#include <istream>
#include <zorba/stateless_function.h>

#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"
#include "api/itemfactoryimpl.h"
#include "api/unmarshaller.h"
#include "api/xmldatamanagerimpl.h"
#include "api/vectoriterator.h"

#include "zorbautils/fatal.h"
#include "zorbaerrors/errors.h"
#include "errors/user_error.h"
#include "zorbaerrors/error_manager.h"

#include "system/globalenv.h"

#include "context/static_context.h"


namespace zorba {

class ZorbaImplStatics
{
public:
  ~ZorbaImplStatics()
  {
    GlobalEnvironment::destroyStatics();
  }
}g_zorbaImplStaticsDestroyer;

ZorbaImpl::ZorbaImpl() : theIsInitialized(false)
{
}


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
  if (theIsInitialized )
  {
    Loki::DeletableSingleton<ItemFactoryImpl>::GracefulDelete();
    Loki::DeletableSingleton<XmlDataManagerImpl>::GracefulDelete();
    GlobalEnvironment::destroy();
    theIsInitialized = false;
  }
}


/**
 * Protected function to initialize the Zorba Engine.
 * It's called once during static initialization or
 * when calling getInstance after a former shutdown.
 */
void
ZorbaImpl::init(store::Store* store)
{
  GlobalEnvironment::init(store);
  theIsInitialized = true;
}


XQuery_t
ZorbaImpl::createQuery(ErrorHandler* aErrorHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aErrorHandler != 0)
    lXQuery->registerErrorHandler(aErrorHandler);
  return lXQuery;
}

XQuery_t
ZorbaImpl::compileQuery(
    const String& aQuery,
    ErrorHandler* aErrorHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, lHints, aErrorHandler);
}


XQuery_t
ZorbaImpl::compileQuery(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    ErrorHandler* aErrorHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, aStaticContext, lHints, aErrorHandler);
}


XQuery_t
ZorbaImpl::compileQuery(
    const String& aQuery,
    const Zorba_CompilerHints_t& aHints,
    ErrorHandler* aErrorHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aErrorHandler != 0)
    lXQuery->registerErrorHandler(aErrorHandler);
  lXQuery->compile(aQuery, aHints);
  return lXQuery;
}


XQuery_t
ZorbaImpl::compileQuery(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints,
    ErrorHandler* aErrorHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aErrorHandler != 0)
    lXQuery->registerErrorHandler(aErrorHandler);
  lXQuery->compile(aQuery, aStaticContext, aHints);
  return lXQuery;
}


XQuery_t
ZorbaImpl::compileQuery(std::istream& aQuery, ErrorHandler* aErrorHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, lHints, aErrorHandler);
}


XQuery_t
ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext,
    ErrorHandler* aErrorHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, aStaticContext, lHints, aErrorHandler);
}


XQuery_t
ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints,
    ErrorHandler* aErrorHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aErrorHandler != 0)
    lXQuery->registerErrorHandler(aErrorHandler);
  lXQuery->compile(aQuery, aHints);
  return lXQuery;
}


XQuery_t
ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints,
    ErrorHandler* aErrorHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aErrorHandler != 0)
    lXQuery->registerErrorHandler(aErrorHandler);
  lXQuery->compile(aQuery, aStaticContext, aHints);
  return lXQuery;
}

void ZorbaImpl::populateRootStaticContext(const String &prolog, const Zorba_CompilerHints_t& aHints)
{
  std::auto_ptr<XQueryImpl> lXQuery(new XQueryImpl());
  lXQuery->loadProlog (prolog, NULL, aHints);
}


/*******************************************************************************

********************************************************************************/
StaticContext_t
ZorbaImpl::createStaticContext(ErrorHandler* aErrorHandler)
{
  return StaticContext_t(new StaticContextImpl(aErrorHandler));
}


/*******************************************************************************

********************************************************************************/
ItemFactory*
ZorbaImpl::getItemFactory()
{
  return &ItemFactorySingleton::Instance();
}


/*******************************************************************************

********************************************************************************/
XmlDataManager*
ZorbaImpl::getXmlDataManager()
{
  return &XmlDataManagerSingleton::Instance();
}

/*******************************************************************************
  Convert an internal zorba error obj to a c++ api exception obj, and then
  notify the user about this error via the error handler.
********************************************************************************/
void
ZorbaImpl::notifyError(ErrorHandler* aErrorHandler, error::ZorbaError& aError)
{
  if (aError.isUserError())
  {
    zorba::error::ZorbaUserError* lUserError = static_cast<zorba::error::ZorbaUserError*>(&aError);

    Iterator_t lIter = new VectorIterator(lUserError->theErrorObject, aErrorHandler);

    UserException lUserException(aError.theErrorCode,
                                 String(aError.theDescription.theStrStore),
                                 String(aError.theFileName),
                                 aError.theLineNumber,
                                 aError.theQueryFileName,
                                 aError.theQueryLine,
                                 aError.theQueryColumn,
                                 lIter);
    aErrorHandler->userError(lUserException);
  }
  else if (aError.isStaticError())
  {
    StaticException lStaticException(aError.theErrorCode,
                                     String(aError.theDescription.theStrStore),
                                     String(aError.theFileName),
                                     aError.theLineNumber,
                                     aError.theQueryFileName,
                                     aError.theQueryLine,
                                     aError.theQueryColumn);
    aErrorHandler->staticError(lStaticException);
  }
  else if (aError.isDynamicError())
  {
    DynamicException lDynamicException(aError.theErrorCode,
                                       String(aError.theDescription.theStrStore),
                                       String(aError.theFileName),
                                       aError.theLineNumber,
                                       aError.theQueryFileName,
                                       aError.theQueryLine,
                                       aError.theQueryColumn);
    aErrorHandler->dynamicError(lDynamicException);
  }
  else if (aError.isTypeError())
  {
    TypeException lTypeException(aError.theErrorCode,
                                 String(aError.theDescription.theStrStore),
                                 String(aError.theFileName),
                                 aError.theLineNumber,
                                 aError.theQueryFileName,
                                 aError.theQueryLine,
                                 aError.theQueryColumn);
    aErrorHandler->typeError(lTypeException);
  }
  else if (aError.isSerializationError())
  {
    SerializationException lSerException(
                            aError.theErrorCode,
                            String(aError.theDescription.theStrStore),
                            String(aError.theFileName),
                            aError.theLineNumber);
    aErrorHandler->serializationError(lSerException);
  }
  else if (aError.isInternalError())
  {
    SystemException lSystemException(aError.theErrorCode,
                                     String(aError.theDescription.theStrStore),
                                     String(aError.theFileName),
                                     aError.theLineNumber);
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
  SystemException lSystemException(XQP0019_INTERNAL_ERROR,
                                   String(aDesc), "", 0);
  aErrorHandler->systemError(lSystemException);
}


void
ZorbaImpl::notifyError(ErrorHandler* aErrorHandler)
{
  SystemException lSystemException(XQP0019_INTERNAL_ERROR,
                                   "An internal error occured.", "", 0);
  aErrorHandler->systemError(lSystemException);
}


void
ZorbaImpl::checkItem(const store::Item_t& aItem)
{
  if (aItem == NULL)
    ZORBA_ERROR_DESC(API0014_INVALID_ARGUMENT, "Invalid item given");
}
} /* namespace zorba */
