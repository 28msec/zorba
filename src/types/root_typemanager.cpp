#include <assert.h>

#include <zorba/identtypes.h>
#include <zorba/typeident.h>
#include "zorbatypes/xqpstring.h"
#include "system/globalenv.h"
#include "store/naive/atomic_items.h"
#include "types/node_test.h"
#include "types/typeops.h"
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

#define Q( q ) TypeConstants::QUANT_##q

const TypeConstants::quantifier_t RootTypeManager::QUANT_MULT_MATRIX [4] [4] = {
  //  ONE          QUESTION     STAR     PLUS
  { Q(ONE),      Q(QUESTION), Q(STAR), Q(PLUS) }, // ONE
  { Q(QUESTION), Q(QUESTION), Q(STAR), Q(STAR) }, // QUESTION
  { Q(STAR),     Q(STAR),     Q(STAR), Q(STAR) }, // STAR
  { Q(PLUS),     Q(STAR),     Q(STAR), Q(PLUS) }, // PLUS
};

const TypeConstants::quantifier_t RootTypeManager::QUANT_INTERS_MATRIX [4] [4] = {
  //  ONE          QUESTION     STAR         PLUS
  { Q(ONE),      Q(ONE),      Q(ONE),      Q(ONE)  },  // ONE
  { Q(ONE),      Q(QUESTION), Q(QUESTION), Q(ONE)  },  // QUESTION
  { Q(ONE),      Q(QUESTION), Q(STAR),     Q(PLUS) },  // STAR
  { Q(ONE),      Q(ONE),      Q(PLUS),     Q(PLUS) }   // PLUS
};

#undef Q

RootTypeManager::RootTypeManager()
  : TypeManager(0)
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
  basename##_TYPE_ONE = new AtomicXQType(this, TypeConstants::XS_##basename, TypeConstants::QUANT_ONE); \
  basename##_TYPE_QUESTION = new AtomicXQType(this, TypeConstants::XS_##basename, TypeConstants::QUANT_QUESTION); \
  basename##_TYPE_STAR = new AtomicXQType(this, TypeConstants::XS_##basename, TypeConstants::QUANT_STAR); \
  basename##_TYPE_PLUS = new AtomicXQType(this, TypeConstants::XS_##basename, TypeConstants::QUANT_PLUS); \
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

  ANY_TYPE = new AnyXQType(this);

  ANY_SIMPLE_TYPE = new AnySimpleXQType(this);

  UNTYPED_TYPE = new UntypedXQType(this);

  EMPTY_TYPE = new EmptyXQType(this);

  NONE_TYPE = new NoneXQType(this);

  ITEM_TYPE_ONE = new ItemXQType(this, TypeConstants::QUANT_ONE);
  ITEM_TYPE_QUESTION = new ItemXQType(this, TypeConstants::QUANT_QUESTION);
  ITEM_TYPE_STAR = new ItemXQType(this, TypeConstants::QUANT_STAR);
  ITEM_TYPE_PLUS = new ItemXQType(this, TypeConstants::QUANT_PLUS);

#define NODE_TYPE_DEFN(basename) \
  basename##_TYPE_ONE = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_ONE); \
  basename##_TYPE_QUESTION = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_QUESTION); \
  basename##_TYPE_STAR = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_STAR); \
  basename##_TYPE_PLUS = new NodeXQType(this, NodeTest::basename##_TEST, EMPTY_TYPE, TypeConstants::QUANT_PLUS);
  NODE_TYPE_DEFN(PI)
  NODE_TYPE_DEFN(TEXT)
  NODE_TYPE_DEFN(COMMENT)
  NODE_TYPE_DEFN(DOCUMENT)
  NODE_TYPE_DEFN(ANY_NODE)
#undef NODE_TYPE_DEFN
}

RootTypeManager::~RootTypeManager()
{
}

