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

/*******************************************************************************
  class DocumentNode
********************************************************************************/

DocumentNodeNaive::DocumentNodeNaive(
    const xqp_string& baseURI_arg,
    const xqp_string& docURI_arg,
    TempSeq_t& children_arg )
  :
  baseURI ( baseURI_arg ),
  docURI ( docURI_arg ),
  children ( children_arg )
{
}
 

DocumentNodeNaive::~DocumentNodeNaive()
{
}


Item_t DocumentNodeNaive::getAtomizationValue() const
{
  const xqp_string& value = this->getStringProperty();
  return zorba::getItemFactory()->createUntypedAtomic ( value );
}


xqp_string DocumentNodeNaive::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = this->getChildren();
  Item_t item = it->next();
  while ( item != NULL )
  {
    oss << item->getStringProperty();
    item = it->next();
  }
  return oss.str();
}


TypeCode DocumentNodeNaive::getNodeKind() const
{
  return documentNode;
}


xqp_string DocumentNodeNaive::getBaseURI() const
{
  return this->baseURI;
}


Iterator_t DocumentNodeNaive::getChildren() const
{
  if ( this->children == NULL )
  {
    PlanIter_t planIter = new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
    return new PlanIterWrapper ( planIter );
  }
  else
  {
    return this->children->getIterator();
  }
}


xqp_string DocumentNodeNaive::getDocumentURI() const
{
  return this->docURI;
}


Iterator_t DocumentNodeNaive::getTypedValue() const
{
  PlanIter_t ret;
  if ( this->children->empty() )
  {
    ret = new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
  }
  else
  {
    xqp_string str = this->getStringProperty();
    Item_t item = zorba::getItemFactory()->createUntypedAtomic ( str );
    ret = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
  }
  return new PlanIterWrapper ( ret );
}


/*******************************************************************************
  class ElementNode
********************************************************************************/

ElementNodeNaive::ElementNodeNaive (
    const Item_t& parent,
    const QNameItem_t& name_arg,
    TypeCode type_arg,
    TempSeq_t& children_arg,
    TempSeq_t& attributes_arg,
    TempSeq_t& namespaces_arg,
    bool copy,
    bool newTypes)
  :
  ElementNode ( parent ),
  name ( name_arg ),
  type ( type_arg ),
  children ( children_arg ),
  attributes ( attributes_arg ),
  namespaces ( namespaces_arg )
{
}


ElementNodeNaive::ElementNodeNaive (
    const QNameItem_t& name_arg,
    TypeCode type_arg,
    TempSeq_t& children_arg,
    TempSeq_t& attributes_arg,
    TempSeq_t& namespaces_arg,
    bool copy,
    bool newTypes)
  :
  name ( name_arg ),
  type ( type_arg ),
  children ( children_arg ),
  attributes ( attributes_arg ),
  namespaces ( namespaces_arg )
{
}


ElementNodeNaive::~ElementNodeNaive()
{
}


Item_t ElementNodeNaive::getAtomizationValue() const
{
  const xqp_string& value = this->getStringProperty();
  return zorba::getItemFactory()->createUntypedAtomic ( value );
}


xqp_string ElementNodeNaive::getStringProperty() const
{
  ostringstream oss;
  Iterator_t it = this->getChildren();
  Item_t item = it->next();
  while ( item != NULL )
  {
    oss << item->getStringProperty();
    item = it->next();
  }
  return oss.str();
}


TypeCode ElementNodeNaive::getNodeKind() const
{
  return elementNode;
}

Iterator_t ElementNodeNaive::getAttributes() const
{
  if ( this->attributes == NULL )
  {
    PlanIter_t planIter = new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
    return new PlanIterWrapper ( planIter );
  }
  else
  {
    return this->attributes->getIterator();
  }
}


Iterator_t ElementNodeNaive::getChildren() const
{
  if ( this->children == NULL )
  {
    PlanIter_t planIter = new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
    return new PlanIterWrapper ( planIter );
  }
  else
  {
    return this->children->getIterator();
  }
}


std::set<std::pair<xqp_string, xqp_string> > ElementNodeNaive::getNamespaceBindings() const
{
  std::set<std::pair<xqp_string, xqp_string> > bindings;
  Iterator_t iter = this->namespaces->getIterator();
  Item_t item = iter->next();
  
  while ( item != NULL )
  {
    bindings.insert ( pair<xqp_string,xqp_string> ( item->getPrefix(), item->getNamespace() ) );
    item = iter->next();
  }
  return bindings;
}


