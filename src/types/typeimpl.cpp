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
#include <iostream>
#include "system/globalenv.h"
#include "zorbaerrors/Assert.h"

#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "types/schema/schema.h"


namespace zorba
{

//#define DO_TRACE

#ifdef DO_TRACE
#define TRACE(msg)                                                            \
  {std::cout << __FUNCTION__ << ": " << msg << std::endl; std::cout.flush(); }
#else
#define TRACE(msg)
#endif


SERIALIZABLE_CLASS_VERSIONS(XQType)
END_SERIALIZABLE_CLASS_VERSIONS(XQType)

SERIALIZABLE_CLASS_VERSIONS(AtomicXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AtomicXQType)

SERIALIZABLE_CLASS_VERSIONS(NodeXQType)
END_SERIALIZABLE_CLASS_VERSIONS(NodeXQType)

SERIALIZABLE_CLASS_VERSIONS(FunctionXQType)
END_SERIALIZABLE_CLASS_VERSIONS(FunctionXQType)

SERIALIZABLE_CLASS_VERSIONS(ItemXQType)
END_SERIALIZABLE_CLASS_VERSIONS(ItemXQType)

SERIALIZABLE_CLASS_VERSIONS(AnyXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AnyXQType)

SERIALIZABLE_CLASS_VERSIONS(AnySimpleXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AnySimpleXQType)

SERIALIZABLE_CLASS_VERSIONS(AnyFunctionXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AnyFunctionXQType)

SERIALIZABLE_CLASS_VERSIONS(UntypedXQType)
END_SERIALIZABLE_CLASS_VERSIONS(UntypedXQType)

SERIALIZABLE_CLASS_VERSIONS(EmptyXQType)
END_SERIALIZABLE_CLASS_VERSIONS(EmptyXQType)

SERIALIZABLE_CLASS_VERSIONS(NoneXQType)
END_SERIALIZABLE_CLASS_VERSIONS(NoneXQType)

SERIALIZABLE_CLASS_VERSIONS(UserDefinedXQType)
END_SERIALIZABLE_CLASS_VERSIONS(UserDefinedXQType)


const char* XQType::KIND_STRINGS[XQType::MAX_TYPE_KIND] =
{
  "EMPTY_KIND",
  "ATOMIC_TYPE_KIND",
  "ITEM_KIND",
  "NODE_TYPE_KIND",
  "FUNCTION_TYPE_KIND",
  "ANY_TYPE_KIND",
  "ANY_SIMPLE_TYPE_KIND",
  "ANY_FUNCTION_TYPE_KIND",
  "UNTYPED_KIND",
  "NONE_KIND",
  "USER_DEFINED_KIND"
};


const char *AtomicXQType::ATOMIC_TYPE_CODE_STRINGS[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE] =
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
  "xs:NOTATION"
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
    result = "empty-sequence()";
    break;
  case ATOMIC_TYPE_KIND:
    result = "xs:anyAtomicType()";
    break;
  case ITEM_KIND:
    result = "item()";
    break;
  case NODE_TYPE_KIND:
    result = "node()";
    break;
  case FUNCTION_TYPE_KIND:
    result = "function(...) as ...";
    break;
  case ANY_TYPE_KIND:
    result = "xs:anyType";
    break;
  case ANY_SIMPLE_TYPE_KIND:
    result = "xs:anySimpleType";
    break;
  case ANY_FUNCTION_TYPE_KIND:
    result = "function(*)";
    break;
  case UNTYPED_KIND:
    result = "xs:untyped";
    break;
  default:
      return toString();
      break;
  }

  result += TypeOps::decode_quantifier(get_quantifier());
  return result;
}

/*******************************************************************************

********************************************************************************/
std::ostream& AtomicXQType::serialize_ostream(std::ostream& os) const
{
  return os << ATOMIC_TYPE_CODE_STRINGS[get_type_code()]
            << TypeOps::decode_quantifier (get_quantifier());
}


store::Item_t AtomicXQType::get_qname() const
{
  return GENV_TYPESYSTEM.m_atomic_typecode_qname_map[m_type_code];
}


/*******************************************************************************

********************************************************************************/
store::Item_t AnyXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME;
}


/*******************************************************************************

********************************************************************************/
store::Item_t AnySimpleXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME;
}


/*******************************************************************************

********************************************************************************/
store::Item_t UntypedXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
}


/*******************************************************************************

********************************************************************************/
NodeXQType::NodeXQType(
    const TypeManager* manager,
    store::StoreConsts::NodeKind nodeKind,
    const store::Item_t& nodeName,
    xqtref_t contentType,
    TypeConstants::quantifier_t quantifier,
    bool nillable,
    bool schematest,
    bool builtin)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier, builtin),
  m_node_kind(nodeKind),
  m_node_name(nodeName),
  m_content_type(contentType),
  m_nillable(nillable),
  m_schema_test(schematest)
{
}


NodeXQType::NodeXQType(
    const NodeXQType& source,
    TypeConstants::quantifier_t quantifier)
  :
  XQType(source.m_manager, NODE_TYPE_KIND, quantifier, false),
  m_node_kind(source.m_node_kind),
  m_node_name(source.m_node_name),
  m_content_type(source.m_content_type),
  m_nillable(source.m_nillable),
  m_schema_test(source.m_schema_test)
{
}


bool NodeXQType::is_untyped() const
{
  return m_content_type == GENV_TYPESYSTEM.UNTYPED_TYPE;
}


