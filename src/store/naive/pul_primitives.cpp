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

#include <exception>

#include "shared_types.h"
#include "store_defs.h"
#include "simple_store.h"
#include "simple_pul.h"
#include "pul_primitives.h"
#include "node_items.h"
#include "atomic_items.h"
#include "collection.h"
#include "simple_item_factory.h"
#include "node_factory.h"
#include "simple_index.h"
#include "simple_index_value.h"
#ifdef ZORBA_WITH_JSON
#include "json_items.h"
#endif

#include "store/api/iterator.h"
#include "store/api/copymode.h"
#include "store/api/validator.h"

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#ifdef ZORBA_WITH_JSON
using namespace zorba::simplestore::json;
#endif

namespace zorba {

namespace simplestore {

#if 0
#define TRACE(msg) std::cout << msg << << std::endl << std::endl;
#else
#define TRACE(msg)
#endif

/*******************************************************************************

********************************************************************************/
UpdatePrimitive::UpdatePrimitive(
    PULImpl* pul,
    const QueryLoc* aLoc,
    store::Item_t& target)
  :
  thePul(pul),
  theCollectionPul(NULL),
  theLoc(aLoc),
  theIsApplied(false),
  theRemoveType(false)
{
  theTarget.transfer(target);

  TRACE("Allocated upd : " << this << " in pul : " << thePul);
}


UpdatePrimitive::UpdatePrimitive(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target)
  :
  thePul(pul->thePul),
  theCollectionPul(pul),
  theLoc(aLoc),
  theIsApplied(false),
  theRemoveType(false)
{
  theTarget.transfer(target);

  TRACE("Allocated upd : " << this << " in pul : " << thePul);
}


UpdatePrimitive::UpdatePrimitive(PULImpl* pul, const QueryLoc* aLoc)
  :
  thePul(pul),
  theCollectionPul(NULL),
  theLoc(aLoc),
  theTarget(NULL),
  theIsApplied(false),
  theRemoveType(false)
{
  TRACE("Allocated upd : " << this << " in pul : " << thePul );
}


UpdatePrimitive::UpdatePrimitive(CollectionPul* pul, const QueryLoc* aLoc)
  :
  thePul(pul->thePul),
  theCollectionPul(pul),
  theLoc(aLoc),
  theIsApplied(false),
  theRemoveType(false)
{
  TRACE("Allocated upd : " << this << " in pul : " << thePul);
}


UpdatePrimitive::~UpdatePrimitive()
{
  TRACE("De-Allocated upd : " << this << " in pul : " << thePul);
}


/*******************************************************************************

********************************************************************************/
void UpdatePrimitive::addNodeForValidation(zorba::store::Item* node)
{
  theCollectionPul->theValidationNodes.insert(node);
}


/*******************************************************************************
  For now, just disconnect the current target from its parent (if any). The
  actual deletion of the target node and its subtree is done after all update
  primitives have been applied without errors (see PULImpl::applyUpdates()
  method). This way, to undo a delete, we just need to reconnect the target node
  at its original position under its original parent.
********************************************************************************/
UpdDelete::UpdDelete(CollectionPul* pul, const QueryLoc* loc, store::Item_t& target)
  :
  UpdatePrimitive(pul, loc, target)
{
  XmlNode* child = BASE_NODE(theTarget);

  store::StoreConsts::NodeKind childKind = child->getNodeKind();

  if (childKind == store::StoreConsts::elementNode || 
      childKind == store::StoreConsts::attributeNode ||
      childKind == store::StoreConsts::textNode)
    theRemoveType = true;
}


void UpdDelete::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  theParent = target->theParent;

  if (theParent != NULL)
  {
    theParent->deleteChild(*this);
  }
}


void UpdDelete::undo()
{
  if (theParent != NULL)
  {
    theParent->restoreChild(*this);
  }
}


/*******************************************************************************

********************************************************************************/
UpdInsertChildren::UpdInsertChildren(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t& target,
    store::Item_t& sibling,
    std::vector<store::Item_t>& children)
  :
  UpdatePrimitive(pul, aLoc, target),
  theKind(kind),
  theNumApplied(0)
{
  theSibling.transfer(sibling);

  std::size_t numNewChildren = 0;
  std::size_t numChildren = children.size();
  theNewChildren.resize(numChildren);

  for (std::size_t i = 0; i < numChildren; i++)
  {
    if (i > 0 &&
        children[i]->getNodeKind() == store::StoreConsts::textNode &&
        theNewChildren[i-1]->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* node1 = reinterpret_cast<TextNode*>(theNewChildren[i-1].getp());
      TextNode* node2 = reinterpret_cast<TextNode*>(children[i].getp());

      zstring newText;
      newText.reserve(node1->getText().size() + node2->getText().size());
      newText = node1->getText();
      newText += node2->getText();
      node1->setText(newText);
    }
    else
    {
      theNewChildren[i].transfer(children[i]);
      ++numNewChildren;
    }

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind childKind = theNewChildren[i]->getNodeKind();
      if (childKind == store::StoreConsts::elementNode ||
          childKind == store::StoreConsts::textNode)
        theRemoveType = true;
    }
  }

  theNewChildren.resize(numNewChildren);
}


