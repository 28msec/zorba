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

  class DocumentNodeNaive : public DocumentNode
	{
		private:
			xqp_string baseURI;
			xqp_string docURI;

			TempSeq_t children;

		public:
			DocumentNodeNaive ( const xqp_string& baseURI, const xqp_string& documentURI, TempSeq_t& children );
			virtual ~DocumentNodeNaive();

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

	class ElementNodeNaive : public ElementNode
	{
		private:
			Item_t name;
			TypeCode type;

			TempSeq_t children;
			TempSeq_t attributes;
			TempSeq_t namespaces;

		public:
      ElementNodeNaive (
			    const Item_t& parent,
			    const Item_t& name,
			    TypeCode type,
			    TempSeq_t& children,
			    TempSeq_t& attributes,
			    TempSeq_t& namespaces,
			    bool copy,
			    bool newTypes
			);

      ElementNodeNaive (
			    const Item_t& name,
			    TypeCode type,
			    TempSeq_t& children,
			    TempSeq_t& attributes,
			    TempSeq_t& namespaces,
			    bool copy,
			    bool newTypes
			);
			
			virtual ~ElementNodeNaive();

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

  class AttributeNodeNaive : public AttributeNode
	{
		private:
			const Item_t name;
			const TypeCode type;
			const Item_t lexicalValue;
			const Item_t typedValue;

			bool bIsId;
			bool bIsIdrefs;

		public:
			AttributeNodeNaive (
// 			    const Item_t& parent,
			    const Item_t& name,
			    const TypeCode type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool bIsId,
			    bool bIsIdrefs
			);
			
      AttributeNodeNaive (
			    const Item_t& parent,
			    const Item_t& name,
			    const TypeCode type,
			    const Item_t& lexicalValue,
			    const Item_t& typedValue,
			    bool bIsId,
			    bool bIsIdrefs
			);
			
      virtual ~AttributeNodeNaive();

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

  class NamespaceNodeNaive : public NamespaceNode
	{
		private:
			xqp_string prefix;
			xqp_string uri;

		public:
      NamespaceNodeNaive ( const Item_t& parent, xqp_string& prefix, xqp_string& uri );
      NamespaceNodeNaive ( xqp_string prefix, xqp_string uri );
      virtual ~NamespaceNodeNaive();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getNamespace() const;
			virtual xqp_string getPrefix() const;
	}; /* class NamespaceNode */

  class PiNodeNaive : public PiNode
	{
		private:
			xqp_string target;
			xqp_string content;
			xqp_string baseUri;

		public:
      PiNodeNaive ( const Item_t& parent, xqp_string& target, xqp_string& content, xqp_string& baseUri );
      PiNodeNaive ( xqp_string& target, xqp_string& content, xqp_string& baseUri );
      virtual ~PiNodeNaive();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;
			virtual xqp_string getBaseURI() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getTarget() const;
			virtual xqp_string getStringValue() const;
	}; /* class PiNode */

  class CommentNodeNaive : public CommentNode
	{
		private:
			xqp_string content;

		public:
      CommentNodeNaive ( const Item_t& parent, xqp_string& content );
      CommentNodeNaive ( xqp_string& content );
      virtual ~CommentNodeNaive();

			virtual Item_t getAtomizationValue() const;
			virtual xqp_string getStringProperty() const;

			virtual TypeCode getNodeKind() const;
			virtual Iterator_t getTypedValue() const;
			virtual xqp_string getStringValue() const;
	}; /* class CommentNode */

  class TextNodeNaive : public TextNode
	{
		private:
			xqp_string content;

		public:
      TextNodeNaive ( const Item_t& parent, xqp_string& content );
      TextNodeNaive ( const xqp_string& content );
      virtual ~TextNodeNaive();

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
