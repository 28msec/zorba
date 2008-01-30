/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include <algorithm>

#include "system/zorba.h"
#include "system/zorba_engine.h"

#include "errors/error_factory.h"

#include "runtime/core/item_iterator.h"

#include "store/naive/atomic_items.h"
#include "store/naive/node_items.h"
#include "store/naive/node_iterators.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/naive/nsbindings.h"
#include "store/api/temp_seq.h"


#ifndef NDEBUG

int traceLevel = 0;

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


namespace xqp
{

#define GET_CURRENT_LOCATION() \
        ZORBA_FOR_CURRENT_THREAD()->GetCurrentLocation()


ConstrNodeVector dummyVector;


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  XmlTree                                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


XmlTree::XmlTree(XmlNode* root, unsigned long id)
  :
  theId(id),
  theRootNode(root)
{
}


void XmlTree::free()
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
//  class ConstrNodeVector                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ConstrNodeVector::ConstrNodeVector(ulong size) : NodeVector(size)
{
  theBitmap.resize(size);
  for (ulong i = 0; i < size; i++)
  {
    theBitmap[i] = false;
    theNodes[i] = 0;
  }
}


void ConstrNodeVector::set(ulong pos, XmlNode* node, bool shared)
{
  ZORBA_ASSERT(pos <= size());
  
  if (pos == size())
  {
    push_back(node, shared);
    return;
  }

  if (shared)
  {
    if (!theBitmap[pos])
      theNodes[pos] = NULL;

    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = node;
    theBitmap[pos] = true;
  }
  else
  {
    if (theBitmap[pos])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[pos])) = NULL;

    theNodes[pos] = node;
    theBitmap[pos] = false;
  }
}


void ConstrNodeVector::push_back(XmlNode* node, bool shared)
{
  theNodes.push_back(node);
  theBitmap.push_back(shared);

  if (shared)
    node->addReference();
}


void ConstrNodeVector::clear()
{
  ulong size = this->size();
  for (ulong i = 0; i < size; i++)
  {
    if (theBitmap[i])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = NULL; 
  }

  theNodes.clear();
}


void ConstrNodeVector::resize(ulong newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  ulong oldSize = size();

  theNodes.resize(newSize);
  theBitmap.resize(newSize);
  for (ulong i = oldSize; i < newSize; i++)
  {
    theBitmap[i] = false;
    theNodes[i] = NULL;
  }
}


