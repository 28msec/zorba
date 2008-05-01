/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "util/Assert.h"
#include "errors/error_manager.h"
#include "system/globalenv.h"
#include "types/root_typemanager.h"
#include "types/casting.h"
#include "types/typeops.h"
#include "context/static_context.h"
#include "context/namespace_context.h"

#include "runtime/api/runtimecb.h"
#include "runtime/core/constructors.h"
#include "runtime/visitors/planitervisitor.h"
#include "runtime/api/plan_iterator_wrapper.h"
#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"


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
  // Note: baseUri has to be rchandles because if createDocumentNode throws
  // an exception, we don't know if the exception was thrown before or after
  // the ownership of the uris was transfered to the doc node.
  xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->
                             final_baseuri().getStore();
  store::Item_t node;

  store::CopyMode copymode;

  DocumentIteratorState* state;
  DEFAULT_STACK_INIT(DocumentIteratorState, state, planState);

  copymode.set(true,
               state->theTypePreserve,
               state->theNsPreserve,
               state->theNsInherit);

  node = GENV_ITEMFACTORY->
         createDocumentNode((ulong)&planState,
                            baseUri,
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
ElementIterator::ElementIterator (
    const QueryLoc&     loc,
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
  StateTraitsImpl<PlanIteratorState>::createState(planState,
                                                  this->stateOffset,
                                                  offset);

  StateTraitsImpl<PlanIteratorState>::initState(planState,
                                                this->stateOffset);

  if (theQNameIter != 0)
    theQNameIter->open(planState, offset);
  
  if ( theChildrenIter != 0 )
    theChildrenIter->open(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->open(planState, offset);

  if (theNamespacesIter != 0)
    theNamespacesIter->open(planState, offset);

  static_context* sctx = planState.theRuntimeCB->theStaticContext;

  theTypePreserve =
    (sctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


store::Item_t ElementIterator::nextImpl(PlanState& planState) const
{
  std::auto_ptr<store::Iterator> cwrapper;
  std::auto_ptr<store::Iterator> awrapper;
  store::CopyMode copymode;
  store::Item_t qnameItem;
  store::Item_t typeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  store::Item_t node;
  xqpStringStore_t baseUri;
  
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
  if (baseUri->empty())
  {
    ZORBA_ERROR_LOC(ZorbaError::XPST0001, loc);
  }

  qnameItem = consumeNext(theQNameIter, planState);

  // parsing of QNameItem does not have to be checked because 
  // the compiler wraps an xs:qname cast around the expression
  if (qnameItem->getLocalName()->empty())
  {
    ZORBA_ERROR_LOC_DESC(ZorbaError::XQDY0074, loc,
                     "Element name must not have an empty local part.");
  }

  if (theChildrenIter != 0)
    cwrapper.reset(new PlanIteratorWrapper(theChildrenIter, planState));

  if (theAttributesIter != 0)
    awrapper.reset(new PlanIteratorWrapper(theAttributesIter, planState));

  copymode.set(true, theTypePreserve, theNsPreserve, theNsInherit);

  node = GENV_ITEMFACTORY->
         createElementNode((ulong)&planState,
                           qnameItem,
                           typeName,
                           cwrapper.get(),
                           awrapper.get(),
                           NULL,
                           theLocalBindings->get_bindings(),
                           baseUri,
                           theIsRoot,
                           true, // assignIds
                           true, // copy
                           copymode);
  STACK_PUSH(node, state);
  STACK_END (state);
}


void ElementIterator::resetImpl(PlanState& planState) const
{
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->stateOffset);

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

  StateTraitsImpl<PlanIteratorState>::destroyState(planState, this->stateOffset);
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
  xqpStringStore_t content;

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
      content = item->getStringValue();
      textNode = factory->createTextNode((ulong)&planState,
                                         content,
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
  BinaryBaseIterator<AttributeIterator, PlanIteratorState>(loc, aQNameIter, aValueIter),
    theIsRoot(isRoot)
{
}


store::Item_t AttributeIterator::nextImpl(PlanState& planState) const
{
  store::Item_t node;
  store::Iterator_t nameWrapper;
  store::Iterator_t valueWrapper;
  store::Item_t typeName = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  nameWrapper = new PlanIteratorWrapper(theChild0, planState);
  valueWrapper = new PlanIteratorWrapper(theChild1, planState);
  
  node = GENV_ITEMFACTORY->
         createAttributeNode((ulong)&planState,
                             nameWrapper,
                             typeName,
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
  xqtref_t lItemType;
  xqpStringStore_t strval;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lItem = consumeNext(theChild.getp(), planState);
  if (lItem == 0)
  {
    ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
                          "Empty sequences cannot be cased to QName.");
  }

  if (consumeNext(theChild, planState) != 0)
  {
    ZORBA_ERROR_LOC_DESC( ZorbaError::XPTY0004, loc, 
                          "Non single sequences cannot be cased to QName.");
  }

  lItemType = planState.theCompilerCB->m_sctx->get_typemanager()->
              create_value_type(lItem);

  if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
  {
    lRes.transfer(lItem);
  }
  else if (!TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.STRING_TYPE_ONE) &&
           !TypeOps::is_equal(*lItemType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    ZORBA_ERROR_LOC_DESC(ZorbaError::XPTY0004, loc, 
                         "Item cannot be casted to QName.");
  }
  else
  {
    try
    {
      strval = lItem->getStringValue();
      lRes = GenericCast::instance()->castToQName(strval, &*theNCtx);
    }
    catch (...)
    {
      // the returned error codes are wrong for name casting => they must be changed
      ZORBA_ERROR_LOC_DESC( ZorbaError::XQDY0074, loc, 
                            "Item cannot be casted to QName.");
    }
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
  store::Iterator_t valueWrapper;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  valueWrapper = new PlanIteratorWrapper(theChild, planState);
      
  node = GENV_ITEMFACTORY->createTextNode((ulong)&planState,
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
  std::string buf;
  xqpStringStore_t content;
  xqpStringStore_t target;
  bool lFirst;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  try {
    lItem = consumeNext(theChild0, planState);
  } catch (error::ZorbaError& e) {
    if (e.theErrorCode == ZorbaError::FORG0001)
      ZORBA_ERROR_LOC(ZorbaError::XQDY0041, loc);
    else
      throw e;
  }
  if (lItem == 0)
    ZORBA_ERROR( ZorbaError::XPTY0004);

  if (consumeNext(theChild0, planState) != 0)
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
    if (! lFirst) buf += " ";

    xqpStringStore_t strvalue = lItem->getStringValue();
    if (strvalue->indexOf("?>") >= 0)
    {
      ZORBA_ERROR( ZorbaError::XQDY0026);
    }
    buf += strvalue->str();
  }

  content = new xqpStringStore(buf); 
  content = content->trimL(" \n\r\t", 4);

  lItem = GENV_ITEMFACTORY->createPiNode((ulong)&planState,
                                         target,
                                         content,
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
  std::string buf;
  xqpStringStore_t content;
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
      buf += " ";

    buf += lItem->getStringValue()->str();
    lFirst = false;
  }

  content = new xqpStringStore(buf);

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
  theAttrValueString = NULL;
  theElemContentString = NULL;
  theDocChildren = NULL;
}


void EnclosedIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if (theAttrValueString) 
  {
    delete theAttrValueString; 
    theAttrValueString = NULL;
  }

  theElemContentString = NULL;
  theContextItem = NULL;

  if (theDocChildren != NULL)
  {
    theDocChildren->close();
    theDocChildren = 0;
  }
}


EnclosedIteratorState::~EnclosedIteratorState()
{
  if (theAttrValueString)
    delete theAttrValueString;

  if (theDocChildren != NULL)
  {
    theDocChildren->close();
    theDocChildren = 0;
  }
}


EnclosedIterator::EnclosedIterator (
    const QueryLoc& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState> ( loc, childIter ),
  theAttrContent(false)
{
}


bool EnclosedIterator::getAttrContent() const
{
  return theAttrContent;
}

void EnclosedIterator::setAttrContent()
{
  theAttrContent = true;
}


store::Item_t EnclosedIterator::nextImpl(PlanState& planState) const
{
  store::Item_t item;
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  xqpStringStore_t strval;

  EnclosedIteratorState* state;
  DEFAULT_STACK_INIT(EnclosedIteratorState, state, planState);

  if (theAttrContent)
  {
    while ( true )
    {
      state->theContextItem = consumeNext(theChild, planState);

      if (state->theContextItem == NULL)
        return NULL;

      if (state->theContextItem->isNode())
      {
        STACK_PUSH(state->theContextItem, state);
      }
      else
      {
        strval = state->theContextItem->getStringValue();

        {
          std::string buf;
          state->theContextItem = consumeNext(theChild, planState);
          while (state->theContextItem != NULL &&
                 state->theContextItem->isAtomic())
          {
            buf += " ";
            buf += state->theContextItem->getStringValue()->str();

            state->theContextItem = consumeNext(theChild, planState);
          }

          if (!buf.empty())
            strval = strval->append(buf);
        }

        item = factory->createString(strval);
        STACK_PUSH(item, state);

        STACK_PUSH(state->theContextItem, state);
      }
    }
  }
  else
  {
    while ( true )
    {
      if (state->theDocChildren != 0)
      {
        state->theContextItem = state->theDocChildren->next();
        if (state->theContextItem == 0)
        {
          state->theDocChildren->close();
          state->theDocChildren = 0;
        }
        else
        {
          STACK_PUSH(state->theContextItem, state);
        }
      }
      else
      {
        state->theContextItem = consumeNext(theChild, planState);

        if (state->theContextItem == NULL)
          break;

        if (state->theContextItem->isNode())
        {
          if (state->theContextItem->getNodeKind() == store::StoreConsts::documentNode)
          {
            state->theDocChildren = state->theContextItem->getChildren();
            state->theDocChildren->open();
          }
          else
          {
            STACK_PUSH(state->theContextItem, state);
          }
        }
        else
        {
          strval = state->theContextItem->getStringValue();

          {
            std::string buf;
            state->theContextItem = consumeNext(theChild, planState);
            while (state->theContextItem != NULL &&
                   state->theContextItem->isAtomic())
            {
              buf += " ";
              buf += state->theContextItem->getStringValue()->str();

              state->theContextItem = consumeNext(theChild, planState);
            }

            if (!buf.empty())
              strval = strval->append(buf);
          }

          if (!strval->empty())
          {
            item = factory->createTextNode((ulong)&planState,
                                           strval,
                                           false,
                                           true);  // assingIds
            STACK_PUSH(item, state);
          }

          STACK_PUSH(state->theContextItem, state);
        }
      }
    }
  }

  STACK_END (state);
}


}
