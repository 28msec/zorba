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
#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/item_factory.h"
#include "store/api/tuples.h"
#include "zorbatypes/numconversions.h"
#include "system/globalenv.h"
#include "runtime/core/tuple_iterators.h"
#include "runtime/api/plan_iterator_wrapper.h"

namespace zorba {

bool
CreateTupleIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  bool status;
  PlanIteratorState *state;
  DEFAULT_STACK_INIT(PlanIteratorState, state, planState);

  {
    int n = theChildren.size();
    std::vector<store::TupleField> fields;
    fields.resize(n);

    for(int i = 0; i < n; ++i) {
      store::TupleField& f = fields[i];
      std::vector<store::Item_t> items;
      items.resize(2);
      store::Item_t& i0 = items[0];
      store::Item_t& i1 = items[1];
      if (consumeNext(i0, theChildren[i].getp(), planState)) {
        if (consumeNext(i1, theChildren[i].getp(), planState)) {
          store::TempSeq_t seq = GENV_STORE.createTempSeq(items);
          store::Iterator_t lIter = new PlanIteratorWrapper(theChildren[i], planState);

          seq->append(lIter, false);
          f.set(seq.getp());
        } else {
          f.set(i0.getp());
        }
      } else {
        f.reset();
      }
    }
    status = GENV_ITEMFACTORY->createTuple(result, fields);
  }
  STACK_PUSH(status, state);

  STACK_END(state);
}

GetTupleFieldIteratorState::GetTupleFieldIteratorState() { }
GetTupleFieldIteratorState::~GetTupleFieldIteratorState() { }

bool
GetTupleFieldIterator::nextImpl(store::Item_t& result, PlanState& planState) const
{
  store::Item_t temp;
  store::Item_t tuple;
  xqp_integer idx;
  store::TempSeq_t tSeq;
  GetTupleFieldIteratorState *state;
  const store::TupleField *f;
  DEFAULT_STACK_INIT(GetTupleFieldIteratorState, state, planState);

  if (consumeNext(temp, theChildren[0].getp(), planState)) {
    idx = temp->getIntegerValue();
    NumConversions::integerToUInt(idx, state->theIndex);

    while(consumeNext(tuple, theChildren[1].getp(), planState)) {
      ZORBA_ASSERT(tuple->isTuple());
      ZORBA_ASSERT(tuple->getTupleFieldCount() >= (int)state->theIndex);

      f = &tuple->getTupleField((int)state->theIndex);
      if (f->getTag() == store::TupleField::UNINITIALIZED) {
          result = NULL;
      } else if (f->getTag() == store::TupleField::FIELD_TYPE_ITEM) {
          f->get(result);
          STACK_PUSH(true, state);
      } else {
          f->get(tSeq);
          state->theIterator = tSeq->getIterator();
          state->theIterator->open();
          while(state->theIterator->next(result)) {
            STACK_PUSH(true, state);
          }
          state->theIterator->close();
          break;
      }
    }
  }

  STACK_END(state);
}

}

/* vim:set ts=2 sw=2: */
