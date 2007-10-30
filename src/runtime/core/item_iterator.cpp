/* -*- mode: c++; indent-tabs-mode: nil; tab-width: 2 -*- *
 *  $Id: item_iterator.cpp,v 1.1 2006/10/09 07:07:59 Paul Pedersen Exp $
 *
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: John Cowan,Paul Pedersen
 *
 */

#include "runtime/core/item_iterator.h"
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/booleans/BooleanImpl.h"

using namespace std;
namespace xqp
{

int32_t iteratorTreeDepth = -1;


/* begin class EmptyIterator */
void
EmptyIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
}
/* end class EmptyIterator */


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
SingletonIterator::nextImpl(PlanState& planState)
{
  PlanIteratorState* state;
  STACK_INIT2(PlanIteratorState, state, planState);
  STACK_PUSH2(i_h, state);
  STACK_END2();
}

	
void 
SingletonIterator::resetImpl(PlanState& planState)
{
  PlanIterator::PlanIteratorState* state;
  GET_STATE(PlanIteratorState, state, planState);
  state->reset();
}
	

void 
SingletonIterator::releaseResourcesImpl(PlanState& planState)
{
}
	

std::ostream& 
SingletonIterator::_show(std::ostream& os)	const
{
	return os;
}

	
int32_t
SingletonIterator::getStateSize()
{
  return sizeof(PlanIterator::PlanIteratorState);
}

	
int32_t
SingletonIterator::getStateSizeOfSubtree()
{
  return this->getStateSize();
}

	
void
SingletonIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
}
/* end class SingletonIterator */


/* begin class MapIterator */
Item_t
MapIterator::nextImpl ( PlanState& planState )
{
  Item_t item;
  vector<var_iter_t>::const_iterator itv;
  PlanIteratorState *state;
  STACK_INIT2 ( PlanIteratorState, state, planState );
	
  while ( true )
	{
    item = this->consumeNext ( this->theInput, planState );
    if ( item == NULL )
      break;

    itv = theVarRefs.begin();
    for ( ; itv != theVarRefs.end(); ++itv )
		{
      ( *itv )->bind ( item );
    }
    
    item = this->consumeNext ( this->theExpr, planState );
    while ( item != NULL )
		{
      STACK_PUSH2 ( item, state );
      item = this->consumeNext ( this->theExpr, planState );
    }
	
    this->resetChild ( this->theExpr, planState );
  }
  STACK_END2();
}


void 
MapIterator::resetImpl(PlanState& planState)
{
  this->resetChild ( this->theInput, planState );
  this->resetChild ( this->theExpr, planState );
}


void 
MapIterator::releaseResourcesImpl(PlanState& planState)
{
  this->releaseChildResources ( this->theInput, planState );
  this->releaseChildResources ( this->theExpr, planState );
}

	
int32_t
MapIterator::getStateSize()
{
  return sizeof(PlanIteratorState);
}


int32_t
MapIterator::getStateSizeOfSubtree()
{
  return theInput->getStateSizeOfSubtree() 
				+ theExpr->getStateSizeOfSubtree() 
				+ this->getStateSize();
}

	
void MapIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();
	
  theInput->setOffset(planState, offset);
  theExpr->setOffset(planState, offset);
}


std::ostream& 
MapIterator::_show ( std::ostream& os )	const
{
  theInput->show ( os );
  theExpr->show ( os );
  return os;
}
/* end class MapIterator */


