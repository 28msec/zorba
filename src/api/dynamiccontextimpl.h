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
#ifndef ZORBA_DYNAMIC_CONTEXT_IMPL_H
#define ZORBA_DYNAMIC_CONTEXT_IMPL_H

#include <zorba/dynamic_context.h>

#include "zorbautils/mutex.h"

#include "common/shared_types.h"
#include "api/xqueryimpl.h"


namespace zorba {

class ErrorHandler;


/*******************************************************************************

  Wrapper of the internal dynamic_context class. 

  An instance of DynamicContextImpl is created when the application asks for
  the dynamic context of a query (see XQueryImpl::getDynamicContext() method).
  There can be at most one instance of DynamicContextImpl per XQuery.
  DynamicContextImpl does not own any of the other objs that it points to.

  theCtx :
  Pointer to the internal dynamic_context obj (which is owned by the XQuery obj).
  
  theStaticContext :
  Pointer to the internal static_context obj (which is owned by the XQuery obj).
  Access to the static context is needed to resolve names, etc.

  theErrorHandler :
  Pointer to the error handler of the query (which is owned either by the XQuery
  obj or the application).

  theCloningMutexp :
  Pointer to the cloning mutex of the query (which is owned by the XQuery obj).

********************************************************************************/
class DynamicContextImpl : public DynamicContext
{
  friend class Unmarshaller; // needs to get the context out of this class
  friend class XQueryImpl;

protected:
  const XQueryImpl          * theQuery;

  dynamic_context           * theCtx;

  static_context            * theStaticContext;

  SYNC_CODE(Mutex           * theCloningMutexp;)

protected:
  DynamicContextImpl(const XQueryImpl* aQuery);

  virtual ~DynamicContextImpl();

public:
  virtual bool
  setVariable(
        const String& aQName,
        const Item& aItem );

  virtual bool
  setVariable(
        const String& aQName,
        const ResultIterator_t& aResultIterator );

  virtual bool
  setVariableAsDocument(
        const String& aQName,
        const String& aDocURI,
        std::istream& aStream );;

  virtual bool
  setVariableAsDocument(
        const String& aQName,
        const String& aDocURI,
        std::istream* aStream );;

  virtual bool
  setContextItem ( const Item& aItem );

  virtual bool
  setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream );

  virtual bool
  setContextItemAsDocument ( const String& aDocURI, std::istream* aInStream );

  virtual bool
  setCurrentDateTime( const Item& aDateTimeItem );
      
  virtual Item
  getCurrentDateTime( );

  // In minutes
  virtual bool
  setImplicitTimezone( int aTimezoneMinutes );

  // In minutes
  virtual int
  getImplicitTimezone();

  virtual bool
  setDefaultCollection( const Item& aCollectionUri );

protected:
  void checkNoIterators();
};

} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
