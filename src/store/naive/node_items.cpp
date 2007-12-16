/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "runtime/core/item_iterator.h"
#include "store/naive/node_items.h"
#include "store/naive/simple_store.h"
#include "store/naive/store_defs.h"
#include "store/api/temp_seq.h"
#include "util/zorba.h"
#include <algorithm>

namespace xqp
{

#define GET_CURRENT_LOCATION() \
        zorba::getZorbaForCurrentThread()->GetCurrentLocation()


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class NodeVector                                                           //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


NodeVector::NodeVector(unsigned long size)
{
  theNodes = new Item_t[size+1];
  memset(theNodes, 0, (size+1)*sizeof(Item_t));
  *(unsigned long*)(theNodes) = size;
}


NodeVector::~NodeVector()
{
  clear();
}

void NodeVector::clear()
{
  if (theNodes != 0)
  {
    *((void**)theNodes) = 0;
    delete [] theNodes;
    theNodes = 0;
  }
}


void NodeVector::move(NodeVector* v)
{
  clear();

  if (v != 0)
  {
    theNodes = v->theNodes;
    v->theNodes = 0;
  }
}


unsigned long NodeVector::size() const
{
  if (theNodes == 0)
    return 0;

  return *(unsigned long*)(theNodes);
}


void NodeVector::resize(unsigned long newSize)
{
  if (newSize == 0)
  {
    clear();
    return;
  }

  if (theNodes != 0)
  {
    Item_t* nodes = new Item_t[newSize + 1];
    memset(nodes, 0, (newSize + 1) * sizeof(Item_t));
 
    unsigned long copySize = (newSize > size() ? size() : newSize) + 1;

    for (unsigned long i = 1; i < copySize; i++)
      nodes[i] = theNodes[i];

    *(unsigned long*)(nodes) = newSize;
   
    clear();
    theNodes = nodes;
  }
  else
  {
    theNodes = new Item_t[newSize + 1];
    memset(theNodes, 0, (newSize + 1) * sizeof(Item_t));
    *(unsigned long*)(theNodes) = newSize;
  }
}


void NodeVector::truncate()
{
  if (theNodes == 0)
    return;

  unsigned long i;

  for (i = size(); i > 0 && theNodes[i] == 0; i--) ;

  resize(i);
}


void NodeVector::push_back(const Item_t& item, unsigned long index)
{
  Assert(index <= size());

  if (index == size())
    resize(size() + 100);

  theNodes[index+1] = item;
}



/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class Node                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


NodeImpl::NodeImpl(bool assignId)
  :
  theParent(NULL)
{
  if (assignId)
    theId.init(GET_STORE().getTreeId());
}


xqp_string NodeImpl::getBaseURI() const
{
  return theParent ? theParent->getBaseURI() : "";
}


xqp_string NodeImpl::getDocumentURI() const
{
  return theParent ? theParent->getDocumentURI() : "";
}


bool NodeImpl::equals(Item_t item) const
{
  ZorbaErrorAlerts::error_alert(
        error_messages::XQP0014_SYSTEM_SHOULD_NEVER_BE_REACHED,
        error_messages::SYSTEM_ERROR,
        NULL,
        true,
        "Equal function for node items not implemented!");
  return false;
}


Item_t NodeImpl::getEBV() const
{
  return zorba::getItemFactory()->createBoolean(true);
}


void NodeImpl::initId()
{
  theId.init(GET_STORE().getTreeId());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class DocumentNode                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor used by the xml SAX loader.
********************************************************************************/
DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI)
  :
  NodeImpl(false),
  theBaseURI(baseURI),
  theDocURI(docURI)
{
}


/*******************************************************************************
  Constructor used by the zorba runtime (during node construction).
********************************************************************************/
DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI,
    const Iterator_t&       childrenIte,
    bool                    assignId)
  :
  NodeImpl(assignId),
  theBaseURI(baseURI),
  theDocURI(docURI)
{
  unsigned long numChildren = 0;
  unsigned long capacity = 100;
  theChildren.resize(capacity);

  Item_t item = childrenIte->next();
  while (item != NULL)
  {
    Assert(item->isNode() && item->getNodeKind() != StoreConsts::attributeNode);

    theChildren[numChildren++] = item;
    if (numChildren == capacity)
    {
      capacity *= 2;
      theChildren.resize(capacity);
    }

    item = childrenIte->next();
  }

  if (numChildren < capacity)
    theChildren.resize(numChildren);
}
 

