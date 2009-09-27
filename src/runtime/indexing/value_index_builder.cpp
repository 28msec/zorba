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
#include "system/globalenv.h"

#include "types/typeimpl.h"

#include "context/static_context.h"
#include "context/dynamic_context.h"

#include "indexing/value_index.h"

#include "runtime/indexing/value_index_builder.h"
#include "runtime/visitors/planitervisitor.h"

#include "store/api/store.h"

namespace zorba {

SERIALIZABLE_CLASS_VERSIONS(CreateValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(CreateValueIndex)

SERIALIZABLE_CLASS_VERSIONS(DropValueIndex)
END_SERIALIZABLE_CLASS_VERSIONS(DropValueIndex)

SERIALIZABLE_CLASS_VERSIONS(ValueIndexInsertSessionOpener)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndexInsertSessionOpener)

SERIALIZABLE_CLASS_VERSIONS(ValueIndexInsertSessionCloser)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndexInsertSessionCloser)

SERIALIZABLE_CLASS_VERSIONS(ValueIndexBuilder)
END_SERIALIZABLE_CLASS_VERSIONS(ValueIndexBuilder)


/***************************************************************************//**

********************************************************************************/
bool CreateValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndex_t indexSpec;
  store::Index_t index;
  ValueIndexInsertSession_t session;

  PlanIteratorState* state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);
  indexSpec = theSctx->lookup_index(result);

  {
    const std::vector<xqtref_t>& iTypes(indexSpec->getKeyTypes());
    const std::vector<std::string>& iColls(indexSpec->getKeyCollations());
    int n = iTypes.size();
    store::IndexSpecification spec(n);
    xqp_string dColl;
    std::string dCollString(theSctx->lookup_default_collation(dColl) ?
                            dColl.getStore()->str() : "");
    for(int i = 0; i < n; ++i) 
    {
      const XQType& t = *iTypes[i];
      spec.theKeyTypes[i] = t.get_qname();
      const std::string& coll = iColls[i];
      spec.theCollations.push_back(coll.empty() ? dCollString : coll);
    }
    spec.theIsUnique = indexSpec->getUnique();
    spec.theIsSorted = indexSpec->getMethod() == ValueIndex::BTREE;
    spec.theIsTemp = indexSpec->getTemp();
    spec.theIsThreadSafe = true;
    spec.theIECreators = indexSpec->getPatternCreatorPairs();

    index = GENV_STORE.createIndex(result, spec);

    planState.dctx()->bind_index(indexSpec->getName(), index);
  }

  STACK_END (state);
}


UNARY_ACCEPT(CreateValueIndex);


/***************************************************************************//**

********************************************************************************/
bool DropValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndex_t index;
  PlanIteratorState *state;
  ValueIndexInsertSession_t session;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  planState.dctx()->unbind_index(result);
  GENV_STORE.deleteIndex(result);

  STACK_END (state);
}


UNARY_ACCEPT(DropValueIndex);


/***************************************************************************//**

********************************************************************************/
bool ValueIndexInsertSessionOpener::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool status;
  PlanIteratorState* state;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  {
    store::Index* index = planState.dctx()->lookup_index(result);

    store::IndexEntryReceiver_t receiver = index->createInsertSession();

    ValueIndexInsertSession_t session = new ValueIndexInsertSession(receiver);

    planState.dctx()->set_index_insert_session(result, session);
  }

  STACK_END (state);
}


UNARY_ACCEPT(ValueIndexInsertSessionOpener);


/***************************************************************************//**

********************************************************************************/
bool ValueIndexInsertSessionCloser::nextImpl(
    store::Item_t& result,
    PlanState& planState) const
{
  bool status;
  ValueIndexInsertSession_t session;
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  session = planState.dctx()->get_index_insert_session(result);
  session->commitBulkInsertSession();

  STACK_END (state);
}


UNARY_ACCEPT(ValueIndexInsertSessionCloser);


/***************************************************************************//**

********************************************************************************/
void ValueIndexBuilderState::init(PlanState& state)
{
  PlanIteratorState::init(state);
  theSession = NULL;
}


void ValueIndexBuilderState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  theSession = NULL;
}


bool ValueIndexBuilder::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t dValue;
  store::IndexKey key;

  ValueIndexBuilderState* state;
  DEFAULT_STACK_INIT(ValueIndexBuilderState, state, planState);

  if (state->theSession == NULL) 
  {
    consumeNext(state->theIndexQname, theChildren[0], planState);

    state->theSession = planState.dctx()->get_index_insert_session(state->theIndexQname);
  }

  consumeNext(dValue, theChildren[1], planState);

  for(unsigned int i = 2; i < theChildren.size(); ++i) 
  {
    store::Item_t cValue;
    if (consumeNext(cValue, theChildren[i], planState))
    {
      key.push_back(cValue);

      assert(cValue->isAtomic());
      assert(!consumeNext(cValue, theChildren[i], planState));
    }
    else
    {
      key.push_back(NULL);
    }
  }

  state->theSession->getBulkInsertSession()->receive(key, dValue);

  STACK_END (state);
}


NARY_ACCEPT(ValueIndexBuilder);


}
/* vim:set ts=2 sw=2: */
