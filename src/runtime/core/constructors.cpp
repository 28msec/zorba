
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/core/constructors.h"

using namespace std;
namespace xqp
{

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
    const QNameItem_t& qname,
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

  item = zorba::getItemFactory()->createElementNode(
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




AttributeIterator::AttributeIterator(
    const yy::location& loc,
    const QNameItem_t& qname,
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

  if ((itemFirst = consumeNext(theChild, planState)) != NULL)
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

}