void ConstrNodeVector::copy(const NodeVector& src)
{
  ulong size = src.size();

  resize(size);

  for (ulong i = 0; i < size; i++)
  {
    *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = src.theNodes[i];
    theBitmap[i] = true;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class XmlNode                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


XmlNode::XmlNode(
    XmlTree*              tree,
    XmlNode*              parent,
    ulong                 pos,
    StoreConsts::NodeKind nodeKind)
  :
  theTree(NULL),
  theParent(NULL)
{
  if (parent == NULL)
  {
    if (tree != NULL)
    {
      theTree = tree;
      theTree->setRoot(this);

      theOrdPath.init();

      NODE_TRACE1("{ \nConstructing root " << StoreConsts::toString(nodeKind) 
                  << " " << this << " tree = " << tree->getId() << ":" << tree);
    }
  }
  else
  {
    assert(parent->getTree() != NULL);
    assert(tree == NULL || tree == parent->getTree());

    theParent = parent;
    theTree = parent->getTree();

    theOrdPath = parent->theOrdPath;

    // Note: we use set() instead of push_back() because we may reach here
    // during the copying of a node, in which case we are replacing the
    // previous (shared) child with its copy.
    if (nodeKind == StoreConsts::attributeNode)
    {
      theOrdPath.appendComp(2 * pos + 1);
      parent->attributes().set(pos, this, false);
    }
    else
    {
      theOrdPath.appendComp(2 * (parent->numAttributes() + pos) + 1);
      parent->children().set(pos, this, false);
    }

    NODE_TRACE1("{ \nConstructing " << StoreConsts::toString(nodeKind)
                << " " << this << " parent = " << parent << " pos = " << pos
                << " ordpath = " << theOrdPath.show()
                << " tree = " << theTree->getId() << ":" << theTree);
  }
}


void XmlNode::appendChild(XmlNode* child)
{
  assert(child->getTree() == NULL);
  assert(child->getParentP() == NULL);
  assert(child->getNodeKind() != StoreConsts::documentNode);
  assert(child->getNodeKind() != StoreConsts::attributeNode);
  assert(child->getNodeKind() != StoreConsts::elementNode); // TODO

  child->theParent = this;
  child->theTree = theTree;

  child->theOrdPath = theOrdPath;
  child->theOrdPath.appendComp(2 * (numAttributes() + numChildren()) + 1);

  children().push_back(child, false);
}


XmlNode::~XmlNode()
{
  ZORBA_ASSERT(theRefCount == 0);
}


xqp_string XmlNode::getBaseURI() const
{
  return theParent ? theParent->getBaseURI() : "";
}


xqp_string XmlNode::getDocumentURI() const
{
  return theParent ? theParent->getDocumentURI() : "";
}


bool XmlNode::equals(Item_t item) const
{
  ZORBA_ASSERT (false && "Equal function for node items not implemented");
  return false;
}


Item_t XmlNode::getEBV() const
{
  return GET_FACTORY().createBoolean(true);
}


void XmlNode::addReference()
{
  assert(theTree != NULL);

  theRefCount++;
  theTree->addReference();
}


void XmlNode::removeReference()
{
  assert(theTree != NULL);

  theRefCount--;
  theTree->removeReference();
}


void XmlNode::setId(XmlTree* tree, const OrdPathStack* op)
{
  ZORBA_ASSERT(theTree == NULL);

  theTree = tree;

  if (op != NULL)
    theOrdPath = *op;
  else
    theOrdPath.init();
}


void XmlNode::deleteTree()
{
  if (getNodeKind() == StoreConsts::documentNode ||
      getNodeKind() == StoreConsts::elementNode)
  {
    unsigned long numChildren = this->numChildren();
    unsigned long numAttrs = this->numAttributes();

    for (unsigned long i = 0; i < numChildren; i++)
    {
      if (getChild(i)->getTree() == getTree())
        getChild(i)->deleteTree();
    }

    for (unsigned long i = 0; i < numAttrs; i++)
    {
      if (getAttr(i)->getTree() == getTree())
        getAttr(i)->deleteTree();
    } 
  }

  delete this;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


DocumentNode::DocumentNode(
    XmlTree*        tree,
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  XmlNode(tree, NULL, 0, StoreConsts::documentNode),
  theBaseUri(baseUri),
  theDocUri(docUri),
  theFlags(0)
{
}


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
  Item_t item = GET_FACTORY().createUntypedAtomic(getStringValue());
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), item));
  return new PlanWrapper(ret);
}


Item_t DocumentNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(getStringValue());
}


xqp_string DocumentNode::getStringValue() const
{
  ostringstream oss;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      oss << getChild(i)->getStringValue();
  }

  return oss.str();
}


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


