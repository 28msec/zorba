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
#include <memory>

#include "zorbaerrors/error_manager.h"
#include "zorbaerrors/Assert.h"
#include "zorbatypes/URI.h"

#include "store/api/copymode.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/simple_collection.h"
#include "store/naive/simple_item_factory.h"
#include "store/naive/qname_pool.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/naive/item_iterator.h"
#include "store/naive/dataguide.h"



namespace zorba { namespace simplestore {



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XmlTree                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
XmlTree::XmlTree(XmlNode* root, ulong id)
  :
  theRefCount(0),
  theId(id),
  thePos(0),
  theCollection(NULL),
  theRootNode(root),
  theDataGuideRootNode(NULL),
  theIsValidated(false),
  theIsRecursive(false)
{
}


/*******************************************************************************

********************************************************************************/
void XmlTree::setCollection(SimpleCollection* collection, ulong pos) 
{
  ZORBA_ASSERT(collection == NULL || theCollection == NULL);

  theCollection = collection;
  thePos = pos;

  if (collection != NULL)
    theId = collection->createTreeId();
}


/*******************************************************************************

********************************************************************************/
ulong XmlTree::getCollectionId() const
{
  if (theCollection != NULL)
    return theCollection->getId();
  else
    return 0;
}


/*******************************************************************************

********************************************************************************/
void XmlTree::free() throw()
{
  // std::cout << "Deleting Xml Tree: " << this << std::endl;

  if (theRootNode != 0)
  {
    theRootNode->destroy();
    theRootNode = NULL;
  }

  if (theDataGuideRootNode != NULL)
  {
    theDataGuideRootNode->deleteTree();
    theDataGuideRootNode = NULL;
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
  deleted. The assumption holds because this case is used only during the
  evaluation of a node-constructor expression, or during the copying of a
  subtree S, and if the node to be created is not the copy of the root of S.
********************************************************************************/
XmlNode::XmlNode(
    XmlTree* tree,
    InternalNode* parent,
    long pos,
    store::StoreConsts::NodeKind nodeKind)
  :
  theParent(parent),
  theFlags(0)
{
  assert(tree || parent);
  assert(parent == NULL || parent->getTree() != NULL);
  assert(tree == NULL || parent == NULL || parent->getTree() == tree);

  theFlags = (uint32_t)nodeKind;

  if (parent == NULL)
  {
    setTree(tree);
    tree->setRoot(this);
    theOrdPath.setAsRoot();

    if (nodeKind != store::StoreConsts::documentNode)
      theOrdPath.appendComp(1);
  }
  else
  {
    setTree(parent->getTree());
    setOrdPath(parent, pos, nodeKind);
  }
}


/*******************************************************************************

********************************************************************************/
#ifndef NDEBUG
XmlNode::~XmlNode() 
{
  NODE_TRACE1("Deleted " << store::StoreConsts::toString(getNodeKind()) << this);
}
#endif


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
    InternalNode* parent,
    long pos,
    store::StoreConsts::NodeKind nodeKind)
{
  if (parent == NULL)
  {
    theOrdPath.setAsRoot();
    return;
  }

  if (!parent->theOrdPath.isValid())
    return;

  ulong numChildren = parent->numChildren();
  ulong numAttrs = 0;
  ElementNode* elemParent = NULL;

  if (parent->getNodeKind() == store::StoreConsts::elementNode)
  {
    elemParent = reinterpret_cast<ElementNode*>(parent);
    numAttrs =  elemParent->numAttributes();
  }
                    
  if (nodeKind == store::StoreConsts::attributeNode)
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
        OrdPath::insertBefore(elemParent->theOrdPath,
                              elemParent->getAttr(0)->theOrdPath,
                              theOrdPath);
      }
      else if (upos == numAttrs && numChildren > 0)
      {
        OrdPath::insertInto(elemParent->theOrdPath,
                            elemParent->getAttr(upos-1)->theOrdPath,
                            elemParent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (upos >= numAttrs)
      {
        OrdPath::insertAfter(elemParent->theOrdPath,
                             elemParent->getAttr(upos-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(elemParent->theOrdPath,
                            elemParent->getAttr(upos-1)->theOrdPath,
                            elemParent->getAttr(upos)->theOrdPath,
                            theOrdPath);
      }
    }
    else if (numChildren > 0)
    {
      OrdPath::insertBefore(elemParent->theOrdPath,
                            elemParent->getChild(0)->getOrdPath(),
                            theOrdPath);
    }
    else
    {
      theOrdPath = elemParent->theOrdPath;
      theOrdPath.appendComp(1);
    }
  }
  else if (elemParent != NULL) // not attribute node with element parent
  {
    if (pos < 0)
    {
      theOrdPath = elemParent->theOrdPath;
      theOrdPath.appendComp(2 * (numAttrs + numChildren) + 1);
    }
    else if (numChildren > 0)
    {
      ulong upos = (ulong)pos;

      if (upos == 0 && numAttrs > 0)
      {
        OrdPath::insertInto(elemParent->theOrdPath,
                            elemParent->getAttr(numAttrs-1)->theOrdPath,
                            elemParent->getChild(0)->theOrdPath,
                            theOrdPath);
      }
      else if (upos == 0)
      {
        OrdPath::insertBefore(elemParent->theOrdPath,
                              elemParent->getChild(0)->theOrdPath,
                              theOrdPath);
      }
      else if (upos >= numChildren)
      {
        OrdPath::insertAfter(elemParent->theOrdPath,
                             elemParent->getChild(numChildren-1)->theOrdPath,
                             theOrdPath);
      }
      else
      {
        OrdPath::insertInto(elemParent->theOrdPath,
                            elemParent->getChild(upos-1)->theOrdPath,
                            elemParent->getChild(upos)->theOrdPath,
                            theOrdPath);
      }
    }
    else if (numAttrs > 0)
    {
      OrdPath::insertAfter(elemParent->theOrdPath,
                           elemParent->getAttr(numAttrs-1)->theOrdPath,
                           theOrdPath);
    }
    else
    {
      theOrdPath = elemParent->theOrdPath;
      theOrdPath.appendComp(1);
    }
  }
  else // not attribute node with document parent
  {
    if (pos < 0)
    {
      theOrdPath = parent->theOrdPath;
      theOrdPath.appendComp(2 * (numAttrs + numChildren) + 1);
    }
    else if (numChildren > 0)
    {
      ulong upos = (ulong)pos;

      if (upos == 0)
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
uint32_t XmlNode::hash(long timezone, const XQPCollator* aCollation) const
{
  ulong tid = getTree()->getId();

  return hashfun::h32((void*)(&tid), sizeof(ulong), theOrdPath.hash());
}


/*******************************************************************************

********************************************************************************/
store::Item_t XmlNode::getEBV() const
{
  store::Item_t bVal;
  GET_FACTORY().createBoolean(bVal, true);
  return bVal;
}


/*******************************************************************************
  Document and element methods redefine this method.
********************************************************************************/
xqpStringStore_t XmlNode::getBaseURIInternal(bool& local) const
{
  local = false;
  return theParent ? theParent->getBaseURI() : 0;
}


/*******************************************************************************
  Make a copy of the xml tree rooted at this node and place the copied tree at
  a given position under a given node. Return a pointer to the root node of the
  copied tree.

  parent   : The node P under which the copied tree is to be placed. P may be
             NULL, in which case the copied tree becomes a new standalone tree.
  pos      : The position under P where the copied tree is to be placed. If
             "this" is an attribute node, pos is a position among the attributes
             of P; otherwise it is a position among the children of P. If pos
             is greater or equal to the current number of attrs/children in P,
             then the copied tree is appended to P's attributes/children.
  copymode : Encapsulates the construction-mode and copy-namespace-mode
             components of the query's static context. 
********************************************************************************/
store::Item* XmlNode::copy(
    store::Item* inParent,
    long pos,
    const store::CopyMode& copymode) const
{
  InternalNode* parent = NULL;

  if (inParent)
  {
    parent = reinterpret_cast<InternalNode*>(inParent);
    ZORBA_ASSERT(inParent->getNodeKind() == store::StoreConsts::elementNode ||
                 inParent->getNodeKind() == store::StoreConsts::documentNode);
  }

  if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    if (parent)
    {
      ElementNode* pnode = reinterpret_cast<ElementNode*>(parent);
      pnode->checkUniqueAttr(getNodeName());
    }
  }

  return copyInternal(parent, parent, (long)pos, NULL, copymode);
}


/*******************************************************************************
  Connect "this" to the given parent at the given position.
********************************************************************************/
void XmlNode::connect(InternalNode* parent, ulong pos) throw()
{
  ZORBA_FATAL(theParent == NULL, "");

  theParent = parent;

  if (getNodeKind() == store::StoreConsts::attributeNode)
  {
    parent->attributes().insert(this, pos);
  }
  else
  {
    parent->children().insert(this, pos);
  }
}


/*******************************************************************************
  Disconnect "this" node from its parent, if any. 
********************************************************************************/
long XmlNode::disconnect() throw()
{
  if (theParent == NULL)
    return -1;

  try
  {
    ulong pos;

    if (getNodeKind() == store::StoreConsts::attributeNode)
    {
      pos = theParent->attributes().find(this);
      ZORBA_FATAL(pos < theParent->numAttributes(), "");
      theParent->attributes().remove(pos);
    }
    else
    {
      pos = theParent->children().find(this);
      ZORBA_FATAL(pos < theParent->numChildren(), "");
      theParent->children().remove(pos);
    }
    
    theParent = NULL;

    return pos;
  }
  catch(...)
  {
    ZORBA_FATAL(false, "Unexpected exception");
  }
}


/*******************************************************************************
  Deallocate all nodes in the subtree rooted at "this".
********************************************************************************/
void XmlNode::destroy() throw()
{
  try
  {
    disconnect();

    destroyInternal();
  }
  catch (...)
  {
    ZORBA_FATAL(false, "Unexpectd exception");
  }
}


void XmlNode::destroyInternal() throw()
{
  if (getNodeKind() == store::StoreConsts::elementNode)
  {
    ElementNode* elemNode = reinterpret_cast<ElementNode*>(this);

    ulong numChildren = elemNode->numChildren();
    ulong numAttrs = elemNode->numAttributes();

    for (ulong i = 0; i < numChildren; i++)
    {
      elemNode->getChild(i)->destroyInternal();
    }
    
    for (ulong i = 0; i < numAttrs; i++)
    {
      elemNode->getAttr(i)->destroyInternal();
    }
  }
  else if (getNodeKind() == store::StoreConsts::documentNode)
  {
    DocumentNode* docNode = reinterpret_cast<DocumentNode*>(this);

    ulong numChildren = docNode->numChildren();

    for (ulong i = 0; i < numChildren; i++)
    {
      XmlNode* child = docNode->getChild(i);
      if (child->theParent == this)
      {
        child->destroyInternal();
      }
    }
  }

  delete this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class InternalNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void InternalNode::insertChild(XmlNode* child, ulong pos)
{
  children().insert(child, pos);

  assert(child->theParent == NULL);

  child->theParent = this;
}


/*******************************************************************************
  Remove the i-th child of "this" (it is assumed that i < numChildren).
********************************************************************************/
bool InternalNode::removeChild(ulong pos)
{
  bool found = (pos < numChildren());

  if (found)
  {
    XmlNode* child = getChild(pos);
    assert(child->theParent == this);
    children().remove(pos);
    child->theParent = NULL;
  }

  return found;
}


/*******************************************************************************
  If the given node N is a child of "this", disconnect N from "this". Return
  true if N was a child of "this"; false otherwise.
********************************************************************************/
bool InternalNode::removeChild(XmlNode* child)
{
  bool found = children().remove(child);

  if (found)
  {
    assert(child->theParent == this);
    child->theParent = NULL;
  }

  return found;
}


/*******************************************************************************
  Remove the i-th attribute of "this" (it is assumed that i < numAttributes).
********************************************************************************/
void InternalNode::removeAttr(ulong i)
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
bool InternalNode::removeAttr(XmlNode* attr)
{
  bool found = attributes().remove(attr);

  if (found)
  {
    assert(attr->theParent == this);
    attr->theParent = NULL;
  }

  return found;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
DocumentNode::DocumentNode()
  :
  InternalNode(store::StoreConsts::documentNode)
{
  NODE_TRACE1("Loaded doc node " << this);
}


/*******************************************************************************

********************************************************************************/
DocumentNode::DocumentNode(
    XmlTree*                tree,
    const xqpStringStore_t& baseUri,
    const xqpStringStore_t& docUri)
  :
  InternalNode(tree, NULL, 0, store::StoreConsts::documentNode)
{
  if (baseUri != NULL && !baseUri->empty())
    tree->setBaseUri(baseUri);

  tree->setDocUri(docUri);

  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << (docUri != 0 ? docUri->c_str() : "NULL"));
}


/*******************************************************************************

********************************************************************************/
XmlNode* DocumentNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  ZORBA_ASSERT(rootParent == NULL && parent == NULL);

  XmlTree* tree = NULL;
  InternalNode* copyNode = NULL;

  try
  {
    tree = new XmlTree(NULL, GET_STORE().createTreeId());

    copyNode = new DocumentNode(tree, getBaseUri(), getDocUri());

    ulong numChildren = this->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      XmlNode* child = getChild(i);

      child->copyInternal(rootParent, copyNode, -1, NULL, copymode);
    }
  }
  catch (...)
  {
    // Note: no rchandles to copied nodes should be used during the copy, so
    // that we can call tree->free() and destroy all the nodes in the copied
    // tree.
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
xqpStringStore_t DocumentNode::getBaseURIInternal(bool& local) const
{
  local = true;
  return getBaseUri();
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t DocumentNode::getChildren() const
{
  ChildrenIteratorImpl* res = new ChildrenIteratorImpl();
  res->init((InternalNode*)this);
  return res;
}


/*******************************************************************************

********************************************************************************/
store::Item* DocumentNode::getType() const
{
  // ???? should return NULL?
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED];
}


/*******************************************************************************

********************************************************************************/
void DocumentNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  xqpStringStore_t rch = getStringValue();
  val = new UntypedAtomicItemImpl(rch);
  iter = NULL;
}


/*******************************************************************************

********************************************************************************/
store::Item_t DocumentNode::getAtomizationValue() const
{
  xqpStringStore_t rch = getStringValue();
  return new UntypedAtomicItemImpl(rch);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t DocumentNode::getStringValue() const
{
  std::string buf;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    store::StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != store::StoreConsts::commentNode && kind != store::StoreConsts::piNode)
      buf += getChild(i)->getStringValue()->str();
  }

  return new xqpStringStore(buf);
}


void DocumentNode::getStringValue(xqpStringStore_t& strval) const
{
  strval = new xqpStringStore("");
  getStringValue(strval->str());
}


void DocumentNode::getStringValue(std::string& buf) const
{
  ulong numChildren = this->numChildren();

  for (ulong i = 0; i < numChildren; i++)
  {
    store::StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
      getChild(i)->getStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
xqp_string DocumentNode::show() const
{
  std::stringstream strStream;

  strStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
            << "<document";
  if (getBaseUri() != NULL)
    strStream << " baseUri = \"" << *getBaseUri();
  if (getDocUri() != NULL)
    strStream << " docUri = \"" << *getDocUri();
  strStream << "\">" << std::endl;

  store::Iterator_t iter = getChildren();
  store::Item_t item;
  while (iter->next(item))
  {
    strStream << item->show();
  }
  
  strStream << std::endl << "</document>";

  return strStream.str().c_str();
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
ElementNode::ElementNode(
    store::Item_t& nodeName,
    ulong          numBindings,
    ulong          numAttributes)
  :
  InternalNode(store::StoreConsts::elementNode)
{
  theName.transfer(nodeName);
  setHaveValue();
  resetRecursive();

  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << " name = " << theName->show()
              << " num bindings = " << numBindings << " num attributes = "
              << numAttributes << std::endl);
}


/*******************************************************************************
  Note: localBindings will be NULL if this contructor is called from the copy()
  method (because in that case, the in-scope bindings must be computed by the
  copy() method based on the copy mode). Otherwise, localBindings should not be
  NULL (but may be empty).
********************************************************************************/
ElementNode::ElementNode(
    XmlTree*                    tree,
    InternalNode*               parent,
    long                        pos,
    store::Item_t&              nodeName,
    store::Item_t&              typeName,
    bool                        haveTypedValue,
    bool                        haveEmptyValue,
    bool                        isInSubstGroup,
    const store::NsBindings*    localBindings,
    xqpStringStore_t&           baseUri)
  :
  InternalNode(tree, parent, pos, store::StoreConsts::elementNode)
{
  try
  {
    theName.transfer(nodeName);
    theTypeName.transfer(typeName);

    if (haveTypedValue)
    {
      setHaveValue();
      
      if (haveEmptyValue)
        setHaveEmptyValue();
    }

    if (isInSubstGroup)
      setInSubstGroup();

    resetRecursive();

    if (localBindings)
    {
      if (!localBindings->empty())
      {
        theNsContext = new NsBindingsContext(*localBindings);
        theFlags |= HaveLocalBindings;
      }

      addBindingForQName(theName, false, true);

      if (parent && parent->getNodeKind() == store::StoreConsts::elementNode)
        setNsContext(reinterpret_cast<ElementNode*>(parent)->getNsContext());
    }
    
    // Note: Setting the base uri property of "this" involves the creation of an
    // attribute node having "this" as the parent. So, if addBaseUriProperty()
    // fails, we must manually remove that attribute to avoid memory leak.
    if (baseUri != NULL)
    {
      xqpStringStore_t dummy;
      addBaseUriProperty(baseUri, dummy);
    }

    // Connect this new node to its parent. Do this here (at the end of the try
    // stmt), so that we don't have to undo it inside the catch stmt.
    if (parent)
    {
      parent->children().insert(this, pos);

      XmlNode* ancestor = parent;

      while (ancestor != NULL &&
             ancestor->getNodeKind() == store::StoreConsts::elementNode)
      {
        ElementNode* elemAncestor = reinterpret_cast<ElementNode*>(ancestor);
        if (elemAncestor->theName->equals(theName))
        {
          elemAncestor->setRecursive();
          break;
        }

        ancestor = ancestor->theParent;
      }
    }
  }
  catch (...)
  {
    theName = NULL;
    theTypeName = NULL;
    theNsContext = NULL;

    if (numAttributes() != 0)
    {
      ulong pos = 0;
      XmlNode* attr = getAttr(pos);
      removeAttr(pos);
      delete attr;
    }

    throw;
  }

  NODE_TRACE1("Constructed element node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " type = " << (theTypeName ? 
                                theTypeName->getStringValue()->c_str() :
                                "untyped"));
}


/*******************************************************************************

********************************************************************************/
XmlNode* ElementNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  ElementNode* copyNode = NULL;

  store::Item_t nodeName = theName;
  store::Item_t typeName;
  bool haveValue;
  bool haveEmptyValue;
  bool inSubstGroup;

  NsBindingsContext* parentNsContext = NULL;
  if (parent && parent->getNodeKind() == store::StoreConsts::elementNode)
    parentNsContext = reinterpret_cast<ElementNode*>(parent)->getNsContext();

  NsBindingsContext* rootNsContext = NULL;
  if (rootParent && rootParent->getNodeKind() == store::StoreConsts::elementNode)
    rootNsContext = reinterpret_cast<ElementNode*>(rootParent)->getNsContext();

  if (copymode.theTypePreserve)
  { 
    typeName = theTypeName;
    haveValue = this->haveValue();
    haveEmptyValue = this->haveEmptyValue();
    inSubstGroup = this->isInSubstitutionGroup();
  }
  else
  {
    typeName = NULL;
    haveValue = true;
    haveEmptyValue = false;
    inSubstGroup = false;
  }

  xqpStringStore_t baseUri;

  try
  {
    if (parent == NULL)
      tree = new XmlTree(NULL, GET_STORE().createTreeId());

    pos = (parent == rootParent ? pos : -1);

    copyNode = new ElementNode(tree, parent, pos, nodeName, typeName,
                               haveValue, haveEmptyValue, inSubstGroup,
                               NULL, // local bindings 
                               baseUri);
    if (rootCopy == NULL)
      rootCopy = copyNode;

    if (copymode.theNsPreserve)
    {
      // If we are copying the root of an xml subtree, or a node that does
      // not inherit ns bindings directly from its parent (but may inherit
      // from another ancestor).
      if (parent == rootParent ||
          theNsContext == NULL ||
          (haveLocalBindings() &&
           theNsContext->getParent() != parentNsContext) ||
          theNsContext != parentNsContext)
      {
        if (theNsContext != NULL)
        {
          std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
          getNamespaceBindings(ctx->getBindings());

          if (!ctx->empty())
          {
            copyNode->theNsContext = ctx.release();
            copyNode->theFlags |= HaveLocalBindings;
          }
        }

        if (rootParent && copymode.theNsInherit)
        {
          // If "this" does not belong to any namespace and the root parent
          // has a default ns binding, then undeclare this default binding.
          xqpStringStore* prefix = theName->getPrefix();
          if (prefix->empty() &&
              theName->getNamespace()->empty() &&
              rootParent->getNodeKind() == store::StoreConsts::elementNode)
          {
            xqpStringStore* ns = reinterpret_cast<ElementNode*>(rootParent)->
                                 findBinding(prefix);
            if (ns != NULL)
              copyNode->addLocalBinding(prefix, theName->getNamespace());
          }

          copyNode->setNsContext(rootNsContext);
        }
      }

      // Else the node we are copying is not the root of the xml subtree and
      // it inherits ns bindings directly from its parent.
      else
      {
        if (haveLocalBindings())
        {
          copyNode->theNsContext = new NsBindingsContext(getLocalBindings());
          copyNode->theFlags |= HaveLocalBindings;
        }

        copyNode->setNsContext(parentNsContext);
      }
    }
    else // ! nsPreserve
    {
      if (copymode.theTypePreserve &&
          theTypeName != NULL &&
          (theTypeName->equals(GET_STORE().theSchemaTypeNames[XS_QNAME]) ||
           theTypeName->equals(GET_STORE().theSchemaTypeNames[XS_NOTATION])))
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
            rootParent->getNodeKind() == store::StoreConsts::elementNode &&
            copymode.theNsInherit)
        {
          ns2 = rootNsContext->findBinding(prefix);
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
              rootParent->getNodeKind() == store::StoreConsts::elementNode &&
              copymode.theNsInherit)
          {
            ns2 = rootNsContext->findBinding(prefix);
          }

          if (ns2 == NULL || !ns->byteEqual(*ns2))
            ctx->addBinding(prefix, ns);
        }
      }

      if (!ctx->empty())
      {
        copyNode->theNsContext = ctx.release();
        copyNode->theFlags |= HaveLocalBindings;
      }

      if (copymode.theNsInherit && rootParent)
      {
        copyNode->setNsContext(rootNsContext);
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

      attr->copyInternal(rootParent, copyNode, -1, rootCopy, copymode);
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
        xqpStringStore_t absuri = hiddenBaseUriAttr->getStringValue();
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
      XmlNode* child = getChild(i);

      // If we are copying a subtree into its own containing tree, then avoid
      // copying the root of this subtree again.
      if (child == rootCopy)
        continue;

      child->copyInternal(rootParent, copyNode, -1, rootCopy, copymode);
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
      copyNode->destroy();
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
store::Item* ElementNode::getType() const
{
  return (theTypeName != NULL ?
          theTypeName.getp() :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED].getp()); 
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::haveTypedTypedValue() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
    if (reinterpret_cast<TextNode*>(getChild(0))->isTyped())
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::isId() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
    if (reinterpret_cast<TextNode*>(getChild(0))->isIdInternal())
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::isIdRefs() const
{
  if (numChildren() == 1 &&
      getChild(0)->getNodeKind() == store::StoreConsts::textNode)
  {
    if (reinterpret_cast<TextNode*>(getChild(0))->isIdRefsInternal())
      return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  if (haveValue())
  {
    if (haveEmptyValue())
    {
      val = NULL;
      iter = NULL;
    }
    else if (haveTypedTypedValue())
    {
      const TextNode* child = reinterpret_cast<const TextNode*>(getChild(0));

      if (child->haveListValue())
      {
        ItemVector* vec = reinterpret_cast<ItemVector*>(child->getValue());
        iter = new ItemIterator(vec->getItems(), true);
        val = NULL;
      }
      else
      {
        val = child->getValue();
        iter = NULL;
      }
    }
    else
    {
      xqpStringStore_t rch = getStringValue();
      val = new UntypedAtomicItemImpl(rch);
    }
  }
  else
  {
    ZORBA_ERROR_DESC_OSS(FOTY0012,
                        "The element node " << *theName->getStringValue()
                        << " with type " << *theTypeName->getStringValue()
                        << " does not have a typed value");
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t ElementNode::getAtomizationValue() const
{
  xqpStringStore_t rch = getStringValue();
  return new UntypedAtomicItemImpl(rch);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementNode::getStringValue() const
{
  xqpStringStore_t strval;
  getStringValue(strval);
  return strval;
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getStringValue(xqpStringStore_t& strval) const
{
  if (this->numChildren() == 1)
  {
    store::StoreConsts::NodeKind kind = getChild(0)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
    {
      getChild(0)->getStringValue(strval);
    }
    else
    {
      strval = new xqpStringStore("");
    }
  }
  else
  {
    strval = new xqpStringStore("");
    getStringValue(strval->str());
  }
}


/*******************************************************************************

********************************************************************************/
void ElementNode::getStringValue(std::string& buf) const
{
  ulong numChildren = this->numChildren();

  for (ulong i = 0; i < numChildren; i++)
  {
    store::StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != store::StoreConsts::commentNode &&
        kind != store::StoreConsts::piNode)
      getChild(i)->getStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t ElementNode::getNilled() const
{
  if (theTypeName == NULL ||
      theTypeName->equals(GET_STORE().theSchemaTypeNames[XS_UNTYPED]))
    return new BooleanItemNaive(false);

  bool nilled = true;
  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    if (getChild(i)->getNodeKind() == store::StoreConsts::elementNode ||
        getChild(i)->getNodeKind() == store::StoreConsts::textNode)
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
    if (attr->getNodeName()->getNamespace()->byteEqual("xsi", 3) &&
        attr->getNodeName()->getLocalName()->byteEqual("nil", 3))
    {
      nilled = true;
      break;
    }
  }

  return new BooleanItemNaive(nilled);
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t ElementNode::getAttributes() const
{
  AttributesIteratorImpl* res = new AttributesIteratorImpl();
  res->init(this);
  return res;
}


/*******************************************************************************

********************************************************************************/
store::Iterator_t ElementNode::getChildren() const
{
  ChildrenIteratorImpl* res = new ChildrenIteratorImpl();
  res->init((XmlNode*)this);
  return res;
}


/*******************************************************************************
  Carefull with this function: it generates the namespaces in the reverse order.
  The higher parent gives the latest namespaces, instead of first.
********************************************************************************/
void ElementNode::getNamespaceBindings(
    store::NsBindings&            bindings,
    store::StoreConsts::NsScoping ns_scoping) const
{
  assert(bindings.empty());

  if (theNsContext != NULL)
  {
    if(ns_scoping != store::StoreConsts::ONLY_PARENT_NAMESPACES)
    {
      bindings = theNsContext->getBindings();
    }

    if(ns_scoping == store::StoreConsts::ONLY_LOCAL_NAMESPACES)
      return;

    const NsBindingsContext* parentContext = theNsContext->getParent();

    while (parentContext != NULL)
    {
      const store::NsBindings& parentBindings = parentContext->getBindings();
      ulong parentSize = parentBindings.size();
      ulong currSize = bindings.size();

      // for each parent binding, add it to the result, if it doesn't have the
      // same prefix as another binding that is already in the result.
      for (ulong i = 0; i < parentSize; i++)
      {
        ulong j;
        for (j = 0; j < currSize; j++)
        {
          if (bindings[j].first->byteEqual(*parentBindings[i].first.getp()))
            break;
        }

        if (j == currSize)
        {
          bindings.push_back(parentBindings[i]);
        }
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
const store::NsBindings& ElementNode::getLocalBindings() const
{
  ZORBA_ASSERT(haveLocalBindings());
  return theNsContext->getBindings();
}


/*******************************************************************************
  Add the ns binding that is implied by the given qname, if such a binding does
  not exist already among the bindings of "this" node. The method returns true
  if a binding was added, or false otherwise.

  The method also checks if the given binding conflicts with the current bindings
  of "this" node. If a conflict exists and replacePrefix is false, an error is
  thrown. Else, if a conflict exists and replacePrefix is true, then the method
  creates and returns a qname with the same local name and ns uri as the given
  qname, but with a prefix that is artificially generated so that the conflict
  is resolved.

  This method is used by the ElementNode and AttributeNode constructors with
  replacePrefix set to true. It is also used by updating methods with 
  replacePrefix set to false.
********************************************************************************/
bool ElementNode::addBindingForQName(
    store::Item_t& qname,
    bool           isAttr,
    bool           replacePrefix)
{
  xqpStringStore* prefix = qname->getPrefix();
  xqpStringStore* ns = qname->getNamespace();

  // If ns is empty, then prefix must be empty
  ZORBA_FATAL(!ns->empty() || prefix->empty(),
              "prefix = " << prefix->str() << "ns = " << ns->str());

  // No ns binding is implied by an attribute qname whose ns uri is empty
  if (ns->empty() && isAttr)
    return false;

  if (prefix->str() != "xml")
  {
    xqpStringStore* ns2 = findBinding(prefix);

    if (ns2 == NULL)
    {
      if (!ns->empty())
      {
        addLocalBinding(prefix, ns);
        return true;
      }
    }
    else if (!ns2->byteEqual(*ns))
    {
      if (replacePrefix)
      {
        //std::cout << "Prefix: " << prefix->str() << " ns: " << ns->c_str() << " ns2: " << ns2->c_str() << " local: " << qname->getLocalName()->str() << "\n";
        ZORBA_FATAL(!ns->empty(), "");

        xqpStringStore_t prefix(new xqpStringStore("XXX"));

        while (findBinding(prefix) != NULL)
          prefix = prefix->append("X");

        GET_FACTORY().createQName(qname, ns, prefix, qname->getLocalName());
        addLocalBinding(prefix, ns);
      }
      else
      {
        ZORBA_ERROR_DESC_OSS(XUDY0024,
                             "The implied namespace binding of "
                             << qname->show()
                             << " conflicts with namespace binding ["
                             << prefix->str() << ", " << ns2->str() << "]");
      }
    }
  }

  return false;
}


/*******************************************************************************
  Same as above, but used when we know that no ns binding conflict exists
********************************************************************************/
void ElementNode::addBindingForQName2(const store::Item* qname)
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
  Add a given ns binding to the local ns bindings of "this", if it's not already
  there. It is assumed that the given binding does not conflit with the other
  local bindings of "this" (ZORBA_FATAL is called if this condition is not true).

  Note: it is possible to add the binding (empty --> empty); this happens when we
  need to delete the default binding (empty --> ns) from the bindings of "this".
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

  theFlags |= HaveLocalBindings;
}


/*******************************************************************************
  Remove the given ns binding from the local ns bindings of "this", if it is
  there.
********************************************************************************/
void ElementNode::removeLocalBinding(xqpStringStore* prefix, xqpStringStore* ns)
{
  if (haveLocalBindings())
    theNsContext->removeBinding(prefix, ns);
}


/*******************************************************************************
  Check if the ns binding implied by the given qname conflicts with the current
  ns bindings of "this" node.
********************************************************************************/
void ElementNode::checkNamespaceConflict(
    const store::Item*  qname,
    XQUERY_ERROR        ecode) const
{
  const QNameItem* qn = reinterpret_cast<const QNameItem*>(qname);

  xqpStringStore* prefix = qn->getPrefix();
  xqpStringStore* ns = qn->getNamespace();

  // Nothing to do if the qname does not imply any ns binding
  if (prefix->empty() && ns->empty())
    return;

  xqpStringStore* ns2 = findBinding(prefix);

  if (ns2 == NULL && prefix->empty() && !ns->empty())
  {
    ZORBA_ERROR_DESC_OSS(ecode,
                         "The implied namespace binding of " << qname->show()
                         << " conflicts with namespace binding ["
                         << prefix->str() << ", \"\"" << "]");
  }

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
void ElementNode::checkUniqueAttr(const store::Item* attrName) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; ++i)
  {
    AttributeNode* attr = getAttr(i);
    if (!attr->isHidden() && attr->getNodeName()->equals(attrName))
    {
      ZORBA_ERROR_PARAM_OSS(XQDY0025, *attrName->getStringValue(), "");
    }
  }
}


/*******************************************************************************
  Check that "this" does not have any attrs with the same name.
********************************************************************************/
void ElementNode::checkUniqueAttrs() const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; ++i)
  {
    AttributeNode* attr = getAttr(i);

    if (attr->isHidden())
      continue;

    const store::Item* attrName = attr->theName.getp();

    for (ulong j = i+1; j < numAttrs; ++j)
    {
      AttributeNode* otherAttr = getAttr(j);

      if (!otherAttr->isHidden() && otherAttr->getNodeName()->equals(attrName))
      {
        ZORBA_ERROR_PARAM_OSS(XUDY0021, *attrName->getStringValue(), "");
      }
    }
  }
}


/*******************************************************************************
  Compute the base-uri property of this element node and store it as a a special
  (hidden) attribute of the node. In general, the base-uri property is computed
  by resolving the "relUri" based on the absolute "absUri". However, if "relUri"
  is an absolute uri already, the base-uri property of the node is set to "relUri".
  It is also possible that "relUri" is NULL, in which case, the base-uri property
  of the node is set to "absUri". 

  It is assumed that both "absUri" and "relUri" (if not NULL) are well-formed uri
  strings.
********************************************************************************/
void ElementNode::addBaseUriProperty(
    xqpStringStore_t& absUri,
    xqpStringStore_t& relUri)
{
  ZORBA_FATAL(absUri != NULL && !absUri->empty(), "");

  const SimpleStore& store = GET_STORE();

  store::Item_t qname = store.getQNamePool().insert(store.XML_URI, "xml", "base");
  store::Item_t typeName = store.theSchemaTypeNames[XS_ANY_URI];

  store::Item_t typedValue;
  if (relUri == NULL)
  {
    typedValue = new AnyUriItemImpl(absUri);
  }
  else
  { 
    xqpStringStore_t resolvedUriString;
    try 
    {
      URI absoluteURI(&*absUri);
      URI resolvedURI(absoluteURI, &*relUri);
      resolvedUriString = resolvedURI.toString().getStore();
    }
    catch (error::ZorbaError&) 
    {
      resolvedUriString.transfer(relUri);
    }

    typedValue = new AnyUriItemImpl(resolvedUriString);
  }

  checkUniqueAttr(qname.getp());

  new AttributeNode(NULL,  // xml tree 
                    this,  // parent
                    0,     // position
                    qname, 
                    typeName,
                    typedValue,
                    false, // isListVale
                    true); // hidden
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

  store::Item_t typedValue;
  if (relUri == NULL)
  {
    typedValue = new AnyUriItemImpl(absUri);
  }
  else
  { 
    xqpStringStore_t resolvedUriString;
    try {
      URI lAbsoluteUri(&*absUri);
      URI lResolvedUri(lAbsoluteUri, &*relUri);
      resolvedUriString = lResolvedUri.toString().getStore();
    } catch (error::ZorbaError& e) {
      ZORBA_FATAL(e.theErrorCode, e.theDescription);
    }
    typedValue = new AnyUriItemImpl(resolvedUriString);
  }

  attr->setTypedValue(typedValue);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementNode::getBaseURIInternal(bool& local) const
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


/*******************************************************************************

********************************************************************************/
xqp_string ElementNode::show() const
{
  std::stringstream str;

  str <<  "<" << *theName->getStringValue() << "-elem";

  str << " nid=\"" << theOrdPath.show() << "\"";

  store::NsBindings nsBindings;
  getNamespaceBindings(nsBindings);

  for (ulong i = 0; i < nsBindings.size(); i++)
  {
    str << " xmlns:" <<  nsBindings[i].first << "=\""
        << nsBindings[i].second << "\"";
  }

  store::Iterator_t iter = getAttributes();
  store::Item_t item;
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
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader only.
********************************************************************************/
AttributeNode::AttributeNode(store::Item_t& attrName)
  :
  XmlNode(store::StoreConsts::attributeNode)
{
  theName.transfer(attrName);

  QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

  if (qn->isBaseUri())
    theFlags |= IsBaseUri;

  NODE_TRACE1("Loaded attr node " << this << " name = "
              << *theName->getStringValue());
}


/*******************************************************************************
  Note: Constructor does NOT check whether the the attr node to create has the
  same name as an existing attr of the parent node. This is so because sometimes
  we know that a name conflict cannot arise (e.g. when the attr is created as
  part of a subtree copy, and the root node of that subtree is not an attr node),
  so we save the overhead of checking. When a check is required, it is the
  responsibility of the caller to call checkUniqueAttr() on the parent before
  invoking this constructor.
********************************************************************************/
AttributeNode::AttributeNode(
    XmlTree*          tree,
    ElementNode*      parent,
    long              pos,
    store::Item_t&    attrName,
    store::Item_t&    typeName,
    store::Item_t&    typedValue,
    bool              isListValue,
    bool              hidden)
  :
  XmlNode(tree, parent, pos, store::StoreConsts::attributeNode)
{
  // Normally, no exceptions are expected by the rest of the code here, but
  // just to be safe, we use a try-catch.
  try
  {
    if (attrName->getPrefix()->empty() && !attrName->getNamespace()->empty())
    {
      xqpStringStore_t prefix(new xqpStringStore("XXX"));
      GET_FACTORY().createQName(attrName,
                                attrName->getNamespace(),
                                prefix,
                                attrName->getLocalName());
    }

    theName.transfer(attrName);
    theTypeName.transfer(typeName);
    theTypedValue.transfer(typedValue);

    if (isListValue)
      setHaveListValue();

    QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

    if (qn->isBaseUri())
      theFlags |= IsBaseUri;

    if (hidden)
      setHidden();

    if (parent)
    {
      // If this is an explicit base uri attribute, (a) set or update the base-uri
      // property of the parent, and (b) create an additional hidden base-uri attr
      // with the resolved version ofthe given uri. 
      if (isBaseUri() && !isHidden())
      {
        xqpStringStore_t parentBaseUri = parent->getBaseURI();
        xqpStringStore_t baseUri = this->getStringValue();

        if (parent->haveBaseUri())
        {
          ulong numAttrs = parent->numAttributes();
          for (ulong i = 0; i < numAttrs; i++)
          {
            AttributeNode* attr = parent->getAttr(i);
            if (attr->isBaseUri() && attr->isHidden())
            {
              attr->destroy();
              break;
            }
          }
        }
        
        if (parentBaseUri == NULL)
          parent->addBaseUriProperty(baseUri, parentBaseUri);
        else
          parent->addBaseUriProperty(parentBaseUri, baseUri);
      }

      // Else, add the ns binding implied by the attr name into the in-scope ns
      // bindings of the parent (if this ns binding is not there already) 
      else if (!isHidden())
      {
        parent->addBindingForQName(theName, true, true);
      }

      // Connect "this" to its parent. We do this at the end of this method
      // so that we don't have to undo it inside the catch clause below.
      parent->attributes().insert(this, pos);
    }
  }
  catch (...)
  {
    theName = NULL;
    theTypeName = NULL;
    theTypedValue = NULL;

    throw;
  }

  NODE_TRACE1("Constructed attribute node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " value = " << *getStringValue());
}


/*******************************************************************************

********************************************************************************/
XmlNode* AttributeNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);
  ZORBA_FATAL(!isHidden(), "");

  SimpleStore& store = GET_STORE();

  XmlTree* tree = NULL;
  AttributeNode* copyNode = NULL;
  store::Item_t nodeName = theName;
  store::Item_t typeName;
  store::Item_t typedValue;

  bool isListValue;

  if (copymode.theTypePreserve)
  {
    typeName = theTypeName;
    typedValue = theTypedValue;

    isListValue = haveListValue();
  }
  else
  {
    isListValue = false;

    typeName = NULL;

    if (!haveListValue() &&
        theTypedValue->getType()->equals(store.theSchemaTypeNames[XS_UNTYPED_ATOMIC]))
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
      tree = new XmlTree(NULL, store.createTreeId());
    
    else if (parent == rootParent)
      reinterpret_cast<ElementNode*>(parent)->checkUniqueAttr(nodeName);

    copyNode = new AttributeNode(tree,
                                 reinterpret_cast<ElementNode*>(parent),
                                 pos,
                                 nodeName,
                                 typeName, typedValue, isListValue,
                                 false); // hidden
  }
  catch (...)
  {
    delete tree;
    throw;
  }
  
  NODE_TRACE1("Copied attribute node " << this << " to node " << copyNode
              << " name = " << theName->show() << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " copy mode = " << copymode.toString());

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
store::Item* AttributeNode::getType() const
{
  return (theTypeName != NULL ?
          theTypeName.getp() :
          GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC].getp()); 
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::setTypedValue(store::Item_t& value)
{
  resetHaveListValue();
  theTypedValue.transfer(value);
}


/*******************************************************************************

********************************************************************************/
void AttributeNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  if (haveListValue())
  {
    iter = new ItemIterator(getValueVector().getItems(), true);
    val = NULL;
  }
  else
  {
    val = theTypedValue;
    iter = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t AttributeNode::getAtomizationValue() const
{
  if (haveListValue())
  {
    ZORBA_ASSERT(0);
  }
  else
  {
    return theTypedValue;
  }
}


/*******************************************************************************

********************************************************************************/
bool AttributeNode::isId() const
{
  QNameItem* qn = reinterpret_cast<QNameItem*>(theName.getp());

  if (qn->isIdQName())
    return true;

  if (dynamic_cast<IDItemImpl*>(theTypedValue.getp()) != NULL)
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool AttributeNode::isIdRefs() const
{
  if (haveListValue())
  {
    const ItemVector& values = getValueVector();
    ulong numValues = values.size();

    for (ulong i = 0; i < numValues; ++i)
    {
      if (dynamic_cast<IDREFItemImpl*>(values.getItem(i)) != NULL)
        return true;
    }
  }
  else if (dynamic_cast<IDREFItemImpl*>(theTypedValue.getp()) != NULL)
  {
    return true;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t AttributeNode::getStringValue() const
{
  xqpStringStore_t strval;
  getStringValue(strval);
  return strval;
}


void AttributeNode::getStringValue(xqpStringStore_t& strval) const
{
  if (haveListValue())
  {
    strval = new xqpStringStore("");
    getStringValue(strval->str());
  }
  else
  {
    theTypedValue->getStringValue(strval);
  }
}


void AttributeNode::getStringValue(std::string& buf) const 
{
  if (haveListValue())
  {
    const std::vector<store::Item_t>& items = getValueVector().getItems();

    items[0]->getStringValue(buf);

    ulong size = items.size();
    for (ulong i = 1; i < size; i++)
    {
      buf += " ";
      items[i]->getStringValue(buf);
    }
  }
  else
  {
    theTypedValue->getStringValue(buf);
  }
}


/*******************************************************************************

********************************************************************************/
xqp_string AttributeNode::show() const
{
  return xqpString::concat(theName->getStringValue(), "=\"",
                           getStringValue()->str(), "\"");
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class TextNode                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
TextNode::TextNode(xqpStringStore_t& content)
  :
  XmlNode(store::StoreConsts::textNode)
{
  setText(content);

  NODE_TRACE1("Loaded text node " << this << " content = " << *getText());
}


/*******************************************************************************
  Note: constructor does NOT check if the new text node will be adjacent to an
  existing text node of the parent. This is so because sometimes we know that 
  this case cannot arise (e.g. when the text node is created as part of a subtree
  copy, and the root node of that subtree is not a text node), so we save the
  overhead of checking. When a check is required, it is the responsibility of
  the caller to merge the new text content into the existing text node and skip
  invoking this constructor.
********************************************************************************/
TextNode::TextNode(
    XmlTree*          tree,
    InternalNode*     parent,
    long              pos,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, store::StoreConsts::textNode)
{
  setText(content);

  if (parent)
  {
    if (parent->getNodeKind() == store::StoreConsts::elementNode &&
        parent->numChildren() == 1 &&
        parent->getChild(0)->getNodeKind() == store::StoreConsts::textNode)
    {
      TextNode* textChild = reinterpret_cast<TextNode*>(parent->getChild(0));
      ZORBA_ASSERT(!textChild->isTyped());
    }

    parent->children().insert(this, pos);
  }

  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << *getText());
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    InternalNode*     parent,
    store::Item_t&    content,
    bool              isListValue)
  :
  XmlNode(NULL, parent, -1, store::StoreConsts::textNode)
{
  assert(parent != NULL);

  ZORBA_ASSERT(parent->getNodeKind() == store::StoreConsts::elementNode);

  ElementNode* p = reinterpret_cast<ElementNode*>(parent);

  ZORBA_ASSERT(p->numChildren() == 0);
  ZORBA_ASSERT(p->haveValue() && !p->haveEmptyValue());

  setTyped(content);
  if (isListValue)
    setHaveListValue();

  p->children().push_back(this);

  NODE_TRACE1("Constructed text node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) 
              << " ordpath = " << theOrdPath.show() << " content = "
              << getValue()->getStringValue()->c_str());
}


/*******************************************************************************

********************************************************************************/
XmlNode* TextNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  TextNode* copyNode = NULL;
  xqpStringStore_t textContent;
  store::Item_t typedContent;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().createTreeId());

      textContent = getStringValue();
      copyNode = new TextNode(tree, NULL, pos, textContent);
    }
    else
    {
      if (parent == rootParent)
      {
        // Merge adjacent text nodes.
        ulong numChildren = parent->numChildren();
        ulong pos2 = (pos >= 0 ? pos : numChildren);
   
        XmlNode* lsib = (pos2 > 0 ? parent->getChild(pos2-1) : NULL);
        XmlNode* rsib = (pos2 < numChildren ? parent->getChild(pos2) : NULL);

        if (lsib != NULL &&
            lsib->getNodeKind() == store::StoreConsts::textNode)
        {
          TextNode* textSibling = reinterpret_cast<TextNode*>(lsib);
          ZORBA_ASSERT(!textSibling->isTyped());

          textContent = textSibling->getText()->append(getStringValue());

          textSibling->setText(textContent);
          copyNode = textSibling;
        }
        else if (rsib != NULL &&
                 rsib->getNodeKind() == store::StoreConsts::textNode)
        {
          TextNode* textSibling = reinterpret_cast<TextNode*>(rsib);
          ZORBA_ASSERT(!textSibling->isTyped());
          
          textContent = getStringValue()->append(textSibling->getText());
          textSibling->setText(textContent);
          copyNode = textSibling;
        }
        else if (isTyped())
        {
          textContent = getValue()->getStringValue();
          copyNode = new TextNode(NULL, parent, pos, textContent);
        }
        else
        {
          textContent = getText();
          copyNode = new TextNode(NULL, parent, pos, textContent);
        }
      }
      else if (isTyped())
      {
        if (copymode.theTypePreserve)
        {
          typedContent = getValue();
          copyNode = new TextNode(parent, typedContent, haveListValue());
        }
        else
        {
          textContent = getValue()->getStringValue();
          copyNode = new TextNode(NULL, parent, pos, textContent);
        }
      }
      else
      {
        textContent = getText();
        copyNode = new TextNode(NULL, parent, pos, textContent);
      }
    }
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied text node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}



/*******************************************************************************

********************************************************************************/
bool TextNode::isTyped() const 
{
  return (theFlags & IsTyped) != 0;
}


/*******************************************************************************

********************************************************************************/
void TextNode::resetTyped()
{
  if (isTyped())
  {
    xqpStringStore_t text;
    getStringValue(text);
    setValue(NULL);
    setText(text);

    theFlags &= ~IsTyped;
  }
}


/*******************************************************************************

********************************************************************************/
void TextNode::setTyped(store::Item_t& value)
{
  if (!isTyped())
  {
    xqpStringStore_t text;
    getStringValue(text);
    setText(NULL);
    setValue(value);

    theFlags |= IsTyped;
  }
  else
  {
    setValue(value);
  }
}


/*******************************************************************************

********************************************************************************/
store::Item* TextNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


/*******************************************************************************

********************************************************************************/
void TextNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  xqpStringStore_t rch;

  if (isTyped())
  {
    rch = getValue()->getStringValue();
    val = new UntypedAtomicItemImpl(rch);
  }
  else
  {
    rch = getText(); 
    val = new UntypedAtomicItemImpl(rch);
  }
  iter = NULL;
}


store::Item_t TextNode::getAtomizationValue() const
{
  xqpStringStore_t rch;

  if (isTyped())
  {
    rch = getValue()->getStringValue();
    return new UntypedAtomicItemImpl(rch);
  }
  else
  {
    rch = getText(); 
    return new UntypedAtomicItemImpl(rch);
  }
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isIdInternal() const
{
  if (isTyped() && dynamic_cast<IDItemImpl*>(getValue()) != NULL)
    return true;

  return false;
}


/*******************************************************************************

********************************************************************************/
bool TextNode::isIdRefsInternal() const
{
  if (isTyped())
  {
    store::Item* value = getValue();

    if (haveListValue())
    {
      const ItemVector& values = *reinterpret_cast<ItemVector*>(value); 
      ulong numValues = values.size();

      for (ulong i = 0; i < numValues; ++i)
      {
        if (dynamic_cast<IDREFItemImpl*>(values.getItem(i)) != NULL)
          return true;
      }
    }
    else if (dynamic_cast<IDREFItemImpl*>(value) != NULL)
    {
      return true;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t TextNode::getStringValue() const
{
  if (isTyped())
  {
    return getValue()->getStringValue();
  }
  else
  {
    return getText();
  }
}


void TextNode::getStringValue(xqpStringStore_t& strval) const
{
  if (isTyped())
  {
    getValue()->getStringValue(strval);
  }
  else
  {
    strval = getText();
  }
}


void TextNode::getStringValue(std::string& buf) const
{
  if (isTyped())
  {
    getValue()->getStringValue(buf);
  }
  else
  {
    buf += getText()->c_str();
  }
}


/*******************************************************************************

********************************************************************************/
xqp_string TextNode::show() const
{
    return xqpString::concat("<text nid=\"", theOrdPath.show(), "\">", 
                           getStringValue(), "</text>");
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class PiNode                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used by FastXmlLoader
********************************************************************************/
PiNode::PiNode(xqpStringStore_t& target, xqpStringStore_t& content)
  :
  XmlNode(store::StoreConsts::piNode)
{
  QNamePool& qnpool = GET_STORE().getQNamePool();

  theTarget.transfer(target);
  theContent.transfer(content);

  theName = qnpool.insert("", "", theTarget->c_str());

  NODE_TRACE1("Loaded pi node " << this << " target = " << theTarget
              << std::endl);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlTree*          tree,
    InternalNode*          parent,
    long              pos,
    xqpStringStore_t& target,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, store::StoreConsts::piNode)
{
  QNamePool& qnpool = GET_STORE().getQNamePool();

  theTarget.transfer(target);
  theContent.transfer(content);

  theName = qnpool.insert("", "", theTarget->c_str());

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this);
    else
      parent->children().insert(this, pos);
  }

  NODE_TRACE1("Constructed pi node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << *theTarget);
}


/*******************************************************************************

********************************************************************************/
XmlNode* PiNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
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
      tree = new XmlTree(NULL, GET_STORE().createTreeId());

      target = theTarget;
      content = theContent;
      copyNode = new PiNode(tree, NULL, pos, target, content);
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
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied pi node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
store::Item* PiNode::getType() const
{
  return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


void PiNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  xqpStringStore_t rch = theContent; 
  val = new StringItemNaive(rch);
  iter = NULL;
}


store::Item_t PiNode::getAtomizationValue() const
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
  XmlNode(store::StoreConsts::commentNode)
{
  theContent.transfer(content);

  NODE_TRACE1("Loaded comment node " << this << " content = " << *theContent);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlTree*          tree,
    InternalNode*     parent,
    long              pos,
    xqpStringStore_t& content)
  :
  XmlNode(tree, parent, pos, store::StoreConsts::commentNode)
{
  theContent.transfer(content);

  if (parent)
  {
    if (pos < 0)
      parent->children().push_back(this);
    else
      parent->children().insert(this, pos);
  }

  NODE_TRACE1("Constructed comment node " << this << " parent = "
              << std::hex << (parent ? (ulong)parent : 0) << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = "
              << theContent->c_str());
}


/*******************************************************************************

********************************************************************************/
XmlNode* CommentNode::copyInternal(
    InternalNode*          rootParent,
    InternalNode*          parent,
    long                   pos,
    const XmlNode*         rootCopy,
    const store::CopyMode& copymode) const
{
  assert(parent != NULL || rootParent == NULL);

  CommentNode* copyNode = NULL;
  XmlTree* tree = NULL;
  xqpStringStore_t content;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().createTreeId());

      content = theContent;
      copyNode = new CommentNode(tree, NULL, pos, content);
    }
    else
    {
      content = theContent;
      copyNode = new CommentNode(tree, parent, pos, content);
    }
  }
  catch (...)
  {
    delete tree;
    throw;
  }

  NODE_TRACE1("Copied coment node " << this << " to node " << copyNode
              << " parent = " << std::hex << (parent ? (ulong)parent : 0)
              << " pos = " << pos);

  return copyNode;
}


/*******************************************************************************

********************************************************************************/
store::Item* CommentNode::getType() const
{
  return NULL;
  // return GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC];
}


void CommentNode::getTypedValue(store::Item_t& val, store::Iterator_t& iter) const
{
  xqpStringStore_t rch = theContent; 
  val = new StringItemNaive(rch);
  iter = NULL;
}


store::Item_t CommentNode::getAtomizationValue() const
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

