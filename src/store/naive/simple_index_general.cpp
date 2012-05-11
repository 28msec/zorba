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

#include "simple_index_general.h"
#include "simple_store.h"
#include "atomic_items.h"
#include "simple_item_factory.h"

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
uint32_t GeneralIndexCompareFunction::hash(const store::Item* key) const
{
  uint32_t hval = FNV_32_INIT;

  if (key == NULL)
    return hval;

  return hashfun::h32<uint32_t>(key->hash(theTimezone, theCollator), hval);
}


/******************************************************************************

********************************************************************************/
bool GeneralIndexCompareFunction::equal(
    const store::Item* key1,
    const store::Item* key2) const
{
  if (key1 == NULL && key2 == NULL)
    return true;

  if (key1 == NULL || key2 == NULL)
    return false;

  if (! key1->equals(key2, theTimezone, theCollator))
    return false;
  
  return true;
}


/*******************************************************************************

********************************************************************************/
long GeneralIndexCompareFunction::compare(
    const store::Item* key1,
    const store::Item* key2) const
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
const int64_t  GeneralIndex::theMaxLong       =  99999999999LL;
const int64_t  GeneralIndex::theMinLong       = -99999999999LL;
const double   GeneralIndex::theDoubleMaxLong =  99999999999.0;
const double   GeneralIndex::theDoubleMinLong = -99999999999.0;


