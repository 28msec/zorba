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
#pragma once
#ifndef ZORBA_TYPEIMPL_H
#define ZORBA_TYPEIMPL_H

#include <cassert>

#include "common/shared_types.h"

#include "types/node_test.h"
#include "types/typeconstants.h"
#include "types/typemanager.h"

#include "zorbatypes/rchandle.h"

#include "store/api/item_handle.h"
#include "store/api/item.h"

#include "system/globalenv.h"

#include "zorbaserialization/class_serializer.h"

namespace zorba
{


/***************************************************************************//**

  Class XQType and its subtypes implement xquery's SequenceType spec as well as
  XMLSchema types.

  ***************
  SequenceTypes:
  ***************

  SequenceType ::= ("empty-sequence" "(" ")") | (ItemType OccurrenceIndicator?)

  ItemType ::= KindTest
      | ("item" "(" ")")
      | AtomicType
      | JSONTest
      | StructuredItemTest
      | FunctionTest

  OccurrenceIndicator ::= "?" | "*" | "+"

  AtomicType ::= QName (** may be built-in or user-defined **)

  KindTest ::= DocumentTest |
               ElementTest |
               AttributeTest |
               SchemaElementTest |
               SchemaAttributeTest |
               PITest |
               CommentTest |
               TextTest |
               AnyKindTest

  DocumentTest ::= "document-node" "(" (ElementTest | SchemaElementTest)? ")"

  ElementTest ::= "element" "(" (ElementNameOrWildcard ("," TypeName "?"?)?)? ")"

  SchemaElementTest ::= "schema-element" "(" ElementDeclaration ")"

  ElementNameOrWildcard ::= ElementName | "*"

  ElementDeclaration ::= ElementName

  ElementName ::= QName

  AttributeTest ::= "attribute" "(" (AttribNameOrWildcard ("," TypeName)?)? ")"

  SchemaAttributeTest ::= "schema-attribute" "(" AttributeDeclaration ")"

  AttributeDeclaration ::= AttributeName

  AttribNameOrWildcard ::= AttributeName | "*"

  AttributeName ::= QName

  TypeName ::= QName (** may be built-in or user-defined, simple or complex **)

  PITest ::= "processing-instruction" "(" (NCName | StringLiteral)? ")"

  CommentTest ::= "comment" "(" ")"

  TextTest ::= "text" "(" ")"

  AnyKindTest ::= "node" "(" ")"

  JSONTest ::= JSONItemTest |
               JSONObjectTest |
               JSONArrayTest

  JSONItemTest ::= "json-item" "(" ")"

  JSONObjectTest ::= "object" "(" ")"

  JSONArrayTest ::= "array" "(" ItemType? ")"
  
  StructuredItemTest ::= "structured-item" "(" ")"

  FunctionTest ::= Annotation* (AnyFunctionTest | TypedFunctionTest)

  AnyFunctionTest ::= "function" "(" "*" ")"

  TypedFunctionTest ::= "function" "(" (SequenceType ("," SequenceType)*)? ")"
                        "as" SequenceType

  ******************
  XML Schema Types:
  ******************

  XML Schema Type Dichotomies:

  1. Built-in vs. user-derived datatypes
  2. Primitive vs. derived datatypes
  3. Atomic vs. list vs. union datatypes
  4. Simple vs. complex.

  1. Built-in datatypes are those which are defined in XMLSchema specification.
     They are all simple types (no complex built-in types).
     They can be either atomic or list (no union built-in types).
     They can be either primitive or derived.

     User-derived datatypes are those derived datatypes that are defined by
     individual schema designers. They are always derived. They can be atomic,
     list, or union, and simple or complex.

  2. Primitive datatypes are those that are not defined in terms of other
     datatypes; they exist ab initio. Primitive types are always atomic and
     built-in.

     Derived datatypes are those that are defined in terms of other datatypes.
     They may be built-in or user-defined, atomic, list, or union, and simple
     or complex.

     Notes:

     Every xml schema type T, except from xs:AnyType has a "baseType" P, which
     is the parent of T in the type hierarchy. This is true even for primitive
     types: their baseType is xs:anyAtomicType.

     If T is a type derived from another type D and its base type is P, then D
     and P may or may not be the same type. For example, list types are derived
     from their "itemType" (see below), but their "baseType" is always the
     xs:anySimpleType.

  3. Atomic datatypes are those having values which are regarded as being
     indivisible. Atomic datatypes can be built-in or user-defined, and
     primitive or derived. They are always simple types.

     A list datatype is derived from an atomic or a union datatype, known as
     the "itemType" of the list datatype. This yields a datatype whose value
     space is composed of finite-length sequences of values from the value
     space of the itemType. List types may be built-in or user-defined. They
     are always derived and simple types.

     A union datatype is derived from one or more atomic, list or other union
     datatypes, known as the "memberTypes" of that union datatype. The value
     space of a union datatype is the union of the value spaces memberTypes.
     Union types are always user-defined, derived, simple types.

  4. Simple types are all the types that are atomic, list, or union types.
     Everything else is complex types. Complex types are used to describe
     the internal structure of element or document nodes that contain other
     elements and/or attributes.

  XMLSchema allows anonymous types, but XQuery Data Model requires that all
  XMLSchema types have a name, which is a qname and uniquely identifies the
  type among all types in the "database" and the in-scope schema definitions.


  *******************************************************
  The intersection of SequenceTypes and XMLSchema types:
  *******************************************************

  Atomic types represent the intersection between the categories of sequence type
  and xml schema type. An atomic type, such as xs:integer or my:hatsize, is both a
  sequence type and a schema type.


  **********************************************
  Zorba Built-in types (see root_typemanager.h):
  **********************************************

  We preallocate XQType objs for the following sequence types:

  - The empty-sequence()

  - XML Data Mode and XMLSchema both define 45 atomic, built-in types (including
    xs:anyAtomicType and xs:untypedAtomic). For each such atomic type T, we
    preallocate 4 XQType objs representing the sequence tyoes T, T?, T*, and T+.

  - item(), item()?, item()+, item()*

  - N(), N()?, N()+, N()*, where N is one of node, document-node, text, comment,
    or processing-instruction.

  - N(xs:untyped), N(xs:untyped)?, N(xs:untyped)+, N(xs:untyped)*, where N is
    one of "node" or "document-node". Note that these types are not really
    expressible via the SequenceType syntax, but we include them in zorba
    because they are convenient for certain type-related optimizations.

  - element(*, xs:anyType), element(*, xs:anyType)?, element(*, xs:anyType)+,
    element(*, xs:anyType)*

  - element(*, xs:untyped), element(*, xs:untyped)?, element(*, xs:untyped)+,
    element(*, xs:untyped)*

  - attribute(*, xs:anySimpleType), attribute(*, xs:anySimpleType)?,
    attribute(*, xs:anySimpleType)+, attribute(*, xs:anySimpleType)*

  - attribute(*, xs:untypedAtomic), attribute(*, xs:untypedAtomic)?,
    attribute(*, xs:untypedAtomic)+, attribute(*, xs:untypedAtomic)*
    
  - structured-item(), structured-item()?,
    structured-item()+, structured-item()*

  We also preallocate XQType objs for the following XML-Schema types:

  - xs:anyType, xs:anySimpleType, and xs:untyped

  - xs:NMTOKENS, xs:IDREFS, and xs:ENTITIES

  - The none type


  *********************
  XQType Data Members:
  *********************

  theManager:
  -----------
  XQType instances are created via methods provided by TypeManager and its
  subclasses. m_manager is a pointer back to the specific TypeManager that
  created this XQType.

  theKind:
  --------
  The "kind" of this type. One "kind" per each concrete subclass of XQType.
  See TypeKind enum below

  theQuantifier:
  --------------
  The quantifier of this type.

  theIsBuiltin:
  -------------
  Whether the type is built-in or not. For built-in types refernce counting based
  garbage collection does not apply; these types are deleted when the root 
  TypeManager is deleted during engine shutdown.

********************************************************************************/
class XQType : public serialization::SerializeBaseClass
{
public:
  //
  // TypeKind contains one enum code for each concrete subclass of XQType
  //
  // ATTENTION !!!! The order of the enum values is important because they are
  // used as indexes into the KIND_STRINGS array !!!!
  //
  typedef enum
  {
    NONE_KIND = 0,           // special kind of "type" defined by the formal
                             // semantics. it represents the absence of type.
                             // for example, the static type of the fn:error
                             // function is "none". (quantifier = 1)

    EMPTY_KIND = 1,              // empty-sequence() (quantifier = ?)

    ITEM_KIND = 2,               // item() + quantifier

    ATOMIC_TYPE_KIND = 3,        // atomic, built-in type + quantifier

    STRUCTURED_ITEM_KIND = 4,    // structured-item() + quantifier

    NODE_TYPE_KIND = 5,          // KindTest + quantifier

    JSON_TYPE_KIND = 6,          // JSONTest + quantifier

    FUNCTION_TYPE_KIND = 7,      // function(...) as ... + quantifier

    ANY_TYPE_KIND = 8,           // xs:anyType (quantifier = *)

    ANY_SIMPLE_TYPE_KIND = 9,    // xs:anySimpleType (quantifier = *)

    ANY_FUNCTION_TYPE_KIND = 10, // function(*)

    UNTYPED_KIND = 11,           // xs:untyped (quantifier = *)

    USER_DEFINED_KIND = 12,      // Named, user-defined XMLSchema type (may be atomic,
                                 // list, union, or complex) + quantifier

    MAX_TYPE_KIND
  } TypeKind;