void UpdInsertChildren::apply()
{
  theIsApplied = true;

  switch (theKind)
  {
  case store::UpdateConsts::UP_INSERT_INTO:
  {
    InternalNode* target = INTERNAL_NODE(theTarget);
    target->insertChildren(*this, target->numChildren());
    break;
  }
  case store::UpdateConsts::UP_INSERT_INTO_FIRST:
  {
    INTERNAL_NODE(theTarget)->insertChildren(*this, 0);
    break;
  }
  case store::UpdateConsts::UP_INSERT_INTO_LAST:
  {
    InternalNode* target = INTERNAL_NODE(theTarget);
    target->insertChildren(*this, target->numChildren());
    break;
  }
  case store::UpdateConsts::UP_INSERT_BEFORE:
  {
    BASE_NODE(theSibling)->insertSiblingsBefore(*this);
    break;
  }
  case store::UpdateConsts::UP_INSERT_AFTER:
  {
    BASE_NODE(theSibling)->insertSiblingsAfter(*this);
    break;
  }
  default:
    ZORBA_FATAL(0, "");
  }
}


void UpdInsertChildren::undo()
{
  if (theKind == store::UpdateConsts::UP_INSERT_BEFORE ||
      theKind == store::UpdateConsts::UP_INSERT_AFTER)
  {
    reinterpret_cast<InternalNode*>(theSibling->getParent())->
    undoInsertChildren(*this);
  }
  else
  {
    INTERNAL_NODE(theTarget)->undoInsertChildren(*this);
  }
}


/*******************************************************************************

********************************************************************************/
UpdInsertAttributes::UpdInsertAttributes(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    std::vector<store::Item_t>&  attrs)
  :
  UpdatePrimitive(pul, aLoc, target),
  theNumApplied(0)
{
  std::size_t numAttrs = attrs.size();
  theNewAttrs.resize(numAttrs);
  for (std::size_t i = 0; i < numAttrs; i++)
  {
    theNewAttrs[i].transfer(attrs[i]);
  }
}


void UpdInsertAttributes::apply()
{
  theIsApplied = true;
  ELEM_NODE(theTarget)->insertAttributes(*this);
}


void UpdInsertAttributes::undo()
{
  ELEM_NODE(theTarget)->undoInsertAttributes(*this);
}


void UpdInsertAttributes::check()
{
  ElementNode* target = ELEM_NODE(theTarget);
  try
  {
    target->checkUniqueAttrs();
  } catch (ZorbaException& e)
  {
    set_source(e, *theLoc);
    throw;
  }
}


/*******************************************************************************

********************************************************************************/
UpdReplaceAttribute::UpdReplaceAttribute(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& attr,
    std::vector<store::Item_t>& newAttrs)
  :
  UpdatePrimitive(pul, aLoc, target),
  theNumApplied(0)
{
  theAttr.transfer(attr);

  std::size_t numAttrs = newAttrs.size();
  theNewAttrs.resize(numAttrs);
  for (std::size_t i = 0; i < numAttrs; i++)
  {
    theNewAttrs[i].transfer(newAttrs[i]);
  }
}


void UpdReplaceAttribute::apply()
{
  theIsApplied = true;
  ELEM_NODE(theTarget)->replaceAttribute(*this);
}


void UpdReplaceAttribute::undo()
{
  ELEM_NODE(theTarget)->restoreAttribute(*this);
}


void UpdReplaceAttribute::check()
{
  ElementNode* target = ELEM_NODE(theTarget);
  try
  {
    target->checkUniqueAttrs();
  } catch (ZorbaException& e)
  {
    set_source(e, *theLoc);
    throw;
  }
}


/*******************************************************************************

********************************************************************************/
UpdReplaceChild::UpdReplaceChild(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& child,
    std::vector<store::Item_t>& newChildren)
  :
  UpdatePrimitive(pul, aLoc, target),
  theNumApplied(0)
{
  theChild.transfer(child);

  store::StoreConsts::NodeKind targetKind = theTarget->getNodeKind();
  store::StoreConsts::NodeKind childKind = theChild->getNodeKind();

  if (targetKind == store::StoreConsts::elementNode &&
      (childKind == store::StoreConsts::elementNode ||
       childKind == store::StoreConsts::textNode))
    theRemoveType = true;

  csize numChildren = newChildren.size();
  theNewChildren.resize(numChildren);
  for (csize i = 0; i < numChildren; ++i)
  {
    theNewChildren[i].transfer(newChildren[i]);

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind childKind = theNewChildren[i]->getNodeKind();
      if (targetKind == store::StoreConsts::elementNode &&
          (childKind == store::StoreConsts::elementNode ||
           childKind == store::StoreConsts::textNode))
        theRemoveType = true;
    }
  }
}


void UpdReplaceChild::apply()
{
  INTERNAL_NODE(theTarget)->replaceChild(*this);
}


