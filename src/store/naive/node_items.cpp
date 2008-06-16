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

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/URI.h"

#include "store/api/copymode.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/api/temp_seq.h"
#include "store/naive/item_iterator.h"
#include "store/api/collection.h"
#include "zorbatypes/datetime.h"


#ifndef NDEBUG

#define NODE_TRACE(level, msg)                \
{                                             \
  if (level <= GET_STORE().getTraceLevel())   \
    std::cout << msg << std::endl;            \
}

#define NODE_TRACE1(msg) NODE_TRACE(1, msg);
#define NODE_TRACE2(msg) NODE_TRACE(2, msg);
#define NODE_TRACE3(msg) NODE_TRACE(3, msg);

#else

#define NODE_TRACE(msg)
#define NODE_TRACE1(msg)
#define NODE_TRACE2(msg)
#define NODE_TRACE3(msg)

#endif


namespace zorba { namespace store {


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XmlTree                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


XmlTree::XmlTree(XmlNode* root, ulong id)
  :
  theRefCount(0),
  theId(id),
  theRootNode(root)
{
}


void XmlTree::free() throw()
{
  if (theRootNode != 0)
  {
    theRootNode->deleteTree();
    theRootNode = NULL;
  }
  delete this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class XmlNode                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Create a new node C within a given tree T and compute its ordpath based on its
  given position among the attributes or children of a given node P, who will
  become the parent of C.

  If P is NULL, C becomes the root (and single node) of T. In this case, C's
  ordpath is the root one (= 1). 

  If P != NULL and pos >= 0, C will become the "pos"-th child/attribute of P.
  In this case, the ordpath of C is computed based on the ordpaths of its left
  and right siblings (if any). Note: If "pos" >= P->numChildren, then C will
  be appended to P's children/attributes.

  If P != NULL and "pos" < 0, C will be appended to P's children/attributes,
  and C's ordpath is computed based on the current number of children/attributes
  in P. This ordpath evaluation assumes that P never had a child that was later
  deleted. The assumption holds because this case applies only during the
  evaluation of a node-constructor expression, or during the copying of a
  subtree S, where the node to be created is not the copy of the root of S.
********************************************************************************/
XmlNode::XmlNode(
    XmlTree*              tree,
    XmlNode*              parent,
    long                  pos,
    StoreConsts::NodeKind nodeKind)
  :
  Item(),
  theParent(parent)
{
  assert(tree || parent);
  assert(parent == NULL || parent->getTree() != NULL);
  assert(tree == NULL || parent == NULL || parent->getTree() == tree);

  if (parent == NULL)
  {
    setTree(tree);
    tree->setRoot(this);
    theOrdPath.setAsRoot();
  }
  else
  {
    setTree(parent->getTree());
    setOrdPath(parent, pos, nodeKind);
  }
}


/*******************************************************************************

********************************************************************************/
XmlNode::~XmlNode()
{
  ZORBA_ASSERT(theRefCount == 0);
}


/*******************************************************************************

********************************************************************************/
void XmlNode::setTree(const XmlTree* t)
{
  theTreeRCPtr = (long*)t;
  SYNC_CODE(theRCLockPtr = &(t->getRCLock());)
}


/*******************************************************************************

********************************************************************************/
void XmlNode::setOrdPath(
    XmlNode*              parent,
    long                  pos,
    StoreConsts::NodeKind nodeKind)
{
  if (!parent->theOrdPath.isValid())
    return;

  ulong numChildren = parent->numChildren();
  ulong numAttrs = parent->numAttributes();

  if (nodeKind == StoreConsts::attributeNode)
  {
    if (pos < 0)
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(2 * numAttrs + 1);
    }
    else if (numAttrs > 0)
    {
      ulong upos = (ulong)pos;

      if (upos == 0)
      {
        OrdPath::insertBefore(parent->theOrdPath,
                              parent->getAttr(0)->theOrdPath,
                              theOrdPath);
      }
      else if (upos == numAttrs && numChildren > 0)
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(upos-1)->theOrdPath,
                            parent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (upos >= numAttrs)
      {
        OrdPath::insertAfter(parent->theOrdPath,
                             parent->getAttr(upos-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(upos-1)->theOrdPath,
                            parent->getAttr(upos)->theOrdPath,
                            theOrdPath);
      }
    }
    else if (numChildren > 0)
    {
      OrdPath::insertBefore(parent->theOrdPath,
                            parent->getChild(0)->getOrdPath(),
                            theOrdPath);
    }
    else
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(1);
    }
  }
  else // not attribute node
  {
    if (pos < 0)
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(2 * (numAttrs + numChildren) + 1);
    }
    else if (numChildren > 0)
    {
      ulong upos = (ulong)pos;

      if (upos == 0 && numAttrs > 0)
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(numAttrs-1)->theOrdPath,
                            parent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (upos == 0)
      {
        OrdPath::insertBefore(parent->theOrdPath,
                              parent->getChild(0)->theOrdPath,
                              theOrdPath);
      }
      else if (upos >= numChildren)
      {
        OrdPath::insertAfter(parent->theOrdPath,
                             parent->getChild(numChildren-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getChild(upos-1)->theOrdPath,
                            parent->getChild(upos)->theOrdPath,
                            theOrdPath);
      }
    }
    else if (numAttrs > 0)
    {
      OrdPath::insertAfter(parent->theOrdPath,
                           parent->getAttr(numAttrs-1)->theOrdPath,
                           theOrdPath);
    }
    else
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(1);
    }
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::setId(XmlTree* tree, const OrdPathStack* op)
{
  ZORBA_ASSERT(getTree() == NULL);

  setTree(tree);

  if (op != NULL)
    theOrdPath = *op;
  else
    theOrdPath.setAsRoot();
}


/*******************************************************************************
  Return a hash value based on the id of the node.
********************************************************************************/
uint32_t XmlNode::hash(long timezone, XQPCollator* aCollation) const
{
  ulong tid = getTree()->getId();

  return hashfun::h32((void*)(&tid), sizeof(ulong), theOrdPath.hash());
}


/*******************************************************************************

********************************************************************************/
Item_t XmlNode::getEBV() const
{
  Item_t bVal;
  GET_FACTORY().createBoolean(bVal, true);
  return bVal;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t XmlNode::getBaseURIInternal(bool& local) const
{
  local = false;
  return theParent ? theParent->getBaseURI() : 0;
}


/*******************************************************************************
  Remove the i-th child of "this" (it is assumed that i < numChildren).
********************************************************************************/
void XmlNode::removeChild(ulong i)
{
  XmlNode* child = getChild(i);

  children().remove(i);

  if (child->theParent == this)
    child->theParent = NULL;
}


/*******************************************************************************
  If the given node N is a child of "this", disconnect N from "this". Return
  true if N was a child of "this"; false otherwise.
********************************************************************************/
bool XmlNode::removeChild(XmlNode* child)
{
  bool found = children().find(child);

  if (found)
  {
    if (child->theParent == this)
      child->theParent = NULL;
  }

  return found;
}


/*******************************************************************************
  Remove the i-th attribute of "this" (it is assumed that i < numAttributes).
********************************************************************************/
void XmlNode::removeAttr(ulong i)
{
  XmlNode* attr = getAttr(i);

  attributes().remove(i);

  if (attr->theParent == this)
    attr->theParent = NULL;
}


/*******************************************************************************
  If the given node N is an attribute of "this", remove it as an attribute of
  "this". Return true if N was an attribute of "this"; false otherwise.
********************************************************************************/
bool XmlNode::removeAttr(XmlNode* attr)
{
  bool found = attributes().remove(attr);

  if (found)
  {
    if (attr->theParent == this)
      attr->theParent = NULL;
  }

  return found;
}


/*******************************************************************************
  Disconnect this node from its parent, if any.
********************************************************************************/
ulong XmlNode::disconnect() throw()
{
  if (theParent == NULL)
    return 0;

  ulong pos;

  if (getNodeKind() == StoreConsts::attributeNode)
  {
    pos = theParent->attributes().find(this);
    if (pos < theParent->numAttributes())
      theParent->attributes().remove(pos);
  }
  else
  {
    pos = theParent->children().find(this);
    if (pos < theParent->numChildren())
      theParent->children().remove(pos);
  }

  theParent = NULL;

  return pos;
}


/*******************************************************************************
  Connect this to the given parent at the given position.
********************************************************************************/
void XmlNode::connect(XmlNode* parent, ulong pos) throw()
{
  ZORBA_FATAL(theParent == NULL, "");

  theParent = parent;

  if (getNodeKind() == StoreConsts::attributeNode)
  {
    parent->attributes().insert(this, pos, false);
  }
  else
  {
    parent->children().insert(this, pos, false);
  }
}


/*******************************************************************************
  Disconnect "this" node and its subtree from its current xml tree and make it
  a member of a new given tree, placing it as a child or attribute of a given
  parent node P. The position among P's children/attributes where "this" is to
  be placed is also given.     
********************************************************************************/
void XmlNode::switchTree(
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) throw()
{
  try
  {
    ulong refcount = 0;
    std::stack<XmlNode*> nodes;

    XmlTree* newTree = (parent == NULL ? 
                        new XmlTree(this, GET_STORE().getTreeId()) :
                        parent->getTree());

    XmlTree* oldTree = getTree();

    if (theParent != NULL)
      theParent->removeChild(this);

    if (oldTree->getRoot() == this)
      oldTree->setRoot(NULL);

    setTree(newTree);
    theParent = parent;

    if (parent)
    {
      if (getNodeKind() == StoreConsts::attributeNode)
      {
        setOrdPath(parent, pos, StoreConsts::attributeNode);

        parent->attributes().insert(this, pos, false);
      }
      else
      {
        setOrdPath(parent, pos, getNodeKind());

        parent->children().insert(this, pos, false);
      }
    }

    nodes.push(this);

    SYNC_CODE(oldTree->getRCLock().acquire());

    refcount += theRefCount;

    while (!nodes.empty())
    {
      XmlNode* n = nodes.top();
      nodes.pop();

      AttributeNode* baseUriAttr = NULL;
      AttributeNode* hiddenBaseUriAttr = NULL;
      ulong numAttrs = n->numAttributes();
      for (ulong i = 0; i < numAttrs; i++)
      {
        AttributeNode* attr = n->getAttr(i);
        refcount += attr->theRefCount;
        attr->setTree(newTree);
        attr->theOrdPath = n->theOrdPath;
        attr->theOrdPath.appendComp(2 * i + 1);

        if (attr->isBaseUri())
        {
          if (attr->isHidden())
            hiddenBaseUriAttr = attr;
          else
            baseUriAttr = attr;
        }
      }

      if (hiddenBaseUriAttr && n->theParent != 0)
      {
        ElementNode* elem = reinterpret_cast<ElementNode*>(n);

        // The current node N has a local base uri property. If this is due to
        // an explicit base uri attribute, then it must be re-resolved based
        // on the (potentially new) base uri of the parent node.
        if (baseUriAttr)
        {
          xqpStringStore_t absuri = parent->getBaseURI();
          xqpStringStore_t reluri = baseUriAttr->getBaseURI();
          elem->adjustBaseUriProperty(hiddenBaseUriAttr, absuri, reluri);
        }
        // The current node N has a local base uri property. If, however, N does 
        // not have an explicit base uri attribute, then N was the root of the
        // old tree, and since N is no longer a root in the new tree, its local
        // base uri must be removed.
        else
        {
          hiddenBaseUriAttr->disconnect();
          hiddenBaseUriAttr->deleteTree();
          elem->resetHaveBaseUri();
        }
      }

      ulong numChildren = n->numChildren();
      for (ulong i = 0; i < numChildren; i++)
      {
        XmlNode* child = n->getChild(i);
        refcount += child->theRefCount;
        child->setTree(newTree);
        child->theOrdPath = n->theOrdPath;
        child->theOrdPath.appendComp(2 * (numAttrs + i) + 1);

        nodes.push(child);
      }
    } // done traversing tree

    oldTree->getRefCount() -= refcount;
    if (oldTree->getRefCount() == 0)
    {
      SYNC_CODE(oldTree->getRCLock().release());
      oldTree->free();
    }
    else
    {
      SYNC_CODE(oldTree->getRCLock().release());
    }

    SYNC_CODE(newTree->getRCLock().acquire());

    newTree->getRefCount() += refcount;
    if (newTree->getRefCount() == 0)
    {
      SYNC_CODE(newTree->getRCLock().release());
      newTree->free();
    }
    else
    {
      SYNC_CODE(newTree->getRCLock().release());
    }
  }
  catch(...)
  {
    ZORBA_FATAL(0, "Unexpected exception");
  }
}


/*******************************************************************************

********************************************************************************/
void XmlNode::deleteTree() throw()
{
  ZORBA_FATAL(theParent == NULL, "");
  ZORBA_FATAL(theRefCount == 0, "");

  ulong numChildren = this->numChildren();
  ulong numAttrs = this->numAttributes();

  for (ulong i = 0; i < numChildren; i++)
  {
    XmlNode* child = getChild(i);
    if (child->theParent == this)
    {
      child->theParent = NULL; 
      child->deleteTree();
    }
  }

  for (ulong i = 0; i < numAttrs; i++)
  {
    XmlNode* attr = getAttr(i);
    if (attr->theParent == this)
    {
      attr->theParent = NULL;
      attr->deleteTree();
    }
  } 

  delete this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
DocumentNode::DocumentNode(
    XmlTree*          tree,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  XmlNode(tree, NULL, 0, StoreConsts::documentNode)
{
  if (baseUri != NULL && !baseUri->empty())
    theBaseUri.transfer(baseUri);

  theDocUri.transfer(docUri);
}


/*******************************************************************************

********************************************************************************/
DocumentNode::~DocumentNode()
{
  NODE_TRACE1("Deleted doc node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* DocumentNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  ZORBA_ASSERT(rootParent == NULL && parent == NULL);

  XmlTree* tree = NULL;
  XmlNode* copyNode = NULL;

  xqpStringStore_t baseuri = theBaseUri;
  xqpStringStore_t docuri = theDocUri;

  try
  {
    tree = new XmlTree(NULL, GET_STORE().getTreeId());

    copyNode = new DocumentTreeNode(tree, baseuri, docuri);

    ulong numChildren = this->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      getChild(i)->copy2(rootParent, copyNode, -1, copymode);
    }
  }
  catch (...)
  {
    if (tree)
      tree->free();
    throw;
  }

  NODE_TRACE1("}");
  NODE_TRACE1("Copied doc node " << this << " to node " << copyNode);

  return copyNode;
}


Item* DocumentNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED];
}


xqpStringStore_t DocumentNode::getBaseURIInternal(bool& local) const
{
  local = true;
  return theBaseUri;
}


Iterator_t DocumentNode::getChildren() const
{
  return (new ChildrenIterator((XmlNode*)this));
}


Iterator_t DocumentNode::getTypedValue() const
{
  xqpStringStore_t rch = getStringValue();
  Item_t item = new UntypedAtomicItemImpl(rch);
  return new ItemIterator(item);
}


Item_t DocumentNode::getAtomizationValue() const
{
  xqpStringStore_t rch = getStringValue();
  return new UntypedAtomicItemImpl(rch);
}


xqpStringStore_t DocumentNode::getStringValue() const
{
  std::string buf;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      buf += getChild(i)->getStringValue()->str();
  }

  return new xqpStringStore(buf);
}


/*******************************************************************************

********************************************************************************/
xqp_string DocumentNode::show() const
{
  std::stringstream strStream;

  strStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
            << "<document";
  if (theBaseUri != NULL)
    strStream << " baseUri = \"" << *theBaseUri;
  if (theDocUri != NULL)
    strStream << " docUri = \"" << *theDocUri;
  strStream << "\">" << std::endl;

  Iterator_t iter = getChildren();
  Item_t item;
  while (iter->next(item))
  {
    strStream << item->show();
  }
  
  strStream << std::endl << "</document>";

  return strStream.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentTreeNode                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
DocumentTreeNode::DocumentTreeNode(
    XmlTree*          tree,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  DocumentNode(tree, baseUri, docUri)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << (theDocUri != 0 ? theDocUri->c_str() : "NULL"));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentDagNode                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
DocumentDagNode::DocumentDagNode(
    XmlTree*          tree,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  DocumentNode(tree, baseUri, docUri)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << (theDocUri != 0 ? theDocUri->c_str() : "NULL"));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  localBindings will be NULL if this contructor is called from the copy() method
  (because in that case, the in-scope bindings must be computed by the copy()
  method based on the copy mode). Otherwise, localBindings should not be NULL
  (but may be empty).
********************************************************************************/
ElementNode::ElementNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    Item_t&           nodeName,
    Item_t&           typeName,
    const NsBindings* localBindings)
  :
  XmlNode(tree, parent, pos, StoreConsts::elementNode),
  theFlags(0)
{
  theName.transfer(nodeName);
  theTypeName.transfer(typeName);

  if (localBindings && !localBindings->empty())
  {
    theNsContext = new NsBindingsContext(*localBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this, false);
    else
      parent->children().insert(this, pos, false);

    if (localBindings)
    {
      try
      {
        addBindingForQName(theName);
        setNsContext(parent->getNsContext());
      }
      catch(...)
      {
        parent->removeChild(this);
        throw;
      }
    }
  }
  else
  {
    if (localBindings)
      addBindingForQName(theName);
  }
}


/*******************************************************************************

********************************************************************************/
ElementNode::~ElementNode()
{
  NODE_TRACE1("Deleted elem node " << this);
  //NODE_TRACE3("nscontext " << theNsContext.getp() << ", "
  //            << (theNsContext != NULL ? theNsContext->getRefCount() : -1));
}


/*******************************************************************************

********************************************************************************/
XmlNode* ElementNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  if (parent != NULL && !copymode.theDoCopy)
  {
    parent->children().push_back(const_cast<ElementNode*>(this), true);

    NODE_TRACE1("Copied elem node " << this << " to node " << this
              << " name = " << *theName->getStringValue() << " parent = "
              << parent << " pos = " << pos);
    return const_cast<ElementNode*>(this);
  }

  XmlTree* tree = NULL;
  ElementTreeNode* copyNode = NULL;

  Item_t nodeName = theName;
  Item_t typeName = (copymode.theTypePreserve ?
                     theTypeName :
                     GET_STORE().theSchemaTypeNames[XS_UNTYPED]);
  xqpStringStore_t baseUri;

  try
  {
    if (parent == NULL)
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

    pos = (parent == rootParent ? pos : -1);

    copyNode = new ElementTreeNode(tree, parent, pos, nodeName, typeName, NULL, baseUri);

    if (copymode.theNsPreserve)
    {
      // If we are copying the root of an xml subtree, or a node that does
      // not inherit ns bindings directly from its parent (but may inherit
      // from another ancestor).
      if (parent == rootParent ||
          theNsContext == NULL ||
          (haveLocalBindings() &&
           theNsContext->getParent() != theParent->getNsContext()) ||
          theNsContext != theParent->getNsContext())
      {
        if (theNsContext != NULL)
        {
          std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
          getNamespaceBindings(ctx->getBindings());

          if (!ctx->empty())
          {
            copyNode->theNsContext = ctx.release();
            copyNode->theFlags |= XmlNode::HaveLocalBindings;
          }
        }

        if (rootParent && copymode.theNsInherit)
        {
          // If "this" does not belong to any namespace and the root parent
          // has a default ns binding, then undeclare this default binding.
          xqpStringStore* prefix = theName->getPrefix();
          if (prefix->empty() &&
              theName->getNamespace()->empty() &&
              rootParent->getNodeKind() == StoreConsts::elementNode)
          {
            xqpStringStore* ns = reinterpret_cast<ElementNode*>(rootParent)->
                                 findBinding(prefix);
            if (ns != NULL)
              copyNode->addLocalBinding(prefix, theName->getNamespace());
          }

          copyNode->setNsContext(rootParent->getNsContext());
        }
      }
      // Else the node we are copying is not the root of the xml subtree and
      // it inherits ns bindings directly from its parent.
      else
      {
        if (haveLocalBindings())
        {
          copyNode->theNsContext = new NsBindingsContext(getLocalBindings());
          copyNode->theFlags |= XmlNode::HaveLocalBindings;
        }

        copyNode->setNsContext(parent->getNsContext());
      }
    }
    else // ! nsPreserve
    {
      if (copymode.theTypePreserve &&
          (theTypeName == GET_STORE().theSchemaTypeNames[XS_QNAME] ||
           theTypeName == GET_STORE().theSchemaTypeNames[XS_NOTATION]))
      {
        ZORBA_ERROR(XQTY0086);
      }

      xqpStringStore* prefix;
      xqpStringStore* ns;
      std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext);

      prefix = theName->getPrefix();
      ns = getNsContext()->findBinding(prefix);

      // ns may be null only if the prefix was empty and there was no default
      // namespace declaration in scope.
      ZORBA_ASSERT(prefix->str() == "" || ns != NULL);

      if (ns != NULL)
      {
        xqpStringStore* ns2 = NULL;

        if (rootParent &&
            rootParent->getNodeKind() == StoreConsts::elementNode &&
            copymode.theNsInherit)
        {
          ns2 = rootParent->getNsContext()->findBinding(prefix);
        }

        if (ns2 == NULL || !ns->byteEqual(*ns2))
          ctx->addBinding(prefix, ns);
      }

      ulong numAttrs = numAttributes();

      for (ulong i = 0; i < numAttrs; i++)
      {
        prefix = getAttr(i)->getNodeName()->getPrefix();
        ns = getNsContext()->findBinding(prefix);

        ZORBA_ASSERT(prefix->empty() || prefix->str() == "xml" || ns != NULL);

        if (ns != NULL)
        {
          xqpStringStore* ns2 = NULL;

          if (rootParent &&
              rootParent->getNodeKind() == StoreConsts::elementNode &&
              copymode.theNsInherit)
          {
            ns2 = rootParent->getNsContext()->findBinding(prefix);
          }

          if (ns2 == NULL || !ns->byteEqual(*ns2))
            ctx->addBinding(prefix, ns);
        }
      }

      if (!ctx->empty())
      {
        copyNode->theNsContext = ctx.release();
        copyNode->theFlags |= XmlNode::HaveLocalBindings;
      }

      if (copymode.theNsInherit)
      {
        copyNode->setNsContext(rootParent->getNsContext());
      }
    }

    // Copy the attributes of this node
    AttributeNode* baseUriAttr = NULL;
    AttributeNode* hiddenBaseUriAttr = NULL;
    ulong numAttrs = this->numAttributes();
    for (ulong i = 0; i < numAttrs; i++)
    {
      AttributeNode* attr = getAttr(i);

      if (attr->isBaseUri())
      {
        if (attr->isHidden())
        {
          hiddenBaseUriAttr = attr;
          continue;
        }
        else
        {
          baseUriAttr = attr;
        }
      }

      attr->copy2(rootParent, copyNode, -1, copymode);
    }

    if (hiddenBaseUriAttr)
    {
      if (baseUriAttr)
      {
        xqpStringStore_t absuri = (parent ? parent->getBaseURI() : NULL);
        xqpStringStore_t reluri = baseUriAttr->getBaseURI();
        copyNode->addBaseUriProperty(absuri, reluri);
      }
      else if (parent == 0)
      {
        xqpStringStore_t absuri = hiddenBaseUriAttr->getStringValueP();
        xqpStringStore_t reluri;
        copyNode->addBaseUriProperty(absuri, reluri);
      }
      else
      {
        // do not add explicit base uri property in the copy ==> copy inherits
        // the base-uri property of its parent.
      }
    }

    // Copy the children of this node
    ulong numChildren = this->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      getChild(i)->copy2(rootParent, copyNode, -1, copymode);
    }
  }
  catch (...)
  {
    if (tree)
    {
      tree->free();
    }
    else if (copyNode && (parent == rootParent))
    {
      copyNode->disconnect();
      copyNode->deleteTree();
    }

    throw;
  }

