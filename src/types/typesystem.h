#ifndef XQP_TYPESYSTEM_H
#define XQP_TYPESYSTEM_H

#include "util/rchandle.h"

namespace xqp {

class XQType;
class AtomicXQType;
class QNameItem;
class NodeNameTest;

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeSystem {
  public:
    typedef enum {
      QUANT_ZERO = 0, QUANT_ONE, QUANT_QUESTION, QUANT_STAR, QUANT_PLUS,
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

    TypeSystem();
    ~TypeSystem() {}

    typedef rchandle<XQType> xqtref_t;

    /*
     * Returns the quantifier of the argument.
     */
    quantifier_t quantifier(const XQType& type) const;

    /*
     * Returns true iff _type1_ is equal to _type2_ including the quantifier,
     * false otherwise.
     */
    bool is_equal(const XQType& type1, const XQType& type2) const;

    /*
     * Returns true if _subtype_ is a subtype of _supertype_, false otherwise.
     */
    bool is_subtype(const XQType& subtype, const XQType& supertype) const;

    /*
     * Returns true if _srctype_ is promotable to _targettype_, false otherwise.
     */
    bool is_promotable(const XQType& srctype, const XQType& targettype) const;

    /*
     * Returns true if the given type is an atomic type. The quantifier of such
     * a type MUST be QUANT_ONE.
     */
    bool is_atomic(const XQType& type) const;

    /*
     * Returns true if the given type is simple. A simple type means that its
     * primetype is atomic.
     */
    bool is_simple(const XQType& type) const;

    /*
     * Computes the union type (type1 | type2), of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
     */
    xqtref_t union_type(const XQType& type1, const XQType& type2) const;

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
    xqtref_t intersect_type(const XQType& type1, const XQType& type2) const;

    /*
     * Returns the prime type of the given type.
     */
    xqtref_t prime_type(const XQType& type) const;

    /*
     * Returns the NodeNameTest for the given type, if one exists.
     */
    rchandle<NodeNameTest> get_nametest(const XQType& type) const;

    /* Factory Methods */
    xqtref_t create_atomic_type(atomic_type_code_t type_code, quantifier_t quantifier) const;

    xqtref_t create_atomic_type(rchandle<QNameItem> qname, quantifier_t quantifier) const;

    xqtref_t create_node_type(rchandle<NodeTest> nodetest, quantifier_t quantifier) const;

    xqtref_t create_any_type() const;

    xqtref_t create_item_type(quantifier_t quantifier) const;

    xqtref_t create_any_simple_type() const;

    xqtref_t create_untyped_type() const;

  private:

#define ATOMIC_DECL(basename) \
    rchandle<QNameItem> XS_##basename##_QNAME; \
    TypeSystem::xqtref_t basename##_TYPE_ONE;\
    TypeSystem::xqtref_t basename##_TYPE_QUESTION; \
    TypeSystem::xqtref_t basename##_TYPE_STAR; \
    TypeSystem::xqtref_t basename##_TYPE_PLUS;

    ATOMIC_DECL(ANY_ATOMIC)
    ATOMIC_DECL(STRING)
    ATOMIC_DECL(NORMALIZED_STRING)
    ATOMIC_DECL(TOKEN)
    ATOMIC_DECL(LANGUAGE)
    ATOMIC_DECL(NMTOKEN)
    ATOMIC_DECL(NAME)
    ATOMIC_DECL(NCNAME)
    ATOMIC_DECL(ID)
    ATOMIC_DECL(IDREF)
    ATOMIC_DECL(ENTITY)
    ATOMIC_DECL(UNTYPED_ATOMIC)
    ATOMIC_DECL(DATETIME)
    ATOMIC_DECL(DATE)
    ATOMIC_DECL(TIME)
    ATOMIC_DECL(DURATION)
    ATOMIC_DECL(DT_DURATION)
    ATOMIC_DECL(YM_DURATION)
    ATOMIC_DECL(FLOAT)
    ATOMIC_DECL(DOUBLE)
    ATOMIC_DECL(DECIMAL)
    ATOMIC_DECL(INTEGER)
    ATOMIC_DECL(NON_POSITIVE_INTEGER)
    ATOMIC_DECL(NEGATIVE_INTEGER)
    ATOMIC_DECL(LONG)
    ATOMIC_DECL(INT)
    ATOMIC_DECL(SHORT)
    ATOMIC_DECL(BYTE)
    ATOMIC_DECL(NON_NEGATIVE_INTEGER)
    ATOMIC_DECL(UNSIGNED_LONG)
    ATOMIC_DECL(UNSIGNED_INT)
    ATOMIC_DECL(UNSIGNED_SHORT)
    ATOMIC_DECL(UNSIGNED_BYTE)
    ATOMIC_DECL(POSITIVE_INTEGER)
    ATOMIC_DECL(GYEAR_MONTH)
    ATOMIC_DECL(GYEAR)
    ATOMIC_DECL(GMONTH_DAY)
    ATOMIC_DECL(GDAY)
    ATOMIC_DECL(GMONTH)
    ATOMIC_DECL(BOOLEAN)
    ATOMIC_DECL(BASE64BINARY)
    ATOMIC_DECL(HEXBINARY)
    ATOMIC_DECL(ANY_URI)
    ATOMIC_DECL(QNAME)
    ATOMIC_DECL(NOTATION)
#undef ATOMIC_DECL

    TypeSystem::xqtref_t ANY_TYPE;
    TypeSystem::xqtref_t ANY_SIMPLE_TYPE;
    TypeSystem::xqtref_t UNTYPED_TYPE;
    TypeSystem::xqtref_t ITEM_TYPE_ONE;
    TypeSystem::xqtref_t ITEM_TYPE_QUESTION;
    TypeSystem::xqtref_t ITEM_TYPE_STAR;
    TypeSystem::xqtref_t ITEM_TYPE_PLUS;

    TypeSystem::xqtref_t *m_atomic_typecode_map[ATOMIC_TYPE_CODE_LIST_SIZE][QUANTIFIER_LIST_SIZE];

    static const bool ATOMIC_SUBTYPE_MATRIX[ATOMIC_TYPE_CODE_LIST_SIZE][ATOMIC_TYPE_CODE_LIST_SIZE];
    static const bool QUANT_SUBTYPE_MATRIX[QUANTIFIER_LIST_SIZE][QUANTIFIER_LIST_SIZE];
};

/*
 * Implementation specific classes after this point.
 */

#define TYPE_FRIENDS friend class TypeSystem;

class XQType : virtual public rcobject {
  private:
    TypeSystem::quantifier_t m_quantifier;

  protected:
    typedef enum {
      ATOMIC_TYPE_KIND,
      NODE_TYPE_KIND,
      ANY_TYPE_KIND,
      ITEM_KIND,
      ANY_SIMPLE_TYPE_KIND,
      UNTYPED_KIND,
    } type_kind_t;

    XQType(TypeSystem::quantifier_t quantifier)
      : m_quantifier(quantifier) { }
    virtual ~XQType() { }
    virtual type_kind_t type_kind() const = 0;

    TYPE_FRIENDS
};

class AtomicXQType : public XQType {
  private:
    TypeSystem::atomic_type_code_t m_type_code;

  protected:
    virtual type_kind_t type_kind() const
    {
      return ATOMIC_TYPE_KIND;
    }

    AtomicXQType(TypeSystem::atomic_type_code_t type_code, TypeSystem::quantifier_t quantifier)
      : XQType(quantifier), m_type_code(type_code) { }

    TYPE_FRIENDS
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

    TYPE_FRIENDS
};

class AnyXQType : public XQType {
  protected:
    virtual type_kind_t type_kind() const
    {
      return ANY_TYPE_KIND;
    }

    AnyXQType() : XQType(TypeSystem::QUANT_STAR) { }

    TYPE_FRIENDS
};

class ItemXQType : public XQType {
  protected:
    virtual type_kind_t type_kind() const
    {
      return ITEM_KIND;
    }

    ItemXQType(TypeSystem::quantifier_t quantifier) : XQType(quantifier) { }

    TYPE_FRIENDS
};

class AnySimpleXQType : public XQType {
  protected:
    virtual type_kind_t type_kind() const
    {
      return ANY_SIMPLE_TYPE_KIND;
    }

    AnySimpleXQType() : XQType(TypeSystem::QUANT_STAR) { }

    TYPE_FRIENDS
};

class UntypedXQType : public XQType {
  protected:
    virtual type_kind_t type_kind() const
    {
      return UNTYPED_KIND;
    }

    UntypedXQType() : XQType(TypeSystem::QUANT_STAR) { }

    TYPE_FRIENDS
};

inline TypeSystem::xqtref_t TypeSystem::create_atomic_type(TypeSystem::atomic_type_code_t type_code, TypeSystem::quantifier_t quantifier) const
{
  return *m_atomic_typecode_map[type_code][quantifier];
}

inline TypeSystem::xqtref_t TypeSystem::create_atomic_type(rchandle<QNameItem> qname, TypeSystem::quantifier_t quantifier) const
{
  return TypeSystem::xqtref_t(0);
}

inline TypeSystem::xqtref_t TypeSystem::create_node_type(rchandle<NodeTest> nodetest, TypeSystem::quantifier_t quantifier) const
{
  return new NodeXQType(nodetest, quantifier);
}

inline TypeSystem::xqtref_t TypeSystem::create_any_type() const
{
  return ANY_TYPE;
}

inline TypeSystem::xqtref_t TypeSystem::create_item_type(TypeSystem::quantifier_t quantifier) const
{
  switch(quantifier) {
    case QUANT_ONE:
      return ITEM_TYPE_ONE;
    case QUANT_QUESTION:
      return ITEM_TYPE_QUESTION;
    case QUANT_STAR:
      return ITEM_TYPE_STAR;
    case QUANT_PLUS:
      return ITEM_TYPE_PLUS;
    default:
      return TypeSystem::xqtref_t(0);
  }
}

inline TypeSystem::xqtref_t TypeSystem::create_any_simple_type() const
{
  return ANY_SIMPLE_TYPE;
}

inline TypeSystem::xqtref_t TypeSystem::create_untyped_type() const
{
  return UNTYPED_TYPE;
}

}

#endif /* XQP_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
