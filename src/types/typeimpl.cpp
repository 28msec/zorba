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
#include "stdafx.h"

#include <iostream>
#include "system/globalenv.h"
#include "diagnostics/assert.h"

#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"

#include "zorbaserialization/serialize_basic_types.h"
#include "zorbaserialization/serialize_template_types.h"
#include "zorbaserialization/serialize_zorba_types.h"

#include "store/api/iterator.h"

namespace zorba
{

//#define DO_TRACE

#undef TRACE
#ifdef DO_TRACE
#define TRACE(msg)                                                            \
  {std::cout << __FUNCTION__ << ": " << msg << std::endl; std::cout.flush(); }
#else
#define TRACE(msg)
#endif


SERIALIZE_INTERNAL_METHOD(XQType)

SERIALIZABLE_CLASS_VERSIONS(AtomicXQType)

SERIALIZABLE_CLASS_VERSIONS(NodeXQType)

SERIALIZABLE_CLASS_VERSIONS(FunctionXQType)

SERIALIZABLE_CLASS_VERSIONS(ItemXQType)

SERIALIZABLE_CLASS_VERSIONS(StructuredItemXQType)

SERIALIZABLE_CLASS_VERSIONS(AnyXQType)

SERIALIZABLE_CLASS_VERSIONS(AnySimpleXQType)

SERIALIZABLE_CLASS_VERSIONS(AnyFunctionXQType)

SERIALIZABLE_CLASS_VERSIONS(UntypedXQType)

SERIALIZABLE_CLASS_VERSIONS(EmptyXQType)

SERIALIZABLE_CLASS_VERSIONS(NoneXQType)

SERIALIZABLE_CLASS_VERSIONS(UserDefinedXQType)

SERIALIZABLE_CLASS_VERSIONS(JSONXQType)


const char* XQType::KIND_STRINGS[XQType::MAX_TYPE_KIND] =
{
  "NONE_KIND",
  "EMPTY_KIND",
  "ITEM_KIND",
  "ATOMIC_TYPE_KIND",
  "STRUCTURED_ITEM_KIND",
  "NODE_TYPE_KIND",
  "JSON_ITEM_KIND",
  "FUNCTION_TYPE_KIND",
  "ANY_TYPE_KIND",
  "ANY_SIMPLE_TYPE_KIND",
  "ANY_FUNCTION_TYPE_KIND",
  "UNTYPED_KIND",
  "USER_DEFINED_KIND"
};


const char* AtomicXQType::ATOMIC_TYPE_CODE_STRINGS[store::XS_LAST] =
{
  "xs:anyAtomicType",
  "xs:string",
  "xs:normalizedString",
  "xs:token",
  "xs:language",
  "xs:NMTOKEN",
  "xs:Name",
  "xs:NCName",
  "xs:ID",
  "xs:IDREF",
  "xs:ENTITY",
  "xs:untypedAtomic",
  "xs:dateTime",
  "xs:date",
  "xs:time",
  "xs:duration",
  "xs:dayTimeDuration",
  "xs:yearMonthDuration",
  "xs:float",
  "xs:double",
  "xs:decimal",
  "xs:integer",
  "xs:nonPositiveInteger",
  "xs:negativeInteger",
  "xs:long",
  "xs:int",
  "xs:short",
  "xs:byte",
  "xs:nonNegativeInteger",
  "xs:unsignedLong",
  "xs:unsignedInt",
  "xs:unsignedShort",
  "xs:unsignedByte",
  "xs:positiveInteger",
  "xs:gYearMonth",
  "xs:gYear",
  "xs:gMonthDay",
  "xs:gDay",
  "xs:gMonth",
  "xs:boolean",
  "xs:base64Binary",
  "xs:hexBinary",
  "xs:anyURI",
  "xs:QName",
  "xs:NOTATION",
  "js:null",
  "xs:dateTimeStamp"
};


/*******************************************************************************

********************************************************************************/
std::string XQType::contentKindStr(content_kind_t contentKind)
{
  switch(contentKind)
  {
  case MIXED_CONTENT_KIND:
    return "mixedContent";
  case ELEMENT_ONLY_CONTENT_KIND:
    return "elementOnlyContent";
  case SIMPLE_CONTENT_KIND:
    return "simpleContent";
  case EMPTY_CONTENT_KIND:
    return "emptyContent";
  default:
    return "unknownContent";
  }
}


/*******************************************************************************

********************************************************************************/
XQType::XQType(
    const TypeManager* manager,
    TypeKind type_kind,
    SequenceType::Quantifier quantifier,
    bool builtin)
  :
  theRefCount(0),
  theManager((TypeManager*)manager),
  theKind(type_kind),
  theQuantifier(quantifier),
  theIsBuiltin(builtin)
{
  if (theIsBuiltin)
  {
#ifndef NDEBUG
    //theRefCount = 1000000;
#endif
    // register this hardcoded object to help plan serialization
    XQType* this_ptr = this;
    *::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects() & this_ptr;
  }
#if 0
  else
  {
    std::cout << "allocated type " << this << " of kind "
              << KIND_STRINGS[type_kind] << std::endl;
  }
#endif
}


/*******************************************************************************

********************************************************************************/
XQType::~XQType()
{
  if (theIsBuiltin)
  {
    assert(theRefCount == 0);
    theRefCount = 0;
  }
}


/*******************************************************************************

********************************************************************************/
void XQType::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_TYPEMANAGER(TypeManager, theManager);
  SERIALIZE_ENUM(TypeKind, theKind);
  SERIALIZE_ENUM(SequenceType::Quantifier, theQuantifier);
  ar & theIsBuiltin;
}


