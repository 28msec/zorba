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

#include <algorithm>

#include <zorba/exception.h>

#include "zorbaerrors/error_manager.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_index.h"
#include "store/naive/simple_pul.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/node_items.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
NodeToUpdatesMap::~NodeToUpdatesMap()
{
  NodeToUpdatesMap::iterator ite = theMap.begin();
  NodeToUpdatesMap::iterator end = theMap.end();

  for (; ite != end; ++ite)
  {
    delete (*ite).second;
  }
}


/*******************************************************************************

********************************************************************************/
inline void cleanList(std::vector<UpdatePrimitive*> aVector)
{
  std::vector<UpdatePrimitive*>::iterator ite = aVector.begin();
  std::vector<UpdatePrimitive*>::iterator end = aVector.end();

  for (; ite != end; ++ite) 
  {
    delete (*ite);
  }
}


/*******************************************************************************

********************************************************************************/
inline void cleanIndexDelta(PULImpl::IndexDelta& delta)
{
  PULImpl::IndexDelta::iterator ite = delta.begin();
  PULImpl::IndexDelta::iterator end = delta.end();

  for (; ite != end; ++ite)
  {
    if ((*ite).second)
      delete (*ite).second;
  }
}


/*******************************************************************************

********************************************************************************/
PULImpl::PULImpl() : theValidationNodes(NULL) 
{
}


/*******************************************************************************

********************************************************************************/
PULImpl::~PULImpl()
{
  cleanList(theDoFirstList);
  cleanList(theInsertList);
  cleanList(theReplaceNodeList);
  cleanList(theReplaceContentList);
  cleanList(theDeleteList);
  cleanList(thePutList);
  cleanList(theValidationList);
  cleanList(theCreateCollectionList);
  cleanList(theInsertIntoCollectionList);
  cleanList(theDeleteFromCollectionList);
  cleanList(theDropCollectionList);

  ulong numDeltas = theBeforeIndexDeltas.size();

  for (ulong i = 0; i < numDeltas; ++i)
  {
    cleanIndexDelta(theBeforeIndexDeltas[i]);
  }

  numDeltas = theAfterIndexDeltas.size();

  for (ulong i = 0; i < numDeltas; ++i)
  {
    cleanIndexDelta(theAfterIndexDeltas[i]);
  }
}


/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(store::Item_t& target)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = NULL;
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
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
    {
      ulong numNewAttrs = newNodes.size();
      for (ulong i = 0; i < numNewAttrs; ++i)
      {
        elemParent->checkNamespaceConflict(newNodes[i]->getNodeName(), XUDY0023); 
      }
    }

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

  NodeUpdates* updates = NULL;
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

  NodeUpdates* updates = NULL;
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

  NodeUpdates* updates = NULL;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::elementNode:
  {
    ElementNode* elemTarget = ELEM_NODE(target);
    elemTarget->checkNamespaceConflict(newName.getp(), XUDY0023);

    upd = new UpdRenameElem(this, target, newName);
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
      elemParent->checkNamespaceConflict(newName.getp(), XUDY0023);

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


/*******************************************************************************

********************************************************************************/
void PULImpl::addSetElementType(
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& value,
    bool haveValue,
    bool haveEmptyValue,
    bool haveTypedValue,
    bool isInSubstitutionGroup)
{
  UpdatePrimitive* upd = 
  new UpdSetElementType(this,
                        target,
                        typeName,
                        value,
                        haveValue,
                        haveEmptyValue,
                        haveTypedValue,
                        false,
                        isInSubstitutionGroup);

  theValidationList.push_back(upd);
}


void PULImpl::addSetElementType(
    store::Item_t& target,
    store::Item_t& typeName,
    std::vector<store::Item_t>& valueV,
    bool haveValue,
    bool haveEmptyValue,
    bool haveTypedValue,
    bool isInSubstitutionGroup)
{
  store::Item_t typedValue = new ItemVector(valueV);

  UpdatePrimitive* upd =
  new UpdSetElementType(this,
                        target,
                        typeName,
                        typedValue,
                        haveValue,
                        haveEmptyValue,
                        haveTypedValue,
                        true,
                        isInSubstitutionGroup);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue)
{
  UpdatePrimitive* upd = 
  new UpdSetAttributeType(this, target, typeName, typedValue, false);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    store::Item_t&              target,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV)
{
  store::Item_t typedValue = new ItemVector(typedValueV);

  UpdatePrimitive* upd = 
  new UpdSetAttributeType(this, target, typeName, typedValue, true);

  theValidationList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addPut(store::Item_t& target, store::Item_t& uri)
{
  ulong numPuts = thePutList.size();

  for (ulong i = 0; i < numPuts; ++i)
  {
    UpdPut* upd = static_cast<UpdPut*>(thePutList[i]);

    if (upd->theTargetUri == uri)
    {
      ZORBA_ERROR(XUDY0031);
    }
  }

  UpdatePrimitive* upd = new UpdPut(this, target, uri);

  thePutList.push_back(upd);
}


/*******************************************************************************
 collection functions
********************************************************************************/
void PULImpl::addCreateCollection(
    store::Item_t& name)
{
  theCreateCollectionList.push_back(
    new UpdCreateCollection(this, name)
  );
}


void PULImpl::addDropCollection(
    store::Item_t& name)
{
  theDropCollectionList.push_back(
    new UpdDropCollection(this, name)
  );
}


void PULImpl::addInsertIntoCollection(
    store::Item_t& name,
    store::Item_t& node)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertIntoCollection(this, name, node)
  );
} 


