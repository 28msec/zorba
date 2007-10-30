#ifndef XQP_TYPESYSTEM_H
#define XQP_TYPESYSTEM_H

#include "util/rchandle.h"

namespace xqp {

class XQType;
class AtomicXQType;
class TypeFactory;
class QNameItem;
class NameTest;

/*
 * Atomic type constants
 */
class AtomicTypeConstants {
  public:
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
    } type_code_t;

    const static rchandle<QNameItem> XS_ANY_ATOMIC_QNAME;
    const static rchandle<QNameItem> XS_STRING_QNAME;
    const static rchandle<QNameItem> XS_NORMALIZED_STRING_QNAME;
    const static rchandle<QNameItem> XS_TOKEN_QNAME;
    const static rchandle<QNameItem> XS_LANGUAGE_QNAME;
    const static rchandle<QNameItem> XS_NMTOKEN_QNAME;
    const static rchandle<QNameItem> XS_NAME_QNAME;
    const static rchandle<QNameItem> XS_NCNAME_QNAME;
    const static rchandle<QNameItem> XS_ID_QNAME;
    const static rchandle<QNameItem> XS_IDREF_QNAME;
    const static rchandle<QNameItem> XS_ENTITY_QNAME;
    const static rchandle<QNameItem> XS_UNTYPED_ATOMIC_QNAME;
    const static rchandle<QNameItem> XS_DATETIME_QNAME;
    const static rchandle<QNameItem> XS_DATE_QNAME;
    const static rchandle<QNameItem> XS_TIME_QNAME;
    const static rchandle<QNameItem> XS_DURATION_QNAME;
    const static rchandle<QNameItem> XS_DT_DURATION_QNAME;
    const static rchandle<QNameItem> XS_YM_DURATION_QNAME;
    const static rchandle<QNameItem> XS_FLOAT_QNAME;
    const static rchandle<QNameItem> XS_DOUBLE_QNAME;
    const static rchandle<QNameItem> XS_DECIMAL_QNAME;
    const static rchandle<QNameItem> XS_INTEGER_QNAME;
    const static rchandle<QNameItem> XS_NON_POSITIVE_INTEGER_QNAME;
    const static rchandle<QNameItem> XS_NEGATIVE_INTEGER_QNAME;
    const static rchandle<QNameItem> XS_LONG_QNAME;
    const static rchandle<QNameItem> XS_INT_QNAME;
    const static rchandle<QNameItem> XS_SHORT_QNAME;
    const static rchandle<QNameItem> XS_BYTE_QNAME;
    const static rchandle<QNameItem> XS_NON_NEGATIVE_INTEGER_QNAME;
    const static rchandle<QNameItem> XS_UNSIGNED_LONG_QNAME;
    const static rchandle<QNameItem> XS_UNSIGNED_INT_QNAME;
    const static rchandle<QNameItem> XS_UNSIGNED_SHORT_QNAME;
    const static rchandle<QNameItem> XS_UNSIGNED_BYTE_QNAME;
    const static rchandle<QNameItem> XS_POSITIVE_INTEGER_QNAME;
    const static rchandle<QNameItem> XS_GYEAR_MONTH_QNAME;
    const static rchandle<QNameItem> XS_GYEAR_QNAME;
    const static rchandle<QNameItem> XS_GMONTH_DAY_QNAME;
    const static rchandle<QNameItem> XS_GDAY_QNAME;
    const static rchandle<QNameItem> XS_GMONTH_QNAME;
    const static rchandle<QNameItem> XS_BOOLEAN_QNAME;
    const static rchandle<QNameItem> XS_BASE64BINARY_QNAME;
    const static rchandle<QNameItem> XS_HEXBINARY_QNAME;
    const static rchandle<QNameItem> XS_ANY_URI_QNAME;
    const static rchandle<QNameItem> XS_QNAME_QNAME;
    const static rchandle<QNameItem> XS_NOTATION_QNAME;

