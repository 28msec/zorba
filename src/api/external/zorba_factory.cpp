///Created: Daniel Turcanu @ IPDevel 

#include "zorba_api.h"
#include "store/api/item_factory.h"
#include "xquerybinary.h"

namespace xqp{

ZorbaFactory::ZorbaFactory(ItemFactory *item_factory)
{
	zorba::initializeZorbaEngine(item_factory);
}

ZorbaFactory::~ZorbaFactory()
{
	zorba::uninitializeZorbaEngine();
}

ZorbaFactory::InitThread()
{
		zorba* zorp = zorba::allocateZorbaForNewThread();//new zorba();
}

ZorbaFactory::UninitThread()
{
	zorba::destroyZorbaForCurrentThread();
}

XQuery* createQuery(xqp_string aQueryString)
{
	return new Zorba_XQueryBinary( aQueryString );
}

}//end namespace xqp
