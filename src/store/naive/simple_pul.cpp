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

#include <algorithm>

#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/util_macros.h"

#include "store_defs.h"
#include "simple_store.h"
#include "collection.h"
#include "simple_index_value.h"
#include "simple_pul.h"
#include "pul_primitives.h"
#include "node_items.h"
#include "json_items.h"
#include "atomic_items.h"
#include "pul_primitive_factory.h"
#include "node_factory.h"

#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/validator.h"
#include "store/api/ic.h"


namespace zorba {
namespace simplestore {


/*******************************************************************************

********************************************************************************/
void cleanList(std::vector<UpdatePrimitive*>& aVector)
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
void cleanIndexDeltas(std::vector<store::IndexDelta>& deltas)
{
  std::vector<store::IndexDelta>::iterator ite = deltas.begin();
  std::vector<store::IndexDelta>::iterator end = deltas.end();

  for (; ite != end; ++ite)
  {
    store::IndexDelta::iterator ite2 = (*ite).begin();
    store::IndexDelta::iterator end2 = (*ite).end();

    for (; ite2 != end2; ++ite2)
    {
      if ((*ite2).second)
        delete (*ite2).second;
    }
  }
}


/*******************************************************************************

********************************************************************************/
void applyList(std::vector<UpdatePrimitive*>& aVector)
{
  std::vector<UpdatePrimitive*>::iterator iter = aVector.begin();
  std::vector<UpdatePrimitive*>::iterator end = aVector.end();

  for (; iter != end; ++iter) 
  {
    (*iter)->apply();
  }
}


/*******************************************************************************

********************************************************************************/
void undoList(std::vector<UpdatePrimitive*>& list)
{
  ulong size = (ulong)list.size();

  for (ulong i = size; i > 0; --i) 
  {
    if (list[i-1]->isApplied())
      list[i-1]->undo();
  }
}


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
PULImpl::PULImpl() 
  :
  PUL(),
  theNoCollectionPul(NULL),
  theLastPul(NULL),
  theLastCollection(NULL),
  theValidator(NULL),
  theInheritNSBindings(false)
{
}


/*******************************************************************************

********************************************************************************/
PULImpl::~PULImpl()
{
  cleanList(thePutList);

  cleanList(theCreateIndexList);
  cleanList(theRefreshIndexList);
  cleanList(theDeleteIndexList);

  cleanList(theValidationList);

  CollectionPulMap::iterator ite = theCollectionPuls.begin();
  CollectionPulMap::iterator end = theCollectionPuls.end();

  for (; ite != end; ++ite)
  {
    if ((*ite).second != NULL)
      delete (*ite).second;
  }
  cleanList(theICActivationList);
  cleanList(theCreateDocumentList);
  cleanList(theDeleteDocumentList);

  cleanList(theCreateHashMapList);
  cleanList(theDestroyHashMapList);
  cleanList(theInsertIntoHashMapList);
  cleanList(theRemoveFromHashMapList);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::setValidator(store::SchemaValidator* validator)
{
  theValidator = validator;
}
  

/*******************************************************************************

********************************************************************************/
CollectionPul* PULImpl::getCollectionPul(const store::Item* target)
{
  const QNameItem* collName;

  assert(target->isNode()
#ifdef ZORBA_WITH_JSON
      || target->isJSONObject()
      || target->isJSONArray()
#endif
      );

  const XmlNode* n = static_cast<const XmlNode*>(target);

  const store::Collection* collection = n->getCollection();

  if (collection != NULL)
  {
    collName = static_cast<const QNameItem*>(collection->getName())->getNormalized();

    if (collName == theLastCollection)
      return theLastPul;

    return getCollectionPulByName(collName, 
                                  collection->isDynamic(),
                                  collection->isJSONIQ());
  }
  else if (theNoCollectionPul != NULL)
  {
    return theNoCollectionPul;
  }
  else if (theCollectionPuls[NULL] != NULL)
  {
    theNoCollectionPul = theCollectionPuls[NULL];
    return theNoCollectionPul;
  }
  else
  {
    theNoCollectionPul = new CollectionPul(this, NULL);
    theCollectionPuls[NULL] = theNoCollectionPul;
    return theNoCollectionPul;
  }
}


CollectionPul* PULImpl::getCollectionPulByName(
    const store::Item* name,
    bool isDynamic,
    bool isJSONIQ)
{
  const QNameItem* collName = static_cast<const QNameItem*>(name)->getNormalized();

  assert(!name->isNode());

  // "name" is the name of a collection.
  if (name == theLastCollection)
    return theLastPul;

  CollectionPulMap::iterator ite = theCollectionPuls.find(collName);

  theLastCollection = collName;

  if (ite != theCollectionPuls.end())
  {
    theLastPul = ite->second;
  }
  else
  {
    Collection* collection = static_cast<Collection*>
      (GET_STORE().getCollection(collName, isDynamic, isJSONIQ).getp());

    theLastPul = new CollectionPul(this, collection);
    theCollectionPuls[collName] = theLastPul;
  }

  return theLastPul;
}



/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(const QueryLoc* aQueryLoc, store::Item_t& target)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = NULL;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdDelete* upd = GET_PUL_FACTORY().createUpdDelete(pul, aQueryLoc, target);
    pul->theDeleteList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    csize numUpdates = updates->size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_DELETE)
        return;
    }

    UpdDelete* upd = GET_PUL_FACTORY().createUpdDelete(pul,  aQueryLoc,target);
    pul->theDeleteList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addInsertInto(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& children)
{
  store::Item_t sibling;
  addInsertChildren(aQueryLoc, 
                    store::UpdateConsts::UP_INSERT_INTO, 
                    target,
                    sibling, 
                    children);
}


void PULImpl::addInsertFirst(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& children)
{
  store::Item_t sibling;
  addInsertChildren(aQueryLoc,
                    store::UpdateConsts::UP_INSERT_INTO_FIRST,
                    target,
                    sibling,
                    children);
}


void PULImpl::addInsertLast(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& children)
{
  store::Item_t sibling;
  addInsertChildren(aQueryLoc, store::UpdateConsts::UP_INSERT_INTO_LAST,
                    target, sibling, children);
}


void PULImpl::addInsertBefore(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& siblings)
{
  store::Item_t p = target->getParent();
  addInsertChildren(aQueryLoc, store::UpdateConsts::UP_INSERT_BEFORE, p, target, siblings);
}


void PULImpl::addInsertAfter(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& siblings)
{
  store::Item_t p = target->getParent();
  addInsertChildren(aQueryLoc, store::UpdateConsts::UP_INSERT_AFTER, p, target, siblings);
}


void PULImpl::addInsertChildren(
    const QueryLoc* aQueryLoc,
    store::UpdateConsts::UpdPrimKind kind,
    store::Item_t& target,
    store::Item_t& sibling,
    std::vector<store::Item_t>& children)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdInsertChildren* upd = GET_PUL_FACTORY().
  createUpdInsertChildren(pul, aQueryLoc, kind, target, sibling, children);

  if (kind == store::UpdateConsts::UP_INSERT_INTO)
    pul->theDoFirstList.push_back(upd);
  else
    pul->theInsertList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addInsertAttributes(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& attrs)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  ElementNode* n = ELEM_NODE(target);

  csize numAttrs = attrs.size();
  for (csize i = 0; i < numAttrs; i++)
  {
    n->checkNamespaceConflict(attrs[i]->getNodeName(), err::XUDY0023);
  }

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = GET_PUL_FACTORY().
  createUpdInsertAttributes(pul, aQueryLoc, target, attrs);

