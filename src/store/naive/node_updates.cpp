
#include <stack>

#include "system/globalenv.h"
#include "errors/error_manager.h"
#include "util/Assert.h"

#include "store/api/copymode.h"
#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/node_updates.h"
#include "store/naive/node_items.h"
#include "store/naive/atomic_items.h"
#include "store/naive/basic_item_factory.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


namespace zorba { namespace store {


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(TypeUndoList& undoList)
{
  XmlNode* currNode = this;

  while(currNode != NULL)
  {
    if (currNode->getNodeKind() == StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      if (n->theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED])
        break;

      NodeTypeInfo tinfo(n->theTypeName, n->isId(), n->isIdRefs());

      undoList.push_back(std::pair<XmlNode*, NodeTypeInfo>(n, tinfo));

      n->theTypeName = GET_STORE().theSchemaTypeNames[XS_ANY];
      n->resetIsId();
      n->resetIsIdRefs();
    }
    else if (currNode->getNodeKind() == StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      NodeTypeInfo tinfo(n->theTypeName, n->isId(), n->isIdRefs());

      undoList.push_back(std::pair<XmlNode*, NodeTypeInfo>(n, tinfo));

      n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
      n->resetIsId();
      n->resetIsIdRefs();
    }
    else
    {
      break;
    }

    currNode = currNode->theParent;
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::restoreType(const TypeUndoList& undoList)
{
  XmlNode* currNode = this;
  long pos = undoList.size() - 1;

  while(currNode != NULL && pos >= 0)
  {
    if (currNode->getNodeKind() == StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      ZORBA_FATAL(n == undoList[pos].first, "");

      n->theTypeName = undoList[pos].second.theTypeName;
    }
    else if (currNode->getNodeKind() == StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      ZORBA_FATAL(n == undoList[pos].first, "");

      n->theTypeName = undoList[pos].second.theTypeName;
    }
    else
    {
      break;
    }

    currNode = currNode->theParent;
    pos--;
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::setToUntyped()
{
  if (getNodeKind() == StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED];

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

    n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];

    n->resetIsId();
    n->resetIsIdRefs();
  }
  else
  {
    ZORBA_FATAL(0, "");
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::revalidate()
{
}


/*******************************************************************************

********************************************************************************/
void XmlNode::removeChildren(
    ulong  pos,
    ulong  numChildren)
{
  ZORBA_FATAL(pos + numChildren <= this->numChildren(), "");

  for (ulong i = 0; i < numChildren; i++)
  {
    XmlNode* child = getChild(pos);
    XmlNode* parent = child->theParent;

    removeChild(pos);

    if (parent == this)
    {
      ZORBA_FATAL(child->getTree() == getTree(), "");

      CopyMode copymode;
      copymode.set(false, true, true, false);
      XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
      child->switchTree(tree, NULL, 0, copymode);
    }
    else
    {
      ZORBA_FATAL(child->getTree() != getTree(), "");
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertChildren(
    std::vector<Item_t>& newChildren,
    ulong                pos,
    bool                 copy,
    const CopyMode&      copymode)
{
  ulong numNewChildren = newChildren.size();
  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy(this, this, pos + i, copymode);
    }
    else
    {
      ZORBA_FATAL(child->isConstructed(), "");

      child->switchTree(getTree(), this, pos + i, copymode);

      children().insert(child, pos + i, false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertChildrenFirst(
    std::vector<Item_t>& newChildren,
    bool                 copy,
    const CopyMode&      copymode)
{
  ulong numNewChildren = newChildren.size();
  for (long i = numNewChildren - 1; i >= 0; i--)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy(this, this, 0, copymode);
    }
    else
    {
      ZORBA_FATAL(child->isConstructed(), "");

      child->switchTree(getTree(), this, 0, copymode);

      this->children().insert(child, 0, false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertChildrenLast(
    std::vector<Item_t>& newChildren,
    bool                 copy,
    const CopyMode&      copymode)
{
  insertChildren(newChildren, numChildren(), copy, copymode);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertSiblingsBefore(
    std::vector<Item_t>& siblings,
    bool                 copy,
    const CopyMode&      copymode)
{
  ZORBA_FATAL(theParent, "");

  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  ulong pos = parent->children().find(this);

  if (pos == 0)
    parent->insertChildrenFirst(siblings, copy, copymode);
  else
    parent->insertChildren(siblings, pos, copy, copymode);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertSiblingsAfter(
    std::vector<Item_t>& siblings,
    bool                 copy,
    const CopyMode&      copymode)
{
  ZORBA_FATAL(theParent, "");

  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  ulong pos = parent->children().find(this);
  pos++;

  parent->insertChildren(siblings, pos, copy, copymode);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::replaceChild(
    std::vector<Item_t>& newChildren,
    ulong                pos,
    bool                 copy,
    const CopyMode&      copymode)
{
  removeChild(pos);

  ulong numNewChildren = newChildren.size();

  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy(this, this, pos + i, copymode);
    }
    else
    {
      ZORBA_FATAL(child->isConstructed(), "");

      child->switchTree(getTree(), this, pos + i, copymode);

      children().insert(child, pos + i, false);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::removeAttributes(
    ulong  pos,
    ulong  numAttrs)
{
  ZORBA_FATAL(pos + numAttrs <= this->numAttributes(), "");

  for (ulong i = 0; i < numAttrs; i++)
  {
    XmlNode* attr = getAttr(pos);
    XmlNode* parent = attr->theParent;

    removeAttr(pos);

    if (parent == this)
    {
      ZORBA_FATAL(attr->getTree() == getTree(), "");

      CopyMode copymode;
      copymode.set(false, true, true, false);
      XmlTree* tree = new XmlTree(NULL, GET_STORE().getTreeId());
      attr->switchTree(tree, NULL, 0, copymode);
    }
    else
    {
      ZORBA_FATAL(attr->getTree() != getTree(), "");
    }
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::insertAttributes(
    std::vector<Item_t>& attrs,
    bool                 copy,
    const CopyMode&      copymode)
{
  ulong numAttrs = numAttributes();
  ulong numNewAttrs = attrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(attrs[i].getp());

    checkNamespaceConflict(attr->theName, ZorbaError::XUDY0024);
    checkUniqueAttr(attr->theName);

    if (copy)
    {
      attr->copy(this, this, numAttrs + i, copymode);
    }
    else
    {
      ZORBA_FATAL(attr->isConstructed(), "");

      attr->switchTree(getTree(), this, numAttrs + i, copymode);

      attributes().push_back(attr, false);
    }

    addBindingForQName(attr->getNodeName());
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::replaceAttribute(
    std::vector<Item_t>& newAttrs,
    ulong                pos,
    bool                 copy,
    const CopyMode&      copymode)
{
  removeAttr(pos);

  ulong numNewAttrs = newAttrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(newAttrs[i].getp());

    checkNamespaceConflict(attr->theName, ZorbaError::XUDY0024);
    checkUniqueAttr(attr->theName);

    if (copy)
    {
      attr->copy(this, this, pos + i, copymode);
    }
    else
    {
      ZORBA_FATAL(attr->isConstructed(), "");

      attr->switchTree(getTree(), this, pos + i, copymode);

      attributes().insert(attr, pos + i, false);
    }

    addBindingForQName(attr->getNodeName());
  }
}


/*******************************************************************************
  Disconnect all the current children of "this" and make the given text node
  the only child of "this". Return a vector of pointers to the disconnected
  children.
********************************************************************************/
void ElementNode::replaceContent(
    XmlNode*          newTextChild,
    ConstrNodeVector& oldChildren,
    bool              copy,
    const CopyMode&   copymode)
{
  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    XmlNode* child = getChild(i);
    if (child->theParent == this)
      child->theParent = NULL;
  }

  children().copy(oldChildren);
  children().clear();

  if (copy)
  {
    newTextChild->copy(this, this, 0, copymode);
  }
  else
  {
    ZORBA_FATAL(newTextChild->isConstructed(), "");

    newTextChild->switchTree(getTree(), this, 0, copymode);

    children().push_back(newTextChild, false);
  }
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  xqpStringStore_t tmp = theTypedValue->getStringValue();
  oldValue.transfer( tmp );
  theTypedValue = new UntypedAtomicItemImpl(newValue);
}


void TextNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  oldValue.transfer(theContent);
  theContent = newValue;
}


void PiNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  oldValue.transfer(theContent);
  theContent = newValue;
}


void CommentNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  oldValue.transfer(theContent);
  theContent = newValue;
}


/*******************************************************************************

********************************************************************************/
void ElementNode::rename(Item_t& newName, Item_t& oldName)
{
  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(newName.getp());

  checkNamespaceConflict(newName, ZorbaError::XUDY0024);

  oldName.transfer(theName);
  theName.transfer(newName);

  addLocalBinding(qn->getPrefix(), qn->getNamespace());
}


void AttributeNode::rename(Item_t& newName, Item_t& oldName)
{
  if (theParent)
  {
    ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

    QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(newName.getp());
    parent->checkNamespaceConflict(newName, ZorbaError::XUDY0024);
    parent->addLocalBinding(qn->getPrefix(), qn->getNamespace());
  }

  oldName.transfer(theName);
  theName.transfer(newName);
}


void PiNode::rename(xqpStringStore_t& newName, xqpStringStore_t& oldName)
{
  oldName.transfer(theTarget);
  theTarget.transfer(newName);
}


/*******************************************************************************
  Check if the ns binding implied by the given qname conflicts with the current
  ns bindings of "this" node.
********************************************************************************/
void ElementNode::checkNamespaceConflict(
    const Item*           qname,
    ZorbaError::ErrorCode ecode) const
{
  xqpStringStore* ns = findBinding(qname->getPrefix());

  if (ns != NULL && ns->byteEqual(*qname->getNamespace()))
  {
    ZORBA_ERROR_DESC_OSS(ecode,
                         "The implied namespace binding of " << qname->show()
                         << " conflicts with namespace binding ["
                         << qname->getPrefix()->str() << ", " 
                         << qname->getNamespace()->str() << "]");
  }
}

}
}
