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

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_index_value.h"
#include "store/naive/simple_pul.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"
#include "store/naive/pul_primitive_factory.h"
#include "store/naive/node_factory.h"

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

  if (target->isNode())
  {
    const XmlNode* n = static_cast<const XmlNode*>(target);

    const store::Collection* collection = n->getCollection();

    if (collection != NULL)
    {
      collName = static_cast<const QNameItem*>(collection->getName())->getNormalized();

      if (collName == theLastCollection)
        return theLastPul;
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
  else
  {
    // "taret" is the name of a collection.
    if (target == theLastCollection)
    {
      return theLastPul;
    }
    else
    {
      collName = static_cast<const QNameItem*>(target)->getNormalized();
    }
  }

  CollectionPulMap::iterator ite = theCollectionPuls.find(collName);

  theLastCollection = collName;

  if (ite != theCollectionPuls.end())
  {
    theLastPul = ite->second;
  }
  else
  {
    SimpleCollection* collection = static_cast<SimpleCollection*>
                                   (GET_STORE().getCollection(collName).getp());
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
    UpdDelete* upd = GET_STORE().getPULFactory().createUpdDelete(pul, aQueryLoc, target);
    pul->theDeleteList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = (ulong)updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_DELETE)
        return;
    }

    UpdDelete* upd = GET_STORE().getPULFactory().createUpdDelete(pul,  aQueryLoc,target);
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

  UpdInsertChildren* upd = GET_STORE().getPULFactory().
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

  ulong numAttrs = (ulong)attrs.size();
  for (ulong i = 0; i < numAttrs; i++)
  {
    n->checkNamespaceConflict(attrs[i]->getNodeName(), err::XUDY0023);
  }

  NodeUpdates* updates = 0;
  bool found = pul->theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = GET_STORE().getPULFactory().
  createUpdInsertAttributes(pul, aQueryLoc, target, attrs);

  pul->theDoFirstList.push_back(upd);

  if (!found)
  {
    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    XmlNode* tmp = reinterpret_cast<XmlNode*>(n);
    pul->theNodeToUpdatesMap.insert(tmp, updates);
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
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
    {
      ulong numNewAttrs = (ulong)newNodes.size();
      for (ulong i = 0; i < numNewAttrs; ++i)
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
        throw XQUERY_EXCEPTION(err::XUDY0016, ERROR_LOC (*lLoc) );
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
    UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdReplaceElemContent(pul, aQueryLoc, target, newChild);
    pul->theReplaceContentList.push_back(upd);

    updates = new NodeUpdates(1);
    (*updates)[0] = upd;
    pul->theNodeToUpdatesMap.insert(n, updates);
  }
  else
  {
    ulong numUpdates = (ulong)updates->size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updates)[i]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
        throw XQUERY_EXCEPTION(err::XUDY0017);
    }

    UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdReplaceElemContent(pul, aQueryLoc, target, newChild);
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
    upd = GET_STORE().getPULFactory().
    createUpdReplaceAttrValue(pul, aQueryLoc, target, newValue);
    break;
  }
  case store::StoreConsts::textNode:
    upd = GET_STORE().getPULFactory().
    createUpdReplaceTextValue(pul, aQueryLoc, target, newValue);
    break;
  case store::StoreConsts::piNode:
    upd = GET_STORE().getPULFactory().
    createUpdReplacePiValue(pul, aQueryLoc, target, newValue);
    break;
  case store::StoreConsts::commentNode:
    upd = GET_STORE().getPULFactory().
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
    ulong numUpdates = (ulong)updates->size();
    for (ulong i = 0; i < numUpdates; i++)
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

    upd = GET_STORE().getPULFactory().
    createUpdRenameElem(pul, aQueryLoc, target, newName);
    break;
  }
  case store::StoreConsts::attributeNode:
  {
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(n->theParent);

    if (elemParent != NULL)
      elemParent->checkNamespaceConflict(newName.getp(), err::XUDY0023);

    upd = GET_STORE().getPULFactory().createUpdRenameAttr(pul, aQueryLoc, target, newName);
    break;
  }
  case store::StoreConsts::piNode:
  {
    zstring tmp;
    newName->getStringValue2(tmp);
    upd = GET_STORE().getPULFactory().createUpdRenamePi(pul, aQueryLoc, target, tmp);
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
    ulong numUpdates = (ulong)updates->size();
    for (ulong i = 0; i < numUpdates; i++)
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
  ulong numPuts = (ulong)thePutList.size();

  for (ulong i = 0; i < numPuts; ++i)
  {
    UpdPut* upd = static_cast<UpdPut*>(thePutList[i]);

    if (upd->theTargetUri == uri)
    {
      throw XQUERY_EXCEPTION(
        err::XUDY0031, ERROR_PARAMS( uri->getStringValue() )
      );
    }
  }

  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdPut(this, aQueryLoc, target, uri);

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
  UpdatePrimitive* upd = 
  GET_STORE().getPULFactory().createUpdSetElementType(this,
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

  UpdatePrimitive* upd =
  GET_STORE().getPULFactory().createUpdSetElementType(this,
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
    const QueryLoc* aQueryLoc,
    store::Item_t& target,
    store::Item_t& typeName,
    store::Item_t& typedValue)
{
  UpdatePrimitive* upd = 
  GET_STORE().getPULFactory().createUpdSetAttributeType(this, 
                                                        aQueryLoc,
                                                        target,
                                                        typeName,
                                                        typedValue,
                                                        false);

  theValidationList.push_back(upd);
}


void PULImpl::addSetAttributeType(
    const QueryLoc* aQueryLoc,
    store::Item_t&              target,
    store::Item_t&              typeName,
    std::vector<store::Item_t>& typedValueV)
{
  store::Item_t typedValue = new ItemVector(typedValueV);

  UpdatePrimitive* upd =
  GET_STORE().getPULFactory().createUpdSetAttributeType(this,
                                                        aQueryLoc,
                                                        target,
                                                        typeName,
                                                        typedValue,
                                                        true);

  theValidationList.push_back(upd);
}


/*******************************************************************************
 Collection primitives
********************************************************************************/
void PULImpl::addCreateCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    const std::vector<store::Annotation_t>& annotations,
    const store::Item_t& nodeType,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theCreateCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdCreateCollection(
    pul,
    aQueryLoc,
    name,
    annotations,
    nodeType,
    dyn_collection));
}


