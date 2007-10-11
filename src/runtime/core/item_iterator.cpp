/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "util/zorba.h"
#include "compiler/expression/expr.h"
#include "runtime/booleans/BooleanImpl.h"

using namespace std;
namespace xqp
{

	int32_t iteratorTreeDepth = -1;

	/* begin class SingletonIterator */
	SingletonIterator::SingletonIterator
		(yy::location loc, Item_t _i_p) 
	: 
		Batcher<SingletonIterator> (loc), i_h(_i_p) 
	{}

	SingletonIterator::~SingletonIterator() {}
	
	Item_t 
	SingletonIterator::nextImpl(IteratorTreeStateBlock& stateBlock) {
		BasicIterator::BasicIteratorState* state;
		STACK_INIT2(BasicIterator::BasicIteratorState, state, stateBlock);
		STACK_PUSH2(i_h, state);
		STACK_END2();
	}
	
	void 
	SingletonIterator::resetImpl(IteratorTreeStateBlock& stateBlock) {
		BasicIterator::BasicIteratorState* state;
		state->reset();
	}
	
	void 
	SingletonIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{}
	
	std::ostream& 
	SingletonIterator::_show(std::ostream& os)	const
	{
		return os;
	}
	
	int32_t
	SingletonIterator::getStateSize() {
		return sizeof(BasicIterator::BasicIteratorState);
	}
	
	int32_t
	SingletonIterator::getStateSizeOfSubtree() {
		return this->getStateSize();
	}
	