  pul->theDoFirstList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceNode(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    std::vector<store::Item_t>& newNodes)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);

  store::Item_t parent = target->getParent();

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  store::UpdateConsts::UpdPrimKind kind;

  if (target->getNodeKind() == store::StoreConsts::attributeNode)
  {
    ElementNode* elemParent = static_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
    {
      csize numNewAttrs = newNodes.size();
      for (csize i = 0; i < numNewAttrs; ++i)
      {
        elemParent->checkNamespaceConflict(newNodes[i]->getNodeName(), err::XUDY0023); 
      }
    }

    upd = GET_PUL_FACTORY().
          createUpdReplaceAttribute(pul, aQueryLoc, parent, target, newNodes);

    kind = store::UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }
  else
  {
    upd = GET_PUL_FACTORY().
          createUpdReplaceChild(pul, aQueryLoc, parent, target, newNodes);

    kind = store::UpdateConsts::UP_REPLACE_CHILD;
  }

  if (!found)
  {
     updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    csize numUpdates = updates->size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      if ((*updates)[i]->getKind() == kind)
      {
        const QueryLoc* lLoc = upd->theLoc;
        delete upd;
        throw XQUERY_EXCEPTION(err::XUDY0016, ERROR_LOC(*lLoc));
      }
    }

    updates->push_back(upd);
  }

   pul->theReplaceNodeList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceContent(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& newChild)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = NULL;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdReplaceElemContent(pul, aQueryLoc, target, newChild);

    pul->theReplaceContentList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    csize numUpdates = updates->size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
        throw XQUERY_EXCEPTION(err::XUDY0017);
    }

    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdReplaceElemContent(pul, aQueryLoc, target, newChild);

    pul->theReplaceContentList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceValue(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    zstring& newValue)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);
  store::StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates = NULL;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::attributeNode:
  {
    upd = GET_PUL_FACTORY().
    createUpdReplaceAttrValue(pul, aQueryLoc, target, newValue);
    break;
  }
  case store::StoreConsts::textNode:
    upd = GET_PUL_FACTORY().
    createUpdReplaceTextValue(pul, aQueryLoc, target, newValue);
    break;
  case store::StoreConsts::piNode:
    upd = GET_PUL_FACTORY().
    createUpdReplacePiValue(pul, aQueryLoc, target, newValue);
    break;
  case store::StoreConsts::commentNode:
    upd = GET_PUL_FACTORY().
    createUpdReplaceCommentValue(pul, aQueryLoc, target, newValue);
    break;
  default:
    ZORBA_FATAL(0, "");
  }

  if (!found)
  {
    pul->theDoFirstList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    csize numUpdates = updates->size();
    for (csize i = 0; i < numUpdates; i++)
    {
      if (store::UpdateConsts::isReplaceValue((*updates)[i]->getKind()))
      {
        delete upd;
        throw XQUERY_EXCEPTION(err::XUDY0017);
      }
    }

    pul->theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addRename(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& newName)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);
  store::StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates = NULL;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case store::StoreConsts::elementNode:
  {
    ElementNode* elemTarget = ELEM_NODE(target);
    elemTarget->checkNamespaceConflict(newName.getp(), err::XUDY0023);

    upd = GET_PUL_FACTORY().
    createUpdRenameElem(pul, aQueryLoc, target, newName);
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
      elemParent->checkNamespaceConflict(newName.getp(), err::XUDY0023);

    upd = GET_PUL_FACTORY().createUpdRenameAttr(pul, aQueryLoc, target, newName);
    break;
  }
  case store::StoreConsts::piNode:
  {
    zstring tmp;
    newName->getStringValue2(tmp);
    upd = GET_PUL_FACTORY().createUpdRenamePi(pul, aQueryLoc, target, tmp);
    break;
  }
  default:
    ZORBA_FATAL(0, "");
  }

  if (!found)
  {
    pul->theDoFirstList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    csize numUpdates = updates->size();
    for (csize i = 0; i < numUpdates; i++)
    {
      if (store::UpdateConsts::isRename((*updates)[i]->getKind()))
      {
        delete upd;
        throw XQUERY_EXCEPTION(err::XUDY0015);
      }
    }

    pul->theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addPut(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& uri)
{
  csize numPuts = thePutList.size();

  for (csize i = 0; i < numPuts; ++i)
  {
    UpdPut* upd = static_cast<UpdPut*>(thePutList[i]);

    if (upd->theTargetUri == uri)
    {
      throw XQUERY_EXCEPTION(err::XUDY0031, ERROR_PARAMS( uri->getStringValue()));
    }
  }

  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdPut(this, aQueryLoc, target, uri);

  thePutList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addSetElementType(
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& value,
    bool haveValue,
    bool haveEmptyValue,
    bool haveTypedValue,
    bool isInSubstitutionGroup)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdSetElementType(this,
                          aQueryLoc,
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
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& typeName,
    std::vector<store::Item_t>& valueV,
    bool haveValue,
    bool haveEmptyValue,
    bool haveTypedValue,
    bool isInSubstitutionGroup)
{
  store::Item_t typedValue = new ItemVector(valueV);

  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdSetElementType(this,
                          aQueryLoc,
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
    const QueryLoc* loc,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdSetAttributeType(this, loc, target, typeName, typedValue, false);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    const QueryLoc* loc,
    store::Item_t&  target,
    store::Item_t&  typeName,
    std::vector<store::Item_t>& typedValueV)
{
  store::Item_t typedValue = new ItemVector(typedValueV);

  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdSetAttributeType(this, loc, target, typeName, typedValue, true);

  theValidationList.push_back(upd);
}


void PULImpl::addRevalidate(
    const QueryLoc* aQueryLoc,
    store::Item_t& target)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdRevalidate* upd = GET_PUL_FACTORY().
  createUpdRevalidate(this, aQueryLoc, target);

  pul->theRevalidateList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    updates->push_back(upd);
  }
}


/*******************************************************************************
 Collection primitives
********************************************************************************/
void PULImpl::addCreateCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    const std::vector<store::Annotation_t>& annotations,
    const store::Item_t& nodeType,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theCreateCollectionList.push_back(GET_PUL_FACTORY().
  createUpdCreateCollection(pul, loc, name, annotations, nodeType, isDynamic, isJSONIQ));
}


void PULImpl::addDeleteCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theDeleteCollectionList.push_back(GET_PUL_FACTORY().
  createUpdDeleteCollection(pul, loc, name, isDynamic, isJSONIQ));
}


void PULImpl::addInsertIntoCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theInsertIntoCollectionList.push_back(GET_PUL_FACTORY().
  createUpdInsertIntoCollection(pul, loc, name, nodes, isDynamic, isJSONIQ));
} 


void PULImpl::addInsertFirstIntoCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theInsertIntoCollectionList.push_back(GET_PUL_FACTORY().
  createUpdInsertFirstIntoCollection(pul, loc, name, nodes, isDynamic, isJSONIQ));
}


void PULImpl::addInsertLastIntoCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theInsertIntoCollectionList.push_back(GET_PUL_FACTORY().
  createUpdInsertLastIntoCollection(pul, loc, name, nodes, isDynamic, isJSONIQ));
}


void PULImpl::addInsertBeforeIntoCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    store::Item_t& target,
    std::vector<store::Item_t>& nodes,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theInsertIntoCollectionList.push_back(GET_PUL_FACTORY().
  createUpdInsertBeforeIntoCollection(pul, loc, name, target, nodes, isDynamic, isJSONIQ));
}


void PULImpl::addInsertAfterIntoCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    store::Item_t& target,
    std::vector<store::Item_t>& nodes,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theInsertIntoCollectionList.push_back(GET_PUL_FACTORY().
  createUpdInsertAfterIntoCollection(pul, loc, name, target, nodes, isDynamic, isJSONIQ));
}


void PULImpl::addDeleteFromCollection(
    const QueryLoc* loc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isLast,
    bool isDynamic,
    bool isJSONIQ)
{
  CollectionPul* pul = getCollectionPulByName(name.getp(), isDynamic, isJSONIQ);

  pul->theDeleteFromCollectionList.push_back(GET_PUL_FACTORY().
  createUpdDeleteNodesFromCollection(pul, loc, name, nodes, isLast, isDynamic, isJSONIQ));
}


/*******************************************************************************
  Index primitives
********************************************************************************/
void PULImpl::addCreateIndex(
    const QueryLoc* loc,
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdCreateIndex(this, loc,  qname, spec, sourceIter);

  theCreateIndexList.push_back(upd);
}


void PULImpl::addDeleteIndex(
    const QueryLoc* loc,
    const store::Item_t& qname)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdDeleteIndex(this, loc, qname);

  theDeleteIndexList.push_back(upd);
}


void PULImpl::addRefreshIndex(
    const QueryLoc* loc,
    const store::Item_t& qname,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdRefreshIndex(this, loc,  qname, sourceIter);

  theRefreshIndexList.push_back(upd);
}


/*******************************************************************************
  Integrity Constraint Primitives
********************************************************************************/
void PULImpl::addActivateIC(
    const QueryLoc* loc,
      const store::Item_t& qname,
      const store::Item_t& aCollectionName)
{
  UpdatePrimitive* upd = 
  GET_PUL_FACTORY().createUpdActivateIC(this, loc, qname, aCollectionName);

  theICActivationList.push_back(upd);
}

void PULImpl::addActivateForeignKeyIC(
    const QueryLoc* loc,
      const store::Item_t& qname,
      const store::Item_t& aFromCollectionName,
      const store::Item_t& aToCollectionName)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdActivateForeignKeyIC(this,
      loc,
      qname,
      aFromCollectionName,
      aToCollectionName);

  theICActivationList.push_back(upd);
}