void UpdReplaceChild::undo()
{
  INTERNAL_NODE(theTarget)->restoreChild(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceElemContent::apply()
{
  ELEM_NODE(theTarget)->replaceContent(*this);
  theIsApplied = true;
}


void UpdReplaceElemContent::undo()
{
  ELEM_NODE(theTarget)->restoreContent(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdRenameElem::apply()
{
  ELEM_NODE(theTarget)->replaceName(*this);
  theIsApplied = true;
}


void UpdRenameElem::undo()
{
  ELEM_NODE(theTarget)->restoreName(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdSetElementType::apply()
{
  ElementNode* target = ELEM_NODE(theTarget);
  TextNode* textChild;

  theOldTypeName = target->getType();
  theOldHaveTypedValue = target->haveTypedValue();
  theOldHaveTypedTypedValue = target->haveTypedTypedValue(textChild);

  if (theOldHaveTypedValue)
    theOldHaveEmptyTypedValue = target->haveEmptyTypedValue();

  theOldIsInSubstitutionGroup = target->isInSubstitutionGroup();

  target->setType(theTypeName);

  if (theOldHaveTypedTypedValue)
  {
    theOldHaveListTypedValue = textChild->haveListValue();    
    theOldTypedValue = textChild->getValue();

    zstring textValue;
    textChild->getStringValue2(textValue);

    textChild->setValue(NULL);

    textChild->theFlags &= ~XmlNode::IsTyped;
    textChild->setText(textValue);
  }

  if (theHaveTypedValue)
  {
    target->setHaveTypedValue();

    if (theHaveEmptyTypedValue)
      target->setHaveEmptyTypedValue();
    else
      target->resetHaveEmptyTypedValue();

    if (theHaveTypedTypedValue)
    {
      textChild = target->getUniqueTextChild();

      textChild->setTypedValue(theTypedValue);

      if (theHaveListTypedValue)
        textChild->setHaveListValue();
      else
        textChild->resetHaveListValue();
    }
  }
  else
  {
    target->resetHaveTypedValue();
  }

  if (theIsInSubstitutionGroup)
    target->setInSubstGroup();
  else
    target->resetInSubstGroup();

  theIsApplied = true;
}


void UpdSetElementType::undo()
{
  if (theIsApplied)
  {
    ElementNode* target = ELEM_NODE(theTarget);

    target->setType(theOldTypeName);

    if (theHaveTypedTypedValue)
    {
      TextNode* textChild = target->getUniqueTextChild();
      textChild->revertToTextContent();
    }

    if (theOldHaveTypedValue)
    {
      target->setHaveTypedValue();

      if (theOldHaveEmptyTypedValue)
        target->setHaveEmptyTypedValue();
      else
        target->resetHaveEmptyTypedValue();

      if (theOldHaveTypedTypedValue)
      {
        TextNode* textChild = target->getUniqueTextChild();

        textChild->setTypedValue(theOldTypedValue);

        if (theOldHaveListTypedValue)
          textChild->setHaveListValue();
        else
          textChild->resetHaveListValue();
      }
    }
    else
    {
      target->resetHaveTypedValue();
    }

    if (theOldIsInSubstitutionGroup)
      target->setInSubstGroup();
    else
      target->resetInSubstGroup();

    theIsApplied = false;
  }
}

/*******************************************************************************

********************************************************************************/
void UpdReplaceAttrValue::apply()
{
  ATTR_NODE(theTarget)->replaceValue(*this);
  theIsApplied = true;
}


void UpdReplaceAttrValue::undo()
{
  ATTR_NODE(theTarget)->restoreValue(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdRenameAttr::apply()
{
  ATTR_NODE(theTarget)->replaceName(*this);
  theIsApplied = true;
}


void UpdRenameAttr::undo()
{
  ATTR_NODE(theTarget)->restoreName(*this);
}


void UpdRenameAttr::check()
{
  AttributeNode* attr = ATTR_NODE(theTarget);
  try
  {
    if (attr->getParent() != NULL)
    {
      ElementNode* parent = reinterpret_cast<ElementNode*>(attr->getParent());
      parent->checkUniqueAttrs();
    }
  } 
  catch (ZorbaException& e)
  {
    set_source(e, *theLoc);
    throw;
  }
}


/*******************************************************************************

********************************************************************************/
void UpdSetAttributeType::apply()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  theOldTypeName = target->getType();
  theOldTypedValue.transfer(target->theTypedValue);
  theOldHaveListValue = target->haveListValue();

  target->setType(theTypeName);
  target->theTypedValue.transfer(theTypedValue);

  if (theHaveListValue)
    target->setHaveListValue();
  else
    target->resetHaveListValue();

  theIsApplied = true;
}


void UpdSetAttributeType::undo()
{
  if (theIsApplied)
  {
    AttributeNode* target = ATTR_NODE(theTarget);
    target->setType(theOldTypeName);
    target->theTypedValue.transfer(theOldTypedValue);

    if (theOldHaveListValue)
      target->setHaveListValue();
    else
      target->resetHaveListValue();

    theIsApplied = false;
  }
}


/*******************************************************************************

********************************************************************************/
void UpdRevalidate::apply()
{
#ifndef ZORBA_NO_XMLSCHEMA
  std::set<store::Item*> nodes;

  theRevalidationPul = GET_STORE().getItemFactory()->createPendingUpdateList();

  nodes.insert(theTarget.getp());

  if (!thePul->theValidator)
    return;

  thePul->theValidator->validate(nodes, *theRevalidationPul.getp());

  try
  {
    theRevalidationPul->applyUpdates(false);
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Error during the in-place validation");
  }

  theIsApplied = true;
#endif
}


void UpdRevalidate::undo()
{
#ifndef ZORBA_NO_XMLSCHEMA
  static_cast<PULImpl *>(theRevalidationPul.getp())->undoUpdates();
#endif
}


/*******************************************************************************

********************************************************************************/
UpdReplaceTextValue::~UpdReplaceTextValue()
{
  if (theIsTyped)
    theOldContent.setValue(NULL);
  else
    theOldContent.destroyText();
}


void UpdReplaceTextValue::apply()
{
  TEXT_NODE(theTarget)->replaceValue(*this);
  theIsApplied = true;
}


void UpdReplaceTextValue::undo()
{
  TEXT_NODE(theTarget)->restoreValue(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdReplacePiValue::apply()
{
  PI_NODE(theTarget)->replaceValue(*this);
  theIsApplied = true;
}


void UpdReplacePiValue::undo()
{
  PI_NODE(theTarget)->restoreValue(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdRenamePi::apply()
{
  PI_NODE(theTarget)->replaceName(*this);
  theIsApplied = true;
}


void UpdRenamePi::undo()
{
  PI_NODE(theTarget)->restoreName(*this);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceCommentValue::apply()
{
  COMMENT_NODE(theTarget)->replaceValue(*this);
  theIsApplied = true;
}


void UpdReplaceCommentValue::undo()
{
  COMMENT_NODE(theTarget)->restoreValue(*this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  fn:put Primitives                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void UpdPut::apply()
{
  Store* store = &GET_STORE();

  zstring targetUri;
  theTargetUri->getStringValue2(targetUri);

  try
  {
    // Have to copy because addNode() will set the doc uri of target tree to
    // the uri passed as an arg to fn:put, but the target tree may already
    // have a doc uri, which we should not overwrite. Another reason that we
    // have to copy is that if the target node is an element node, we wrap it
    // with a doc node, but this would not be possible if the target node had
    // a parent already.
    store::CopyMode copymode;
    copymode.set(true, true, true, true);

    if (theTarget->getNodeKind() != store::StoreConsts::documentNode)
    {
      store::Item_t docItem;
      GET_FACTORY().createDocumentNode(docItem, targetUri, targetUri);

      theTarget = theTarget->copy(docItem.getp(), copymode);

      theTarget.transfer(docItem);
    }
    else
    {
      theTarget = theTarget->copy(NULL, copymode);
    }

    store->addNode(targetUri, theTarget);
  }
  catch(ZorbaException const& e)
  {
    if (e.diagnostic() == zerr::ZAPI0020_DOCUMENT_ALREADY_EXISTS)
    {
      theOldDocument = store->getDocument(targetUri);

      store->deleteDocument(targetUri);

      store->addNode(targetUri, theTarget);
    }
    else
    {
      throw;
    }
  }

  theIsApplied = true;
}


void UpdPut::undo()
{
  Store* store = &GET_STORE();

  store->deleteDocument(theTargetUri->getStringValue());

  store->addNode(theTargetUri->getStringValue(), theOldDocument);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Collection Primitives                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
UpdCollection::UpdCollection(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isDynamic)
  :
  UpdatePrimitive(pul, aLoc),
  theIsDynamic(isDynamic)
{
  theName.transfer(name);

  csize numNodes = nodes.size();
  theNodes.resize(numNodes);

  for (csize i = 0; i < numNodes; ++i)
  {
    theNodes[i].transfer(nodes[i]);
  }
}


UpdCollection::UpdCollection(
    CollectionPul* pul,
    const QueryLoc* aLoc,
    store::Item_t& target,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isDynamic)
  :
  UpdatePrimitive(pul, aLoc, target),
  theIsDynamic(isDynamic)
{
  theName.transfer(name);

  csize numNodes = nodes.size();
  theNodes.resize(numNodes);

  for (csize i = 0; i < numNodes; ++i)
  {
    theNodes[i].transfer(nodes[i]);
  }
}


/*******************************************************************************
  UpdCreateCollection
********************************************************************************/
void UpdCreateCollection::apply()
{
  // Error is raised if collection exists already.
  GET_STORE().createCollection(theName,
                               theAnnotations,
                               theNodeType,
                               theIsDynamic);
  theIsApplied = true;
}


void UpdCreateCollection::undo()
{
  try
  {
    GET_STORE().deleteCollection(theName, theIsDynamic);
  }
  catch (...)
  {
    // In general, GET_STORE().deleteCollection(theName) will raise an error if
    // collection does not exists, but in this case, the collection should exist.
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************
  UpdDeleteCollection
********************************************************************************/
void UpdDeleteCollection::apply()
{
  theCollection = GET_STORE().getCollection(theName, theIsDynamic);
  if (theCollection == NULL)
    return;//If two delete collection are issued in the same snapshot is a noop

  Collection* collection = static_cast<Collection*>(theCollection.getp());

  std::vector<store::Index*> indexes;
  collection->getIndexes(indexes);

  if (!indexes.empty())
  {
    RAISE_ERROR(zerr::ZDDY0013_COLLECTION_BAD_DESTROY_INDEXES, theLoc,
    ERROR_PARAMS(collection->getName()->getStringValue()));
  }

  std::vector<store::IC*> activeICs;
  collection->getActiveICs(activeICs);

  if (!activeICs.empty())
  {
    RAISE_ERROR(zerr::ZDDY0014_COLLECTION_BAD_DESTROY_ICS, theLoc,
    ERROR_PARAMS(collection->getName()->getStringValue()));
  }

  uint64_t size;
  try 
  {
    size = to_xs_unsignedLong(collection->size());
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("collection too big ("
                              << e.what() << "; " << theName << ")")));
  }

  for (uint64_t i = 0; i < size; ++i)
  {
    XmlNode* root = static_cast<XmlNode*>(collection->nodeAt(xs_integer(i)).getp());
    XmlTree* tree = root->getTree();
    if (tree->getRefCount() > 1)
    {
      RAISE_ERROR(zerr::ZDDY0015_COLLECTION_BAD_DESTROY_NODES, theLoc,
      ERROR_PARAMS(collection->getName()->getStringValue()));
    }
  }

  GET_STORE().deleteCollection(theName, theIsDynamic);
  theIsApplied = true;
}


void UpdDeleteCollection::undo()
{
  GET_STORE().addCollection(theCollection);
}


/*******************************************************************************
  UpdInsertIntoCollection
********************************************************************************/
void UpdInsertIntoCollection::apply()
{
  Collection* lColl = static_cast<Collection*>(
  GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  theIsApplied = true;

  csize numNodes = theNodes.size();
  for (csize i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], xs_integer(-1));
    ++theNumApplied;
  }
}


void UpdInsertIntoCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  uint64_t lastPos;
  try 
  {
    lastPos = to_xs_unsignedLong(lColl->size()) - 1;
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("collection too big ("
                              << e.what() << "; " << theName << ")")));
  }

  for (long i = theNumApplied-1; i >= 0; --i)
  {
    xs_integer xs_lastPos( lastPos );
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(xs_lastPos));

    lColl->removeNode(xs_lastPos);
    --lastPos;
  }
}


/*******************************************************************************
  UpdInsertFirstIntoCollection
********************************************************************************/
void UpdInsertFirstIntoCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  theIsApplied = true;

  theCollectionPul->setAdjustTreePositions();

  csize numNodes = theNodes.size();
  for (csize i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], xs_integer(i));
    ++theNumApplied;
  }
}


void UpdInsertFirstIntoCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  xs_integer const zero( xs_integer::zero() );
  for (std::size_t i = 0; i < theNumApplied; ++i)
  {
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(zero));

    lColl->removeNode(zero);
  }
}


/*******************************************************************************
  UpdInsertLastIntoCollection
********************************************************************************/
void UpdInsertLastIntoCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  theIsApplied = true;

  std::size_t numNodes = theNodes.size();
  xs_integer const neg_1( -1 );
  for (std::size_t i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], neg_1);
  }
}


void UpdInsertLastIntoCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  uint64_t lastPos;
  try 
  {
    lastPos = to_xs_unsignedLong(lColl->size()) - 1;
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("collection too big ("
                              << e.what() << "; " << theName << ")")));
  }

  xs_integer const xs_lastPos( lastPos );
  for (long i = theNumApplied-1; i >= 0; --i)
  {
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(xs_lastPos));

    lColl->removeNode(xs_lastPos);
  }
}


