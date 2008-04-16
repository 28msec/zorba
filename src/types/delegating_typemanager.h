#ifndef ZORBA_DELEGATING_TYPEMANAGER_H
#define ZORBA_DELEGATING_TYPEMANAGER_H

#include "types/typemanagerimpl.h"
#include <zorba/typeident.h>
#include "common/shared_types.h"
#ifndef ZORBA_NO_XMLSCHEMA
#include "types/schema/schema.h"
#endif

namespace zorba {

/*
 * Interface used by other parts of zorba to ask questions about types.
 */
class DelegatingTypeManager : public TypeManagerImpl {
  public:
    DelegatingTypeManager(TypeManager *parent)
        : TypeManagerImpl(parent->level() + 1, parent) 
    {
#ifndef ZORBA_NO_XMLSCHEMA
      _schema = NULL; 
#endif
    }
    
    virtual ~DelegatingTypeManager()
    {
#ifndef ZORBA_NO_XMLSCHEMA
        if ( _schema!=NULL )
            delete _schema;
#endif
    }


    virtual xqtref_t create_named_atomic_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier) const;

    virtual xqtref_t create_named_type(
        store::Item* qname,
        TypeConstants::quantifier_t quantifier = TypeConstants::QUANT_ONE) const;

#ifndef ZORBA_NO_XMLSCHEMA
    void initializeSchema();
    void terminateSchema();
	 
    Schema* getSchema() const
    { 
        return _schema; 
    }
 
  private:
    Schema *_schema;
#endif
};

}

#endif /* ZORBA_DELEGATING_TYPEMANAGER_H */
/* vim:set ts=2 sw=2: */
