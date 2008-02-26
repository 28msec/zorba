#include <memory>
#include <sys/types.h>
#include <zorba/item.h>

#include "runtime/core/constructors.h"
#include "util/Assert.h"
#include "system/zorba.h"
#include "errors/error_factory.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "context/static_context.h"
#include "context/namespace_context.h"
#include "store/api/temp_seq.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/base/plan_iterator_wrapper.h"
#include "store/api/item_factory.h"


using namespace std;
namespace xqp
{


/*******************************************************************************

********************************************************************************/
void
DocumentIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<DocumentIteratorState>::createState(planState, this->stateOffset, offset);
  StateTraitsImpl<DocumentIteratorState>::initState(planState, this->stateOffset);
  
  DocumentIteratorState* lState = StateTraitsImpl<DocumentIteratorState>::getState(planState, this->stateOffset);
  lState->childWrapper = new PlanIteratorWrapper(theChild, planState); 

  theChild->open(planState, offset);
}

Item_t DocumentIterator::nextImpl(PlanState& planState) const
{
  // Note: baseUri and docUri have to be rchandles because if createDocumentNode
  // throws and exception, we don't know if the exception was thrown before or
  // after the ownership of the uris was transfered to the doc node.
  xqpStringStore_t baseUri = 0;
  xqpStringStore_t docUri = 0;
  Item_t node;

  DocumentIteratorState* state;
  DEFAULT_STACK_INIT(DocumentIteratorState, state, planState);

  // maybe we can make these members of the class in order to save new's when calling 
  // close or reset
  baseUri = new xqpStringStore("");
  docUri = new xqpStringStore("");

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
Item_t DocumentContentIterator::nextImpl(PlanState& planState) const
{
  Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (true)
  {
    lItem = consumeNext(theChild.getp(), planState);
    if (lItem == 0)
      break;

    if (lItem->isNode() && lItem->getNodeKind() == StoreConsts::attributeNode)
    {
        ZORBA_ERROR_ALERT(ZorbaError::XPTY0004, &loc, DONT_CONTINUE_EXECUTION,
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
    const QueryLoc& loc,
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


Item_t ElementIterator::nextImpl(PlanState& planState) const
{
  std::auto_ptr<Iterator> cwrapper;
  std::auto_ptr<Iterator> awrapper;

  Item_t qnameItem;
  Item_t node;

  ElementIteratorState* state;
  DEFAULT_STACK_INIT(ElementIteratorState, state, planState);

  qnameItem = consumeNext(theQNameIter.getp(), planState);

  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  if (qnameItem->getLocalName().size() == 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0074, NULL, DONT_CONTINUE_EXECUTION,
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
  StateTraitsImpl<ElementIteratorState>::initState(planState, this->stateOffset);

  if (theQNameIter != 0)
    theQNameIter->open(planState, offset);
  
  if ( theChildrenIter != 0 )
    theChildrenIter->open(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->open(planState, offset);

  if (theNamespacesIter != 0)
    theNamespacesIter->open(planState, offset);
  
}

void ElementIterator::resetImpl(PlanState& planState) const
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
Item_t ElementContentIterator::nextImpl(PlanState& planState) const
{
  ItemFactory* factory = Zorba::getItemFactory();
  Item_t item;
  Item_t textNode;

  ElementContentState* state;
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    item = consumeNext(theChildren[0].getp(), planState );
    if (item == NULL)
      break;

    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child.
    if (item->isNode() && item->getNodeKind() == StoreConsts::attributeNode) 
    {
      if (state->theNoAttrAllowed)
        ZORBA_ERROR_ALERT(ZorbaError::XQTY0024, &loc, DONT_CONTINUE_EXECUTION);
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
      textNode = factory->createTextNode((unsigned long)&planState,
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
    const QueryLoc& loc,
    PlanIter_t&  aQNameIter,
    PlanIter_t&  aValueIter,
    bool         isRoot)
  :
    BinaryBaseIterator<AttributeIterator, PlanIteratorState>( loc, aQNameIter, aValueIter ),
    theIsRoot(isRoot)
{
}


Item_t AttributeIterator::nextImpl(PlanState& planState) const
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
    const QueryLoc& loc,
    PlanIter_t& aChild,
    bool isRoot) 
  :
  UnaryBaseIterator<TextIterator, PlanIteratorState>(loc, aChild),
  theIsRoot(isRoot)
{
}


Item_t TextIterator::nextImpl(PlanState& planState) const
{
  Item_t node;
  Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valueWrapper = new PlanIteratorWrapper(theChild, planState);
      
  node = Zorba::getItemFactory()->createTextNode((unsigned long)&planState,
                                                 valueWrapper,
                                                 theIsRoot);

  STACK_PUSH(node, state);
    
  STACK_END();
}


/*******************************************************************************

********************************************************************************/
PiIterator::PiIterator (
    const QueryLoc& loc,
    PlanIter_t& aTarget,
    PlanIter_t& aContent,
    bool isRoot)
  :
  BinaryBaseIterator<PiIterator, PlanIteratorState>(loc, aTarget, aContent),
  theIsRoot(isRoot)
{
}


Item_t PiIterator::nextImpl(PlanState& planState) const
{
  Item_t lItem;
  xqp_string target, content;
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lItem = consumeNext(theChild0.getp(), planState);
  if (lItem == 0)
    ZORBA_ERROR_ALERT (ZorbaError::XPTY0004);

  if (consumeNext(theChild0.getp(), planState) != 0)
    ZORBA_ERROR_ALERT (ZorbaError::XPTY0004);

  // TODO: check if lItem is string, raise XPTY0004 if not
  target = lItem->getStringValue();
  if (target.empty ())
    ZORBA_ERROR_ALERT (ZorbaError::XQDY0041);
  else if (target.substr (0).uppercase () == "XML") 
    ZORBA_ERROR_ALERT (ZorbaError::XQDY0064);
  
  for (lFirst = true; 0 != (lItem = consumeNext (theChild1.getp(), planState)); lFirst = false)
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

  lItem = Zorba::getItemFactory()->createPiNode((unsigned long)&planState,
                                                target.getStore(),
                                                content.getStore (),
                                                theIsRoot);
  STACK_PUSH(lItem, state);
  
  STACK_END();
}


/********************************************************************************

********************************************************************************/
CommentIterator::CommentIterator(
    const QueryLoc& loc,
    PlanIter_t& aComment,
    bool isRoot)
  : UnaryBaseIterator<CommentIterator, PlanIteratorState>(loc, aComment),
  theIsRoot(isRoot)
{
}


Item_t CommentIterator::nextImpl(PlanState& planState) const
{
  Item_t lItem;
  xqp_string content = "";
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lFirst = true;
  while (true)
  {
    lItem = consumeNext(theChild.getp(), planState);
    if (lItem == 0)
      break;
    
    if (!lFirst)
      content += " ";
    content += lItem->getStringValue();
    lFirst = false;
  }

  
  if (content != "")
  {
    if (content.indexOf("-") == (long)(content.size()-1))
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQDY0072);
    }

    if (content.indexOf("--") >= 0)
    {
      ZORBA_ERROR_ALERT(ZorbaError::XQDY0072);
    }
  }

  lItem = Zorba::getItemFactory()->createCommentNode((unsigned long)&planState,
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
    const QueryLoc& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState> ( loc, childIter ),
  theAttrContent(false)
{
}


Item_t EnclosedIterator::nextImpl(PlanState& planState) const
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
      state->theContextItem = consumeNext(theChild.getp(), planState);

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
      state->theContextItem = consumeNext(theChild.getp(), planState);

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

        state->theContextItem = factory->createTextNode((unsigned long)&planState,
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
DocFilterIteratorState::DocFilterIteratorState(){}

DocFilterIteratorState::~DocFilterIteratorState()
{
  if (theChildren != NULL) {
    theChildren->close();
  }
}

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

Item_t DocFilterIterator::nextImpl(PlanState& planState) const
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
      lItem = consumeNext(theChild.getp(), planState);
      if (lItem == 0)
        break;
      if (lItem->isNode() && lItem->getNodeKind() == StoreConsts::documentNode)
      {
        state->theChildren = lItem->getChildren();
        state->theChildren->open();
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
