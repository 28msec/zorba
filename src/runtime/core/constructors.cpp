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
#include "stdafx.h"

#include "zorbautils/fatal.h"
#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"

#include "system/globalenv.h"

#include "types/root_typemanager.h"
#include "types/casting.h"
#include "types/typeops.h"

#include "context/static_context.h"
#include "context/namespace_context.h"

#include "compiler/api/compilercb.h"

#include "runtime/core/constructors.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "store/api/temp_seq.h"
#include "store/api/item_factory.h"
#include "store/api/copymode.h"

#include "util/ascii_util.h"
#include "util/string_util.h"
#include "util/utf8_util.h"

using namespace std;

namespace zorba
{

SERIALIZABLE_CLASS_VERSIONS(DocumentIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DocumentIterator)

SERIALIZABLE_CLASS_VERSIONS(ElementIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ElementIterator)

SERIALIZABLE_CLASS_VERSIONS(AttributeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(AttributeIterator)

SERIALIZABLE_CLASS_VERSIONS(NameCastIterator)
END_SERIALIZABLE_CLASS_VERSIONS(NameCastIterator)

SERIALIZABLE_CLASS_VERSIONS(CommentIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CommentIterator)

SERIALIZABLE_CLASS_VERSIONS(PiIterator)
END_SERIALIZABLE_CLASS_VERSIONS(PiIterator)

SERIALIZABLE_CLASS_VERSIONS(TextIterator)
END_SERIALIZABLE_CLASS_VERSIONS(TextIterator)

SERIALIZABLE_CLASS_VERSIONS(EnclosedIterator)
END_SERIALIZABLE_CLASS_VERSIONS(EnclosedIterator)

/*******************************************************************************

********************************************************************************/
DocumentIterator::DocumentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child,
    bool copyInputNodes)
  :
  UnaryBaseIterator<DocumentIterator, PlanIteratorState>(sctx, loc, child),
  theTypePreserve(false),
  theNsPreserve(false),
  theNsInherit(false),
  theCopyInputNodes(copyInputNodes)
{
}


void DocumentIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<DocumentIterator, PlanIteratorState>*)this);

  ar & theTypePreserve;
  ar & theNsPreserve;
  ar & theNsInherit;
  ar & theCopyInputNodes;
}


void DocumentIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<DocumentIterator, PlanIteratorState>::openImpl(planState, offset);

  theTypePreserve =
    (theSctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit =
    (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


bool DocumentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  // Note: baseUri has to be rchandle because if createDocumentNode throws
  // an exception, we don't know if the exception was thrown before or after
  // the ownership of the uri was transfered to the doc node.
  zstring baseUri = theSctx->get_base_uri();
  zstring docUri;

  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;
  store::CopyMode copymode;
  store::Item_t child;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  GENV_ITEMFACTORY->createDocumentNode(result, baseUri, docUri);

  path.push(result);

  // Compute the children of the element node
  copymode.set(theCopyInputNodes, theTypePreserve, theNsPreserve, theNsInherit);

  try
  {
    while (consumeNext(child, theChild, planState))
    {
      ZORBA_FATAL(child->isNode(), "");

      if (child->getNodeKind() == store::StoreConsts::attributeNode)
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(NoAttrNodesInDocument)));
      }

      if (child->getParent() != result.getp())
      {
        // Skip text node with zero-length value
        if (child->getNodeKind() == store::StoreConsts::textNode &&
            child->getStringValue().empty())
        {
          continue;
        }

        child->copy(result, copymode);
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


UNARY_ACCEPT(DocumentIterator);


/*******************************************************************************

********************************************************************************/
void ElementIteratorState::init(PlanState&)
{
}


void ElementIteratorState::reset(PlanState&)
{
  baseUri.clear();
}


ElementIterator::ElementIterator (
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& qnameIter,
    PlanIter_t& attrsIter,
    PlanIter_t& childrenIter,
    const namespace_context* localBindings,
    bool isRoot,
    bool copyInputNodes)
  :
  NoaryBaseIterator<ElementIterator, ElementIteratorState>(sctx, loc),
  theQNameIter(qnameIter),
  theAttributesIter(attrsIter),
  theChildrenIter(childrenIter),
  theLocalBindings(const_cast<namespace_context*>(localBindings)),
  theIsRoot(isRoot),
  theTypePreserve(false),
  theNsPreserve(false),
  theNsInherit(false),
  theCopyInputNodes(copyInputNodes)
{
}


void ElementIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (NoaryBaseIterator<ElementIterator,
                           ElementIteratorState>*)this);
  ar & theQNameIter;
  ar & theAttributesIter;
  ar & theChildrenIter;
  ar & theNamespacesIter;
  ar & theLocalBindings;
  ar & theIsRoot;
  ar & theTypePreserve;
  ar & theNsPreserve;
  ar & theNsInherit;
  ar & theCopyInputNodes;
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


void ElementIterator::accept(PlanIterVisitor& v) const
{
  v.beginVisit(*this);

  if (theQNameIter != 0)
    theQNameIter->accept(v);

  if (theAttributesIter != 0)
    theAttributesIter->accept(v);

  if (theChildrenIter != 0)
    theChildrenIter->accept(v);

  if (theNamespacesIter != 0)
    theNamespacesIter->accept(v);

  v.endVisit(*this);
}


void ElementIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  StateTraitsImpl<ElementIteratorState>::createState(planState,
                                                     theStateOffset,
                                                     offset);

  StateTraitsImpl<ElementIteratorState>::initState(planState, theStateOffset);

  if (theQNameIter != 0)
    theQNameIter->open(planState, offset);

  if ( theChildrenIter != 0 )
    theChildrenIter->open(planState, offset);

  if (theAttributesIter != 0)
    theAttributesIter->open(planState, offset);

  if (theNamespacesIter != 0)
    theNamespacesIter->open(planState, offset);

  theTypePreserve =
    (theSctx->construction_mode() == StaticContextConsts::cons_preserve ? true : false);

  theNsPreserve =
    (theSctx->preserve_mode() == StaticContextConsts::preserve_ns ? true : false);

  theNsInherit =
    (theSctx->inherit_mode() == StaticContextConsts::inherit_ns ? true : false);
}