  private:
    AtomicTypeConstants() {}
    ~AtomicTypeConstants() {}
};

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeSystem {
  public:
    typedef enum {
      QUANT_ZERO = 0, QUANT_ONE, QUANT_QUESTION, QUANT_STAR, QUANT_PLUS
    } quantifier_t;

  public:
    typedef rchandle<XQType> xqtref_t;
    typedef const rchandle<XQType> cxqtref_t;

    static cxqtref_t ANY_ATOMIC_TYPE;
    static cxqtref_t STRING_TYPE;
    static cxqtref_t NORMALIZED_STRING_TYPE;
    static cxqtref_t TOKEN_TYPE;
    static cxqtref_t LANGUAGE_TYPE;
    static cxqtref_t NMTOKEN_TYPE;
    static cxqtref_t NAME_TYPE;
    static cxqtref_t NCNAME_TYPE;
    static cxqtref_t ID_TYPE;
    static cxqtref_t IDREF_TYPE;
    static cxqtref_t ENTITY_TYPE;
    static cxqtref_t UNTYPED_ATOMIC_TYPE;
    static cxqtref_t DATETIME_TYPE;
    static cxqtref_t DATE_TYPE;
    static cxqtref_t TIME_TYPE;
    static cxqtref_t DURATION_TYPE;
    static cxqtref_t DT_DURATION_TYPE;
    static cxqtref_t YM_DURATION_TYPE;
    static cxqtref_t FLOAT_TYPE;
    static cxqtref_t DOUBLE_TYPE;
    static cxqtref_t DECIMAL_TYPE;
    static cxqtref_t INTEGER_TYPE;
    static cxqtref_t NON_POSITIVE_INTEGER_TYPE;
    static cxqtref_t NEGATIVE_INTEGER_TYPE;
    static cxqtref_t LONG_TYPE;
    static cxqtref_t INT_TYPE;
    static cxqtref_t SHORT_TYPE;
    static cxqtref_t BYTE_TYPE;
    static cxqtref_t NON_NEGATIVE_INTEGER_TYPE;
    static cxqtref_t UNSIGNED_LONG_TYPE;
    static cxqtref_t UNSIGNED_INT_TYPE;
    static cxqtref_t UNSIGNED_SHORT_TYPE;
    static cxqtref_t UNSIGNED_BYTE_TYPE;
    static cxqtref_t POSITIVE_INTEGER_TYPE;
    static cxqtref_t GYEAR_MONTH_TYPE;
    static cxqtref_t GYEAR_TYPE;
    static cxqtref_t GMONTH_DAY_TYPE;
    static cxqtref_t GDAY_TYPE;
    static cxqtref_t GMONTH_TYPE;
    static cxqtref_t BOOLEAN_TYPE;
    static cxqtref_t BASE64BINARY_TYPE;
    static cxqtref_t HEXBINARY_TYPE;
    static cxqtref_t ANY_URI_TYPE;
    static cxqtref_t QNAME_TYPE;
    static cxqtref_t NOTATION_TYPE;

    /*
     * Returns the quantifier of the argument.
     */
    static quantifier_t quantifier(const XQType& type);

    /*
     * Returns true iff _type1_ is equal to _type2_ including the quantifier,
     * false otherwise.
     */
    static bool is_equal(const XQType& type1, const XQType& type2);

    /*
     * Returns true if _subtype_ is a subtype of _supertype_, false otherwise.
     */
    static bool is_subtype(const XQType& subtype, const XQType& supertype);

    /*
     * Returns true if _srctype_ is promotable to _targettype_, false otherwise.
     */
    static bool is_promotable(const XQType& srctype, const XQType& targettype);

    /*
     * Returns true if the given type is an atomic type. The quantifier of such
     * a type MUST be QUANT_ONE.
     */
    static bool is_atomic(const XQType& type);

    /*
     * Returns true if the given type is simple. A simple type means that its
     * primetype is atomic.
     */
    static bool is_simple(const XQType& type);

    /*
     * Computes the union type (type1 | type2), of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
     */
    static xqtref_t union_type(TypeFactory& type_factory, const XQType& type1, const XQType& type2);

    /*
     * Computes the intersection of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      there exists some type(not necessarily representable in this TypeSystem), _t_
     *      such that:
     *          is_subtype(_t_, _type1_) == true && is_subtype(_t_, _type2_) == true
     *          && is_subtype(_t_, _u_) == true.
     *
     * Informally, the returned type is a supertype (not necessarily a perfect supertype)
     * of the actual intersection type.
     */
    static xqtref_t intersect_type(TypeFactory& type_factory,
        const XQType& type1, const XQType& type2);

    /*
     * Returns the prime type of the given type.
     */
    static xqtref_t prime_type(TypeFactory& type_factory, const XQType& type);

    /*
     * Returns the NameTest for the given type, if one exists.
     */
    static rchandle<NameTest> get_nametest(const XQType& type);

  private:
    // Cannot instantiate the type system.
    // Cannot derive from TypeSystem.
    TypeSystem() {}
    ~TypeSystem() {}

    static const bool ATOMIC_SUBTYPE_MATRIX[45][45];
    static const bool QUANT_SUBTYPE_MATRIX[5][5];
};

