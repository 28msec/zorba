
#include "util/Assert.h"
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
void PULImpl::addInsertInto(
    Item*                target,
    std::vector<Item_t>& children,
    bool                 copy,
    const CopyMode&      copymode)
{
  XmlNode* n = reinterpret_cast<XmlNode*>(target);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertChildren* upd = new UpdInsertChildren(UpdateConsts::UP_INSERT_INTO,
                                                 n, children, copy, copymode);
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
void PULImpl::addInsertAttributes(
    Item*                target,
    std::vector<Item_t>& attrs,
    bool                 copy,
    const CopyMode&      copymode)
{
  XmlNode* n = reinterpret_cast<XmlNode*>(target);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = new UpdInsertAttributes(n, attrs, copy, copymode);
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
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(Item* target)
{
  XmlNode* n = reinterpret_cast<XmlNode*>(target);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdDelete* upd = new UpdDelete(n);
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

    UpdDelete* upd = new UpdDelete(n);
    theDeleteList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceContent(Item* target, Item_t& newChild)
{
  XmlNode* n = reinterpret_cast<XmlNode*>(target);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  if (!found)
  {
    UpdatePrimitive* upd = new UpdReplaceContent(n, newChild);
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

    UpdatePrimitive* upd = new UpdReplaceContent(n, newChild);
    theReplaceContentList.push_back(upd);
    updates->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceValue(Item* target, xqpStringStore_t& newValue)
{
  XmlNode* n = reinterpret_cast<XmlNode*>(target);
  StoreConsts::NodeKind targetKind = n->getNodeKind();

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case StoreConsts::attributeNode:
    upd = new UpdReplaceAttrValue(n, newValue);
    break;
  case StoreConsts::textNode:
    upd = new UpdReplaceTextValue(n, newValue);
    break;
  case StoreConsts::piNode:
    upd = new UpdReplacePiValue(n, newValue);
    break;
  case StoreConsts::commentNode:
    upd = new UpdReplaceCommentValue(n, newValue);
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
void PULImpl::addRename(Item* target, Item_t& newName)
{
  ZORBA_ASSERT(target->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(target);
  StoreConsts::NodeKind targetKind = n->getNodeKind();

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdatePrimitive* upd;
  switch (targetKind)
  {
  case StoreConsts::elementNode:
  {
    upd = new UpdRenameElem(n, newName);
    break;
  }
  case StoreConsts::attributeNode:
  {
    upd = new UpdRenameAttr(n, newName);
    break;
  }
  case StoreConsts::piNode:
  {
    xqpStringStore_t tmp = newName->getStringValue();
    upd = new UpdRenamePi(n, tmp);
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
void PULImpl::mergeUpdates(const PUL& other)
{
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
    theDeleteList[i]->theTarget->switchTree(tree, NULL, 0, false);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdInsertChildren::apply()
{
  if (theKind == UpdateConsts::UP_INSERT_INTO)
  {
    ELEM_NODE(theTarget)->insertInto(theChildren,
                                     theTarget->numChildren(),
                                     theDoCopy,
                                     theCopyMode);
  }
  else if (theKind == UpdateConsts::UP_INSERT_INTO_FIRST)
  {
    ELEM_NODE(theTarget)->insertFirst(theChildren, theDoCopy, theCopyMode);
  }
  else
  {
    ELEM_NODE(theTarget)->insertLast(theChildren, theDoCopy, theCopyMode);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdInsertSiblings::apply()
{
  if (theKind == UpdateConsts::UP_INSERT_BEFORE)
  {
    ELEM_NODE(theTarget)->insertBefore(theSiblings, theDoCopy, theCopyMode);
  }
  else
  {
    ELEM_NODE(theTarget)->insertAfter(theSiblings, theDoCopy, theCopyMode);
  }
}


/*******************************************************************************

********************************************************************************/
void UpdInsertAttributes::apply()
{
  ELEM_NODE(theTarget)->insertAttributes(theAttributes, theDoCopy, theCopyMode);
}


/*******************************************************************************

********************************************************************************/
void UpdDelete::apply()
{
  theTarget->disconnect();
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceContent::apply()
{
  ELEM_NODE(theTarget)->replaceContent(BASE_NODE(theNewChild), theOldChildren);
}

/*******************************************************************************

********************************************************************************/
void UpdReplaceAttrValue::apply()
{
  ATTR_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceTextValue::apply()
{
  TEXT_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


/*******************************************************************************

********************************************************************************/
void UpdReplacePiValue::apply()
{
  PI_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceCommentValue::apply()
{
  COMMENT_NODE(theTarget)->replaceValue(theNewValue, theOldValue);
}


/*******************************************************************************

********************************************************************************/
void UpdRenameElem::apply()
{
  ELEM_NODE(theTarget)->rename(theNewName, theOldName);
}


/*******************************************************************************

********************************************************************************/
void UpdRenameAttr::apply()
{
  ATTR_NODE(theTarget)->rename(theNewName, theOldName);
}


/*******************************************************************************

********************************************************************************/
void UpdRenamePi::apply()
{
  PI_NODE(theTarget)->rename(theNewName, theOldName);
}


}
}
