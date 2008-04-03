

#include "runtime/api/runtimecb.h"
#include "runtime/core/constructors.h"
#include "util/Assert.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "context/static_context.h"
#include "context/namespace_context.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"
#include "types/casting.h"
#include "context/namespace_context.h"
#include "types/typeops.h"


using namespace std;

namespace zorba
{


/*******************************************************************************

********************************************************************************/
void
DocumentIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
}


DocumentIteratorState::~DocumentIteratorState()
{
  delete childWrapper; childWrapper = 0;
}


void DocumentIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<DocumentIteratorState>::createState(planState,
                                                      this->stateOffset,
                                                      offset);

  StateTraitsImpl<DocumentIteratorState>::initState(planState, this->stateOffset);
  
  DocumentIteratorState* lState = StateTraitsImpl<DocumentIteratorState>::
                                  getState(planState, this->stateOffset);

  lState->childWrapper = new PlanIteratorWrapper(theChild, planState); 

  theChild->open(planState, offset);
}


store::Item_t DocumentIterator::nextImpl(PlanState& planState) const
{
  // Note: baseUri and docUri have to be rchandles because if createDocumentNode
  // throws and exception, we don't know if the exception was thrown before or
  // after the ownership of the uris was transfered to the doc node.
  xqpStringStore_t baseUri = 0;
  xqpStringStore_t docUri = 0;
  store::Item_t node;

  store::CopyMode copymode;

  DocumentIteratorState* state;
  DEFAULT_STACK_INIT(DocumentIteratorState, state, planState);

  copymode.set(true,
               state->theTypePreserve,
               state->theNsPreserve,
               state->theNsInherit);

  // maybe we can make these members of the class in order to save new's when calling 
  // close or reset
  baseUri = new xqpStringStore("");
  docUri = new xqpStringStore("");

  node = GENV_ITEMFACTORY->
         createDocumentNode((ulong)&planState,
                            baseUri,
                            docUri,
                            state->childWrapper,
                            true, // is root
                            true, // assign ids
                            true, // copy children
                            copymode);
  STACK_PUSH(node, state);
  STACK_END (state);
}


