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

#include "runtime/visitors/planiter_visitor.h"
#include "runtime/indexing/index_ddl.h"
#include "runtime/api/plan_wrapper.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "system/globalenv.h"

#include "store/api/iterator.h"
#include "store/api/store.h"        // for checking if index exists
#include "store/api/item_factory.h" // for creating pul
#include "store/api/iterator_factory.h" // for creating the probe iterator
#include "store/api/pul.h"
#include "store/api/index.h"

#include "compiler/xqddf/value_index.h"

#include "types/typeimpl.h"
#include "types/typeops.h"
#include "types/casting.h"
#include "zorbatypes/decimal.h"
#include "zorbatypes/integer.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "zorbautils/hashset_structured_itemh.h"

#include "diagnostics/xquery_exception.h"
#include "diagnostics/util_macros.h"

namespace zorba {


SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)
DEF_GET_NAME_AS_STRING(CreateInternalIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(CreateIndexIterator)
DEF_GET_NAME_AS_STRING(CreateIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(DeleteIndexIterator)
DEF_GET_NAME_AS_STRING(DeleteIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(RefreshIndexIterator)
DEF_GET_NAME_AS_STRING(RefreshIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(ValueIndexEntryBuilderIterator)
DEF_GET_NAME_AS_STRING(ValueIndexEntryBuilderIterator)

SERIALIZABLE_CLASS_VERSIONS(GeneralIndexEntryBuilderIterator)
DEF_GET_NAME_AS_STRING(GeneralIndexEntryBuilderIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointValueIterator)
DEF_GET_NAME_AS_STRING(ProbeIndexPointValueIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointGeneralIterator)
DEF_GET_NAME_AS_STRING(ProbeIndexPointGeneralIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeValueIterator)
DEF_GET_NAME_AS_STRING(ProbeIndexRangeValueIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeGeneralIterator)
DEF_GET_NAME_AS_STRING(ProbeIndexRangeGeneralIterator)


/*******************************************************************************
  This function is called from the probe function to chaeck that the type of
  the probing key is consistent with the index declaration.
********************************************************************************/
static void checkKeyType(
    const QueryLoc& loc,
    TypeManager* tm,
    const IndexDecl* indexDecl,
    csize keyNo,
    store::Item_t& searchKey)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t searchKeyType = tm->create_value_type(searchKey);
  xqtref_t indexKeyType = (indexDecl->getKeyTypes())[keyNo];

  if (indexKeyType == NULL)
  {
    ZORBA_ASSERT(indexDecl->isGeneral());

    if (TypeOps::is_equal(tm, *searchKeyType, *rtm.ANY_ATOMIC_TYPE_ONE) ||
        (indexDecl->isOrdered() &&
         (TypeOps::is_subtype(tm, *searchKeyType, *rtm.QNAME_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.NOTATION_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.BASE64BINARY_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.HEXBINARY_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.GYEAR_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.GYEAR_MONTH_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.GMONTH_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.GMONTH_DAY_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.GDAY_TYPE_ONE))))
    {
      RAISE_ERROR(err::XPTY0004, loc,
      ERROR_PARAMS(ZED(SearchKeyTypeNoProbeIndex_23),
                   *searchKeyType,
                   indexDecl->getName()->getStringValue()));
    }
  }
  else if (!TypeOps::is_subtype(tm, *searchKeyType, *indexKeyType))
  {
    store::SchemaTypeCode searchKeyTypeCode = searchKey->getTypeCode();

    if (TypeOps::is_subtype(tm, *indexKeyType, *rtm.STRING_TYPE_ONE) &&
        (searchKeyTypeCode == store::XS_UNTYPED_ATOMIC ||
         searchKeyTypeCode == store::XS_ANY_URI))
    {
      return;
    }

    if (TypeOps::is_subtype(tm, *indexKeyType, *rtm.DOUBLE_TYPE_ONE))
    {
      if (TypeOps::is_subtype(searchKeyTypeCode, store::XS_DECIMAL))
      {
        GENV_STORE.getItemFactory()->
        createDouble(searchKey, xs_double(searchKey->getDecimalValue()));
      }
      else if (TypeOps::is_subtype(searchKeyTypeCode, store::XS_FLOAT))
      {
        GENV_STORE.getItemFactory()->
        createDouble(searchKey, xs_double(searchKey->getFloatValue()));
      }

      return;
    }

    if (TypeOps::is_subtype(tm, *indexKeyType, *rtm.FLOAT_TYPE_ONE) &&
        TypeOps::is_subtype(searchKeyTypeCode, store::XS_DECIMAL))
    {
      GENV_STORE.getItemFactory()->
      createDouble(searchKey, xs_float(searchKey->getDecimalValue()));

      return;
    }

    RAISE_ERROR(err::XPTY0004, loc,
    ERROR_PARAMS(ZED(SearchKeyTypeMismatch_234),
                 *searchKeyType,
                 indexDecl->getName()->getStringValue(),
                 *indexKeyType));
  }
}


/*******************************************************************************

********************************************************************************/
static void createIndexSpec(
    IndexDecl* indexDecl,
    long timezone,
    store::IndexSpecification& spec)
{
  const std::vector<xqtref_t>& keyTypes(indexDecl->getKeyTypes());
  const std::vector<OrderModifier>& keyModifiers(indexDecl->getOrderModifiers());
  csize numColumns = keyTypes.size();

  spec.resize(numColumns);

  for (csize i = 0; i < numColumns; ++i) 
  {
    if (keyTypes[i] != NULL)
    {
      const XQType& t = *keyTypes[i];
      spec.theKeyTypes[i] = t.getQName();
    }
    spec.theCollations.push_back(keyModifiers[i].theCollation);
  }

  spec.theIsGeneral = indexDecl->isGeneral();
  spec.theIsUnique = indexDecl->getUnique();
  spec.theIsSorted = indexDecl->getMethod() == IndexDecl::TREE;
  spec.theIsTemp = indexDecl->isTemp();
  spec.theIsThreadSafe = true;
  spec.theIsAutomatic = indexDecl->getMaintenanceMode() != IndexDecl::MANUAL;
  spec.theTimezone = timezone;

  csize numSources = indexDecl->numSources();

  spec.theSources.resize(numSources);

  for (csize i = 0; i < numSources; ++i)
  {
    spec.theSources[i] = const_cast<store::Item*>(indexDecl->getSourceName(i));
  }
}


/*******************************************************************************
  CreateInternalIndexIterator
********************************************************************************/

CreateInternalIndexIterator::~CreateInternalIndexIterator() 
{
}


bool CreateInternalIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  IndexDecl* indexDecl;
  store::IndexSpecification spec;
  store::Iterator_t planIteratorWrapper;
  store::Index_t storeIndex;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  indexDecl = theSctx->lookup_index(theQName);
  ZORBA_ASSERT(indexDecl);

  planIteratorWrapper = new PlanIteratorWrapper(theChild, planState);

  createIndexSpec(indexDecl, planState.theLocalDynCtx->get_implicit_timezone(), spec);

  try
  {
    storeIndex = GENV_STORE.createIndex(indexDecl->getName(), spec, planIteratorWrapper);
  }
  catch(XQueryException& e)
  {
    // Store raises error if index exists already
    set_source( e, loc );
    throw;
  }

  if (planState.theLocalDynCtx->getIndex(indexDecl->getName()))
    planState.theLocalDynCtx->unbindIndex(indexDecl->getName());

  planState.theLocalDynCtx->bindIndex(indexDecl->getName(), storeIndex);

  STACK_END(state);
}


void CreateInternalIndexIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}


/*******************************************************************************
  CreateIndexIterator
********************************************************************************/

CreateIndexIterator::~CreateIndexIterator() 
{
}


bool CreateIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;
  IndexDecl_t indexDecl;
  store::IndexSpecification spec;
  PlanIter_t buildPlan;
  store::Iterator_t planWrapper;

  CompilerCB* ccb = planState.theCompilerCB;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
  {
    RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
    ERROR_PARAMS(qname->getStringValue()));
  }

  if (GENV_STORE.getIndex(qname) != NULL)
  {
    RAISE_ERROR(zerr::ZDDY0022_INDEX_ALREADY_EXISTS, loc,
    ERROR_PARAMS(qname->getStringValue()));
  }

  buildPlan = indexDecl->getBuildPlan(loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, NULL, NULL, 0, false, 0); 

  createIndexSpec(indexDecl, planState.theLocalDynCtx->get_implicit_timezone(), spec);

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->
  addCreateIndex(&loc, qname, spec, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void CreateIndexIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}


