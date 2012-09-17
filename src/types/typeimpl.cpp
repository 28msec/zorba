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

#ifdef ZORBA_WITH_JSON
SERIALIZABLE_CLASS_VERSIONS(JSONXQType)
#endif


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
  "UNTYPED_ATOMIC",
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
  "jdm:null"
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
    TypeConstants::quantifier_t quantifier,
    bool builtin)
  :
  theManager((TypeManager*)manager),
  theKind(type_kind),
  theQuantifier(quantifier),
  theIsBuiltin(builtin)
{
  if (theIsBuiltin)
  {
    // register this hardcoded object to help plan serialization
    XQType* this_ptr = this;
    *::zorba::serialization::ClassSerializer::getInstance()->
    getArchiverForHardcodedObjects() & this_ptr;
  }
}


/*******************************************************************************

********************************************************************************/
void XQType::serialize(::zorba::serialization::Archiver& ar)
{
  SERIALIZE_TYPEMANAGER(TypeManager, theManager);
  SERIALIZE_ENUM(TypeKind, theKind);
  SERIALIZE_ENUM(TypeConstants::quantifier_t, theQuantifier);
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

  TypeConstants::quantifier_t q = get_quantifier();

  if (RootTypeManager::QUANT_MIN_CNT[q] == RootTypeManager::QUANT_MAX_CNT[q])
    return  RootTypeManager::QUANT_MIN_CNT[q];

  return -1;
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
    break;
  }
  case STRUCTURED_ITEM_KIND:
  {
    result = "structured-item()";
    break;
  }

#ifdef ZORBA_WITH_JSON

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

    break;
  }
#endif

  case NODE_TYPE_KIND:
  {
    result = static_cast<const NodeXQType*>(this)->toSchemaStringInternal();
    break;
  }
  case FUNCTION_TYPE_KIND:
  {
    result = toString();
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
  case ANY_FUNCTION_TYPE_KIND:
  {
    result = "function(*)";
    break;
  }
  case UNTYPED_KIND:
  {
    result = toString();
    break;
  }
  default:
    return toString();
    break;
  }

  result += TypeOps::decode_quantifier(get_quantifier());
  return result;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  NoneXQType                                                                 //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

NoneXQType::NoneXQType(const TypeManager* manager, bool builtin)
  :
  XQType(manager, NONE_KIND, TypeConstants::QUANT_ONE, builtin)
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
  XQType(manager, EMPTY_KIND, TypeConstants::QUANT_QUESTION, builtin)
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
    TypeConstants::quantifier_t quant,
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
  SERIALIZE_ENUM(store::SchemaTypeCode, m_type_code);
}


/*******************************************************************************

********************************************************************************/
std::ostream& AtomicXQType::serialize_ostream(std::ostream& os) const
{
  return os << ATOMIC_TYPE_CODE_STRINGS[get_type_code()]
            << TypeOps::decode_quantifier(get_quantifier());
}


/*******************************************************************************

********************************************************************************/
store::Item_t AtomicXQType::get_qname() const
{
  return GENV_TYPESYSTEM.m_atomic_typecode_qname_map[m_type_code];
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  StructuredItemXQType                                                       //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////

StructuredItemXQType::StructuredItemXQType(
    const TypeManager* tm,
    TypeConstants::quantifier_t quant,
    bool builtin)
  :
  XQType(tm, STRUCTURED_ITEM_KIND, quant, builtin)
{
}


void StructuredItemXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
}


#ifdef ZORBA_WITH_JSON
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
    TypeConstants::quantifier_t quantifier,
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
  os << "[JSONXQType " << store::StoreConsts::toString(theJSONKind)
     << TypeOps::decode_quantifier(get_quantifier());

  return os << "]";
}

