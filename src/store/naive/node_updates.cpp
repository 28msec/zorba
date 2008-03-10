
#include <stack>

#include "system/globalenv.h"
#include "errors/error_factory.h"
#include "util/Assert.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/node_updates.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"
#include "store/naive/basic_item_factory.h"

namespace zorba { namespace store {


/*******************************************************************************
  Disconnect all the current children of "this" and make the given text node
  the only child og "this". Return a vector of pointers to the disconnected
  children.
********************************************************************************/
void XmlNode::replaceElementContent(
    XmlNode*               newText,
    std::vector<XmlNode*>& children)
{
  ElementNode* n = reinterpret_cast<ElementNode*>(this);

  // Make a copy of the children and then disconnect all the children
  children = n->children().theNodes;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
    removeChild(i);

  appendChild(newText);
}


/*******************************************************************************
  Disconnect all the current children of "this" and make the given text node
  the only child og "this". Return a vector of pointers to the disconnected
  children.
********************************************************************************/
void XmlNode::replaceValue(xqpStringStore* newValue, xqpStringStore_t& oldValue)
{
  switch (getNodeKind())
  {
  case StoreConsts::attributeNode:
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    oldValue = n->theTypedValue->getStringValue().getStore();
    n->theTypedValue = GET_FACTORY().createUntypedAtomic(newValue);
    break;
  }
  case StoreConsts::textNode:
  {
    TextNode* n = reinterpret_cast<TextNode*>(this);

    oldValue = n->theContent;
    n->theContent = newValue;
    break;
  }
  case StoreConsts::commentNode:
  {
    CommentNode* n = reinterpret_cast<CommentNode*>(this);

    oldValue = n->theContent;
    n->theContent = newValue;
    break;
  }
  case StoreConsts::piNode:
  {
    PiNode* n = reinterpret_cast<PiNode*>(this);

    oldValue = n->theContent;
    n->theContent = newValue;
    break;
  }
  default:
  {
    ZORBA_FATAL("");
  }
  }
}


/*******************************************************************************
  Check if the ns binding implied by the given qname conflicts with the current
  ns bindings of "this" node.
********************************************************************************/
void XmlNode::checkQName(QNameItemImpl* newName)
{
  ElementNode* n;

  if (getNodeKind() == StoreConsts::elementNode)
  {
    n = reinterpret_cast<ElementNode*>(this);
  }
  else if(getNodeKind() == StoreConsts::attributeNode)
  {
    n = reinterpret_cast<ElementNode*>(theParent);
  }
  else
  {
    ZORBA_ASSERT(0);
  }

  if (n)
  {
    xqpStringStore* ns = n->findBinding(newName->getPrefixP());

    if (ns != NULL && ns->byteEqual(*newName->getNamespaceP()))
    {
      ZORBA_ERROR_ALERT_OSS(ZorbaError::XUDY0024, NULL, DONT_CONTINUE_EXECUTION,
                            "The implied namespace binding of " << newName->show()
                            << " conflicts with namespace binding ["
                            << newName->getPrefixP() << ", " 
                            << newName->getNamespaceP() << "]", "");
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::rename(QNameItemImpl* newName, Item_t& oldName)
{
  if (getNodeKind() == StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    oldName = n->theName;
    n->theName = newName;

    n->addLocalBinding(newName->getPrefixP(), newName->getNamespaceP());
  }
  else if(getNodeKind() == StoreConsts::attributeNode)
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    oldName = n->theName;
    n->theName = newName;

    if (n->theParent)
    {
      ElementNode* parent = reinterpret_cast<ElementNode*>(n->theParent);
      parent->addLocalBinding(newName->getPrefixP(), newName->getNamespaceP());
    }
  }
  else
  {
    ZORBA_ASSERT(0);
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::renamePi(xqpStringStore* newName,  xqpStringStore_t& oldName)
{
  PiNode* n = reinterpret_cast<PiNode*>(this);

  oldName = n->theTarget;
  n->theTarget = newName;
}


/*******************************************************************************

********************************************************************************/
void XmlNode::disconnect() throw()
{
  if (theParent == NULL)
    return;

  theParent->removeChild(this);
}


/*******************************************************************************
  This method is invoked at the end of applyUpdates, after we know that no
  errors may be raised.
********************************************************************************/
void XmlNode::switchTree() throw()
{
  XmlTree* oldTree = getTree();
  XmlTree* newTree = new XmlTree(this, GET_STORE().getTreeId());

  SYNC_CODE(oldTree->getRCLock().acquire());

  try
  {
    ulong refcount = 0;
    std::stack<XmlNode*> nodes;
    nodes.push(this);

    while (!nodes.empty())
    {
      XmlNode* n = nodes.top();
      nodes.pop();

      refcount += n->theRefCount;
      setTree(newTree);

      ulong numAttrs = numAttributes();
      for (ulong i = 0; i < numAttrs; i++)
      {
        XmlNode* attr = getAttr(i);
        refcount += attr->theRefCount;
        attr->setTree(newTree);
      }

      ulong numChildren = n->numChildren();
      for (ulong i = 0; i < numChildren; i++)
      {
        nodes.push(n->getChild(i));
      }
    }

    newTree->setRefCount(refcount);
    oldTree->removeReferences(refcount);
  }
  catch (...)
  {
    ZORBA_FATAL("");
  }

  SYNC_CODE(oldTree->getRCLock().release());
}



/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(TypeUndoList& undoList)
{
  if (getNodeKind() == StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    if (! n->theTypeName->equals(GET_STORE().theUntypedType))
    {
      NodeTypeInfo tinfo(n->theTypeName, n->isId(), n->isIdRefs());

      undoList.push_back(std::pair<XmlNode*, NodeTypeInfo>(n, tinfo));

      n->resetIsId();
      n->resetIsIdRefs();

      n->theTypeName = GET_STORE().theAnyType;

      if (n->theParent && n->theParent->getNodeKind() == StoreConsts::elementNode)
        n->theParent->removeType(undoList);
    }
  }
  else if (getNodeKind() == StoreConsts::attributeNode)
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    NodeTypeInfo tinfo(n->theTypeName, n->isId(), n->isIdRefs());

    undoList.push_back(std::pair<XmlNode*, NodeTypeInfo>(n, tinfo));

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
void XmlNode::revalidate()
{
}

}
}
