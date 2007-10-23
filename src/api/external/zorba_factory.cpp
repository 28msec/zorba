///Created: Daniel Turcanu @ IPDevel 

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "xquerybinary.h"
#include "util/zorba.h"

namespace xqp{

ZorbaFactory::ZorbaFactory(ItemFactory *item_factory,
													Store *theStore)
{
	zorba::itemFactory = item_factory;
	zorba::theStore = theStore;

	zorba::initializeZorbaEngine();//item_factory);

}

ZorbaFactory::~ZorbaFactory()
{
	zorba::uninitializeZorbaEngine();
}

void ZorbaFactory::InitThread(//ItemFactory *item_factory,
												 error_messages *em,//=NULL
													char *collator_name,// = "root",
													::Collator::ECollationStrength collator_strength)// = Collator::PRIMARY)
{
	zorba* zorp = zorba::allocateZorbaForNewThread();
	//zorp->itemFactory = item_factory;
	if(!em)
	{
		errors_english	*err_messages = new errors_english;///the english error messages
		zorp->m_error_manager.err_messages = err_messages;
	}
	else
		zorp->m_error_manager.err_messages = em;

	zorp->coll_string = collator_name;
	zorp->coll_strength = collator_strength;

}

void ZorbaFactory::UninitThread()
{
	zorba::destroyZorbaForCurrentThread();
}

XQuery* ZorbaFactory::createQuery(xqp_string aQueryString)
{
	return new Zorba_XQueryBinary( aQueryString );
}

void		ZorbaFactory::destroyQuery( XQuery *query )
{
	query->removeReference();
}

}//end namespace xqp
