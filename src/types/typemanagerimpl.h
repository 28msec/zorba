#ifndef ZORBA_TYPEMANAGERIMPL_H
#define ZORBA_TYPEMANAGERIMPL_H

#include "types/typemanager.h"


namespace zorba {

class NodeTest;

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class TypeManagerImpl : public TypeManager {
  public:
    TypeManagerImpl(int level, TypeManager *parent) : TypeManager(level), m_parent(parent) { }
    virtual ~TypeManagerImpl() { }

    TypeManager *get_parent_type_manager() const { return m_parent; }

    /* Factory Methods */
    xqtref_t create_type_x_quant(const XQType& type, TypeConstants::quantifier_t quantifier) const;

    virtual xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

    xqtref_t create_type(const TypeIdentifier& ident) const;

    xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const;

    virtual xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_node_type(rchandle<NodeTest> nodetest, xqtref_t content_type, TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_any_type() const;

    xqtref_t create_item_type(TypeConstants::quantifier_t quantifier) const;

    xqtref_t create_any_simple_type() const;

    xqtref_t create_untyped_type() const;

    xqtref_t create_empty_type() const;

    xqtref_t create_none_type() const;

    xqtref_t item_type (store::Item_t item) const;

  protected:
    TypeManager *m_parent;
};

}

#endif /* ZORBA_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
