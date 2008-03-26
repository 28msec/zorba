#ifndef XQP_XQUERY_API_H
#define XQP_XQUERY_API_H

#include <ostream>

#include <zorba/api_shared_types.h>


namespace zorba {


  class XQuery 
  {
    public:
      virtual ~XQuery() {}

      // register an error handler
      // if no error handler has already been set when creating the query
      // the default error handler (i.e. throwing exceptions) is used
      virtual void
      registerErrorHandler(ErrorHandler*) = 0;

      // xml serialization
      // prepares the query with the default dynamic that belongs to this query
      // it can be retrieved using getDynamicContext. 
      virtual void
      serialize(std::ostream&) = 0;

      // get an result iterator
      // prepares the query with the default dynamic context if non is set using prepare
      virtual ResultIterator_t
      iterator() = 0;

      // get the static context of this query
      // you can modify it and afterwards execute the query with the changes that were applied
      virtual DynamicContext_t
      getDynamicContext() = 0;

      // get the static context that belongs to this query
      // the static context has all the components and values that have been
      // set before (by supplying a static context) compiling the query and
      // those that have been changed while compiling the query (e.g. in the query prolog)
      virtual StaticContext_t
      getStaticContext() = 0;

  };

  // xml serialization of the query (equiv to calling serialize(os) 
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

} /* namespace zorba */

#endif
