/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "util/rchandle.h"

#include "store/naive/simple_temp_seq.h"

namespace xqp
{
	SimpleTempSeq::SimpleTempSeq ( Iterator_t iterator )
	{
		Item_t curItem = iterator->next();
		while ( curItem != NULL )
		{
			this->items.push_back ( curItem );
			curItem = iterator->next();
		}
	}
	SimpleTempSeq::~SimpleTempSeq()
	{	}

	Iterator_t 
	SimpleTempSeq::getIterator()
	{
		return new SimpleTempSeqIter ( &this->items );
	}
	
	Iterator_t 
	SimpleTempSeq::getIterator ( int32_t startPos, int32_t endPos, bool streaming )
	{
		return Iterator_t ( NULL );
	}
	
	Iterator_t 
	SimpleTempSeq::getIterator ( int32_t startPos, Iterator_t function, const std::vector<var_iterator>& vars, bool streaming )
	{
		return Iterator_t ( NULL );
	}
	
	Iterator_t 
	SimpleTempSeq::getIterator ( const std::vector<int32_t>& positions, bool streaming )
	{
		return Iterator_t ( NULL );
	}
	
	Iterator_t 
	SimpleTempSeq::getIterator ( Iterator_t positions, bool streaming )
	{
		return Iterator_t ( NULL );
	}
	
	Item_t 
	SimpleTempSeq::getItem ( int32_t position )
	{
		if ( this->containsItem( position ))
		{
			return this->items[position - 1];
		}
		else
		{
			return NULL;
		}
	}
	
	bool
	SimpleTempSeq::containsItem ( int32_t position)
	{
		return int32_t ( this->items.size() ) >= position;
	}
	
	void 
	SimpleTempSeq::purge()
	{

	}
	
	void 
	SimpleTempSeq::purgeUpTo ( int32_t upTo )
	{

	}
	
	void 
	SimpleTempSeq::purgeItem ( const std::vector<int32_t>& positions )
	{

	}
	
	void 
	SimpleTempSeq::purgeItem ( int32_t position )
	{

	}
	
	bool 
	SimpleTempSeq::empty()
	{
		return this->items.size() == 0;
	}
	
	SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter (const std::vector<Item_t>* items_arg )
	:
		items ( items_arg ), borderType ( none ), curPos ( -1 ) {}

	SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter( const std::vector<Item_t>* items_arg, int startPos_arg, int endPos_arg )
	:
		items ( items_arg ), borderType ( startEnd ), curPos ( startPos_arg - 2 ), startPos ( startPos_arg ), endPos ( endPos_arg ) {}

	SimpleTempSeq::SimpleTempSeqIter::SimpleTempSeqIter (const std::vector<Item_t>* items_arg, const std::vector<int32_t>& positions_arg )
	:
		items ( items_arg ), borderType ( specificPositions ), curPos ( -1 ), positions ( positions_arg ) {}

	SimpleTempSeq::SimpleTempSeqIter::~SimpleTempSeqIter() {}

	Item_t 
	SimpleTempSeq::SimpleTempSeqIter::next()
	{
		this->curPos++;
		switch ( this->borderType )
		{
			case none:
				if ( this->curPos < int32_t ( this->items->size() ) )
					return ( *(this->items) ) [this->curPos];
				break;
			case startEnd:
				if ( this->curPos < this->endPos )
					return ( *(this->items) ) [this->curPos];
				break;
			case specificPositions:
				if ( this->curPos < int32_t ( this->positions.size() ) )
					return ( *(this->items) ) [this->positions[this->curPos]];
				break;
		}
		return NULL;
	}

	void 
	SimpleTempSeq::SimpleTempSeqIter::reset()
	{
		switch ( this->borderType )
		{
			case startEnd:
				this->curPos = this->startPos - 2;
				break;
			case none:
			case specificPositions:
				this->curPos = -1;
				break;
		}
	}

} /* namespace xqp */
