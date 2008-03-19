#ifndef ZORBA_ROOT_TYPEMANAGER_H
#define ZORBA_ROOT_TYPEMANAGER_H

#include <map>
#include <assert.h>
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typemanager.h"

namespace zorba {

class RootTypeManager : public TypeManager {
  public:
    ~RootTypeManager();


    TypeManager *get_parent_type_manager() const { return NULL; }

    /*
     * Writes a string representation of the given type to the output stream.
     */
    std::ostream& serialize(std::ostream& os, const XQType& type) const;
  
    std::string toString (const XQType& type) const;

    /*
     * Returns the quantifier of the argument.
     */
    TypeConstants::quantifier_t quantifier(const XQType& type) const;

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
     * Returns true if _item_ is treatable as _type_, false otherwise.
     */
    bool is_treatable(const store::Item_t item, const XQType& type) const;

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
     * Returns true is the given type is a numeric type.
     */
    bool is_numeric(const XQType& type) const;

    /*
     * Returns the atomic_type_code_t for the given type.
     * The input type MUST be atomic.
     */
    TypeConstants::atomic_type_code_t get_atomic_type_code(const XQType& type) const;

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
     * Returns the type to be used for arithmetic ops.
     */
    xqtref_t arithmetic_type(const XQType& type1, const XQType& type2) const;

   /*
    * Multiplies type by quantifier.
    * TODO: create_type should do this (currently overrides quantifier)
    */
    xqtref_t type_x_quant (const XQType& type, TypeConstants::quantifier_t quant) const {
      return create_type (type, QUANT_MULT_MATRIX [quant] [quantifier (type)]);
    }

    /*
     * Returns the NodeNameTest for the given type, if one exists.
     */
    rchandle<NodeNameTest> get_nametest(const XQType& type) const;

    /*
     * Returns a type identifier that represents the given type.
     * The invariant that is guaranteed is:
     *    is_subtype(_t_, create_type(*get_type_identifier(_t_))) == true
     */
    type_ident_ref_t get_type_identifier(const XQType& type) const;

    /* Factory Methods */
    xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

    xqtref_t create_type(const TypeIdentifier& ident) const;

    xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_any_type() const;

    xqtref_t create_item_type(TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_any_simple_type() const;

    xqtref_t create_untyped_type() const;

    xqtref_t create_empty_type() const;

    xqtref_t create_none_type() const;
    
    xqtref_t create_user_defined_type(const UserDefinedXQType& type, TypeConstants::quantifier_t quantifier) const;
    
    store::Item_t XS_ANY_TYPE_QNAME;

    store::Item_t XS_ANY_SIMPLE_TYPE_QNAME;

    store::Item_t XS_UNTYPED_QNAME;

#define ATOMIC_DECL(basename) \
    store::Item_t XS_##basename##_QNAME; \
    xqtref_t basename##_TYPE_ONE;\
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;

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

    xqtref_t ANY_TYPE;

    xqtref_t ANY_SIMPLE_TYPE;

    xqtref_t UNTYPED_TYPE;

    xqtref_t EMPTY_TYPE;

    xqtref_t NONE_TYPE;

#define ALL_QUANT_TYPE_DECL(basename) \
    xqtref_t basename##_TYPE_ONE; \
    xqtref_t basename##_TYPE_QUESTION; \
    xqtref_t basename##_TYPE_STAR; \
    xqtref_t basename##_TYPE_PLUS;

    ALL_QUANT_TYPE_DECL(ITEM)
    ALL_QUANT_TYPE_DECL(ANY_NODE)
    ALL_QUANT_TYPE_DECL(PI)
    ALL_QUANT_TYPE_DECL(TEXT)
    ALL_QUANT_TYPE_DECL(COMMENT)
#undef ALL_QUANT_TYPE_DECL


  private:

    xqtref_t *m_atomic_typecode_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];
    store::Item_t *m_atomic_typecode_qname_map[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];
    typedef std::map<store::Item_t, TypeConstants::atomic_type_code_t> qnametype_map_t;
    qnametype_map_t m_atomic_qnametype_map;

    static const bool ATOMIC_SUBTYPE_MATRIX[TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE][TypeConstants::ATOMIC_TYPE_CODE_LIST_SIZE];
    static const bool QUANT_SUBTYPE_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];
    static const TypeConstants::quantifier_t QUANT_MULT_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];
    static const TypeConstants::quantifier_t QUANT_INTERS_MATRIX[TypeConstants::QUANTIFIER_LIST_SIZE][TypeConstants::QUANTIFIER_LIST_SIZE];

    RootTypeManager();

    friend class root_static_context;
};

}

#endif /* ZORBA_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
