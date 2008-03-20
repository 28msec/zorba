#include "zorba/item.h"
#include "types/typeconstants.h"
#include "types/typeimpl.h"
#include "delegating_typemanager.h"
#include "zorbatypes/representations.h"

namespace zorba 
{

/* Factory Methods */
xqtref_t DelegatingTypeManager::create_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const
{
//    xqtref_t userXQType = _schema->createIfExists(qname);
//    if ( userXQType!=NULL )
//        return this.create_type(*userXQType, quantifier);
//    else
        return m_parent->create_type(qname, quantifier); 
}

xqtref_t DelegatingTypeManager::create_atomic_type(store::Item_t qname, TypeConstants::quantifier_t quantifier) const 
{
//    xqtref_t userXQType = _schema->createIfExists(qname);
//    if ( userXQType!=NULL )
//        return this.create_type(*userXQType, quantifier);
//    else
        return m_parent->create_atomic_type(qname, quantifier); 
}

void DelegatingTypeManager::initSchema()
{ 
    Schema::initialize();
    _schema = new Schema(); 
}

} // namespace zorba
