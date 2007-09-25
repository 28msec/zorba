/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 */

#include "node_items.h"
#include "store/api/temp_seq.h"
#include "runtime/zorba.h"

namespace xqp
{

	/* start class Node */
	Node::Node ( const Item_t& parent_arg ) : parent_p ( &*parent_arg ) {}
	Node::Node() : parent_p ( NULL ) {}
	Node::~Node() {}

	bool Node::isNode() const
	{
		return true;
	}

	bool Node::isAtomic() const
	{
		return false;
	}

	Item_t Node::getEBV() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createBoolean ( true );
	}

	bool Node::equals ( Item_t item ) const
	{
		ZorbaErrorAlerts::error_alert (
		    error_messages::XQP0014_SYSTEM_SHOUD_NEVER_BE_REACHED,
		    error_messages::SYSTEM_ERROR,
		    NULL,
		    true,
		    "Equal function for node items not implemented!"
		);
		return false;
	}

	TypeCode Node::getType() const
	{
		return xs_anyType;
	}

	Item_t Node::getParent() const
	{
		return this->parent_p;
	}

	xqp_string Node::getBaseURI() const
	{
		return this->parent_p ? this->parent_p->getBaseURI() : "";
	}

	xqp_string Node::getDocumentURI() const
	{
		return this->parent_p ? this->parent_p->getDocumentURI() : "";
	}
	/* end class Node */

	/* start class DocumentNode */
	DocumentNode::DocumentNode ( const xqp_string& baseURI_arg, const xqp_string& docURI_arg, TempSeq_t& children_arg ) : baseURI ( baseURI_arg ), docURI ( docURI_arg ), children( children_arg)
	{	}
	DocumentNode::~DocumentNode(){}

	Item_t DocumentNode::getAtomizationValue() const
	{
		const xqp_string& value = this->getStringProperty();
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( value );
	}

	xqp_string DocumentNode::getStringProperty() const
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

	TypeCode DocumentNode::getNodeKind() const
	{
		return documentNode;
	}

	xqp_string DocumentNode::getBaseURI() const
	{
		return this->baseURI;
	}

	Iterator_t DocumentNode::getChildren() const
	{
		return this->children->getIterator();
	}

	xqp_string DocumentNode::getDocumentURI() const
	{
		return this->docURI;
	}

	Iterator_t DocumentNode::getTypedValue() const
	{
		if ( this->children->empty() )
			return new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
		xqp_string str = this->getStringProperty();
		Item_t item = zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( str );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}
	/* end class DocumentNode */

	/* start class ElementNode */

	ElementNode::ElementNode (
	    const Item_t& parent,
	    const Item_t& name_arg,
	    TypeCode type_arg,
	    TempSeq_t& children_arg,
	    TempSeq_t& attributes_arg,
	    TempSeq_t& namespaces_arg,
	    bool copy,
	    bool newTypes
	)
			:
			Node ( parent ),
			name ( name_arg ),
			type ( type_arg ),
			children(children_arg),
			attributes(attributes_arg),
			namespaces(namespaces_arg)/*,
			children ( zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( children_arg ) ),
			attributes ( zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( attributes_arg ) ),
			namespaces ( namespaces_arg == NULL ? NULL : zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( namespaces_arg ) )*/
	{ }

	ElementNode::ElementNode (
	    const Item_t& name_arg,
	    TypeCode type_arg,
	    TempSeq_t& children_arg,
	    TempSeq_t& attributes_arg,
	    TempSeq_t& namespaces_arg,
	    bool copy,
	    bool newTypes
	)
			:
			name ( name_arg ),
			type ( type_arg ),
			children(children_arg),
			attributes(attributes_arg),
			namespaces(namespaces_arg)/*,
			children ( zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( children_arg ) ),
			attributes ( zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( attributes_arg ) ),
			namespaces ( zorba::getZorbaForCurrentThread()->getStore()->createTempSeq ( namespaces_arg ) )*/
	{ }
	
	ElementNode::~ElementNode(){}

	Item_t ElementNode::getAtomizationValue() const
	{
		const xqp_string& value = this->getStringProperty();
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( value );
	}

	xqp_string ElementNode::getStringProperty() const
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

	TypeCode ElementNode::getNodeKind() const
	{
		return elementNode;
	}

	Iterator_t ElementNode::getAttributes() const
	{
		return this->attributes->getIterator();
	}

	Iterator_t ElementNode::getChildren() const
	{
		return this->children->getIterator();
	}

	std::set<std::pair<std::string, std::string> > ElementNode::getNamespaceBindings() const
	{
		std::set<std::pair<std::string, std::string> > bindings;
		Iterator_t iter = this->namespaces->getIterator();
		Item_t item = iter->next();

		while ( item != NULL )
		{
			bindings.insert ( pair<std::string,std::string> ( item->getPrefix(), item->getNamespace() ) );
			item = iter->next();
		}
		return bindings;
	}

	Iterator_t ElementNode::getNamespaceNodes() const
	{
		return this->namespaces->getIterator();
	}

	bool ElementNode::getNilled() const
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

	Item_t ElementNode::getNodeName() const
	{
		return this->name;
	}

	Iterator_t ElementNode::getTypedValue() const
	{
		if ( this->children->empty() )
			return new EmptyIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation() );
		xqp_string str = this->getStringProperty();
		Item_t item = zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( str );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}
	
	xqp_string ElementNode::show() const
	{
		xqp_string str;
		
		str =  "<" + this->name->getLocalName();
		
		if (this->attributes != NULL) {
			Iterator_t iter = this->attributes->getIterator();
			Item_t item = iter->next();
			while (item != NULL) {
				str += " " + item->show();
				item = iter->next();
			}
		}
		str += ">";
		if (this->children != NULL) {
			Iterator_t iter = this->children->getIterator();
			Item_t item = iter->next();
			while (item != NULL) {
				str += item->show();
				item = iter->next();
			}
		}
		str += "</" + this->name->getStringProperty() + ">";
		return str;
	}
	/* end class ElementNode */

	/* start class AttributeNode */
	AttributeNode::AttributeNode (
	    const Item_t& name_arg,
	    const TypeCode type_arg,
	    const Item_t& lexicalValue_arg,
	    const Item_t& typedValue_arg,
	    bool bIsId_arg,
	    bool bIsIdrefs_arg
	)
			:
			name ( name_arg ),
			type ( type_arg ),
			lexicalValue ( lexicalValue_arg ),
			typedValue ( typedValue_arg ),
			bIsId ( bIsId_arg ),
			bIsIdrefs ( bIsIdrefs_arg )
	{}
	
	AttributeNode::AttributeNode (
	    const Item_t& parent,
	    const Item_t& name_arg,
	    const TypeCode type_arg,
	    const Item_t& lexicalValue_arg,
	    const Item_t& typedValue_arg,
	    bool bIsId_arg,
	    bool bIsIdrefs_arg
	)
			:
			Node ( parent ),
			name ( name_arg ),
			type ( type_arg ),
			lexicalValue ( lexicalValue_arg ),
			typedValue ( typedValue_arg ),
			bIsId ( bIsId_arg ),
			bIsIdrefs ( bIsIdrefs_arg )
	{}
	
	AttributeNode::~AttributeNode(){}

	Item_t AttributeNode::getAtomizationValue() const
	{
		return this->lexicalValue;
	}

	xqp_string AttributeNode::getStringProperty() const
	{
		return this->lexicalValue->getStringProperty();
	}

	TypeCode AttributeNode::getNodeKind() const
	{
		return attributeNode;
	}

	xqp_string AttributeNode::getStringValue() const
	{
		return this->lexicalValue->getStringValue();
	}

	bool AttributeNode::isId() const
	{
		return this->bIsId;
	}

	bool AttributeNode::isIdrefs() const
	{
		return this->bIsIdrefs;
	}

	Item_t AttributeNode::getNodeName() const
	{
		return this->name;
	}

	Iterator_t AttributeNode::getTypedValue() const
	{
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), this->typedValue );
	}
	
	xqp_string AttributeNode::show() const
	{
		return this->name->getStringProperty() + "=\"" + (this->lexicalValue != NULL ? this->lexicalValue->show() : "") + "\"";
	}
	/* end class AttributeNode */

	/* start class NamespaceNode */
	NamespaceNode::NamespaceNode ( const Item_t& parent, xqp_string& prefix_arg, xqp_string& uri_arg )
			:
			Node ( parent ), prefix ( prefix_arg ), uri ( uri_arg )
	{ }
	NamespaceNode::NamespaceNode ( xqp_string prefix_arg, xqp_string uri_arg ) : prefix ( prefix_arg ), uri ( uri_arg ) { }
	NamespaceNode::~NamespaceNode(){}

	Item_t NamespaceNode::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( this->getStringProperty() );
	}

	xqp_string NamespaceNode::getStringProperty() const
	{
		return this->uri;
	}

	TypeCode NamespaceNode::getNodeKind() const
	{
		return namespaceNode;
	}

	Iterator_t NamespaceNode::getTypedValue() const
	{
		const Item_t& item = zorba::getZorbaForCurrentThread()->getItemFactory()->createString ( this->uri );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}

	xqp_string NamespaceNode::getNamespace() const
	{
		return this->uri;
	}

	xqp_string NamespaceNode::getPrefix() const
	{
		return this->prefix;
	}
	/* end class NamespaceNode */

	/* start class PiNode */
	PiNode::PiNode ( const Item_t& parent, xqp_string& target_arg, xqp_string& content_arg, xqp_string& baseUri_arg )
			:
			Node ( parent ), target ( target_arg ), content ( content_arg ), baseUri ( baseUri_arg ) { }

	PiNode::PiNode ( xqp_string& target_arg, xqp_string& uri_arg, xqp_string& baseUri_arg )
			:
			target ( target_arg ), content ( uri_arg ), baseUri ( baseUri_arg ) { }
	
	PiNode::~PiNode(){}

	Item_t PiNode::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( this->content );
	}

	xqp_string PiNode::getStringProperty() const
	{
		return this->content;
	}

	xqp_string PiNode::getBaseURI() const
	{
		return this->baseUri;
	}

	TypeCode PiNode::getNodeKind() const
	{
		return processingInstructionNode;
	}

	Iterator_t PiNode::getTypedValue() const
	{
		const Item_t& item = zorba::getZorbaForCurrentThread()->getItemFactory()->createString ( this->content );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}

	xqp_string PiNode::getTarget() const
	{
		return this->target;
	}

	xqp_string PiNode::getStringValue() const
	{
		return this->content;
	}
	/* end class PiNode */

	/* start class CommentNode */
	CommentNode::CommentNode ( const Item_t& parent, xqp_string& content_arg ) : Node ( parent ), content ( content_arg ) {}
	CommentNode::CommentNode ( xqp_string& content_arg ) : content ( content_arg ) {}
	CommentNode::~CommentNode(){}

	Item_t CommentNode::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( this->content );
	}

	xqp_string CommentNode::getStringProperty() const
	{
		return this->content;
	}

	TypeCode CommentNode::getNodeKind() const
	{
		return commentNode;
	}

	Iterator_t CommentNode::getTypedValue() const
	{
		const Item_t& item = zorba::getZorbaForCurrentThread()->getItemFactory()->createString ( this->content );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}

	xqp_string CommentNode::getStringValue() const
	{
		return this->content;
	}
	/* end class CommentNode */

	/* start class TextNode */
	TextNode::TextNode ( const Item_t& parent, xqp_string& content_arg ) : Node ( parent ), content ( content_arg ) {}
	TextNode::TextNode ( const xqp_string& content_arg ) : content ( content_arg ) {}
	TextNode::~TextNode(){}

	TypeCode TextNode::getType() const
	{
		return xs_untypedAtomicValue;
	}

	Item_t TextNode::getAtomizationValue() const
	{
		return zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( this->content );
	}

	xqp_string TextNode::getStringProperty() const
	{
		return this->content;
	}

	TypeCode TextNode::getNodeKind() const
	{
		return textNode;
	}

	Iterator_t TextNode::getTypedValue() const
	{
		const Item_t& item = zorba::getZorbaForCurrentThread()->getItemFactory()->createUntypedAtomic ( this->content );
		return new SingletonIterator ( zorba::getZorbaForCurrentThread()->GetCurrentLocation(), item );
	}

	xqp_string TextNode::getStringValue() const
	{
		return this->content;
	}
	
	xqp_string TextNode::show() const
	{
		return this->content;
	}
	/* end class TextNode */

} /* namespace xqp */