bool ElementIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;

  store::Item* parent;
  store::Item_t nodeName;
  store::Item_t typeName;
  store::Item_t nullValue;
  zstring content;

  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;
  store::Item_t attr;
  store::Item_t child;
  store::CopyMode copymode;
  zstring baseuri;

  ElementIteratorState* state;
  DEFAULT_STACK_INIT(ElementIteratorState, state, planState);

  // Compute the node name. Note: the compiler wraps an xs:qname cast around
  // the name expression, so we know that consumeNext() returns exactly one,
  // well formed qname.
  consumeNext(nodeName, theQNameIter, planState);

  if (nodeName->getLocalName().empty())
  {
    RAISE_ERROR(err::XQDY0074, loc,  ERROR_PARAMS("", ZED(NoEmptyLocalname)));
  }

  if (nodeName->getPrefix() == "xmlns" ||
      nodeName->getNamespace() == "http://www.w3.org/2000/xmlns/" ||
      (nodeName->getPrefix() == "xml" && nodeName->getNamespace() != "http://www.w3.org/XML/1998/namespace") ||
      (nodeName->getPrefix() != "xml" && nodeName->getNamespace() == "http://www.w3.org/XML/1998/namespace"))
  {
    RAISE_ERROR(err::XQDY0096, loc, ERROR_PARAMS(nodeName->getStringValue()));
  }

  typeName = (theTypePreserve ?
              GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME :
              GENV_TYPESYSTEM.XS_UNTYPED_QNAME);

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
    state->baseUri = theSctx->get_base_uri();
    if (state->baseUri.empty())
      RAISE_ERROR(err::XPST0001, loc, ERROR_PARAMS("", ZED(BaseURI)));

    store::NsBindings bindings;
    theLocalBindings->getAllBindings(bindings);

    // Create the element node and push it to the construction path.
    GENV_ITEMFACTORY->createElementNode(result,
                                        parent,
                                        nodeName,
                                        typeName,
                                        true,
                                        false,
                                        bindings,
                                        state->baseUri);
  }
  else
  {
    // Create the element node and push it to the construction path.
    GENV_ITEMFACTORY->createElementNode(result,
                                        parent,
                                        nodeName,
                                        typeName,
                                        true,
                                        false,
                                        theLocalBindings->getLocalBindings(),
                                        state->baseUri);
  }

  path.push(result);

  // Compute the attributes and children of the element node
  copymode.set(theCopyInputNodes, theTypePreserve, theNsPreserve, theNsInherit);

  try
  {
    if (theAttributesIter != 0)
    {
      while (consumeNext(attr, theAttributesIter, planState))
      {
        assert(attr->isNode());
        assert(attr->getNodeKind() == store::StoreConsts::attributeNode);

        if (attr->getParent() != result.getp())
          attr->copy(result, copymode);
      }
    }

    if (theChildrenIter != 0)
    {
      bool valid = false;

      while ((valid = consumeNext(child, theChildrenIter, planState)))
      {
        if (!child->isNode())
        {
          child->getStringValue2(content);
          factory->createTextNode(child, result, content);
        }

        assert(child->getNodeKind() != store::StoreConsts::documentNode);

        if (child->getNodeKind() != store::StoreConsts::attributeNode)
        {
          // Remove empty text nodes, as per 3.8.3.1 Computed Element Constructors
          // http://www.w3.org/TR/xquery-30/#id-computedElements
          if (child->getNodeKind() == store::StoreConsts::textNode &&
              child->getStringValue().empty())
            continue;
          else
            break;
        }

        if (child->getParent() != result.getp())
          child->copy(result, copymode);
      }

      while (valid)
      {
        if (!child->isNode())
        {
          child->getStringValue2(content);
          factory->createTextNode(child, result, content);
        }

        assert(child->getNodeKind() != store::StoreConsts::documentNode);

        if (child->getNodeKind() == store::StoreConsts::attributeNode)
          throw XQUERY_EXCEPTION(err::XQTY0024, ERROR_LOC(loc));

        // Skip text node with zero-length value
        if (child->getNodeKind() == store::StoreConsts::textNode &&
            child->getStringValue().empty())
        {
          ;
        }
        // Else copy the child node if it was not a node constructed by a
        // directly nested constructor
        else if (child->getParent() != result.getp())
        {
          child->copy(result, copymode);
        }

        valid = consumeNext(child, theChildrenIter, planState);
      }
    }

    result->finalizeNode();
  }
  catch (XQueryException& e)
  {
    result = NULL;
    path.pop();
    set_source( e, loc, false );
    throw;
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
  StateTraitsImpl<PlanIteratorState>::reset(planState, this->theStateOffset);

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

  if (theAttributesIter != 0)    theAttributesIter->close(planState);

  if (theNamespacesIter != 0)
    theNamespacesIter->close(planState);

  StateTraitsImpl<ElementIteratorState>::destroyState(planState, theStateOffset);
}


