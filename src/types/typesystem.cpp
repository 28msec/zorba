#include "store/naive/atomic_items.h"
#include "util/test_types.h"
#include "typesystem.h"

using namespace xqp;

#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define XSQNDECL(var, local) const rchandle<QNameItem> AtomicTypeConstants::var = new QNameItemNaive(XS_URI, XS_PREFIX, local)

XSQNDECL(XS_ANY_ATOMIC_QNAME, "anyAtomicType");
XSQNDECL(XS_STRING_QNAME, "string");
XSQNDECL(XS_NORMALIZED_STRING_QNAME, "normalizedString");
XSQNDECL(XS_TOKEN_QNAME, "token");
XSQNDECL(XS_LANGUAGE_QNAME, "language");
XSQNDECL(XS_NMTOKEN_QNAME, "NMTOKEN");
XSQNDECL(XS_NAME_QNAME, "Name");
XSQNDECL(XS_NCNAME_QNAME, "NCName");
XSQNDECL(XS_ID_QNAME, "ID");
XSQNDECL(XS_IDREF_QNAME, "IDREF");
XSQNDECL(XS_ENTITY_QNAME, "ENTITY");
XSQNDECL(XS_UNTYPED_ATOMIC_QNAME, "untypedAtomic");
XSQNDECL(XS_DATETIME_QNAME, "dateTime");
XSQNDECL(XS_DATE_QNAME, "date");
XSQNDECL(XS_TIME_QNAME, "time");
XSQNDECL(XS_DURATION_QNAME, "duration");
XSQNDECL(XS_DT_DURATION_QNAME, "dayTimeDuration");
XSQNDECL(XS_YM_DURATION_QNAME, "yearMonthDuration");
XSQNDECL(XS_FLOAT_QNAME, "float");
XSQNDECL(XS_DOUBLE_QNAME, "double");
XSQNDECL(XS_DECIMAL_QNAME, "decimal");
XSQNDECL(XS_INTEGER_QNAME, "integer");
XSQNDECL(XS_NON_POSITIVE_INTEGER_QNAME, "nonPositiveInteger");
XSQNDECL(XS_NEGATIVE_INTEGER_QNAME, "negativeInteger");
XSQNDECL(XS_LONG_QNAME, "long");
XSQNDECL(XS_INT_QNAME, "int");
XSQNDECL(XS_SHORT_QNAME, "short");
XSQNDECL(XS_BYTE_QNAME, "byte");
XSQNDECL(XS_NON_NEGATIVE_INTEGER_QNAME, "nonNegativeInteger");
XSQNDECL(XS_UNSIGNED_LONG_QNAME, "unsignedLong");
XSQNDECL(XS_UNSIGNED_INT_QNAME, "unsignedInt");
XSQNDECL(XS_UNSIGNED_SHORT_QNAME, "unsignedShort");
XSQNDECL(XS_UNSIGNED_BYTE_QNAME, "unsignedByte");
XSQNDECL(XS_POSITIVE_INTEGER_QNAME, "positiveInteger");
XSQNDECL(XS_GYEAR_MONTH_QNAME, "gYearMonth");
XSQNDECL(XS_GYEAR_QNAME, "gYear");
XSQNDECL(XS_GMONTH_DAY_QNAME, "gMonthDay");
XSQNDECL(XS_GDAY_QNAME, "gDay");
XSQNDECL(XS_GMONTH_QNAME, "gMonth");
XSQNDECL(XS_BOOLEAN_QNAME, "boolean");
XSQNDECL(XS_BASE64BINARY_QNAME, "base64Binary");
XSQNDECL(XS_HEXBINARY_QNAME, "hexBinary");
XSQNDECL(XS_ANY_URI_QNAME, "anyURI");
XSQNDECL(XS_QNAME_QNAME, "QName");
XSQNDECL(XS_NOTATION_QNAME, "notation");

#define T true
#define F false

