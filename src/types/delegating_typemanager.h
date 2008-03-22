#ifndef ZORBA_DELEGATING_TYPEMANAGER_H
#define ZORBA_DELEGATING_TYPEMANAGER_H

#include "types/typemanager.h"
#include <zorba/typeident.h>
#include "common/shared_types.h"
#include "types/schema/schema.h"

namespace zorba {

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class DelegatingTypeManager : public TypeManager {
  public:
    DelegatingTypeManager(TypeManager *parent)
      : TypeManager(parent->level() + 1),
      m_parent(parent) { }

    TypeManager *get_parent_type_manager() const { return m_parent; }

    /* Factory Methods */
    xqtref_t create_type_x_quant(const XQType& type, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_type_x_quant(type, quantifier); }

    xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const ;

    xqtref_t create_type(const TypeIdentifier& ident) const
    { return m_parent->create_type(ident); }

    xqtref_t create_type(const XQType& type, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_type(type, quantifier); }

    xqtref_t create_atomic_type(TypeConstants::atomic_type_code_t type_code, TypeConstants::quantifier_t quantifier) const
    { return m_parent->create_atomic_type(type_code, quantifier); }

    xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const ;

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

    void initSchema();
    
    Schema* getSchema(Schema* schema) const
    { return _schema; }
    
  private:
    TypeManager *m_parent;
    Schema *_schema;
};

}

#endif /* ZORBA_DELEGATING_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
