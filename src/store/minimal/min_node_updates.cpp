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
#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_node_updates.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_item_factory.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


namespace zorba { namespace storeminimal {


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(TypeUndoList& undoList)
{
  XmlNode* currNode = this;

  while(currNode != NULL)
  {
    NodeTypeInfo tinfo;
    tinfo.theNode = currNode;

    store::StoreConsts::NodeKind nodeKind = currNode->getNodeKind();

    if (nodeKind == store::StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      if (n->theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED] ||
          n->theTypeName == GET_STORE().theSchemaTypeNames[XS_ANY])
        break;

      tinfo.theTypeName.transfer(n->theTypeName);
      tinfo.theFlags = n->theFlags;

      if (n->haveTypedValue())
      {
        TextNode* textChild = reinterpret_cast<TextNode*>(n->getChild(0));

        xqpStringStore_t newValue = textChild->getStringValue();

        tinfo.theTextContent.setValue(textChild->getValue());
        textChild->setValue(NULL);
        tinfo.theIsTyped = true;

        textChild->setText(newValue);
      }

      undoList.push_back(tinfo);

      n->theTypeName = GET_STORE().theSchemaTypeNames[XS_ANY];
      n->resetIsId();
      n->resetIsIdRefs();
      n->setHaveValue();
      n->resetHaveEmptyValue();
      n->resetHaveTypedValue();
      n->resetHaveListValue();
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      tinfo.theTypedValue.transfer(n->theTypedValue);

      if (n->theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
      {
        undoList.push_back(tinfo);
      }
      else
      {
        tinfo.theTypeName.transfer(n->theTypeName);
        tinfo.theFlags = n->theFlags;

        undoList.push_back(tinfo);

        n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
        n->resetIsId();
        n->resetIsIdRefs();
        n->resetHaveListValue();
      }
    }
    else if (nodeKind == store::StoreConsts::textNode)
    {
      TextNode* n = reinterpret_cast<TextNode*>(currNode);

      if (n->isTyped())
      {
        tinfo.theTextContent.setValue(n->getValue());
        n->setValue(NULL);
        tinfo.theIsTyped = true;

        if (n->theParent)
        {
          ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);
          parent->resetHaveTypedValue();
        }
      }
      else
      {
        tinfo.theTextContent.setText(n->getText());
        n->setText(NULL);
        tinfo.theIsTyped = false;
      }

      undoList.push_back(tinfo);
    }
    else if (nodeKind == store::StoreConsts::documentNode)
    {
      break;
    }
    else
    {
      ZORBA_FATAL(0, "");
    }

    currNode = currNode->theParent;
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::restoreType(TypeUndoList& undoList)
{
  XmlNode* currNode = this;
  long pos = undoList.size() - 1;

  while(currNode != NULL && pos >= 0)
  {
    ZORBA_FATAL(currNode == undoList[pos].theNode, "");
 
   store::StoreConsts::NodeKind nodeKind = currNode->getNodeKind();

    if (nodeKind == store::StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      n->theTypeName = undoList[pos].theTypeName;
      n->theFlags = undoList[pos].theFlags;

      if (n->haveTypedValue())
      {
        TextNode* textChild = reinterpret_cast<TextNode*>(n->getChild(0));

        textChild->setText(NULL);
        textChild->setValue(undoList[pos].theTextContent.getValue());
        undoList[pos].theTextContent.setValue(NULL);
      }
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      n->theTypedValue.transfer(undoList[pos].theTypedValue);

      if (undoList[pos].theTypeName != NULL)
      {
        n->theTypeName.transfer(undoList[pos].theTypeName);
        n->theFlags = undoList[pos].theFlags;
      }
    }
    else if (nodeKind == store::StoreConsts::textNode)
    {
      TextNode* n = reinterpret_cast<TextNode*>(currNode);

      if (undoList[pos].theIsTyped)
      {
        n->theContent.setValue(undoList[pos].theTextContent.getValue());
        undoList[pos].theTextContent.setValue(NULL);

        if (n->theParent)
        {
          ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);
          parent->setHaveTypedValue();
        }
      }
      else
      {
        n->theContent.setText(undoList[pos].theTextContent.getText());
        undoList[pos].theTextContent.setText(NULL);
      }
    }
    else if (nodeKind == store::StoreConsts::documentNode)
    {
      break;
    }
    else
    {
      ZORBA_FATAL(0, "");
    }

    currNode = currNode->theParent;
    pos--;
  }
}


#if 0
/*******************************************************************************
  This method is commented out because the type is removed during the copying
  of the source nodes.
********************************************************************************/
void XmlNode::setToUntyped()
{
  if (getNodeKind() == store::StoreConsts::elementNode)
  {
    ElementNode* n = reinterpret_cast<ElementNode*>(this);

    n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED];

    n->setHaveValue();
    n->resetHaveEmptyValue();
    n->resetHaveTypedValue();
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
      // TODO: fix text node (if any) anyholding typed value
    }
  }
  else if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    AttributeNode* n = reinterpret_cast<AttributeNode*>(this);

