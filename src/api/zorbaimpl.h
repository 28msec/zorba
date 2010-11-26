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
#ifndef XQP_ZORBA_IMPL_H
#define XQP_ZORBA_IMPL_H

#include <istream>

#include <exception>
#include <zorba/zorba.h>
#include "common/shared_types.h"

#include "zorbautils/mutex.h"


namespace zorba 
{

class FlowCtlException;

namespace error {
  class ZorbaError;
}

namespace store {
  class Store;
}


#define ZORBA_TRY try {
 
#define ZORBA_CATCH                                            \
  } catch (error::ZorbaError& e) {                             \
    ZorbaImpl::notifyError(theErrorHandler, e);                \
  } catch (FlowCtlException&) {                                \
    ZorbaImpl::notifyError(theErrorHandler, "User interrupt"); \
  } catch (std::exception& e) {                                \
    ZorbaImpl::notifyError(theErrorHandler, e.what());         \
  } catch (...) {                                              \
    ZorbaImpl::notifyError(theErrorHandler);                   \
  }                                                            \
  

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

  static void notifyError(ErrorHandler*, error::ZorbaError&);

  // notify zorba internal error 
  static void notifyError(ErrorHandler*, const std::string&);
  
  static void notifyError(ErrorHandler*);

  static void checkItem(const store::Item_t& aItem);

 public:

  virtual ~ZorbaImpl();

  void shutdown() { shutdownInternal(true); }

  int runUriTest() const;
  int runDebuggerProtocolTest() const;

  XQuery_t createQuery(ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        const StaticContext_t& aContext,
        ErrorHandler* aErrorHandler = 0); 

  XQuery_t compileQuery(
        const String& aQuery,
        const Zorba_CompilerHints_t& aHints,
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        const String& aQuery,
        const StaticContext_t& aContext,
        const Zorba_CompilerHints_t& aHints, 
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const StaticContext_t& aContext,
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const Zorba_CompilerHints_t& aHints,
        ErrorHandler* aErrorHandler = 0);

  XQuery_t compileQuery(
        std::istream& aQuery,
        const StaticContext_t& aContext,
        const Zorba_CompilerHints_t& aHints, 
        ErrorHandler* aErrorHandler = 0);

  StaticContext_t createStaticContext(ErrorHandler* aErrorHandler = 0);

  ItemFactory* getItemFactory();

  XmlDataManager* getXmlDataManager();

protected:
  ZorbaImpl();

  void init(store::Store* store);

  void shutdownInternal(bool soft = true);
  
}; /* class ZorbaImpl */


} /* namespace zorba */
#endif /* XQP_ZORBA_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