/*******************************************************************************
  DeleteIndexIterator
********************************************************************************/

DeleteIndexIterator::~DeleteIndexIterator() 
{
}


bool DeleteIndexIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t qname;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if (theSctx->lookup_index(qname) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0021_INDEX_NOT_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addDeleteIndex(&loc, qname);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void DeleteIndexIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}



/*******************************************************************************
  RefreshIndexIterator
********************************************************************************/

RefreshIndexIterator::~RefreshIndexIterator() 
{
}


bool RefreshIndexIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t qname;
  IndexDecl_t indexDecl;
  PlanIter_t buildPlan;
  store::Iterator_t planWrapper;

  dynamic_context* dctx = planState.theGlobalDynCtx;
  CompilerCB* ccb = planState.theCompilerCB;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  if (!consumeNext(qname, theChild, planState))
    ZORBA_ASSERT(false);

  if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0021_INDEX_NOT_DECLARED,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    throw XQUERY_EXCEPTION(
      zerr::ZDDY0023_INDEX_DOES_NOT_EXIST,
      ERROR_PARAMS( qname->getStringValue() ),
      ERROR_LOC( loc )
    );
  }

  buildPlan = indexDecl->getBuildPlan(loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, dctx, NULL, 0, false, 0); 

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addRefreshIndex(&loc, qname, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void RefreshIndexIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  theChild->accept(v);

  v.endVisit(*this);
}



/*******************************************************************************
  ValueIndexEntryBuilderIterator
********************************************************************************/

