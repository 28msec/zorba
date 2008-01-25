
#include "util/Assert.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "types/typesystem.h"
#include "context/static_context.h"
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

DocumentIterator::DocumentIterator(const yy::location& loc, PlanIter_t& input)
  :
  UnaryBaseIterator<DocumentIterator>(loc, input)
{
}


Item_t DocumentIterator::nextImpl(PlanState& planState)
{
  Iterator* childWrapper = 0;
  xqpStringStore* baseUri = 0;
  xqpStringStore* docUri = 0;
  Item_t node;

  DocumentIteratorState* state;
  DEFAULT_STACK_INIT(DocumentIteratorState, state, planState);
  
  baseUri = new xqpStringStore("");
  docUri = new xqpStringStore("");
  childWrapper = new PlanIteratorWrapper(theChild, planState); 
  
  try
  {
    node = Zorba::getItemFactory()->
           createDocumentNode(baseUri,
                              docUri,
                              childWrapper,
                              true, // is root
                              true, // copy children
                              state->theTypePreserve,
                              state->theNsPreserve,
                              state->theNsInherit);
  }
  catch(...)
  {
    delete baseUri;
    delete docUri;
    delete childWrapper;
  }

  STACK_PUSH(node, state);
  STACK_END();
}


void DocumentIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<DocumentIterator>::setOffset(planState, offset);

  DocumentIteratorState* state;
  GET_STATE(DocumentIteratorState, state, planState);

  static_context* sctx = planState.zorp->get_static_context();

  state->theTypePreserve =
    (sctx->construction_mode() == StaticQueryContext::cons_preserve ? true : false);

  state->theNsPreserve =
    (sctx->preserve_mode() == StaticQueryContext::preserve_ns ? true : false);

  state->theNsInherit = 
    (sctx->inherit_mode() == StaticQueryContext::inherit_ns ? true : false);
}


/*******************************************************************************

********************************************************************************/

DocumentContentIterator::DocumentContentIterator(
    const yy::location& loc,
    PlanIter_t& aChild)
  :
  UnaryBaseIterator<DocumentContentIterator>(loc, aChild)
{
}


Item_t DocumentContentIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (true)
  {
    lItem = consumeNext(theChild, planState);
    if (lItem == 0)
      break;

    if (lItem->isNode() && lItem->getNodeKind() == StoreConsts::attributeNode)
    {
        ZORBA_ERROR_ALERT(ZorbaError::XQTY0024, &loc, false,
                          "A Document Node must not contain attribute nodes!");
    }

    STACK_PUSH(lItem, state);
  }

  STACK_END();
}


/*******************************************************************************

********************************************************************************/
ElementIterator::ElementIterator (
    const yy::location& loc,
    PlanIter_t&  qnameIter,
    PlanIter_t&  attrsIter,
    PlanIter_t&  childrenIter,
    NsBindings&  nsBindings,
    bool         assignId)
    :
    Batcher<ElementIterator>(loc),
    theQNameIter(qnameIter),
    theAttributesIter(attrsIter),
    theChildrenIter(childrenIter),
    theNsBindings(nsBindings),
    theAssignId(assignId)
{
}


ElementIterator::ElementIterator (
    const yy::location& loc,
    PlanIter_t&  qnameIter,
    PlanIter_t&  childrenIter,
    bool         assignId)
    :
    Batcher<ElementIterator>(loc),
    theQNameIter(qnameIter),
    theAttributesIter(0),
    theChildrenIter(childrenIter),
    theAssignId(assignId)
{
}


