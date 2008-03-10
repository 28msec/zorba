#include <assert.h>

#include <zorba/typeident.h>

#include "zorbatypes/xqpstring.h"
#include "system/globalenv.h"
#include "store/naive/atomic_items.h"
#include "node_test.h"
#include "store/api/item_factory.h"
#include "store/api/store.h"
#include "types/root_typemanager.h"
#include "util/Assert.h"

using namespace zorba;

#define T true
#define F false

const bool RootTypeManager::ATOMIC_SUBTYPE_MATRIX[45][45] = {
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

const bool RootTypeManager::QUANT_SUBTYPE_MATRIX[4][4] = {
  {T, T, T, T}, /* QUANT_ONE */
  {F, T, T, F}, /* QUANT_QUESTION */
  {F, F, T, F}, /* QUANT_STAR */
  {F, F, T, T}, /* QUANT_PLUS */
};

#undef T
#undef F

RootTypeManager::RootTypeManager()
{
#define XS_URI "http://www.w3.org/2001/XMLSchema"
#define XS_PREFIX "xs"

#define XSQNDECL(var, local)                         \
        var =                    \
            GENV.getStore().getItemFactory()->   \
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
  basename##_TYPE_ONE = new AtomicXQType(TypeConstants::XS_##basename, TypeConstants::QUANT_ONE); \
  basename##_TYPE_QUESTION = new AtomicXQType(TypeConstants::XS_##basename, TypeConstants::QUANT_QUESTION); \
  basename##_TYPE_STAR = new AtomicXQType(TypeConstants::XS_##basename, TypeConstants::QUANT_STAR); \
  basename##_TYPE_PLUS = new AtomicXQType(TypeConstants::XS_##basename, TypeConstants::QUANT_PLUS); \
  m_atomic_typecode_qname_map[TypeConstants::XS_##basename] = &XS_##basename##_QNAME; \
  m_atomic_qnametype_map[XS_##basename##_QNAME] = TypeConstants::XS_##basename; \
  m_atomic_typecode_map[TypeConstants::XS_##basename][TypeConstants::QUANT_ONE] = &basename##_TYPE_ONE; \
  m_atomic_typecode_map[TypeConstants::XS_##basename][TypeConstants::QUANT_QUESTION] = &basename##_TYPE_QUESTION; \
  m_atomic_typecode_map[TypeConstants::XS_##basename][TypeConstants::QUANT_STAR] = &basename##_TYPE_STAR; \
  m_atomic_typecode_map[TypeConstants::XS_##basename][TypeConstants::QUANT_PLUS] = &basename##_TYPE_PLUS;

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

  ITEM_TYPE_ONE = new ItemXQType(TypeConstants::QUANT_ONE);
  ITEM_TYPE_QUESTION = new ItemXQType(TypeConstants::QUANT_QUESTION);
  ITEM_TYPE_STAR = new ItemXQType(TypeConstants::QUANT_STAR);
  ITEM_TYPE_PLUS = new ItemXQType(TypeConstants::QUANT_PLUS);

#define NODE_TYPE_DEFN(basename) \
  basename##_TYPE_ONE = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_ONE); \
  basename##_TYPE_QUESTION = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_QUESTION); \
  basename##_TYPE_STAR = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_STAR); \
  basename##_TYPE_PLUS = new NodeXQType(NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_PLUS);
  NODE_TYPE_DEFN(PI)
  NODE_TYPE_DEFN(TEXT)
  NODE_TYPE_DEFN(COMMENT)
  NODE_TYPE_DEFN(ANY_NODE)
#undef NODE_TYPE_DEFN
}

RootTypeManager::~RootTypeManager()
{
}

std::ostream& RootTypeManager::serialize(std::ostream& os, const XQType& type) const
{
  return type.serialize(os);
}

std::string RootTypeManager::toString (const XQType& type) const {
  std::ostringstream os;
  serialize (os, type);
  return os.str ();
}

TypeConstants::quantifier_t RootTypeManager::quantifier(const XQType &type) const
{
  return type.get_quantifier();
}

bool RootTypeManager::is_equal(const XQType& type1, const XQType& type2) const
{
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

bool RootTypeManager::is_subtype(const XQType& subtype, const XQType& supertype) const
{
  if (is_equal(subtype, *NONE_TYPE)) {
    return true;
  }
  if (!QUANT_SUBTYPE_MATRIX[subtype.get_quantifier()][supertype.get_quantifier()]) {
    return false;
  }
  switch(supertype.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      switch(subtype.type_kind()) {
        case XQType::ATOMIC_TYPE_KIND:
        {
          const AtomicXQType& a1 = static_cast<const AtomicXQType&>(subtype);
          const AtomicXQType& a2 = static_cast<const AtomicXQType&>(supertype);
          return ATOMIC_SUBTYPE_MATRIX[a1.get_type_code()][a2.get_type_code()];
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

bool RootTypeManager::is_promotable(const XQType& srctype, const XQType& targettype) const
{
  return false;
}

bool RootTypeManager::is_treatable(const store::Item_t item, const XQType& type) const
{
  switch(type.type_kind()) {
    case XQType::NODE_TYPE_KIND:
      {
        if (!item->isNode()) {
          return false;
        }
        const NodeXQType& nType = static_cast<const NodeXQType&>(type);
        rchandle<NodeTest> nodeTest = nType.get_nodetest();
        switch(nodeTest->get_kind()) {
          case store::StoreConsts::anyNode:
            return true;

          case store::StoreConsts::documentNode:
            return item->getNodeKind() == store::StoreConsts::documentNode;

          case store::StoreConsts::textNode:
            return item->getNodeKind() == store::StoreConsts::textNode;

          case store::StoreConsts::piNode:
            return item->getNodeKind() == store::StoreConsts::piNode
              && (nodeTest->get_nametest() == NULL
                || nodeTest->get_nametest()->get_local() == NULL
                || nodeTest->get_nametest()->get_local()->byteEqual(*item->getTarget().getStore()));

          case store::StoreConsts::commentNode:
            return item->getNodeKind() == store::StoreConsts::commentNode;

          default:
            break;
        }
      }

    default:
      break;
  }
  return is_subtype(*create_type(item->getType(), TypeConstants::QUANT_ONE), type);
}

bool RootTypeManager::is_atomic(const XQType& type) const
{
  return type.get_quantifier() == TypeConstants::QUANT_ONE && type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool RootTypeManager::is_simple(const XQType& type) const
{
  return type.type_kind() == XQType::ATOMIC_TYPE_KIND;
}

bool RootTypeManager::is_numeric(const XQType& type) const
{
  return is_subtype(type, *DOUBLE_TYPE_ONE)
    || is_subtype(type, *FLOAT_TYPE_ONE)
    || is_subtype(type, *DECIMAL_TYPE_ONE);
}

TypeConstants::atomic_type_code_t RootTypeManager::get_atomic_type_code(const XQType& type) const
{
  assert(type.type_kind() == XQType::ATOMIC_TYPE_KIND);
  return (static_cast<const AtomicXQType&>(type)).get_type_code();
}

xqtref_t RootTypeManager::union_type(const XQType& type1, const XQType& type2) const
{
  return xqtref_t(0);
}

xqtref_t RootTypeManager::intersect_type(const XQType& type1, const XQType& type2) const
{
  return xqtref_t(0);
}

xqtref_t RootTypeManager::prime_type(const XQType& type) const
{
  if (is_equal(type, *EMPTY_TYPE)) {
    return NONE_TYPE;
  } else if (type.type_kind() == XQType::ATOMIC_TYPE_KIND) {
    const AtomicXQType& atype = static_cast<const AtomicXQType&>(type);
    return create_atomic_type(atype.get_type_code(), TypeConstants::QUANT_ONE);
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
  } else if (type.type_kind() == XQType::NODE_TYPE_KIND) {
    const NodeXQType& ntype = static_cast<const NodeXQType&>(type);
    return create_node_type(ntype.get_nodetest(), ntype.get_content_type(), TypeConstants::QUANT_ONE);
  }
  Assert(false);

  return NULL;
}

xqtref_t RootTypeManager::arithmetic_type(const XQType& type1, const XQType& type2) const
{
  if (is_subtype(type1, *UNTYPED_ATOMIC_TYPE_ONE)
      || is_subtype(type2, *UNTYPED_ATOMIC_TYPE_ONE)
      || is_subtype(type1, *DOUBLE_TYPE_ONE)
      || is_subtype(type2, *DOUBLE_TYPE_ONE)) {
    return DOUBLE_TYPE_ONE;
  }
  if (is_subtype(type1, *FLOAT_TYPE_ONE)
      || is_subtype(type2, *FLOAT_TYPE_ONE)) {
    return FLOAT_TYPE_ONE;
  }
  bool b = is_subtype(type1, *DECIMAL_TYPE_ONE);
  b = is_subtype(type1, *INTEGER_TYPE_ONE);
  if ((is_subtype(type1, *DECIMAL_TYPE_ONE)
       && !is_subtype(type1, *INTEGER_TYPE_ONE))
       || (is_subtype(type2, *DECIMAL_TYPE_ONE))
       && !is_subtype(type2, *INTEGER_TYPE_ONE)) {
    return DECIMAL_TYPE_ONE;
  }

  return INTEGER_TYPE_ONE;
}

rchandle<NodeNameTest> RootTypeManager::get_nametest(const XQType& type) const
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

xqtref_t RootTypeManager::create_type(const TypeIdentifier& ident) const
{
  TypeConstants::quantifier_t q = TypeConstants::QUANT_ONE;
  switch(ident.get_quantifier()) {
    case TypeIdentifier::QUANT_ONE:
      q = TypeConstants::QUANT_ONE;
      break;

    case TypeIdentifier::QUANT_QUESTION:
      q = TypeConstants::QUANT_QUESTION;
      break;

    case TypeIdentifier::QUANT_PLUS:
      q = TypeConstants::QUANT_PLUS;
      break;

    case TypeIdentifier::QUANT_STAR:
      q = TypeConstants::QUANT_STAR;
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
        rchandle<NodeTest> ent(new NodeTest(store::StoreConsts::elementNode, ennt));
        TypeIdentifier *ci = eai.get_content_type().getp();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        return create_node_type(ent, content_type, q);
      }

    case TypeIdentifier::ATTRIBUTE_TYPE:
      {
        const ElementOrAttributeTypeIdentifier& eai = static_cast<const ElementOrAttributeTypeIdentifier&>(ident);
        rchandle<NodeNameTest> annt(new NodeNameTest(eai.get_uri(), eai.get_local()));
        rchandle<NodeTest> ant(new NodeTest(store::StoreConsts::attributeNode, annt));
        TypeIdentifier *ci = eai.get_content_type().getp();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        return create_node_type(ant, content_type, q);
      }

    case TypeIdentifier::DOCUMENT_TYPE:
      {
        const DocumentTypeIdentifier& di = static_cast<const DocumentTypeIdentifier&>(ident);
        TypeIdentifier *ci = di.get_content_type().getp();
        xqtref_t content_type = ci ? create_type(*ci) : xqtref_t(0);
        rchandle<NodeTest> nt(new NodeTest(store::StoreConsts::documentNode));
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

  return xqtref_t(0);
}


xqtref_t RootTypeManager::create_type(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  // TODO: full implem. danm: at least provide atomic types for now
  switch(type.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      return create_atomic_type(static_cast <const AtomicXQType *> (& type)->get_type_code(), quantifier);

    case XQType::NODE_TYPE_KIND:
      {
        const NodeXQType& nt = static_cast<const NodeXQType&>(type);
        return create_node_type(nt.get_nodetest(), nt.get_content_type(), quantifier);
      }

    case XQType::ANY_TYPE_KIND:
      return ANY_TYPE;

    case XQType::ITEM_KIND:
      return create_item_type(quantifier);

    case XQType::ANY_SIMPLE_TYPE_KIND:
      return ANY_SIMPLE_TYPE;

    case XQType::UNTYPED_KIND:
      return UNTYPED_TYPE;

    case XQType::EMPTY_KIND:
      return EMPTY_TYPE;

    case XQType::NONE_KIND:
      return NONE_TYPE;

    case XQType::USER_DEFINED_KIND:
    {
      const UserDefinedXQType& udt = static_cast<const UserDefinedXQType&>(type);
      return create_user_defined_type(udt, quantifier);
    }
  }

  assert(false);
  return 0;
}


xqtref_t RootTypeManager::create_node_type(
    rchandle<NodeTest> nodetest,
    xqtref_t content_type,
    TypeConstants::quantifier_t quantifier) const
{
  return new NodeXQType(nodetest, content_type, quantifier);
}


static inline TypeIdentifier::quantifier_t get_typeident_quant(TypeConstants::quantifier_t quant)
{
  switch(quant) {
    case TypeConstants::QUANT_ONE:
      return TypeIdentifier::QUANT_ONE;

    case TypeConstants::QUANT_QUESTION:
      return TypeIdentifier::QUANT_QUESTION;

    case TypeConstants::QUANT_STAR:
      return TypeIdentifier::QUANT_STAR;

    case TypeConstants::QUANT_PLUS:
      return TypeIdentifier::QUANT_PLUS;

    default:
      break;
  }

  return TypeIdentifier::QUANT_ONE;
}

type_ident_ref_t RootTypeManager::get_type_identifier(const XQType& type) const
{
  TypeIdentifier::quantifier_t q = get_typeident_quant(quantifier(type));
  switch(type.type_kind()) {
    case XQType::ATOMIC_TYPE_KIND:
      {
        const AtomicXQType& at = static_cast<const AtomicXQType&>(type);
        return type_ident_ref_t(new NamedTypeIdentifier(q, *m_atomic_typecode_qname_map[at.get_type_code()]));
      }
    case XQType::NODE_TYPE_KIND:
      {
        const NodeXQType& nt = static_cast<const NodeXQType&>(type);
        const type_ident_ref_t& content_type = get_type_identifier(*nt.get_content_type());
        const NodeTest *test = nt.get_nodetest().getp();
        const NodeNameTest *nametest = test->get_nametest().getp();
        switch(test->get_kind()) {
          case store::StoreConsts::anyNode:
            return type_ident_ref_t(new AnyNodeTypeIdentifier(q));

          case store::StoreConsts::textNode:
            return type_ident_ref_t(new TextTypeIdentifier(q));

          case store::StoreConsts::piNode:
            return type_ident_ref_t(new PITypeIdentifier(q));

          case store::StoreConsts::commentNode:
            return type_ident_ref_t(new CommentTypeIdentifier(q));

          case store::StoreConsts::documentNode:
            return type_ident_ref_t(new DocumentTypeIdentifier(q, content_type));

          case store::StoreConsts::elementNode:
            return type_ident_ref_t(new ElementTypeIdentifier(q, nametest->get_uri(), nametest->get_local(), content_type));

          case store::StoreConsts::attributeNode:
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

    case XQType::USER_DEFINED_KIND:
        //TODO for Vinayak return type identifier
    default:
      break;
  }
  return type_ident_ref_t(0);
}

xqtref_t RootTypeManager::create_type(
    store::Item_t qname,
    TypeConstants::quantifier_t quantifier) const
{
  if (m_atomic_qnametype_map.find(qname) != m_atomic_qnametype_map.end()) {
    return create_atomic_type(qname, quantifier);
  }
  else if (qname == XS_ANY_TYPE_QNAME) {
    return create_any_type();
  }
  else if (qname == XS_ANY_SIMPLE_TYPE_QNAME) {
    return create_any_simple_type();
  }
  else if (qname == XS_UNTYPED_QNAME) {
    return create_untyped_type();
  }
  return xqtref_t(0);
}


xqtref_t RootTypeManager::create_atomic_type(
    TypeConstants::atomic_type_code_t type_code,
    TypeConstants::quantifier_t quantifier) const
{
  return *m_atomic_typecode_map[type_code][quantifier];
}


xqtref_t RootTypeManager::create_atomic_type(
    store::Item_t qname,
    TypeConstants::quantifier_t quantifier) const
{
  qnametype_map_t::const_iterator i = m_atomic_qnametype_map.find(qname);
  return (i == m_atomic_qnametype_map.end()) ? 
    xqtref_t (NULL) : create_atomic_type(i->second, quantifier);
}


xqtref_t RootTypeManager::create_any_type() const
{
  return ANY_TYPE;
}


xqtref_t RootTypeManager::create_item_type(
    TypeConstants::quantifier_t quantifier) const
{
  switch(quantifier) {
    case TypeConstants::QUANT_ONE:
      return ITEM_TYPE_ONE;
    case TypeConstants::QUANT_QUESTION:
      return ITEM_TYPE_QUESTION;
    case TypeConstants::QUANT_STAR:
      return ITEM_TYPE_STAR;
    case TypeConstants::QUANT_PLUS:
      return ITEM_TYPE_PLUS;
    default:
      return xqtref_t(0);
  }
}

xqtref_t RootTypeManager::create_any_simple_type() const
{
  return ANY_SIMPLE_TYPE;
}

xqtref_t RootTypeManager::create_untyped_type() const
{
  return UNTYPED_TYPE;
}

xqtref_t RootTypeManager::create_empty_type() const
{
  return EMPTY_TYPE;
}

xqtref_t RootTypeManager::create_none_type() const
{
  return NONE_TYPE;
}

xqtref_t RootTypeManager::create_user_defined_type(const UserDefinedXQType& type, TypeConstants::quantifier_t quantifier) const
{
    return xqtref_t(new UserDefinedXQType(type.getQName(), type.getBaseType(), quantifier));
}

/* vim:set ts=2 sw=2: */
