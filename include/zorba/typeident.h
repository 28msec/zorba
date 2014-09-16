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
    DOCUMENT_TYPE,            // document-node() and subtypes
    ELEMENT_TYPE,             // element() and subtypes
    SCHEMA_ELEMENT_TYPE,      // schema-element() and subtypes
    ATTRIBUTE_TYPE,           // attribute() and subtypes
    SCHEMA_ATTRIBUTE_TYPE,    // schema-attribute() and subtypes
    PI_TYPE,                  // processing-instruction() and subtypes
    TEXT_TYPE,                // text()
    COMMENT_TYPE,             // comment()
    NAMESPACE_TYPE,           // namespace-node()
    JSON_ITEM_TYPE,           // json-item()
    JSON_OBJECT_TYPE,         // object()
    JSON_ARRAY_TYPE,          // array()
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
   * \brief Create a generalized atomic type (see
   * http://www.w3.org/TR/xquery-30/#dt-generalized-atomic-type ) with quantifier
   *
   * A generalized atomic type is specified simply as a QName, which may identify
   * an XMLSchema builtin atomic type or a user-defined atomic or pure union type.
   * In the case of user-defined types, the QName must be among the in-scope
   * type names of a given static context. Otherwise, for builtin types, the
   * given sctx may be NULL.
   *
   * If the given QName (uri and local name pair) does not specify a generalized
   * atomic type among the in-scope type names of a given static context, an
   * invalid SequenceType is returned.
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

#ifndef ZORBA_NO_FULL_TEXT
  /**
   *
   */
  static SequenceType createSchemaElementType(
      const StaticContext_t& sctx,
      const String& uri,
      const String& localName,
      Quantifier quant = QUANT_ONE);
#endif
  
  /**
   *
   */
  static SequenceType createAttributeType(
      const StaticContext_t& sctx,
      const String& nodeUri,
      const String& nodeLocalName,
      const String& contentTypeUri,
      const String& contentTypeLocalName,
      Quantifier quant = QUANT_ONE);

#ifndef ZORBA_NO_FULL_TEXT
  /**
   *
   */
  static SequenceType createSchemaAttributeType(
      const StaticContext_t& sctx,
      const String& uri,
      const String& localName,
      Quantifier quant = QUANT_ONE);
  
#endif
  /**
   *
   */
  static SequenceType createPIType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createTextType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createCommentType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createNamespaceType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createJSONItemType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createJSONObjectType(Quantifier q = QUANT_ONE);

  /**
   *
   */
  static SequenceType createJSONArrayType(Quantifier q = QUANT_ONE);

 public:
  /**
   * Constructor for an invalid (NULL) type.
   */
  SequenceType();

  /**
   * Copy constructor
   */
  SequenceType(const SequenceType& other);

  /**
   * \brief Destructor
   */
  ~SequenceType();

  /**
   * Returns true if this a valid (non-NULL) type; otherwise, returns false.
   */
  bool isValid() const;

  /**
   *
   */
  Kind getKind() const;

  /**
   *
   */
  Quantifier getQuantifier() const;

  /**
   * If this is a generalized atomic type, this method returns the URI of
   * the type name. For other kinds of types, an empty string is returned.
   */
  String getTypeUri() const;

  /**
   * If this is a generalized atomic type, this method returns the local part of
   * the type name. For other kinds of types, an empty string is returned.
   */
  String getTypeLocalName() const;

  /**
   * If this is an element() or attribute() type that contains a NodeName,
   * this method returns the URI of that NodeName. If this is a schema-element(N)
   * or schema-attribute(N) type, the method returns the URI of N. In all other
   * cases, an empty string is returned.
   */
  String getNodeUri() const;

  /**
   * If this is an element() or attribute() type that contains a NodeName,
   * this method returns the local part of that NodeName. If this is a
   * schema-element(N) or schema-attribute(N) type, the method returns the
   * local part of N. If this is a processing-instruction() that contains a
   * TargetName, that TargetName is returned. In all other cases, an empty
   * string is returned.
   */
  String getNodeLocalName() const;

  /**
   * If this is an element() or attribute() type that does not contain a
   * NodeName, this method returns true. In all other cases, false is returned.
   */
  bool isWildcard() const;

  /**
   * If this is an document-node() type that contains an embedded element()
   * type, this method returns the embedded element() type. In all other cases,
   * an invalid SequenceType is returned.
   */
  SequenceType getContentType() const;

  /**
   * If this is an element() or attribute() type that contains a TypeName, this
   * method returns the URI of that TypeName. If this is a schema-element(N) or
   * schema-attribute(N) type, the method returns the URI of the XMLSchema type
   * associated with the global element or attribute declaration N. In all other
   * cases, it returns an empty string.
   */
  String getContentTypeUri() const;

  /**
   * If this is an element() or attribute() type that contains a TypeName, this
   * method returns the local name of that TypeName. If this is a schema-element(N)
   * or schema-attribute(N) type, the method returns the local name of the
   * XMLSchema type associated with the global element or attribute declaration N.
   * In all other cases, it returns an empty string.
   */
  String getContentTypeLocalName() const;

  /**
   * Return true if this type is a schema-element() or schema-attribute() type,
   * Otherwise return false.
   */
  bool isSchemaTest() const;

  /**
   *
   */
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
