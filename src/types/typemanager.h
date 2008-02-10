#ifndef XQP_TYPEMANAGER_H
#define XQP_TYPEMANAGER_H

#include <ostream>
#include "util/rchandle.h"
#include "types/typeconstants.h"

namespace xqp {

class XQType;
class NodeTest;
class NodeNameTest;
class TypeIdentifier;
class Item;

typedef rchandle<XQType> xqtref_t;
typedef rchandle<TypeIdentifier> type_ident_ref_t;
typedef rchandle<Item> Item_t;

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeManager {
  public:
    virtual ~TypeManager() { }

    virtual TypeManager *get_parent_type_manager() const = 0;

    /*
     * Writes a string representation of the given type to the output stream.
     */
    virtual std::ostream& serialize(std::ostream& os, const XQType& type) const = 0;
  
    virtual std::string toString (const XQType& type) const = 0;

    /*
     * Returns the quantifier of the argument.
     */
    virtual TypeConstants::quantifier_t quantifier(const XQType& type) const = 0;

    /*
     * Returns true iff _type1_ is equal to _type2_ including the quantifier,
     * false otherwise.
     */
    virtual bool is_equal(const XQType& type1, const XQType& type2) const = 0;

    /*
     * Returns true if _subtype_ is a subtype of _supertype_, false otherwise.
     */
    virtual bool is_subtype(const XQType& subtype, const XQType& supertype) const = 0;

    /*
     * Returns true if _srctype_ is promotable to _targettype_, false otherwise.
     */
    virtual bool is_promotable(const XQType& srctype, const XQType& targettype) const = 0;

    /*
     * Returns true if the given type is an atomic type. The quantifier of such
     * a type MUST be QUANT_ONE.
     */
    virtual bool is_atomic(const XQType& type) const = 0;

    /*
     * Returns true if the given type is simple. A simple type means that its
     * primetype is atomic.
     */
    virtual bool is_simple(const XQType& type) const = 0;

    /*
     * Returns true is the given type is a numeric type.
     */
    virtual bool is_numeric(const XQType& type) const = 0;

    /*
     * Returns the atomic_type_code_t for the given type.
     * The input type MUST be atomic.
     */
    virtual TypeConstants::atomic_type_code_t get_atomic_type_code(const XQType& type) const = 0;

    /*
     * Computes the union type (type1 | type2), of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
     */
    virtual xqtref_t union_type(const XQType& type1, const XQType& type2) const = 0;

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
    virtual xqtref_t intersect_type(const XQType& type1, const XQType& type2) const = 0;

    /*
     * Returns the prime type of the given type.
     */
    virtual xqtref_t prime_type(const XQType& type) const = 0;

    /*
     * Returns the type to be used for arithmetic ops.
     */
    virtual xqtref_t arithmetic_type(const XQType& type1, const XQType& type2) const = 0;

    /*
     * Returns the NodeNameTest for the given type, if one exists.
     */
    virtual rchandle<NodeNameTest> get_nametest(const XQType& type) const = 0;

    /*
     * Returns a type identifier that represents the given type.
     * The invariant that is guaranteed is:
     *    is_subtype(_t_, create_type(*get_type_identifier(_t_))) == true
     */
    virtual type_ident_ref_t get_type_identifier(const XQType& type) const = 0;

    /* Factory Methods */
    virtual xqtref_t create_type(Item_t qname, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_type(const TypeIdentifier& ident) const = 0;

    virtual xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_atomic_type(Item_t qname, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_type() const = 0;

    virtual xqtref_t create_item_type(TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_simple_type() const = 0;

    virtual xqtref_t create_untyped_type() const = 0;

    virtual xqtref_t create_empty_type() const = 0;

    virtual xqtref_t create_none_type() const = 0;
};

}

#endif /* XQP_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
