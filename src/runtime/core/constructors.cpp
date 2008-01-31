#include <memory>
#include "util/Assert.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "types/typesystem.h"
#include "context/static_context.h"
#include "context/namespace_context.h"
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
  xqpStringStore_t baseUri = 0;
  xqpStringStore_t docUri = 0;
  Item_t node;

  DocumentIteratorState* state;
  DEFAULT_STACK_INIT(DocumentIteratorState, state, planState);
  
  // Note: baseUri and docUri have to be rchandles because if createDocumentNode
  // throws and exception, we don't know if the exception was thrown before or
  // after the ownership of the uris was transfered to the doc node.
  baseUri = new xqpStringStore("");
  docUri = new xqpStringStore("");
  childWrapper = new PlanIteratorWrapper(theChild, planState); 
  
  try
  {
    node = Zorba::getItemFactory()->
           createDocumentNode((unsigned long)&planState,
                              baseUri,
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
    delete childWrapper;
    throw;
  }

  STACK_PUSH(node, state);
  STACK_END();
}


void DocumentIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<DocumentIterator>::setOffset(planState, offset);

  DocumentIteratorState* state;
  GET_STATE(DocumentIteratorState, state, planState);

  static_context* sctx = planState.theZorba->get_static_context();

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
        ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, false,
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
    PlanIter_t&         qnameIter,
    PlanIter_t&         attrsIter,
    PlanIter_t&         childrenIter,
    namespace_context*  ctxBindings,
    namespace_context*  localBindings,
    bool                isRoot)
  :
  Batcher<ElementIterator>(loc),
  theQNameIter(qnameIter),
  theAttributesIter(attrsIter),
  theChildrenIter(childrenIter),
  theContextBindigns(ctxBindings),
  theLocalBindings(localBindings),
  theIsRoot(isRoot)
{
}


Item_t ElementIterator::nextImpl(PlanState& planState)
{
  std::auto_ptr<Iterator> cwrapper;
  std::auto_ptr<Iterator> awrapper;

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
    cwrapper.reset(new PlanIteratorWrapper(theChildrenIter, planState));

  if (theAttributesIter != 0)
    awrapper.reset(new PlanIteratorWrapper(theAttributesIter, planState));

  node = Zorba::getItemFactory()->
         createElementNode((unsigned long)&planState,
                           qnameItem.get_ptr(),
                           GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
                           cwrapper.get(),
                           awrapper.get(),
                           NULL,
                           theLocalBindings->get_bindings(),
                           theIsRoot,
                           true,
                           state->theTypePreserve,
                           state->theNsPreserve,
                           state->theNsInherit);
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

  static_context* sctx = planState.theZorba->get_static_context();

  state->theTypePreserve =
    (sctx->construction_mode() == StaticQueryContext::cons_preserve ? true : false);

  state->theNsPreserve =
    (sctx->preserve_mode() == StaticQueryContext::preserve_ns ? true : false);

  state->theNsInherit = 
    (sctx->inherit_mode() == StaticQueryContext::inherit_ns ? true : false);
}


/*******************************************************************************

********************************************************************************/
Item_t ElementContentIterator::nextImpl(PlanState& planState)
{
  ItemFactory* factory = Zorba::getItemFactory();
  Item_t item;
  Item_t textNode;

  ElementContentState* state;
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    item = this->consumeNext(theChildren[0], planState );
    if (item == NULL)
      break;

    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child.
    if (item->isNode() && item->getNodeKind() == StoreConsts::attributeNode) 
    {
      if (state->theNoAttrAllowed)
        ZORBA_ERROR_ALERT(ZorbaError::XQTY0024, &loc, false);
    }
    else
    {
      state->theNoAttrAllowed = true;
    }
    
    if (item->isNode())
    {
      STACK_PUSH(item, state);
    }
    else 
    {
      textNode = factory->createTextNode((ulong)&planState,
                                         item->getStringValue().getStore(),
                                         false);
      STACK_PUSH(textNode, state);
    }
  }

  STACK_END();
}


void ElementContentState::init()
{
  PlanIteratorState::init();
  theNoAttrAllowed = false;
}


void ElementContentState::reset()
{
  PlanIteratorState::reset();
  theNoAttrAllowed = false;
}


/*******************************************************************************

********************************************************************************/
AttributeIterator::AttributeIterator(
    const yy::location& loc,
    PlanIter_t&  aQNameIter,
    PlanIter_t&  aValueIter,
    bool         isRoot)
  :
    BinaryBaseIterator<AttributeIterator>( loc, aQNameIter, aValueIter ),
    theIsRoot(isRoot)
{
}


Item_t AttributeIterator::nextImpl(PlanState& planState)
{
  Item_t node;
  Iterator_t nameWrapper;
  Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  nameWrapper = new PlanIteratorWrapper(theChild0, planState);
  valueWrapper = new PlanIteratorWrapper(theChild1, planState);
  
  node = Zorba::getItemFactory()->
         createAttributeNode((unsigned long)&planState,
                             nameWrapper,
                             GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME,
                             valueWrapper,
                             theIsRoot);

  STACK_PUSH(node, state);
  STACK_END();
}


/*******************************************************************************

********************************************************************************/
TextIterator::TextIterator(
    const yy::location& loc,
    PlanIter_t& aChild,
    bool isRoot) 
  :
  UnaryBaseIterator<TextIterator>(loc, aChild),
  theIsRoot(isRoot)
{
}