    n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];

    // TODO: recompute theTypedValue
    n->resetIsId();
    n->resetIsIdRefs();
  }
  else
  {
    ZORBA_FATAL(0, "");
  }
}
#endif


/*******************************************************************************

********************************************************************************/
void XmlNode::revalidate()
{
}


/*******************************************************************************
  This method is used by the undo of UpdInsertChildren, UpdInsertSiblings, and
  UpdReplaceChild.
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
    bool                        copy,
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
    bool                        copy,
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
    {
      attr = reinterpret_cast<AttributeNode*>(
             attr->copy2(this, this, numAttrs + i, copymode));
      attrs[i] = attr;
    }
    else
    {
      attr->switchTree(this, numAttrs + i, copymode);
    }

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

  if (newTextChild->getStringValue()->empty())
    return;

  if (copymode.theDoCopy)
    newTextChild->copy2(this, this, 0, copymode);
  else
    newTextChild->switchTree(this, 0, copymode);
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


/*******************************************************************************

********************************************************************************/
void AttributeNode::replaceValue(
    xqpStringStore_t& newStrValue,
    TypeUndoList&     undoList)
{
  removeType(undoList);

  store::Item_t newValue = new UntypedAtomicItemImpl(newStrValue);
  theTypedValue.transfer(newValue);
}


void AttributeNode::restoreValue(
    TypeUndoList& undoList)
{
  ZORBA_FATAL(!undoList.empty(), "");
  restoreType(undoList);
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::replaceName(
    store::Item_t& newName,
    store::Item_t& oldName,
    TypeUndoList&  undoList)
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

  store::Item_t newValue;

  if (theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
  {
    newValue = theTypedValue;
  }
  else
  {
    xqpStringStore_t strvalue = theTypedValue->getStringValue();
    newValue = new UntypedAtomicItemImpl(strvalue);
  }

  removeType(undoList);

  theTypedValue.transfer(newValue);
}


void AttributeNode::restoreName(
    store::Item_t& oldName,
    TypeUndoList&  undoList)
{
  theName.transfer(oldName);

  if (!undoList.empty())
    restoreType(undoList);
}


/*******************************************************************************

********************************************************************************/
void TextNode::replaceValue(
    xqpStringStore_t&   newValue,
    TypeUndoList&       undoList)
{
  removeType(undoList);

  setText(newValue);
}


void TextNode::restoreValue(
    TypeUndoList&  undoList)
{
  ZORBA_FATAL(!undoList.empty(), "");
  restoreType(undoList);
}


/*******************************************************************************

********************************************************************************/
void PiNode::rename(
    xqpStringStore_t& newName,
    xqpStringStore_t& oldName)
{
  oldName.transfer(theTarget);
  theTarget.transfer(newName);
}


void PiNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  oldValue.transfer(theContent);
  theContent = newValue;
}


/*******************************************************************************

********************************************************************************/
void CommentNode::replaceValue(
    xqpStringStore_t& newValue,
    xqpStringStore_t& oldValue)
{
  oldValue.transfer(theContent);
  theContent = newValue;
}


}
}
