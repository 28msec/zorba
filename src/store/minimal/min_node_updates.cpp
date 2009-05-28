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
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_pul.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_item_factory.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"


namespace zorba { namespace storeminimal {


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
      {
        revalidationNode = currNode;
        break;
      }

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
  {
    while (revalidationNode->getParent() != NULL)
      revalidationNode = revalidationNode->getParent();

    upd.addNodeForValidation(revalidationNode);
  }
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



/*******************************************************************************
  This method is used by the undo of UpdInsertChildren and UpdReplaceChild.
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
void XmlNode::deleteChild(UpdDelete& upd)
{
  XmlNode* child = BASE_NODE(upd.theTarget);

  upd.thePos = child->disconnect();

  store::StoreConsts::NodeKind childKind = child->getNodeKind();
  store::StoreConsts::NodeKind parentKind = getNodeKind();

  if (childKind == store::StoreConsts::elementNode || 
      childKind == store::StoreConsts::attributeNode ||
      childKind == store::StoreConsts::textNode)
    removeType(upd);
  
  // Merge 2 text nodes that become adjacent due to this delete

  if (childKind == store::StoreConsts::attributeNode ||
      parentKind != store::StoreConsts::elementNode)
    return;

  if (upd.thePos == 0 || upd.thePos == numChildren())
    return;

  TextNode* rsib = reinterpret_cast<TextNode*>(getChild(upd.thePos));
  TextNode* lsib = reinterpret_cast<TextNode*>(getChild(upd.thePos - 1));

  if (lsib->getNodeKind() != store::StoreConsts::textNode ||
      rsib->getNodeKind() != store::StoreConsts::textNode)
    return;

  upd.theRightSibling = rsib;
  upd.theLeftContent = lsib->getText();

  removeChild(upd.thePos);

  xqpStringStore_t newText(new xqpStringStore(lsib->getText()->str() +
                                              rsib->getText()->str()));

  lsib->setText(newText);
}


void XmlNode::restoreChild(UpdDelete& upd)
{
  XmlNode* child = BASE_NODE(upd.theTarget);

  child->connect(this, upd.thePos);

  if (!upd.theTypeUndoList.empty())
    restoreType(upd.theTypeUndoList);

  if (upd.theRightSibling != NULL)
  {
    ZORBA_ASSERT(upd.thePos > 0);
    ZORBA_ASSERT(getChild(upd.thePos - 1)->getNodeKind() == store::StoreConsts::textNode);

    TextNode* lsib = reinterpret_cast<TextNode*>(getChild(upd.thePos - 1));
    TextNode* rsib = reinterpret_cast<TextNode*>(upd.theRightSibling.getp());

    rsib->connect(this, upd.thePos+1);
    lsib->setText(upd.theLeftContent);
  }
}


/*******************************************************************************
  Insert a set of new nodes as children of "this" node. The new children must be
  inserted in the order they appear in the given vector (newChildren). Let S and
  E be the first and last nodes in this sequence. The new nodes will be injected
  between the current children of "this" at positions pos - 1 and pos.
  Let L and R be the children at these positions (L is NULL if startPos == 0, and
  R is NULL if startPos == this->numChildren()). If L and S are both text nodes,
  S must be merged into L. Similarly, if E and R are both text nodes, E must be
  merged into R. It is assumed that the newChildren sequence does not contain
  any 2 adjecent text nodes.
********************************************************************************/
void XmlNode::insertChildren(UpdInsertChildren& upd, ulong pos)
{
  ulong numNewChildren = upd.theNewChildren.size();
  XmlNode* rsib = (pos < numChildren() ? getChild(pos) : NULL);
  XmlNode* lsib = (pos > 0 ? getChild(pos-1) : NULL);

  // Insert the new children without merging text nodes
  for (ulong i = 0; i < numNewChildren; ++i)
  {
    XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

    upd.theNewChildren[i] = 
    child->copy2(this, this, pos + i, false, false, NULL, upd.theCopyMode);
    
    upd.theNumApplied++;
  }

  // Merge adjacent text nodes (if any) on the left or right boundary.
  XmlNode* firstNew = BASE_NODE(upd.theNewChildren[0]);
  XmlNode* lastNew = BASE_NODE(upd.theNewChildren[numNewChildren-1]);

  if (lsib != NULL &&
      lsib->getNodeKind() == store::StoreConsts::textNode &&
      firstNew->getNodeKind() == store::StoreConsts::textNode)
  {
    TextNode* textNode1 = reinterpret_cast<TextNode*>(lsib);
    TextNode* textNode2 = reinterpret_cast<TextNode*>(firstNew);
    xqpStringStore_t content = textNode1->getText()->append(textNode2->getText());
    textNode2->setText(content);

    upd.theMergedNode = lsib;

    removeChild(pos-1);
  }
  else if (rsib != NULL &&
      rsib->getNodeKind() == store::StoreConsts::textNode &&
      lastNew->getNodeKind() == store::StoreConsts::textNode)
  {
    TextNode* textNode1 = reinterpret_cast<TextNode*>(lastNew);
    TextNode* textNode2 = reinterpret_cast<TextNode*>(rsib);
    xqpStringStore_t content = textNode1->getText()->append(textNode2->getText());
    textNode1->setText(content);

    upd.theMergedNode = rsib;

    removeChild(pos + numNewChildren);
  }

  if (upd.theRemoveType)
    removeType(upd);
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

********************************************************************************/
void XmlNode::undoInsertChildren(UpdInsertChildren& upd)
{
  if (upd.theNumApplied == 0)
    return;

  ulong pos = children().find(BASE_NODE(upd.theNewChildren[0]));

  ZORBA_FATAL(pos < children().size(), "");

  removeChildren(pos, upd.theNumApplied);

  if (upd.theMergedNode)
    insertChild(BASE_NODE(upd.theMergedNode), pos);

  restoreType(upd.theTypeUndoList);
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
    try
    {
      checkUniqueAttr(attr->getNodeName());
    }
    catch (error::ZorbaError& e)
    {
      if (e.theErrorCode == XQDY0025)
        upd.thePul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw e;
    }

    if (addBindingForQName(attr->theName, true, false))
      upd.theNewBindings.push_back(attr->theName);

    upd.theNewAttrs[i] =
    attr->copy2(this, this, numAttrs + i, false, false, NULL, upd.theCopyMode);

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
    try
    {
      checkUniqueAttr(attr->getNodeName());
    }
    catch (error::ZorbaError& e)
    {
      if (e.theErrorCode == XQDY0025)
        upd.thePul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw e;
    }

    if (addBindingForQName(attr->theName, true, false))
      upd.theNewBindings.push_back(attr->theName);
  
    upd.theNewAttrs[i] = 
    attr->copy2(this, this, pos + i, false, false, NULL, upd.theCopyMode);

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

  ulong numNewChildren = upd.theNewChildren.size();
  XmlNode* rsib = (pos < numChildren() - 1 ? getChild(pos+1) : NULL);
  XmlNode* lsib = (pos > 0 ? getChild(pos-1) : NULL);

  // Insert the new children without merging text nodes
  for (ulong i = 0; i < numNewChildren; i++)
  {
    XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

    upd.theNewChildren[i] =
    child->copy2(this, this, pos + i, false, false, NULL, upd.theCopyMode);

    upd.theNumApplied++;
  }

  // Remove the child that is being replaced
  removeChild(pos + numNewChildren);

  // Merge adjacent text nodes (if any) on the left and/or right boundary.
  if (numNewChildren > 0)
  {
    XmlNode* firstNew = BASE_NODE(upd.theNewChildren[0]);
    XmlNode* lastNew = BASE_NODE(upd.theNewChildren[numNewChildren-1]);

    if (lsib != NULL &&
        lsib->getNodeKind() == store::StoreConsts::textNode &&
        firstNew->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textNode1 = reinterpret_cast<TextNode*>(lsib);
      TextNode* textNode2 = reinterpret_cast<TextNode*>(firstNew);
      xqpStringStore_t content = textNode1->getText()->append(textNode2->getText());
      textNode2->setText(content);

      upd.theLeftMergedNode = lsib;

      --pos;
      removeChild(pos);
    }

    if (rsib != NULL &&
        rsib->getNodeKind() == store::StoreConsts::textNode &&
        lastNew->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textNode1 = reinterpret_cast<TextNode*>(lastNew);
      TextNode* textNode2 = reinterpret_cast<TextNode*>(rsib);
      xqpStringStore_t content = textNode1->getText()->append(textNode2->getText());
      textNode1->setText(content);
      
      upd.theRightMergedNode = rsib;
      
      removeChild(pos + numNewChildren);
    }
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

  if (upd.theLeftMergedNode)
  {
    ZORBA_ASSERT(pos > 0);
    insertChild(BASE_NODE(upd.theLeftMergedNode), pos-1);
  }

  if (upd.theRightMergedNode)
  {
    ZORBA_ASSERT(pos < numChildren() - 1);
    insertChild(BASE_NODE(upd.theRightMergedNode), pos+1);
  }

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

  if (upd.theNewChild == NULL || upd.theNewChild->getStringValue()->empty())
    return;

  if (upd.theCopyMode.theDoCopy)
  {
    TEXT_NODE(upd.theNewChild)->
    copy2(this, this, 0, false, false, NULL, upd.theCopyMode);
  }
  else
  {
    TEXT_NODE(upd.theNewChild)->switchTree(this, 0, upd.theCopyMode);
  }

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

  upd.theNewBinding = addBindingForQName(upd.theNewName, false, false);

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
    try
    {
      parent->checkUniqueAttr(upd.theNewName);
    }
    catch (error::ZorbaError& e)
    {
      if (e.theErrorCode == XQDY0025)
        upd.thePul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw e;
    }

    upd.theNewBinding = parent->addBindingForQName(upd.theNewName, true, false);
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

    if (upd.theNewContent->empty())
    {
      assert(parent);
      upd.theOldNode = this;
      upd.theOldPos = disconnect();
    }
    else
    {
      upd.theOldContent.setValue(theContent.transferValue());
      setText(upd.theNewContent);
    }

    // before calling removeType on the parent P, reset P's haveTypedValue
    // flag, so that P will not attempt to save its typed value in its
    // associated NodeTypeInfo.
    parent->resetHaveTypedValue();

    parent->removeType(upd);
  }
  else
  {
    upd.theIsTyped = false;

    if (upd.theNewContent->empty() && parent != NULL)
    {
      upd.theOldNode = this;
      upd.theOldPos = disconnect();
    }
    else
    {
      upd.theOldContent.setText(theContent.transferText());
      setText(upd.theNewContent);
    }

    if (parent)
      parent->removeType(upd);
  }
}


void TextNode::restoreValue(UpdReplaceTextValue& upd)
{
  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  if (upd.theOldNode)
  {
    parent->insertChild(BASE_NODE(upd.theOldNode), upd.theOldPos);

    parent->restoreType(upd.theTypeUndoList);

    if (upd.theIsTyped)
      parent->setHaveTypedValue();
  }
  else if (upd.theIsTyped)
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
