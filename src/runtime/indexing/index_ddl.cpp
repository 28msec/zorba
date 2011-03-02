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

#include "context/static_context.h"
#include "context/dynamic_context.h"

namespace zorba 
{


static void checkKeyType(
    const QueryLoc& loc,
    TypeManager* tm,
    const IndexDecl* indexDecl,
    ulong keyNo,
    store::Item_t& searchKey)
{
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  xqtref_t searchKeyType = tm->create_value_type(searchKey);
  xqtref_t indexKeyType = (indexDecl->getKeyTypes())[keyNo];

  if (indexKeyType != NULL &&
      !TypeOps::is_subtype(tm, *searchKeyType, *indexKeyType))
  {
    ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc,
                             "The type of a search key does not mathch the type"
                             << " of the corresponding index key for index "
                             << indexDecl->getName()->getStringValue()
                             << ". The search key has type "
                             << searchKeyType->toString()
                             << " and the expected key type is "
                             << indexKeyType->toString());
  }
  else if (indexKeyType == NULL)
  {
    ZORBA_ASSERT(indexDecl->isGeneral());

    if (TypeOps::is_equal(tm, *searchKeyType, *rtm.ANY_ATOMIC_TYPE_ONE) ||
        (indexDecl->isOrdered() &&
         (TypeOps::is_subtype(tm, *searchKeyType, *rtm.NOTATION_TYPE_ONE) ||
          TypeOps::is_subtype(tm, *searchKeyType, *rtm.HEXBINARY_TYPE_ONE))))
    {
      ZORBA_ERROR_LOC_DESC_OSS(XPTY0004, loc, 
                               "Cannot probe index "
                               << indexDecl->getName()->getStringValue()
                               << " with a search key of type "
                               << searchKeyType->toString());
    }
  }
}


SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateInternalIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(CreateIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(CreateIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(DeleteIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(DeleteIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(RefreshIndexIterator)
END_SERIALIZABLE_CLASS_VERSIONS(RefreshIndexIterator)

SERIALIZABLE_CLASS_VERSIONS(ValueIndexEntryBuilderIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndexEntryBuilderIterator)

SERIALIZABLE_CLASS_VERSIONS(GeneralIndexEntryBuilderIterator)
END_SERIALIZABLE_CLASS_VERSIONS(GeneralIndexEntryBuilderIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointValueIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointValueIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointGeneralIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ProbeIndexPointGeneralIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeValueIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeValueIterator)

SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeGeneralIterator)
END_SERIALIZABLE_CLASS_VERSIONS(ProbeIndexRangeGeneralIterator)


/*******************************************************************************

********************************************************************************/
void createIndexSpec(
    IndexDecl* indexDecl,
    store::IndexSpecification& spec)
{
  const std::vector<xqtref_t>& keyTypes(indexDecl->getKeyTypes());
  const std::vector<OrderModifier>& keyModifiers(indexDecl->getOrderModifiers());
  ulong numColumns = (ulong)keyTypes.size();

  spec.resize(numColumns);

  for(ulong i = 0; i < numColumns; ++i) 
  {
    if (keyTypes[i] != NULL)
    {
      const XQType& t = *keyTypes[i];
      spec.theKeyTypes[i] = t.get_qname();
    }
    spec.theCollations.push_back(keyModifiers[i].theCollation);
  }

  spec.theIsGeneral = indexDecl->isGeneral();
  spec.theIsUnique = indexDecl->getUnique();
  spec.theIsSorted = indexDecl->getMethod() == IndexDecl::TREE;
  spec.theIsTemp = indexDecl->isTemp();
  spec.theIsThreadSafe = true;
  spec.theIsAutomatic = indexDecl->getMaintenanceMode() != IndexDecl::MANUAL;

  ulong numSources = (ulong)indexDecl->numSources();

  spec.theSources.resize(numSources);

  for (ulong i = 0; i < numSources; ++i)
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

  createIndexSpec(indexDecl, spec);

  try
  {
    storeIndex = GENV_STORE.createIndex(indexDecl->getName(), spec, planIteratorWrapper);
  }
  catch(error::ZorbaError& e)
  {
    // Store raises error if index exists already
    ZORBA_ERROR_LOC_DESC(e.theErrorCode, loc, e.theDescription);
  }

  if (planState.theLocalDynCtx->getIndex(indexDecl->getName()))
    planState.theLocalDynCtx->unbindIndex(indexDecl->getName());

  planState.theLocalDynCtx->bindIndex(indexDecl->getName(), storeIndex);

  STACK_END(state);
}


void CreateInternalIndexIterator::accept(PlanIterVisitor& v) const 
{
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
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue().c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) != NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0022_INDEX_EXISTS_ALREADY, loc,
                          qname->getStringValue().c_str(), "");
  }

  buildPlan = indexDecl->getBuildPlan(ccb, loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, NULL, NULL); 

  createIndexSpec(indexDecl, spec);

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addCreateIndex(qname, spec, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void CreateIndexIterator::accept(PlanIterVisitor& v) const 
{
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
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue().c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue().c_str(), "");
  }

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addDeleteIndex(qname);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void DeleteIndexIterator::accept(PlanIterVisitor& v) const 
{
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
    ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                          qname->getStringValue().c_str(), "");
  }

  if (GENV_STORE.getIndex(qname) == NULL)
  {
    ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                          qname->getStringValue().c_str(), "");
  }

  buildPlan = indexDecl->getBuildPlan(ccb, loc); 
  
  planWrapper = new PlanWrapper(buildPlan, ccb, dctx, NULL); 

  result = GENV_ITEMFACTORY->createPendingUpdateList();

  reinterpret_cast<store::PUL*>(result.getp())->addRefreshIndex(qname, planWrapper);

  STACK_PUSH(true, state);

  STACK_END(state);
}


