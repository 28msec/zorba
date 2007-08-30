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

namespace xqp 
{
	class Item;
	typedef rchandle<Item> Item_t;
	class BasicIterator;
	typedef rchandle<BasicIterator> Iterator_t;


	class Collection
	{
	public:
		virtual ~Collection(){}
		
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
		virtual void addToCollection(iostream& stream, int32_t position = -1) = 0;
		
		/** Deletes an item of the collection.
			*
		  * @param position of the items which will be deleted
		  */
		virtual void deleteFromCollection(int32_t position) = 0;
		
		/** Returns the URI of the collection
			*/
		virtual Item_t getURI() = 0;
	}; /* class Collection */
} /* namespace xqp */
#endif /* XQP_COLLECTION_H */