/* begin class EnclosedIterator */
EnclosedIterator::EnclosedIterator(
    const yy::location& loc,
    PlanIter_t& childIter)
	:
  UnaryBaseIterator<EnclosedIterator>(loc, childIter)
{
}

		
Item_t 
EnclosedIterator::nextImpl(PlanState& planState)
{
  EnclosedState* state;
  STACK_INIT2(EnclosedState, state, planState);

  while (true)
  {
    state->theContextItem = consumeNext(theChild, planState);
    if (state->theContextItem == NULL)
    {
      if (state->theString != "")
      {
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      break;
    }
    else if (state->theContextItem->isNode()) 
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
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
EnclosedIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<EnclosedIterator>::resetImpl(planState);

  EnclosedState* state;
  GET_STATE(EnclosedState, state, planState);
  state->theString = "";
}

	
void 
EnclosedIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl(planState);

  EnclosedState* state;
  GET_STATE(EnclosedState, state, planState);
  state->theContextItem = NULL;
  state->theString.clear();
}


void EnclosedIterator::setOffset(
    PlanState& planState,
    int32_t& offset)
{
  UnaryBaseIterator<EnclosedIterator>::setOffset(planState, offset);

  EnclosedState* state = new (planState.block + stateOffset) EnclosedState;
}


void EnclosedIterator::EnclosedState::init()
{
  PlanIterator::PlanIteratorState::init();
  theString = "";
}

/* end class EnclosedIterator */


/* begin class ElementContentIterator */
ElementContentIterator::ElementContentIterator(
    const yy::location& loc,
    PlanIter_t& childIter)
	:
  UnaryBaseIterator<ElementContentIterator>(loc, childIter)
{
}

		
Item_t 
ElementContentIterator::nextImpl(PlanState& planState)
{
  ElementContentState* state;
  STACK_INIT2(ElementContentState, state, planState);

  while (true)
	{
    state->theContextItem = this->consumeNext(theChild, planState );
    if (state->theContextItem == NULL)
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
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
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString), state);
        state->theString = "";
      }
      STACK_PUSH2(state->theContextItem, state);
    }
  }
  STACK_END2();
}


void 
ElementContentIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<ElementContentIterator>::resetImpl(planState);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, planState);
  state->theString = "";
}

	
void 
ElementContentIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<ElementContentIterator>::releaseResourcesImpl(planState);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, planState);
  state->theContextItem = NULL;
  state->theString.clear();
}


void ElementContentIterator::setOffset(
    PlanState& planState,
    int32_t& offset)
{
  UnaryBaseIterator<ElementContentIterator>::setOffset(planState, offset);

  ElementContentState* state = new (planState.block + stateOffset) ElementContentState;
}


void ElementContentIterator::ElementContentState::init()
{
  PlanIterator::PlanIteratorState::init();
  theString = "";
}
/* end class ElementContentIterator */


/* begin class ElementIterator */
ElementIterator::ElementIterator (
    const yy::location& loc,
    const Item_t& qname,
    PlanIter_t& children,
    PlanIter_t& attributes)
  :
  Batcher<ElementIterator> ( loc ),
  theQName ( qname ),
  theChildren ( children ),
  theAttributes ( attributes )
{
}


Item_t
ElementIterator::nextImpl(PlanState& planState)
{
  Item_t item;

  Store* store = zorba::getStore();
  TempSeq_t seqChildren = NULL;
  TempSeq_t seqAttributes = NULL;
  TempSeq_t seqNamespaces = NULL;
	Iterator_t lIter0;
	Iterator_t lIter1;
	Iterator_t lIter2;

  PlanIteratorState* state;
  STACK_INIT2(PlanIteratorState, state, planState);
		
  if (theChildren != NULL)
  {
    lIter0 = new PlanIterWrapper(theChildren, planState);
    seqChildren = store->createTempSeq ( lIter0 );
  }

  if (theAttributes != NULL)
  {
    lIter1 = new PlanIterWrapper(theAttributes, planState);
    seqAttributes = store->createTempSeq ( lIter1 );
  }

  if (theNamespaceBindings != NULL)
  {
    lIter2 = new PlanIterWrapper(theNamespaceBindings, planState); 
    seqNamespaces = store->createTempSeq ( lIter2 );
  }

  item = zorba::getItemFactory()->createElementNode (
		           theQName,
		           xs_anyType,
		           seqChildren,
		           seqAttributes,
		           seqNamespaces,
		           false,
		           false );

  STACK_PUSH2(item, state);
		
  STACK_END2();
}


void
ElementIterator::resetImpl(PlanState& planState)
{
  if ( theChildren != NULL )
    resetChild(theChildren, planState);

  if (theAttributes != NULL)
    resetChild(theAttributes, planState);

  PlanIterator::PlanIteratorState* state;
  GET_STATE(PlanIterator::PlanIteratorState, state, planState);
  state->reset();
}


void
ElementIterator::releaseResourcesImpl(PlanState& planState)
{
  if (theChildren != NULL)
    releaseChildResources(theChildren, planState);

  if (theAttributes != NULL)
    releaseChildResources(theAttributes, planState);
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
  return sizeof(PlanIterator::PlanIteratorState);
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
ElementIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  if (theChildren != NULL)
    theChildren->setOffset(planState, offset);

  if (theAttributes != NULL)
    theAttributes->setOffset(planState, offset);

  if (theNamespaceBindings != NULL)
    theNamespaceBindings->setOffset(planState, offset);
}
/* end class ElementIterator */


