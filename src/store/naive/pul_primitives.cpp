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

#include "store/naive/shared_types.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_pul.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_collection.h"
#include "store/naive/node_factory.h"

#include "store/api/iterator.h"
#include "store/api/copymode.h"

#include "zorbaerrors/error_manager.h"

#include <zorba/exception.h>


namespace zorba { namespace simplestore {

#if 0
#define TRACE(msg) std::cout << msg << << std::endl << std::endl;
#else
#define TRACE(msg)
#endif

/*******************************************************************************

********************************************************************************/
UpdatePrimitive::UpdatePrimitive(PULImpl* pul, store::Item_t& target)
  :
  thePul(pul),
  theCollectionPul(NULL),
  theIsApplied(false),
  theRemoveType(false)
{
  theTarget.transfer(target);

  TRACE("Allocated upd : " << this << " in pul : " << thePul);
}


UpdatePrimitive::UpdatePrimitive(CollectionPul* pul, store::Item_t& target)
  :
  thePul(pul->thePul),
  theCollectionPul(pul),
  theIsApplied(false),
  theRemoveType(false)
{
  theTarget.transfer(target);

  TRACE("Allocated upd : " << this << " in pul : " << thePul);
}


UpdatePrimitive::UpdatePrimitive(PULImpl* pul)
  :
  thePul(pul),
  theCollectionPul(NULL),
  theTarget(NULL),
  theIsApplied(false),
  theRemoveType(false)
{
  TRACE("Allocated upd : " << this << " in pul : " << thePul );
}


UpdatePrimitive::UpdatePrimitive(CollectionPul* pul)
  :
  thePul(pul->thePul),
  theCollectionPul(pul),
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
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t& target,
    store::Item_t& sibling,
    std::vector<store::Item_t>& children)
  :
  UpdatePrimitive(pul, target),
  theKind(kind),
  theNumApplied(0)
{
  theSibling.transfer(sibling);

  ulong numNewChildren = 0;
  ulong numChildren = (ulong)children.size();
  theNewChildren.resize(numChildren);

  for (ulong i = 0; i < numChildren; i++)
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
    store::Item_t& target,
    std::vector<store::Item_t>&  attrs)
  :
  UpdatePrimitive(pul, target),
  theNumApplied(0)
{
  ulong numAttrs = (ulong)attrs.size();
  theNewAttrs.resize(numAttrs);
  for (ulong i = 0; i < numAttrs; i++)
    theNewAttrs[i].transfer(attrs[i]);
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
  target->checkUniqueAttrs();
}


/*******************************************************************************

********************************************************************************/
UpdReplaceAttribute::UpdReplaceAttribute(
    CollectionPul* pul,
    store::Item_t& target,
    store::Item_t& attr,
    std::vector<store::Item_t>& newAttrs)
  :
  UpdatePrimitive(pul, target),
  theNumApplied(0)
{
  theAttr.transfer(attr);

  ulong numAttrs = (ulong)newAttrs.size();
  theNewAttrs.resize(numAttrs);
  for (ulong i = 0; i < numAttrs; i++)
      theNewAttrs[i].transfer(newAttrs[i]);
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
  target->checkUniqueAttrs();
}


/*******************************************************************************

********************************************************************************/
UpdReplaceChild::UpdReplaceChild(
    CollectionPul* pul,
    store::Item_t& target,
    store::Item_t& child,
    std::vector<store::Item_t>& newChildren)
  :
  UpdatePrimitive(pul, target),
  theNumApplied(0),
  theIsTyped(false)
{
  theChild.transfer(child);

  store::StoreConsts::NodeKind targetKind = theTarget->getNodeKind();

  store::StoreConsts::NodeKind childKind = theChild->getNodeKind();
  if (targetKind == store::StoreConsts::elementNode &&
      (childKind == store::StoreConsts::elementNode ||
       childKind == store::StoreConsts::textNode))
    theRemoveType = true;

  ulong numChildren = (ulong)newChildren.size();
  theNewChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
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
  theIsApplied = true;
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

  target->setType(theTypeName);

  if (target->haveTypedTypedValue())
  {
    TextNode* textChild = reinterpret_cast<TextNode*>(target->getChild(0));

    zstring textValue;
    textChild->getStringValue2(textValue);

    textChild->setValue(NULL);

    textChild->theFlags &= ~XmlNode::IsTyped;
    textChild->setText(textValue);
  }

  if (theHaveValue)
  {
    target->setHaveValue();

    if (theHaveEmptyValue)
      target->setHaveEmptyValue();

    if (theHaveTypedValue)
    {
      ZORBA_FATAL(target->numChildren() == 1, "");
      ZORBA_FATAL(target->getChild(0)->getNodeKind() == store::StoreConsts::textNode, "");

      TextNode* textChild = reinterpret_cast<TextNode*>(target->getChild(0));

      textChild->setTypedValue(theTypedValue);
      if (theHaveListValue)
        textChild->setHaveListValue();
    }
  }
  else
  {
    target->resetHaveValue();
  }

  if (theIsInSubstitutionGroup)
    target->setInSubstGroup();
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
  if (attr->getParent() != NULL)
  {
    ElementNode* parent = reinterpret_cast<ElementNode*>(attr->getParent());
    parent->checkUniqueAttrs();
  }
}


/*******************************************************************************

********************************************************************************/
void UpdSetAttributeType::apply()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->setType(theTypeName);
  target->theTypedValue.transfer(theTypedValue);

