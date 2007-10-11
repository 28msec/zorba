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
SingletonIterator::SingletonIterator(yy::location loc, Item_t _i_p) 
	: 
  Batcher<SingletonIterator> (loc), i_h(_i_p) 
{
}


SingletonIterator::~SingletonIterator()
{
}

	Item_t 
	SingletonIterator::nextImpl(IteratorTreeStateBlock& stateBlock) {
		BasicIteratorState* state;
		STACK_INIT2(BasicIteratorState, state, stateBlock);
		STACK_PUSH2(i_h, state);
		STACK_END2();
	}
	
	void 
	SingletonIterator::resetImpl(IteratorTreeStateBlock& stateBlock) {
		BasicIterator::BasicIteratorState* state;
		GET_STATE(BasicIteratorState, state, stateBlock);
		state->reset();
	}
	

void 
SingletonIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
}
	

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
SingletonIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
}
/* end class SingletonIterator */

	/* begin class MapIterator */
	Item_t
	MapIterator::nextImpl ( IteratorTreeStateBlock& stateBlock )
	{
		Item_t item;
		vector<var_iter_t>::const_iterator itv;
		BasicIteratorState *state;
		STACK_INIT2 ( BasicIteratorState, state, stateBlock );
	
	
		while ( true )
		{
			item = this->consumeNext ( this->theInput, stateBlock );
			if ( item == NULL )
				break;
			itv = varv.begin();
			for ( ; itv!=varv.end(); ++itv )
			{
				( *itv )->bind ( item );
			}
	
			item = this->consumeNext ( this->theExpr, stateBlock );
			while ( item != NULL )
			{
				STACK_PUSH2 ( item, state );
				item = this->consumeNext ( this->theExpr, stateBlock );
			}
	
			this->resetChild ( this->theExpr, stateBlock );
		}
		STACK_END2();
	}

	void 
	MapIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->resetChild ( this->theInput, stateBlock );
		this->resetChild ( this->theExpr, stateBlock );
	}

	void 
	MapIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
	{
		this->releaseChildResources ( this->theInput, stateBlock );
		this->releaseChildResources ( this->theExpr, stateBlock );
	}
	
	int32_t
	MapIterator::getStateSize()
	{
		return sizeof(BasicIteratorState);
	}
	
	int32_t
	MapIterator::getStateSizeOfSubtree()
	{
		return theInput->getStateSizeOfSubtree() 
				+ theExpr->getStateSizeOfSubtree() 
				+ this->getStateSize();
	}
	
	void MapIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset) {
		this->stateOffset = offset;
		offset += this->getStateSize();
		
		theInput->setOffset(stateBlock, offset);
		theExpr->setOffset(stateBlock, offset);
	}

	std::ostream& 
	MapIterator::_show ( std::ostream& os )
	const
	{
		theInput->show ( os );
		theExpr->show ( os );
		return os;
	}
	/* end class MapIterator */

/* begin class EnclosedIterator */
EnclosedIterator::EnclosedIterator(
    const yy::location& loc,
    Iterator_t& childIter)
	:
  UnaryBaseIterator<EnclosedIterator>(loc, childIter)
{
}

		
Item_t 
EnclosedIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  EnclosedState* state;
  STACK_INIT2(EnclosedState, state, stateBlock);

  while (true)
  {
    state->theContextItem = consumeNext(theChild, stateBlock);
    if (state->theContextItem == NULL)
    {
      if (state->theString != "")
      {
        STACK_PUSH2(zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      break;
    }
    else if (state->theContextItem->isNode()) 
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      STACK_PUSH2(state->theContextItem, state);
    }
    else if (state->theString == "")
		{
      state->theString = state->theContextItem->getStringProperty();
    }
    else
		{
      state->theString += " " + state->theContextItem->getStringProperty();
    }
  }
  STACK_END2();
}


void 
EnclosedIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  UnaryBaseIterator<EnclosedIterator>::resetImpl(stateBlock);

  EnclosedState* state;
  GET_STATE(EnclosedState, state, stateBlock);
  state->theString = "";
}

	
void 
EnclosedIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl(stateBlock);

  EnclosedState* state;
  GET_STATE(EnclosedState, state, stateBlock);
  state->theContextItem = NULL;
  state->theString.clear();
}


void EnclosedIterator::setOffset(
    IteratorTreeStateBlock& stateBlock,
    int32_t& offset)
{
  UnaryBaseIterator<EnclosedIterator>::setOffset(stateBlock, offset);

  EnclosedState* state = new (stateBlock.block + stateOffset) EnclosedState;
}


void EnclosedIterator::EnclosedState::init()
{
  BasicIterator::BasicIteratorState::init();
  theString = "";
}

/* end class EnclosedIterator */


/* begin class ElementContentIterator */
ElementContentIterator::ElementContentIterator(
    const yy::location& loc,
    Iterator_t& childIter)
	:
  UnaryBaseIterator<ElementContentIterator>(loc, childIter)
{
}

		
Item_t 
ElementContentIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  ElementContentState* state;
  STACK_INIT2(ElementContentState, state, stateBlock);

  while (true)
	{
    state->theContextItem = this->consumeNext(theChild, stateBlock );
    if (state->theContextItem == NULL)
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      break;
    }
    else if (state->theContextItem->isNode() && (state->theContextItem->getNodeKind() == textNode)) 
		{
      state->theString += state->theContextItem->getStringProperty();
    }
    else 
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getZorbaForCurrentThread()->getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      STACK_PUSH2(state->theContextItem, state);
    }
  }
  STACK_END2();
}