  //
  // The kind of a UDT: atomic, union, list, or complex
  //
  enum UDTKind
  {
    ATOMIC_UDT,
    LIST_UDT,  
    UNION_UDT, 
    COMPLEX_UDT
  };

  //
  // The content kind of a complex type
  //
  typedef enum
  {
    MIXED_CONTENT_KIND,         // any kind of children nodes
    ELEMENT_ONLY_CONTENT_KIND,  // no text nodes as children
    SIMPLE_CONTENT_KIND,        // no element nodes as children
    EMPTY_CONTENT_KIND,         // empty (no children at all)
  } content_kind_t;


  static std::string contentKindStr(XQType::content_kind_t contentKind);

protected:
  static const char         * KIND_STRINGS[XQType::MAX_TYPE_KIND];

  mutable long                   theRefCount;

  TypeManager                  * theManager;
  TypeKind                       theKind;
  SequenceType::Quantifier       theQuantifier;
  bool                           theIsBuiltin;

public:
  SERIALIZABLE_ABSTRACT_CLASS(XQType)

  XQType(::zorba::serialization::Archiver& ar)
    :
    serialization::SerializeBaseClass(),
    theRefCount(0),
    theIsBuiltin(false)
  {
  }

  void serialize(::zorba::serialization::Archiver& ar);

public:
  long getRefCount() const
  {
    return theRefCount;
  }

