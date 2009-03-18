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

namespace zorba {

bool ValueIndexInsertSessionOpener::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  ValueIndex_t index;
  PlanIteratorState *state;
  ValueIndexInsertSession_t session;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);
  status = consumeNext(result, theChild, planState);
  ZORBA_ASSERT(status);
  index = planState.sctx()->lookup_index(result->getStringValueP());
  session = index->createBulkInsertSession();
  planState.dctx()->set_val_idx_insert_session(result->getStringValueP(), session);
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
  session = planState.dctx()->get_val_idx_insert_session(result->getStringValueP());
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
  if (state->theSession == NULL) {
    store::Item_t iName;
    consumeNext(iName, theChildren[0], planState);
    state->theSession = planState.dctx()->get_val_idx_insert_session(iName->getStringValueP());
  }
  consumeNext(dValue, theChildren[1], planState);
  for(unsigned int i = 1; i < theChildren.size(); ++i) {
    store::Item_t cValue;
    key.push_back(consumeNext(cValue, theChildren[i], planState) ? cValue : NULL);
  }
  state->theSession->getBulkInsertSession()->receive(key, dValue);
  STACK_END (state);
}

}
/* vim:set ts=2 sw=2: */
