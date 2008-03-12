
#include "util/Assert.h"

#include "store/naive/simple_pul.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"


namespace zorba { namespace store {


/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(Item* target)
{
  ZORBA_ASSERT(target->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(target);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updatesp;
  bool found = theNodeToUpdatesMap.get(n, updatesp);

  if (!found)
  {
    DeletePrimitive* upd = new DeletePrimitive(n);

    theDeleteList.push_back(upd);

    NodeUpdates updates(1);
    updates[0] = upd;
    updatesp = &updates;
    theNodeToUpdatesMap.insert(n, updatesp);
  }
  else
  {
    ulong numUpdates = updatesp->size();

    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updatesp)[i]->getKind() == UpdateConsts::PUL_DELETE)
        return;
    }

    DeletePrimitive* upd = new DeletePrimitive(n);

    theDeleteList.push_back(upd);

    updatesp->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addReplaceContent(Item* target, Item* newChild)
{
  ZORBA_ASSERT(target->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(target);
  XmlNode* child = reinterpret_cast<XmlNode*>(newChild);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updatesp;
  bool found = theNodeToUpdatesMap.get(n, updatesp);

  if (!found)
  {
    ReplaceContentPrimitive* upd = new ReplaceContentPrimitive(n, child);

    theReplaceContentList.push_back(upd);

    NodeUpdates updates(1);
    updates[0] = upd;
    updatesp = &updates;
    theNodeToUpdatesMap.insert(n, updatesp);
  }
  else
  {
    ulong numUpdates = updatesp->size();

    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updatesp)[i]->getKind() == UpdateConsts::REPLACE_CONTENT)
      {
        ZORBA_ERROR_ALERT(ZorbaError::XUDY0015, NULL, DONT_CONTINUE_EXECUTION, "", "");
      }
    }

    ReplaceContentPrimitive* upd = new ReplaceContentPrimitive(n, child);

    theReplaceContentList.push_back(upd);

    updatesp->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addRename(Item* target, Item* newName)
{
  ZORBA_ASSERT(target->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(target);
  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(newName);

  theTreeRoots.insert(n->getTree()->getRoot());

  NodeUpdates* updatesp;
  bool found = theNodeToUpdatesMap.get(n, updatesp);

  if (!found)
  {
    RenamePrimitive* upd = new RenamePrimitive(n, qn);

    theDoFirstList.push_back(upd);

    NodeUpdates updates(1);
    updates[0] = upd;
    updatesp = &updates;
    theNodeToUpdatesMap.insert(n, updatesp);
  }
  else
  {
    ulong numUpdates = updatesp->size();

    for (ulong i = 0; i < numUpdates; i++)
    {
      if ((*updatesp)[i]->getKind() == UpdateConsts::RENAME)
      {
        ZORBA_ERROR_ALERT(ZorbaError::XUDY0015, NULL, DONT_CONTINUE_EXECUTION, "", "");
      }
    }

    RenamePrimitive* upd = new RenamePrimitive(n, qn);

    theDoFirstList.push_back(upd);

    updatesp->push_back(upd);
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
    theDeleteList[i]->theTarget->switchTree();
}


/*******************************************************************************

********************************************************************************/
void PULImpl::verify()
{
}


/*******************************************************************************

********************************************************************************/
void DeletePrimitive::apply()
{
  theTarget->disconnect();
}


/*******************************************************************************

********************************************************************************/
void ReplaceContentPrimitive::apply()
{
  theTarget->replaceElementContent(theNewChild, theOldChildren);
}


/*******************************************************************************

********************************************************************************/
void RenamePrimitive::apply()
{
  theTarget->rename(theNewName, theOldName);
}


}
}
