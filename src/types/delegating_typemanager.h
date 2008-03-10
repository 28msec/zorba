#ifndef ZORBA_DELEGATING_TYPEMANAGER_H
#define ZORBA_DELEGATING_TYPEMANAGER_H

#include "types/typemanager.h"

namespace zorba {

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class DelegatingTypeManager : public TypeManager {
  public:
    DelegatingTypeManager(TypeManager *parent)
      : m_parent(parent) { }

    TypeManager *get_parent_type_manager() const { return m_parent; }

    /*
     * Writes a string representation of the given type to the output stream.
     */
    std::ostream& serialize(std::ostream& os, const XQType& type) const
    { return m_parent->serialize(os, type); }
  
    std::string toString (const XQType& type) const
    { return m_parent->toString(type); }

    /*
     * Returns the quantifier of the argument.
     */
    TypeConstants::quantifier_t quantifier(const XQType& type) const
    { return m_parent->quantifier(type); }

    /*
     * Returns true iff _type1_ is equal to _type2_ including the quantifier,
     * false otherwise.
     */
    bool is_equal(const XQType& type1, const XQType& type2) const
    { return m_parent->is_equal(type1, type2); }

    /*
     * Returns true if _subtype_ is a subtype of _supertype_, false otherwise.
     */
    bool is_subtype(const XQType& subtype, const XQType& supertype) const
    { return m_parent->is_subtype(subtype, supertype); }

    /*
     * Returns true if _srctype_ is promotable to _targettype_, false otherwise.
     */
    bool is_promotable(const XQType& srctype, const XQType& targettype) const
    { return m_parent->is_promotable(srctype, targettype); }

    /*
     * Returns true if _item_ is treatable as _type_, false otherwise.
     */
    bool is_treatable(const store::Item_t item, const XQType& type) const
    { return m_parent->is_treatable(item, type); }

    /*
     * Returns true if the given type is an atomic type. The quantifier of such
     * a type MUST be QUANT_ONE.
     */
    bool is_atomic(const XQType& type) const
    { return m_parent->is_atomic(type); }

    /*
     * Returns true if the given type is simple. A simple type means that its
     * primetype is atomic.
     */
    bool is_simple(const XQType& type) const
    { return m_parent->is_simple(type); }

    /*
     * Returns true is the given type is a numeric type.
     */
    bool is_numeric(const XQType& type) const
    { return m_parent->is_numeric(type); }

    /*
     * Returns the atomic_type_code_t for the given type.
     * The input type MUST be atomic.
     */
    TypeConstants::atomic_type_code_t get_atomic_type_code(const XQType& type) const
    { return m_parent->get_atomic_type_code(type); }

    /*
     * Computes the union type (type1 | type2), of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
     */
    xqtref_t union_type(const XQType& type1, const XQType& type2) const
    { return m_parent->union_type(type1, type2); }

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
    xqtref_t intersect_type(const XQType& type1, const XQType& type2) const
    { return m_parent->intersect_type(type1, type2); }

    /*
     * Returns the prime type of the given type.
     */
    xqtref_t prime_type(const XQType& type) const
    { return m_parent->prime_type(type); }

    /*
     * Returns the type to be used for arithmetic ops.
     */
    xqtref_t arithmetic_type(const XQType& type1, const XQType& type2) const
    { return m_parent->arithmetic_type(type1, type2); }

    /*
     * Returns the NodeNameTest for the given type, if one exists.
     */
    rchandle<NodeNameTest> get_nametest(const XQType& type) const
    { return m_parent->get_nametest(type); }

    /*
     * Returns a type identifier that represents the given type.
     * The invariant that is guaranteed is:
     *    is_subtype(_t_, create_type(*get_type_identifier(_t_))) == true
     */
    type_ident_ref_t get_type_identifier(const XQType& type) const
    { return m_parent->get_type_identifier(type); }

    /* Factory Methods */
    xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_type(qname, quantifier); }

    xqtref_t create_type(const TypeIdentifier& ident) const
    { return m_parent->create_type(ident); }

    xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_type(type, quantifier); }

    xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_atomic_type(type_code, quantifier); }

    xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_atomic_type(qname, quantifier); }

    xqtref_t create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_node_type(nodetest, content_type, quantifier); }

    xqtref_t create_any_type() const
    { return m_parent->create_any_type(); }

    xqtref_t create_item_type(TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_item_type(quantifier); }

    xqtref_t create_any_simple_type() const
    { return m_parent->create_any_simple_type(); }

    xqtref_t create_untyped_type() const
    { return m_parent->create_untyped_type(); }

    xqtref_t create_empty_type() const
    { return m_parent->create_empty_type(); }

    xqtref_t create_none_type() const
    { return m_parent->create_none_type(); }

  private:
    TypeManager *m_parent;
};

}

#endif /* ZORBA_DELEGATING_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