  void addReference() const
  {
    if (!theIsBuiltin)
      ++theRefCount;
  }

  void removeReference() 
  {
    if (!theIsBuiltin)
    {
      assert(getRefCount() > 0);

      if (--theRefCount == 0)
        delete this;
    }
  }

public:
  virtual ~XQType();

  TypeManager* get_manager() const { return theManager; }

  TypeKind type_kind() const { return theKind; }

  SequenceType::Quantifier get_quantifier() const { return theQuantifier; }

  bool is_builtin() const { return theIsBuiltin; }

  bool is_empty() const { return theKind == XQType::EMPTY_KIND; }

  bool is_none() const { return theKind == XQType::NONE_KIND; }

  int max_card() const;
  
  int min_card() const;

  int card() const;

  store::Item_t getQName() const;

  bool isAnonymous() const;

  bool isComplex() const;

  bool isList() const;

  bool isUnion() const;

  bool isGenAtomicAny() const;

  bool isGenAtomicOne() const;

  bool isAtomicAny() const;

  bool isAtomicOne() const;

  bool isBuiltinAtomicAny() const;

  bool isBuiltinAtomicOne() const;

  content_kind_t contentKind() const;

  virtual xqtref_t getBaseBuiltinType() const { return this; }

  virtual std::ostream& serialize_ostream(std::ostream& os) const;