void PULImpl::addInsertFirstIntoCollection(
    store::Item_t&              name,
    std::vector<store::Item_t>& nodes)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertFirstIntoCollection(this, name, nodes)
  );
}


void PULImpl::addInsertLastIntoCollection(
    store::Item_t&              name,
    std::vector<store::Item_t>& nodes)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertLastIntoCollection(this, name, nodes)
  );
}


void PULImpl::addInsertBeforeIntoCollection(
    store::Item_t&              name,
    store::Item_t&              target,
    std::vector<store::Item_t>& nodes)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertBeforeIntoCollection(this, name, target, nodes)
  );
}


void PULImpl::addInsertAfterIntoCollection(
    store::Item_t& name,
    store::Item_t& target,
    std::vector<store::Item_t>& nodes)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertAfterIntoCollection(this, name, target, nodes)
  );
}


void PULImpl::addInsertAtIntoCollection(
    store::Item_t& name,
    ulong pos,
    std::vector<store::Item_t>& nodes)
{
  theInsertIntoCollectionList.push_back(
    new UpdInsertAtIntoCollection(this, name, pos, nodes)
  );
}


void PULImpl::addRemoveFromCollection(
    store::Item_t& name,
    std::vector<store::Item_t>& nodes)
{
  theDeleteFromCollectionList.push_back(
    new UpdRemoveNodesFromCollection(this, name, nodes)
  );
}


void PULImpl::addRemoveAtFromCollection(
    store::Item_t& name,
    ulong pos)
{
  theDeleteFromCollectionList.push_back(
    new UpdRemoveNodeAtFromCollection(this, name, pos)
  );
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addCreateIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = new UpdCreateIndex(this, qname, spec, sourceIter);
  theCreateIndexList.push_back(upd);
}


void PULImpl::addDropIndex(const store::Item_t& qname)
{
  UpdatePrimitive* upd = new UpdDropIndex(this, qname);
  theDropIndexList.push_back(upd);
}


