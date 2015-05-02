/*
 * Copyright 2006-2012 The FLWOR Foundation.
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

#include "diagnostics/assert.h"
#include "diagnostics/util_macros.h"
#include "diagnostics/xquery_diagnostics.h"

#include "zorbatypes/integer.h"
#include "zorbatypes/URI.h"

#include "system/globalenv.h"

#include "runtime/store/maps.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"
#include "context/namespace_context.h"

#include "store/api/pul.h"
#include "store/api/store.h"
#include "store/api/item.h"
#include "store/api/item_factory.h"
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/iterator.h"
#include "store/api/index.h"

#include "runtime/core/apply_updates.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"

#include <zorba/internal/unique_ptr.h>

namespace zorba {

/*******************************************************************************
********************************************************************************/
zstring
getMapURI(
    const static_context* sctx,
    const QueryLoc& aLoc)
{
  return "http://zorba.io/maps";
}

/*******************************************************************************
********************************************************************************/
void
createMapQName(
    store::Item_t& name,
    const static_context* sctx,
    const QueryLoc& loc)
{
  GENV_ITEMFACTORY->createQName(name, getMapURI(sctx, loc),
      "", name->getStringValue()); 
}


/*******************************************************************************
********************************************************************************/
void
castOrCheckIndexType(
    store::Item_t& aKeyItem,
    const store::Item_t& aKeyType,
    const store::Item_t& aQName,
    namespace_context* aNCtx,
    const QueryLoc& loc)
{
  xqtref_t searchKeyType = GENV_TYPESYSTEM.create_value_type(aKeyItem);
  xqtref_t indexKeyType  = GENV_TYPESYSTEM.create_named_type(
      aKeyType.getp(), SequenceType::QUANT_ONE, loc);
  
  if ( indexKeyType != NULL )
  {
    if ( !TypeOps::is_subtype(&GENV_TYPESYSTEM, *searchKeyType, *indexKeyType))
    {
      store::Item_t lResult;
      try
      {
        if ( !GenericCast::castToAtomic(
              lResult,
              aKeyItem,
              indexKeyType.getp(),
              &GENV_TYPESYSTEM,
              aNCtx,
              loc ) )
        {
          RAISE_ERROR(zerr::ZXQD0005_INVALID_KEY_FOR_MAP, loc,
          ERROR_PARAMS(*searchKeyType, *indexKeyType, aQName->getStringValue()));
        }
        else
        {
          aKeyItem = lResult;
        }
      } catch (const ZorbaException& e)
      {
        if ( e.diagnostic() == err::FORG0001 )
        {
          RAISE_ERROR(zerr::ZXQD0005_INVALID_KEY_FOR_MAP, loc,
          ERROR_PARAMS(*searchKeyType, *indexKeyType, aQName->getStringValue()));
        }
        throw;
      }
    }
  }
}


/*******************************************************************************
********************************************************************************/
void
createKeysArray(
    store::IndexKey& aKey,
    store::Item_t& aArray)
{
  std::vector<store::Item_t> lValues;
  lValues.reserve(aKey.size());

  size_t i = 1;

  // build [ key1, null, key3 ]
  for (store::ItemVector::iterator lIter = aKey.begin();
       lIter != aKey.end();
       ++lIter, ++i)
  {
    lValues.resize(i);

    store::Item_t lValue = *lIter;
    if (lValue)
    {
      lValues[i - 1] = (*lIter);
    }
    else
    {
      GENV_ITEMFACTORY->createJSONNull(lValues[i - 1]);
    }
  }

  GENV_ITEMFACTORY->createJSONArray(aArray, lValues);
}


