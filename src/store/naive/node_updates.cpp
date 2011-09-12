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
#include "stdafx.h"

#include <stack>

#include "system/globalenv.h"
#include "diagnostics/xquery_diagnostics.h"
#include "diagnostics/assert.h"
#include "zorbatypes/datetime.h"
#include "zorbatypes/duration.h"

#include "store/api/copymode.h"
#include "store/api/collection.h"
#include "store/api/update_consts.h"

#include "store/naive/store_defs.h"
#include "store/naive/simple_store.h"
#include "store/naive/nsbindings.h"
#include "store/naive/node_items.h"
#include "store/naive/pul_primitives.h"
#include "store/naive/simple_pul.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/node_factory.h"

#include "store/api/validator.h"


namespace zorba { namespace simplestore {


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  NodeTypeInfo                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


NodeTypeInfo::~NodeTypeInfo() 
{
  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.setValue(NULL);
  else
    theTextContent.destroyText(); 
}


NodeTypeInfo::NodeTypeInfo(const NodeTypeInfo& other)
{
  theNode = other.theNode;
  theTypeName = other.theTypeName;
  theFlags = other.theFlags;
  theChildFlags = other.theChildFlags;
  
  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.copyValue(other.theTextContent.getValue());
  else
    theTextContent.copyText(other.theTextContent.getText());
}


NodeTypeInfo& NodeTypeInfo::operator=(const NodeTypeInfo& other)
{
  theNode = other.theNode;
  theTypeName = other.theTypeName;
  theFlags = other.theFlags;

  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.setValue(NULL);
  else
    theTextContent.destroyText();

  theChildFlags = other.theChildFlags;
  
  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.copyValue(other.theTextContent.getValue());
  else
    theTextContent.copyText(other.theTextContent.getText());

  return *this;
}


void NodeTypeInfo::transfer(NodeTypeInfo& other)
{
  theNode = other.theNode;
  theTypeName.transfer(other.theTypeName);
  theFlags = other.theFlags;

  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.setValue(NULL);
  else
    theTextContent.destroyText();
  
  theChildFlags = other.theChildFlags;

  if (theChildFlags & XmlNode::IsTyped)
    theTextContent.setValue(other.theTextContent.releaseValue());
  else
    theTextContent.setText(other.theTextContent);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Node Update Utils                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Make the tree rooted at "this" node a subtree of the given parent node at the
  given position among the children of the parent node.
********************************************************************************/
void XmlNode::attach(InternalNode* parent, csize pos) 
{
  ZORBA_ASSERT(theParent == NULL);
  ZORBA_ASSERT(parent != NULL);

  XmlTree* newTree = parent->getTree();
  XmlTree* oldTree = getTree();

#ifndef EMBEDED_TYPE
  newTree->copyTypesMap(oldTree);
#endif

  oldTree->setRoot(NULL);

  setTree(newTree);

  theParent = parent;

  store::StoreConsts::NodeKind nodeKind = getNodeKind();

  switch (nodeKind)
  {
  case store::StoreConsts::attributeNode:
  {
    ElementNode* elemParent = reinterpret_cast<ElementNode*>(parent);

    static_cast<AttributeNode*>(this)->
    setOrdPath(parent, false, pos, store::StoreConsts::attributeNode);

    elemParent->insertAttr(this, pos);

    break;
  }
  case store::StoreConsts::commentNode:
  {
    static_cast<CommentNode*>(this)->
    setOrdPath(parent, false, pos, getNodeKind());
    
    parent->insertChild(this, pos);

    break;
  }
  case store::StoreConsts::piNode:
  {
    static_cast<PiNode*>(this)->
    setOrdPath(parent, false, pos, getNodeKind());
    
    parent->insertChild(this, pos);

    break;
  }
  case store::StoreConsts::textNode:
  {
#ifdef TEXT_ORDPATH
    static_cast<TextNode*>(this)->
    setOrdPath(parent, false, pos, getNodeKind());
#endif

    parent->insertChild(this, pos);

    break;
  }
  case store::StoreConsts::elementNode:
  {
    ElementNode* elemRoot = reinterpret_cast<ElementNode*>(this);

    static_cast<ElementNode*>(this)->
    setOrdPath(parent, false, pos, getNodeKind());
    
    parent->insertChild(this, pos);

    std::stack<XmlNode*> nodes;
    nodes.push(this);

    while (!nodes.empty())
    {
      XmlNode* node = nodes.top();
      nodes.pop();

      if (node->getNodeKind() != store::StoreConsts::elementNode)
        continue;

      ElementNode* elem = reinterpret_cast<ElementNode*>(node);

      // Maintain recursiveness info: check if the current node is a descendant
      // of another node with the same name.
      XmlNode* ancestor = parent;
      while (ancestor != NULL &&
             ancestor->getNodeKind() == store::StoreConsts::elementNode)
      {
        ElementNode* elemAncestor = reinterpret_cast<ElementNode*>(ancestor);
        if (elemAncestor->theName->equals(elem->theName))
        {
          elemAncestor->setRecursive();
          break;
        }

        ancestor = ancestor->theParent;
      }

      // Attach the attributes of this node to the new tree.
      AttributeNode* baseUriAttr = NULL;
      AttributeNode* hiddenBaseUriAttr = NULL;
      ulong numAttrs = elem->numAttrs();

      InternalNode::iterator ite = elem->attrsBegin();
      InternalNode::iterator end = elem->attrsEnd();

      for (ulong i = 0; ite != end; ++i, ++ite)
      {
        AttributeNode* attr = static_cast<AttributeNode*>(*ite);

        attr->setTree(newTree);
        attr->theOrdPath = elem->theOrdPath;
        attr->theOrdPath.appendComp(2 * i + 1);

        if (attr->isBaseUri())
        {
          if (attr->isHidden())
            hiddenBaseUriAttr = attr;
          else
            baseUriAttr = attr;
        }
      }

      // If the current node N has a local base uri property.
      if (hiddenBaseUriAttr)
      {
        // If N's local base uri is due to an explicit base uri attribute, then
        // it must be re-resolved based on the (potentially new) base uri of the
        // parent node.
        if (baseUriAttr)
        {
          zstring absuri;
          zstring reluri;
          parent->getBaseURI(absuri);
          baseUriAttr->getBaseURI(reluri);

          elem->adjustBaseUriProperty(hiddenBaseUriAttr, absuri, reluri);
        }
        // else if N does not have an explicit base uri attribute, then N was the
        // root of the old tree, and since N is no longer a root in the new tree,
        // its local base uri must be removed.
        else
        {
          ZORBA_ASSERT(elem == elemRoot);
          csize pos;
          hiddenBaseUriAttr->disconnect(pos);
          hiddenBaseUriAttr->destroy(true);
          elem->resetHaveBaseUri();
        }
      }

      // Attach the children of this node to the new tree.
      ite = elem->childrenBegin();
      end = elem->childrenEnd();

      for (ulong i = 0; ite != end; ++i, ++ite)
      {
        XmlNode* child = (*ite);

        child->setTree(newTree);

#ifndef TEXT_ORDPATH
        if (child->getNodeKind() != store::StoreConsts::textNode)
        {
          OrdPathNode* child2 = static_cast<OrdPathNode*>(child);
          
          child2->theOrdPath = elem->theOrdPath;
          child2->theOrdPath.appendComp(2 * (numAttrs + i) + 1);
        }
#else
        static_cast<OrdPathNode*>(child)->theOrdPath = elem->theOrdPath;
        static_cast<OrdPathNode*>(child)->theOrdPath.appendComp(2 * (numAttrs + i) + 1);
#endif

        nodes.push(child);
      }
    } // done traversing tree

    break;
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }

  ulong refcount = oldTree->getRefCount();
  oldTree->getRefCount() = 0;
  oldTree->free();

  SYNC_CODE(newTree->getRCLock()->acquire());
  newTree->getRefCount() += refcount;
  SYNC_CODE(newTree->getRCLock()->release());
}


/*******************************************************************************
  Let N be "this" node. Disconnect N and its subtree NT from its containing xml
  tree T and make NT a new standalone xml tree. The method guarantees that the
  new tree will be XDM consistent. On the other hand, T may become inconsistent
  (eg, text nodes may become adjacent, but are not merged).
********************************************************************************/
void XmlNode::detach()
{
  try
  {
    ZORBA_ASSERT(theParent != NULL);

    ulong refcount = 0;

    XmlTree* oldTree = getTree();
    XmlTree* newTree = GET_STORE().getNodeFactory().createXmlTree();
    newTree->setRoot(this);

    store::StoreConsts::NodeKind nodeKind = getNodeKind();

    // ???? What we do here is not really thread-safe. For example, consider the
    // following scenario: Let T1 be "this" thread and T2 be another thread that
    // has an rchandle, rc2, on N. Right after T1 acquires the rclock on the old
    // tree, T2 tries to make a copy of rc2; as a result, T2 will block on the
    // old tree rclock. When T1 releases the old rclock, the old tree may be
    // destroyed already, so T2 will be trying to acquire a deallocated lock. 
    // Even if the old tree is there, T2 will increment the ref counter of the
    // new tree while holding the lock of the old tree. In fact, the setTree()
    // method istself is not safe (if T2 tries to copy rc2 after T1 has returned
    // from setTree(), then things are ok).
    SYNC_CODE(oldTree->getRCLock()->acquire());
    SYNC_CODE(newTree->getRCLock()->acquire());

    refcount += theRefCount;

    switch (nodeKind)
    {
    case store::StoreConsts::attributeNode:
    {
      setTree(newTree);
      theParent->removeAttr(this);
      theParent = NULL;
      break;
    }
    case store::StoreConsts::piNode:
    case store::StoreConsts::commentNode:
    {
      setTree(newTree);
      theParent->removeChild(this);
      theParent = NULL;
      break;
    }
    case store::StoreConsts::textNode:
    {
      setTree(newTree);

      reinterpret_cast<TextNode*>(this)->revertToTextContent();

      theParent->removeChild(this);
      theParent = NULL;
      break;
    }
    case store::StoreConsts::elementNode:
    {
      ElementNode* rootNode = reinterpret_cast<ElementNode*>(this);

      // If the baseUri property of N is inherited from its ancestors, make a
      // local copy of it, before disconnecting N from its parent.
      bool localBaseUri;
      zstring baseUri;
      getBaseURIInternal(baseUri, localBaseUri);
      if (!localBaseUri && !baseUri.empty())
      {
        zstring dummyUri;
        rootNode->addBaseUriProperty(baseUri, dummyUri);
      }

      std::stack<XmlNode*> nodes;

      nodes.push(this);

      while (!nodes.empty())
      {
        XmlNode* node = nodes.top();
        nodes.pop();

        if (node->getNodeKind() == store::StoreConsts::elementNode)
        {
          ElementNode* elemNode = reinterpret_cast<ElementNode*>(node);

#ifndef EMBEDDED_TYPE
          store::Item_t type;

          if (elemNode->haveType())
          {
            type = elemNode->getType();
            oldTree->removeType(elemNode);
            node->setTree(newTree);
            elemNode->setType(type);
          }
          else
          {
            node->setTree(newTree);
          }
#else
          node->setTree(newTree);
#endif
          // Preserve the namespace bindings of the current node
          NsBindingsContext* nsContext = elemNode->getNsContext();
          NsBindingsContext* parentNsContext = NULL;

          if (elemNode->theParent->getNodeKind() == store::StoreConsts::elementNode)
          {
            parentNsContext = reinterpret_cast<ElementNode*>(elemNode->theParent)->
                              getNsContext();
          }

          // If the current node is N, or a node in NT that does not inherit ns
          // bindings directly from its parent (but may inherit from some other
          // ancestor).
          if (elemNode == rootNode ||
              nsContext == NULL ||
              (elemNode->haveLocalBindings() &&
               nsContext->getParent() != parentNsContext) ||
              nsContext != parentNsContext)
          {
            if (nsContext != NULL)
            {
              std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
              getNamespaceBindings(ctx->getBindings());
            
              if (!ctx->empty())
              {
                elemNode->theNsContext = ctx.release();
                elemNode->theFlags |= HaveLocalBindings;
              }
            }
          }

          // Else the current node is not N and it inherits ns bindings directly
          // from its parent.
          else
          {
            if (elemNode->haveLocalBindings())
            {
              elemNode->theNsContext =
                new NsBindingsContext(elemNode->getLocalBindings());
            }

            elemNode->setNsContext(parentNsContext);
          }

          // Detach the attributes of the current node
          InternalNode::iterator ite = elemNode->attrsBegin();
          InternalNode::iterator end = elemNode->attrsEnd();
          
          for (; ite != end; ++ite)
          {
            XmlNode* attr = (*ite);
            refcount += attr->theRefCount;
            attr->setTree(newTree);
          }

          // Detach the children of the current node
          ite = elemNode->childrenBegin();
          end = elemNode->childrenEnd();

          for (; ite != end; ++ite)
          {
            XmlNode* child = (*ite);
            refcount += child->theRefCount;
            nodes.push(child);
          }
        }
        else
        {
          node->setTree(newTree);
        }
      } // done traversing tree

      theParent->removeChild(this);
      theParent = NULL;

      break;
    }
    default:
    {
      ZORBA_ASSERT(false);
    }
    }

    newTree->getRefCount() += refcount;
    if (newTree->getRefCount() == 0)
    {
      SYNC_CODE(newTree->getRCLock()->release());
      newTree->free();
    }
    else
    {
      SYNC_CODE(newTree->getRCLock()->release());
    }

    oldTree->getRefCount() -= refcount;
    if (oldTree->getRefCount() == 0)
    {
      SYNC_CODE(oldTree->getRCLock()->release());
      oldTree->free();
    }
    else
    {
      SYNC_CODE(oldTree->getRCLock()->release());
    }
  }
  catch(...)
  {
    ZORBA_FATAL(0, "Unexpected exception");
  }
}



/*******************************************************************************
  This method is used by the undo of UpdInsertChildren and UpdReplaceChild.
********************************************************************************/
void InternalNode::removeChildren(csize pos, csize numChildren)
{
  ZORBA_FATAL(pos + numChildren <= this->numChildren(), "");

  for (csize i = 0; i < numChildren; ++i)
  {
    XmlNode* child = getChild(pos);
    child->detach();
  }
}


/*******************************************************************************
  This method is used by the undo of UpdInsertAttributes, and UpdReplaceAttribute.
********************************************************************************/
void ElementNode::removeAttributes(csize pos, csize numAttrs)
{
  ZORBA_FATAL(pos + numAttrs <= this->numAttrs(), "");

  for (csize i = 0; i < numAttrs; ++i)
  {
    XmlNode* attr = getAttr(pos);
    attr->detach();
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Node Update Primitives                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void XmlNode::removeType(UpdatePrimitive& upd)
{
  TypeUndoList& undoList = upd.theTypeUndoList;
  ulong undoSize = (ulong)undoList.size();

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

      if (n->getType()->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED]))
      {
        revalidationNode = currNode;
        break;
      }

      if (n->getType()->equals(GET_STORE().theSchemaTypeNames[XS_ANY]))
      {
        revalidationNode = currNode;
        break;
      }

#ifdef EMBEDED_TYPE
      tinfo.theTypeName.transfer(n->theTypeName);
      n->theTypeName = GET_STORE().theSchemaTypeNames[XS_ANY];
#else
      assert(n->haveType());
      tinfo.theTypeName = n->getType();
      n->setType(GET_STORE().theSchemaTypeNames[XS_ANY]);
#endif
      tinfo.theFlags = n->theFlags;

      if (n->haveTypedTypedValue())
      {
        TextNode* textChild = reinterpret_cast<TextNode*>(n->getChild(0));

        zstring textValue;
        textChild->getStringValue2(textValue);

        tinfo.theChildFlags = textChild->theFlags;
        tinfo.theTextContent.setValue(textChild->theContent.releaseValue());

        textChild->theFlags &= ~IsTyped;
        textChild->setText(textValue);
      }

      undoList.resize(++undoSize);
      undoList[undoSize - 1].transfer(tinfo);

      n->setHaveValue();
      n->resetHaveEmptyValue();
      n->resetInSubstGroup();

      revalidationNode = currNode;
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      if (n->getType()->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC]))
      {
        undoList.resize(++undoSize);
        undoList[undoSize - 1].transfer(tinfo);
      }
      else
      {
#ifdef EMBEDED_TYPE
        tinfo.theTypeName.transfer(n->theTypeName);
        n->theTypeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
#else
        assert(n->haveType());
        tinfo.theTypeName = n->getType();
        n->setType(GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC]);
#endif

        tinfo.theFlags = n->theFlags;

        undoList.resize(++undoSize);
        undoList[undoSize - 1].transfer(tinfo);

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

  ulong pos = 0;
  ulong numNodes = (ulong)undoList.size();
  XmlNode* currNode = this;

  while(currNode != NULL && pos < numNodes)
  {
    ZORBA_FATAL(currNode == undoList[pos].theNode, "");
 
    store::StoreConsts::NodeKind nodeKind = currNode->getNodeKind();

    NodeTypeInfo& tinfo = undoList[pos];

    if (nodeKind == store::StoreConsts::elementNode)
    {
      ElementNode* n = reinterpret_cast<ElementNode*>(currNode);

      n->setType(tinfo.theTypeName);
      n->theFlags = tinfo.theFlags;

      if (tinfo.theChildFlags & IsTyped)
      {
        ZORBA_ASSERT(n->numChildren() == 1 &&
                     n->getChild(0)->getNodeKind() == store::StoreConsts::textNode);

        TextNode* textChild = reinterpret_cast<TextNode*>(n->getChild(0));

        if (!textChild->isTyped())
        {
          textChild->theFlags = tinfo.theChildFlags;
          textChild->destroyText();
          textChild->setValue(tinfo.theTextContent.releaseValue());
        }
        else
        {
          ZORBA_ASSERT(textChild->getValue()->equals(
                       tinfo.theTextContent.getValue()));
        }
      }
    }
    else if (nodeKind == store::StoreConsts::attributeNode)
    {
      AttributeNode* n = reinterpret_cast<AttributeNode*>(currNode);

      if (tinfo.theTypeName != NULL)
      {
        n->setType(tinfo.theTypeName);
        n->theFlags = tinfo.theFlags;
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
    ++pos;
  }
}


/*******************************************************************************

********************************************************************************/
void InternalNode::deleteChild(UpdDelete& upd)
{
  XmlNode* child = BASE_NODE(upd.theTarget);

  // For now, just diconnect but do not detach the child. This way, undo becomes
  // easy as we just have to connect the child back to it parent. The child will
  // be detached later, after all updates have been applied with no errors (see.
  // applyUpdates() method). 
  csize pos;
  if (! child->disconnect(pos))
    return;

  upd.thePos = pos;
  upd.theIsApplied = true;

  if (upd.theRemoveType)
    removeType(upd);
  
  // Merge 2 text nodes that become adjacent due to this delete

  store::StoreConsts::NodeKind childKind = child->getNodeKind();
  store::StoreConsts::NodeKind parentKind = getNodeKind();

  if (childKind == store::StoreConsts::attributeNode ||
      parentKind != store::StoreConsts::elementNode)
    return;

  // Note: numChildren() returns the number of children AFTER the child deletion
  if (pos == 0 || pos == numChildren())
    return;

  XmlNode* rsib = getChild(pos);
  XmlNode* lsib = getChild(pos - 1);

  if (lsib->getNodeKind() != store::StoreConsts::textNode ||
      rsib->getNodeKind() != store::StoreConsts::textNode)
    return;

  TextNode* t_rsib = reinterpret_cast<TextNode*>(rsib);
  TextNode* t_lsib = reinterpret_cast<TextNode*>(lsib);

  upd.theRsib = t_rsib;
  upd.theLsib = t_lsib;

  zstring newText = t_lsib->getText();
  newText += t_rsib->getText();

  upd.theNewTextNode = GET_NODE_FACTORY().createTextNode(this->getTree(),
                                                         this,
                                                         false,
                                                         pos+1,
                                                         newText);
  removeChild(pos);
  removeChild(pos-1);
}


void InternalNode::restoreChild(UpdDelete& upd)
{
  if (!upd.theIsApplied)
    return;

  XmlNode* child = BASE_NODE(upd.theTarget);
  csize pos = upd.thePos;

  if (upd.theNewTextNode)
  {
    ZORBA_ASSERT(pos > 0);
    ZORBA_ASSERT(getChild(pos - 1) == upd.theNewTextNode);

    upd.theRsib->connect(this, pos);
    child->connect(this, pos);
    upd.theLsib->connect(this, pos);
    
    upd.theNewTextNode->detach();
  }
  else
  {
    child->connect(this, pos);
  }

  if (!upd.theTypeUndoList.empty())
    restoreType(upd.theTypeUndoList);
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
  any 2 adjacent text nodes.

  Note: L and R cannot both be text nodes, so at most one merging of text nodes
  will be performed.
********************************************************************************/
void InternalNode::insertChildren(UpdInsertChildren& upd, csize pos)
{
  assert(pos <= numChildren());

  csize numNewChildren = upd.theNewChildren.size();
  XmlNode* rsib = (pos < numChildren() ? getChild(pos) : NULL);
  XmlNode* lsib = (pos > 0 ? getChild(pos-1) : NULL);

  // Do this before inserting the new children, so that if "this" has a
  // single typed text child, its typed value will be saved and the child
  // will be converted to an untyped text child.
  if (upd.theRemoveType)
    removeType(upd);

  // Insert the new children without merging text nodes
  for (ulong i = 0; i < numNewChildren; ++i)
  {
    XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

    child->attach(this, pos + i);
    
    if (getNodeKind() == store::StoreConsts::elementNode &&
        child->getNodeKind() == store::StoreConsts::elementNode &&
        upd.thePul->inheritNSBindings())
    {
      static_cast<ElementNode*>(child)->
      setNsContext(static_cast<ElementNode*>(this)->getNsContext());
    }

    upd.theNumApplied++;
  }

  // Merge adjacent text nodes (if any) on the left or right boundary.
  XmlNode* firstNew = BASE_NODE(upd.theNewChildren[0]);
  XmlNode* lastNew = BASE_NODE(upd.theNewChildren[numNewChildren-1]);

  if (lsib != NULL &&
      lsib->getNodeKind() == store::StoreConsts::textNode &&
      firstNew->getNodeKind() == store::StoreConsts::textNode)
  {
    TextNode* textNode1 = static_cast<TextNode*>(lsib);
    TextNode* textNode2 = static_cast<TextNode*>(firstNew);

    zstring content1;
    textNode1->getStringValue2(content1);

    zstring content2;
    content2.reserve(content1.size() + textNode2->getText().size());
    content2 = content1;
    content2 += textNode2->getText();

    textNode2->setText(content2);

    upd.theMergedNode = lsib;

    removeChild(pos-1);
  }
  else if (rsib != NULL &&
      rsib->getNodeKind() == store::StoreConsts::textNode &&
      lastNew->getNodeKind() == store::StoreConsts::textNode)
  {
    TextNode* textNode1 = reinterpret_cast<TextNode*>(lastNew);
    TextNode* textNode2 = reinterpret_cast<TextNode*>(rsib);

    zstring content2;
    textNode2->getStringValue2(content2);

    zstring content1;
    content1.reserve(textNode1->getText().size() + content2.size());
    content1 = textNode1->getText();
    content1 += content2;

    textNode1->setText(content1);

    upd.theMergedNode = rsib;

    removeChild(pos + numNewChildren);
  }
}


/*******************************************************************************
  ELEMENT/TEXT/PI/COMMENT - INSERT SIBLINGS BEFORE
********************************************************************************/
void XmlNode::insertSiblingsBefore(UpdInsertChildren& upd)
{
  ZORBA_FATAL(theParent, "");

  InternalNode* parent = static_cast<InternalNode*>(upd.theSibling->getParent());

  csize pos = parent->findChild(this);

  parent->insertChildren(upd, pos);
}


/*******************************************************************************
  ELEMENT/TEXT/PI/COMMENT - INSERT SIBLINGS AFTER
********************************************************************************/
void XmlNode::insertSiblingsAfter(UpdInsertChildren& upd)
{
  ZORBA_FATAL(theParent, "");

  InternalNode* parent = static_cast<InternalNode*>(upd.theSibling->getParent());

  csize pos = parent->findChild(this);
  pos++;

  parent->insertChildren(upd, pos);
}


/*******************************************************************************

********************************************************************************/
void InternalNode::undoInsertChildren(UpdInsertChildren& upd)
{
  if (upd.theNumApplied == 0)
    return;

  csize pos = findChild(BASE_NODE(upd.theNewChildren[0]));

  ZORBA_FATAL(pos < numChildren(), "");

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
  csize numAttrs = this->numAttrs();
  csize numNewAttrs = upd.theNewAttrs.size();

  removeType(upd);

  for (csize i = 0; i < numNewAttrs; i++)
  {
    AttributeNode* attr = reinterpret_cast<AttributeNode*>(
                          upd.theNewAttrs[i].getp());
    try
    {
      checkUniqueAttr(attr->getNodeName());
    }
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XQDY0025)
        upd.theCollectionPul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw;
    }

    if (addBindingForQName(attr->theName, true, false))
    {
      upd.theNewBindings.push_back(attr->theName);
    }

    attr->attach(this, numAttrs + i);

    if (!upd.thePul->inheritNSBindings())
    {
      csize numChildren = this->numChildren();

      for (csize i = 0; i < numChildren; ++i)
      {
        if (getChild(i)->getNodeKind() == store::StoreConsts::elementNode)
        {
          static_cast<ElementNode*>(getChild(i))->
            uninheritBinding(theNsContext, attr->theName->getPrefix());
        }
      }  
    }

    upd.theNumApplied++;
  }
}


void ElementNode::undoInsertAttributes(UpdInsertAttributes& upd)
{
  if (upd.theNumApplied == 0)
    return;

  csize pos = findAttr(BASE_NODE(upd.theNewAttrs[0]));

  ZORBA_FATAL(pos < numAttrs(), "");

  removeAttributes(pos, upd.theNumApplied);

  csize numBindings = upd.theNewBindings.size();
  for (csize i = 0; i < numBindings; ++i)
  {
    removeLocalBinding(upd.theNewBindings[i]->getPrefix(),
                       upd.theNewBindings[i]->getNamespace());
  }

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT - REPLACE ATTRIBUTE
********************************************************************************/
void ElementNode::replaceAttribute(UpdReplaceAttribute& upd)
{
  removeType(upd);

  AttributeNode* oldAttr = ATTR_NODE(upd.theAttr);

  csize pos;
  oldAttr->disconnect(pos);

  upd.thePos = pos;

  csize numNewAttrs = upd.theNewAttrs.size();

  for (csize i = 0; i < numNewAttrs; ++i)
  {
    AttributeNode* attr = static_cast<AttributeNode*>(upd.theNewAttrs[i].getp());
    try
    {
      checkUniqueAttr(attr->getNodeName());
    }
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XQDY0025)
        upd.theCollectionPul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw;
    }

    bool newBinding = addBindingForQName(attr->theName, true, false);

    if (newBinding)
      upd.theNewBindings.push_back(attr->theName);
  
    attr->attach(this, pos + i);

    if (newBinding && !upd.thePul->inheritNSBindings())
    {
      iterator ite = childrenBegin();
      iterator end = childrenEnd();

      for (; ite != end; ++ite)
      {
        if ((*ite)->getNodeKind() == store::StoreConsts::elementNode)
        {
          static_cast<ElementNode*>((*ite))->
          uninheritBinding(theNsContext, attr->theName->getPrefix());
        }
      }  
    }

    upd.theNumApplied++;
  }
}


void ElementNode::restoreAttribute(UpdReplaceAttribute& upd)
{
  if (upd.theNumApplied == 0)
  {
    if (upd.theIsApplied)
    {
      XmlNode* attr = BASE_NODE(upd.theAttr);
      attr->connect(this, upd.thePos);
      restoreType(upd.theTypeUndoList);
    }

    return;
  }

  XmlNode* attr = BASE_NODE(upd.theAttr);

  csize pos = findAttr(BASE_NODE(upd.theNewAttrs[0]));

  ZORBA_FATAL(pos < numAttrs(), "");

  removeAttributes(pos, upd.theNumApplied);

  csize numBindings = upd.theNewBindings.size();
  for (csize i = 0; i < numBindings; ++i)
    removeLocalBinding(upd.theNewBindings[i]->getPrefix(),
                       upd.theNewBindings[i]->getNamespace());

  attr->connect(this, pos);

  restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT/DOCUMENT - REPLACE CHILD
********************************************************************************/
void InternalNode::replaceChild(UpdReplaceChild& upd)
{
  XmlNode* child = BASE_NODE(upd.theChild);

  csize numNewChildren = upd.theNewChildren.size();

  if (numNewChildren == 0)
  {
    csize pos;
    bool found = child->disconnect(pos);
    ZORBA_ASSERT(found);

    upd.thePos = pos;
    upd.theIsApplied = true;

    if (upd.theRemoveType)
      removeType(upd);
  
    // Note: numChildren() returns the number of children AFTER the child deletion
    if (pos == 0 || pos == numChildren())
      return;

    XmlNode* rsib = getChild(pos);
    XmlNode* lsib = getChild(pos - 1);

    if (lsib->getNodeKind() != store::StoreConsts::textNode ||
        rsib->getNodeKind() != store::StoreConsts::textNode)
      return;

    TextNode* t_rsib = reinterpret_cast<TextNode*>(rsib);
    TextNode* t_lsib = reinterpret_cast<TextNode*>(lsib);

    upd.theRsib = t_rsib;
    upd.theLsib = t_lsib;

    zstring newText = t_lsib->getText();
    newText += t_rsib->getText();

    upd.theNewTextNode = GET_NODE_FACTORY().createTextNode(this->getTree(),
                                                           this,
                                                           false,
                                                           pos+1,
                                                           newText);
    removeChild(pos);
    removeChild(pos-1);
  }
  else
  {
    csize pos = findChild(child);

    if (pos >= numChildren())
      return;

    upd.thePos = pos;
    upd.theIsApplied = true;

    if (upd.theRemoveType)
      removeType(upd);

    XmlNode* rsib = (pos < numChildren() - 1 ? getChild(pos+1) : NULL);
    XmlNode* lsib = (pos > 0 ? getChild(pos-1) : NULL);

    // Insert the new children without merging text nodes
    for (csize i = 0; i < numNewChildren; ++i)
    {
      XmlNode* child = BASE_NODE(upd.theNewChildren[i]);

      child->attach(this, pos + i);

      if (getNodeKind() == store::StoreConsts::elementNode &&
          child->getNodeKind() == store::StoreConsts::elementNode &&
          upd.thePul->inheritNSBindings())
      {
        static_cast<ElementNode*>(child)->
          setNsContext(static_cast<ElementNode*>(this)->getNsContext());
      }
      
      upd.theNumApplied++;
    }
    
    // Remove the child that is being replaced
    removeChild(pos + numNewChildren);

    // Merge adjacent text nodes (if any) on the left and/or right boundary.
    XmlNode* firstNew = BASE_NODE(upd.theNewChildren[0]);
    XmlNode* lastNew = BASE_NODE(upd.theNewChildren[numNewChildren-1]);

    if (lsib != NULL &&
        lsib->getNodeKind() == store::StoreConsts::textNode &&
        firstNew->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textNode1 = reinterpret_cast<TextNode*>(lsib);
      TextNode* textNode2 = reinterpret_cast<TextNode*>(firstNew);
      
      upd.theLsib = lsib;

      zstring newText;
      newText.reserve(textNode1->getText().size() + textNode2->getText().size());
      newText = textNode1->getText();
      newText += textNode2->getText();
    
      // Note: we can update in-place textNode2 because it is a brand new node that
      // cannot be referenced anywhere outside this pul.
      textNode2->setText(newText);

      --pos;
      removeChild(pos);
    }
    
    if (rsib != NULL &&
        rsib->getNodeKind() == store::StoreConsts::textNode &&
        lastNew->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textNode1 = reinterpret_cast<TextNode*>(lastNew);
      TextNode* textNode2 = reinterpret_cast<TextNode*>(rsib);
      
      upd.theRsib = rsib;

      zstring newText;
      newText.reserve(textNode1->getText().size() + textNode2->getText().size());
      newText = textNode1->getText();
      newText += textNode2->getText();
      
      textNode1->setText(newText);
      
      removeChild(pos + numNewChildren);
    }
  }
}


void InternalNode::restoreChild(UpdReplaceChild& upd)
{
  XmlNode* child = BASE_NODE(upd.theChild);

  csize numNewChildren = upd.theNewChildren.size();

  if (numNewChildren == 0)
  {
    if (!upd.theIsApplied)
      return;

    csize pos = upd.thePos;

    if (upd.theNewTextNode)
    {
      ZORBA_ASSERT(pos > 0);
      ZORBA_ASSERT(getChild(pos - 1) == upd.theNewTextNode.getp());
      
      upd.theRsib->connect(this, pos);
      child->connect(this, pos);
      upd.theLsib->connect(this, pos);
      
      upd.theNewTextNode->detach();
    }
    else
    {
      child->connect(this, pos);
    }
  }
  else
  {
    if (upd.theNumApplied == 0)
      return;

    csize pos = upd.thePos;

    if (upd.theLsib)
    {
      ZORBA_ASSERT(pos > 0);
      upd.theLsib->connect(this, pos-1);
    }

    ZORBA_ASSERT(getChild(pos) == upd.theNewChildren[0].getp());

    removeChildren(pos, upd.theNumApplied);

    child->connect(this, pos);

    if (upd.theRsib)
    {
      upd.theRsib->connect(this, pos + numNewChildren);
      ZORBA_ASSERT(pos < numChildren() - 1);
    }
  }

  if (upd.theRemoveType)
    restoreType(upd.theTypeUndoList);
}


/*******************************************************************************
  ELEMENT - REPLACE CONTENT
********************************************************************************/
void ElementNode::replaceContent(UpdReplaceElemContent& upd)
{
  upd.theOldChildren.insert(upd.theOldChildren.begin(),
                            childrenBegin(),
                            childrenEnd());

  theNodes.resize(theNumAttrs);

  if (upd.theNewChild == NULL || upd.theNewChild->getStringValue().empty())
    return;

#ifndef ZORBA_NO_XMLSCHEMA
  if ( upd.thePul->getValidator()->isPossibleSimpleContentRevalidation(getType()) )
  {
    std::vector<store::Item_t> result;
    upd.thePul->getValidator()->validateSimpleContent(getType(), 
                                                      upd.theNewChild->getStringValue(),
                                                      result);
    
    GENV_ITEMFACTORY->createTextNode(upd.theNewChild, this, result);
  }
  else
#endif
  {
    TextNode* newChild = TEXT_NODE(upd.theNewChild);
    
    XmlTree* oldTree = newChild->getTree();
    XmlTree* newTree = getTree();
    
    oldTree->setRoot(NULL);
    delete oldTree;
    
    SYNC_CODE(newTree->getRCLock()->acquire());
    newTree->getRefCount() += 1;
    SYNC_CODE(newTree->getRCLock()->release());
    
    newChild->setTree(newTree);
#ifdef TEXT_ORDPATH
    newChild->setOrdPath(this, true, 0, store::StoreConsts::textNode);
#endif
    newChild->connect(this, 0);
    
    upd.theNewChild = NULL;
    
    removeType(upd);
  }
}


void ElementNode::restoreContent(UpdReplaceElemContent& upd)
{
  if (numChildren() > 0)
  {
    ZORBA_FATAL(numChildren() == 1, "");

    XmlNode* child = getChild(0);
 
    child->destroy(true);
  }

  ElementNode* target1 = reinterpret_cast<ElementNode*>(this);
  target1->theNodes.insert(childrenBegin(),
                           upd.theOldChildren.begin(),
                           upd.theOldChildren.end()); 

  restoreType(upd.theTypeUndoList);
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

  if (upd.theNewBinding && 
      (!upd.thePul->inheritNSBindings() ||  theName->getPrefix().empty()))
  {
    iterator ite = childrenBegin();
    iterator end = childrenEnd();

    for (; ite != end; ++ite)
    {
      if ((*ite)->getNodeKind() == store::StoreConsts::elementNode)
      {
        static_cast<ElementNode*>((*ite))->
        uninheritBinding(theNsContext, theName->getPrefix());
      }
    }  
  }

  store::Item* typeName = getType();

  if (theParent &&
      (typeName->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED]) ||
       typeName->equals(GET_STORE().theSchemaTypeNames[XS_ANY])))
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
    const zstring& prefix = theName->getPrefix();
    const zstring& ns = theName->getNamespace();

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

#ifndef ZORBA_NO_XMLSCHEMA
  if ( upd.thePul->getValidator()->isPossibleSimpleContentRevalidation(getType()) )
  {
    std::vector<store::Item_t> result;
    upd.thePul->getValidator()->validateSimpleContent(getType(), 
                                                      upd.theNewValue,
                                                      result);
    
    if ( result.size()==1 )
      theTypedValue.transfer(result[0]);
    else
    {
      theTypedValue = new ItemVector(result) ;
    }
  }
  else
#endif
  {
    store::Item_t newValue;
    GET_STORE().getItemFactory()->createUntypedAtomic(newValue, upd.theNewValue);
    theTypedValue.transfer(newValue);
    removeType(upd);
  }
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
    catch (ZorbaException const& e)
    {
      if (e.diagnostic() == err::XQDY0025)
        upd.theCollectionPul->thePrimitivesToRecheck.push_back(&upd);
      else
        throw;
    }