class TypeFactory {
  public:
    TypeFactory() {}
    virtual ~TypeFactory() {}

    virtual TypeSystem::xqtref_t create_atomic_type(
        AtomicTypeConstants::type_code_t type_code,
        TypeSystem::quantifier_t quantifier) = 0;

    virtual TypeSystem::xqtref_t create_atomic_type(
        rchandle<QNameItem> qname,
        TypeSystem::quantifier_t quantifier) = 0;

    virtual TypeSystem::xqtref_t create_node_type(
        rchandle<NodeTest> nodetest,
        TypeSystem::quantifier_t quantifier) = 0;
};

class BasicTypeFactory : public TypeFactory {
  public:
    BasicTypeFactory() {}
    virtual ~BasicTypeFactory() {}

    static BasicTypeFactory& get_instance();

    virtual TypeSystem::xqtref_t create_atomic_type(
        AtomicTypeConstants::type_code_t type_code,
        TypeSystem::quantifier_t quantifier);

    virtual TypeSystem::xqtref_t create_atomic_type(
        rchandle<QNameItem> qname,
        TypeSystem::quantifier_t quantifier);

    virtual TypeSystem::xqtref_t create_node_type(
        rchandle<NodeTest> nodetest,
        TypeSystem::quantifier_t quantifier);
};

/*
 * Implementation specific classes after this point.
 */

class XQType : virtual public rcobject {
  private:
    TypeSystem::quantifier_t m_quantifier;

  protected:
    typedef enum {
      ATOMIC_TYPE_KIND,
      NODE_TYPE_KIND
    } type_kind_t;

    XQType(TypeSystem::quantifier_t quantifier)
      : m_quantifier(quantifier) { }
    virtual ~XQType() { }
    virtual type_kind_t type_kind() const = 0;

    friend class TypeSystem;
};

class AtomicXQType : public XQType {
  private:
    AtomicTypeConstants::type_code_t m_type_code;

  protected:
    virtual type_kind_t type_kind() const
    {
      return ATOMIC_TYPE_KIND;
    }

    AtomicXQType(AtomicTypeConstants::type_code_t type_code, TypeSystem::quantifier_t quantifier)
      : XQType(quantifier), m_type_code(type_code) { }

    friend class TypeSystem;
    friend class BasicTypeFactory;
};

class NodeXQType : public XQType {
  private:
    rchandle<NodeTest> m_nodetest;

  protected:
    virtual type_kind_t type_kind() const
    {
      return NODE_TYPE_KIND;
    }

    NodeXQType(rchandle<NodeTest> nodetest, TypeSystem::quantifier_t quantifier) : XQType(quantifier), m_nodetest(nodetest) { }

    friend class TypeSystem;
    friend class BasicTypeFactory;
};

}

#endif /* XQP_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
