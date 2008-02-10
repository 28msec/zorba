#ifndef XQP_TYPECONSTANTS_H
#define XQP_TYPECONSTANTS_H

namespace xqp {

class TypeConstants {
  public:
    typedef enum {
      QUANT_ONE = 0, QUANT_QUESTION, QUANT_STAR, QUANT_PLUS,
      QUANTIFIER_LIST_SIZE
    } quantifier_t;

    typedef enum {
      XS_ANY_ATOMIC = 0,
      XS_STRING,
      XS_NORMALIZED_STRING,
      XS_TOKEN,
      XS_LANGUAGE,
      XS_NMTOKEN,
      XS_NAME,
      XS_NCNAME,
      XS_ID,
      XS_IDREF,
      XS_ENTITY,
      XS_UNTYPED_ATOMIC,
      XS_DATETIME,
      XS_DATE,
      XS_TIME,
      XS_DURATION,
      XS_DT_DURATION,
      XS_YM_DURATION,
      XS_FLOAT,
      XS_DOUBLE,
      XS_DECIMAL,
      XS_INTEGER,
      XS_NON_POSITIVE_INTEGER,
      XS_NEGATIVE_INTEGER,
      XS_LONG,
      XS_INT,
      XS_SHORT,
      XS_BYTE,
      XS_NON_NEGATIVE_INTEGER,
      XS_UNSIGNED_LONG,
      XS_UNSIGNED_INT,
      XS_UNSIGNED_SHORT,
      XS_UNSIGNED_BYTE,
      XS_POSITIVE_INTEGER,
      XS_GYEAR_MONTH,
      XS_GYEAR,
      XS_GMONTH_DAY,
      XS_GDAY,
      XS_GMONTH,
      XS_BOOLEAN,
      XS_BASE64BINARY,
      XS_HEXBINARY,
      XS_ANY_URI,
      XS_QNAME,
      XS_NOTATION,
      ATOMIC_TYPE_CODE_LIST_SIZE // Used to indicate the size of the list.
    } atomic_type_code_t;
};

}

#endif /* XQP_TYPECONSTANTS_H */
/* vim:set ts=2 sw=2: */