void PULImpl::addRebuildIndex(
    const store::Item_t& qname,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = new UpdRebuildIndex(this, qname, sourceIter);
  theRebuildIndexList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeUpdates(store::Item* other)
{
  PULImpl* otherp = reinterpret_cast<PULImpl*>(other);

  mergeUpdateList(theDoFirstList, otherp->theDoFirstList, UP_LIST_DO_FIRST);

  mergeUpdateList(theInsertList, otherp->theInsertList, UP_LIST_NONE);

  mergeUpdateList(theReplaceNodeList,
                  otherp->theReplaceNodeList,
                  UP_LIST_REPLACE_NODE);

  mergeUpdateList(theReplaceContentList,
                  otherp->theReplaceContentList,
                  UP_LIST_REPLACE_CONTENT);

  mergeUpdateList(theDeleteList, otherp->theDeleteList, UP_LIST_DELETE);

  mergeUpdateList(thePutList, otherp->thePutList, UP_LIST_PUT);

  // merge collection functions
  mergeUpdateList(theCreateCollectionList,
                  otherp->theCreateCollectionList,
                  UP_LIST_CREATE_COLLECTION);

  mergeUpdateList(theInsertIntoCollectionList,
                  otherp->theInsertIntoCollectionList,
                  UP_LIST_NONE);

  mergeUpdateList(theDeleteFromCollectionList,
                  otherp->theDeleteFromCollectionList,
                  UP_LIST_NONE);

  mergeUpdateList(theDropCollectionList,
                  otherp->theDropCollectionList,
                  UP_LIST_NONE);

  mergeUpdateList(theCreateIndexList, otherp->theCreateIndexList, UP_LIST_NONE);

  mergeUpdateList(theDropIndexList, otherp->theDropIndexList, UP_LIST_NONE);

  mergeUpdateList(theRebuildIndexList, otherp->theRebuildIndexList, UP_LIST_NONE);
}


void PULImpl::mergeUpdateList(
    std::vector<UpdatePrimitive*>&  myList,
    std::vector<UpdatePrimitive*>&  otherList,
    UpdListKind                     listKind)
{
  ulong numUpdates;
  ulong numOtherUpdates;

  numUpdates = myList.size();
  numOtherUpdates = otherList.size();

  for (ulong i = 0; i < numOtherUpdates; i++)
  {
    if (listKind == UP_LIST_PUT)
    {
      UpdPut* otherUpd = static_cast<UpdPut*>(otherList[i]);

      ulong numPuts = thePutList.size();

      for (ulong j = 0; j < numPuts; ++j)
      {
        UpdPut* upd = static_cast<UpdPut*>(thePutList[j]);

        if (upd->theTargetUri->equals(otherUpd->theTargetUri))
        {
          ZORBA_ERROR(XUDY0031);
        }
      }

      thePutList.push_back(otherUpd);
      otherList[i] = NULL;

      continue;
    }

    if (listKind == UP_LIST_CREATE_COLLECTION) {
      UpdCreateCollection* otherUpd = static_cast<UpdCreateCollection*>(otherList[i]);
      for (size_t j = 0; j < theCreateCollectionList.size(); ++j) {
        if (myList[j]->getKind() == store::UpdateConsts::UP_CREATE_COLLECTION) {
          UpdCreateCollection* upd = static_cast<UpdCreateCollection*>(theCreateCollectionList[j]);
          if (upd->getCollectionName()->equals(otherUpd->getCollectionName())) {
            ZORBA_ERROR(XDDY0013);
          }
        }
      }
    }

    UpdatePrimitive* otherUpd = otherList[i];
    otherUpd->thePul = this;

    store::UpdateConsts::UpdPrimKind updKind = otherUpd->getKind();
    XmlNode* target;

    if (updKind == store::UpdateConsts::UP_REPLACE_CHILD)
      target = BASE_NODE(reinterpret_cast<UpdReplaceChild*>(otherUpd)->theChild);
    else if (updKind == store::UpdateConsts::UP_REPLACE_ATTRIBUTE)
      target = BASE_NODE(reinterpret_cast<UpdReplaceAttribute*>(otherUpd)->theAttr);
    else
      target = BASE_NODE(otherUpd->theTarget);

    NodeUpdates* targetUpdates = NULL;
    bool found = (target == NULL ?
                  false : 
                  theNodeToUpdatesMap.get(target, targetUpdates));

    if (!found)
    {
      myList.push_back(otherUpd);
      otherList[i] = NULL;

      if (target)
      {
        targetUpdates = new NodeUpdates(1);
        (*targetUpdates)[0] = otherUpd;
        theNodeToUpdatesMap.insert(target, targetUpdates);
      }
    }
    else
    {
      switch (listKind)
      {
      case UP_LIST_DO_FIRST:
      {
        if (store::UpdateConsts::isRename(updKind))
        {
          ulong numTargetUpdates = targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; j++)
          {
            if (store::UpdateConsts::isRename((*targetUpdates)[j]->getKind()))
              ZORBA_ERROR(XUDY0015);
          }
        }
        else if (store::UpdateConsts::isReplaceValue(updKind))
        {
          ulong numTargetUpdates = targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; j++)
          {
            if (store::UpdateConsts::isReplaceValue((*targetUpdates)[j]->getKind()))
              ZORBA_ERROR(XUDY0017);
          }
        }
        break;
      }
      case UP_LIST_REPLACE_NODE:
      {
        if (store::UpdateConsts::isReplaceNode(updKind))
        {
          ulong numTargetUpdates = targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; ++j)
          {
            if (store::UpdateConsts::isReplaceNode((*targetUpdates)[j]->getKind()))
              ZORBA_ERROR(XUDY0016);
          }
        }
        break;
      }
      case UP_LIST_REPLACE_CONTENT:
      {
        if (updKind == store::UpdateConsts::UP_REPLACE_CONTENT)
        {
          ulong numTargetUpdates = targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; ++j)
          {
            if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
              ZORBA_ERROR(XUDY0017);
          }
        }
        break;
      }
      case UP_LIST_DELETE:
      {
        if (updKind == store::UpdateConsts::UP_DELETE)
        {
          ulong numTargetUpdates = targetUpdates->size();
          ulong j;
          for (j = 0; j < numTargetUpdates; ++j)
          {
            if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_DELETE)
              break;
          }

          if (j < numTargetUpdates)
            continue;
        }
        break;
      }
      default:
        break;
      }

      myList.push_back(otherUpd);
      otherList[i] = NULL;
      targetUpdates->push_back(otherUpd);
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


