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

#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_pul.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_atomic_items.h"

#include "store/api/collection.h"

namespace zorba { namespace storeminimal {

/*******************************************************************************

********************************************************************************/
NodeToUpdatesMap::~NodeToUpdatesMap()
{
  ulong n = theHashTab.size();

  for (ulong i = 0; i < n; i++)
  {
    HashEntry<XmlNode*, NodeUpdates*>* entry = &this->theHashTab[i];
    if (entry->theItem != NULL)
    {
      delete entry->theValue;
    }
  }
}


/*******************************************************************************

********************************************************************************/
PULImpl::~PULImpl()
{
  ulong num;

  num = theDoFirstList.size();
  for (ulong i = 0; i < num; i++)
    delete theDoFirstList[i];

  num = theInsertList.size();
  for (ulong i = 0; i < num; i++)
    delete theInsertList[i];

  num = theReplaceNodeList.size();
  for (ulong i = 0; i < num; i++)
    delete theReplaceNodeList[i];

  num = theReplaceContentList.size();
  for (ulong i = 0; i < num; i++)
    delete theReplaceContentList[i];

  num = theDeleteList.size();
  for (ulong i = 0; i < num; i++)
    delete theDeleteList[i];

  num = theValidationList.size();
  for (ulong i = 0; i < num; i++)
    delete theValidationList[i];
}


/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(store::Item_t& target)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdDelete* upd = new UpdDelete(this, target);
    theDeleteList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_DELETE)
        return;
    }

    UpdDelete* upd = new UpdDelete(this, target);
    theDeleteList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addInsertInto(
    store::Item_t&              target,
    std::vector<store::Item_t>& children,
    const store::CopyMode&      copymode)
{
  store::Item_t sibling;

  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO,
                    target, sibling, children, copymode);
}


void PULImpl::addInsertFirst(
    store::Item_t&              target,
    std::vector<store::Item_t>& children,
    const store::CopyMode&      copymode)
{
  store::Item_t sibling;

  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO_FIRST,
                    target, sibling, children, copymode);
}


void PULImpl::addInsertLast(
    store::Item_t&              target,
    std::vector<store::Item_t>& children,
    const store::CopyMode&      copymode)
{
  store::Item_t sibling;

  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO_LAST,
                    target, sibling, children, copymode);
}


