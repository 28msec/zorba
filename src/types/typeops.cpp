#include <boost/smart_ptr.hpp>
#include <zorba/identtypes.h>
#include <zorba/typeident.h>
#include "types/typeops.h"
#include "types/typeimpl.h"
#include "types/node_test.h"
#include "system/globalenv.h"
#include "store/api/item.h"
#include "types/root_typemanager.h"
#include "util/Assert.h"

namespace zorba {

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

const TypeManager *TypeOps::get_lower_manager(const TypeManager* m1, const TypeManager* m2)
{
  return m1->level() > m2->level() ? m2 : m1;
}

TypeConstants::quantifier_t TypeOps::quantifier(const XQType &type)
{
  return type.get_quantifier();
}

TypeConstants::castable_t TypeOps::castability(const XQType& src, const XQType& target)
{
  if (src.type_kind() == XQType::ATOMIC_TYPE_KIND && target.type_kind() == XQType::ATOMIC_TYPE_KIND) {
    const AtomicXQType& aSrc = static_cast<const AtomicXQType&>(src);
    const AtomicXQType& aTarget = static_cast<const AtomicXQType&>(target);
    return RootTypeManager::ATOMIC_CAST_MATRIX[aSrc.get_type_code()][aTarget.get_type_code()];
  }
  return TypeConstants::NOT_CASTABLE;
}

bool TypeOps::is_equal(const XQType& type1, const XQType& type2)
{
  if (&type1 == &type2) return true;
  if (type1.get_quantifier() != type2.get_quantifier()) {
    return false;
  }
  if (type1.type_kind() != type2.type_kind()) {
    return false;
  }
  switch(type1.type_kind()) {
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
      return *n1.get_nodetest() == *n2.get_nodetest();
    }
    default:
      break;
  }
  return true;
}

bool TypeOps::is_subtype(const XQType& subtype, const XQType& supertype)
{
  if (is_equal(subtype, *GENV_TYPESYSTEM.NONE_TYPE))
    return true;
  if (is_equal (subtype, supertype))
    return true;
  if (is_equal (subtype, *GENV_TYPESYSTEM.EMPTY_TYPE) && quantifier (supertype) != TypeConstants::QUANT_ONE)
    return true;
  if (!RootTypeManager::QUANT_SUBTYPE_MATRIX[subtype.get_quantifier()][supertype.get_quantifier()])
    return false;
  switch(supertype.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        {
          const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
          const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);
          return RootTypeManager::ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()][a2.get_type_code()];
        }
        case XQType::USER_DEFINED_KIND:
        {
            const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);
            return udSubType.isSubTypeOf(supertype);
        }
        default:
          return false;
      }
      break;

    case XQType::NODE_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::NODE_TYPE_KIND:
        {
          const NodeXQType& n1 = static_cast<const NodeXQType&>(subtype);
          const NodeXQType& n2 = static_cast<const NodeXQType&>(supertype);
          return n1.get_nodetest()->is_sub_nodetest_of(*n2.get_nodetest());
        }
        default:
          return false;
      }
      break;

    case XQType::ANY_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        case XQType::NODE_TYPE_KIND:
        case XQType::ANY_TYPE_KIND:
        case XQType::ANY_SIMPLE_TYPE_KIND:
        case XQType::UNTYPED_KIND:
        case XQType::USER_DEFINED_KIND:
          return true;

        default:
          return false;
      }
      break;

    case XQType::ITEM_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        case XQType::NODE_TYPE_KIND:
        case XQType::ITEM_KIND:
          return true;

        default:
          return false;
      }
      break;

    case XQType::ANY_SIMPLE_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        case XQType::ANY_SIMPLE_TYPE_KIND:
          return true;

        case XQType::USER_DEFINED_KIND:
        {
            const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);
            return udSubType.isAtomic();
        }

        default:
          return false;
      }
      break;

    case XQType::UNTYPED_KIND:
      switch(subtype.type_kind()) {
        case XQType::UNTYPED_KIND:
          return true;

        default:
          return false;
      }
      break;

    case XQType::EMPTY_KIND:
      switch(subtype.type_kind()) {
        case XQType::EMPTY_KIND:
          return true;

        default:
          return false;
      }
      break;

    case XQType::NONE_KIND:
      return false;

    case XQType::USER_DEFINED_KIND:
      {
          const UserDefinedXQType& udSubType = static_cast<const UserDefinedXQType&>(subtype);
          return udSubType.isSubTypeOf(supertype);
      }
  }
  return false;
}

bool TypeOps::is_promotable(const XQType& srctype, const XQType& targettype)
{
  return false;
}

