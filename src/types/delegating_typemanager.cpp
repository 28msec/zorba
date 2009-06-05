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


void DelegatingTypeManager::initializeSchema()
{
  if ( _schema == NULL )
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


xqtref_t DelegatingTypeManager::create_named_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const
{    
  xqtref_t namedType = m_parent->create_named_type(qname, quantifier); 

#ifndef ZORBA_NO_XMLSCHEMA
  if ( _schema != NULL && namedType == NULL )
  {
    namedType = _schema->createXQTypeFromTypeName(this, qname);

    if (namedType != NULL)
      namedType = create_type(*namedType, quantifier);
  }
#endif

  return namedType;
}


xqtref_t DelegatingTypeManager::create_named_atomic_type(
    store::Item* qname,
    TypeConstants::quantifier_t quantifier) const 
{
  xqtref_t namedType = m_parent->create_named_atomic_type(qname, quantifier);

#ifndef ZORBA_NO_XMLSCHEMA
  if ( _schema != NULL &&
       namedType == NULL &&
       // If the type name indicates an xml schema built-in type, and 
       // nameType == NULL, then the type cannot be an atomic one, so we 
       // should return NULL.
       ! qname->getNamespace()->byteEqual(XML_SCHEMA_NS))
  {
    namedType = _schema->createXQTypeFromTypeName(this, qname);

    if (namedType != NULL)
      namedType = create_type(*namedType, quantifier);
  }
#endif
    
  return namedType;
}


#ifndef ZORBA_NO_XMLSCHEMA

/***************************************************************************//**
  Create a sequence type of the form "element(ename, tname) quant", where
  quant is a given quantifier, ename is a given element qname, ename is a
  globaly declared element name, and tname is the name of the type associated
  with ename in the in-scope declarations.
********************************************************************************/
xqtref_t DelegatingTypeManager::create_schema_element_type(
    store::Item* elemName,
    TypeConstants::quantifier_t quant) const
{
  xqtref_t contentType = _schema->createXQTypeFromElementName(this, elemName);

  return create_node_type(store::StoreConsts::elementNode,
                          elemName,
                          contentType,
                          quant,
                          false);
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared element name.
********************************************************************************/
void DelegatingTypeManager::get_schema_element_typename(
    store::Item* elemName,
    store::Item_t& typeName)
{
  _schema->getTypeNameFromElementName(elemName, typeName);
}


/***************************************************************************//**
  Create a sequence type of the form "attribute(aname, tname) quant", where
  quant is a given quantifier, aname is a given attribute qname, aname is a
  globaly declared attribute name, and tname is the name of the type associated
  with aname in the in-scope declarations.
********************************************************************************/
xqtref_t DelegatingTypeManager::create_schema_attribute_type(
    store::Item* attrName,
    TypeConstants::quantifier_t quant) const
{
  xqtref_t contentType = _schema->createXQTypeFromElementName(this, attrName);

  return create_node_type(store::StoreConsts::attributeNode,
                          attrName,
                          contentType,
                          quant,
                          false);
}


/***************************************************************************//**
  Get the name of the type associated with a given globally declared attribute name.
********************************************************************************/
void DelegatingTypeManager::get_schema_attribute_typename(
    store::Item* attrName,
    store::Item_t& typeName)
{
  _schema->getTypeNameFromAttributeName(attrName, typeName);
}

#endif


} // namespace zorba
