#ifndef ZORBA_TYPES_TYPEIDENT_H
#define ZORBA_TYPES_TYPEIDENT_H

#include <boost/shared_ptr.hpp>
#include <zorba/api_shared_types.h>
#include <zorba/identtypes.h>
#include <zorba/string.h>

namespace zorba {

class TypeIdentifier {
  public:
    ~TypeIdentifier();

    static
    boost::shared_ptr<TypeIdentifier>
    createNamedType(
        const String& uri,
        const String& localName,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createElementType(
        const String& uri,
        bool uriWildcard,
        const String& localName,
        bool localNameWildcard,
        boost::shared_ptr<TypeIdentifier> contentType,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createAttributeType(
        const String& uri,
        bool uriWildcard,
        const String& localNameName,
        bool localNameWildcard,
        boost::shared_ptr<TypeIdentifier> contentType,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createDocumentType(
        boost::shared_ptr<TypeIdentifier> contentType,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createPIType(
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createTextType(
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createCommentType(
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createAnyNodeType(
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createItemType(
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    boost::shared_ptr<TypeIdentifier>
    createEmptyType();

    IdentTypes::kind_t
    getKind() const;

    IdentTypes::quantifier_t
    getQuantifier() const;

    const String&
    getUri() const;

    bool
    isUriWildcard() const;

    const String&
    getLocalName() const;

    bool
    isLocalNameWildcard() const;

    boost::shared_ptr<TypeIdentifier>
    getContentType() const;

  private:
    TypeIdentifier();

    IdentTypes::kind_t m_kind;
    IdentTypes::quantifier_t m_quantifier;
    String m_uri;
    bool m_uriWildcard;
    String m_localName;
    bool m_localNameWildcard;
    boost::shared_ptr<TypeIdentifier> m_contentType;
};

} /* namespace zorba */

#endif /* ZORBA_TYPES_TYPEIDENT_H */
/* vim:set ts=2 sw=2: */
