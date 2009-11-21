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

#include <zorba/exception.h>

#include "zorbaerrors/error_manager.h"

#include "store/api/iterator.h"

#include "store/naive/shared_types.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_pul.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_collection.h"
//#include "store/naive/simple_index.h"


namespace zorba { namespace simplestore {



/*******************************************************************************

********************************************************************************/
void UpdatePrimitive::addNodeForValidation(zorba::store::Item* node)
{
  thePul->theValidationNodes.insert(node);
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
    PULImpl*                         pul,
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    store::Item_t&                   sibling,
    std::vector<store::Item_t>&      children,
    const store::CopyMode&           copymode)
  :
  UpdatePrimitive(pul, target),
  theKind(kind),
  theNumApplied(0)
{
  theSibling.transfer(sibling);

  ulong numNewChildren = 0;
  ulong numChildren = children.size();
  theNewChildren.resize(numChildren);

  for (ulong i = 0; i < numChildren; i++)
  {
    if (i > 0 &&
        children[i]->getNodeKind() == store::StoreConsts::textNode &&
        theNewChildren[i-1]->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* node1 = reinterpret_cast<TextNode*>(theNewChildren[i-1].getp());
      TextNode* node2 = reinterpret_cast<TextNode*>(children[i].getp());

      xqpStringStore_t newText = node1->getText()->append(node2->getText());
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
    PULImpl*                     pul,
    store::Item_t&               target,
    std::vector<store::Item_t>&  attrs,
    const store::CopyMode&       copymode)
  :
  UpdatePrimitive(pul, target),
  theCopyMode(copymode),
  theNumApplied(0)
{
  ulong numAttrs = attrs.size();
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
    PULImpl*                    pul,
    store::Item_t&              target,
    store::Item_t&              attr,
    std::vector<store::Item_t>& newAttrs,
    const store::CopyMode&      copymode)
  :
  UpdatePrimitive(pul, target),
  theCopyMode(copymode),
  theNumApplied(0)
{
  theAttr.transfer(attr);

  ulong numAttrs = newAttrs.size();
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
    PULImpl*                    pul,
    store::Item_t&              target,
    store::Item_t&              child,
    std::vector<store::Item_t>& newChildren,
    const store::CopyMode&      copymode)
  :
  UpdatePrimitive(pul, target),
  theCopyMode(copymode),
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

  ulong numChildren = newChildren.size();
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

  target->theTypeName.transfer(theTypeName);

  if(target->haveTypedTypedValue())
  {
    TextNode* textChild = reinterpret_cast<TextNode*>(target->getChild(0));

    xqpStringStore_t textValue;
    textChild->getStringValue(textValue);
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

      textChild->setTyped(theTypedValue);
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

  target->theTypeName.transfer(theTypeName);
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
    theOldContent.setText(NULL);
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


/*******************************************************************************

********************************************************************************/
void UpdPut::apply()
{
  SimpleStore* store = SimpleStoreManager::getStore();

  try
  {
    // Have to copy because addNode() will set the doc uri of target tree to
    // the uri passed as an arg to fn:put, but the target tree may already
    // have a doc uri, which we should not overwrite. Another reason that we
    // have to copy is that if the target node is an element node, we wrap it
    // with a doc node, but thi not be possible would if the target node
    // has a parent already.
    store::CopyMode copymode;
    copymode.set(true, true, true, true);
    theTarget = theTarget->copy(NULL, 0, copymode);

    if (theTarget->getNodeKind() != store::StoreConsts::documentNode)
    {
      assert(theTarget->getNodeKind() == store::StoreConsts::elementNode);

      ElementNode* elem =  static_cast<ElementNode*>(theTarget.getp());

      DocumentNode* doc = new DocumentNode();
      doc->setTree(elem->getTree());
      doc->setOrdPath(NULL, 1, store::StoreConsts::documentNode);
      
      doc->insertChild(elem, 0);

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
  SimpleStore* store = SimpleStoreManager::getStore();

  store->deleteDocument(theTargetUri->getStringValue());
  store->addNode(theTargetUri->getStringValue(), theOldDocument);
}


/*******************************************************************************
  UpdatePrimitives for collection functions
********************************************************************************/
/*******************************************************************************
  UpdCreateCollection
********************************************************************************/
void UpdCreateCollection::apply()
{
  GET_STORE().createCollection(theCollectionName);
  theIsApplied = true;
}


void UpdCreateCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  if (lColl) 
  {
    GET_STORE().deleteCollection(theCollectionName);
  }
}


/*******************************************************************************
  UpdDropCollection
********************************************************************************/
void UpdDropCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  // save nodes for potential undo
  store::Item_t lTmp = NULL;
  store::Iterator_t lIter = lColl->getIterator(true);
  assert(lIter);

  lIter->open();
  while (lIter->next(lTmp))
    theSavedItems.push_back(lTmp);
  lIter->close();

  GET_STORE().deleteCollection(theCollectionName);
  theIsApplied = true;
}


void UpdDropCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  if (!lColl) {
    GET_STORE().createCollection(theCollectionName); 
#ifndef NDEBUG
    lColl = GET_STORE().getCollection(theCollectionName);
    assert(lColl);
#endif
  }


  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theSavedItems.begin();
       lIter != theSavedItems.end(); ++lIter) 
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
#ifndef NDEBUG
      dynamic_cast<SimpleCollection*>(lColl.getp())->addNode(lIter->getp());
#else
      static_cast<SimpleCollection*>(lColl.getp())->addNode(lIter->getp());
#endif
    }
  }
}


/*******************************************************************************
  UpdInsertIntoCollection
********************************************************************************/
void UpdInsertIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  lColl->addNode(theNodes[0]);

