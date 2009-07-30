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
#ifndef ZORBA_TYPEIMPL_H
#define ZORBA_TYPEIMPL_H

#include "common/shared_types.h"
#include "types/node_test.h"
#include "types/typeconstants.h"
#include "zorbatypes/rchandle.h"
#include "store/api/item.h"
#include "types/typemanager.h"

#include "system/globalenv.h"
#include "zorbaserialization/serialization_engine.h"

namespace zorba {


/***************************************************************************//**

  Class XQType and its subtypes implement xquery's SequenceType spec as well as
  XMLSchema types.

  ***************
  SequenceTypes:
  ***************

  SequenceType ::= ("empty-sequence" "(" ")") | (ItemType OccurrenceIndicator?)

  ItemType ::= KindTest | ("item" "(" ")") | AtomicType

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


  ******************
  XML Schema Types:
  ******************

  XML Schema Type Dichotomies:

  1. Built-in vs. user-derived datatypes
  2. Primitive vs. derived datatypes
  3. Atomic vs. list vs. union datatypes
  4. Simple vs. complex.

  1. Built-in datatypes are those which are defined in XMLSchema specification.
     They can be either primitive or derived. 
     They can be either atomic or list.
     There are no union built-in types.
     There are no complex built-in types.

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

     If T is a type derived from another type D and it base type is P, then D
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

  - xs:anyType*, xs:anySimpleType*, and xs:untyped*

  - XML Data Mode and XMLSchema both define 45 atomic, built-in types (including
    xs:anyAtomicType and xs:untypedAtomic). For each such atomic type T, we 
    preallocate 4 XQType objs representing the sequence tyoes T, T?, T*, and T+.

  - item(), item()?, item()+, item()*

  - N(), N()?, N()+, N()*, where N is one of node, document-node, text, comment,
    or processing-instruction.

  - N(xs:untyped), N(xs:untyped)?, N(xs:untyped)+, N(xs:untyped)*, where N is
    one of node or document. Note that these types are not really expressible
    via the SequenceType syntax, but we include them in zorba because they are
    convenient for certain type-related optimizations.

  - element(*, xs:anyType), element(*, xs:anyType)?, element(*, xs:anyType)+,
    element(*, xs:anyType)*

  - element(*, xs:untyped), element(*, xs:untyped)?, element(*, xs:untyped)+,
    element(*, xs:untyped)*

  - attribute(*, xs:anySimpleType), attribute(*, xs:anySimpleType)?,
    attribute(*, xs:anySimpleType)+, attribute(*, xs:anySimpleType)*

  - attribute(*, xs:untypedAtomic), attribute(*, xs:untypedAtomic)?,
    attribute(*, xs:untypedAtomic)+, attribute(*, xs:untypedAtomic)*

  - The none type


  *********************
  XQType Data Members:
  *********************

  m_manager    : XQType instances are created via methods provided by TypeManager
                 and its subclasses. m_manager is a pointer back to the specific
                 TypeManager that created this XQType. 
  m_type_kind  : The "kind" of this type. One "kind" per each concrete subclass
                 of XQType. See type_kind_t enum below
  m_quantifier : The quantifier of this type.
  theIsBuiltin : Whether the type is built-in or not. For built-in types refernce
                 counting based garbage collection does not apply; these types
                 are deleted when the root TypeManager is deleted during engine
                 shutdown.

********************************************************************************/
class XQType : public SimpleRCObject
{
public:
  //
  // type_kind_t contains one enum code for each concrete subclass of XQType
  //
  typedef enum 
  {
    EMPTY_KIND,            // empty-sequence() (quanttifier = ?)

    ATOMIC_TYPE_KIND,      // atomic, built-in type + quantifier

    ITEM_KIND,             // item() + quantifier

    NODE_TYPE_KIND,        // KindTest + quantifier

    ANY_TYPE_KIND,         // xs:anyType (quanttifier = *)

    ANY_SIMPLE_TYPE_KIND,  // xs:anySimpleType (quanttifier = *)

    UNTYPED_KIND,          // xs:untyped (quanttifier = *)

    NONE_KIND,             // special kind of "type" defined by the formal
                           // semantics. it represents the absence of type.
                           // for example, the static type of the fn:error
                           // function is "none". (quanttifier = 1)

    USER_DEFINED_KIND,     // Named, user-defined XMLSchema type (may be atomic,
                           // list, union, or complex) + quantifier

    MAX_TYPE_KIND
  } type_kind_t;

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


protected:
  static const char            * KIND_STRINGS[XQType::MAX_TYPE_KIND];

  /*const*/ TypeManager        * m_manager;
  /*const*/ type_kind_t          m_type_kind;
  TypeConstants::quantifier_t    m_quantifier;
  bool                           theIsBuiltin;


public:
  SERIALIZABLE_ABSTRACT_CLASS(XQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(XQType, SimpleRCObject)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    //serialize_baseclass(ar, (SimpleRCObject*)this);
    SERIALIZE_TYPEMANAGER(TypeManager, m_manager);
    SERIALIZE_ENUM(type_kind_t, m_type_kind)
    SERIALIZE_ENUM(TypeConstants::quantifier_t, m_quantifier);
    ar & theIsBuiltin;
  }

public:
  virtual ~XQType() { }

