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
#ifndef XQP_XQUERY_IMPL_H
#define XQP_XQUERY_IMPL_H

#include <iostream>
#include <zorba/xquery.h>
#include <zorba/sax2.h>

#include <zorba/api_shared_types.h>

#include "zorbautils/mutex.h"
#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h" 
#include "compiler/api/compilercb.h"
#include "context/dynamic_context.h"

namespace zorba {

class RCObject;
class ZorbaDebugger;
class ZorbaDebuggerRuntime;
class ZorbaDebuggerCommons;
class DynamicContextImpl;
class StaticContextImpl;
class ResultIteratorImpl;


/*******************************************************************************

  - theFileName :
  The filename of the query

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

  - theStaticContext : 
  Pointer to the static context for this xquery. This sctx is a child of the
  zorba root sctx, or a child of an sctx that was created by the application.
  In both cases, the sctx of the query is owned by the query, and is deleted
  during the desctruction of the query. Note: after a query is compiled, its
  sctx cannot be changed.

  - theStaticContextWrapper :
  Pointer to a StaticContextImpl obj that wraps theStaticContext and which is
  created when the application asks for the static context of the query (see
  getStaticContext() method). The pointer is cached, so that it is returned
  if the application askes for the static context again.

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

  - theErrorHandler :
  Normally, this is an object provided by the application to handle errors in
  some specific way. If the application does not provide an error handler, a
  default zorba error handler is created for the query (the default error
  handler just throws a ZorbaException).

  - theUserErrorHandler :
  True if the error handler was provided by the application (in which case it
  is not owned by the query). Also true if this is a cloned query, in which
  case, theErrorHandler points to the same error handler obj as the orignal
  query. False otherwise (in which case the error handler is owned by the
  query).

  - theErrorManager :
  Currently, it always belongs to the query. See note in the constructor.

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
  xqpString                        theFileName;

  std::map<short, static_context_t>  theSctxMap;

  CompilerCB                     * theCompilerCB;

  PlanProxy_t                      thePlan; 

  static_context                 * theStaticContext;
  
  // dynamic stuff
  dynamic_context                * theDynamicContext;

  mutable DynamicContextImpl     * theDynamicContextWrapper;
  mutable StaticContextImpl      * theStaticContextWrapper;

  std::vector<ResultIteratorImpl*> theResultIterators;

  // utility stuff
  bool                             theUserErrorHandler; 
  ErrorHandler                   * theErrorHandler; 
    
  error::ErrorManager            * theErrorManager; 

  SAX2_ContentHandler            * theSAX2Handler; 
    
  bool                             theIsClosed;


  SYNC_CODE(mutable Mutex          theCloningMutex;)

  double                           theDocLoadingUserTime;
  long                             theDocLoadingTime;

  long                             theTimeout;

public:
  SERIALIZABLE_CLASS(XQueryImpl)
  SERIALIZABLE_CLASS_CONSTRUCTOR(XQueryImpl)
  void serialize(::zorba::serialization::Archiver &ar)
  {
  // static stuff
    ar & theFileName;
    if(!ar.is_serializing_out())
    {
      delete theCompilerCB;
      //ar.xquery_impl = this;
    }
    else
      ar.compiler_cb = theCompilerCB;
    ar & theCompilerCB;
    ar & theSctxMap;
    ar & thePlan; 
    ar & theStaticContext;
    if(!ar.is_serializing_out())
    {
      RCHelper::addReference (theStaticContext);
      theDynamicContextWrapper = NULL; 
      theStaticContextWrapper = NULL;//new StaticContextImpl(theStaticContext, theErrorHandler); 

      theIsClosed = false;

      theCompilerCB->m_error_manager = theErrorManager;
    }
    ar & theTimeout;
  }

public:
  virtual ~XQueryImpl();

  void
  registerErrorHandler(ErrorHandler*);

  void
  resetErrorHandler();

  bool
  isUpdateQuery() const;

  void
  setTimeout(long aTimeout /* = -1 */);

  void
  serialize(std::ostream&, const Zorba_SerializerOptions_t* = NULL);

  void 
  applyUpdates();

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
  loadProlog (const String&, const StaticContext_t&, const Zorba_CompilerHints_t& aHints);

  void
  setFileName( const String& );

  String
  getFileName();

  void
  registerSAXHandler( SAX2_ContentHandler *  aSAXHandler );
    
  void
  executeSAX( SAX2_ContentHandler *  aSAXHandler );

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
  saveExecutionPlan(std::ostream &os, Zorba_binary_plan_format_t archive_format);

  bool
  loadExecutionPlan(std::istream &is, SerializationCallback* aCallback = 0);

  static void
  setSerializationParameters(serializer*, const Zorba_SerializerOptions_t*);

protected:
    
  XQueryImpl();
      
  void
  doCompile(std::istream&, const Zorba_CompilerHints_t& aHints, bool fork_sctx = true);

  CompilerCB::config_t
  getCompilerConfig(const Zorba_CompilerHints_t&);

  PlanWrapper_t
  generateWrapper();

  friend class ZorbaDebugger;
  friend class ZorbaDebuggerRuntime;
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
  void
  serialize(std::ostream&, PlanWrapper_t& aWrapper, const Zorba_SerializerOptions_t* = NULL);

  void 
  applyUpdates(PlanWrapper_t& aWrapper);

  void
  removeResultIterator(const ResultIterator* iter);

  // check whether the query is open, and if not, fire an error
  void
  checkNotClosed() const;

  // check whether the query has been compiled (successfully), and
  // if not, fire an error
  void
  checkCompiled() const;

  // check whether the query has not been compiled, and if not, fire an error
  void
  checkNotCompiled() const;

 private:
  bool theIsDebugMode;
  std::string theProfileName;
 
 protected:
  void
  checkIsDebugMode() const;

 public:
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
}; /* class XQueryImpl */


  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery);
  std::ostream& operator<< (std::ostream& os, XQuery* aQuery);


} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
