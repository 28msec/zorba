///Created: Daniel Turcanu @ IPDevel 

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "xquerybinary.h"
#include "util/zorba.h"
#include "errors/Error_impl.h"

///temporary stuff
#include "store/naive/basic_item_factory.h"
#include "store/naive/simple_store.h"
#include "system/globalenv.h"
#include "api/external/static_context_wrapper.h"

namespace xqp{


ZorbaFactory	*g_ZorbaFactory = NULL;


ZorbaFactory&	ZorbaFactory::getInstance()
{
	if(!g_ZorbaFactory)
	{
		g_ZorbaFactory = new ZorbaFactory;
		zorba::initializeZorbaEngine();//Store::getInstance());
	}
	return *g_ZorbaFactory;
}


void ZorbaFactory::shutdownZorbaEngine()
{
	zorba::uninitializeZorbaEngine();

	delete g_ZorbaFactory;
	g_ZorbaFactory = NULL;
}

ZorbaFactory::ZorbaFactory()
{
}

/*
ZorbaFactory::ZorbaFactory(ItemFactory *item_factory,
													Store *theStore)
{
	zorba::initializeZorbaEngine(item_factory, theStore);
}


ZorbaFactory::~ZorbaFactory()
{
	zorba::uninitializeZorbaEngine();

	g_ZorbaFactory = NULL;///kind of thread-unsafe
}
*/

void ZorbaFactory::InitThread(
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


void ZorbaFactory::UninitThread()
{
	zorba::destroyZorbaForCurrentThread();
}


XQuery_t ZorbaFactory::createQuery(const char* aQueryString,
																	 StaticQueryContext_t sctx, 
																	 xqp_string	xquery_source_uri,
																	 bool routing_mode)
{
	Zorba_XQueryBinary	*xq = new Zorba_XQueryBinary( aQueryString );

	if(!xq->compile(sctx.get_ptr(), xquery_source_uri, routing_mode))
	{
		delete xq;
		return NULL;
	}

	return xq;
}
/*
void		ZorbaFactory::destroyQuery( XQuery *query )
{
	query->removeReference();
}
*/

Zorba_AlertsManager&		ZorbaFactory::getAlertsManagerForCurrentThread()
{
	zorba	*z = zorba::getZorbaForCurrentThread();

	return *z->getErrorManager();
}

void		ZorbaFactory::setDefaultCollation(std::string  coll_string, ::Collator::ECollationStrength coll_strength)
{
	zorba::getZorbaForCurrentThread()->setDefaultCollation(coll_string, coll_strength);
}

void		ZorbaFactory::setDefaultCollation(::Collator *default_coll)
{
	zorba::getZorbaForCurrentThread()->setDefaultCollation(default_coll);
}

void		ZorbaFactory::getDefaultCollation(std::string  *coll_string, ::Collator::ECollationStrength *coll_strength, ::Collator **default_coll)
{
	zorba::getZorbaForCurrentThread()->getDefaultCollation(coll_string, coll_strength, default_coll);
}

StaticQueryContext_t ZorbaFactory::createStaticContext()
{
	return new StaticContextWrapper;
}

}//end namespace xqp
