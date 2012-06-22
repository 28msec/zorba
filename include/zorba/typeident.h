/*
 * Copyright 2006-2008 The FLWOR Foundation.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef ZORBA_TYPES_TYPEIDENT_H
#define ZORBA_TYPES_TYPEIDENT_H

#include <zorba/config.h>
#include <zorba/api_shared_types.h>
#include <zorba/identtypes.h>
#include <zorba/zorba_string.h>
#include <iostream>

namespace zorba {

/** \brief Type identifiers
 *
 * The type identifiers are not used, yet.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC TypeIdentifier : public SmartObject {
  public:
    /** \brief Destructor
     */
    ~TypeIdentifier();

    static
    TypeIdentifier_t
    createNamedType(
        const String& uri,
        const String& localName,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    TypeIdentifier_t
    createElementType(
        const String& uri,
        bool uriWildcard,
        const String& localName,
        bool localNameWildcard,
        TypeIdentifier_t contentType,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );

    static
    TypeIdentifier_t
    createAttributeType(
        const String& uri,
        bool uriWildcard,
        const String& localName,
        bool localNameWildcard,
        TypeIdentifier_t contentType,
        IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createDocumentType(
        TypeIdentifier_t contentType,
        IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createPIType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createTextType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createCommentType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createAnyNodeType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

#ifdef ZORBA_WITH_JSON
    static
    TypeIdentifier_t
    createStructuredItemType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createJSONItemType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createJSONObjectType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createJSONArrayType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createJSONPairType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);
#endif

    static
    TypeIdentifier_t
    createItemType(IdentTypes::quantifier_t q = IdentTypes::QUANT_ONE);

    static
    TypeIdentifier_t
    createEmptyType();

    static
    TypeIdentifier_t
    createSchemaElementType(
        const String& uri,
        const String& localName,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );
  
    static
    TypeIdentifier_t
    createSchemaAttributeType(
        const String& uri,
        const String& localName,
        IdentTypes::quantifier_t quantifier = IdentTypes::QUANT_ONE
        );
  
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

    TypeIdentifier_t
    getContentType() const;

    std::ostream&
    emit(std::ostream&) const;

  private:
    TypeIdentifier();

    std::ostream&
    emitItemType(std::ostream&) const;

    std::ostream&
    emitName(std::ostream&) const;

    IdentTypes::kind_t m_kind;
    IdentTypes::quantifier_t m_quantifier;
    String m_uri;
    bool m_uriWildcard;
    String m_localName;
    bool m_localNameWildcard;
    TypeIdentifier_t m_contentType;
};

#ifdef WIN32
  template class ZORBA_DLL_PUBLIC  zorba::SmartPtr<TypeIdentifier>;
#endif


} /* namespace zorba */

namespace std {

ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::TypeIdentifier& ti);
ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::TypeIdentifier_t ti);

}

#endif /* ZORBA_TYPES_TYPEIDENT_H */
/* vim:set et sw=2 ts=2: */
