#include "runtime/core/constructors.h"
#include <memory>
#include <sys/types.h>
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
#include "runtime/visitors/planitervisitor.h"
#include "runtime/base/statetraits.h"


using namespace std;
namespace xqp
{


/*******************************************************************************

********************************************************************************/
Item_t DocumentIterator::nextImpl(PlanState& planState)
{
  xqpStringStore_t baseUri = 0;
  xqpStringStore_t docUri = 0;
  Item_t node;

  DocumentIteratorState* state;
  GET_STATE(DocumentIteratorState, state, planState);
  MANUAL_STACK_INIT(state);

  // Note: baseUri and docUri have to be rchandles because if createDocumentNode
  // throws and exception, we don't know if the exception was thrown before or
  // after the ownership of the uris was transfered to the doc node.
  baseUri = new xqpStringStore("");
  docUri = new xqpStringStore("");
  state->childWrapper = new PlanIteratorWrapper(theChild, planState); 

  FINISHED_ALLOCATING_RESOURCES();
  
  node = Zorba::getItemFactory()->
          createDocumentNode((unsigned long)&planState,
                              baseUri,
                              docUri,
                              state->childWrapper,
                              true, // is root
                              true, // copy children
                              state->theTypePreserve,
                              state->theNsPreserve,
                              state->theNsInherit);

  STACK_PUSH(node, state);
  STACK_END();
}

void
DocumentIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);

  static_context* sctx = planState.theZorba->get_static_context();

  theTypePreserve =
    (sctx->construction_mode() == StaticQueryContext::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticQueryContext::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticQueryContext::inherit_ns ? true : false);
}

void
DocumentIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
}

DocumentIteratorState::~DocumentIteratorState()
{
  delete childWrapper; childWrapper = 0;
}

/*******************************************************************************

********************************************************************************/
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
void
ElementIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  static_context* sctx = planState.theZorba->get_static_context();

  theTypePreserve =
    (sctx->construction_mode() == StaticQueryContext::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticQueryContext::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticQueryContext::inherit_ns ? true : false);
}


void
ElementIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
}


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
  theContextBindings(ctxBindings),
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
                           qnameItem.getp(),
                           GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
                           cwrapper.get(),
                           awrapper.get(),
                           NULL,
                           theContextBindings->get_bindings(),
                           theLocalBindings->get_bindings(),
                           theIsRoot,
                           true,
                           state->theTypePreserve,
                           state->theNsPreserve,
                           state->theNsInherit);
  STACK_PUSH(node, state);
  STACK_END();
}


void ElementIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<ElementIteratorState>::createState(planState, this->stateOffset, offset);

  if (theQNameIter != 0)
    theQNameIter->open(planState, offset);
  
  if ( theChildrenIter != 0 )
    theChildrenIter->open(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->open(planState, offset);

  if (theNamespacesIter != 0)
    theNamespacesIter->open(planState, offset);
  
}

void ElementIterator::resetImpl(PlanState& planState)
{
  StateTraitsImpl<ElementIteratorState>::reset(planState, this->stateOffset);

  if (theQNameIter != 0)
    theQNameIter->reset(planState);
  
  if ( theChildrenIter != 0 )
    theChildrenIter->reset(planState);

  if (theAttributesIter != 0)
    theAttributesIter->reset(planState);

  if (theNamespacesIter != 0)
    theNamespacesIter->reset(planState);

}


void ElementIterator::closeImpl(PlanState& planState)
{
  if (theQNameIter != 0)
    theQNameIter->close(planState);
  
  if (theChildrenIter != 0)
    theChildrenIter->close(planState);

  if (theAttributesIter != 0)
    theAttributesIter->close(planState);

  if (theNamespacesIter != 0)
    theNamespacesIter->close(planState);

  StateTraitsImpl<ElementIteratorState>::destroyState(planState, this->stateOffset);
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


void ElementContentState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theNoAttrAllowed = false;
}


void ElementContentState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
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
    BinaryBaseIterator<AttributeIterator, PlanIteratorState>( loc, aQNameIter, aValueIter ),
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
  : UnaryBaseIterator<TextIterator, PlanIteratorState>(loc, aChild),
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
  BinaryBaseIterator<PiIterator, PlanIteratorState>(loc, aTarget, aContent),
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
  : UnaryBaseIterator<CommentIterator, PlanIteratorState>(loc, aComment),
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
void EnclosedIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theString = NULL;
}

void EnclosedIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  theString = NULL;
  theContextItem = NULL;
}

EnclosedIteratorState::~EnclosedIteratorState()
{
  // TODO fix this (theAttrContent is not available)
  //if (theString != NULL && theAttrContent)
  //    delete state->theString;
}

EnclosedIterator::EnclosedIterator (
    const yy::location& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState> ( loc, childIter ),
  theAttrContent(false)
{
}


Item_t EnclosedIterator::nextImpl(PlanState& planState)
{
  Item_t lItem;
  ItemFactory* factory = Zorba::getItemFactory();
  xqpString str;

  EnclosedIteratorState* state;
  DEFAULT_STACK_INIT(EnclosedIteratorState, state, planState);

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

        if (str == "")
          continue;

        state->theContextItem = factory->createTextNode((ulong)&planState,
                                                        str.getStore(),
                                                        false);
        STACK_PUSH(state->theContextItem, state);
      }
    }
  }

  STACK_END();
}
  

/*******************************************************************************

********************************************************************************/

void DocFilterIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theChildren = 0;
  theCurItem = 0;
}

void DocFilterIteratorState::reset(PlanState& planState ) 
{
  PlanIteratorState::reset(planState);
  theChildren = 0;
  theCurItem = 0;
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

}
