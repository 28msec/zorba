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
#include <zorba/identtypes.h>
#include <zorba/typeident.h>
#include "types/typeops.h"
#include "types/typeimpl.h"
#include "types/node_test.h"
#include "system/globalenv.h"
#include "store/api/item.h"
#include "types/root_typemanager.h"
#include "zorbaerrors/Assert.h"
#include "types/delegating_typemanager.h"

namespace zorba {


// Worth using if a function needs GENV_TYPESYSTEM more than once
#define CACHE_ROOT_TS( var ) RootTypeManager &var = GENV_TYPESYSTEM


/*******************************************************************************

********************************************************************************/
const char *TypeOps::decode_quantifier (TypeConstants::quantifier_t quant) 
{
  switch (quant) {
  case TypeConstants::QUANT_ONE:
    return "";
  case TypeConstants::QUANT_QUESTION:
    return "?";
  case TypeConstants::QUANT_STAR:
    return "*";
  case TypeConstants::QUANT_PLUS:
      return "+";
  default:
    return "<unknown-quant>";
  }
}


std::ostream& TypeOps::serialize(std::ostream& os, const XQType& type)
{
  return type.serialize(os);
}


std::string TypeOps::toString (const XQType& type)
{
  std::ostringstream os;
  serialize (os, type);
  return os.str ();
}


/*******************************************************************************

********************************************************************************/
const TypeManager *TypeOps::get_lower_manager(
    const TypeManager* m1,
    const TypeManager* m2)
{
  return m1->level() > m2->level() ? m2 : m1;
}


/*******************************************************************************

********************************************************************************/
TypeConstants::quantifier_t TypeOps::quantifier(const XQType &type)
{
  return type.get_quantifier();
}


/*******************************************************************************
  Returns the castability fron the source ItemType to the target ItemType. It
  works only if both source and target types are builtin atomic types.
  Otherwise, it returns NOT_CASTABLE.
********************************************************************************/
TypeConstants::castable_t TypeOps::castability(const XQType& src, const XQType& target)
{
  if (src.type_kind() == XQType::ATOMIC_TYPE_KIND &&
      target.type_kind() == XQType::ATOMIC_TYPE_KIND) 
  {
    const AtomicXQType& aSrc = static_cast<const AtomicXQType&>(src);
    const AtomicXQType& aTarget = static_cast<const AtomicXQType&>(target);
    return RootTypeManager::ATOMIC_CAST_MATRIX[aSrc.get_type_code()][aTarget.get_type_code()];
  }
  // incorect should work for other than built-in types or at least rename it.
  return TypeConstants::NOT_CASTABLE;
}


/*******************************************************************************
  Returns true iff type1 is equal to type2 including the quantifier.
********************************************************************************/
bool TypeOps::is_equal(const XQType& type1, const XQType& type2)
{
  if (&type1 == &type2) return true;

  if (type1.get_quantifier() != type2.get_quantifier()) 
  {
    return false;
  }

  if (type1.type_kind() != type2.type_kind()) 
  {
    return false;
  }

  switch(type1.type_kind()) 
  {
    case XQType::ATOMIC_TYPE_KIND:
    {
      const AtomicXQType& a1 = static_cast<const AtomicXQType&>(type1);
      const AtomicXQType& a2 = static_cast<const AtomicXQType&>(type2);

      return a1.get_type_code() == a2.get_type_code();
    }
    case XQType::NODE_TYPE_KIND:
    {
      const NodeXQType& n1 = static_cast<const NodeXQType&>(type1);
      const NodeXQType& n2 = static_cast<const NodeXQType&>(type2);

      // Must compare content type as well ????
      return *n1.get_nodetest() == *n2.get_nodetest();
    }
    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udt1 = static_cast<const UserDefinedXQType&>(type1);
      const UserDefinedXQType& udt2 = static_cast<const UserDefinedXQType&>(type2);
      return udt1.get_qname()->equals(udt2.get_qname());
    }
    default:
      break;
  }

  return true;
}


