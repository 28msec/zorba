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
#include "diagnostics/xquery_diagnostics.h"

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

namespace zorba {

#define RAISE_ERROR(errcode, loc, params)                     \
  throw XQUERY_EXCEPTION(errcode,                             \
                         params,                              \
                         ERROR_LOC(loc));

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
      aKeyType.getp(), TypeConstants::QUANT_ONE, loc);
  
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
            ERROR_PARAMS(*searchKeyType,
                         *indexKeyType,
                         aQName->getStringValue())
          );
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
            ERROR_PARAMS(*searchKeyType,
                         *indexKeyType,
                         aQName->getStringValue())
          );
        }
        throw;
      }
    }
  }
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
        aTypes[i].getp(), TypeConstants::QUANT_ONE, aLoc);

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
    store::Index*& aIndex)
{
  aIndex = GENV_STORE.getMap(aName);

  if (aIndex) return true;

  aIndex = aContext->getMap(aName.getp());

  if (!aIndex)
  {
    RAISE_ERROR(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( aName->getStringValue() ),
      aLoc);
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
  store::Item_t              lQName;
  std::vector<store::Item_t> lTypes;
  std::vector<zstring>       lCollations;
  std::auto_ptr<store::PUL>  lPul;
  long                       lTimezone = 0;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  if (GENV_STORE.getMap(lQName)
      || aPlanState.theLocalDynCtx->getMap(lQName.getp()))
  {
    RAISE_ERROR(
      zerr::ZSTR0001_INDEX_ALREADY_EXISTS,
      ERROR_PARAMS( lQName->getStringValue() ),
      loc
    );
  }

  lCollations.resize(theChildren.size() - 1);
  lTypes.resize(theChildren.size() - 1);

  for (size_t i = 1; i < theChildren.size(); ++i)
  {
    consumeNext(lTypes[i-1], theChildren[i].getp(), aPlanState);
  }

  checkMapTypes(lTypes, lQName, loc);

  lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
  lPul->addCreateHashMap(&loc, lQName, lTypes, lCollations, lTimezone);

  apply_updates(
      aPlanState.theCompilerCB,
      aPlanState.theGlobalDynCtx,
      theSctx,
      lPul.get(),
      loc);

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapCreateTransientIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lQName;
  store::IndexSpecification  lSpec;
  store::Index_t             lIndex;
  std::vector<std::string>   lCollations;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  if (GENV_STORE.getMap(lQName)
      || aPlanState.theLocalDynCtx->getMap(lQName.getp()))
  {
    RAISE_ERROR(
      zerr::ZSTR0001_INDEX_ALREADY_EXISTS,
      ERROR_PARAMS( lQName->getStringValue() ),
      loc
    );
  }

  lCollations.resize(theChildren.size() - 1);
  lSpec.theKeyTypes.resize(theChildren.size() - 1);

  for (size_t i = 1; i < theChildren.size(); ++i)
  {
    consumeNext(lSpec.theKeyTypes[i-1], theChildren[i].getp(), aPlanState);
  }

  checkMapTypes(lSpec.theKeyTypes, lQName, loc);

  lSpec.theNumKeyColumns = lSpec.theKeyTypes.size();
  lSpec.theIsTemp = true;
  lSpec.theCollations = lCollations;
  lSpec.theTimezone = 0;

  lIndex = GENV_STORE.createMap(lQName, lSpec);
  
  aPlanState.theLocalDynCtx->bindMap(lIndex->getName(), lIndex);

  result = NULL;

  STACK_END(state);
}


/*******************************************************************************
********************************************************************************/
bool
MapDestroyIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lQName;
  store::Index*              lIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  if (getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex))
  {
    std::auto_ptr<store::PUL> lPul(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addDestroyHashMap(&loc, lQName);

    apply_updates(
        aPlanState.theCompilerCB,
        aPlanState.theGlobalDynCtx,
        theSctx,
        lPul.get(),
        loc);
  }
  else
  {
    aPlanState.theLocalDynCtx->unbindMap(lQName.getp());
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
  store::Item_t              lQName;
  std::vector<store::Item_t> lKey;
  store::Index*              lIndex;
  ulong i;
  store::Item_t              lKeyItem;
  store::IndexSpecification  lSpec;

  MapGetIteratorState* state;
  DEFAULT_STACK_INIT(MapGetIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  lSpec = lIndex->getSpecification();

  if (lSpec.getNumColumns() != theChildren.size() - 1)
  {
    RAISE_ERROR(
      zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS,
      ERROR_PARAMS(
        lQName->getStringValue(),
        "map",
        theChildren.size() - 1,
        lSpec.getNumColumns() ),
      loc
    );
  }

  state->theCond = lIndex->createCondition(store::IndexCondition::POINT_VALUE);

  for (i = 1; i < theChildren.size(); ++i)
  {
    if (!consumeNext(lKeyItem, theChildren[i], aPlanState)) 
    {
      // Return the empty seq if any of the search key items is the empty seq.
      break;
    }

    namespace_context tmp_ctx(theSctx);
    castOrCheckIndexType(lKeyItem, lSpec.theKeyTypes[i-1], lQName, &tmp_ctx, loc);

    state->theCond->pushItem(lKeyItem);
  }

  if (i == theChildren.size())
  {
    state->theIter = GENV_STORE.getIteratorFactory()->
      createIndexProbeIterator(lIndex);

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
  store::Item_t              lQName;
  std::vector<store::Item_t> lKey;
  store::IndexSpecification  lSpec;
  store::Index*              lIndex;
  bool                       lPersistent;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  lPersistent = getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  lSpec = lIndex->getSpecification();

  if (lSpec.getNumColumns() != theChildren.size() - 2)
  {
    RAISE_ERROR(
      zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS,
      ERROR_PARAMS(
        lQName->getStringValue(),
        "map",
        theChildren.size() - 2,
        lSpec.getNumColumns() ),
      loc
    );
  }

  lKey.resize(theChildren.size() - 2);
  for (size_t i = 2; i < theChildren.size(); ++i)
  {
    if (consumeNext(lKey[i-2], theChildren[i].getp(), aPlanState))
    {
      namespace_context tmp_ctx(theSctx);
      castOrCheckIndexType(
          lKey[i-2],
          lSpec.theKeyTypes[i-2],
          lQName,
          &tmp_ctx,
          loc);
    }
  }

  if (lPersistent)
  {
    std::auto_ptr<store::PUL>  lPul;
    store::Iterator_t lValue
      = new PlanIteratorWrapper(theChildren[1], aPlanState);

    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addInsertIntoHashMap(&loc, lQName, lKey, lValue);

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
    while (consumeNext(lValue, theChildren[1], aPlanState))
    {
      std::auto_ptr<store::IndexKey> k(new store::IndexKey());
      for (std::vector<store::Item_t>::const_iterator lIter = lKey.begin();
           lIter != lKey.end();
           ++lIter)
      {
        k->push_back(*lIter);
      }

      store::IndexKey* lKeyPtr = k.get();
      if (!lIndex->insert(lKeyPtr, lValue))
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
MapRemoveIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t              lQName;
  std::vector<store::Item_t> lKey;
  store::Index*              lIndex;
  ulong i;
  store::Item_t              lKeyItem;
  std::auto_ptr<store::PUL>  lPul;
  store::IndexSpecification  lSpec;
  bool                       lPersistent;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  lPersistent = getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  lSpec = lIndex->getSpecification();

  if (lSpec.getNumColumns() != theChildren.size() - 1)
  {
    RAISE_ERROR(
      zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS,
      ERROR_PARAMS(
        lQName->getStringValue(),
        "map",
        theChildren.size() - 1,
        lSpec.getNumColumns()
      ),
      loc
    );
  }

  lKey.resize(theChildren.size()-1);
  for (i = 1; i < theChildren.size(); ++i)
  {
    if (consumeNext(lKey[i-1], theChildren[i], aPlanState)) 
    {
      namespace_context tmp_ctx(theSctx);
      castOrCheckIndexType(lKey[i-1], lSpec.theKeyTypes[i-1], lQName, &tmp_ctx, loc);
    }
  }

  if (lPersistent)
  {
    lPul.reset(GENV_ITEMFACTORY->createPendingUpdateList());
    lPul->addRemoveFromHashMap(&loc, lQName, lKey);

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
    for (std::vector<store::Item_t>::const_iterator lIter = lKey.begin();
         lIter != lKey.end();
         ++lIter)
    {
      k.push_back(*lIter);
    }
    store::Item_t lValue;
    lIndex->remove(&k, lValue, true);
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
  store::Item_t    lQName;
  store::Index*    lIndex;
  store::IndexKey  lKey;
  store::Item_t    lTypeName;
  zstring          lBaseURI =
    static_context::ZORBA_STORE_DYNAMIC_UNORDERED_MAP_FN_NS;

  store::Item_t lKeyNodeName;
  GENV_ITEMFACTORY->createQName(lKeyNodeName,
      static_context::ZORBA_STORE_DYNAMIC_UNORDERED_MAP_FN_NS,
      "", "key");

  MapKeysIteratorState* state;
  DEFAULT_STACK_INIT(MapKeysIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  state->theIter = lIndex->keys();

  state->theIter->open();

  // generate result elements of the form
  // <key>
  //   <attribute value="key1_value"/>
  //   <attribute value="key2_value"/>
  //   <attribute value="key3_value"/>
  // </key>
  while (state->theIter->next(lKey))
  {
    lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;

    GENV_ITEMFACTORY->createElementNode(
        result, NULL, lKeyNodeName, lTypeName,
        true, false, theNSBindings, lBaseURI);

    for (store::ItemVector::iterator lIter = lKey.begin();
         lIter != lKey.end();
         ++lIter)
    {
      store::Item_t lAttrElem, lAttrNodeName;
      store::Item_t lNameAttr, lValueAttr, lValueAttrName;

      GENV_ITEMFACTORY->createQName(lAttrNodeName,
          static_context::ZORBA_STORE_DYNAMIC_UNORDERED_MAP_FN_NS,
          "", "attribute");

      GENV_ITEMFACTORY->createQName(lValueAttrName,
           "", "", "value");

      lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;

      GENV_ITEMFACTORY->createElementNode(
          lAttrElem, result, lAttrNodeName, lTypeName,
          true, false, theNSBindings, lBaseURI);

      lTypeName = GENV_TYPESYSTEM.XS_UNTYPED_QNAME;
      GENV_ITEMFACTORY->createAttributeNode(
          lValueAttr, lAttrElem.getp(), lValueAttrName, lTypeName, (*lIter));
    }
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
  store::Item_t              lQName;
  store::Index*              lIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  GENV_ITEMFACTORY->createInteger(result, xs_integer(lIndex->size()));

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
  AvailableMapsIteratorState * state;
  store::Item_t              nameItem;

  DEFAULT_STACK_INIT(AvailableMapsIteratorState, state, planState);

  for ((state->persistentMapNamesIter = GENV_STORE.listMapNames())->open ();
       state->persistentMapNamesIter->next(nameItem); ) 
  {
    result = nameItem;
    STACK_PUSH( true, state);
  }

  state->persistentMapNamesIter->close();

  planState.theLocalDynCtx->getMapNames(state->transientMapNames);

  for (state->transientMapNamesIter = state->transientMapNames.begin();
       state->transientMapNamesIter != state->transientMapNames.end();
       ++state->transientMapNamesIter)
  {
    result = *state->transientMapNamesIter;
    STACK_PUSH( true, state);
  }

  STACK_END (state);
}


/*******************************************************************************
********************************************************************************/
bool
MapIsTransientIterator::nextImpl(
    store::Item_t& result,
    PlanState& aPlanState) const
{
  store::Item_t lQName;
  store::Index* lIndex;
  bool          lPersistent;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, aPlanState);

  consumeNext(lQName, theChildren[0].getp(), aPlanState);

  lPersistent = getMap(lQName, loc, aPlanState.theLocalDynCtx, lIndex);

  GENV_ITEMFACTORY->createBoolean(result, !lPersistent);

  STACK_PUSH(true, state);

  STACK_END(state);
}


} // namespace zorba
/* vim:set et sw=2 ts=2: */
