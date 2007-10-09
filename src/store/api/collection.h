/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: collection.h,v 1.1 2007/08/27 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_COLLECTION_H
#define XQP_COLLECTION_H

#include <iostream>

#include "runtime/core/batching.h"

namespace xqp 
{
	template <class Object> class rchandle;
	
	typedef rchandle<class Item> Item_t;
	typedef rchandle<class BasicIterator> Iterator_t;


	class Collection : public rcobject
	{
	public:
		virtual ~Collection(){}
		
		/**
		 * Reads the whole Collection from beginning to end; it is allowed to have several 
		 * concurrent iterators on the same Collection.
		 * 
		 * @param idsNeeded whether the returned items contain ids, e.g. for sorting
		 * @return Iterator which iterates over the complete Collection
		 * 
		 * Ids == false is likely to be faster. 'idsNeeded' should only be set to true if clients wants to 
		 * sort or compare the items or sub-items generated from the returned iterator.
		 */
		virtual Iterator_t getIterator(bool idsNeeded) = 0;
		
		/** Inserts data into the collection
		  *
			* @param item to insert
			* @param position Where to insert the item. Default -1, which means it is attached to the end. 
			*/
		virtual void addToCollection(Item_t item, int32_t position = -1) = 0;

		/** Inserts data into the collection
			*
		  * @param iterator which produces the items to insert
		  * @param position Where to insert the item. Default -1, which means it is attached to the end.
		  */
		virtual void addToCollection(Iterator_t& items, int32_t position = -1) = 0;

		/** Inserts data into the collection
		  * TODO loading from SAX & DOM
		  * @param stream which streams the data to insert (e.g. from a file)
		  * @param position Where to insert the item. Default -1, which means it is attached to the end.
		  */
		virtual void addToCollection(std::iostream& stream, int32_t position = -1) = 0;
		
		/** Deletes an item of the collection.
			*
		  * @param position of the items which will be deleted
		  */
		virtual void deleteFromCollection(int32_t position) = 0;
		
		/** Returns the URI of the collection
			* @return URI
			*/
		virtual Item_t getURI() = 0;
	}; /* class Collection */
} /* namespace xqp */
#endif /* XQP_COLLECTION_H */
