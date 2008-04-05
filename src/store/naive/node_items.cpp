
#include <stack>

#include "system/globalenv.h"
#include "compiler/parser/query_loc.h"
#include "errors/error_manager.h"
#include "util/Assert.h"

#include "store/api/copymode.h"
#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/basic_item_factory.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/api/temp_seq.h"
#include "store/api/item_iterator.h"
#include "zorbatypes/datetime.h"


#ifndef NDEBUG

int traceLevel = -1;

#define NODE_TRACE(level, msg)               \
{                                            \
  if (level <= traceLevel)                   \
    std::cout << msg << std::endl;           \
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

  SYNC_CODE(theRCLockPtr = &(tree->getRCLock());)
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
  SYNC_CODE(theRCLockPtr = &(getTree()->getRCLock());)

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
      theOrdPath.appendComp(2 * (parent->numAttributes() + parent->numChildren()) + 1);
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
  SYNC_CODE(theRCLockPtr = &(getTree()->getRCLock());)

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
xqp_string XmlNode::getBaseURI() const
{
  return theParent ? theParent->getBaseURI() : "";
}


xqp_string XmlNode::getDocumentURI() const
{
  return theParent ? theParent->getDocumentURI() : "";
}


/*******************************************************************************

********************************************************************************/
Item_t XmlNode::getEBV() const
{
  return GET_FACTORY().createBoolean(true);
}


/*******************************************************************************

********************************************************************************/
XmlNode* XmlNode::copy(XmlNode* parent, ulong pos, const CopyMode& copymode)
{
  return copy(parent, parent, pos, copymode);
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

  ulong numChildren = parent->numChildren();
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
  a member of a new given tree, placing as a child or attribute of a given
  parent node P. The position among P's children/attributes where "this" is to
  be placed is also given.     
********************************************************************************/
void XmlNode::switchTree(
    XmlTree* newTree,
    XmlNode* parent,
    ulong    pos,
    bool     assignIds)
{
  ZORBA_FATAL(parent == NULL || parent->getTree() == newTree, "");

  ulong refcount = 0;
  std::stack<XmlNode*> nodes;

  XmlTree* oldTree = getTree();

  SYNC_CODE(oldTree->getRCLock().acquire());

  try
  {
    if (theParent != NULL)
      theParent->removeChild(this);

    theParent = parent;

    refcount += theRefCount;

    setTree(newTree);
    if (theParent == NULL)
      newTree->setRoot(this);

    if (assignIds)
    {
      if (theParent != NULL)
        setOrdPath(parent, pos, getNodeKind());
      else
        theOrdPath.setAsRoot();
    }

    nodes.push(this);

    while (!nodes.empty())
    {
      XmlNode* n = nodes.top();
      nodes.pop();

      ulong numAttrs = n->numAttributes();
      for (ulong i = 0; i < numAttrs; i++)
      {
        XmlNode* attr = n->getAttr(i);
        refcount += attr->theRefCount;
        attr->setTree(newTree);
        if (assignIds)
        {
          attr->theOrdPath = n->theOrdPath;
          attr->theOrdPath.appendComp(2 * i + 1);
        }
      }

      ulong numChildren = n->numChildren();
      for (ulong i = 0; i < numChildren; i++)
      {
        XmlNode* child = n->getChild(i);
        refcount += child->theRefCount;
        child->setTree(newTree);
        if (assignIds)
        {
          child->theOrdPath = n->theOrdPath;
          child->theOrdPath.appendComp(2 * (numAttrs + i) + 1);
        }

        nodes.push(child);
      }
    }

    newTree->getRefCount() += refcount;

    oldTree->getRefCount() -= refcount;
    if (oldTree->getRefCount() == 0)
      oldTree->free();
  }
  catch(...)
  {
    SYNC_CODE(oldTree->getRCLock().release());
    throw;
  }

  SYNC_CODE(oldTree->getRCLock().release());
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
DocumentNode::DocumentNode(xqpStringStore* baseUri, xqpStringStore* docUri)
  :
  XmlNode(),
  theBaseUri(baseUri),
  theDocUri(docUri)
{
}


DocumentNode::DocumentNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  XmlNode(tree, assignIds),
  theBaseUri(baseUri),
  theDocUri(docUri)
{
}


/*******************************************************************************

********************************************************************************/
DocumentNode::~DocumentNode()
{
  NODE_TRACE1("Deleted doc node " << this);
}


Item_t DocumentNode::getType() const
{
  return GET_STORE().theAnyType;
}


Iterator_t DocumentNode::getChildren() const
{
  return (new ChildrenIterator((XmlNode*)this));
}


Iterator_t DocumentNode::getTypedValue() const
{
  Item_t item = new UntypedAtomicItemImpl(getStringValue());
  return new ItemIterator(item);
}


Item_t DocumentNode::getAtomizationValue() const
{
  return new UntypedAtomicItemImpl(getStringValue());
}


xqpStringStore_t DocumentNode::getStringValue() const
{
  std::ostringstream oss;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      oss << getChild(i)->getStringValue()->str();
  }

  return new xqpStringStore(oss.str());
}


/*******************************************************************************

********************************************************************************/
XmlNode* DocumentNode::copy(
    XmlNode*        rootParent,
    XmlNode*        parent,
    ulong           pos,
    const CopyMode& copymode)
{
  assert(rootParent == NULL);

  XmlTree* tree = NULL;
  LoadedDocumentNode* copyNode = NULL;

  try
  {
    tree = new XmlTree(NULL, GET_STORE().getTreeId());

    copyNode = new LoadedDocumentNode(tree, copymode.theAssignIds,
                                      theBaseUri, theDocUri);

    ulong numChildren = this->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      getChild(i)->copy(rootParent, copyNode, 0, copymode);
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
            << "<document baseUri = \"" << *theBaseUri << "\" docUri = \""
            << *theDocUri << "\">" << std::endl;

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
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  DocumentNode(baseUri, docUri)
{
  NODE_TRACE1("Loaded doc node " << this << " base uri = " << *baseUri
              << " doc uri = " << *docUri);
}


/*******************************************************************************

********************************************************************************/
LoadedDocumentNode::LoadedDocumentNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  DocumentNode(tree, assignIds, baseUri, docUri)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << docUri);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrDocumentNode                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrDocumentNode::ConstrDocumentNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  DocumentNode(tree, assignIds, baseUri, docUri)
{
  NODE_TRACE1("{\nConstructing doc node " << this << " tree = "
              << getTree()->getId() << ":" << getTree()
              << " doc uri = " << docUri);
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
        if (textNode->theContent->str() == "")
        {
          item = childrenIte->next();
          continue;
        }

        ulong numChildren = this->numChildren();
        XmlNode* lsib = (numChildren > 0 ? getChild(numChildren-1) : NULL);

        if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
        {
          lsib->getStringValueP()->str() += textNode->getStringValueP()->str();

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
ElementNode::ElementNode(Item*  nodeName, Item* typeName)
  :
  XmlNode(),
  theName(nodeName),
  theTypeName(typeName),
  theFlags(0)
{
}


ElementNode::ElementNode(
    XmlTree* tree,
    bool     assignIds,
    Item*    nodeName,
    Item*    typeName)
  :
  XmlNode(tree, assignIds),
  theName(nodeName),
  theTypeName(typeName),
  theFlags(0)
{
}


ElementNode::ElementNode(
    XmlNode* parent,
    ulong    pos,
    Item*    nodeName,
    Item*    typeName)
  :
  XmlNode(parent, pos, StoreConsts::elementNode),
  theName(nodeName),
  theTypeName(typeName),
  theFlags(0)
{
}


ElementNode::ElementNode(
    XmlNode* parent,
    Item*    nodeName,
    Item*    typeName)
  :
  XmlNode(parent, StoreConsts::elementNode),
  theName(nodeName),
  theTypeName(typeName),
  theFlags(0)
{
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
  return new UntypedAtomicItemImpl(getStringValue());
}


/*******************************************************************************

********************************************************************************/
xqpStringStore_t ElementNode::getStringValue() const
{
  std::ostringstream oss;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      oss << getChild(i)->getStringValue()->str();
  }

  return new xqpStringStore(oss.str());
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::getNilled() const
{
  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    if (getChild(i)->getNodeKind() == StoreConsts::elementNode ||
        getChild(i)->getNodeKind() == StoreConsts::textNode)
      return false;
  }

  return true;
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

********************************************************************************/
void ElementNode::setNsContext(NsBindingsContext* parentCtx)
{
  if (theNsContext == NULL)
    theNsContext = parentCtx;
  else if (theNsContext.getp() != parentCtx)
    theNsContext->setParent(parentCtx);
}


/*******************************************************************************

********************************************************************************/
xqpStringStore* ElementNode::findBinding(xqpStringStore* prefix) const
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

********************************************************************************/
void ElementNode::addBindingForQName(Item* qname)
{
  xqpStringStore* prefix = qname->getPrefix().getStore();
  xqpStringStore* ns = qname->getNamespace().getStore();

  if (prefix->str() != "xml")
  {
    xqpStringStore* ns2 = findBinding(prefix);

    if (ns2 == NULL && !ns->empty())
      addLocalBinding(prefix, ns);
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

********************************************************************************/
void ElementNode::checkUniqueAttr(Item* attrName) const
{
  ulong numAttrs = numAttributes();
  for (ulong i = 0; i < numAttrs; i++)
  {
    if (getAttr(i)->getNodeName()->equals(attrName, NULL))
    {
      ZORBA_ERROR_PARAM_OSS(ZorbaError::XQDY0025,
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
    const CopyMode& copymode)
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  LoadedElementNode* copyNode = NULL;

  Item* typeName = (copymode.theTypePreserve ?
                    theTypeName.getp() :
                    GET_STORE().theUntypedType.getp());
  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new LoadedElementNode(tree, copymode.theAssignIds,
                                       theName, typeName);
    }
    else if (parent == rootParent)
    {
      copyNode = new LoadedElementNode(parent, pos, theName, typeName);
    }
    else
    {
      copyNode = new LoadedElementNode(parent, theName, typeName);
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
          copyNode->setNsContext(rootParent->getNsContext());
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
          (theTypeName == GET_STORE().theQNameType ||
           theTypeName == GET_STORE().theNotationType))
      {
        ZORBA_ERROR(ZorbaError::XQTY0086);
      }

      xqpStringStore* prefix;
      xqpStringStore* ns;
      std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext);

      prefix = theName->getPrefix().getStore();
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
        prefix = getAttr(i)->getNodeName()->getPrefix().getStore();
        ns = getNsContext()->findBinding(prefix);

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

    ulong numAttrs = this->numAttributes();
    for (ulong i = 0; i < numAttrs; i++)
    {
      getAttr(i)->copy(rootParent, copyNode, 0, copymode);
    }

    ulong numChildren = this->numChildren();
    for (ulong i = 0; i < numChildren; i++)
    {
      getChild(i)->copy(rootParent, copyNode, 0, copymode);
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
    Item*  nodeName,
    Item*  typeName,
    ulong  numBindings,
    ulong  numAttributes)
  :
  ElementNode(nodeName, typeName)
{
  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << " name = " << nodeName->show()
              << " num bindings = " << numBindings << " num attributes = "
              << numAttributes << std::endl);
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlTree*  tree,
    bool      assignIds,
    Item*     nodeName,
    Item*     typeName)
  :
  ElementNode(tree, assignIds, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing root element node " << this
              << " tree = " << tree->getId() << ":" << tree
              << " name = " << *nodeName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlNode*  parent,
    ulong     pos,
    Item*     nodeName,
    Item*     typeName)
  :
  ElementNode(parent, pos, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = "
              << parent << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *nodeName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
LoadedElementNode::LoadedElementNode(
    XmlNode*  parent,
    Item*     nodeName,
    Item*     typeName)
  :
  ElementNode(parent, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *nodeName->getStringValue());
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
    Item*     nodeName,
    Item*     typeName)
  :
  ElementNode(tree, assignIds, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing root element node " << this
              << " tree = " << tree->getId() << ":" << tree
              << " name = " << *nodeName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(
    XmlNode*  parent,
    Item*     nodeName,
    Item*     typeName)
  :
  ElementNode(parent, nodeName, typeName)
{
  NODE_TRACE1("{\nConstructing element node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *nodeName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
void ConstrElementNode::constructSubtree(
    Iterator*         attributesIte,
    Iterator*         childrenIte,
    const NsBindings& localBindings,
    bool              copy,
    const CopyMode&   copymode)
{
  Item_t item;
  Item_t prevItem;

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

      addAttribute(BASE_NODE(item), copy, copymode);

      item = attributesIte->next();
    }
  }
  
  if (childrenIte != 0)
  {
    item = childrenIte->next();
    while (item != 0)
    {
      ZORBA_FATAL(item->isNode(), "");
      ZORBA_FATAL(item->getNodeKind() != StoreConsts::documentNode, "");

      XmlNode* cnode = BASE_NODE(item);

      if (cnode->getNodeKind() == StoreConsts::attributeNode)
      {
        addAttribute(cnode, copy, copymode);
      }
      else if (cnode->theParent != this)
      {
        addChild(cnode, copy, copymode);
      }

      item = childrenIte->next();
    }
  }

  theChildren.resize(numChildren());
  theAttributes.resize(numAttributes());

  NODE_TRACE2("Constructed elem node " << this << ":" << *theName->getStringValue());
  NODE_TRACE1("}");
}


void ConstrElementNode::addAttribute(
    XmlNode*        cnode,
    bool            copy,
    const CopyMode& copymode)
{
  if (cnode->theParent != this)
  {
    checkUniqueAttr(cnode->getNodeName().getp());

    if (copy)
    {
      cnode = cnode->copy(this, this, numAttributes(), copymode);
    }
    else
    {
      theAttributes.push_back(cnode, true);
    }
  }

  addBindingForQName(cnode->getNodeName());
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
        lsib->getStringValueP()->str() += textNode->getStringValueP()->str();
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


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Node constructor used during loading of an xml doc
********************************************************************************/
AttributeNode::AttributeNode(
    Item*  attrName,
    Item*  typeName,
    bool   isId,
    bool   isIdrefs)
  :
  XmlNode(),
  theName(attrName),
  theTypeName(typeName),
  theFlags(0)
{
  if (isId)
    theFlags |= XmlNode::IsId;

  if (isIdrefs)
    theFlags |= XmlNode::IsIdRefs;

  NODE_TRACE1("Loaded attr node " << this << " name = "
              << *attrName->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlTree*  tree,
    bool      assignIds,
    Item*     attrName,
    Item*     typeName,
    Item*     typedValue,
    bool      isId,
    bool      isIdrefs)
  :
  XmlNode(tree, assignIds),
  theName(attrName),
  theTypeName(typeName),
  theTypedValue(typedValue),
  theFlags(0)
{
  if (isId)
    theFlags |= XmlNode::IsId;

  if (isIdrefs)
    theFlags |= XmlNode::IsIdRefs;

  NODE_TRACE1("Constructed root attribute node " << this
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " name = " << *theName->getStringValue()
              << " value = " << *typedValue->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlNode*  parent,
    ulong     pos,
    Item*     attrName,
    Item*     typeName,
    Item*     typedValue,
    bool      isId,
    bool      isIdRefs)
  :
  XmlNode(parent, pos, StoreConsts::attributeNode),
  theName(attrName),
  theTypeName(typeName),
  theTypedValue(typedValue),
  theFlags(0)
{
  if (isId)
    theFlags |= XmlNode::IsId;

  if (isIdRefs)
    theFlags |= XmlNode::IsIdRefs;

  NODE_TRACE1("Constructed attribute node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " value = " << *typedValue->getStringValue());
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    XmlNode*  parent,
    Item*     attrName,
    Item*     typeName,
    Item*     typedValue,
    bool      isId,
    bool      isIdRefs)
  :
  XmlNode(parent, StoreConsts::attributeNode),
  theName(attrName),
  theTypeName(typeName),
  theTypedValue(typedValue),
  theFlags(0)
{
  if (isId)
    theFlags |= XmlNode::IsId;

  if (isIdRefs)
    theFlags |= XmlNode::IsIdRefs;

  NODE_TRACE1("Constructed attribute node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show()
              << " name = " << *theName->getStringValue()
              << " value = " << *typedValue->getStringValue());
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
    const CopyMode& copymode)
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  AttributeNode* copyNode = NULL;
  Item* typeName;
  Item* typedValue;
  bool deleteValue = false;
  bool isId = false;
  bool isIdRefs = false;

  if (copymode.theTypePreserve)
  {
    typeName = theTypeName.getp();
    isId = this->isId();
    isIdRefs = this->isIdRefs();
    typedValue = theTypedValue.getp();
  }
  else
  {
    typeName = GET_STORE().theUntypedAtomicType.getp();

    if (theName->getLocalName() == "id" && theName->getPrefix() == "xml")
      isId = true;

    if (theTypedValue->getType()->equals(GET_STORE().theUntypedAtomicType, NULL))
      typedValue = theTypedValue;
    else
    {
      typedValue = new UntypedAtomicItemImpl(getStringValue());
      deleteValue = true;
    }
  }

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new AttributeNode(tree, copymode.theAssignIds, theName,
                                   typeName, typedValue, isId, isIdRefs);
    }
    else if (parent == rootParent)
    {
      copyNode = new AttributeNode(parent, pos, theName,
                                   typeName, typedValue, isId, isIdRefs);
    }
    else
    {
      copyNode = new AttributeNode(parent, theName,
                                   typeName, typedValue, isId, isIdRefs);
    }
    typedValue = NULL;
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

    if (typedValue && deleteValue)
      delete typedValue;

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
TextNode::TextNode(xqpStringStore* value) : XmlNode(), theContent(value)
{
  NODE_TRACE1("Loaded text node " << this << " content = " << *value);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* value)
  :
  XmlNode(tree, assignIds),
  theContent(value)
{
  NODE_TRACE1("Constructed root text node " << this << " content = " << *value);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* value)
  :
  XmlNode(parent, pos, StoreConsts::textNode),
  theContent(value)
{
  NODE_TRACE1("Constructed text node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = " << *value);
}


/*******************************************************************************

********************************************************************************/
TextNode::TextNode(
    XmlNode*        parent,
    xqpStringStore* value)
  :
  XmlNode(parent, StoreConsts::textNode),
  theContent(value)
{
  NODE_TRACE1("Constructed text node " << this << " parent = " << parent 
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = " << *value);
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
    const CopyMode& copymode)
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  TextNode* copyNode = NULL;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new TextNode(tree, copymode.theAssignIds, theContent);
    }
    else
    {
      XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);

      if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
      {
        lsib->getStringValueP()->str() += theContent->str();
        return lsib;
      }

      if (parent == rootParent)
        copyNode = new TextNode(parent, pos, theContent);
      else
        copyNode = new TextNode(parent, theContent);
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
Item_t TextNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t TextNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createUntypedAtomic(theContent.getp());
  return new ItemIterator(item);
}


Item_t TextNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent.getp());
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
PiNode::PiNode(xqpStringStore* target, xqpStringStore* content)
  :
  XmlNode(),
  theTarget(target),
  theContent(content)
{
  NODE_TRACE1("Loaded pi node " << this << " target = " << target << std::endl);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* target,
    xqpStringStore* content)
  :
  XmlNode(tree, assignIds),
  theTarget(target),
  theContent(content)
{
  NODE_TRACE1("Constructed root pi node " << this << " target = " << *target);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* target,
    xqpStringStore* content)
  :
  XmlNode(parent, pos, StoreConsts::piNode),
  theTarget(target),
  theContent(content)
{
  NODE_TRACE1("Constructed pi node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << *target);
}


/*******************************************************************************

********************************************************************************/
PiNode::PiNode(
    XmlNode*        parent,
    xqpStringStore* target,
    xqpStringStore* content)
  :
  XmlNode(parent, StoreConsts::piNode),
  theTarget(target),
  theContent(content)
{
  NODE_TRACE1("Constructed pi node " << this << " parent = " << parent
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " target = " << *target);
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
    const CopyMode& copymode)
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  PiNode* copyNode = NULL;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new PiNode(tree, copymode.theAssignIds, theTarget, theContent);
    }
    else if (parent == rootParent)
    {
      copyNode = new PiNode(parent, pos, theTarget, theContent);
    }
    else
    {
      copyNode = new PiNode(parent, theTarget, theContent);
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
Item_t PiNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t PiNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theContent.getp());
  return new ItemIterator(item);
}


Item_t PiNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent.getp());
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
CommentNode::CommentNode(xqpStringStore* content)
  :
  XmlNode(),
  theContent(content)
{
  NODE_TRACE1("Loaded comment node " << this << " content = " << content);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlTree*        tree,
    bool            assignIds,
    xqpStringStore* content)
  :
  XmlNode(tree, assignIds),
  theContent(content)
{
  NODE_TRACE1("Constructed root comment node " << this << " content = " << *content);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* content)
  :
  XmlNode(parent, pos, StoreConsts::commentNode),
  theContent(content)
{
  NODE_TRACE1("Constructed comment node " << this << " parent = " << parent
              << " pos = " << pos
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = " << *content);
}


/*******************************************************************************

********************************************************************************/
CommentNode::CommentNode(
    XmlNode*        parent,
    xqpStringStore* content)
  :
  XmlNode(parent, StoreConsts::commentNode),
  theContent(content)
{
  NODE_TRACE1("Constructed comment node " << this << " parent = " << parent
              << " tree = " << getTree()->getId() << ":" << getTree()
              << " ordpath = " << theOrdPath.show() << " content = " << *content);
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
    const CopyMode& copymode)
{
  assert(parent != NULL || rootParent == NULL);

  XmlTree* tree = NULL;
  CommentNode* copyNode = NULL;

  try
  {
    if (parent == NULL)
    {
      tree = new XmlTree(NULL, GET_STORE().getTreeId());

      copyNode = new CommentNode(tree, copymode.theAssignIds, theContent);
    }
    else if (parent == rootParent)
    {
      copyNode = new CommentNode(parent, pos, theContent);
    }
    else
    {
      copyNode = new CommentNode(parent, theContent);
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
Item_t CommentNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t CommentNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theContent.getp());
  return new ItemIterator(item);
}


Item_t CommentNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent.getp());
}


/*******************************************************************************

********************************************************************************/
xqp_string CommentNode::show() const
{
  return "<!--" + theContent->str() + "-->";
}

} // namespace store
} // namespace zorba