/*******************************************************************************

********************************************************************************/
AttributeIterator::AttributeIterator(
    static_context* sctx,
    const QueryLoc& loc,
    const store::Item_t& qname,
    PlanIter_t& qnameIte,
    PlanIter_t& valueIte,
    bool isRoot)
  :
  BinaryBaseIterator<AttributeIterator, PlanIteratorState>(sctx, loc, qnameIte, valueIte),
  theQName(qname),
  theIsId(false),
  theIsRoot(isRoot)
{
  if (theQName != NULL)
  {
    if (theQName->getLocalName().empty())
    {
      RAISE_ERROR(err::XQDY0074, loc,
      ERROR_PARAMS("", ZED(NoEmptyLocalname)));
    }

    if (ZSTREQ(theQName->getNamespace(), "http://www.w3.org/2000/xmlns/") ||
        (theQName->getNamespace().empty() &&
         ZSTREQ(theQName->getLocalName(), "xmlns")))
    {
      RAISE_ERROR(err::XQDY0044, loc,
      ERROR_PARAMS(theQName->getStringValue()));
    }

    if ((ZSTREQ(theQName->getNamespace(), "http://www.w3.org/XML/1998/namespace") &&
         !theQName->getPrefix().empty() &&
         !ZSTREQ(theQName->getPrefix(), "xml")) ||
        (ZSTREQ(theQName->getPrefix(), "xml") &&
         !ZSTREQ(theQName->getNamespace(), "http://www.w3.org/XML/1998/namespace")))
    {
      RAISE_ERROR(err::XQDY0044, loc,
      ERROR_PARAMS(theQName->getStringValue()));
    }

    if ((ZSTREQ(theQName->getNamespace(), "http://www.w3.org/2000/xmlns/") &&
         !theQName->getPrefix().empty() &&
         !ZSTREQ(theQName->getPrefix(), "xmlns")) ||
        (ZSTREQ(theQName->getPrefix(), "xmlns") &&
         !ZSTREQ(theQName->getNamespace(), "http://www.w3.org/2000/xmlns/")))
    {
      throw XQUERY_EXCEPTION(
        err::XQDY0044,
        ERROR_PARAMS( theQName->getStringValue() ),
        ERROR_LOC( loc )
      );
    }

    if (ZSTREQ(theQName->getPrefix(), "xml") &&
        ZSTREQ(theQName->getLocalName(), "id"))
      theIsId = true;
  }
}


void AttributeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<AttributeIterator, PlanIteratorState>*)this);

  ar & theQName;
  ar & theIsId;
  ar & theIsRoot;
}


bool AttributeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  store::Item_t typeName = GENV_TYPESYSTEM.XS_UNTYPED_ATOMIC_QNAME;
  store::Item_t valueItem;
  zstring lexicalValue;
  store::Item_t typedValue;
  store::Item* parent;
  bool isId = theIsId;
  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (theChild0 != NULL)
  {
    // Compute the attribute name. Note: we don't have to check that itemQName
    // is indeed a valid qname, because the compiler wraps an xs:qname cast
    // around the name expression.
    consumeNext(qname, theChild0, planState);

    if (ZSTREQ(qname->getPrefix(), "xml") &&
        ZSTREQ(qname->getLocalName(), "id"))
    {
      isId = true;
    }

    if (qname->getLocalName().empty())
    {
      throw XQUERY_EXCEPTION(
        err::XQDY0074,
        ERROR_PARAMS( "", ZED( NoEmptyLocalname ) ),
        ERROR_LOC( loc )
      );
    }

    if (ZSTREQ(qname->getNamespace(), "http://www.w3.org/2000/xmlns/") ||
        (qname->getNamespace().empty() &&
         ZSTREQ(qname->getLocalName(), "xmlns")))
    {
      throw XQUERY_EXCEPTION(
        err::XQDY0044,
        ERROR_PARAMS( qname->getStringValue() ),
        ERROR_LOC( loc )
      );
    }
  }
  else
  {
    qname = theQName;
  }

  // Compute lexical value of the attribute.
  if (consumeNext(valueItem, theChild1, planState))
  {
    valueItem->getStringValue2(lexicalValue);

    while (consumeNext(valueItem, theChild1, planState))
    {
      valueItem->appendStringValue(lexicalValue);
    }
  }

  // normalize value of xml:id
  if (theIsId)
  {
    ascii::normalize_whitespace(lexicalValue);
  }

  GENV_ITEMFACTORY->createUntypedAtomic(typedValue, lexicalValue);

  // Create the attribute node
  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createAttributeNode(result,
                                        parent,
                                        qname,
                                        typeName,
                                        typedValue);
  STACK_PUSH(true, state);
  STACK_END (state);
}


BINARY_ACCEPT(AttributeIterator);


/*******************************************************************************

********************************************************************************/
TextIterator::TextIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t&     aChild,
    bool            isRoot)
  :
  UnaryBaseIterator<TextIterator, PlanIteratorState>(sctx, loc, aChild),
  theIsRoot(isRoot)
{
}