const bool TypeSystem::ATOMIC_SUBTYPE_MATRIX[45][45] = {
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* anyAtomicType */
  {T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* string */
  {T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* normalizedString */
  {T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* token */
  {T, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* language */
  {T, T, T, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* NMTOKEN */
  {T, T, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* Name */
  {T, T, T, T, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* NCName */
  {T, T, T, T, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* ID */
  {T, T, T, T, F, F, T, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* IDREF */
  {T, T, T, T, F, F, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* ENTITY */
  {T, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* untypedAtomic */
  {T, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* dateTime */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* date */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* time */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* duration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* yearMonthDuration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* dayTimeDuration */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* float */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* double */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* decimal */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* integer */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* nonPositiveInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* negativeInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* long */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* int */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* short */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* byte */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* nonNegativeInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedLong */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedInt */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedShort */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, T, T, T, T, F, F, F, F, F, F, F, F, F, F, F, F}, /* unsignedByte */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, T, F, F, F, F, F, F, T, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F, F}, /* positiveInteger */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F, F}, /* gYearMonth */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F, F}, /* gYear */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F, F}, /* gMonthDay */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F, F}, /* gDay */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F, F}, /* gMonth */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F, F}, /* boolean */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F, F}, /* base64Binary */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F, F}, /* hexBinary */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F, F}, /* anyURI */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T, F}, /* QName */
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, T}, /* NOTATION */
};

const bool TypeSystem::QUANT_SUBTYPE_MATRIX[5][5] = {
  {T, F, T, T, F}, /* QUANT_ZERO */
  {F, T, T, T, T}, /* QUANT_ONE */
  {F, F, T, T, F}, /* QUANT_QUESTION */
  {F, F, F, T, F}, /* QUANT_STAR */
  {F, F, F, T, T}, /* QUANT_PLUS */
};

#undef T
#undef F

#define ATOMIC_TYPE_DECL(name, tc, q) TypeSystem::cxqtref_t TypeSystem::name(BasicTypeFactory::get_instance().create_atomic_type(AtomicTypeConstants::tc, TypeSystem::q))

