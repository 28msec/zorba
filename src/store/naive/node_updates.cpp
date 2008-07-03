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

#include <stack>

#include "system/globalenv.h"
#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"

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


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(TypeUndoList& undoList)
{
  XmlNode* currNode = this;

  while(currNode != NULL)
  {
    if (currNode->getNodeKind() == store::StoreConsts::elementNode)
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
    else if (currNode->getNodeKind() == store::StoreConsts::attributeNode)
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
    if (currNode->getNodeKind() == store::StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      ZORBA_FATAL(n == undoList[pos].first, "");

      n->theTypeName = undoList[pos].second.theTypeName;
    }
    else if (currNode->getNodeKind() == store::StoreConsts::attributeNode)
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
  if (getNodeKind() == store::StoreConsts::elementNode)
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
      if (child->getNodeKind() == store::StoreConsts::elementNode)
        child->setToUntyped();
    }
  }
  else if (getNodeKind() == store::StoreConsts::attributeNode)
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

      store::CopyMode copymode;
      copymode.set(false, true, true, false);

      child->switchTree(NULL, 0, copymode);
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
    std::vector<store::Item_t>& newChildren,
    ulong                       pos,
    bool                 copy,
    const store::CopyMode&      copymode)
{
  ulong numNewChildren = newChildren.size();
  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy2(this, this, pos + i, copymode);
    }
    else
    {
      child->switchTree(this, pos + i, copymode);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertChildrenFirst(
    std::vector<store::Item_t>& newChildren,
    bool                 copy,
    const store::CopyMode&      copymode)
{
  ulong numNewChildren = newChildren.size();
  for (long i = numNewChildren - 1; i >= 0; i--)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy2(this, this, 0, copymode);
    }
    else
    {
      child->switchTree(this, 0, copymode);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertChildrenLast(
    std::vector<store::Item_t>& newChildren,
    bool                 copy,
    const store::CopyMode&      copymode)
{
  insertChildren(newChildren, numChildren(), copy, copymode);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::insertSiblingsBefore(
    std::vector<store::Item_t>& siblings,
    bool                        copy,
    const store::CopyMode&      copymode)
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
    std::vector<store::Item_t>& siblings,
    bool                        copy,
    const store::CopyMode&      copymode)
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
    std::vector<store::Item_t>& newChildren,
    ulong                       pos,
    bool                        copy,
    const store::CopyMode&      copymode)
{
  removeChild(pos);

  ulong numNewChildren = newChildren.size();

  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(newChildren[i]);

    if (copy)
    {
      child->copy2(this, this, pos + i, copymode);
    }
    else
    {
      child->switchTree(this, pos + i, copymode);
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

      store::CopyMode copymode;
      copymode.set(false, true, true, false);

      attr->switchTree(NULL, 0, copymode);
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
    std::vector<store::Item_t>& attrs,
    bool                        copy,
    const store::CopyMode&      copymode)
{
  ulong numAttrs = numAttributes();
  ulong numNewAttrs = attrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(attrs[i].getp());

    checkNamespaceConflict(attr->getNodeName(), XUDY0024);
    checkUniqueAttr(attr->getNodeName());

    if (copy)
      attr->copy2(this, this, numAttrs + i, copymode);
    else
      attr->switchTree(this, numAttrs + i, copymode);

    addBindingForQName2(attr->getNodeName());
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::replaceAttribute(
    std::vector<store::Item_t>& newAttrs,
    ulong                       pos,
    bool                        copy,
    const store::CopyMode&      copymode)
{
  removeAttr(pos);

  ulong numNewAttrs = newAttrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(newAttrs[i].getp());

    checkNamespaceConflict(attr->getNodeName(), XUDY0024);
    checkUniqueAttr(attr->getNodeName());

    if (copy)
      attr->copy2(this, this, pos + i, copymode);
    else
      attr->switchTree(this, pos + i, copymode);

    addBindingForQName2(attr->getNodeName());
  }
}


/*******************************************************************************
  Disconnect all the current children of "this" and make the given text node
  the only child of "this". Return a vector of pointers to the disconnected
  children.
********************************************************************************/
void ElementNode::replaceContent(
    XmlNode*               newTextChild,
    ConstrNodeVector&      oldChildren,
    const store::CopyMode& copymode)
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

  if (newTextChild->getStringValueP()->empty())
    return;

  if (copymode.theDoCopy)
    newTextChild->copy2(this, this, 0, copymode);
  else
    newTextChild->switchTree(this, 0, copymode);
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::replaceValue(
    xqpStringStore_t& newValue,
    store::Item_t&    oldType,
    store::Item_t&    oldValue,
    uint16_t&         oldFlags)
{
  oldValue.transfer(theTypedValue);
  oldType.transfer(theTypeName);
  oldFlags = theFlags;

  theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
 
  store::Item_t item(new UntypedAtomicItemImpl(newValue));
  theTypedValue.transfer(item);
}


void AttributeNode::restoreValue(
    store::Item_t&    oldType,
    store::Item_t&    oldValue,
    uint16_t          oldFlags)
{
  theTypedValue.transfer(oldValue);
  theTypeName.transfer(oldType);
  theFlags = oldFlags;
}


/*******************************************************************************

********************************************************************************/
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
void ElementNode::rename(store::Item_t& newName, store::Item_t& oldName)
{
  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(newName.getp());

  checkNamespaceConflict(newName, XUDY0024);

  oldName.transfer(theName);
  theName.transfer(newName);

  addLocalBinding(qn->getPrefix(), qn->getNamespace());
}


void AttributeNode::rename(store::Item_t& newName, store::Item_t& oldName)
{
  if (theParent)
  {
    ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

    QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(newName.getp());
    parent->checkNamespaceConflict(newName, XUDY0024);
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


}
}