/*******************************************************************************
  Returns true iff "subtype" is a subtype of "supertype".
********************************************************************************/
bool TypeOps::is_subtype(const XQType& subtype, const XQType& supertype)
{
  if (subtype.type_kind() == XQType::NONE_KIND)
    return true;

  if (!RootTypeManager::QUANT_SUBTYPE_MATRIX[subtype.get_quantifier()]
                                            [supertype.get_quantifier()])
    return false;

  switch(supertype.type_kind()) 
  {
    case XQType::ATOMIC_TYPE_KIND:
    {
      switch(subtype.type_kind()) 
      {
      case XQType::ATOMIC_TYPE_KIND:
      {
        const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
        const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);

        return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()][a2.get_type_code()];
      }
      case XQType::USER_DEFINED_KIND:
      {
        const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);
        if (!udSubType.isAtomic())
          return false;

        //std::cout << "!!!!!!!!!!!! atomic-udt" << std::endl;
        // ????
        return false; 
      }
      case XQType::EMPTY_KIND:
      {
        return true;
      }
      default:
      {
        // NODE, ITEM, ANY, ANY_SIMPLE, UNTYPED, EMPTY 
        return false;
      }
      }
      break;
    }

    case XQType::NODE_TYPE_KIND:
    {
      switch(subtype.type_kind())
      {
      case XQType::NODE_TYPE_KIND:
      {
        const NodeXQType& n1 = static_cast<const NodeXQType&>(subtype);
        const NodeXQType& n2 = static_cast<const NodeXQType&>(supertype);

        //std::cout << "!!!!!!!!!!!! node-node" << std::endl;
        // ??? What about content type?
        return n1.get_nodetest()->is_sub_nodetest_of(*n2.get_nodetest());
      }
      case XQType::EMPTY_KIND:
      {
        return true;
      }
      default:
      {
        // ATOMIC, ITEM, ANY, ANY_SIMPLE, UNTYPED, USER_DEFINED (???)
        return false;
      }
      }
      break;
    }

    case XQType::ITEM_KIND:
    {
      switch(subtype.type_kind())
      {
      case XQType::ATOMIC_TYPE_KIND:
      case XQType::NODE_TYPE_KIND:
      case XQType::ITEM_KIND:
      case XQType::EMPTY_KIND:
        return true;

      case XQType::USER_DEFINED_KIND:
      {
        const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);

        // What about union of atomic types ????
        return udSubType.isAtomic();
      }

      default:
        // ANY, ANY_SIMPLE, UNTYPED
        return false;
      }
      break;
    }

    case XQType::ANY_TYPE_KIND:
    {
      switch(subtype.type_kind()) 
      {
      case XQType::ATOMIC_TYPE_KIND:
      case XQType::NODE_TYPE_KIND:
      case XQType::ITEM_KIND:
      case XQType::ANY_TYPE_KIND:
      case XQType::ANY_SIMPLE_TYPE_KIND:
      case XQType::UNTYPED_KIND:
      case XQType::EMPTY_KIND:
      case XQType::USER_DEFINED_KIND:
        return true;

      default:
        ZORBA_ASSERT(false);
      }
      break;
    }

    case XQType::ANY_SIMPLE_TYPE_KIND:
    {
      switch(subtype.type_kind())
      {
      case XQType::ATOMIC_TYPE_KIND:
      case XQType::ANY_SIMPLE_TYPE_KIND:
      case XQType::EMPTY_KIND:
          return true;

      case XQType::USER_DEFINED_KIND:
      {
        const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);
        return (udSubType.isAtomic() || udSubType.isList() || udSubType.isUnion());
      }

      default:
        // ANY, UNTYPED
        return false;
      }
      break;
    }

    case XQType::UNTYPED_KIND:
    {
      switch(subtype.type_kind()) 
      {
      case XQType::UNTYPED_KIND:
        return true;

      default:
        return false;
      }
      break;
    }

    case XQType::EMPTY_KIND:
    {
      switch(subtype.type_kind()) 
      {
      case XQType::EMPTY_KIND:
        return true;

      default:
        return false;
      }
      break;
    }

    case XQType::NONE_KIND:
    {
      return false;
    }

    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udSuperType = dynamic_cast<const UserDefinedXQType&>(supertype);

      // std::cout << "!!!!!!!!!!!! udt" << std::endl;
      // ????
      return udSuperType.isSuperTypeOf(subtype);
    }
  }

  return false;
}