ValueIndexEntryBuilderIteratorState::ValueIndexEntryBuilderIteratorState() 
{
}


ValueIndexEntryBuilderIteratorState::~ValueIndexEntryBuilderIteratorState() 
{
}


void ValueIndexEntryBuilderIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurChild = 0;
}


void ValueIndexEntryBuilderIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theCurChild = 0;
}


ValueIndexEntryBuilderIterator::~ValueIndexEntryBuilderIterator() 
{
}


bool ValueIndexEntryBuilderIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  ValueIndexEntryBuilderIteratorState* state;
  DEFAULT_STACK_INIT(ValueIndexEntryBuilderIteratorState, state, planState);

  for (; state->theCurChild < theChildren.size(); ++state->theCurChild) 
  {
    if (!consumeNext(result, theChildren[state->theCurChild].getp(), planState))
      result = NULL;

    STACK_PUSH(true, state);
  }
  
  STACK_END(state);
}


NARY_ACCEPT(ValueIndexEntryBuilderIterator)


/*******************************************************************************
  GeneralIndexEntryBuilderIterator
********************************************************************************/

GeneralIndexEntryBuilderIterator::GeneralIndexEntryBuilderIterator(
    static_context* sctx,
    const QueryLoc& loc,
    PlanIter_t& child0,
    PlanIter_t& child1)
  : 
  BinaryBaseIterator<GeneralIndexEntryBuilderIterator,
                     PlanIteratorState>(sctx, loc, child0, child1)
{
}


GeneralIndexEntryBuilderIterator::~GeneralIndexEntryBuilderIterator() 
{
}


void GeneralIndexEntryBuilderIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (BinaryBaseIterator<GeneralIndexEntryBuilderIterator,
                      PlanIteratorState>*)this);
}


bool GeneralIndexEntryBuilderIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  consumeNext(result, theChild0.getp(), planState);
  ZORBA_ASSERT(result);

  STACK_PUSH(true, state);

  while (consumeNext(result, theChild1.getp(), planState))
  {
    STACK_PUSH(true, state);
  }
  
  STACK_END(state);
}


BINARY_ACCEPT(GeneralIndexEntryBuilderIterator)


/*******************************************************************************
  probe-index-point-value($indexName as xs:QName,
                          $key1      as anyAtomic?,
                          ...,
                          $keyN      as anyAtomic?) as node()*
********************************************************************************/

ProbeIndexPointValueIteratorState::ProbeIndexPointValueIteratorState() 
{
}


ProbeIndexPointValueIteratorState::~ProbeIndexPointValueIteratorState() 
{
}


void ProbeIndexPointValueIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theQname = 0;
  theIndexDecl = 0;
  theIndex = 0;
  theIterator = NULL;
}


void ProbeIndexPointValueIteratorState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) 
  {
    theIterator->close();
  }

  theQname = 0;
  theIndexDecl = 0;
  theIndex = 0;
  theIterator = NULL;
}


ProbeIndexPointValueIterator::ProbeIndexPointValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool skip)
  : 
  NaryBaseIterator<ProbeIndexPointValueIterator,
                   ProbeIndexPointValueIteratorState>(sctx, loc, children),
  theCheckKeyType(true),
  theSkip(skip)
{
}


ProbeIndexPointValueIterator::~ProbeIndexPointValueIterator() 
{
}

void ProbeIndexPointValueIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ProbeIndexPointValueIterator,
                    ProbeIndexPointValueIteratorState>*)this);

  ar & theCheckKeyType;
  ar & theSkip;
}


bool ProbeIndexPointValueIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::IndexCondition_t cond;
  xs_integer skip( numeric_consts<xs_integer>::zero() );

  try
  {
    ProbeIndexPointValueIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexPointValueIteratorState, state, planState);

    getIndex(state, planState);

    cond = createCondition(state, planState);

    if (cond)
    {
      if (theSkip)
      {
        store::Item_t skipItem;
        ZORBA_ASSERT(consumeNext(skipItem, theChildren[1], planState));
        skip = skipItem->getIntegerValue();
        if (skip.sign() < 0)
          skip = numeric_consts<xs_integer>::zero();
      }

      state->theIterator->init(cond, skip);
      state->theIterator->open();
        
      while(state->theIterator->next(result)) 
      {
        STACK_PUSH(true, state);
      }
    }
    
    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


bool ProbeIndexPointValueIterator::countImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::IndexCondition_t cond;
  xs_integer skip(0);

  try
  {
    ProbeIndexPointValueIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexPointValueIteratorState, state, planState);

    getIndex(state, planState);

    cond = createCondition(state, planState);

    if (cond)
    {
      if (theSkip)
      {
        store::Item_t skipItem;
        ZORBA_ASSERT(consumeNext(skipItem, theChildren[1], planState));
        skip = skipItem->getIntegerValue();
        if (skip.sign() < 0)
          skip = numeric_consts<xs_integer>::zero();
      }

      state->theIterator->init(cond, skip);
      state->theIterator->count(result);
      STACK_PUSH(true, state);
    }

    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