bool TextIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  zstring content;
  bool haveContent = false;
  store::Item_t valueItem;
  store::Item_t typedVal;
  store::Iterator_t typedIter;
  store::Item* parent;
  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the text content. If the value is the empty sequence, no text
  // node should be constructed.
  if (consumeNext(valueItem, theChild, planState))
  {
    haveContent = true;

    if (valueItem->isAtomic())
    {
      valueItem->getStringValue2(content);
    }
    else
    {
      valueItem->getTypedValue(typedVal, typedIter);

      if (typedIter == NULL)
      {
        typedVal->getStringValue2(content);
      }
      else
      {
        typedIter->open();

        if (typedIter->next(typedVal))
        {
          typedVal->appendStringValue(content);

          while (typedIter->next(typedVal))
          {
            content += " ";
            typedVal->appendStringValue(content);
          }
        }

        typedIter->close();
      }
    }

    while (consumeNext(valueItem, theChild, planState))
    {
      content += " ";

      if (valueItem->isAtomic())
      {
        valueItem->appendStringValue(content);
      }
      else
      {
        valueItem->getTypedValue(typedVal, typedIter);

        if (typedIter == NULL)
        {
          typedVal->appendStringValue(content);
        }
        else
        {
          typedIter->open();

          while (typedIter->next(typedVal))
          {
            content += " ";
            typedVal->appendStringValue(content);
          }

          typedIter->close();
        }
      }
    }
  }

  if (haveContent)
  {
    ZORBA_FATAL(theIsRoot || !path.empty(), "");

    parent = (theIsRoot ? NULL : path.top());

    STACK_PUSH(GENV_ITEMFACTORY->createTextNode(result, parent, content),
               state);
  }
  else
  {
    result = NULL;
    STACK_PUSH(false, state);
  }

  STACK_END (state);
}


UNARY_ACCEPT(TextIterator);


/*******************************************************************************

********************************************************************************/
PiIterator::PiIterator (
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t&     aTarget,
    PlanIter_t&     aContent,
    bool            isRoot)
  :
  BinaryBaseIterator<PiIterator, PlanIteratorState>(sctx, loc, aTarget, aContent),
  theIsRoot(isRoot)
{
}


bool PiIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  store::Item_t temp;
  zstring content;
  zstring target;
  zstring baseUri;
  bool lFirst;

  store::Item* parent;
  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  // Compute the target of the pi node.
  try
  {
    if (!consumeNext(lItem, theChild0, planState))
      // TODO: needs type in error message
      throw XQUERY_EXCEPTION(err::XPTY0004, ERROR_LOC(loc));
  }
  catch (ZorbaException const& e)
  {
    if (e.diagnostic() == err::FORG0001)
      throw XQUERY_EXCEPTION(err::XQDY0041, ERROR_LOC(loc));
    else
      throw;
  }

  if (consumeNext(temp, theChild0, planState))
    // TODO: needs type in error message
    throw XQUERY_EXCEPTION(err::XPTY0004, ERROR_LOC(loc));

  // TODO: check if lItem is string, raise XPTY0004 if not
  lItem->getStringValue2(target);

  if (target.empty())
  {
    throw XQUERY_EXCEPTION(err::XQDY0041, ERROR_LOC(loc));
  }
  else if (target.size() == 3)
  {
    zstring upper;
    utf8::to_upper(target, &upper);

    if (ZSTREQ(upper, "XML"))
      throw XQUERY_EXCEPTION(err::XQDY0064, ERROR_LOC(loc));
  }

  // Compute the content of the pi node
  for (lFirst = true;
       consumeNext(lItem, theChild1.getp(), planState);
       lFirst = false)
  {
    if (! lFirst)
      content += " ";

    zstring strvalue;
    lItem->getStringValue2(strvalue);

    if (strvalue.find("?>", 0, 2) != zstring::npos)
      throw XQUERY_EXCEPTION(err::XQDY0026, ERROR_LOC(loc));

    content += strvalue;
  }

  ascii::trim_start(content, " \n\r\t", &content);

  // Create the pi node
  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createPiNode(result, parent, target, content, baseUri);
  STACK_PUSH(true, state);

  STACK_END (state);
}


