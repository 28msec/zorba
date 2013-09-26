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


class XQType;


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
class ZORBA_DLL_PUBLIC SequenceType
{
public:
  typedef enum 
  {
    EMPTY_TYPE,               // empty-sequence()
    ITEM_TYPE,                // item()
    ATOMIC_OR_UNION_TYPE,     // AtomicOrUnionType
    FUNCTION_TYPE,            // function(*) and subtypes
    STRUCTURED_ITEM_TYPE,     // structured-item()
    NODE_TYPE,                // node()
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
    QUANT_STAR,
    QUANT_PLUS,
    QUANT_INVALID
  } Quantifier;


 public:
  /**
   * \brief Create an empty-sequence() type
   */
  static SequenceType createEmptyType();

  /**
   * \brief Create an item() type with quantifier
   */
  static SequenceType createItemType(Quantifier q = QUANT_ONE);

  /**
   * \brief Create an AtomicOrUnion type with quantifier
   *
   * An AtomicOrUnion type is specified simply as a QName, which may identify
   * an XMLSchema builtin atomic type or a user-defined atomic or union type.
   * In the case of user-defined types, the QName must be among the in-scope
   * type names of a given static context. Otherwise, for builtin types, the
   * given sctx may be NULL.
   */
  static SequenceType createAtomicOrUnionType(
      const StaticContext_t& sctx,
      const String& uri,
      const String& localName,
      Quantifier q = QUANT_ONE);

  /**
   * \brief Create an structured-item() type with quantifier
   */
  static SequenceType createStructuredItemType(Quantifier q = QUANT_ONE);

  /**
   * \brief Create an node() type with quantifier
   */
  static SequenceType createAnyNodeType(Quantifier q = QUANT_ONE);

  /**
   * \brief Create a document-node() type or subtype with quantifier
   */
  static SequenceType createDocumentType(
      const SequenceType& contentType,
      Quantifier q = QUANT_ONE);

  /**
   * \brief Create an element() type or subtype with quantifier
   */
  static SequenceType createElementType(
      const StaticContext_t& sctx,
      const String& nodeUri,
      const String& nodeLocalName,
      const String& contentTypeUri,
      const String& contentTypeLocalName,
      bool nillable,
      Quantifier quant = QUANT_ONE);

  static SequenceType createSchemaElementType(
      const StaticContext_t& sctx,
      const String& uri,
      const String& localName,
      Quantifier quant = QUANT_ONE);
  
  static SequenceType createAttributeType(
      const StaticContext_t& sctx,
      const String& nodeUri,
      const String& nodeLocalName,
      const String& contentTypeUri,
      const String& contentTypeLocalName,
      Quantifier quant = QUANT_ONE);

  static SequenceType createSchemaAttributeType(
      const StaticContext_t& sctx,
      const String& uri,
      const String& localName,
      Quantifier quant = QUANT_ONE);
  
  static SequenceType createPIType(Quantifier q = QUANT_ONE);

  static SequenceType createTextType(Quantifier q = QUANT_ONE);

  static SequenceType createCommentType(Quantifier q = QUANT_ONE);

  static SequenceType createNamespaceType(Quantifier q = QUANT_ONE);

  static SequenceType createJSONItemType(Quantifier q = QUANT_ONE);

  static SequenceType createJSONObjectType(Quantifier q = QUANT_ONE);

  static SequenceType createJSONArrayType(Quantifier q = QUANT_ONE);

 public:
  SequenceType();

  SequenceType(const SequenceType& other);

  /**
   * \brief Destructor
   */
  ~SequenceType();

  bool isValid() const;

  Kind getKind() const;

  Quantifier getQuantifier() const;

  String getTypeUri() const;

  String getTypeLocalName() const;

  String getNodeUri() const;

  String getNodeLocalName() const;

  bool isWildcard() const;

  String getContentTypeUri() const;

  String getContentTypeLocalName() const;

  bool isSchemaTest() const;

  std::ostream& emit(std::ostream&) const;

 private:
  SequenceType(const XQType* t);

 public:
  static char const *const kind_string_of[];

  static char const *const quantifier_string_of[];

 private:
  friend class Unmarshaller;

  const XQType  * theType;
};
  

} /* namespace zorba */

namespace std 
{

ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType& ti);

ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType::Kind k);
ZORBA_DLL_PUBLIC ostream& operator<<(ostream& o, const zorba::SequenceType::Quantifier q);

}

#endif /* ZORBA_TYPES_TYPEIDENT_H */
/* vim:set et sw=2 ts=2: */
