#include "delegating_typemanager.h"

#include "typeimpl.h"

namespace zorba 
{

/* Factory Methods */
xqtref_t DelegatingTypeManager::create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const
{
    if ( _schema!=NULL )
    {
    	xqtref_t userXQType = _schema->createIfExists(this, qname, quantifier);
        if ( userXQType!=NULL )
		    return userXQType;
    }
    
    return m_parent->create_type(qname, quantifier); 
}

xqtref_t DelegatingTypeManager::create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const 
{
    if ( _schema!=NULL )
    {
    	xqtref_t userXQType = _schema->createIfExists(this, qname, quantifier);
        if ( userXQType!=NULL )
		    return userXQType;
    }
    
    return m_parent->create_atomic_type(qname, quantifier); 
}

void DelegatingTypeManager::initializeSchema()
{
    if ( _schema==NULL )
        _schema = new Schema();
}

void DelegatingTypeManager::terminateSchema()
{
    delete _schema;
    _schema = NULL;
}

} // namespace zorba
