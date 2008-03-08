
#include "system/globalenv.h"
#include "errors/error_factory.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"

namespace zorba { namespace store {


/*******************************************************************************

********************************************************************************/
void XmlNode::setToUntyped()
{
  if (getNodeKind() == StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    n->theTypeName = GET_STORE().theUntypedType;

    n->resetIsId();
    n->resetIsIdRefs();

    ulong numAttrs = n->numAttributes();
    for (ulong i = 0; i < numAttrs; i++)
    {
      n->getAttr(i)->setToUntyped();
    }

    ulong numChildren = n->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      XmlNode* child = n->getChild(i);
      if (child->getNodeKind() == StoreConsts::elementNode)
        child->setToUntyped();
    }
  }
  else if (getNodeKind() == StoreConsts::attributeNode)
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    n->theTypeName = GET_STORE().theUntypedAtomicType;

    n->resetIsId();
    n->resetIsIdRefs();
  }
  else
  {
    ZORBA_ASSERT(0);
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(std::vector<std::pair<XmlNode*, QNameItem_t> >& undoList)
{
  if (getNodeKind() == StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    undoList.push_back(std::pair<XmlNode*, QNameItem_t>(n, n->theTypeName));

    n->resetIsId();
    n->resetIsIdRefs();

    if (! n->theTypeName->equals(GET_STORE().theUntypedType))
    {
      n->theTypeName = GET_STORE().theAnyType;

      if (n->theParent && n->theParent->getNodeKind() == StoreConsts::elementNode)
        n->theParent->removeType(undoList);
    }
  }
  else if (getNodeKind() == StoreConsts::attributeNode)
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    undoList.push_back(std::pair<XmlNode*, QNameItem_t>(n, n->theTypeName));

    n->theTypeName = GET_STORE().theUntypedAtomicType;

    n->resetIsId();
    n->resetIsIdRefs();

    if (n->theParent != NULL)
      n->theParent->removeType(undoList);
  }
  else
  {
    ZORBA_ASSERT(0);
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::revalidate()
{
}

}
}
