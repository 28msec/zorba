
#ifndef COMPILED_XQUERY_API_12_DEC_2007
#define COMPILED_XQUERY_API_12_DEC_2007

#include "zorba/context/static_context_api.h"
#include "zorba/context/dynamic_context_api.h"

namespace xqp {

class XQuery;
typedef rchandle<XQuery>	XQuery_t;

class XQuery : public Iterator
{
public:
		virtual ~XQuery() {};

public:

		// start/restart the query execution
    virtual bool initExecution( DynamicQueryContext_t = 0) = 0;

		//execute completely and serialize the result
		virtual bool serialize( std::ostream& os ) = 0;
		virtual bool serializeXML( std::ostream& os ) = 0;
		virtual bool serializeHTML( std::ostream& os ) = 0;
		virtual bool serializeTEXT( std::ostream& os ) = 0;

		//get one item from result; check isError() for errors
		virtual Item_t next() = 0;

		//serialize the query to persistent storage
    virtual bool   serializeQuery(std::ostream &os) = 0;

		virtual void	AbortQueryExecution() = 0;

		virtual bool isError() = 0;

		//set param to be received by alert callback
		virtual void setAlertsParam(void *alert_callback_param) = 0;

		//create a duplicate of this compiled xquery
		virtual XQuery_t		clone() = 0;

public:

		// extension from dynamic context (specific only for this execution)
		virtual bool SetVariable( xqp_string varname, XQuery_t item_iter ) = 0;
		virtual bool SetVariable( xqp_string varname, xqp_string docUri, std::istream &is ) = 0;

		// register documents available through fn:doc() in xquery
	//	virtual bool AddAvailableDocument(xqp_string docURI,
	//																		Item_t docitem) = 0;
		// register collections available through fn:collection() in xquery
		// default collection has empty URI ""
	//	virtual bool AddAvailableCollection(xqp_string collectionURI,
	//																			Collection_t) = 0;

};    




}//end namespace xqp


#endif