/* begin class AttributeIterator */
AttributeIterator::AttributeIterator (
    const yy::location& loc,
    const Item_t& qname,
    PlanIter_t& value)
  :
  UnaryBaseIterator<AttributeIterator>( loc, value ),
  theQName(qname)
{
}


Item_t
AttributeIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  Item_t itemCur;
  Item_t itemFirst;
  Item_t itemLexical;
  Item_t itemTyped;
  xqp_string lexicalString;
  bool concatenation = false;

  PlanIteratorState* state;
  STACK_INIT2(PlanIteratorState, state, planState);

  if ((itemFirst = consumeNext(theChild, planState)) != NULL )
	{
    lexicalString = itemFirst->getStringProperty();

    // handle concatenation
    itemCur = consumeNext ( theChild, planState );
    while ( itemCur != NULL )
		{
      concatenation = true;
      lexicalString += itemCur->getStringProperty();
      itemCur = consumeNext ( theChild, planState );
    }

    itemLexical = zorba::getItemFactory()->
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

  item = zorba::getItemFactory()->createAttributeNode (
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
	    PlanIter_t& iterCond_arg,
	    PlanIter_t& iterThen_arg,
	    PlanIter_t& iterElse_arg,
	    bool condIsBooleanIter_arg
	) : Batcher<IfThenElseIterator> ( loc ), iterCond ( iterCond_arg ), iterThen ( iterThen_arg ),
			iterElse ( iterElse_arg ), condIsBooleanIter ( condIsBooleanIter_arg )
	{}

	Item_t
	IfThenElseIterator::nextImpl(PlanState& planState)
	{
		Item_t condResult;

		STACK_INIT();

		if ( this->condIsBooleanIter )
			condResult = this->consumeNext ( this->iterCond, planState );
		else
			condResult = FnBooleanIterator::effectiveBooleanValue ( this->loc, planState, this->iterCond );

		if ( condResult->getBooleanValue() )
			this->iterActive = this->iterThen;
		else
			this->iterActive = this->iterElse;

		while ( true )
		{
			STACK_PUSH ( this->consumeNext ( this->iterActive, planState ) );
		}

		STACK_END();
	}

	void
	IfThenElseIterator::resetImpl(PlanState& planState)
	{
		this->resetChild ( this->iterCond, planState );
		this->resetChild ( this->iterThen, planState );
		this->resetChild ( this->iterElse, planState );
	}

	void
	IfThenElseIterator::releaseResourcesImpl(PlanState& planState)
	{
		this->releaseChildResources ( this->iterCond, planState );
		this->releaseChildResources ( this->iterThen, planState );
		this->releaseChildResources ( this->iterElse, planState );
	}
	
	FLWORIterator::ForLetClause::ForLetClause(std::vector<var_iter_t> forVars, PlanIter_t& input){}
	FLWORIterator::ForLetClause::ForLetClause(std::vector<var_iter_t> forVars, std::vector<var_iter_t> posVars, PlanIter_t& input){}

	FLWORIterator::ForLetClause::ForLetClause(std::vector<ref_iter_t> letVars, PlanIter_t& input,bool needsMaterialization){}
		
	FLWORIterator::OrderSpec::OrderSpec(PlanIter_t orderByIter, 
			bool empty_least, 
			bool descending){}
			
	FLWORIterator::OrderByClause::OrderByClause(std::vector<FLWORIterator::OrderSpec> orderSpecs, 
			bool stable){}
	
	FLWORIterator::FLWORIterator(const yy::location& loc, 
	  		  std::vector<FLWORIterator::ForLetClause> &forLetClauses,
	  		  PlanIter_t& whereClause, 
	  		  FLWORIterator::OrderByClause* orderByClause,  
	  		  PlanIter_t& returnClause, 
	  		  bool whereClauseReturnsBooleanPlus): Batcher<FLWORIterator> ( loc ){ }
			  
			  
	Item_t 
	FLWORIterator::nextImpl(PlanState& planState){ return NULL;}
	
	void 
	FLWORIterator::resetImpl(PlanState& planState){}
	
    void 
    FLWORIterator::releaseResourcesImpl(PlanState& planState){}
    
    int32_t 
    FLWORIterator::getStateSize(){return 0;}
    
    int32_t 
    FLWORIterator::getStateSizeOfSubtree(){return 0;}
    
    void 
    FLWORIterator::setOffset(PlanState& planState, int32_t& offset){}
    
    
			    
	/* end class IfThenElseIterator */

} /* namespace xqp */