void ProbeIndexPointValueIterator::getIndex(
    ProbeIndexPointValueIteratorState* state,
    PlanState& planState) const
{
  store::Item_t qnameItem;
  csize numChildren = theChildren.size();
  csize numNonKeyParams = (theSkip ? 2 : 1);

  ZORBA_ASSERT(consumeNext(qnameItem, theChildren[0], planState));

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((state->theIndexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }

    if (state->theIndexDecl->getNumKeyExprs() != numChildren - numNonKeyParams)
    {
      RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
      ERROR_PARAMS(qnameItem->getStringValue(),
                   "index",
                   numChildren - numNonKeyParams,
                   state->theIndexDecl->getNumKeyExprs()));
    }

    state->theIndex = (state->theIndexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));
      
    if (state->theIndex == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0023_INDEX_DOES_NOT_EXIST, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }
      
    state->theIterator = GENV_STORE.getIteratorFactory()->
    createIndexProbeIterator(state->theIndex);
  }
}


store::IndexCondition_t ProbeIndexPointValueIterator::createCondition(
    ProbeIndexPointValueIteratorState* state,
    PlanState& planState) const
{
  TypeManager* tm = theSctx->get_typemanager();
  store::Item_t keyItem;
  store::IndexCondition_t cond;
  csize numChildren = theChildren.size();
  csize numNonKeyParams = (theSkip ? 2 : 1);

  cond = state->theIndex->createCondition(store::IndexCondition::POINT_VALUE);

  for (csize i = numNonKeyParams; i < numChildren; ++i) 
  {
    if (!consumeNext(keyItem, theChildren[i], planState)) 
    {
      // Return the empty seq if any of the search key items is the empty seq.
      return NULL;
    }

    if (theCheckKeyType)
    {
      checkKeyType(loc, tm, state->theIndexDecl, i - numNonKeyParams, keyItem);
    }

    if (state->theIndexDecl->isGeneral() &&
        (state->theIndexDecl->getKeyTypes())[i - numNonKeyParams] == NULL)
    {
      store::SchemaTypeCode searchKeyType = keyItem->getTypeCode();
        
      if (searchKeyType == store::XS_UNTYPED_ATOMIC)
      {
        zstring str = keyItem->getStringValue();
        GENV_ITEMFACTORY->createString(keyItem, str);
      }
    }
      
    cond->pushItem(keyItem);
  }

  return cond;
}


void ProbeIndexPointValueIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************
  ProbeIndexPointGeneralIterator

  probe-index-point-general(
      $indexName as xs:QName,
      $keys      as xs:anyAtomicItem*) as node()*

  Note: the translator wraps calls to this function with an OP_NODE_SORT_DISTINCT_ASC
  function.
********************************************************************************/
ProbeIndexPointGeneralIteratorState::ProbeIndexPointGeneralIteratorState()
{
}


ProbeIndexPointGeneralIteratorState::~ProbeIndexPointGeneralIteratorState()
{
}


ProbeIndexPointGeneralIterator::ProbeIndexPointGeneralIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<ProbeIndexPointGeneralIterator,
                   ProbeIndexPointGeneralIteratorState>(sctx, loc, children),
  theCheckKeyType(true)
{
}


ProbeIndexPointGeneralIterator::~ProbeIndexPointGeneralIterator() 
{
}


void ProbeIndexPointGeneralIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ProbeIndexPointGeneralIterator,
                    ProbeIndexPointGeneralIteratorState>*)this);
	ar & theCheckKeyType;
}


bool ProbeIndexPointGeneralIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t keyItem;

  try
  {
    ProbeIndexPointGeneralIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexPointGeneralIteratorState, state, planState);

    getIndex(state, planState);
    createCondition(state);

    while (consumeNext(keyItem, theChildren[1], planState)) 
    {
      if (keyItem == NULL)
        // We may reach here in the case of internally-generated hashjoins
        continue;
      
      if (theCheckKeyType)
      {
        checkKeyType(loc, theSctx->get_typemanager(), state->theIndexDecl, 0, keyItem);
      }

      state->theCondition->clear();
      state->theCondition->pushItem(keyItem);
      
      state->theIterator->init(state->theCondition.getp());
      state->theIterator->open();
      
      while (state->theIterator->next(result)) 
      {
        STACK_PUSH(true, state);
      }

      state->theIterator->close();
    }

    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


void ProbeIndexPointGeneralIterator::getIndex(
    ProbeIndexPointGeneralIteratorState* state,
    PlanState& planState) const
{
  csize numChildren = theChildren.size();
  store::Item_t qnameItem;

  ZORBA_ASSERT(consumeNext(qnameItem, theChildren[0], planState));

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;
      
    if ((state->theIndexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }

    if (!state->theIndexDecl->isGeneral())
    {
      RAISE_ERROR(zerr::ZDDY0029_INDEX_POINT_GENERAL_PROBE_NOT_ALLOWED, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }

    if (state->theIndexDecl->getNumKeyExprs() != numChildren-1 ||
        numChildren != 2)
    {
      RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
      ERROR_PARAMS(qnameItem->getStringValue(),
                   "index",
                   numChildren-1,
                   state->theIndexDecl->getNumKeyExprs()));
    }

    state->theIndex = (state->theIndexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0023_INDEX_DOES_NOT_EXIST, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }
    
    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }
}


