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
#include <zorba/zorba_string.h>
#include <iostream>

namespace zorba {

/**
 * \brief Representation and factory for xquery sequence types.
 *
 * Class SequenceType represents xquery sequence types, as defined in
 * http://www.w3.org/TR/xquery-30/#id-sequencetype-syntax. Instances of
 * SequenceType may be returned by methods of Zorba's C++ API. The class also
 * provides static methods to create instances of SequenceType, which can then
 * be passed as arguments to other methods of Zorba's C++ API.
 *
 * Note: This class is reference counted. When writing multi-threaded clients,
 * it is the responibility of the client code to synchronize assignments to the
 * SmartPtr holding this object.
 */
class ZORBA_DLL_PUBLIC SequenceType : public SmartObject
{
 public:
  typedef enum 
  {
    EMPTY_TYPE,               // empty-sequence()
    ITEM_TYPE,                // item()
    ATOMIC_OR_UNION_TYPE,     // AtomicOrUnionType
    ANY_STRUCTURED_ITEM_TYPE, // structured-item()
    ANY_NODE_TYPE,            // node()
    DOCUMENT_TYPE,
    ELEMENT_TYPE,
    SCHEMA_ELEMENT_TYPE,
    ATTRIBUTE_TYPE,
    SCHEMA_ATTRIBUTE_TYPE,
    PI_TYPE,
    TEXT_TYPE,
    COMMENT_TYPE,
    NAMESPACE_TYPE,
    JSON_ITEM_TYPE,
    JSON_OBJECT_TYPE,
    JSON_ARRAY_TYPE,
    INVALID_TYPE
  } Kind;
  

  typedef enum 
  {
    QUANT_ONE,
    QUANT_QUESTION,
    QUANT_PLUS,
    QUANT_STAR
  } Quantifier;


 public:
  /** \brief Destructor
   */
  ~SequenceType();

  static SequenceType_t
  createEmptyType();

  static SequenceType_t
  createItemType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createNamedType(
      const String& uri,
      const String& localName,
      Quantifier q = QUANT_ONE);

  static SequenceType_t
  createStructuredItemType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createAnyNodeType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createDocumentType(
      SequenceType_t contentType,
      Quantifier q = QUANT_ONE);

  static SequenceType_t
  createElementType(
      const String& uri,
      bool uriWildcard,
      const String& localName,
      bool localNameWildcard,
      SequenceType_t contentType,
      Quantifier q = QUANT_ONE);

  static SequenceType_t
  createSchemaElementType(
      const String& uri,
      const String& localName,
      Quantifier q = QUANT_ONE);
  
  static SequenceType_t
  createAttributeType(
      const String& uri,
      bool uriWildcard,
      const String& localName,
      bool localNameWildcard,
      SequenceType_t contentType,
      Quantifier q = QUANT_ONE);

  static SequenceType_t
  createSchemaAttributeType(
      const String& uri,
      const String& localName,
      Quantifier q = QUANT_ONE);
  
  static SequenceType_t
  createPIType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createTextType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createCommentType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createNamespaceType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createJSONItemType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createJSONObjectType(Quantifier q = QUANT_ONE);

  static SequenceType_t
  createJSONArrayType(Quantifier q = QUANT_ONE);

 public:
  Kind getKind() const;

  Quantifier
  getQuantifier() const;

  const String&
  getUri() const;

  bool
  isUriWildcard() const;

  const String&
  getLocalName() const;

  bool
  isLocalNameWildcard() const;

  SequenceType_t
  getContentType() const;

  std::ostream&
  emit(std::ostream&) const;

 private:
  SequenceType();

  std::ostream&
  emitItemType(std::ostream&) const;

  std::ostream&
  emitName(std::ostream&) const;

public:
  static char const *const kind_string_of[];

  static char const *const quantifier_string_of[];

 private:
  Kind           m_kind;
  Quantifier     m_quantifier;
  String         m_uri;
  bool           m_uriWildcard;
  String         m_localName;
  bool           m_localNameWildcard;
  SequenceType_t m_contentType;
};
  
#ifdef WIN32
  template class ZORBA_DLL_PUBLIC  zorba::SmartPtr<SequenceType>;
#endif


} /* namespace zorba */

namespace std {

ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType& ti);
ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType_t ti);

ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType::Kind k);
ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType::Quantifier q);

}

#endif /* ZORBA_TYPES_TYPEIDENT_H */
/* vim:set et sw=2 ts=2: */