  void free() 
  {
    if (!theIsBuiltin)
      delete this;
  }

  const TypeManager* get_manager() const { return m_manager; }

  type_kind_t type_kind() const { return m_type_kind; }

  TypeConstants::quantifier_t get_quantifier() const { return m_quantifier; }

  bool is_builtin() const { return theIsBuiltin; }

  virtual content_kind_t content_kind() const { return MIXED_CONTENT_KIND; };

  virtual store::Item_t get_qname() const { return NULL; }

  bool get_isBuiltin() const { return theIsBuiltin; }
  virtual std::ostream& serialize_ostream(std::ostream& os) const;

  virtual std::string toString() const;

protected:
  XQType(
        const TypeManager* manager,
         type_kind_t type_kind,
         TypeConstants::quantifier_t quantifier,
         bool builtin)
    :
    m_manager((TypeManager*)manager),
    m_type_kind(type_kind),
    m_quantifier(quantifier),
    theIsBuiltin(builtin)
  {
    if(theIsBuiltin)
    {//register this hardcoded object to help plan serialization
      XQType  *this_ptr = this;
      *::zorba::serialization::ClassSerializer::getInstance()->getArchiverForHardcodedObjects() & this_ptr;
    }
  }
};


/***************************************************************************//**
  Class AtomicXQType represents all the sequence types whose ItemType is one
  of the 45 XQDM builtin atomic types.
********************************************************************************/
class AtomicXQType : public XQType
{
public:
   static const char* ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];

private:
   TypeConstants::atomic_type_code_t m_type_code;

public:
  SERIALIZABLE_CLASS(AtomicXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AtomicXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
    SERIALIZE_ENUM(TypeConstants::atomic_type_code_t, m_type_code);
  }
public:
   AtomicXQType(
        const TypeManager *manager,
        TypeConstants::atomic_type_code_t type_code,
        TypeConstants::quantifier_t quantifier,
        bool builtin = false)
     :
     XQType(manager, ATOMIC_TYPE_KIND, quantifier, builtin),
     m_type_code(type_code)
   {
   }

   TypeConstants::atomic_type_code_t get_type_code() const { return m_type_code; }

   content_kind_t content_kind() const { return SIMPLE_CONTENT_KIND; };

  store::Item_t get_qname() const;
   virtual std::ostream& serialize_ostream(std::ostream& os) const;
};


/***************************************************************************//**
  Class NodeXQType represents all the sequence types whose ItemType is a
  KindTest.
********************************************************************************/
class NodeXQType : public XQType
{
private:
  rchandle<NodeTest> m_nodetest;
  xqtref_t           m_content_type;
  bool               m_nillable;
  bool               m_schema_test;

 public:
  SERIALIZABLE_CLASS(NodeXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NodeXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
    ar & m_nodetest;
    ar & m_content_type;
    ar & m_nillable;
  }
public:
  NodeXQType(
        const TypeManager* manager,
        rchandle<NodeTest> nodetest,
        xqtref_t content_type,
        TypeConstants::quantifier_t quantifier,
        bool nillable,
        bool schematest,
        bool builtin = false);

  NodeXQType(
        const TypeManager* manager,
        store::StoreConsts::NodeKind nodekind,
        const store::Item* qname,
        xqtref_t content_type,
        TypeConstants::quantifier_t quantifier,
        bool nillable,
        bool schematest,
        bool builtin = false);

  NodeXQType(
        const NodeXQType& source,
        TypeConstants::quantifier_t quantifier);

  store::StoreConsts::NodeKind get_node_kind() const 
  {
    return m_nodetest->get_node_kind(); 
  }

  NodeTest* get_nodetest() const { return m_nodetest.getp(); }

  NodeNameTest* get_node_name_test() const { return m_nodetest->get_nametest(); }

  xqtref_t get_content_type() const { return m_content_type; }

  bool is_untyped() const;

  content_kind_t content_kind() const { return MIXED_CONTENT_KIND; };

  bool get_nillable() const { return m_nillable; }

  virtual std::ostream& serialize_ostream(std::ostream& os) const;
};


