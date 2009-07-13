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
#include "runtime/indexing/value_index_builder.h"
#include "store/api/store.h"
#include "system/globalenv.h"

namespace zorba {

bool CreateValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndex_t indexSpec;
  store::Index_t index;
  PlanIteratorState *state;
  ValueIndexInsertSession_t session;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);
  indexSpec = getStaticContext(planState)->lookup_index(result->getStringValueP());

  {
    const std::vector<xqtref_t>& iTypes(indexSpec->getIndexFieldTypes());
    const std::vector<std::string>& iColls(indexSpec->getIndexFieldCollations());
    int n = iTypes.size();
    store::IndexSpecification spec(n);
    xqp_string dColl;
    std::string dCollString(getStaticContext(planState)->lookup_default_collation(dColl) ?
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

    index = GENV_STORE.createIndex(result->getStringValueP(), spec);

    planState.dctx()->bind_index(indexSpec->getIndexUri()->str(), index);
  }
  STACK_END (state);
}


bool DropValueIndex::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndex_t index;
  PlanIteratorState *state;
  ValueIndexInsertSession_t session;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  planState.dctx()->unbind_index(result->getStringValueP()->str());
  GENV_STORE.deleteIndex(result->getStringValueP());

  STACK_END (state);
}


bool ValueIndexInsertSessionOpener::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  PlanIteratorState* state;

  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  {
    std::string& indexUri = result->getStringValueP()->str();

    store::Index* index = planState.dctx()->lookup_index(indexUri);

    store::IndexEntryReceiver_t receiver = index->createInsertSession();

    ValueIndexInsertSession_t session = new ValueIndexInsertSession(receiver);

    planState.dctx()->set_index_insert_session(indexUri, session);
  }

  STACK_END (state);
}


bool ValueIndexInsertSessionCloser::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndexInsertSession_t session;
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);

  session = planState.dctx()->get_index_insert_session(result->getStringValueP()->str());
  session->commitBulkInsertSession();

  STACK_END (state);
}


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
  ValueIndexBuilderState *state;
  DEFAULT_STACK_INIT(ValueIndexBuilderState, state, planState);

  if (state->theSession == NULL) 
  {
    store::Item_t iName;
    consumeNext(iName, theChildren[0], planState);
    state->theSession = planState.dctx()->get_index_insert_session(iName->getStringValueP()->str());
  }

  consumeNext(dValue, theChildren[1], planState);

  for(unsigned int i = 2; i < theChildren.size(); ++i) 
  {
    store::Item_t cValue;
    key.push_back(consumeNext(cValue, theChildren[i], planState) ? cValue : NULL);
  }

  state->theSession->getBulkInsertSession()->receive(key, dValue);

  STACK_END (state);
}

}
/* vim:set ts=2 sw=2: */