void PULImpl::addDeleteCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theDeleteCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdDeleteCollection(pul, aQueryLoc, name, dyn_collection));
}


void PULImpl::addInsertIntoCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theInsertIntoCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdInsertIntoCollection(pul, aQueryLoc, name, nodes, dyn_collection));
} 


void PULImpl::addInsertFirstIntoCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theInsertIntoCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdInsertFirstIntoCollection(pul, aQueryLoc, name, nodes, dyn_collection));
}


void PULImpl::addInsertLastIntoCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theInsertIntoCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdInsertLastIntoCollection(pul, aQueryLoc, name, nodes, dyn_collection));
}


void PULImpl::addInsertBeforeIntoCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    store::Item_t& target,
    std::vector<store::Item_t>& nodes,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theInsertIntoCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdInsertBeforeIntoCollection(pul, aQueryLoc, name, target, nodes, dyn_collection));
}


void PULImpl::addInsertAfterIntoCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    store::Item_t& target,
    std::vector<store::Item_t>& nodes,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theInsertIntoCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdInsertAfterIntoCollection(pul, aQueryLoc, name, target, nodes, dyn_collection));
}


void PULImpl::addDeleteFromCollection(
    const QueryLoc* aQueryLoc,
    store::Item_t& name,
    std::vector<store::Item_t>& nodes,
    bool isLast,
    bool dyn_collection)
{
  CollectionPul* pul = getCollectionPul(name.getp());

  pul->theDeleteFromCollectionList.push_back(
  GET_STORE().getPULFactory().createUpdDeleteNodesFromCollection(pul, aQueryLoc, name, nodes, isLast, dyn_collection));
}


