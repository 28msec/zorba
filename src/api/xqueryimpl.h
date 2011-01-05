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
#ifndef ZORBA_API_XQUERY_IMPL
#define ZORBA_API_XQUERY_IMPL

#include <iostream>
#include <zorba/xquery.h>
#include <zorba/sax2.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/mutex.h"

#include "common/shared_types.h"

#include "zorbaserialization/class_serializer.h"


namespace zorba
{

class RCObject;
class ZorbaDebugger;
class DebuggerRuntime;
class DebuggerCommons;
class DynamicContextImpl;
class StaticContextImpl;
class ResultIteratorImpl;
class dynamic_context;
class CompilerCB;


/*******************************************************************************

  - theFileName :
  The filename of the file containing the query. It is taken into account when
  computing the base uri property of the static context. It may be an empty
  string, if query does not come from a file.

  - theStaticContext :
  rchandle to the root sctx obj for this xquery. This sctx may be (a) a child
  of the zorba root sctx, or (b) a child of an sctx that was created by the
  application, or (c) if this XQuery obj is a clone of another XQuery obj, a
  child of the root sctx of the other XQuery obj, or (d) if this XQuery obj
  is one that is created internally by StaticContextImpl::loadProlog(), the
  sctx that was created by the application. In cases (a), (b), and (c), the
  root sctx of the query is created by the xquery obj itself.

  - theStaticContextWrapper :
  Pointer to a StaticContextImpl obj that wraps theStaticContext and which is
  created when the application asks for the static context of the query (see
  getStaticContext() method). The pointer is cached, so that it is returned
  if the application askes for the static context again.

  - theCompilerCB :
  A CompilerCB obj provides some additional context that is needed during the
  compilation and execution of a query. See src/compiler/api/compilercb.h for
  deetails. Each xquery obj has its own associated CompilerCB obj, which is
  created by the constructor of the xquery obj.

  - thePlanProxy :
  An rchandle to a PlanProxy obj that provides thread-safe access to the root
  iterator of the plan iterator tree. A PlanProxy obj is needed for thread
  safety, because the plan is shared among cloned queries, but the PlanIterator
  class does not do thread-safe ref counting. All clones share the same 
  PlanProxy obj, which is a sunchronized RCObject. This way, no ref count
  ops are performed on the plan root, except when the plan proxy itself is
  destroyed, which can be done by a single therad only.

  - theDynamicContext :
  The dynamic context for this query. Always belongs to the query. It is created
  by the XQueryImpl constructor.

  - theDynamicContextWrapper :

  - theResultIterator :
  There is an 0:1 relationship between ResultIterator and XQuery objs. This
  relationship is implemented by (a) theResultIterator, which is a ptr to
  a ResultIterator that has been created by the XQuery::iterator() method,
  and (b) a ptr in this ResultIterator pointing back to the associated
  XQuery. This way we can guarantee that no ResultIterator exists when its
  associated XQuery is closed (see ~ResultIterator() and XQuery::close()).

  - theIsClosed :
  Set to true when the query has been closed. Used to check that after closing
  a query, no operations can be performed on that query anymore.

  - theExecuting :
  Set to true while the query is being executed. It is used to make sure that
  a second execution of the same XQuery obj cannot be started while a previous
  execution is still going on.

  - theErrorManager :
  Each query has its own ErrorManager. The ErrorManager provides static methods
  for throwing exceptions, and can also accumulate query errors/warnings that
  need to be processed in some deferred fashion.

  - theErrorHandler :
  Normally, this is an object provided by the application to handle errors in
  some specific way (see include/zorba/error_handler.h and src/api/zorbaimpl.cpp).
  If the application does not provide an error handler, a default zorba error
  handler is created for the query (the default error handler just throws a
  ZorbaException).

  - theUserErrorHandler :
  True if the error handler was provided by the application (in which case it
  is not owned by the query). Also true if this is a cloned query, in which
  case, theErrorHandler points to the same error handler obj as the orignal
  query. False otherwise (in which case the error handler is owned by the
  query).

  - theSAX2Handler :
  sax content handler that provide event-based xml parser

  - theIsDebugMode :

  - theProfileName :

********************************************************************************/
class XQueryImpl : public XQuery , public ::zorba::serialization::SerializeBaseClass
{
  friend class ResultIteratorImpl;
  friend class StaticContextImpl;  // StaticContextImpl::loadProlog() needs this
  friend class DynamicContextImpl;
  friend class CompilerCB;
  friend class ZorbaDebugger;
  friend class DebuggerRuntime;

 protected:

  class PlanProxy : public RCObject
  {
  public:
    SYNC_CODE(mutable RCLock  theRCLock;)

    rchandle<SimpleRCObject>  theRootIter;

  public:
    SERIALIZABLE_CLASS(PlanProxy)
    SERIALIZABLE_CLASS_CONSTRUCTOR2(PlanProxy, RCObject)
    void serialize(::zorba::serialization::Archiver& ar);

  public:
    long* getSharedRefCounter() const { return NULL; }

    SYNC_CODE(virtual RCLock* getRCLock() const { return &theRCLock; })

    PlanProxy(PlanIter_t& root);
  };

  typedef rchandle<PlanProxy> PlanProxy_t;

 protected:

  SYNC_CODE(mutable Mutex            theMutex;)

  // static stuff
  zstring                            theFileName;