  theIsApplied = true;
}


void UpdInsertIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  // remove the node if it exists
  long lIndex;
  if ( (lIndex = lColl->indexOf(theNodes[0].getp())) != -1 ) 
  {
    lColl->removeNode(lIndex);
  }
}


/*******************************************************************************
  UpdInsertFirstIntoCollection
********************************************************************************/
void UpdInsertFirstIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  for (std::vector<store::Item_t>::reverse_iterator lIter = theNodes.rbegin();
       lIter != theNodes.rend();
       ++lIter) 
  {
    lColl->addNode(*lIter, 1);
  }
}

void UpdInsertFirstIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      lColl->removeNode(lIndex);
    }
  }
}


/*******************************************************************************
  UpdInsertLastIntoCollection
********************************************************************************/
void UpdInsertLastIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    lColl->addNode(*lIter, -1);
  }
}

void UpdInsertLastIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      lColl->removeNode(lIndex);
    }
  }
}


/*******************************************************************************
  UpdInsertBeforeIntoCollection
********************************************************************************/
void UpdInsertBeforeIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter)
  {
    lColl->addNode(*lIter, theTarget, true);
  }
}

void UpdInsertBeforeIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter)
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      lColl->removeNode(lIndex);
    }
  }
}


/*******************************************************************************
  UpdInsertAfterIntoCollection
********************************************************************************/
void UpdInsertAfterIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  for (std::vector<store::Item_t>::reverse_iterator lIter = theNodes.rbegin();
       lIter != theNodes.rend();
       ++lIter) 
  {
    lColl->addNode(*lIter, theTarget, false);
  }
}


void UpdInsertAfterIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter)
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      lColl->removeNode(lIndex);
    }
  }
}


/*******************************************************************************
  UpdInsertAtIntoCollection
********************************************************************************/
void UpdInsertAtIntoCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  ulong lPos = thePos;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    lColl->addNode(*lIter, lPos++);
  }
}

void UpdInsertAtIntoCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      lColl->removeNode(lIndex);
    }
  }
}


/*******************************************************************************
  UpdRemoveNodesFromCollection
********************************************************************************/
void UpdRemoveNodesFromCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    lColl->removeNode(lIter->getp());
  }
}

void UpdRemoveNodesFromCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  long lIndex;
  for (std::vector<store::Item_t>::iterator lIter = theNodes.begin();
       lIter != theNodes.end();
       ++lIter) 
  {
    if ( ( lIndex = lColl->indexOf(lIter->getp())) != -1) 
    {
      static_cast<SimpleCollection*>(lColl.getp())->addNode(lIter->getp());
    }
  }
}


/*******************************************************************************
  UpdRemoveNodeAtFromCollection
********************************************************************************/
void UpdRemoveNodeAtFromCollection::apply()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

  theNode = lColl->nodeAt(thePos);
  assert(theNode);
  lColl->removeNode(thePos);
}

void UpdRemoveNodeAtFromCollection::undo()
{
  store::Collection_t lColl = GET_STORE().getCollection(theCollectionName);
  assert(lColl);

#ifndef NDEBUG
  dynamic_cast<SimpleCollection*>(lColl.getp())->addNode(theNode);
#else
  static_cast<SimpleCollection*>(lColl.getp())->addNode(theNode);
#endif
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
  SimpleStore* store = SimpleStoreManager::getStore();

  theIndex = store->createIndex(theQName, theSpec, theSourceIter);

  theIsApplied = true;
}


void UpdCreateIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = SimpleStoreManager::getStore();

    store->deleteIndex(theQName);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdDropIndex::apply()
{
  SimpleStore* store = SimpleStoreManager::getStore();

  if ((theIndex = store->getIndex(theQName)) == NULL)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_DOES_NOT_EXIST,
                      theQName->getStringValue()->c_str(), "");
  }

  store->deleteIndex(theQName);

  theIsApplied = true;
}


void UpdDropIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = SimpleStoreManager::getStore();

    store->addIndex(theIndex);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdRebuildIndex::apply()
{
  SimpleStore* store = SimpleStoreManager::getStore();

  if ((theIndex = store->getIndex(theQName)) == NULL)
  {
    ZORBA_ERROR_PARAM(STR0002_INDEX_DOES_NOT_EXIST,
                      theQName->getStringValue()->c_str(), "");
  }

  store->deleteIndex(theQName);

  try
  {
    store->createIndex(theQName, theIndex->getSpecification(), theSourceIter);
  }
  catch (...)
  {
    store->addIndex(theIndex);
    throw;
  }

  theIsApplied = true;
}


void UpdRebuildIndex::undo()
{
  if (theIsApplied)
  {
    SimpleStore* store = SimpleStoreManager::getStore();
    store->deleteIndex(theQName);
    store->addIndex(theIndex);
  }
}


}
}

