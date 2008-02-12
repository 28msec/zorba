///Created: Daniel Turcanu @ IPDevel 


#ifndef ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007
#define ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007

#include "compiler/compiled_xquery.h"
#include "api/external/static_context_wrapper.h"

///Implement the objects for the Zorba external C++ API
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
namespace xqp{

class PlanState;

template <class Object> class rchandle;

typedef rchandle<class PlanIterator> PlanIter_t;

class	ResultIteratorWrapper;
typedef rchandle<ResultIteratorWrapper>		ResultIteratorWrapper_t;

class Zorba_XQueryBinary : public XQuery
{
  friend class ZorbaEngine;
  friend class zorba;
	friend class ResultIteratorWrapper;

private:
	xqp_string                 m_xquery_source_uri;
	xqp_string                 m_query_text;

	bool                       is_compiled;

	PlanIter_t                 top_iterator;
  std::vector<rchandle<static_context> > sctx_list;

public:
	::Collator	             * default_collator;
	rchandle<static_context>   internal_sctx;///generated at compilation

	//execution specific
public:
	///state objects for the iterator tree
	ResultIteratorWrapper_t		result;

	void			               * alert_callback_param;

public:
  Zorba_XQueryBinary(xqp_string	xquery_source_uri, xqp_string query_text);

  Zorba_XQueryBinary(Zorba_XQueryBinary *original_xquery);

  virtual ~Zorba_XQueryBinary();

  bool compile(StaticQueryContext* = 0, bool routing_mode = false);

  // start/restart the query execution
  virtual bool initExecution( DynamicQueryContext_t = 0);

  virtual bool serialize( std::ostream& os );
  virtual bool serializeXML( std::ostream& os );
  virtual bool serializeHTML( std::ostream& os );
  virtual bool serializeTEXT( std::ostream& os );

	virtual ResultIterator_t		getIterator();

  virtual bool   serializeQuery(std::ostream &os);

  virtual void	abortQueryExecution();

  virtual bool isError();

  //set param to be received by alert callback
  virtual void setAlertsParam(void *alert_callback_param);
  
	//create a duplicate of this compiled xquery
  virtual XQuery_t		clone();

public:
  // extension from dynamic context (specific only for this execution)
  virtual bool setVariableAsXQueryResult( xqp_string varname, ResultIterator_t item_iter );
  virtual bool setVariableAsDocumentFromStream( xqp_string varname, xqp_string docUri, std::istream &is );
	virtual bool setContextItemAsDocumentFromStream( xqp_string docUri, std::istream &is );
};

typedef rchandle<Zorba_XQueryBinary>		Zorba_XQueryBinary_t;

}//end namespace xqp

#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
