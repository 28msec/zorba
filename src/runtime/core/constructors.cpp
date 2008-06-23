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

#include "zorbautils/fatal.h"
#include "zorbaerrors/Assert.h"
#include "zorbaerrors/error_manager.h"
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
void DocumentIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<DocumentIterator, PlanIteratorState>::openImpl(planState, offset);

  static_context* sctx = planState.theRuntimeCB->theStaticContext;

  theTypePreserve =
    (sctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (sctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit = 
    (sctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


bool DocumentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  // Note: baseUri has to be rchandle because if createDocumentNode throws
  // an exception, we don't know if the exception was thrown before or after
  // the ownership of the uri was transfered to the doc node.
  xqpStringStore_t baseUri = planState.theRuntimeCB->theStaticContext->
                             final_baseuri().getStore();
  xqpStringStore_t docUri;

  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;
  store::CopyMode copymode;
  store::Item_t child;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  GENV_ITEMFACTORY->createDocumentNode(result, baseUri, docUri);

  path.push(result);

  // Compute the children of the element node
  copymode.set(true, theTypePreserve, theNsPreserve, theNsInherit);

  try
  {
    while (consumeNext(child, theChild, planState))
    {
      ZORBA_FATAL(child->isNode(), "");
      ZORBA_FATAL(child->getNodeKind() != store::StoreConsts::attributeNode, "");

      if (child->getParent() != result.getp())
      {
        // Skip text node with zero-length value
        if (child->getNodeKind() == store::StoreConsts::textNode && 
            child->getStringValueP()->empty())
        {
          continue;
        }

        child->copy(result, -1, copymode);
      }
    }

    result->finalizeNode();
  }
  catch (...)
  {
    path.pop();
    result = NULL;
    throw;
  }

  path.pop();

  STACK_PUSH(true, state);
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
bool DocumentContentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  while (true)
  {
    if (!consumeNext(result, theChild.getp(), planState))
      break;

    if (result->isNode() &&
        result->getNodeKind() == store::StoreConsts::attributeNode)
    {
      ZORBA_ERROR_LOC_DESC(XPTY0004, loc,
                           "A Document Node must not contain attribute nodes!");
    }

    STACK_PUSH(true, state);
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


bool ElementIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item* parent;
  store::Item_t nodeName;
  store::Item_t typeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  xqpStringStore_t baseUri;

  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;
  store::Item_t attr;
  store::Item_t child;
  store::CopyMode copymode;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the node name. Note: the compiler wraps an xs:qname cast around
  // the name expression, so we know that consumeNext() returns exactly one,
  // well formed qname. 
  consumeNext(nodeName, theQNameIter, planState);

  if (nodeName->getLocalName()->empty())
  {
    ZORBA_ERROR_LOC_DESC(XQDY0074, loc,
                     "Element name must not have an empty local part.");
  }

  // Get the parent, if any, of the new element node 
  ZORBA_FATAL(theIsRoot || !path.empty(), "");
  parent = (theIsRoot ? NULL : path.top());

  if (theIsRoot)
  {
    // Conservatively, assign the base uri from the static ctx as the base uri
    // of the new node. If theAttributesIter does not later produce any explicit
    // base-uri attribute, then the base-uri used here is the correct one, and
    // it MUST be assigned here, because it is needed for resolving any relative
    // uris that may appear in the children. If theAttributesIter does produce
    // an explicit base-uri attribute, then the base-uri added here will be
    // replaced with the explicit one.
    baseUri = planState.theRuntimeCB->theStaticContext->final_baseuri().getStore();
    if (baseUri->empty())
      ZORBA_ERROR_LOC(XPST0001, loc);
  }

  // Create the element node and push it to the construction path.
  GENV_ITEMFACTORY->createElementNode(result,
                                      parent,
                                      -1,
                                      nodeName,
                                      typeName,
                                      theLocalBindings->get_bindings(),
                                      baseUri);
  path.push(result);

  // Compute the attributes and children of the element node
  copymode.set(true, theTypePreserve, theNsPreserve, theNsInherit);

  try
  {
    if (theAttributesIter != 0)
    {
      while (consumeNext(attr, theAttributesIter, planState))
      {
        assert(attr->isNode());
        assert(attr->getNodeKind() == store::StoreConsts::attributeNode);

        if (attr->getParent() != result.getp())
          attr->copy(result, -1, copymode);
      }
    }

    if (theChildrenIter != 0)
    {
      bool valid = false;

      while (valid = consumeNext(child, theChildrenIter, planState))
      {
        assert(child->isNode());
        assert(child->getNodeKind() != store::StoreConsts::documentNode);

        if (child->getNodeKind() != store::StoreConsts::attributeNode)
          break;

        if (child->getParent() != result.getp())
          child->copy(result, -1, copymode);
      }

      while (valid)
      {
        assert(child->isNode());
        assert(child->getNodeKind() != store::StoreConsts::documentNode);
        assert(child->getNodeKind() != store::StoreConsts::attributeNode);

        // Skip text node with zero-length value
        if (child->getNodeKind() == store::StoreConsts::textNode && 
            child->getStringValueP()->empty())
        {
          ;
        }
        // Else copy the child node if it was not a node constructed by a 
        // directly nested constructor
        else if (child->getParent() != result.getp())
          child->copy(result, -1, copymode);

        valid = consumeNext(child, theChildrenIter, planState);
      }
    }

    result->finalizeNode();
  }
  catch (...)
  {
    result = NULL;
    path.pop();
    throw;
  }

  path.pop();

  STACK_PUSH(true, state);
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


bool ElementContentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  store::Item_t textNode;
  xqpStringStore_t content;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  ElementContentState* state;
  bool valid;
  DEFAULT_STACK_INIT(ElementContentState, state, planState);
  
  while (true)
  {
    if (!consumeNext(result, theChildren[0], planState ))
      break;

    valid = true;

    // Check to find out if the content contains an attribute child which is
    // located after a non attribute child.
    if (result->isNode() &&
        result->getNodeKind() == store::StoreConsts::attributeNode) 
    {
      if (state->theNoAttrAllowed)
        ZORBA_ERROR_LOC(XQTY0024, loc); 
    }
    else
    {
      state->theNoAttrAllowed = true;
    }
    
    if (!result->isNode())
    {
      content = result->getStringValue();
      valid = factory->createTextNode(result, path.top(), -1, content);
    }
    STACK_PUSH(valid, state);
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


bool AttributeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t name;
  store::Item_t typeName = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  store::Item_t valueItem;
  xqpStringStore_t lexicalValue;
  store::Item_t typedValue;
  store::Item* parent;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the attribute name. Note: we don't have to check that itemQName
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around the name expression.
  consumeNext(name, theChild0, planState);

  if (name->getLocalName()->empty())
  {
    ZORBA_ERROR_LOC_DESC(XQDY0074, loc,
                     "Attribute name must not have an empty local part.");
  }

  if (name->getNamespace()->byteEqual("http://www.w3.org/2000/xmlns/", 29) ||
      (name->getNamespace()->empty() &&
       name->getLocalName()->byteEqual("xmlns", 5)))
  {
    ZORBA_ERROR_LOC(XQDY0044, loc);
  }

  // Compute lexical value of the attribute.
  if (consumeNext(valueItem, theChild1, planState))
  {
    lexicalValue = valueItem->getStringValue();

    std::string buf;
    while (consumeNext(valueItem, theChild1, planState))
    {
      buf += valueItem->getStringValue()->str();
    }
    if (!buf.empty())
      lexicalValue = lexicalValue->append(buf);
  }
  else
  {
    lexicalValue = new xqpStringStore("");
  }
  
  GENV_ITEMFACTORY->createUntypedAtomic(typedValue, lexicalValue);

  // Create the attribute node
  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createAttributeNode(result, parent, -1,
                                        name,
                                        typeName,
                                        typedValue);

  STACK_PUSH(true, state);
  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
TextIterator::TextIterator(
    const QueryLoc& loc,
    PlanIter_t&     aChild,
    bool            isRoot) 
  :
  UnaryBaseIterator<TextIterator, PlanIteratorState>(loc, aChild),
  theIsRoot(isRoot)
{
}


bool TextIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqpStringStore_t content;
  store::Item_t valueItem;
  std::string buf;

  store::Item* parent;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the text content. If the value is the empty sequence, no text
  // node should be constructed.
  if (consumeNext(valueItem, theChild, planState))
  {
    content = (valueItem->isAtomic() ?
               valueItem->getStringValue() :
               valueItem->getAtomizationValue()->getStringValue());

    while (consumeNext(valueItem, theChild, planState))
    {
      buf += " ";
      buf += (valueItem->isAtomic() ?
              valueItem->getStringValue()->c_str() :
              valueItem->getAtomizationValue()->getStringValue()->str());
    }
    if (!buf.empty())
      content = content->append(buf);

    ZORBA_FATAL(theIsRoot || !path.empty(), "");

    parent = (theIsRoot ? NULL : path.top());

    STACK_PUSH(GENV_ITEMFACTORY->createTextNode(result, parent, -1, content),
               state);
  }
  else
  {
    result = NULL;
    STACK_PUSH(false, state);
  }

  STACK_END (state);
}


/*******************************************************************************

********************************************************************************/
PiIterator::PiIterator (
    const QueryLoc& loc,
    PlanIter_t&     aTarget,
    PlanIter_t&     aContent,
    bool            isRoot)
  :
  BinaryBaseIterator<PiIterator, PlanIteratorState>(loc, aTarget, aContent),
  theIsRoot(isRoot)
{
}


bool PiIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  store::Item_t temp;
  xqpStringStore_t content;
  xqpStringStore_t target;
  xqpStringStore_t baseUri;
  std::string buf;
  bool lFirst;

  store::Item* parent;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the target of the pi node.
  try 
  {
    if (!consumeNext(lItem, theChild0, planState))
      ZORBA_ERROR_LOC(XPTY0004, loc);
  }
  catch (error::ZorbaError& e) 
  {
    if (e.theErrorCode == FORG0001)
      ZORBA_ERROR_LOC(XQDY0041, loc);
    else
      throw e;
  }

  if (consumeNext(temp, theChild0, planState))
    ZORBA_ERROR_LOC(XPTY0004, loc);

  // TODO: check if lItem is string, raise XPTY0004 if not
  target = lItem->getStringValue();

  if (target->empty())
    ZORBA_ERROR_LOC(XQDY0041, loc);
  else if (target->uppercase()->byteEqual("XML", 3)) 
    ZORBA_ERROR_LOC(XQDY0064, loc);

  // Compute the content of the pi node  
  for (lFirst = true;
       consumeNext (lItem, theChild1.getp(), planState);
       lFirst = false)
  {
    if (! lFirst) buf += " ";

    xqpStringStore_t strvalue = lItem->getStringValue();
    if (strvalue->indexOf("?>") >= 0)
      ZORBA_ERROR_LOC(XQDY0026, loc);

    buf += strvalue->str();
  }

  content = new xqpStringStore(buf); 
  content = content->trimL(" \n\r\t", 4);

  // Create the pi node
  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createPiNode(result, parent, -1, target, content, baseUri);
  STACK_PUSH(true, state);
  
  STACK_END (state);
}


/********************************************************************************

********************************************************************************/
CommentIterator::CommentIterator(
    const QueryLoc& loc,
    PlanIter_t&     aComment,
    bool            isRoot)
  :
  UnaryBaseIterator<CommentIterator, PlanIteratorState>(loc, aComment),
  theIsRoot(isRoot)
{
}


bool CommentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  std::string buf;
  xqpStringStore_t content;
  bool lFirst;
  store::Item* parent;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
      
  lFirst = true;
  while (true)
  {
    if (!consumeNext(lItem, theChild.getp(), planState))
      break;
    
    if (!lFirst)
      buf += " ";

    buf += lItem->getStringValue()->str();
    lFirst = false;
  }

  content = new xqpStringStore(buf);

  if (!content->empty())
  {
    if (content->byteAt(content->bytes()-1) == '-' || content->indexOf("--") >= 0)
      ZORBA_ERROR_LOC(XQDY0072, loc);
  }

  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createCommentNode(result, parent, -1, content);
  STACK_PUSH(true, state);
    
  STACK_END(state);
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


bool EnclosedIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  xqpStringStore_t strval;
  std::stack<store::Item*>& path = planState.theRuntimeCB->theNodeConstuctionPath;

  EnclosedIteratorState* state;
  DEFAULT_STACK_INIT(EnclosedIteratorState, state, planState);

  if (theAttrContent)
  {
    while ( true )
    {
      if (!consumeNext(result, theChild, planState))
        break;

      if (result->isNode())
      {
        STACK_PUSH(true, state);
      }
      else
      {
        strval = result->getStringValue();

        {
          std::string buf;
          while(true) 
          {
            bool status = consumeNext(state->theContextItem, theChild, planState);
            if (!status) 
            {
              state->theContextItem = NULL;
              break;
            }
            if (!state->theContextItem->isAtomic())
              break;

            buf += " ";
            buf += state->theContextItem->getStringValue()->str();
          }

          if (!buf.empty())
            strval = strval->append(buf);
        }

        factory->createString(result, strval);
        STACK_PUSH(true, state);

        result.transfer(state->theContextItem);
        STACK_PUSH(result != NULL, state);
      }
    }
  }
  else
  {
    while ( true )
    {
      if (state->theDocChildren != 0)
      {
        if (!state->theDocChildren->next(result))
        {
          state->theDocChildren->close();
          state->theDocChildren = 0;
        }
        else
        {
          STACK_PUSH(true, state);
        }
      }
      else
      {
        if (!consumeNext(result, theChild, planState))
          break;

        if (result->isNode())
        {
          if (result->getNodeKind() == store::StoreConsts::documentNode)
          {
            state->theDocChildren = result->getChildren();
            state->theDocChildren->open();
          }
          else
          {
            STACK_PUSH(true, state);
          }
        }
        else
        {
          strval = result->getStringValue();

          {
            std::string buf;
            while(true) 
            {
              bool status = consumeNext(state->theContextItem, theChild, planState);
              if (!status) 
              {
                state->theContextItem = NULL;
                break;
              }
              if (!state->theContextItem->isAtomic())
                break;

              buf += " ";
              buf += state->theContextItem->getStringValue()->str();
            }

            if (!buf.empty())
              strval = strval->append(buf);
          }

          if (!strval->empty())
          {
            STACK_PUSH(factory->createTextNode(result,
                                               (path.empty() ? NULL : path.top()),
                                               -1,
                                               strval),
                       state);
          }

          if (state->theContextItem != NULL &&
              state->theContextItem->getNodeKind() == store::StoreConsts::documentNode)
          {
            state->theDocChildren = state->theContextItem->getChildren();
            state->theDocChildren->open();
          }
          else
          {
            result.transfer(state->theContextItem);
            STACK_PUSH(result != NULL, state);
          }
        }
      }
    }
  }

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


bool NameCastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqtref_t lItemType;
  xqpStringStore_t strval;
  store::Item_t temp;
  bool valid = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChild.getp(), planState))
  {
    ZORBA_ERROR_LOC_DESC(XPTY0004, loc, 
                         "Empty sequences cannot be cased to QName.");
  }
  valid = true;

  if (consumeNext(temp, theChild, planState))
  {
    ZORBA_ERROR_LOC_DESC(XPTY0004, loc, 
                         "Non single sequences cannot be cased to QName.");
  }

  lItemType = planState.theCompilerCB->m_sctx->get_typemanager()->
              create_value_type(result);

  if (TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.QNAME_TYPE_ONE))
  {
    /* do nothing */
  }
  else if (!TypeOps::is_subtype(*lItemType, *GENV_TYPESYSTEM.STRING_TYPE_ONE) &&
           !TypeOps::is_equal(*lItemType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE))
  {
    ZORBA_ERROR_LOC_DESC(XPTY0004, loc, 
                         "Item cannot be casted to QName.");
  }
  else
  {
    try
    {
      strval = result->getStringValue();
      valid = GenericCast::instance()->castToQName(result, strval, &*theNCtx);
    }
    catch (...)
    {
      // the returned error codes are wrong for name casting => they must be changed
      ZORBA_ERROR_LOC_DESC(XQDY0074, loc, 
                           "Item cannot be casted to QName.");
    }
  }

  STACK_PUSH(valid, state);
  STACK_END(state);
}

}
