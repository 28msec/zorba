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
}


/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(store::Item_t& target)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdDelete* upd = new UpdDelete(target);
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

    UpdDelete* upd = new UpdDelete(target);
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
  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO,
                    target, children, copymode);
}


void PULImpl::addInsertFirst(
    store::Item_t&              target,
    std::vector<store::Item_t>& children,
    const store::CopyMode&      copymode)
{
  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO_FIRST,
                    target, children, copymode);
}


void PULImpl::addInsertLast(
    store::Item_t&              target,
    std::vector<store::Item_t>& children,
    const store::CopyMode&      copymode)
{
  addInsertChildren(store::UpdateConsts::UP_INSERT_INTO_LAST,
                    target, children, copymode);
}


void PULImpl::addInsertChildren(
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    std::vector<store::Item_t>&      children,
    const store::CopyMode&           copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertChildren* upd = new UpdInsertChildren(kind, target, children,
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
void PULImpl::addInsertBefore(
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
{
  addInsertSiblings(store::UpdateConsts::UP_INSERT_BEFORE,
                    target, siblings, copymode);
}


void PULImpl::addInsertAfter(
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
{
  addInsertSiblings(store::UpdateConsts::UP_INSERT_AFTER,
                    target, siblings, copymode);
}


void PULImpl::addInsertSiblings(
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertSiblings* upd = new UpdInsertSiblings(kind, target, siblings,
                                                 copymode);
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

  UpdInsertAttributes* upd = new UpdInsertAttributes(target, attrs, copymode);
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
    upd = new UpdReplaceAttribute(parent, target, newNodes, copymode);
    kind = store::UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }
  else
  {
    upd = new UpdReplaceChild(parent, target, newNodes, copymode);
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

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdatePrimitive* upd = new UpdReplaceContent(target, newChild, copymode);
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

    UpdatePrimitive* upd = new UpdReplaceContent(target, newChild, copymode);
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

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::attributeNode:
    upd = new UpdReplaceAttrValue(target, newValue);
    break;
  case store::StoreConsts::textNode:
    upd = new UpdReplaceTextValue(target, newValue);
    break;
  case store::StoreConsts::piNode:
    upd = new UpdReplacePiValue(target, newValue);
    break;
  case store::StoreConsts::commentNode:
    upd = new UpdReplaceCommentValue(target, newValue);
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

  NodeUpdates* updates = 0;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::elementNode:
  {
    upd = new UpdRenameElem(target, newName);
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    upd = new UpdRenameAttr(target, newName);
    break;
  }
  case store::StoreConsts::piNode:
  {
    xqpStringStore_t tmp = newName->getStringValue();
    upd = new UpdRenamePi(target, tmp);
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
void PULImpl::applyUpdates()
{
  try
  {
    ulong i;
    ulong numUpdates;

    numUpdates = theDoFirstList.size();
    for (i = 0; i < numUpdates; i++)
      theDoFirstList[i]->apply();

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
    undoUpdates();
    throw e;
  }
  catch(...)
  {
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

      XmlNode* node = BASE_NODE(upd->getKind() == store::UpdateConsts::UP_REPLACE_CHILD ?
                                reinterpret_cast<UpdReplaceChild*>(upd)->theChild :
                                reinterpret_cast<UpdReplaceAttribute*>(upd)->theAttr);

      node->switchTree(NULL, 0, copymode);
    }

    numUpdates = theReplaceContentList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdReplaceContent* upd;
      upd = reinterpret_cast<UpdReplaceContent*>(theReplaceContentList[i]);

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
      theParent->removeType(theTypeUndoList);
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
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    std::vector<store::Item_t>&      children,
    const store::CopyMode&           copymode)
  :
  UpdatePrimitive(target),
  theKind(kind),
  theDoCopy(copymode.theDoCopy),
  theCopyMode(copymode)
{
  ulong numChildren = children.size();
  theChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
  {
    theChildren[i].transfer(children[i]);

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind childKind = theChildren[i]->getNodeKind();
      if (childKind == store::StoreConsts::elementNode || 
        childKind == store::StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


void UpdInsertChildren::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  if (theKind == store::UpdateConsts::UP_INSERT_INTO)
  {
    target->insertChildren(theChildren,
                           target->numChildren(),
                           theDoCopy,
                           theCopyMode);
  }
  else if (theKind == store::UpdateConsts::UP_INSERT_INTO_FIRST)
  {
    target->insertChildrenFirst(theChildren, theDoCopy, theCopyMode);
  }
  else
  {
    target->insertChildrenLast(theChildren, theDoCopy, theCopyMode);
  }

  if (theRemoveType)
    target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdInsertChildren::undo()
{
  XmlNode* target = BASE_NODE(theTarget);

  ulong pos = target->children().find(BASE_NODE(theChildren[0]));

  target->removeChildren(pos, theChildren.size());

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
UpdInsertSiblings::UpdInsertSiblings(
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t&                   target,
    std::vector<store::Item_t>&      siblings,
    const store::CopyMode&           copymode)
  :
  UpdatePrimitive(target),
  theKind(kind),
  theDoCopy(copymode.theDoCopy),
  theCopyMode(copymode)
{
  ulong numSiblings = siblings.size();
  theSiblings.resize(numSiblings);
  for (ulong i = 0; i < numSiblings; i++)
  {
    theSiblings[i].transfer(siblings[i]);

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind sibKind = theSiblings[i]->getNodeKind();
      if (sibKind == store::StoreConsts::elementNode || 
        sibKind == store::StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


void UpdInsertSiblings::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  if (theKind == store::UpdateConsts::UP_INSERT_BEFORE)
  {
    target->insertSiblingsBefore(theSiblings, theDoCopy, theCopyMode);
  }
  else
  {
    target->insertSiblingsAfter(theSiblings, theDoCopy, theCopyMode);
  }

  if (theRemoveType)
    target->theParent->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdInsertSiblings::undo()
{
  XmlNode* parent = BASE_NODE(theTarget)->theParent;

  ulong pos = parent->children().find(BASE_NODE(theSiblings[0]));

  parent->removeChildren(pos, theSiblings.size());

  if (!theTypeUndoList.empty())
    parent->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
UpdInsertAttributes::UpdInsertAttributes(
    store::Item_t&               target,
    std::vector<store::Item_t>&  attrs,
    const store::CopyMode&       copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copymode.theDoCopy),
  theCopyMode(copymode)
{
  ulong numAttrs = attrs.size();
  theAttributes.resize(numAttrs);
  for (ulong i = 0; i < numAttrs; i++)
    theAttributes[i].transfer(attrs[i]);
}


void UpdInsertAttributes::apply()
{
  ElementNode* target = ELEM_NODE(theTarget);

  target->insertAttributes(theAttributes, theDoCopy, theCopyMode);

  target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdInsertAttributes::undo()
{
  ElementNode* target = ELEM_NODE(theTarget);

  ulong pos = target->attributes().find(BASE_NODE(theAttributes[0]));

  target->removeAttributes(pos, theAttributes.size());

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
UpdReplaceChild::UpdReplaceChild(
    store::Item_t&              target,
    store::Item_t&              child,
    std::vector<store::Item_t>& newChildren,
    const store::CopyMode&      copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copymode.theDoCopy),
  theCopyMode(copymode)
{
  theChild.transfer(child);

  store::StoreConsts::NodeKind childKind = theChild->getNodeKind();
  if (childKind == store::StoreConsts::elementNode || 
    childKind == store::StoreConsts::textNode)
    theRemoveType = true;

  ulong numChildren = newChildren.size();
  theNewChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
  {
    theNewChildren[i].transfer(newChildren[i]);

    if (theRemoveType == false)
    {
      store::StoreConsts::NodeKind childKind = theNewChildren[i]->getNodeKind();
      if (childKind == store::StoreConsts::elementNode || 
        childKind == store::StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


void UpdReplaceChild::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  ulong pos = target->children().find(BASE_NODE(theChild));

  target->replaceChild(theNewChildren, pos, theDoCopy, theCopyMode);

  if (theRemoveType)
    target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceChild::undo()
{
  XmlNode* target = BASE_NODE(theTarget);
  XmlNode* child = BASE_NODE(theChild);

  ulong pos = target->children().find(BASE_NODE(theNewChildren[0]));

  ZORBA_FATAL(pos < target->children().size(), "");

  target->removeChildren(pos, theNewChildren.size());

  child->connect(target, pos);

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
UpdReplaceAttribute::UpdReplaceAttribute(
    store::Item_t&              target,
    store::Item_t&              attr,
    std::vector<store::Item_t>& newAttrs,
    const store::CopyMode&      copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copymode.theDoCopy),
  theCopyMode(copymode)
{
  theAttr.transfer(attr);

  ulong numAttrs = newAttrs.size();
  theNewAttrs.resize(numAttrs);
  for (ulong i = 0; i < numAttrs; i++)
      theNewAttrs[i].transfer(newAttrs[i]);
}


void UpdReplaceAttribute::apply()
{
  ElementNode* target = ELEM_NODE(theTarget);

  ulong pos = target->attributes().find(BASE_NODE(theAttr));

  target->replaceAttribute(theNewAttrs, pos, theDoCopy, theCopyMode);

  target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceAttribute::undo()
{
  ElementNode* target = ELEM_NODE(theTarget);
  XmlNode* attr = BASE_NODE(theAttr);

  ulong pos = target->attributes().find(BASE_NODE(theNewAttrs[0]));

  ZORBA_FATAL(pos < target->attributes().size(), "");

  target->removeAttributes(pos, theNewAttrs.size());

  attr->connect(target, pos);

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceContent::apply()
{
  ElementNode* target = ELEM_NODE(theTarget);

  target->replaceContent(BASE_NODE(theNewChild), theOldChildren, theCopyMode);

  target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceContent::undo()
{
  ElementNode* target = ELEM_NODE(theTarget);

  if (target->numChildren() > 0)
  {
    ZORBA_FATAL(target->numChildren() == 1, "");

    XmlNode* child = target->getChild(0);
 
    child->disconnect();
    child->deleteTree();
  }

  if (dynamic_cast<ElementDagNode*>(target) != NULL)
  {
    ElementDagNode* target1 = reinterpret_cast<ElementDagNode*>(target);
    theOldChildren.copy(target1->theChildren);
  }
  else
  {
    ElementTreeNode* target1 = reinterpret_cast<ElementTreeNode*>(target);
    theOldChildren.copy(target1->theChildren); 
  }

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}

/*******************************************************************************

********************************************************************************/
UpdReplaceAttrValue::~UpdReplaceAttrValue()
{
}

void UpdReplaceAttrValue::apply()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->replaceValue(theNewValue, theOldType, theOldValue, theOldFlags);

  if (target->theParent)
    target->theParent->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceAttrValue::undo()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->restoreValue(theOldType, theOldValue, theOldFlags);

  if (!theTypeUndoList.empty())
    target->theParent->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceTextValue::apply()
{
  TextNode* target = TEXT_NODE(theTarget);

  target->replaceValue(theNewValue, theOldValue);

  if (target->theParent)
    target->theParent->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceTextValue::undo()
{
  TextNode* target = TEXT_NODE(theTarget);

  target->replaceValue(theOldValue, theNewValue);

  if (!theTypeUndoList.empty())
    target->theParent->restoreType(theTypeUndoList);
}


void UpdReplacePiValue::apply()
{
  PI_NODE(theTarget)->replaceValue(theNewValue, theOldValue);

  theIsApplied = true;
}


void UpdReplacePiValue::undo()
{
  PI_NODE(theTarget)->replaceValue(theOldValue, theNewValue);
}


void UpdReplaceCommentValue::apply()
{
  COMMENT_NODE(theTarget)->replaceValue(theNewValue, theOldValue);

  theIsApplied = true;
}


void UpdReplaceCommentValue::undo()
{
  COMMENT_NODE(theTarget)->replaceValue(theOldValue, theNewValue);
}


/*******************************************************************************

********************************************************************************/
void UpdRenameElem::apply()
{
  ELEM_NODE(theTarget)->rename(theNewName, theOldName);

  theIsApplied = true;
}


void UpdRenameElem::undo()
{
  ELEM_NODE(theTarget)->rename(theOldName, theNewName);
}


void UpdRenameAttr::apply()
{
  ATTR_NODE(theTarget)->rename(theNewName, theOldName);

  theIsApplied = true;
}


void UpdRenameAttr::undo()
{
  ATTR_NODE(theTarget)->rename(theOldName, theNewName);
}


void UpdRenamePi::apply()
{
  PI_NODE(theTarget)->rename(theNewName, theOldName);

  theIsApplied = true;
}


void UpdRenamePi::undo()
{
  PI_NODE(theTarget)->rename(theOldName, theNewName);
}

}
}