/***************************************************************************//**
  Class ItemXQType represents sequence types item(), item()?, item()*, or item()+
********************************************************************************/
class ItemXQType : public XQType
{
public:
  ItemXQType(
        const TypeManager* manager,
        TypeConstants::quantifier_t quantifier,
        bool builtin = false)
    :
    XQType(manager, ITEM_KIND, quantifier, builtin) 
  { 
  }
 public:
  SERIALIZABLE_CLASS(ItemXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(ItemXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**
  xs:anyType
********************************************************************************/
class AnyXQType : public XQType
{
public:
  AnyXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, ANY_TYPE_KIND, TypeConstants::QUANT_STAR, builtin) 
  {
  }

  store::Item_t get_qname() const;
 public:
  SERIALIZABLE_CLASS(AnyXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnyXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**
  xs:anySimpleType
********************************************************************************/
class AnySimpleXQType : public XQType
{
public:
  AnySimpleXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, ANY_SIMPLE_TYPE_KIND, TypeConstants::QUANT_STAR, builtin)
  { 
  }

  content_kind_t content_kind() const { return SIMPLE_CONTENT_KIND; };

  store::Item_t get_qname() const;
 public:
  SERIALIZABLE_CLASS(AnySimpleXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(AnySimpleXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**
  xs:untyped
********************************************************************************/
class UntypedXQType : public XQType
{
public:
  UntypedXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, UNTYPED_KIND, TypeConstants::QUANT_STAR, builtin)
  {
  }

  store::Item_t get_qname() const;
 public:
  SERIALIZABLE_CLASS(UntypedXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(UntypedXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**
  Represents the empty sequence
********************************************************************************/
class EmptyXQType : public XQType
{
public:
  EmptyXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, EMPTY_KIND, TypeConstants::QUANT_QUESTION, builtin) 
  { 
  }

  content_kind_t content_kind() const { return EMPTY_CONTENT_KIND; };
 public:
  SERIALIZABLE_CLASS(EmptyXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(EmptyXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**

********************************************************************************/
class NoneXQType : public XQType
{
public:
  NoneXQType(const TypeManager* manager, bool builtin = false)
    :
    XQType(manager, NONE_KIND, TypeConstants::QUANT_ONE, builtin) 
  { 
  }

  content_kind_t content_kind() const { return EMPTY_CONTENT_KIND; };
 public:
  SERIALIZABLE_CLASS(NoneXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(NoneXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
  }
};


/***************************************************************************//**
  Represents a XMLSchema user-defined type that describes the content of an
  element or attribute node.

  m_qname          : The name of this user-defined type. The actual type 
                     definition is stored in the TypeManger that created this
                     type (and is pointed to my m_manager). The TypeManager
                     also stores the mapping from the type name to the type
                     definition.
  m_base_type      : The baseType of this type. NULL for list or union types.
  m_typeCategory   : Whether this is an atomic, list, union, or complex type.
  m_contentKind    : This type's content kind, if this is a complex type. One
                     of empty, simple, element-only, or mixed.
  m_listItemType   : This type's itemType, if this is a list type. 
  m_unionItemTypes : This type's memberTypes, if this is a union type. 
********************************************************************************/
class UserDefinedXQType : public XQType
{
public:
  enum TYPE_CATEGORY
  {
    ATOMIC_TYPE,  // atomic types: ex: int, date, token, string
    LIST_TYPE,    // list of simple types: ex: list of int: "1 2 33"
    UNION_TYPE,   // union of simple types: ShirtSize int or string: "8", "small"
                  // ATOMIC, LIST and UNION types are all SIMPLE types: i.e. 
                  // their representation is a text value
    COMPLEX_TYPE  // complex types: they represent structure
  };


private:
  store::Item_t           m_qname;
  xqtref_t                m_baseType;
  TYPE_CATEGORY           m_typeCategory;
  content_kind_t          m_contentKind;
  std::vector<xqtref_t>   m_unionItemTypes;
  xqtref_t                m_listItemType;

 public:
  SERIALIZABLE_CLASS(UserDefinedXQType)
  SERIALIZABLE_CLASS_CONSTRUCTOR2(UserDefinedXQType, XQType)
  void serialize(::zorba::serialization::Archiver &ar)
  {
    serialize_baseclass(ar, (XQType*)this);
    ar & m_qname;
    ar & m_baseType;
    SERIALIZE_ENUM(TYPE_CATEGORY, m_typeCategory);
    SERIALIZE_ENUM(content_kind_t, m_contentKind);
    ar & m_listItemType;
    ar & m_unionItemTypes;
  }
public:
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier, 
        content_kind_t contentKind);

  // Constructor for List types 
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier,
        const XQType* listItemType);

  // Constructor for Union types 
  UserDefinedXQType(
        const TypeManager *manager,
        store::Item_t qname,
        xqtref_t baseType,
        TypeConstants::quantifier_t quantifier,
        std::vector<xqtref_t> unionItemTypes);

  virtual ~UserDefinedXQType() {}

  virtual content_kind_t content_kind() const { return m_contentKind; };

  store::Item_t get_qname() const { return m_qname;    }

  bool isAtomic()                 const { return m_typeCategory == ATOMIC_TYPE;  }
  bool isList()                   const { return m_typeCategory == LIST_TYPE;    }
  bool isUnion()                  const { return m_typeCategory == UNION_TYPE;   }
  bool isComplex()                const { return m_typeCategory == COMPLEX_TYPE; }
  TYPE_CATEGORY getTypeCategory() const { return m_typeCategory; }

  xqtref_t getBaseType() const { return m_baseType; }

  const XQType* getListItemType() const { return m_listItemType.getp(); }

  std::vector<xqtref_t> getUnionItemTypes()  const { return m_unionItemTypes; }

  bool isSuperTypeOf(const XQType& subType) const;

  bool isSubTypeOf(const XQType& superType) const;

  virtual std::ostream& serialize_ostream(std::ostream& os) const;
};

}

#endif /* ZORBA_TYPEIMPL_H */
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */

