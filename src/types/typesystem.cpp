
#include <assert.h>
#include "zorba_api.h"
#include "store/naive/atomic_items.h"
#include "node_test.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "typesystem.h"

using namespace xqp;

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

const bool TypeSystem::QUANT_SUBTYPE_MATRIX[4][4] = {
  {T, T, T, T}, /* QUANT_ONE */
  {F, T, T, F}, /* QUANT_QUESTION */
  {F, F, T, F}, /* QUANT_STAR */
  {F, F, T, T}, /* QUANT_PLUS */
};

#undef T
#undef F

TypeSystem::TypeSystem()
{
#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define XSQNDECL(var, local)                         \
        var =                    \
            Store::getInstance().getItemFactory().   \
            createQName(XS_URI, XS_PREFIX, local)

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
  XSQNDECL(XS_ANY_TYPE_QNAME, "anyType");
  XSQNDECL(XS_ANY_SIMPLE_TYPE_QNAME, "anySimpleType");
  XSQNDECL(XS_UNTYPED_QNAME, "untyped");

#define ATOMIC_TYPE_DEFN(basename) \
  basename##_TYPE_ONE = new AtomicXQType(XS_##basename, QUANT_ONE); \
  basename##_TYPE_QUESTION = new AtomicXQType(XS_##basename, QUANT_QUESTION); \
  basename##_TYPE_STAR = new AtomicXQType(XS_##basename, QUANT_STAR); \
  basename##_TYPE_PLUS = new AtomicXQType(XS_##basename, QUANT_PLUS); \
  m_atomic_typecode_qname_map[XS_##basename] = &XS_##basename##_QNAME; \
  m_atomic_qnametype_map[XS_##basename##_QNAME] = XS_##basename; \
  m_atomic_typecode_map[XS_##basename][QUANT_ONE] = &basename##_TYPE_ONE; \
  m_atomic_typecode_map[XS_##basename][QUANT_QUESTION] = &basename##_TYPE_QUESTION; \
  m_atomic_typecode_map[XS_##basename][QUANT_STAR] = &basename##_TYPE_STAR; \
  m_atomic_typecode_map[XS_##basename][QUANT_PLUS] = &basename##_TYPE_PLUS;

  ATOMIC_TYPE_DEFN(ANY_ATOMIC)
  ATOMIC_TYPE_DEFN(STRING)
  ATOMIC_TYPE_DEFN(NORMALIZED_STRING)
  ATOMIC_TYPE_DEFN(TOKEN)
  ATOMIC_TYPE_DEFN(LANGUAGE)
  ATOMIC_TYPE_DEFN(NMTOKEN)
  ATOMIC_TYPE_DEFN(NAME)
  ATOMIC_TYPE_DEFN(NCNAME)
  ATOMIC_TYPE_DEFN(ID)
  ATOMIC_TYPE_DEFN(IDREF)
  ATOMIC_TYPE_DEFN(ENTITY)
  ATOMIC_TYPE_DEFN(UNTYPED_ATOMIC)
  ATOMIC_TYPE_DEFN(DATETIME)
  ATOMIC_TYPE_DEFN(DATE)
  ATOMIC_TYPE_DEFN(TIME)
  ATOMIC_TYPE_DEFN(DURATION)
  ATOMIC_TYPE_DEFN(DT_DURATION)
  ATOMIC_TYPE_DEFN(YM_DURATION)
  ATOMIC_TYPE_DEFN(FLOAT)
  ATOMIC_TYPE_DEFN(DOUBLE)
  ATOMIC_TYPE_DEFN(DECIMAL)
  ATOMIC_TYPE_DEFN(INTEGER)
  ATOMIC_TYPE_DEFN(NON_POSITIVE_INTEGER)
  ATOMIC_TYPE_DEFN(NEGATIVE_INTEGER)
  ATOMIC_TYPE_DEFN(LONG)
  ATOMIC_TYPE_DEFN(INT)
  ATOMIC_TYPE_DEFN(SHORT)
  ATOMIC_TYPE_DEFN(BYTE)
  ATOMIC_TYPE_DEFN(NON_NEGATIVE_INTEGER)
  ATOMIC_TYPE_DEFN(UNSIGNED_LONG)
  ATOMIC_TYPE_DEFN(UNSIGNED_INT)
  ATOMIC_TYPE_DEFN(UNSIGNED_SHORT)
  ATOMIC_TYPE_DEFN(UNSIGNED_BYTE)
  ATOMIC_TYPE_DEFN(POSITIVE_INTEGER)
  ATOMIC_TYPE_DEFN(GYEAR_MONTH)
  ATOMIC_TYPE_DEFN(GYEAR)
  ATOMIC_TYPE_DEFN(GMONTH_DAY)
  ATOMIC_TYPE_DEFN(GDAY)
  ATOMIC_TYPE_DEFN(GMONTH)
  ATOMIC_TYPE_DEFN(BOOLEAN)
  ATOMIC_TYPE_DEFN(BASE64BINARY)
  ATOMIC_TYPE_DEFN(HEXBINARY)
  ATOMIC_TYPE_DEFN(ANY_URI)
  ATOMIC_TYPE_DEFN(QNAME)
  ATOMIC_TYPE_DEFN(NOTATION)
#undef ATOMIC_TYPE_DEFN

  ANY_TYPE = new AnyXQType();

  ANY_SIMPLE_TYPE = new AnySimpleXQType();

  UNTYPED_TYPE = new UntypedXQType();

  EMPTY_TYPE = new EmptyXQType();

  NONE_TYPE = new NoneXQType();

  ITEM_TYPE_ONE = new ItemXQType(QUANT_ONE);
  ITEM_TYPE_QUESTION = new ItemXQType(QUANT_QUESTION);
  ITEM_TYPE_STAR = new ItemXQType(QUANT_STAR);
  ITEM_TYPE_PLUS = new ItemXQType(QUANT_PLUS);

#define NODE_TYPE_DEFN(basename) \
  basename##_TYPE_ONE = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, QUANT_ONE); \
  basename##_TYPE_QUESTION = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, QUANT_QUESTION); \
  basename##_TYPE_STAR = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, QUANT_STAR); \
  basename##_TYPE_PLUS = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, QUANT_PLUS);
  NODE_TYPE_DEFN(PI)
  NODE_TYPE_DEFN(TEXT)
  NODE_TYPE_DEFN(COMMENT)
  NODE_TYPE_DEFN(ANY_NODE)
#undef NODE_TYPE_DEFN
}

TypeSystem::~TypeSystem()
{
}

TypeSystem::quantifier_t TypeSystem::quantifier(const XQType &type) const
{
  return type.m_quantifier;
}

bool TypeSystem::is_equal(const XQType& type1, const XQType& type2) const
{
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
    {
      const NodeXQType& n1 = static_cast<const NodeXQType&>(type1);
      const NodeXQType& n2 = static_cast<const NodeXQType&>(type2);
      return *n1.m_nodetest == *n2.m_nodetest;
    }
    default:
      break;
  }
  return true;
}

bool TypeSystem::is_subtype(const XQType& subtype, const XQType& supertype) const
{
  if (is_equal(subtype, *NONE_TYPE)) {
    return true;
  }
  if (!QUANT_SUBTYPE_MATRIX[subtype.m_quantifier][supertype.m_quantifier]) {
    return false;
  }
  switch(supertype.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        {
          const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
          const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);
          return ATOMIC_SUBTYPE_MATRIX[a1.m_type_code][a2.m_type_code];
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
          return n1.m_nodetest->is_sub_nodetest_of(*n2.m_nodetest);
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
  }
  return false;
}

bool TypeSystem::is_promotable(const XQType& srctype, const XQType& targettype) const
{
  return false;
}

bool TypeSystem::is_atomic(const XQType& type) const
{
  return type.m_quantifier == QUANT_ONE && type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool TypeSystem::is_simple(const XQType& type) const
{
  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool TypeSystem::is_numeric(const XQType& type) const
{
  return is_subtype(*DOUBLE_TYPE_ONE, type)
    || is_subtype(*FLOAT_TYPE_ONE, type)
    || is_subtype(*DECIMAL_TYPE_ONE, type);
}

TypeSystem::atomic_type_code_t TypeSystem::get_atomic_type_code(const XQType& type) const
{
  assert(type.type_kind() == XQType::ATOMIC_TYPE_KIND);
  return (static_cast<const AtomicXQType&>(type)).m_type_code;
}

TypeSystem::xqtref_t TypeSystem::union_type(const XQType& type1, const XQType& type2) const
{
  return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::intersect_type(const XQType& type1, const XQType& type2) const
{
  return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::prime_type(const XQType& type) const
{
  if (is_equal(type, *EMPTY_TYPE)) {
    return NONE_TYPE;
  } else if (type.type_kind() == XQType::ATOMIC_TYPE_KIND) {
    const AtomicXQType& atype = static_cast<const AtomicXQType&>(type);
    return create_atomic_type(atype.m_type_code, QUANT_ONE);
  } else if (is_equal(type, *NONE_TYPE)) {
    return NONE_TYPE;
  } else if (type.type_kind() == XQType::ITEM_KIND) {
    return ITEM_TYPE_ONE;
  } else if (is_equal(type, *ANY_TYPE)) {
    return ITEM_TYPE_ONE;
  } else if (is_equal(type, *ANY_SIMPLE_TYPE)) {
    return ANY_ATOMIC_TYPE_ONE;
  } else if (is_equal(type, *UNTYPED_TYPE)) {
    return ITEM_TYPE_ONE;
  }
  return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::arithmetic_type(const XQType& type1, const XQType& type2) const
{
  if (is_subtype(*UNTYPED_ATOMIC_TYPE_ONE, type1)
    || is_subtype(*UNTYPED_ATOMIC_TYPE_ONE, type2)
    || is_subtype(*DOUBLE_TYPE_ONE, type1)
    || is_subtype(*DOUBLE_TYPE_ONE, type2)) {
    return DOUBLE_TYPE_ONE;
  }
  if (is_subtype(*FLOAT_TYPE_ONE, type1)
    || is_subtype(*FLOAT_TYPE_ONE, type2)) {
    return FLOAT_TYPE_ONE;
  }
  if ((is_subtype(*DECIMAL_TYPE_ONE, type1)
    && !is_subtype(*INTEGER_TYPE_ONE, type1))
    || (is_subtype(*DECIMAL_TYPE_ONE, type2))
    && !is_subtype(*INTEGER_TYPE_ONE, type2)) {
    return DECIMAL_TYPE_ONE;
  }

  return INTEGER_TYPE_ONE;
}

rchandle<NodeNameTest> TypeSystem::get_nametest(const XQType& type) const
{
  if (type.type_kind() == XQType::NODE_TYPE_KIND) {
    const NodeXQType& n = static_cast<const NodeXQType&>(type);
    const NodeTest *nt = n.m_nodetest.get_ptr();
    if (nt) {
      return rchandle<NodeNameTest>(nt->get_nametest());
    }
  }
  return rchandle<NodeNameTest>(0);
}

NodeXQType::NodeXQType(rchandle<NodeTest> nodetest, TypeSystem::xqtref_t content_type, TypeSystem::quantifier_t quantifier) : XQType(quantifier), m_nodetest(nodetest), m_content_type(content_type)
{
}

TypeSystem::xqtref_t TypeSystem::create_type(const TypeIdentifier& ident) const
{
  TypeSystem::quantifier_t q;
  switch(ident.get_quantifier()) {
    case TypeIdentifier::QUANT_ONE:
      q = TypeSystem::QUANT_ONE;
      break;

    case TypeIdentifier::QUANT_QUESTION:
      q = TypeSystem::QUANT_QUESTION;
      break;

    case TypeIdentifier::QUANT_PLUS:
      q = TypeSystem::QUANT_PLUS;
      break;

    case TypeIdentifier::QUANT_STAR:
      q = TypeSystem::QUANT_STAR;
      break;
  }

  switch(ident.get_kind()) {
    case TypeIdentifier::NAMED_TYPE:
      {
        const NamedTypeIdentifier& ni = static_cast<const NamedTypeIdentifier&>(ident);
        return create_type(ni.get_name(), q);
      }

    case TypeIdentifier::ELEMENT_TYPE:
      {
        const ElementOrAttributeTypeIdentifier& eai = static_cast<const ElementOrAttributeTypeIdentifier&>(ident);
        rchandle<NodeNameTest> ennt(new NodeNameTest(eai.get_uri(), eai.get_local()));
        rchandle<NodeTest> ent(new NodeTest(StoreConsts::elementNode, ennt));
        TypeIdentifier *ci = eai.get_content_type().get_ptr();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        return create_node_type(ent, content_type, q);
      }

    case TypeIdentifier::ATTRIBUTE_TYPE:
      {
        const ElementOrAttributeTypeIdentifier& eai = static_cast<const ElementOrAttributeTypeIdentifier&>(ident);
        rchandle<NodeNameTest> annt(new NodeNameTest(eai.get_uri(), eai.get_local()));
        rchandle<NodeTest> ant(new NodeTest(StoreConsts::attributeNode, annt));
        TypeIdentifier *ci = eai.get_content_type().get_ptr();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        return create_node_type(ant, content_type, q);
      }

    case TypeIdentifier::DOCUMENT_TYPE:
      {
        const DocumentTypeIdentifier& di = static_cast<const DocumentTypeIdentifier&>(ident);
        TypeIdentifier *ci = di.get_content_type().get_ptr();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        rchandle<NodeTest> nt(new NodeTest(StoreConsts::documentNode));
        return create_node_type(nt, content_type, q);
      }

    case TypeIdentifier::PI_TYPE:
      return create_node_type(NodeTest::PI_TEST, NONE_TYPE, q);

    case TypeIdentifier::TEXT_TYPE:
      return create_node_type(NodeTest::TEXT_TEST, NONE_TYPE, q);

    case TypeIdentifier::COMMENT_TYPE:
      return create_node_type(NodeTest::COMMENT_TEST, NONE_TYPE, q);

    case TypeIdentifier::ANY_NODE_TYPE:
      return create_node_type(NodeTest::ANY_NODE_TEST, NONE_TYPE, q);

    case TypeIdentifier::ITEM_TYPE:
      return create_item_type(q);

    case TypeIdentifier::EMPTY_TYPE:
      return create_empty_type();
  }

  return TypeSystem::xqtref_t(0);
}

static inline TypeIdentifier::quantifier_t get_typeident_quant(TypeSystem::quantifier_t quant)
{
  switch(quant) {
    case TypeSystem::QUANT_ONE:
      return TypeIdentifier::QUANT_ONE;

    case TypeSystem::QUANT_QUESTION:
      return TypeIdentifier::QUANT_QUESTION;

    case TypeSystem::QUANT_STAR:
      return TypeIdentifier::QUANT_STAR;

    case TypeSystem::QUANT_PLUS:
      return TypeIdentifier::QUANT_PLUS;

    default:
      break;
  }

  return TypeIdentifier::QUANT_ONE;
}

type_ident_ref_t TypeSystem::get_type_identifier(const XQType& type) const
{
  TypeIdentifier::quantifier_t q = get_typeident_quant(quantifier(type));
  switch(type.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      {
        const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
        return type_ident_ref_t(new NamedTypeIdentifier(q, *m_atomic_typecode_qname_map[at.m_type_code]));
      }
    case XQType::NODE_TYPE_KIND:
      {
        const NodeXQType& nt = static_cast<const NodeXQType&>(type);
        const type_ident_ref_t& content_type = get_type_identifier(*nt.m_content_type);
        const NodeTest *test = nt.m_nodetest.get_ptr();
        const NodeNameTest *nametest = test->get_nametest().get_ptr();
        switch(test->get_kind()) {
          case StoreConsts::anyNode:
            return type_ident_ref_t(new AnyNodeTypeIdentifier(q));

          case StoreConsts::textNode:
            return type_ident_ref_t(new TextTypeIdentifier(q));

          case StoreConsts::piNode:
            return type_ident_ref_t(new PITypeIdentifier(q));

          case StoreConsts::commentNode:
            return type_ident_ref_t(new CommentTypeIdentifier(q));

          case StoreConsts::documentNode:
            return type_ident_ref_t(new DocumentTypeIdentifier(q, content_type));

          case StoreConsts::elementNode:
            return type_ident_ref_t(new ElementTypeIdentifier(q, nametest->get_uri(), nametest->get_local(), content_type));

          case StoreConsts::attributeNode:
            return type_ident_ref_t(new AttributeTypeIdentifier(q, nametest->get_uri(), nametest->get_local(), content_type));
          default:
            // cannot happen
            return type_ident_ref_t(0);
        }
      }
    case XQType::ANY_TYPE_KIND:
      return type_ident_ref_t(new NamedTypeIdentifier(q, XS_ANY_TYPE_QNAME));

    case XQType::ITEM_KIND:
      return type_ident_ref_t(new ItemTypeIdentifier(q));

    case XQType::ANY_SIMPLE_TYPE_KIND:
      return type_ident_ref_t(new NamedTypeIdentifier(q, XS_ANY_SIMPLE_TYPE_QNAME));

    case XQType::UNTYPED_KIND:
      return type_ident_ref_t(new NamedTypeIdentifier(q, XS_UNTYPED_QNAME));

    case XQType::EMPTY_KIND:
      return type_ident_ref_t(new EmptyTypeIdentifier());

    default:
      break;
  }
  return type_ident_ref_t(0);
}

TypeSystem::xqtref_t TypeSystem::create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeSystem::quantifier_t quantifier) const
{
  return new NodeXQType(nodetest, content_type, quantifier);
}

/* vim:set ts=2 sw=2: */
