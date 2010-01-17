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

#include <map>
#include <iostream>
#include <zorba/xquery.h>
#include <zorba/sax2.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/mutex.h"

#include "common/shared_types.h" 

#include "zorbatypes/xqpstring.h"

#include "zorbaserialization/class_serializer.h"

//#include "compiler/api/compilercb.h"


namespace zorba 
{

class RCObject;
class ZorbaDebugger;
class ZorbaDebuggerRuntime;
class ZorbaDebuggerCommons;
class DynamicContextImpl;
class StaticContextImpl;
class ResultIteratorImpl;
class dynamic_context;
class CompilerCB;


/*******************************************************************************

  - theFileName :
  The filename of the query.

  - theStaticContext : 
  rchandle to the root static context for this xquery. This sctx may be (a) a
  child of the zorba root sctx, or (b) a child of an sctx that was created by
  the application, or (c) if this XQuery obj is a clone of another XQuery obj,
  a child of the root sctx of the other XQuery obj, or (d) if this XQuery obj
  is one that is created internally by StaticContextImpl::loadProlog(), the
  sctx that was created by the application. In cases (a), (b), and (c), the
  root sctx of the query is owned by the query, and will be deleted during
  the desctruction of the query.

  - theStaticContextWrapper :
  Pointer to a StaticContextImpl obj that wraps theStaticContext and which is
  created when the application asks for the static context of the query (see
  getStaticContext() method). The pointer is cached, so that it is returned
  if the application askes for the static context again.

  - theSctxMap :
  A query-level map that stores the sctx objs that need to be kept around for
  the whole duration of a query (including runtime). In non-DEBUGGER mode,
  the map stores only for root sctx of each module. In DEBUGGER mode, it
  stores all the sctxs created by each module. Each sctx stored in this map
  has an associated numeric id, and theSctxMap actually maps these numeric
  ids to their associated sctx objs. The map is modified by the methods
  TranslatorImpl::end_visit(ModuleImport) and TranslatorImpl::push_scope().

  - theCompilerCB :

  - thePlan :
  Provides access to the root iterator of the plan iterator tree.
  Note: The root iterator is made accessible via a PlanProxy obj. This is for
  thread safe operation, because the plan is shared among cloned queries. If a
  direct rchandle to the root iterator was used, then PlanIterator would have
  to be made a synchronized RCObject, which is too much overhead given that
  we only need the synchronization during cloning and closing of a query.

  - theIsClosed :
  Set to true when the query has been closed. Used to check that after closing
  a query, no operations can be performed on that query anymore.

  - theDynamicContext :
  The dynamic context for this query. Always belongs to the query.

  - theDynamicContextWrapper :

  - theResultIterators :
  There is an N:1 relationship between ResultIterator and XQuery objs. This
  relationship is implemented by (a) theResultIterators vector, which contains
  a ptr to each ResultIterator that has been created by the XQuery::iterator()
  method, and (b) a ptr in each ResultIterator pointing back to the associated
  XQuery. This way we can guarantee that no ResultIterator objs can exists when
  their associated XQuery is closed (see ~ResultIterator() and XQuery::close()).

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
 
********************************************************************************/
class XQueryImpl : public XQuery , public ::zorba::serialization::SerializeBaseClass
{
  friend class ResultIteratorImpl;
  friend class ZorbaImpl; // only ZorbaImpl is allowed to create us
  friend class StaticContextImpl;  // StaticContextImpl::loadProlog() needs this
  friend class DynamicContextImpl;
  friend class CompilerCB;
  friend class ZorbaDebugger;
  friend class ZorbaDebuggerRuntime;

 protected:

  class PlanProxy : public RCObject
  {
  public:
    rchandle<SimpleRCObject>  theRootIter;

    SYNC_CODE(mutable RCLock  theRCLock;)

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

  // static stuff
  xqpString                          theFileName;

  static_context                   * theStaticContext;

