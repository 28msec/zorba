/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "runtime/core/item_iterator.h"
#include "store/naive/node_items.h"
#include "store/naive/simple_store.h"
#include "store/api/temp_seq.h"
#include "util/zorba.h"

namespace xqp
{

#define GET_CURRENT_LOCATION() \
        zorba::getZorbaForCurrentThread()->GetCurrentLocation()


/*******************************************************************************
  class DocumentNode
********************************************************************************/

DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI)
  :
  theBaseURI(baseURI),
  theDocURI(docURI)
{
}


DocumentNodeImpl::DocumentNodeImpl(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI,
    const TempSeq_t& children)
  :
  theBaseURI(baseURI),
  theDocURI(docURI),
  theChildren(children)
{
}
 

DocumentNodeImpl::~DocumentNodeImpl()
{
}


StoreConsts::NodeKind_t DocumentNodeImpl::getNodeKind() const
{
  return StoreConsts::documentNode;
}


QNameItem_t DocumentNodeImpl::getType() const
{
  return static_cast<SimpleStore*>(&Store::getInstance())->theAnyType;
}


xqp_string DocumentNodeImpl::getBaseURI() const
{
  return theBaseURI;
}


xqp_string DocumentNodeImpl::getDocumentURI() const
{
  return theDocURI;
}


Iterator_t DocumentNodeImpl::getChildren() const
{
  if (theChildren == NULL)
  {
    PlanIter_t planIter = new EmptyIterator(GET_CURRENT_LOCATION());
    return new PlanIterWrapper(planIter);
  }
  else
  {
    return (new ChildrenIterator(theChildren->getIterator(),(NodeImpl*)this));
  }
}


void DocumentNodeImpl::setChildren(const TempSeq_t& seq)
{
  theChildren = seq;
}


Iterator_t DocumentNodeImpl::getTypedValue() const
{
  PlanIter_t ret;
  if (theChildren->empty())
  {
    ret = new EmptyIterator(GET_CURRENT_LOCATION());
  }
  else
  {
    Item_t item = zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
    ret = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  }
  return new PlanIterWrapper(ret);
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
            << *theDocURI << "\"/>" << std::endl;

  if (theChildren != NULL)
  {
    Iterator_t iter = theChildren->getIterator();
    Item_t item = iter->next();
    while (item != NULL)
    {
      strStream << item->show();
      item = iter->next();
    }
  }

  return strStream.str().c_str();
}


/*******************************************************************************
  class ElementNode
********************************************************************************/

ElementNodeImpl::ElementNodeImpl(
    const QNameItem_t& name,
    const QNameItem_t& type,
    TempSeq_t& seqAttributes,
    const NamespaceBindings& nsBindings)
  :
  NodeImpl(NULL),
  theName(name),
  theType(type),
  theAttributes(seqAttributes)
{
  if (!nsBindings.empty())
    theNsBindings = new NsBindingsContext(nsBindings);
}


ElementNodeImpl::ElementNodeImpl(
    const QNameItem_t& name,
    const QNameItem_t& type,
    TempSeq_t& seqChildren,
    TempSeq_t& seqAttributes,
    TempSeq_t& seqNsUris,
    const NamespaceBindings& nsBindings,
    bool copy,
    bool newTypes)
  :
  theName(name),
  theType(type),
  theChildren(seqChildren),
  theAttributes(seqAttributes),
  theNsUris(seqNsUris)
{
  if (!nsBindings.empty())
  {
    theNsBindings = new NsBindingsContext(nsBindings);
  }
}


ElementNodeImpl::~ElementNodeImpl()
{
}


StoreConsts::NodeKind_t ElementNodeImpl::getNodeKind() const
{
  return StoreConsts::elementNode;
}


QNameItem_t ElementNodeImpl::getType() const
{
  return theType;
}


QNameItem_t ElementNodeImpl::getNodeName() const
{
  return theName;
}