/*******************************************************************************
  UpdInsertBeforeIntoCollection
********************************************************************************/
void UpdInsertBeforeIntoCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  if (!theNodes.empty())
    theFirstNode = theNodes[0];

  theCollectionPul->setAdjustTreePositions();

  theFirstPos = lColl->addNodes(theNodes, theTarget, true);

  theIsApplied = true;
}

void UpdInsertBeforeIntoCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);
  ZORBA_ASSERT(theFirstNode == lColl->nodeAt(theFirstPos));

  lColl->removeNodes(theFirstPos, xs_integer(theNodes.size()));
}


/*******************************************************************************
  UpdInsertAfterIntoCollection
********************************************************************************/
void UpdInsertAfterIntoCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  if (!theNodes.empty())
    theFirstNode = theNodes[0];

  theCollectionPul->setAdjustTreePositions();

  theFirstPos = lColl->addNodes(theNodes, theTarget, false);

  theIsApplied = true;
}


void UpdInsertAfterIntoCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);
  ZORBA_ASSERT(theFirstNode == lColl->nodeAt(theFirstPos));

  lColl->removeNodes(theFirstPos, xs_integer(theNodes.size()));
}


/*******************************************************************************
  UpdRemoveNodesFromCollection
********************************************************************************/
void UpdDeleteNodesFromCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  theIsApplied = true;

  uint64_t size;
  try
  {
    size = to_xs_unsignedLong(lColl->size());
  }
  catch (std::range_error& e)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0060_RANGE_EXCEPTION,
    ERROR_PARAMS(BUILD_STRING("collection too big ("
                              << e.what() << "; " << theName << ")")));
  }

  csize numNodes = theNodes.size();

  bool isLast = theIsLast;

  if (theIsLast)
  {
    for (csize i = numNodes; i > 0; --i)
    {
      if (theNodes[i-1] != lColl->nodeAt(xs_integer(size - i)))
      {
        isLast = false;
        break;
      }
    }
  }

  if (!isLast)
  {
    theCollectionPul->setAdjustTreePositions();
  }

  theFound.resize(numNodes);
  thePositions.resize(numNodes);

  for (std::size_t i = 0; i < numNodes; ++i)
  {
    theFound[i] = lColl->removeNode(theNodes[i], thePositions[i]);
    ++theNumApplied;
  }
}

