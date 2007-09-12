/*
 *	Copyright 2006-2007 FLWOR Foundation.
 *  Author: David Graf (david.graf@28msec.com)
 *
 *  Info: This file contains the class declarations of all nodes defined in [http://www.w3.org/TR/xpath-datamodel/#Nodes].
 */

#ifndef XQP_NODE_ITEMS_H
#define XQP_NODE_ITEMS_H

#include <vector>
#include <string>

#include "store/api/item.h"

namespace xqp
{
	template <class Object> class rchandle;

	typedef rchandle<class Item> Item_t;
	typedef rchandle<class TempSeq> TempSeq_t;

	typedef std::string xqp_string;

	class Node : public Item
	{
		protected:
			// Pointer to avoid cyclic smart pointers
			Item* parent_p;

		public:
			explicit Node ( const Item_t& parent_arg );
			Node();

			bool isNode() const;
			bool isAtomic() const;
			Item_t getEBV() const;
			virtual bool equal ( Item_t ) const;

			// Must be overwritten from every node implementation when zorba is schema-aware
			virtual TypeCode getType() const;
			Item_t getParent() const;
			virtual xqp_string getBaseURI() const;
			virtual xqp_string getDocumentURI() const;
	}; /* class Node */

	class DocumentNode : public Node
	{
		private:
			xqp_string baseURI;
			xqp_string docURI;

			TempSeq_t children;

		public:
			DocumentNode ( const xqp_string& baseURI, const xqp_string& documentURI, Iterator_t& children );

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			xqp_string getBaseURI() const;
			Iterator_t getChildren() const;
			xqp_string getDocumentURI() const;
			Iterator_t getTypedValue() const;

			// Used when zorba supports DTD
// 		xqp_string getUnparsedEntityPublicId() const;
// 		xqp_string getunparsedEntitySystemId() const;
	}; /* class DocumentNode */

	class ElementNode : public Node
	{
		private:
			Item_t name;
			TypeCode type;

			TempSeq_t children;
			TempSeq_t attributes;
			TempSeq_t namespaces;

		public:
			ElementNode (
			    const Item_t& parent,
			    const Item_t& name,
			    TypeCode type,
			    Iterator_t& children,
			    Iterator_t& attributes,
			    Iterator_t& namespaces,
			    bool copy,
			    bool newTypes
			);

			ElementNode (
			    const Item_t& name,
			    TypeCode type,
			    Iterator_t& children,
			    Iterator_t& attributes,
			    Iterator_t& namespaces,
			    bool copy,
			    bool newTypes
			);

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			Iterator_t getAttributes() const;
			Iterator_t getChildren() const;
			std::set<std::pair<xqp_string, xqp_string> > getNamespaceBindings() const;
			Iterator_t getNamespaceNodes() const;
			bool getNilled() const;
			Item_t getNodeName() const;
			Iterator_t getTypedValue() const;
			// Not implemented till types are supported
// 		Item_t getTypeName() const;
	}; /* class ElementNode */

	class AttributeNode : public Node
	{
		private:
			Item_t name;
			TypeCode type;
			Item_t lexicalValue;
			Item_t typedValue;

			bool bIsId;
			bool bIsIdrefs;

		public:
			AttributeNode (
			    const Item_t& parent,
			    const Item_t& name,
			    const TypeCode type,
			    Item_t& lexicalValue,
			    Item_t& typedValue,
			    bool bIsId,
			    bool bIsIdrefs
			);

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			xqp_string getStringValue() const;
			bool isId() const;
			bool isIdrefs() const;
			Item_t getNodeName() const;
			Iterator_t getTypedValue() const;
			// Not implemented till types are supported
// 		Item_t getTypeName() const;
	}; /* class AttributeNode */

	class NamespaceNode : public Node
	{
		private:
			xqp_string prefix;
			xqp_string uri;

		public:
			NamespaceNode ( const Item_t& parent, xqp_string& prefix, xqp_string& uri );
			NamespaceNode ( xqp_string prefix, xqp_string uri );

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			Iterator_t getTypedValue() const;
			xqp_string getNamespace() const;
			xqp_string getPrefix() const;
	}; /* class NamespaceNode */

	class PiNode : public Node
	{
		private:
			xqp_string target;
			xqp_string content;
			xqp_string baseUri;

		public:
			PiNode ( const Item_t& parent, xqp_string& target, xqp_string& content, xqp_string& baseUri );
			PiNode ( xqp_string& target, xqp_string& content, xqp_string& baseUri );

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;
			xqp_string getBaseURI() const;

			TypeCode getNodeKind() const;
			Iterator_t getTypedValue() const;
			xqp_string getTarget() const;
			xqp_string getContent() const;
			xqp_string getStringValue() const;
	}; /* class PiNode */

	class CommentNode : public Node
	{
		private:
			xqp_string content;

		public:
			CommentNode ( const Item_t& parent, xqp_string& content );
			CommentNode ( xqp_string& content );

			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			Iterator_t getTypedValue() const;
			xqp_string getStringValue() const;
	}; /* class CommentNode */

	class TextNode : public Node
	{
		private:
			xqp_string content;

		public:
			TextNode ( const Item_t& parent, xqp_string& content );
			TextNode ( xqp_string& content );

			TypeCode getType() const;
			Item_t getAtomizationValue() const;
			xqp_string getStringProperty() const;

			TypeCode getNodeKind() const;
			Iterator_t getTypedValue() const;
			xqp_string getStringValue() const;
	}; /* class TextNode */

} /* namespace xqp */

#endif /* XQP_NODE_ITEMS_H */
