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
#include "stdafx.h"

#include "api/zorbaimpl.h"

#include <istream>
#include <zorba/diagnostic_list.h>
#include <zorba/store_manager.h>
#include <zorba/query_location.h>
#include <zorba/properties.h>

#include "api/xqueryimpl.h"
#include "api/staticcontextimpl.h"
#include "api/documentmanagerimpl.h"
#include "api/itemfactoryimpl.h"
#include "api/unmarshaller.h"
#include "api/jsondatamanagerimpl.h"
#include "api/xmldatamanagerimpl.h"
//#include "api/item_iter_vector.h"
#include "api/auditimpl.h"

#include "zorbautils/fatal.h"
#include "diagnostics/xquery_diagnostics.h"

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
} g_zorbaImplStaticsDestroyer;


#ifdef WIN32
bool ZorbaImpl::ctrl_c_signaled = false;

BOOL WINAPI CtrlCHandlerRoutine(__in  DWORD dwCtrlType)
{
switch( dwCtrlType )
  {
    case CTRL_LOGOFF_EVENT:
      break;
    case CTRL_C_EVENT:
    case CTRL_CLOSE_EVENT:
    case CTRL_BREAK_EVENT:
    case CTRL_SHUTDOWN_EVENT:
    default:
      ZorbaImpl::ctrl_c_signaled = true;
  }
  return FALSE;
}
#endif


ZorbaImpl::ZorbaImpl() : theNumUsers(0)
{
#ifdef WIN32
  SetConsoleCtrlHandler((PHANDLER_ROUTINE)CtrlCHandlerRoutine, TRUE);
#endif
}


ZorbaImpl::~ZorbaImpl()
{
  shutdownInternal(false);
}


/*******************************************************************************
  Protected function to initialize the Zorba Engine.
  It's called from the static Zorba::getInstance() method.
********************************************************************************/
void ZorbaImpl::init(store::Store* store)
{
  SYNC_CODE(AutoMutex lock(&theUsersMutex);)

  if (theNumUsers == 0)
  {
    void* store2 = StoreManager::getStore();
    (void)store2;
    assert(store2 == store);
    GlobalEnvironment::init(store);
  }

  ++theNumUsers;
}


/*******************************************************************************
  Implements Zorba::shutdown in the API.

  The function is either called explicitly by the user or implicitly at
  destruction of the singleton instance. The "soft" param differentiates
  between these 2 cases: if "true", then it's a user-requested shutdown,
  else it's a shutdown invoked from the destructor.
********************************************************************************/
void ZorbaImpl::shutdownInternal(bool soft)
{
  SYNC_CODE(AutoMutex lock(&theUsersMutex);)

  if (theNumUsers == 0)
    return;

  --theNumUsers;

  if (theNumUsers == 0 || soft == false)
  {
    Loki::DeletableSingleton<ItemFactoryImpl>::GracefulDelete();
    Loki::DeletableSingleton<XmlDataManagerImpl>::GracefulDelete();
    Loki::DeletableSingleton<JsonDataManagerImpl>::GracefulDelete();
    void* store = &GENV_STORE;
    GlobalEnvironment::destroy();
    StoreManager::shutdownStore(store);
  }
}


XQuery_t ZorbaImpl::createQuery(DiagnosticHandler* aDiagnosticHandler)
{
  XQuery_t lXQuery(new XQueryImpl());

  if (aDiagnosticHandler != 0)
    lXQuery->registerDiagnosticHandler(aDiagnosticHandler);

  return lXQuery;
}


XQuery_t ZorbaImpl::compileQuery(
    const String& aQuery,
    DiagnosticHandler* aDiagnosticHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, lHints, aDiagnosticHandler);
}


XQuery_t ZorbaImpl::compileQuery(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    DiagnosticHandler* aDiagnosticHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, aStaticContext, lHints, aDiagnosticHandler);
}


XQuery_t ZorbaImpl::compileQuery(
    const String& aQuery,
    const Zorba_CompilerHints_t& aHints,
    DiagnosticHandler* aDiagnosticHandler)
{
  XQuery_t lXQuery(new XQueryImpl());

  if (aDiagnosticHandler != 0)
    lXQuery->registerDiagnosticHandler(aDiagnosticHandler);

  lXQuery->compile(aQuery, aHints);

  return lXQuery;
}


XQuery_t ZorbaImpl::compileQuery(
    const String& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints,
    DiagnosticHandler* aDiagnosticHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aDiagnosticHandler != 0)
    lXQuery->registerDiagnosticHandler(aDiagnosticHandler);
  lXQuery->compile(aQuery, aStaticContext, aHints);
  return lXQuery;
}


XQuery_t ZorbaImpl::compileQuery(std::istream& aQuery, DiagnosticHandler* aDiagnosticHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, lHints, aDiagnosticHandler);
}


XQuery_t ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext,
    DiagnosticHandler* aDiagnosticHandler)
{
  Zorba_CompilerHints_t lHints;
  return compileQuery(aQuery, aStaticContext, lHints, aDiagnosticHandler);
}


XQuery_t ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const Zorba_CompilerHints_t& aHints,
    DiagnosticHandler* aDiagnosticHandler)
{
  XQuery_t lXQuery(new XQueryImpl());
  if (aDiagnosticHandler != 0)
    lXQuery->registerDiagnosticHandler(aDiagnosticHandler);
  lXQuery->compile(aQuery, aHints);
  return lXQuery;
}


XQuery_t ZorbaImpl::compileQuery(
    std::istream& aQuery,
    const StaticContext_t& aStaticContext,
    const Zorba_CompilerHints_t& aHints,
    DiagnosticHandler* aDiagnosticHandler)
{
  XQuery_t lXQuery(new XQueryImpl());

  if (aDiagnosticHandler != 0)
    lXQuery->registerDiagnosticHandler(aDiagnosticHandler);

  lXQuery->compile(aQuery, aStaticContext, aHints);
  return lXQuery;
}


/*******************************************************************************

********************************************************************************/
StaticContext_t ZorbaImpl::createStaticContext(DiagnosticHandler* handler)
{
  return new StaticContextImpl(handler);
}


/*******************************************************************************

********************************************************************************/
ItemFactory* ZorbaImpl::getItemFactory()
{
  return &ItemFactorySingleton::Instance();
}


/*******************************************************************************

********************************************************************************/
XmlDataManager_t ZorbaImpl::getXmlDataManager()
{
  return new XmlDataManagerImpl();
}


/*******************************************************************************

********************************************************************************/
JsonDataManager_t ZorbaImpl::getJsonDataManager()
{
  return new JsonDataManagerImpl();
}


/*******************************************************************************

********************************************************************************/
audit::Provider* ZorbaImpl::getAuditProvider()
{
  return &audit::PROVIDER_IMPL;
}


/*******************************************************************************

********************************************************************************/
Properties* ZorbaImpl::getProperties()
{
  return &Properties::instance();
}


void ZorbaImpl::notifyError( DiagnosticHandler *eh, ZorbaException const &ze )
{
  eh->error( ze );
}


void ZorbaImpl::notifyError( DiagnosticHandler *eh, char const *what )
{
  eh->error(
    ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR, ERROR_PARAMS( what ) )
  );
}


void ZorbaImpl::notifyError( DiagnosticHandler *eh )
{
  eh->error( ZORBA_EXCEPTION( zerr::ZXQP0003_INTERNAL_ERROR ) );
}


void ZorbaImpl::notifyWarning(DiagnosticHandler* dh, XQueryWarning const& xqw)
{
  dh->warning(xqw);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
