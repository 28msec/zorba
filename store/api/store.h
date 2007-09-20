/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*-
 *
 *  $Id: item.h,v 1.1 2006/10/09 07:07:59 $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf, Donald Kossmann, Tim Kraska
 *
 */

#ifndef XQP_STORE_H
#define XQP_STORE_H

#include <string>

#include "../../types/representations.h"

namespace xqp
{

	template <class Object> class rchandle;
	
	typedef rchandle<class BasicIterator> Iterator_t;
	typedef rchandle<class Item> Item_t;
	typedef rchandle<class Collection> Collection_t;
	typedef rchandle<class TempSeq> TempSeq_t;
	typedef rchandle<class PUL> PUL_t;
	class Timetravel;
	class Requester;
	

	/** Manages XDM Instances 
		*/
	class Store : public rcobject
	{
	public:
		virtual ~Store(){}
		
		/*-------------------------------------- Zorba Engine Internal ------------------------------------*/
		/**
			* Creates a new TempSeq. The instance can be used, e.g. for variable bindings
			* @param iterator The source for the XMDInstance
			* @param lazy			Hint for the store. If possible a XMDInstance should be evaluated lazily. For XQueryP it might be necassary to set this to false. 
			*/
		virtual TempSeq_t createTempSeq(Iterator_t&, bool lazy = true) = 0;
		
		/**
			* Possibility to change the Garbage Collection strategy of the store.
			* @param garbageCollectionStrategy
			*/
		virtual void setGarbageCollectionStrategy(const xqp_string& garbageCollectionStrategy) = 0;
		
		/**
			* Applies a pending update list on this store
			* @param pendingUpdateList
			*/
		virtual void apply(PUL_t pendingUpdateList) = 0;
		
		/**
			* Applies the pending update list on the specified branch. Potentially, 
			* creates a new branch if no branch for that requester exists yet.
			*
			* @param pendingUpdateList
			* @param requester
			* @throws NotSupportedException Throws an exception if the store does not support branching
			*/
		virtual void apply(PUL_t pendingUpdateList, Requester requester) = 0;
		
		/* ------------------------------------- Reference Management ------------------------------------*/
		
		/** 
			* Computes the URI of the passed item.
			*
			* @param item XDM item
			* @return Returns an item of type xs:uri 
			*/
		virtual Item_t getReference(Item_t) = 0;
		
		/** Returns a fixed reference of an item, dependent on a requester
			* (defines branch) and a timetravel (defines version)
			* 
			* @param Item 
			* @param requester
			* @param timetravel
			* @throws NotSupportedException Throws an exception if the store does not support branching or versioning
			*/
		virtual Item_t getFixedReference(Item_t, Requester requester, Timetravel timetravel) = 0;
		
		/**
			* Returns Item which is identified by a reference
			*
			* @param uri Has to be an xs:URI item
			* @returns referenced item if it exists, otherwise NULL
			*/
		virtual Item_t getNodeByReference(Item_t) = 0;
		
		/** Returns Item wich is identified by a referenced, dependent on a requester
			* (defines branch) and a timetravel (defines version)
			*
			* @param Item_t Has to be an xs:URI item (no correctness check is applied!!!)
			* @param requester
			* @param timetravel
			* @returns referenced item if it exists, otherwise NULL
			* @throws NotSupportedException Throws an exception if the store does not support branching or versioning
			* @throws IllegalReferenceException Throws an exception if the reference is fixed.
			*
			*/
		virtual Item_t getNodeByReference(Item_t, Requester requester, Timetravel timetravel) = 0;
		
		/* ------------------------------------- Node Id Management ------------------------------------*/
		
		/** Compares two items, based on their id.
			* @param item1
			* @param item2
			* @return 	-1, if item1.id &lt; item2.id
			*						 0, if item1.id == item2.id
			*						+1, if item1.id &gt; item2.id
			*/
		virtual int32_t compare(Item_t item1, Item_t item2) = 0;
		
		/** Sorts the items of the passed iterator
			* @param iterator to sort
			* @param ascendent true for ascendent and false for descendant
			* @param duplicate duplicate elemination should be applied
			* @return iterator which produces the sorted items
			*/
		virtual Iterator_t sort(Iterator_t iterator, bool ascendent, bool duplicateElemination) = 0;
		
		/** Eliminates the duplicates in collection of items which is produced by the passed iterator
			* @param iterator
			*/
		virtual Iterator_t distinctNodeStable(Iterator_t) = 0;
		
		
		/* ------------------------ Collection Management ------------------------------------*/
		
		/** Returns an XDM instance which is saved in the store 
			* (corresponds to the opening of a connection to a database)
			*
			* @param URI of the colleciton
			* @return handle object of the collection. Returns NULL if the collection does not exist
			*/
		virtual Collection_t getCollection(Item_t uri) = 0;
		
		/** Creates a collection in the store.
		  * 
		  * @param URI The URI of the collection to create.
		  * @return handle object of the newly created collection
		  * @throws CollectionAlreadyExistsException If a collection with the passed uri already exists in the store.
		  */
		virtual Collection_t createCollection(Item_t uri) = 0;
		
		/** Creates a collection in the store (without given URI).
		  * 
		  * @return handle object of the newly created collection
		  */
		virtual Collection_t createCollection() = 0;
		
		/** Deletes a collection.
			*
		  * @param URI to identify the collection to delete.
		  */
		virtual void deleteCollection(Item_t uri) = 0;
		
		/**
		 * Creates a new unique URI which can be used as an ID for a collection.
		 *
		 * @return URI
		 */
		virtual Item_t createURI() = 0;
		
	}; /* class Store */
	
	
	/* ----------------------------- Versioning ------------------------------ */
	/**
		* Requester
		*/
	class Requester {
	 // TODO Requester interface
	}; /* Requester */
	
	/** Timetravel
		*
		*/
	class Timetravel {
		// TODO Timetravel interface
	}; /* Timetravel */

} /* namespace xqp */

#endif /* XQP_STORE_H */
