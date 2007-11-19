/*
 *  Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "runtime/core/item_iterator.h"
#include "store/naive/node_items.h"
#include "store/api/temp_seq.h"
#include "util/zorba.h"

namespace xqp
{

#define GET_CURRENT_LOCATION() \
        zorba::getZorbaForCurrentThread()->GetCurrentLocation()


/*******************************************************************************
  class DocumentNode
********************************************************************************/

DocumentNodeNaive::DocumentNodeNaive(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI)
  :
  theBaseURI(baseURI),
  theDocURI(docURI)
{
}


DocumentNodeNaive::DocumentNodeNaive(
    const xqpStringStore_t& baseURI,
    const xqpStringStore_t& docURI,
    const TempSeq_t& children)
  :
  theBaseURI(baseURI),
  theDocURI(docURI),
  theChildren(children)
{
}
 

DocumentNodeNaive::~DocumentNodeNaive()
{
}


Item_t DocumentNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
}


xqp_string DocumentNodeNaive::getStringProperty() const
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


StoreConsts::NodeKind_t DocumentNodeNaive::getNodeKind() const
{
  return StoreConsts::documentNode;
}


xqp_string DocumentNodeNaive::getBaseURI() const
{
  return theBaseURI;
}


Iterator_t DocumentNodeNaive::getChildren() const
{
  if (theChildren == NULL)
  {
    PlanIter_t planIter = new EmptyIterator(GET_CURRENT_LOCATION());
    return new PlanIterWrapper(planIter);
  }
  else
  {
    return (new ChildrenIterator(theChildren->getIterator(),(NodeNaive*)this));
  }
}


void DocumentNodeNaive::setChildren(const TempSeq_t& seq)
{
  theChildren = seq;
}


xqp_string DocumentNodeNaive::getDocumentURI() const
{
  return theDocURI;
}


Iterator_t DocumentNodeNaive::getTypedValue() const
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


xqp_string DocumentNodeNaive::show() const
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

ElementNodeNaive::ElementNodeNaive(
    const QNameItem_t& name,
    const QNameItem_t& type,
    TempSeq_t& seqAttributes,
    const NamespaceBindings& nsBindings)
  :
  NodeNaive(NULL),
  theName(name),
  theType(type),
  theAttributes(seqAttributes)
{
  if (!nsBindings.empty())
    theNsBindings = new NsBindingsContext(nsBindings);
}


ElementNodeNaive::ElementNodeNaive(
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


ElementNodeNaive::~ElementNodeNaive()
{
}


void ElementNodeNaive::setParent(const Item_t& p)
{
  theParent = p.get_ptr();

  if (theNsBindings == NULL)
    theNsBindings = new NsBindingsContext();

  if (p->getNodeKind() == StoreConsts::elementNode)
  {
    ElementNodeNaive* parentNode = reinterpret_cast<ElementNodeNaive*>(p.get_ptr());

    theNsBindings->setParentContext(parentNode->getNsBindingsContext());
  }
}


Item_t ElementNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(getStringProperty());
}


xqp_string ElementNodeNaive::getStringProperty() const
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


StoreConsts::NodeKind_t ElementNodeNaive::getNodeKind() const
{
  return StoreConsts::elementNode;
}


Iterator_t ElementNodeNaive::getAttributes() const
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


Iterator_t ElementNodeNaive::getChildren() const
{
  if (theChildren == NULL)
  {
    PlanIter_t planIter = new EmptyIterator(GET_CURRENT_LOCATION());
    return new PlanIterWrapper(planIter);
  }
  else
  {
    return (new ChildrenIterator(theChildren->getIterator(), (NodeNaive*)this));
  }
}


void ElementNodeNaive::setChildren(const TempSeq_t& seq)
{
  theChildren = seq;
}


NamespaceBindings ElementNodeNaive::getNamespaceBindings() const
{
  NamespaceBindings bindings;

  if (theNsBindings != NULL)
  {
    bindings = theNsBindings->getBindings();

    NsBindingsContext* parentContext = theNsBindings->getParentContext().get_ptr();

    while (parentContext != NULL)
    {
      const NamespaceBindings& parentBindings = parentContext->getBindings();
      ulong parentSize = parentBindings.size();
      ulong currSize = bindings.size();

      for (ulong i = 0; i < parentSize; i++)
      {
        for (ulong j = 0; j < currSize; j++)
        {
          if (bindings[j].first != parentBindings[i].first)
            bindings.push_back(parentBindings[i]);
        }
      }

      parentContext = theNsBindings->getParentContext().get_ptr();
    }
  }

  return bindings;
}


bool ElementNodeNaive::getNilled() const
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


QNameItem_t ElementNodeNaive::getNodeName() const
{
  return theName;
}