Iterator_t ElementNodeImpl::getAttributes() const
{
  if ( theAttributes == NULL )
  {
    PlanIter_t planIter = new EmptyIterator(GET_CURRENT_LOCATION());
    return new PlanIterWrapper(planIter);
  }
  else
  {
    return theAttributes->getIterator();
  }
}


Iterator_t ElementNodeImpl::getChildren() const
{
  if (theChildren == NULL)
  {
    PlanIter_t planIter = new EmptyIterator(GET_CURRENT_LOCATION());
    return new PlanIterWrapper(planIter);
  }
  else
  {
    return (new ChildrenIterator(theChildren->getIterator(), (NodeImpl*)this));
  }
}


void ElementNodeImpl::setChildren(const TempSeq_t& seq)
{
  theChildren = seq;
}


Iterator_t ElementNodeImpl::getTypedValue() const
{
  PlanIter_t ret;
  if (theChildren->empty())
  {
    ret = new EmptyIterator(GET_CURRENT_LOCATION());
  }
  else
  {
    Item_t item = zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
    ret = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  }
  return new PlanIterWrapper(ret);
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
  Iterator_t iter = theChildren->getIterator();
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

//   str << " nid = \"" << theId.show() << "\"";

  NamespaceBindings nsBindings = getNamespaceBindings();

  for (unsigned long i = 0; i < nsBindings.size(); i++)
  {
    str << " xmlns:" <<  nsBindings[i].first << "=\""
        << nsBindings[i].second << "\"";
  }

  if (theAttributes != NULL)
  {
    Iterator_t iter = theAttributes->getIterator();
    Item_t item = iter->next();
    bool lFirst = true;
    while (item != NULL)
    {
      if (!lFirst)
        str << " ";
      str << item->show();
      item = iter->next();
    }
  }

  str << ">";

  if (theChildren != NULL)
  {
    Iterator_t iter = theChildren->getIterator();
    Item_t item = iter->next();
    while (item != NULL)
    {
      str << item->show();
      item = iter->next();
    }
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
    bool isIdrefs)
  :
  theName(name),
  theType(type),
  theLexicalValue(lexicalValue),
  theTypedValue(typedValue),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
}


AttributeNodeImpl::AttributeNodeImpl(
    const Item_t& parent,
    const QNameItem_t& name,
    const QNameItem_t& type,
    const Item_t& lexicalValue,
    const Item_t& typedValue,
    bool isId,
    bool isIdrefs)
  :
  NodeImpl(parent),
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
  return new PlanIterWrapper(planIter);
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

TextNodeImpl::TextNodeImpl(const xqpStringStore_t& content) 
  :
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
  return new PlanIterWrapper(planIter);
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
    const xqpStringStore_t& data)
  :
  theTarget(target), theData(data)
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
  return new PlanIterWrapper(planIter);
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
CommentNodeImpl::CommentNodeImpl(const xqpStringStore_t& content)
  :
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
  return new PlanIterWrapper(planIter);
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


/*******************************************************************************
  Class ChildrenIterator
********************************************************************************/
Item_t ChildrenIterator::next()
{
  Item_t item = theInput->next();
  if (item == NULL)
    return NULL;

  if (!item->isNode())
    return item;

  Assert(item->getNodeKind() != StoreConsts::documentNode);

  if (item->getParent() == NULL)
  {
    static_cast<NodeImpl*>(item.get_ptr())->setParent(theParentNode.get_ptr());

    if (item->getNodeKind() == StoreConsts::elementNode &&
        theParentNode->getNodeKind() != StoreConsts::documentNode)
    {
      Assert(theParentNode->getNodeKind() == StoreConsts::elementNode);

      ElementNodeImpl* child = static_cast<ElementNodeImpl*>(item.get_ptr());

      child->setNsBindingsContext(theParentNode->getNsBindingsContext());
    }
  }
  else
  {
    Assert(item->getParent().get_ptr() == theParentNode.get_ptr());
  }

  return item;
}


void ChildrenIterator::reset()
{
  theInput->reset();
}


} /* namespace xqp */