bool NodeXQType::is_equal(const NodeXQType& other) const
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
    return TypeOps::is_equal(*c1, *c2);

  if (c1 == NULL)
    return (c2->type_kind() == XQType::ANY_TYPE_KIND);
  else
    return (c1->type_kind() == XQType::ANY_TYPE_KIND);

  return false;
}


bool NodeXQType::is_subtype(const NodeXQType& supertype) const
{
  if (supertype.m_node_kind == store::StoreConsts::anyNode)
    return true;

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
        Schema* schema = supertype.m_manager->getSchema();
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

  if (m_content_type == supertype.m_content_type)
    return true;

  if (supertype.m_node_kind == store::StoreConsts::anyNode &&
      supertype.m_content_type != NULL &&
      supertype.m_content_type->type_kind() == XQType::UNTYPED_KIND)
  {
    return (m_content_type != NULL &&
            m_content_type->type_kind() == XQType::UNTYPED_KIND);
  }

  if (m_content_type != NULL && supertype.m_content_type != NULL)
  {
    return TypeOps::is_subtype(*m_content_type, *supertype.m_content_type);
  }
  else if (supertype.m_content_type == NULL)
  {
    return true;
  }
  else
  {
    return supertype.m_content_type->type_kind() == XQType::ANY_TYPE_KIND;
  }

  return false;
}


std::ostream& NodeXQType::serialize_ostream(std::ostream& os) const
{
  store::StoreConsts::NodeKind node_kind = m_node_kind;
  xqtref_t content_type = get_content_type();

  os << "[NodeXQType " << store::StoreConsts::toString(node_kind)
     << TypeOps::decode_quantifier(get_quantifier()) << " ";

  if (m_node_name != NULL)
  {
    os << "nametest=[uri: " << m_node_name->getNamespace()->c_str()
       << ", local: " << m_node_name->getLocalName()->c_str() << "]";
  }

  if (content_type != NULL)
  {
    os << " content=";
    os << content_type->toString ();
  }

  return os << "]";
}


/*******************************************************************************

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


bool
FunctionXQType::is_equal(const FunctionXQType& other) const
{
  return true;
}


/** 
 * Bi is function(Ba_1, Ba_2, ... Ba_N) as Br,
 * Ai is function(Aa_1, Aa_2, ... Aa_M) as Ar,
 * Ai is subtype of Bi iff
 * N (arity of Bi) equals M (arity of Ai),
 * subtype(Ar, Br), and
 * for values of I between 1 and N, subtype(Ba_I, Aa_I).
 */
bool
FunctionXQType::is_subtype(const FunctionXQType& supertype) const
{
  if (this->get_number_params() != supertype.get_number_params()) {
    return false;
  }

  if (!TypeOps::is_subtype(*get_return_type().getp(), *supertype.get_return_type().getp())) {
    return false;
  }

  size_t i = 0;
  for (std::vector<xqtref_t>::const_iterator lIter = m_param_types.begin();
       lIter != m_param_types.end(); ++lIter) {
    if (!TypeOps::is_subtype(*lIter->getp(), *supertype[i++].getp())) {
      return false;
    }
  }

  return true;
}


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
  os << m_return_type->toString ();
  os  << "]";

  return os << "]";
}

/*******************************************************************************

********************************************************************************/
// constructor for Atomic and Complex types
UserDefinedXQType::UserDefinedXQType(
    const TypeManager *manager,
    store::Item_t qname,
    xqtref_t baseType,
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
  ZORBA_ASSERT(baseType!=NULL);

  TRACE("UserDefinedXQType c2: " << m_qname->getLocalName()->str() << "@"
        << m_qname->getNamespace()->str() << " " << typeCategoryStr(m_typeCategory)
        << " " << contentKindStr(m_contentKind));
}


// Constructor for List types
UserDefinedXQType::UserDefinedXQType(
    const TypeManager *manager,
    store::Item_t qname,
    xqtref_t baseType,
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
  ZORBA_ASSERT( listItemType );
}


// Constructor for Union types
UserDefinedXQType::UserDefinedXQType(
    const TypeManager *manager,
    store::Item_t qname,
    xqtref_t baseType,
    TypeConstants::quantifier_t quantifier,
    std::vector<xqtref_t> unionItemTypes)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, false),
  m_qname(qname),
  m_baseType(baseType),
  m_typeCategory(UNION_TYPE),
  m_contentKind(SIMPLE_CONTENT_KIND),
  m_unionItemTypes(unionItemTypes)
{
}


bool UserDefinedXQType::isSuperTypeOf(const XQType& subType) const
{
  if (subType.type_kind() != XQType::USER_DEFINED_KIND)
    return false;

  const UserDefinedXQType* subtype = static_cast<const UserDefinedXQType*>(&subType);

  do
  {
    if (TypeOps::is_equal(*this, *subtype))
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


bool UserDefinedXQType::isSubTypeOf(const XQType& supertype) const
{
  const XQType* subtype = this;

  do
  {
    if (TypeOps::is_equal(*subtype, supertype))
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
      return TypeOps::is_subtype(*subtype, supertype);
    }
  }
  while(true);

  return false;
}

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
            << m_qname->getLocalName()->str() << "@"
            << m_qname->getNamespace()->str() << " "
            << info.str()
            << " base:"
            << ( m_baseType ? TypeOps::toString(*m_baseType) : "NULL" )
            << " ]";
}

}  // namespace zorba