/*******************************************************************************

********************************************************************************/
DocumentNodeImpl::~DocumentNodeImpl()
{
  unsigned long numChildren = theChildren.size();
  unsigned long i;
  for (i = 0; i < numChildren; i++)
  {
    NodeImpl* child = BASE_NODE(theChildren[i]);

    if (!child->getId().isValid())
    {
      child->initId();
    }

    child->theParent = NULL;
  }
}


QNameItem_t DocumentNodeImpl::getType() const
{
  return GET_STORE().theAnyType;
}


Iterator_t DocumentNodeImpl::getChildren() const
{
  return (new ChildrenIterator((NodeImpl*)this, 0));
}


Iterator_t DocumentNodeImpl::getTypedValue() const
{
  Item_t item = zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), item));
  return new PlanWrapper(ret);
}


Item_t DocumentNodeImpl::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
}


xqp_string DocumentNodeImpl::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = getChildren();
  Item_t item = it->next();
  while (item != NULL)
  {
    oss << item->getStringProperty();
    item = it->next();
  }
  return oss.str();
}


xqp_string DocumentNodeImpl::show() const
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
//  class ElementNode                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor used by the xml SAX loader.
********************************************************************************/
ElementNodeImpl::ElementNodeImpl(
    const QNameItem_t&       name,
    const QNameItem_t&       type,
    const NamespaceBindings& nsBindings)
  :
  NodeImpl(false),
  theName(name),
  theType(type)
{
  if (!nsBindings.empty())
    theNsBindings = new NsBindingsContext(nsBindings);
}


/*******************************************************************************
  Constructor used by the zorba runtime (during node construction).
********************************************************************************/
ElementNodeImpl::ElementNodeImpl(
    const QNameItem_t& name,
    const QNameItem_t& type,
    Iterator_t&        childrenIte,
    Iterator_t&        attributesIte,
    Iterator_t&        namespacesIte,
    const NamespaceBindings& nsBindings,
    bool copy,
    bool newTypes,
    bool assignId)
  :
  NodeImpl(assignId),
  theName(name),
  theType(type)
{
  Assert(namespacesIte == NULL);

  unsigned long numAttrs = 0;
  Item_t item;

  if (attributesIte != 0)
  {
    item = attributesIte->next();
    while (item != 0)
    {
      Assert(item->isNode() && item->getNodeKind() == StoreConsts::attributeNode);
      theAttributes.push_back(item, numAttrs++);
      item = attributesIte->next();
    }
  }
  
  if (childrenIte != 0)
  {
    unsigned long numChildren = 0;

    item = childrenIte->next();
    while (item != 0)
    {
      Assert(item->isNode());

      if (item->getNodeKind() == StoreConsts::attributeNode)
      {
        theAttributes.push_back(item, numAttrs++);
      }
      else
      {
        theChildren.push_back(item, numChildren++);
      }

      item = childrenIte->next();
    }

    if (numChildren > 0)
      theChildren.truncate();
  }

  if (numAttrs > 0)
    theAttributes.truncate();

  if (!nsBindings.empty())
  {
    theNsBindings = new NsBindingsContext(nsBindings);
  }
}


/*******************************************************************************

********************************************************************************/
ElementNodeImpl::~ElementNodeImpl()
{
  Assert(getRefCount() == 0);

  unsigned long i;
  unsigned long numNodes = theChildren.size();

  for (i = 0; i < numNodes; i++)
  {
    NodeImpl* child = BASE_NODE(theChildren[i]);

    if (!child->getId().isValid())
    {
      child->initId();
    }

    child->theParent = NULL;
  }

  numNodes = theAttributes.size();

  for (i = 0; i < numNodes; i++)
  {
    NodeImpl* attr = BASE_NODE(theAttributes[i]);

    if (!attr->getId().isValid())
    {
      attr->initId();
    }

    attr->theParent = NULL;
  }
}