void ProbeIndexPointGeneralIterator::createCondition(
    ProbeIndexPointGeneralIteratorState* state) const
{
  if (state->theCondition == NULL)
  {
    state->theCondition = 
    state->theIndex->createCondition(store::IndexCondition::POINT_GENERAL);
  }
}


void ProbeIndexPointGeneralIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for (; lIter != lEnd; ++lIter)
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************

  probe-index-range-value($indexName               as xs:QName,
                          $range1LowerBound         as anyAtomic?,
                          $range1UpperBound         as anyAtomic?,
                          $range1HaveLowerBound     as boolean?,
                          $range1HaveupperBound     as boolean?,
                          $range1LowerBoundIncluded as boolean?,
                          $range1upperBoundIncluded as boolean?,
                          ....,
                          $rangeNLowerBound         as anyAtomic?,
                          $rangeNUpperBound         as anyAtomic?,
                          $rangeNHaveLowerBound     as boolean?,
                          $rangeNHaveupperBound     as boolean?,
                          $rangeNLowerBoundIncluded as boolean?,
                          $rangeNupperBoundIncluded as boolean?) as node()*

  Note: the translator makes sure that there is at least one range, and each
        range consits of exactly 6 values.
********************************************************************************/

ProbeIndexRangeValueIteratorState::ProbeIndexRangeValueIteratorState() 
{
}


ProbeIndexRangeValueIteratorState::~ProbeIndexRangeValueIteratorState() 
{
}


void ProbeIndexRangeValueIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theQname = 0;
  theIndex = 0;
  theIterator = NULL;
}


void ProbeIndexRangeValueIteratorState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) 
  {
    theIterator->close();
  }

  theQname = 0;
  theIndex = 0;
  theIterator = NULL;
}


ProbeIndexRangeValueIterator::ProbeIndexRangeValueIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children,
    bool skip)
  : 
  NaryBaseIterator<ProbeIndexRangeValueIterator,
                   ProbeIndexRangeValueIteratorState>(sctx, loc, children),
  theCheckKeyType(true),
  theSkip(skip)
{
}


ProbeIndexRangeValueIterator::~ProbeIndexRangeValueIterator() 
{
}


void ProbeIndexRangeValueIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ProbeIndexRangeValueIterator,
                    ProbeIndexRangeValueIteratorState>*)this);

  ar & theCheckKeyType;
  ar & theSkip;
}


bool ProbeIndexRangeValueIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::IndexCondition_t cond;
  xs_integer skip( numeric_consts<xs_integer>::zero() );

  try
  {
    ProbeIndexRangeValueIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexRangeValueIteratorState, state, planState);

    getIndex(state, planState);

    cond = createCondition(state, planState);

    if (theSkip)
    {
      store::Item_t skipItem;
      ZORBA_ASSERT(consumeNext(skipItem, theChildren[1], planState));
      skip = skipItem->getIntegerValue();
      if (skip.sign() < 0)
        skip = numeric_consts<xs_integer>::zero();
    }

    state->theIterator->init(cond, skip);
    state->theIterator->open();
      
    while (state->theIterator->next(result)) 
    {
      STACK_PUSH(true, state);
    }
    
    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


bool ProbeIndexRangeValueIterator::countImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::IndexCondition_t cond;
  xs_integer skip( numeric_consts<xs_integer>::zero() );

  try
  {
    ProbeIndexRangeValueIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexRangeValueIteratorState, state, planState);

    getIndex(state, planState);

    cond = createCondition(state, planState);

    if (theSkip)
    {
      store::Item_t skipItem;
      ZORBA_ASSERT(consumeNext(skipItem, theChildren[1], planState));
      skip = skipItem->getIntegerValue();
      if (skip.sign() < 0)
        skip = numeric_consts<xs_integer>::zero();
    }

    state->theIterator->init(cond, skip);
    state->theIterator->count(result);
    STACK_PUSH(true, state);

    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


void ProbeIndexRangeValueIterator::getIndex(
    ProbeIndexRangeValueIteratorState* state,
    PlanState& planState) const
{
  store::Item_t qnameItem;
  csize numChildren = theChildren.size();
  csize numNonKeyParams = (theSkip ? 2 : 1);
  IndexDecl_t indexDecl;

  ZORBA_ASSERT(consumeNext(qnameItem, theChildren[0], planState));

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((state->theIndexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }

    if (state->theIndexDecl->getMethod() != IndexDecl::TREE)
    {
      RAISE_ERROR(zerr::ZDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }

    if (numChildren < (6 + numNonKeyParams) ||
        (numChildren - numNonKeyParams) % 6 != 0)
    {
      RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
      ERROR_PARAMS(qnameItem->getStringValue(),
                   "index",
                   numChildren - numNonKeyParams,
                   "multiple of 6"));
    }

    if (state->theIndexDecl->getNumKeyExprs() * 6 < numChildren - numNonKeyParams)
    {
      RAISE_ERROR(zerr::ZDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
      ERROR_PARAMS(qnameItem->getStringValue(),
                   "index",
                   numChildren-numNonKeyParams,
                   state->theIndexDecl->getNumKeyExprs() * 6));
    }

    state->theIndex = (state->theIndexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));
      
    if (state->theIndex == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0023_INDEX_DOES_NOT_EXIST, loc,
      ERROR_PARAMS(qnameItem->getStringValue()));
    }
      
    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }
}