BINARY_ACCEPT(PiIterator);


/********************************************************************************

********************************************************************************/
CommentIterator::CommentIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t&     aComment,
    bool            isRoot)
  :
  UnaryBaseIterator<CommentIterator, PlanIteratorState>(sctx, loc, aComment),
  theIsRoot(isRoot)
{
}


bool CommentIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lItem;
  zstring content;
  bool lFirst;
  store::Item* parent;
  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  lFirst = true;
  while (true)
  {
    if (!consumeNext(lItem, theChild.getp(), planState))
      break;

    if (!lFirst)
      content += " ";

    lItem->appendStringValue(content);
    lFirst = false;
  }

  if (!content.empty())
  {
    if (content[content.size()-1] == '-' || content.find("--") != zstring::npos)
      throw XQUERY_EXCEPTION(err::XQDY0072, ERROR_LOC(loc));
  }

  ZORBA_FATAL(theIsRoot || !path.empty(), "");

  parent = (theIsRoot ? NULL : path.top());

  GENV_ITEMFACTORY->createCommentNode(result, parent, content);
  STACK_PUSH(true, state);

  STACK_END(state);
}


UNARY_ACCEPT(CommentIterator);


/*******************************************************************************

********************************************************************************/
void EnclosedIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  theDocChildren = NULL;
}


void EnclosedIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);

  theContextItem = NULL;

  if (theDocChildren != NULL)
  {
    theDocChildren->close();
    theDocChildren = 0;
  }
}


EnclosedIteratorState::~EnclosedIteratorState()
{
  if (theDocChildren != NULL)
  {
    theDocChildren->close();
    theDocChildren = 0;
  }
}


EnclosedIterator::EnclosedIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& childIter)
  :
  UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState>(sctx, loc, childIter),
  theAttrContent(false),
  theTextContent(false),
  theIsInUpdateExpr(false)
{
}


void EnclosedIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (UnaryBaseIterator<EnclosedIterator, EnclosedIteratorState>*)this);

  ar & theAttrContent;
  ar & theTextContent;
  ar & theIsInUpdateExpr;
}


bool EnclosedIterator::getAttrContent() const
{
  return theAttrContent;
}


void EnclosedIterator::setAttrContent()
{
  assert(theTextContent == false);
  theAttrContent = true;
}


bool EnclosedIterator::getTextContent() const
{
  return theTextContent;
}


void EnclosedIterator::setTextContent()
{
  assert(theAttrContent == false);
  theTextContent = true;
}


void EnclosedIterator::setInUpdateExpr()
{
  theIsInUpdateExpr = true;
}


