
#include "errors/error_manager.h"

#include "system/globalenv.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_pul.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"


namespace zorba { namespace store {

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
void PULImpl::addDelete(Item_t& target)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
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
      if ((*updates)[i]->getKind() == UpdateConsts::UP_DELETE)
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
    Item_t&              target,
    std::vector<Item_t>& children,
    bool                 copy,
    const CopyMode&      copymode)
{
  addInsertChildren(UpdateConsts::UP_INSERT_INTO,
                    target, children, copy, copymode);
}


void PULImpl::addInsertFirst(
    Item_t&              target,
    std::vector<Item_t>& children,
    bool                 copy,
    const CopyMode&      copymode)
{
  addInsertChildren(UpdateConsts::UP_INSERT_INTO_FIRST,
                    target, children, copy, copymode);
}


void PULImpl::addInsertLast(
    Item_t&              target,
    std::vector<Item_t>& children,
    bool                 copy,
    const CopyMode&      copymode)
{
  addInsertChildren(UpdateConsts::UP_INSERT_INTO_LAST,
                    target, children, copy, copymode);
}


void PULImpl::addInsertChildren(
    UpdateConsts::UpdPrimKind kind,
    Item_t&                   target,
    std::vector<Item_t>&      children,
    bool                      copy,
    const CopyMode&           copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertChildren* upd = new UpdInsertChildren(kind, target, children,
                                                 copy, copymode);

  if (kind == UpdateConsts::UP_INSERT_INTO)
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
    Item_t&                   target,
    std::vector<Item_t>&      siblings,
    bool                      copy,
    const CopyMode&           copymode)
{
  addInsertSiblings(UpdateConsts::UP_INSERT_BEFORE,
                    target, siblings, copy, copymode);
}


void PULImpl::addInsertAfter(
    Item_t&                   target,
    std::vector<Item_t>&      siblings,
    bool                      copy,
    const CopyMode&           copymode)
{
  addInsertSiblings(UpdateConsts::UP_INSERT_AFTER,
                    target, siblings, copy, copymode);
}


void PULImpl::addInsertSiblings(
    UpdateConsts::UpdPrimKind kind,
    Item_t&                   target,
    std::vector<Item_t>&      siblings,
    bool                      copy,
    const CopyMode&           copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertSiblings* upd = new UpdInsertSiblings(kind, target, siblings,
                                                 copy, copymode);
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
    Item_t&              target,
    std::vector<Item_t>& attrs,
    bool                 copy,
    const CopyMode&      copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = new UpdInsertAttributes(target, attrs, copy, copymode);
  theDoFirstList.push_back(upd);

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
void PULImpl::addReplaceNode(
    Item_t&              target,
    std::vector<Item_t>& newNodes,
    bool                 copy,
    const CopyMode&      copymode)
{
  XmlNode* n = BASE_NODE(target);

  Item_t parent = target->getParent();

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  UpdateConsts::UpdPrimKind kind;

  if (target->getNodeKind() == StoreConsts::attributeNode)
  {
    upd = new UpdReplaceAttribute(parent, target, newNodes, copy, copymode);
    kind = UpdateConsts::UP_REPLACE_ATTRIBUTE;
  }
  else
  {
    upd = new UpdReplaceChild(parent, target, newNodes, copy, copymode);
    kind = UpdateConsts::UP_REPLACE_CHILD;
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
        ZORBA_ERROR(ZorbaError::XUDY0016);
      }
    }

    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceContent(
    Item_t&         target,
    Item_t&         newChild,
    bool            copy,
    const CopyMode& copymode)
{
  XmlNode* n = BASE_NODE(target);

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdatePrimitive* upd = new UpdReplaceContent(target, newChild, copy, copymode);
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
      if ((*updates)[i]->getKind() == UpdateConsts::UP_REPLACE_CONTENT)
        ZORBA_ERROR(ZorbaError::XUDY0017);
    }

    UpdatePrimitive* upd = new UpdReplaceContent(target, newChild, copy, copymode);
    theReplaceContentList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceValue(Item_t& target, xqpStringStore_t& newValue)
{
  XmlNode* n = BASE_NODE(target);
  StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case StoreConsts::attributeNode:
    upd = new UpdReplaceAttrValue(target, newValue);
    break;
  case StoreConsts::textNode:
    upd = new UpdReplaceTextValue(target, newValue);
    break;
  case StoreConsts::piNode:
    upd = new UpdReplacePiValue(target, newValue);
    break;
  case StoreConsts::commentNode:
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
      if (UpdateConsts::isReplaceValue((*updates)[i]->getKind()))
      {
        delete upd;
        ZORBA_ERROR(ZorbaError::XUDY0017);
      }
    }

    theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addRename(Item_t& target, Item_t& newName)
{
  XmlNode* n = BASE_NODE(target);
  StoreConsts::NodeKind targetKind = n->getNodeKind();

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case StoreConsts::elementNode:
  {
    upd = new UpdRenameElem(target, newName);
    break;
  }
  case StoreConsts::attributeNode:
  {
    upd = new UpdRenameAttr(target, newName);
    break;
  }
  case StoreConsts::piNode:
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
      if (UpdateConsts::isRename((*updates)[i]->getKind()))
      {
        delete upd;
        ZORBA_ERROR(ZorbaError::XUDY0015);
      }
    }

    theDoFirstList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::mergeUpdates(const Item* other)
{
  const PULImpl* otherp = reinterpret_cast<const PULImpl*>(other);

  mergeUpdateList(theDoFirstList, otherp->theDoFirstList,
                  true, true, false, false);

  mergeUpdateList(theInsertList, otherp->theInsertList,
                  false, false, false, false);

  mergeUpdateList(theReplaceNodeList, otherp->theReplaceNodeList,
                  false, false, true, false);

  mergeUpdateList(theReplaceContentList, otherp->theReplaceContentList,
                  false, false, false, true);

  mergeUpdateList(theDeleteList, otherp->theDeleteList,
                  false, false, false, false);
}


void PULImpl::mergeUpdateList(
    std::vector<UpdatePrimitive*>        myList,
    const std::vector<UpdatePrimitive*>& otherList,
    bool                                 checkRename,
    bool                                 checkReplaceValue,
    bool                                 checkReplaceNode,
    bool                                 checkReplaceContent)
{
  ulong numUpdates;
  ulong numOtherUpdates;

  numUpdates = myList.size();
  numOtherUpdates = otherList.size();

  myList.resize(numUpdates + numOtherUpdates);

  for (ulong i = 0; i < numOtherUpdates; i++)
  {
    UpdatePrimitive* upd = otherList[i];
    UpdateConsts::UpdPrimKind updKind = upd->getKind();
    XmlNode* target;

    if (updKind == UpdateConsts::UP_REPLACE_CHILD)
      target = BASE_NODE(reinterpret_cast<UpdReplaceChild*>(upd)->theChild);
    else
      target = BASE_NODE(upd->theTarget);

    NodeUpdates* targetUpdates;
    bool found = theNodeToUpdatesMap.get(target, targetUpdates);

    if (!found)
    {
      myList[numUpdates + i] = upd;

      targetUpdates = new NodeUpdates(1);
      (*targetUpdates)[0] = upd;
      theNodeToUpdatesMap.insert(target, targetUpdates);
    }
    else
    {
      if (checkRename && UpdateConsts::isRename(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (UpdateConsts::isRename((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(ZorbaError::XUDY0015);
        }
      }
      else if (checkReplaceValue && UpdateConsts::isReplaceValue(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (UpdateConsts::isReplaceValue((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(ZorbaError::XUDY0017);
        }
      }
      else if (checkReplaceNode && UpdateConsts::isReplaceNode(updKind))
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if (UpdateConsts::isReplaceNode((*targetUpdates)[j]->getKind()))
            ZORBA_ERROR(ZorbaError::XUDY0016);
        }
      }
      else if (checkReplaceContent && upd->getKind() == UpdateConsts::UP_REPLACE_CONTENT)
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if ((*targetUpdates)[j]->getKind() == UpdateConsts::UP_REPLACE_CONTENT)
            ZORBA_ERROR(ZorbaError::XUDY0017);
        }
      }

      myList[numUpdates + i] = upd;
      targetUpdates->push_back(upd);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::serializeUpdates(serializer& ser, std::ostream& os)
{
  NodeToUpdatesMap::iterator it;

  for (it = theNodeToUpdatesMap.begin(); it != theNodeToUpdatesMap.end(); ++it)
  {
    (*it).first->serializeXML(ser, os);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::applyUpdates()
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

  numUpdates = theDeleteList.size();
  for (i = 0; i < numUpdates; i++)
  {
    XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
    BASE_NODE(theDeleteList[i]->theTarget)->switchTree(tree, NULL, 0, false);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdDelete::apply()
{
  BASE_NODE(theTarget)->disconnect();
}


void UpdDelete::undo()
{

}


/*******************************************************************************

********************************************************************************/
void UpdInsertChildren::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  if (theKind == UpdateConsts::UP_INSERT_INTO)
  {
    target->insertChildren(theChildren,
                           target->numChildren(),
                           theDoCopy,
                           theCopyMode);
  }
  else if (theKind == UpdateConsts::UP_INSERT_INTO_FIRST)
  {
    target->insertChildrenFirst(theChildren, theDoCopy, theCopyMode);
  }
  else
  {
    target->insertChildrenLast(theChildren, theDoCopy, theCopyMode);
  }
}


void UpdInsertChildren::undo()
{
}


/*******************************************************************************

********************************************************************************/
void UpdInsertSiblings::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  if (theKind == UpdateConsts::UP_INSERT_BEFORE)
  {
    target->insertSiblingsBefore(theSiblings, theDoCopy, theCopyMode);
  }
  else
  {
    target->insertSiblingsAfter(theSiblings, theDoCopy, theCopyMode);
  }
}


void UpdInsertSiblings::undo()
{
}


/*******************************************************************************

********************************************************************************/
void UpdInsertAttributes::apply()
{
  ELEM_NODE(theTarget)->insertAttributes(theAttributes, theDoCopy, theCopyMode);
}


void UpdInsertAttributes::undo()
{

}


/*******************************************************************************

********************************************************************************/
void UpdReplaceChild::apply()
{
  XmlNode* target = BASE_NODE(theTarget);

  thePos = target->children().find(BASE_NODE(theChild));

  target->replaceChild(theNewChildren, thePos, theDoCopy, theCopyMode);
}


void UpdReplaceChild::undo()
{
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceAttribute::apply()
{
  ElementNode* target = ELEM_NODE(theTarget);

  thePos = target->attributes().find(BASE_NODE(theAttr));

  target->replaceAttribute(theNewAttrs, thePos, theDoCopy, theCopyMode);
}


void UpdReplaceAttribute::undo()
{

}


/*******************************************************************************

********************************************************************************/
void UpdReplaceContent::apply()
{
  ELEM_NODE(theTarget)->replaceContent(BASE_NODE(theNewChild), theOldChildren);
}


void UpdReplaceContent::undo()
{

}


/*******************************************************************************

********************************************************************************/
void UpdReplaceAttrValue::apply()
{
  ATTR_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


void UpdReplaceAttrValue::undo()
{

}


void UpdReplaceTextValue::apply()
{
  TEXT_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


void UpdReplaceTextValue::undo()
{

}


void UpdReplacePiValue::apply()
{

  PI_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


void UpdReplacePiValue::undo()
{

}


void UpdReplaceCommentValue::apply()
{
  COMMENT_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


void UpdReplaceCommentValue::undo()
{

}


/*******************************************************************************

********************************************************************************/
void UpdRenameElem::apply()
{
  ELEM_NODE(theTarget)->rename(theNewName, theOldName);
}


void UpdRenameElem::undo()
{

}


void UpdRenameAttr::apply()
{
  ATTR_NODE(theTarget)->rename(theNewName, theOldName);
}


void UpdRenameAttr::undo()
{

}


void UpdRenamePi::apply()
{
  PI_NODE(theTarget)->rename(theNewName, theOldName);
}


void UpdRenamePi::undo()
{

}

}
}
