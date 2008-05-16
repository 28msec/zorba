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

#include <zorba/exception.h>

#include "system/globalenv.h"
#include "compiler/parser/query_loc.h"
#include "errors/error_manager.h"
#include "util/Assert.h"
#include "zorbatypes/URI.h"

#include "store/api/copymode.h"
#include "store/minimal/min_atomic_items.h"
#include "store/minimal/min_node_items.h"
#include "store/minimal/min_node_iterators.h"
#include "store/minimal/min_store.h"
#include "store/minimal/min_item_factory.h"
#include "store/minimal/min_store_defs.h"
#include "store/minimal/min_nsbindings.h"
#include "store/api/temp_seq.h"
#include "store/api/item_iterator.h"
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

********************************************************************************/
XmlNode::XmlNode() : Item(), theParent(NULL)
{
}


/*******************************************************************************
  Create a new node C and make it the root of given tree T. 
********************************************************************************/
 XmlNode::XmlNode(
    XmlTree*  tree,
    bool      assignIds)
  :
  Item(),
  theParent(NULL)
{
  ZORBA_FATAL(tree != NULL && tree->getRoot() == NULL, "");

  setTree(tree);
  tree->setRoot(this);

  if (assignIds)
    theOrdPath.setAsRoot();
}


/*******************************************************************************
  Create a new node C and make it a child (or attribute) of a given node P.
  C is appended to P's children (or attributes), and C's ordpath is computed
  based on the current number of attributs and/or children of P. This ordpath
  evaluation assumes that P never had a child that was later deleted. The
  assumption holds because this constructor is used only during the evaluation
  of a node-constructor expression, or during the copying of a subtree S, where
  the node to be created is not the copy of the root of S.
********************************************************************************/
XmlNode::XmlNode(XmlNode* parent, StoreConsts::NodeKind nodeKind)
  :
  Item(),
  theParent(parent)
{
  assert(parent);
  assert(parent->getTree() != NULL);

  setTree(parent->getTree());

  if (nodeKind == StoreConsts::attributeNode)
  {
    if (parent->theOrdPath.isValid())
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(2 * parent->numAttributes() + 1);
    }

    parent->attributes().push_back(this, false);
  }
  else
  {
    if (parent->theOrdPath.isValid()) 
    {
      theOrdPath = parent->theOrdPath;
      if(parent->hasLoaderAttached() == NULL)
        theOrdPath.appendComp(2 * (parent->numAttributes() + parent->numChildren()) + 1);
      else//the number of children is not known, assume 5000
        theOrdPath.appendComp(2 * (parent->numAttributes() + 5000) + 1);
    }

    parent->children().push_back(this, false);
  }
}