Iterator_t ElementNodeNaive::getTypedValue() const
{
  PlanIter_t ret;
  if ( theChildren->empty() )
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


xqp_string ElementNodeNaive::show() const
{
  xqp_string str;

  str =  "<" + theName->getStringProperty();

  if ( theAttributes != NULL )
  {
    Iterator_t iter = theAttributes->getIterator();
    Item_t item = iter->next();
    while (item != NULL)
    {
      str += " " + item->show();
      item = iter->next();
    }
  }
  str += ">";
  if (theChildren != NULL)
  {
    Iterator_t iter = theChildren->getIterator();
    Item_t item = iter->next();
    while (item != NULL)
    {
      str += item->show();
      item = iter->next();
    }
  }
  str += "</" + theName->getStringProperty() + ">";
  return str;
}


/*******************************************************************************
  class AttributeNode
********************************************************************************/

AttributeNodeNaive::AttributeNodeNaive(
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


AttributeNodeNaive::AttributeNodeNaive(
    const Item_t& parent,
    const QNameItem_t& name,
    const QNameItem_t& type,
    const Item_t& lexicalValue,
    const Item_t& typedValue,
    bool isId,
    bool isIdrefs)
  :
  NodeNaive(parent),
  theName(name),
  theType(type),
  theLexicalValue(lexicalValue),
  theTypedValue(typedValue),
  theIsId(isId),
  theIsIdrefs(isIdrefs)
{
}


AttributeNodeNaive::~AttributeNodeNaive()
{
}


Item_t AttributeNodeNaive::getAtomizationValue() const
{
  return theLexicalValue;
}

xqp_string AttributeNodeNaive::getStringProperty() const
{
  return theLexicalValue->getStringProperty();
}


StoreConsts::NodeKind_t AttributeNodeNaive::getNodeKind() const
{
  return StoreConsts::attributeNode;
}


xqp_string AttributeNodeNaive::getStringValue() const
{
  return theLexicalValue->getStringValue();
}


bool AttributeNodeNaive::isId() const
{
  return theIsId;
}


bool AttributeNodeNaive::isIdrefs() const
{
  return theIsIdrefs;
}


QNameItem_t AttributeNodeNaive::getNodeName() const
{
  return theName;
}


Iterator_t AttributeNodeNaive::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), theTypedValue);
  return new PlanIterWrapper(planIter);
}


xqp_string AttributeNodeNaive::show() const
{
  return theName->getStringProperty() + "=\"" + (theLexicalValue != NULL ? theLexicalValue->show() : "") + "\"";
}


/*******************************************************************************

********************************************************************************/

TextNodeNaive::TextNodeNaive(const xqpStringStore_t& content) 
  :
  theContent(content)
{
}


TextNodeNaive::~TextNodeNaive()
{
}


QNameItem_t TextNodeNaive::getType() const
{
  return Store::getInstance().getItemFactory().
         createQName(StoreConsts::XS_URI, "xs", "untypedAtomic");
}


Item_t TextNodeNaive::getAtomizationValue() const
{
  return Store::getInstance().getItemFactory().createUntypedAtomic(theContent);
}


xqp_string TextNodeNaive::getStringProperty() const
{
  return theContent;
}


StoreConsts::NodeKind_t TextNodeNaive::getNodeKind() const
{
  return StoreConsts::textNode;
}


Iterator_t TextNodeNaive::getTypedValue() const
{
  const Item_t& item = Store::getInstance().getItemFactory().
                              createUntypedAtomic(theContent);

  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item);
  return new PlanIterWrapper(planIter);
}


xqp_string TextNodeNaive::getStringValue() const
{
  return theContent;
}

  
xqp_string TextNodeNaive::show() const
{
  return theContent;
}


/*******************************************************************************

********************************************************************************/
 
PiNodeNaive::PiNodeNaive(
    xqp_string& target_arg,
    xqp_string& uri_arg,
    xqp_string& baseUri_arg)
  :
  target ( target_arg ), content ( uri_arg ), baseUri ( baseUri_arg ) { }


PiNodeNaive::~PiNodeNaive()
{
}


Item_t PiNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(content);
}

xqp_string PiNodeNaive::getStringProperty() const
{
  return this->content;
}


xqp_string PiNodeNaive::getBaseURI() const
{
  return this->baseUri;
}

StoreConsts::NodeKind_t PiNodeNaive::getNodeKind() const
{
  return StoreConsts::piNode;
}


Iterator_t PiNodeNaive::getTypedValue() const
{
  const Item_t& item = zorba::getItemFactory()->createString(this->content);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item );
  return new PlanIterWrapper ( planIter );
}


xqp_string PiNodeNaive::getTarget() const
{
  return this->target;
}


xqp_string PiNodeNaive::getStringValue() const
{
  return this->content;
}


/*******************************************************************************

********************************************************************************/
CommentNodeNaive::CommentNodeNaive(const xqp_string& content_arg) : content(content_arg)
{
}

CommentNodeNaive::~CommentNodeNaive()
{
}


Item_t CommentNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic(this->content.getStore());
}

xqp_string CommentNodeNaive::getStringProperty() const
{
  return this->content;
}

StoreConsts::NodeKind_t CommentNodeNaive::getNodeKind() const
{
  return StoreConsts::commentNode;
}

Iterator_t CommentNodeNaive::getTypedValue() const
{
  const Item_t& item = zorba::getItemFactory()->createString(this->content);
  PlanIter_t planIter = new SingletonIterator(GET_CURRENT_LOCATION(), item );
  return new PlanIterWrapper(planIter);
}

xqp_string CommentNodeNaive::getStringValue() const
{
  return this->content;
}

xqp_string CommentNodeNaive::show() const
{
  return "<!--" + this->content + "-->";
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
    static_cast<NodeNaive*>(item.get_ptr())->setParent(theParentNode.get_ptr());

    if (item->getNodeKind() == StoreConsts::elementNode &&
        theParentNode->getNodeKind() != StoreConsts::documentNode)
    {
      Assert(theParentNode->getNodeKind() == StoreConsts::elementNode);

      ElementNodeNaive* child = static_cast<ElementNodeNaive*>(item.get_ptr());

      NsBindingsContext_t nsCtx = child->getNsBindingsContext();

      if (nsCtx == NULL)
      {
        child->setNsBindingsContext(theParentNode->getNsBindingsContext());
      }
      else
      {
        nsCtx->setParentContext(theParentNode->getNsBindingsContext());
      }

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