#endif // ZORBA_WITH_JSON


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
    TypeConstants::quantifier_t quantifier,
    bool nillable,
    bool schematest,
    bool builtin)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier, builtin),
  m_node_kind(nodeKind),
  m_node_name(nodeName),
  theContentType(contentType),
  m_nillable(nillable),
  m_schema_test(schematest)
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
         contentType->get_quantifier() == TypeConstants::QUANT_ONE ||
         contentType->type_kind() == ANY_TYPE_KIND ||
         contentType->type_kind() == ANY_SIMPLE_TYPE_KIND ||
         contentType->type_kind() == UNTYPED_KIND);

  assert(nodeKind != store::StoreConsts::anyNode ||
         (contentType == NULL ||
          contentType->type_kind() == XQType::UNTYPED_KIND ||
          contentType->type_kind() == XQType::ANY_TYPE_KIND));
}


/*******************************************************************************

********************************************************************************/
NodeXQType::NodeXQType(
    const NodeXQType& source,
    TypeConstants::quantifier_t quantifier)
  :
  XQType(source.theManager, NODE_TYPE_KIND, quantifier, false),
  m_node_kind(source.m_node_kind),
  m_node_name(source.m_node_name),
  theContentType(source.theContentType),
  m_nillable(source.m_nillable),
  m_schema_test(source.m_schema_test)
{
}


