/*
 * Copyright 2006-2008 The FLWOR Foundation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 * http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#include "delegating_typemanager.h"

#include "typeimpl.h"

namespace zorba 
{

/* Factory Methods */

xqtref_t DelegatingTypeManager::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{    
  xqtref_t namedType = m_parent->create_named_type(qname, quantifier); 

#ifndef ZORBA_NO_XMLSCHEMA
  if ( _schema!=NULL && namedType==NULL )
  {
    xqtref_t userXQType = _schema->createIfExists(this, qname, quantifier);
    if ( userXQType!=NULL )
      return userXQType;
  }
#endif

  return namedType;
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


void DelegatingTypeManager::initializeSchema()
{
  if ( _schema==NULL )
    _schema = new Schema();
}


void DelegatingTypeManager::terminateSchema()
{
  if ( _schema != NULL )
  {
    delete _schema;
    _schema = NULL;
  }
}


} // namespace zorba