void PULImpl::addDeActivateIC(
    const QueryLoc* loc,
      const store::Item_t& qname)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdDeActivateIC(this, loc, qname);

  theICActivationList.push_back(upd);
}


/*******************************************************************************
  Document PULs
********************************************************************************/
void PULImpl::addCreateDocument(
    const QueryLoc* loc,
    const store::Item_t& uri,
    store::Item_t& doc)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdCreateDocument(
      this, loc, uri, doc);
  theCreateDocumentList.push_back(upd);
}


void PULImpl::addDeleteDocument(
    const QueryLoc* loc,
    const store::Item_t& uri)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdDeleteDocument(
      this, loc, uri);
  theDeleteDocumentList.push_back(upd);
}


/*******************************************************************************
  HashMap PULs
********************************************************************************/
void PULImpl::addCreateHashMap(
    const QueryLoc* loc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKeyTypes,
    const std::vector<zstring>& aCollations,
    long  aTimezone)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdCreateHashMap(
      this, loc, aQName, aKeyTypes, aCollations, aTimezone);

  theCreateHashMapList.push_back(upd);
}

void PULImpl::addDestroyHashMap(
    const QueryLoc* loc,
    const store::Item_t& aQName)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdDestroyHashMap(
      this, loc, aQName);

  theDestroyHashMapList.push_back(upd);
}

void PULImpl::addInsertIntoHashMap(
    const QueryLoc* loc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKey,
    const store::Iterator_t& aValue)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdInsertIntoHashMap(
      this, loc, aQName, aKey, aValue);

  theInsertIntoHashMapList.push_back(upd);
}

void PULImpl::addRemoveFromHashMap(
    const QueryLoc* loc,
      const store::Item_t& aQName,
      const std::vector<store::Item_t>& aKey)
{
  UpdatePrimitive* upd = GET_PUL_FACTORY().createUpdRemoveFromHashMap(
      this, loc, aQName, aKey);

  theRemoveFromHashMapList.push_back(upd);
}