  NODE_TRACE1("Copied elem node " << this << " to node " << copyNode
              << " name = " << *theName->getStringValue() << " parent = "
              << (parent ? parent : 0x0)
              << " pos = " << pos << " copy mode = " << copymode.toString());

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNode::getTypedValue() const
{
  Item_t retItem = getAtomizationValue();
  return new ItemIterator(retItem);
}


/*******************************************************************************

********************************************************************************/
Item_t ElementNode::getAtomizationValue() const
{
  xqpStringStore_t rch = getStringValue();
  return new UntypedAtomicItemImpl(rch);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementNode::getStringValue() const
{
  std::string buf;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      buf += getChild(i)->getStringValue()->str();
  }

  return new xqpStringStore(buf);
}


/*******************************************************************************

********************************************************************************/
Item_t ElementNode::getNilled() const
{
  if (theTypeName == GET_STORE().theSchemaTypeNames[XS_UNTYPED])
    return new BooleanItemNaive(false);

  bool nilled = true;
  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    if (getChild(i)->getNodeKind() == StoreConsts::elementNode ||
        getChild(i)->getNodeKind() == StoreConsts::textNode)
    {
      nilled = false;
      break;
    }
  }

  if (!nilled)
    return new BooleanItemNaive(false);

  nilled = false;

