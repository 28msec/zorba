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

#include "runtime/misc/materialize.h"
#include "runtime/visitors/planiter_visitor.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "system/globalenv.h"

#include "store/api/temp_seq.h"
#include "store/api/store.h"


namespace zorba
{


SERIALIZABLE_CLASS_VERSIONS(MaterializeIterator)
END_SERIALIZABLE_CLASS_VERSIONS(MaterializeIterator)



MaterializeIteratorState::MaterializeIteratorState()
{
}


MaterializeIteratorState::~MaterializeIteratorState()
{
}


void MaterializeIteratorState::init(PlanState& planState)
{
  PlanIteratorState::init(planState);

  theTempSeq = GENV_STORE.createTempSeq(false);
}


void MaterializeIterator::serialize(::zorba::serialization::Archiver& ar)
{
  serialize_baseclass(ar, 
  (UnaryBaseIterator<MaterializeIterator, MaterializeIteratorState>*)this);
}


void MaterializeIterator::openImpl(PlanState& planState, uint32_t& offset)
{
  UnaryBaseIterator<MaterializeIterator, MaterializeIteratorState>::
  openImpl(planState, offset);

  MaterializeIteratorState* state =
  StateTraitsImpl<MaterializeIteratorState>::getState(planState, theStateOffset);

  state->theChildWrapper = new PlanIteratorWrapper(theChild, planState);
}


bool MaterializeIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  MaterializeIteratorState* state;
  DEFAULT_STACK_INIT(MaterializeIteratorState, state, planState);

  state->theTempSeq->init(state->theChildWrapper);

  state->theTempSeqIter = state->theTempSeq->getIterator();

  state->theTempSeqIter->open();

  while (state->theTempSeqIter->next(result))
  {
    STACK_PUSH(true, state);
  }

  state->theTempSeqIter->close();

  STACK_END(state);
}


UNARY_ACCEPT(MaterializeIterator);


}

/* vim:set et sw=2 ts=2: */
