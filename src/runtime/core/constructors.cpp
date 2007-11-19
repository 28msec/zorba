
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "system/globalenv.h"
#include "types/typesystem.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/core/constructors.h"

using namespace std;
namespace xqp
{


/*******************************************************************************

********************************************************************************/
ElementIterator::ElementIterator (
    const yy::location& loc,
    const QNameItem_t& qname,
    PlanIter_t& children,
    PlanIter_t& attributes)
  :
  Batcher<ElementIterator>(loc),
  theQName(qname),
  theChildrenIter(children),
  theAttributesIter(attributes)
{
}


Item_t
ElementIterator::nextImpl(PlanState& planState)
{
  Item_t item;

  Store* store = zorba::getStore();
  TempSeq_t seqChildren;
  TempSeq_t seqAttributes;
  TempSeq_t seqNamespaces;
	Iterator_t cwrapper;
	Iterator_t awrapper;
	Iterator_t nwrapper;

  PlanIteratorState* state;
  STACK_INIT2(PlanIteratorState, state, planState);
		
  if (theChildrenIter != NULL)
  {
    cwrapper = new PlanIterWrapper(theChildrenIter, planState);
    seqChildren = store->createTempSeq(cwrapper);
  }

  if (theAttributesIter != NULL)
  {
    awrapper = new PlanIterWrapper(theAttributesIter, planState);
    seqAttributes = store->createTempSeq(awrapper);
  }

  if (theNamespacesIter != NULL)
  {
    nwrapper = new PlanIterWrapper(theNamespacesIter, planState); 
    seqNamespaces = store->createTempSeq(nwrapper);
  }

  item = zorba::getItemFactory()->createElementNode(
		           theQName,
		           GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
		           seqChildren,
		           seqAttributes,
               seqNamespaces,
               theNsBindings,
		           false,
		           false).get_ptr();

  STACK_PUSH2(item, state);
		
  STACK_END2();
}


void
ElementIterator::resetImpl(PlanState& planState)
{
  if ( theChildrenIter != NULL )
    resetChild(theChildrenIter, planState);

  if (theAttributesIter != NULL)
    resetChild(theAttributesIter, planState);

  if (theNamespacesIter != NULL)
    resetChild(theNamespacesIter, planState);

  PlanIterator::PlanIteratorState* state;
  GET_STATE(PlanIterator::PlanIteratorState, state, planState);
  state->reset();
}


void
ElementIterator::releaseResourcesImpl(PlanState& planState)
{
  if (theChildrenIter != NULL)
    releaseChildResources(theChildrenIter, planState);

  if (theAttributesIter != NULL)
    releaseChildResources(theAttributesIter, planState);

  if (theNamespacesIter != NULL)
    releaseChildResources(theNamespacesIter, planState);
}


std::ostream&
ElementIterator::_show(std::ostream& os) const
{
  os << IT_DEPTH << " " << "qname: " << theQName->show() << std::endl;

  if (theAttributesIter != NULL)
    theAttributesIter->show(os);

  if (theChildrenIter != NULL)
    theChildrenIter->show(os);

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

  if (theChildrenIter != NULL)
    size += theChildrenIter->getStateSizeOfSubtree();

  if (theAttributesIter != NULL)
    size += theAttributesIter->getStateSizeOfSubtree();

  if (theNamespacesIter != NULL)
    size += theNamespacesIter->getStateSizeOfSubtree();

  return this->getStateSize() + size;
}

	
void
ElementIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  if (theChildrenIter != NULL)
    theChildrenIter->setOffset(planState, offset);

  if (theAttributesIter != NULL)
    theAttributesIter->setOffset(planState, offset);

  if (theNamespacesIter != NULL)
    theNamespacesIter->setOffset(planState, offset);
}


/*******************************************************************************

********************************************************************************/
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
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString).get_ptr(), state);
        state->theString = "";
      }
      break;
    }
    else if (state->theContextItem->isNode() &&
             state->theContextItem->getNodeKind() == StoreConsts::textNode) 
		{
      state->theString += state->theContextItem->getStringProperty();
    }
    else 
		{
      if (state->theString != "")
			{
        STACK_PUSH2(zorba::getItemFactory()->createTextNode(state->theString).get_ptr(), state);
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


/*******************************************************************************

********************************************************************************/
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

    itemLexical = zorba::getItemFactory()->createUntypedAtomic(lexicalString);
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
		           GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
		           itemLexical,
		           itemTyped).get_ptr();

  STACK_PUSH2(item, state);
  STACK_END2();
}

/*******************************************************************************

********************************************************************************/
CommentIterator::CommentIterator (
    const yy::location& loc,
    PlanIter_t& expression)
  :
  Batcher<CommentIterator>(loc),
  theExpressionIter(expression)
{
}

Item_t CommentIterator::nextImpl(PlanState& planState)
{
  Item_t item, child;
  xqp_string content = "";

  Store* store = zorba::getStore();
  TempSeq_t seqExpression;  
	Iterator_t ewrapper;

  PlanIteratorState* state;
  STACK_INIT2(PlanIteratorState, state, planState);
		
  if (theExpressionIter != NULL)
  {
    /*
    ewrapper = new PlanIterWrapper(theExpressionIter, planState);
    seqExpression = store->createTempSeq(ewrapper);
    */
    // TODO: put a while() to handle expressions        
    child = consumeNext( theExpressionIter, planState);    
    if (child != NULL)
      content = child->getStringValue(); // TODO: maybe getStringProperty()?
  }

  item = zorba::getItemFactory()->createCommentNode(
		           content,
		           false).get_ptr();

  STACK_PUSH2(item, state);
		
  STACK_END2();
}


void
CommentIterator::resetImpl(PlanState& planState)
{
  if ( theExpressionIter != NULL )
    resetChild(theExpressionIter, planState);

  PlanIterator::PlanIteratorState* state;
  GET_STATE(PlanIterator::PlanIteratorState, state, planState);
  state->reset();
}


void
CommentIterator::releaseResourcesImpl(PlanState& planState)
{
  if (theExpressionIter != NULL)
    releaseChildResources(theExpressionIter, planState);
}


std::ostream&
CommentIterator::_show(std::ostream& os) const
{  
  if (theExpressionIter != NULL)
    theExpressionIter->show(os);
 
  return os;
}


int32_t
CommentIterator::getStateSize()
{
  return sizeof(PlanIterator::PlanIteratorState);
}

	
int32_t
CommentIterator::getStateSizeOfSubtree()
{
  int32_t size = 0;
  
  if (theExpressionIter != NULL)
    size += theExpressionIter->getStateSizeOfSubtree();

  return this->getStateSize() + size;
}

	
void
CommentIterator::setOffset(PlanState& planState, int32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  if (theExpressionIter != NULL)
    theExpressionIter->setOffset(planState, offset);
}

}