  mutable StaticContextImpl        * theStaticContextWrapper;

  std::map<short, static_context_t>  theSctxMap;

  CompilerCB                       * theCompilerCB;

  PlanProxy_t                        thePlan; 
  
  // dynamic stuff
  dynamic_context                  * theDynamicContext;

  mutable DynamicContextImpl       * theDynamicContextWrapper;

  std::vector<ResultIteratorImpl*>   theResultIterators;

  // utility stuff
  error::ErrorManager              * theErrorManager; 
  ErrorHandler                     * theErrorHandler; 
  bool                               theUserErrorHandler; 

  SAX2_ContentHandler              * theSAX2Handler; 
    
  bool                               theIsClosed;


  SYNC_CODE(mutable Mutex            theCloningMutex;)

  double                             theDocLoadingUserTime;
  long                               theDocLoadingTime;

  long                               theTimeout;

private:
  bool                               theIsDebugMode;
  std::string                        theProfileName;

public:
  SERIALIZABLE_CLASS(XQueryImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR(XQueryImpl)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  virtual ~XQueryImpl();

  void
  registerErrorHandler(ErrorHandler*);

  void
  resetErrorHandler();

  void
  setTimeout(long aTimeout /* = -1 */);

  void
  execute(std::ostream&, const Zorba_SerializerOptions_t* = NULL);

  virtual void
  execute(
        std::ostream& aOutStream,
        itemHandler aCallbackFunction,
        void* aCallbackData,
        const Zorba_SerializerOptions_t* aSerOptions = NULL);

  void
  execute();

  ResultIterator_t
  iterator();

  DynamicContext*
  getDynamicContext() const;

  const StaticContext*
  getStaticContext() const;

  void
  parse(std::istream&);

  void
  compile(const String&);

  void 
  compile(const String&, const Zorba_CompilerHints_t& aHints);
      
  void 
  compile(const String&, const StaticContext_t&, const Zorba_CompilerHints_t& aHints);
  
  void 
  compile(std::istream&, const Zorba_CompilerHints_t& aHints);
    
  void 
  compile(std::istream&, const StaticContext_t&, const Zorba_CompilerHints_t& aHints);

  void
  printPlan( std::ostream& aStream, bool aDotFormat = false ) const;

  void
  loadProlog(const String&, const StaticContext_t&, const Zorba_CompilerHints_t& aHints);

  void
  setFileName(const String&);

  String
  getFileName();

  void
  registerSAXHandler(SAX2_ContentHandler *  aSAXHandler);
    
  void
  executeSAX(SAX2_ContentHandler *  aSAXHandler);

  void executeSAX();

  virtual double
  getDocLoadingUserTime() const;

  long
  getDocLoadingTime() const;

  void
  close();

  bool
  isClosed() const { return theIsClosed; }

  XQuery_t
  clone() const;

  bool
  isUpdating() const;

  bool
  saveExecutionPlan(std::ostream& os, Zorba_binary_plan_format_t archive_format);

  bool
  loadExecutionPlan(std::istream& is, SerializationCallback* aCallback = 0);

  void
  setDebugMode( bool aDebugMode );

  bool
  isDebugMode() const;

  void
  setProfileName(std::string aProfileName);

  std::string
  getProfileName() const;
  
  void
  debug( unsigned short aCommandPort, unsigned short anEventPort );

  void
  debug(std::ostream& aOutStream,
        Zorba_SerializerOptions& aSerOptions,
        unsigned short aCommandPort, unsigned short anEventPort);

protected:
    
  XQueryImpl();
      
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

  void removeResultIterator(const ResultIterator* iter);

  // check whether the query is open, and if not, fire an error
  void checkNotClosed() const;

  // check whether the query has been compiled (successfully), and
  // if not, fire an error
  void checkCompiled() const;

  // check whether the query has not been compiled, and if not, fire an error
  void checkNotCompiled() const;
 
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