  if (theHaveListValue)
    target->setHaveListValue();
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
  SimpleStore* store = &GET_STORE();

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
    theTarget = theTarget->copy(NULL, copymode);

    if (theTarget->getNodeKind() != store::StoreConsts::documentNode)
    {
      XmlNode* target =  BASE_NODE(theTarget);

      DocumentNode* doc = GET_STORE().getNodeFactory().createDocumentNode();
      doc->setId(target->getTree(), NULL);
      doc->insertChild(target, 0);
      doc->getTree()->setRoot(doc);

      store::Item_t docItem(doc);

      theTarget = docItem;
    }

    store->addNode(theTargetUri->getStringValue(), theTarget);
  }
  catch(error::ZorbaError& e)
  {
    if (e.theErrorCode == API0020_DOCUMENT_ALREADY_EXISTS)
    {
      theOldDocument = store->getDocument(theTargetUri->getStringValue());

      store->deleteDocument(theTargetUri->getStringValue());

      store->addNode(theTargetUri->getStringValue(), theTarget);
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
  SimpleStore* store = &GET_STORE();

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
    store::Item_t& name,
    std::vector<store::Item_t>& nodes)
  :
  UpdatePrimitive(pul)
{
  theName.transfer(name);

  ulong numNodes = (ulong)nodes.size();
  theNodes.resize(numNodes);

  for (ulong i = 0; i < numNodes; ++i)
    theNodes[i].transfer(nodes[i]);
}


UpdCollection::UpdCollection(
    CollectionPul* pul,
    store::Item_t& target,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes)
  :
  UpdatePrimitive(pul, target)
{
  theName.transfer(name);

  ulong numNodes = (ulong)nodes.size();
  theNodes.resize(numNodes);

  for (ulong i = 0; i < numNodes; ++i)
    theNodes[i].transfer(nodes[i]);
}


/*******************************************************************************
  UpdCreateCollection
********************************************************************************/
void UpdCreateCollection::apply()
{
  // Error is raised if collection exists already.
  GET_STORE().createCollection(theName);
  theIsApplied = true;
}


void UpdCreateCollection::undo()
{
  try
  {
    GET_STORE().deleteCollection(theName);
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
  theCollection = GET_STORE().getCollection(theName);
  assert(theCollection);
  SimpleCollection* collection = static_cast<SimpleCollection*>(theCollection.getp());

  std::vector<store::Index*> indexes;
  collection->getIndexes(indexes);

  if (!indexes.empty())
    ZORBA_ERROR_PARAM(XDDY0013_COLLECTION_BAD_DESTROY_INDEXES,
                      collection->getName()->getStringValue(), "");

  std::vector<store::IC*> activeICs;
  collection->getActiveICs(activeICs);

  if (!activeICs.empty())
    ZORBA_ERROR_PARAM(XDDY0014_COLLECTION_BAD_DESTROY_ICS,
                      collection->getName()->getStringValue(), "");

  ulong size = collection->size();
  for (ulong i = 0; i < size; ++i)
  {
    XmlNode* root = static_cast<XmlNode*>(collection->nodeAt(i).getp());
    XmlTree* tree = root->getTree();
    if (tree->getRefCount() > 1)
      ZORBA_ERROR_PARAM(XDDY0015_COLLECTION_BAD_DESTROY_NODES,
                        collection->getName()->getStringValue(), "");
  }

  GET_STORE().deleteCollection(theName);
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
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  theIsApplied = true;

  ulong numNodes = (ulong)theNodes.size();
  for (ulong i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], -1);
    ++theNumApplied;
  }
}


void UpdInsertIntoCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  ulong lastPos = lColl->size()-1;

  for (long i = theNumApplied-1; i >= 0; --i)
  {
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(lastPos));

    lColl->removeNode(lastPos);
    --lastPos;
  }
}


/*******************************************************************************
  UpdInsertFirstIntoCollection
********************************************************************************/
void UpdInsertFirstIntoCollection::apply()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  theIsApplied = true;

  theCollectionPul->setAdjustTreePositions();

  ulong numNodes = (ulong)theNodes.size();
  for (ulong i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], i);
    ++theNumApplied;
  }
}


void UpdInsertFirstIntoCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  for (ulong i = 0; i < theNumApplied; ++i)
  {
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(0));

    lColl->removeNode((ulong)0);
  }
}


/*******************************************************************************
  UpdInsertLastIntoCollection
********************************************************************************/
void UpdInsertLastIntoCollection::apply()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  theIsApplied = true;

  ulong numNodes = (ulong)theNodes.size();
  for (ulong i = 0; i < numNodes; ++i)
  {
    lColl->addNode(theNodes[i], -1);
  }
}


void UpdInsertLastIntoCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  ulong lastPos = lColl->size()-1;

  for (long i = theNumApplied-1; i >= 0; --i)
  {
    ZORBA_ASSERT(theNodes[i] == lColl->nodeAt(lastPos));

    lColl->removeNode(lastPos);
  }
}


/*******************************************************************************
  UpdInsertBeforeIntoCollection
********************************************************************************/
void UpdInsertBeforeIntoCollection::apply()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  if (!theNodes.empty())
    theFirstNode = theNodes[0];

  theCollectionPul->setAdjustTreePositions();

  theFirstPos = lColl->addNodes(theNodes, theTarget, true);

  theIsApplied = true;
}

void UpdInsertBeforeIntoCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);
  ZORBA_ASSERT(theFirstNode == lColl->nodeAt(theFirstPos));

  lColl->removeNodes(theFirstPos, (ulong)theNodes.size());
}


/*******************************************************************************
  UpdInsertAfterIntoCollection
********************************************************************************/
void UpdInsertAfterIntoCollection::apply()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  if (!theNodes.empty())
    theFirstNode = theNodes[0];

  theCollectionPul->setAdjustTreePositions();

  theFirstPos = lColl->addNodes(theNodes, theTarget, false);

  theIsApplied = true;
}


void UpdInsertAfterIntoCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);
  ZORBA_ASSERT(theFirstNode == lColl->nodeAt(theFirstPos));

  lColl->removeNodes(theFirstPos, (ulong)theNodes.size());
}


/*******************************************************************************
  UpdRemoveNodesFromCollection
********************************************************************************/
void UpdDeleteNodesFromCollection::apply()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  theIsApplied = true;

  ulong size = lColl->size();

  ulong numNodes = (ulong)theNodes.size();

  bool isLast = theIsLast;

  if (theIsLast)
  {
    for (ulong i = numNodes; i > 0; --i)
    {
      if (theNodes[i-1] != lColl->nodeAt(size - i))
      {
        isLast = false;
        break;
      }
    }
  }

  if (!isLast)
    theCollectionPul->setAdjustTreePositions();

  theFound.resize(numNodes);
  thePositions.resize(numNodes);

  for (ulong i = 0; i < numNodes; ++i)
  {
    theFound[i] = lColl->removeNode(theNodes[i], thePositions[i]);
    ++theNumApplied;
  }
}

void UpdDeleteNodesFromCollection::undo()
{
  SimpleCollection* lColl = static_cast<SimpleCollection*>
                            (GET_STORE().getCollection(theName).getp());
  assert(lColl);

  for (ulong i = 0; i < theNumApplied; ++i)
  {
    if (theFound[i])
    {
      lColl->addNode(theNodes[i], thePositions[i]);
    }
  }
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
   const store::Item_t& qname,
   const store::IndexSpecification& spec,
   store::Iterator* sourceIter)
  :
  UpdatePrimitive(pul),
  theQName(qname),
  theSpec(spec),
  theSourceIter(sourceIter)
{
}


