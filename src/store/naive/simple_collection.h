/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_SIMPLE_COLLECTION_H
#define XQP_SIMPLE_COLLECTION_H

#include "store/api/collection.h"

namespace xqp
{
	class SimpleCollection : public Collection
	{
		public:
			SimpleCollection();
			virtual ~SimpleCollection();

			virtual Iterator_t getIterator ( bool isNeeded );
			virtual void addToCollection(Item_t item, int32_t position = -1);
			virtual void addToCollection(Iterator_t& items, int32_t position = -1);
			virtual void addToCollection(std::iostream& stream, int32_t position = -1);
			virtual void deleteFromCollection ( int32_t position );
			virtual Item_t getURI();
	}; /* class SimpleCollection */
} /* namespace xqp */

#endif /* XQP_SIMPLE_COLLECTION_H */
