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

int traceLevel = 1;

#define NODE_TRACE(level, msg)               \
{                                            \
  if (level <= traceLevel)                   \
    std::cout << msg << std::endl;           \
}

#define NODE_TRACE1(msg) NODE_TRACE(1, msg);

#else

#define NODE_TRACE(msg)
#define NODE_TRACE1(msg)

#endif


namespace xqp
{

#define GET_CURRENT_LOCATION() \
        ZORBA_FOR_CURRENT_THREAD()->GetCurrentLocation()


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
//  class XmlNodeVector                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


XmlNodeVector::XmlNodeVector(unsigned long size)
{
  theNodes = new XmlNode*[size+1];
  memset(theNodes, 0, (size+1) * sizeof(XmlNode*));
  *(unsigned long*)(theNodes) = size;
}


unsigned long XmlNodeVector::size() const
{
  if (theNodes == 0)
    return 0;

  return *(unsigned long*)(theNodes);
}


void XmlNodeVector::truncate()
{
  if (theNodes == 0)
    return;

  unsigned long i;
  for (i = size(); i > 0 && theNodes[i] == 0; i--) ;

  resize(i);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class LoadedXmlNodeVector                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


void LoadedXmlNodeVector::push_back(unsigned long pos, XmlNode* node, bool shared)
{
  Assert(pos <= size());

  if (pos == size())
    resize(size() + 100);

  theNodes[pos+1] = node;
}


void LoadedXmlNodeVector::clear()
{
  if (theNodes != 0)
  {
    delete [] theNodes;
    theNodes = 0;
  }
}


void LoadedXmlNodeVector::resize(unsigned long newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  if (newSize == size())
    return;

  if (theNodes != 0)
  {
    XmlNode** nodes = new XmlNode*[newSize + 1];
    memset(nodes, 0, (newSize + 1) * sizeof(XmlNode*));
 
    unsigned long copySize = (newSize > size() ? size() : newSize) + 1;

    for (unsigned long i = 1; i < copySize; i++)
      nodes[i] = theNodes[i];

    *(unsigned long*)(nodes) = newSize;
   
    clear();
    theNodes = nodes;
  }
  else
  {
    theNodes = new XmlNode*[newSize + 1];
    memset(theNodes, 0, (newSize + 1) * sizeof(XmlNode*));
    *(unsigned long*)(theNodes) = newSize;
  }
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrXmlNodeVector                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ConstrXmlNodeVector::ConstrXmlNodeVector(unsigned long size) : XmlNodeVector(size)
{
  theBitmap.resize(size);
}


void ConstrXmlNodeVector::set(unsigned long pos, XmlNode* node, bool shared)
{
  ZORBA_ASSERT(pos < size());
  
  if (shared)
  {
    if (!theBitmap[pos+1])
      theNodes[pos+1] = NULL;

    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos+1])) = node;
    theBitmap[pos+1] = true;
  }
  else
  {
    if (theBitmap[pos+1])
      *(reinterpret_cast<XmlNode_t*>(&theNodes[pos+1])) = NULL;

    theNodes[pos+1] = node;
    theBitmap[pos+1] = false;
  }
}


void ConstrXmlNodeVector::push_back(unsigned long pos, XmlNode* node, bool shared)
{
  ZORBA_ASSERT(pos <= size());

  if (pos == size())
    resize(size() + 100);

  ZORBA_ASSERT(theNodes[pos+1] == NULL);

  if (shared)
  {
    *(reinterpret_cast<XmlNode_t*>(&theNodes[pos+1])) = node;
    theBitmap[pos+1] = true;
  }
  else
  {
    theNodes[pos+1] = node;
    theBitmap[pos+1] = false;
  }
}


void ConstrXmlNodeVector::clear()
{
  if (theNodes != 0)
  {
    unsigned long size = this->size();
    for (unsigned long i = 1; i <= size; i++)
    {
      if (theBitmap[i])
        *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = NULL; 
    }

    delete [] theNodes;
    theNodes = 0;
  }
}