ATOMIC_TYPE_DECL(ANY_ATOMIC_TYPE, XS_ANY_ATOMIC, QUANT_ONE);
ATOMIC_TYPE_DECL(STRING_TYPE, XS_STRING, QUANT_ONE);
ATOMIC_TYPE_DECL(NORMALIZED_STRING_TYPE, XS_NORMALIZED_STRING, QUANT_ONE);
ATOMIC_TYPE_DECL(TOKEN_TYPE, XS_TOKEN, QUANT_ONE);
ATOMIC_TYPE_DECL(LANGUAGE_TYPE, XS_LANGUAGE, QUANT_ONE);
ATOMIC_TYPE_DECL(NMTOKEN_TYPE, XS_NMTOKEN, QUANT_ONE);
ATOMIC_TYPE_DECL(NAME_TYPE, XS_NAME, QUANT_ONE);
ATOMIC_TYPE_DECL(NCNAME_TYPE, XS_NCNAME, QUANT_ONE);
ATOMIC_TYPE_DECL(ID_TYPE, XS_ID, QUANT_ONE);
ATOMIC_TYPE_DECL(IDREF_TYPE, XS_IDREF, QUANT_ONE);
ATOMIC_TYPE_DECL(ENTITY_TYPE, XS_ENTITY, QUANT_ONE);
ATOMIC_TYPE_DECL(UNTYPED_ATOMIC_TYPE, XS_UNTYPED_ATOMIC, QUANT_ONE);
ATOMIC_TYPE_DECL(DATETIME_TYPE, XS_DATETIME, QUANT_ONE);
ATOMIC_TYPE_DECL(DATE_TYPE, XS_DATE, QUANT_ONE);
ATOMIC_TYPE_DECL(TIME_TYPE, XS_TIME, QUANT_ONE);
ATOMIC_TYPE_DECL(DURATION_TYPE, XS_DURATION, QUANT_ONE);
ATOMIC_TYPE_DECL(DT_DURATION_TYPE, XS_DT_DURATION, QUANT_ONE);
ATOMIC_TYPE_DECL(YM_DURATION_TYPE, XS_YM_DURATION, QUANT_ONE);
ATOMIC_TYPE_DECL(FLOAT_TYPE, XS_FLOAT, QUANT_ONE);
ATOMIC_TYPE_DECL(DOUBLE_TYPE, XS_DOUBLE, QUANT_ONE);
ATOMIC_TYPE_DECL(DECIMAL_TYPE, XS_DECIMAL, QUANT_ONE);
ATOMIC_TYPE_DECL(INTEGER_TYPE, XS_INTEGER, QUANT_ONE);
ATOMIC_TYPE_DECL(NON_POSITIVE_INTEGER_TYPE, XS_NON_POSITIVE_INTEGER, QUANT_ONE);
ATOMIC_TYPE_DECL(NEGATIVE_INTEGER_TYPE, XS_NEGATIVE_INTEGER, QUANT_ONE);
ATOMIC_TYPE_DECL(LONG_TYPE, XS_LONG, QUANT_ONE);
ATOMIC_TYPE_DECL(INT_TYPE, XS_INT, QUANT_ONE);
ATOMIC_TYPE_DECL(SHORT_TYPE, XS_SHORT, QUANT_ONE);
ATOMIC_TYPE_DECL(BYTE_TYPE, XS_BYTE, QUANT_ONE);
ATOMIC_TYPE_DECL(NON_NEGATIVE_INTEGER_TYPE, XS_NON_NEGATIVE_INTEGER, QUANT_ONE);
ATOMIC_TYPE_DECL(UNSIGNED_LONG_TYPE, XS_UNSIGNED_LONG, QUANT_ONE);
ATOMIC_TYPE_DECL(UNSIGNED_INT_TYPE, XS_UNSIGNED_INT, QUANT_ONE);
ATOMIC_TYPE_DECL(UNSIGNED_SHORT_TYPE, XS_UNSIGNED_SHORT, QUANT_ONE);
ATOMIC_TYPE_DECL(UNSIGNED_BYTE_TYPE, XS_UNSIGNED_BYTE, QUANT_ONE);
ATOMIC_TYPE_DECL(POSITIVE_INTEGER_TYPE, XS_POSITIVE_INTEGER, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_MONTH_TYPE, XS_GYEAR_MONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_TYPE, XS_GYEAR, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_DAY_TYPE, XS_GMONTH_DAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GDAY_TYPE, XS_GDAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_TYPE, XS_GMONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(BOOLEAN_TYPE, XS_BOOLEAN, QUANT_ONE);
ATOMIC_TYPE_DECL(BASE64BINARY_TYPE, XS_BASE64BINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(HEXBINARY_TYPE, XS_HEXBINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(ANY_URI_TYPE, XS_ANY_URI, QUANT_ONE);
ATOMIC_TYPE_DECL(QNAME_TYPE, XS_QNAME, QUANT_ONE);
ATOMIC_TYPE_DECL(NOTATION_TYPE, XS_NOTATION, QUANT_ONE);
#undef ATOMIC_TYPE_DECL

TypeSystem::quantifier_t TypeSystem::quantifier(const XQType &type) {
  return type.m_quantifier;
}

bool TypeSystem::is_equal(const XQType& type1, const XQType& type2) {
  if (type1.m_quantifier != type2.m_quantifier) {
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
      return a1.m_type_code == a2.m_type_code;
    }
    case XQType::NODE_TYPE_KIND:
      // TODO
      break;
  }
  return false;
}

bool TypeSystem::is_subtype(const XQType& subtype, const XQType& supertype) {
  if (!QUANT_SUBTYPE_MATRIX[subtype.m_quantifier][supertype.m_quantifier]) {
    return false;
  }
  if (subtype.type_kind() == XQType::ATOMIC_TYPE_KIND
    && supertype.type_kind() == XQType::ATOMIC_TYPE_KIND) {
      const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
      const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);
      return ATOMIC_SUBTYPE_MATRIX[a1.m_type_code][a2.m_type_code];
  }
  return false;
}

bool TypeSystem::is_promotable(const XQType& srctype, const XQType& targettype) {
  return false;
}

bool TypeSystem::is_atomic(const XQType& type) {
  return type.m_quantifier == QUANT_ONE && type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool TypeSystem::is_simple(const XQType& type) {
  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

TypeSystem::xqtref_t TypeSystem::union_type(TypeFactory& type_factory, const XQType& type1, const XQType& type2) {
  return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::intersect_type(TypeFactory& type_factory, const XQType& type1, const XQType& type2) {
  return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::prime_type(TypeFactory& type_factory, const XQType& type) {
  return TypeSystem::xqtref_t(0);
}

BasicTypeFactory& BasicTypeFactory::get_instance() {
  static BasicTypeFactory *_m_instance = new BasicTypeFactory();

  return *_m_instance;
}

TypeSystem::xqtref_t BasicTypeFactory::create_atomic_type(AtomicTypeConstants::type_code_t type_code, TypeSystem::quantifier_t quantifier) {
  return TypeSystem::xqtref_t(new AtomicXQType(type_code, quantifier));
}

TypeSystem::xqtref_t BasicTypeFactory::create_atomic_type(rchandle<QNameItem> qname, TypeSystem::quantifier_t quantifier)
{
  return TypeSystem::xqtref_t(new AtomicXQType(AtomicTypeConstants::XS_STRING, quantifier));
}

TypeSystem::xqtref_t BasicTypeFactory::create_node_type(rchandle<NodeTest> nodetest, TypeSystem::quantifier_t quantifier)
{
  return new NodeXQType(nodetest, quantifier);
}
/* vim:set ts=2 sw=2: */
