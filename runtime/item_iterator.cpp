/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "item_iterator.h"
#include "util/Assert.h"
#include "errors/Error.h"
#include "../store/api/item.h"
#include "runtime/zorba.h"
#include "exprtree/expr.h"
#include "../functions/BooleanImpl.h"

using namespace std;
namespace xqp
{

	int32_t iteratorTreeDepth = -1;



	Item_t MapIterator::nextImpl()
	{
		Item_t item;
		vector<var_iter_t>::const_iterator itv;

		STACK_INIT();

		while ( true )
		{
			item = this->consumeNext ( this->theInput );
			itv = varv.begin();
			for ( ; itv!=varv.end(); ++itv )
			{
				( *itv )->bind ( item );
			}

			item = this->consumeNext ( this->theExpr );
			while ( item != NULL )
			{
				STACK_PUSH ( item );
				item = this->consumeNext ( this->theExpr );
			}

			this->resetChild ( this->theExpr );
		}

		STACK_END();
	}

	void MapIterator::resetImpl()
	{
		this->resetChild ( this->theInput );
		this->resetChild ( this->theExpr );
	}

	void MapIterator::releaseResourcesImpl()
	{
		this->releaseChildResources ( this->theInput );
		this->releaseChildResources ( this->theExpr );
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
	FilterIterator::resetImpl()
	{
		this->resetChild( this->content );
	}
	
	void 
	FilterIterator::releaseResourcesImpl()
	{
		this->releaseChildResources( this->content );
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
	EnclosedIterator::nextImpl()
	{
		STACK_INIT();
		this->str = "";
		while (true)
		{
			this->item = this->consumeNext( this->content );
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
	ElementContentIterator::nextImpl()
	{
		STACK_INIT();
		this->str = "";
		while (true)
		{
			this->item = this->consumeNext( this->content );
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
	ElementIterator::nextImpl()
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
	ElementIterator::resetImpl()
	{
		if ( this->children != NULL )
			this->resetChild ( this->children );
	}

	void
	ElementIterator::releaseResourcesImpl()
	{
		if ( this->children != NULL )
			this->releaseChildResources ( this->children );
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
	AttributeIterator::nextImpl()
	{
		Item_t item;
		Item_t itemCur;
		Item_t itemFirst;
		Item_t itemLexical;
		Item_t itemTyped;
		xqp_string lexicalString;
		bool concatenation = false;

		STACK_INIT();
		if ( this->value != NULL && (itemFirst = this->consumeNext(this->value)) != NULL )
		{
			lexicalString = itemFirst->getStringProperty();

			// handle concatenation
			itemCur = this->consumeNext ( this->value );
			while ( itemCur != NULL )
			{
				concatenation = true;
				lexicalString += itemCur->getStringProperty();
				itemCur = this->consumeNext ( this->value );
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
	AttributeIterator::resetImpl()
	{
		if ( this->value != NULL )
			this->resetChild ( this->value );
	}

	void
	AttributeIterator::releaseResourcesImpl()
	{
		if ( this->value != NULL )
			this->releaseChildResources ( this->value );
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
	IfThenElseIterator::nextImpl()
	{
		Item_t condResult;

		STACK_INIT();

		if ( this->condIsBooleanIter )
			condResult = this->consumeNext ( this->iterCond );
		else
			condResult = FnBooleanIterator::effectiveBooleanValue ( this->loc, this->iterCond );

		if ( condResult->getBooleanValue() )
			this->iterActive = this->iterThen;
		else
			this->iterActive = this->iterElse;

		while ( true )
		{
			STACK_PUSH ( this->consumeNext ( this->iterActive ) );
		}

		STACK_END();
	}

	void
	IfThenElseIterator::resetImpl()
	{
		this->resetChild ( this->iterCond );
		this->resetChild ( this->iterThen );
		this->resetChild ( this->iterElse );
	}

	void
	IfThenElseIterator::releaseResourcesImpl()
	{
		this->releaseChildResources ( this->iterCond );
		this->releaseChildResources ( this->iterThen );
		this->releaseChildResources ( this->iterElse );
	}
	/* end class IfThenElseIterator */

} /* namespace xqp */