    upd.theNewBinding = parent->addBindingForQName(upd.theNewName, true, false);

    if (upd.theNewBinding && !upd.thePul->inheritNSBindings())
    {
      InternalNode::iterator ite = parent->childrenBegin();
      InternalNode::iterator end = parent->childrenEnd();

      for (; ite != end; ++ite)
      {
        if ((*ite)->getNodeKind() == store::StoreConsts::elementNode)
        {
          static_cast<ElementNode*>((*ite))->
          uninheritBinding(parent->theNsContext, upd.theNewName->getPrefix());
        }
      }
    }
  }

  upd.theOldName.transfer(theName);
  theName.transfer(upd.theNewName);

  if (getType()->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC]))
  {
    // We must call removeType() even if "this" is untyped, because renaming
    // of an attribute may require revalidation of the ancestors.
    removeType(upd);
  }
  else
  {
    // We must convert the current typed value to an untyped one.
    zstring strvalue;
    theTypedValue->getStringValue2(strvalue);
    store::Item_t newValue;
    GET_STORE().getItemFactory()->createUntypedAtomic(newValue, strvalue);

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

    parent->removeLocalBinding(theName->getPrefix(), theName->getNamespace());
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
  InternalNode* parent = theParent;

#ifndef ZORBA_NO_XMLSCHEMA
  if ( upd.thePul->getValidator()->isPossibleSimpleContentRevalidation(getType()) )
  {
    if (isTyped())
    {
      assert(parent);
      upd.theIsTyped = true;
    }
    else
    {
      upd.theIsTyped = false;
      upd.theOldContent.setText(theContent);
    }

    std::vector<store::Item_t> result;
    upd.thePul->getValidator()->validateSimpleContent(getType(), 
                                                      upd.theNewContent,
                                                      result);
    
    if ( result.size()==1 )
      setValue(result[0]);
    else
      setValue( new ItemVector(result) );
  }
  else
#endif
  {
    if (parent)
      parent->removeType(upd);
    
    if (isTyped())
    {
      assert(parent);
      upd.theIsTyped = true;
    }
    else
    {
      upd.theIsTyped = false;
      upd.theOldContent.setText(theContent);
    }

    setText(upd.theNewContent);
  }
}


