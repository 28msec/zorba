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
      // prepares the query with the default dynamic context if non is set using prepare
      virtual void
      serialize(std::ostream&) = 0;

      // get an result iterator
      // prepares the query with the default dynamic context if non is set using prepare
      virtual ResultIterator_t
      iterator() = 0;

      virtual DynamicContext_t
      getDynamicContext() = 0;

  };

  // xml serialization of the query (equiv to calling serialize(os) 
  std::ostream& operator<< (std::ostream& os, const XQuery_t& aQuery); 

} /* namespace zorba */

#endif