bool ElementNodeNaive::getNilled() const
{
  Iterator_t iter = this->children->getIterator();
  Item_t item = iter->next();
  while ( item != NULL )
  {
    if ( item->isNode() && ( item->getNodeKind() == elementNode || item->getNodeKind() == textNode ) )
      return false;
    item = iter->next();
  }
  return true;
}


QNameItem_t ElementNodeNaive::getNodeName() const
{
  return this->name;
}


Iterator_t ElementNodeNaive::getTypedValue() const
{
  PlanIter_t ret;
  if ( this->children->empty() )
  {
    ret = new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
  }
  else
  {
    xqp_string str = this->getStringProperty();
    Item_t item = zorba::getItemFactory()->createUntypedAtomic ( str );
    ret = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
  }
  return new PlanIterWrapper ( ret );
}


xqp_string ElementNodeNaive::show() const
{
  xqp_string str;

  str =  "<" + this->name->getLocalName();

  if ( this->attributes != NULL )
  {
    Iterator_t iter = this->attributes->getIterator();
    Item_t item = iter->next();
    while ( item != NULL )
    {
      str += " " + item->show();
      item = iter->next();
    }
  }
  str += ">";
  if ( this->children != NULL )
  {
    Iterator_t iter = this->children->getIterator();
    Item_t item = iter->next();
    while ( item != NULL )
    {
      str += item->show();
      item = iter->next();
    }
  }
  str += "</" + this->name->getStringProperty() + ">";
  return str;
}


/*******************************************************************************
  class AttributeNode
********************************************************************************/

AttributeNodeNaive::AttributeNodeNaive (
    const QNameItem_t& name_arg,
    const TypeCode type_arg,
    const Item_t& lexicalValue_arg,
    const Item_t& typedValue_arg,
    bool bIsId_arg,
    bool bIsIdrefs_arg)
  :
  name ( name_arg ),
  type ( type_arg ),
  lexicalValue ( lexicalValue_arg ),
  typedValue ( typedValue_arg ),
  bIsId ( bIsId_arg ),
  bIsIdrefs ( bIsIdrefs_arg )
{
}


AttributeNodeNaive::AttributeNodeNaive (
    const Item_t& parent,
    const QNameItem_t& name_arg,
    const TypeCode type_arg,
    const Item_t& lexicalValue_arg,
    const Item_t& typedValue_arg,
    bool bIsId_arg,
    bool bIsIdrefs_arg)
  :
  AttributeNode ( parent ),
  name ( name_arg ),
  type ( type_arg ),
  lexicalValue ( lexicalValue_arg ),
  typedValue ( typedValue_arg ),
  bIsId ( bIsId_arg ),
  bIsIdrefs ( bIsIdrefs_arg )
{
}


AttributeNodeNaive::~AttributeNodeNaive()
{
}


Item_t AttributeNodeNaive::getAtomizationValue() const
{
  return this->lexicalValue;
}

xqp_string AttributeNodeNaive::getStringProperty() const
{
  return this->lexicalValue->getStringProperty();
}


TypeCode AttributeNodeNaive::getNodeKind() const
{
  return attributeNode;
}


xqp_string AttributeNodeNaive::getStringValue() const
{
  return this->lexicalValue->getStringValue();
}


bool AttributeNodeNaive::isId() const
{
  return this->bIsId;
}


bool AttributeNodeNaive::isIdrefs() const
{
  return this->bIsIdrefs;
}


QNameItem_t AttributeNodeNaive::getNodeName() const
{
  return this->name;
}


Iterator_t AttributeNodeNaive::getTypedValue() const
{
  PlanIter_t planIter = new SingletonIterator(zorba::getZorbaForCurrentThread()->GetCurrentLocation(), this->typedValue);
  return new PlanIterWrapper(planIter);
}


xqp_string AttributeNodeNaive::show() const
{
  return this->name->getStringProperty() + "=\"" + ( this->lexicalValue != NULL ? this->lexicalValue->show() : "" ) + "\"";
}
  /* end class AttributeNode */

  /* start class NamespaceNode */
NamespaceNodeNaive::NamespaceNodeNaive ( const Item_t& parent, xqp_string& prefix_arg, xqp_string& uri_arg )
  :
  NamespaceNode ( parent ), prefix ( prefix_arg ), uri ( uri_arg )
{
}


NamespaceNodeNaive::NamespaceNodeNaive ( xqp_string prefix_arg, xqp_string uri_arg ) : prefix ( prefix_arg ), uri ( uri_arg ) { }


