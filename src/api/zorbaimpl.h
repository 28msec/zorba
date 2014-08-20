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
#pragma once
#ifndef XQP_ZORBA_IMPL_H
#define XQP_ZORBA_IMPL_H

#include <exception>
#include <istream>

#include <zorba/zorba.h>
#include <zorba/zorba_exception.h>

#include "common/shared_types.h"
#include "zorbautils/mutex.h"


namespace zorba {

class FlowCtlException;

namespace store {
  class Store;
}

#define ZORBA_TRY try {

#define ZORBA_CATCH                                                 \
  } catch (ZorbaException const& e) {                               \
    ZorbaImpl::notifyError(theDiagnosticHandler, e);                \
  } catch (FlowCtlException const&) {                               \
    ZorbaImpl::notifyError(theDiagnosticHandler, "User interrupt"); \
  } catch (std::exception const& e) {                               \
    ZorbaImpl::notifyError(theDiagnosticHandler, e.what());         \
  } catch (...) {                                                   \
    ZorbaImpl::notifyError(theDiagnosticHandler);                   \
  }                                                                 \

/**
 *
 */
class ZorbaImpl : public Zorba
{
protected:
  friend class Zorba;

  SYNC_CODE(Mutex theUsersMutex);
  ulong           theNumUsers;

public:
#ifdef WIN32
  static bool ctrl_c_signaled;
#endif

public:

  static void notifyError(DiagnosticHandler*, ZorbaException const&);

  // notify zorba internal error
  static void notifyError(DiagnosticHandler*, char const *what);

  static void notifyError(DiagnosticHandler*);

  static void notifyWarning(DiagnosticHandler*, XQueryWarning const&);

 public:

  virtual ~ZorbaImpl();

  void shutdown() { shutdownInternal(true); }

  int runUriTest() const;

  int runDebuggerProtocolTest() const;

  XQuery_t createQuery(DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        const StaticContext_t& aContext,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        const Zorba_CompilerHints_t& aHints,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        const StaticContext_t& aContext,
        const Zorba_CompilerHints_t& aHints,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const StaticContext_t& aContext,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const Zorba_CompilerHints_t& aHints,
        DiagnosticHandler* aDiagnosticHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const StaticContext_t& aContext,
        const Zorba_CompilerHints_t& aHints,
        DiagnosticHandler* aDiagnosticHandler = 0);

  StaticContext_t createStaticContext(DiagnosticHandler* handler = 0);

  XmlDataManager_t getXmlDataManager();

  JsonDataManager_t getJsonDataManager();

  ItemFactory* getItemFactory();

  audit::Provider* getAuditProvider();

  Properties* getProperties();

protected:
  ZorbaImpl();

  void init(store::Store* store);

  void shutdownInternal(bool soft = true);

}; // class ZorbaImpl

} // namespace zorba

#endif /* XQP_ZORBA_IMPL_H */
/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