void UpdDeleteNodesFromCollection::undo()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);

  for (csize i = 0; i < theNumApplied; ++i)
  {
    if (theFound[i])
    {
      lColl->addNode(theNodes[i], thePositions[i]);
    }
  }
}


/*******************************************************************************
  UpdTruncateCollection
********************************************************************************/
void UpdTruncateCollection::apply()
{
  Collection* lColl = static_cast<Collection*>
  (GET_STORE().getCollection(theName, theIsDynamic).getp());

  assert(lColl);
  
  lColl->removeAll();
}


void UpdTruncateCollection::undo()
{
  // NOOP
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Index Primitives                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
UpdCreateIndex::UpdCreateIndex(
   PULImpl* pul,
   const QueryLoc* aLoc,
   const store::Item_t& qname,
   const store::IndexSpecification& spec,
   store::Iterator* sourceIter)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(qname),
  theSpec(spec),
  theSourceIter(sourceIter)
{
}


void UpdCreateIndex::apply()
{
  Store* store = &GET_STORE();

  try
  {
    theIndex = store->createIndex(theQName, theSpec, theSourceIter);
  }
  catch(ZorbaException const& e)
  {
    if (e.diagnostic() == zerr::ZSTR0045_DUPLICATE_NODE_ERROR)
    {
      throw ZORBA_EXCEPTION(
        zerr::ZDDY0028_INDEX_DOMAIN_HAS_DUPLICATE_NODES, 
        ERROR_PARAMS( theQName->getStringValue() )
      );
    }
    throw;
  }

  theIsApplied = true;
}


void UpdCreateIndex::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();

    store->deleteIndex(theQName);
  }
}


