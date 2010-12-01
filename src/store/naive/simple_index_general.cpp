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
#include "store/naive/simple_item_factory.h"

#include "zorbaerrors/Assert.h"
#include "zorbatypes/floatimpl.h"

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
void GeneralIndexValue::addNode(store::Item_t& node, bool multikey, bool untyped)
{
  ulong numNodes = theNodes.size();
  theNodes.resize(numNodes + 1);
  theNodes[numNodes].theNode.transfer(node);
  theNodes[numNodes].theMultiKey = multikey;
  theNodes[numNodes].theUntyped = untyped;
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
  theCompFunction(getNumColumns(), spec.theTimezone, theCollators),
  theSingleMap(NULL)
{
  assert(getNumColumns() == 1);

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

#define ADD_IN_MAP(MAP_ID, untyped)                                            \
if (castItem !=  NULL)                                                         \
{                                                                              \
  if (key == NULL) key = new store::IndexKey(1);                               \
  (*key)[0].transfer(castItem);                                                \
  found = found || insertInMap(key, node, theMaps[MAP_ID], multikey, untyped); \
  node = node2;                                                                \
}


bool GeneralHashIndex::insert(
    store::IndexKey*& key,
    store::Item_t& node,
    bool multikey)
{
  bool found = false;
  store::Item_t castItem;
  store::Item_t node2;

  AtomicItem* keyItem = static_cast<AtomicItem*>((*key)[0].getp());

  if (keyItem->getBaseItem() != NULL)
  {
    keyItem = static_cast<AtomicItem*>(keyItem->getBaseItem());
    (*key)[0] = keyItem;
  }

  SchemaTypeCode keyType = keyItem->getTypeCode();

  if (isTyped())
  {
    return insertInMap(key, node, theSingleMap, multikey, false);
  }

  switch (keyType)
  {
  case XS_ANY_URI:
  case XS_QNAME:
  case XS_NOTATION:
  case XS_DATETIME:
  case XS_DATE:
  case XS_TIME:
  case XS_GYEAR_MONTH:
  case XS_GYEAR:
  case XS_GMONTH_DAY:
  case XS_GDAY:
  case XS_GMONTH:
  case XS_BASE64BINARY:
  case XS_HEXBINARY:
  case XS_BOOLEAN:
  {
    return insertInMap(key, node, theMaps[keyType], multikey, false);
  }

  case XS_DURATION:
  case XS_YM_DURATION:
  case XS_DT_DURATION:
  {
    return insertInMap(key, node, theMaps[XS_DURATION], multikey, false);
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
    return insertInMap(key, node, theMaps[XS_STRING], multikey, false);
  }

  case XS_DOUBLE:
  case XS_FLOAT:
  {
    return insertInMap(key, node, theMaps[XS_DOUBLE], multikey, false);
  }

  case XS_DECIMAL:
  case XS_INTEGER:
  case XS_NON_POSITIVE_INTEGER:
  case XS_NEGATIVE_INTEGER:
  case XS_NON_NEGATIVE_INTEGER:
  case XS_POSITIVE_INTEGER:
  case XS_UNSIGNED_LONG:
  {
    keyItem->castToLong(castItem);
    if (castItem != NULL)
    {
      keyItem = static_cast<AtomicItem*>(castItem.getp());
      (*key)[0].transfer(castItem);
      goto longmap;
    }

    bool lossy;
    keyItem->coerceToDouble(castItem, true, lossy);

    if (lossy)
    {
      node2 = node;
      found = insertInMap(key, node2, theMaps[XS_DECIMAL], multikey, false);
    }

    if (key == NULL) key = new store::IndexKey(1);
    (*key)[0].transfer(castItem);

    found = found || insertInMap(key, node, theMaps[XS_DOUBLE], multikey, false);

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
      found = insertInMap(key, node2, theMaps[XS_LONG], multikey, false);

      if (key == NULL) key = new store::IndexKey(1);
      (*key)[0].transfer(castItem);

      found = found || insertInMap(key, node, theMaps[XS_DOUBLE], multikey, false);
    }
    else
    {
      found = insertInMap(key, node, theMaps[XS_LONG], multikey, false);
    }

    return found;
  }

  case XS_UNTYPED_ATOMIC:
  {
    bool found = false;

    rchandle<UntypedAtomicItem> untypedItem = 
    static_cast<UntypedAtomicItem*>((*key)[0].getp());

    node2 = node;

    // cast to xs:string
    untypedItem->castToString(castItem);
    ADD_IN_MAP(XS_STRING, false);

    // try casting to xs:long
    if (untypedItem->castToLong(castItem))
    {
      rchandle<LongItem> longItem = static_cast<LongItem*>(castItem.getp());

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
      rchandle<DecimalItem> decimalItem = static_cast<DecimalItem*>(castItem.getp());

      ADD_IN_MAP(XS_DOUBLE, true);

      bool lossy;
      decimalItem->coerceToDouble(castItem, true, lossy);
      if (lossy)
      {
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
    store::IndexKey*& key,
    store::Item_t& node,
    IndexMap*& targetMap,
    bool multikey,
    bool untyped)
{
  GeneralIndexValue* valueSet = NULL;

  if (targetMap == NULL)
    targetMap = new IndexMap(theCompFunction, 1024, theSpec.theIsThreadSafe);

  if (targetMap->get(key, valueSet))
  {
    if (isUnique())
    {
      ZORBA_ERROR_PARAM(XDDY0024_INDEX_UNIQUE_VIOLATION,
                        theQname->getStringValue(), "");
    }
    
    valueSet->addNode(node, multikey, untyped);

    return true;
  }

  valueSet = new GeneralIndexValue();
  valueSet->addNode(node, multikey, untyped);
  
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
//  ProbeHashGeneralIndexIterator                                              //
//                                                                             //
//  Iterator to probe a general, hash-based index. The probe itself may be a   //
//  value probe or a general probe.                                            //
//                                                                             //
/////////////////////////////////////////////////////////////////////////////////


/******************************************************************************
  Create an 
********************************************************************************/
ProbeHashGeneralIndexIterator::ProbeHashGeneralIndexIterator(
    const store::Index_t& index) 
  :
  theResultSets(1)
{
  theIndex = static_cast<GeneralHashIndex*>(index.getp());
    
  theResultSets[0] = NULL;
}


#define PROBE_MAP(MAP_ID)                                                           \
{                                                                                   \
  altKey[0].transfer(castItem);                                                     \
  theResultSets.push_back(NULL);                                                    \
  theIndex->theMaps[MAP_ID]->get(&altKey, theResultSets[theResultSets.size() - 1]); \
}


/******************************************************************************
  
********************************************************************************/
void ProbeHashGeneralIndexIterator::init(const store::IndexCondition_t& cond)
{
  theProbeKind = cond->getKind();

  if (theProbeKind != store::IndexCondition::POINT_VALUE &&
      theProbeKind != store::IndexCondition::POINT_GENERAL)
  {
    ZORBA_ERROR_PARAM(STR0007_INDEX_UNSUPPORTED_PROBE_CONDITION,
                      theIndex->getName()->getStringValue().c_str(), 
                      cond->getKindString());
  }

  theCondition = reinterpret_cast<IndexPointCondition*>(cond.getp());

  store::IndexKey* key = &(theCondition->theKey);

  if (key->size() != theIndex->getNumColumns())
  {
    ZORBA_ERROR_PARAM(STR0005_INDEX_PARTIAL_KEY_PROBE,
                      theIndex->getName()->getStringValue().c_str(),
                      key->toString());
  }

  theResultSets.resize(1);
  theResultSets[0] = NULL;

  if (theIndex->isTyped())
  {
    // Note: the runtime (or compiler) makes sure that the search key is a
    // subtype of the index key type.

    theIndex->theSingleMap->get(key, theResultSets[0]);
  }
  else
  {
    bool lossy;
    store::Item_t castItem;
    store::IndexKey altKey(1);
    AtomicItem* keyItem = static_cast<AtomicItem*>((*key)[0].getp());

    if (keyItem->getBaseItem() != NULL)
    {
      keyItem = static_cast<AtomicItem*>(keyItem->getBaseItem());
      (*key)[0] = keyItem;
    }

    SchemaTypeCode keyType = keyItem->getTypeCode();

    switch (keyType)
    {
    case XS_ANY_URI:
    {
      if (theIndex->theMaps[XS_ANY_URI])
      {
        theIndex->theMaps[XS_ANY_URI]->get(key, theResultSets[0]);
      }

      if (theIndex->theMaps[XS_STRING] != NULL)
      {
        store::Item_t castItem;
        zstring tmp;
        keyItem->getStringValue2(tmp);
        GET_FACTORY().createString(castItem, tmp);

        PROBE_MAP(XS_STRING);
      }

      break;
    }

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
      if (theIndex->theMaps[keyType] != NULL)
      {
        theIndex->theMaps[keyType]->get(key, theResultSets[0]);
      }

      break;
    }

    case XS_DURATION:
    case XS_YM_DURATION:
    case XS_DT_DURATION:
    {
      if (theIndex->theMaps[XS_DURATION])
      {
        theIndex->theMaps[XS_DURATION]->get(key, theResultSets[0]);
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
      if (theIndex->theMaps[XS_STRING])
      {
        theIndex->theMaps[XS_STRING]->get(key, theResultSets[0]);
      }

      if (theIndex->theMaps[XS_ANY_URI])
      {
        store::Item_t castItem;
        zstring tmp;
        keyItem->getStringValue2(tmp);
        GET_FACTORY().createAnyURI(castItem, tmp);

        PROBE_MAP(XS_ANY_URI);
      }

      break;
    }

    case XS_DOUBLE:
    case XS_FLOAT:
    {
      if (theIndex->theMaps[XS_DOUBLE])
      {
        theIndex->theMaps[XS_DOUBLE]->get(key, theResultSets[0]);
      }

      if (theIndex->theMaps[XS_LONG] && keyItem->castToLong(castItem))
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
      keyItem->coerceToDouble(castItem, true, lossy);

      if (lossy && theIndex->theMaps[XS_DECIMAL])
      {
        theIndex->theMaps[XS_DECIMAL]->get(key, theResultSets[0]);
      }

      if (theIndex->theMaps[XS_DOUBLE])
      {
        PROBE_MAP(XS_DOUBLE);
      }

      if (theIndex->theMaps[XS_LONG] && keyItem->castToLong(castItem))
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
      if (theIndex->theMaps[XS_LONG])
      {
        theIndex->theMaps[XS_LONG]->get(key, theResultSets[0]);
      }

      if (theIndex->theMaps[XS_DOUBLE])
      {
        keyItem->coerceToDouble(castItem, true, lossy);
        PROBE_MAP(XS_DOUBLE);
      }

      break;
    }

    case XS_UNTYPED_ATOMIC:
    {
      ZORBA_ASSERT(theProbeKind == store::IndexCondition::POINT_GENERAL);

      rchandle<UntypedAtomicItem> untypedItem = static_cast<UntypedAtomicItem*>(keyItem);

      // cast to xs:string
      if (theIndex->theMaps[XS_STRING])
      {
        untypedItem->castToString(castItem); 
        PROBE_MAP(XS_STRING);
      }

      // try casting to xs:long
      if ((theIndex->theMaps[XS_LONG] ||
           theIndex->theMaps[XS_DOUBLE]) &&
          (untypedItem->castToLong(castItem), castItem != NULL))
      {
        rchandle<LongItem> longItem = static_cast<LongItem*>(castItem.getp());

        if (theIndex->theMaps[XS_LONG])
          PROBE_MAP(XS_LONG);

        if (theIndex->theMaps[XS_DOUBLE])
        {
          longItem->coerceToDouble(castItem, true, lossy);
          PROBE_MAP(XS_DOUBLE);
        }

        // may also be gYear, hexBinary, or boolean
        if (theIndex->theMaps[XS_GYEAR])
        {
          untypedItem->castToGYear(castItem);
          PROBE_MAP(XS_GYEAR);
        }

        if (theIndex->theMaps[XS_HEXBINARY])
        {
          untypedItem->castToHexBinary(castItem); 
          PROBE_MAP(XS_HEXBINARY);
        }
      }

      // try casting to xs:decimal
      else if ((theIndex->theMaps[XS_DECIMAL] ||
                theIndex->theMaps[XS_LONG] ||
                theIndex->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDecimal(castItem))
      {
        rchandle<DecimalItem> decimalItem = static_cast<DecimalItem*>(castItem.getp());

        decimalItem->coerceToDouble(castItem, true, lossy);

        if (theIndex->theMaps[XS_DOUBLE])
        {
          PROBE_MAP(XS_DOUBLE);
        }

        if (theIndex->theMaps[XS_LONG] && decimalItem->castToLong(castItem))
        {
          PROBE_MAP(XS_LONG);
        }

        if (lossy && theIndex->theMaps[XS_DECIMAL])
        {
          castItem.transfer(decimalItem);
          PROBE_MAP(XS_DOUBLE);
        }

        // may also be hexBinary
        if (theIndex->theMaps[XS_HEXBINARY])
        {
          untypedItem->castToHexBinary(castItem); 
          PROBE_MAP(XS_HEXBINARY);
        }
      }

      // try casting to xs:double
      else if ((theIndex->theMaps[XS_LONG] || theIndex->theMaps[XS_DOUBLE]) &&
               untypedItem->castToDouble(castItem))
      {
        rchandle<DoubleItem> doubleItem = static_cast<DoubleItem*>(castItem.getp());

        if (theIndex->theMaps[XS_DOUBLE])
          PROBE_MAP(XS_DOUBLE);

        if (theIndex->theMaps[XS_LONG] && doubleItem->castToLong(castItem))
        {
          PROBE_MAP(XS_LONG);
        }
      }

      // try casting to xs:datetime
      else if (theIndex->theMaps[XS_DATETIME] &&
               untypedItem->castToDateTime(castItem))
      {
        PROBE_MAP(XS_DATETIME);
      }

      // try casting to xs:date
      else if (theIndex->theMaps[XS_DATE] &&
               untypedItem->castToDate(castItem))
      {
        PROBE_MAP(XS_DATE);
      }

      // try casting to xs:time
      else if (theIndex->theMaps[XS_TIME] &&
               untypedItem->castToTime(castItem))
      {
        PROBE_MAP(XS_TIME);
      }

      // try casting to xs:gYearMonth
      else if (theIndex->theMaps[XS_GYEAR_MONTH] &&
               untypedItem->castToGYearMonth(castItem))
      {
        PROBE_MAP(XS_GYEAR_MONTH);
      }

      // try casting to xs:gMonthDay
      else if (theIndex->theMaps[XS_GMONTH_DAY] &&
               untypedItem->castToGMonthDay(castItem))
      {
        PROBE_MAP(XS_GMONTH_DAY);
      }

      // try casting to xs:gDay
      else if (theIndex->theMaps[XS_GDAY] &&
               untypedItem->castToGDay(castItem))
      {
        PROBE_MAP(XS_GDAY);
      }

      // try casting to xs:gMonth
      else if (theIndex->theMaps[XS_GMONTH] &&
               untypedItem->castToGMonth(castItem))
      {
        PROBE_MAP(XS_GMONTH);
      }
      
      // try casting to xs:duration
      else if (theIndex->theMaps[XS_DURATION] &&
               untypedItem->castToDuration(castItem))
      {
        PROBE_MAP(XS_DURATION);
      }
      
      // try casting to xs:hexBinary
      else if (theIndex->theMaps[XS_HEXBINARY] &&
               untypedItem->castToHexBinary(castItem))
      {
        PROBE_MAP(XS_HEXBINARY);
      }
      
      // try casting to xs:base64Binary
      else if (theIndex->theMaps[XS_BASE64BINARY] &&
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
void ProbeHashGeneralIndexIterator::open()
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
void ProbeHashGeneralIndexIterator::reset()
{
  open();
}


/******************************************************************************

********************************************************************************/
void ProbeHashGeneralIndexIterator::close()
{
}


/******************************************************************************
  TODO : need sync on result vector
********************************************************************************/
bool ProbeHashGeneralIndexIterator::next(store::Item_t& result)
{
  while (theResultSetsIte != theResultSetsEnd)
  {
    while (theIte != theEnd)
    {
      result = (*theIte).theNode;

      if (theProbeKind == store::IndexCondition::POINT_VALUE)
      {
        if ((*theIte).theMultiKey)
        {
          ZORBA_ERROR_DESC_OSS(XPTY0004,
                               "During a value probe on index "
                               << theIndex->getName()->getStringValue()
                               << " a node was found that has more than one key values");
        }

        if ((*theIte).theUntyped)
        {
          ++theIte;
          continue;
        }
      }

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


}
}
