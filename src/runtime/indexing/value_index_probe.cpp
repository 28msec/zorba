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
#include "runtime/indexing/value_index_probe.h"

namespace zorba {

void ValueIndexPointProbeState::init(PlanState& state)
{
  PlanIteratorState::init(state);
  theUri = NULL;
  theIndex = NULL;
  theIterator = NULL;
}

void ValueIndexPointProbeState::reset(PlanState& state)
{
  PlanIteratorState::reset(state);
  if (theIterator != NULL) {
    theIterator->close();
  }
}

bool ValueIndexPointProbe::nextImpl(store::Item_t& result, PlanState& planState) const
{
  ValueIndexPointProbeState *state;
  store::Item_t uri;
  store::IndexPointCondition_t cond;
  int numChildren;
  bool status;
  xqpStringStore *tempUri;
  DEFAULT_STACK_INIT(ValueIndexPointProbeState, state, planState);

  status = consumeNext(uri, theChildren[0], planState);
  ZORBA_ASSERT(status);

  tempUri = uri->getStringValueP();
  if (state->theUri == NULL || !state->theUri->equals(tempUri)) {
    state->theUri = tempUri;
    state->theIndex = GENV_STORE.getIndex(state->theUri);
    ZORBA_ASSERT(state->theIndex != NULL);
    state->theIterator = GENV_STORE.getIteratorFactory()->createIndexProbeIterator(state->theIndex);
  }
  cond = state->theIndex->createPointCondition();
  numChildren = theChildren.size();
  for(int i = 1; i < numChildren; ++i) {
    store::Item_t temp;
    if (!consumeNext(temp, theChildren[i], planState)) {
      temp = NULL;
    }
    cond->pushItem(temp);
  }

  state->theIterator->init(cond);
  state->theIterator->open();
  while(state->theIterator->next(result)) {
    STACK_PUSH(true, state);
  }
  STACK_END(state);
}

}