store::IndexCondition_t ProbeIndexRangeValueIterator::createCondition(
    ProbeIndexRangeValueIteratorState* state,
    PlanState& planState) const
{
  TypeManager* tm = theSctx->get_typemanager();
  store::IndexCondition_t cond;
  csize numChildren = theChildren.size();
  csize numNonKeyParams = (theSkip ? 2 : 1);

  cond = state->theIndex->createCondition(store::IndexCondition::BOX_VALUE);

  for (csize i = numNonKeyParams, keyNo = 0; i < numChildren; i += 6, ++keyNo) 
  {
    store::Item_t tempLeft;
    store::Item_t tempRight;
    store::Item_t tempHaveLeft;
    store::Item_t tempHaveRight;
    store::Item_t tempInclLeft;
    store::Item_t tempInclRight;

    if (!consumeNext(tempLeft, theChildren[i], planState))
      tempLeft = NULL;
 
    if (!consumeNext(tempRight, theChildren[i + 1], planState))
      tempRight = NULL;

    ZORBA_ASSERT(consumeNext(tempHaveLeft, theChildren[i + 2], planState));
    ZORBA_ASSERT(consumeNext(tempHaveRight, theChildren[i + 3], planState));
    ZORBA_ASSERT(consumeNext(tempInclLeft, theChildren[i + 4], planState));
    ZORBA_ASSERT(consumeNext(tempInclRight, theChildren[i + 5], planState));

    bool haveLeft = tempHaveLeft->getBooleanValue();
    bool haveRight = tempHaveRight->getBooleanValue();
    bool inclLeft = tempInclLeft->getBooleanValue();
    bool inclRight = tempInclRight->getBooleanValue();
      
    if (tempLeft != NULL && theCheckKeyType)
    {
      checkKeyType(loc, tm, state->theIndexDecl, keyNo, tempLeft);
    }

    if (tempRight != NULL && theCheckKeyType)
    {
      checkKeyType(loc, tm, state->theIndexDecl, keyNo, tempRight);
    }

    if (state->theIndexDecl->isGeneral() &&
        (state->theIndexDecl->getKeyTypes())[keyNo] == NULL)
    {
      store::SchemaTypeCode leftType;
      store::SchemaTypeCode rightType;

      if (tempLeft != NULL)
      {
        leftType = tempLeft->getTypeCode();
          
        if (leftType == store::XS_UNTYPED_ATOMIC)
        {
          zstring str = tempLeft->getStringValue();
          GENV_ITEMFACTORY->createString(tempLeft, str);
          leftType = store::XS_STRING;
        }
      }
        
      if (tempRight != NULL)
      {
        rightType = tempRight->getTypeCode();
          
        if (rightType == store::XS_UNTYPED_ATOMIC)
        {
          zstring str = tempRight->getStringValue();
          GENV_ITEMFACTORY->createString(tempRight, str);
          rightType = store::XS_STRING;
        }
      }
        
      if (tempLeft != NULL && tempRight != NULL)
      {
        if (!TypeOps::is_subtype(leftType, rightType) &&
            !TypeOps::is_subtype(rightType, leftType))
        {
          RAISE_ERROR(zerr::ZDDY0034_INDEX_RANGE_VALUE_PROBE_BAD_KEY_TYPES, loc,
          ERROR_PARAMS(state->theIndexDecl->getName()->getStringValue()));
        }
      }
    }
      
    cond->pushRange(tempLeft, tempRight, haveLeft, haveRight, inclLeft, inclRight);
  }

  return cond;
}


void ProbeIndexRangeValueIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************
  probe-index-range-general
********************************************************************************/
ProbeIndexRangeGeneralIteratorState::ProbeIndexRangeGeneralIteratorState()
  :
  theTimezone(0),
  theCollator(NULL),
  theNodeHashSet(NULL)
{
}


ProbeIndexRangeGeneralIteratorState::~ProbeIndexRangeGeneralIteratorState()
{
  if (theNodeHashSet)
    delete theNodeHashSet;
}


void ProbeIndexRangeGeneralIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theQname = 0;
  theIndex = 0;
  theIterator = NULL;
}


void ProbeIndexRangeGeneralIteratorState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) 
  {
    theIterator->close();
  }

  theQname = 0;
  theIndex = 0;
  theIterator = NULL;

  if (theNodeHashSet)
    theNodeHashSet->clear();
}