Item_t ElementIterator::nextImpl(PlanState& planState)
{
  Iterator* cwrapper = 0;
  Iterator* awrapper = 0;
  Item_t qnameItem;
  Item_t node;

  ElementIteratorState* state;
  DEFAULT_STACK_INIT(ElementIteratorState, state, planState);

  qnameItem = consumeNext(theQNameIter, planState);

  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  if (qnameItem->getLocalName().size() == 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0074, false, false,
                      "Element name must not have an empty local part.");
  }

  if (theChildrenIter != 0)
    cwrapper = new PlanIteratorWrapper(theChildrenIter, planState);

  if (theAttributesIter != 0)
    awrapper = new PlanIteratorWrapper(theAttributesIter, planState);

  try
  {
    node = Zorba::getItemFactory()->
           createElementNode(qnameItem.get_ptr(),
                             GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
                             cwrapper,
                             awrapper,
                             NULL,
                             theNsBindings,
                             theAssignId,
                             true,
                             state->theTypePreserve,
                             state->theNsPreserve,
                             state->theNsInherit);
  }
  catch(...)
  {
    if (cwrapper != 0) delete cwrapper;
    if (awrapper != 0) delete awrapper;
  }

  STACK_PUSH(node, state);
  STACK_END();
}


void ElementIterator::resetImpl(PlanState& planState)
{
  if (theQNameIter != 0)
    resetChild(theQNameIter, planState);
  
  if ( theChildrenIter != 0 )
    resetChild(theChildrenIter, planState);

  if (theAttributesIter != 0)
    resetChild(theAttributesIter, planState);

  if (theNamespacesIter != 0)
    resetChild(theNamespacesIter, planState);

  ElementIteratorState* state;
  GET_STATE(ElementIteratorState, state, planState);
  state->reset();
}


void ElementIterator::releaseResourcesImpl(PlanState& planState)
{
  if (theQNameIter != 0)
    releaseChildResources(theQNameIter, planState);
  
  if (theChildrenIter != 0)
    releaseChildResources(theChildrenIter, planState);

  if (theAttributesIter != 0)
    releaseChildResources(theAttributesIter, planState);

  if (theNamespacesIter != 0)
    releaseChildResources(theNamespacesIter, planState);

  ElementIteratorState* state;
  GET_STATE(ElementIteratorState, state, planState);
  state->releaseResources();
}

  
uint32_t ElementIterator::getStateSizeOfSubtree() const
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

  return getStateSize() + size;
}

  
void ElementIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  this->stateOffset = offset;
  offset += getStateSize();

  if (theQNameIter != 0)
    theQNameIter->setOffset(planState, offset);
  
  if (theChildrenIter != 0)
    theChildrenIter->setOffset(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->setOffset(planState, offset);

  if (theNamespacesIter != 0)
    theNamespacesIter->setOffset(planState, offset);

  ElementIteratorState* state;
  GET_STATE(ElementIteratorState, state, planState);

  static_context* sctx = planState.zorp->get_static_context();

  state->theTypePreserve =
    (sctx->construction_mode() == StaticQueryContext::cons_preserve ? true : false);

  state->theNsPreserve =
    (sctx->preserve_mode() == StaticQueryContext::preserve_ns ? true : false);

  state->theNsInherit = 
    (sctx->inherit_mode() == StaticQueryContext::inherit_ns ? true : false);
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

    
Item_t ElementContentIterator::nextImpl(PlanState& planState)
{
  xqpStringStore* tmp;

  ElementContentState* state;
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    state->theContextItem = this->consumeNext(theChild, planState );

    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child.
    if (state->theContextItem != 0 &&
        state->theContextItem->isNode() &&
        state->theContextItem->getNodeKind() == StoreConsts::attributeNode) 
    {
      if (state->theNoAttrAllowed)
        ZORBA_ERROR_ALERT(ZorbaError::XQTY0024, &loc, false);
    }
    else
    {
      state->theNoAttrAllowed = true;
    }
    
    if (state->theContextItem == 0)
    {
      if (state->theString != NULL && *(state->theString) != "")
      {
        // Release ownership of theString *before* passing it to the text node.
        tmp = state->theString;
        state->theString = NULL;
        STACK_PUSH(Zorba::getItemFactory()->createTextNode(tmp, false), state);
      }
      break;
    }
    else if (state->theContextItem->isNode() &&
             state->theContextItem->getNodeKind() == StoreConsts::textNode) 
    {
      if (state->theString == NULL)
        state->theString = new xqpStringStore(state->theContextItem->getStringValue().c_str());
      else
        *(state->theString) += state->theContextItem->getStringValue().c_str();
    }
    else 
    {
      if (state->theString != NULL && *(state->theString) != "")
      {
        tmp = state->theString;
        state->theString = NULL;
        STACK_PUSH(Zorba::getItemFactory()->createTextNode(tmp, false), state);
      }

      STACK_PUSH(state->theContextItem, state);
    }
  }

  STACK_END();
}


void ElementContentIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<ElementContentIterator>::resetImpl(planState);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, planState);

  if (state->theString != NULL)
  {
    delete state->theString;
    state->theString = NULL;
  }

  state->theContextItem = 0;
  state->theNoAttrAllowed = false;
}

  
void ElementContentIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<ElementContentIterator>::releaseResourcesImpl(planState);

  ElementContentState* state;
  GET_STATE(ElementContentState, state, planState);

  if (state->theString != NULL)
  {
    delete state->theString;
    state->theString = NULL;
  }

  state->theContextItem = NULL;
}


void ElementContentIterator::ElementContentState::init()
{
  PlanIteratorState::init();
  theContextItem = 0;
  theString = NULL;
  theNoAttrAllowed = false;
}


/*******************************************************************************

********************************************************************************/
AttributeIterator::AttributeIterator(
    const yy::location& loc,
    PlanIter_t&  aQNameIter,
    PlanIter_t&  aValueIter,
    bool         assignId)
  :
    BinaryBaseIterator<AttributeIterator>( loc, aQNameIter, aValueIter ),
    theAssignId(assignId)
{
}


Item_t AttributeIterator::nextImpl(PlanState& planState)
{
  Item_t item;
  Item_t itemCur;
  Item_t itemFirst;
  Item_t itemLexical;
  Item_t itemTyped;
  Item_t itemQName;
  xqp_string lexicalString;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  
  // Compute the attribute name. Note: we don't have to check that itemQName 
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around the expression.
  itemQName = consumeNext(theChild0, planState);
  if (itemQName->getLocalName().size() == 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0074, false, false,
                      "Attribute name must not have an empty local part.");
  }

  if ((itemFirst = consumeNext(theChild1, planState)) != 0)
  {
    lexicalString = itemFirst->getStringValue();

    // handle concatenation
    itemCur = consumeNext ( theChild1, planState );
    while ( itemCur != NULL )
    {
      lexicalString += itemCur->getStringValue();
      itemCur = consumeNext ( theChild1, planState );
    }

    itemTyped = Zorba::getItemFactory()->createUntypedAtomic(lexicalString);
  }
  else
  {
    itemTyped = 0;
  }

  item = Zorba::getItemFactory()->
         createAttributeNode(itemQName,
                             GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME,
                             itemTyped,
                             theAssignId);

  STACK_PUSH(item, state);
  STACK_END();
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
  Item_t lItem;
  xqp_string content = "";
  bool lFirst;

  Store* store = Zorba::getStore();

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
    content += lItem->getStringValue();
    lFirst = false;
  }

  if (! content.empty ()) 
  {
    lItem = Zorba::getItemFactory()->createCommentNode(content.getStore(), theAssignId);
    
    STACK_PUSH(lItem, state);
  }
    
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
  Item_t lItem, lAtomicItem;
  xqp_string content = "";
  bool lFirst;

  Store* store = Zorba::getStore();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lFirst = true;
  while (true)
  {
    lItem = consumeNext(theChild, planState);
    if (lItem == 0)
      break;
    
    lAtomicItem = lItem->getAtomizationValue();
    if (!lFirst)
      content += " ";
    content += lAtomicItem->getStringValue();
    lFirst = false;
  }

  lItem = Zorba::getItemFactory()->createTextNode(content.getStore(), theAssignId);

  STACK_PUSH(lItem, state);
    
  STACK_END();
}


/*******************************************************************************

********************************************************************************/

