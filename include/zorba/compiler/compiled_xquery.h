
#ifndef COMPILED_XQUERY_API_12_DEC_2007
#define COMPILED_XQUERY_API_12_DEC_2007

namespace xqp {

class XQuery : public rcobject
{
public:
		virtual ~XQuery() {};

public:

    // execute the query 
		//daniel: return NULL for error
		// Matthias: again, how tu return errors? daniel: using the error manager
    // the DynamicQueryContext does not need to be passed, a default one can always be used
    virtual XQueryExecution_t createExecution( DynamicQueryContext_t = 0) = 0;

		//daniel: isn't the Query more suitable to serialize itself?
    virtual bool   serializeQuery(std::ostream &os) = 0;

public:
    // getters/setters for Static- and DynamicQueryContext
    // a default static and dynamiccontext is always available

    // Matthias: don't call it internal
    // there is no need to distinguish internal and external
		virtual StaticQueryContext_t getInternalStaticContext() = 0;
 //   DynamicQueryContextPtr getInternalDynamicContext();

public:

	//register a callback specific to this xquery object
	//	virtual void RegisterAlertCallback(alert_callback	*user_alert_callback,
	//																		void *param) = 0;
};    

typedef rchandle<XQuery>	XQuery_t;



}//end namespace xqp


#endif