LoadedDocumentNode::LoadedDocumentNode(
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  DocumentNode(NULL, baseUri, docUri)
{
  NODE_TRACE1("Loaded doc node " << this << " base uri = " << *baseUri
              << " doc uri = " << *docUri);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrDocumentNode                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ConstrDocumentNode::ConstrDocumentNode(
    XmlTree*        tree,
    xqpStringStore* baseUri,
    xqpStringStore* docUri,
    bool            typePreserve,
    bool            nsPreserve,
    bool            nsInherit)
  :
  DocumentNode(tree, baseUri, docUri)
{
  theFlags |= XmlNode::IsConstructed;

  if (typePreserve)
    theFlags |= XmlNode::TypePreserve;

  if (nsPreserve)
    theFlags |= XmlNode::NsPreserve;

  if (nsInherit)
    theFlags |= XmlNode::NsInherit;
}


void ConstrDocumentNode::constructSubtree(Iterator* childrenIte, bool copy)
{
  Item_t item = childrenIte->next();
  while (item != NULL)
  {
    ZORBA_ASSERT(item->isNode());
    ZORBA_ASSERT(item->getNodeKind() != StoreConsts::attributeNode);

    XmlNode* cnode = BASE_NODE(item);

    if (cnode->getTree() != getTree())
    {
      ZORBA_ASSERT(cnode->getParentP() != this);

      // Skip text node with zero-length value
      if (cnode->getNodeKind() == StoreConsts::textNode)
      {
        TextNode* textNode = reinterpret_cast<TextNode*>(cnode);
        if (*textNode->theContent == "")
        {
          item = childrenIte->next();
          continue;
        }
      }

      if (copy)
        cnode = cnode->copy(this, numChildren());
      else
        theChildren.push_back(cnode, true);
    }

    item = childrenIte->next();
  }

  theChildren.resize(numChildren());

  NODE_TRACE2("Constructed doc node " << this << " docUri = " << *theDocUri);
  NODE_TRACE1("}");
}
 

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ElementNode::ElementNode(
    XmlTree*  tree,
    XmlNode*  parent,
    ulong     pos,
    Item*     nodeName)
  :
  XmlNode(tree, parent, pos, StoreConsts::elementNode),
  theName(nodeName),
  theFlags(0)
{
}


/*******************************************************************************

********************************************************************************/
ElementNode::~ElementNode()
{
  NODE_TRACE1("Deleted elem node " << this);
  NODE_TRACE3("nscontext " << theNsContext.get_ptr() << ", "
              << (theNsContext != NULL ? theNsContext->getRefCount() : -1));
}


/*******************************************************************************

********************************************************************************/
const NsBindings& ElementNode::getLocalBindings() const
{
  return theNsContext->getBindings();
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
void ElementNode::getNamespaceBindings(NsBindings& bindings) const
{
  if (theNsContext != NULL)
  {
    bindings = theNsContext->getBindings();

    const NsBindingsContext* parentContext = theNsContext->getParent();

    while (parentContext != NULL)
    {
      const NsBindings& parentBindings = parentContext->getBindings();
      unsigned long parentSize = parentBindings.size();
      unsigned long currSize = bindings.size();

      for (unsigned long i = 0; i < parentSize; i++)
      {
        unsigned long j;
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
  else if (theNsContext.get_ptr() != parentCtx)
    theNsContext->setParent(parentCtx);
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

********************************************************************************/
Iterator_t ElementNode::getTypedValue() const
{
  Item_t retItem = getAtomizationValue();
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), retItem));
  return new PlanWrapper(ret);
}


/*******************************************************************************

********************************************************************************/
Item_t ElementNode::getAtomizationValue() const
{
  xqp_string stringValue = getStringValue();

  return GET_FACTORY().createUntypedAtomic(stringValue);
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNode::getStringValue() const
{
  ostringstream oss;

  ulong numChildren = this->numChildren();
  for (ulong i = 0; i < numChildren; i++)
  {
    StoreConsts::NodeKind kind = getChild(i)->getNodeKind();

    if (kind != StoreConsts::commentNode && kind != StoreConsts::piNode)
      oss << getChild(i)->getStringValue();
  }

  return oss.str();
}


/*******************************************************************************

********************************************************************************/
bool ElementNode::getNilled() const
{
  unsigned long numChildren = this->numChildren();
  for (unsigned long i = 0; i < numChildren; i++)
  {
    if (getChild(i)->getNodeKind() == StoreConsts::elementNode ||
        getChild(i)->getNodeKind() == StoreConsts::textNode)
      return false;
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNode::show() const
{
  std::stringstream str;

  str <<  "<" << theName->getStringValue();

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
  item = iter->next();
  while (item != NULL)
  {
    str << item->show();
    item = iter->next();
  }

  str << "</" << theName->getStringValue() << ">";
  return str.str().c_str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class LoadedElementNode                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


LoadedElementNode::LoadedElementNode(
    Item*  nodeName,
    Item*  typeName,
    ulong  numBindings,
    ulong  numAttributes)
  :
  ElementNode(NULL, NULL, 0, nodeName)
{
  theTypeName = typeName;

  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << ":" << nodeName->show());
  NODE_TRACE1("num bindings = " << numBindings << " num attributes = "
              << numAttributes << std::endl);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrElementNode                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(
    XmlTree*          tree,
    XmlNode*          parent,
    ulong             pos,
    Item*             nodeName,
    Item*             typeName,
    const NsBindings& nsBindings,
    bool              typePreserve,
    bool              nsPreserve,
    bool              nsInherit)
  :
  ElementNode(tree, parent, pos, nodeName)
{
  theTypeName = typeName;

  theFlags |= XmlNode::IsConstructed;

  if (typePreserve)
    theFlags |= XmlNode::TypePreserve;

  if (nsPreserve)
    theFlags |= XmlNode::NsPreserve;

  if (nsInherit)
    theFlags |= XmlNode::NsInherit;

  if (!nsBindings.empty())
  {
    theNsContext = new NsBindingsContext(nsBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  //ZORBA_ASSERT(0);
}


/*******************************************************************************

********************************************************************************/
void ConstrElementNode::constructSubtree(
    Iterator* attributesIte,
    Iterator* childrenIte,
    bool      copy)
{
  Item_t item;
  Item_t prevItem;

  if (attributesIte != 0)
  {
    item = attributesIte->next();
    while (item != 0)
    {
      ZORBA_ASSERT(item->isNode());
      ZORBA_ASSERT(item->getNodeKind() == StoreConsts::attributeNode);

      XmlNode* cnode = BASE_NODE(item);

      if (cnode->getTree() != getTree())
      {
        ZORBA_ASSERT(cnode->getParentP() != this);

        if (copy)
          cnode = cnode->copy(this, numAttributes());
        else
          theAttributes.push_back(cnode, true);
      }

      item = attributesIte->next();
    }
  }
  
  if (childrenIte != 0)
  {
    item = childrenIte->next();
    while (item != 0)
    {
      ZORBA_ASSERT(item->isNode());
      ZORBA_ASSERT(item->getNodeKind() != StoreConsts::documentNode);

      XmlNode* cnode = BASE_NODE(item);

      if (cnode->getNodeKind() == StoreConsts::attributeNode)
      {
        if (cnode->getTree() != getTree())
        {
          ZORBA_ASSERT(cnode->getParentP() != this);

          if (copy)
            cnode = cnode->copy(this, numAttributes());
          else
            theAttributes.push_back(cnode, true);
        }
      }
      else if (cnode->getTree() != getTree())
      {
        ZORBA_ASSERT(cnode->getParentP() != this);

        // Skip text node with zero-length value
        if (cnode->getNodeKind() == StoreConsts::textNode)
        {
          TextNode* textNode = reinterpret_cast<TextNode*>(cnode);
          if (*textNode->theContent == "")
          {
            item = childrenIte->next();
            continue;
          }
        }

        if (copy)
          cnode = cnode->copy(this, numChildren());
        else
          theChildren.push_back(cnode, true);
      }

      item = childrenIte->next();
    }
  }

  theChildren.resize(numChildren());
  theAttributes.resize(numAttributes());

  NODE_TRACE2("Constructed elem node " << this << ":" << theName->show());
  NODE_TRACE1("}");
}


/*******************************************************************************

********************************************************************************/
XmlNode* ElementNode::copy(XmlNode* parent, ulong pos)
{
  // Get an rchandle to "this" node before copying it. This is needed because
  // the tree where "this" belongs to may be referenced only from "parent", and
  // during copying, the rchandle from "parent" to "this" will be changed to a
  // pointer from "parent" to the new copy node. Thus, "this" may be deleted
  // while it is still being copied.
  Item_t tmp = this;

  Item* typeName = (parent->typePreserve() ?
                    theTypeName.get_ptr() :
                    GET_STORE().theUntypedType.get_ptr());

  NsBindings bindings;

  ElementNode* copy = new ConstrElementNode(NULL, parent, pos,
                                            theName.get_ptr(),
                                            typeName,
                                            bindings,
                                            parent->typePreserve(),
                                            parent->nsPreserve(),
                                            parent->nsInherit());

  copy->theFlags |= XmlNode::IsCopy;

  copy->attributes().copy(attributes());
  copy->children().copy(children());

  if (parent->nsPreserve())
  {
    if (!parent->isCopy())
    {
      auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
      getNamespaceBindings(ctx->getBindings());

      if (!ctx->empty())
      {
        copy->theNsContext = ctx.release();
        copy->theFlags |= XmlNode::HaveLocalBindings;
      }
    }
    else if (haveLocalBindings())
    {
      copy->theNsContext = new NsBindingsContext(getLocalBindings());
      copy->theNsContext->setParent(parent->getNsContext());
      copy->theFlags |= XmlNode::HaveLocalBindings;
    }
    else
    {
      copy->theNsContext = parent->getNsContext();
    }

    if (parent->nsInherit())
    {
      if (!parent->isCopy())
        copy->setNsContext(parent->getNsContext());
    }
  }
  else
  {
    xqpStringStore* prefix;
    xqpStringStore* ns;
    std::auto_ptr<NsBindingsContext> ctx(new NsBindingsContext);

    prefix = theName->getPrefix().getStore();
    ns = getNsContext()->findBinding(prefix);

    // ns may be null only if the prefix was empty and there was no default
    // namespace declaration in scope.
    ZORBA_ASSERT(*prefix == "" || ns != NULL);

    if (ns != NULL)
    {
      xqpStringStore* ns2 = NULL;

      if (parent->getNodeKind() == StoreConsts::elementNode && parent->nsInherit())
        ns2 = parent->getNsContext()->findBinding(prefix);

      if (ns2 == NULL || !ns->byteEqual(*ns2))
        ctx->addBinding(prefix, ns);
    }

    ulong numAttrs = numAttributes();

    for (ulong i = 0; i < numAttrs; i++)
    {
      prefix = getAttr(i)->getNodeName()->getPrefix().getStore();
      ns = getNsContext()->findBinding(prefix);

      ZORBA_ASSERT(*prefix == "" || ns != NULL);

      if (ns != NULL)
      {
        xqpStringStore* ns2 = NULL;

        if (parent->getNodeKind() == StoreConsts::elementNode && parent->nsInherit())
          ns2 = parent->getNsContext()->findBinding(prefix);

        if (ns2 == NULL || !ns->byteEqual(*ns2))
          ctx->addBinding(prefix, ns);
      }
    }

    if (!ctx->empty())
    {
      copy->theNsContext = ctx.release();
      copy->theFlags |= XmlNode::HaveLocalBindings;
    }

    if (parent->nsInherit())
    {
      copy->theFlags |= XmlNode::NsInherit;

      const XmlNode* ancestor = parent;

      while (ancestor->isCopy())
        ancestor = ancestor->getParentP();

      copy->setNsContext(ancestor->getNsContext());
    }
  }

  NODE_TRACE1("Copied elem node " << this << " to node " << copy
              << " parent = " << parent << " pos = " << pos);
  NODE_TRACE1("typePreserve = " << parent->typePreserve()
              << " nsPreserve = " << parent->nsPreserve() << std::endl);
  NODE_TRACE1("}");

  return copy;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


AttributeNode::AttributeNode(
    XmlTree*  tree,
    XmlNode*  parent,
    ulong     pos,
    Item*     typeName,
    bool      isId,
    bool      isIdrefs)
  :
  XmlNode(tree, parent, pos, StoreConsts::attributeNode),
  theTypeName(typeName),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
  if (tree == NULL && parent == NULL)
  {
    NODE_TRACE1("Loaded attr node " << this << std::endl);
  }
}


AttributeNode::~AttributeNode()
{
  NODE_TRACE1("Deleted attr node " << this);
}


void AttributeNode::constructValue(Iterator* nameIter, Iterator* valueIter)
{
  // Compute the attribute name. Note: we don't have to check that itemQName 
  // is indeed a valid qname, because the compiler wraps an xs:qname cast
  // around thIteme expression.
  Item_t qnameItem = nameIter->next();

  if (qnameItem->getLocalName().size() == 0)
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0074, false, false,
                      "Attribute name must not have an empty local part.");
  }

  if (qnameItem->getNamespace() == "http://www.w3.org/2000/xmlns/" ||
      (qnameItem->getNamespace() == "" && qnameItem->getLocalName() == "xmlns"))
  {
    ZORBA_ERROR_ALERT(ZorbaError::XQDY0044);
  }

  Item_t typedValue;
  xqpStringStore_t lexicalValue;

  Item_t valueItem = valueIter->next();
  if (valueItem != 0)
  {
    lexicalValue = valueItem->getStringValue().getStore();

    valueItem = valueIter->next();
    while (valueItem != NULL)
    {
      lexicalValue->append(valueItem->getStringValue().c_str());
      valueItem = valueIter->next();
    }

    typedValue = GET_FACTORY().createUntypedAtomic(lexicalValue);
  }
  else
  {
    typedValue = GET_FACTORY().createUntypedAtomic("");
  }

  theName = qnameItem.get_ptr();
  theTypedValue = typedValue;

  NODE_TRACE2("Constructed attr node " << this << ":" << qnameItem->show()
              << " with value " << typedValue->show());
  NODE_TRACE1("}");
}


XmlNode* AttributeNode::copy(XmlNode* parent, unsigned long pos)
{
  Item_t tmp = this;

  AttributeNode* copy;

  if (parent->typePreserve())
  {
    copy = new AttributeNode(NULL, parent, pos,
                             theTypeName.get_ptr(),
                             isId(),
                             isIdrefs());

    copy->theName = theName.get_ptr();
    copy->theTypedValue = theTypedValue.get_ptr();
  }
  else
  {
    bool isId = false;
    bool isIdrefs = false;

    if (theName->getLocalName() == "id" && theName->getPrefix() == "xml")
      isId = true;

    Item_t typedValue;

    if (theTypedValue->getType()->equals(GET_STORE().theUntypedAtomicType))
      typedValue = theTypedValue;
    else
      typedValue = new UntypedAtomicItemImpl(getStringValue().getStore());

    copy = new AttributeNode(NULL, parent, pos,
                             GET_STORE().theUntypedAtomicType.get_ptr(),
                             isId,
                             isIdrefs);

    copy->theName = theName.get_ptr();
    copy->theTypedValue = typedValue.get_ptr();
  }

  NODE_TRACE1("Copied attr node " << this << " to attr node " << copy
              << " parent = " << parent << " pos = " << pos);
  NODE_TRACE1(" typePreserve = " << parent->typePreserve()
              << " nsPreserve = " << parent->nsPreserve() << std::endl);
  NODE_TRACE1("}");

  return copy;
}


Iterator_t AttributeNode::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), theTypedValue);
  return new PlanWrapper(planIter);
}


Item_t AttributeNode::getAtomizationValue() const
{
  return theTypedValue;
}

xqp_string AttributeNode::getStringValue() const
{
  if (theTypedValue != 0)
    return theTypedValue->getStringValue();
  else
    return "";
}


xqp_string AttributeNode::show() const
{
  return theName->getStringValue() + "=\"" +
         (theTypedValue != NULL ? theTypedValue->show() : "") + "\"";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class TextNode                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


TextNode::TextNode(
    XmlTree*        tree,
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* value)
  :
  XmlNode(tree, parent, pos, StoreConsts::textNode),
  theContent(value)
{
  NODE_TRACE2("Constructed text node " << this << " content = " << *value);
  NODE_TRACE1("}");
}


TextNode::TextNode()
{
  NODE_TRACE1("{\nConstructing text node " << this);
}


TextNode::~TextNode()
{
  NODE_TRACE1("Deleted text node " << this);
}


XmlNode* TextNode::copy(XmlNode* parent, unsigned long pos)
{
  XmlNode* lsib = (pos > 0 ? parent->getChild(pos-1) : NULL);

  if (lsib != NULL && lsib->getNodeKind() == StoreConsts::textNode)
  {
    *(lsib->getStringValueP()) = *(lsib->getStringValueP()) + *theContent;
    return lsib;
  }

  Item_t tmp = this;

  TextNode* copy = new TextNode(NULL, parent, pos, theContent.get_ptr());

  NODE_TRACE1("Copied text node " << this << " to node " << copy
              << " parent = " << parent << " pos = " << pos);

  return copy;
}


Item_t TextNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t TextNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createUntypedAtomic(theContent);

  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t TextNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent);
}


xqp_string TextNode::show() const
{
  return theContent.get_ptr();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class PiNode                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

 
PiNode::PiNode(
    XmlTree*        tree,
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* target,
    xqpStringStore* data)
  :
  XmlNode(tree, parent, pos, StoreConsts::piNode),
  theTarget(target),
  theData(data)
{
  if (tree == NULL && parent == NULL)
  {
    NODE_TRACE1("Loaded pi node " << this);
  }
  NODE_TRACE1("}");
}

PiNode::~PiNode()
{
  NODE_TRACE1("Deleted pi node " << this);
}


XmlNode* PiNode::copy(XmlNode* parent, unsigned long  pos)
{
  Item_t tmp = this;

  PiNode* copy = new PiNode(NULL, parent, pos,
                            theTarget.get_ptr(),
                            theData.get_ptr());

  NODE_TRACE1("Copied pi node " << this << " to node " << copy
              << " parent = " << parent << " pos = " << pos);
  NODE_TRACE1("}");

  return copy;
}


Item_t PiNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t PiNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theData.get_ptr());
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t PiNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theData);
}


xqp_string PiNode::show() const
{
  return "<?" + *theTarget + " " + *theData + "?>";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class CommentNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


CommentNode::CommentNode(
    XmlTree*        tree,
    XmlNode*        parent,
    ulong           pos,
    xqpStringStore* content)
  :
  XmlNode(tree, parent, pos, StoreConsts::commentNode),
  theContent(content)
{
  if (tree == NULL && parent == NULL)
  {
    NODE_TRACE1("Loaded comment node " << this);
  }
  NODE_TRACE1("}");
}


CommentNode::~CommentNode()
{
  NODE_TRACE1("Deleted comment node " << this);
}


XmlNode* CommentNode::copy(XmlNode* parent, ulong pos)
{
  Item_t tmp = this;

  CommentNode* copy = new CommentNode(NULL, parent, pos, theContent.get_ptr());

  NODE_TRACE1("Copied comment node " << this << " to comment node " << copy
              << " parent = " << parent << " pos = " << pos);
  NODE_TRACE1("}");

  return copy;
}


Item_t CommentNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t CommentNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theContent.get_ptr());
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t CommentNode::getAtomizationValue() const
{
  return GET_FACTORY().createUntypedAtomic(theContent);
}


xqp_string CommentNode::show() const
{
  return "<!--" + *theContent + "-->";
}


} /* namespace xqp */