EnclosedIterator::EnclosedIterator (
    const yy::location& loc,
    PlanIter_t& childIter,
    bool aAttrContent )
  :
  UnaryBaseIterator<EnclosedIterator> ( loc, childIter ),
  theAttrContent(aAttrContent)
{
}


Item_t EnclosedIterator::nextImpl ( PlanState& planState )
{
  Item_t lItem;

  ItemFactory* factory = Zorba::getItemFactory();

  static_context* sctx = NULL;

  EnclosedState* state;
  DEFAULT_STACK_INIT(EnclosedState, state, planState);

  state->init();

  while ( true )
  {
    state->theContextItem = consumeNext(theChild, planState);

    if ( state->theContextItem == NULL )
    {
      if ( state->theString != "" )
      {
        if (theAttrContent)
        {
          lItem = factory->createString(state->theString);
        }
        else
        {
          lItem = factory->createTextNode(state->theString.getStore(), false);
        }

        STACK_PUSH(lItem, state);

        state->theString = "";
      }
      break;
    }

    else if (state->theContextItem->isNode())
    {
      if ( state->theString != "" )
      {
        if (theAttrContent)
        {
          lItem = factory->createString(state->theString);
        }
        else
        {
          lItem = factory->createTextNode(state->theString.getStore(), false);
        }

        STACK_PUSH(lItem, state);

        state->theString = "";
      }

      STACK_PUSH(state->theContextItem, state);
    }

    else if ( state->theString == "" )
    {
      state->theString = state->theContextItem->getStringValue();
    }
    else
    {
      state->theString += " " + state->theContextItem->getStringValue();
    }
  }
  STACK_END();
}
  

void EnclosedIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<EnclosedIterator>::resetImpl(planState);

  EnclosedState* state;
  GET_STATE ( EnclosedState, state, planState );
  state->theString = "";
}


void EnclosedIterator::releaseResourcesImpl ( PlanState& planState )
{
  UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl ( planState );

  EnclosedState* state;
  GET_STATE ( EnclosedState, state, planState );
  state->theContextItem = NULL;
  state->theString.~xqpString();
}


void EnclosedIterator::setOffset ( PlanState& planState, uint32_t& offset )
{
  UnaryBaseIterator<EnclosedIterator>::setOffset ( planState, offset );
  
  EnclosedState* state = new ( planState.block + stateOffset ) EnclosedState;
}


void EnclosedIterator::EnclosedState::init()
{
  PlanIteratorState::init();
  theString = "";
}



/*******************************************************************************

********************************************************************************/

void DocFilterIterator::DocFilterIteratorState::init() 
{
  theChildren = 0;
  theCurItem = 0;
}


DocFilterIterator::DocFilterIterator(const yy::location& loc, PlanIter_t& aChild)
  :
  UnaryBaseIterator<DocFilterIterator>(loc, aChild)
{
}


Item_t DocFilterIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  
  DocFilterIteratorState* state;
  DEFAULT_STACK_INIT(DocFilterIteratorState, state, planState);
 
  while (true)
  {
    if (state->theChildren != 0)
    {
      lItem = state->theChildren->next();
      if (lItem == 0)
      {
        state->theChildren->close();
        state->theChildren = 0;
        state->theCurItem = 0;
      }
      else
      {
        STACK_PUSH(lItem, state);
      }
    }
    else
    {
      lItem = consumeNext(theChild, planState);
      if (lItem == 0)
        break;
      if (lItem->isNode() && lItem->getNodeKind() == StoreConsts::documentNode)
      {
        state->theChildren = lItem->getChildren();
        state->theCurItem = lItem;
      }
      else
      {
        STACK_PUSH(lItem, state);
      }
    }
  }
  STACK_END();
}


void DocFilterIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<DocFilterIterator>::releaseResourcesImpl(planState);

  DocFilterIteratorState* state;
  GET_STATE(DocFilterIteratorState, state, planState);
  if (state->theChildren != 0)
  {
    state->theChildren->close();
    state->theChildren = 0;
  }
  state->theCurItem = 0;
}

}