/*******************************************************************************
********************************************************************************/
void
processTypes(
    const store::Item_t& aMapName,
    const QueryLoc& loc,
    std::vector<store::Item_t>& aTypes)
{
  for (size_t i = 0; i < aTypes.size(); ++i)
  {
    store::Item_t& lType = aTypes[i];

    if (!lType->isAtomic())
    {
      RAISE_ERROR(zerr::ZXQD0005_INVALID_KEY_FOR_MAP, loc,
          ERROR_PARAMS(*(GENV_TYPESYSTEM.create_value_type(lType)),
          "anyAtomicType",
          aMapName->getStringValue()));
    }

    if (TypeOps::is_subtype(lType->getTypeCode(), store::XS_STRING))
    {
      zstring t = lType->getStringValue();
      std::transform(t.begin(), t.end(), t.begin(), zorba::unicode::to_lower);
      if (t == "string")
        lType = GENV_TYPESYSTEM.XS_STRING_QNAME;
      else if (t == "integer")
        lType = GENV_TYPESYSTEM.XS_INTEGER_QNAME;
      else if (t == "boolean")
        lType = GENV_TYPESYSTEM.XS_BOOLEAN_QNAME;
      else if (t == "datetime")
        lType = GENV_TYPESYSTEM.XS_DATETIME_QNAME;
      else if (t == "date")
        lType = GENV_TYPESYSTEM.XS_DATE_QNAME;
      else if (t == "time")
        lType = GENV_TYPESYSTEM.XS_TIME_QNAME;
      else if (t == "duration")
        lType = GENV_TYPESYSTEM.XS_DURATION_QNAME;
      else if (t == "daytimeduration")
        lType = GENV_TYPESYSTEM.XS_DT_DURATION_QNAME;
      else if (t == "yearmonthduration")
        lType = GENV_TYPESYSTEM.XS_YM_DURATION_QNAME;
      else if (t == "float")
        lType = GENV_TYPESYSTEM.XS_FLOAT_QNAME;
      else if (t == "double")
        lType = GENV_TYPESYSTEM.XS_DOUBLE_QNAME;
      else if (t == "decimal")
        lType = GENV_TYPESYSTEM.XS_DECIMAL_QNAME;
      else if (t == "long")
        lType = GENV_TYPESYSTEM.XS_LONG_QNAME;
      else if (t == "int")
        lType = GENV_TYPESYSTEM.XS_INT_QNAME;
      else if (t == "short")
        lType = GENV_TYPESYSTEM.XS_SHORT_QNAME;
      else if (t == "byte")
        lType = GENV_TYPESYSTEM.XS_BYTE_QNAME;
      else if (t == "base64binary")
        lType = GENV_TYPESYSTEM.XS_BASE64BINARY_QNAME;
      else if (t == "hexbinary")
        lType = GENV_TYPESYSTEM.XS_HEXBINARY_QNAME;
      else if (t == "null")
        lType = GENV_TYPESYSTEM.JS_NULL_QNAME;
      else
        RAISE_ERROR(zerr::ZXQD0005_INVALID_KEY_FOR_MAP, loc,
            ERROR_PARAMS(t,
            "anyAtomicType",
            aMapName->getStringValue()));
    }
    else if (!TypeOps::is_subtype(lType->getTypeCode(), store::XS_QNAME))
    {
      RAISE_ERROR(zerr::ZXQD0005_INVALID_KEY_FOR_MAP, loc,
          ERROR_PARAMS(*(GENV_TYPESYSTEM.create_value_type(lType)),
          "QName",
          aMapName->getStringValue()));
    }
  }
}

/*******************************************************************************
********************************************************************************/
bool
prepareKeyAttributes(
    const QueryLoc& loc,
    const static_context* sctx,
    const store::Item_t& aKey,
    store::Index* aMap,
    std::vector<store::Item_t>& aKeyAttrs)
{
  if (aKey->isArray())
  {
    ulong lNumKeys = static_cast<ulong>(to_xs_long(aKey->getArraySize()));
    aKeyAttrs.resize(lNumKeys);
    for (size_t i = 0; i < lNumKeys; ++i)
    {
      aKeyAttrs[i] = aKey->getArrayValue(xs_integer(i+1));
    }
  }
  else
  {
    aKeyAttrs.push_back(aKey);
  }

  const store::IndexSpecification& lSpec = aMap->getSpecification();

  store::Item_t lName = aMap->getName();

  if (lSpec.getNumColumns() != aKeyAttrs.size())
  {
    RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
    ERROR_PARAMS(lName->getLocalName(),
                 "map",
                 aKeyAttrs.size(),
                 lSpec.getNumColumns()));
  }

  bool lValidProbe = true;

  for (size_t i = 0; i < aKeyAttrs.size(); ++i)
  {
    store::Item_t& lTmp = aKeyAttrs[i];

    if (! lTmp->isAtomic())
    {
      store::Item_t lVal;
      store::Iterator_t lValIter;
      lTmp->getTypedValue(lVal, lValIter);
      if (! lValIter.isNull())
      {
        RAISE_ERROR(err::XPTY0004, loc,
        ERROR_PARAMS(ZED(XPTY0004_NoMultiSeqTypePromotion_2),
                     lSpec.theKeyTypes.at(i)));
      }
      lTmp = lVal;
    }

    namespace_context tmp_ctx(sctx);
    castOrCheckIndexType(lTmp, lSpec.theKeyTypes[i], lName, &tmp_ctx, loc);

    if (lTmp == NULL ||
        (lTmp->isAtomic() && lTmp->getTypeCode() == store::JS_NULL))
    {
      lValidProbe = false;
    }
  }
  return lValidProbe;
}