/*******************************************************************************

********************************************************************************/
UpdDeleteIndex::UpdDeleteIndex(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& qname)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(qname)
{
}


void UpdDeleteIndex::apply()
{
  Store* store = &GET_STORE();

  if ((theIndex = store->getIndex(theQName)) == NULL)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0002_INDEX_DOES_NOT_EXIST,
    ERROR_PARAMS(theQName->getStringValue()));
  }

  store->deleteIndex(theQName);

  theIsApplied = true;
}


void UpdDeleteIndex::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();

    store->addIndex(theIndex);
  }
}


/*******************************************************************************

********************************************************************************/
UpdRefreshIndex::UpdRefreshIndex(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& qname,
    store::Iterator* sourceIter)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(qname),
  theSourceIter(sourceIter)
{
}


UpdRefreshIndex::~UpdRefreshIndex()
{
}


void UpdRefreshIndex::apply()
{
  Store& store = GET_STORE();

  if ((theIndex = store.getIndex(theQName)) == NULL)
  {
    throw ZORBA_EXCEPTION(zerr::ZSTR0002_INDEX_DOES_NOT_EXIST,
    ERROR_PARAMS(theQName->getStringValue()));
  }

  store.refreshIndex(theQName, theIndex->getSpecification(), theSourceIter);

  theIsApplied = true;
}  


void UpdRefreshIndex::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();
    store->deleteIndex(theQName);
    store->addIndex(theIndex);
  }
}


/*******************************************************************************

********************************************************************************/
UpdActivateIC::UpdActivateIC(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& qname,
    const store::Item_t& aCollectionName)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(qname),
  theCollectionName(aCollectionName)
{
}


UpdActivateIC::~UpdActivateIC()
{
}


void UpdActivateIC::apply()
{
  Store* store = &GET_STORE();
  store->activateIC(theQName, theCollectionName,theIsApplied);
}


void UpdActivateIC::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();
    bool isApplied;
    store->deactivateIC(theQName,isApplied);
    theIsApplied=false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdActivateForeignKeyIC::UpdActivateForeignKeyIC(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName,
    const store::Item_t& aFromCollection,
    const store::Item_t& aToCollection)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(aQName),
  theFromCollectionName(aFromCollection),
  theToCollectionName(aToCollection)
{
}


UpdActivateForeignKeyIC::~UpdActivateForeignKeyIC()
{
}


void UpdActivateForeignKeyIC::apply()
{
  Store* store = &GET_STORE();
  store->activateForeignKeyIC(theQName, theFromCollectionName, theToCollectionName,theIsApplied);
}


void UpdActivateForeignKeyIC::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();
    bool isApplied;
    store->deactivateIC(theQName,isApplied);
    theIsApplied=false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdDeActivateIC::UpdDeActivateIC(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(aQName)
{
}


UpdDeActivateIC::~UpdDeActivateIC()
{
}


void UpdDeActivateIC::apply()
{
  Store* store = &GET_STORE();
  store::IC_t ic = store->deactivateIC(theQName,theIsApplied);
  if (theIsApplied)
  {
    theICKind = ic->getICKind();
    switch (theICKind) {
      case store::IC::ic_collection:
        theFromCollectionName = ic->getCollectionName();
        break;
      case store::IC::ic_foreignkey:
        theFromCollectionName = ic->getFromCollectionName();
        theToCollectionName = ic->getToCollectionName();
        break;
      default:
        ZORBA_ASSERT(false);
    }
  }
}


void UpdDeActivateIC::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();
    bool isApplied;
    switch (theICKind) 
    {
      case store::IC::ic_collection:
        store->activateIC(theQName, theFromCollectionName,isApplied);
        break;
      case store::IC::ic_foreignkey:
        store->activateForeignKeyIC(
            theQName,
            theFromCollectionName,
            theToCollectionName,isApplied);
        break;
      default:
        ZORBA_ASSERT(false);
      // TODO
    }
  }
}


/*******************************************************************************

********************************************************************************/
UpdCreateDocument::UpdCreateDocument(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aUri,
    store::Item_t& aDoc)
  :
  UpdatePrimitive(pul, aLoc),
  theUri(aUri),
  theDoc(aDoc)
{
}


void UpdCreateDocument::apply()
{
  Store* store = &GET_STORE();

  store->addNode(theUri->getStringValue(), theDoc);

  theIsApplied = true;
}


void UpdCreateDocument::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();

    store->deleteDocument(theUri->getStringValue());
    theIsApplied = false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdDeleteDocument::UpdDeleteDocument(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aUri)
  :
  UpdatePrimitive(pul, aLoc),
  theUri(aUri)
{
}


void UpdDeleteDocument::apply()
{
  Store* store = &GET_STORE();

  zstring lUri = theUri->getStringValue();

  theDoc = store->getDocument(lUri); // remember for undo

  if(theDoc != NULL) //is not checked in the iterator if two
  {                  //deleteDocument are present for the same uri
    store->deleteDocument(lUri);
    theIsApplied = true;
  }
}


