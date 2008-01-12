
#ifndef COMPILED_XQUERY_EASY_API_12_DEC_2007
#define COMPILED_XQUERY_EASY_API_12_DEC_2007

#include "util/rchandle.h"


namespace xqp {

class ZorbaAlertsManager;

typedef rchandle<class XQueryResult> XQueryResult_t;
typedef rchandle<class StaticQueryContext> StaticQueryContext_t;
typedef rchandle<class DynamicQueryContext> DynamicQueryContext_t;


class XQuerySimple : public rcobject
{
public:
		virtual ~XQuerySimple() {};

		//compile and execute the query
    virtual XQueryResult_t execute( ) = 0;

		virtual StaticQueryContext_t getInternalStaticContext() = 0;
		virtual DynamicQueryContext_t getInternalDynamicContext() = 0;

		virtual ZorbaAlertsManager& getAlertsManager() = 0;
};


typedef rchandle<XQuerySimple>	XQuerySimple_t;



}//end namespace xqp


#endif
