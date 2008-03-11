
#include "util/Assert.h"

#include "store/naive/simple_pul.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"


namespace zorba { namespace store {


/*******************************************************************************
  Create a delete primitive in "this" pul for the given node, if another delete
  for the same node does not exist already.
********************************************************************************/
void PULImpl::addDelete(Item* node)
{
  ZORBA_ASSERT(node->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(node);

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
      if ((*updatesp)[i]->getKind() == PUL::DELETE)
        return;
    }

    DeletePrimitive* upd = new DeletePrimitive(n);

    theDeleteList.push_back(upd);

    updatesp->push_back(upd);
  }
}


/*******************************************************************************

********************************************************************************/
void PULImpl::addRename(Item* node, Item* newName)
{
  ZORBA_ASSERT(node->isNode());

  XmlNode* n = reinterpret_cast<XmlNode*>(node);
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
      if ((*updatesp)[i]->getKind() == PUL::RENAME)
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
void PULImpl::apply()
{
}


/*******************************************************************************

********************************************************************************/
void PULImpl::merge(const PUL& other)
{
}


}
}
