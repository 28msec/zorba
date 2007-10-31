///Created: Daniel Turcanu @ IPDevel 

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "xquerybinary.h"
#include "util/zorba.h"

namespace xqp{

ZorbaFactory::ZorbaFactory(
    ItemFactory *item_factory,
    Store *theStore)
{
	zorba::initializeZorbaEngine(item_factory, theStore);
}


ZorbaFactory::~ZorbaFactory()
{
	zorba::uninitializeZorbaEngine();
}


void ZorbaFactory::InitThread(
    error_messages *em,//=NULL
    const char *collator_name,// = "root",
    ::Collator::ECollationStrength collator_strength)// = Collator::PRIMARY)
{
	zorba* zorp = zorba::allocateZorbaForCurrentThread();

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


XQuery_t ZorbaFactory::createQuery(const char* aQueryString)
{
	return new Zorba_XQueryBinary( aQueryString );
}
/*
void		ZorbaFactory::destroyQuery( XQuery *query )
{
	query->removeReference();
}
*/
}//end namespace xqp
