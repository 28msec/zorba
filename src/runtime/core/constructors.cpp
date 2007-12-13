
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
    PlanIter_t& aQNameIter,
    PlanIter_t& aAttrs,
    PlanIter_t& aChildren,
    bool assignId)
    :
    Batcher<ElementIterator> ( loc ),
    theQNameIter ( aQNameIter ),
    theAttributesIter ( aAttrs ),
    theChildrenIter ( aChildren ),
    theAssignId(assignId)
{
}

ElementIterator::ElementIterator (
    const yy::location& loc,
    PlanIter_t& aQNameIter,
    PlanIter_t& aChildren,
    bool assignId)
    :
    Batcher<ElementIterator> ( loc ),
    theQNameIter ( aQNameIter ),
    theAttributesIter ( 0 ),
    theChildrenIter ( aChildren ),
    theAssignId(assignId)
{
}


Item_t
ElementIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  Iterator_t cwrapper = 0;
  Iterator_t awrapper = 0;
  Iterator_t nwrapper = 0;
  Item_t lItem;
  QNameItem_t lQName;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lItem = consumeNext(theQNameIter, planState);
  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  lQName = (QNameItem*)&*lItem;

  if (theChildrenIter != 0)
    cwrapper = new PlanIteratorWrapper(theChildrenIter, planState);

  if (theAttributesIter != 0)
    awrapper = new PlanIteratorWrapper(theAttributesIter, planState);

  item = zorba::getItemFactory()->createElementNode(
               lQName,
               GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
               cwrapper,
               awrapper,
               nwrapper,
               theNsBindings,
               false,
               false,
               theAssignId);

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
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    state->theContextItem = this->consumeNext(theChild, planState );
    
    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child
    if (state->theContextItem != 0 
        && state->theContextItem->isNode() 
        && (state->theContextItem->getNodeKind() == StoreConsts::attributeNode)) 
    {
      if (state->theNoAttrAllowed)
      {
        ZorbaErrorAlerts::error_alert (
          error_messages::XQTY0024_TYPE_ATTRIBUTE_NODE_OUT_OF_ORDER,
          error_messages::RUNTIME_ERROR,
          false,
          "Content sequence of element contains an attribute node following a node that is not an attribute node!"
        );
      }
    }
    else
    {
      state->theNoAttrAllowed = true;
    }
    
    if (state->theContextItem == 0)
    {
      if (state->theString != "")
      {
        STACK_PUSH(zorba::getItemFactory()->createTextNode(state->theString, false), state);
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
        STACK_PUSH(zorba::getItemFactory()->createTextNode(state->theString, false), state);
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
  state->theString.~xqpString();
}

void ElementContentIterator::ElementContentState::init()
{
  PlanIterator::PlanIteratorState::init();
  theContextItem = 0;
  theString = "";
  theNoAttrAllowed = false;
}


/*******************************************************************************

********************************************************************************/
AttributeIterator::AttributeIterator(
    const yy::location& loc,
    PlanIter_t& aQNameIter,
    PlanIter_t& aValueIter,
    bool assignId)
  :
    BinaryBaseIterator<AttributeIterator>( loc, aQNameIter, aValueIter ),
    theAssignId(assignId)
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
  QNameItem_t lQName;
  xqp_string lexicalString;
  bool concatenation = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  itemCur = consumeNext(theChild0, planState);
  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  lQName = (QNameItem*)&*itemCur;

  if ((itemFirst = consumeNext(theChild1, planState)) != 0)
  {
    lexicalString = itemFirst->getStringProperty();

    // handle concatenation
    itemCur = consumeNext ( theChild1, planState );
    while ( itemCur != NULL )
    {
      concatenation = true;
      lexicalString += itemCur->getStringProperty();
      itemCur = consumeNext ( theChild1, planState );
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
    itemLexical = 0;
    itemTyped = 0;
  }

  item = zorba::getItemFactory()->createAttributeNode (
               lQName,
               GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
               itemLexical,
               itemTyped,
               theAssignId);

  STACK_PUSH(item, state);
  STACK_END();
}

/*******************************************************************************


********************************************************************************/

DocumentIterator::DocumentIterator( const yy::location& loc, PlanIter_t& aChild)
  : UnaryBaseIterator<DocumentIterator>(loc, aChild)
{}

Item_t DocumentIterator::nextImpl(PlanState& planState) {
  Store* lStore = zorba::getStore();
  Iterator_t lChildWrapper;
  Item_t lItem;
  xqp_string lBaseUri = "";
  xqp_string lDocUri = "";
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  lChildWrapper = new PlanIteratorWrapper(theChild, planState); 
  
  lItem = zorba::getItemFactory()->createDocumentNode (
                                lBaseUri.theStrStore,
                                lDocUri.theStrStore,
                                lChildWrapper, true);

  STACK_PUSH(lItem, state);
  STACK_END();
}


DocumentContentIterator::DocumentContentIterator( const yy::location& loc, PlanIter_t& aChild)
  : UnaryBaseIterator<DocumentContentIterator>(loc, aChild)
{}

Item_t DocumentContentIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  while (true) {
    lItem = consumeNext(theChild, planState);
    if (lItem == 0)
      break;
    if (lItem->isNode()) {
      if (lItem->getNodeKind() == StoreConsts::attributeNode) {
        // throwing an error when child is an attribute node
        ZorbaErrorAlerts::error_alert (
          error_messages::XQTY0024_TYPE_ATTRIBUTE_NODE_OUT_OF_ORDER,
          error_messages::RUNTIME_ERROR,
          false,
          "A Document Node must not contain attribute nodes!"
        );
      } 
    }
    STACK_PUSH(lItem, state);
  }
  STACK_END();
}