ProbeIndexRangeGeneralIterator::ProbeIndexRangeGeneralIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<ProbeIndexRangeGeneralIterator,
                   ProbeIndexRangeGeneralIteratorState>(sctx, loc, children),
  theCheckKeyType(true)
{
}


ProbeIndexRangeGeneralIterator::~ProbeIndexRangeGeneralIterator() 
{
}


void ProbeIndexRangeGeneralIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ProbeIndexRangeGeneralIterator,
                    ProbeIndexRangeGeneralIteratorState>*)this);

  ar & theCheckKeyType;
}


bool ProbeIndexRangeGeneralIterator::nextImpl(
    store::Item_t& result, 
    PlanState& planState) const
{
  store::IndexCondition_t cond;
  bool haveLower = false;
  bool haveUpper = false;
  bool inclLower = false;
  bool inclUpper = false;
  bool inclBound = false;

  try
  {
    ProbeIndexRangeGeneralIteratorState* state;
    DEFAULT_STACK_INIT(ProbeIndexRangeGeneralIteratorState, state, planState);

    getIndex(state, planState);

    {
      store::Item_t itemHaveLower;
      store::Item_t itemHaveUpper;
      store::Item_t itemInclLower;
      store::Item_t itemInclUpper;
      
      // Get the values of $haveLowerBound, $haveUpperBound, $lowerBoundIncluded,
      // and $upperBoundIncluded params
      if (!consumeNext(itemHaveLower, theChildren[3], planState))
        ZORBA_ASSERT(false);
      
      if (!consumeNext(itemHaveUpper, theChildren[4], planState))
        ZORBA_ASSERT(false);
      
      if (!consumeNext(itemInclLower, theChildren[5], planState))
        ZORBA_ASSERT(false);
      
      if (!consumeNext(itemInclUpper, theChildren[6], planState))
        ZORBA_ASSERT(false);
      
      haveLower = itemHaveLower->getBooleanValue();
      haveUpper = itemHaveUpper->getBooleanValue();
      inclLower = itemInclLower->getBooleanValue();
      inclUpper = itemInclUpper->getBooleanValue();
    }
    
    cond = state->theIndex->createCondition(store::IndexCondition::BOX_GENERAL);

    if (haveLower && haveUpper)
    {
      //
      // Build hashmap from the nodes satisfying the lower bound condition
      //
      
      if (!getSearchItems(planState, state, true, false, inclLower, false))
        goto done;
      
      assert(state->theSearchItems.size() >= 1);
      assert(state->theKeyType == NULL || state->theSearchItems.size() == 1);
      
      state->theNodeHashSet = new StructuredItemHandleHashSet(1024, false);
      
      state->theSearchItemsIte = state->theSearchItems.begin();
      state->theSearchItemsEnd = state->theSearchItems.end();
      
      for (;
           state->theSearchItemsIte != state->theSearchItemsEnd;
           ++state->theSearchItemsIte)
      {
        cond->clear();
        cond->pushBound(*state->theSearchItemsIte, true, inclLower);
        
        state->theIterator->init(cond);
        state->theIterator->open();
        
        while (state->theIterator->next(result)) 
        {
          state->theNodeHashSet->insert(result.getp());
        }
        
        state->theIterator->close();
      }
      
      state->theSearchItems.clear();
      cond->clear();

      //
      // Compute the nodes satisfying the upper bound condition and probe the
      // node hashmap.
      //
      
      if (!getSearchItems(planState, state, false, true, false, inclUpper))
        goto done;

      assert(state->theSearchItems.size() >= 1);
      assert(state->theKeyType == NULL || state->theSearchItems.size() == 1);

      state->theSearchItemsIte = state->theSearchItems.begin();
      state->theSearchItemsEnd = state->theSearchItems.end();

      for (;
           state->theSearchItemsIte != state->theSearchItemsEnd;
           ++state->theSearchItemsIte)
      {
        cond->clear();
        cond->pushBound(*state->theSearchItemsIte, false, inclUpper);

        state->theIterator->init(cond);

        state->theIterator->open();

        while(state->theIterator->next(result)) 
        {
          if (state->theNodeHashSet->exists(result))
            STACK_PUSH(true, state);
        }
          
        state->theIterator->close();
      }
    }
    
    else if (haveLower || haveUpper)
    {
      if (!getSearchItems(planState, state, haveLower, haveUpper, inclLower, inclUpper))
        goto done;
      
      assert(state->theSearchItems.size() >= 1);
      assert(state->theKeyType == NULL || state->theSearchItems.size() == 1);
      
      inclBound = (haveLower ? inclLower : inclUpper);
      
      state->theSearchItemsIte = state->theSearchItems.begin();
      state->theSearchItemsEnd = state->theSearchItems.end();
      
      for (;
           state->theSearchItemsIte != state->theSearchItemsEnd;
           ++state->theSearchItemsIte)
      {
        cond->clear();
        cond->pushBound(*state->theSearchItemsIte, haveLower, inclBound);
        
        state->theIterator->init(cond);

        state->theIterator->open();
          
        while(state->theIterator->next(result)) 
        {
          STACK_PUSH(true, state);
        }
          
        state->theIterator->close();
      }
    }
    
    else
    {
      getSearchItems(planState, state, false, false, false, false);

      state->theIterator->init(cond);

      state->theIterator->open();
        
      while(state->theIterator->next(result)) 
      {
        STACK_PUSH(true, state);
      }
        
      state->theIterator->close();
    }

  done:
    STACK_END(state);
  }
  catch (ZorbaException& e)
  {
    set_source(e, loc, false);
    throw;
  }
}