void 
ElementContentIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  UnaryBaseIterator<ElementContentIterator>::resetImpl(stateBlock);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, stateBlock);
  state->theString = "";
}

	
void 
ElementContentIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  UnaryBaseIterator<ElementContentIterator>::releaseResourcesImpl(stateBlock);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, stateBlock);
  state->theContextItem = NULL;
  state->theString.clear();
}


void ElementContentIterator::setOffset(
    IteratorTreeStateBlock& stateBlock,
    int32_t& offset)
{
  UnaryBaseIterator<ElementContentIterator>::setOffset(stateBlock, offset);

  ElementContentState* state = new (stateBlock.block + stateOffset) ElementContentState;
}


void ElementContentIterator::ElementContentState::init()
{
  BasicIterator::BasicIteratorState::init();
  theString = "";
}
/* end class ElementContentIterator */


/* begin class ElementIterator */
ElementIterator::ElementIterator (
    const yy::location& loc,
    const Item_t& qname,
    Iterator_t& children,
    Iterator_t& attributes)
  :
  Batcher<ElementIterator> ( loc ),
  theQName ( qname ),
  theChildren ( children ),
  theAttributes ( attributes )
{
}


Item_t
ElementIterator::nextImpl(IteratorTreeStateBlock& stateBlock)
{
  Item_t item;

  BasicIteratorState* state;
  STACK_INIT2(BasicIteratorState, state, stateBlock);

  item = zorba::getZorbaForCurrentThread()->getItemFactory()->createElementNode (
		           theQName,
		           xs_anyType,
		           theChildren,
		           theAttributes,
		           theNamespaceBindings,
		           false,
		           false
		       );

  STACK_PUSH2(item, state);
		
  STACK_END2();
}


void
ElementIterator::resetImpl(IteratorTreeStateBlock& stateBlock)
{
  if ( theChildren != NULL )
    resetChild(theChildren, stateBlock);

  if (theAttributes != NULL)
    resetChild(theAttributes, stateBlock);

  BasicIterator::BasicIteratorState* state;
  GET_STATE(BasicIterator::BasicIteratorState, state, stateBlock);
  state->reset();
}


void
ElementIterator::releaseResourcesImpl(IteratorTreeStateBlock& stateBlock)
{
  if (theChildren != NULL)
    releaseChildResources(theChildren, stateBlock);

  if (theAttributes != NULL)
    releaseChildResources(theAttributes, stateBlock);
}


std::ostream&
ElementIterator::_show(std::ostream& os) const
{
  os << IT_DEPTH << " " << "qname: " << theQName->show() << std::endl;

  if (theAttributes != NULL)
    theAttributes->show(os);

  if (theChildren != NULL)
    theChildren->show(os);

  return os;
}


int32_t
ElementIterator::getStateSize()
{
  return sizeof(BasicIterator::BasicIteratorState);
}

	
int32_t
ElementIterator::getStateSizeOfSubtree()
{
  int32_t size = 0;

  if (theChildren != NULL)
    size += theChildren->getStateSizeOfSubtree();

  if (theAttributes != NULL)
    size += theAttributes->getStateSizeOfSubtree();

  if (theNamespaceBindings != NULL)
    size += theNamespaceBindings->getStateSizeOfSubtree();

  return this->getStateSize() + size;
}

	
void
ElementIterator::setOffset(IteratorTreeStateBlock& stateBlock, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  if (theChildren != NULL)
    theChildren->setOffset(stateBlock, offset);

  if (theAttributes != NULL)
    theAttributes->setOffset(stateBlock, offset);

  if (theNamespaceBindings != NULL)
    theNamespaceBindings->setOffset(stateBlock, offset);
}
/* end class ElementIterator */


/* begin class AttributeIterator */
AttributeIterator::AttributeIterator (
    const yy::location& loc,
    const Item_t& qname,
    Iterator_t& value)
  :
  UnaryBaseIterator<AttributeIterator>( loc, value ),
  theQName(qname)
{
}


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

  BasicIteratorState* state;
  STACK_INIT2(BasicIteratorState, state, stateBlock);

  if ((itemFirst = consumeNext(theChild, stateBlock)) != NULL )
	{
    lexicalString = itemFirst->getStringProperty();

    // handle concatenation
    itemCur = consumeNext ( theChild, stateBlock );
    while ( itemCur != NULL )
		{
      concatenation = true;
      lexicalString += itemCur->getStringProperty();
      itemCur = consumeNext ( theChild, stateBlock );
    }

    itemLexical = zorba::getZorbaForCurrentThread()->getItemFactory()->
                  createUntypedAtomic ( lexicalString );
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
		           theQName,
		           xs_anyType,
		           itemLexical,
		           itemTyped
		       );

  STACK_PUSH2(item, state);
  STACK_END2();
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