  static_context_t                   theStaticContext;

  mutable StaticContextImpl        * theStaticContextWrapper;

  CompilerCB                       * theCompilerCB;

  PlanProxy_t                        thePlanProxy;

  // dynamic stuff
  dynamic_context                  * theDynamicContext;

  mutable DynamicContextImpl       * theDynamicContextWrapper;

  ResultIteratorImpl               * theResultIterator;

  bool                               theExecuting;

  bool                               theIsClosed;

  // utility stuff
  error::ErrorManager              * theErrorManager;
  ErrorHandler                     * theErrorHandler;
  bool                               theUserErrorHandler;

  SAX2_ContentHandler              * theSAX2Handler;

  double                             theDocLoadingUserTime;
  double                             theDocLoadingTime;

private:
  bool                               theIsDebugMode;
  std::string                        theProfileName;

public:
  SERIALIZABLE_CLASS(XQueryImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR(XQueryImpl)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  XQueryImpl();

  ~XQueryImpl();

  void setFileName(const String&);

  String getFileName();

  void setTimeout(long aTimeout /* = -1 */);

  double getDocLoadingUserTime() const;

  double getDocLoadingTime() const;

  void setDebugMode(bool aDebugMode);

  bool isDebugMode() const;

  void setProfileName(std::string aProfileName);

  std::string getProfileName() const;

  void registerErrorHandler(ErrorHandler*);

  ErrorHandler* getRegisteredErrorHandler();

  ErrorHandler* getRegisteredErrorHandlerNoSync();

  void resetErrorHandler();

  void compile(const String&);

  void compile(
        const String&,
        const Zorba_CompilerHints_t& aHints);

  void compile(
        const String&,
        const StaticContext_t&,
        const Zorba_CompilerHints_t& aHints);

  void compile(
        std::istream&, 
        const Zorba_CompilerHints_t& aHints);

  void compile(
        std::istream&,
        const StaticContext_t&,
        const Zorba_CompilerHints_t& aHints);

  void loadProlog(
        const String&,
        const StaticContext_t&,
        const Zorba_CompilerHints_t& aHints);

  void parse(std::istream&);

  const StaticContext* getStaticContext() const;

  bool isUpdating() const;

  bool saveExecutionPlan(
        std::ostream& os,
        Zorba_binary_plan_format_t archive_format = ZORBA_USE_BINARY_ARCHIVE,
        Zorba_save_plan_options_t save_options = DONT_SAVE_UNUSED_FUNCTIONS);

  bool loadExecutionPlan(std::istream& is, SerializationCallback* aCallback = 0);

  void printPlan(std::ostream& aStream, bool aDotFormat = false) const;

  DynamicContext* getDynamicContext() const;

  void execute(std::ostream&, const Zorba_SerializerOptions_t* = NULL);

  void execute(
        std::ostream& aOutStream,
        itemHandler aCallbackFunction,
        void* aCallbackData,
        const Zorba_SerializerOptions_t* aSerOptions = NULL);

  void execute();

  Iterator_t iterator();

  void registerSAXHandler(SAX2_ContentHandler *  aSAXHandler);

  void executeSAX(SAX2_ContentHandler *  aSAXHandler);

  void executeSAX();

  void debug(
        unsigned short aCommandPort,
        unsigned short anEventPort );

  void debug(
        std::ostream& aOutStream,
        Zorba_SerializerOptions& aSerOptions,
        unsigned short aCommandPort,
        unsigned short anEventPort);

  void debug(
        std::ostream& aOutStream,
        Zorba_SerializerOptions& aSerOptions,
        const std::string& aHost,
        unsigned short aCommandPort,
        unsigned short anEventPort);

  void debug(
        std::ostream& aOutStream,
        itemHandler aCallbackFunction,
        void* aCallbackData,
        Zorba_SerializerOptions& aSerOptions,
        const std::string& aHost,
        unsigned short aCommandPort = 8000,
        unsigned short anEventPort = 9000);

  void close();

  bool isClosed() const { return theIsClosed; }

  XQuery_t clone() const;

protected:

  void doCompile(
        std::istream&,
        const Zorba_CompilerHints_t& aHints,
        bool fork_sctx = true);

  PlanWrapper_t generateWrapper();

  // special serialize and applyUpdate function that is used by debugger
  // and by the public serialize and applyUpdate functions, respectively.
  // they are passed an opened PlanWrapper
  // important: this function does not (read/write) lock the store. this
  // needs to be done by the caller of this function
  // also note that the PlanWrapper that is passed to this function needs
  // to be generated by the generateWrapper of the same object
  // there is currently no check that enforces this
  // after this function has finished, the PlanWrapper also needs to be
  // closed by the caller
  void serialize(
        std::ostream&,
        PlanWrapper_t& aWrapper,
        const Zorba_SerializerOptions_t* = NULL);

  void serialize(
        std::ostream&,
        PlanWrapper_t& aWrapper,
        itemHandler aHandler,
        void* aHandlerData,
        const Zorba_SerializerOptions_t* = NULL);

  void removeResultIterator(const ResultIteratorImpl* iter);

  void checkNotClosed() const;

  void checkCompiled() const;

  void checkNotCompiled() const;

  void checkNotExecuting() const;

  void checkIsDebugMode() const;
};


std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery);

std::ostream& operator<< (std::ostream& os, XQuery* aQuery);


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