/*******************************************************************************

********************************************************************************/
unsigned long ElementNodeImpl::numAttributes() const
{
  return theAttributes.size();
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getAttributes() const
{
  return (new AttributesIterator((ElementNodeImpl*)this));
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getChildren() const
{
  return (new ChildrenIterator((NodeImpl*)this, numAttributes() * 2));
}


/*******************************************************************************

********************************************************************************/
Iterator_t ElementNodeImpl::getTypedValue() const
{
  Item_t item = zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
  PlanIter_t ret(new SingletonIterator(GET_CURRENT_LOCATION(), item));
  return new PlanWrapper(ret);
}


Item_t ElementNodeImpl::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
}


xqp_string ElementNodeImpl::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = getChildren();
  Item_t item = it->next();
  while ( item != NULL )
  {
    oss << item->getStringProperty();
    item = it->next();
  }
  return oss.str();
}


void ElementNodeImpl::setNsBindingsContext(const NsBindingsContext_t& parentCtx)
{
  if (theNsBindings == NULL)
    theNsBindings = parentCtx;
  else
    theNsBindings->setParentContext(parentCtx);
}


NamespaceBindings ElementNodeImpl::getNamespaceBindings() const
{
  NamespaceBindings bindings;

  if (theNsBindings != NULL)
  {
    bindings = theNsBindings->getBindings();

    NsBindingsContext* parentContext = theNsBindings->getParentContext().get_ptr();

    while (parentContext != NULL)
    {
      const NamespaceBindings& parentBindings = parentContext->getBindings();
      unsigned long parentSize = parentBindings.size();
      unsigned long currSize = bindings.size();

      for (unsigned long i = 0; i < parentSize; i++)
      {
        unsigned long j;
        for (j = 0; j < currSize; j++)
        {
          if (bindings[j].first == parentBindings[i].first)
            break;
        }

        if (j == currSize)
          bindings.push_back(parentBindings[i]);
      }

      parentContext = parentContext->getParentContext().get_ptr();
    }
  }

  return bindings;
}


bool ElementNodeImpl::getNilled() const
{
  Iterator_t iter = getChildren();
  Item_t item = iter->next();
  while (item != NULL)
  {
    if (item->isNode() && 
        (item->getNodeKind() == StoreConsts::elementNode ||
         item->getNodeKind() == StoreConsts::textNode))
      return false;

    item = iter->next();
  }
  return true;
}


xqp_string ElementNodeImpl::show() const
{
  std::stringstream str;

  str <<  "<" << theName->getStringProperty();

  str << " nid=\"" << theId.show() << "\"";

  NamespaceBindings nsBindings = getNamespaceBindings();

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

  str << "</" << theName->getStringProperty() << ">";
  return str.str().c_str();
}


/*******************************************************************************
  class AttributeNode
********************************************************************************/

AttributeNodeImpl::AttributeNodeImpl(
    const QNameItem_t& name,
    const QNameItem_t& type,
    const Item_t& lexicalValue,
    const Item_t& typedValue,
    bool isId,
    bool isIdrefs,
    bool assignId)
  :
  NodeImpl(assignId),
  theName(name),
  theType(type),
  theLexicalValue(lexicalValue),
  theTypedValue(typedValue),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
}


AttributeNodeImpl::~AttributeNodeImpl()
{
}


StoreConsts::NodeKind_t AttributeNodeImpl::getNodeKind() const
{
  return StoreConsts::attributeNode;
}


QNameItem_t AttributeNodeImpl::getType() const
{
  return theType;
}


QNameItem_t AttributeNodeImpl::getNodeName() const
{
  return theName;
}


Iterator_t AttributeNodeImpl::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), theTypedValue);
  return new PlanWrapper(planIter);
}


Item_t AttributeNodeImpl::getAtomizationValue() const
{
  return theLexicalValue;
}

xqp_string AttributeNodeImpl::getStringProperty() const
{
  return theLexicalValue->getStringProperty();
}


xqp_string AttributeNodeImpl::getStringValue() const
{
  return theLexicalValue->getStringValue();
}


