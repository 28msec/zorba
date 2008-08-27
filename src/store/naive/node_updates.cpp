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
#include "store/naive/node_items.h"
#include "store/naive/simple_pul.h"
#include "store/naive/atomic_items.h"
#include "store/naive/basic_item_factory.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


namespace zorba { namespace simplestore {


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(UpdatePrimitive& upd)
{
  TypeUndoList& undoList = upd.theTypeUndoList;

  zorba::store::Item* revalidationNode = NULL;
  XmlNode* currNode = this;

  while(currNode != NULL)
  {
    NodeTypeInfo tinfo;
    tinfo.theNode = currNode;

    store::StoreConsts::NodeKind nodeKind = currNode->getNodeKind();

    if (nodeKind == store::StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      if (n->theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED])
        break;

      if (n->theTypeName == GET_STORE().theSchemaTypeNames[XS_ANY])
      {
        revalidationNode = currNode;
        break;
      }

      tinfo.theTypeName.transfer(n->theTypeName);
      tinfo.theFlags = n->theFlags;

      if (n->haveTypedValue())
      {
        ZORBA_FATAL(n->numChildren() == 1, "");

        TextNode* textChild = reinterpret_cast<TextNode*>(n->getChild(0));

        xqpStringStore_t newValue = textChild->getStringValue();

        tinfo.theIsTyped = true;
        tinfo.theTextContent.setValue(textChild->theContent.transferValue());

        textChild->setText(newValue);
      }

      undoList.push_back(tinfo);

      n->theTypeName = GET_STORE().theSchemaTypeNames[XS_ANY];
      n->setHaveValue();
      n->resetIsId();
      n->resetIsIdRefs();
      n->resetHaveEmptyValue();
      n->resetHaveTypedValue();
      n->resetHaveListValue();

      revalidationNode = currNode;
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

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
    else if (nodeKind == store::StoreConsts::documentNode)
    {
      revalidationNode = currNode;
      break;
    }
    else
    {
      ZORBA_FATAL(0, "");
    }

    currNode = currNode->theParent;
  }

  if (revalidationNode != NULL)
    upd.addNodeForValidation(revalidationNode);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::restoreType(TypeUndoList& undoList)
{
  if (undoList.empty())
    return;

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
        textChild->setValue(undoList[pos].theTextContent.transferValue());
      }
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      if (undoList[pos].theTypeName != NULL)
      {
        n->theTypeName.transfer(undoList[pos].theTypeName);
        n->theFlags = undoList[pos].theFlags;
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
  This method is used by the undo of UpdInsertAttributes, and UpdReplaceAttribute.
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
void XmlNode::insertChildren(UpdInsertChildren& upd, ulong pos)
{
  if (pos == 0)
  {
    ulong numNewChildren = upd.theNewChildren.size();
    for (long i = numNewChildren - 1; i >= 0; i--)
    {
      XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

      if (upd.theCopyMode.theDoCopy)
        upd.theNewChildren[i] = child->copy2(this, this, 0, upd.theCopyMode);
      else
        child->switchTree(this, 0, upd.theCopyMode);

      upd.theNumApplied++;
    }
  }
  else
  {
    ulong numNewChildren = upd.theNewChildren.size();
    for (ulong i = 0; i < numNewChildren; i++)
    {
      XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

      if (upd.theCopyMode.theDoCopy)
        upd.theNewChildren[i] = child->copy2(this, this, pos + i, upd.theCopyMode);
      else
        child->switchTree(this, pos + i, upd.theCopyMode);

      upd.theNumApplied++;
    }
  }

  if (upd.theRemoveType)
    removeType(upd);
}


void XmlNode::undoInsertChildren(UpdInsertChildren& upd)
{
  if (upd.theNumApplied == 0)
    return;

  ulong pos = children().find(BASE_NODE(upd.theNewChildren[0]));

  ZORBA_FATAL(pos < children().size(), "");

  removeChildren(pos, upd.theNumApplied);

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT/TEXT/PI/COMMENT - INSERT SIBLINGS BEFORE
********************************************************************************/
void XmlNode::insertSiblingsBefore(UpdInsertChildren& upd)
{
  ZORBA_FATAL(theParent, "");

  XmlNode* parent = reinterpret_cast<XmlNode*>(upd.theSibling->getParent());

  ulong pos = parent->children().find(this);

  parent->insertChildren(upd, pos);
}


/*******************************************************************************
  ELEMENT/TEXT/PI/COMMENT - INSERT SIBLINGS AFTER
********************************************************************************/
void XmlNode::insertSiblingsAfter(UpdInsertChildren& upd)
{
  ZORBA_FATAL(theParent, "");

  XmlNode* parent = reinterpret_cast<XmlNode*>(upd.theSibling->getParent());

  ulong pos = parent->children().find(this);
  pos++;

  parent->insertChildren(upd, pos);
}


/*******************************************************************************
  ELEMENT - INSERT ATTRIBUTES
********************************************************************************/
void ElementNode::insertAttributes(UpdInsertAttributes& upd)
{
  ulong numAttrs = numAttributes();
  ulong numNewAttrs = upd.theNewAttrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(
                          upd.theNewAttrs[i].getp());

    checkUniqueAttr(attr->getNodeName());

    if (addBindingForQName(attr->theName, false))
      upd.theNewBindings.push_back(attr->theName);

    if (upd.theCopyMode.theDoCopy)
      upd.theNewAttrs[i] = attr->copy2(this, this, numAttrs + i, upd.theCopyMode);
    else
      attr->switchTree(this, numAttrs + i, upd.theCopyMode);

    upd.theNumApplied++;
  }

  removeType(upd);
}


void ElementNode::undoInsertAttributes(UpdInsertAttributes& upd)
{
  if (upd.theNumApplied == 0)
    return;

  ulong pos = attributes().find(BASE_NODE(upd.theNewAttrs[0]));

  ZORBA_FATAL(pos < attributes().size(), "");

  removeAttributes(pos, upd.theNumApplied);

  ulong numBindings = upd.theNewBindings.size();
  for (ulong i = 0; i < numBindings; i++)
    removeLocalBinding(upd.theNewBindings[i]->getPrefix(),
                       upd.theNewBindings[i]->getNamespace());

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT - REPLACE ATTRIBUTE
********************************************************************************/
void ElementNode::replaceAttribute(UpdReplaceAttribute& upd)
{
  ulong pos = attributes().find(BASE_NODE(upd.theAttr));
  removeAttr(pos);

  ulong numNewAttrs = upd.theNewAttrs.size();

  for (ulong i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(
                          upd.theNewAttrs[i].getp());

    checkUniqueAttr(attr->getNodeName());

    if (addBindingForQName(attr->theName, false))
      upd.theNewBindings.push_back(attr->theName);
  
    if (upd.theCopyMode.theDoCopy)
      upd.theNewAttrs[i] = attr->copy2(this, this, pos + i, upd.theCopyMode);
    else
      attr->switchTree(this, pos + i, upd.theCopyMode);

    upd.theNumApplied++;
  }

  removeType(upd);
}


void ElementNode::restoreAttribute(UpdReplaceAttribute& upd)
{
  if (upd.theNumApplied == 0)
    return;

  XmlNode* attr = BASE_NODE(upd.theAttr);

  ulong pos = attributes().find(BASE_NODE(upd.theNewAttrs[0]));

  ZORBA_FATAL(pos < attributes().size(), "");

  removeAttributes(pos, upd.theNumApplied);

  ulong numBindings = upd.theNewBindings.size();
  for (ulong i = 0; i < numBindings; i++)
    removeLocalBinding(upd.theNewBindings[i]->getPrefix(),
                       upd.theNewBindings[i]->getNamespace());

  attr->connect(this, pos);

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT/DOCUMENT - REPLACE CHILD
********************************************************************************/
void XmlNode::replaceChild(UpdReplaceChild& upd)
{
  XmlNode* child = BASE_NODE(upd.theChild);

  ulong pos = children().find(child);

  ZORBA_FATAL(pos < children().size(), "");

  removeChild(pos);

  ulong numNewChildren = upd.theNewChildren.size();

  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

    if (upd.theCopyMode.theDoCopy)
      upd.theNewChildren[i] = child->copy2(this, this, pos + i, upd.theCopyMode);
    else
      child->switchTree(this, pos + i, upd.theCopyMode);

    upd.theNumApplied++;
  }

  if (upd.theRemoveType)
  {
    // we can be here only if the target is an element node
    ElementNode* target = reinterpret_cast<ElementNode*>(this);

    // Before calling removeType on "this", reset its haveTypedValue flag,
    // so that "this" will not attempt to save its typed value in its
    // associated NodeTypeInfo.
    if (target->haveTypedValue())
    {
      target->resetHaveTypedValue();
      upd.theIsTyped = true;
    }

    removeType(upd);
  }
}


void XmlNode::restoreChild(UpdReplaceChild& upd)
{
  if (upd.theNumApplied == 0)
    return;

  XmlNode* child = BASE_NODE(upd.theChild);

  ulong pos = children().find(BASE_NODE(upd.theNewChildren[0]));

  ZORBA_FATAL(pos < children().size(), "");

  removeChildren(pos, upd.theNumApplied);

  child->connect(this, pos);

  if (upd.theRemoveType)
  {
    // we can be here only if the target is an element node
    ElementNode* target = reinterpret_cast<ElementNode*>(this);

    restoreType(upd.theTypeUndoList);

    if (upd.theIsTyped)
      target->setHaveTypedValue();
  }
}


/*******************************************************************************
  ELEMENT - REPLACE CONTENT
********************************************************************************/
void ElementNode::replaceContent(UpdReplaceElemContent& upd)
{
  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    XmlNode* child = getChild(i);
    if (child->theParent == this)
      child->theParent = NULL;
  }

  children().copy(upd.theOldChildren);
  children().clear();

  if (upd.theNewChild->getStringValue()->empty())
    return;

  if (upd.theCopyMode.theDoCopy)
    TEXT_NODE(upd.theNewChild)->copy2(this, this, 0, upd.theCopyMode);
  else
    TEXT_NODE(upd.theNewChild)->switchTree(this, 0, upd.theCopyMode);

  // Before calling removeType on "this", reset its haveTypedValue flag,
  // so that "this" will not attempt to save its typed value in its
  // associated NodeTypeInfo.
  if (haveTypedValue())
  {
    resetHaveTypedValue();
    upd.theIsTyped = true;
  }

  removeType(upd);
}


void ElementNode::restoreContent(UpdReplaceElemContent& upd)
{
  if (numChildren() > 0)
  {
    ZORBA_FATAL(numChildren() == 1, "");

    XmlNode* child = getChild(0);
 
    child->disconnect();
    child->deleteTree();
  }

  if (dynamic_cast<ElementDagNode*>(this) != NULL)
  {
    ElementDagNode* target1 = reinterpret_cast<ElementDagNode*>(this);
    upd.theOldChildren.copy(target1->theChildren);
  }
  else
  {
    ElementTreeNode* target1 = reinterpret_cast<ElementTreeNode*>(this);
    upd.theOldChildren.copy(target1->theChildren); 
  }

  restoreType(upd.theTypeUndoList);

  if (upd.theIsTyped)
    setHaveTypedValue();
}


/*******************************************************************************
  ELEMENT - RENAME
********************************************************************************/
void ElementNode::replaceName(UpdRenameElem& upd)
{
  if (upd.theNewName->equals(theName))
    return;

  upd.theNewBinding = addBindingForQName(upd.theNewName, false);

  upd.theOldName.transfer(theName);
  theName.transfer(upd.theNewName);

  if (theParent &&
      (theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED] ||
       theTypeName == GET_STORE().theSchemaTypeNames[XS_ANY]))
  {
    // Even if "this" is untyped, we must call removeType() on the parent
    // because renaming of an elelemt may require revalidation of the ancestors.
    upd.theRestoreParentType = true;
    theParent->removeType(upd);
  }
  else
  {
    removeType(upd);
  }
}


void ElementNode::restoreName(UpdRenameElem& upd)
{
  if (upd.theNewBinding)
  {
    xqpStringStore* prefix = theName->getPrefix();
    xqpStringStore* ns = theName->getNamespace();

    removeLocalBinding(prefix, ns);
  }

  theName.transfer(upd.theOldName);

  if (upd.theRestoreParentType)
    theParent->restoreType(upd.theTypeUndoList);
  else
    restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ATTRIBUTE - REPLACE VALUE
********************************************************************************/
void AttributeNode::replaceValue(UpdReplaceAttrValue& upd)
{
  upd.theOldValue.transfer(theTypedValue);

  store::Item_t newValue = new UntypedAtomicItemImpl(upd.theNewValue);
  theTypedValue.transfer(newValue);

  removeType(upd);
}


void AttributeNode::restoreValue(UpdReplaceAttrValue& upd)
{
  theTypedValue.transfer(upd.theOldValue);

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ATTRIBUTE - RENAME
********************************************************************************/
void AttributeNode::replaceName(UpdRenameAttr& upd)
{
  if (upd.theNewName->equals(theName))
    return;

  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  if (parent)
  {
    // TODO: this check should actually be done after all updates have been
    // applied because the conflicting attribute may be deleted by a later
    // update
    parent->checkUniqueAttr(upd.theNewName);

    upd.theNewBinding = parent->addBindingForQName(upd.theNewName, false);
  }

  upd.theOldName.transfer(theName);
  theName.transfer(upd.theNewName);

  if (theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
  {
    // We must call removeType() even if "this" is untyped, because renaming
    // of an attribute may require revalidation of the ancestors.
    removeType(upd);
  }
  else
  {
    // We must convert the current typed value to an untyped one.
    xqpStringStore_t strvalue = theTypedValue->getStringValue();
    store::Item_t newValue = new UntypedAtomicItemImpl(strvalue);

    upd.theOldValue.transfer(theTypedValue);
    theTypedValue.transfer(newValue);

    removeType(upd);
  }
}


void AttributeNode::restoreName(UpdRenameAttr& upd)
{
  if (theParent && upd.theNewBinding)
  {
    ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

    xqpStringStore* prefix = theName->getPrefix();
    xqpStringStore* ns = theName->getNamespace();

    parent->removeLocalBinding(prefix, ns);
  }

  theName.transfer(upd.theOldName);

  if (upd.theOldValue != NULL)
    theTypedValue.transfer(upd.theOldValue);

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  TEXT - REPLACE VALUE
********************************************************************************/
void TextNode::replaceValue(UpdReplaceTextValue& upd)
{
  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  if (isTyped())
  {
    upd.theIsTyped = true;
    upd.theOldContent.setValue(theContent.transferValue());
    setText(upd.theNewContent);

    // before calling removeType on the parent P, reset P's haveTypedValue
    // flag, so that P will not attempt to save its typed value in its
    // associated NodeTypeInfo.
    parent->resetHaveTypedValue();

    parent->removeType(upd);
  }
  else
  {
    upd.theIsTyped = false;
    upd.theOldContent.setText(theContent.transferText());
    setText(upd.theNewContent);

    if (parent)
      parent->removeType(upd);
  }
}


void TextNode::restoreValue(UpdReplaceTextValue& upd)
{
  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  if (upd.theIsTyped)
  {
    setValue(upd.theOldContent.getValue());
    upd.theOldContent.setValue(NULL);

    parent->restoreType(upd.theTypeUndoList);

    // Restore the haveTypedValue flag on P.
    parent->setHaveTypedValue();
  }
  else
  {
    setText(upd.theOldContent.getText());
    upd.theOldContent.setText(NULL);

    if (parent)
      parent->restoreType(upd.theTypeUndoList);
  }
}


/*******************************************************************************
  PI - REPLACE VALUE
********************************************************************************/
void PiNode::replaceValue(UpdReplacePiValue& upd)
{
  upd.theOldValue.transfer(theContent);
  theContent.transfer(upd.theNewValue);
}


void PiNode::restoreValue(UpdReplacePiValue& upd)
{
  theContent.transfer(upd.theOldValue);
}


/*******************************************************************************
  PI - RENAME
********************************************************************************/
void PiNode::replaceName(UpdRenamePi& upd)
{
  upd.theOldName.transfer(theTarget);
  theTarget.transfer(upd.theNewName);
}


void PiNode::restoreName(UpdRenamePi& upd)
{
  theTarget.transfer(upd.theOldName);
}


/*******************************************************************************
 COMMENT - REPLACE VALUE
********************************************************************************/
void CommentNode::replaceValue(UpdReplaceCommentValue& upd)
{
  upd.theOldValue.transfer(theContent);
  theContent.transfer(upd.theNewValue);
}


void CommentNode::restoreValue(UpdReplaceCommentValue& upd)
{
  theContent.transfer(upd.theOldValue);
}


}
}