void UpdCreateIndex::apply()
{
  SimpleStore* store = &GET_STORE();

  try
  {
    theIndex = store->createIndex(theQName, theSpec, theSourceIter);
  }
  catch(error::ZorbaError& e)
  {
    if (e.theErrorCode == STR0045_DUPLICATE_NODE_ERROR)
    {
      ZORBA_ERROR_PARAM(XDDY0028_INDEX_DOMAIN_HAS_DUPLICATE_NODES, 
                        theQName->getStringValue().c_str(), "");
    }

    throw e;
  }

  theIsApplied = true;
}


void UpdCreateIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();

    store->deleteIndex(theQName);
  }
}


/*******************************************************************************

********************************************************************************/
UpdDeleteIndex::UpdDeleteIndex(PULImpl* pul, const store::Item_t& qname)
  :
  UpdatePrimitive(pul),
  theQName(qname)
{
}


void UpdDeleteIndex::apply()
{
  SimpleStore* store = &GET_STORE();

  if ((theIndex = store->getIndex(theQName)) == NULL)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_DOES_NOT_EXIST,
                      theQName->getStringValue().c_str(), "");
  }

  store->deleteIndex(theQName);

  theIsApplied = true;
}


void UpdDeleteIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();

    store->addIndex(theIndex);
  }
}


/*******************************************************************************

********************************************************************************/
UpdRefreshIndex::UpdRefreshIndex(
    PULImpl* pul,
    const store::Item_t& qname,
    store::Iterator* sourceIter)
  :
  UpdatePrimitive(pul),
  theQName(qname),
  theSourceIter(sourceIter)
{
}


UpdRefreshIndex::~UpdRefreshIndex()
{
}


void UpdRefreshIndex::apply()
{
  SimpleStore& store = GET_STORE();

  if ((theIndex = store.getIndex(theQName)) == NULL)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_DOES_NOT_EXIST,
                      theQName->getStringValue().c_str(), "");
  }

  store.refreshIndex(theQName, theIndex->getSpecification(), theSourceIter);

  theIsApplied = true;
}  


void UpdRefreshIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();
    store->deleteIndex(theQName);
    store->addIndex(theIndex);
  }
}


/*******************************************************************************

********************************************************************************/
UpdActivateIC::UpdActivateIC(
    PULImpl* pul,
    const store::Item_t& qname,
    const store::Item_t& aCollectionName)
  :
  UpdatePrimitive(pul),
  theQName(qname),
  theCollectionName(aCollectionName)
{
}


UpdActivateIC::~UpdActivateIC()
{
}


void UpdActivateIC::apply()
{
  SimpleStore* store = &GET_STORE();
  store->activateIC(theQName, theCollectionName);
  theIsApplied = true;
}


void UpdActivateIC::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();
    store->deactivateIC(theQName);
    theIsApplied = false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdActivateForeignKeyIC::UpdActivateForeignKeyIC(
    PULImpl* pul,
    const store::Item_t& aQName,
    const store::Item_t& aFromCollection,
    const store::Item_t& aToCollection)
  :
  UpdatePrimitive(pul),
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
  SimpleStore* store = &GET_STORE();
  store->activateForeignKeyIC(theQName, theFromCollectionName, theToCollectionName);
  theIsApplied = true;
}


void UpdActivateForeignKeyIC::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();
    store->deactivateIC(theQName);
    theIsApplied = false;
  }
}


/*******************************************************************************

********************************************************************************/
UpdDeActivateIC::UpdDeActivateIC(
    PULImpl* pul,
    const store::Item_t& aQName)
  :
  UpdatePrimitive(pul),
  theQName(aQName)
{
}


UpdDeActivateIC::~UpdDeActivateIC()
{
}


void UpdDeActivateIC::apply()
{
  SimpleStore* store = &GET_STORE();
  store::IC_t ic = store->deactivateIC(theQName);
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
  theIsApplied = false;
}


void UpdDeActivateIC::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = &GET_STORE();
    switch (theICKind) {
      case store::IC::ic_collection:
        store->activateIC(theQName, theFromCollectionName);
        break;
      case store::IC::ic_foreignkey:
        store->activateForeignKeyIC(
            theQName,
            theFromCollectionName,
            theToCollectionName);
        break;
      default:
        ZORBA_ASSERT(false);
      // TODO
    }
  }
}

}
}

