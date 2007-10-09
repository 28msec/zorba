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

	class Node : public Item
	{
		protected:
			// Pointer to avoid cyclic smart pointers
			Item* parent_p;

		public:
			explicit Node ( const Item_t& parent_arg );
			Node();
			virtual ~Node();

			virtual bool isNode() const;
			virtual bool isAtomic() const;
			virtual Item_t getEBV() const;
			virtual bool equals ( Item_t ) const;

			// Must be overwritten from every node implementation when zorba is schema-aware
			virtual TypeCode getType() const;
			virtual Item_t getParent() const;
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
			DocumentNode ( const xqp_string& baseURI, const xqp_string& documentURI, TempSeq_t& children );
			virtual ~DocumentNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual xqp_string getBaseURI() const;
			virtual Iterator_t getChildren() const;
			virtual xqp_string getDocumentURI() const;
			virtual Iterator_t getTypedValue() const;

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
			    TempSeq_t& children,
			    TempSeq_t& attributes,
			    TempSeq_t& namespaces,
			    bool copy,
			    bool newTypes
			);

			ElementNode (
			    const Item_t& name,
			    TypeCode type,
			    TempSeq_t& children,
			    TempSeq_t& attributes,
			    TempSeq_t& namespaces,
			    bool copy,
			    bool newTypes
			);
			
			virtual ~ElementNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getAttributes() const;
			virtual Iterator_t getChildren() const;
			virtual std::set<std::pair<xqp_string, xqp_string> > getNamespaceBindings() const;
			virtual Iterator_t getNamespaceNodes() const;
			virtual bool getNilled() const;
			virtual Item_t getNodeName() const;
			virtual Iterator_t getTypedValue() const;
			// Not implemented till types are supported
// 		Item_t getTypeName() const;
			virtual xqp_string show() const;
	}; /* class ElementNode */

	class AttributeNode : public Node
	{
		private:
			const Item_t name;
			const TypeCode type;
			const Item_t lexicalValue;
			const Item_t typedValue;

			bool bIsId;
			bool bIsIdrefs;

		public:
			AttributeNode (
// 			    const Item_t& parent,
			    const Item_t& name,
			    const TypeCode type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool bIsId,
			    bool bIsIdrefs
			);
			
			AttributeNode (
			    const Item_t& parent,
			    const Item_t& name,
			    const TypeCode type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool bIsId,
			    bool bIsIdrefs
			);
			
			virtual ~AttributeNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual xqp_string getStringValue() const;
			virtual bool isId() const;
			virtual bool isIdrefs() const;
			virtual Item_t getNodeName() const;
			virtual Iterator_t getTypedValue() const;
			// Not implemented till types are supported
// 		Item_t getTypeName() const;
			virtual xqp_string show() const;
	}; /* class AttributeNode */

	class NamespaceNode : public Node
	{
		private:
			xqp_string prefix;
			xqp_string uri;

		public:
			NamespaceNode ( const Item_t& parent, xqp_string& prefix, xqp_string& uri );
			NamespaceNode ( xqp_string prefix, xqp_string uri );
			virtual ~NamespaceNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getNamespace() const;
			virtual xqp_string getPrefix() const;
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
			virtual ~PiNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;
			virtual xqp_string getBaseURI() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getTarget() const;
			virtual xqp_string getStringValue() const;
	}; /* class PiNode */

	class CommentNode : public Node
	{
		private:
			xqp_string content;

		public:
			CommentNode ( const Item_t& parent, xqp_string& content );
			CommentNode ( xqp_string& content );
			virtual ~CommentNode();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getStringValue() const;
	}; /* class CommentNode */

	class TextNode : public Node
	{
		private:
			xqp_string content;

		public:
			TextNode ( const Item_t& parent, xqp_string& content );
			TextNode ( const xqp_string& content );
			virtual ~TextNode();

			virtual TypeCode getType() const;
			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getStringValue() const;
			
			virtual xqp_string show() const;
	}; /* class TextNode */

} /* namespace xqp */

#endif /* XQP_NODE_ITEMS_H */
