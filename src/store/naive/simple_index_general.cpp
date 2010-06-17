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

#include "store/naive/simple_index_general.h"
#include "store/naive/simple_store.h"
#include "store/naive/atomic_items.h"


namespace zorba 
{ 

namespace simplestore 
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Hash Map General Index                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
void GeneralIndexValue::addNode(store::Item_t& node, bool multikey)
{
  ulong numNodes = theNodes.size();
  theNodes.resize(numNodes + 1);
  theNodes[numNodes].theNode.transfer(node);
  theNodes[numNodes].theMultiKey = multikey;
}


/******************************************************************************

*******************************************************************************/
GeneralIndex::GeneralIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  IndexImpl(qname, spec),
  theLastNode(NULL)
{
}


/******************************************************************************

*******************************************************************************/
GeneralHashIndex::GeneralHashIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  GeneralIndex(qname, spec),
  theCompFunction(theNumColumns, spec.theTimezone, theCollators),
  theSingleMap(NULL)
{
  assert(theNumColumns == 1);

  for (ulong i = 0; i < XS_LAST; ++i)
  {
    theMaps[i] = NULL;
  }

  if (spec.theKeyTypes[0] != NULL)
  {
    theSingleMap = new IndexMap(theCompFunction, 1024, spec.theIsThreadSafe);

    theMaps[GET_STORE().theSchemaTypeCodes[spec.theKeyTypes[0].getp()]] = theSingleMap;
  }
}


/******************************************************************************

*******************************************************************************/
GeneralHashIndex::~GeneralHashIndex()
{
  for (ulong i = 0; i < XS_LAST; ++i)
  {
    if (theMaps[i] == NULL)
      continue;

    IndexMap::iterator ite = theMaps[i]->begin();
    IndexMap::iterator end = theMaps[i]->end();
 
    for (; ite != end; ++ite)
    {
      //std::cout << "Index Entry Delete [" << (*ite).first << "," 
      //          << (*ite).second << "]" << std::endl;
      
      delete (*ite).first;
      delete (*ite).second;
    }

    delete theMaps[i];
  }
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::insert(store::IndexKey*& key, store::Item_t& node)
{
  AtomicItem* keyItem = static_cast<AtomicItem*>((*key)[0].getp());
  SchemaTypeCode keyType = keyItem->getTypeCode();

  if (theSpec.theKeyTypes[0] != NULL)
  {
    return insertInMap(key, node, theSingleMap);
  }

  switch (keyType)
  {
  case XS_QNAME:
  case XS_NOTATION:
  case XS_BASE64BINARY:
  case XS_HEXBINARY:
  case XS_BOOLEAN:
  {
    return insertInMap(key, node, theMaps[keyType]);
  }

  case XS_DOUBLE:
  case XS_FLOAT:
  {
    return insertInMap(key, node, theMaps[XS_DOUBLE]);
  }

  case XS_DECIMAL:
  {
    return false;
  }

  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  {
    return false;
  }

  case XS_LONG:
  case XS_INT:
  case XS_SHORT:
  case XS_BYTE:
  {
    return insertInMap(key, node, theMaps[XS_LONG]);
  }

  case XS_UNSIGNED_LONG:
  case XS_UNSIGNED_INT:
  case XS_UNSIGNED_SHORT:
  case XS_UNSIGNED_BYTE:
  {
    return insertInMap(key, node, theMaps[XS_UNSIGNED_LONG]);
  }

  case XS_STRING:
  case XS_NORMALIZED_STRING:
  case XS_TOKEN:
  case XS_NMTOKEN:
  case XS_LANGUAGE:
  case XS_NAME:
  case XS_NCNAME:
  case XS_ID:
  case XS_IDREF:
  case XS_ENTITY:
  {
    return insertInMap(key, node, theMaps[XS_STRING]);
  }

  case XS_UNTYPED_ATOMIC:
  {
    return false;
  }

  default:
  {
    ZORBA_ASSERT(false);
    return false;
  }
  }
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::insertInMap(
    store::IndexKey*& key,
    store::Item_t& node,
    IndexMap*& targetMap)
{
  GeneralIndexValue* valueSet = NULL;

  bool multikey = (node.getp() == theLastNode);

  if (targetMap == NULL)
    targetMap = new IndexMap(theCompFunction, 1024, theSpec.theIsThreadSafe);

  if (targetMap->get(key, valueSet))
  {
    if (isUnique())
    {
      ZORBA_ERROR_PARAM(XDDY0024_INDEX_UNIQUE_VIOLATION,
                        theQname->getStringValue(), "");
    }
    
    valueSet->addNode(node, multikey);
    
    return true;
  }

  valueSet = new GeneralIndexValue();
  valueSet->addNode(node, multikey);
  
  //std::cout << "Index Entry Insert [" << key << "," 
  //          << valueSet << "]" << std::endl;
  
  const store::IndexKey* key2 = key;
  targetMap->insert(key2, valueSet);
  key = NULL; // ownership of the key obj passes to the index.

  return false;
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::remove(const store::IndexKey* key, store::Item_t& item)
{
  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralHashProbeIterator                                                   //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
void GeneralHashProbeIterator::init(const store::IndexCondition_t& cond)
{
  if (cond->getKind() != store::IndexCondition::EXACT_KEY)
  {
    ZORBA_ERROR_PARAM(STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
                      theIndex->getName()->getStringValue()->c_str(), 
                      cond->getKindString());
  }

  theTargetMap = theIndex->theSingleMap;

  theCondition = reinterpret_cast<IndexPointConditionImpl*>(cond.getp());

  store::IndexKey* key = &(theCondition->theKey);

  if (key->size() != theIndex->getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0005_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->getName()->getStringValue()->c_str(),
                      key->toString());
  }

  theTargetMap->get(key, theResultSet);

  if (theResultSet)
  {
    theIte = theResultSet->begin();
    theEnd = theResultSet->end();
  }
}


/******************************************************************************

********************************************************************************/
void GeneralHashProbeIterator::open()
{
  if (theResultSet)
    theIte = theResultSet->begin();
}


/******************************************************************************

********************************************************************************/
void GeneralHashProbeIterator::reset()
{
  if (theResultSet)
    theIte = theResultSet->begin(); 
}


/******************************************************************************

********************************************************************************/
void GeneralHashProbeIterator::close()
{
  theCondition = NULL;
  theResultSet = NULL;
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool GeneralHashProbeIterator::next(store::Item_t& result)
{
  if (theResultSet && theIte != theEnd)
  {
    result = (*theIte).theNode;
    ++theIte;
    return true;
  }

  return false;
}


}
}
