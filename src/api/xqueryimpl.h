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


namespace zorba {

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
class XQueryImpl : public XQuery 
{
  friend class ResultIteratorImpl;
  friend class ZorbaImpl; // only ZorbaImpl is allowed to create us
  friend class DynamicContextImpl;

 protected:

  class PlanProxy : public RCObject
  {
  public:
    PlanIter_t                theRootIter;

    SYNC_CODE(mutable RCLock  theRCLock;)

  public:
    long*
    getSharedRefCounter() const { return NULL; }  

    SYNC_CODE(RCLock* getRCLock() const { return &theRCLock; })

    PlanProxy(PlanIter_t& root);
  };

  typedef rchandle<PlanProxy> PlanProxy_t;

 protected:

  // static stuff
  xqpString                        theFileName;

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

 public:
  virtual ~XQueryImpl();

  void
  registerErrorHandler(ErrorHandler*);

  void
  resetErrorHandler();

  bool
  isUpdateQuery() const;

  void
  serialize(std::ostream&, const XQuery::SerializerOptions_t& = XQuery::SerializerOptions());

  void 
  applyUpdates();

  ResultIterator_t
  iterator();

  DynamicContext*
  getDynamicContext() const;

  const StaticContext*
  getStaticContext() const;

  void
  compile(const String&);

  void 
  compile(const String&, const XQuery::CompilerHints_t& aHints);
      
  void 
  compile(const String&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints);
  
  void 
  compile(std::istream&, const XQuery::CompilerHints_t& aHints);
    
  void 
  compile(std::istream&, const StaticContext_t&, const XQuery::CompilerHints_t& aHints);

  void
  setFileName( const String& );

  void
  registerSAXHandler( SAX2_ContentHandler *  aSAXHandler );
    
  void
  executeSAX( SAX2_ContentHandler *  aSAXHandler );

  void executeSAX();

  void
  close();

  XQuery_t
  clone() const;

 protected:
    
  XQueryImpl();
      
  void
  doCompile(std::istream&, const XQuery::CompilerHints_t& aHints);

  CompilerCB::config_t
  getCompilerConfig(const XQuery::CompilerHints_t&);

  void
  setSerializationParameters(serializer*, const XQuery::SerializerOptions&);

  PlanWrapper_t
  generateWrapper();

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

}; /* class XQueryImpl */


  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery);
  std::ostream& operator<< (std::ostream& os, XQuery* aQuery);


} /* namespace zorba */
#endif