/*******************************************************************************
  
********************************************************************************/
bool TypeOps::is_treatable(const store::Item_t& item, const XQType& type)
{
  switch(type.type_kind()) 
  {
  case XQType::NODE_TYPE_KIND: 
  {
    if (!item->isNode())
      return false;
    
    const NodeXQType& nType = static_cast<const NodeXQType&>(type);
    rchandle<NodeTest> nodeTest = nType.get_nodetest();
    store::StoreConsts::NodeKind kind = nodeTest->get_node_kind();
    rchandle<NodeNameTest> nameTest = nodeTest->get_nametest();

    if (kind != store::StoreConsts::anyNode && kind != item->getNodeKind())
      return false;

    if (nameTest != NULL && ! nameTest->matches (item->getNodeName ()))
      return false;

    // TODO: check content type ????
    return true;
  }

  default:
    break;
  }

  return is_subtype(*type.get_manager()->create_value_type(item.getp()), type);
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_atomic(const XQType& type)
{
  return type.get_quantifier() == TypeConstants::QUANT_ONE &&
         type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_simple(const XQType& type)
{
  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::is_numeric(const XQType& type)
{
  CACHE_ROOT_TS (genv_ts);
  return is_subtype(type, *genv_ts.DOUBLE_TYPE_QUESTION)
    || is_subtype(type, *genv_ts.FLOAT_TYPE_QUESTION)
    || is_subtype(type, *genv_ts.DECIMAL_TYPE_QUESTION);
}

bool TypeOps::is_numeric_or_untyped(const XQType& type)
{
  CACHE_ROOT_TS (genv_ts);
  return is_subtype(type, *genv_ts.DOUBLE_TYPE_QUESTION)
    || is_subtype(type, *genv_ts.FLOAT_TYPE_QUESTION)
    || is_subtype(type, *genv_ts.DECIMAL_TYPE_QUESTION)
    || is_subtype (type, *genv_ts.UNTYPED_ATOMIC_TYPE_QUESTION);
}

bool TypeOps::is_empty(const XQType& type) 
{
  return type.type_kind () == XQType::EMPTY_KIND;
}


bool TypeOps::is_none(const XQType& type) 
{
  return type.type_kind () == XQType::NONE_KIND;
}


/*******************************************************************************

********************************************************************************/
bool TypeOps::maybe_date_time(const XQType& type) 
{
  const XQType &prime = *prime_type(type);

  switch (prime.type_kind()) 
  {
  case XQType::ATOMIC_TYPE_KIND:
    switch (static_cast<const AtomicXQType &> (type).get_type_code ()) {
    case TypeConstants::XS_ANY_ATOMIC:
    case TypeConstants::XS_DATE:
    case TypeConstants::XS_TIME:
    case TypeConstants::XS_DATETIME:
    case TypeConstants::XS_GYEAR_MONTH:
    case TypeConstants::XS_GYEAR:
    case TypeConstants::XS_GMONTH_DAY:
    case TypeConstants::XS_GDAY:
    case TypeConstants::XS_GMONTH:
      return true;
    default: return false;
    }
    break;

  case XQType::ANY_TYPE_KIND:
  case XQType::ANY_SIMPLE_TYPE_KIND:
  case XQType::ITEM_KIND:
    return true;
  case XQType::USER_DEFINED_KIND:
    return true;  // TODO: finer analysis
  default:
    // NODE, EMPTY, NONE
    return false;
  }
}


/*******************************************************************************

********************************************************************************/
TypeConstants::atomic_type_code_t TypeOps::get_atomic_type_code(const XQType& type)
{
  assert(type.type_kind() == XQType::ATOMIC_TYPE_KIND);
  return (static_cast<const AtomicXQType&>(type)).get_type_code();
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::union_type(const XQType& type1, const XQType& type2)
{
  const TypeManager *mgr = get_lower_manager(type1.get_manager(), type2.get_manager());
  if (is_subtype (type1, type2))
    return &type2;
  else if (is_subtype (type2, type1))
    return &type1;
  else if (is_empty (type1))
    return mgr->create_type_x_quant (type2, TypeConstants::QUANT_QUESTION);
  else if (is_empty (type2))
    return mgr->create_type_x_quant (type1, TypeConstants::QUANT_QUESTION);
  else if (quantifier (type1) == TypeConstants::QUANT_ONE && quantifier (type2) == TypeConstants::QUANT_ONE) {
    if (type1.type_kind () == type2.type_kind ())
      switch (type1.type_kind ()) {
      case XQType::ATOMIC_TYPE_KIND:
        return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
      case XQType::NODE_TYPE_KIND:
          return GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
      default:
        break;
      }
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  } else {
    xqtref_t pt1 = prime_type (type1), pt2 = prime_type (type2);
    if (! is_equal (type1, *pt1) || ! is_equal (type2, *pt2))
      return mgr->create_type_x_quant (*union_type (*pt1, *pt2),
                           RootTypeManager::QUANT_UNION_MATRIX [TypeConstants::QUANT_QUESTION] /* to be on the safe side */
                                              [RootTypeManager::QUANT_UNION_MATRIX [quantifier (type1)] [quantifier (type2)]]);
    else
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::intersect_type(const XQType& type1, const XQType& type2)
{
  const TypeManager *mgr = get_lower_manager(type1.get_manager(), type2.get_manager());
  XQType::type_kind_t tk1 = type1.type_kind (), tk2 = type2.type_kind ();

  if (tk1 < tk2)
    return intersect_type (type2, type1);

  TypeConstants::quantifier_t q1 = quantifier (type1), q2 = quantifier (type2);

  if (is_subtype (type1, type2))
    return &type1;

  else if (is_subtype (type2, type1))
    return &type2;

  else if (tk1 == XQType::EMPTY_KIND)
    return (q2 == TypeConstants::QUANT_QUESTION || q2 == TypeConstants::QUANT_STAR
            ? GENV_TYPESYSTEM.EMPTY_TYPE : GENV_TYPESYSTEM.NONE_TYPE);

  else if (tk2 == XQType::EMPTY_KIND)
    return (q1 == TypeConstants::QUANT_QUESTION || q1 == TypeConstants::QUANT_STAR)
      ? GENV_TYPESYSTEM.EMPTY_TYPE : GENV_TYPESYSTEM.NONE_TYPE;

  else if (q1 == TypeConstants::QUANT_ONE && q2 == TypeConstants::QUANT_ONE) 
  {
    switch (tk1) 
    {
    case XQType::ATOMIC_TYPE_KIND:
      if (tk2 == XQType::NODE_TYPE_KIND || tk2 == XQType::ATOMIC_TYPE_KIND)
        return GENV_TYPESYSTEM.NONE_TYPE;
      else
        return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
      break;

    case XQType::NODE_TYPE_KIND:
      return (tk2 == XQType::NODE_TYPE_KIND) ? GENV_TYPESYSTEM.NONE_TYPE : GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE; // ????

    default:
      break;
    }

    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }

  else 
  {
    xqtref_t pt1 = prime_type (type1), pt2 = prime_type (type2);
    if (! is_equal (type1, *pt1) || ! is_equal (type2, *pt2)) {
      xqtref_t pti = intersect_type (*pt1, *pt2);
      return mgr->create_type_x_quant (*pti, RootTypeManager::QUANT_INTERS_MATRIX [q1] [q2]);
    } else return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }
}

TypeConstants::quantifier_t TypeOps::intersect_quant(TypeConstants::quantifier_t q1,
                                                        TypeConstants::quantifier_t q2)
{
  return RootTypeManager::QUANT_INTERS_MATRIX [q1] [q2];
}

/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::prime_type(const XQType& type) 
{
  switch (type.type_kind ()) 
  {
  case XQType::EMPTY_KIND:
    return GENV_TYPESYSTEM.NONE_TYPE;

  case XQType::ATOMIC_TYPE_KIND: 
  {
    const AtomicXQType& atype = static_cast<const AtomicXQType&>(type);
    return type.get_manager()->create_atomic_type(atype.get_type_code(),
                                                  TypeConstants::QUANT_ONE);
  }
  case XQType::NONE_KIND:
    return &type;

  case XQType::ITEM_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

  case XQType::ANY_TYPE_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;

  case XQType::UNTYPED_KIND:
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;

  case XQType::NODE_TYPE_KIND: 
  {
    const NodeXQType& ntype = static_cast<const NodeXQType&>(type);
    return type.get_manager()->create_node_type(ntype.get_nodetest(),
                                                ntype.get_content_type(),
                                                TypeConstants::QUANT_ONE,
                                                ntype.get_nillable());
  }
  case XQType::USER_DEFINED_KIND:
  {
    const UserDefinedXQType& udType = static_cast<const UserDefinedXQType&>(type);
    const DelegatingTypeManager* delTM = static_cast<const DelegatingTypeManager*>(type.get_manager());

    return delTM->create_named_type(udType.get_qname(), TypeConstants::QUANT_ONE);
  }

  default:
    ZORBA_ASSERT(false);
    return NULL;
  }
}


/*******************************************************************************

********************************************************************************/
xqtref_t TypeOps::arithmetic_type_exact(const XQType& type1, const XQType& type2)
{
  CACHE_ROOT_TS (genv_ts);
  if (TypeOps::is_subtype(type1, *genv_ts.UNTYPED_ATOMIC_TYPE_ONE)
    || TypeOps::is_subtype(type2, *genv_ts.UNTYPED_ATOMIC_TYPE_ONE)) {
    return genv_ts.DOUBLE_TYPE_ONE;
  }
 
  if (TypeOps::is_subtype(type1, *genv_ts.DOUBLE_TYPE_ONE)
    || TypeOps::is_subtype(type2, *genv_ts.DOUBLE_TYPE_ONE)) {
    return genv_ts.DOUBLE_TYPE_ONE;
  }
 
  if (TypeOps::is_subtype(type1, *genv_ts.FLOAT_TYPE_ONE)
    || TypeOps::is_subtype(type2, *genv_ts.FLOAT_TYPE_ONE)) {
    return genv_ts.FLOAT_TYPE_ONE;
  }

  if (TypeOps::is_subtype(type1, *genv_ts.INTEGER_TYPE_ONE)
    && TypeOps::is_subtype(type2, *genv_ts.INTEGER_TYPE_ONE)) {
    return genv_ts.INTEGER_TYPE_ONE;
  }

  if (TypeOps::is_subtype(type1, *genv_ts.DECIMAL_TYPE_ONE)
    && TypeOps::is_subtype(type2, *genv_ts.DECIMAL_TYPE_ONE)) {
    return genv_ts.DECIMAL_TYPE_ONE;
  }

  return NULL;
}

xqtref_t TypeOps::arithmetic_type_static(const XQType& type1, const XQType& type2)
{
  xqtref_t aType = arithmetic_type_exact(type1, type2);
  if (aType != NULL) {
    return aType;
  }
  xqtref_t pt1 = TypeOps::prime_type(type1);
  xqtref_t pt2 = TypeOps::prime_type(type2);

  TypeConstants::quantifier_t iquant = RootTypeManager::QUANT_UNION_MATRIX[type1.get_quantifier()][type2.get_quantifier()];

  aType = arithmetic_type_exact(*pt1, *pt2);
  if (aType == NULL) {
    return NULL;
  }
  return aType->get_manager()->create_type(*aType, iquant);
}

xqtref_t TypeOps::arithmetic_type(const XQType& type1, const XQType& type2)
{
  CACHE_ROOT_TS (genv_ts);
  xqtref_t aType = arithmetic_type_static(type1, type2);
  if (aType == NULL) {
    return genv_ts.INTEGER_TYPE_ONE;
  }
  return aType;
}
/*******************************************************************************

********************************************************************************/
rchandle<NodeNameTest> TypeOps::get_nametest(const XQType& type)
{
  if (type.type_kind() == XQType::NODE_TYPE_KIND) {
    const NodeXQType& n = static_cast<const NodeXQType&>(type);
    const NodeTest *nt = n.get_nodetest().getp();
    if (nt) {
      return rchandle<NodeNameTest>(nt->get_nametest());
    }
  }
  return rchandle<NodeNameTest>(0);
}


/*******************************************************************************

********************************************************************************/
static inline IdentTypes::quantifier_t get_typeident_quant(TypeConstants::quantifier_t quant)
{
  switch(quant) {
    case TypeConstants::QUANT_ONE:
      return IdentTypes::QUANT_ONE;

    case TypeConstants::QUANT_QUESTION:
      return IdentTypes::QUANT_QUESTION;

    case TypeConstants::QUANT_STAR:
      return IdentTypes::QUANT_STAR;

    case TypeConstants::QUANT_PLUS:
      return IdentTypes::QUANT_PLUS;

    default:
      break;
  }

  return IdentTypes::QUANT_ONE;
}


/*******************************************************************************

********************************************************************************/
type_ident_ref_t TypeOps::get_type_identifier(const XQType& type)
{
  IdentTypes::quantifier_t q = get_typeident_quant(quantifier(type));
  switch(type.type_kind()) 
  {
  case XQType::ATOMIC_TYPE_KIND:
  {
    const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
    store::Item* qname = GENV_TYPESYSTEM.m_atomic_typecode_qname_map[at.get_type_code()];
    return TypeIdentifier::createNamedType(qname->getNamespace(),
                                           qname->getLocalName(),
                                           q);
  }
  case XQType::NODE_TYPE_KIND:
  {
    const NodeXQType& nt = static_cast<const NodeXQType&>(type);
    type_ident_ref_t content_type = nt.get_content_type() != NULL ? get_type_identifier(*nt.get_content_type()) : type_ident_ref_t();
    const NodeTest *test = nt.get_nodetest().getp();
    const NodeNameTest *nametest = test->get_nametest().getp();
    switch(test->get_node_kind()) 
    {
    case store::StoreConsts::anyNode:
      return TypeIdentifier::createAnyNodeType(q);

    case store::StoreConsts::textNode:
      return TypeIdentifier::createTextType(q);

    case store::StoreConsts::piNode:
      return TypeIdentifier::createPIType(q);

    case store::StoreConsts::commentNode:
      return TypeIdentifier::createCommentType(q);

    case store::StoreConsts::documentNode:
      return TypeIdentifier::createDocumentType(content_type, q);

    case store::StoreConsts::elementNode:
      return TypeIdentifier::createElementType(&*nametest->get_uri(), nametest->get_uri() == NULL, &*nametest->get_local(), nametest->get_local() == NULL, content_type, q);
      
    case store::StoreConsts::attributeNode:
      return TypeIdentifier::createAttributeType(&*nametest->get_uri(), nametest->get_uri() == NULL, &*nametest->get_local(), nametest->get_local() == NULL, content_type, q);

    default:
      // cannot happen
      ZORBA_ASSERT(false);
      return type_ident_ref_t();
    }
  }
  case XQType::ANY_TYPE_KIND:
    return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME->getNamespace(), &*GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME->getLocalName(), q);

  case XQType::ITEM_KIND:
    return TypeIdentifier::createItemType(q);

  case XQType::ANY_SIMPLE_TYPE_KIND:
    return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME->getNamespace(), &*GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME->getLocalName(), q);

  case XQType::UNTYPED_KIND:
    return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_UNTYPED_QNAME->getNamespace(), &*GENV_TYPESYSTEM.XS_UNTYPED_QNAME->getLocalName(), q);
    
  case XQType::EMPTY_KIND:
    return TypeIdentifier::createEmptyType();

  case XQType::USER_DEFINED_KIND:
    //TODO for Vinayak return type identifier
  default:
    break;
  }
  ZORBA_ASSERT(false);
  return type_ident_ref_t();
}


/*******************************************************************************

********************************************************************************/
int TypeOps::type_max_cnt (const XQType& type) 
{
  return is_empty (type)
    ? 0
    : QUANT_MAX_CNT [quantifier (type)];
}


/*******************************************************************************

********************************************************************************/
int TypeOps::type_min_cnt (const XQType& type) 
{
  return is_empty (type)
    ? 0
    : QUANT_MIN_CNT [quantifier (type)];
}


/*******************************************************************************

********************************************************************************/
int TypeOps::type_cnt (const XQType& type) 
{
  if (is_empty(type) || is_none(type))
    return 0;

  TypeConstants::quantifier_t q = quantifier (type);
  if (QUANT_MIN_CNT [q] == QUANT_MAX_CNT [q])
    return QUANT_MIN_CNT [q];
  return -1;
}

store::Item_t TypeOps::getQName(const XQType& type)
{
  return type.get_qname();
}

//                                       1  ?  *  +
const int TypeOps::QUANT_MIN_CNT [4] = { 1, 0, 0, 1 };
const int TypeOps::QUANT_MAX_CNT [4] = { 1, 1, 2, 2 };

}
