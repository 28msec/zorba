#ifndef ZORBA_DYNAMIC_CONTEXT_API_H
#define ZORBA_DYNAMIC_CONTEXT_API_H

#include <time.h>
#include <istream>

#include <zorba/api_shared_types.h>

namespace zorba {

  class DynamicContext 
  {
    public:
      virtual ~DynamicContext( ) {};

      virtual bool
      setVariable( const String& aQName, const Item& aItem ) = 0;

      virtual bool
      setVariable( const String& aQName, const ResultIterator_t& aResultIterator ) = 0;

      virtual bool
      setVariableAsDocument ( const String& aQName, const String& aDocURI, std::istream& ) = 0;

      virtual bool
      setContextItem ( const Item& aItem ) = 0;

      virtual bool
      setContextItemAsDocument ( const String& aDocURI, std::istream& aInStream ) = 0;

      virtual bool
      setCurrentDateTime( const Item& aDateTimeItem ) = 0;
      
      virtual Item
      getCurrentDateTime( ) = 0;

      virtual bool
      setImplicitTimezone( int aTimezone ) = 0;

      virtual int
      getImplicitTimezone() = 0;

      virtual bool
      setDefaultCollection( const Item& aCollectionUri ) = 0;


#if 0
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