/*******************************************************************************
  Create a new node C and make it a child (or attribute) of a given node P. 
  C is placed in a given position among P's exisitng children (or attributes),
  and the ordpath of C is computed based on the ordpaths of its left and right
  siblings (if any). Note: "pos" must be <= P->numChildren. If "pos" ==
  P->numChuldren, the "this" is appended to the P's children.
********************************************************************************/
XmlNode::XmlNode(XmlNode* parent, ulong pos, StoreConsts::NodeKind nodeKind)
  :
  Item(),
  theParent(parent)
{
  assert(parent);
  assert(parent->getTree() != NULL);

  setTree(parent->getTree());

  setOrdPath(parent, pos, nodeKind);

  if (nodeKind == StoreConsts::attributeNode)
    parent->attributes().insert(this, pos, false);
  else 
    parent->children().insert(this, pos, false);
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
  Return a hash value based on the id of the node.
********************************************************************************/
uint32_t XmlNode::hash(RuntimeCB* aRuntimeCB, XQPCollator* aCollation) const
{
  ulong tid = getTree()->getId();

  return hashfun::h32((void*)(&tid), sizeof(ulong), theOrdPath.hash());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t XmlNode::getBaseURIInternal(bool& local) const
{
  local = false;
  return theParent ? theParent->getBaseURI().getp() : 0;
}


/*******************************************************************************

********************************************************************************/
Item_t XmlNode::getEBV() const
{
  return GET_FACTORY().createBoolean(true);
}


Item* XmlNode::copyXmlTree(const CopyMode& copymode) const
{
  return copy(NULL, NULL, 0, copymode);
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

********************************************************************************/
void XmlNode::setOrdPath(
    XmlNode*              parent,
    ulong                 pos,
    StoreConsts::NodeKind nodeKind)
{
  if (!parent->theOrdPath.isValid())
    return;

  ulong numChildren;
//  if(parent->hasLoaderAttached() == NULL)
    numChildren = parent->numChildren();
//  else
//    numChildren = 5000;//assume 5000 children
  ulong numAttrs = parent->numAttributes();

  if (nodeKind == StoreConsts::attributeNode)
  {
    if (numAttrs > 0)
    {
      if (pos == 0)
      {
        OrdPath::insertBefore(parent->theOrdPath,
                              parent->getAttr(0)->theOrdPath,
                              theOrdPath);
      }
      else if (pos == numAttrs && numChildren > 0)
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(pos-1)->theOrdPath,
                            parent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (pos == numAttrs)
      {
        OrdPath::insertAfter(parent->theOrdPath,
                             parent->getAttr(pos-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(pos-1)->theOrdPath,
                            parent->getAttr(pos)->theOrdPath,
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
    if (numChildren > 0)
    {
      if (pos == 0 && numAttrs > 0)
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getAttr(numAttrs-1)->theOrdPath,
                            parent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (pos == 0)
      {
        OrdPath::insertBefore(parent->theOrdPath,
                              parent->getChild(0)->theOrdPath,
                              theOrdPath);
      }
      else if (pos == numChildren)
      {
        OrdPath::insertAfter(parent->theOrdPath,
                             parent->getChild(numChildren-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(parent->theOrdPath,
                            parent->getChild(pos-1)->theOrdPath,
                            parent->getChild(pos)->theOrdPath,
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

    bool assignIds = (copymode.theAssignIds && parent != NULL);

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
        if (assignIds)
          setOrdPath(parent, pos, StoreConsts::attributeNode);

        parent->attributes().insert(this, pos, false);
      }
      else
      {
        if (assignIds)
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
        if (assignIds)
        {
          attr->theOrdPath = n->theOrdPath;
          attr->theOrdPath.appendComp(2 * i + 1);
        }
      }

      if (hiddenBaseUriAttr && n->theParent != 0)
      {
        if (baseUriAttr)
        {
          xqpStringStore_t absuri = parent->getBaseURI();
          xqpStringStore_t reluri = baseUriAttr->getBaseURI();
          reinterpret_cast<ElementNode*>(n)->
            adjustBaseUriProperty(hiddenBaseUriAttr, absuri, reluri);
        }
        else
        {
          hiddenBaseUriAttr->disconnect();
          hiddenBaseUriAttr->deleteTree();
        }
      }

      //ulong numChildren = n->numChildren();
      //for (ulong i = 0; i < numChildren; i++)
      ulong i = 0;
      Iterator_t    child_iter = n->getChildren();
      child_iter->open();
      store::Item*  child_item;
      while((child_item=&*child_iter->next()))
      {
        XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
        refcount += child->theRefCount;
        child->setTree(newTree);
        if (assignIds)
        {
          child->theOrdPath = n->theOrdPath;
          child->theOrdPath.appendComp(2 * (numAttrs + i) + 1);
        }

        nodes.push(child);
        i++;
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
//  Iterator_t    child_iter = this->getChildren();
//  child_iter->open();
//  Item*  child_item;
//  while((child_item=&*child_iter->next()))
//  {
//    XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
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
DocumentNode::DocumentNode(xqpStringStore_t& baseUri, xqpStringStore_t& docUri)
  :
  XmlNode()
{
  if (baseUri != NULL && !baseUri->empty())
    theBaseUri.transfer(baseUri);

  theDocUri.transfer(docUri);
}


DocumentNode::DocumentNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  XmlNode(tree, assignIds)
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
  if(this->hasLoaderAttached())
    return (new ChildrenIteratorLazy((XmlNode*)this));
  else
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

//  ulong numChildren = this->numChildren();
//  for (ulong i = 0; i < numChildren; i++)
//  {
    //StoreConsts::NodeKind kind = getChild(i)->getNodeKind();
  Iterator_t    child_iter = this->getChildren();
  child_iter->open();
  Item*  child_item;
  while((child_item=&*child_iter->next()))
  {
    XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
    StoreConsts::NodeKind kind = child->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      buf += child->getStringValue()->str();
  }

  return new xqpStringStore(buf);
}


/*******************************************************************************

********************************************************************************/
XmlNode* DocumentNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  ZORBA_ASSERT(rootParent == NULL);

  XmlTree* tree = NULL;
  LoadedDocumentNode* copyNode = NULL;

  xqpStringStore_t baseuri = theBaseUri;
  xqpStringStore_t docuri = theDocUri;

  try
  {
    tree = new XmlTree(NULL, GET_STORE().getTreeId());

    copyNode = new LoadedDocumentNode(tree, copymode.theAssignIds, baseuri, docuri);

//    ulong numChildren = this->numChildren();
//    for (ulong i = 0; i < numChildren; i++)
//    {
//      getChild(i)->copy(rootParent, copyNode, 0, copymode);
//    }
      Iterator_t    child_iter = this->getChildren();
      child_iter->open();
      Item*  child_item;
      while((child_item=&*child_iter->next()))
      {
        XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
        child->copy(rootParent, copyNode, 0, copymode);
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
  Item_t item = iter->next();
  while (item != NULL)
  {
    strStream << item->show();
    item = iter->next();
  }
  
  strStream << std::endl << "</document>";

  return strStream.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class LoadedDocumentNode                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
LoadedDocumentNode::LoadedDocumentNode(
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  DocumentNode(baseUri, docUri),
  attachedloader(NULL)
{
  NODE_TRACE1("Loaded doc node " << this << " base uri = "
              << (theBaseUri != 0 ? theBaseUri->c_str() : "NULL")
              << " doc uri = " << (theDocUri != 0 ? theDocUri->c_str() : "NULL"));
}


/*******************************************************************************

********************************************************************************/
LoadedDocumentNode::LoadedDocumentNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  DocumentNode(tree, assignIds, baseUri, docUri),
  attachedloader(NULL)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << (theDocUri != 0 ? theDocUri->c_str() : "NULL"));
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrDocumentNode                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrDocumentNode::ConstrDocumentNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& baseUri,
    xqpStringStore_t& docUri)
  :
  DocumentNode(tree, assignIds, baseUri, docUri)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << (theDocUri != 0 ? theDocUri->c_str() : "NULL"));
}


/*******************************************************************************

********************************************************************************/
void ConstrDocumentNode::constructSubtree(
    Iterator*       childrenIte,
    bool            copy,
    const CopyMode& copymode)
{
  Item_t item = childrenIte->next();

  while (item != NULL)
  {
    ZORBA_FATAL(item->isNode(), "");
    ZORBA_FATAL(item->getNodeKind() != StoreConsts::attributeNode, "");

    XmlNode* cnode = BASE_NODE(item);

    if (cnode->theParent != this)
    {
      // Skip text node with zero-length value and merge adjacent text nodes
      if (cnode->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textNode = reinterpret_cast<TextNode*>(cnode);
        if (textNode->theContent->empty())
        {
          item = childrenIte->next();
          continue;
        }

        ulong numChildren = this->numChildren();
        XmlNode* lsib = (numChildren > 0 ? getChild(numChildren-1) : NULL);

        if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
        {
          TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
          textSibling->theContent = textSibling->theContent->append(textNode->theContent);

          item = childrenIte->next();
          continue;
        }
      }

      if (copy)
      {
        cnode = cnode->copy(this, this, numChildren(), copymode);
      }
      else
      {
        theChildren.push_back(cnode, true);
      }
    }

    item = childrenIte->next();
  }

  theChildren.resize(numChildren());

  NODE_TRACE1("}");
}
 

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ElementNode::ElementNode(Item_t&  nodeName, Item_t& typeName)
  :
  XmlNode(),
  theFlags(0)
{
  theName.transfer(nodeName);
  theTypeName.transfer(typeName);
}


ElementNode::ElementNode(
    XmlTree* tree,
    bool     assignIds,
    Item_t&  nodeName,
    Item_t&  typeName)
  :
  XmlNode(tree, assignIds),
  theFlags(0)
{
  theName.transfer(nodeName);
  theTypeName.transfer(typeName);
}


ElementNode::ElementNode(
    XmlNode* parent,
    ulong    pos,
    Item_t&  nodeName,
    Item_t&  typeName)
  :
  XmlNode(parent, pos, StoreConsts::elementNode),
  theFlags(0)
{
  theName.transfer(nodeName);
  theTypeName.transfer(typeName);
}


ElementNode::ElementNode(
    XmlNode* parent,
    Item_t&  nodeName,
    Item_t&  typeName)
  :
  XmlNode(parent, StoreConsts::elementNode),
  theFlags(0)
{
  theName.transfer(nodeName);
  theTypeName.transfer(typeName);
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

//  ulong numChildren = this->numChildren();
//  for (ulong i = 0; i < numChildren; i++)
//  {
//    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();
  Iterator_t    child_iter = this->getChildren();
  child_iter->open();
  Item*  child_item;
  while((child_item=&*child_iter->next()))
  {
    XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
    StoreConsts::NodeKind kind = child->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      buf += child->getStringValue()->str();
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
//  ulong numChildren = this->numChildren();
//  for (ulong i = 0; i < numChildren; i++)
//  {
  Iterator_t    child_iter = this->getChildren();
  child_iter->open();
  Item*  child_item;
  while((child_item=&*child_iter->next()))
  {
    XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
    if (child->getNodeKind() == StoreConsts::elementNode ||
        child->getNodeKind() == StoreConsts::textNode)
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
  if(this->hasLoaderAttached())
    return (new ChildrenIteratorLazy((XmlNode*)this));
  else
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

********************************************************************************/
void ElementNode::setNsContext(NsBindingsContext* parentCtx)
{
  if (theNsContext == NULL)
  {
  //  if(parentCtx)
  //    theFlags |= XmlNode::HaveLocalBindings;
    theNsContext = parentCtx;
  }
  else if (theNsContext.getp() != parentCtx)
    theNsContext->setParent(parentCtx);
}


/*******************************************************************************

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
  Add the ns binding that is implied by the given 
********************************************************************************/
void ElementNode::addBindingForQName(Item* qname)
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
      xqpStringStore_t prefix(new xqpStringStore("XXX"));

      while (findBinding(prefix) != NULL)
        prefix = prefix->append("X");

      QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(qname);
      qn->thePrefix = prefix;
      addLocalBinding(prefix, ns);
    }
  }
}


/*******************************************************************************

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
    const Item*           qname,
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

********************************************************************************/
void ElementNode::checkUniqueAttr(const Item* attrName) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    if (getAttr(i)->getNodeName()->equals(attrName, NULL))
    {
      ZORBA_ERROR_PARAM_OSS(XQDY0025,
                            "Attribute name " << *attrName->getStringValue() 
                            << " is not unique", "");
    }
  }
}


/*******************************************************************************

********************************************************************************/
XmlNode* ElementNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  LoadedElementNode* copyNode = NULL;

  Item_t qname = theName;
  Item_t typeName = (copymode.theTypePreserve ?
                     theTypeName :
                     GET_STORE().theSchemaTypeNames[XS_UNTYPED]);
  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new LoadedElementNode(tree, copymode.theAssignIds, qname, typeName);
    }
    else if (parent == rootParent)
    {
      copyNode = new LoadedElementNode(parent, pos, qname, typeName);
    }
    else
    {
      copyNode = new LoadedElementNode(parent, qname, typeName);
    }

    copyNode->theFlags = theFlags;

    if (copymode.theNsPreserve)
    {
      if (parent == rootParent)
      {
        std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
        getNamespaceBindings(ctx->getBindings());

        if (!ctx->empty())
        {
          copyNode->theNsContext = ctx.release();
          copyNode->theFlags |= XmlNode::HaveLocalBindings;
        }

        if (copymode.theNsInherit && rootParent)
        {
          // If the copynode does not belong to any namespace and the parent
          // has a default ns binding, then undeclare this default binding
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
      else if (haveLocalBindings())
      {
        // TODO: fix this case
        copyNode->theNsContext = new NsBindingsContext(getLocalBindings());
        copyNode->theNsContext->setParent(parent->getNsContext());
        copyNode->theFlags |= XmlNode::HaveLocalBindings;
      }
      else
      {
        copyNode->theNsContext = parent->getNsContext();
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

      attr->copy(rootParent, copyNode, 0, copymode);
    }

    if (hiddenBaseUriAttr)
    {
      if (parent == 0)
      {
        hiddenBaseUriAttr->copy(rootParent, copyNode, 0, copymode);
      }
      else if (baseUriAttr)
      {
        xqpStringStore_t baseuri = parent->getBaseURI();
        xqpStringStore_t reluri = baseUriAttr->getBaseURI();
        copyNode->addBaseUriProperty(baseuri, reluri);
      }
    }

    // Copy the children of this node
//    ulong numChildren = this->numChildren();
//    for (ulong i = 0; i < numChildren; i++)
//    {
    Iterator_t    child_iter = this->getChildren();
    child_iter->open();
    Item*  child_item;
    while((child_item=&*child_iter->next()))
    {
      XmlNode* child = reinterpret_cast<XmlNode*>(child_item);
      child->copy(rootParent, copyNode, 0, copymode);
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

  NODE_TRACE1("}");

  NODE_TRACE1("Copied elem node " << this << " to node " << copyNode
              << " name = " << *theName->getStringValue() << " parent = "
              << (parent ? parent : 0x0)
              << " pos = " << pos << " copy mode = " << copymode.toString());

  return copyNode;
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

//  Item_t qname = store.getQNamePool().insert(store.XML_URI, "xml", "base");
  Item_t  qname = new QNameItemImpl(store.XML_URI, "xml", "base");
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

  AttributeNode* attr = new AttributeNode(this, qname, tname, typedValue, false);
  attr->setHidden();
}


/*******************************************************************************

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
  Item_t item = iter->next();
  while (item != NULL)
  {
    str << " " << item->show();
    item = iter->next();
  }

  str << ">";

  iter = getChildren();
  iter->open();
  item = iter->next();
  while (item != NULL)
  {
    str << item->show();
    item = iter->next();
  }

  str << "</" << *theName->getStringValue() << "-elem>";
  return str.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class LoadedElementNode                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
LoadedElementNode::LoadedElementNode(
    Item_t& nodeName,
    Item_t& typeName,
    ulong   numBindings,
    ulong   numAttributes)
  :
  ElementNode(nodeName, typeName),
  attachedloader(NULL)
{
  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << " name = " << theName->show()
              << " num bindings = " << numBindings << " num attributes = "
              << numAttributes << std::endl);
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlTree*  tree,
    bool      assignIds,
    Item_t&   nodeName,
    Item_t&   typeName)
  :
  ElementNode(tree, assignIds, nodeName, typeName),
  attachedloader(NULL)
{
  NODE_TRACE1("{\nConstructing root element node " << this
              << " tree = " << tree->getId() << ":" << tree
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlNode*  parent,
    ulong     pos,
    Item_t&   nodeName,
    Item_t&   typeName)
  :
  ElementNode(parent, pos, nodeName, typeName),
  attachedloader(NULL)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = "
              << parent << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlNode*  parent,
    Item_t&   nodeName,
    Item_t&   typeName)
  :
  ElementNode(parent, nodeName, typeName),
  attachedloader(NULL)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t LoadedElementNode::getBaseURIInternal(bool& local) const
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
//  class ConstrElementNode                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(
    XmlTree*  tree,
    bool      assignIds,
    Item_t&   nodeName,
    Item_t&   typeName)
  :
  ElementNode(tree, assignIds, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing root element node " << this
              << " tree = " << tree->getId() << ":" << tree
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(
    XmlNode*  parent,
    Item_t&    nodeName,
    Item_t&    typeName)
  :
  ElementNode(parent, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
void ConstrElementNode::constructSubtree(
    Iterator*         attributesIte,
    Iterator*         childrenIte,
    const NsBindings& localBindings,
    xqpStringStore_t& staticBaseUri,
    bool              isRoot,
    bool              copy,
    const CopyMode&   copymode)
{
  Item_t item;
  Item_t prevItem;
  bool haveBaseUri = false;

  if (!localBindings.empty())
  {
    theNsContext = new NsBindingsContext(localBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (theParent != NULL)
    setNsContext(theParent->getNsContext());

  addBindingForQName(theName);

  if (attributesIte != 0)
  {
    item = attributesIte->next();
    while (item != 0)
    {
      ZORBA_FATAL(item->isNode(), "");
      ZORBA_FATAL(item->getNodeKind() == StoreConsts::attributeNode, "");

      addAttribute(ATTR_NODE(item), copy, copymode, staticBaseUri, haveBaseUri);

      item = attributesIte->next();
    }
  }
  
  // Conservatively, add a hidden base-uri attr here. If the childrenIte does
  // not produce any explicit base-uri attribute, then the base-uri added here
  // is the correct one, and it MUST be added here, because it is needed for
  // resolving any relative uris that may appear in the children. If the 
  // childrenIte does produce an explicit base-uri attribute, then the base-uri
  // added here will be replaced with the explicit one.
  if (!haveBaseUri && isRoot)
  {
    xqpStringStore_t nulluri;
    addBaseUriProperty(staticBaseUri, nulluri);
    haveBaseUri = true;
  }

  if (childrenIte != 0)
  {
    item = childrenIte->next();
    while (item != 0)
    {
      ZORBA_FATAL(item->isNode(), "");
      ZORBA_FATAL(item->getNodeKind() != StoreConsts::documentNode, "");

      if (item->getNodeKind() != StoreConsts::attributeNode)
        break;

      addAttribute(ATTR_NODE(item), copy, copymode, staticBaseUri, haveBaseUri);

      item = childrenIte->next();
    }

    if (!haveBaseUri && isRoot)
    {
      xqpStringStore_t nulluri;
      addBaseUriProperty(staticBaseUri, nulluri);
    }

    while (item != 0)
    {
      ZORBA_FATAL(item->isNode(), "");
      ZORBA_FATAL(item->getNodeKind() != StoreConsts::documentNode, "");

      XmlNode* cnode = BASE_NODE(item);

      if (cnode->theParent != this)
        addChild(cnode, copy, copymode);
      
      item = childrenIte->next();
    }
  }
  else if (!haveBaseUri && isRoot)
  {
    xqpStringStore_t nulluri;
    addBaseUriProperty(staticBaseUri, nulluri);
  }

  theChildren.resize(numChildren());
  theAttributes.resize(numAttributes());

  NODE_TRACE1("Constructed elem node " << this << ":" << *theName->getStringValue()
              << " baseuri = " << *getBaseURI());
  NODE_TRACE1("}");
}


void ConstrElementNode::addAttribute(
    AttributeNode*    attr,
    bool              copy,
    const CopyMode&   copymode,
    xqpStringStore_t& staticBaseUri,
    bool&             haveBaseUri)
{
  if (attr->theParent != this)
  {
    checkUniqueAttr(attr->theName);

    if (copy)
    {
      attr->copy(this, this, numAttributes(), copymode);
    }
    else
    {
      try
      {
        checkNamespaceConflict(attr->theName, XQDY0025);
      }
      catch(ZorbaException& e)
      {
        attr->copy(this, this, numAttributes(), copymode);
        return;
      }

      theAttributes.push_back(attr, true);
    }
  }

  if (attr->isBaseUri())
  {
    // Remove the base-uri that was added consevatively in constructSubtree().
    if (haveBaseUri)
    {
      ulong numAttrs = numAttributes();
      for (ulong i = 0; i < numAttrs; i++)
      {
        AttributeNode* attr = getAttr(i);
        if (attr->isBaseUri())
        {
          ZORBA_FATAL(attr->isHidden(), "");
          attr->disconnect();
          delete attr;
          break;
        }
      }
    }

    haveBaseUri = true;
    xqpStringStore_t baseUri = attr->getStringValue();
    if (theParent != NULL)
    {
      xqpStringStore_t parentBaseUri = theParent->getBaseURI();
      addBaseUriProperty(parentBaseUri, baseUri);
    }
    else
    {
      addBaseUriProperty(staticBaseUri, baseUri);
    }
  }
}


void ConstrElementNode::addChild(
    XmlNode*        cnode,
    bool            copy,
    const CopyMode& copymode)
{
  if (cnode->theParent != this)
  {
    // Skip text node with zero-length value
    if (cnode->getNodeKind() == StoreConsts::textNode)
    {
      TextNode* textNode = reinterpret_cast<TextNode*>(cnode);
      if (textNode->theContent->empty())
        return;

      ulong numChildren = this->numChildren();
      XmlNode* lsib = (numChildren > 0 ? getChild(numChildren-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
        textSibling->theContent = textSibling->theContent->append(textNode->theContent);
        return;
      }
    }

    if (copy)
    {
      cnode = cnode->copy(this, this, numChildren(), copymode);
    }
    else
    {
      theChildren.push_back(cnode, true);
    }
  }
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ConstrElementNode::getBaseURIInternal(bool& local) const
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
  Node constructor used during loading of an xml doc
********************************************************************************/
AttributeNode::AttributeNode(
    Item_t&  attrName,
    Item_t&  typeName,
    bool     isIdrefs)
  :
  XmlNode(),
  theFlags(0)
{
  theName.transfer(attrName);
  theTypeName.transfer(typeName);

  if (isIdrefs)
    theFlags |= XmlNode::IsIdRefs;

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= XmlNode::IsBaseUri;
  else if (qn->isId())
    theFlags |= XmlNode::IsId;

  NODE_TRACE1("Loaded attr node " << this << " name = "
              << *theName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlTree*  tree,
    bool      assignIds,
    Item_t&   attrName,
    Item_t&   typeName,
    Item_t&   typedValue,
    bool      isIdrefs)
  :
  XmlNode(tree, assignIds),
  theFlags(0)
{
  theName.transfer(attrName);
  theTypeName.transfer(typeName);
  theTypedValue.transfer(typedValue);

  if (isIdrefs)
    theFlags |= XmlNode::IsIdRefs;

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= XmlNode::IsBaseUri;
  else if (qn->isId())
    theFlags |= XmlNode::IsId;

  NODE_TRACE1("Constructed root attribute node " << this
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " name = " << *theName->getStringValue()
              << " value = " << *theTypedValue->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlNode*  parent,
    ulong     pos,
    Item_t&   attrName,
    Item_t&   typeName,
    Item_t&   typedValue,
    bool      isIdRefs)
  :
  XmlNode(parent, pos, StoreConsts::attributeNode),
  theFlags(0)
{
  theName.transfer(attrName);
  theTypeName.transfer(typeName);
  theTypedValue.transfer(typedValue);

  if (isIdRefs)
    theFlags |= XmlNode::IsIdRefs;

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= XmlNode::IsBaseUri;
  else if (qn->isId())
    theFlags |= XmlNode::IsId;

  reinterpret_cast<ElementNode*>(parent)->addBindingForQName(theName);

  NODE_TRACE1("Constructed attribute node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " value = " << *theTypedValue->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlNode*  parent,
    Item_t&   attrName,
    Item_t&   typeName,
    Item_t&   typedValue,
    bool      isIdRefs)
  :
  XmlNode(parent, StoreConsts::attributeNode),
  theFlags(0)
{
  theName.transfer(attrName);
  theTypeName.transfer(typeName);
  theTypedValue.transfer(typedValue);

  if (isIdRefs)
    theFlags |= XmlNode::IsIdRefs;

  QNameItemImpl* qn = reinterpret_cast<QNameItemImpl*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= XmlNode::IsBaseUri;
  else if (qn->isId())
    theFlags |= XmlNode::IsId;

  reinterpret_cast<ElementNode*>(parent)->addBindingForQName(theName);

  NODE_TRACE1("Constructed attribute node " << this << " parent = " << parent 
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
XmlNode* AttributeNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  AttributeNode* copyNode = NULL;
  Item_t qname = theName;
  Item_t typeName;
  Item_t typedValue;
  bool isIdRefs = false;

  if (copymode.theTypePreserve)
  {
    typeName = theTypeName;
    isIdRefs = this->isIdRefs();
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
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new AttributeNode(tree, copymode.theAssignIds, qname,
                                   typeName, typedValue, isIdRefs);
    }
    else if (parent == rootParent)
    {
      copyNode = new AttributeNode(parent, pos, qname,
                                   typeName, typedValue, isIdRefs);
    }
    else
    {
      copyNode = new AttributeNode(parent, qname,
                                   typeName, typedValue, isIdRefs);
    }

    if (isHidden())
      copyNode->setHidden();
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

  NODE_TRACE1("Copied attribute node " << this << " to node " << copyNode
              << " name = " << theName->show() << " parent = ");
  if (parent) { NODE_TRACE1(parent); }
  else{ NODE_TRACE1("NULL"); }
  NODE_TRACE1(" pos = " << pos << " copy mode = " << copymode.toString());

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
  Node constructor used during loading of an xml doc
********************************************************************************/
TextNode::TextNode(xqpStringStore_t& value) : XmlNode()
{
  theContent.transfer(value);

  NODE_TRACE1("Loaded text node " << this << " content = " << *theContent);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& value)
  :
  XmlNode(tree, assignIds)
{
  theContent.transfer(value);

  NODE_TRACE1("Constructed root text node " << this << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlNode*          parent,
    ulong             pos,
    xqpStringStore_t& value)
  :
  XmlNode(parent, pos, StoreConsts::textNode)
{
  theContent.transfer(value);

  NODE_TRACE1("Constructed text node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlNode*          parent,
    xqpStringStore_t& value)
  :
  XmlNode(parent, StoreConsts::textNode)
{
  theContent.transfer(value);

  NODE_TRACE1("Constructed text node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
TextNode::~TextNode()
{
  NODE_TRACE1("Deleted text node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* TextNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  TextNode* copyNode = NULL;
  xqpStringStore_t content = theContent;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new TextNode(tree, copymode.theAssignIds, content);
    }
    else
    {
      XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
        textSibling->theContent = textSibling->theContent->append(theContent);
        return lsib;
      }

      if (parent == rootParent)
        copyNode = new TextNode(parent, pos, content);
      else
        copyNode = new TextNode(parent, content);
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

  NODE_TRACE1("Copied text node " << this << " to node " << copyNode);
  if (parent) { NODE_TRACE1(" parent = " << parent); }
  else { NODE_TRACE1(" parent = NULL"); }
  NODE_TRACE1(" pos = " << pos);

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
  Node constructor used during loading of an xml doc
********************************************************************************/
PiNode::PiNode(xqpStringStore_t& target, xqpStringStore_t& content)
  :
  XmlNode()
{
  theTarget.transfer(target);
  theContent.transfer(content);

  NODE_TRACE1("Loaded pi node " << this << " target = " << theTarget << std::endl);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& target,
    xqpStringStore_t& content)
  :
  XmlNode(tree, assignIds)
{
  theTarget.transfer(target);
  theContent.transfer(content);

  NODE_TRACE1("Constructed root pi node " << this << " target = " << *theTarget);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlNode*          parent,
    ulong             pos,
    xqpStringStore_t& target,
    xqpStringStore_t& content)
  :
  XmlNode(parent, pos, StoreConsts::piNode)
{
  theTarget.transfer(target);
  theContent.transfer(content);

  NODE_TRACE1("Constructed pi node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << *theTarget);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlNode*          parent,
    xqpStringStore_t& target,
    xqpStringStore_t& content)
  :
  XmlNode(parent, StoreConsts::piNode)
{
  theTarget.transfer(target);
  theContent.transfer(content);

  NODE_TRACE1("Constructed pi node " << this << " parent = " << parent
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
XmlNode* PiNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  PiNode* copyNode = NULL;
  xqpStringStore_t content = theContent;
  xqpStringStore_t target = theTarget;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new PiNode(tree, copymode.theAssignIds, target, content);
    }
    else if (parent == rootParent)
    {
      copyNode = new PiNode(parent, pos, target, content);
    }
    else
    {
      copyNode = new PiNode(parent, target, content);
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

  NODE_TRACE1("Copied pi node " << this << " to node " << copyNode);
  if (parent) { NODE_TRACE1(" parent = " << parent); }
  else { NODE_TRACE1(" parent = NULL"); }
  NODE_TRACE1(" pos = " << pos);

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
  Node constructor used during loading of an xml doc
********************************************************************************/
CommentNode::CommentNode(xqpStringStore_t& content)
  :
  XmlNode()
{
  theContent.transfer(content);

  NODE_TRACE1("Loaded comment node " << this << " content = " << *theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlTree*          tree,
    bool              assignIds,
    xqpStringStore_t& content)
  :
  XmlNode(tree, assignIds)
{
  theContent.transfer(content);

  NODE_TRACE1("Constructed root comment node " << this << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlNode*          parent,
    ulong             pos,
    xqpStringStore_t& content)
  :
  XmlNode(parent, pos, StoreConsts::commentNode)
{
  theContent.transfer(content);

  NODE_TRACE1("Constructed comment node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlNode*          parent,
    xqpStringStore_t& content)
  :
  XmlNode(parent, StoreConsts::commentNode)
{
  theContent.transfer(content);

  NODE_TRACE1("Constructed comment node " << this << " parent = " << parent
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << *theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::~CommentNode()
{
  NODE_TRACE1("Deleted comment node " << this);
}


/*******************************************************************************

********************************************************************************/
XmlNode* CommentNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  CommentNode* copyNode = NULL;
  xqpStringStore_t content = theContent;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new CommentNode(tree, copymode.theAssignIds, content);
    }
    else if (parent == rootParent)
    {
      copyNode = new CommentNode(parent, pos, content);
    }
    else
    {
      copyNode = new CommentNode(parent, content);
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

  NODE_TRACE1("Copied comment node " << this << " to node " << copyNode);
  if (parent) { NODE_TRACE1(" parent = " << parent); }
  else { NODE_TRACE1(" parent = NULL"); }
  NODE_TRACE1(" pos = " << pos);

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