void
DocumentIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);

  static_context* sctx = planState.theRuntimeCB->theStaticContext;

  theTypePreserve =
    (sctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


/*******************************************************************************

********************************************************************************/
store::Item_t DocumentContentIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (true)
  {
    lItem = consumeNext(theChild.getp(), planState);
    if (lItem == 0)
      break;

    if (lItem->isNode() && lItem->getNodeKind() == store::StoreConsts::attributeNode)
    {
        ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, "A Document Node must not contain attribute nodes!");
    }

    STACK_PUSH(lItem, state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
void
ElementIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  static_context* sctx = planState.theRuntimeCB->theStaticContext;

  theTypePreserve =
    (sctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
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
    namespace_context*  localBindings,
    bool                isRoot)
  :
  Batcher<ElementIterator>(loc),
  theQNameIter(qnameIter),
  theAttributesIter(attrsIter),
  theChildrenIter(childrenIter),
  theLocalBindings(localBindings),
  theIsRoot(isRoot)
{
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


store::Item_t ElementIterator::nextImpl(PlanState& planState) const
{
  std::auto_ptr<Iterator> cwrapper;
  std::auto_ptr<Iterator> awrapper;

  store::Item_t qnameItem;
  store::Item_t node;

  store::CopyMode copymode;
  
  ElementIteratorState* state;
  DEFAULT_STACK_INIT(ElementIteratorState, state, planState);

  qnameItem = consumeNext(theQNameIter.getp(), planState);

  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  if (qnameItem->getLocalName().size() == 0)
  {
    ZORBA_ERROR_DESC( ZorbaError::XQDY0074, "Element name must not have an empty local part.");
  }

  if (theChildrenIter != 0)
    cwrapper.reset(new PlanIteratorWrapper(theChildrenIter, planState));

  if (theAttributesIter != 0)
    awrapper.reset(new PlanIteratorWrapper(theAttributesIter, planState));

  copymode.set(true,
               state->theTypePreserve,
               state->theNsPreserve,
               state->theNsInherit);

  node = GENV_ITEMFACTORY->
         createElementNode((ulong)&planState,
                           qnameItem.getp(),
                           GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME,
                           cwrapper.get(),
                           awrapper.get(),
                           NULL,
                           theLocalBindings->get_bindings(),
                           theIsRoot,
                           true, // assignIds
                           true, // copy
                           copymode);
  STACK_PUSH(node, state);
  STACK_END (state);
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


store::Item_t ElementContentIterator::nextImpl(PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  store::Item_t item;
  store::Item_t textNode;

  ElementContentState* state;
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    item = consumeNext(theChildren[0].getp(), planState );
    if (item == NULL)
      break;

    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child.
    if (item->isNode() && item->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      if (state->theNoAttrAllowed)
        ZORBA_ERROR_LOC(ZorbaError::XQTY0024, loc); 
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
                                         item->getStringValue(),
                                         false, // not root
                                         true); // assignIds
      STACK_PUSH(textNode, state);
    }
  }

  STACK_END (state);
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


store::Item_t AttributeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t node;
  Iterator_t nameWrapper;
  Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  nameWrapper = new PlanIteratorWrapper(theChild0, planState);
  valueWrapper = new PlanIteratorWrapper(theChild1, planState);
  
  node = GENV_ITEMFACTORY->
         createAttributeNode((unsigned long)&planState,
                             nameWrapper,
                             GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME,
                             valueWrapper,
                             theIsRoot,
                             true);  // assignIds

  STACK_PUSH(node, state);
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
NameCastIterator::NameCastIterator(
    const QueryLoc& loc,
    PlanIter_t& aChild,
    NamespaceContext_t aNCtx)
  :
  UnaryBaseIterator<NameCastIterator, PlanIteratorState>(loc, aChild),
  theNCtx(aNCtx)
{
}


NameCastIterator::~NameCastIterator()
{
}


store::Item_t NameCastIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  store::Item_t lRes;
  xqpStringStore_t strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  lItem = consumeNext(theChild.getp(), planState);
  if (lItem == 0)
  {
    ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
                          "Empty sequences cannot be cased to QName.");
  }

  if (consumeNext(theChild.getp(), planState) != 0)
  {
    ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
                          "Non single sequences cannot be cased to QName.");
  }

  try
  {
    xqtref_t lItemType = planState.theCompilerCB->m_sctx->get_typemanager()->item_type (lItem);
    if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
    {
      lRes = lItem;
    }
    else
    {
      lRes = GenericCast::instance()->castToQName(lItem->getStringValue(),
                                                  true,
                                                  true,
                                                  &*theNCtx);
    }
  }
  catch (...)
  {
    // the returned error codes are wrong for name casting => they must be changed
    ZORBA_ERROR_LOC_DESC( ZorbaError::XQDY0074, loc, 
                          "Item cannot be casted to QName.");
  }

  STACK_PUSH(lRes, state);
  STACK_END(state);
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


store::Item_t TextIterator::nextImpl(PlanState& planState) const
{
  store::Item_t node;
  Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valueWrapper = new PlanIteratorWrapper(theChild, planState);
      
  node = GENV_ITEMFACTORY->createTextNode((unsigned long)&planState,
                                                 valueWrapper,
                                                 theIsRoot,
                                                 true); // assignIds

  STACK_PUSH(node, state);
    
  STACK_END (state);
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


store::Item_t PiIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  xqpString content;
  xqpStringStore_t target;
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lItem = consumeNext(theChild0.getp(), planState);
  if (lItem == 0)
    ZORBA_ERROR( ZorbaError::XPTY0004);

  if (consumeNext(theChild0.getp(), planState) != 0)
    ZORBA_ERROR( ZorbaError::XPTY0004);

  // TODO: check if lItem is string, raise XPTY0004 if not
  target = lItem->getStringValue();

  if (target->empty())
    ZORBA_ERROR( ZorbaError::XQDY0041);
  else if (target->uppercase()->byteEqual("XML", 3)) 
    ZORBA_ERROR( ZorbaError::XQDY0064);
  
  for (lFirst = true;
       0 != (lItem = consumeNext (theChild1.getp(), planState));
       lFirst = false)
  {
    if (! lFirst) content += " ";

    xqpStringStore_t strvalue = lItem->getStringValue();
    if (strvalue->indexOf("?>") >= 0)
    {
      ZORBA_ERROR( ZorbaError::XQDY0026);
    }
    content += strvalue->str();
  }

  content = content.trimL(" \n\r\t", 4);

  lItem = GENV_ITEMFACTORY->createPiNode((ulong)&planState,
                                         target,
                                         content.getStore (),
                                         theIsRoot,
                                         true);  // assingIds
  STACK_PUSH(lItem, state);
  
  STACK_END (state);
}


/********************************************************************************

********************************************************************************/
CommentIterator::CommentIterator(
    const QueryLoc& loc,
    PlanIter_t& aComment,
    bool isRoot)
  :
  UnaryBaseIterator<CommentIterator, PlanIteratorState>(loc, aComment),
  theIsRoot(isRoot)
{
}


store::Item_t CommentIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  xqpStringStore_t content = new xqpStringStore("");
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
      content->str() += " ";
    content->str() += lItem->getStringValue()->str();
    lFirst = false;
  }

  if (!content->empty())
  {
    if (content->indexOf("-") == (long)(content->bytes()-1))
    {
      ZORBA_ERROR( ZorbaError::XQDY0072);
    }

    if (content->indexOf("--") >= 0)
    {
      ZORBA_ERROR( ZorbaError::XQDY0072);
    }
  }

  lItem = GENV_ITEMFACTORY->createCommentNode((ulong)&planState,
                                              content,
                                              theIsRoot,
                                              true); // assingIds
    
  STACK_PUSH(lItem, state);
    
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
void EnclosedIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theAttrContentString = NULL;
  theElemContentString = NULL;
}


void EnclosedIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theAttrContentString) 
  {
    delete theAttrContentString; 
    theAttrContentString = NULL;
  }
  theElemContentString = NULL;
  theContextItem = NULL;
}


EnclosedIteratorState::~EnclosedIteratorState()
{
  if (theAttrContentString)
    delete theAttrContentString;
}


EnclosedIterator::EnclosedIterator (
    const QueryLoc& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState> ( loc, childIter ),
  theAttrContent(false)
{
}


store::Item_t EnclosedIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  xqpStringStore_t strval;

  EnclosedIteratorState* state;
  DEFAULT_STACK_INIT(EnclosedIteratorState, state, planState);

  if (theAttrContent)
  {
    while ( true )
    {
      state->theContextItem = consumeNext(theChild.getp(), planState);

      if (state->theContextItem == NULL)
      {
        if (state->theAttrContentString != NULL)
        {
          lItem = factory->createString(state->theAttrContentString);
          state->theAttrContentString = NULL;
          STACK_PUSH(lItem, state);
        }

        break;
      }

      else if (state->theContextItem->isNode())
      {
        if ( state->theAttrContentString != NULL)
        {
          lItem = factory->createString(state->theAttrContentString);
          state->theAttrContentString = NULL;
          STACK_PUSH(lItem, state);
        }

        STACK_PUSH(state->theContextItem, state);
      }

      else if (state->theAttrContentString == NULL)
      {
        state->theAttrContentString = new xqpStringStore(state->theContextItem->getStringValue()->c_str());
      }
      else
      {
        state->theAttrContentString->str().append(" ");
        state->theAttrContentString->str().append(state->theContextItem->getStringValue()->c_str());
      }
    }
  }
  else
  {
    while ( true )
    {
      lItem = consumeNext(theChild.getp(), planState);

      if (lItem == NULL)
        break;

      else if (lItem->isNode())
      {
        state->theElemContentString = NULL;

        STACK_PUSH(lItem, state);
      }
      else
      {
        strval = lItem->getStringValue();

        if (state->theElemContentString != NULL)
          strval = new xqpStringStore(" " + strval->str());
        else
          state->theElemContentString = strval;

        if (strval->empty())
          continue;

        lItem = factory->createTextNode((ulong)&planState,
                                        strval,
                                        false,
                                        true);  // assingIds
        STACK_PUSH(lItem, state);
      }
    }
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
DocFilterIteratorState::DocFilterIteratorState()
{
}


DocFilterIteratorState::~DocFilterIteratorState()
{
  if (theChildren != NULL)
  {
    theChildren->close();
    theChildren = 0;
  }
}


void DocFilterIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theChildren = 0;
}


void DocFilterIteratorState::reset(PlanState& planState ) 
{
  PlanIteratorState::reset(planState);
  if (theChildren != NULL)
  {
    theChildren->close();
    theChildren = 0;
  }
}


store::Item_t DocFilterIterator::nextImpl(PlanState& planState) const
{
  store::Item_t lItem;
  
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

      if (lItem->isNode() && lItem->getNodeKind() == store::StoreConsts::documentNode)
      {
        state->theChildren = lItem->getChildren();
        state->theChildren->open();
      }
      else
      {
        STACK_PUSH(lItem, state);
      }
    }
  }
  STACK_END (state);
}

}