  //const char* xsi = "http://www.w3.org/2001/XMLSchema-instance";
  //ulong xsilen = strlen(xsi);

  ulong numAttrs = this->numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    AttributeNode* attr = getAttr(i);
    if (attr->theName->getNamespace()->byteEqual("xsi", 3) &&
        attr->theName->getLocalName()->byteEqual("nil", 3))
    {
      nilled = true;
      break;
    }
  }

  return new BooleanItemNaive(nilled);
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNode::getAttributes() const
{
  return (new AttributesIterator((ElementNode*)this));
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNode::getChildren() const
{
  return (new ChildrenIterator((XmlNode*)this));
}


/*******************************************************************************
  Carefull with this function: it generates the namespaces in the reverse order.
  The higher parent gives the latest namespaces, instead of first.
********************************************************************************/
void ElementNode::getNamespaceBindings(
    NsBindings& bindings,
    StoreConsts::NsScoping ns_scoping) const
{
  if (theNsContext != NULL)
  {
    if(ns_scoping != StoreConsts::ONLY_PARENT_NAMESPACES)
      bindings = theNsContext->getBindings();

    if(ns_scoping == StoreConsts::ONLY_LOCAL_NAMESPACES)
      return;

    const NsBindingsContext* parentContext = theNsContext->getParent();

    while (parentContext != NULL)
    {
      const NsBindings& parentBindings = parentContext->getBindings();
      ulong parentSize = parentBindings.size();
      ulong currSize = bindings.size();

      for (ulong i = 0; i < parentSize; i++)
      {
        ulong j;
        for (j = 0; j < currSize; j++)
        {
          if (bindings[j].first.byteEqual(parentBindings[i].first))
            break;
        }

        if (j == currSize)
          bindings.push_back(parentBindings[i]);
      }

      parentContext = parentContext->getParent();
    }
  }
}


/*******************************************************************************
  Make "this" inherit the ns bindings of its parent.
********************************************************************************/
void ElementNode::setNsContext(NsBindingsContext* parentCtx)
{
  if (theNsContext == NULL)
    theNsContext = parentCtx;
  else if (theNsContext.getp() != parentCtx)
    theNsContext->setParent(parentCtx);
}


/*******************************************************************************
  Search all the in-scope ns bindings of "this" to find the ns uri associated
  with the given prefix. Return NULL if no binding exists for the given prefix.
********************************************************************************/
xqpStringStore* ElementNode::findBinding(const xqpStringStore* prefix) const
{
  if (theNsContext == NULL)
    return NULL;

  return theNsContext->findBinding(prefix);
}


/*******************************************************************************

********************************************************************************/
const NsBindings& ElementNode::getLocalBindings() const
{
  ZORBA_ASSERT(haveLocalBindings());
  return theNsContext->getBindings();
}


/*******************************************************************************
  Add the ns binding that is implied by the given qname. If this ns binding
  conflicts with the current ns bindings of "this" node, then replace the given
  qname with a new one that has the same local name and ns uri, but whose
  prefix is artificially generated so that the conflict is resolved.
********************************************************************************/
void ElementNode::addBindingForQName(Item_t& qname)
{
  xqpStringStore* prefix = qname->getPrefix();
  xqpStringStore* ns = qname->getNamespace();

  // If ns is empty, then prefix must be empty
  ZORBA_FATAL(!ns->empty() || prefix->empty(),
              "prefix = " << prefix->str() << "ns = " << ns->str());

  if (ns->empty())
    return;

  if (prefix->str() != "xml")
  {
    xqpStringStore* ns2 = findBinding(prefix);

    if (ns2 == NULL)
    {
      if (!ns->empty())
        addLocalBinding(prefix, ns);
    }
    else if (!ns2->byteEqual(*ns))
    {
      xqpStringStore_t prefix(new xqpStringStore("XXX"));

      while (findBinding(prefix) != NULL)
        prefix = prefix->append("X");

      GET_FACTORY().createQName(qname, ns, prefix, qname->getLocalName());
      addLocalBinding(prefix, ns);
    }
  }
}


/*******************************************************************************
  Same as above, but used when we know that no ns binding conflict exists
********************************************************************************/
void ElementNode::addBindingForQName2(const Item* qname)
{
  xqpStringStore* prefix = qname->getPrefix();
  xqpStringStore* ns = qname->getNamespace();

  // If ns is empty, then prefix must be empty
  ZORBA_FATAL(!ns->empty() || prefix->empty(),
              "prefix = " << prefix->str() << "ns = " << ns->str());

  if (prefix->str() != "xml")
  {
    xqpStringStore* ns2 = findBinding(prefix);

    if (ns2 == NULL)
    {
      if (!ns->empty())
        addLocalBinding(prefix, ns);
    }
    else if (!ns2->byteEqual(*ns))
    {
      ZORBA_FATAL(0, "");
    }
  }
}


/*******************************************************************************
  Add a local ns binding to "this". It is assumed that "this" does not already
  have the given binding among its local bindings (ZORBA_FATAL is called if this
  condition is not true).
********************************************************************************/
void ElementNode::addLocalBinding(xqpStringStore* prefix, xqpStringStore* ns)
{
  if (!haveLocalBindings())
  {
    NsBindingsContext* parent = theNsContext;
    theNsContext = new NsBindingsContext(0);
    theNsContext->setParent(parent);
  }

  theNsContext->addBinding(prefix, ns);

  theFlags |= XmlNode::HaveLocalBindings;
}


/*******************************************************************************
  Check if the ns binding implied by the given qname conflicts with the current
  ns bindings of "this" node.
********************************************************************************/
void ElementNode::checkNamespaceConflict(
    const Item*  qname,
    XQUERY_ERROR ecode) const
{
  const QNameItemImpl* qn = reinterpret_cast<const QNameItemImpl*>(qname);

  xqpStringStore* prefix = qn->getPrefix();
  xqpStringStore* ns = qn->getNamespace();

  if (prefix->empty() && ns->empty())
    return;

  xqpStringStore* ns2 = findBinding(prefix);

  if (ns2 != NULL && !ns2->byteEqual(*ns))
  {
    ZORBA_ERROR_DESC_OSS(ecode,
                         "The implied namespace binding of " << qname->show()
                         << " conflicts with namespace binding ["
                         << prefix->str() << ", " << ns2->str() << "]");
  }
}


/*******************************************************************************
  Check that "this" does not have an attr with the same name as the given name.
********************************************************************************/
void ElementNode::checkUniqueAttr(const Item* attrName) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    if (getAttr(i)->getNodeName()->equals(attrName))
    {
      ZORBA_ERROR_PARAM_OSS(XQDY0025,
                            "Attribute name " << *attrName->getStringValue() 
                            << " is not unique", "");
    }
  }
}


