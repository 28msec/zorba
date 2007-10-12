/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */
#include "util/rchandle.h"
#include "store/naive/simple_collection.h"

namespace xqp
{
	typedef rchandle<PlanIterator> PlanIter_t;

	SimpleCollection::SimpleCollection()
	{

	}
	SimpleCollection::~SimpleCollection()
	{

	}

	PlanIter_t SimpleCollection::getIterator ( bool isNeeded )
	{
		return rchandle<PlanIterator> ( NULL );
	}
	void SimpleCollection::addToCollection ( Item_t item, int32_t position )
	{
	}
	void SimpleCollection::addToCollection ( PlanIter_t& items, int32_t position )
	{
	}
	void SimpleCollection::addToCollection ( std::iostream& stream, int32_t position )
	{
	}
	void SimpleCollection::deleteFromCollection ( int32_t position )
	{

	}
	Item_t SimpleCollection::getURI()
	{
		return rchandle<Item> ( NULL );
	}
} /* namespace xqp */