void ConstrXmlNodeVector::resize(unsigned long newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  if (newSize == size())
    return;

  if (theNodes != 0)
  {
    XmlNode** nodes = new XmlNode*[newSize + 1];
    memset(nodes, 0, (newSize + 1) * sizeof(XmlNode*));

    unsigned long copySize = (newSize > size() ? size() : newSize) + 1;

    for (unsigned long i = 1; i < copySize; i++)
    {
      if (theBitmap[i])
        *(reinterpret_cast<XmlNode_t*>(&theNodes[i])) = theNodes[i];
      else
        nodes[i] = theNodes[i];
    }

    *(unsigned long*)(nodes) = newSize;
   
    clear();
    theBitmap.resize(newSize + 1);
    theNodes = nodes;
  }
  else
  {
    theNodes = new XmlNode*[newSize + 1];
    memset(theNodes, 0, (newSize + 1) * sizeof(XmlNode*));
    *(unsigned long*)(theNodes) = newSize;

    theBitmap.resize(newSize+1);
  }
}


void ConstrXmlNodeVector::copy(const XmlNodeVector& src)
{
  clear();

  unsigned long size = src.size();

  if (size == 0)
    return;

  resize(size);

  for (unsigned long i = 1; i <= size; i++)
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


XmlNode::XmlNode(bool isRoot)
  :
  theTree(NULL),
  theParent(NULL)
{
  if (isRoot)
    theOrdPath.init();
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
  if (theTree != NULL)
  {
    theTree->addReference();
  }
}


void XmlNode::removeReference()
{
  if (theTree != NULL)
  {
    theTree->removeReference();
  }
}


void XmlNode::createId(unsigned long tid, const OrdPathStack& op)
{
  ZORBA_ASSERT(theTree == NULL);

  theTree = new XmlTree(this, tid);
  theOrdPath = op;
}


void XmlNode::setId(XmlTree* tree, const OrdPathStack& op)
{
  ZORBA_ASSERT(theTree == NULL);

  theTree = tree;
  theOrdPath = op;
}


void XmlNode::constructTree(XmlTree* tree, unsigned long childPos)
{
  if (theTree == NULL)
  {
    theTree = tree;

    if (theParent != NULL)
    {
      theOrdPath = theParent->theOrdPath;
      theOrdPath.appendComp(2 * childPos + 1);
    }

    if (getNodeKind() == StoreConsts::elementNode ||
        getNodeKind() == StoreConsts::documentNode)
    {
      if (theParent != NULL && (!isCopy() || nsInherit()))
        setNsContext(theParent->getNsContext());

      if (isCopy())
        return;

      unsigned long numAttrs = this->numAttributes();
      unsigned long numChildren = this->numChildren();

      for (unsigned long i = 0; i < numAttrs; i++)
        getAttr(i)->constructTree(tree, i);

      for (unsigned long i = 0; i < numChildren; i++)
        getChild(i)->constructTree(tree, numAttrs + i);
    }
  }
  else
  {
    ZORBA_ASSERT(theTree != tree);
  }
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


/*******************************************************************************

********************************************************************************/
DocumentNode::DocumentNode(
    xqpStringStore* baseURI,
    xqpStringStore* docURI,
    bool            isRoot)
  :
  XmlNode(isRoot),
  theBaseURI(baseURI),
  theDocURI(docURI),
  theFlags(0)
{
}


/*******************************************************************************

********************************************************************************/
DocumentNode::~DocumentNode()
{
  ZORBA_ASSERT(theRefCount == 0);
}


/*******************************************************************************

********************************************************************************/
Item_t DocumentNode::getType() const
{
  return GET_STORE().theAnyType;
}


/*******************************************************************************

********************************************************************************/
Iterator_t DocumentNode::getChildren() const
{
  return (new ChildrenIterator((XmlNode*)this));
}


/*******************************************************************************

********************************************************************************/
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

  unsigned long numChildren = this->numChildren();
  for (unsigned long i = 0; i < numChildren; i++)
  {
    oss << getChild(i)->getStringValue();
  }

  return oss.str();
}


/*******************************************************************************

********************************************************************************/
xqp_string DocumentNode::show() const
{
  std::stringstream strStream;

  strStream << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << std::endl
            << "<document baseUri = \"" << *theBaseURI << "\" docUri = \""
            << *theDocURI << "\">" << std::endl;

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

********************************************************************************/
LoadedDocumentNode::LoadedDocumentNode(
    xqpStringStore* baseUri,
    xqpStringStore* docUri)
  :
  DocumentNode(baseUri, docUri, false)
{
  NODE_TRACE1("Loaded doc node " << this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrDocumentNode                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrDocumentNode::ConstrDocumentNode(
    xqpStringStore* baseUri,
    xqpStringStore* docUri,
    Iterator*       childrenIte,
    bool            isRoot,
    bool            copy,
    bool            typePreserve,
    bool            nsPreserve,
    bool            nsInherit)
  :
  DocumentNode(baseUri, docUri, isRoot)
{
  theFlags |= XmlNode::IsConstructed;

  if (typePreserve)
    theFlags |= XmlNode::TypePreserve;

  if (nsPreserve)
    theFlags |= XmlNode::NsPreserve;

  if (nsInherit)
    theFlags |= XmlNode::NsInherit;

  unsigned long numChildren = 0;
  Item_t item;

  if (childrenIte != 0)
  {
    item = childrenIte->next();
    while (item != NULL)
    {
      ZORBA_ASSERT(item->isNode() &&
                   item->getNodeKind() != StoreConsts::attributeNode);

      addChild(BASE_NODE(item), numChildren++, isRoot, copy);

      item = childrenIte->next();
    }
  }

  if (numChildren > 0)
    theChildren.truncate();

  NODE_TRACE1("Constructed doc node " << this << " nid = " << theOrdPath.show());
}
 

/*******************************************************************************

********************************************************************************/
void ConstrDocumentNode::addChild(
    XmlNode*      childNode,
    unsigned long pos,
    bool          isRoot,
    bool          copy)
{
  if (childNode->getTree() != NULL)
  {
    ZORBA_ASSERT(childNode->getTree() != this->getTree());
    ZORBA_ASSERT(childNode->getParentPtr() != this);

    if (copy)
      childNode = childNode->copy(this, pos);

    theChildren.push_back(pos, childNode, !copy);
  }
  else
  {
    theChildren.push_back(pos, childNode, false);
    childNode->setParent(this);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ElementNode::ElementNode(const Item* nodeName, bool  isRoot)
  :
  XmlNode(isRoot),
  theName(const_cast<Item*>(nodeName)),
  theFlags(0)
{
}


/*******************************************************************************

********************************************************************************/
ElementNode::~ElementNode()
{
  ZORBA_ASSERT(getRefCount() == 0);

  NODE_TRACE1("Deleted elem node " << this << ", nscontext "
              << theNsContext.get_ptr() << ", "
              << (theNsContext != NULL ? theNsContext->getRefCount() : -1));
}


/*******************************************************************************

********************************************************************************/
XmlNode* ElementNode::copy(const XmlNode* parent, unsigned long pos) const
{
  std::auto_ptr<ElementNode> copy(new ConstrElementNode(theName.get_ptr(), false));

  copy->theParent = const_cast<XmlNode*>(parent);

  if (parent->hasId())
  {
    copy->theTree = parent->getTree();
    copy->theOrdPath = parent->getOrdPath();
    copy->theOrdPath.appendComp(2 * (pos + parent->numAttributes()) + 1);
  }

  if (parent->typePreserve())
  {
    copy->theFlags |= XmlNode::TypePreserve;
    copy->theTypeName = theTypeName;
  }
  else
  {
    copy->theTypeName = GET_STORE().theUntypedType;
  }

  copy->attributes().copy(attributes());
  copy->children().copy(children());

  if (parent->nsPreserve())
  {
    copy->theFlags |= XmlNode::NsPreserve;

    if (!parent->isCopy())
    {
      auto_ptr<NsBindingsContext> ctx(new NsBindingsContext());
      getNamespaceBindings(ctx->getBindings());

      if (!ctx->getBindings().empty())
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
      copy->theFlags |= XmlNode::NsInherit;
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

      if (parent->getNodeKind() == StoreConsts::elementNode)
        ns2 = parent->getNsContext()->findBinding(prefix);

      if (ns2 == NULL || !ns->byteEqual(*ns2))
        ctx->addBinding(prefix, ns);
    }

    unsigned long numAttrs = numAttributes();

    for (unsigned long i = 0; i < numAttrs; i++)
    {
      prefix = getAttr(i)->getNodeName()->getPrefix().getStore();
      ns = getNsContext()->findBinding(prefix);

      ZORBA_ASSERT(*prefix == "" || ns != NULL);

      if (ns != NULL)
      {
        xqpStringStore* ns2 = NULL;

        if (parent->getNodeKind() == StoreConsts::elementNode)
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
        ancestor = ancestor->getParentPtr();

      copy->setNsContext(ancestor->getNsContext());
    }
  }

  NODE_TRACE1("Copied elem node " << this << " to elem node " << copy.get()
              << " parent = " << parent
              << " typePreserve = " << parent->typePreserve()
              << " nsPreserve = " << parent->nsPreserve());

  return copy.release();
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
  ostringstream oss;

  unsigned long numChildren = this->numChildren();
  for (unsigned long i = 0; i < numChildren; i++)
  {
    if (getChild(i)->getNodeKind() != StoreConsts::commentNode)
    {
      Item_t lAtomicItem = getChild(i)->getAtomizationValue(); 
      oss << lAtomicItem->getStringValue();
    }
  }

  return GET_FACTORY().createUntypedAtomic(oss.str());
}


/*******************************************************************************

********************************************************************************/
xqp_string ElementNode::getStringValue() const
{
  ostringstream oss;

  unsigned long numChildren = this->numChildren();
  for (unsigned long i = 0; i < numChildren; i++)
  {
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

  for (unsigned long i = 0; i < nsBindings.size(); i++)
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


/*******************************************************************************
  Constructor used by the xml SAX loader.
********************************************************************************/
LoadedElementNode::LoadedElementNode(
    const Item*   nodeName,
    const Item*   typeName,
    unsigned long numBindings,
    unsigned long numAttributes)
  :
  ElementNode(nodeName, false)
{
  theTypeName = const_cast<Item*>(typeName);

  if (numBindings > 0)
  {
    theNsContext = new NsBindingsContext(numBindings);
    theFlags |= XmlNode::HaveLocalBindings;
  }

  if (numAttributes > 0)
    theAttributes.resize(numAttributes);

  NODE_TRACE1("Loaded elem node " << this << " name = " << theName->show()
              <<" num bindings = " << numBindings);
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ConstrElementNode                                                    //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(Item* nodeName, bool isRoot)
  :
  ElementNode(nodeName, isRoot)
{
  theFlags |= (XmlNode::IsConstructed | XmlNode::IsCopy);
}


/*******************************************************************************

********************************************************************************/
ConstrElementNode::ConstrElementNode(
    Item*             nodeName,
    Item*             typeName,
    Iterator*         childrenIte,
    Iterator*         attributesIte,
    Iterator*         namespacesIte,
    const NsBindings& nsBindings,
    bool              isRoot,
    bool              copy,
    bool              typePreserve,
    bool              nsPreserve,
    bool              nsInherit)
  :
  ElementNode(nodeName, isRoot)
{
  Assert(namespacesIte == NULL);

  unsigned long numAttrs = 0;
  unsigned long numChildren = 0;
  Item_t item;

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

  if (attributesIte != 0)
  {
    item = attributesIte->next();
    while (item != 0)
    {
      ZORBA_ASSERT(item->isNode());
      ZORBA_ASSERT(item->getNodeKind() == StoreConsts::attributeNode);

      addAttribute(ATTR_NODE(item), numAttrs++, copy, typePreserve);

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

      if (item->getNodeKind() == StoreConsts::attributeNode)
        addAttribute(ATTR_NODE(item), numAttrs++, isRoot, copy);
      else
        addChild(BASE_NODE(item), numChildren++, isRoot, copy);

      item = childrenIte->next();
    }
  }

  if (numChildren > 0)
    theChildren.truncate();

  if (numAttrs > 0)
    theAttributes.truncate();

  NODE_TRACE1("Constructed elem node " << this << " nid = " << theOrdPath.show()
              << " nsInherit = " << nsInherit);
}


/*******************************************************************************

********************************************************************************/
void ConstrElementNode::addChild(
    XmlNode*      childNode,
    unsigned long pos,
    bool          isRoot,
    bool          copy)
{
  if (childNode->getTree() != NULL)
  {
    ZORBA_ASSERT(childNode->getTree() != this->getTree());
    ZORBA_ASSERT(childNode->getParentPtr() != this);

    if (copy)
      childNode = childNode->copy(this, pos);

    theChildren.push_back(pos, childNode, !copy);
  }
  else
  {
    theChildren.push_back(pos, childNode, false);
    childNode->setParent(this);
  }
}


/*******************************************************************************

********************************************************************************/
void ConstrElementNode::addAttribute(
    XmlNode* attrNode,
    unsigned long pos,
    bool isRoot,
    bool copy)
{
  if (attrNode->getTree() != NULL)
  {
    ZORBA_ASSERT(attrNode->getTree() != this->getTree());
    ZORBA_ASSERT(attrNode->getParentPtr() != this);

    if (copy)
      attrNode = attrNode->copy(this, pos);

    theAttributes.push_back(pos, attrNode, !copy);
  }
  else
  {
    theAttributes.push_back(pos, attrNode, false);
    attrNode->setParent(this);
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributeNode                                                        //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(
    const Item*  name,
    const Item*  type,
    const Item*  typedValue,
    bool         isId,
    bool         isIdrefs,
    bool         isRoot)
  :
  XmlNode(isRoot),
  theName(const_cast<Item*>(name)),
  theTypeName(const_cast<Item*>(type)),
  theTypedValue(const_cast<Item*>(typedValue)),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
}


/*******************************************************************************

********************************************************************************/
AttributeNode::AttributeNode(const Item* name, bool isRoot)
  :
  XmlNode(isRoot),
  theName(const_cast<Item*>(name))
{
}


/*******************************************************************************

********************************************************************************/
XmlNode* AttributeNode::copy(const XmlNode* parent, unsigned long pos) const
{
  std::auto_ptr<AttributeNode> copy(new AttributeNode(theName, false));

  copy->theParent = const_cast<XmlNode*>(parent);

  if (parent->hasId())
  {
    copy->theTree = parent->getTree();
    copy->theOrdPath = parent->getOrdPath();
    copy->theOrdPath.appendComp(2 * pos + 1);
  }

  if (parent->typePreserve())
  {
    copy->theTypeName = theTypeName;
    copy->theTypedValue = theTypedValue;
    copy->theIsId = isId();
    copy->theIsIdrefs = isIdrefs();
  }
  else
  {
    copy->theTypeName = GET_STORE().theUntypedAtomicType;

    if (theTypedValue == NULL || theTypedValue->getType() == GET_STORE().theUntypedAtomicType)
      copy->theTypedValue = theTypedValue;
    else
      copy->theTypedValue = new UntypedAtomicItemImpl(getStringValue().getStore());

    if (theName->getLocalName() == "id" && theName->getPrefix() == "xml")
      copy->theIsId = true;
    else
      copy->theIsId = false;

    copy->theIsIdrefs = false;
  }

  return copy.release();
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


TextNode::TextNode(const xqpStringStore* content, bool isRoot) 
  :
  XmlNode(isRoot),
  theContent(const_cast<xqpStringStore*>(content))
{
}


XmlNode* TextNode::copy(const XmlNode* parent, unsigned long pos) const
{
  std::auto_ptr<TextNode> copy(new TextNode(theContent, false));

  copy->theParent = const_cast<XmlNode*>(parent);

  if (parent->hasId())
  {
    copy->theTree = parent->getTree();
    copy->theOrdPath = parent->getOrdPath();
    copy->theOrdPath.appendComp(2 * (pos + parent->numAttributes()) + 1);
  }

  return copy.release();
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
    const xqpStringStore* target,
    const xqpStringStore* data,
    bool                  isRoot)
  :
  XmlNode(isRoot),
  theTarget(const_cast<xqpStringStore*>(target)),
  theData(const_cast<xqpStringStore*>(data))
{
}


XmlNode* PiNode::copy(const XmlNode* parent, unsigned long  pos) const
{
  std::auto_ptr<PiNode> copy(new PiNode(theTarget, theData, false));

  copy->theParent = const_cast<XmlNode*>(parent);

  if (parent->hasId())
  {
    copy->theTree = parent->getTree();
    copy->theOrdPath = parent->getOrdPath();
    copy->theOrdPath.appendComp(2 * (pos + parent->numAttributes()) + 1);
  }

  return copy.release();
}


Item_t PiNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t PiNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theData);
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
    const xqpStringStore* content,
    bool                  isRoot)
  :
  XmlNode(isRoot),
  theContent(const_cast<xqpStringStore*>(content))
{
}


XmlNode* CommentNode::copy(const XmlNode* parent, unsigned long pos) const
{
  std::auto_ptr<CommentNode> copy(new CommentNode(theContent, false));

  copy->theParent = const_cast<XmlNode*>(parent);

  if (parent->hasId())
  {
    copy->theTree = parent->getTree();
    copy->theOrdPath = parent->getOrdPath();
    copy->theOrdPath.appendComp(2 * (pos + parent->numAttributes()) + 1);
  }

  return copy.release();
}


Item_t CommentNode::getType() const
{
  return GET_STORE().theUntypedAtomicType;
}


Iterator_t CommentNode::getTypedValue() const
{
  const Item_t& item = GET_FACTORY().createString(theContent);
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
