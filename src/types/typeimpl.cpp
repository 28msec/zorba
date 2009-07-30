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
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/root_typemanager.h"
#include "zorbaerrors/Assert.h"


namespace zorba 
{

SERIALIZABLE_CLASS_VERSIONS(XQType)
END_SERIALIZABLE_CLASS_VERSIONS(XQType)

SERIALIZABLE_CLASS_VERSIONS(AtomicXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AtomicXQType)

SERIALIZABLE_CLASS_VERSIONS(NodeXQType)
END_SERIALIZABLE_CLASS_VERSIONS(NodeXQType)

SERIALIZABLE_CLASS_VERSIONS(ItemXQType)
END_SERIALIZABLE_CLASS_VERSIONS(ItemXQType)

SERIALIZABLE_CLASS_VERSIONS(AnyXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AnyXQType)

SERIALIZABLE_CLASS_VERSIONS(AnySimpleXQType)
END_SERIALIZABLE_CLASS_VERSIONS(AnySimpleXQType)

SERIALIZABLE_CLASS_VERSIONS(UntypedXQType)
END_SERIALIZABLE_CLASS_VERSIONS(UntypedXQType)

SERIALIZABLE_CLASS_VERSIONS(EmptyXQType)
END_SERIALIZABLE_CLASS_VERSIONS(EmptyXQType)

SERIALIZABLE_CLASS_VERSIONS(NoneXQType)
END_SERIALIZABLE_CLASS_VERSIONS(NoneXQType)

SERIALIZABLE_CLASS_VERSIONS(UserDefinedXQType)
END_SERIALIZABLE_CLASS_VERSIONS(UserDefinedXQType)


#if 0
static void foo()
{
  std::cout << "..." << std::endl;
}
#endif


const char* XQType::KIND_STRINGS[XQType::MAX_TYPE_KIND] =
{
  "EMPTY_KIND",
  "ATOMIC_TYPE_KIND",
  "ITEM_KIND",
  "NODE_TYPE_KIND",
  "ANY_TYPE_KIND",
  "ANY_SIMPLE_TYPE_KIND",
  "UNTYPED_KIND",
  "NONE_KIND"
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

std::ostream& XQType::serialize_ostream(std::ostream& os) const
{
  return os << "[XQType " << KIND_STRINGS[type_kind()]
            << TypeOps::decode_quantifier(get_quantifier()) << "]";
}


std::string XQType::toString() const
{
  std::ostringstream os;
  serialize_ostream(os);
  return os.str();
}


std::ostream& AtomicXQType::serialize_ostream(std::ostream& os) const
{
  return os << ATOMIC_TYPE_CODE_STRINGS[get_type_code()]
            << TypeOps::decode_quantifier (get_quantifier());
}

store::Item_t AtomicXQType::get_qname() const
{
  return GENV_TYPESYSTEM.m_atomic_typecode_qname_map[m_type_code];
}

store::Item_t AnyXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME;
}

store::Item_t AnySimpleXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME;
}

store::Item_t UntypedXQType::get_qname() const
{
  return GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
}


NodeXQType::NodeXQType(
    const TypeManager* manager,
    rchandle<NodeTest> nodetest,
    xqtref_t contentType,
    TypeConstants::quantifier_t quantifier,
    bool nillable,
    bool schematest,
    bool builtin)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier, builtin),
  m_nodetest(nodetest),
  m_content_type(contentType),
  m_nillable(nillable),
  m_schema_test(schematest)
{
}


NodeXQType::NodeXQType(
    const TypeManager* manager,
    store::StoreConsts::NodeKind nodekind,
    const store::Item* nodename,
    xqtref_t contentType,
    TypeConstants::quantifier_t quantifier,
    bool nillable,
    bool schematest,
    bool builtin)
  :
  XQType(manager, NODE_TYPE_KIND, quantifier, builtin),
  m_nodetest(new NodeTest(nodekind, nodename)),
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
  m_nodetest(source.m_nodetest),
  m_content_type(source.m_content_type),
  m_nillable(source.m_nillable),
  m_schema_test(source.m_schema_test)
{
}


bool NodeXQType::is_untyped() const
{
  return m_content_type == GENV_TYPESYSTEM.UNTYPED_TYPE;
}


std::ostream& NodeXQType::serialize_ostream(std::ostream& os) const
{
  rchandle<NodeTest> node_test = get_nodetest ();
  store::StoreConsts::NodeKind node_kind = node_test->get_node_kind();
  xqtref_t content_type = get_content_type ();
  rchandle<NodeNameTest> nametest = node_test->get_nametest();
  os << "[NodeXQType " << store::StoreConsts::toString (node_kind)
     << TypeOps::decode_quantifier (get_quantifier()) << " ";
  if (nametest != NULL) {
    os << "nametest=[uri: " << nametest->get_uri () << ", local: " << nametest->get_local () << "]";
  }
  if (content_type != NULL)
  {
    os << " content=";
    os << content_type->toString ();
  }
  return os << "]";
}


UserDefinedXQType::UserDefinedXQType(
    const TypeManager *manager,
    store::Item_t qname,
    xqtref_t baseType,
    TypeConstants::quantifier_t quantifier,
    content_kind_t contentKind)
  :
  XQType(manager, USER_DEFINED_KIND, quantifier, false),
  m_qname(qname),
  m_baseType(baseType),
  m_contentKind(contentKind)
{
  ZORBA_ASSERT(baseType!=NULL);

  switch (baseType.getp()->type_kind())
  {
  case USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udBaseType = static_cast<const UserDefinedXQType&>(*baseType);
    m_typeCategory = udBaseType.getTypeCategory();
    switch (m_typeCategory)
    {
    case ATOMIC_TYPE:
    case COMPLEX_TYPE:
    break;
      
    case LIST_TYPE:
      m_listItemType = udBaseType.getListItemType();
      break;
      
    case UNION_TYPE:
      m_unionItemTypes = udBaseType.getUnionItemTypes();
      break;
      
    default:
      ZORBA_ASSERT(false);
  }
    

    break;
  }
  case ATOMIC_TYPE_KIND:
  {
    m_typeCategory = ATOMIC_TYPE;
    break;
  }
  default:
  {
    m_typeCategory = COMPLEX_TYPE;            
  }        
  }        
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