/*******************************************************************************
  Compute the base-uri property of this element node and store it as a a special
  ("hidden") attribute of the node. In general, the base-uri property is 
  computed by resolving the "relUri" based on the absolute "absUri". However,
  "relUri" may be an absolute uri already, in which case the base-uri property
  of the node is set to "relUri". It is also possible that "relUri" is NULL,
  in which case, the base-uri property of the node is set to "absUri". It is
  assumed that both "absUri" and "relUri" (if not NULL) are well-formed uri
  strings.
********************************************************************************/
void ElementNode::addBaseUriProperty(
    xqpStringStore_t& absUri,
    xqpStringStore_t& relUri)
{
  ZORBA_FATAL(absUri != NULL && !absUri->empty(), "");

  const SimpleStore& store = GET_STORE();

  Item_t qname = store.getQNamePool().insert(store.XML_URI, "xml", "base");
  Item_t tname = store.theSchemaTypeNames[XS_ANY_URI];

  Item_t typedValue;
  if (relUri == NULL)
  {
    typedValue = new AnyUriItemImpl(absUri);
  }
  else
  { 
    xqpStringStore_t resolvedUri;
    URI::error_t err = URI::resolve_relative(absUri, relUri, resolvedUri);
    if (err != URI::MAX_ERROR_CODE)
      resolvedUri.transfer(relUri);

    typedValue = new AnyUriItemImpl(resolvedUri);
  }

  new AttributeNode(NULL, this, 0, qname, tname, typedValue, true);
  setHaveBaseUri();
}