/*******************************************************************************
  Index primitives
********************************************************************************/
void PULImpl::addCreateIndex(
    const QueryLoc* aQueryLoc,
    const store::Item_t& qname,
    const store::IndexSpecification& spec,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdCreateIndex(this, aQueryLoc,  qname, spec, sourceIter);
  theCreateIndexList.push_back(upd);
}


void PULImpl::addDeleteIndex(
    const QueryLoc* aQueryLoc,
    const store::Item_t& qname)
{
  UpdatePrimitive* upd = 
  GET_STORE().getPULFactory().createUpdDeleteIndex(this, aQueryLoc, qname);

  theDeleteIndexList.push_back(upd);
}


void PULImpl::addRefreshIndex(
    const QueryLoc* aQueryLoc,
    const store::Item_t& qname,
    store::Iterator* sourceIter)
{
  UpdatePrimitive* upd = 
  GET_STORE().getPULFactory().createUpdRefreshIndex(this, aQueryLoc,  qname, sourceIter);

  theRefreshIndexList.push_back(upd);
}


/*******************************************************************************
  Integrity Constraint Primitives
********************************************************************************/
void PULImpl::addActivateIC(
    const QueryLoc* aQueryLoc,
      const store::Item_t& qname,
      const store::Item_t& aCollectionName)
{
  UpdatePrimitive* upd = 
  GET_STORE().getPULFactory().createUpdActivateIC(this, aQueryLoc, qname, aCollectionName);

  theICActivationList.push_back(upd);
}

void PULImpl::addActivateForeignKeyIC(
    const QueryLoc* aQueryLoc,
      const store::Item_t& qname,
      const store::Item_t& aFromCollectionName,
      const store::Item_t& aToCollectionName)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdActivateForeignKeyIC(this,
      aQueryLoc,
      qname,
      aFromCollectionName,
      aToCollectionName);
  theICActivationList.push_back(upd);
}

void PULImpl::addDeActivateIC(
    const QueryLoc* aQueryLoc,
      const store::Item_t& qname)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdDeActivateIC(this, aQueryLoc, qname);
  theICActivationList.push_back(upd);
}


/*******************************************************************************
  Document PULs
********************************************************************************/
void PULImpl::addCreateDocument(
    const QueryLoc* aQueryLoc,
    const store::Item_t& uri,
    store::Item_t& doc)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdCreateDocument(
      this, aQueryLoc, uri, doc);
  theCreateDocumentList.push_back(upd);
}


void PULImpl::addDeleteDocument(
    const QueryLoc* aQueryLoc,
    const store::Item_t& uri)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdDeleteDocument(
      this, aQueryLoc, uri);
  theDeleteDocumentList.push_back(upd);
}


/*******************************************************************************
  HashMap PULs
********************************************************************************/
void PULImpl::addCreateHashMap(
    const QueryLoc* aQueryLoc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKeyTypes,
    const std::vector<zstring>& aCollations,
    long  aTimezone)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdCreateHashMap(
      this, aQueryLoc, aQName, aKeyTypes, aCollations, aTimezone);
  theCreateHashMapList.push_back(upd);
}

void PULImpl::addDestroyHashMap(
    const QueryLoc* aQueryLoc,
    const store::Item_t& aQName)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdDestroyHashMap(
      this, aQueryLoc, aQName);
  theDestroyHashMapList.push_back(upd);
}

void PULImpl::addInsertIntoHashMap(
    const QueryLoc* aQueryLoc,
    const store::Item_t& aQName,
    const std::vector<store::Item_t>& aKey,
    const store::Iterator_t& aValue)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdInsertIntoHashMap(
      this, aQueryLoc, aQName, aKey, aValue);
  theInsertIntoHashMapList.push_back(upd);
}

