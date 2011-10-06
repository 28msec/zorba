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
#include "stdafx.h"

#include "store/naive/simple_index_general.h"
#include "store/naive/simple_store.h"
#include "store/naive/atomic_items.h"
#include "store/naive/simple_item_factory.h"

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"

#include "zorbatypes/floatimpl.h"

namespace zorba 
{ 

namespace simplestore 
{

/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralIndexCompareFunction                                                //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
GeneralIndexCompareFunction::GeneralIndexCompareFunction(
    long timezone,
    const std::string& collation)
  :
  theTimezone(timezone)
{
  if (!collation.empty())
  {
    theCollator = CollationFactory::createCollator(collation);
  }
  else
  {
    theCollator = NULL;
  } 
}


/******************************************************************************

********************************************************************************/
GeneralIndexCompareFunction::~GeneralIndexCompareFunction()
{
  if (theCollator)
    delete theCollator; 
}


/******************************************************************************

********************************************************************************/
uint32_t GeneralIndexCompareFunction::hash(const store::Item_t& key) const
{
  uint32_t hval = FNV_32_INIT;

  if (key == NULL)
    return hval;

  return hashfun::h32<uint32_t>(key->hash(theTimezone, theCollator), hval);
}


/******************************************************************************

********************************************************************************/
bool GeneralIndexCompareFunction::equal(
    const store::Item_t& key1,
    const store::Item_t& key2) const
{
  if (key1 == NULL && key2 == NULL)
    return true;

  if (key1 == NULL || key2 == NULL)
    return false;

  if (! key1->equals(key2.getp(), theTimezone, theCollator))
    return false;
  
  return true;
}


/*******************************************************************************

********************************************************************************/
long GeneralIndexCompareFunction::compare(
    const store::Item_t& key1,
    const store::Item_t& key2) const
{
  long result;

  if (key1 == NULL)
  {
    if (key2 != NULL)
      return -1;
  }
  else if (key2 == NULL)
  {
    if (key1 != NULL)
      return +1;
  }
  else if (key1 == IndexConditionImpl::theNegInf)
  {
    return -1;
  }
  else if (key1 == IndexConditionImpl::thePosInf)
  {
    return +1;
  }
  else if (key2 == IndexConditionImpl::theNegInf)
  {
    return +1;
  }
  else if (key2 == IndexConditionImpl::thePosInf)
  {
    return -1;
  }
  else if ((result = key1->compare(key2, theTimezone, theCollator)))
  {
    return result;
  }

  return 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralIndexValue                                                          //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
void GeneralIndexValue::addNode(store::Item_t& node, bool untyped)
{
  csize numNodes = theNodes.size();
  theNodes.resize(numNodes + 1);
  theNodes[numNodes].theNode.transfer(node);
  theNodes[numNodes].theUntyped = untyped;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralIndex                                                               //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
GeneralIndex::GeneralIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  IndexImpl(qname, spec),
  theCompFunction(spec.theTimezone, spec.theCollations[0]),
  theUntypedFlag(false),
  theMultiKeyFlag(false)
{
}


/******************************************************************************

*******************************************************************************/
GeneralIndex::~GeneralIndex()
{
}


/******************************************************************************

*******************************************************************************/
const XQPCollator* GeneralIndex::getCollator(ulong i) const
{
  ZORBA_ASSERT(i == 0);
  return theCompFunction.getCollator();
}


/******************************************************************************
  Macro used during the population of both hash and tree general indexes.
*******************************************************************************/
#define ADD_IN_MAP(MAP_ID, untyped)                                       \
if (castItem !=  NULL)                                                    \
{                                                                         \
  found = found || insertInMap(castItem, node, theMaps[MAP_ID], untyped); \
  node = node2;                                                           \
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Hash Map General Index                                                     //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
GeneralHashIndex::GeneralHashIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  GeneralIndex(qname, spec),
  theSingleMap(NULL)
{
  assert(getNumColumns() == 1);

  memset(reinterpret_cast<void*>(theMaps), 0, XS_LAST * sizeof(IndexMap*));

  store::Item* typeName = spec.theKeyTypes[0].getp();

  if (typeName != NULL &&
      typeName != GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC] &&
      typeName != GET_STORE().theSchemaTypeNames[XS_ANY_ATOMIC])
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
      
      //delete (*ite).first;
      delete (*ite).second;
    }

    delete theMaps[i];
  }
}


/******************************************************************************

*******************************************************************************/
ulong GeneralHashIndex::size() const
{
  assert(false);
  return 0;
}


/******************************************************************************

*******************************************************************************/
store::Index::KeyIterator_t GeneralHashIndex::keys() const
{
  assert(false);
  return 0;
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::insert(store::Item_t& key, store::Item_t& node)
{
  bool found = false;
  store::Item_t castItem;
  store::Item_t node2;

  AtomicItem* keyItem = static_cast<AtomicItem*>(key.getp());

  if (keyItem == NULL)
  {
    csize numNodes = theEmptyKeyNodes.size();
    theEmptyKeyNodes.resize(numNodes + 1);
    theEmptyKeyNodes[numNodes].transfer(node);
    return true;
  }

  if (keyItem->getBaseItem() != NULL)
  {
    keyItem = static_cast<AtomicItem*>(keyItem->getBaseItem());
    key = keyItem;
  }

  SchemaTypeCode keyType = keyItem->getTypeCode();

  if (isTyped())
  {
    return insertInMap(key, node, theSingleMap, false);
  }

  switch (keyType)
  {
  case XS_QNAME:
  case XS_NOTATION:

  case XS_ANY_URI:

  case XS_BOOLEAN:

  case XS_BASE64BINARY:
  case XS_HEXBINARY:

  case XS_DATETIME:
  case XS_DATE:
  case XS_TIME:
  case XS_GYEAR_MONTH:
  case XS_GYEAR:
  case XS_GMONTH_DAY:
  case XS_GDAY:
  case XS_GMONTH:
  {
    return insertInMap(key, node, theMaps[keyType], false);
  }

  case XS_DURATION:
  case XS_YM_DURATION:
  case XS_DT_DURATION:
  {
    return insertInMap(key, node, theMaps[XS_DURATION], false);
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
    return insertInMap(key, node, theMaps[XS_STRING], false);
  }

  case XS_DOUBLE:
  case XS_FLOAT:
  {
    return insertInMap(key, node, theMaps[XS_DOUBLE], false);
  }

  case XS_DECIMAL:
  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  case XS_UNSIGNED_LONG:
  {
    // try lossless cast to xs:long
    keyItem->castToLong(castItem);
    if (castItem != NULL)
    {
      keyItem = static_cast<AtomicItem*>(castItem.getp());
      key.transfer(castItem);
      goto longmap;
    }

    // Coerce to xs:double 
    bool lossy;
    keyItem->coerceToDouble(castItem, true, lossy);

    if (lossy)
    {
      node2 = node;
      found = insertInMap(key, node2, theMaps[XS_DECIMAL], false);
    }

    key.transfer(castItem);

    found = found || insertInMap(key, node, theMaps[XS_DOUBLE], false);

    return found;
  }

  case XS_LONG:
  case XS_INT:
  case XS_SHORT:
  case XS_BYTE:
  case XS_UNSIGNED_INT:
  case XS_UNSIGNED_SHORT:
  case XS_UNSIGNED_BYTE:
  {
longmap:
    bool lossy;
    keyItem->coerceToDouble(castItem, false, lossy);

    if (lossy)
    {
      node2 = node;
      found = insertInMap(key, node2, theMaps[XS_LONG], false);

      key.transfer(castItem);

      found = found || insertInMap(key, node, theMaps[XS_DOUBLE], false);
    }
    else
    {
      found = insertInMap(key, node, theMaps[XS_LONG], false);
    }

    return found;
  }

  case XS_UNTYPED_ATOMIC:
  {
    bool found = false;

    store::ItemHandle<UntypedAtomicItem> untypedItem = 
    static_cast<UntypedAtomicItem*>(key.getp());

    node2 = node;

    // cast to xs:string
    untypedItem->castToString(castItem);
    ADD_IN_MAP(XS_STRING, false);

    // no reason to cast to xs:anyUri, because when we probe with xs:string or with
    // xs:anyUri, or with xs:untypedAtomic, we unconditionally probe both the
    // STRING and the ANY_URI tables.
 
    // try casting to xs:long
    if (untypedItem->castToLong(castItem))
    {
      store::ItemHandle<LongItem> longItem = static_cast<LongItem*>(castItem.getp());

      ADD_IN_MAP(XS_LONG, true);

      bool lossy;
      longItem->coerceToDouble(castItem, false, lossy);
      if (lossy)
      {
        ADD_IN_MAP(XS_DOUBLE, true);
      }

      // may also be gYear, hexBinary, base64Binary, or boolean
      if (untypedItem->castToGYear(castItem))
        ADD_IN_MAP(XS_GYEAR, true);

      if (untypedItem->castToHexBinary(castItem))
        ADD_IN_MAP(XS_HEXBINARY, true);

      if (untypedItem->castToBase64Binary(castItem))
        ADD_IN_MAP(XS_BASE64BINARY, true);
    }

    // try casting to xs:decimal
    else if (untypedItem->castToDecimal(castItem))
    {
      store::ItemHandle<DecimalItem> decimalItem = 
      static_cast<DecimalItem*>(castItem.getp());

      bool lossy;
      decimalItem->coerceToDouble(castItem, true, lossy);

      ADD_IN_MAP(XS_DOUBLE, true);

      if (lossy)
      {
        castItem.transfer(decimalItem);
        ADD_IN_MAP(XS_DECIMAL, true);
      }

      // may also be hexBinary or base64Binary
      if (untypedItem->castToHexBinary(castItem))
        ADD_IN_MAP(XS_HEXBINARY, true);

      if (untypedItem->castToBase64Binary(castItem))
        ADD_IN_MAP(XS_BASE64BINARY, true);
    }

    // try casting to xs:double
    else if (untypedItem->castToDouble(castItem))
    {
      ADD_IN_MAP(XS_DOUBLE, true);
    }

    // try casting to xs:datetime
    else if (untypedItem->castToDateTime(castItem))
    {
      ADD_IN_MAP(XS_DATETIME, true);
    }

    // try casting to xs:date
    else if (untypedItem->castToDate(castItem))
    {
      ADD_IN_MAP(XS_DATE, true);
    }

    // try casting to xs:time
    else if (untypedItem->castToTime(castItem))
    {
      ADD_IN_MAP(XS_TIME, true);
    }

    // try casting to xs:gYearMonth
    else if (untypedItem->castToGYearMonth(castItem))
    {
      ADD_IN_MAP(XS_GYEAR_MONTH, true);
    }

    // try casting to xs:gMonthDay
    else if (untypedItem->castToGMonthDay(castItem))
    {
      ADD_IN_MAP(XS_GMONTH_DAY, true);
    }

    // try casting to xs:gDay
    else if (untypedItem->castToGDay(castItem))
    {
      ADD_IN_MAP(XS_GDAY, true);
    }

    // try casting to xs:gMonth
    else if (untypedItem->castToGMonth(castItem))
    {
      ADD_IN_MAP(XS_GMONTH, true);
    }

    // try casting to xs:duration
    else if (untypedItem->castToDuration(castItem))
    {
      ADD_IN_MAP(XS_DURATION, true);
    }

    // try casting to xs:hexBinary
    else if (untypedItem->castToHexBinary(castItem))
    {
      ADD_IN_MAP(XS_HEXBINARY, true);
    }

    // try casting to xs:base64Binary
    else if (untypedItem->castToBase64Binary(castItem))
    {
      ADD_IN_MAP(XS_BASE64BINARY, true);
    }

    return found;
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
    store::Item_t& key,
    store::Item_t& node,
    IndexMap*& targetMap,
    bool untyped)
{
  GeneralIndexValue* valueSet = NULL;

  if (targetMap == NULL)
    targetMap = new IndexMap(theCompFunction, 1024, theSpec.theIsThreadSafe);

  if (untyped)
    theUntypedFlag = true;

  if (targetMap->get(key, valueSet))
  {
    if (isUnique())
    {
      throw ZORBA_EXCEPTION(zerr::ZDDY0024_INDEX_UNIQUE_VIOLATION,
      ERROR_PARAMS(theQname->getStringValue()));
    }
    
    valueSet->addNode(node, untyped);

    return true;
  }

  valueSet = new GeneralIndexValue();
  valueSet->addNode(node, untyped);
  
  //std::cout << "Index Entry Insert [" << key << "," 
  //          << valueSet << "]" << std::endl;
  
  targetMap->insert(key, valueSet);
  key = NULL; // ownership of the key passes to the index.

  return false;
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::remove(
    const store::Item_t& key,
    store::Item_t& item,
    bool all)
{
  assert(false);
  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralHashIndex::KeyIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
GeneralHashIndex::KeyIterator::~KeyIterator()
{
}


/******************************************************************************

*******************************************************************************/
void GeneralHashIndex::KeyIterator::open()
{
  assert(false);
}


/******************************************************************************

*******************************************************************************/
bool GeneralHashIndex::KeyIterator::next(store::IndexKey&)
{
  assert(false);
  return false;
}


/******************************************************************************

*******************************************************************************/
void GeneralHashIndex::KeyIterator::close()
{
  assert(false);
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  Tree General Index                                                         //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
const int64_t  GeneralTreeIndex::theMaxLong       =  99999999999LL;
const int64_t  GeneralTreeIndex::theMinLong       = -99999999999LL;
const double   GeneralTreeIndex::theDoubleMaxLong =  99999999999.0;
const double   GeneralTreeIndex::theDoubleMinLong = -99999999999.0;


/******************************************************************************

*******************************************************************************/
GeneralTreeIndex::GeneralTreeIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  GeneralIndex(qname, spec),
  theSingleMap(NULL)
{
  assert(getNumColumns() == 1);

  memset(reinterpret_cast<void*>(theMaps), 0, XS_LAST * sizeof(IndexMap*));

  store::Item* typeName = spec.theKeyTypes[0].getp();

  if (typeName != NULL &&
      typeName != GET_STORE().theSchemaTypeNames[XS_UNTYPED_ATOMIC] &&
      typeName != GET_STORE().theSchemaTypeNames[XS_ANY_ATOMIC])
  {
    theSingleMap = new IndexMap(theCompFunction);

    theMaps[GET_STORE().theSchemaTypeCodes[spec.theKeyTypes[0].getp()]] = theSingleMap;
  }
}


/******************************************************************************

*******************************************************************************/
GeneralTreeIndex::~GeneralTreeIndex()
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
      
      //delete (*ite).first;
      delete (*ite).second;
    }

    delete theMaps[i];
  }
}


/******************************************************************************

*******************************************************************************/
bool GeneralTreeIndex::insert(store::Item_t& key, store::Item_t& node)
{
  store::Item_t castItem;
  store::Item_t node2;
  bool lossy;
  bool found = false;

  AtomicItem* keyItem = static_cast<AtomicItem*>(key.getp());

  if (keyItem == NULL)
  {
    csize numNodes = theEmptyKeyNodes.size();
    theEmptyKeyNodes.resize(numNodes + 1);
    theEmptyKeyNodes[numNodes].transfer(node);
    return true;
  }

  if (keyItem->getBaseItem() != NULL)
  {
    keyItem = static_cast<AtomicItem*>(keyItem->getBaseItem());
    key = keyItem;
  }

  SchemaTypeCode keyType = keyItem->getTypeCode();

  if (isTyped())
  {
    return insertInMap(key, node, theSingleMap, false);
  }

  switch (keyType)
  {
  case XS_ANY_URI:
  case XS_DATETIME:
  case XS_DATE:
  case XS_TIME:
  case XS_BOOLEAN:
  {
    return insertInMap(key, node, theMaps[keyType], false);
  }

  case XS_DURATION:
  case XS_YM_DURATION:
  case XS_DT_DURATION:
  {
    return insertInMap(key, node, theMaps[XS_DURATION], false);
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
    return insertInMap(key, node, theMaps[XS_STRING], false);
  }

  case XS_DOUBLE:
  case XS_FLOAT:
  {
    return insertInMap(key, node, theMaps[XS_DOUBLE], false);
  }

  case XS_DECIMAL:
  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  case XS_UNSIGNED_LONG:
  {
    // try lossless cast to xs:long
    keyItem->castToLong(castItem);
    if (castItem != NULL)
    {
      keyItem = static_cast<AtomicItem*>(castItem.getp());
      key.transfer(castItem);
      goto longmap;
    }

    // Do a forced coersion to xs:double 
    keyItem->coerceToDouble(castItem, true, lossy);

    found = insertInMap(key, node, theMaps[XS_DOUBLE], false);

    if (lossy)
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, theMaps[XS_DECIMAL], false);
    }

    return found;
  }

  case XS_LONG:
  {
longmap:
    xs_long longValue = static_cast<LongItem*>(keyItem)->getLongValue();

    if (longValue > theMaxLong || longValue < theMinLong)
    {
      node2 = node;
      found = insertInMap(key, node2, theMaps[XS_LONG], false);

      xs_double doubleValue(longValue);
      GET_FACTORY().createDouble(castItem, doubleValue);

      found = found || insertInMap(castItem, node, theMaps[XS_DOUBLE], false);
    }
    else
    {
      found = insertInMap(key, node, theMaps[XS_LONG], false);
    }

    return found;
  }

  case XS_INT:
  case XS_SHORT:
  case XS_BYTE:
  case XS_UNSIGNED_INT:
  case XS_UNSIGNED_SHORT:
  case XS_UNSIGNED_BYTE:
  {
    return insertInMap(key, node, theMaps[XS_LONG], false);
  }

  case XS_UNTYPED_ATOMIC:
  {
    bool found = false;

    store::ItemHandle<UntypedAtomicItem> untypedItem = 
    static_cast<UntypedAtomicItem*>(key.getp());

    node2 = node;

    // cast to xs:string
    untypedItem->castToString(castItem);
    ADD_IN_MAP(XS_STRING, false);

    // try casting to xs:long
    if (untypedItem->castToLong(castItem))
    {
      store::ItemHandle<LongItem> longItem = static_cast<LongItem*>(castItem.getp());
      xs_long longValue = longItem->getLongValue();

      ADD_IN_MAP(XS_LONG, true);

      if (longValue > theMaxLong || longValue < theMinLong)
      {
        xs_double doubleValue(longValue);
        GET_FACTORY().createDouble(castItem, doubleValue);

        ADD_IN_MAP(XS_DOUBLE, true);
      }
    }

    // try casting to xs:decimal
    else if (untypedItem->castToDecimal(castItem))
    {
      store::ItemHandle<DecimalItem> decimalItem = 
      static_cast<DecimalItem*>(castItem.getp());

      decimalItem->coerceToDouble(castItem, true, lossy);

      ADD_IN_MAP(XS_DOUBLE, true);

      if (lossy)
      {
        castItem.transfer(decimalItem);
        ADD_IN_MAP(XS_DECIMAL, true);
      }
    }

    // try casting to xs:double
    else if (untypedItem->castToDouble(castItem))
    {
      ADD_IN_MAP(XS_DOUBLE, true);
    }

    // try casting to xs:datetime
    else if (untypedItem->castToDateTime(castItem))
    {
      ADD_IN_MAP(XS_DATETIME, true);
    }

    // try casting to xs:date
    else if (untypedItem->castToDate(castItem))
    {
      ADD_IN_MAP(XS_DATE, true);
    }

    // try casting to xs:time
    else if (untypedItem->castToTime(castItem))
    {
      ADD_IN_MAP(XS_TIME, true);
    }

    // try casting to xs:duration
    else if (untypedItem->castToDuration(castItem))
    {
      ADD_IN_MAP(XS_DURATION, true);
    }

    return found;
  }

  default:
  {
    RAISE_ERROR_NO_LOC(zerr::ZDTY0012_INDEX_KEY_TYPE_ERROR, 
    ERROR_PARAMS(getName()->getStringValue()));
  }
  }
}


/******************************************************************************

*******************************************************************************/
bool GeneralTreeIndex::insertInMap(
    store::Item_t& key,
    store::Item_t& node,
    IndexMap*& targetMap,
    bool untyped)
{
  GeneralIndexValue* valueSet = NULL;

  if (targetMap == NULL)
    targetMap = new IndexMap(theCompFunction);

  if (untyped)
    theUntypedFlag = true;

  IndexMap::iterator pos = targetMap->find(key);

  if (pos != targetMap->end())
  {
    if (isUnique())
    {
      RAISE_ERROR_NO_LOC(zerr::ZDDY0024_INDEX_UNIQUE_VIOLATION,
      ERROR_PARAMS(theQname->getStringValue()));
    }
    
    pos->second->addNode(node, untyped);

    return true;
  }

  valueSet = new GeneralIndexValue();
  valueSet->addNode(node, untyped);
  
  //std::cout << "Index Entry Insert [" << key << "," 
  //          << valueSet << "]" << std::endl;
  
  targetMap->insert(IndexMapPair(key, valueSet));
  key = NULL; // ownership of the key obj passes to the index.

  return false;
}


/******************************************************************************

*******************************************************************************/
bool GeneralTreeIndex::remove(
    const store::Item_t& key,
    store::Item_t& item,
    bool all)
{
  return true;
}


/******************************************************************************

*******************************************************************************/
ulong GeneralTreeIndex::size() const
{
  return 0;
}


/******************************************************************************

*******************************************************************************/
store::Index::KeyIterator_t GeneralTreeIndex::keys() const
{
  return 0;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  GeneralTreeIndex::KeyIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

*******************************************************************************/
GeneralTreeIndex::KeyIterator::~KeyIterator()
{
}


/******************************************************************************

*******************************************************************************/
void GeneralTreeIndex::KeyIterator::open()
{
}


/******************************************************************************

*******************************************************************************/
bool GeneralTreeIndex::KeyIterator::next(store::IndexKey&)
{
  return false;
}


/******************************************************************************

*******************************************************************************/
void GeneralTreeIndex::KeyIterator::close()
{
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeGeneralIndexIterator                                                  //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


ProbeGeneralIndexIterator::ProbeGeneralIndexIterator(const store::Index_t& idx)
  :
  theIndex(static_cast<GeneralIndex*>(idx.getp())),
  theIsUntypedProbe(false)
{
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralIndexIterator::init(const store::IndexCondition_t& cond)
{
  theProbeKind = cond->getKind();
  theCondition = static_cast<GeneralIndexCondition*>(cond.getp());

  //assert(theCondition->theIsSet);

  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::BOX_VALUE)
  {
    if (theIndex->theMultiKeyFlag)
    {
      RAISE_ERROR_NO_LOC(err::XPTY0004,
      ERROR_PARAMS(ZED(NoMultiKeyNodeValues_2), theIndex->getName()->getStringValue()));
    }

    if (theIndex->theUntypedFlag)
    {
      checkStringKeyType(theCondition->theKey.getp());
      checkStringKeyType(theCondition->theLowerBound.getp());
      checkStringKeyType(theCondition->theUpperBound.getp());
    }
  }
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::checkStringKeyType(const AtomicItem* key) const
{
  if (key == NULL)
    return;

  SchemaTypeCode keyType = key->getTypeCode();

  if (keyType != XS_UNTYPED_ATOMIC &&
      keyType != XS_ANY_URI &&
      keyType != XS_STRING &&
      keyType != XS_NORMALIZED_STRING &&
      keyType != XS_TOKEN &&
      keyType != XS_NMTOKEN &&
      keyType != XS_LANGUAGE &&
      keyType != XS_NAME &&
      keyType != XS_NCNAME &&
      keyType != XS_ID &&
      keyType != XS_IDREF &&
      keyType != XS_ENTITY)
  {
    RAISE_ERROR_NO_LOC(err::XPTY0004,
    ERROR_PARAMS(ZED(NoUntypedKeyNodeValue_2), theIndex->getName()->getStringValue()));
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeHashGeneralIndexIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************

********************************************************************************/
ProbeGeneralHashIndexIterator::ProbeGeneralHashIndexIterator(
    const store::Index_t& index) 
  :
  ProbeGeneralIndexIterator(index),
  theResultSets(1)
{
  theResultSets[0] = NULL;
}


#define PROBE_MAP(MAP_ID)                                               \
  {                                                                     \
  theResultSets.push_back(NULL);                                        \
  idx->theMaps[MAP_ID]->get(castItem, theResultSets[theResultSets.size() - 1]); \
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralHashIndexIterator::init(const store::IndexCondition_t& cond)
{
  ProbeGeneralIndexIterator::init(cond);

  // Note: the runtime (or compiler) makes sure that the search key is a
  // subtype of the index key type.
  AtomicItem_t& key = theCondition->theKey;

  theResultSets.resize(1);
  theResultSets[0] = NULL;

  GeneralHashIndex* idx = static_cast<GeneralHashIndex*>(theIndex.getp());

  if (idx->isTyped())
  {
    idx->theSingleMap->get(key, theResultSets[0]);
  }
  else
  {
    bool lossy;
    store::Item_t castItem;

    SchemaTypeCode keyType = key->getTypeCode();

    switch (keyType)
    {
    case XS_QNAME:
    case XS_NOTATION:

    case XS_BASE64BINARY:
    case XS_HEXBINARY:

    case XS_BOOLEAN:

    case XS_DATETIME:
    case XS_DATE:
    case XS_TIME:
    case XS_GYEAR_MONTH:
    case XS_GYEAR:
    case XS_GMONTH_DAY:
    case XS_GDAY:
    case XS_GMONTH:
    {
      if (idx->theMaps[keyType] != NULL)
      {
        idx->theMaps[keyType]->get(key, theResultSets[0]);
      }

      break;
    }

    case XS_DURATION:
    case XS_YM_DURATION:
    case XS_DT_DURATION:
    {
      if (idx->theMaps[XS_DURATION])
      {
        idx->theMaps[XS_DURATION]->get(key, theResultSets[0]);
      }

      break;
    }

    case XS_ANY_URI:
    {
      if (idx->theMaps[XS_ANY_URI])
      {
        idx->theMaps[XS_ANY_URI]->get(key, theResultSets[0]);
      }

      if (idx->theMaps[XS_STRING] != NULL)
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createString(castItem, tmp);

        PROBE_MAP(XS_STRING);
      }

      break;
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
      if (idx->theMaps[XS_STRING])
      {
        idx->theMaps[XS_STRING]->get(key, theResultSets[0]);
      }

      if (idx->theMaps[XS_ANY_URI])
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createAnyURI(castItem, tmp);

        PROBE_MAP(XS_ANY_URI);
      }

      break;
    }

    case XS_DOUBLE:
    case XS_FLOAT:
    {
      if (idx->theMaps[XS_DOUBLE])
      {
        idx->theMaps[XS_DOUBLE]->get(key, theResultSets[0]);
      }

      if (idx->theMaps[XS_LONG] && key->castToLong(castItem))
      {
        PROBE_MAP(XS_LONG);
      }

      break;
    }

    case XS_DECIMAL:
    case XS_INTEGER:
    case XS_NON_POSITIVE_INTEGER:
    case XS_NEGATIVE_INTEGER:
    case XS_NON_NEGATIVE_INTEGER:
    case XS_POSITIVE_INTEGER:
    case XS_UNSIGNED_LONG:
    {
      key->coerceToDouble(castItem, true, lossy);

      if (lossy && idx->theMaps[XS_DECIMAL])
      {
        idx->theMaps[XS_DECIMAL]->get(key, theResultSets[0]);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        PROBE_MAP(XS_DOUBLE);
      }

      if (idx->theMaps[XS_LONG] && key->castToLong(castItem))
      {
        PROBE_MAP(XS_LONG);
      }

      break;
    }

    case XS_LONG:
    case XS_INT:
    case XS_SHORT:
    case XS_BYTE:
    case XS_UNSIGNED_INT:
    case XS_UNSIGNED_SHORT:
    case XS_UNSIGNED_BYTE:
    {
      if (idx->theMaps[XS_LONG])
      {
        idx->theMaps[XS_LONG]->get(key, theResultSets[0]);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        key->coerceToDouble(castItem, true, lossy);
        PROBE_MAP(XS_DOUBLE);
      }

      break;
    }

    case XS_UNTYPED_ATOMIC:
    {
      theIsUntypedProbe = true;

      store::ItemHandle<UntypedAtomicItem> untypedItem = 
      static_cast<UntypedAtomicItem*>(key.getp());

      // cast to xs:string
      if (idx->theMaps[XS_STRING])
      {
        untypedItem->castToString(castItem); 
        PROBE_MAP(XS_STRING);
      }

      // cast to xs:anyURI
      if (idx->theMaps[XS_ANY_URI] && untypedItem->castToUri(castItem))
      {
        PROBE_MAP(XS_ANY_URI);
      }

      if (theProbeKind == store::IndexCondition::POINT_VALUE)
        return;

      // try casting to xs:long
      if ((idx->theMaps[XS_LONG] || idx->theMaps[XS_DOUBLE]) &&
          (untypedItem->castToLong(castItem), castItem != NULL))
      {
        store::ItemHandle<LongItem> longItem = 
        static_cast<LongItem*>(castItem.getp());

        if (idx->theMaps[XS_LONG])
          PROBE_MAP(XS_LONG);

        if (idx->theMaps[XS_DOUBLE])
        {
          longItem->coerceToDouble(castItem, true, lossy);
          PROBE_MAP(XS_DOUBLE);
        }

        // may also be gYear, hexBinary, or boolean
        if (idx->theMaps[XS_GYEAR])
        {
          untypedItem->castToGYear(castItem);
          PROBE_MAP(XS_GYEAR);
        }

        if (idx->theMaps[XS_HEXBINARY])
        {
          untypedItem->castToHexBinary(castItem); 
          PROBE_MAP(XS_HEXBINARY);
        }
      }

      // try casting to xs:decimal
      else if ((idx->theMaps[XS_DECIMAL] ||
                idx->theMaps[XS_LONG] ||
                idx->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDecimal(castItem))
      {
        store::ItemHandle<DecimalItem> decimalItem = 
        static_cast<DecimalItem*>(castItem.getp());

        decimalItem->coerceToDouble(castItem, true, lossy);

        if (idx->theMaps[XS_DOUBLE])
        {
          PROBE_MAP(XS_DOUBLE);
        }

        if (idx->theMaps[XS_LONG] && decimalItem->castToLong(castItem))
        {
          PROBE_MAP(XS_LONG);
        }

        if (lossy && idx->theMaps[XS_DECIMAL])
        {
          castItem.transfer(decimalItem);
          PROBE_MAP(XS_DOUBLE);
        }

        // may also be hexBinary
        if (idx->theMaps[XS_HEXBINARY])
        {
          untypedItem->castToHexBinary(castItem); 
          PROBE_MAP(XS_HEXBINARY);
        }
      }

      // try casting to xs:double
      else if ((idx->theMaps[XS_LONG] || idx->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDouble(castItem))
      {
        store::ItemHandle<DoubleItem> doubleItem = 
        static_cast<DoubleItem*>(castItem.getp());

        if (idx->theMaps[XS_DOUBLE])
          PROBE_MAP(XS_DOUBLE);

        if (idx->theMaps[XS_LONG] && doubleItem->castToLong(castItem))
        {
          PROBE_MAP(XS_LONG);
        }
      }

      // try casting to xs:datetime
      else if (idx->theMaps[XS_DATETIME] &&
               untypedItem->castToDateTime(castItem))
      {
        PROBE_MAP(XS_DATETIME);
      }

      // try casting to xs:date
      else if (idx->theMaps[XS_DATE] &&
               untypedItem->castToDate(castItem))
      {
        PROBE_MAP(XS_DATE);
      }

      // try casting to xs:time
      else if (idx->theMaps[XS_TIME] &&
               untypedItem->castToTime(castItem))
      {
        PROBE_MAP(XS_TIME);
      }

      // try casting to xs:gYearMonth
      else if (idx->theMaps[XS_GYEAR_MONTH] &&
               untypedItem->castToGYearMonth(castItem))
      {
        PROBE_MAP(XS_GYEAR_MONTH);
      }

      // try casting to xs:gMonthDay
      else if (idx->theMaps[XS_GMONTH_DAY] &&
               untypedItem->castToGMonthDay(castItem))
      {
        PROBE_MAP(XS_GMONTH_DAY);
      }

      // try casting to xs:gDay
      else if (idx->theMaps[XS_GDAY] &&
               untypedItem->castToGDay(castItem))
      {
        PROBE_MAP(XS_GDAY);
      }

      // try casting to xs:gMonth
      else if (idx->theMaps[XS_GMONTH] &&
               untypedItem->castToGMonth(castItem))
      {
        PROBE_MAP(XS_GMONTH);
      }
      
      // try casting to xs:duration
      else if (idx->theMaps[XS_DURATION] &&
               untypedItem->castToDuration(castItem))
      {
        PROBE_MAP(XS_DURATION);
      }
      
      // try casting to xs:hexBinary
      else if (idx->theMaps[XS_HEXBINARY] &&
               untypedItem->castToHexBinary(castItem))
      {
        PROBE_MAP(XS_HEXBINARY);
      }
      
      // try casting to xs:base64Binary
      else if (idx->theMaps[XS_BASE64BINARY] &&
               untypedItem->castToBase64Binary(castItem))
      {
        PROBE_MAP(XS_BASE64BINARY);
      }
      
      break;
    }

    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralHashIndexIterator::open()
{
  theResultSetsEnd = theResultSets.end();
  theResultSetsIte = theResultSets.begin();

  for (; theResultSetsIte != theResultSetsEnd; ++theResultSetsIte)
  {
    if (*theResultSetsIte != NULL)
    {
      theIte = (*theResultSetsIte)->begin();
      theEnd = (*theResultSetsIte)->end();

      break;
    }
  }
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralHashIndexIterator::reset()
{
  open();
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralHashIndexIterator::close()
{
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeGeneralHashIndexIterator::next(store::Item_t& result)
{
  while (theResultSetsIte != theResultSetsEnd)
  {
    while (theIte != theEnd)
    {
      if (theIsUntypedProbe && (*theIte).theUntyped)
      {
        ++theIte;
        continue;
      }

      result = (*theIte).theNode;
      ++theIte;
      return true;
    }

    ++theResultSetsIte;

    if (theResultSetsIte != theResultSetsEnd && *theResultSetsIte != NULL)
    {
      theIte = (*theResultSetsIte)->begin();
      theEnd = (*theResultSetsIte)->end();
    }
  }

  return false;
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeGeneralTreeIndexIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


#define PROBE_TREE_MAP(MAP_ID)                                     \
{                                                                  \
  ite = idx->theMaps[MAP_ID]->find(key);                           \
  if (ite != idx->theMaps[MAP_ID]->end())                          \
    theResultSets[0] = ite->second;                                \
}


#define PROBE_ALT_TREE_MAP(MAP_ID)                                 \
{                                                                  \
  theResultSets.push_back(NULL);                                   \
  ite = idx->theMaps[MAP_ID]->find(castItem);                      \
  if (ite != idx->theMaps[MAP_ID]->end())                          \
    theResultSets[theResultSets.size() - 1] = ite->second;         \
}


/******************************************************************************

********************************************************************************/
ProbeGeneralTreeIndexIterator::ProbeGeneralTreeIndexIterator(
    const store::Index_t& index) 
  :
  ProbeGeneralIndexIterator(index),
  theIsFullProbe(false),
  theResultSets(1)
{
  theResultSets[0] = NULL;
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::init(const store::IndexCondition_t& cond)
{
  ProbeGeneralIndexIterator::init(cond);

  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::POINT_GENERAL)
  {
    initPoint();
  }
  else if (theProbeKind == store::IndexCondition::BOX_VALUE)
  {
    initValueBox();
  }
  else
  {
    initGeneralBox();
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::initPoint()
{
  // Note: the runtime (or compiler) makes sure that the search tuple consists
  // of exactly one search item, which is not NULL and whose type is a subtype
  // of the index key type. Furthermore, in the case of a point-value probe,
  // the type of the search item cannot be untyped, because untyped search keys
  // either don't match the index key type, or are cast to xs:string. 

  GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(theIndex.getp());

  AtomicItem_t& key = theCondition->theKey;

  theResultSets.resize(1);
  theResultSets[0] = NULL;

  EntryIterator ite;

  if (idx->isTyped())
  {
    ite = idx->theSingleMap->find(key);

    if (ite != idx->theSingleMap->end())
      theResultSets[0] = ite->second;
  }
  else
  {
    bool lossy;
    store::Item_t castItem;
    store::IndexKey altKey(1);

    SchemaTypeCode keyType = key->getTypeCode();

    switch (keyType)
    {
    case XS_BOOLEAN:

    case XS_DATETIME:
    case XS_DATE:
    case XS_TIME:
    {
      if (idx->theMaps[keyType] != NULL)
        PROBE_TREE_MAP(keyType);

      break;
    }

    case XS_DURATION:
    case XS_YM_DURATION:
    case XS_DT_DURATION:
    {
      if (idx->theMaps[XS_DURATION])
        PROBE_TREE_MAP(XS_DURATION);

      break;
    }

    case XS_ANY_URI:
    {
      if (idx->theMaps[XS_ANY_URI])
        PROBE_TREE_MAP(XS_ANY_URI);

      if (idx->theMaps[XS_STRING] != NULL)
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createString(castItem, tmp);

        PROBE_ALT_TREE_MAP(XS_STRING);
      }

      break;
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
      if (idx->theMaps[XS_STRING])
        PROBE_TREE_MAP(XS_STRING);

      if (idx->theMaps[XS_ANY_URI])
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createAnyURI(castItem, tmp);

        PROBE_ALT_TREE_MAP(XS_ANY_URI);
      }

      break;
    }

    case XS_DOUBLE:
    case XS_FLOAT:
    {
      if (idx->theMaps[XS_DOUBLE])
        PROBE_TREE_MAP(XS_DOUBLE);

      if (idx->theMaps[XS_LONG] && key->castToLong(castItem))
        PROBE_ALT_TREE_MAP(XS_LONG);

      break;
    }

    case XS_DECIMAL:
    case XS_INTEGER:
    case XS_NON_POSITIVE_INTEGER:
    case XS_NEGATIVE_INTEGER:
    case XS_NON_NEGATIVE_INTEGER:
    case XS_POSITIVE_INTEGER:
    case XS_UNSIGNED_LONG:
    {
      key->coerceToDouble(castItem, true, lossy);

      if (lossy && idx->theMaps[XS_DECIMAL])
        PROBE_TREE_MAP(XS_DECIMAL);

      if (idx->theMaps[XS_DOUBLE])
        PROBE_ALT_TREE_MAP(XS_DOUBLE);

      if (idx->theMaps[XS_LONG] && key->castToLong(castItem))
        PROBE_ALT_TREE_MAP(XS_LONG);

      break;
    }

    case XS_LONG:
    case XS_INT:
    case XS_SHORT:
    case XS_BYTE:
    case XS_UNSIGNED_INT:
    case XS_UNSIGNED_SHORT:
    case XS_UNSIGNED_BYTE:
    {
      if (idx->theMaps[XS_LONG])
        PROBE_TREE_MAP(XS_LONG);

      if (idx->theMaps[XS_DOUBLE])
      {
        key->coerceToDouble(castItem, true, lossy);
        PROBE_ALT_TREE_MAP(XS_DOUBLE);
      }

      break;
    }

    case XS_UNTYPED_ATOMIC:
    {
      ZORBA_ASSERT(theProbeKind == store::IndexCondition::POINT_GENERAL);

      theIsUntypedProbe = true;

      store::ItemHandle<UntypedAtomicItem> untypedItem = 
      static_cast<UntypedAtomicItem*>(key.getp());

      // cast to xs:string
      if (idx->theMaps[XS_STRING])
      {
        untypedItem->castToString(castItem); 
        PROBE_ALT_TREE_MAP(XS_STRING);
      }

      // cast to xs:anyURI
      if (idx->theMaps[XS_ANY_URI] && untypedItem->castToUri(castItem))
        PROBE_ALT_TREE_MAP(XS_ANY_URI);

      if (theProbeKind == store::IndexCondition::POINT_VALUE)
        return;

      // try casting to xs:long
      if ((idx->theMaps[XS_LONG] ||
           idx->theMaps[XS_DOUBLE]) &&
          (untypedItem->castToLong(castItem), castItem != NULL))
      {
        store::ItemHandle<LongItem> longItem = 
        static_cast<LongItem*>(castItem.getp());

        if (idx->theMaps[XS_LONG])
          PROBE_ALT_TREE_MAP(XS_LONG);

        if (idx->theMaps[XS_DOUBLE])
        {
          longItem->coerceToDouble(castItem, true, lossy);
          PROBE_ALT_TREE_MAP(XS_DOUBLE);
        }
      }

      // try casting to xs:decimal
      else if ((idx->theMaps[XS_DECIMAL] ||
                idx->theMaps[XS_LONG] ||
                idx->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDecimal(castItem))
      {
        store::ItemHandle<DecimalItem> decimalItem = 
        static_cast<DecimalItem*>(castItem.getp());

        decimalItem->coerceToDouble(castItem, true, lossy);

        if (idx->theMaps[XS_DOUBLE])
          PROBE_ALT_TREE_MAP(XS_DOUBLE);

        if (idx->theMaps[XS_LONG] && decimalItem->castToLong(castItem))
          PROBE_ALT_TREE_MAP(XS_LONG);

        if (lossy && idx->theMaps[XS_DECIMAL])
        {
          castItem.transfer(decimalItem);
          PROBE_ALT_TREE_MAP(XS_DOUBLE);
        }
      }

      // try casting to xs:double
      else if ((idx->theMaps[XS_LONG] || idx->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDouble(castItem))
      {
        store::ItemHandle<DoubleItem> doubleItem = 
        static_cast<DoubleItem*>(castItem.getp());

        if (idx->theMaps[XS_DOUBLE])
          PROBE_ALT_TREE_MAP(XS_DOUBLE);

        if (idx->theMaps[XS_LONG] && doubleItem->castToLong(castItem))
          PROBE_ALT_TREE_MAP(XS_LONG);
      }

      // try casting to xs:datetime
      else if (idx->theMaps[XS_DATETIME] && untypedItem->castToDateTime(castItem))
      {
        PROBE_ALT_TREE_MAP(XS_DATETIME);
      }

      // try casting to xs:date
      else if (idx->theMaps[XS_DATE] && untypedItem->castToDate(castItem))
      {
        PROBE_ALT_TREE_MAP(XS_DATE);
      }

      // try casting to xs:time
      else if (idx->theMaps[XS_TIME] && untypedItem->castToTime(castItem))
      {
        PROBE_ALT_TREE_MAP(XS_TIME);
      }

      // try casting to xs:duration
      else if (idx->theMaps[XS_DURATION] && untypedItem->castToDuration(castItem))
      {
        PROBE_ALT_TREE_MAP(XS_DURATION);
      }

      break;
    }

    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::initValueBox()
{
  GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(theIndex.getp());

  bool haveLower = theCondition->theRangeFlags.theHaveLowerBound;
  bool haveUpper = theCondition->theRangeFlags.theHaveUpperBound;

  AtomicItem_t& lowerKey = theCondition->theLowerBound;
  AtomicItem_t& upperKey = theCondition->theUpperBound;
  store::Item_t lowerAltKey;
  store::Item_t upperAltKey;

  zstring tmp;

  theMapBegins.clear();
  theMapEnds.clear();

  if (idx->isTyped())
  {
    // Note: the runtime (or compiler) makes sure that each search key is a
    // subtype of the index key type.
    probeMap(idx->theSingleMap, lowerKey, upperKey);
  }
  else if (haveLower || haveUpper)
  {
    store::Item_t castItem;

    SchemaTypeCode lowerKeyType = (haveLower ? lowerKey->getTypeCode() : XS_LAST);
    SchemaTypeCode upperKeyType = (haveUpper ? upperKey->getTypeCode() : XS_LAST);

    SchemaTypeCode keyType = (lowerKeyType < upperKeyType ?
                              lowerKeyType :
                              upperKeyType);

    switch (keyType)
    {
    case XS_BOOLEAN:
    case XS_DATETIME:
    case XS_DATE:
    case XS_TIME:
    {
      probeMap(idx->theMaps[keyType], lowerKey, upperKey);
      break;
    }

    case XS_DURATION:
    case XS_YM_DURATION:
    case XS_DT_DURATION:
    {
      probeMap(idx->theMaps[XS_DURATION], lowerKey, upperKey);
      break;
    }

    case XS_ANY_URI:
    {
      probeMap(idx->theMaps[XS_ANY_URI], lowerKey, upperKey);

      if (idx->theMaps[XS_STRING])
      {
        if (haveLower)
        {
          lowerKey->getStringValue2(tmp);
          GET_FACTORY().createString(lowerAltKey, tmp);
        }

        if (haveUpper)
        {
          upperKey->getStringValue2(tmp);
          GET_FACTORY().createString(upperAltKey, tmp);
        }
        
        probeMap(idx->theMaps[XS_STRING], lowerAltKey, upperAltKey);
      }

      break;
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
      probeMap(idx->theMaps[XS_STRING], lowerKey, upperKey);

      if (idx->theMaps[XS_ANY_URI])
      {
        if (haveLower)
        {
          lowerKey->getStringValue2(tmp);
          GET_FACTORY().createAnyURI(lowerAltKey, tmp);
        }

        if (haveUpper)
        {
          upperKey->getStringValue2(tmp);
          GET_FACTORY().createAnyURI(upperAltKey, tmp);
        }

        probeMap(idx->theMaps[XS_ANY_URI], lowerAltKey, upperAltKey);
      }

      break;
    }

    case XS_DOUBLE:
    case XS_FLOAT:
    {
      probeMap(idx->theMaps[XS_DOUBLE], lowerKey, upperKey);

      if (idx->theMaps[XS_LONG])
      {
        if (haveLower)
          doubleToLongProbe(lowerAltKey, lowerKey, true, false);

        if (haveUpper)
          doubleToLongProbe(upperAltKey, upperKey, false, true);

        if (haveLower && haveUpper)
        {
          if (lowerAltKey && upperAltKey)
            probeMap(idx->theMaps[XS_ANY_URI], lowerAltKey, upperAltKey);    
        }
        else if ((haveLower && lowerAltKey) || (haveUpper && upperAltKey))
        {
          probeMap(idx->theMaps[XS_ANY_URI], lowerAltKey, upperAltKey);
        }
      }

      break;
    }

    case XS_DECIMAL:
    case XS_INTEGER:
    case XS_NON_POSITIVE_INTEGER:
    case XS_NEGATIVE_INTEGER:
    case XS_NON_NEGATIVE_INTEGER:
    case XS_POSITIVE_INTEGER:
    case XS_UNSIGNED_LONG:
    {
      probeMap(idx->theMaps[XS_DECIMAL], lowerKey, upperKey);

      if (idx->theMaps[XS_LONG])
      {
        probeMap(idx->theMaps[XS_LONG], lowerKey, upperKey);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        if (haveLower)
        {
          xs_double doubleValue = lowerKey->getDecimalValue();
          GET_FACTORY().createDouble(lowerAltKey, doubleValue);
        }

        if (haveUpper)
        {
          xs_double doubleValue = upperKey->getDecimalValue();
          GET_FACTORY().createDouble(upperAltKey, doubleValue);
        }

        probeMap(idx->theMaps[XS_DOUBLE], lowerAltKey, upperAltKey);
      }

      break;
    }

    case XS_LONG:
    case XS_INT:
    case XS_SHORT:
    case XS_BYTE:
    case XS_UNSIGNED_INT:
    case XS_UNSIGNED_SHORT:
    case XS_UNSIGNED_BYTE:
    {
      probeMap(idx->theMaps[XS_LONG], lowerKey, upperKey);

      if (idx->theMaps[XS_DECIMAL])
      {
        if (haveLower)
        {
          xs_decimal decimalValue = lowerKey->getLongValue();
          GET_FACTORY().createDecimal(lowerAltKey, decimalValue);
        }

        if (haveUpper)
        {
          xs_decimal decimalValue = upperKey->getLongValue();
          GET_FACTORY().createDecimal(upperAltKey, decimalValue);
        }

        probeMap(idx->theMaps[XS_DECIMAL], lowerAltKey, upperAltKey);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        if (haveLower)
        {
          xs_double doubleValue = lowerKey->getLongValue();
          GET_FACTORY().createDouble(lowerAltKey, doubleValue);
        }

        if (haveUpper)
        {
          xs_double doubleValue = upperKey->getLongValue();
          GET_FACTORY().createDouble(upperAltKey, doubleValue);
        }

        probeMap(idx->theMaps[XS_DOUBLE], lowerAltKey, upperAltKey);
      }

      break;
    }

    default:
      ZORBA_ASSERT(false);
    }
  }
  else
  {
    theIsFullProbe = true;

    for (ulong i = 0; i < XS_LAST; ++i)
    {
      if (idx->theMaps[i] == NULL)
        continue;

      theMapBegins.push_back(idx->theMaps[i]->begin());
      theMapEnds.push_back(idx->theMaps[i]->end());
    }
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::initGeneralBox()
{
  GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(theIndex.getp());

  bool haveLower = theCondition->theRangeFlags.theHaveLowerBound;
  bool haveUpper = theCondition->theRangeFlags.theHaveUpperBound;

  assert(!(haveLower && haveUpper));

  AtomicItem_t& key = (haveLower ?
                       theCondition->theLowerBound :
                       theCondition->theUpperBound);
  store::Item_t altKey;

  zstring tmp;

  theMapBegins.clear();
  theMapEnds.clear();

  if (idx->isTyped())
  {
    // Note: the runtime (or compiler) makes sure that the search key is a
    // subtype of the index key type.
    probeMap(idx->theSingleMap, key, key);
  }
  else if (haveLower || haveUpper)
  {
    SchemaTypeCode keyType = key->getTypeCode();

    switch (keyType)
    {
    case XS_BOOLEAN:
    case XS_DATETIME:
    case XS_DATE:
    case XS_TIME:
    {
      probeMap(idx->theMaps[keyType], key, key);
      break;
    }

    case XS_DURATION:
    case XS_YM_DURATION:
    case XS_DT_DURATION:
    {
      probeMap(idx->theMaps[XS_DURATION], key, key);
      break;
    }

    case XS_ANY_URI:
    {
      probeMap(idx->theMaps[XS_ANY_URI], key, key);

      if (idx->theMaps[XS_STRING])
      {
        key->getStringValue2(tmp);
        GET_FACTORY().createString(altKey, tmp);

        probeMap(idx->theMaps[XS_STRING], altKey, altKey);
      }

      break;
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
      probeMap(idx->theMaps[XS_STRING], key, key);

      if (idx->theMaps[XS_ANY_URI])
      {
        key->getStringValue2(tmp);
        GET_FACTORY().createAnyURI(altKey, tmp);

        probeMap(idx->theMaps[XS_ANY_URI], altKey, altKey);
      }

      break;
    }

    case XS_DOUBLE:
    case XS_FLOAT:
    {
      probeMap(idx->theMaps[XS_DOUBLE], key, key);

      if (idx->theMaps[XS_LONG])
      {
        doubleToLongProbe(altKey, key, haveLower, haveUpper);

        if (altKey)
          probeMap(idx->theMaps[XS_LONG], altKey, altKey);
      }

      break;
    }

    case XS_DECIMAL:
    case XS_INTEGER:
    case XS_NON_POSITIVE_INTEGER:
    case XS_NEGATIVE_INTEGER:
    case XS_NON_NEGATIVE_INTEGER:
    case XS_POSITIVE_INTEGER:
    case XS_UNSIGNED_LONG:
    {
      probeMap(idx->theMaps[XS_DECIMAL], key, key);

      if (idx->theMaps[XS_LONG])
      {
        probeMap(idx->theMaps[XS_LONG], key, key);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        xs_double doubleValue = key->getDecimalValue();
        GET_FACTORY().createDouble(altKey, doubleValue);

        probeMap(idx->theMaps[XS_DOUBLE], altKey, altKey);
      }

      break;
    }

    case XS_LONG:
    case XS_INT:
    case XS_SHORT:
    case XS_BYTE:
    case XS_UNSIGNED_INT:
    case XS_UNSIGNED_SHORT:
    case XS_UNSIGNED_BYTE:
    {
      probeMap(idx->theMaps[XS_LONG], key, key);

      if (idx->theMaps[XS_DECIMAL])
      {
        xs_decimal decimalValue = key->getLongValue();
        GET_FACTORY().createDecimal(altKey, decimalValue);

        probeMap(idx->theMaps[XS_DECIMAL], altKey, altKey);
      }

      if (idx->theMaps[XS_DOUBLE])
      {
        xs_double doubleValue = key->getLongValue();
        GET_FACTORY().createDouble(altKey, doubleValue);

        probeMap(idx->theMaps[XS_DOUBLE], altKey, altKey);
      }

      break;
    }

    case XS_UNTYPED_ATOMIC:
    {
      theIsUntypedProbe = true;

      store::ItemHandle<UntypedAtomicItem> untypedItem = 
      static_cast<UntypedAtomicItem*>(key.getp());

      // cast to xs:string
      if (idx->theMaps[XS_STRING])
      {
        untypedItem->castToString(altKey);
        probeMap(idx->theMaps[XS_STRING], altKey, altKey);
      }

      // cast to xs:anyURI
      if (idx->theMaps[XS_ANY_URI] && untypedItem->castToUri(altKey))
      {
        probeMap(idx->theMaps[XS_ANY_URI], altKey, altKey);
      }

      // try casting to xs:long
      if ((idx->theMaps[XS_LONG] ||
           idx->theMaps[XS_DOUBLE] ||
           idx->theMaps[XS_DECIMAL]) &&
          untypedItem->castToLong(altKey), altKey != NULL)
      {
        store::ItemHandle<LongItem> longItem = 
        static_cast<LongItem*>(altKey.getp());

        if (idx->theMaps[XS_LONG])
        {
          probeMap(idx->theMaps[XS_LONG], altKey, altKey);
        }

        if (idx->theMaps[XS_DOUBLE])
        {
          xs_double doubleValue = longItem->getLongValue();
          GET_FACTORY().createDouble(altKey, doubleValue);
          probeMap(idx->theMaps[XS_DOUBLE], altKey, altKey);
        }

        if (idx->theMaps[XS_DECIMAL])
        {
          xs_decimal decimalValue = longItem->getLongValue();
          GET_FACTORY().createDecimal(altKey, decimalValue);
          probeMap(idx->theMaps[XS_DECIMAL], altKey, altKey);
        }
      }

      // try casting to xs:decimal
      else if ((idx->theMaps[XS_LONG] ||
                idx->theMaps[XS_DOUBLE] ||
                idx->theMaps[XS_DECIMAL]) &&
               untypedItem->castToDecimal(altKey), altKey != NULL)
      {
        store::ItemHandle<DecimalItem> decimalItem = 
        static_cast<DecimalItem*>(altKey.getp());

        if (idx->theMaps[XS_DECIMAL])
        {
          probeMap(idx->theMaps[XS_DECIMAL], altKey, altKey);
        }

        if (idx->theMaps[XS_LONG])
        {
          probeMap(idx->theMaps[XS_LONG], altKey, altKey);
        }

        if (idx->theMaps[XS_DOUBLE])
        {
          xs_double doubleValue = decimalItem->getDecimalValue();
          GET_FACTORY().createDouble(altKey, doubleValue);
          probeMap(idx->theMaps[XS_DOUBLE], altKey, altKey);
        }
      }

      // try casting to xs:double
      else if ((idx->theMaps[XS_LONG] ||
               idx->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDouble(altKey), altKey != NULL)
      {
        store::ItemHandle<DoubleItem> doubleItem = 
        static_cast<DoubleItem*>(altKey.getp());

        if (idx->theMaps[XS_DOUBLE])
        {
          probeMap(idx->theMaps[XS_DOUBLE], altKey, altKey);
        }

        if (idx->theMaps[XS_LONG])
        {
          doubleToLongProbe(altKey, doubleItem.getp(), haveLower, haveUpper);

          if (altKey)
          {
            probeMap(idx->theMaps[XS_LONG], altKey, altKey);
          }
        }
      }

      // try casting to xs:datetime
      else if (idx->theMaps[XS_DATETIME] && untypedItem->castToDateTime(altKey))
      {
        probeMap(idx->theMaps[XS_DATETIME], altKey, altKey);
      }

      // try casting to xs:date
      else if (idx->theMaps[XS_DATE] && untypedItem->castToDate(altKey))
      {
        probeMap(idx->theMaps[XS_DATE], altKey, altKey);
      }

      // try casting to xs:time
      else if (idx->theMaps[XS_TIME] && untypedItem->castToTime(altKey))
      {
        probeMap(idx->theMaps[XS_TIME], altKey, altKey);
      }

      // try casting to xs:duration
      else if (idx->theMaps[XS_DURATION] && untypedItem->castToDuration(altKey))
      {
        probeMap(idx->theMaps[XS_DURATION], altKey, altKey);
      }

      break;
    }

    default:
    {
      ZORBA_ASSERT(false);
    }
    }
  }
  else
  {
    for (csize i = 0; i < XS_LAST; ++i)
    {
      if (idx->theMaps[i] == NULL)
        continue;

      theMapBegins.push_back(idx->theMaps[i]->begin());
      theMapEnds.push_back(idx->theMaps[i]->end());
    }
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::probeMap(
    GeneralTreeIndex::IndexMap* map,
    const AtomicItem_t& lowerKey,
    const AtomicItem_t& upperKey)
{
  if (map == NULL)
    return;

  GeneralIndexCondition::RangeFlags& flags = theCondition->theRangeFlags;

  bool haveLower = flags.theHaveLowerBound;
  bool haveUpper = flags.theHaveUpperBound;
  bool lowerIncl = flags.theLowerBoundIncl;
  bool upperIncl = flags.theUpperBoundIncl;

  assert(theProbeKind != store::IndexCondition::BOX_GENERAL ||
         !(haveLower && haveUpper));

  if (haveLower && haveUpper)
  {
    long cmp = lowerKey->compare(upperKey);

    if (cmp > 0)
      return;

    if (cmp == 0 && (!lowerIncl || !upperIncl))
      return;
  }

  if (haveLower)
  {
    if (lowerIncl)
      theMapBegins.push_back(map->lower_bound(lowerKey));
    else
      theMapBegins.push_back(map->upper_bound(lowerKey));    
  }
  else
  {
    theMapBegins.push_back(map->begin());
  }
 
  if (haveUpper)
  {
    if (upperIncl)
      theMapEnds.push_back(map->upper_bound(upperKey));
    else
      theMapEnds.push_back(map->lower_bound(upperKey));
  }
  else
  {
    theMapEnds.push_back(map->end());
  }
}


/*******************************************************************************

********************************************************************************/
void ProbeGeneralTreeIndexIterator::doubleToLongProbe(
    store::Item_t& result,
    const AtomicItem* doubleItem,
    bool haveLower,
    bool haveUpper) const
{
  assert(!(haveLower && haveUpper));

  xs_double doubleObj = doubleItem->getDoubleValue();

  if (doubleObj.isNaN())
    throw ZORBA_EXCEPTION(zerr::ZSTR0041_NAN_COMPARISON);

  double doubleValue = doubleObj.getNumber();

  int64_t longValue;

  result = NULL;

  if (doubleObj.isPosInf() || doubleValue > GeneralTreeIndex::theDoubleMaxLong)
  {
    if (haveLower)
    {
      return;
    }
    else
    {
      longValue = GeneralTreeIndex::theMaxLong;
      theCondition->theRangeFlags.theUpperBoundIncl = true;
    }
  }
  else if (doubleObj.isNegInf() || doubleValue < GeneralTreeIndex::theDoubleMinLong)
  {
    if (haveLower)
    {
      longValue = GeneralTreeIndex::theMinLong;
      theCondition->theRangeFlags.theLowerBoundIncl = true;
    }
    else
    {
      return;
    }
  }
  else
  {
    double doubleFloor = ::floor(doubleValue);
    longValue = static_cast<uint64_t>(doubleFloor);
    
    bool lossy = (doubleFloor != doubleValue);

    assert(doubleFloor + 1.0 > doubleValue);

    if (haveLower && lossy)
    {
      theCondition->theRangeFlags.theLowerBoundIncl = false;
    }
    else if (haveUpper && lossy)
    {
      theCondition->theRangeFlags.theUpperBoundIncl = true;
    }
  }

  GET_FACTORY().createLong(result, longValue);
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralTreeIndexIterator::open()
{
  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::POINT_GENERAL)
  {
    theResultSetsEnd = theResultSets.end();
    theResultSetsIte = theResultSets.begin();

    for (; theResultSetsIte != theResultSetsEnd; ++theResultSetsIte)
    {
      if (*theResultSetsIte != NULL)
      {
        theIte = (*theResultSetsIte)->begin();
        theEnd = (*theResultSetsIte)->end();
        
        break;
      }
    }
  }
  else
  {
    theCurrentMap = 0;

    if (!theMapBegins.empty())
    {
      assert(!theMapEnds.empty());

      theMapIte = theMapBegins[theCurrentMap];

      if (theMapIte != theMapEnds[theCurrentMap])
      {
        GeneralIndexValue* resultSet = theMapIte->second;
        theIte = resultSet->begin();
        theEnd = resultSet->end();
      }
    }
  }
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralTreeIndexIterator::reset()
{
  open();
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralTreeIndexIterator::close()
{
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeGeneralTreeIndexIterator::next(store::Item_t& result)
{
  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::POINT_GENERAL)
  {
    while (theResultSetsIte != theResultSetsEnd)
    {
      while (theIte != theEnd)
      {
        if (theIsUntypedProbe && (*theIte).theUntyped)
        {
          assert(theProbeKind == store::IndexCondition::POINT_GENERAL);
          // Note: in case of a point value probe, (*theIte).theUntyped implies
          // that the search key is of type xs:string, or xs:anyURI (otherwise,
          // an error would have been raised in the initPoint method). As a 
          // result, we should not skip this node.

          ++theIte;
          continue;
        }

        result = (*theIte).theNode;
        
        ++theIte;
        return true;
      }

      ++theResultSetsIte;

      if (theResultSetsIte != theResultSetsEnd && *theResultSetsIte != NULL)
      {
        theIte = (*theResultSetsIte)->begin();
        theEnd = (*theResultSetsIte)->end();
      }
    }
  }
  else
  {
    while (theCurrentMap < theMapBegins.size())
    {
      while (theMapIte != theMapEnds[theCurrentMap])
      {
        while (theIte != theEnd)
        {
          if ((theIsFullProbe || theIsUntypedProbe) && (*theIte).theUntyped)
          {
            ++theIte;
            continue;
          }

          result = (*theIte).theNode;
          
          ++theIte;
          return true;
        }

        ++theMapIte;
        if (theMapIte == theMapEnds[theCurrentMap])
          break;

        GeneralIndexValue* resultSet = theMapIte->second;
        theIte = resultSet->begin();
        theEnd = resultSet->end();
      }

      ++theCurrentMap;
      if (theCurrentMap == theMapBegins.size())
        break;

      theMapIte = theMapBegins[theCurrentMap];

      if (theMapIte != theMapEnds[theCurrentMap])
      {
        GeneralIndexValue* resultSet = theMapIte->second;
        theIte = resultSet->begin();
        theEnd = resultSet->end();
      }
    }
  }

  return false;
}


} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
