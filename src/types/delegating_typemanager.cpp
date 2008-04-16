#include "delegating_typemanager.h"

#include "typeimpl.h"

namespace zorba 
{

/* Factory Methods */

xqtref_t DelegatingTypeManager::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{
#ifndef ZORBA_NO_XMLSCHEMA
  if ( _schema!=NULL )
  {
    xqtref_t userXQType = _schema->createIfExists(this, qname, quantifier);
    if ( userXQType!=NULL )
      return userXQType;
  }
#endif
    
  return m_parent->create_named_type(qname, quantifier); 
}


xqtref_t DelegatingTypeManager::create_named_atomic_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const 
{
#ifndef ZORBA_NO_XMLSCHEMA
  if ( _schema != NULL )
  {
    xqtref_t userXQType = _schema->createIfExists(this, qname, quantifier);
    if ( userXQType!=NULL )
      return userXQType;
  }
#endif
    
  return m_parent->create_named_atomic_type(qname, quantifier); 
}


#ifndef ZORBA_NO_XMLSCHEMA

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

#endif//ZORBA_NO_XMLSCHEMA

} // namespace zorba
