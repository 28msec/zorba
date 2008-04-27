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

#include "common/shared_types.h"

namespace zorba {

  class ErrorHandler;

  class DynamicContextImpl : public DynamicContext
  {
    public:
      DynamicContextImpl(dynamic_context* dctx, static_context* sctx, ErrorHandler* aErrorHandler);
      virtual ~DynamicContextImpl();

      virtual bool
      setVariable( const String& aQName, const Item& aItem );

      virtual bool
      setVariable( const String& aQName, const ResultIterator_t& aResultIterator );

      virtual bool
      setVariableAsDocument( const String& aQName, const String& aDocURI, std::istream& aStream );;

      virtual bool
      setContextItem ( const Item& aItem );

      virtual bool
      setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream );

      virtual bool
      setCurrentDateTime( const Item& aDateTimeItem );
      
      virtual Item
      getCurrentDateTime( );

      virtual bool
      setImplicitTimezone( int aTimezone );

      virtual int
      getImplicitTimezone();

      virtual bool
      setDefaultCollection( const Item& aCollectionUri );

      friend class Unmarshaller; // needs to get the context out of this class
    protected:
      // we do not held ownership for any of these objects
      // because the dynamic context can only be created out of a query
      dynamic_context* theCtx;

      // we need the according dynamic context to resolve names, etc.
      static_context*  theStaticContext;

      // this is the error handler of the query
      ErrorHandler* theErrorHandler;
  };

} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