	void
	SingletonIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset) {
		this->stateOffset = offset;
		offset += this->getStateSize();
	}
	/* end class SingletonIterator */

	Item_t MapIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		Item_t item;
		vector<var_iter_t>::const_iterator itv;

		STACK_INIT();

		while ( true )
		{
			item = this->consumeNext ( this->theInput, stateBlock );
			itv = varv.begin();
			for ( ; itv!=varv.end(); ++itv )
			{
				( *itv )->bind ( item );
			}

			item = this->consumeNext ( this->theExpr, stateBlock );
			while ( item != NULL )
			{
				STACK_PUSH ( item );
				item = this->consumeNext ( this->theExpr, stateBlock );
			}

			this->resetChild ( this->theExpr, stateBlock );
		}

		STACK_END();
	}

	void MapIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->resetChild ( this->theInput, stateBlock );
		this->resetChild ( this->theExpr, stateBlock );
	}

	void MapIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources ( this->theInput, stateBlock );
		this->releaseChildResources ( this->theExpr, stateBlock );
	}

	std::ostream& MapIterator::_show ( std::ostream& os )
	const
	{
		theInput->show ( os );
		theExpr->show ( os );
		return os;
	}

	/* begin class FilterIterator */
	FilterIterator::FilterIterator(
			const yy::location& loc,
			Iterator_t& content_arg
		)
	:
		Batcher<FilterIterator>(loc), content(content_arg){}

	FilterIterator::~FilterIterator(){}
	
	void 
	FilterIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->resetChild( this->content, stateBlock );
	}
	
	void 
	FilterIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources( this->content, stateBlock );
	}
	/* end class FilterIterator */
	
	/* begin class EnclosedIterator */
	EnclosedIterator::EnclosedIterator(
			const yy::location& loc,
			Iterator_t& content_arg
		)
	:
		FilterIterator(loc, content_arg){}

		
	Item_t 
	EnclosedIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		STACK_INIT();
		this->str = "";
		while (true)
		{
			this->item = this->consumeNext( this->content, stateBlock );
			if (this->item == NULL)
			{
				if (this->str != "")
				{
					STACK_PUSH( zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(str) );
					this->str = "";
				}
				break;
			}
			else if (this->item->isNode()) 
			{
				if (this->str != "")
				{
					STACK_PUSH( zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(str) );
					this->str = "";
				}
				STACK_PUSH(this->item);
			}
			else if (this->str == "")
			{
				this->str = this->item->getStringProperty();
			}
			else
			{
				this->str += " " + this->item->getStringProperty();
			}
		}
		STACK_END();
	}
	/* end class EnclosedIterator */

	/* begin class ElementContentIterator */
	ElementContentIterator::ElementContentIterator(
			const yy::location& loc,
			Iterator_t& content_arg
		)
	:
		FilterIterator(loc, content_arg){}

		
	Item_t 
	ElementContentIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		STACK_INIT();
		this->str = "";
		while (true)
		{
			this->item = this->consumeNext( this->content, stateBlock );
			if (this->item == NULL)
			{
				if (this->str != "")
				{
					STACK_PUSH(zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(this->str));
					this->str = "";
				}
				break;
			}
			else if (this->item->isNode() && (this->item->getNodeKind() == textNode)) 
			{
				this->str += this->item->getStringProperty();
			}
			else 
			{
				if (this->str != "")
				{
					STACK_PUSH( zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(str) );
					this->str = "";
				}
				STACK_PUSH(this->item);
			}
		}
		STACK_END();
	}
	/* end class ElementContentIterator */

	/* begin class ElementIterator */
	ElementIterator::ElementIterator (
	    const yy::location& loc,
	    const Item_t& qname_arg,
	    Iterator_t& children_arg,
	    Iterator_t& attributes_arg )
		:
		Batcher<ElementIterator> ( loc ), qname ( qname_arg ), children ( children_arg ), attributes ( attributes_arg ) {}

	Item_t
	ElementIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		Item_t item;

 		STACK_INIT();

		item = zorba::getZorbaForCurrentThread()->getItemFactory()->createElementNode (
		           this->qname,
		           xs_anyType,
		           this->children,
		           this->attributes,
		           this->namespaceBindings,
		           false,
		           false
		       );

		STACK_PUSH ( item );
		
		STACK_END();
	}

	void
	ElementIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		if ( this->children != NULL )
			this->resetChild ( this->children, stateBlock );
	}

	void
	ElementIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		if ( this->children != NULL )
			this->releaseChildResources ( this->children, stateBlock );
	}
	/* end class ElementIterator */

	/* begin class AttributeIterator */
	AttributeIterator::AttributeIterator (
	    const yy::location& loc,
	    const Item_t& qname_arg,
	    Iterator_t& value_arg )
			:
			Batcher<AttributeIterator> ( loc ), qname ( qname_arg ), value ( value_arg ) {}

	Item_t
	AttributeIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		Item_t item;
		Item_t itemCur;
		Item_t itemFirst;
		Item_t itemLexical;
		Item_t itemTyped;
		xqp_string lexicalString;
		bool concatenation = false;

		STACK_INIT();
		if ( this->value != NULL && (itemFirst = this->consumeNext(this->value, stateBlock)) != NULL )
		{
			lexicalString = itemFirst->getStringProperty();

			// handle concatenation
			itemCur = this->consumeNext ( this->value, stateBlock );
			while ( itemCur != NULL )
			{
				concatenation = true;
				lexicalString += itemCur->getStringProperty();
				itemCur = this->consumeNext ( this->value, stateBlock );
			}

			itemLexical = zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( lexicalString );
			if ( concatenation )
			{
				itemTyped = itemLexical;
			}
			else
			{
				itemTyped = itemFirst;
			}

		}
		else
		{
			itemLexical = NULL;
			itemTyped = NULL;
		}

		item = zorba::getZorbaForCurrentThread()->getItemFactory()->createAttributeNode (
		           this->qname,
		           xs_anyType,
		           itemLexical,
		           itemTyped
		       );
		STACK_PUSH ( item );
		STACK_END();
	}

	void
	AttributeIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		if ( this->value != NULL )
			this->resetChild ( this->value, stateBlock );
	}

	void
	AttributeIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		if ( this->value != NULL )
			this->releaseChildResources ( this->value, stateBlock );
	}
	/* end class AttributeIterator */

	/* start class IfThenElseIterator */
	IfThenElseIterator::IfThenElseIterator (
	    const yy::location& loc,
	    Iterator_t& iterCond_arg,
	    Iterator_t& iterThen_arg,
	    Iterator_t& iterElse_arg,
	    bool condIsBooleanIter_arg
	) : Batcher<IfThenElseIterator> ( loc ), iterCond ( iterCond_arg ), iterThen ( iterThen_arg ),
			iterElse ( iterElse_arg ), condIsBooleanIter ( condIsBooleanIter_arg )
	{}

	Item_t
	IfThenElseIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
	{
		Item_t condResult;

		STACK_INIT();

		if ( this->condIsBooleanIter )
			condResult = this->consumeNext ( this->iterCond, stateBlock );
		else
			condResult = FnBooleanIterator::effectiveBooleanValue ( this->loc, stateBlock, this->iterCond );

		if ( condResult->getBooleanValue() )
			this->iterActive = this->iterThen;
		else
			this->iterActive = this->iterElse;

		while ( true )
		{
			STACK_PUSH ( this->consumeNext ( this->iterActive, stateBlock ) );
		}

		STACK_END();
	}

	void
	IfThenElseIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->resetChild ( this->iterCond, stateBlock );
		this->resetChild ( this->iterThen, stateBlock );
		this->resetChild ( this->iterElse, stateBlock );
	}

	void
	IfThenElseIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources ( this->iterCond, stateBlock );
		this->releaseChildResources ( this->iterThen, stateBlock );
		this->releaseChildResources ( this->iterElse, stateBlock );
	}
	/* end class IfThenElseIterator */

} /* namespace xqp */

