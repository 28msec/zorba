/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#ifndef XQP_SIMPLE_TEMP_SEQ_H
#define XQP_SIMPLE_TEMP_SEQ_H

#include <vector>

#include "store/api/temp_seq.h"
#include "runtime/core/batching.h"

namespace xqp
{

	/** Very simple implementation of Temp Sequence. It saves the resulting items of an iterator eager in a vector.
		*/
	class SimpleTempSeq : public TempSeq
	{
		private:
			std::vector<Item_t> items;
			yy::location loc;

		public:
			SimpleTempSeq ( Iterator_t iterator );
			virtual ~SimpleTempSeq();

			virtual Iterator_t getIterator();
			virtual Iterator_t getIterator ( int32_t startPos, int32_t endPos, bool streaming = false );
			virtual Iterator_t getIterator ( int32_t startPos, Iterator_t function, const std::vector<var_iterator>& var, bool streaming = false );
			virtual Iterator_t getIterator ( const std::vector<int32_t>& positions, bool streaming = false );
			virtual Iterator_t getIterator ( Iterator_t positions, bool streaming = false );
			virtual Item_t getItem ( int32_t position );
			virtual bool containsItem( int32_t position );
			virtual void purge();
			virtual void purgeUpTo ( int32_t upTo );
			virtual void purgeItem ( const std::vector<int32_t>& positions );
			virtual void purgeItem ( int32_t position );
			virtual bool empty();

		class Iterator : public Batcher<Iterator>
			{
				private:
					enum BorderType
					{
						none,
						startEnd,
						specificPositions
					};

					const std::vector<Item_t>* items;
					BorderType borderType;

					int32_t curPos;
					int32_t startPos;
					int32_t endPos;
					std::vector<int32_t> positions;

				public:
					Iterator ( yy::location& loc, const std::vector<Item_t>* items_arg )
							:
							Batcher<Iterator> ( loc ), items ( items_arg ), borderType ( none ), curPos ( -1 ) {}

					Iterator ( yy::location& loc, const std::vector<Item_t>* items_arg, int startPos_arg, int endPos_arg )
							:
							Batcher<Iterator> ( loc ), items ( items_arg ), borderType ( startEnd ), curPos ( startPos_arg - 2 ), startPos ( startPos_arg ), endPos ( endPos_arg ) {}

					Iterator ( yy::location& loc, const std::vector<Item_t>* items_arg, const std::vector<int32_t>& positions_arg )
							:
							Batcher<Iterator> ( loc ), items ( items_arg ), borderType ( specificPositions ), curPos ( -1 ), positions ( positions_arg ) {}

					~Iterator() {}

					Item_t nextImpl(IteratorTreeStateBlock& stateBlock);
					void resetImpl(IteratorTreeStateBlock& stateBlock);
					void releaseResourcesImpl(IteratorTreeStateBlock& stateBlock);
			};

	}; /* class SimpleTempSeq */

} /* namespace xqp */

#endif /* XQP_SIIMPLE_TEMP_SEQ_H */