#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONObjectInsert(
     const QueryLoc* loc,
     store::Item_t& target,
     std::vector<store::Item_t>& names,
     std::vector<store::Item_t>& values)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  json::JSONObject* obj = static_cast<json::JSONObject*>(target.getp());

  csize numPairs = names.size();

  for (csize i = 0; i < numPairs; ++i)
  {
    if (obj->getPair(names[i]))
    {
      RAISE_ERROR(jerr::JNUP0006, loc, ERROR_PARAMS(names[i]->getStringValue()));
    }

    for (csize j = 0; j < i; ++j)
    {
      if (names[j]->equals(names[i]))
      {
        RAISE_ERROR(jerr::JNUP0005, loc, ERROR_PARAMS(names[i]->getStringValue()));
      }
    }
  }
  
  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(obj, updates);

  // merge object-insert primitives and raise error if duplicate names
  if (found)
  {
    NodeUpdates::iterator ite = updates->begin();
    NodeUpdates::iterator end = updates->end();

    for (; ite != end; ++ite)
    {
      if ((*ite)->getKind() != store::UpdateConsts::UP_JSON_OBJECT_INSERT)
        continue;

      UpdJSONObjectInsert* upd = static_cast<UpdJSONObjectInsert*>(*ite);

      csize numPairs1 = upd->theNames.size();
      csize numPairs2 = names.size();
      csize numPairs = numPairs1;

      upd->theNames.resize(numPairs1 + numPairs2);
      upd->theValues.resize(numPairs1 + numPairs2);

      for (csize i = 0; i < numPairs2; ++i, ++numPairs)
      {
        for (csize j = 0; j < numPairs1; ++j)
        {
          if (names[i]->equals(upd->theNames[j]))
            RAISE_ERROR(jerr::JNUP0005, loc, ERROR_PARAMS(names[i]->getStringValue()));
        }
        
        upd->theNames[numPairs].transfer(names[i]);
        upd->theValues[numPairs].transfer(values[i]);
      }
      
      return;
    }

    UpdatePrimitive* upd =  GET_PUL_FACTORY().
    createUpdJSONObjectInsert(pul, loc, target, names, values);

    pul->theJSONObjectInsertList.push_back(upd);

    updates->push_back(upd);
  }
  else
  {
    UpdatePrimitive* upd =  GET_PUL_FACTORY().
    createUpdJSONObjectInsert(pul, loc, target, names, values);

    pul->theJSONObjectInsertList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(obj, updates);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONObjectDelete(
   const QueryLoc* loc,
   store::Item_t& target,
   store::Item_t& name)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  json::JSONObject* obj = static_cast<json::JSONObject*>(target.getp());

  if (!obj->getPair(name))
  {
    RAISE_ERROR(jerr::JNUP0007, loc, ERROR_PARAMS(name->getStringValue()));
  }

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(obj, updates);

  // skip deletions with duplicate names
  if (found)
  {
    NodeUpdates::iterator ite = updates->begin();
    NodeUpdates::iterator end = updates->end();

    for (; ite != end; ++ite)
    {
      if ((*ite)->getKind() != store::UpdateConsts::UP_JSON_OBJECT_DELETE)
        continue;

      UpdJSONObjectDelete* upd = static_cast<UpdJSONObjectDelete*>(*ite);

      if (upd->theName->equals(name))
        return;
    }

    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectDelete(pul, loc, target, name);

    pul->theJSONObjectDeleteList.push_back(upd);

    updates->push_back(upd);
  }
  else
  {
    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectDelete(pul, loc, target, name);

    pul->theJSONObjectDeleteList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(obj, updates);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONObjectReplaceValue(
     const QueryLoc* loc,
     store::Item_t& target,
     store::Item_t& name,
     store::Item_t& newValue)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  json::JSONObject* obj = static_cast<json::JSONObject*>(target.getp());

  if (!obj->getPair(name))
  {
    RAISE_ERROR(jerr::JNUP0009, loc, ERROR_PARAMS(name->getStringValue()));
  }

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(obj, updates);

  // raise error if duplicate names
  if (found)
  {
    NodeUpdates::iterator ite = updates->begin();
    NodeUpdates::iterator end = updates->end();

    for (; ite != end; ++ite)
    {
      if ((*ite)->getKind() != store::UpdateConsts::UP_JSON_OBJECT_REPLACE_VALUE)
        continue;

      UpdJSONObjectReplaceValue* upd = static_cast<UpdJSONObjectReplaceValue*>(*ite);

      if (name->equals(upd->theName))
        RAISE_ERROR(jerr::JNUP0008, loc, ERROR_PARAMS(name->getStringValue()));
    }

    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectReplaceValue(pul, loc, target, name, newValue);

    pul->theJSONObjectReplaceValueList.push_back(upd);

    updates->push_back(upd);
  }
  else
  {
    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectReplaceValue(pul, loc, target, name, newValue);

    pul->theJSONObjectReplaceValueList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(obj, updates);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONObjectRename(
     const QueryLoc* loc,
     store::Item_t& target,
     store::Item_t& name,
     store::Item_t& newName)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  json::JSONObject* obj = static_cast<json::JSONObject*>(target.getp());

  if (!obj->getPair(name))
  {
    RAISE_ERROR(jerr::JNUP0011, loc, ERROR_PARAMS(name->getStringValue()));
  }

  if (obj->getPair(newName))
  {
    RAISE_ERROR(jerr::JNUP0012, loc, ERROR_PARAMS(newName->getStringValue()));
  }

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(obj, updates);

  // raise error if duplicate names
  if (found)
  {
    NodeUpdates::iterator ite = updates->begin();
    NodeUpdates::iterator end = updates->end();
  
    for (; ite != end; ++ite)
    {
      if ((*ite)->getKind() != store::UpdateConsts::UP_JSON_OBJECT_RENAME)
        continue;

      UpdJSONObjectRename* upd = static_cast<UpdJSONObjectRename*>(*ite);

      if (name->equals(upd->theName))
        RAISE_ERROR(jerr::JNUP0010, loc, ERROR_PARAMS(name->getStringValue()));
    }

    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectRename(pul, loc, target, name, newName);

    pul->theJSONObjectRenameList.push_back(upd);

    updates->push_back(upd);
  }
  else
  {
    UpdatePrimitive* upd = GET_PUL_FACTORY().
    createUpdJSONObjectRename(pul, loc, target, name, newName);

    pul->theJSONObjectRenameList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(obj, updates);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONArrayInsert(
     const QueryLoc* loc,
     store::Item_t& target,
     xs_integer& pos,
     std::vector<store::Item_t>& members)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  json::JSONArray* arr = static_cast<json::JSONArray*>(target.getp());

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(arr, updates);

  // merge array-insert primitives
  if (found)
  {
    NodeUpdates::iterator ite = updates->begin();
    NodeUpdates::iterator end = updates->end();

    for (; ite != end; ++ite)
    {
      if ((*ite)->getKind() != store::UpdateConsts::UP_JSON_ARRAY_INSERT)
        continue;

      UpdJSONArrayInsert* insUpd = static_cast<UpdJSONArrayInsert*>(*ite);

      if (insUpd->thePosition != pos)
        continue;

      csize numMembers1 = insUpd->theMembers.size();
      csize numMembers2 = members.size();
      csize numMembers = numMembers1;

      insUpd->theMembers.resize(numMembers1 + numMembers2);

      for (csize i = 0; i < numMembers2; ++i, ++numMembers)
      {
        insUpd->theMembers[numMembers].transfer(members[i]);
      }

      return;
    }
  }

  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdJSONArrayInsert(pul, loc, target, pos, members);

  pul->theJSONArrayInsertList.push_back(upd);

  updates = new NodeUpdates(1);
  (*updates)[0] = upd;
  pul->theNodeToUpdatesMap.insert(arr, updates);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONArrayDelete(
   const QueryLoc* loc,
   store::Item_t& target,
   xs_integer& pos)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdJSONArrayDelete(pul, loc, target, pos);

  pul->theJSONArrayDeleteList.push_back(upd);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addJSONArrayReplaceValue(
     const QueryLoc* loc,
     store::Item_t& target,
     xs_integer& pos,
     store::Item_t& newValue)
{
  CollectionPul* pul = getCollectionPul(target.getp());

  UpdatePrimitive* upd = GET_PUL_FACTORY().
  createUpdJSONArrayReplaceValue(pul, loc, target, pos, newValue);

  pul->theJSONArrayReplaceValueList.push_back(upd);
}

#endif // ZORBA_WITH_JSON


/*******************************************************************************
  Merge PULs
********************************************************************************/
void PULImpl::mergeUpdates(store::Item* other)
{
  PULImpl* otherp = reinterpret_cast<PULImpl*>(other);

  // Merge collection-specific primitives
  CollectionPulMap::iterator thisIte = theCollectionPuls.begin();
  CollectionPulMap::iterator thisEnd = theCollectionPuls.end();
  CollectionPulMap::iterator otherIte = otherp->theCollectionPuls.begin();
  CollectionPulMap::iterator otherEnd = otherp->theCollectionPuls.end();

  while (thisIte != thisEnd && otherIte != otherEnd)
  {
    if (thisIte->first == otherIte->first)
    {
      CollectionPul* thisPul = thisIte->second;
      CollectionPul* otherPul = otherIte->second;

      // Merge XQUF primitives
      mergeTargetedUpdateLists(thisPul,
                               thisPul->theDoFirstList,
                               otherPul->theDoFirstList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theInsertList,
                               otherPul->theInsertList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theReplaceNodeList,
                               otherPul->theReplaceNodeList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theReplaceContentList,
                               otherPul->theReplaceContentList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theDeleteList,
                               otherPul->theDeleteList);

      // Merge revalidation primitives
      mergeCollectionUpdateLists(thisPul,
                                 thisPul->theRevalidateList,
                                 otherPul->theRevalidateList);

      // Merge collection primitives
      mergeCollectionUpdateLists(thisPul,
                                 thisPul->theCreateCollectionList,
                                 otherPul->theCreateCollectionList);

      mergeCollectionUpdateLists(thisPul,
                                 thisPul->theInsertIntoCollectionList,
                                 otherPul->theInsertIntoCollectionList);

      mergeCollectionUpdateLists(thisPul,
                                 thisPul->theDeleteFromCollectionList,
                                 otherPul->theDeleteFromCollectionList);

      mergeCollectionUpdateLists(thisPul,
                                 thisPul->theDeleteCollectionList,
                                 otherPul->theDeleteCollectionList);

#ifdef ZORBA_WITH_JSON
      // merge jsoniq primitives
      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONObjectInsertList,
                               otherPul->theJSONObjectInsertList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONObjectDeleteList,
                               otherPul->theJSONObjectDeleteList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONObjectReplaceValueList,
                               otherPul->theJSONObjectReplaceValueList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONObjectRenameList,
                               otherPul->theJSONObjectRenameList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONArrayInsertList,
                               otherPul->theJSONArrayInsertList);
      
      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONArrayDeleteList,
                               otherPul->theJSONArrayDeleteList);

      mergeTargetedUpdateLists(thisPul,
                               thisPul->theJSONArrayReplaceValueList,
                               otherPul->theJSONArrayReplaceValueList);
#endif

      ++thisIte;
      ++otherIte;
    }
    else if (thisIte->first < otherIte->first)
    {
      ++thisIte;
    }
    else
    {
      theCollectionPuls[otherIte->first] = otherIte->second;
      otherIte->second->thePul = this;
      otherIte->second = NULL;
      ++otherIte;
    }
  }

  while (otherIte != otherEnd)
  {
    theCollectionPuls[otherIte->first] = otherIte->second;
    otherIte->second->switchPul(this);
    otherIte->second = NULL;
    ++otherIte;
  }

  // Merge fn:put primitives
  mergeSimpleUpdateLists(thePutList, otherp->thePutList);

  // merge index and IC primitives
  mergeSimpleUpdateLists(theCreateIndexList, otherp->theCreateIndexList);

  mergeSimpleUpdateLists(theDeleteIndexList, otherp->theDeleteIndexList);

  mergeSimpleUpdateLists(theRefreshIndexList, otherp->theRefreshIndexList);

  mergeSimpleUpdateLists(theICActivationList, otherp->theICActivationList);

  // merge document primitives
  mergeSimpleUpdateLists(theCreateDocumentList, otherp->theCreateDocumentList);

  mergeSimpleUpdateLists(theDeleteDocumentList, otherp->theDeleteDocumentList);

  // merge hashmap primitives
  mergeSimpleUpdateLists(theCreateHashMapList, otherp->theCreateHashMapList);

  mergeSimpleUpdateLists(theDestroyHashMapList, otherp->theDestroyHashMapList);

  mergeSimpleUpdateLists(theInsertIntoHashMapList, otherp->theInsertIntoHashMapList);

  mergeSimpleUpdateLists(theRemoveFromHashMapList, otherp->theRemoveFromHashMapList);

  // merge validation primitives
  mergeSimpleUpdateLists(theValidationList, otherp->theValidationList);
}


#ifdef ZORBA_WITH_JSON
/*******************************************************************************

********************************************************************************/
void PULImpl::mergeJSONUpdateList(
    CollectionPul* myPul,
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList,
    UpdListKind listKind)
{
  csize numUpdates = myList.size();
  csize numOtherUpdates = otherList.size();

  for (csize i = 0; i < numOtherUpdates; ++i)
  {
    bool inserted = false;
    UpdatePrimitive* otherUpd = otherList[i];

    switch (listKind)
    {
    case UP_LIST_JSON_ARRAY_INSERT:
    {
      for (csize j = 0; j < numUpdates; ++j)
      {
        UpdJSONArrayInsert* myUpd = static_cast<UpdJSONArrayInsert*>(myList[j]);
        UpdJSONArrayInsert* otherUpd = static_cast<UpdJSONArrayInsert*>(otherList[i]);

        if (myUpd->theTarget == otherUpd->theTarget &&
            myUpd->thePosition == otherUpd->thePosition)
        {
          csize myNumMembers = myUpd->theMembers.size();
          csize otherNumMembers = otherUpd->theMembers.size();

          myUpd->theMembers.resize(myNumMembers + otherNumMembers);

          for (csize i = 0; i < otherNumMembers; ++i)
          {
            myUpd->theMembers[myNumMembers + i].transfer(otherUpd->theMembers[i]);
          }

          inserted = true;
        }
      }
      break;
    }
    case UP_LIST_JSON_DELETE:
    {
      /*
      UpdJSONArrayDelete* lOther = static_cast<UpdJSONArrayDelete*>(otherUpd);
      if (!lOther->theTarget->isJSONObject())
      {
        for (csize j = 0; j < numUpdates; ++j)
        {
          UpdJSONArrayDelete* lThis = static_cast<UpdJSONArrayDelete*>(myList[j]);
          if (lThis->theTarget->isJSONObject() ||
              lThis->theDeletee->getIntegerValue() > lOther->theDeletee->getIntegerValue())
          {
            break;
          }
          myList.insert(myList.begin() + j, lOther); 
          otherList[i] = NULL;
          inserted = true;
        }
      }
      */
      break;
    }
    default:
      break;
    }

    if (!inserted)
    {
      otherUpd->thePul = this;
      otherUpd->theCollectionPul = myPul;
      myList.push_back(otherUpd);
      otherList[i] = NULL;
    }
  }

  otherList.clear();
}
#endif


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeSimpleUpdateLists(
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList)
{
  csize numUpdates = myList.size();
  csize numOtherUpdates = otherList.size();

  myList.reserve(numUpdates + numOtherUpdates);

  for (csize i = 0; i < numOtherUpdates; ++i)
  {
    UpdatePrimitive* otherUpd = otherList[i];
    otherUpd->thePul = this;

    myList.push_back(otherUpd);
    otherList[i] = NULL;

    store::UpdateConsts::UpdPrimKind otherUpdKind = otherUpd->getKind();

    switch (otherUpdKind)
    {
    case store::UpdateConsts::UP_CREATE_INDEX:
    {
      UpdCreateIndex* otherUpd2 = static_cast<UpdCreateIndex*>(otherUpd);

      for (csize j = 0; j < numUpdates; ++j) 
      {
        UpdCreateIndex* myUpd = static_cast<UpdCreateIndex*>(myList[j]);

        if (myUpd->getName()->equals(otherUpd2->getName())) 
        {
          RAISE_ERROR(zerr::ZDDY0027_INDEX_MULTIPLE_CREATES, otherUpd->theLoc,
          ERROR_PARAMS(myUpd->getName()->getStringValue()));
        }
      }
    }
    case store::UpdateConsts::UP_PUT:
    {
      UpdPut* otherUpd2 = static_cast<UpdPut*>(otherUpd);

      for (csize j = 0; j < numUpdates; ++j)
      {
        UpdPut* myUpd = static_cast<UpdPut*>(myList[j]);
      
      if (myUpd->theTargetUri->equals(otherUpd2->theTargetUri))
      {
        RAISE_ERROR(err::XUDY0031, otherUpd->theLoc,
        ERROR_PARAMS(myUpd->theTargetUri->getStringValue()));
      }
    }
    }
    default:
      break;
    }
  }

  otherList.clear();
}


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeTargetedUpdateLists(
    CollectionPul* myPul,
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList)
{
  csize numUpdates = myList.size();
  csize numOtherUpdates = otherList.size();

  myList.reserve(numUpdates + numOtherUpdates);

  for (csize i = 0; i < numOtherUpdates; ++i)
  {
    UpdatePrimitive* otherUpd = otherList[i];
    otherUpd->thePul = this;
    otherUpd->theCollectionPul = myPul;

    myList.push_back(otherUpd);
    otherList[i] = NULL;  

    store::UpdateConsts::UpdPrimKind otherUpdKind = otherUpd->getKind();

    // Get the target and see if myPul has any other updates on the same target
    store::Item* target = otherUpd->theTarget.getp();

    if (otherUpdKind == store::UpdateConsts::UP_REPLACE_CHILD)
      target = static_cast<UpdReplaceChild*>(otherUpd)->theChild.getp();
    else if (otherUpdKind == store::UpdateConsts::UP_REPLACE_ATTRIBUTE)
      target = static_cast<UpdReplaceAttribute*>(otherUpd)->theAttr.getp();

    NodeUpdates* targetUpdates = NULL;
    bool found = myPul->theNodeToUpdatesMap.get(target, targetUpdates);

    if (!found)
    {
      targetUpdates = new NodeUpdates(1);
      (*targetUpdates)[0] = otherUpd;
      
      myPul->theNodeToUpdatesMap.insert(target, targetUpdates);
    }
    else
    {
      bool merged = false;

      switch (otherUpdKind)
      {
      case store::UpdateConsts::UP_RENAME_ELEM:
      case store::UpdateConsts::UP_RENAME_ATTR:
      case store::UpdateConsts::UP_RENAME_PI:

      case store::UpdateConsts::UP_REPLACE_CHILD:
      case store::UpdateConsts::UP_REPLACE_ATTRIBUTE:

      case store::UpdateConsts::UP_REPLACE_ATTR_VALUE:
      case store::UpdateConsts::UP_REPLACE_TEXT_VALUE:
      case store::UpdateConsts::UP_REPLACE_PI_VALUE:
      case store::UpdateConsts::UP_REPLACE_COMMENT_VALUE:

      case store::UpdateConsts::UP_REPLACE_CONTENT:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() == otherUpdKind)
          {
            if (store::UpdateConsts::isRename(otherUpdKind))
              RAISE_ERROR_NO_PARAMS(err::XUDY0015, otherUpd->theLoc);

            else if (store::UpdateConsts::isReplaceNode(otherUpdKind))
              RAISE_ERROR_NO_PARAMS(err::XUDY0016, otherUpd->theLoc);

            else 
              RAISE_ERROR_NO_PARAMS(err::XUDY0017, otherUpd->theLoc);
          }
        }

        break;
      }

      case store::UpdateConsts::UP_DELETE:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() == otherUpdKind)
          {
            merged = true;
            break;
          }
        }
        
        break;
      }

