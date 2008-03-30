#ifndef ZORBA_TYPEOPS_H
#define ZORBA_TYPEOPS_H

#include <string>
#include "common/shared_types.h"
#include "types/typeconstants.h"

namespace zorba {

typedef boost::shared_ptr<TypeIdentifier> type_ident_ref_t;

class TypeOps {
  public:
    /*
     * Writes a string representation of the given type to the output stream.
     */
    static std::ostream& serialize(std::ostream& os, const XQType& type);
  
    static std::string toString (const XQType& type);

    static const TypeManager *get_lower_manager(const TypeManager* m1, const TypeManager* m2);

    /*
     * Returns the quantifier of the argument.
     */
    static TypeConstants::quantifier_t quantifier(const XQType& type);

    /*
     * Returns the castability fron the source type to the target type
     */
    static TypeConstants::castable_t castability(const XQType& src, const XQType& target);

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
     * Returns true if _item_ is treatable as _type_, false otherwise.
     */
    static bool is_treatable(const store::Item_t item, const XQType& type);

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
     * Returns true is the given type is a numeric type.
     */
    static bool is_numeric(const XQType& type);

    /*
     * Returns the atomic_type_code_t for the given type.
     * The input type MUST be atomic.
     */
    static TypeConstants::atomic_type_code_t get_atomic_type_code(const XQType& type);

    /*
     * Computes the union type (type1 | type2), of the two types.
     * The output _u_ of this call satisfies the following invariant.
     *      is_subtype(_type1_, _u_) == true && is_subtype(_type2_, _u_) == true
     */
    static xqtref_t union_type(const XQType& type1, const XQType& type2);

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
    static xqtref_t intersect_type(const XQType& type1, const XQType& type2);

    /*
     * Returns the prime type of the given type.
     */
    static xqtref_t prime_type(const XQType& type);

    /*
     * Returns the type to be used for arithmetic ops.
     */
    static xqtref_t arithmetic_type(const XQType& type1, const XQType& type2);

    /*
     * Returns the NodeNameTest for the given type, if one exists.
     */
    static rchandle<NodeNameTest> get_nametest(const XQType& type);

    /*
     * Returns a type identifier that represents the given type.
     * The invariant that is guaranteed is:
     *    is_subtype(_t_, create_type(*get_type_identifier(_t_))) == true
     */
    static type_ident_ref_t get_type_identifier(const XQType& type);

    /*
     * Returns 0, 1 or 2 (2 meaning "many")
     */
    static int type_max_cnt (const XQType& type);

    /*
     * Returns 0 or 1
     */
    static int type_min_cnt (const XQType& type);

    static const int QUANT_MAX_CNT [TypeConstants::QUANTIFIER_LIST_SIZE];
    static const int QUANT_MIN_CNT [TypeConstants::QUANTIFIER_LIST_SIZE];
};

}

#endif /* ZORBA_TYPEOPS_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