/*******************************************************************************
  Return the maximum number of items that can appear in an instance of the
  type. Returned value may be 0, 1 or 2, with 2 meaning "infinity".
********************************************************************************/
int XQType::max_card() const
{
  return (is_empty() ? 0 : RootTypeManager::QUANT_MAX_CNT[get_quantifier()]);
}


/*******************************************************************************
  Return the minimum number of items that can appear in an instance of the
  type. Returned value may be 0 or 1.
********************************************************************************/
int XQType::min_card() const
{
  return (is_empty() ? 0 : RootTypeManager::QUANT_MIN_CNT[get_quantifier()]);
}


/*******************************************************************************
  Return 0 if all instances of the type consist of exactly 0 items,  1 if all
  instances of the type consist of exactly 1 item, or -1  otherwise.
********************************************************************************/
int XQType::card() const
{
  if (is_empty() || is_none())
    return 0;

  SequenceType::Quantifier q = get_quantifier();

  if (RootTypeManager::QUANT_MIN_CNT[q] == RootTypeManager::QUANT_MAX_CNT[q])
    return  RootTypeManager::QUANT_MIN_CNT[q];

  return -1;
}


/*******************************************************************************

********************************************************************************/
bool XQType::isComplex() const
{
  switch (type_kind())
  {
  case XQType::USER_DEFINED_KIND:
  {
    return static_cast<const UserDefinedXQType*>(this)->theUDTKind == COMPLEX_UDT; 
  }
  case XQType::ANY_TYPE_KIND:
  case XQType::UNTYPED_KIND:
  {
    return true;
  }
  default:
  {
    return false;
  }
  }
}


