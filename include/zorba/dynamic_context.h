#ifndef ZORBA_DYNAMIC_CONTEXT_API_H
#define ZORBA_DYNAMIC_CONTEXT_API_H

#include <time.h>
#include <istream>

#include <zorba/api_shared_types.h>

namespace zorba {

  class ResultIterator;

  class DynamicContext 
  {
    public:
      virtual ~DynamicContext( ) {};

      virtual void
      setVariable( const String& aQName, const Item& aItem ) = 0;

      virtual void
      setVariable( const String& aQName, const ItemSequence_t& aSequence ) = 0;

      virtual void
      setVariable( const String& aQName, const ResultIterator& aResultIterator ) = 0;

      virtual void
      setVariableAsDocument ( const String& aQName, const String& aDocURI, std::istream& ) = 0;

      virtual void
      setContextItem ( const Item& aItem ) = 0;

      virtual void
      setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream ) = 0;

#if 0
      virtual void
      setCurrentDateTime( struct ::tm datetime, long timezone_seconds ) = 0;
      
      virtual struct
      ::tm getCurrentDateTime( long *timezone_seconds ) = 0;

      virtual bool
      deleteVariable( xqp_string varname ) = 0;

      virtual void
      deleteAllVariables( ) = 0;
#endif
  };

} /* namespace zorba */
#endif

/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