void ProbeIndexRangeGeneralIterator::getIndex(
    ProbeIndexRangeGeneralIteratorState* state,
    PlanState& planState) const
{
  TypeManager* tm = theSctx->get_typemanager();
  store::Item_t qname;
  IndexDecl_t indexDecl;
  xqtref_t keyType;

  ZORBA_ASSERT(consumeNext(qname, theChildren[0], planState));

  if (state->theQname == NULL || !state->theQname->equals(qname)) 
  {
    state->theQname = qname;

    if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0021_INDEX_NOT_DECLARED, loc,
      ERROR_PARAMS(qname->getStringValue()));
    }

    if (indexDecl->getMethod() != IndexDecl::TREE)
    {
      RAISE_ERROR(zerr::ZDDY0030_INDEX_RANGE_GENERAL_PROBE_NOT_ALLOWED, loc,
      ERROR_PARAMS(qname->getStringValue()));
    }

    if (!indexDecl->isGeneral())
    {
      RAISE_ERROR(zerr::ZDDY0030_INDEX_RANGE_GENERAL_PROBE_NOT_ALLOWED, loc,
      ERROR_PARAMS(qname->getStringValue()));
    }

    state->theIndex = (indexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qname) :
                       GENV_STORE.getIndex(state->theQname));
      
    if (state->theIndex == NULL)
    {
      RAISE_ERROR(zerr::ZDDY0023_INDEX_DOES_NOT_EXIST, loc,
      ERROR_PARAMS(qname->getStringValue()));
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);

    state->theTimezone = state->theIndex->getSpecification().getTimezone();
    state->theCollator = state->theIndex->getCollator(0);

    xqtref_t keyType = indexDecl->getKeyTypes()[0];

    assert(keyType == NULL ||
           keyType->get_quantifier() == SequenceType::QUANT_ONE);

    if (keyType != NULL && 
        !TypeOps::is_subtype(tm, *keyType, *GENV_TYPESYSTEM.UNTYPED_ATOMIC_TYPE_ONE) &&
        !TypeOps::is_equal(tm, *keyType, *GENV_TYPESYSTEM.ANY_ATOMIC_TYPE_ONE))
    {
      state->theKeyType = keyType;
    }
  }
}


bool ProbeIndexRangeGeneralIterator::getSearchItems(
    PlanState& planState,
    ProbeIndexRangeGeneralIteratorState* state,
    bool haveLower,
    bool haveUpper,
    bool inclLower,
    bool inclUpper) const
{
  store::Item_t searchItem;
  store::Item_t minmaxItem;
  long cmp;

  TypeManager* tm = theSctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  ulong childIdx = (haveLower ? 1 : 2);

  assert(!(haveLower && haveUpper));

  if (!haveLower && !haveUpper)
    return true;

  if (!consumeNext(searchItem, theChildren[childIdx], planState))
      return false;

  minmaxItem.transfer(searchItem);

  if (state->theKeyType != NULL)
  {
    while (consumeNext(searchItem, theChildren[childIdx], planState))
    {
      cmp = minmaxItem->compare(searchItem, state->theTimezone, state->theCollator);

      if ((haveLower && cmp > 0) || (haveUpper && cmp < 0))
        minmaxItem.transfer(searchItem);
    }
  }
  else
  {
    while (consumeNext(searchItem, theChildren[childIdx], planState))
    {
      xqtref_t minmaxItemType = tm->create_value_type(minmaxItem, loc);
      xqtref_t searchItemType = tm->create_value_type(searchItem, loc);

      if (!TypeOps::is_equal(tm, *searchItemType, *rtm.UNTYPED_ATOMIC_TYPE_ONE) &&
          TypeOps::is_subtype(tm, *searchItemType, *minmaxItemType))
      {
        cmp = minmaxItem->compare(searchItem, state->theTimezone, state->theCollator);
        
        if ((haveLower && cmp > 0) || (haveUpper && cmp < 0))
        {
          minmaxItem.transfer(searchItem);
          continue;
        }
      }

      state->theSearchItems.push_back(NULL);
      state->theSearchItems.back().transfer(minmaxItem);
      minmaxItem = searchItem;
    }
  }

  if (minmaxItem != NULL)
  {
    state->theSearchItems.push_back(NULL);
    state->theSearchItems.back().transfer(minmaxItem);
  }

  return true;
}


void ProbeIndexRangeGeneralIterator::accept(PlanIterVisitor& v) const 
{
  if (!v.hasToVisit(this))
    return;

  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}

} // namespace zorba
/* vim:set et sw=2 ts=2: */