NamespaceNodeNaive::~NamespaceNodeNaive() {}

Item_t NamespaceNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic ( this->getStringProperty() );
}

xqp_string NamespaceNodeNaive::getStringProperty() const
{
  return this->uri;
}

TypeCode NamespaceNodeNaive::getNodeKind() const
{
  return namespaceNode;
}

Iterator_t NamespaceNodeNaive::getTypedValue() const
{
  const Item_t& item = zorba::getItemFactory()->createString ( this->uri );
  PlanIter_t planIter = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
  return new PlanIterWrapper ( planIter );
}

xqp_string NamespaceNodeNaive::getNamespace() const
{
  return this->uri;
}

xqp_string NamespaceNodeNaive::getPrefix() const
{
  return this->prefix;
}
  /* end class NamespaceNode */

  /* start class PiNode */
PiNodeNaive::PiNodeNaive ( const Item_t& parent, xqp_string& target_arg, xqp_string& content_arg, xqp_string& baseUri_arg )
  :
  PiNode ( parent ), target ( target_arg ), content ( content_arg ), baseUri ( baseUri_arg ) { }
  
PiNodeNaive::PiNodeNaive ( xqp_string& target_arg, xqp_string& uri_arg, xqp_string& baseUri_arg )
  :
  target ( target_arg ), content ( uri_arg ), baseUri ( baseUri_arg ) { }

PiNodeNaive::~PiNodeNaive() {}

Item_t PiNodeNaive::getAtomizationValue() const
{
  return zorba::getItemFactory()->createUntypedAtomic ( this->content );
}

xqp_string PiNodeNaive::getStringProperty() const
{
  return this->content;
}

  xqp_string PiNodeNaive::getBaseURI() const
  {
    return this->baseUri;
  }

  TypeCode PiNodeNaive::getNodeKind() const
  {
    return processingInstructionNode;
  }

  Iterator_t PiNodeNaive::getTypedValue() const
  {
    const Item_t& item = zorba::getItemFactory()->createString ( this->content );
    PlanIter_t planIter = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
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
  /* end class PiNode */

  /* start class CommentNode */
  CommentNodeNaive::CommentNodeNaive ( const Item_t& parent, xqp_string& content_arg ) : CommentNode ( parent ), content ( content_arg ) {}
  CommentNodeNaive::CommentNodeNaive ( xqp_string& content_arg ) : content ( content_arg ) {}
  CommentNodeNaive::~CommentNodeNaive() {}

  Item_t CommentNodeNaive::getAtomizationValue() const
  {
    return zorba::getItemFactory()->createUntypedAtomic ( this->content );
  }

  xqp_string CommentNodeNaive::getStringProperty() const
  {
    return this->content;
  }

  TypeCode CommentNodeNaive::getNodeKind() const
  {
    return commentNode;
  }

  Iterator_t CommentNodeNaive::getTypedValue() const
  {
    const Item_t& item = zorba::getItemFactory()->createString ( this->content );
    PlanIter_t planIter = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
    return new PlanIterWrapper ( planIter );
  }

  xqp_string CommentNodeNaive::getStringValue() const
  {
    return this->content;
  }
  /* end class CommentNode */

  /* start class TextNode */
  TextNodeNaive::TextNodeNaive ( const Item_t& parent, xqp_string& content_arg ) : TextNode ( parent ), content ( content_arg ) {}
  TextNodeNaive::TextNodeNaive ( const xqp_string& content_arg ) : content ( content_arg ) {}
  TextNodeNaive::~TextNodeNaive() {}

  TypeCode TextNodeNaive::getType() const
  {
    return xs_untypedAtomicValue;
  }

  Item_t TextNodeNaive::getAtomizationValue() const
  {
    return zorba::getItemFactory()->createUntypedAtomic ( this->content );
  }

  xqp_string TextNodeNaive::getStringProperty() const
  {
    return this->content;
  }

  TypeCode TextNodeNaive::getNodeKind() const
  {
    return textNode;
  }

  Iterator_t TextNodeNaive::getTypedValue() const
  {
    const Item_t& item = zorba::getItemFactory()->createUntypedAtomic ( this->content );
    PlanIter_t planIter = new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
    return new PlanIterWrapper ( planIter );
  }

  xqp_string TextNodeNaive::getStringValue() const
  {
    return this->content;
  }

  xqp_string TextNodeNaive::show() const
  {
    return this->content;
  }
  /* end class TextNode */

} /* namespace xqp */
