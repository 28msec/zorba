
#include "xquery_easy.h"
#include "api/external/static_context_wrapper.h"
#include "api/external/dynamic_context_wrapper.h"
#include <string.h>

namespace xqp{

Zorba_XQuerySimple::Zorba_XQuerySimple(const char *query_string, xqp_string	xquery_source_uri)
{
	m_query_string = ::strdup(query_string);
	m_xquery_source_uri = xquery_source_uri;
	keep_engine = ZorbaEngine_SingleThread::getInstance();
}

Zorba_XQuerySimple::~Zorba_XQuerySimple()
{
	::free((void*)m_query_string);
}

//compile and execute the query
XQueryResult_t Zorba_XQuerySimple::execute( )
{
	ZorbaEngine		&real_engine = ZorbaEngine::getInstance();

	XQuery_t		query;
	query = real_engine.createQuery(m_query_string, sctx, m_xquery_source_uri);
	if(query.isNull())
	{
		return NULL;
	}

	XQueryExecution_t	result = query->createExecution();
	if(result.isNull())
	{
		return NULL;
	}
	return new Zorba_XQuerySimpleResult(result);

}

StaticQueryContext_t Zorba_XQuerySimple::getInternalStaticContext()
{
	if(sctx.isNull())
		sctx = new StaticContextWrapper();
	return sctx;
}

DynamicQueryContext_t Zorba_XQuerySimple::getInternalDynamicContext()
{
	if(dctx.isNull())
		dctx = new DynamicContextWrapper();
	return dctx;
}

ZorbaAlertsManager& Zorba_XQuerySimple::getAlertsManager()
{
	ZorbaEngine		&real_engine = ZorbaEngine::getInstance();
	return real_engine.getAlertsManagerForCurrentThread();
}


Zorba_XQuerySimpleResult::Zorba_XQuerySimpleResult(XQueryExecution_t		xquery_exec) :
		m_xquery_exec(xquery_exec)
{
	keep_engine = ZorbaEngine_SingleThread::getInstance();
}

Zorba_XQuerySimpleResult::~Zorba_XQuerySimpleResult()
{
}

std::ostream& Zorba_XQuerySimpleResult::serializeXML( std::ostream& os )
{
	return m_xquery_exec->serializeXML(os);
}

std::ostream& Zorba_XQuerySimpleResult::serializeHTML( std::ostream& os )
{
	return m_xquery_exec->serializeHTML(os);
}

std::ostream& Zorba_XQuerySimpleResult::serializeTEXT( std::ostream& os )
{
	return m_xquery_exec->serializeTEXT(os);
}

}//end namespace xqp