Item_t TextIterator::nextImpl(PlanState& planState)
{
  Item_t node;
  Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valueWrapper = new PlanIteratorWrapper(theChild, planState);
      
  node = Zorba::getItemFactory()->createTextNode((ulong)&planState,
                                                 valueWrapper,
                                                 theIsRoot);

  STACK_PUSH(node, state);
    
  STACK_END();
}


/*******************************************************************************

********************************************************************************/
PiIterator::PiIterator (
    const yy::location& loc,
    PlanIter_t& aTarget,
    PlanIter_t& aContent,
    bool isRoot)
  :
  BinaryBaseIterator<PiIterator>(loc, aTarget, aContent),
  theIsRoot(isRoot)
{
}


Item_t PiIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  xqp_string target, content;
  bool lFirst;

  Store* store = Zorba::getStore();

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lItem = consumeNext(theChild0, planState);
  if (lItem == 0)
    ZORBA_ERROR_ALERT (ZorbaError::XPTY0004);

  if (consumeNext(theChild0, planState) != 0)
    ZORBA_ERROR_ALERT (ZorbaError::XPTY0004);

  // TODO: check if lItem is string, raise XPTY0004 if not
  target = lItem->getStringValue();
  if (target.empty ())
    ZORBA_ERROR_ALERT (ZorbaError::XQDY0041);
  else if (target.substr (0).uppercase () == "XML") 
    ZORBA_ERROR_ALERT (ZorbaError::XQDY0064);
  
  for (lFirst = true; 0 != (lItem = consumeNext (theChild1, planState)); lFirst = false)
  {
    if (! lFirst) content += " ";

    xqpString strvalue = lItem->getStringValue();
    if (strvalue.indexOf("?>") >= 0)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQDY0026);
    }
    content += strvalue;
  }

  content = content.trimL(" \n\r\t", 4);

  lItem = Zorba::getItemFactory()->createPiNode((ulong)&planState,
                                                target.getStore(),
                                                content.getStore (),
                                                theIsRoot);
  STACK_PUSH(lItem, state);
  
  STACK_END();
}


/********************************************************************************

********************************************************************************/
CommentIterator::CommentIterator(
    const yy::location& loc,
    PlanIter_t& aComment,
    bool isRoot)
  :
  UnaryBaseIterator<CommentIterator>(loc, aComment),
  theIsRoot(isRoot)
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

  
  if (content.indexOf("-") == (long)(content.size()-1))
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0072);
  }

  if (content.indexOf("--") >= 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0072);
  }

  lItem = Zorba::getItemFactory()->createCommentNode((ulong)&planState,
                                                     content.getStore(),
                                                     theIsRoot);
    
  STACK_PUSH(lItem, state);
    
  STACK_END();
}


/*******************************************************************************

********************************************************************************/

EnclosedIterator::EnclosedIterator (
    const yy::location& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator> ( loc, childIter ),
  theAttrContent(false)
{
}


Item_t EnclosedIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  ItemFactory* factory = Zorba::getItemFactory();
  xqpString str;

  EnclosedState* state;
  DEFAULT_STACK_INIT(EnclosedState, state, planState);

  if (theAttrContent)
  {
    while ( true )
    {
      state->theContextItem = consumeNext(theChild, planState);

      if (state->theContextItem == NULL)
      {
        if (state->theString != NULL)
        {
          lItem = factory->createString(state->theString);
          state->theString = NULL;
          STACK_PUSH(lItem, state);
        }

        break;
      }

      else if (state->theContextItem->isNode())
      {
        if ( state->theString != NULL)
        {
          lItem = factory->createString(state->theString);
          state->theString = NULL;
          STACK_PUSH(lItem, state);
        }

        STACK_PUSH(state->theContextItem, state);
      }

      else if (state->theString == NULL)
      {
        state->theString = new xqpStringStore(state->theContextItem->getStringValue().c_str());
      }
      else
      {
        state->theString->append(" ");
        state->theString->append(state->theContextItem->getStringValue().c_str());
      }
    }
  }
  else
  {
    while ( true )
    {
      state->theContextItem = consumeNext(theChild, planState);

      if (state->theContextItem == NULL)
        break;

      else if (state->theContextItem->isNode())
      {
        state->theString = NULL;

        STACK_PUSH(state->theContextItem, state);
      }

      else
      {
        str = state->theContextItem->getStringValue();

        if (state->theString != NULL)
          str = " " + str;
        else
          state->theString = str.getStore();

        state->theContextItem = factory->createTextNode((ulong)&planState,
                                                        str.getStore(),
                                                        false);
        STACK_PUSH(state->theContextItem, state);
      }
    }
  }

  STACK_END();
}
  

void EnclosedIterator::resetImpl(PlanState& planState)
{
  UnaryBaseIterator<EnclosedIterator>::resetImpl(planState);

  EnclosedState* state;
  GET_STATE ( EnclosedState, state, planState );

  if (state->theString != NULL && theAttrContent)
    delete state->theString;

  state->theString = NULL;
}


void EnclosedIterator::releaseResourcesImpl(PlanState& planState)
{
  UnaryBaseIterator<EnclosedIterator>::releaseResourcesImpl ( planState );

  EnclosedState* state;
  GET_STATE ( EnclosedState, state, planState );
  state->theContextItem = NULL;

  if (state->theString != NULL && theAttrContent)
    delete state->theString;

  state->theString = NULL;
}


void EnclosedIterator::setOffset(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<EnclosedIterator>::setOffset ( planState, offset );
  
  EnclosedState* state = new ( planState.theBlock + stateOffset ) EnclosedState;
}


void EnclosedIterator::EnclosedState::init()
{
  PlanIteratorState::init();
  theString = NULL;
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
