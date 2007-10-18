#ifndef XQP_TYPESYSTEM_H
#define XQP_TYPESYSTEM_H

#include "util/rchandle.h"

namespace xqp {

class XQType;
class AtomicXQType;
class TypeFactory;


/*
 * Atomic type constants
 */
class AtomicTypeConstants {
    public:
        typedef enum {
            XS_STRING = 0,
            XS_BOOLEAN,
            XS_FLOAT,
            XS_DOUBLE,
            XS_DURATION,
            XS_DATETIME,
            XS_TIME,
            XS_DATE,
            XS_GYEAR_MONTH,
            XS_GYEAR,
            XS_GMONTH_DAY,
            XS_GDAY,
            XS_GMONTH,
            XS_HEXBINARY,
            XS_BASE64BINARY,
            XS_ANY_URI,
            XS_QNAME,
            XS_NOTATION,
            XS_UNTYPED_ATOMIC
        } type_code_t;

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

        static cxqtref_t STRING_TYPE;
        static cxqtref_t BOOLEAN_TYPE;
        static cxqtref_t FLOAT_TYPE;
        static cxqtref_t DOUBLE_TYPE;
        static cxqtref_t DURATION_TYPE;
        static cxqtref_t DATETIME_TYPE;
        static cxqtref_t TIME_TYPE;
        static cxqtref_t DATE_TYPE;
        static cxqtref_t GYEAR_MONTH_TYPE;
        static cxqtref_t GYEAR_TYPE;
        static cxqtref_t GMONTH_DAY_TYPE;
        static cxqtref_t GDAY_TYPE;
        static cxqtref_t GMONTH_TYPE;
        static cxqtref_t HEXBINARY_TYPE;
        static cxqtref_t BASE64BINARY_TYPE;
        static cxqtref_t ANY_URI_TYPE;
        static cxqtref_t QNAME_TYPE;
        static cxqtref_t NOTATION_TYPE;
        static cxqtref_t UNTYPED_ATOMIC_TYPE;

        /*
         * Returns the quantifier of the argument.
         */
        static quantifier_t quantifier(const XQType *type);

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

    private:
        // Cannot instantiate the type system.
        // Cannot derive from TypeSystem.
        TypeSystem() {}
        ~TypeSystem() {}
};

class TypeFactory {
    public:
        TypeFactory() {}
        virtual ~TypeFactory() {}

        virtual TypeSystem::xqtref_t create_atomic_type(
                AtomicTypeConstants::type_code_t type_code,
                TypeSystem::quantifier_t quantifier) = 0;
};

class BasicTypeFactory : public TypeFactory {
    public:
        BasicTypeFactory() {}
        virtual ~BasicTypeFactory() {}

        static BasicTypeFactory& get_instance();

        virtual TypeSystem::xqtref_t create_atomic_type(AtomicTypeConstants::type_code_t type_code, TypeSystem::quantifier_t quantifier);
};

/*
 * Implementation specific classes after this point.
 */

class XQType : public rcobject {
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
        virtual type_kind_t type_kind() = 0;

        friend class TypeSystem;
};

class AtomicXQType : public XQType {
    private:
        static const bool SUBTYPE_MATRIX[19][19];

        AtomicTypeConstants::type_code_t m_type_code;

    protected:
        virtual type_kind_t type_kind() {
            return ATOMIC_TYPE_KIND;
        }

        AtomicXQType(AtomicTypeConstants::type_code_t type_code, TypeSystem::quantifier_t quantifier)
            : XQType(quantifier), m_type_code(type_code) { }

        friend class TypeSystem;
        friend class BasicTypeFactory;
};

}

#endif /* XQP_TYPESYSTEM_H */