void PULImpl::addRemoveFromHashMap(
    const QueryLoc* aQueryLoc,
      const store::Item_t& aQName,
      const std::vector<store::Item_t>& aKey)
{
  UpdatePrimitive* upd = GET_STORE().getPULFactory().createUpdRemoveFromHashMap(
      this, aQueryLoc, aQName, aKey);
  theRemoveFromHashMapList.push_back(upd);
}


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
      mergeUpdateList(thisPul,
                      thisPul->theDoFirstList,
                      otherPul->theDoFirstList,
                      UP_LIST_DO_FIRST);

      mergeUpdateList(thisPul,
                      thisPul->theInsertList,
                      otherPul->theInsertList,
                      UP_LIST_NONE);

      mergeUpdateList(thisPul,
                      thisPul->theReplaceNodeList,
                      otherPul->theReplaceNodeList,
                      UP_LIST_REPLACE_NODE);

      mergeUpdateList(thisPul,
                      thisPul->theReplaceContentList,
                      otherPul->theReplaceContentList,
                      UP_LIST_REPLACE_CONTENT);

      mergeUpdateList(thisPul,
                      thisPul->theDeleteList,
                      otherPul->theDeleteList,
                      UP_LIST_DELETE);

      // Merge collection primitives
      mergeUpdateList(thisPul,
                      thisPul->theCreateCollectionList,
                      otherPul->theCreateCollectionList,
                      UP_LIST_CREATE_COLLECTION);

      mergeUpdateList(thisPul,
                      thisPul->theInsertIntoCollectionList,
                      otherPul->theInsertIntoCollectionList,
                      UP_LIST_NONE);

      mergeUpdateList(thisPul,
                      thisPul->theDeleteFromCollectionList,
                      otherPul->theDeleteFromCollectionList,
                      UP_LIST_NONE);

      mergeUpdateList(thisPul,
                      thisPul->theDeleteCollectionList,
                      otherPul->theDeleteCollectionList,
                      UP_LIST_NONE);

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
  ulong numPuts = (ulong)thePutList.size();
  ulong numOtherPuts = (ulong)otherp->thePutList.size();

  for (ulong i = 0; i < numOtherPuts; ++i)
  {
    UpdPut* otherUpd = static_cast<UpdPut*>(otherp->thePutList[i]);

    for (ulong j = 0; j < numPuts; ++j)
    {
      UpdPut* upd = static_cast<UpdPut*>(thePutList[j]);
      
      if (upd->theTargetUri->equals(otherUpd->theTargetUri))
      {
        throw XQUERY_EXCEPTION(
          err::XUDY0031, ERROR_PARAMS( upd->theTargetUri->getStringValue() )
        );
      }
    }

    thePutList.push_back(otherUpd);
    otherp->thePutList[i] = NULL;
  }

  // merge index primitives
  mergeUpdateList(NULL,
                  theCreateIndexList,
                  otherp->theCreateIndexList,
                  UP_LIST_CREATE_INDEX);

  mergeUpdateList(NULL,
                  theDeleteIndexList,
                  otherp->theDeleteIndexList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theRefreshIndexList,
                  otherp->theRefreshIndexList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theICActivationList,
                  otherp->theICActivationList,
                  UP_LIST_NONE);

  // merge document primitives
  mergeUpdateList(NULL,
                  theCreateDocumentList,
                  otherp->theCreateDocumentList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theDeleteDocumentList,
                  otherp->theDeleteDocumentList,
                  UP_LIST_NONE);

  // merge hashmap primitives
  mergeUpdateList(NULL,
                  theCreateHashMapList,
                  otherp->theCreateHashMapList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theDestroyHashMapList,
                  otherp->theDestroyHashMapList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theInsertIntoHashMapList,
                  otherp->theInsertIntoHashMapList,
                  UP_LIST_NONE);

  mergeUpdateList(NULL,
                  theRemoveFromHashMapList,
                  otherp->theRemoveFromHashMapList,
                  UP_LIST_NONE);

  // merge validation primitives
  mergeUpdateList(NULL,
                  theValidationList,
                  otherp->theValidationList,
                  UP_LIST_NONE);
}