bool EnclosedIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::ItemFactory* factory = GENV_ITEMFACTORY;
  zstring strval;
  std::stack<store::Item*>& path = planState.theNodeConstuctionPath;
  bool haveContent = false;
  store::Item* parent;

  EnclosedIteratorState* state;
  DEFAULT_STACK_INIT(EnclosedIteratorState, state, planState);

  if (theAttrContent || theTextContent)
  {
#if 1
    if (consumeNext(result, theChild, planState))
    {
      haveContent = true;

      if (result->isNode())
      {
        store::Item_t typedValue;
        store::Iterator_t typedIter;
        result->getTypedValue(typedValue, typedIter);

        if (typedIter == NULL)
        {
          typedValue->getStringValue2(strval);
        }
        else
        {
          if (typedIter->next(typedValue))
          {
            typedValue->appendStringValue(strval);
          }

          while (typedIter->next(typedValue))
          {
            strval += " ";
            typedValue->appendStringValue(strval);
          }
        }
      }
      else
      {
        result->getStringValue2(strval);
      }

      while (consumeNext(result, theChild, planState))
      {
        strval += " ";

        if (result->isNode())
        {
          store::Item_t typedValue;
          store::Iterator_t typedIter;
          result->getTypedValue(typedValue, typedIter);

          if (typedIter == NULL)
          {
            typedValue->appendStringValue(strval);
          }
          else
          {
            if (typedIter->next(typedValue))
            {
              typedValue->appendStringValue(strval);
            }

            while (typedIter->next(typedValue))
            {
              strval += " ";
              typedValue->appendStringValue(strval);
            }
          }
        }
        else
        {
          result->appendStringValue(strval);
        }
      }
    }

    if (theTextContent && !haveContent)
    {
      STACK_PUSH(false, state);
    }
    else
    {
      factory->createString(result, strval);
      STACK_PUSH(true, state);
    }
#else
    while ( true )
    {
      if (!consumeNext(result, theChild, planState))
        break;

      if (result->isNode())
      {
        store::Item_t typedValue;
        store::Iterator_t typedIter;
        result->getTypedValue(typedValue, typedIter);

        if (typedIter == NULL)
        {
          typedValue->appendStringValue(strval);
          strval += " ";
        }
        else
        {
          while (typedIter->next(typedValue))
          {
            typedValue->appendStringValue(strval);
            strval += " ";
          }
        }
      }
      else
      {
        result->appendStringValue(strval);
        strval += " ";
      }
    }

    if (strval.empty() && theTextContent)
    {
      STACK_PUSH(false, state);
    }
    else
    {
      // Erase the last space added in the above loop
      if (!strval.empty())
        strval.resize(strval.size() - 1);

      factory->createString(result, strval);
      STACK_PUSH(true, state);
    }
#endif
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
          result->getStringValue2(strval);

          {
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

              strval += " ";
              state->theContextItem->appendStringValue(strval);
            }
          }

          if (!strval.empty())
          {
            parent = NULL;
            if (!theIsInUpdateExpr && !path.empty())
              parent = path.top();

            STACK_PUSH(factory->createTextNode(result, parent, strval),
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


UNARY_ACCEPT(EnclosedIterator);


/*******************************************************************************

********************************************************************************/
NameCastIterator::NameCastIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& aChild,
    const namespace_context* aNCtx,
    bool isAttrName)
  :
  UnaryBaseIterator<NameCastIterator, PlanIteratorState>(sctx, loc, aChild),
  theNCtx(const_cast<namespace_context*>(aNCtx)),
  theIsAttrName(isAttrName)
{
}


NameCastIterator::~NameCastIterator()
{
}


bool NameCastIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  xqtref_t lItemType;
  store::Item_t temp;
  bool valid = false;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(result, theChild.getp(), planState))
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004,
      ERROR_PARAMS( ZED( EmptySeqNoCastToQName ) ),
      ERROR_LOC( loc )
    );
  }
  valid = true;

  if (consumeNext(temp, theChild, planState))
  {
    throw XQUERY_EXCEPTION(
      err::XPTY0004, ERROR_PARAMS( ZED( SeqNoCastToQName ) ), ERROR_LOC( loc )
    );
  }

  try
  {
    temp = result;
    valid = GenericCast::instance()->castToQName(result,
                                                 temp,
                                                 &*theNCtx,
                                                 theIsAttrName,
                                                 theSctx->get_typemanager(),
                                                 loc);
  }
  catch (ZorbaException const& e)
  {
    if (e.diagnostic() != err::XPTY0004)
    {
      zstring name = result->getStringValue();
      if (name.find(":") != zstring::npos && name.substr(0, name.find(":")) == "xmlns")
      {
        // this needs to be checked and thrown here as the optimizer
        // might try to fold a const expression and would return a different error code
        if (theIsAttrName)
          throw XQUERY_EXCEPTION(
            err::XQDY0044, ERROR_PARAMS(name), ERROR_LOC(loc)
          );
        else
          throw XQUERY_EXCEPTION(
            err::XQDY0096, ERROR_PARAMS(name), ERROR_LOC(loc)
          );
      }
      else
        // the returned error codes are wrong for name casting => they must be changed
        throw XQUERY_EXCEPTION(
          err::XQDY0074, ERROR_PARAMS( "item" ), ERROR_LOC( loc )
        );
    }
    else
    {
      throw;
    }
  }

  STACK_PUSH(valid, state);
  STACK_END(state);
}


UNARY_ACCEPT(NameCastIterator);


} // namespace zorba
/* vim:set et sw=2 ts=2: */