bool TypeOps::is_treatable(const store::Item_t item, const XQType& type)
{
  switch(type.type_kind()) {
  case XQType::NODE_TYPE_KIND: {
    if (!item->isNode())
      return false;
    
    const NodeXQType& nType = static_cast<const NodeXQType&>(type);
    rchandle<NodeTest> nodeTest = nType.get_nodetest();
    switch(nodeTest->get_kind()) {
    case store::StoreConsts::piNode:
      return item->getNodeKind() == store::StoreConsts::piNode
        && (nodeTest->get_nametest() == NULL
            || nodeTest->get_nametest()->get_local() == NULL
            || nodeTest->get_nametest()->get_local()->byteEqual(*item->getTarget().getStore()));
      
    default:
      break;
    }
  }

  default:
    break;
  }

  // TODO: remove above switch when item_type is complete
  return is_subtype(*type.get_manager()->item_type (item), type);
}

bool TypeOps::is_atomic(const XQType& type)
{
  return type.get_quantifier() == TypeConstants::QUANT_ONE && type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool TypeOps::is_simple(const XQType& type)
{
  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool TypeOps::is_numeric(const XQType& type)
{
  return is_subtype(type, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
    || is_subtype(type, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
    || is_subtype(type, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE);
}

TypeConstants::atomic_type_code_t TypeOps::get_atomic_type_code(const XQType& type)
{
  assert(type.type_kind() == XQType::ATOMIC_TYPE_KIND);
  return (static_cast<const AtomicXQType&>(type)).get_type_code();
}

xqtref_t TypeOps::union_type(const XQType& type1, const XQType& type2)
{
  const TypeManager *mgr = get_lower_manager(type1.get_manager(), type2.get_manager());
  if (is_subtype (type1, type2))
    return &type2;
  else if (is_subtype (type2, type1))
    return &type1;
  else if (is_equal (type1, *GENV_TYPESYSTEM.EMPTY_TYPE))
    return mgr->create_type_x_quant (type2, TypeConstants::QUANT_QUESTION);
  else if (is_equal (type2, *GENV_TYPESYSTEM.EMPTY_TYPE))
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
                           RootTypeManager::QUANT_MULT_MATRIX [TypeConstants::QUANT_QUESTION] /* to be on the safe side */
                                              [RootTypeManager::QUANT_MULT_MATRIX [quantifier (type1)] [quantifier (type2)]]);
    else
      return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }
}

xqtref_t TypeOps::intersect_type(const XQType& type1, const XQType& type2)
{
  const TypeManager *mgr = get_lower_manager(type1.get_manager(), type2.get_manager());
  XQType::type_kind_t tk1 = type1.type_kind (), tk2 = type2.type_kind ();

  if (tk1 < tk2)
    return intersect_type (type2, type2);

  TypeConstants::quantifier_t q1 = quantifier (type1), q2 = quantifier (type2);
  if (is_subtype (type1, type2))
    return &type1;
  else if (is_subtype (type2, type1))
    return &type2;
  else if (tk1 == XQType::EMPTY_KIND)
    return (q2 == TypeConstants::QUANT_QUESTION || q2 == TypeConstants::QUANT_STAR)
      ? GENV_TYPESYSTEM.EMPTY_TYPE : GENV_TYPESYSTEM.NONE_TYPE;
  else if (tk2 == XQType::EMPTY_KIND)
    return (q1 == TypeConstants::QUANT_QUESTION || q1 == TypeConstants::QUANT_STAR)
      ? GENV_TYPESYSTEM.EMPTY_TYPE : GENV_TYPESYSTEM.NONE_TYPE;
  else if (q1 == TypeConstants::QUANT_ONE && q2 == TypeConstants::QUANT_ONE) {
    switch (tk1) {
    case XQType::ATOMIC_TYPE_KIND:
      if (tk2 == XQType::NODE_TYPE_KIND || tk2 == XQType::ATOMIC_TYPE_KIND)
        return GENV_TYPESYSTEM.NONE_TYPE;
      else
        return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
      break;
    case XQType::NODE_TYPE_KIND:
      return (tk2 == XQType::NODE_TYPE_KIND) ? GENV_TYPESYSTEM.NONE_TYPE : GENV_TYPESYSTEM.ANY_NODE_TYPE_ONE;
    default: break;
    }
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  }
  else {
    xqtref_t pt1 = prime_type (type1), pt2 = prime_type (type2);
    if (! is_equal (type1, *pt1) || ! is_equal (type2, *pt2)) {
      xqtref_t pti = intersect_type (*pt1, *pt2);
      return mgr->create_type_x_quant (*pti, RootTypeManager::QUANT_INTERS_MATRIX [q1] [q2]);
    } else return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
  }
}

xqtref_t TypeOps::prime_type(const XQType& type)
{
  if (is_equal(type, *GENV_TYPESYSTEM.EMPTY_TYPE)) {
    return GENV_TYPESYSTEM.NONE_TYPE;
  } else if (type.type_kind() == XQType::ATOMIC_TYPE_KIND) {
    const AtomicXQType& atype = static_cast<const AtomicXQType&>(type);
    return type.get_manager()->create_atomic_type(atype.get_type_code(), TypeConstants::QUANT_ONE);
  } else if (is_equal(type, *GENV_TYPESYSTEM.NONE_TYPE)) {
    return GENV_TYPESYSTEM.NONE_TYPE;
  } else if (type.type_kind() == XQType::ITEM_KIND) {
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  } else if (is_equal(type, *GENV_TYPESYSTEM.ANY_TYPE)) {
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  } else if (is_equal(type, *GENV_TYPESYSTEM.ANY_SIMPLE_TYPE)) {
    return GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
  } else if (is_equal(type, *GENV_TYPESYSTEM.UNTYPED_TYPE)) {
    return GENV_TYPESYSTEM.ITEM_TYPE_ONE;
  } else if (type.type_kind() == XQType::NODE_TYPE_KIND) {
    const NodeXQType& ntype = static_cast<const NodeXQType&>(type);
    return type.get_manager()->create_node_type(ntype.get_nodetest(), ntype.get_content_type(), TypeConstants::QUANT_ONE);
  }
  ZORBA_ASSERT(false);

  return NULL;
}

xqtref_t TypeOps::arithmetic_type(const XQType& type1, const XQType& type2)
{
  if (is_subtype(type1, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
      || is_subtype(type2, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE)
      || is_subtype(type1, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)
      || is_subtype(type2, *GENV_TYPESYSTEM.DOUBLE_TYPE_ONE)) {
    return GENV_TYPESYSTEM.DOUBLE_TYPE_ONE;
  }
  if (is_subtype(type1, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)
      || is_subtype(type2, *GENV_TYPESYSTEM.FLOAT_TYPE_ONE)) {
    return GENV_TYPESYSTEM.FLOAT_TYPE_ONE;
  }
  bool b = is_subtype(type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE);
  b = is_subtype(type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE);
  if ((is_subtype(type1, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE)
       && !is_subtype(type1, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE))
       || (is_subtype(type2, *GENV_TYPESYSTEM.DECIMAL_TYPE_ONE))
       && !is_subtype(type2, *GENV_TYPESYSTEM.INTEGER_TYPE_ONE)) {
    return GENV_TYPESYSTEM.DECIMAL_TYPE_ONE;
  }

  return GENV_TYPESYSTEM.INTEGER_TYPE_ONE;
}

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

type_ident_ref_t TypeOps::get_type_identifier(const XQType& type)
{
  IdentTypes::quantifier_t q = get_typeident_quant(quantifier(type));
  switch(type.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      {
        const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
        store::Item_t& qname = *GENV_TYPESYSTEM.m_atomic_typecode_qname_map[at.get_type_code()];
        return TypeIdentifier::createNamedType(&*qname->getNamespace().theStrStore, &*qname->getLocalName().theStrStore, q);
      }
    case XQType::NODE_TYPE_KIND:
      {
        const NodeXQType& nt = static_cast<const NodeXQType&>(type);
        type_ident_ref_t content_type = nt.get_content_type() != NULL ? get_type_identifier(*nt.get_content_type()) : type_ident_ref_t();
        const NodeTest *test = nt.get_nodetest().getp();
        const NodeNameTest *nametest = test->get_nametest().getp();
        switch(test->get_kind()) {
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
      return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME->getNamespace().theStrStore, &*GENV_TYPESYSTEM.XS_ANY_TYPE_QNAME->getLocalName().theStrStore, q);

    case XQType::ITEM_KIND:
      return TypeIdentifier::createItemType(q);

    case XQType::ANY_SIMPLE_TYPE_KIND:
      return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME->getNamespace().theStrStore, &*GENV_TYPESYSTEM.XS_ANY_SIMPLE_TYPE_QNAME->getLocalName().theStrStore, q);

    case XQType::UNTYPED_KIND:
      return TypeIdentifier::createNamedType(&*GENV_TYPESYSTEM.XS_UNTYPED_QNAME->getNamespace().theStrStore, &*GENV_TYPESYSTEM.XS_UNTYPED_QNAME->getLocalName().theStrStore, q);

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

int TypeOps::type_max_cnt (const XQType& type) {
  return is_equal (type, *GENV_TYPESYSTEM.EMPTY_TYPE)
    ? 0
    : QUANT_MAX_CNT [quantifier (type)];
}

int TypeOps::type_min_cnt (const XQType& type) {
  return is_equal (type, *GENV_TYPESYSTEM.EMPTY_TYPE)
    ? 0
    : QUANT_MIN_CNT [quantifier (type)];
}

const int TypeOps::QUANT_MIN_CNT [4] = { 1, 0, 0, 1 };
const int TypeOps::QUANT_MAX_CNT [4] = { 1, 1, 2, 2 };

}