/*******************************************************************************
  Change the base-uri property of this node. The new base-uri value is computed
  by resolving the "relUri" based on the "absUri". If "relUri" is NULL, then the
  new base-uri value is set to "absUri". If "relUri" is already an absolute uri,
  then the new base-uri value is set to "relUri". "attr" is the hidden attribute
  that stores the base-uri value.
********************************************************************************/
void ElementNode::adjustBaseUriProperty(
    AttributeNode*    attr,
    xqpStringStore_t& absUri,
    xqpStringStore_t& relUri)
{
  ZORBA_FATAL(absUri != NULL && !absUri->empty(), "");

  Item_t typedValue;
  if (relUri == NULL)
  {
    typedValue = new AnyUriItemImpl(absUri);
  }
  else
  { 
    xqpStringStore_t resolvedUri;
    URI::error_t err = URI::resolve_relative(absUri, relUri, resolvedUri);
    ZORBA_FATAL(err == URI::MAX_ERROR_CODE, "err = " << (int)err);
    typedValue = new AnyUriItemImpl(resolvedUri);
  }

  attr->theTypedValue.transfer(typedValue);
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNode::show() const
{
  std::stringstream str;

  str <<  "<" << *theName->getStringValue() << "-elem";

  str << " nid=\"" << theOrdPath.show() << "\"";

  NsBindings nsBindings;
  getNamespaceBindings(nsBindings);

  for (ulong i = 0; i < nsBindings.size(); i++)
  {
    str << " xmlns:" <<  nsBindings[i].first << "=\""
        << nsBindings[i].second << "\"";
  }

  Iterator_t iter = getAttributes();
  Item_t item;
  while (iter->next(item))
  {
    str << " " << item->show();
  }

  str << ">";

  iter = getChildren();
  iter->open();
  while (iter->next(item))
  {
    str << item->show();
  }

  str << "</" << *theName->getStringValue() << "-elem>";
  return str.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementTreeNode                                                      //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ElementTreeNode::ElementTreeNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    Item_t&           nodeName,
    Item_t&           typeName,
    const NsBindings* localBindings,
    xqpStringStore_t& baseUri)
  :
  ElementNode(tree, parent, pos, nodeName, typeName, localBindings)
{
  // Setting the base uri property of "this" cannot be done in the ElementNode
  // constructor, because it involves the creation of an attribute node having
  // "this" as the parent, and within the attribute constructor the class type
  // of "this" cannot be ElementNode.
  if (baseUri != NULL)
  {
    try
    {
      xqpStringStore_t dummy;
      addBaseUriProperty(baseUri, dummy);
    }
    catch(...)
    {
      if (parent)
        parent->removeChild(this);

      throw;
    }
  }

  NODE_TRACE1("Constructed element node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementTreeNode::getBaseURIInternal(bool& local) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    AttributeNode* attr = getAttr(i);
    if (attr->isBaseUri() && attr->isHidden())
    {
      local = true;
      return attr->getStringValue();
    }
  }

  local = false;
  return theParent ? theParent->getBaseURI().getp() : 0;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementDagNode                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ElementDagNode::ElementDagNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    Item_t&           nodeName,
    Item_t&           typeName,
    const NsBindings* localBindings,
    xqpStringStore_t& baseUri)
  :
  ElementNode(tree, parent, pos, nodeName, typeName, localBindings)
{
  if (baseUri != NULL)
  {
    try
    {
      xqpStringStore_t dummy;
      addBaseUriProperty(baseUri, dummy);
    }
    catch(...)
    {
      if (parent)
        parent->removeChild(this);

      throw;
    }
  }

  NODE_TRACE1("Constructed element node " << this << " parent = " 
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementDagNode::getBaseURIInternal(bool& local) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    AttributeNode* attr = getAttr(i);
    if (attr->isBaseUri() && attr->isHidden())
    {
      local = true;
      return attr->getStringValue();
    }
  }

  local = false;
  return theParent ? theParent->getBaseURI().getp() : new xqpStringStore("");
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlTree*  tree,
    XmlNode*  parent,
    long      pos,
    Item_t&   attrName,
    Item_t&   typeName,
    Item_t&   typedValue,
    bool      hidden)
  :
  XmlNode(tree, parent, pos, StoreConsts::attributeNode),
  theFlags(0)
{
  theName.transfer(attrName);
  theTypeName.transfer(typeName);
  theTypedValue.transfer(typedValue);

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= XmlNode::IsBaseUri;
  else if (qn->isId())
    theFlags |= XmlNode::IsId;

  if (hidden)
    setHidden();

  if (parent)
  {
    ElementNode* p = reinterpret_cast<ElementNode*>(parent);
    p->checkUniqueAttr(theName);

    // If this is an explicit base uri attribute, set or update the base-uri
    // property of the parent.
    if (isBaseUri() && !isHidden())
    {
      xqpStringStore_t parentBaseUri = p->getBaseURI();
      xqpStringStore_t baseUri = this->getStringValue();

      if (p->haveBaseUri())
      {
        ulong numAttrs = p->numAttributes();
        for (ulong i = 0; i < numAttrs; i++)
        {
          AttributeNode* attr = p->getAttr(i);
          if (attr->isBaseUri() && attr->isHidden())
          {
            attr->disconnect();
            delete attr;
            break;
          }
        }
      }

      if (parentBaseUri == NULL)
        p->addBaseUriProperty(baseUri, parentBaseUri);
      else
        p->addBaseUriProperty(parentBaseUri, baseUri);
    }

    // Else add the ns binding implied by the attr name into the in-scope ns
    // bindings of the parent (if this ns binding is not there already) 
    else if (!isHidden())
    {
      p->addBindingForQName(theName);
    }

    // Connect "this" to its parent
    if (pos < 0)
      parent->attributes().push_back(this, false);
    else
      parent->attributes().insert(this, pos, false);
  }

  NODE_TRACE1("Constructed attribute node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " value = " << *theTypedValue->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::~AttributeNode()
{
  NODE_TRACE1("Deleted attr node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* AttributeNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);
  ZORBA_FATAL(!isHidden(), "");

  XmlTree* tree = NULL;
  AttributeNode* copyNode = NULL;
  Item_t nodeName = theName;
  Item_t typeName;
  Item_t typedValue;

  ElementNode* p = reinterpret_cast<ElementNode*>(parent);

  // Skip copy if caller says so. For simplicity, base-uri attributes are
  // always copied.
  if (parent != NULL && !copymode.theDoCopy && !isBaseUri())
  {
    try
    {
      p->checkNamespaceConflict(theName, XQDY0025);
    }
    catch(error::ZorbaError& e)
    {
      // Resolving the namespace conflict requires that the prefix of the
      // attribute name is changed. However, we cannot do that if the attr
      // is not owned by its parent. So, in this case we do the actual copy.
      goto docopy;
    }

    p->checkUniqueAttr(theName);
    p->addBindingForQName2(theName);

    ZORBA_FATAL(dynamic_cast<ElementDagNode*>(parent) != NULL, "");

    if (pos < 0)
      p->attributes().push_back(const_cast<AttributeNode*>(this), true);
    else
      p->attributes().insert(const_cast<AttributeNode*>(this), pos, true);

    copyNode = const_cast<AttributeNode*>(this);
  }
  else
  {
docopy:
    if (copymode.theTypePreserve)
    {
      typeName = theTypeName;
      typedValue = theTypedValue;
    }
    else
    {
      typeName = GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];

      if (theTypedValue->getType() == GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC])
      {
        typedValue = theTypedValue;
      }
      else
      {
        xqpStringStore_t rch = getStringValue();
        typedValue = new UntypedAtomicItemImpl(rch);
      }
    }

    try
    {
      if (parent == NULL)
        tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new AttributeNode(tree, parent, pos, nodeName, typeName, typedValue);
    }
    catch (...)
    {
      if (tree) delete tree;
      throw;
    }
  }

  NODE_TRACE1("Copied attribute node " << this << " to node " << copyNode
              << " name = " << theName->show() << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " copy mode = " << copymode.toString());

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
Iterator_t AttributeNode::getTypedValue() const
{
  return new ItemIterator(theTypedValue);
}


Item_t AttributeNode::getAtomizationValue() const
{
  return theTypedValue;
}

xqpStringStore_t AttributeNode::getStringValue() const
{
  if (theTypedValue != 0)
    return theTypedValue->getStringValue();
  else
    return new xqpStringStore("");
}


/*******************************************************************************

********************************************************************************/
xqp_string AttributeNode::show() const
{
  return theName->getStringValue()->str() + "=\"" +
         (theTypedValue != NULL ? theTypedValue->show() : "") + "\"";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class TextNode                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, StoreConsts::textNode)
{
  theContent.transfer(content);

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this, false);
    else
      parent->children().insert(this, pos, false);
  }

  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << theContent->c_str());
}


