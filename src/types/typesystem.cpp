#include "store/naive/atomic_items.h"
#include "util/test_types.h"
#include "typesystem.h"

using namespace xqp;

#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define XSQN(local) new QNameItemNaive(XS_URI, XS_PREFIX, local)

const rchandle<QNameItem> AtomicTypeConstants::XS_STRING_QNAME = XSQN("string");
const rchandle<QNameItem> AtomicTypeConstants::XS_BOOLEAN_QNAME = XSQN("boolean");
const rchandle<QNameItem> AtomicTypeConstants::XS_FLOAT_QNAME = XSQN("float");
const rchandle<QNameItem> AtomicTypeConstants::XS_DECIMAL_QNAME = XSQN("decimal");
const rchandle<QNameItem> AtomicTypeConstants::XS_DOUBLE_QNAME = XSQN("double");
const rchandle<QNameItem> AtomicTypeConstants::XS_DURATION_QNAME = XSQN("duration");
const rchandle<QNameItem> AtomicTypeConstants::XS_DT_DURATION_QNAME = XSQN("dayTimeDuration");
const rchandle<QNameItem> AtomicTypeConstants::XS_YM_DURATION_QNAME = XSQN("yearMonthDuration");
const rchandle<QNameItem> AtomicTypeConstants::XS_DATETIME_QNAME = XSQN("dateTime");
const rchandle<QNameItem> AtomicTypeConstants::XS_TIME_QNAME = XSQN("time");
const rchandle<QNameItem> AtomicTypeConstants::XS_DATE_QNAME = XSQN("date");
const rchandle<QNameItem> AtomicTypeConstants::XS_GYEAR_MONTH_QNAME = XSQN("gYearMonth");
const rchandle<QNameItem> AtomicTypeConstants::XS_GYEAR_QNAME = XSQN("gYear");
const rchandle<QNameItem> AtomicTypeConstants::XS_GMONTH_DAY_QNAME = XSQN("gMonthDay");
const rchandle<QNameItem> AtomicTypeConstants::XS_GDAY_QNAME = XSQN("gDay");
const rchandle<QNameItem> AtomicTypeConstants::XS_GMONTH_QNAME = XSQN("gMonth");
const rchandle<QNameItem> AtomicTypeConstants::XS_HEXBINARY_QNAME = XSQN("hexBinary");
const rchandle<QNameItem> AtomicTypeConstants::XS_INTEGER_QNAME = XSQN("integer");
const rchandle<QNameItem> AtomicTypeConstants::XS_LONG_QNAME = XSQN("long");
const rchandle<QNameItem> AtomicTypeConstants::XS_INT_QNAME = XSQN("int");
const rchandle<QNameItem> AtomicTypeConstants::XS_SHORT_QNAME = XSQN("short");
const rchandle<QNameItem> AtomicTypeConstants::XS_BYTE_QNAME = XSQN("byte");
const rchandle<QNameItem> AtomicTypeConstants::XS_NON_NEG_INTEGER_QNAME = XSQN("nonNegativeInteger");
const rchandle<QNameItem> AtomicTypeConstants::XS_UNSIGNED_LONG_QNAME = XSQN("unsignedLong");
const rchandle<QNameItem> AtomicTypeConstants::XS_UNSIGNED_INT_QNAME = XSQN("unsignedInt");
const rchandle<QNameItem> AtomicTypeConstants::XS_UNSIGNED_SHORT_QNAME = XSQN("unsignedShort");
const rchandle<QNameItem> AtomicTypeConstants::XS_UNSIGNED_BYTE_QNAME = XSQN("unsignedByte");
const rchandle<QNameItem> AtomicTypeConstants::XS_POSITIVE_INTEGER_QNAME = XSQN("positiveInteger");
const rchandle<QNameItem> AtomicTypeConstants::XS_BASE64BINARY_QNAME = XSQN("base64Binary");
const rchandle<QNameItem> AtomicTypeConstants::XS_ANY_URI_QNAME = XSQN("anyURI");
const rchandle<QNameItem> AtomicTypeConstants::XS_QNAME_QNAME = XSQN("QName");
const rchandle<QNameItem> AtomicTypeConstants::XS_NOTATION_QNAME = XSQN("notation");
const rchandle<QNameItem> AtomicTypeConstants::XS_UNTYPED_ATOMIC_QNAME = XSQN("untypedAtomic");

#define T true
#define F false

/* TODO - The type matrix is not done yet */
const bool AtomicXQType::SUBTYPE_MATRIX[19][19] = {
  {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
  {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
};

#undef T
#undef F

#define ATOMIC_TYPE_DECL(name, tc, q) TypeSystem::cxqtref_t TypeSystem::name(BasicTypeFactory::get_instance().create_atomic_type(AtomicTypeConstants::tc, TypeSystem::q))

ATOMIC_TYPE_DECL(STRING_TYPE, XS_STRING, QUANT_ONE);
ATOMIC_TYPE_DECL(BOOLEAN_TYPE, XS_BOOLEAN, QUANT_ONE);
ATOMIC_TYPE_DECL(FLOAT_TYPE, XS_FLOAT, QUANT_ONE);
ATOMIC_TYPE_DECL(DOUBLE_TYPE, XS_DOUBLE, QUANT_ONE);
ATOMIC_TYPE_DECL(DURATION_TYPE, XS_DURATION, QUANT_ONE);
ATOMIC_TYPE_DECL(DATETIME_TYPE, XS_DATETIME, QUANT_ONE);
ATOMIC_TYPE_DECL(TIME_TYPE, XS_TIME, QUANT_ONE);
ATOMIC_TYPE_DECL(DATE_TYPE, XS_DATE, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_MONTH_TYPE, XS_GYEAR_MONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_TYPE, XS_GYEAR, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_DAY_TYPE, XS_GMONTH_DAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GDAY_TYPE, XS_GDAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_TYPE, XS_GMONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(HEXBINARY_TYPE, XS_HEXBINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(BASE64BINARY_TYPE, XS_BASE64BINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(ANY_URI_TYPE, XS_ANY_URI, QUANT_ONE);
ATOMIC_TYPE_DECL(QNAME_TYPE, XS_QNAME, QUANT_ONE);
ATOMIC_TYPE_DECL(NOTATION_TYPE, XS_NOTATION, QUANT_ONE);
ATOMIC_TYPE_DECL(UNTYPED_ATOMIC_TYPE, XS_UNTYPED_ATOMIC, QUANT_ONE);

#undef ATOMIC_TYPE_DECL

TypeSystem::quantifier_t TypeSystem::quantifier(const XQType *type) {
  return TypeSystem::QUANT_ONE;
}

bool TypeSystem::is_equal(const XQType& type1, const XQType& type2) {
  return false;
}

bool TypeSystem::is_subtype(const XQType& subtype, const XQType& supertype) {
  return false;
}

bool TypeSystem::is_promotable(const XQType& srctype, const XQType& targettype) {
  return false;
}

bool TypeSystem::is_atomic(const XQType& type) {
  return false;
}

bool TypeSystem::is_simple(const XQType& type) {
  return false;
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