/*******************************************************************************

********************************************************************************/
void NodeXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  SERIALIZE_ENUM(store::StoreConsts::NodeKind, m_node_kind);
  ar & m_node_name;
  ar & theContentType;
  ar & m_nillable;
  ar & m_schema_test;
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
  if (m_node_kind != other.m_node_kind)
    return false;

  if (m_node_name != other.m_node_name)
  {
    if (m_node_name == NULL || other.m_node_name == NULL)
      return false;

    if (!m_node_name->equals(other.m_node_name))
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
  if (supertype.m_node_kind == store::StoreConsts::anyNode)
  {
    if (supertype.theContentType != NULL &&
        supertype.theContentType->type_kind() == XQType::UNTYPED_KIND)
    {
      return (theContentType != NULL &&
              theContentType->type_kind() == XQType::UNTYPED_KIND);
    }

    return true;
  }

  if (supertype.m_node_kind != m_node_kind)
    return false;

  if (supertype.m_node_name != NULL)
  {
    if (m_node_name == NULL)
      return false;

    if (!m_node_name->equals(supertype.m_node_name))
    {
      if (supertype.m_schema_test)
      {
        Schema* schema = supertype.theManager->getSchema();
        ZORBA_ASSERT(schema != NULL);

        store::Item_t headName;

#ifndef ZORBA_NO_XMLSCHEMA
        schema->getSubstitutionHeadForElement(m_node_name.getp(), headName);

        while (headName != NULL)
        {
          if (headName->equals(supertype.m_node_name))
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
    return true;

  if (theContentType != NULL && supertype.theContentType != NULL)
  {
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

  if (m_node_kind == store::StoreConsts::anyNode)
    return true;

  if (m_node_kind != subitem->getNodeKind())
    return false;

  if (m_node_name != NULL)
  {
    if (!subitem->getNodeName()->equals(m_node_name))
    {
      if (m_schema_test)
      {
        Schema* schema = theManager->getSchema();
        ZORBA_ASSERT(schema != NULL);

        store::Item_t headName;

#ifndef ZORBA_NO_XMLSCHEMA
        schema->getSubstitutionHeadForElement(subitem->getNodeName(), headName);

        while (headName != NULL)
        {
          if (headName->equals(m_node_name))
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

  // document-node( E ) matches any document node that contains exactly one element
  // node, optionally accompanied by one or more comment and processing instruction
  // nodes, if E is an ElementTest or SchemaElementTest that matches the element node.
  bool is_element_test = (
      m_node_kind == store::StoreConsts::documentNode &&
      theContentType != NULL &&
      theContentType->type_kind() == XQType::NODE_TYPE_KIND &&
      dynamic_cast<const NodeXQType*>(theContentType.getp())->m_schema_test == false);

  if (m_node_kind != store::StoreConsts::elementNode &&
      m_node_kind != store::StoreConsts::attributeNode &&
      !is_element_test)
    return true;

  if (theContentType == NULL ||
      theContentType->type_kind() == XQType::ANY_TYPE_KIND)
    return true;

  if (is_element_test)
  {
    xqtref_t documentNodeType = tm->create_value_type(subitem, loc);
    return TypeOps::is_subtype(tm, *documentNodeType, *this);
  }

  xqtref_t subContentType = tm->create_named_type(subitem->getType(),
                                                  TypeConstants::QUANT_ONE,
                                                  loc,
                                                  err::XPTY0004);

  return TypeOps::is_subtype(tm, *subContentType, *theContentType);
}


/*******************************************************************************

********************************************************************************/
std::ostream& NodeXQType::serialize_ostream(std::ostream& os) const
{
  store::StoreConsts::NodeKind node_kind = m_node_kind;
  xqtref_t content_type = get_content_type();

  os << "[NodeXQType " << store::StoreConsts::toString(node_kind)
     << TypeOps::decode_quantifier(get_quantifier());

  if (m_node_name != NULL)
  {
    os << " nametest=[uri: " << m_node_name->getNamespace()
       << ", local: " << m_node_name->getLocalName() << "]";
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

  if (m_node_kind == store::StoreConsts::documentNode)
  {
    os << "document-node(";
    
    if (theContentType != NULL &&
        theContentType->type_kind() == XQType::NODE_TYPE_KIND)
    {
      os << ", " << theContentType->toSchemaString();
    }
  }
  else if (m_schema_test)
  {
    assert(theContentType != NULL);

    os << "schema-" << store::StoreConsts::toSchemaString(get_node_kind()) << "("
       << m_node_name->getStringValue();
  }
  else
  {
    os << store::StoreConsts::toSchemaString(get_node_kind()) << "(";
    
    if (m_node_name != NULL)
    {
      os << m_node_name->getStringValue();

      if (theContentType != NULL)
      {
        os << ", " << theContentType->toSchemaString();

        if (m_nillable)
          os << "?";
      }
    }
    else if (theContentType != NULL)
    {
      os << "*, " << theContentType->toSchemaString();

      if (m_nillable)
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
    TypeConstants::quantifier_t quantifier,
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
    const FunctionXQType& supertype) const
{
  if (this->get_number_params() != supertype.get_number_params())
  {
    return false;
  }

  if (!TypeOps::is_subtype(tm,
                           *get_return_type().getp(),
                           *supertype.get_return_type().getp()))
  {
    return false;
  }

  size_t i = 0;
  for (std::vector<xqtref_t>::const_iterator lIter = m_param_types.begin();
       lIter != m_param_types.end(); ++lIter)
  {
    if (!TypeOps::is_subtype(tm, *lIter->getp(), *supertype[i++].getp()))
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
    store::Item_t qname,
    const xqtref_t& baseType,
    TypeConstants::quantifier_t quantifier,
    type_category_t typeCategory,
    content_kind_t contentKind)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, false),
  m_qname(qname),
  m_baseType(baseType),
  m_typeCategory(typeCategory),
  m_contentKind(contentKind)
{
  assert(typeCategory == ATOMIC_TYPE || typeCategory == COMPLEX_TYPE);

  ZORBA_ASSERT(baseType != NULL);
  ZORBA_ASSERT(typeCategory == ATOMIC_TYPE || quantifier == TypeConstants::QUANT_ONE);

  TRACE("UserDefinedXQType c2: " << m_qname->getLocalName()->str() << "@"
        << m_qname->getNamespace()->str() << " " << typeCategoryStr(m_typeCategory)
        << " " << contentKindStr(m_contentKind));
}


/*******************************************************************************
  Constructor for user-defined list types
********************************************************************************/
UserDefinedXQType::UserDefinedXQType(
    const TypeManager* manager,
    store::Item_t qname,
    const xqtref_t& baseType,
    TypeConstants::quantifier_t quantifier,
    const XQType* listItemType)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, false),
  m_qname(qname),
  m_baseType(baseType),
  m_typeCategory(LIST_TYPE),
  m_contentKind(SIMPLE_CONTENT_KIND),
  m_listItemType(listItemType)
{
  ZORBA_ASSERT(quantifier == TypeConstants::QUANT_ONE);
  ZORBA_ASSERT(listItemType);
}


/*******************************************************************************
  Constructor for user-defined union types
********************************************************************************/
UserDefinedXQType::UserDefinedXQType(
    const TypeManager* manager,
    store::Item_t qname,
    const xqtref_t& baseType,
    TypeConstants::quantifier_t quantifier,
    std::vector<xqtref_t>& unionItemTypes)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, false),
  m_qname(qname),
  m_baseType(baseType),
  m_typeCategory(UNION_TYPE),
  m_contentKind(SIMPLE_CONTENT_KIND),
  m_unionItemTypes(unionItemTypes)
{
  ZORBA_ASSERT(quantifier == TypeConstants::QUANT_ONE);
}


/*******************************************************************************

********************************************************************************/
void UserDefinedXQType::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, (XQType*)this);
  ar & m_qname;
  ar & m_baseType;
  SERIALIZE_ENUM(type_category_t, m_typeCategory);
  SERIALIZE_ENUM(content_kind_t, m_contentKind);
  ar & m_listItemType;
  ar & m_unionItemTypes;
}


/*******************************************************************************

********************************************************************************/
xqtref_t UserDefinedXQType::getBaseBuiltinType() const
{
  xqtref_t builtinType = m_baseType;

  while (builtinType->type_kind() == XQType::USER_DEFINED_KIND)
  {
    const UserDefinedXQType* tmp =
    reinterpret_cast<const UserDefinedXQType*>(builtinType.getp());

    builtinType = tmp->getBaseType();
  }

  return builtinType;
}


/*******************************************************************************

********************************************************************************/
bool UserDefinedXQType::isSuperTypeOf(
    const TypeManager* tm,
    const XQType& subType) const
{
  if (subType.type_kind() != XQType::USER_DEFINED_KIND)
    return false;

  const UserDefinedXQType* subtype = static_cast<const UserDefinedXQType*>(&subType);

  do
  {
    if (TypeOps::is_equal(tm, *this, *subtype))
      return true;

    if (subtype->type_kind() == XQType::USER_DEFINED_KIND)
    {
      subtype = static_cast<const UserDefinedXQType*>(subtype->getBaseType().getp());
    }
    else
    {
      return false;
    }
  }
  while(true);

  return false;
}


/*******************************************************************************

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
  while(true);

  return false;
}


/*******************************************************************************

********************************************************************************/
std::string UserDefinedXQType::typeCategoryStr(type_category_t typeCategory)
{
  switch(typeCategory)
  {
  case UserDefinedXQType::ATOMIC_TYPE:
    return "atomic";
  case UserDefinedXQType::COMPLEX_TYPE:
    return "complex";
  case UserDefinedXQType::LIST_TYPE:
    return "list";
  case UserDefinedXQType::UNION_TYPE:
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

  switch (m_typeCategory)
  {
  case ATOMIC_TYPE:
    info << "isAtomic";
    break;
  case COMPLEX_TYPE:
    info << "isComplex";
    break;
  case LIST_TYPE:
    info << " isList itemType:" << m_listItemType->toString();
    break;
  case UNION_TYPE:
    info << " isUnion " << m_unionItemTypes.size() << ":";
    for ( unsigned int i = 0; i < m_unionItemTypes.size(); i++)
    {
      info << m_unionItemTypes[i]->toString();
    }
    break;
  default:
    ZORBA_ASSERT(false);
  }

  info << " " << contentKindStr(m_contentKind);

  return os << "[UserDefinedXQType " << " "
            << TypeOps::decode_quantifier (get_quantifier()) << " "
            << m_qname->getLocalName() << "@"
            << m_qname->getNamespace() << " "
            << info.str()
            << " base:"
            << ( m_baseType ? TypeOps::toString(*m_baseType) : "NULL" )
            << " ]";
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


store::Item_t AnyXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME;
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


store::Item_t AnySimpleXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME;
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


store::Item_t UntypedXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
}


}  // namespace zorba
/* vim:set et sw=2 ts=2: */
