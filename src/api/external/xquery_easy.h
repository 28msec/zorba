
#ifndef ZORBA_EASY_API_XQUERY_OBJECTS_IMPLEMENTATION_12_DEC_2007
#define ZORBA_EASY_API_XQUERY_OBJECTS_IMPLEMENTATION_12_DEC_2007

#include "context/static_context_api.h"
#include "context/dynamic_context_api.h"
#include "compiler/compiled_xquery_easy.h"
#include "util/rchandle.h"
#include "util/utf8/xqpString.h"

namespace xqp{

class ZorbaEngine_SingleThread;
typedef rchandle<ZorbaEngine_SingleThread>		ZorbaEngine_SingleThread_t;

class ZorbaEngine_SingleThread : public rcobject
{
public:
	ZorbaEngine_SingleThread();//init the engine and the thread
	~ZorbaEngine_SingleThread();//uninit the thread and shutdown the engine

	static ZorbaEngine_SingleThread_t getInstance();
};

class Zorba_XQuerySimple : public XQuerySimple
{
private:
	const char *m_query_string;
	xqp_string	m_xquery_source_uri;
	StaticQueryContext_t		sctx;
	DynamicQueryContext_t		dctx;

	ZorbaEngine_SingleThread_t		keep_engine;
public:
	Zorba_XQuerySimple(const char *query_string, xqp_string	xquery_source_uri = "");
	virtual ~Zorba_XQuerySimple();

	//compile and execute the query
  virtual XQueryResult_t execute( );

	virtual StaticQueryContext_t getInternalStaticContext();
	virtual DynamicQueryContext_t getInternalDynamicContext();

	virtual ZorbaAlertsManager& getAlertsManager();
};

class Zorba_XQuerySimpleResult	: public XQueryResult
{
	XQueryExecution_t		m_xquery_exec;
	ZorbaEngine_SingleThread_t		keep_engine;
public:
	Zorba_XQuerySimpleResult(XQueryExecution_t		xquery_exec);
	virtual ~Zorba_XQuerySimpleResult();
  virtual std::ostream& serializeXML( std::ostream& os );
  virtual std::ostream& serializeHTML( std::ostream& os );
  virtual std::ostream& serializeTEXT( std::ostream& os );
};

}//end namespace xqp

#endif

