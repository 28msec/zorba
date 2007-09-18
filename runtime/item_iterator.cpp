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
	
	/* begin class ElementIterator */
	ElementIterator::ElementIterator(
		const yy::location& loc,
		const Item_t& qname_arg,
		const Iterator_t& children_arg,
		const Iterator_t& attributes_arg)
	:
		Batcher<ElementIterator>(loc), qname(qname_arg), children(children_arg), attributes(attributes_arg){}
	
	Item_t 
	ElementIterator::nextImpl() {
		Item_t item;
		
		STACK_INIT();
		
		item = zorba::getZorbaForCurrentThread()->getItemFactory()->createElementNode(
				this->qname,
				xs_anyType,
				this->children,
				this->attributes,
				this->namespaceBindings,
				false,
				false
			);
		STACK_PUSH(item);
		
		STACK_PUSH ( NULL );
		STACK_END();
	}
	
	void 
	ElementIterator::resetImpl() {
		if (this->children != NULL)
			this->resetChild(this->children);
	}
	
	void 
	ElementIterator::releaseResourcesImpl() {
		if (this->children != NULL)
			this->releaseChildResources(this->children);
	}
	/* end class ElementIterator */
	
	/* begin class AttributeIterator */
	AttributeIterator::AttributeIterator(
		const yy::location& loc,
		const Item_t& qname_arg,
		const Iterator_t& value_arg)
	:
		Batcher<AttributeIterator>(loc), qname(qname_arg), value(value_arg) {}
	
	Item_t
	AttributeIterator::nextImpl() {
		Item_t item;
		Item_t itemCur;
		Item_t itemFirst;
		Item_t itemLexical;
		Item_t itemTyped;
		xqp_string lexicalString;
		bool concatenation = false;
		
		STACK_INIT();
		if (this->value != NULL) {
			itemFirst = this->consumeNext(this->value);
			lexicalString = itemFirst->getStringProperty();
			
			// handle condatenation
			itemCur = this->consumeNext(this->value);
			while (itemCur != NULL) {
				concatenation = true;
				lexicalString += itemCur->getStringProperty();
				itemCur = this->consumeNext(this->value);
			}
			
			itemLexical = zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic(lexicalString);
			if (concatenation) {
				itemTyped = itemLexical;
			} else {
				itemTyped = itemFirst;
			}
		
		} else {
			itemLexical = NULL;
			itemTyped = NULL;
		}
		
		item = zorba::getZorbaForCurrentThread()->getItemFactory()->createAttributeNode(
				this->qname,
				xs_anyType,
				itemLexical,
				itemTyped
			);
		STACK_PUSH(item);
		STACK_PUSH(NULL);
		STACK_END();
	}
	
	void 
	AttributeIterator::resetImpl() {
		if (this->value != NULL)
			this->resetChild(this->value);
	}
	
	void 
	AttributeIterator::releaseResourcesImpl() {
		if (this->value != NULL)
			this->releaseChildResources(this->value);
	}
	/* end class AttributeIterator */

} /* namespace xqp */