/*******************************************************************************
  Find all the indices that may require maintenance. A index is a candidate for
  maintenance if it references at least one collection that has been modified
  (either by adding/removing docs to/from it, or by modifying at least one of
  the docs that belong to that collection already).

  As a side-effect, the method will also collect in theModifiedDocs all the
  collection docs that are modified by this pul.
********************************************************************************/
void PULImpl::getIndicesToRefresh(std::vector<store::Index*>& indices)
{
  SimpleStore* store = SimpleStoreManager::getStore();

  // First, find all the collections that are modified. We also gather all the
  // modified collection docs, because they will be need later to maintain indices.
  std::set<SimpleCollection*> collections;

  NodeToUpdatesMap::iterator ite = theNodeToUpdatesMap.begin();
  NodeToUpdatesMap::iterator end = theNodeToUpdatesMap.end();

  for (; ite != end; ++ite)
  {
    XmlNode* node = (*ite).first;

    SimpleCollection* collection = node->getCollection();

    if (collection != NULL)
    {
      collections.insert(collection);

      theModifiedDocs.insert(node->getRoot());
    }
  }

  // Now go through each index, and check if its sources intersect with the
  // modified collections.
  IndexSet::iterator idxIte = store->getIndices().begin();
  IndexSet::iterator idxEnd = store->getIndices().end();

  for (; idxIte != idxEnd; ++idxIte)
  {
    IndexImpl* index = static_cast<IndexImpl*>((*idxIte).second.getp());
    const store::IndexSpecification& indexSpec = index->getSpecification();

    if (!indexSpec.theIsAutomatic)
      continue;

    const std::vector<store::Item_t>& indexSources = indexSpec.theSources;
    ulong numIndexSources = indexSources.size();

    for (ulong i = 0; i < numIndexSources; ++i)
    {
      std::set<SimpleCollection*>::const_iterator colIte = collections.begin();
      std::set<SimpleCollection*>::const_iterator colEnd = collections.end();

      for (; colIte != colEnd; ++colIte)
      {
        if (indexSources[i]->equals((*colIte)->getName()))
        {
          indices.push_back(index);
          break;
        }
      }

      if (colIte != colEnd)
        break;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addIndexEntryCreator(
    store::Index* idx,
    store::IndexEntryCreator* creator)
{
  theIncrementalIndices.push_back(static_cast<IndexImpl*>(idx));
  theIndexEntryCreators.push_back(creator);
}


static bool cmp(const std::pair<store::Item_t, store::IndexKey*>& e1,
                const std::pair<store::Item_t, store::IndexKey*>& e2)
{
  return e1.first.getp() < e2.first.getp();
}


/*******************************************************************************
  For each incrementally maintained index I and each collection doc D that is
  modified by this pul, compute the index entries for I and D, and insert them
  into the given deltas vector
********************************************************************************/
void PULImpl::computeIndexDeltas(std::vector<IndexDelta>& deltas)
{
  ulong numIncrementalIndices = theIncrementalIndices.size();

  if (numIncrementalIndices == 0)
    return;

  deltas.resize(numIncrementalIndices);

  std::set<XmlNode*>::const_iterator docIte = theModifiedDocs.begin();
  std::set<XmlNode*>::const_iterator docEnd = theModifiedDocs.end();

  for (; docIte != docEnd; ++docIte)
  {
    for (ulong i = 0; i < numIncrementalIndices; ++i)
    {
      store::IndexEntryCreator* docIndexer = theIndexEntryCreators[i].getp();
      IndexDelta& indexDelta = deltas[i];

      std::vector<store::Item_t> domainNodes;
      std::vector<store::IndexKey*> keys;

      docIndexer->createIndexEntries((*docIte), domainNodes, keys);

      ulong numEntries = domainNodes.size();

      indexDelta.resize(numEntries);

      for (ulong j = 0; j < numEntries; ++j)
      {
        indexDelta[j].first.transfer(domainNodes[j]);
        indexDelta[j].second = keys[j];
      }
    }
  }

  for (ulong i = 0; i < numIncrementalIndices; ++i)
  {
    IndexDelta& indexDelta = deltas[i];

    std::sort(indexDelta.begin(), indexDelta.end(), cmp);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::refreshIndices()
{
  ulong numIncrementalIndices = theIncrementalIndices.size();

  for (ulong i = 0; i < numIncrementalIndices; ++i)
  {
    IndexImpl* index = theIncrementalIndices[i];

    HashIndex::CompareFunction keyCmp(index->getNumColumns(),
                                      index->getTimezone(),
                                      index->getCollators());

    IndexDelta& beforeDelta = theBeforeIndexDeltas[i];
    IndexDelta& afterDelta = theAfterIndexDeltas[i];

    IndexDelta::iterator beforeIte = beforeDelta.begin();
    IndexDelta::iterator beforeEnd = beforeDelta.end();
    IndexDelta::iterator afterIte = afterDelta.begin();
    IndexDelta::iterator afterEnd = afterDelta.end();

    while (beforeIte != beforeEnd && afterIte != afterEnd)
    {
      store::Item_t& beforeNode = (*beforeIte).first;
      store::Item_t& afterNode = (*afterIte).first;
      store::IndexKey* beforeKey = (*beforeIte).second;
      store::IndexKey* afterKey = (*afterIte).second;

      if (beforeNode == afterNode)
      {
        if (!keyCmp.equal(beforeKey, afterKey))
        {
          index->remove(beforeKey, beforeNode);
          index->insert(afterKey, afterNode);
          (*afterIte).second = NULL; // ownership of the key was passed to the index
        }

        ++beforeIte;
        ++afterIte;
      }
      else if (beforeNode < afterNode)
      {
        index->remove(beforeKey, beforeNode);
        ++beforeIte;
      }
      else
      {
        index->insert(afterKey, afterNode);
        (*afterIte).second = NULL; // ownership of the key was passed to the index
        ++afterIte;
      }
    }

    while (beforeIte != beforeEnd)
    {
      index->remove((*beforeIte).second, (*beforeIte).first);
      ++beforeIte;
    }

    while (afterIte != afterEnd)
    {
      index->insert((*afterIte).second, (*afterIte).first);
      (*afterIte).second = NULL; // ownership of the key was passed to the index
      ++afterIte;
    }
  }
}


/*******************************************************************************

********************************************************************************/
inline void applyList(std::vector<UpdatePrimitive*> aVector)
{
  for (std::vector<UpdatePrimitive*>::iterator lIter = aVector.begin();
       lIter != aVector.end();
       ++lIter) 
  {
    (*lIter)->apply();
  }
}


void PULImpl::applyUpdates(std::set<zorba::store::Item*>& validationNodes)
{
  // Compute the before-delta for each incrementally maintained index.
  computeIndexDeltas(theBeforeIndexDeltas);

  // Apply all the update primitives
  try
  {
    theValidationNodes = &validationNodes;

    applyList(theDoFirstList);
    applyList(theInsertList);
    applyList(theReplaceNodeList);
    applyList(theReplaceContentList);
    applyList(theDeleteList);
    applyList(theValidationList);

    ulong numToRecheck = thePrimitivesToRecheck.size();
    for (ulong i = 0; i < numToRecheck; ++i)
      thePrimitivesToRecheck[i]->check();

    applyList(thePutList);

    applyList(theCreateCollectionList);
    applyList(theInsertIntoCollectionList);
    applyList(theDeleteFromCollectionList);

    applyList(theRebuildIndexList);

    applyList(theCreateIndexList);
    applyList(theDropIndexList);

    applyList(theDropCollectionList);
  }
  catch (error::ZorbaError& e)
  {
#ifndef NDEBUG
    std::cerr << "Exception thrown during pul::applyUpdates: "
              << std::endl <<  e.theDescription << std::endl;
#endif

    try
    {
      undoUpdates();
    }
    catch (...)
    {
      ZORBA_FATAL(0, "Error during pul::undoUpdates()");
    }

    throw e;
  }
  catch(...)
  {
#ifndef NDEBUG
    std::cerr << "Unknown exception thrown during pul::applyUpdates " << std::endl;
#endif

    try
    {
      undoUpdates();
    }
    catch (...)
    {
      ZORBA_FATAL(0, "Error during pul::undoUpdates()");
    }

    throw;
  }

  // Compute the after-delta for each incrementally maintained index.
  computeIndexDeltas(theAfterIndexDeltas);

  // Refresh each incrementally maintained index using its before and after deltas
  refreshIndices();

  // Detach nodes that were deleted from their trees.
  try
  {
    ulong numUpdates = theReplaceNodeList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdatePrimitive* upd = theReplaceNodeList[i];

      XmlNode* node = BASE_NODE(
                      upd->getKind() == store::UpdateConsts::UP_REPLACE_CHILD ?
                      static_cast<UpdReplaceChild*>(upd)->theChild :
                      static_cast<UpdReplaceAttribute*>(upd)->theAttr);

      // To make the detach() method work properly, we must set the node's
      // parent back to what it used to be.
      node->theParent = INTERNAL_NODE(upd->theTarget);
      node->detach();
    }

    numUpdates = theReplaceContentList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdReplaceElemContent* upd;
      upd = static_cast<UpdReplaceElemContent*>(theReplaceContentList[i]);

      ulong numChildren = upd->theOldChildren.size();
      for (ulong j = 0; j < numChildren; j++)
      {
        XmlNode* node = upd->theOldChildren.get(j);
        node->theParent = INTERNAL_NODE(upd->theTarget);
        node->detach();
      }
    }

    numUpdates = theDeleteList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdDelete* upd = static_cast<UpdDelete*>(theDeleteList[i]);

      if (upd->theParent != NULL)
      {
        XmlNode* target = BASE_NODE(upd->theTarget);
        target->theParent = upd->theParent;
        target->detach();
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
inline void undoList(std::vector<UpdatePrimitive*> aVector)
{
  for ( std::vector<UpdatePrimitive*>::reverse_iterator lIter = aVector.rbegin();
        lIter != aVector.rend();
        ++lIter ) 
  {
    if ((*lIter)->isApplied())
      (*lIter)->undo();
  }
}

void PULImpl::undoUpdates()
{
  try
  {
    undoList(theDropCollectionList);

    undoList(theDropIndexList);
    undoList(theCreateIndexList);

    undoList(theRebuildIndexList);

    undoList(theDeleteFromCollectionList);
    undoList(theInsertIntoCollectionList);
    undoList(theCreateCollectionList);

    undoList(thePutList);

    undoList(theDeleteList);
    undoList(theReplaceContentList);
    undoList(theReplaceNodeList);
    undoList(theInsertList);
    undoList(theDoFirstList);
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during pul undo");
  }
}


}
}