/*******************************************************************************
********************************************************************************/
void
processOption(
    const QueryLoc& loc,
    const store::Item_t& aOption,
    bool& aIsPersistent)
{
  assert(aOption->isObject());
  zstring lTmp("persistent");

  store::Item_t lPersistentItem;
  GENV_ITEMFACTORY->createString(lPersistentItem, lTmp);

  lPersistentItem = aOption->getObjectValue(lPersistentItem);
  if (!lPersistentItem->isAtomic()
      || lPersistentItem->getTypeCode() != store::XS_BOOLEAN)
  {
    RAISE_ERROR(zerr::ZDDY0043_INVALID_OPTION_TYPE,
      loc, ERROR_PARAMS(
        lPersistentItem->getType()->getLocalName(), "persistent", "boolean"));
  }
  aIsPersistent = lPersistentItem->getBooleanValue();
}


/*******************************************************************************
********************************************************************************/
void
checkMapTypes(
    std::vector<store::Item_t>& aTypes,
    const store::Item_t& aMapName,
    const QueryLoc& aLoc)
{
  xqtref_t                   lAnyAtomicType, lIndexKeyType;

  for (size_t i = 0; i < aTypes.size(); ++i)
  {
    lAnyAtomicType = GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE;
    lIndexKeyType  = GENV_TYPESYSTEM.create_named_type(
        aTypes[i].getp(), SequenceType::QUANT_ONE, aLoc);

    if (lIndexKeyType != NULL &&
        !TypeOps::is_subtype(&GENV_TYPESYSTEM,
          *lIndexKeyType, *lAnyAtomicType))
    {
      RAISE_ERROR(err::XPTY0004, aLoc,
        ERROR_PARAMS(ZED(SearchKeyTypeMismatch_234),
                     *lAnyAtomicType,
                     aMapName->getStringValue(),
                     *lIndexKeyType)
      );
    }
  }
}


/*******************************************************************************
********************************************************************************/
bool
getMap(
    const store::Item_t& aName,
    const QueryLoc& aLoc,
    dynamic_context* aContext,
    store::Index*& aIndex,
    bool aLookupParent = true)
{
  aIndex = GENV_STORE.getMap(aName);

  if (aIndex) return true;

  aIndex = aContext->getMap(aName.getp(), aLookupParent);

  if (!aIndex)
  {
    RAISE_ERROR(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      aLoc,
      ERROR_PARAMS( aName->getStringValue() )
    );
  }

  return false;
}

    

