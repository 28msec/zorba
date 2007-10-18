#include "typesystem.h"

using namespace xqp;

#define T true
#define F false

/* TODO - The type matrix is not done yet */
const bool AtomicXQType::SUBTYPE_MATRIX[19][19] = {
    {T, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
    {F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F, F},
};

#undef T
#undef F

#define ATOMIC_TYPE_DECL(name, tc, q) TypeSystem::cxqtref_t TypeSystem::name(BasicTypeFactory::get_instance().create_atomic_type(AtomicTypeConstants::tc, TypeSystem::q))

ATOMIC_TYPE_DECL(STRING_TYPE, XS_STRING, QUANT_ONE);
ATOMIC_TYPE_DECL(BOOLEAN_TYPE, XS_BOOLEAN, QUANT_ONE);
ATOMIC_TYPE_DECL(FLOAT_TYPE, XS_FLOAT, QUANT_ONE);
ATOMIC_TYPE_DECL(DOUBLE_TYPE, XS_DOUBLE, QUANT_ONE);
ATOMIC_TYPE_DECL(DURATION_TYPE, XS_DURATION, QUANT_ONE);
ATOMIC_TYPE_DECL(DATETIME_TYPE, XS_DATETIME, QUANT_ONE);
ATOMIC_TYPE_DECL(TIME_TYPE, XS_TIME, QUANT_ONE);
ATOMIC_TYPE_DECL(DATE_TYPE, XS_DATE, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_MONTH_TYPE, XS_GYEAR_MONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(GYEAR_TYPE, XS_GYEAR, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_DAY_TYPE, XS_GMONTH_DAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GDAY_TYPE, XS_GDAY, QUANT_ONE);
ATOMIC_TYPE_DECL(GMONTH_TYPE, XS_GMONTH, QUANT_ONE);
ATOMIC_TYPE_DECL(HEXBINARY_TYPE, XS_HEXBINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(BASE64BINARY_TYPE, XS_BASE64BINARY, QUANT_ONE);
ATOMIC_TYPE_DECL(ANY_URI_TYPE, XS_ANY_URI, QUANT_ONE);
ATOMIC_TYPE_DECL(QNAME_TYPE, XS_QNAME, QUANT_ONE);
ATOMIC_TYPE_DECL(NOTATION_TYPE, XS_NOTATION, QUANT_ONE);
ATOMIC_TYPE_DECL(UNTYPED_ATOMIC_TYPE, XS_UNTYPED_ATOMIC, QUANT_ONE);

#undef ATOMIC_TYPE_DECL

TypeSystem::quantifier_t TypeSystem::quantifier(const XQType *type) {
    return TypeSystem::QUANT_ONE;
}

bool TypeSystem::is_equal(const XQType& type1, const XQType& type2) {
    return false;
}

bool TypeSystem::is_subtype(const XQType& subtype, const XQType& supertype) {
    return false;
}

bool TypeSystem::is_promotable(const XQType& srctype, const XQType& targettype) {
    return false;
}

bool TypeSystem::is_atomic(const XQType& type) {
    return false;
}

bool TypeSystem::is_simple(const XQType& type) {
    return false;
}

TypeSystem::xqtref_t TypeSystem::union_type(TypeFactory& type_factory, const XQType& type1, const XQType& type2) {
    return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::intersect_type(TypeFactory& type_factory, const XQType& type1, const XQType& type2) {
    return TypeSystem::xqtref_t(0);
}

TypeSystem::xqtref_t TypeSystem::prime_type(TypeFactory& type_factory, const XQType& type) {
    return TypeSystem::xqtref_t(0);
}

BasicTypeFactory& BasicTypeFactory::get_instance() {
    static BasicTypeFactory *_m_instance = new BasicTypeFactory();

    return *_m_instance;
}

TypeSystem::xqtref_t BasicTypeFactory::create_atomic_type(AtomicTypeConstants::type_code_t type_code, TypeSystem::quantifier_t quantifier) {
    return TypeSystem::xqtref_t(new AtomicXQType(type_code, quantifier));
}