void RefreshIndexIterator::accept(PlanIterVisitor& v) const 
{
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

GeneralIndexEntryBuilderIteratorState::GeneralIndexEntryBuilderIteratorState() 
{
}


GeneralIndexEntryBuilderIteratorState::~GeneralIndexEntryBuilderIteratorState() 
{
}


void GeneralIndexEntryBuilderIteratorState::init(PlanState& planState) 
{
  PlanIteratorState::init(planState);
  theCurChild = 0;
}


void GeneralIndexEntryBuilderIteratorState::reset(PlanState& planState) 
{
  PlanIteratorState::reset(planState);
  theCurChild = 0;
}


GeneralIndexEntryBuilderIterator::~GeneralIndexEntryBuilderIterator() 
{
}


bool GeneralIndexEntryBuilderIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  GeneralIndexEntryBuilderIteratorState* state;
  DEFAULT_STACK_INIT(GeneralIndexEntryBuilderIteratorState, state, planState);

  for (; state->theCurChild < theChildren.size(); ++state->theCurChild) 
  {
    while (consumeNext(result, theChildren[state->theCurChild].getp(), planState))
    {
      STACK_PUSH(true, state);
    }
  }
  
  STACK_END(state);
}


void GeneralIndexEntryBuilderIterator::accept(PlanIterVisitor& v) const 
{
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
  ProbeIndexPointValueIterator
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
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<ProbeIndexPointValueIterator,
                   ProbeIndexPointValueIteratorState>(sctx, loc, children),
  theCheckKeyType(true)
{
}


ProbeIndexPointValueIterator::~ProbeIndexPointValueIterator() 
{
}


bool ProbeIndexPointValueIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t qnameItem;
  store::Item_t keyItem;
  store::IndexCondition_t cond;
  ulong numChildren = (ulong)theChildren.size();
  ulong i;
  bool status;
  TypeManager* tm = theSctx->get_typemanager();
  RootTypeManager& rtm = GENV_TYPESYSTEM;

  ProbeIndexPointValueIteratorState* state;
  DEFAULT_STACK_INIT(ProbeIndexPointValueIteratorState, state, planState);

  status = consumeNext(qnameItem, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((state->theIndexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    if (state->theIndexDecl->getKeyExpressions().size() != numChildren-1)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    state->theIndex = (state->theIndexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createCondition(store::IndexCondition::POINT_VALUE);

  for (i = 1; i < numChildren; ++i) 
  {
    if (!consumeNext(keyItem, theChildren[i], planState)) 
    {
      // We may reach here in the case of internally-generated hashjoins
      break;
    }

    if (theCheckKeyType)
    {
      checkKeyType(loc, tm, state->theIndexDecl, i-1, keyItem);
    }

    if (state->theIndexDecl->isGeneral() &&
        (state->theIndexDecl->getKeyTypes())[i-1] == NULL)
    {
      xqtref_t searchKeyType = tm->create_value_type(keyItem);

      if (TypeOps::is_equal(tm, *searchKeyType, *rtm.UNTYPED_ATOMIC_TYPE_ONE))
      {
        zstring str = keyItem->getStringValue();
        GENV_ITEMFACTORY->createString(keyItem, str);
      }
    }

    cond->pushItem(keyItem);
  }

  if (i == numChildren)
  {
    state->theIterator->init(cond);
    state->theIterator->open();

    while(state->theIterator->next(result)) 
    {
      STACK_PUSH(true, state);
    }
  }

  STACK_END(state);
}


void ProbeIndexPointValueIterator::accept(PlanIterVisitor& v) const 
{
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
  store::Item_t qnameItem;
  store::Item_t keyItem;
  ulong numChildren = (ulong)theChildren.size();
  bool status;

  ProbeIndexPointGeneralIteratorState* state;
  DEFAULT_STACK_INIT(ProbeIndexPointGeneralIteratorState, state, planState);

  status = consumeNext(qnameItem, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qnameItem)) 
  {
    state->theQname = qnameItem;

    if ((state->theIndexDecl = theSctx->lookup_index(qnameItem)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    if (!state->theIndexDecl->isGeneral())
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0029_INDEX_GENERAL_PROBE_NOT_ALLOWED, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    if (state->theIndexDecl->getKeyExpressions().size() != numChildren-1 ||
        numChildren != 2)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    state->theIndex = (state->theIndexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qnameItem) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                            qnameItem->getStringValue().c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  if (state->theCondition == NULL)
  {
    state->theCondition = 
    state->theIndex->createCondition(store::IndexCondition::POINT_GENERAL);
  }

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


void ProbeIndexPointGeneralIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter ){
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


/*******************************************************************************
  ProbeIndexRangeValueIterator
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
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<ProbeIndexRangeValueIterator,
                   ProbeIndexRangeValueIteratorState>(sctx, loc, children),
  theCheckKeyType(true)
{
}


ProbeIndexRangeValueIterator::~ProbeIndexRangeValueIterator() 
{
}


void ProbeIndexRangeValueIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar,
  (NaryBaseIterator<ProbeIndexRangeValueIterator, ProbeIndexRangeValueIteratorState>*)this);

  ar & theCheckKeyType;
}


bool ProbeIndexRangeValueIterator::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  store::Item_t qname;
  IndexDecl_t indexDecl;
  store::IndexCondition_t cond;
  ulong numChildren = (ulong)theChildren.size();
  bool status;
 
  ProbeIndexRangeValueIteratorState* state;
  DEFAULT_STACK_INIT(ProbeIndexRangeValueIteratorState, state, planState);

  status = consumeNext(qname, theChildren[0], planState);
  ZORBA_ASSERT(status);

  if (state->theQname == NULL || !state->theQname->equals(qname)) 
  {
    state->theQname = qname;

    if ((indexDecl = theSctx->lookup_index(qname)) == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0021_INDEX_IS_NOT_DECLARED, loc,
                            qname->getStringValue().c_str(), "");
    }

    if (indexDecl->getMethod() != IndexDecl::TREE)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0026_INDEX_RANGE_PROBE_NOT_ALLOWED, loc,
                            qname->getStringValue().c_str(), "");
    }

    if ((numChildren-1) % 6 != 0)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qname->getStringValue().c_str(), "");
    }

    if (indexDecl->getKeyExpressions().size() * 6 > numChildren-1)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0025_INDEX_WRONG_NUMBER_OF_PROBE_ARGS, loc,
                            qname->getStringValue().c_str(), "");
    }

    state->theIndex = (indexDecl->isTemp() ?
                       planState.theLocalDynCtx->getIndex(qname) :
                       GENV_STORE.getIndex(state->theQname));

    if (state->theIndex == NULL)
    {
      ZORBA_ERROR_LOC_PARAM(XDDY0023_INDEX_DOES_NOT_EXIST, loc,
                            qname->getStringValue().c_str(), "");
    }

    state->theIterator = GENV_STORE.getIteratorFactory()->
                         createIndexProbeIterator(state->theIndex);
  }

  cond = state->theIndex->createCondition(store::IndexCondition::BOX_VALUE);

  ulong keyNo;
  ulong i;
  for (i = 1, keyNo = 0; i < numChildren; i += 6, ++keyNo) 
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

    if (!consumeNext(tempHaveLeft, theChildren[i + 2], planState))
      ZORBA_ASSERT(false);

    if (!consumeNext(tempHaveRight, theChildren[i + 3], planState))
     ZORBA_ASSERT(false);

    if (!consumeNext(tempInclLeft, theChildren[i + 4], planState))
     ZORBA_ASSERT(false);
 
    if (!consumeNext(tempInclRight, theChildren[i + 5], planState))
     ZORBA_ASSERT(false);

    bool haveLeft = tempHaveLeft->getBooleanValue();
    bool haveRight = tempHaveRight->getBooleanValue();
    bool inclLeft = tempInclLeft->getBooleanValue();
    bool inclRight = tempInclRight->getBooleanValue();

    if (tempLeft != NULL && theCheckKeyType)
    {
      checkKeyType(loc, theSctx->get_typemanager(), indexDecl, keyNo, tempLeft);
    }

    if (tempRight != NULL && theCheckKeyType)
    {
      checkKeyType(loc, theSctx->get_typemanager(), indexDecl, keyNo, tempRight);
    }

    cond->pushRange(tempLeft, tempRight, haveLeft, haveRight, inclLeft, inclRight);
  }

  state->theIterator->init(cond);
  state->theIterator->open();

  while(state->theIterator->next(result)) 
  {
    STACK_PUSH(true, state);
  }

  STACK_END(state);
}


void ProbeIndexRangeValueIterator::accept(PlanIterVisitor& v) const 
{
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
  ProbeIndexRangeGeneralIterator
********************************************************************************/


ProbeIndexRangeGeneralIterator::ProbeIndexRangeGeneralIterator(
    static_context* sctx,
    const QueryLoc& loc,
    std::vector<PlanIter_t>& children)
  : 
  NaryBaseIterator<ProbeIndexRangeGeneralIterator,
                   ProbeIndexRangeValueIteratorState>(sctx, loc, children),
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
                    ProbeIndexRangeValueIteratorState>*)this);

  ar & theCheckKeyType;
}


bool ProbeIndexRangeGeneralIterator::nextImpl(
    store::Item_t& result, 
    PlanState& aPlanState) const
{
  return false;
}


void ProbeIndexRangeGeneralIterator::accept(PlanIterVisitor& v) const 
{
  v.beginVisit(*this);

  std::vector<PlanIter_t>::const_iterator lIter = theChildren.begin();
  std::vector<PlanIter_t>::const_iterator lEnd = theChildren.end();
  for ( ; lIter != lEnd; ++lIter )
  {
    (*lIter)->accept(v);
  }

  v.endVisit(*this);
}


}