void UpdDeleteDocument::undo()
{
  if (theIsApplied)
  {
    Store* store = &GET_STORE();
    store->addNode(theUri->getStringValue(), theDoc);
    theIsApplied = false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdHashMap::UpdHashMap(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName)
  :
  UpdatePrimitive(pul, aLoc),
  theQName(aQName)
{
}

/*******************************************************************************

********************************************************************************/
UpdCreateHashMap::UpdCreateHashMap(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKeyTypes,
    const std::vector<zstring>& aCollations,
    long aTimezone)
  :
  UpdHashMap(pul, aLoc, aQName),
  theKeyTypes(aKeyTypes),
  theCollations(aCollations),
  theTimezone(aTimezone)
{
}


void UpdCreateHashMap::apply()
{
  store::IndexSpecification lSpec;
  lSpec.theNumKeyColumns = theKeyTypes.size();
  lSpec.theKeyTypes = theKeyTypes;

  std::vector<std::string> lCollations;
  lCollations.reserve(theCollations.size());
  for (std::vector<zstring>::const_iterator lIter = theCollations.begin();
       lIter != theCollations.end(); ++lIter)
  { 
    lCollations.push_back(lIter->c_str());
  }

  lSpec.theCollations = lCollations;
  lSpec.theTimezone = theTimezone;


  GET_STORE().createMap(theQName, lSpec);
  theIsApplied = true;
}


void UpdCreateHashMap::undo()
{
  if (theIsApplied)
  {
    GET_STORE().destroyMap(theQName);
  }
}


/*******************************************************************************

********************************************************************************/
UpdDestroyHashMap::UpdDestroyHashMap(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName)
  :
  UpdHashMap(pul, aLoc, aQName)
{
}


void UpdDestroyHashMap::apply()
{
  theMap = GET_STORE().destroyMap(theQName);
  theIsApplied = true;
}


void UpdDestroyHashMap::undo()
{
  if (theIsApplied)
  {
    GET_STORE().addMap(theMap);
  }
}


/*******************************************************************************

********************************************************************************/
UpdInsertIntoHashMap::UpdInsertIntoHashMap(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKey,
    const store::Iterator_t& aValue)
  :
  UpdHashMap(pul, aLoc, aQName),
  theKey(aKey),
  theValue(aValue)
{
}


void UpdInsertIntoHashMap::apply()
{
  store::Index_t lMap = GET_STORE().getMap(theQName);

  if (!lMap)
  {
    throw ZORBA_EXCEPTION(zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
    ERROR_PARAMS(theQName->getStringValue()));
  }

  ValueIndex* lImpl = static_cast<ValueIndex*>(lMap.getp());

  theValue->open();
  store::Item_t lValue;

  while (theValue->next(lValue))
  {
    std::auto_ptr<store::IndexKey> lKey(new store::IndexKey());
    for (std::vector<store::Item_t>::const_iterator lIter = theKey.begin();
         lIter != theKey.end();
         ++lIter)
    {
      lKey->push_back(*lIter);
    }

    store::IndexKey* lKeyPtr = lKey.get();
    if (!lImpl->insert(lKeyPtr, lValue))
    {
      // the index took the ownership over the key if the index
      // did _not_ already contain an entry with the same key
      lKey.release();
    }
  }
}


void UpdInsertIntoHashMap::undo()
{
}


/*******************************************************************************

********************************************************************************/
UpdRemoveFromHashMap::UpdRemoveFromHashMap(
    PULImpl* pul,
    const QueryLoc* aLoc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKey)
  :
  UpdHashMap(pul, aLoc, aQName),
  theKey(aKey)
{
}


void UpdRemoveFromHashMap::apply()
{
  store::Index_t lMap = GET_STORE().getMap(theQName);

  if (!lMap)
  {
    throw ZORBA_EXCEPTION(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( theQName->getStringValue() )
    );
  }

  simplestore::ValueHashIndex* lImpl =
    static_cast<simplestore::ValueHashIndex*>(lMap.getp());

  store::IndexKey lKey;
  for (std::vector<store::Item_t>::const_iterator lIter = theKey.begin();
       lIter != theKey.end();
       ++lIter)
  {
    lKey.push_back(*lIter);
  }

  store::Item_t lValue;
  lImpl->remove(&lKey, lValue, true);
}


void UpdRemoveFromHashMap::undo()
{
}

#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
UpdJSONObjectInsert::UpdJSONObjectInsert(
    CollectionPul* pul,
    const QueryLoc* loc,
    store::Item_t& target,
    std::vector<store::Item_t>& names,
    std::vector<store::Item_t>& values)
  :
  UpdatePrimitive(pul, loc, target),
  theNumApplied(0)
{
  assert(names.size() == values.size());

  theNames.swap(names);
  theValues.swap(values);
}


void UpdJSONObjectInsert::apply()
{
  ZORBA_ASSERT(theTarget->isJSONObject());

  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  csize numPairs = theNames.size();
  for (csize i = 0; i < numPairs; ++i, ++theNumApplied)
  {
    if (!obj->add(theNames[i], theValues[i], false))
    {
      RAISE_ERROR(jerr::JNUP0006, theLoc, 
      ERROR_PARAMS(theNames[i]->getStringValue()));
    }
  }

  theIsApplied = true;
}


void UpdJSONObjectInsert::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  for (csize i = theNumApplied; i > 0; --i)
  {
    obj->remove(theNames[i-1]);
  }

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONObjectDelete::UpdJSONObjectDelete(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      store::Item_t& name)
  :
  UpdatePrimitive(pul, loc, target),
  theName(name)
{
  assert(theTarget->isJSONObject());
}


void UpdJSONObjectDelete::apply()
{
  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  theOldValue = obj->remove(theName);
  
  theIsApplied = true;
}


void UpdJSONObjectDelete::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  bool inserted = obj->add(
      theName,
      theOldValue,
      false);

  ZORBA_ASSERT(inserted);

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONObjectReplaceValue::UpdJSONObjectReplaceValue(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newValue)
  :
  UpdatePrimitive(pul, loc, target),
  theName(name),
  theNewValue(newValue)
{
}


void UpdJSONObjectReplaceValue::apply()
{
  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  theOldValue = obj->setValue(theName, theNewValue);

  if (theOldValue != NULL)
  {
    theIsApplied = true;
  }
}


void UpdJSONObjectReplaceValue::undo()
{
  if (!theIsApplied)
    return;

  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  ZORBA_ASSERT(obj);

  obj->setValue(theName, theOldValue);

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONObjectRename::UpdJSONObjectRename(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      store::Item_t& name,
      store::Item_t& newName)
  :
  UpdatePrimitive(pul, loc, target),
  theName(name),
  theNewName(newName)
{
}


void UpdJSONObjectRename::apply()
{
  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  if (obj->getObjectValue(theNewName) != NULL)
  {
    RAISE_ERROR(jerr::JNUP0006, theLoc, ERROR_PARAMS(theNewName->getStringValue()));
  }
  
  if (obj->rename(theName, theNewName))
  {
    theIsApplied = true;
  }
}


void UpdJSONObjectRename::undo()
{
  if (!theIsApplied)
    return;

  JSONObject* obj = static_cast<JSONObject*>(theTarget.getp());

  ZORBA_ASSERT(obj);

  ZORBA_ASSERT(obj->rename(theNewName, theName));

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONArrayUpdate::UpdJSONArrayUpdate(
    CollectionPul* pul,
    const QueryLoc* loc,
    store::Item_t& target,
    xs_integer& pos)
  :
  UpdatePrimitive(pul, loc, target),
  thePosition(pos)
{
  assert(theTarget->isJSONArray());
}

UpdJSONArrayUpdate::UpdJSONArrayUpdate(
    CollectionPul* pul,
    const QueryLoc* loc,
    store::Item_t& target)
  :
  UpdatePrimitive(pul, loc, target),
  thePosition(0)
{
  assert(theTarget->isJSONArray());
}


bool UpdJSONArrayUpdate::Comparator::operator() (
    const UpdatePrimitive* lhs,
    const UpdatePrimitive* rhs)
{
  const UpdJSONArrayUpdate* l = static_cast<const UpdJSONArrayUpdate*>(lhs);
  const UpdJSONArrayUpdate* r = static_cast<const UpdJSONArrayUpdate*>(rhs);
  
  if (l->thePosition == 0) // lhs is an appending UP
    return true;

  if (l->thePosition > r->thePosition)
    return true;

  if (l->thePosition == r->thePosition)
  {
    if (l->getKind() == store::UpdateConsts::UP_JSON_ARRAY_DELETE)
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONArrayInsert::UpdJSONArrayInsert(
    CollectionPul* pul,
    const QueryLoc* loc,
    store::Item_t& target,
    xs_integer& pos,
    std::vector<store::Item_t>& members)
  :
  UpdJSONArrayUpdate(pul, loc, target, pos),
  theNumApplied(0)
{
  theMembers.swap(members);
}


void UpdJSONArrayInsert::apply()
{
  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  array->insert_before(thePosition, theMembers);

  theIsApplied = true;
}


void UpdJSONArrayInsert::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  csize numNewMembers = theMembers.size();

  for (csize i = 0; i < numNewMembers; ++i) 
    array->remove(thePosition);

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONArrayAppend::UpdJSONArrayAppend(
    CollectionPul* pul,
    const QueryLoc* loc,
    store::Item_t& target,
    std::vector<store::Item_t>& members)
  :
  UpdJSONArrayUpdate(pul, loc, target),
  theNumApplied(0)
{
  theMembers.swap(members);
}


void UpdJSONArrayAppend::apply()
{
  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  array->push_back(theMembers);

  theIsApplied = true;
}


void UpdJSONArrayAppend::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  csize numNewMembers = theMembers.size();
  xs_integer numTotalMembers = theTarget->getArraySize();
  xs_integer lPositionToDelete = numTotalMembers - numNewMembers;

  for (csize i = 0; i < numNewMembers; ++i) 
    array->remove(lPositionToDelete);

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONArrayDelete::UpdJSONArrayDelete(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      xs_integer& pos)
  :
  UpdJSONArrayUpdate(pul, loc, target, pos)
{
}


void UpdJSONArrayDelete::apply()
{
  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());
  
  theOldValue = array->remove(thePosition);
  
  if (theOldValue != NULL)
  {
    theIsApplied = true;
  }
}


void UpdJSONArrayDelete::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  array->insert_before(thePosition, theOldValue);

  theIsApplied = false;
}


/*******************************************************************************

********************************************************************************/
UpdJSONArrayReplaceValue::UpdJSONArrayReplaceValue(
      CollectionPul* pul,
      const QueryLoc* loc,
      store::Item_t& target,
      xs_integer& pos,
      store::Item_t& newValue)
  :
  UpdJSONArrayUpdate(pul, loc, target, pos),
  theNewValue(newValue)
{
}


void UpdJSONArrayReplaceValue::apply()
{
  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  theOldValue = array->replace(thePosition, theNewValue);
  
  if (theOldValue != NULL) {
    theIsApplied = true;
  }
}


void UpdJSONArrayReplaceValue::undo()
{
  if (!theIsApplied)
  {
    return;
  }

  JSONArray* array = static_cast<JSONArray*>(theTarget.getp());

  array->replace(thePosition, theOldValue);

  theIsApplied = false;
}


#endif

} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