/*******************************************************************************

********************************************************************************/
TextNode::~TextNode()
{
  NODE_TRACE1("Deleted text node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* TextNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  TextNode* copyNode = NULL;
  xqpStringStore_t content;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      content = theContent;
      copyNode = new TextNode(tree, NULL, pos, content);
    }
    else
    {
      // Merge adjacent text nodes (if we don't merge, then a query which, say,
      // counts the number of text nodes of some element node will return the
      // wrong result).
      ulong pos2 = (pos >= 0 ? pos : parent->numChildren());
   
      XmlNode* lsib = (pos2 > 0 ? parent->getChild(pos2-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);

        if (lsib->theParent == parent)
        {
          textSibling->theContent = textSibling->theContent->append(theContent);
          copyNode = textSibling;
        }
        else
        {
          content = textSibling->theContent->append(theContent);

          parent->removeChild(pos2-1);

          copyNode = new TextNode(tree, parent, pos2-1, content);
        }
      }
      // Skip copy if caller says so.
      else if (!copymode.theDoCopy)
      {
        if (pos < 0)
          parent->children().push_back(const_cast<TextNode*>(this), true);
        else
          parent->children().insert(const_cast<TextNode*>(this), pos, true);
        
        copyNode = const_cast<TextNode*>(this);
      }
      // Regular copy
      else
      {
        content = theContent;
        copyNode = new TextNode(NULL, parent, pos, content);
      }
    }
  }
  catch (...)
  {
    if (tree) delete tree;
    throw;
  }

  NODE_TRACE1("Copied text node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
Item* TextNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


Iterator_t TextNode::getTypedValue() const
{
  xqpStringStore_t rch = theContent; 
  const Item_t& item = new UntypedAtomicItemImpl(rch);
  return new ItemIterator(item);
}


Item_t TextNode::getAtomizationValue() const
{
  xqpStringStore_t rch = theContent; 
  return new UntypedAtomicItemImpl(rch);
}


/*******************************************************************************

********************************************************************************/
xqp_string TextNode::show() const
{
  return xqp_string ("<text nid=\"") + theOrdPath.show() + "\">" + theContent.getp() + "</text>";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class PiNode                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    xqpStringStore_t& target,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, StoreConsts::piNode)
{
  theTarget.transfer(target);
  theContent.transfer(content);

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this, false);
    else
      parent->children().insert(this, pos, false);
  }

  NODE_TRACE1("Constructed pi node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << *theTarget);
}


