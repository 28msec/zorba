
#include "util/Assert.h"
#include "util/zorba.h"
#include "errors/Error.h"
#include "system/globalenv.h"
#include "types/typesystem.h"
#include "store/api/item.h"
#include "store/api/temp_seq.h"
#include "compiler/expression/expr.h"
#include "runtime/core/constructors.h"
#include "runtime/visitors/planitervisitor.h"

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
  theQNameIter(0),
  theChildrenIter(children),
  theAttributesIter(attributes)
{
}

ElementIterator::ElementIterator(
    const yy::location& loc,
    PlanIter_t aQNameIter,
    PlanIter_t aChildren)
  :
    Batcher<ElementIterator>(loc),
    theQNameIter(aQNameIter),
    theChildrenIter(aChildren),
    theAttributesIter(0)
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
  STACK_INIT(PlanIteratorState, state, planState);
    
  if (theChildrenIter != NULL)
  {
    cwrapper = new PlanIteratorWrapper(theChildrenIter, planState);
    seqChildren = store->createTempSeq(cwrapper);
  }

  if (theAttributesIter != NULL)
  {
    awrapper = new PlanIteratorWrapper(theAttributesIter, planState);
    seqAttributes = store->createTempSeq(awrapper);
  }

  if (theNamespacesIter != NULL)
  {
    nwrapper = new PlanIteratorWrapper(theNamespacesIter, planState); 
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
               false);

  STACK_PUSH(item, state);
    
  STACK_END();
}


void
ElementIterator::resetImpl(PlanState& planState)
{
  if (theQNameIter != 0)
    resetChild(theQNameIter, planState);
  
  if ( theChildrenIter != 0 )
    resetChild(theChildrenIter, planState);

  if (theAttributesIter != 0)
    resetChild(theAttributesIter, planState);

  if (theNamespacesIter != 0)
    resetChild(theNamespacesIter, planState);

  PlanIterator::PlanIteratorState* state;
  GET_STATE(PlanIterator::PlanIteratorState, state, planState);
  state->reset();
}


void
ElementIterator::releaseResourcesImpl(PlanState& planState)
{
  if (theQNameIter != 0)
    resetChild(theQNameIter, planState);
  
  if (theChildrenIter != 0)
    releaseChildResources(theChildrenIter, planState);

  if (theAttributesIter != 0)
    releaseChildResources(theAttributesIter, planState);

  if (theNamespacesIter != 0)
    releaseChildResources(theNamespacesIter, planState);
}

  
uint32_t
ElementIterator::getStateSizeOfSubtree() const
{
  int32_t size = 0;

  if (theQNameIter != 0)
    size += theQNameIter->getStateSizeOfSubtree();
  
  if (theChildrenIter != 0)
    size += theChildrenIter->getStateSizeOfSubtree();

  if (theAttributesIter != 0)
    size += theAttributesIter->getStateSizeOfSubtree();

  if (theNamespacesIter != 0)
    size += theNamespacesIter->getStateSizeOfSubtree();

  return this->getStateSize() + size;
}

  
void
ElementIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += this->getStateSize();

  if (theQNameIter != 0)
    theQNameIter->setOffset(planState, offset);
  
  if (theChildrenIter != 0)
    theChildrenIter->setOffset(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->setOffset(planState, offset);

  if (theNamespacesIter != 0)
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
  STACK_INIT(ElementContentState, state, planState);

  while (true)
  {
    state->theContextItem = this->consumeNext(theChild, planState );
    if (state->theContextItem == NULL)
    {
      if (state->theString != "")
      {
        STACK_PUSH(zorba::getItemFactory()->createTextNode(state->theString).get_ptr(), state);
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
        STACK_PUSH(zorba::getItemFactory()->createTextNode(state->theString).get_ptr(), state);
        state->theString = "";
      }
      STACK_PUSH(state->theContextItem, state);
    }
  }
  STACK_END();
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
    uint32_t& offset)
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
  STACK_INIT(PlanIteratorState, state, planState);

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

  STACK_PUSH(item, state);
  STACK_END();
}

/*******************************************************************************

********************************************************************************/
CommentIterator::CommentIterator (
    const yy::location& loc,
    PlanIter_t& aComment)
  :
  UnaryBaseIterator<CommentIterator>(loc, aComment)
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
  STACK_INIT(PlanIteratorState, state, planState);
    
    /*
    ewrapper = new PlanIterWrapper(theExpressionIter, planState);
    seqExpression = store->createTempSeq(ewrapper);
    */
    // TODO: put a while() to handle expressions        
    child = consumeNext( theChild, planState);    
    if (child != NULL)
      content = child->getStringValue(); // TODO: maybe getStringProperty()?

  item = zorba::getItemFactory()->createCommentNode(
               content,
               false);

  STACK_PUSH(item, state);
    
  STACK_END();
}

/* begin class TextIterator */

TextIterator::TextIterator(const yy::location& loc, PlanIter_t& aChild) 
  : UnaryBaseIterator<TextIterator>(loc, aChild)
{}

Item_t TextIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  xqp_string content = "";
  bool lFirst;

  Store* store = zorba::getStore();

  PlanIteratorState* state;
  STACK_INIT(PlanIteratorState, state, planState);
      
  lFirst = true;
  while (true) {
    lItem = consumeNext(theChild, planState);
    if (lItem == 0)
      break;
    
    if (!lFirst)
      content += " ";
    content += lItem->getStringProperty();
    lFirst = false;
  }

  lItem = zorba::getItemFactory()->createTextNode(content);

  STACK_PUSH(lItem, state);
    
  STACK_END();
}

/* end class TextIterator */

}