#ifdef ZORBA_WITH_JSON
      // merge object-insert primitives and raise error if duplicate names
      case store::UpdateConsts::UP_JSON_OBJECT_INSERT:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() != otherUpdKind)
            continue;
          
          UpdJSONObjectInsert* myUpd = static_cast<UpdJSONObjectInsert*>(*ite);
          UpdJSONObjectInsert* otherUpd2 = static_cast<UpdJSONObjectInsert*>(otherUpd);

          csize numMyPairs = myUpd->theNames.size();
          csize numOtherPairs = otherUpd2->theNames.size();
          csize numPairs = numMyPairs;

          myUpd->theNames.resize(numMyPairs + numOtherPairs);
          myUpd->theValues.resize(numMyPairs + numOtherPairs);

          for (csize i = 0; i < numOtherPairs; ++i, ++numPairs)
          {
            for (csize j = 0; j < numMyPairs; ++j)
            {
              if (otherUpd2->theNames[i]->equals(myUpd->theNames[j]))
                RAISE_ERROR(jerr::JNUP0005, otherUpd->theLoc,
                ERROR_PARAMS(myUpd->theNames[j]->getStringValue()));
            }
        
            myUpd->theNames[numPairs].transfer(otherUpd2->theNames[i]);
            myUpd->theValues[numPairs].transfer(otherUpd2->theValues[i]);
          }

          merged = true;
          break;
        }

        break;
      }

      // skip deletions with duplicate names
      case store::UpdateConsts::UP_JSON_OBJECT_DELETE:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() != otherUpdKind)
            continue;
          
          UpdJSONObjectDelete* myUpd = static_cast<UpdJSONObjectDelete*>(*ite);
          UpdJSONObjectDelete* otherUpd2 = static_cast<UpdJSONObjectDelete*>(otherUpd);

          if (myUpd->theName->equals(otherUpd2->theName))
          {
            merged = true;
            break;
          }
        }

        break;
      }

      // raise error if duplicate names
      case store::UpdateConsts::UP_JSON_OBJECT_REPLACE_VALUE:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() != otherUpdKind)
            continue;
          
          UpdJSONObjectReplaceValue* myUpd = 
          static_cast<UpdJSONObjectReplaceValue*>(*ite);
          UpdJSONObjectReplaceValue* otherUpd2 = 
          static_cast<UpdJSONObjectReplaceValue*>(otherUpd);

          if (myUpd->theName->equals(otherUpd2->theName))
          {
            RAISE_ERROR(jerr::JNUP0008, otherUpd->theLoc, 
            ERROR_PARAMS(myUpd->theName->getStringValue()));
          }
        }

        break;
      }

      // raise error if duplicate names
      case store::UpdateConsts::UP_JSON_OBJECT_RENAME:
      {
        NodeUpdates::iterator ite = targetUpdates->begin();
        NodeUpdates::iterator end = targetUpdates->end();

        for (; ite != end; ++ite)
        {
          if ((*ite)->getKind() != otherUpdKind)
            continue;
          
          UpdJSONObjectRename* myUpd = static_cast<UpdJSONObjectRename*>(*ite);
          UpdJSONObjectRename* otherUpd2 = static_cast<UpdJSONObjectRename*>(otherUpd);

          if (myUpd->theName->equals(otherUpd2->theName))
          {
            RAISE_ERROR(jerr::JNUP0010, otherUpd->theLoc, 
            ERROR_PARAMS(myUpd->theName->getStringValue()));
          }
        }

        break;
      }