void TextNode::restoreValue(UpdReplaceTextValue& upd)
{
  ElementNode* parent = reinterpret_cast<ElementNode*>(theParent);

  if (upd.theIsTyped)
  {
    parent->restoreType(upd.theTypeUndoList);
  }
  else
  {
    theContent.setText(upd.theOldContent);

    if (parent)
      parent->restoreType(upd.theTypeUndoList);
  }
}


/*******************************************************************************
  PI - REPLACE VALUE
********************************************************************************/
void PiNode::replaceValue(UpdReplacePiValue& upd)
{
  upd.theOldValue.take(theContent);
  theContent.take(upd.theNewValue);
}


void PiNode::restoreValue(UpdReplacePiValue& upd)
{
  theContent.take(upd.theOldValue);
}


/*******************************************************************************
  PI - RENAME
********************************************************************************/
void PiNode::replaceName(UpdRenamePi& upd)
{
  upd.theOldName.take(theTarget);
  theTarget.take(upd.theNewName);
}


void PiNode::restoreName(UpdRenamePi& upd)
{
  theTarget.take(upd.theOldName);
}


/*******************************************************************************
 COMMENT - REPLACE VALUE
********************************************************************************/
void CommentNode::replaceValue(UpdReplaceCommentValue& upd)
{
  upd.theOldValue.take(theContent);
  theContent.take(upd.theNewValue);
}


void CommentNode::restoreValue(UpdReplaceCommentValue& upd)
{
  theContent.take(upd.theOldValue);
}


}
}
/* vim:set et sw=2 ts=2: */