void DocFilterIterator::DocFilterIteratorState::init() {
  theChildren = 0;
  theCurItem = 0;
}

DocFilterIterator::DocFilterIterator( const yy::location& loc, PlanIter_t& aChild)
  : UnaryBaseIterator<DocFilterIterator>(loc, aChild){}

Item_t DocFilterIterator::nextImpl(PlanState& planState) {
  Item_t lItem;
  
  DocFilterIteratorState* state;
  DEFAULT_STACK_INIT(DocFilterIteratorState, state, planState);
 
  while (true) {
    if (state->theChildren != 0) {
      lItem = state->theChildren->next();
      if (lItem == 0) {
        state->theChildren->close();
        state->theChildren = 0;
        state->theCurItem = 0;
      } else {
        STACK_PUSH(lItem, state);
      }
    } else {
      lItem = consumeNext(theChild, planState);
      if (lItem == 0)
        break;
      if (lItem->isNode() && lItem->getNodeKind() == StoreConsts::documentNode) {
        state->theChildren = lItem->getChildren();
        state->theCurItem = lItem;
      } else {
        STACK_PUSH(lItem, state);
      }
    }
  }
  STACK_END();
}

void DocFilterIterator::releaseResourcesImpl(PlanState& planState) {
  UnaryBaseIterator<DocFilterIterator>::releaseResourcesImpl(planState);
  DocFilterIteratorState* state;
  GET_STATE(DocFilterIteratorState, state, planState);
  if (state->theChildren != 0) {
    state->theChildren->close();
    state->theChildren = 0;
    state->theCurItem = 0;
  }
}


/********************************************************************************


********************************************************************************/
CommentIterator::CommentIterator (
    const yy::location& loc,
    PlanIter_t& aComment,
    bool assignId)
  :
  UnaryBaseIterator<CommentIterator>(loc, aComment),
  theAssignId(assignId)
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
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
    
    /*
    ewrapper = new PlanIterWrapper(theExpressionIter, planState);
    seqExpression = store->createTempSeq(ewrapper);
    */
    // TODO: put a while() to handle expressions        
  child = consumeNext(theChild, planState);    
  if (child != NULL)
    content = child->getStringValue(); // TODO: maybe getStringProperty()?
  
  item = zorba::getItemFactory()->createCommentNode(
               content,
               theAssignId);

  STACK_PUSH(item, state);
    
  STACK_END();
}


/*******************************************************************************

********************************************************************************/
TextIterator::TextIterator(
    const yy::location& loc,
    PlanIter_t& aChild,
    bool assignId) 
  :
  UnaryBaseIterator<TextIterator>(loc, aChild),
  theAssignId(assignId)
{
}


Item_t TextIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  xqp_string content = "";
  bool lFirst;

  Store* store = zorba::getStore();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lFirst = true;
  while (true)
  {
    lItem = consumeNext(theChild, planState);
    if (lItem == 0)
      break;
    
    if (!lFirst)
      content += " ";
    content += lItem->getStringProperty();
    lFirst = false;
  }

  lItem = zorba::getItemFactory()->createTextNode(content, theAssignId);

  STACK_PUSH(lItem, state);
    
  STACK_END();
}

/* end class TextIterator */

}