void PULImpl::addInsertBefore(
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
{
  store::Item_t parent = target->getParent();

  addInsertChildren(store::UpdateConsts::UP_INSERT_BEFORE,
                    parent, target, siblings, copymode);
}


void PULImpl::addInsertAfter(
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
{
  store::Item_t parent = target->getParent();

  addInsertChildren(store::UpdateConsts::UP_INSERT_AFTER,
                    parent, target, siblings, copymode);
}


void PULImpl::addInsertChildren(
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    store::Item_t&                   sibling,
    std::vector<store::Item_t>&      children,
    const store::CopyMode&           copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertChildren* upd = new UpdInsertChildren(this, kind,
                                                 target, sibling, children,
                                                 copymode);

  if (kind == store::UpdateConsts::UP_INSERT_INTO)
    theDoFirstList.push_back(upd);
  else
    theInsertList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addInsertAttributes(
    store::Item_t&              target,
    std::vector<store::Item_t>& attrs,
    const store::CopyMode&      copymode)
{
  ElementNode* n = ELEM_NODE(target);

  ulong numAttrs = attrs.size();
  for (ulong i = 0; i < numAttrs; i++)
  {
    n->checkNamespaceConflict(attrs[i]->getNodeName(), XUDY0023);
  }

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = new UpdInsertAttributes(this, target, attrs, copymode);
  theDoFirstList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    XmlNode* tmp = reinterpret_cast<XmlNode*>(n);
    theNodeToUpdatesMap.insert(tmp, updates);
  }
  else
  {
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceNode(
    store::Item_t&              target,
    std::vector<store::Item_t>& newNodes,
    const store::CopyMode&      copymode)
{
  XmlNode* n = BASE_NODE(target);

  store::Item_t parent = target->getParent();

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  store::UpdateConsts::UpdPrimKind kind;

  if (target->getNodeKind() == store::StoreConsts::attributeNode)
  {
    upd = new UpdReplaceAttribute(this, parent, target, newNodes, copymode);
    kind = store::UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }
  else
  {
    upd = new UpdReplaceChild(this, parent, target, newNodes, copymode);
    kind = store::UpdateConsts::UP_REPLACE_CHILD;
  }

  if (!found)
  {
    theReplaceNodeList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updates)[i]->getKind() == kind)
      {
        delete upd;
        ZORBA_ERROR(XUDY0016);
      }
    }

    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceContent(
    store::Item_t&         target,
    store::Item_t&         newChild,
    const store::CopyMode& copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdatePrimitive* upd = new UpdReplaceElemContent(this, target, newChild, copymode);
    theReplaceContentList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
        ZORBA_ERROR(XUDY0017);
    }

    UpdatePrimitive* upd = new UpdReplaceElemContent(this, target, newChild, copymode);
    theReplaceContentList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceValue(store::Item_t& target, xqpStringStore_t& newValue)
{
  XmlNode* n = BASE_NODE(target);
  store::StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::attributeNode:
    upd = new UpdReplaceAttrValue(this, target, newValue);
    break;
  case store::StoreConsts::textNode:
    upd = new UpdReplaceTextValue(this, target, newValue);
    break;
  case store::StoreConsts::piNode:
    upd = new UpdReplacePiValue(this, target, newValue);
    break;
  case store::StoreConsts::commentNode:
    upd = new UpdReplaceCommentValue(this, target, newValue);
    break;
  default:
    ZORBA_FATAL(0, "");
  }

  if (!found)
  {
    theDoFirstList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if (store::UpdateConsts::isReplaceValue((*updates)[i]->getKind()))
      {
        delete upd;
        ZORBA_ERROR(XUDY0017);
      }
    }

    theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addRename(store::Item_t& target, store::Item_t& newName)
{
  XmlNode* n = BASE_NODE(target);
  store::StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::elementNode:
  {
    upd = new UpdRenameElem(this, target, newName);
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    upd = new UpdRenameAttr(this, target, newName);
    break;
  }
  case store::StoreConsts::piNode:
  {
    xqpStringStore_t tmp = newName->getStringValue();
    upd = new UpdRenamePi(this, target, tmp);
    break;
  }
  default:
    ZORBA_FATAL(0, "");
  }

  if (!found)
  {
    theDoFirstList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if (store::UpdateConsts::isRename((*updates)[i]->getKind()))
      {
        delete upd;
        ZORBA_ERROR(XUDY0015);
      }
    }

    theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


void PULImpl::addSetElementType(
    store::Item_t&              target,
    store::Item_t&              typeName,
    store::Item_t&              typedValue,
    bool                        haveValue,
    bool                        haveEmptyValue,
    bool                        haveTypedValue,
    bool                        isId,
    bool                        isIdRefs)
{
  UpdatePrimitive* upd = new UpdSetElementType(this, target,
                                               typeName, typedValue,
                                               haveValue, haveEmptyValue,
                                               haveTypedValue, false,
                                               isId, isIdRefs);

  theValidationList.push_back(upd);
}


void PULImpl::addSetElementType(
    store::Item_t&              target,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV,
    bool                        haveValue,
    bool                        haveEmptyValue,
    bool                        haveTypedValue,
    bool                        isId,
    bool                        isIdRefs)
{
  store::Item_t typedValue = new ItemVector(typedValueV);

  UpdatePrimitive* upd = new UpdSetElementType(this, target,
                                               typeName, typedValue,
                                               haveValue, haveEmptyValue,
                                               haveTypedValue, true,
                                               isId, isIdRefs);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    store::Item_t&              target,
    store::Item_t&              typeName,
    store::Item_t&              typedValue,
    bool                        isId,
    bool                        isIdRefs)
{
  UpdatePrimitive* upd = new UpdSetAttributeType(this, target,
                                                 typeName, typedValue, false,
                                                 isId, isIdRefs);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    store::Item_t&              target,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV,
    bool                        isId,
    bool                        isIdRefs)
{
  store::Item_t typedValue = new ItemVector(typedValueV);

  UpdatePrimitive* upd = new UpdSetAttributeType(this, target,
                                                 typeName, typedValue, true,
                                                 isId, isIdRefs);

  theValidationList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeUpdates(store::Item* other)
{
  PULImpl* otherp = reinterpret_cast<PULImpl*>(other);

  mergeUpdateList(theDoFirstList, otherp->theDoFirstList,
                  true, true, false, false, false);

  mergeUpdateList(theInsertList, otherp->theInsertList,
                  false, false, false, false, false);

  mergeUpdateList(theReplaceNodeList, otherp->theReplaceNodeList,
                  false, false, true, false, false);

  mergeUpdateList(theReplaceContentList, otherp->theReplaceContentList,
                  false, false, false, true, false);

  mergeUpdateList(theDeleteList, otherp->theDeleteList,
                  false, false, false, false, true);
}


void PULImpl::mergeUpdateList(
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList,
    bool                           checkRename,
    bool                           checkReplaceValue,
    bool                           checkReplaceNode,
    bool                           checkReplaceContent,
    bool                           checkDelete)
{
  ulong numUpdates;
  ulong numOtherUpdates;

  numUpdates = myList.size();
  numOtherUpdates = otherList.size();

  myList.resize(numUpdates + numOtherUpdates);

  for (ulong i = 0; i < numOtherUpdates; i++)
  {
    UpdatePrimitive* upd = otherList[i];
    upd->thePul = this;

    store::UpdateConsts::UpdPrimKind updKind = upd->getKind();
    XmlNode* target;

    if (updKind == store::UpdateConsts::UP_REPLACE_CHILD)
      target = BASE_NODE(reinterpret_cast<UpdReplaceChild*>(upd)->theChild);
    else
      target = BASE_NODE(upd->theTarget);

    NodeUpdates* targetUpdates;
    bool found = theNodeToUpdatesMap.get(target, targetUpdates);

    if (!found)
    {
      myList[numUpdates + i] = upd;
      otherList[i] = NULL;

      targetUpdates = new NodeUpdates(1);
      (*targetUpdates)[0] = upd;
      theNodeToUpdatesMap.insert(target, targetUpdates);
    }
    else
    {
      if (checkRename && store::UpdateConsts::isRename(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (store::UpdateConsts::isRename((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(XUDY0015);
        }
      }
      else if (checkReplaceValue && store::UpdateConsts::isReplaceValue(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (store::UpdateConsts::isReplaceValue((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(XUDY0017);
        }
      }
      else if (checkReplaceNode && store::UpdateConsts::isReplaceNode(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (store::UpdateConsts::isReplaceNode((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(XUDY0016);
        }
      }
      else if (checkReplaceContent && upd->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
            ZORBA_ERROR(XUDY0017);
        }
      }
      else if (checkDelete && upd->getKind() == store::UpdateConsts::UP_DELETE)
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_DELETE)
            continue;
        }
      }

      myList[numUpdates + i] = upd;
      otherList[i] = NULL;
      targetUpdates->push_back(upd);
    }
  }

  otherList.clear();
}


/*******************************************************************************
  Check that each target node of this pul is inside one of the trees rooted at
  the given root nodes (the root nodes are the copies of the nodes produced by
  the source expr of a transform expr).
********************************************************************************/
void PULImpl::checkTransformUpdates(const std::vector<store::Item*>& rootNodes) const
{
  ulong numRoots = rootNodes.size();

  NodeToUpdatesMap::iterator it = theNodeToUpdatesMap.begin();
  NodeToUpdatesMap::iterator end = theNodeToUpdatesMap.end();

  for (; it != end; ++it)
  {
    const XmlNode* targetNode = (*it).first;

    bool found = false;

    for (ulong i = 0; i < numRoots; i++)
    {
      XmlNode* rootNode = reinterpret_cast<XmlNode*>(rootNodes[i]);

      if (targetNode->getTree() == rootNode->getTree())
      {
        found = true;
        break;
      }
    }

    if (!found)
      ZORBA_ERROR(XUDY0014);
  }
}

#if 0
/*******************************************************************************

********************************************************************************/
void PULImpl::serializeUpdates(serializer& ser, std::ostream& os)
{
  NodeToUpdatesMap::iterator it = theNodeToUpdatesMap.begin();
  NodeToUpdatesMap::iterator end = theNodeToUpdatesMap.end();

  for (; it != end; ++it)
  {
    const XmlNode* target = (*it).first;
    target->getTree()->getRoot()->serializeXML(ser, os);
    os << std::endl << "******************" << std::endl;
  }
}
#endif

/*******************************************************************************

********************************************************************************/
void PULImpl::applyUpdates(std::set<zorba::store::Item*>& validationNodes)
{
  try
  {
    ulong i;
    ulong numUpdates;

    theValidationNodes = &validationNodes;

    // insertInto, insertAttributes, replaceValue, rename
    numUpdates = theDoFirstList.size();
    for (i = 0; i < numUpdates; i++)
      theDoFirstList[i]->apply();

    // insertBefore, insertAfter, insertIntoFirst, insertIntoLast
    numUpdates = theInsertList.size();
    for (i = 0; i < numUpdates; i++)
      theInsertList[i]->apply();

    numUpdates = theReplaceNodeList.size();
    for (i = 0; i < numUpdates; i++)
      theReplaceNodeList[i]->apply();

    numUpdates = theReplaceContentList.size();
    for (i = 0; i < numUpdates; i++)
      theReplaceContentList[i]->apply();

    numUpdates = theDeleteList.size();
    for (i = 0; i < numUpdates; i++)
      theDeleteList[i]->apply();
  }
  catch (error::ZorbaError& e)
  {
#ifndef NDEBUG
    std::cerr << "Exception thrown during pul::applyUpdates: "
              << std::endl <<  e.theDescription << std::endl;
#endif
    //ZORBA_FATAL(0, "");
    undoUpdates();
    throw e;
  }
  catch(...)
  {
    //ZORBA_FATAL(0, "");
    undoUpdates();
    throw;
  }

  try
  {
    store::CopyMode copymode;
    copymode.set(false, true, true, false);

    ulong numUpdates = theReplaceNodeList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdatePrimitive* upd = theReplaceNodeList[i];

      XmlNode* node = BASE_NODE(
                      upd->getKind() == store::UpdateConsts::UP_REPLACE_CHILD ?
                      reinterpret_cast<UpdReplaceChild*>(upd)->theChild :
                      reinterpret_cast<UpdReplaceAttribute*>(upd)->theAttr);

      node->switchTree(NULL, 0, copymode);
    }

    numUpdates = theReplaceContentList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdReplaceElemContent* upd;
      upd = reinterpret_cast<UpdReplaceElemContent*>(theReplaceContentList[i]);

      ulong numChildren = upd->theOldChildren.size();
      for (ulong j = 0; j < numChildren; j++)
      {
        upd->theOldChildren.get(j)->switchTree(NULL, 0, copymode);
      }
    }

    numUpdates = theDeleteList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdDelete* upd = reinterpret_cast<UpdDelete*>(theDeleteList[i]);
      if (upd->theParent != NULL)
      {
        XmlNode* target = BASE_NODE(upd->theTarget);
        target->switchTree(NULL, 0, copymode);
      }
    }
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during pul apply");
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::undoUpdates()
{
  try
  {
    long numUpdates;

    numUpdates = theDeleteList.size();
    for (long i = numUpdates-1; i >= 0; --i)
      if (theDeleteList[i]->theIsApplied)
        theDeleteList[i]->undo();

    numUpdates = theReplaceContentList.size();
    for (long i = numUpdates-1; i >= 0; --i)
      if (theReplaceContentList[i]->theIsApplied)
        theReplaceContentList[i]->undo();

    numUpdates = theReplaceNodeList.size();
    for (long i = numUpdates-1; i >= 0; --i)
      if (theReplaceNodeList[i]->theIsApplied)
        theReplaceNodeList[i]->undo();

    numUpdates = theInsertList.size();
    for (long i = numUpdates-1; i >= 0; --i)
      if (theInsertList[i]->theIsApplied)
        theInsertList[i]->undo();

    numUpdates = theDoFirstList.size();
    for (long i = numUpdates-1; i >= 0; --i)
      if (theDoFirstList[i]->theIsApplied)
        theDoFirstList[i]->undo();
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during pul undo");
  }
}


/*******************************************************************************
  Just disconnect the current target from its parent (if any).
********************************************************************************/
void UpdDelete::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  theParent = target->theParent;

  if (theParent != NULL)
  {
    thePos = target->disconnect();

    store::StoreConsts::NodeKind targetKind = target->getNodeKind();
    if (targetKind == store::StoreConsts::elementNode || 
        targetKind == store::StoreConsts::attributeNode ||
        targetKind == store::StoreConsts::textNode)
      theParent->removeType(*this);
  }

  theIsApplied = true;
}


void UpdDelete::undo()
{
  if (theParent != NULL)
  {
    XmlNode* target = BASE_NODE(theTarget);

    target->connect(theParent, thePos);

    if (!theTypeUndoList.empty())
      target->theParent->restoreType(theTypeUndoList);
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
  theCopyMode(copymode),
  theNumApplied(0)
{
  theSibling.transfer(sibling);

  ulong numChildren = children.size();
  theNewChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
  {
    theNewChildren[i].transfer(children[i]);

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind childKind = theNewChildren[i]->getNodeKind();
      if (childKind == store::StoreConsts::elementNode ||
          childKind == store::StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


void UpdInsertChildren::apply()
{
  theIsApplied = true;

  switch (theKind)
  {
  case store::UpdateConsts::UP_INSERT_INTO:
  {
    XmlNode* target = BASE_NODE(theTarget);
    target->insertChildren(*this, target->numChildren());
    break;
  }
  case store::UpdateConsts::UP_INSERT_INTO_FIRST:
  {
    BASE_NODE(theTarget)->insertChildren(*this, 0);
    break;
  }
  case store::UpdateConsts::UP_INSERT_INTO_LAST:
  {
    XmlNode* target = BASE_NODE(theTarget);
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
    reinterpret_cast<XmlNode*>(theSibling->getParent())->
    undoInsertChildren(*this);
  }
  else
  {
    BASE_NODE(theTarget)->undoInsertChildren(*this);
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
  BASE_NODE(theTarget)->replaceChild(*this);
}


void UpdReplaceChild::undo()
{
  BASE_NODE(theTarget)->restoreChild(*this);
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

  ZORBA_FATAL(target->theTypeName == GET_STORE().theSchemaTypeNames[XS_ANY], "");

  target->theTypeName.transfer(theTypeName);

  if (theHaveValue)
  {
    target->setHaveValue();

    if (theHaveEmptyValue)
      target->setHaveEmptyValue();
    else if (theIsId)
      target->setIsId();
    else if (theIsIdRefs)
      target->setIsIdRefs();

    if (theHaveTypedValue)
    {
      ZORBA_FATAL(target->numChildren() == 1, "");

      TextNode* textChild = reinterpret_cast<TextNode*>(target->getChild(0));

      textChild->setValue(theTypedValue);

      target->setHaveTypedValue();

      if (theHaveListValue)
        target->setHaveListValue();
    }
  }
  else
  {
    target->resetHaveValue();
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


/*******************************************************************************

********************************************************************************/
void UpdSetAttributeType::apply()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->theTypeName.transfer(theTypeName);
  target->theTypedValue.transfer(theTypedValue);

  if (theIsId)
    target->setIsId();
  else if (theIsIdRefs)
    target->setIsIdRefs();

  if (theHaveListValue)
    target->setHaveListValue();
}


/*******************************************************************************

********************************************************************************/
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

}
}
