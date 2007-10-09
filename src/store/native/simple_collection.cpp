/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */
#include "util/rchandle.h"

#include "simple_collection.h"

namespace xqp
{
	typedef rchandle<BasicIterator> Iterator_t;

	SimpleCollection::SimpleCollection()
	{

	}
	SimpleCollection::~SimpleCollection()
	{

	}

	Iterator_t SimpleCollection::getIterator ( bool isNeeded )
	{
		return rchandle<BasicIterator> ( NULL );
	}
	void SimpleCollection::addToCollection ( Item_t item, int32_t position )
	{
	}
	void SimpleCollection::addToCollection ( Iterator_t& items, int32_t position )
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
