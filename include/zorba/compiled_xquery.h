#ifndef ZORBA_XQUERY_H
#define ZORBA_XQUERY_H

#include <ostream>
#include <zorba/common/api_shared_types.h>
#include <zorba/representations.h>

namespace xqp {

  class XQuery : public SimpleRCObject
  {
    // TODO should we create a private constructor and make
    //      the zorba engine a friend of it
    //      this way, nobody else could ever create an xquery object
    public: 
      virtual ~XQuery() {};

    public:
      // start/restart the query execution
      virtual bool
      initExecution( DynamicQueryContext_t = 0 ) = 0;

      //execute completely and serialize the result
      virtual bool
      serialize     ( std::ostream &os ) = 0;
      
      virtual bool
      serializeXML  ( std::ostream &os ) = 0;
      
      virtual bool
      serializeHTML ( std::ostream &os ) = 0;
      
      virtual bool
      serializeTEXT ( std::ostream &os ) = 0;

      virtual ResultIterator_t
      getIterator () = 0;

      //serialize the query to persistent storage
      virtual bool
      serializeQuery ( std::ostream &os ) = 0;

      virtual void
      abortQueryExecution () = 0;

      // TODO: what does isError mean? Is hasError more appropriate?
      virtual bool
      isError () = 0;

      //set param to be received by alert callback
      virtual void 
      setAlertsParam ( void *alert_callback_param ) = 0;

      //create a duplicate of this compiled xquery
      virtual 
      XQuery_t clone () = 0;

      // extension from dynamic context (specific only for this execution)
      virtual bool 
      setVariableAsXQueryResult( xqp_string varname, ResultIterator_t item_iter ) = 0;
      
      virtual bool 
      setVariableAsDocumentFromStream( xqp_string varname, xqp_string docUri, std::istream &is ) = 0;

      virtual bool 
      setContextItemAsDocumentFromStream( xqp_string docUri, std::istream &is ) = 0;

  };    

} /* namespace xqp */
#endif
