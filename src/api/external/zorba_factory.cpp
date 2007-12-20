///Created: Daniel Turcanu @ IPDevel 

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "xquerybinary.h"
#include "util/zorba.h"
#include "errors/Error_impl.h"

//#include "store/naive/basic_item_factory.h"
//#include "store/naive/simple_store.h"
#include "system/globalenv.h"
#include "api/external/static_context_wrapper.h"
#include "api/external/dynamic_context_wrapper.h"
#include "api/serialization/serializer.h"

namespace xqp{


ZorbaEngine	*g_ZorbaFactory = NULL;


ZorbaEngine&	ZorbaEngine::getInstance()
{
	if(!g_ZorbaFactory)
	{
		g_ZorbaFactory = new ZorbaEngine;
		zorba::initializeZorbaEngine();//Store::getInstance());
	}
	return *g_ZorbaFactory;
}

void ZorbaEngine::startupZorbaEngine()
{
	getInstance();
}

void ZorbaEngine::shutdownZorbaEngine()
{
	zorba::uninitializeZorbaEngine();

	delete g_ZorbaFactory;
	g_ZorbaFactory = NULL;
}

ZorbaEngine::ZorbaEngine()
{
}

/*
ZorbaEngine::ZorbaEngine(ItemFactory *item_factory,
													Store *theStore)
{
	zorba::initializeZorbaEngine(item_factory, theStore);
}


ZorbaEngine::~ZorbaEngine()
{
	zorba::uninitializeZorbaEngine();

	g_ZorbaFactory = NULL;///kind of thread-unsafe
}
*/

void ZorbaEngine::InitThread(
    error_messages* em)//=NULL
//    const char *collator_name,// = "root",
//    ::Collator::ECollationStrength collator_strength)// = Collator::PRIMARY)
{
	zorba* zorp = zorba::allocateZorbaForCurrentThread();

	if(!em)
	{
		errors_english	*err_messages = new errors_english;///the english error messages
		zorp->m_error_manager->err_messages = err_messages;
	}
	else
		zorp->m_error_manager->err_messages = em;

//	zorp->coll_string = collator_name;
//	zorp->coll_strength = collator_strength;

}


void ZorbaEngine::UninitThread()
{
	zorba::destroyZorbaForCurrentThread();
}


XQuery_t ZorbaEngine::createQuery(const char* aQueryString,
																	 StaticQueryContext_t sctx, 
																	 xqp_string	xquery_source_uri,
																	 bool routing_mode)
{
	Zorba_XQueryBinary	*xq = new Zorba_XQueryBinary( xquery_source_uri, aQueryString );

	if(!xq->compile(sctx.get_ptr(), routing_mode))
	{
		delete xq;
		return NULL;
	}

	return xq;
}
/*
void		ZorbaEngine::destroyQuery( XQuery *query )
{
	query->removeReference();
}
*/

Zorba_AlertsManager&		ZorbaEngine::getAlertsManagerForCurrentThread()
{
	zorba	*z = zorba::getZorbaForCurrentThread();

	return *z->getErrorManager();
}

void		ZorbaEngine::setDefaultCollation(std::string  coll_string, ::Collator::ECollationStrength coll_strength)
{
	zorba::getZorbaForCurrentThread()->setDefaultCollation(coll_string, coll_strength);
}

void		ZorbaEngine::setDefaultCollation(::Collator *default_coll)
{
	zorba::getZorbaForCurrentThread()->setDefaultCollation(default_coll);
}

void		ZorbaEngine::getDefaultCollation(std::string  *coll_string, ::Collator::ECollationStrength *coll_strength, ::Collator **default_coll)
{
	zorba::getZorbaForCurrentThread()->getDefaultCollation(coll_string, coll_strength, default_coll);
}

void	ZorbaEngine::setItemSerializerParameter(xqp_string parameter_name, xqp_string value)
{
	zorba::getZorbaForCurrentThread()->getItemSerializer()->set_parameter(parameter_name, value);
}

void	ZorbaEngine::setDocSerializerParameter(xqp_string parameter_name, xqp_string value)
{
	zorba::getZorbaForCurrentThread()->getDocSerializer()->set_parameter(parameter_name, value);
}

StaticQueryContext_t ZorbaEngine::createStaticContext()
{
	return new StaticContextWrapper;
}

DynamicQueryContext_t ZorbaEngine::createDynamicContext()
{
	return new DynamicContextWrapper;
}
}//end namespace xqp
