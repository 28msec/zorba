
#include <zorba/exception.h>

#include "errors/error_manager.h"

#include "system/globalenv.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_pul.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"

#include "store/api/collection.h"

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
  ElementNode* n = ELEM_NODE(target);

  ulong numAttrs = attrs.size();
  for (ulong i = 0; i < numAttrs; i++)
  {
    n->checkNamespaceConflict(attrs[i]->getNodeName(), ZorbaError::XUDY0023);
  }

  NodeUpdates* updates;
  bool found = theNodeToUpdatesMap.get(n, updates);

  UpdInsertAttributes* upd = new UpdInsertAttributes(target, attrs, copy, copymode);
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
void PULImpl::addReplaceValue(Item_t& target, xqpStringStore* newValue)
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
void PULImpl::mergeUpdates(Item* other)
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
      else if (checkDelete && upd->getKind() == UpdateConsts::UP_DELETE)
      {
        ulong numTargetUpdates = targetUpdates->size();
        for (ulong j = 0; j < numTargetUpdates; j++)
        {
          if ((*targetUpdates)[j]->getKind() == UpdateConsts::UP_DELETE)
            continue;
        }
      }

      myList[numUpdates + i] = upd;
      targetUpdates->push_back(upd);
    }
  }

  otherList.clear();
}


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
  catch (ZorbaException& e)
  {
#ifndef NDEBUG
    std::cerr << "Exception thrown during pul::applyUpdates: "
              << std::endl <<  e << std::endl;
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
    CopyMode copymode;
    copymode.set(false, true, true, false);

    ulong numUpdates = theReplaceNodeList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdatePrimitive* upd = theReplaceNodeList[i];

      XmlNode* node = BASE_NODE(upd->getKind() == UpdateConsts::UP_REPLACE_CHILD ?
                                reinterpret_cast<UpdReplaceChild*>(upd)->theChild :
                                reinterpret_cast<UpdReplaceAttribute*>(upd)->theAttr);

      XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
      node->switchTree(tree, NULL, 0, copymode);
    }

    numUpdates = theReplaceContentList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdReplaceContent* upd;
      upd = reinterpret_cast<UpdReplaceContent*>(theReplaceContentList[i]);

      ulong numChildren = upd->theOldChildren.size();
      for (ulong j = 0; j < numChildren; j++)
      {
        XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
        upd->theOldChildren.get(j)->switchTree(tree, NULL, 0, copymode);
      }
    }

    numUpdates = theDeleteList.size();
    for (ulong i = 0; i < numUpdates; i++)
    {
      UpdDelete* upd = reinterpret_cast<UpdDelete*>(theDeleteList[i]);
      if (upd->theParent != NULL)
      {
        XmlNode* target = BASE_NODE(upd->theTarget);
        XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
        target->switchTree(tree, NULL, 0, copymode);
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

    StoreConsts::NodeKind targetKind = target->getNodeKind();
    if (targetKind == StoreConsts::elementNode || 
        targetKind == StoreConsts::attributeNode ||
        targetKind == StoreConsts::textNode)
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
    UpdateConsts::UpdPrimKind kind,
    Item_t&                   target,
    std::vector<Item_t>&      children,
    bool                      copy,
    const CopyMode&           copymode)
  :
  UpdatePrimitive(target),
  theKind(kind),
  theDoCopy(copy),
  theCopyMode(copymode)
{
  ulong numChildren = children.size();
  theChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
  {
    theChildren[i].transfer(children[i]);

    if (theRemoveType == false)
    {
      StoreConsts::NodeKind childKind = theChildren[i]->getNodeKind();
      if (childKind == StoreConsts::elementNode || childKind == StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


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
    UpdateConsts::UpdPrimKind kind,
    Item_t&                   target,
    std::vector<Item_t>&      siblings,
    bool                      copy,
    const CopyMode&           copymode)
  :
  UpdatePrimitive(target),
  theKind(kind),
  theDoCopy(copy),
  theCopyMode(copymode)
{
  ulong numSiblings = siblings.size();
  theSiblings.resize(numSiblings);
  for (ulong i = 0; i < numSiblings; i++)
  {
    theSiblings[i].transfer(siblings[i]);

    if (theRemoveType == false)
    {
      StoreConsts::NodeKind sibKind = theSiblings[i]->getNodeKind();
      if (sibKind == StoreConsts::elementNode || sibKind == StoreConsts::textNode)
        theRemoveType = true;
    }
  }
}


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
    Item_t&               target,
    std::vector<Item_t>&  attrs,
    bool                  copy,
    const CopyMode&       copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copy),
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
    Item_t&              target,
    Item_t&              child,
    std::vector<Item_t>& newChildren,
    bool                 copy,
    const CopyMode&      copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copy),
  theCopyMode(copymode)
{
  theChild.transfer(child);

  StoreConsts::NodeKind childKind = theChild->getNodeKind();
  if (childKind == StoreConsts::elementNode || childKind == StoreConsts::textNode)
    theRemoveType = true;

  ulong numChildren = newChildren.size();
  theNewChildren.resize(numChildren);
  for (ulong i = 0; i < numChildren; i++)
  {
    theNewChildren[i].transfer(newChildren[i]);

    if (theRemoveType == false)
    {
      StoreConsts::NodeKind childKind = theNewChildren[i]->getNodeKind();
      if (childKind == StoreConsts::elementNode || childKind == StoreConsts::textNode)
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
    Item_t&              target,
    Item_t&              attr,
    std::vector<Item_t>& newAttrs,
    bool                 copy,
    const CopyMode&      copymode)
  :
  UpdatePrimitive(target),
  theDoCopy(copy),
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

  target->replaceContent(BASE_NODE(theNewChild), theOldChildren,
                         theDoCopy, theCopyMode);

  target->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceContent::undo()
{
  ElementNode* target = ELEM_NODE(theTarget);
  XmlNode* child = target->getChild(0);
 
  child->disconnect();
  child->deleteTree();

  if (target->isConstructed())
  {
    ConstrElementNode* target1 = reinterpret_cast<ConstrElementNode*>(target);
    theOldChildren.copy(target1->theChildren);
  }
  else
  {
    LoadedElementNode* target1 = reinterpret_cast<LoadedElementNode*>(target);
    theOldChildren.copy(target1->theChildren); 
  }

  if (!theTypeUndoList.empty())
    target->restoreType(theTypeUndoList);
}


/*******************************************************************************

********************************************************************************/
void UpdReplaceAttrValue::apply()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->replaceValue(theNewValue, theOldValue);

  if (target->theParent)
    target->theParent->removeType(theTypeUndoList);

  theIsApplied = true;
}


void UpdReplaceAttrValue::undo()
{
  AttributeNode* target = ATTR_NODE(theTarget);

  target->replaceValue(theOldValue, theNewValue);

  if (!theTypeUndoList.empty())
    target->theParent->restoreType(theTypeUndoList);
}


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