#endif

      default:
        break;
      }

      if (merged)
      {
        delete otherUpd;
        myList.pop_back();
      }
      else
      {
        targetUpdates->push_back(otherUpd);
      }
    } // target has other updates in this pul
  } // for each primitive in other list

  otherList.clear();
}


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeCollectionUpdateLists(
    CollectionPul* myPul,
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList)
{
  csize numUpdates = myList.size();
  csize numOtherUpdates = otherList.size();

  myList.reserve(numUpdates + numOtherUpdates);

  for (csize i = 0; i < numOtherUpdates; ++i)
  {
    UpdatePrimitive* otherUpd = otherList[i];
    otherUpd->thePul = this;
    otherUpd->theCollectionPul = myPul;

    myList.push_back(otherUpd);
    otherList[i] = NULL;  

    store::UpdateConsts::UpdPrimKind otherUpdKind = otherUpd->getKind();

    if (otherUpdKind == store::UpdateConsts::UP_CREATE_COLLECTION) 
    {
      UpdCreateCollection* otherUpd2 = static_cast<UpdCreateCollection*>(otherUpd);

      for (csize j = 0; j < numUpdates; ++j) 
      {
        UpdCreateCollection* myUpd = static_cast<UpdCreateCollection*>(myList[j]);

        if (myUpd->getName()->equals(otherUpd2->getName())) 
        {
          RAISE_ERROR(zerr::ZDDY0016_COLLECTION_MULTIPLE_CREATES, otherUpd->theLoc,
          ERROR_PARAMS(myUpd->getName()->getStringValue()));
        }
      }
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
  csize numRoots = rootNodes.size();

  CollectionPulMap::const_iterator collIte = theCollectionPuls.begin();
  CollectionPulMap::const_iterator collEnd = theCollectionPuls.end();

  for (; collIte != collEnd; ++collIte)
  {
    CollectionPul* pul = collIte->second;

    NodeToUpdatesMap::iterator it = pul->theNodeToUpdatesMap.begin();
    NodeToUpdatesMap::iterator end = pul->theNodeToUpdatesMap.end();

    for (; it != end; ++it)
    {
      const XmlNode* targetNode = static_cast<XmlNode*>((*it).first);

      bool found = false;

      for (csize i = 0; i < numRoots; i++)
      {
        XmlNode* rootNode = static_cast<XmlNode*>(rootNodes[i]);
        
        if (targetNode->getTree() == rootNode->getTree())
        {
          found = true;
          break;
        }
      }

      if (!found)
        throw XQUERY_EXCEPTION(err::XUDY0014);
    }
  }
}


/*******************************************************************************
  Find all the indices that may require maintenance. A index is a candidate for
  maintenance if it references at least one collection that has been modified
  (either by adding/removing docs to/from it, or by modifying at least one of
  the docs that belong to that collection already).

  As a side-effect, the method will also collect in theModifiedDocs all the
  exisiting collection docs that are modified by this pul.

  This method is invoked by the ApplyIterator before any of the pul primitives
  is applied.
********************************************************************************/
void PULImpl::getIndicesToRefresh(std::vector<store::Index*>& indices)
{
  SimpleStore* store = &GET_STORE();

  if (store->getIndices().empty())
    return;

  // First, find all the collections that are modified. We also gather all the
  // modified/inserted/deleted collection docs, because they will be need later
  // to maintain indices.
  std::set<store::Collection*> collections;

  CollectionPulMap::iterator collIte = theCollectionPuls.begin();
  CollectionPulMap::iterator collEnd = theCollectionPuls.end();

  for (; collIte != collEnd; ++collIte)
  {
    store::Collection* collection = store->getCollection(collIte->first, false, false);

    // The collection may not be created yet.
    if (collection == NULL)
      continue;

    collections.insert(collection);

    CollectionPul* pul = collIte->second;

    NodeToUpdatesMap::iterator ite = pul->theNodeToUpdatesMap.begin();
    NodeToUpdatesMap::iterator end = pul->theNodeToUpdatesMap.end();
    for (; ite != end; ++ite)
    {
      XmlNode* node = static_cast<XmlNode*>((*ite).first);
      pul->theModifiedDocs.insert(node->getRoot());
    }

    csize numCollUpdates = pul->theInsertIntoCollectionList.size();

    for (csize i = 0; i < numCollUpdates; ++i)
    {
      UpdCollection* upd = static_cast<UpdCollection*>
                           (pul->theInsertIntoCollectionList[i]);

      csize numDocs = upd->numNodes();
      for (csize j = 0; j < numDocs; ++j)
        pul->theInsertedDocs.push_back(static_cast<XmlNode*>(upd->getNode(j)));
    }

    numCollUpdates = pul->theDeleteFromCollectionList.size();

    for (csize i = 0; i < numCollUpdates; ++i)
    {
      UpdCollection* upd = static_cast<UpdCollection*>
                           (pul->theDeleteFromCollectionList[i]);

      csize numDocs = upd->numNodes();
      for (csize j = 0; j < numDocs; ++j)
        pul->theDeletedDocs.push_back(static_cast<XmlNode*>(upd->getNode(j)));
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
    csize numIndexSources = indexSources.size();

    for (csize i = 0; i < numIndexSources; ++i)
    {
      std::set<store::Collection*>::const_iterator colIte = collections.begin();
      std::set<store::Collection*>::const_iterator colEnd = collections.end();

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
    const store::Item* collectionName,
    store::Index* idx,
    store::IndexEntryCreator* creator)
{
  CollectionPul* pul = getCollectionPulByName(collectionName, false, false);

  pul->theIncrementalIndices.push_back(static_cast<IndexImpl*>(idx));
  pul->theIndexEntryCreators.push_back(creator);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::setICChecker(store::ICChecker* icChecker)
{
  theICChecker = icChecker;
}


/*******************************************************************************

********************************************************************************/
void PULImpl::checkIC(const store::Item* collName)
{
  theICChecker->check(collName);
}


/*******************************************************************************

********************************************************************************/
void PULImpl::applyUpdates(bool inheritNSBindings)
{
  CollectionPulMap::iterator collIte = theCollectionPuls.begin();
  CollectionPulMap::iterator collEnd = theCollectionPuls.end();

  theInheritNSBindings = inheritNSBindings;

  try
  {
    // For each collection C, apply XQUF and collection primitives (except
    // delete primitives). Also, refresh any indexes that can be
    // maintained incrementally w.r.t. updates in C.
    for (; collIte != collEnd; ++collIte)
    {
      CollectionPul* pul = collIte->second;
      pul->applyUpdates();
    }

    // apply fn:put primitives
    applyList(thePutList);

    // Apply index primitives
    applyList(theRefreshIndexList);
    applyList(theCreateIndexList);
    applyList(theDeleteIndexList);

    // Apply document primitives
    applyList(theCreateDocumentList);
    applyList(theDeleteDocumentList);

    // Apply hashmap primitives
    applyList(theCreateHashMapList);
    applyList(theDestroyHashMapList);
    applyList(theInsertIntoHashMapList);
    applyList(theRemoveFromHashMapList);

    // check integrity constraints for involved collections
    for (collIte = theCollectionPuls.begin(); collIte != collEnd; ++collIte)
    {
      CollectionPul* pul = collIte->second;      

      if (pul->theCollection != NULL)
      {
        const store::Item* collName = pul->theCollection->getName();

        if ( collName && theICChecker )
        {
          // throws error if IC not met
          checkIC(collName);
        }
      }
    }

    // Apply delete-collection primitives
    for (collIte = theCollectionPuls.begin(); collIte != collEnd; ++collIte)
    {
      CollectionPul* pul = collIte->second;
      applyList(pul->theDeleteCollectionList);
    }
  }
  catch (...)
  {
    undoUpdates();
    throw;
  }

  //
  for (collIte = theCollectionPuls.begin(); collIte != collEnd; ++collIte)
  {
    CollectionPul* pul = collIte->second;
    pul->finalizeUpdates();
  }

  // Apply validation primitives, if this is a revalidation pul.
  try
  {
    applyList(theValidationList);
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during application of revalidation PUL");
  }

  try
  {
    applyList(theICActivationList);
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during application of integrity constraint PUL");
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::undoUpdates()
{
  try
  {
    undoList(theValidationList);

    CollectionPulMap::iterator collIte = theCollectionPuls.begin();
    CollectionPulMap::iterator collEnd = theCollectionPuls.end();

    for (; collIte != collEnd; ++collIte)
    {
      CollectionPul* pul = collIte->second;
      undoList(pul->theDeleteCollectionList);
    }

    undoList(theDeleteIndexList);
    undoList(theCreateIndexList);
    undoList(theRefreshIndexList);

    undoList(thePutList);

    for (collIte = theCollectionPuls.begin(); collIte != collEnd; ++collIte)
    {
      CollectionPul* pul = collIte->second;
      pul->undoUpdates();
    }

    undoList(theICActivationList);
  }
  catch (...)
  {
    ZORBA_FATAL(0, "Unexpected error during pul undo");
  }
}


/*******************************************************************************

********************************************************************************/
CollectionPul::CollectionPul(PULImpl* pul, Collection* collection) 
  :
  theCollection(collection),
  thePul(pul),
  theAdjustTreePositions(false),
  theIsApplied(false)
{
}


/*******************************************************************************

********************************************************************************/
CollectionPul::~CollectionPul()
{
  cleanList(theDoFirstList);
  cleanList(theInsertList);
  cleanList(theReplaceNodeList);
  cleanList(theReplaceContentList);
  cleanList(theDeleteList);
  cleanList(theRevalidateList);

  cleanList(theCreateCollectionList);
  cleanList(theInsertIntoCollectionList);
  cleanList(theDeleteFromCollectionList);
  cleanList(theDeleteCollectionList);

#ifdef ZORBA_WITH_JSON
  cleanList(theJSONObjectInsertList);
  cleanList(theJSONObjectDeleteList);
  cleanList(theJSONObjectReplaceValueList);
  cleanList(theJSONObjectRenameList);
  cleanList(theJSONArrayInsertList);
  cleanList(theJSONArrayDeleteList);
  cleanList(theJSONArrayReplaceValueList);
#endif

  cleanIndexDeltas(theBeforeIndexDeltas);
  cleanIndexDeltas(theAfterIndexDeltas);
  cleanIndexDeltas(theInsertedDocsIndexDeltas);
  cleanIndexDeltas(theDeletedDocsIndexDeltas);
}


/*******************************************************************************

********************************************************************************/
void CollectionPul::switchPul(PULImpl* pul)
{
  thePul = pul;

  switchPulInPrimitivesList(theDoFirstList);
  switchPulInPrimitivesList(theInsertList);
  switchPulInPrimitivesList(theReplaceNodeList);
  switchPulInPrimitivesList(theReplaceContentList);
  switchPulInPrimitivesList(theDeleteList);
  switchPulInPrimitivesList(theRevalidateList);

#ifdef ZORBA_WITH_JSON
  switchPulInPrimitivesList(theJSONObjectInsertList);
  switchPulInPrimitivesList(theJSONObjectDeleteList);
  switchPulInPrimitivesList(theJSONObjectReplaceValueList);
  switchPulInPrimitivesList(theJSONObjectRenameList);
  switchPulInPrimitivesList(theJSONArrayInsertList);
  switchPulInPrimitivesList(theJSONArrayDeleteList);
  switchPulInPrimitivesList(theJSONArrayReplaceValueList);
#endif

  switchPulInPrimitivesList(theCreateCollectionList);
  switchPulInPrimitivesList(theInsertIntoCollectionList);
  switchPulInPrimitivesList(theDeleteFromCollectionList);
  switchPulInPrimitivesList(theDeleteCollectionList);
}


void CollectionPul::switchPulInPrimitivesList(std::vector<UpdatePrimitive*>& list)
{
  std::vector<UpdatePrimitive*>::iterator ite = list.begin();
  std::vector<UpdatePrimitive*>::iterator end = list.end();
  for (; ite != end; ++ite)
  {
    (*ite)->thePul = thePul;
  }
}

/*******************************************************************************
  The comparison function for sorting the entries of an IndexDelta by the doc node
********************************************************************************/
static bool cmp(const std::pair<store::Item_t, store::IndexKey*>& e1,
                const std::pair<store::Item_t, store::IndexKey*>& e2)
{
  return e1.first.getp() < e2.first.getp();
}


/*******************************************************************************
  Compute the index contents on the modified docs, before any modifications
  are actually applied.
********************************************************************************/
void CollectionPul::computeIndexBeforeDeltas()
{
  computeIndexDeltas(theBeforeIndexDeltas);
}


/*******************************************************************************
  Compute the index contents on the modified docs, after the modifications
  are actually applied. Also, compute the index contents on the newly inserted
  and the deleted docs.
********************************************************************************/
void CollectionPul::computeIndexAfterDeltas()
{
  computeIndexDeltas(theAfterIndexDeltas);

  csize numIncrementalIndices = theIncrementalIndices.size();

  if (numIncrementalIndices == 0)
    return;

  theInsertedDocsIndexDeltas.resize(numIncrementalIndices);

  std::vector<XmlNode*>::const_iterator docIte = theInsertedDocs.begin();
  std::vector<XmlNode*>::const_iterator docEnd = theInsertedDocs.end();

  for (; docIte != docEnd; ++docIte)
  {
    for (ulong i = 0; i < numIncrementalIndices; ++i)
    {
      store::IndexEntryCreator* docIndexer = theIndexEntryCreators[i].getp();
      store::IndexDelta& indexDelta = theInsertedDocsIndexDeltas[i];

      docIndexer->createIndexEntries((*docIte), indexDelta);
    }
  }

  theDeletedDocsIndexDeltas.resize(numIncrementalIndices);

  docIte = theDeletedDocs.begin();
  docEnd = theDeletedDocs.end();

  for (; docIte != docEnd; ++docIte)
  {
    for (ulong i = 0; i < numIncrementalIndices; ++i)
    {
      store::IndexEntryCreator* docIndexer = theIndexEntryCreators[i].getp();
      store::IndexDelta& indexDelta = theDeletedDocsIndexDeltas[i];

      docIndexer->createIndexEntries((*docIte), indexDelta);
    }
  }
}


/*******************************************************************************
  For each incrementally maintained index I and each collection doc D that is
  modified by this pul, compute the index entries for I and D, and insert them
  into the given deltas vector
********************************************************************************/
void CollectionPul::computeIndexDeltas(std::vector<store::IndexDelta>& deltas)
{
  ulong numIncrementalIndices = (ulong)theIncrementalIndices.size();

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
      store::IndexDelta& indexDelta = deltas[i];

      docIndexer->createIndexEntries((*docIte), indexDelta);
    }
  }

  for (ulong i = 0; i < numIncrementalIndices; ++i)
  {
    store::IndexDelta& indexDelta = deltas[i];

    std::sort(indexDelta.begin(), indexDelta.end(), cmp);
  }
}


/*******************************************************************************

********************************************************************************/
void CollectionPul::refreshIndices()
{
  csize numIncrementalIndices = theIncrementalIndices.size();

  for (csize idx = 0; idx < numIncrementalIndices; ++idx)
  {
    ValueIndex* index = static_cast<ValueIndex*>(theIncrementalIndices[idx]);

    //
    // Referesh the index w.r.t. modified docs.
    //
    ValueIndexCompareFunction keyCmp(index->getNumColumns(),
                                     index->getTimezone(),
                                     index->getCollations());
    
    store::IndexDelta& beforeDelta = theBeforeIndexDeltas[idx];
    store::IndexDelta& afterDelta = theAfterIndexDeltas[idx];
    store::IndexDelta& insertedDelta = theInsertedDocsIndexDeltas[idx];
    store::IndexDelta& deletedDelta = theDeletedDocsIndexDeltas[idx];

    store::IndexDelta::iterator beforeIte = beforeDelta.begin();
    store::IndexDelta::iterator beforeEnd = beforeDelta.end();
    store::IndexDelta::iterator afterIte = afterDelta.begin();
    store::IndexDelta::iterator afterEnd = afterDelta.end();
    store::IndexDelta::iterator insertedIte = insertedDelta.begin();
    store::IndexDelta::iterator insertedEnd = insertedDelta.end();
    store::IndexDelta::iterator deletedIte = deletedDelta.begin();
    store::IndexDelta::iterator deletedEnd = deletedDelta.end();

    while (beforeIte != beforeEnd && afterIte != afterEnd)
    {
      store::Item_t& beforeNode = (*beforeIte).first;
      store::Item_t& afterNode = (*afterIte).first;
      store::IndexKey* beforeKey = (*beforeIte).second;
      store::IndexKey*& afterKey = (*afterIte).second;

      if (beforeNode == afterNode)
      {
        if (!keyCmp.equal(beforeKey, afterKey))
        {
          index->remove(beforeKey, beforeNode);
          index->insert(afterKey, afterNode);
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
      ++afterIte;
    }

    //
    // Referesh the index w.r.t. newly inserted docs.
    //
    for (; insertedIte != insertedEnd; ++insertedIte)
    {
      index->insert((*insertedIte).second, (*insertedIte).first);
    }

    //
    // Referesh the index w.r.t. deleted docs,
    //
    for (; deletedIte != deletedEnd; ++deletedIte)
    {
      index->remove((*deletedIte).second, (*deletedIte).first);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void CollectionPul::applyUpdates()
{
  // Don't apply anything if the collection is going to be deleted. 
  if (!theDeleteCollectionList.empty())
    return;

  try
  {
    // Compute the before-delta for each incrementally maintained index.
    computeIndexBeforeDeltas();

    theIsApplied = true;

    // Apply all the XQUF update primitives
    applyList(theDoFirstList);
    applyList(theInsertList);
    applyList(theReplaceNodeList);
    applyList(theReplaceContentList);
    applyList(theDeleteList);

#ifdef ZORBA_WITH_JSON
    applyList(theJSONObjectDeleteList);
    applyList(theJSONObjectReplaceValueList);
    applyList(theJSONObjectRenameList);
    applyList(theJSONObjectInsertList);

    applyList(theJSONArrayDeleteList);
    applyList(theJSONArrayReplaceValueList);
    applyList(theJSONArrayInsertList);
#endif

    // Check if any inconsistencies that were detected during the application
    // of XQUF primitives were only temporary and have been resolved by now.
    // If not, an exception will be raised, and the updates will be undone
    // in the "catch" clause below.
    csize numToRecheck = thePrimitivesToRecheck.size();
    for (csize i = 0; i < numToRecheck; ++i)
      thePrimitivesToRecheck[i]->check();

    // Check if any text node merging has to be performed
    std::set<InternalNode*>::iterator it = theMergeToCheckSet.begin();
    std::set<InternalNode*>::iterator end = theMergeToCheckSet.end();
    for (; it != end; ++it)
    {
      InternalNode* node = (*it);

      for (csize i = 0; i < node->numChildren()-1; ++i)
      {
        if (node->getChild(i)->getNodeKind() == store::StoreConsts::textNode &&
            node->getChild(i+1)->getNodeKind() == store::StoreConsts::textNode)
        {
          TextNode* mergedNode = reinterpret_cast<TextNode*>(node->getChild(i));

          TextNodeMerge mergeInfo(node, i);
          mergeInfo.theMergedNodes.push_back(mergedNode);
          node->removeChild(i);

          zstring newContent = mergedNode->getText();
          csize j = i;

          while (j < node->numChildren() &&
                 node->getChild(j)->getNodeKind() == store::StoreConsts::textNode)
          {
            TextNode* mergedNode = reinterpret_cast<TextNode*>(node->getChild(j));
            newContent += mergedNode->getText();
            node->removeChild(j);
            mergeInfo.theMergedNodes.push_back(mergedNode);
          }

          theMergeList.push_back(mergeInfo);

          (void)GET_NODE_FACTORY().createTextNode(node->getTree(),
              node,
              false,
              i,
              newContent);
        }
      }
    }

#ifndef ZORBA_NO_XMLSCHEMA
    // Revalidate the updated docs
    if (thePul->theValidator != NULL && !theValidationNodes.empty())
    {
      theValidationPul = GET_STORE().getItemFactory()->createPendingUpdateList();
      
      thePul->theValidator->validate(theValidationNodes, *theValidationPul.getp());

      try
      {
        theValidationPul->applyUpdates(false);
      }
      catch (...)
      {
        ZORBA_FATAL(0, "Error during the application of the validation PUL");
      }
    }

    if (thePul->theValidator != NULL)
    {
      applyList(theRevalidateList);
    }
#endif

    // Apply collection primitives, except delete primitives
    applyList(theCreateCollectionList);
    applyList(theInsertIntoCollectionList);
    applyList(theDeleteFromCollectionList);

    // Compute the after-delta for each incrementally maintained index.
    computeIndexAfterDeltas();
  }
  catch (const std::exception& e) 
  {
#ifndef NDEBUG
    std::cerr << "Exception thrown during pul::applyUpdates: " << e.what() << std::endl;
#endif
    throw;
  }
  catch (...)
  {
#ifndef NDEBUG
    std::cerr << "Exception thrown during pul::applyUpdates " << std::endl;
#endif
    throw;
  }
}


/*******************************************************************************
  Actions performed in this method are not expected to raise any error, and
  the method itself is called after all other actions that may raise errors
  have been executed already. This separation of actions into ones that may 
  raise errors and other that never raise errors makes it easier to implement
  the undo actions for certain operations.
********************************************************************************/
void CollectionPul::finalizeUpdates()
{
  try
  {
    // Refresh each incrementally maintained index using its before and after
    // deltas. 
    refreshIndices();

    // If necessary, adjust the position of trees inside this collection.
    if (theAdjustTreePositions)
    {
      assert(theCollection);
      theCollection->adjustTreePositions();
    }

    // Detach nodes that were deleted from their trees due to replace-node,
    // replace-content, or delete-node XQUF primitives.
    csize numUpdates;

    numUpdates = theReplaceNodeList.size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      UpdatePrimitive* upd = theReplaceNodeList[i];

      if (!upd->theIsApplied)
        continue;

      if (upd->getKind() == store::UpdateConsts::UP_REPLACE_CHILD)
      {
        UpdReplaceChild* upd2 = static_cast<UpdReplaceChild*>(upd);

        XmlNode* node = BASE_NODE(upd2->theChild);

        // To make the detach() method work properly, we must set the node's
        // parent back to what it used to be.
        node->theParent = INTERNAL_NODE(upd->theTarget);
        node->detach();
      }
      else
      {
        XmlNode* node = BASE_NODE(static_cast<UpdReplaceAttribute*>(upd)->theAttr);

        // To make the detach() method work properly, we must set the node's
        // parent back to what it used to be.
        node->theParent = INTERNAL_NODE(upd->theTarget);
        node->detach();
      }
    }

    numUpdates = theReplaceContentList.size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      UpdReplaceElemContent* upd;
      upd = static_cast<UpdReplaceElemContent*>(theReplaceContentList[i]);

      csize numChildren = upd->theOldChildren.size();
      for (csize j = 0; j < numChildren; ++j)
      {
        XmlNode* node = upd->theOldChildren[j];
        node->theParent = INTERNAL_NODE(upd->theTarget);
        node->detach();
      }
    }

    numUpdates = theDeleteList.size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      UpdDelete* upd = static_cast<UpdDelete*>(theDeleteList[i]);

      if (upd->theIsApplied)
      {
        XmlNode* target = BASE_NODE(upd->theTarget);
        target->theParent = upd->theParent;
        target->detach();
      }
    }

    numUpdates = theMergeList.size();
    for (csize i = 0; i < numUpdates; ++i)
    {
      for (csize j = 0; j < theMergeList[i].theMergedNodes.size(); ++j)
      {
        theMergeList[i].theMergedNodes[j]->theParent= theMergeList[i].theParent;
        theMergeList[i].theMergedNodes[j]->detach();
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
void CollectionPul::undoUpdates()
{
  if (!theIsApplied)
    return;

  try
  {
    undoList(theDeleteFromCollectionList);
    undoList(theInsertIntoCollectionList);
    undoList(theCreateCollectionList);

#ifndef ZORBA_NO_XMLSCHEMA
    // Undo validate-in-place validation
    undoList(theRevalidateList);

    // Undo apply-updates caused validation
    if (theValidationPul)
    {
      undoList(static_cast<PULImpl *>(theValidationPul.getp())->theValidationList);
    }
#endif

    // Undo text node merging
    std::vector<TextNodeMerge>::reverse_iterator rit = theMergeList.rbegin();
    std::vector<TextNodeMerge>::reverse_iterator rend = theMergeList.rend();
    for (; rit != rend; ++rit)
    {
      TextNodeMerge merge = (*rit);
      XmlNode* newTextNode = merge.theParent->getChild(merge.thePos);
      ZORBA_ASSERT(newTextNode->getNodeKind()== store::StoreConsts::textNode);

      newTextNode->detach();

      for (csize j = 0; j < merge.theMergedNodes.size(); ++j)
        merge.theMergedNodes[j]->connect(merge.theParent, merge.thePos + j);
    }
    theMergeList.clear();

#ifdef ZORBA_WITH_JSON
    undoList(theJSONObjectInsertList);
    undoList(theJSONObjectRenameList);
    undoList(theJSONObjectReplaceValueList);
    undoList(theJSONObjectDeleteList);

    undoList(theJSONArrayInsertList);
    undoList(theJSONArrayReplaceValueList);
    undoList(theJSONArrayDeleteList);
#endif

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


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
