#ifndef ZORBA_TYPEIDENT_H
#define ZORBA_TYPEIDENT_H

#include <zorba/common/api_shared_types.h>
#include <zorba/item.h> // TODO this could maybe be removed if we have explizit destructors in cpp files

namespace zorba {

  class TypeIdentifier : virtual public SimpleRCObject {
    public:
      typedef enum {
        NAMED_TYPE,
        ELEMENT_TYPE,
        ATTRIBUTE_TYPE,
        DOCUMENT_TYPE,
        PI_TYPE,
        TEXT_TYPE,
        COMMENT_TYPE,
        ANY_NODE_TYPE,
        ITEM_TYPE,
        EMPTY_TYPE,
      } kind_t;

      typedef enum {
        QUANT_ONE,
        QUANT_QUESTION,
        QUANT_PLUS,
        QUANT_STAR,
      } quantifier_t;

      virtual ~TypeIdentifier() { }

      virtual kind_t
      get_kind() const = 0;

      quantifier_t
      get_quantifier() const
      {
        return m_quantifier;
      }

    protected:
      TypeIdentifier(quantifier_t quantifier)
        : m_quantifier(quantifier) { }

      quantifier_t m_quantifier;
  };

  typedef rchandle<TypeIdentifier> type_ident_ref_t;

  class NamedTypeIdentifier : public TypeIdentifier {
    public:
      NamedTypeIdentifier(quantifier_t quantifier, Item_t name)
        : TypeIdentifier(quantifier), m_name(name) { }

      virtual kind_t 
      get_kind() const
      {
        return NAMED_TYPE;
      }

      const Item_t 
      get_name() const
      {
        return m_name;
      }

    protected:
      Item_t m_name;
  };

  class ContentTypeHolder {
    public:
      const type_ident_ref_t 
      get_content_type() const
      {
        return m_content_type;
      }

      virtual ~ContentTypeHolder() { }

    protected:
      ContentTypeHolder(type_ident_ref_t content_type)
        : m_content_type(content_type) { }

      type_ident_ref_t m_content_type;
  };

  class ElementOrAttributeTypeIdentifier : public TypeIdentifier, public ContentTypeHolder {
    public:
      virtual ~ElementOrAttributeTypeIdentifier() { }

      const rchandle<xqpStringStore> 
      get_uri() const
      {
        return m_uri;
      }

      const rchandle<xqpStringStore>
      get_local() const
      {
        return m_local;
      }
    protected:
      ElementOrAttributeTypeIdentifier(quantifier_t quantifier, rchandle<xqpStringStore> uri, 
                                       rchandle<xqpStringStore> local, type_ident_ref_t content_type)
        : TypeIdentifier(quantifier),
        ContentTypeHolder(content_type),
        m_uri(uri),
        m_local(local) { }

      rchandle<xqpStringStore> m_uri;
      rchandle<xqpStringStore> m_local;
  };

  class ElementTypeIdentifier : public ElementOrAttributeTypeIdentifier {
    public:
      ElementTypeIdentifier(quantifier_t quantifier, rchandle<xqpStringStore> uri, 
                            rchandle<xqpStringStore> local, type_ident_ref_t content_type)
        : ElementOrAttributeTypeIdentifier(quantifier, uri, local, content_type) { }

      virtual kind_t 
      get_kind() const
      {
        return ELEMENT_TYPE;
      }
  };

  class AttributeTypeIdentifier : public ElementOrAttributeTypeIdentifier {
    public:
      AttributeTypeIdentifier(quantifier_t quantifier, rchandle<xqpStringStore> uri, 
                              rchandle<xqpStringStore> local, type_ident_ref_t content_type)
        : ElementOrAttributeTypeIdentifier(quantifier, uri, local, content_type) { }

      virtual kind_t 
      get_kind() const
      {
        return ATTRIBUTE_TYPE;
      }
  };

  class DocumentTypeIdentifier : public TypeIdentifier, public ContentTypeHolder {
    public:
      DocumentTypeIdentifier(quantifier_t quantifier, type_ident_ref_t content_type)
        : TypeIdentifier(quantifier),
        ContentTypeHolder(content_type) { }

      virtual ~DocumentTypeIdentifier() { }

      virtual kind_t
      get_kind() const
      {
        return DOCUMENT_TYPE;
      }
  };

  class PITypeIdentifier : public TypeIdentifier {
    public:
      PITypeIdentifier(quantifier_t quantifier)
        : TypeIdentifier(quantifier) { }

      virtual kind_t
      get_kind() const
      {
        return PI_TYPE;
      }
  };

  class TextTypeIdentifier : public TypeIdentifier {
    public:
      TextTypeIdentifier(quantifier_t quantifier)
        : TypeIdentifier(quantifier) { }

      virtual kind_t
      get_kind() const
      {
        return TEXT_TYPE;
      }
  };

  class CommentTypeIdentifier : public TypeIdentifier {
    public:
      CommentTypeIdentifier(quantifier_t quantifier)
        : TypeIdentifier(quantifier) { }

      virtual kind_t
      get_kind() const
      {
        return COMMENT_TYPE;
      }
  };

  class AnyNodeTypeIdentifier : public TypeIdentifier {
    public:
      AnyNodeTypeIdentifier(quantifier_t quantifier)
        : TypeIdentifier(quantifier) { }

      virtual kind_t
      get_kind() const
      {
        return ANY_NODE_TYPE;
      }
  };

  class ItemTypeIdentifier : public TypeIdentifier {
    public:
      ItemTypeIdentifier(quantifier_t quantifier)
        : TypeIdentifier(quantifier) { }

      virtual kind_t
      get_kind() const
      {
        return ITEM_TYPE;
      }
  };

  class EmptyTypeIdentifier : public TypeIdentifier {
    public:
      EmptyTypeIdentifier()
        : TypeIdentifier(QUANT_ONE) { }

      virtual kind_t
      get_kind() const
      {
        return EMPTY_TYPE;
      }
  };

} /* namespace zorba */
#endif /* XQP_TYPEIDENT_H */

/* vim:set ts=2 sw=2: */