/*******************************************************************************

********************************************************************************/
PiNode::~PiNode()
{
  NODE_TRACE1("Deleted pi node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* PiNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  PiNode* copyNode = NULL;
  XmlTree* tree = NULL;
  xqpStringStore_t content;
  xqpStringStore_t target;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      target = theTarget;
      content = theContent;
      copyNode = new PiNode(tree, NULL, pos, target, content);
    }
    // Skip copy if caller says so.
    else if (!copymode.theDoCopy)
    {
      if (pos < 0)
        parent->children().push_back(const_cast<PiNode*>(this), true);
      else
        parent->children().insert(const_cast<PiNode*>(this), pos, true);

      copyNode = const_cast<PiNode*>(this);
    }
    else
    {
      target = theTarget;
      content = theContent;
      copyNode = new PiNode(tree, parent, pos, target, content);
    }
  }
  catch (...)
  {
    if (tree) delete tree;
    throw;
  }

  NODE_TRACE1("Copied pi node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
Item* PiNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


Iterator_t PiNode::getTypedValue() const
{
  xqpStringStore_t rch = theContent; 
  const Item_t& item = new StringItemNaive(rch);
  return new ItemIterator(item);
}


Item_t PiNode::getAtomizationValue() const
{
  xqpStringStore_t rch = theContent; 
  return new StringItemNaive(rch);
}


/*******************************************************************************

********************************************************************************/
xqp_string PiNode::show() const
{
  return "<?" + theTarget->str() + " " + theContent->str() + "?>";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class CommentNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlTree*          tree,
    XmlNode*          parent,
    long              pos,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, StoreConsts::commentNode)
{
  theContent.transfer(content);

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this, false);
    else
      parent->children().insert(this, pos, false);
  }

  NODE_TRACE1("Constructed comment node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << theContent->c_str());
}


