#ifndef ZORBA_ROOT_TYPEMANAGER_H
#define ZORBA_ROOT_TYPEMANAGER_H

#include <map>
#include <assert.h>
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "types/typemanagerimpl.h"

namespace zorba {

class RootTypeManager : public TypeManagerImpl {
  public:
    ~RootTypeManager();

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
    ALL_QUANT_TYPE_DECL(DOCUMENT)
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
    friend class TypeOps;
    friend class TypeManagerImpl;
};

}

#endif /* ZORBA_TYPESYSTEM_H */
/* vim:set ts=2 sw=2: */
/*
 * Local variables:
 * mode: c++
 * End:
 */
