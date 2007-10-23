///Created: Daniel Turcanu @ IPDevel 


#ifndef ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007
#define ZORBA_XQUERY_BINARY_FOR_EXTERNAL_API_24_SEP_2007

#include "zorba_api.h"
#include "context/static_context.h"

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

class Zorba_XQueryResult : public XQueryResult
{
public:
	virtual Item_t		next();

public:
	PlanIter_t		it_result;
	///state objects for the iterator tree
	///this is the state block created by Zorba_XQueryBinary when doing execution
	///increments its ref count; when Zorba_Result ends its life, will decrement the ref count for state block
	PlanState		*state_block;
};


class Zorba_XQueryBinary : public XQuery
{
    friend class ZorbaFactory;
		friend class XQueryPtr;
		friend class zorba;
public:
    Zorba_XQueryBinary(xqp_string );
    virtual ~Zorba_XQueryBinary();


private:
	xqp_string m_query_text;
	bool		is_compiled;

//	Zorba_AlertsManager		m_error_manager;

	PlanIter_t		top_iterator;

//	zorba			*thread_specific_zorba;

	static_context		internal_static_context;
public:
//	yy::location		current_loc;

	int32_t			lStateSize;
public:


    // StaticQueryContext is optional
		//daniel: return true for success
		// Matthias: how to return errors? daniel: using the error manager
    // routing_mode: should documents in a collection be filtered or queried completely
    //         if filtered, the result will be a sequences of URI, one for each qualifying documents
    virtual bool compile(StaticQueryContext* = 0, bool routing_mode = false);

    // execute the query and compile it if necessary
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    virtual XQueryResult* execute( DynamicQueryContext* = 0);

    virtual bool isCompiled();

    // clone the query (can be compiled or not compiled)
		//daniel: not cloning, but duplicating the state block
    //Query* clone();

		virtual bool   serializeQuery(ostream &os);

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always availabe

    // Matthias: don't call it internal
    // there is no need to distinguish internal and external
		virtual StaticQueryContext* getInternalStaticContext();
//    DynamicQueryContextPtr getInternalDynamicContext();

		//daniel: get the variables out of the dynamic context class
		// Matthias: get the dynamiccontext from the query and set the variables there
		//           adhere to the XQuery processing model and don't deviate from it
		//daniel: one dynamic context object can be used in many Queries; a variable is specific to only one Query
		//				that is because an ItemIterator keeps an internal state and can be used in a single thread
//		bool		SetVariable( Zorba_QName varname, ItemIterator &item_iter );
//		bool		SetVariable( Zorba_QName varname, Item_t &item );
//		bool		DeleteVariable( Zorba_QName varname );

public:
	///error manager holds the list of errors for this Query
	///you can set a callback function into the error manager
	///when executing the Query returns false, you can get the list of errors from the error manager
//	Zorba_AlertsManager*		getAlertsManager();
};    

}//end namespace xqp

#endif