bool AttributeNodeImpl::isId() const
{
  return theIsId;
}


bool AttributeNodeImpl::isIdrefs() const
{
  return theIsIdrefs;
}


xqp_string AttributeNodeImpl::show() const
{
  return theName->getStringProperty() + "=\"" + (theLexicalValue != NULL ? theLexicalValue->show() : "") + "\"";
}


/*******************************************************************************

********************************************************************************/

  TextNodeImpl::TextNodeImpl(const xqpStringStore_t& content, bool assignId) 
  :
  NodeImpl(assignId),
  theContent(content)
{
}


TextNodeImpl::~TextNodeImpl()
{
}


StoreConsts::NodeKind_t TextNodeImpl::getNodeKind() const
{
  return StoreConsts::textNode;
}


QNameItem_t TextNodeImpl::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}


Iterator_t TextNodeImpl::getTypedValue() const
{
  const Item_t& item = Store::getInstance().getItemFactory().
                              createUntypedAtomic(theContent);

  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t TextNodeImpl::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createUntypedAtomic(theContent);
}


xqp_string TextNodeImpl::getStringProperty() const
{
  return theContent;
}


xqp_string TextNodeImpl::getStringValue() const
{
  return theContent;
}

  
xqp_string TextNodeImpl::show() const
{
  return theContent;
}


/*******************************************************************************

********************************************************************************/
 
PiNodeImpl::PiNodeImpl(
    const xqpStringStore_t& target,
    const xqpStringStore_t& data,
    bool assignId)
  :
  NodeImpl(assignId),
  theTarget(target),
  theData(data)
{
}


PiNodeImpl::~PiNodeImpl()
{
}


StoreConsts::NodeKind_t PiNodeImpl::getNodeKind() const
{
  return StoreConsts::piNode;
}


QNameItem_t PiNodeImpl::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}


Iterator_t PiNodeImpl::getTypedValue() const
{
  const Item_t& item = zorba::getItemFactory()->createString(theData);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t PiNodeImpl::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(theData);
}

xqp_string PiNodeImpl::getStringProperty() const
{
  return theData;
}


xqp_string PiNodeImpl::getStringValue() const
{
  return theData;
}


xqp_string PiNodeImpl::getTarget() const
{
  return theTarget;
}


xqp_string PiNodeImpl::show() const
{
  return "<?" + *theTarget + " " + *theData + "?>";
}


/*******************************************************************************

********************************************************************************/
CommentNodeImpl::CommentNodeImpl(
    const xqpStringStore_t& content,
    bool assignId)
  :
  NodeImpl(assignId),
  theContent(content)
{
}

CommentNodeImpl::~CommentNodeImpl()
{
}


StoreConsts::NodeKind_t CommentNodeImpl::getNodeKind() const
{
  return StoreConsts::commentNode;
}


QNameItem_t CommentNodeImpl::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theUntypedAtomicType;
}


Iterator_t CommentNodeImpl::getTypedValue() const
{
  const Item_t& item = zorba::getItemFactory()->createString(theContent);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanWrapper(planIter);
}


Item_t CommentNodeImpl::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(theContent);
}

xqp_string CommentNodeImpl::getStringProperty() const
{
  return theContent;
}


xqp_string CommentNodeImpl::getStringValue() const
{
  return theContent;
}