xqtref_t RootTypeManager::create_type_x_quant(const XQType& type, TypeConstants::quantifier_t quantifier) const
{
  return create_type(type, QUANT_MULT_MATRIX[type.get_quantifier()][quantifier]);
}

xqtref_t RootTypeManager::create_type(const TypeIdentifier& ident) const
{
  TypeConstants::quantifier_t q = TypeConstants::QUANT_ONE;
  switch(ident.getQuantifier()) {
    case IdentTypes::QUANT_ONE:
      q = TypeConstants::QUANT_ONE;
      break;

    case IdentTypes::QUANT_QUESTION:
      q = TypeConstants::QUANT_QUESTION;
      break;

    case IdentTypes::QUANT_PLUS:
      q = TypeConstants::QUANT_PLUS;
      break;

    case IdentTypes::QUANT_STAR:
      q = TypeConstants::QUANT_STAR;
      break;
  }

  switch(ident.getKind()) {
    case IdentTypes::NAMED_TYPE:
      return create_type(GENV_ITEMFACTORY->createQName(ident.getUri().c_str(), NULL, ident.getLocalName().c_str()), q);

    case IdentTypes::ELEMENT_TYPE:
      {
        rchandle<NodeNameTest> nnt(new NodeNameTest(GENV_ITEMFACTORY->createQName(ident.getUri().c_str(), NULL, ident.getLocalName().c_str())));
        rchandle<NodeTest> nt(new NodeTest(store::StoreConsts::elementNode, nnt));
        type_ident_ref_t ci = ident.getContentType();
        xqtref_t content_type = ci != NULL ? create_type(*ci) : xqtref_t(0);
        return create_node_type(nt, content_type, q);
      }

    case IdentTypes::ATTRIBUTE_TYPE:
      {
        rchandle<NodeNameTest> nnt(new NodeNameTest(GENV_ITEMFACTORY->createQName(ident.getUri().c_str(), NULL, ident.getLocalName().c_str())));
        rchandle<NodeTest> nt(new NodeTest(store::StoreConsts::attributeNode, nnt));
        type_ident_ref_t ci = ident.getContentType();
        xqtref_t content_type = ci != NULL ? create_type(*ci) : xqtref_t(0);
        return create_node_type(nt, content_type, q);
      }

    case IdentTypes::DOCUMENT_TYPE:
      {
        type_ident_ref_t ci = ident.getContentType();
        xqtref_t content_type = ci != NULL ? create_type(*ci) : xqtref_t(0);
        return create_node_type(NodeTest::DOCUMENT_TEST, content_type, q);
      }

    case IdentTypes::PI_TYPE:
      return create_node_type(NodeTest::PI_TEST, NONE_TYPE, q);

    case IdentTypes::TEXT_TYPE:
      return create_node_type(NodeTest::TEXT_TEST, NONE_TYPE, q);

    case IdentTypes::COMMENT_TYPE:
      return create_node_type(NodeTest::COMMENT_TEST, NONE_TYPE, q);

    case IdentTypes::ANY_NODE_TYPE:
      return create_node_type(NodeTest::ANY_NODE_TEST, NONE_TYPE, q);

    case IdentTypes::ITEM_TYPE:
      return create_item_type(q);

    case IdentTypes::EMPTY_TYPE:
      return create_empty_type();

    default:
      break;
  }

  return xqtref_t(0);
}


xqtref_t RootTypeManager::create_type(
    const XQType& type,
    TypeConstants::quantifier_t quantifier) const
{
  // quantifier multiplication:
  // quantifier = QUANT_MULT_MATRIX [quantifier] [type.get_quantifier ()];
  // most code assumes that the quantifier arg *overrides* the original quantifier!
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
    case XQType::NONE_KIND:
      return EMPTY_TYPE;

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
  return new NodeXQType(this, nodetest, content_type, quantifier);
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
    return xqtref_t(new UserDefinedXQType(this, type.getQName(), type.getBaseType(), quantifier));
}

/* vim:set ts=2 sw=2: */