/*******************************************************************************

********************************************************************************/
CommentNode::~CommentNode()
{
  NODE_TRACE1("Deleted comment node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* CommentNode::copy2(
    XmlNode*        rootParent,
    XmlNode*        parent,
    long            pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  CommentNode* copyNode = NULL;
  XmlTree* tree = NULL;
  xqpStringStore_t content;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      content = theContent;
      copyNode = new CommentNode(tree, NULL, pos, content);
    }
    // Skip copy if caller says so.
    else if (!copymode.theDoCopy)
    {
      if (pos < 0)
        parent->children().push_back(const_cast<CommentNode*>(this), true);
      else
        parent->children().insert(const_cast<CommentNode*>(this), pos, true);
      
      copyNode = const_cast<CommentNode*>(this);
    }
    else
    {
      content = theContent;
      copyNode = new CommentNode(tree, parent, pos, content);
    }
  }
  catch (...)
  {
    if (tree) delete tree;
    throw;
  }

  NODE_TRACE1("Copied coment node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
Item* CommentNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


Iterator_t CommentNode::getTypedValue() const
{
  xqpStringStore_t rch = theContent; 
  const Item_t& item = new StringItemNaive(rch);
  return new ItemIterator(item);
}


Item_t CommentNode::getAtomizationValue() const
{
  xqpStringStore_t rch = theContent; 
  return new StringItemNaive(rch);
}


/*******************************************************************************

********************************************************************************/
xqp_string CommentNode::show() const
{
  return "<!--" + theContent->str() + "-->";
}

} // namespace store
} // namespace zorba

