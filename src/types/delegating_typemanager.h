#ifndef ZORBA_DELEGATING_TYPEMANAGER_H
#define ZORBA_DELEGATING_TYPEMANAGER_H

#include "types/typemanagerimpl.h"
#include <zorba/typeident.h>
#include "common/shared_types.h"
#include "types/schema/schema.h"

namespace zorba {

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class DelegatingTypeManager : public TypeManagerImpl {
  public:
    DelegatingTypeManager(TypeManager *parent)
      : TypeManagerImpl(parent->level() + 1, parent) { }

    virtual xqtref_t create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const;

	virtual xqtref_t create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

	
	void initializeSchema();
    void terminateSchema();
    
    Schema* getSchema() const
    { return _schema; }
    
  private:
    Schema *_schema;
};

}

#endif /* ZORBA_DELEGATING_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
