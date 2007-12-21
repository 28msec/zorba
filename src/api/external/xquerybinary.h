///Created: Daniel Turcanu @ IPDevel 


#ifndef ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007
#define ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007

#include "zorba_api.h"
#include "api/external/static_context_wrapper.h"

///Implement the objects for the Zorba external C++ API
////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////
namespace xqp{
/*
class Zorba_DynamicContext : public DynamicQueryContext
{
private:
	bool			is_new_dynamic_context;///if the input data has been consumed or not
};

class Zorba_StaticQueryContext : public StaticQueryContext
{
};
*/

class PlanState;

template <class Object> class rchandle;

typedef rchandle<class PlanIterator> PlanIter_t;

class dynamic_context;

class Zorba_XQueryExecution : public XQueryExecution
{
	bool		theClosed;
public:
	Zorba_XQueryExecution();
	virtual ~Zorba_XQueryExecution();
  virtual Item_t next();
  virtual void reset();
  virtual void close();
	virtual void setAlertsParam(void *alert_callback_param);
	virtual ostream& serialize( ostream& os );
  virtual std::ostream& serializeXML( std::ostream& os );
  virtual std::ostream& serializeHTML( std::ostream& os );
  virtual std::ostream& serializeTEXT( std::ostream& os );
	virtual bool isError();

	virtual void	AbortQueryExecution();

	///extension from dynamic context (specific only for this execution)
	virtual bool SetVariable( xqp_string varname, XQueryExecution_t item_iter );
	virtual bool SetVariable( xqp_string varname, std::istream &is );

	///register documents available through fn:doc() in xquery
	virtual bool AddAvailableDocument(xqp_string docURI,
																		Item_t docitem);
	///register collections available through fn:collection() in xquery
	///default collection has empty URI ""
	virtual bool AddAvailableCollection(xqp_string collectionURI,
																			Collection_t collection);

public:
	PlanIter_t		it_result;
	///state objects for the iterator tree
	///this is the state block created by Zorba_XQueryBinary when doing execution
	///increments its ref count; when Zorba_Result ends its life, will decrement the ref count for state block
	PlanState		*state_block;

	void			*alert_callback_param;
	bool			is_error;

	dynamic_context		*internal_dyn_context;
};


class Zorba_XQueryBinary : public XQuery
{
    friend class ZorbaEngine;
		friend class XQueryPtr;
		friend class zorba;
public:
    Zorba_XQueryBinary(xqp_string	xquery_source_uri, const char* query_text);
    virtual ~Zorba_XQueryBinary();


private:
	xqp_string            m_xquery_source_uri;
	const char*           m_query_text;
	bool                  is_compiled;

	PlanIter_t            top_iterator;

	StaticQueryContext_t  internal_static_context;//set by user

public:
	int32_t			          lStateSize;
	::Collator	        * default_collator;
	static_context		  * internal_sctx;///generated at compilation

public:

    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    bool compile(StaticQueryContext* = 0, bool routing_mode = false);

    // execute the query 
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    virtual XQueryExecution_t createExecution( DynamicQueryContext_t = 0);

		virtual bool   serializeQuery(ostream &os);

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish internal and external
		virtual StaticQueryContext_t getInternalStaticContext();
//    DynamicQueryContextPtr getInternalDynamicContext();
};

}//end namespace xqp

#endif