/******************************************************************************

*******************************************************************************/
GeneralIndex::GeneralIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  IndexImpl(qname, spec),
  theKeyTypeCode(store::XS_LAST),
  theCompFunction(spec.theTimezone, spec.theCollations[0]),
  theUntypedFlag(false),
  theMultiKeyFlag(false)
{
  store::Item* typeName = spec.theKeyTypes[0].getp();

  if (typeName != NULL &&
      typeName != GET_STORE().theSchemaTypeNames[store::XS_UNTYPED_ATOMIC] &&
      typeName != GET_STORE().theSchemaTypeNames[store::XS_ANY_ATOMIC])
  {
    theKeyTypeCode = GET_STORE().theSchemaTypeCodes[spec.theKeyTypes[0].getp()];
  }
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

*******************************************************************************/
ulong GeneralIndex::size() const
{
  assert(false);
  return 0;
}


/******************************************************************************

*******************************************************************************/
bool GeneralIndex::insert(store::IndexKey*& key, store::Item_t& value)
{
  if (key->size() != 1)
  {
    RAISE_ERROR_NO_LOC(zerr::ZDDY0035_INDEX_GENERAL_INSERT,
    ERROR_PARAMS(getName()->getStringValue()));
  }
  return insert((*key)[0], value);
}


/******************************************************************************

*******************************************************************************/
bool GeneralIndex::insert(store::Item_t& key, store::Item_t& node)
{
  bool lossy = false;
  bool found = false;
  store::Item_t castItem;
  store::Item_t node2;

  bool sorted = isSorted();

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

  store::SchemaTypeCode keyType = keyItem->getTypeCode();

  if (isTyped())
  {
    return insertInMap(key, node, theKeyTypeCode, false);
  }

  switch (keyType)
  {
  case store::XS_BASE64BINARY:
  case store::XS_HEXBINARY:

  case store::XS_QNAME:
  case store::XS_NOTATION:

  case store::XS_GYEAR_MONTH:
  case store::XS_GYEAR:
  case store::XS_GMONTH_DAY:
  case store::XS_GDAY:
  case store::XS_GMONTH:
  {
    assert(!sorted);
    // falth through
  }

  case store::XS_ANY_URI:

  case store::XS_BOOLEAN:

  case store::XS_DATETIME:
  case store::XS_DATE:
  case store::XS_TIME:
  {
    return insertInMap(key, node, keyType, false);
  }

  case store::XS_DURATION:
  case store::XS_YM_DURATION:
  case store::XS_DT_DURATION:
  {
    return insertInMap(key, node, store::XS_DURATION, false);
  }

  case store::XS_STRING:
  case store::XS_NORMALIZED_STRING:
  case store::XS_TOKEN:
  case store::XS_NMTOKEN:
  case store::XS_LANGUAGE:
  case store::XS_NAME:
  case store::XS_NCNAME:
  case store::XS_ID:
  case store::XS_IDREF:
  case store::XS_ENTITY:
  {
    return insertInMap(key, node, store::XS_STRING, false);
  }

  case store::XS_DOUBLE:
  case store::XS_FLOAT:
  {
    return insertInMap(key, node, store::XS_DOUBLE, false);
  }

  case store::XS_DECIMAL:
  case store::XS_INTEGER:
  case store::XS_NON_POSITIVE_INTEGER:
  case store::XS_NEGATIVE_INTEGER:
  case store::XS_NON_NEGATIVE_INTEGER:
  case store::XS_POSITIVE_INTEGER:
  case store::XS_UNSIGNED_LONG:
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
    keyItem->coerceToDouble(castItem, true, lossy);

    found = insertInMap(key, node, store::XS_DOUBLE, false);

    if (lossy)
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DECIMAL, false);
    }

    return found;
  }

  case store::XS_LONG:
  {
longmap:
    xs_long longValue = static_cast<LongItem*>(keyItem)->getLongValue();

    if (longValue > theMaxLong || longValue < theMinLong)
    {
      if (sorted)
      {
        lossy = true;
        xs_double doubleValue(longValue);
        GET_FACTORY().createDouble(castItem, doubleValue);
      }
      else
      {
        keyItem->coerceToDouble(castItem, false, lossy);
      }

      if (lossy)
      {
        node2 = node;
        found = insertInMap(key, node2, store::XS_LONG, false);

        found = found || insertInMap(castItem, node, store::XS_DOUBLE, false);
      }
      else
      {
        found = insertInMap(key, node, store::XS_LONG, false);
      }
    }
    else
    {
      found = insertInMap(key, node, store::XS_LONG, false);
    }

    return found;
  }

  case store::XS_INT:
  case store::XS_SHORT:
  case store::XS_BYTE:
  case store::XS_UNSIGNED_INT:
  case store::XS_UNSIGNED_SHORT:
  case store::XS_UNSIGNED_BYTE:
  {
    return insertInMap(key, node, store::XS_LONG, false);
  }

  case store::XS_UNTYPED_ATOMIC:
  {
    store::ItemHandle<UntypedAtomicItem> untypedItem = 
    static_cast<UntypedAtomicItem*>(key.getp());

    // cast to xs:string
    untypedItem->castToString(castItem);

    node2 = node;
    found = insertInMap(castItem, node2, store::XS_STRING, false);

    // No reason to cast to xs:anyUri, because when we probe with xs:string or
    // with xs:anyUri, or with xs:untypedAtomic, we unconditionally probe both
    // the STRING and the ANY_URI tables.
 
    // try casting to xs:long
    if (untypedItem->castToLong(castItem))
    {
      store::ItemHandle<LongItem> longItem = static_cast<LongItem*>(castItem.getp());

      xs_long longValue = longItem->getLongValue();

      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_LONG, true);

      if (longValue > theMaxLong || longValue < theMinLong)
      {
        if (sorted)
        {
          lossy = true;
          xs_double doubleValue(longValue);
          GET_FACTORY().createDouble(castItem, doubleValue);
        }
        else
        {
          longItem->coerceToDouble(castItem, false, lossy);
        }

        if (lossy)
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_DOUBLE, true);
        }
      }

      // may also be gYear, hexBinary, base64Binary, or boolean
      if (!sorted)
      {
        if (untypedItem->castToGYear(castItem))
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_GYEAR, true);
        }

        if (untypedItem->castToHexBinary(castItem))
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_HEXBINARY, true);
        }

        if (untypedItem->castToBase64Binary(castItem))
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_BASE64BINARY, true);
        }
      }
    }

    // try casting to xs:decimal
    else if (untypedItem->castToDecimal(castItem))
    {
      store::ItemHandle<DecimalItem> decimalItem = 
      static_cast<DecimalItem*>(castItem.getp());

      decimalItem->coerceToDouble(castItem, true, lossy);

      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DOUBLE, true);

      if (lossy)
      {
        castItem.transfer(decimalItem);
        node2 = node;
        found = found || insertInMap(castItem, node2, store::XS_DECIMAL, true);
      }

      // may also be hexBinary or base64Binary
      if (sorted)
      {
        if (untypedItem->castToHexBinary(castItem))
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_HEXBINARY, true);
        }

        if (untypedItem->castToBase64Binary(castItem))
        {
          node2 = node;
          found = found || insertInMap(castItem, node2, store::XS_BASE64BINARY, true);
        }
      }
    }

    // try casting to xs:double
    else if (untypedItem->castToDouble(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DOUBLE, true);
    }

    // try casting to xs:datetime
    else if (untypedItem->castToDateTime(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DATETIME, true);
    }

    // try casting to xs:date
    else if (untypedItem->castToDate(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DATE, true);
    }

    // try casting to xs:time
    else if (untypedItem->castToTime(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_TIME, true);
    }

    // try casting to xs:gYearMonth
    if (!sorted && untypedItem->castToGYearMonth(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_GYEAR_MONTH, true);
    }

    // try casting to xs:gMonthDay
    else if (!sorted && untypedItem->castToGMonthDay(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_GMONTH_DAY, true);
    }

    // try casting to xs:gDay
    else if (!sorted && untypedItem->castToGDay(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_GDAY, true);
    }

    // try casting to xs:gMonth
    else if (!sorted && untypedItem->castToGMonth(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_GMONTH, true);
    }

    // try casting to xs:duration
    else if (untypedItem->castToDuration(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_DURATION, true);
    }

    // try casting to xs:hexBinary
    else if (!sorted && untypedItem->castToHexBinary(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_HEXBINARY, true);
    }

    // try casting to xs:base64Binary
    else if (!sorted && untypedItem->castToBase64Binary(castItem))
    {
      node2 = node;
      found = found || insertInMap(castItem, node2, store::XS_BASE64BINARY, true);
    }

    return found;
  }

  default:
  {
    RAISE_ERROR_NO_LOC(zerr::ZDTY0012_INDEX_KEY_TYPE_ERROR, 
    ERROR_PARAMS(getName()->getStringValue()));
    return false;
  }
  }
}