/*******************************************************************************

********************************************************************************/
bool XQType::isList() const
{
  if (type_kind() == XQType::USER_DEFINED_KIND)
  {
    return static_cast<const UserDefinedXQType*>(this)->theUDTKind == LIST_UDT; 
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool XQType::isUnion() const
{
  if (type_kind() == XQType::USER_DEFINED_KIND)
  {
    return static_cast<const UserDefinedXQType*>(this)->theUDTKind == UNION_UDT; 
  }

  return false;
}


/*******************************************************************************
  Returns true if the ItemType of the given sequence type is a generalized atomic
  type.
********************************************************************************/
bool XQType::isGenAtomicAny() const
{
  if (type_kind() == XQType::ATOMIC_TYPE_KIND)
  {
    return true;
  }
  else if (type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* udt = static_cast<const UserDefinedXQType*>(this);

    if (udt->isAtomicAny())
      return true;

    if (udt->isUnion())
    {
      std::vector<xqtref_t>::const_iterator ite = udt->m_unionItemTypes.begin();
      std::vector<xqtref_t>::const_iterator end = udt->m_unionItemTypes.end();
      for (; ite != end; ++ite)
      {
        if ((*ite)->get_quantifier() != SequenceType::QUANT_ONE &&
            (*ite)->get_quantifier() != SequenceType::QUANT_QUESTION)
          return false;
      }

      return true;
    }
  }

  return false;
}


/*******************************************************************************
  Returns true if the ItemType of the given sequence type is an atomic type.
********************************************************************************/
bool XQType::isAtomicAny() const
{
  if (type_kind() == XQType::ATOMIC_TYPE_KIND)
  {
    return true;
  }
  else if (type_kind() == XQType::USER_DEFINED_KIND)
  {
    return static_cast<const UserDefinedXQType*>(this)->theUDTKind == ATOMIC_UDT;
  }

  return false;
}


/*******************************************************************************
  Returns true if the quantifier of the given sequence type is QUANT_ONE and
  its ItemType is an atomic type.
********************************************************************************/
bool XQType::isAtomicOne() const
{
  if (get_quantifier() == SequenceType::QUANT_ONE)
  {
    if (type_kind() == XQType::ATOMIC_TYPE_KIND)
    {
      return true;
    }
    else if (type_kind() == XQType::USER_DEFINED_KIND)
    {
      return static_cast<const UserDefinedXQType*>(this)->theUDTKind == ATOMIC_UDT;
    }
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool XQType::isBuiltinAtomicAny() const
{
  return type_kind() == XQType::ATOMIC_TYPE_KIND;
}


/*******************************************************************************
  Returns true if the quantifier of the given sequence type is QUANT_ONE and
  its ItemType is a builtin atomic type.
********************************************************************************/
bool XQType::isBuiltinAtomicOne() const
{
  return get_quantifier() == SequenceType::QUANT_ONE &&
         type_kind() == XQType::ATOMIC_TYPE_KIND;
}


/*******************************************************************************

********************************************************************************/
XQType::content_kind_t XQType::contentKind() const
{
  switch (type_kind())
  {
  case XQType::USER_DEFINED_KIND:
  {
    return static_cast<const UserDefinedXQType*>(this)->theContentKind; 
  }
  case XQType::NONE_KIND:
  case XQType::EMPTY_KIND:
  {
    return EMPTY_CONTENT_KIND;
  }
  case XQType::ATOMIC_TYPE_KIND:
  case XQType::ANY_SIMPLE_TYPE_KIND:
  {
    return SIMPLE_CONTENT_KIND; 
  }
  default:
  {
    return MIXED_CONTENT_KIND;
  }
  }
}


/*******************************************************************************

********************************************************************************/
bool XQType::isAnonymous() const
{
  switch (type_kind())
  {
  case XQType::USER_DEFINED_KIND:
  {
    return static_cast<const UserDefinedXQType*>(this)->theIsAnonymous; 
  }
  default:
  {
    return false;
  }
  }
}


/*******************************************************************************

********************************************************************************/
store::Item_t XQType::getQName() const
{
  switch (type_kind())
  {
  case ATOMIC_TYPE_KIND:
  {
    store::SchemaTypeCode type = 
    static_cast<const AtomicXQType*>(this)->theAtomicCode;

    return GENV_TYPESYSTEM.m_atomic_typecode_qname_map[type];
  }
  case USER_DEFINED_KIND:
  {
    return static_cast<const UserDefinedXQType*>(this)->theQName;
  }
  case ANY_TYPE_KIND:
  {
    return GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME;
  }
  case UNTYPED_KIND:
  {
    return GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
  }
  case ANY_SIMPLE_TYPE_KIND:
  {
    return GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME;
  }
  default:
    ZORBA_ASSERT(false);
  }
}


/*******************************************************************************

********************************************************************************/
std::string XQType::toString() const
{
  std::ostringstream os;
  serialize_ostream(os);
  std::string lResult = os.str();
  return lResult;
}


/*******************************************************************************

********************************************************************************/
std::ostream& XQType::serialize_ostream(std::ostream& os) const
{
  return os << "[XQType " << KIND_STRINGS[type_kind()]
            << TypeOps::decode_quantifier(get_quantifier()) << "]";
}


/*******************************************************************************
  Attempt to output the type as a string closer to the xs: representation
********************************************************************************/
std::string XQType::toSchemaString() const
{
  std::string result;

  switch (type_kind())
  {
  case NONE_KIND:
  {
    result = "none";
    break;
  }
  case EMPTY_KIND:
  {
    result = "empty-sequence()";
    break;
  }
  case ATOMIC_TYPE_KIND:
  {
    result = toString();
    break;
  }
  case ITEM_KIND:
  {
    result = "item()";
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  case STRUCTURED_ITEM_KIND:
  {
    result = "structured-item()";
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  case JSON_TYPE_KIND:
  {
    const JSONXQType* type = static_cast<const JSONXQType*>(this);
    store::StoreConsts::JSONItemKind kind = type->get_json_kind();

    if (kind == store::StoreConsts::jsonItem)
    {
      result = "json-item()";
    }
    else if (kind == store::StoreConsts::jsonObject)
    {
      result = "object()";
    }
    else if (kind == store::StoreConsts::jsonArray)
    {
      result = "array()";
    }

    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }

  case NODE_TYPE_KIND:
  {
    result = static_cast<const NodeXQType*>(this)->toSchemaStringInternal();
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  case FUNCTION_TYPE_KIND:
  {
    result = toString();
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  case ANY_FUNCTION_TYPE_KIND:
  {
    result = "function(*)";
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  case ANY_TYPE_KIND:
  {
    result = "xs:anyType";
    break;
  }
  case ANY_SIMPLE_TYPE_KIND:
  {
    result = "xs:anySimpleType";
    break;
  }
  case UNTYPED_KIND:
  {
    result = "xs:untyped";
    break;
  }
  default:
  {
    result = toString();
    result += TypeOps::decode_quantifier(get_quantifier());
    break;
  }
  }

  return result;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  NoneXQType                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

NoneXQType::NoneXQType(const TypeManager* manager, bool builtin)
  :
  XQType(manager, NONE_KIND, SequenceType::QUANT_ONE, builtin)
{
}


void NoneXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  EmptyXQType                                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

EmptyXQType::EmptyXQType(const TypeManager* manager, bool builtin)
  :
  XQType(manager, EMPTY_KIND, SequenceType::QUANT_QUESTION, builtin)
{
}


void EmptyXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ItemXQType                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

ItemXQType::ItemXQType(
    const TypeManager* tm,
    SequenceType::Quantifier quant,
    bool builtin)
  :
  XQType(tm, ITEM_KIND, quant, builtin)
{
}


void ItemXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AtomicXQType                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void AtomicXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  SERIALIZE_ENUM(store::SchemaTypeCode, theAtomicCode);
}


/*******************************************************************************

********************************************************************************/
std::ostream& AtomicXQType::serialize_ostream(std::ostream& os) const
{
  return os << ATOMIC_TYPE_CODE_STRINGS[get_type_code()]
            << TypeOps::decode_quantifier(get_quantifier());
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StructuredItemXQType                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

StructuredItemXQType::StructuredItemXQType(
    const TypeManager* tm,
    SequenceType::Quantifier quant,
    bool builtin)
  :
  XQType(tm, STRUCTURED_ITEM_KIND, quant, builtin)
{
}


void StructuredItemXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  JSONXQType                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
JSONXQType::JSONXQType(
    const TypeManager* manager,
    store::StoreConsts::JSONItemKind kind,
    SequenceType::Quantifier quantifier,
    bool builtin)
  :
  XQType(manager, JSON_TYPE_KIND, quantifier, builtin),
  theJSONKind(kind)
{
}


/*******************************************************************************

********************************************************************************/
void JSONXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  SERIALIZE_ENUM(store::StoreConsts::JSONItemKind, theJSONKind);
}


/*******************************************************************************

********************************************************************************/
std::ostream& JSONXQType::serialize_ostream(std::ostream& os) const
{
  os << "[JSONXQType " << theJSONKind
     << TypeOps::decode_quantifier(get_quantifier());

  return os << "]";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  NodeXQType                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

/*******************************************************************************

********************************************************************************/
NodeXQType::NodeXQType(
    const TypeManager* manager,
    store::StoreConsts::NodeKind nodeKind,
    const store::Item_t& nodeName,
    const xqtref_t& contentType,
    SequenceType::Quantifier quantifier,
    bool nillable,
    bool schematest,
    bool builtin)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier, builtin),
  theNodeKind(nodeKind),
  theNodeName(nodeName),
  theContentType(contentType),
  theNillable(nillable),
  theIsSchemaTest(schematest)
{
  assert(contentType == NULL ||
         (nodeKind == store::StoreConsts::documentNode &&
          contentType->type_kind() == NODE_TYPE_KIND) ||
         contentType->type_kind() == ATOMIC_TYPE_KIND ||
         contentType->type_kind() == ANY_TYPE_KIND ||
         contentType->type_kind() == ANY_SIMPLE_TYPE_KIND ||
         contentType->type_kind() == UNTYPED_KIND ||
         contentType->type_kind() == USER_DEFINED_KIND);

  assert(contentType == NULL ||
         contentType->get_quantifier() == SequenceType::QUANT_ONE ||
         contentType->type_kind() == ANY_TYPE_KIND ||
         contentType->type_kind() == ANY_SIMPLE_TYPE_KIND ||
         contentType->type_kind() == UNTYPED_KIND);

  assert(nodeKind != store::StoreConsts::anyNode ||
         (contentType == NULL ||
          contentType->type_kind() == XQType::UNTYPED_KIND ||
          contentType->type_kind() == XQType::ANY_TYPE_KIND));

#if 0
  if (theIsBuiltin == false &&
      nodeKind == store::StoreConsts::elementNode &&
      contentType == NULL &&
      nodeName == NULL)
  {
    ZORBA_ASSERT(false);
  }

  if (!theIsBuiltin)
  {
    std::cout << "allocated type " << this << " : " << toSchemaString() << std::endl;
  }
#endif
}


/*******************************************************************************

********************************************************************************/
NodeXQType::NodeXQType(
    const NodeXQType& source,
    SequenceType::Quantifier quantifier,
    bool builtin)
  :
  XQType(source.theManager, NODE_TYPE_KIND, quantifier, builtin),
  theNodeKind(source.theNodeKind),
  theNodeName(source.theNodeName),
  theContentType(source.theContentType),
  theNillable(source.theNillable),
  theIsSchemaTest(source.theIsSchemaTest)
{
#if 0
  if (theIsBuiltin == false &&
      theNodeKind == store::StoreConsts::elementNode &&
      theContentType == NULL &&
      theNodeName == NULL)
  {
    std::cerr << "STRANGE TYPE" << std::endl;
    theNodeKind = store::StoreConsts::elementNode;
  }

  if (!theIsBuiltin)
  {
    std::cout << "allocated copy type " << this << " : " << toSchemaString() << std::endl;
  }
#endif
}


/*******************************************************************************

********************************************************************************/
void NodeXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  SERIALIZE_ENUM(store::StoreConsts::NodeKind, theNodeKind);
  ar & theNodeName;
  ar & theContentType;
  ar & theNillable;
  ar & theIsSchemaTest;
}


/*******************************************************************************

********************************************************************************/
bool NodeXQType::is_untyped() const
{
  return theContentType == GENV_TYPESYSTEM.UNTYPED_TYPE;
}


/*******************************************************************************

********************************************************************************/
bool NodeXQType::is_equal(const TypeManager* tm, const NodeXQType& other) const
{
  if (theNodeKind != other.theNodeKind)
    return false;

  if (theNodeName != other.theNodeName)
  {
    if (theNodeName == NULL || other.theNodeName == NULL)
      return false;

    if (!theNodeName->equals(other.theNodeName))
      return false;
  }

  xqtref_t c1 = get_content_type();
  xqtref_t c2 = other.get_content_type();

  if (c1 == c2)
    return true;

  if (c1 != NULL && c2 != NULL)
    return TypeOps::is_equal(tm, *c1, *c2);

  if (c1 == NULL)
    return (c2->type_kind() == XQType::ANY_TYPE_KIND);
  else
    return (c1->type_kind() == XQType::ANY_TYPE_KIND);

  return false;
}


/*******************************************************************************

********************************************************************************/
bool NodeXQType::is_subtype(
    const TypeManager* tm,
    const NodeXQType& supertype,
    const QueryLoc& loc) const
{
  if (supertype.theNodeKind == store::StoreConsts::anyNode)
  {
    if (supertype.theContentType != NULL &&
        supertype.theContentType->type_kind() == XQType::UNTYPED_KIND)
    {
      return (theContentType != NULL &&
              theContentType->type_kind() == XQType::UNTYPED_KIND);
    }

    return true;
  }

  if (supertype.theNodeKind != theNodeKind)
    return false;

  if (supertype.theNodeName != NULL)
  {
    if (theNodeName == NULL)
      return false;

    if (!theNodeName->equals(supertype.theNodeName))
    {
      if (supertype.theIsSchemaTest)
      {
        Schema* schema = supertype.theManager->getSchema();
        ZORBA_ASSERT(schema != NULL);

        store::Item_t headName;

#ifndef ZORBA_NO_XMLSCHEMA
        schema->getSubstitutionHeadForElement(theNodeName.getp(), headName);

        while (headName != NULL)
        {
          if (headName->equals(supertype.theNodeName))
          {
            break;
          }

          schema->getSubstitutionHeadForElement(headName.getp(), headName);
        }
#endif // ZORBA_NO_XMLSCHEMA

        if (headName == NULL)
          return false;
      }
      else
      {
        return false;
      }
    }
  }

  if (theContentType == supertype.theContentType)
  {
    if (supertype.theNillable == false && theNillable == true)
      return false;

    return true;
  }

  if (theContentType != NULL && supertype.theContentType != NULL)
  {
    if (supertype.theNillable == false && theNillable == true)
      return false;

    return TypeOps::is_subtype(tm, *theContentType, *supertype.theContentType);
  }
  else if (supertype.theContentType == NULL)
  {
    return true;
  }
  else
  {
    return supertype.theContentType->type_kind() == XQType::ANY_TYPE_KIND;
  }

  return false;
}


/*******************************************************************************

********************************************************************************/
bool NodeXQType::is_supertype(
    const TypeManager* tm,
    const store::Item* subitem,
    const QueryLoc& loc) const
{
  assert(subitem->isNode());

  if (theNodeKind == store::StoreConsts::anyNode)
  {
    if (theContentType != NULL &&
        theContentType->type_kind() == XQType::UNTYPED_KIND)
    {
      return (subitem->getType()->equals(GENV_TYPESYSTEM.XS_UNTYPED_QNAME));
    }

    return true;
  }

  if (theNodeKind != subitem->getNodeKind())
    return false;

  switch (theNodeKind)
  {
  case store::StoreConsts::textNode:
  case store::StoreConsts::commentNode:
  case store::StoreConsts::namespaceNode:
  {
    return true;
  }
  case store::StoreConsts::piNode:
  {
    if (theNodeName != NULL && !subitem->getNodeName()->equals(theNodeName))
      return false;

    return true;
  }
  case store::StoreConsts::attributeNode:
  {
    assert(!theIsSchemaTest || (theNodeName && theContentType));

    if (theNodeName != NULL && !subitem->getNodeName()->equals(theNodeName))
      return false;

    if (theContentType != NULL)
    {
      xqtref_t subContentType = 
      tm->create_named_type(subitem->getType(), SequenceType::QUANT_ONE, loc, true);

      return TypeOps::is_subtype(tm, *subContentType, *theContentType);
    }

    return true;
  }
  case store::StoreConsts::elementNode:
  {
    if (theIsSchemaTest)
    {
      assert(theNodeName != NULL);

      if (!subitem->getNodeName()->equals(theNodeName))
      {
        Schema* schema = theManager->getSchema();
        ZORBA_ASSERT(schema != NULL);
          
        store::Item_t headName;
          
#ifndef ZORBA_NO_XMLSCHEMA
        schema->getSubstitutionHeadForElement(subitem->getNodeName(), headName);
          
        while (headName != NULL)
        {
          if (headName->equals(theNodeName))
            break;
          
          schema->getSubstitutionHeadForElement(headName.getp(), headName);
        }
#endif // ZORBA_NO_XMLSCHEMA
        
        if (headName == NULL)
          return false;
      }

      if (theContentType == NULL ||
          theContentType->type_kind() == XQType::ANY_TYPE_KIND)
        return true;

      xqtref_t subContentType = tm->create_named_type(subitem->getType(),
                                                      SequenceType::QUANT_ONE,
                                                      loc,
                                                      true);

      if (!TypeOps::is_subtype(tm, *subContentType, *theContentType))
        return false;

#ifndef ZORBA_NO_XMLSCHEMA
      bool nillable;
      store::Item_t typeName;
      tm->get_schema_element_typeinfo(subitem->getNodeName(), typeName, nillable, loc);

      if (!nillable && subitem->getNilled())
        return false;

      return true;
#else
      return theNillable;
#endif
    }
    else
    {
      if (theNodeName != NULL && !subitem->getNodeName()->equals(theNodeName))
        return false;

      if (!theNillable && subitem->getNilled())
        return false;

      if (theContentType == NULL ||
          theContentType->type_kind() == XQType::ANY_TYPE_KIND)
        return true;

      xqtref_t subContentType = 
      tm->create_named_type(subitem->getType(), SequenceType::QUANT_ONE, loc, true);

      return TypeOps::is_subtype(tm, *subContentType, *theContentType);
    }
  }
  case store::StoreConsts::documentNode:
  {
    if (theContentType == NULL ||
        theContentType->type_kind() == XQType::ANY_TYPE_KIND)
      return true;

    if (theContentType->type_kind() == XQType::UNTYPED_KIND)
    {
      return !subitem->isValidated();
    }

    ZORBA_ASSERT(theContentType->type_kind() == XQType::NODE_TYPE_KIND);

    store::Iterator_t childrenIte = subitem->getChildren();
    store::Item_t child;
    store::Item_t elemChild;
    csize numElemChildren = 0;
    childrenIte->open();
    while (childrenIte->next(child))
    {
      if (child->getNodeKind() == store::StoreConsts::elementNode)
      {
        if (numElemChildren == 0)
          elemChild.transfer(child);

        ++numElemChildren;
      }
    }
    childrenIte->close();

    if (numElemChildren != 1)
      return false;

    const NodeXQType* elemTestType = 
    static_cast<const NodeXQType*>(theContentType.getp());

    return elemTestType->is_supertype(tm, elemChild, loc);
  }
  default:
  {
    ZORBA_ASSERT(false);
  }
  }
}


/*******************************************************************************

********************************************************************************/
std::ostream& NodeXQType::serialize_ostream(std::ostream& os) const
{
  store::StoreConsts::NodeKind node_kind = theNodeKind;
  xqtref_t content_type = get_content_type();

  os << "[NodeXQType " << store::StoreConsts::toString(node_kind)
     << TypeOps::decode_quantifier(get_quantifier());

  if (theNodeName != NULL)
  {
    os << " nametest=[uri: " << theNodeName->getNamespace()
       << ", local: " << theNodeName->getLocalName() << "]";
  }

  if (content_type != NULL)
  {
    os << " content=";
    os << content_type->toString();
  }

  return os << "]";
}


std::string NodeXQType::toSchemaStringInternal() const
{
  std::ostringstream os;

  if (theNodeKind == store::StoreConsts::documentNode)
  {
    os << "document-node(";
    
    if (theContentType != NULL &&
        theContentType->type_kind() == XQType::NODE_TYPE_KIND)
    {
      os << ", " << theContentType->toSchemaString();
    }
  }
  else if (theIsSchemaTest)
  {
    assert(theContentType != NULL);

    os << "schema-" << store::StoreConsts::toSchemaString(get_node_kind()) << "("
       << theNodeName->getStringValue();
  }
  else
  {
    os << store::StoreConsts::toSchemaString(get_node_kind()) << "(";
    
    if (theNodeName != NULL)
    {
      os << theNodeName->getStringValue();

      if (theContentType != NULL)
      {
        os << ", " << theContentType->toSchemaString();

        if (theNillable)
          os << "?";
      }
    }
    else if (theContentType != NULL)
    {
      os << "*, " << theContentType->toSchemaString();

      if (theNillable)
        os << "?";
    }
  }
  
  os << ")";
  
  return os.str();
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AnyFunctionXQType                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void AnyFunctionXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  FunctionXQType                                                             //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor for user-defined Atomic and Complex types
********************************************************************************/
FunctionXQType::FunctionXQType(
    const TypeManager* manager,
    const std::vector<xqtref_t>& aParamTypes,
    const xqtref_t& aReturnType,
    SequenceType::Quantifier quantifier,
    bool builtin)
  :
  XQType(manager, FUNCTION_TYPE_KIND, quantifier, builtin),
  m_param_types(aParamTypes),
  m_return_type(aReturnType)
{
}


/*******************************************************************************

********************************************************************************/
void FunctionXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  ar & m_param_types;
  ar & m_return_type;
}


/*******************************************************************************

********************************************************************************/
bool FunctionXQType::is_equal(
    const TypeManager* tm,
    const FunctionXQType& other) const
{
  if (this->get_number_params() != other.get_number_params())
  {
    return false;
  }

  if ( ! TypeOps::is_equal(tm,
                           *get_return_type().getp(),
                           *other.get_return_type().getp()))
  {
    return false;
  }

  size_t i = 0;
  for (std::vector<xqtref_t>::const_iterator lIter = m_param_types.begin();
       lIter != m_param_types.end(); ++lIter, ++i)
  {
    if ( ! TypeOps::is_equal(tm, *other[i].getp(), *lIter->getp()))
    {
      return false;
    }
  }

  return true;
}


/*******************************************************************************
  Bi is function(Ba_1, Ba_2, ... Ba_N) as Br,
  Ai is function(Aa_1, Aa_2, ... Aa_M) as Ar,
  Ai is subtype of Bi iff
  N (arity of Bi) equals M (arity of Ai),
  subtype(Ar, Br), and
  for values of I between 1 and N, subtype(Ba_I, Aa_I).
********************************************************************************/
bool FunctionXQType::is_subtype(
    const TypeManager* tm,
    const FunctionXQType& supertype,
    bool ignoreReturnType) const
{
  if (this->get_number_params() != supertype.get_number_params())
  {
    return false;
  }

  if (!ignoreReturnType &&
      !TypeOps::is_subtype(tm,
                           *get_return_type().getp(),
                           *supertype.get_return_type().getp()))
  {
    return false;
  }

  size_t i = 0;
  for (std::vector<xqtref_t>::const_iterator lIter = m_param_types.begin();
       lIter != m_param_types.end(); ++lIter, ++i)
  {
    if (!TypeOps::is_subtype(tm, *supertype[i].getp(), *lIter->getp()))
    {
      return false;
    }
  }

  return true;
}


/*******************************************************************************

********************************************************************************/
std::ostream&
FunctionXQType::serialize_ostream(std::ostream& os) const
{
  os << "[FunctionXQType "
     << TypeOps::decode_quantifier(get_quantifier()) << " ";

  if (m_param_types.size() != 0)
  {
    os << "params=[";
    size_t i = 1;
    for (std::vector<xqtref_t>::const_iterator lIter = m_param_types.begin();
         lIter != m_param_types.end(); ++i, ++lIter) {
      os << (*lIter)->toString();
      if (i < m_param_types.size()) os << ", ";
    }
    os  << "] ";
  }

  os << "return=[";
  os << m_return_type->toString();
  os  << "]";

  return os << "]";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  UserDefinedXQType                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************
  Constructor for user-defined Atomic and Complex types
********************************************************************************/
UserDefinedXQType::UserDefinedXQType(
    const TypeManager* manager,
    bool isAnonymous,
    store::Item_t qname,
    const xqtref_t& baseType,
    SequenceType::Quantifier quantifier,
    UDTKind udtKind,
    content_kind_t contentKind,
    bool builtin)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, builtin),
  theIsAnonymous(isAnonymous),
  theQName(qname),
  theBaseType(baseType),
  theUDTKind(udtKind),
  theContentKind(contentKind)
{
  assert(udtKind == ATOMIC_UDT || udtKind == COMPLEX_UDT);

  ZORBA_ASSERT(baseType != NULL);
  ZORBA_ASSERT(udtKind == ATOMIC_UDT || quantifier == SequenceType::QUANT_ONE);

  TRACE("UserDefinedXQType c2: " << theQName->getLocalName() << "@"
        << theQName->getNamespace() << " " << decodeUDTKind(theUDTKind)
        << " " << contentKindStr(theContentKind));
}


/*******************************************************************************
  Constructor for user-defined list types
********************************************************************************/
UserDefinedXQType::UserDefinedXQType(
    const TypeManager* manager,
    bool isAnonymous,
    store::Item_t qname,
    const xqtref_t& baseType,
    const XQType* listItemType,
    bool builtin)
  :
  XQType(manager, USER_DEFINED_KIND, SequenceType::QUANT_STAR, builtin),
  theIsAnonymous(isAnonymous),
  theQName(qname),
  theBaseType(baseType),
  theUDTKind(LIST_UDT),
  theContentKind(SIMPLE_CONTENT_KIND),
  m_listItemType(listItemType)
{
  ZORBA_ASSERT(listItemType);
}


/*******************************************************************************
  Constructor for user-defined union types
********************************************************************************/
UserDefinedXQType::UserDefinedXQType(
    const TypeManager* manager,
    bool isAnonymous,
    store::Item_t qname,
    const xqtref_t& baseType,
    SequenceType::Quantifier quantifier,
    const std::vector<xqtref_t>& unionItemTypes,
    bool builtin)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, builtin),
  theIsAnonymous(isAnonymous),
  theQName(qname),
  theBaseType(baseType),
  theUDTKind(UNION_UDT),
  theContentKind(SIMPLE_CONTENT_KIND),
  m_unionItemTypes(unionItemTypes)
{
  std::vector<xqtref_t>::const_iterator ite = unionItemTypes.begin();
  std::vector<xqtref_t>::const_iterator end = unionItemTypes.end();
  for (; ite != end; ++ite)
  {
    theQuantifier = TypeOps::union_quant(theQuantifier, (*ite)->get_quantifier());
  }
}


/*******************************************************************************

********************************************************************************/
void UserDefinedXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  ar & theQName;
  ar & theBaseType;
  SERIALIZE_ENUM(UDTKind, theUDTKind);
  SERIALIZE_ENUM(content_kind_t, theContentKind);
  ar & m_listItemType;
  ar & m_unionItemTypes;
}


/*******************************************************************************

********************************************************************************/
xqtref_t UserDefinedXQType::getBaseBuiltinType() const
{
  xqtref_t builtinType = theBaseType;

  while (builtinType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* tmp =
    static_cast<const UserDefinedXQType*>(builtinType.getp());

    builtinType = tmp->getBaseType();
  }

  return builtinType;
}


/*******************************************************************************

********************************************************************************/
bool UserDefinedXQType::isSuperTypeOf(
    const TypeManager* tm,
    const XQType* subType,
    const QueryLoc& loc) const
{
  if (isUnion() && isGenAtomicAny() && subType->isAtomicAny())
  {
    std::vector<xqtref_t>::const_iterator ite = m_unionItemTypes.begin();
    std::vector<xqtref_t>::const_iterator end = m_unionItemTypes.end();
    for (; ite != end; ++ite)
    {
      if (TypeOps::is_subtype(tm, *subType, *(*ite), loc))
        return true;
    }

    return false;
  }

  if (subType->type_kind() != XQType::USER_DEFINED_KIND)
    return false;

  const UserDefinedXQType* subtype = static_cast<const UserDefinedXQType*>(subType);

  do
  {
    if (getUDTKind() == subtype->getUDTKind() &&
        getQName()->equals(subtype->getQName()))
    {
      return true;
    }

    subType = subtype->getBaseType().getp();

    if (subType->type_kind() != XQType::USER_DEFINED_KIND)
      return false;

    subtype = static_cast<const UserDefinedXQType*>(subType);

  }
  while (subtype != NULL);

  return false;
}


/*******************************************************************************
  TODO: fix this method ?????
********************************************************************************/
bool UserDefinedXQType::isSubTypeOf(
    const TypeManager* tm,
    const XQType& supertype) const
{
  const XQType* subtype = this;

  do
  {
    if (TypeOps::is_equal(tm, *subtype, supertype))
      return true;

    if (subtype->type_kind() == XQType::USER_DEFINED_KIND)
    {
      subtype = static_cast<const UserDefinedXQType*>(subtype)->getBaseType().getp();
    }
    else if (supertype.type_kind() == XQType::USER_DEFINED_KIND)
    {
      return false;
    }
    else
    {
      return TypeOps::is_subtype(tm, *subtype, supertype);
    }
  }
  while(subtype != NULL);

  return false;
}


/*******************************************************************************

********************************************************************************/
std::string UserDefinedXQType::decodeUDTKind(UDTKind typeCategory)
{
  switch(typeCategory)
  {
  case ATOMIC_UDT:
    return "atomic";
  case COMPLEX_UDT:
    return "complex";
  case LIST_UDT:
    return "list";
  case UNION_UDT:
    return "union";
  default:
    return "unknownTypeCategory";
  }
}


/*******************************************************************************

********************************************************************************/
std::ostream& UserDefinedXQType::serialize_ostream(std::ostream& os) const
{
  std::ostringstream info;

  switch (theUDTKind)
  {
  case ATOMIC_UDT:
  {
    info << "isAtomic";
    break;
  }
  case COMPLEX_UDT:
  {
    info << "isComplex";
    break;
  }
  case LIST_UDT:
  {
    info << " isList itemType:" << m_listItemType->toString();
    break;
  }
  case UNION_UDT:
  {
    csize numMembers = m_unionItemTypes.size();
    info << " Union (" ;

    if (numMembers > 0)
    {
      for (csize i = 0; i < numMembers-1; ++i)
      {
        info << m_unionItemTypes[i]->toString() << ", ";
      }
      info << m_unionItemTypes[numMembers-1]->toString();
    }

    info << ")";

    break;
  }
  default:
    ZORBA_ASSERT(false);
  }

  info << " " << contentKindStr(theContentKind);

  return os << "[UserDefinedXQType "
            << TypeOps::decode_quantifier(get_quantifier()) << " "
            << theQName->getLocalName() << "@"
            << theQName->getNamespace() << " "
            << info.str()
            << " base:"
            << ( theBaseType ? theBaseType->toString() : "NULL" )
            << "]";
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AnyXQType                                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void AnyXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  UntypedXQType                                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void UntypedXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  AnySimpleXQType                                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
void AnySimpleXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}

}  // namespace zorba
/* vim:set et sw=2 ts=2: */