xqp_string CommentNodeImpl::show() const
{
  return "<!--" + *theContent + "-->";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class ChildrenIterator                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

ChildrenIterator::ChildrenIterator(
    NodeImpl*     parent,
    unsigned long startId)
  :
  theParentNode(parent),
  theStartingId(startId),
  theCurrentPos(0),
  theChildNodes(parent->getNodeKind() == StoreConsts::documentNode ?
                reinterpret_cast<DocumentNodeImpl*>(parent)->children() :
                reinterpret_cast<ElementNodeImpl*>(parent)->children())
{
}


Item_t ChildrenIterator::next()
{
  if (theCurrentPos >= theChildNodes.size())
    return NULL;

  Item_t item = theChildNodes[theCurrentPos];
  NodeImpl_t childNode = BASE_NODE(item);

  if (childNode->getParentPtr() == NULL)
  {
    childNode->setParent(theParentNode.get_ptr());

    if (childNode->getNodeKind() == StoreConsts::elementNode &&
        theParentNode->getNodeKind() != StoreConsts::documentNode)
    {
      Assert(theParentNode->getNodeKind() == StoreConsts::elementNode);

      ELEM_NODE(item)->setNsBindingsContext(theParentNode->getNsBindingsContext());
    }
  }
  else
  {
    Assert(childNode->getParent().get_ptr() == theParentNode.get_ptr());
  }

  if (theParentNode->getId().isValid() &&
      childNode->getTreeId() != theParentNode->getTreeId())
  {
    childNode->setId(theParentNode->getId());
    childNode->appendIdComponent(theStartingId + theCurrentPos * 2 + 1);
  }

  theCurrentPos++;

  return item;
}


void ChildrenIterator::reset()
{
  theCurrentPos = 0;
}


void ChildrenIterator::close()
{
  theCurrentPos = 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  class AttributesIterator                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

AttributesIterator::AttributesIterator(ElementNodeImpl* parent)
  :
  theParentNode(parent),
  theCurrentPos(0),
  theChildNodes(parent->attributes())
{
}


Item_t AttributesIterator::next()
{
  if (theCurrentPos >= theChildNodes.size())
    return NULL;

  Item_t item = theChildNodes[theCurrentPos];
  NodeImpl_t childNode = BASE_NODE(item);

  if (childNode->getParent() == NULL)
  {
    childNode->setParent(theParentNode.get_ptr());
  }
  else
  {
    Assert(childNode->getParent().get_ptr() == theParentNode.get_ptr());
  }

  if (theParentNode->getId().isValid() &&
      childNode->getTreeId() != theParentNode->getTreeId())
  {
    childNode->setId(theParentNode->getId());
    childNode->appendIdComponent(theCurrentPos * 2 + 1);
  }

  theCurrentPos++;

  return item;
}


void AttributesIterator::reset()
{
  theCurrentPos = 0;
}


void AttributesIterator::close()
{
  theCurrentPos = 0;
}


/*******************************************************************************
  Class NodeDistinctIterator
********************************************************************************/
Item_t StoreNodeDistinctIterator::next()
{
  while (true)
  {
    Item_t contextNode = theInput->next();
    if (contextNode == NULL)
      return NULL;

    Assert(contextNode->isNode());

    if (!theNodeSet.insert(contextNode))
      return contextNode;
  }
}


void StoreNodeDistinctIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeDistinctIterator,
  // which wraps this store iterator.

  theNodeSet.clear();
}


void StoreNodeDistinctIterator::close()
{
  // Do not close the input. This is done by the runtime NodeDistinctIterator,
  // which wraps this store iterator.

  theNodeSet.clear();
}


/*******************************************************************************
  Class NodeSortIterator
********************************************************************************/
Item_t StoreNodeSortIterator::next()
{
  if (theCurrentNode < 0)
  {
    theCurrentNode = 0;

    while (true)
    {
      Item_t contextNode = theInput->next();
      if (contextNode == NULL)
        break;

      Assert(contextNode->isNode());

      theNodes.push_back(BASE_NODE(contextNode));
    }

    ComparisonFunction cmp;

    std::sort(theNodes.begin(), theNodes.end(), cmp);
  }

  if (theCurrentNode < (long)theNodes.size())
  {
    if (theDistinct)
    {
      NodeImpl_t result = theNodes[theCurrentNode++];

      while (theCurrentNode < (long)theNodes.size() &&
             theNodes[theCurrentNode] == result)
      {
        theCurrentNode++;
      }

      return result.get_ptr();
    }
    else
    {
      return theNodes[theCurrentNode++].get_ptr();
    }
  }
  else
  {
    return NULL;
  }
}


void StoreNodeSortIterator::reset()
{
  // Do not reset the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  theNodes.clear();
  theCurrentNode = -1;
}


void StoreNodeSortIterator::close()
{
  // Do not close the input. This is done by the runtime NodeSortIterator,
  // which wraps this store iterator.

  theNodes.clear();
  theCurrentNode = -1;
}


} /* namespace xqp */