  std::string toString() const;

  std::string toSchemaString() const;

protected:
  XQType(
      const TypeManager* mgr,
      TypeKind kind,
      SequenceType::Quantifier quant,
      bool builtin);

private:
  XQType& operator=(const XQType& t);
};


/***************************************************************************//**
  NONE is a special sequence "type" defined by the formal semantics. It 
  represents the "absence" of type. For example, the static type of the fn:error
  function is "none". 

  NONE type has quantifier ONE
  NONE type is considered a subtype of every other type.
********************************************************************************/
class NoneXQType : public XQType
{
public:
  NoneXQType(const TypeManager* manager, bool builtin);

 public:
  SERIALIZABLE_CLASS(NoneXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NoneXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/***************************************************************************//**
  Represents the empty sequence
********************************************************************************/
class EmptyXQType : public XQType
{
public:
  EmptyXQType(const TypeManager* manager, bool builtin);

 public:
  SERIALIZABLE_CLASS(EmptyXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(EmptyXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/******************************************************************************
  Class ItemXQType represents sequence types item(), item()?, item()*, or item()+
*******************************************************************************/
class ItemXQType : public XQType
{
public:
  ItemXQType(
      const TypeManager* tm,
      SequenceType::Quantifier q,
      bool builtin);

 public:
  SERIALIZABLE_CLASS(ItemXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ItemXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/***************************************************************************//**
  Class AtomicXQType represents all the sequence types whose ItemType is one
  of the 45 XQDM builtin atomic types.
********************************************************************************/
class AtomicXQType : public XQType
{
  friend class XQType;

public:
   static const char* ATOMIC_TYPE_CODE_STRINGS[store::XS_LAST];

private:
   store::SchemaTypeCode theAtomicCode;

public:
  SERIALIZABLE_CLASS(AtomicXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AtomicXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  AtomicXQType(
      const TypeManager* manager,
      store::SchemaTypeCode code,
      SequenceType::Quantifier quant,
      bool builtin)
    :
    XQType(manager, ATOMIC_TYPE_KIND, quant, builtin),
    theAtomicCode(code)
  {
  }

  store::SchemaTypeCode get_type_code() const { return theAtomicCode; }

  virtual std::ostream& serialize_ostream(std::ostream& os) const;
};


/******************************************************************************
  Class StructuredItemXQType represents sequence types structured-item(), 
  structured-item()?, structured-item()*, or structured-item()+
*******************************************************************************/
class StructuredItemXQType : public XQType
{
public:
  StructuredItemXQType(
      const TypeManager* tm,
      SequenceType::Quantifier quant,
      bool builtin);

 public:
  SERIALIZABLE_CLASS(StructuredItemXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(StructuredItemXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/***************************************************************************//**
  Class JSONXQType represents all the sequence types whose ItemType is a
  JSONTest.
********************************************************************************/
class JSONXQType : public XQType
{
private:
  store::StoreConsts::JSONItemKind  theJSONKind;

public:
  SERIALIZABLE_CLASS(JSONXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(JSONXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  JSONXQType(
      const TypeManager* manager,
      store::StoreConsts::JSONItemKind kind,
      SequenceType::Quantifier quantifier,
      bool builtin);

  store::StoreConsts::JSONItemKind get_json_kind() const { return theJSONKind; }

  std::ostream& serialize_ostream(std::ostream& os) const;
};


/***************************************************************************//**
  Class NodeXQType represents all the sequence types whose ItemType is a
  KindTest.
********************************************************************************/
class NodeXQType : public XQType
{
  friend class XQType;

private:
  store::StoreConsts::NodeKind  theNodeKind;
  store::Item_t                 theNodeName;
  xqtref_t                      theContentType;
  bool                          theNillable;
  bool                          theIsSchemaTest;

public:
  SERIALIZABLE_CLASS(NodeXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NodeXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  NodeXQType(
      const TypeManager* manager,
      store::StoreConsts::NodeKind nodeKind,
      const store::Item_t& nodeName,
      const xqtref_t& contentType,
      SequenceType::Quantifier quantifier,
      bool nillable,
      bool schematest,
      bool builtin);

  NodeXQType(const NodeXQType& source, SequenceType::Quantifier q, bool builtin);

  store::StoreConsts::NodeKind get_node_kind() const { return theNodeKind; }

  store::Item* get_node_name() const { return theNodeName.getp(); }

  bool is_schema_test() const { return theIsSchemaTest; }

  const XQType* get_content_type() const { return theContentType.getp(); }

  bool get_nillable() const { return theNillable; }

  bool is_untyped() const;

  bool is_equal(const TypeManager* tm, const NodeXQType& supertype) const;

  bool is_subtype(
      const TypeManager* tm,
      const NodeXQType& supertype,
      const QueryLoc& loc) const;

  bool is_supertype(
      const TypeManager* tm,
      const store::Item* subitem,
      const QueryLoc& loc) const;

  virtual std::ostream& serialize_ostream(std::ostream& os) const;

protected:
  std::string toSchemaStringInternal() const;
};


/******************************************************************************
  function(*)
*******************************************************************************/
class AnyFunctionXQType : public XQType
{
public:
  AnyFunctionXQType(const TypeManager* manager, bool builtin)
    :
    XQType(manager, ANY_FUNCTION_TYPE_KIND, SequenceType::QUANT_STAR, builtin)
  {
  }

  AnyFunctionXQType(
      const TypeManager* manager,
      SequenceType::Quantifier quantifier,
      bool builtin)
    :
    XQType(manager, ANY_FUNCTION_TYPE_KIND, quantifier, builtin)
  {
  }

 public:
  SERIALIZABLE_CLASS(AnyFunctionXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnyFunctionXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/***************************************************************************//**
  Class FunctionXQType represents all the sequence types whose ItemType is a
  FunctionType.
********************************************************************************/
class FunctionXQType : public XQType
{
private:
  std::vector<xqtref_t>   m_param_types;
  xqtref_t                m_return_type;

public:
  SERIALIZABLE_CLASS(FunctionXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(FunctionXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  FunctionXQType(
        const TypeManager* manager,
        const std::vector<xqtref_t>& aParamTypes,
        const xqtref_t& aReturnType,
        SequenceType::Quantifier quantifier,
        bool builtin);

  const std::vector<xqtref_t>&
  get_param_types() const { return m_param_types; }

  const xqtref_t& operator[](size_t i) const { return m_param_types[i]; }

  size_t get_number_params() const { return m_param_types.size(); }

  xqtref_t get_return_type() const { return m_return_type; }

  bool is_equal(const TypeManager* tm, const FunctionXQType& supertype) const;

  bool is_subtype(
      const TypeManager* tm,
      const FunctionXQType& supertype,
      bool ignoreReturnType = false) const;

  virtual std::ostream& serialize_ostream(std::ostream& os) const;
};


/***************************************************************************//**
  Represents :

  (a) a XMLSchema user-defined type that describes the content of an element
      or attribute node, or
  (b) a sequence type whose ItemType is a user0defined atomic type.

  Note: For list types, the associated quantifier is always STAR. For user-
  defined atomic types, the associated quantifier can be anything. For all
  other user-defined types, associated quantifier must be ONE.
 
  teQName:
  --------
  The name of this user-defined type. The actual type definition is stored in
  the TypeManger that created this type (and is pointed to my theManager). The
  TypeManager also stores the mapping from the type name to the type definition.

  theBaseType:
  ------------
  The baseType of this type. NULL for list or union types.

  theUDTKind:
  -----------
  Whether this is an atomic, list, union, or complex type.

  theContentKind:
  ---------------
  This type's content kind, if this is a complex type. One of empty, simple,
  element-only, or mixed.

  m_listItemType:
  ---------------
  This type's itemType, if this is a list type.

  m_unionItemTypes:
  -----------------
  This type's memberTypes, if this is a union type.
********************************************************************************/
class UserDefinedXQType : public XQType
{
  friend class XQType;

public:


private:
  bool                    theIsAnonymous;

  store::Item_t           theQName;

  xqtref_t                theBaseType;

  UDTKind                 theUDTKind;

  content_kind_t          theContentKind;

  std::vector<xqtref_t>   m_unionItemTypes;

  xqtref_t                m_listItemType;

public:
  static std::string decodeUDTKind(UDTKind typeCategory);

public:
  SERIALIZABLE_CLASS(UserDefinedXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(UserDefinedXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);

public:
  // constructor for Atomic and Complex types
  UserDefinedXQType(
      const TypeManager* manager,
      bool isAnonymous,
      store::Item_t qname,
      const xqtref_t& baseType,
      SequenceType::Quantifier quantifier,
      UDTKind typeCategory,
      content_kind_t contentKind,
      bool builtin);

  // Constructor for List types
  UserDefinedXQType(
      const TypeManager* manager,
      bool isAnonymous,
      store::Item_t qname,
      const xqtref_t& baseType,
      const XQType* listItemType,
      bool builtin);

  // Constructor for Union types
  UserDefinedXQType(
      const TypeManager* manager,
      bool isAnonymous,
      store::Item_t qname,
      const xqtref_t& baseType,
      SequenceType::Quantifier quantifier,
      const std::vector<xqtref_t>& unionItemTypes,
      bool builtin);

  virtual ~UserDefinedXQType() {}

  UDTKind getUDTKind() const { return theUDTKind; }

  xqtref_t getBaseType() const { return theBaseType; }

  xqtref_t getBaseBuiltinType() const;

  const XQType* getListItemType() const { return m_listItemType.getp(); }

  const std::vector<xqtref_t>& getUnionItemTypes() const { return m_unionItemTypes; }

  bool isSuperTypeOf(
      const TypeManager* tm,
      const XQType* subType,
      const QueryLoc& loc) const;

  bool isSubTypeOf(const TypeManager* tm, const XQType& superType) const;

  virtual std::ostream& serialize_ostream(std::ostream& os) const;
};


/******************************************************************************
  xs:anyType
*******************************************************************************/
class AnyXQType : public XQType
{
public:
  AnyXQType(const TypeManager* manager, bool builtin)
    :
    XQType(manager, ANY_TYPE_KIND, SequenceType::QUANT_STAR, builtin)
  {
  }

 public:
  SERIALIZABLE_CLASS(AnyXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnyXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/***************************************************************************//**
  xs:untyped
********************************************************************************/
class UntypedXQType : public XQType
{
public:
  UntypedXQType(const TypeManager* manager, bool builtin)
    :
    XQType(manager, UNTYPED_KIND, SequenceType::QUANT_STAR, builtin)
  {
  }

 public:
  SERIALIZABLE_CLASS(UntypedXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(UntypedXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


/******************************************************************************
  xs:anySimpleType
*******************************************************************************/
class AnySimpleXQType : public XQType
{
public:
  AnySimpleXQType(const TypeManager* manager, bool builtin)
    :
    XQType(manager, ANY_SIMPLE_TYPE_KIND, SequenceType::QUANT_STAR, builtin)
  {
  }

public:
  SERIALIZABLE_CLASS(AnySimpleXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnySimpleXQType, XQType)
  void serialize(::zorba::serialization::Archiver& ar);
};


}

#endif /* ZORBA_TYPEIMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
/* vim:set et sw=2 ts=2: */