/*******************************************************************************
********************************************************************************/
bool
MapCreateIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Item_t              lTypeParam;
  std::vector<store::Item_t> lTypes;
  bool                       lPersistent = true;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  if (GENV_STORE.getMap(lName)
      || aPlanState.theLocalDynCtx->getMap(lName.getp()))
  {
    RAISE_ERROR(
      zerr::ZSTR0001_INDEX_ALREADY_EXISTS,
      loc,
      ERROR_PARAMS( lName->getStringValue() )
    );
  }

  consumeNext(lTypeParam, theChildren[1].getp(), aPlanState);

  if (lTypeParam->isArray())
  {
    long lSize = static_cast<long>(to_xs_long(lTypeParam->getArraySize()));
    lTypes.resize(lSize);
    for (long i = 1; i <= lSize; ++i)
    {
      lTypes[i-1] = lTypeParam->getArrayValue(xs_integer(i));
    }
  }
  else
  {
    lTypes.push_back(lTypeParam);
  }

  if (theChildren.size() == 3)
  {
    store::Item_t lOptions;
    consumeNext(lOptions, theChildren[2].getp(), aPlanState);
    processOption(loc, lOptions, lPersistent);
  }

  processTypes(lName, loc, lTypes);
  checkMapTypes(lTypes, lName, loc);

  if (lPersistent)
  {
    std::unique_ptr<store::PUL> lPul(GENV_ITEMFACTORY->createPendingUpdateList());
    std::vector<zstring>       lCollations(lTypes.size());
    lPul->addCreateHashMap(&loc, lName, lTypes, lCollations, 0);

    apply_updates(
        aPlanState.theCompilerCB,
        aPlanState.theGlobalDynCtx,
        theSctx,
        lPul.get(),
        loc);
  }
  else
  {
    store::IndexSpecification lSpec;
    lSpec.theKeyTypes.swap(lTypes);
    lSpec.theNumKeyColumns = lSpec.theKeyTypes.size();
    lSpec.theIsTemp = true;
    lSpec.theCollations.resize(lSpec.theKeyTypes.size());
    lSpec.theTimezone = 0;
    store::Index_t lMap = GENV_STORE.createMap(lName, lSpec);

    aPlanState.theLocalDynCtx->bindMap(lMap->getName(), lMap);
  }

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapDropIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Index*              lIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  if (getMap(lName, loc, aPlanState.theLocalDynCtx, lIndex, false))
  {
    std::unique_ptr<store::PUL> lPul(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addDestroyHashMap(&loc, lName);

    apply_updates(
        aPlanState.theCompilerCB,
        aPlanState.theGlobalDynCtx,
        theSctx,
        lPul.get(),
        loc);
  }
  else
  {
    aPlanState.theLocalDynCtx->unbindMap(lName.getp());
  }

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapGetIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Item_t              lKey;
  std::vector<store::Item_t> lKeyAttrs;
  store::Index*              lMap;
  store::IndexSpecification  lSpec;
  bool                       lValidProbe;

  MapGetIteratorState* state;
  DEFAULT_STACK_INIT(MapGetIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  getMap(lName, loc, aPlanState.theLocalDynCtx, lMap);

  consumeNext(lKey, theChildren[1].getp(), aPlanState);

  state->theCond = lMap->createCondition(store::IndexCondition::POINT_VALUE);
  lValidProbe = prepareKeyAttributes(loc, theSctx, lKey, lMap, lKeyAttrs);

  if (lValidProbe)
  {
    for (size_t i = 0; i < lKeyAttrs.size(); ++i)
    {
      state->theCond->pushItem(lKeyAttrs[i]);
    }

    state->theIter = GENV_STORE.getIteratorFactory()->
      createIndexProbeIterator(lMap);

    state->theIter->init(state->theCond);
    state->theIter->open();
    
    while (state->theIter->next(result))
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapInsertIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Item_t              lKey;
  std::vector<store::Item_t> lKeyAttrs;
  store::Index*              lMap;
  bool                       lPersistent;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  lPersistent = getMap(lName, loc, aPlanState.theLocalDynCtx, lMap);

  consumeNext(lKey, theChildren[1].getp(), aPlanState);

  prepareKeyAttributes(loc, theSctx, lKey, lMap, lKeyAttrs);

  if (lPersistent)
  {
    store::Iterator_t lValue
      = new PlanIteratorWrapper(theChildren[2], aPlanState);

    std::unique_ptr<store::PUL> lPul(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addInsertIntoHashMap(&loc, lName, lKeyAttrs, lValue);

    apply_updates(
        aPlanState.theCompilerCB,
        aPlanState.theGlobalDynCtx,
        theSctx,
        lPul.get(),
        loc);
  }
  else
  {
    store::Item_t lValue;
    while (consumeNext(lValue, theChildren[2], aPlanState))
    {
      if ((lValue->isNode() || lValue->isArray() || lValue->isObject())
          && lValue->getCollection() == 0)
      {
        zstring lType = "node";
        if (lValue->isArray()) lType = "array";
        else if (lValue->isObject()) lType = "object";

        RAISE_ERROR(zerr::ZDDY0042_ITEM_NOT_IN_COLLECTION, loc,
        ERROR_PARAMS(lName->getLocalName(), lType));
      }

      std::unique_ptr<store::IndexKey> k(new store::IndexKey());
      for (size_t i = 0; i < lKeyAttrs.size(); ++i)
      {
        k->push_back(lKeyAttrs[i]);
      }

      store::IndexKey* lKeyPtr = k.get();
      if (!lMap->insert(lKeyPtr, lValue))
      {
        // the index took the ownership over the key if the index
        // did _not_ already contain an entry with the same key
        k.release();
      }
    }
  }

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapDeleteIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Item_t              lKey;
  std::vector<store::Item_t> lKeyAttrs;
  store::Index*              lMap;
  bool                       lPersistent;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  lPersistent = getMap(lName, loc, aPlanState.theLocalDynCtx, lMap);

  consumeNext(lKey, theChildren[1].getp(), aPlanState);

  prepareKeyAttributes(loc, theSctx, lKey, lMap, lKeyAttrs);

  if (lPersistent)
  {
    std::unique_ptr<store::PUL> lPul(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addRemoveFromHashMap(&loc, lName, lKeyAttrs);

    apply_updates(
        aPlanState.theCompilerCB,
        aPlanState.theGlobalDynCtx,
        theSctx,
        lPul.get(),
        loc);
  }
  else
  {
    store::IndexKey k;
    for (size_t i = 0; i < lKeyAttrs.size(); ++i)
    {
      k.push_back(lKeyAttrs[i]);
    }
    store::Item_t lValue;
    lMap->remove(&k, lValue, true);
  }

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapKeysIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t    lName;
  store::Index*    lIndex;
  store::IndexKey  lKey;
  store::Item_t    lTypeName;

  MapKeysIteratorState* state;
  DEFAULT_STACK_INIT(MapKeysIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  getMap(lName, loc, aPlanState.theLocalDynCtx, lIndex);

  state->theIter = lIndex->keys();

  state->theIter->open();

  while (state->theIter->next(lKey))
  {
    createKeysArray(lKey, result);

    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapSizeIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t lName;
  store::Index* lMap;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  getMap(lName, loc, aPlanState.theLocalDynCtx, lMap);

  GENV_ITEMFACTORY->createInteger(result, xs_integer(lMap->size()));

  STACK_PUSH(true, state);

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
AvailableMapsIteratorState::~AvailableMapsIteratorState()
{
  if ( persistentMapNamesIter != NULL ) 
  {
    persistentMapNamesIter->close();
    persistentMapNamesIter = NULL;
  }
  transientMapNames.clear();
}


void AvailableMapsIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);
  persistentMapNamesIter = NULL;
}


void AvailableMapsIteratorState::reset(PlanState& planState)
{
  PlanIteratorState::reset(planState);
  if ( persistentMapNamesIter != NULL ) {
    persistentMapNamesIter->close();
    persistentMapNamesIter = NULL;
  }
  transientMapNames.clear();
}


bool
AvailableMapsIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t lNameItem;;
  zstring       lLocalName;

  AvailableMapsIteratorState * state;
  DEFAULT_STACK_INIT(AvailableMapsIteratorState, state, planState);

  for ((state->persistentMapNamesIter = GENV_STORE.listMapNames())->open ();
       state->persistentMapNamesIter->next(lNameItem); ) 
  {
    if (lNameItem->getNamespace() != getMapURI(theSctx, loc))
    {
      continue;
    }
    lLocalName = lNameItem->getLocalName();
    GENV_ITEMFACTORY->createString(result, lLocalName);
    STACK_PUSH(true, state);
  }

  state->persistentMapNamesIter->close();

  planState.theLocalDynCtx->getMapNames(state->transientMapNames);

  for (state->transientMapNamesIter = state->transientMapNames.begin();
       state->transientMapNamesIter != state->transientMapNames.end();
       ++state->transientMapNamesIter)
  {
    lNameItem = *state->transientMapNamesIter;
    if (lNameItem->getNamespace() != getMapURI(theSctx, loc))
    {
      continue;
    }
    lLocalName = lNameItem->getLocalName();
    GENV_ITEMFACTORY->createString(result, lLocalName);
    STACK_PUSH( true, state);
  }

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
MapOptionsIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lName;
  store::Index*              lMap;
  bool                       lPersistent;
  std::vector<store::Item_t> lNames(1);
  std::vector<store::Item_t> lValues(1);
  zstring lTmp("persistent");

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lName, theChildren[0].getp(), aPlanState);
  createMapQName(lName, theSctx, loc);

  lPersistent = getMap(lName, loc, aPlanState.theLocalDynCtx, lMap);

  GENV_ITEMFACTORY->createString(lNames[0], lTmp);
  GENV_ITEMFACTORY->createBoolean(lValues[0], lPersistent);

  GENV_ITEMFACTORY->createJSONObject(result, lNames, lValues);

  STACK_PUSH(true, state);

  STACK_END(state);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
