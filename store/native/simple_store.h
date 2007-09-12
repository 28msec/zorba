/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_SIMPLE_STORE_H
#define XQP_SIMPLE_STORE_H

#include "store/api/store.h"

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

	class SimpleStore : public Store
	{
		public:
		public:
			SimpleStore();
			~SimpleStore();

			TempSeq_t createTempSeq ( Iterator_t&, bool lazy = true );
			void setGarbageCollectionStrategy ( const xqp_string& garbageCollectionStrategy );
			void apply ( PUL_t pendingUpdateList );
			void apply ( PUL_t pendingUpdateList, Requester requester );
			Item_t getReference ( Item_t );
			Item_t getFixedReference ( Item_t, Requester requester, Timetravel timetravel );
			Item_t getNodeByReference ( Item_t );
			Item_t getNodeByReference ( Item_t, Requester requester, Timetravel timetravel );
			int32_t compare ( Item_t item1, Item_t item2 );
			Iterator_t sort ( Iterator_t iterator, bool ascendent, bool duplicateElemination );
			Iterator_t distinctNodeStable ( Iterator_t );
			Collection_t getCollection ( Item_t uri );
			Collection_t createCollection ( Item_t uri );
			Collection_t createCollection();
			void deleteCollection ( Item_t uri );

	}; /* class SimpleStore */

} /* namespace xqp */

#endif /* XQP_SIMPLE_STORE_H */