/******************************************************************************

*******************************************************************************/
bool GeneralIndex::insertInMap(
    store::Item_t& key,
    store::Item_t& node,
    store::SchemaTypeCode targetMap,
    bool untyped)
{
  if (untyped)
    theUntypedFlag = true;

  if (isSorted())
  {
    GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(this);
    return idx->insertInMap(key, node, idx->theMaps[targetMap], untyped);
  }
  else
  {
    GeneralHashIndex* idx = static_cast<GeneralHashIndex*>(this);
    return idx->insertInMap(key, node, idx->theMaps[targetMap], untyped);
  }
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

  memset(reinterpret_cast<void*>(theMaps), 0, store::XS_LAST * sizeof(IndexMap*));

  if (isTyped())
  {
    theSingleMap = new IndexMap(theCompFunction, 1024, spec.theIsThreadSafe);

    theMaps[theKeyTypeCode] = theSingleMap;
  }
}


/******************************************************************************

*******************************************************************************/
GeneralHashIndex::~GeneralHashIndex()
{
  for (ulong i = 0; i < store::XS_LAST; ++i)
  {
    if (theMaps[i] == NULL)
      continue;

    IndexMap::iterator ite = theMaps[i]->begin();
    IndexMap::iterator end = theMaps[i]->end();
 
    for (; ite != end; ++ite)
    {
      //std::cout << "Index Entry Delete [" << (*ite).first << "," 
      //          << (*ite).second << "]" << std::endl;
      
      const_cast<store::Item*>((*ite).first)->removeReference();
      delete (*ite).second;
    }

    delete theMaps[i];
  }
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
bool GeneralHashIndex::insertInMap(
    store::Item_t& key,
    store::Item_t& node,
    IndexMap*& targetMap,
    bool untyped)
{
  GeneralIndexValue* valueSet = NULL;

  if (targetMap == NULL)
    targetMap = new IndexMap(theCompFunction, 1024, theSpec.theIsThreadSafe);

  if (targetMap->get(key, valueSet))
  {
    if (isUnique())
    {
      RAISE_ERROR_NO_LOC(zerr::ZDDY0024_INDEX_UNIQUE_VIOLATION,
      ERROR_PARAMS(theQname->getStringValue()));
    }
    
    valueSet->addNode(node, untyped);

    return true;
  }

  valueSet = new GeneralIndexValue();
  valueSet->addNode(node, untyped);
  
  //std::cout << "Index Entry Insert [" << key << "," 
  //          << valueSet << "]" << std::endl;
  
  targetMap->insert(key.getp(), valueSet);
  key.release(); // ownership of the key passes to the index.

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


/******************************************************************************

*******************************************************************************/
void GeneralHashIndex::clear()
{
  for (ulong i = 0; i < store::XS_LAST; ++i)
  {
    if (theMaps[i] == NULL)
      continue;

    theMaps[i]->clear();
  }

  if (isTyped())
  {
    theSingleMap->clear();
  }
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
GeneralTreeIndex::GeneralTreeIndex(
    const store::Item_t& qname,
    const store::IndexSpecification& spec)
  :
  GeneralIndex(qname, spec),
  theSingleMap(NULL)
{
  assert(getNumColumns() == 1);

  memset(reinterpret_cast<void*>(theMaps), 0, store::XS_LAST * sizeof(IndexMap*));

  if (isTyped())
  {
    theSingleMap = new IndexMap(theCompFunction);

    theMaps[theKeyTypeCode] = theSingleMap;
  }
}


/******************************************************************************

*******************************************************************************/
GeneralTreeIndex::~GeneralTreeIndex()
{
  for (ulong i = 0; i < store::XS_LAST; ++i)
  {
    if (theMaps[i] == NULL)
      continue;

    IndexMap::iterator ite = theMaps[i]->begin();
    IndexMap::iterator end = theMaps[i]->end();
 
    for (; ite != end; ++ite)
    {
      //std::cout << "Index Entry Delete [" << (*ite).first << "," 
      //          << (*ite).second << "]" << std::endl;
      
      const_cast<store::Item*>((*ite).first)->removeReference();
      delete (*ite).second;
    }

    delete theMaps[i];
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
  
  targetMap->insert(IndexMapPair(key.getp(), valueSet));
  key.release(); // ownership of the key obj passes to the index.

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
void GeneralTreeIndex::clear()
{
  for (ulong i = 0; i < store::XS_LAST; ++i)
  {
    if (theMaps[i] == NULL)
      continue;

    theMaps[i]->clear();
  }

  if (isTyped())
  {
    theSingleMap->clear();
  }
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
  theIsUntypedProbe(false),
  theIsFullProbe(false)
{
}


/*******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::checkStringKeyType(const AtomicItem* key) const
{
  if (key == NULL)
    return;

  store::SchemaTypeCode keyType = key->getTypeCode();

  if (keyType != store::XS_UNTYPED_ATOMIC &&
      keyType != store::XS_ANY_URI &&
      keyType != store::XS_STRING &&
      keyType != store::XS_NORMALIZED_STRING &&
      keyType != store::XS_TOKEN &&
      keyType != store::XS_NMTOKEN &&
      keyType != store::XS_LANGUAGE &&
      keyType != store::XS_NAME &&
      keyType != store::XS_NCNAME &&
      keyType != store::XS_ID &&
      keyType != store::XS_IDREF &&
      keyType != store::XS_ENTITY)
  {
    RAISE_ERROR_NO_LOC(err::XPTY0004,
    ERROR_PARAMS(ZED(NoUntypedKeyNodeValue_2), theIndex->getName()->getStringValue()));
  }
}


/*******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::doubleToLongProbe(
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


/*******************************************************************************
  
********************************************************************************/
void ProbeGeneralIndexIterator::init(const store::IndexCondition_t& cond)
{
  theProbeKind = cond->getKind();
  theCondition = static_cast<GeneralIndexCondition*>(cond.getp());

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

  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::POINT_GENERAL)
  {
    initPoint();
  }
  else
  {
    static_cast<ProbeGeneralTreeIndexIterator*>(this)->initBox();
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralIndexIterator::initPoint()
{
  // Note: the runtime (or compiler) makes sure that the search key is not NULL
  // and its type is a subtype of the index key type. Furthermore, in the case 
  // of a point-value probe, the type of the search item cannot be untyped, 
  // because untyped search keys either don't match the index key type, or are 
  // cast to xs:string. 
  AtomicItem_t& key = theCondition->theKey;

  bool sorted = theIndex->isSorted();

  if (theIndex->isTyped())
  {
    probeMap(theIndex->theKeyTypeCode, key.getp());
  }
  else
  {
    bool lossy;
    store::Item_t castItem;

    store::SchemaTypeCode keyType = key->getTypeCode();

    switch (keyType)
    {
    case store::XS_QNAME:
    case store::XS_NOTATION:
    case store::XS_BASE64BINARY:
    case store::XS_HEXBINARY:
    case store::XS_GYEAR_MONTH:
    case store::XS_GYEAR:
    case store::XS_GMONTH_DAY:
    case store::XS_GDAY:
    case store::XS_GMONTH:
    {
      assert(!sorted);
    }

    case store::XS_BOOLEAN:
    case store::XS_DATETIME:
    case store::XS_DATE:
    case store::XS_TIME:

    {
      probeMap(keyType, key.getp());
      break;
    }

    case store::XS_DURATION:
    case store::XS_YM_DURATION:
    case store::XS_DT_DURATION:
    {
      probeMap(store::XS_DURATION, key.getp()); 
      break;
    }

    case store::XS_ANY_URI:
    {
      probeMap(store::XS_ANY_URI, key.getp()); 

      if (haveMap(store::XS_STRING))
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createString(castItem, tmp);

        probeMap(store::XS_STRING, castItem.getp());
      }

      break;
    }

    case store::XS_STRING:
    case store::XS_NORMALIZED_STRING:
    case store::XS_TOKEN:
    case store::XS_NMTOKEN:
    case store::XS_LANGUAGE:
    case store::XS_NAME:
    case store::XS_NCNAME:
    case store::XS_ID:
    case store::XS_IDREF:
    case store::XS_ENTITY:
    {
      probeMap(store::XS_STRING, key.getp());

      if (haveMap(store::XS_ANY_URI))
      {
        zstring tmp;
        key->getStringValue2(tmp);
        GET_FACTORY().createAnyURI(castItem, tmp);

        probeMap(store::XS_ANY_URI, castItem.getp());
      }

      break;
    }

    case store::XS_DOUBLE:
    case store::XS_FLOAT:
    {
      probeMap(store::XS_DOUBLE, key.getp());

      if (haveMap(store::XS_LONG) && key->castToLong(castItem))
        probeMap(store::XS_LONG, castItem.getp());

      break;
    }

    case store::XS_DECIMAL:
    case store::XS_INTEGER:
    case store::XS_NON_POSITIVE_INTEGER:
    case store::XS_NEGATIVE_INTEGER:
    case store::XS_NON_NEGATIVE_INTEGER:
    case store::XS_POSITIVE_INTEGER:
    case store::XS_UNSIGNED_LONG:
    {
      key->coerceToDouble(castItem, true, lossy);

      if (lossy)
        probeMap(store::XS_DECIMAL, key.getp());

      probeMap(store::XS_DOUBLE, castItem.getp());

      if (haveMap(store::XS_LONG) && key->castToLong(castItem))
        probeMap(store::XS_LONG, castItem.getp());

      break;
    }

    case store::XS_LONG:
    case store::XS_INT:
    case store::XS_SHORT:
    case store::XS_BYTE:
    case store::XS_UNSIGNED_INT:
    case store::XS_UNSIGNED_SHORT:
    case store::XS_UNSIGNED_BYTE:
    {
      probeMap(store::XS_LONG, key.getp());

      if (haveMap(store::XS_DOUBLE))
      {
        key->coerceToDouble(castItem, true, lossy);
        probeMap(store::XS_DOUBLE, castItem.getp());
      }

      break;
    }

    case store::XS_UNTYPED_ATOMIC:
    {
      ZORBA_ASSERT(theProbeKind == store::IndexCondition::POINT_GENERAL);

      theIsUntypedProbe = true;

      store::ItemHandle<UntypedAtomicItem> untypedItem = 
      static_cast<UntypedAtomicItem*>(key.getp());

      // cast to xs:string
      if (haveMap(store::XS_STRING))
      {
        untypedItem->castToString(castItem); 
        probeMap(store::XS_STRING, castItem.getp());
      }

      // cast to xs:anyURI
      if (haveMap(store::XS_ANY_URI) && untypedItem->castToUri(castItem))
      {
        probeMap(store::XS_ANY_URI, castItem.getp());
      }

      // try casting to xs:long
      if ((haveMap(store::XS_LONG) || haveMap(store::XS_DOUBLE)) &&
          (untypedItem->castToLong(castItem), castItem != NULL))
      {
        store::ItemHandle<LongItem> longItem = 
        static_cast<LongItem*>(castItem.getp());

        probeMap(store::XS_LONG, castItem.getp());

        if (haveMap(store::XS_DOUBLE))
        {
          longItem->coerceToDouble(castItem, true, lossy);
          probeMap(store::XS_DOUBLE, castItem.getp());
        }

        // may also be gYear, hexBinary, base64Binary, or boolean
        if (!sorted)
        {
          if (haveMap(store::XS_GYEAR))
          {
            untypedItem->castToGYear(castItem);
            probeMap(store::XS_GYEAR, castItem.getp());
          }

          if (haveMap(store::XS_HEXBINARY))
          {
            untypedItem->castToHexBinary(castItem); 
            probeMap(store::XS_HEXBINARY, castItem.getp());
          }

          if (haveMap(store::XS_BASE64BINARY))
          {
            untypedItem->castToBase64Binary(castItem); 
            probeMap(store::XS_BASE64BINARY, castItem.getp());
          }
        }
      }

      // try casting to xs:decimal
      else if ((haveMap(store::XS_DECIMAL) ||
                haveMap(store::XS_LONG) ||
                haveMap(store::XS_DOUBLE)) &&
               untypedItem->castToDecimal(castItem))
      {
        store::ItemHandle<DecimalItem> decimalItem = 
        static_cast<DecimalItem*>(castItem.getp());

        decimalItem->coerceToDouble(castItem, true, lossy);

        probeMap(store::XS_DOUBLE, castItem.getp());

        if (haveMap(store::XS_LONG) && decimalItem->castToLong(castItem))
        {
          probeMap(store::XS_LONG, castItem.getp());
        }

        if (lossy && haveMap(store::XS_DECIMAL))
        {
          castItem.transfer(decimalItem);
          probeMap(store::XS_DOUBLE, castItem.getp());
        }

        // may also be hexBinary or base64Binary
        if (!sorted)
        {
          if (haveMap(store::XS_HEXBINARY))
          {
            untypedItem->castToHexBinary(castItem); 
            probeMap(store::XS_HEXBINARY, castItem.getp());
          }

          if (haveMap(store::XS_BASE64BINARY))
          {
            untypedItem->castToBase64Binary(castItem); 
            probeMap(store::XS_BASE64BINARY, castItem.getp());
          }
        }
      }

      // try casting to xs:double
      else if ((haveMap(store::XS_LONG) || haveMap(store::XS_DOUBLE)) &&
               untypedItem->castToDouble(castItem))
      {
        store::ItemHandle<DoubleItem> doubleItem = 
        static_cast<DoubleItem*>(castItem.getp());

        probeMap(store::XS_DOUBLE, castItem.getp());

        if (haveMap(store::XS_LONG) && doubleItem->castToLong(castItem))
        {
          probeMap(store::XS_LONG, castItem.getp());
        }
      }

      // try casting to xs:datetime
      else if (haveMap(store::XS_DATETIME) &&
               untypedItem->castToDateTime(castItem))
      {
        probeMap(store::XS_DATETIME, castItem.getp());
      }

      // try casting to xs:date
      else if (haveMap(store::XS_DATE) &&
               untypedItem->castToDate(castItem))
      {
        probeMap(store::XS_DATE, castItem.getp());
      }

      // try casting to xs:time
      else if (haveMap(store::XS_TIME) &&
               untypedItem->castToTime(castItem))
      {
        probeMap(store::XS_TIME, castItem.getp());
      }

      // try casting to xs:gYearMonth
      if (!sorted && 
          haveMap(store::XS_GYEAR_MONTH) &&
          untypedItem->castToGYearMonth(castItem))
      {
        probeMap(store::XS_GYEAR_MONTH, castItem.getp());
      }

      // try casting to xs:gMonthDay
      else if (!sorted && 
               haveMap(store::XS_GMONTH_DAY) &&
               untypedItem->castToGMonthDay(castItem))
      {
        probeMap(store::XS_GMONTH_DAY, castItem.getp());
      }

      // try casting to xs:gDay
      else if (!sorted &&
               haveMap(store::XS_GDAY) &&
               untypedItem->castToGDay(castItem))
      {
        probeMap(store::XS_GDAY, castItem.getp());
      }

      // try casting to xs:gMonth
      else if (!sorted &&
               haveMap(store::XS_GMONTH) &&
               untypedItem->castToGMonth(castItem))
      {
        probeMap(store::XS_GMONTH, castItem.getp());
      }

      // try casting to xs:duration
      else if (haveMap(store::XS_DURATION) &&
               untypedItem->castToDuration(castItem))
      {
        probeMap(store::XS_DURATION, castItem.getp());
      }
      
      // try casting to xs:hexBinary
      else if (!sorted &&
               haveMap(store::XS_HEXBINARY) &&
               untypedItem->castToHexBinary(castItem))
      {
        probeMap(store::XS_HEXBINARY, castItem.getp());
      }
      
      // try casting to xs:base64Binary
      else if (!sorted &&
               haveMap(store::XS_BASE64BINARY) &&
               untypedItem->castToBase64Binary(castItem))
      {
        probeMap(store::XS_BASE64BINARY, castItem.getp());
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
void ProbeGeneralIndexIterator::initBox()
{
  GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(theIndex.getp());

  bool haveLower = theCondition->theRangeFlags.theHaveLowerBound;
  bool haveUpper = theCondition->theRangeFlags.theHaveUpperBound;

  assert(theProbeKind == store::IndexCondition::BOX_VALUE ||
         !(haveLower && haveUpper));

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
    probeMap(theIndex->theKeyTypeCode, lowerKey, upperKey);
  }
  else if (haveLower || haveUpper)
  {
    store::Item_t castItem;

    store::SchemaTypeCode lowerKeyType = 
    (haveLower ? lowerKey->getTypeCode() : store::XS_LAST);

    store::SchemaTypeCode upperKeyType = 
    (haveUpper ? upperKey->getTypeCode() : store::XS_LAST);

    store::SchemaTypeCode keyType = 
    (lowerKeyType < upperKeyType ? lowerKeyType : upperKeyType);

    switch (keyType)
    {
    case store::XS_BOOLEAN:
    case store::XS_DATETIME:
    case store::XS_DATE:
    case store::XS_TIME:
    {
      probeMap(keyType, lowerKey, upperKey);
      break;
    }

    case store::XS_DURATION:
    case store::XS_YM_DURATION:
    case store::XS_DT_DURATION:
    {
      probeMap(store::XS_DURATION, lowerKey, upperKey);
      break;
    }

    case store::XS_ANY_URI:
    {
      probeMap(store::XS_ANY_URI, lowerKey, upperKey);

      if (idx->theMaps[store::XS_STRING])
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
        
        probeMap(store::XS_STRING, lowerAltKey, upperAltKey);
      }

      break;
    }

    case store::XS_STRING:
    case store::XS_NORMALIZED_STRING:
    case store::XS_TOKEN:
    case store::XS_NMTOKEN:
    case store::XS_LANGUAGE:
    case store::XS_NAME:
    case store::XS_NCNAME:
    case store::XS_ID:
    case store::XS_IDREF:
    case store::XS_ENTITY:
    {
      probeMap(store::XS_STRING, lowerKey, upperKey);

      if (idx->theMaps[store::XS_ANY_URI])
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

        probeMap(store::XS_ANY_URI, lowerAltKey, upperAltKey);
      }

      break;
    }

    case store::XS_DOUBLE:
    case store::XS_FLOAT:
    {
      probeMap(store::XS_DOUBLE, lowerKey, upperKey);

      if (idx->theMaps[store::XS_LONG])
      {
        if (haveLower)
          doubleToLongProbe(lowerAltKey, lowerKey, true, false);

        if (haveUpper)
          doubleToLongProbe(upperAltKey, upperKey, false, true);

        if (haveLower && haveUpper)
        {
          if (lowerAltKey && upperAltKey)
            probeMap(store::XS_ANY_URI, lowerAltKey, upperAltKey);    
        }
        else if ((haveLower && lowerAltKey) || (haveUpper && upperAltKey))
        {
          probeMap(store::XS_ANY_URI, lowerAltKey, upperAltKey);
        }
      }

      break;
    }

    case store::XS_DECIMAL:
    case store::XS_INTEGER:
    case store::XS_NON_POSITIVE_INTEGER:
    case store::XS_NEGATIVE_INTEGER:
    case store::XS_NON_NEGATIVE_INTEGER:
    case store::XS_POSITIVE_INTEGER:
    case store::XS_UNSIGNED_LONG:
    {
      probeMap(store::XS_DECIMAL, lowerKey, upperKey);

      if (idx->theMaps[store::XS_LONG])
      {
        probeMap(store::XS_LONG, lowerKey, upperKey);
      }

      if (idx->theMaps[store::XS_DOUBLE])
      {
        if (haveLower)
        {
          xs_double const doubleValue( lowerKey->getDecimalValue() );
          GET_FACTORY().createDouble(lowerAltKey, doubleValue);
        }

        if (haveUpper)
        {
          xs_double const doubleValue( upperKey->getDecimalValue() );
          GET_FACTORY().createDouble(upperAltKey, doubleValue);
        }

        probeMap(store::XS_DOUBLE, lowerAltKey, upperAltKey);
      }

      break;
    }

    case store::XS_LONG:
    case store::XS_INT:
    case store::XS_SHORT:
    case store::XS_BYTE:
    case store::XS_UNSIGNED_INT:
    case store::XS_UNSIGNED_SHORT:
    case store::XS_UNSIGNED_BYTE:
    {
      probeMap(store::XS_LONG, lowerKey, upperKey);

      if (idx->theMaps[store::XS_DECIMAL])
      {
        if (haveLower)
        {
          xs_decimal const decimalValue( lowerKey->getLongValue() );
          GET_FACTORY().createDecimal(lowerAltKey, decimalValue);
        }

        if (haveUpper)
        {
          xs_decimal const decimalValue( upperKey->getLongValue() );
          GET_FACTORY().createDecimal(upperAltKey, decimalValue);
        }

        probeMap(store::XS_DECIMAL, lowerAltKey, upperAltKey);
      }

      if (idx->theMaps[store::XS_DOUBLE])
      {
        if (haveLower)
        {
          xs_double doubleValue( lowerKey->getLongValue() );
          GET_FACTORY().createDouble(lowerAltKey, doubleValue);
        }

        if (haveUpper)
        {
          xs_double const doubleValue( upperKey->getLongValue() );
          GET_FACTORY().createDouble(upperAltKey, doubleValue);
        }

        probeMap(store::XS_DOUBLE, lowerAltKey, upperAltKey);
      }

      break;
    }

    case store::XS_UNTYPED_ATOMIC:
    {
      assert(theProbeKind == store::IndexCondition::BOX_GENERAL);

      theIsUntypedProbe = true;

      store::ItemHandle<UntypedAtomicItem> untypedItem = 
      (haveLower ? 
       static_cast<UntypedAtomicItem*>(lowerKey.getp()) :
       static_cast<UntypedAtomicItem*>(upperKey.getp()));

      store::Item_t altKey;

      // cast to xs:string
      if (idx->theMaps[store::XS_STRING])
      {
        untypedItem->castToString(altKey);
        probeMap(store::XS_STRING, altKey, altKey);
      }

      // cast to xs:anyURI
      if (idx->theMaps[store::XS_ANY_URI] && untypedItem->castToUri(altKey))
      {
        probeMap(store::XS_ANY_URI, altKey, altKey);
      }

      // try casting to xs:long
      if ((idx->theMaps[store::XS_LONG] ||
           idx->theMaps[store::XS_DOUBLE] ||
           idx->theMaps[store::XS_DECIMAL]) &&
          untypedItem->castToLong(altKey), altKey != NULL)
      {
        store::ItemHandle<LongItem> longItem = 
        static_cast<LongItem*>(altKey.getp());

        if (idx->theMaps[store::XS_LONG])
        {
          probeMap(store::XS_LONG, altKey, altKey);
        }

        if (idx->theMaps[store::XS_DOUBLE])
        {
          xs_double const doubleValue( longItem->getLongValue() );
          GET_FACTORY().createDouble(altKey, doubleValue);
          probeMap(store::XS_DOUBLE, altKey, altKey);
        }

        if (idx->theMaps[store::XS_DECIMAL])
        {
          xs_decimal const decimalValue( longItem->getLongValue() );
          GET_FACTORY().createDecimal(altKey, decimalValue);
          probeMap(store::XS_DECIMAL, altKey, altKey);
        }
      }

      // try casting to xs:decimal
      else if ((idx->theMaps[store::XS_LONG] ||
                idx->theMaps[store::XS_DOUBLE] ||
                idx->theMaps[store::XS_DECIMAL]) &&
               untypedItem->castToDecimal(altKey), altKey != NULL)
      {
        store::ItemHandle<DecimalItem> decimalItem = 
        static_cast<DecimalItem*>(altKey.getp());

        if (idx->theMaps[store::XS_DECIMAL])
        {
          probeMap(store::XS_DECIMAL, altKey, altKey);
        }

        if (idx->theMaps[store::XS_LONG])
        {
          probeMap(store::XS_LONG, altKey, altKey);
        }

        if (idx->theMaps[store::XS_DOUBLE])
        {
          xs_double const doubleValue( decimalItem->getDecimalValue() );
          GET_FACTORY().createDouble(altKey, doubleValue);
          probeMap(store::XS_DOUBLE, altKey, altKey);
        }
      }

      // try casting to xs:double
      else if ((idx->theMaps[store::XS_LONG] ||
               idx->theMaps[store::XS_DOUBLE]) &&
               untypedItem->castToDouble(altKey), altKey != NULL)
      {
        store::ItemHandle<DoubleItem> doubleItem = 
        static_cast<DoubleItem*>(altKey.getp());

        if (idx->theMaps[store::XS_DOUBLE])
        {
          probeMap(store::XS_DOUBLE, altKey, altKey);
        }

        if (idx->theMaps[store::XS_LONG])
        {
          doubleToLongProbe(altKey, doubleItem.getp(), haveLower, haveUpper);

          if (altKey)
          {
            probeMap(store::XS_LONG, altKey, altKey);
          }
        }
      }

      // try casting to xs:datetime
      else if (idx->theMaps[store::XS_DATETIME] && untypedItem->castToDateTime(altKey))
      {
        probeMap(store::XS_DATETIME, altKey, altKey);
      }

      // try casting to xs:date
      else if (idx->theMaps[store::XS_DATE] && untypedItem->castToDate(altKey))
      {
        probeMap(store::XS_DATE, altKey, altKey);
      }

      // try casting to xs:time
      else if (idx->theMaps[store::XS_TIME] && untypedItem->castToTime(altKey))
      {
        probeMap(store::XS_TIME, altKey, altKey);
      }

      // try casting to xs:duration
      else if (idx->theMaps[store::XS_DURATION] && untypedItem->castToDuration(altKey))
      {
        probeMap(store::XS_DURATION, altKey, altKey);
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

    for (ulong i = 0; i < store::XS_LAST; ++i)
    {
      if (idx->theMaps[i] == NULL)
        continue;

      theMapBegins.push_back(idx->theMaps[i]->begin());
      theMapEnds.push_back(idx->theMaps[i]->end());
    }
  }
}


/******************************************************************************

*******************************************************************************/
void ProbeGeneralIndexIterator::probeMap(
    store::SchemaTypeCode targetMap,
    const store::Item* key)
{
  if (theIndex->isSorted())
  {
    static_cast<ProbeGeneralTreeIndexIterator*>(this)->
    probeMap(static_cast<GeneralTreeIndex*>(theIndex.getp())->theMaps[targetMap],
             key);
  }
  else
  {
    static_cast<ProbeGeneralHashIndexIterator*>(this)->
    probeMap(static_cast<GeneralHashIndex*>(theIndex.getp())->theMaps[targetMap],
             key);
  }
}


/*******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::probeMap(
    store::SchemaTypeCode targetMap,
    const store::Item* lowerKey,
    const store::Item* upperKey)
{
    static_cast<ProbeGeneralTreeIndexIterator*>(this)->
    probeMap(static_cast<GeneralTreeIndex*>(theIndex.getp())->theMaps[targetMap],
             lowerKey,
             upperKey);
}


/*******************************************************************************

********************************************************************************/
bool ProbeGeneralIndexIterator::haveMap(store::SchemaTypeCode targetMap) const
{
  if (theIndex->isSorted())
  {
    GeneralTreeIndex* idx = static_cast<GeneralTreeIndex*>(theIndex.getp());
    return (idx->theMaps[targetMap] != NULL);
  }
  else
  {
    GeneralHashIndex* idx = static_cast<GeneralHashIndex*>(theIndex.getp());
    return (idx->theMaps[targetMap] != NULL);
  }
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::open()
{
  if (theProbeKind == store::IndexCondition::POINT_VALUE ||
      theProbeKind == store::IndexCondition::POINT_GENERAL)
  {
    theResultSetsEnd = theResultSets.end();
    theResultSetsIte = theResultSets.begin();

    for (; theResultSetsIte != theResultSetsEnd; ++theResultSetsIte)
    {
      assert(*theResultSetsIte != NULL);

      theIte = (*theResultSetsIte)->begin();
      theEnd = (*theResultSetsIte)->end();
        
      break;
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
void ProbeGeneralIndexIterator::reset()
{
  open();
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralIndexIterator::close()
{
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeGeneralIndexIterator::next(store::Item_t& result)
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

          ++theIte;
          continue;
        }

        result = (*theIte).theNode;
        
        ++theIte;
        return true;
      }

      ++theResultSetsIte;

      if (theResultSetsIte != theResultSetsEnd)
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
  ProbeGeneralIndexIterator(index)
{
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralHashIndexIterator::probeMap(
    const GeneralHashIndex::IndexMap* targetMap,
    const store::Item* key)
{
  if (targetMap == NULL)
    return;

  GeneralHashIndex::EntryIterator ite = const_cast<GeneralHashIndex::IndexMap*>
  (targetMap)->find(const_cast<store::Item*>(key));

  if (ite != targetMap->end())
  {
    theResultSets.push_back(NULL);
    theResultSets[theResultSets.size() - 1] = (*ite).second;
  }
}


/////////////////////////////////////////////////////////////////////////////////
//                                                                             //
//  ProbeGeneralTreeIndexIterator                                              //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/*******************************************************************************

********************************************************************************/
ProbeGeneralTreeIndexIterator::ProbeGeneralTreeIndexIterator(
    const store::Index_t& index) 
  :
  ProbeGeneralIndexIterator(index)
{
}


/******************************************************************************

********************************************************************************/
void ProbeGeneralTreeIndexIterator::probeMap(
    const GeneralTreeIndex::IndexMap* targetMap,
    const store::Item* key)
{
  if (targetMap == NULL)
    return;

  GeneralTreeIndex::EntryIterator ite = const_cast<GeneralTreeIndex::IndexMap*>
  (targetMap)->find(const_cast<store::Item*>(key));

  if (ite != targetMap->end())
  {
    theResultSets.push_back(NULL);
    theResultSets[theResultSets.size() - 1] = (*ite).second;
  }
}


/******************************************************************************
  
********************************************************************************/
void ProbeGeneralTreeIndexIterator::probeMap(
    const GeneralTreeIndex::IndexMap* map,
    const store::Item* lowerKey,
    const store::Item* upperKey)
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



} // namespace simplestore
} // namespace zorba
/* vim:set et sw=2 ts=2: */
