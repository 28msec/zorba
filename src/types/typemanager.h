#ifndef ZORBA_TYPEMANAGER_H
#define ZORBA_TYPEMANAGER_H

#include <ostream>
#include <boost/shared_ptr.hpp>
#include <zorba/typeident.h>
#include "util/rchandle.h"
#include "common/shared_types.h"
#include "types/typeconstants.h"


namespace zorba {

class NodeTest;

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeManager {
  public:
    TypeManager(int level) : m_level(level) { }
    virtual ~TypeManager() { }

    virtual TypeManager *get_parent_type_manager() const = 0;

    virtual int level() const { return m_level; }

    /* Factory Methods */
    virtual xqtref_t create_type_x_quant(const XQType& type, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const = 0;

    virtual xqtref_t create_type(const TypeIdentifier& ident) const = 0;

    virtual xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_type() const = 0;

    virtual xqtref_t create_item_type(TypeConstants::quantifier_t quantifier) const = 0;

    virtual xqtref_t create_any_simple_type() const = 0;

    virtual xqtref_t create_untyped_type() const = 0;

    virtual xqtref_t create_empty_type() const = 0;

    virtual xqtref_t create_none_type() const = 0;

  protected:
    int m_level;
};

}

#endif /* ZORBA_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
