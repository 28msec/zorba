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

      virtual void
      setVariable( const String& aQName, const Item& aItem );

      virtual void
      setVariable( const String& aQName, const ItemSequence_t& aSequence );

      virtual void
      setVariable( const String& aQName, const ResultIterator& aResultIterator );

      virtual void
      setVariableAsDocument( const String& aQName, const String& aDocURI, std::istream& aStream );;

      virtual void
      setContextItem ( const Item& aItem );

      virtual void
      setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream );

      virtual void
      setCurrentDateTime( const Item& aDateTimeItem );
      
      virtual Item
      getCurrentDateTime( );

      virtual void
      setImplicitTimezone( int aTimezone );

      virtual int
      getImplicitTimezone();

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