void PULImpl::mergeUpdateList(
    CollectionPul* myPul,
    std::vector<UpdatePrimitive*>& myList,
    std::vector<UpdatePrimitive*>& otherList,
    UpdListKind listKind)
{
  ulong numUpdates;
  ulong numOtherUpdates;

  numUpdates = (ulong)myList.size();
  numOtherUpdates = (ulong)otherList.size();

  for (ulong i = 0; i < numOtherUpdates; ++i)
  {
    if (listKind == UP_LIST_CREATE_COLLECTION) 
    {
      UpdCreateCollection* otherUpd = static_cast<UpdCreateCollection*>(otherList[i]);
      for (ulong j = 0; j < myList.size(); ++j) 
      {
        if (myList[j]->getKind() == store::UpdateConsts::UP_CREATE_COLLECTION) 
        {
          UpdCreateCollection* upd = static_cast<UpdCreateCollection*>(myList[j]);
          if (upd->getName()->equals(otherUpd->getName())) 
          {
            throw XQUERY_EXCEPTION(
              zerr::ZDDY0016_COLLECTION_MULTIPLE_CREATES,
              ERROR_PARAMS( upd->getName()->getStringValue() ),
              ERROR_LOC( *upd->theLoc )
            );
          }
        }
      }
    }
    else if (listKind == UP_LIST_CREATE_INDEX) 
    {
      UpdCreateIndex* otherUpd = static_cast<UpdCreateIndex*>(otherList[i]);
      for (ulong j = 0; j < myList.size(); ++j) 
      {
        if (myList[j]->getKind() == store::UpdateConsts::UP_CREATE_INDEX) 
        {
          UpdCreateIndex* upd = static_cast<UpdCreateIndex*>(myList[j]);
          if (upd->getName()->equals(otherUpd->getName())) 
          {
            throw XQUERY_EXCEPTION(
              zerr::ZDDY0027_INDEX_MULTIPLE_CREATES,
              ERROR_PARAMS( upd->getName()->getStringValue() ),
              ERROR_LOC( *upd->theLoc )
            );
          }
        }
      }
    }

    UpdatePrimitive* otherUpd = otherList[i];
    otherUpd->thePul = this;
    otherUpd->theCollectionPul = myPul;

    store::UpdateConsts::UpdPrimKind updKind = otherUpd->getKind();
    XmlNode* target;

    if (updKind == store::UpdateConsts::UP_REPLACE_CHILD)
      target = BASE_NODE(reinterpret_cast<UpdReplaceChild*>(otherUpd)->theChild);

    else if (updKind == store::UpdateConsts::UP_REPLACE_ATTRIBUTE)
      target = BASE_NODE(reinterpret_cast<UpdReplaceAttribute*>(otherUpd)->theAttr);

    else
      target = BASE_NODE(otherUpd->theTarget);

    NodeUpdates* targetUpdates = NULL;
    bool found = (target == NULL || myPul == NULL?
                  false : 
                  myPul->theNodeToUpdatesMap.get(target, targetUpdates));

    if (!found)
    {
      myList.push_back(otherUpd);
      otherList[i] = NULL;

      if (target && myPul)
      {
        targetUpdates = new NodeUpdates(1);
        (*targetUpdates)[0] = otherUpd;
        myPul->theNodeToUpdatesMap.insert(target, targetUpdates);
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
          ulong numTargetUpdates = (ulong)targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; j++)
          {
            if (store::UpdateConsts::isRename((*targetUpdates)[j]->getKind()))
              throw XQUERY_EXCEPTION(
                  err::XUDY0015,
                  ERROR_LOC( (*targetUpdates)[j]->theLoc )
                );
          }
        }
        else if (store::UpdateConsts::isReplaceValue(updKind))
        {
          ulong numTargetUpdates = (ulong)targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; j++)
          {
            if (store::UpdateConsts::isReplaceValue((*targetUpdates)[j]->getKind()))
              throw XQUERY_EXCEPTION(
                  err::XUDY0017,
                  ERROR_LOC( (*targetUpdates)[j]->theLoc )
                );
          }
        }
        break;
      }
      case UP_LIST_REPLACE_NODE:
      {
        if (store::UpdateConsts::isReplaceNode(updKind))
        {
          ulong numTargetUpdates = (ulong)targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; ++j)
          {
            if (store::UpdateConsts::isReplaceNode((*targetUpdates)[j]->getKind()))
              throw XQUERY_EXCEPTION(
                  err::XUDY0016,
                  ERROR_LOC( (*targetUpdates)[j]->theLoc )
                );
          }
        }
        break;
      }
      case UP_LIST_REPLACE_CONTENT:
      {
        if (updKind == store::UpdateConsts::UP_REPLACE_CONTENT)
        {
          ulong numTargetUpdates = (ulong)targetUpdates->size();
          for (ulong j = 0; j < numTargetUpdates; ++j)
          {
            if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_REPLACE_CONTENT)
              throw XQUERY_EXCEPTION(
                  err::XUDY0017,
                  ERROR_LOC( (*targetUpdates)[j]->theLoc )
                );
          }
        }
        break;
      }
      case UP_LIST_DELETE:
      {
        if (updKind == store::UpdateConsts::UP_DELETE)
        {
          ulong numTargetUpdates = (ulong)targetUpdates->size();
          ulong j;
          for (j = 0; j < numTargetUpdates; ++j)
          {
            if ((*targetUpdates)[j]->getKind() == store::UpdateConsts::UP_DELETE)
              break;
          }

          if (j < numTargetUpdates)
          {
            delete otherUpd;
            otherList[i] = NULL;
            continue;
          }
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
  ulong numRoots = (ulong)rootNodes.size();

  CollectionPulMap::const_iterator collIte = theCollectionPuls.begin();
  CollectionPulMap::const_iterator collEnd = theCollectionPuls.end();

  for (; collIte != collEnd; ++collIte)
  {
    CollectionPul* pul = collIte->second;

    NodeToUpdatesMap::iterator it = pul->theNodeToUpdatesMap.begin();
    NodeToUpdatesMap::iterator end = pul->theNodeToUpdatesMap.end();

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
    store::Collection* collection = store->getCollection(collIte->first);

    // The collection may not be created yet.
    if (collection == NULL)
      continue;

    collections.insert(collection);

    CollectionPul* pul = collIte->second;

    NodeToUpdatesMap::iterator ite = pul->theNodeToUpdatesMap.begin();
    NodeToUpdatesMap::iterator end = pul->theNodeToUpdatesMap.end();
    for (; ite != end; ++ite)
    {
      XmlNode* node = (*ite).first;
      pul->theModifiedDocs.insert(node->getRoot());
    }

    csize numCollUpdates = pul->theInsertIntoCollectionList.size();

    for (csize i = 0; i < numCollUpdates; ++i)
    {
      UpdCollection* upd = static_cast<UpdCollection*>
                           (pul->theInsertIntoCollectionList[i]);

      ulong numDocs = upd->numNodes();
      for (ulong j = 0; j < numDocs; ++j)
        pul->theInsertedDocs.push_back(static_cast<XmlNode*>(upd->getNode(j)));
    }

    numCollUpdates = pul->theDeleteFromCollectionList.size();

    for (csize i = 0; i < numCollUpdates; ++i)
    {
      UpdCollection* upd = static_cast<UpdCollection*>
                           (pul->theDeleteFromCollectionList[i]);

      ulong numDocs = upd->numNodes();
      for (ulong j = 0; j < numDocs; ++j)
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
  CollectionPul* pul = getCollectionPul(collectionName);

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
CollectionPul::CollectionPul(PULImpl* pul, SimpleCollection* collection) 
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

  cleanList(theCreateCollectionList);
  cleanList(theInsertIntoCollectionList);
  cleanList(theDeleteFromCollectionList);
  cleanList(theDeleteCollectionList);

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
      store::PUL_t validationPul =
      GET_STORE().getItemFactory()->createPendingUpdateList();
      
      thePul->theValidator->validate(theValidationNodes, *validationPul.getp());

      try
      {
        validationPul->applyUpdates(false);
      }
      catch (...)
      {
        ZORBA_FATAL(0, "Error during the application of the validation PUL");
      }
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
      if (theCollection) // ??? not set if the collection is dynamic
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
