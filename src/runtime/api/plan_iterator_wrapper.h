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
#ifndef XQP_PLAN_ITERATOR_WRAPPER_H
#define XQP_PLAN_ITERATOR_WRAPPER_H

#include "store/api/iterator.h"
#include "common/shared_types.h"

namespace zorba {

  class PlanState;

/*******************************************************************************
  This is a "helper" wrapper that is used when we need to pass a plan iterator
  to the store. The wrapper wraps the plan iterator in order to provide a
  simpler interface that the store can use.

  The wrapper does not allocate a new state block, but it points to the same 
  block that contains the state of the wrapped plan iterator.
********************************************************************************/
class PlanIteratorWrapper : public store::Iterator
{
 private:
  const PlanIterator*   theIterator;
  PlanState*            theStateBlock;

 public:
  PlanIteratorWrapper(const PlanIterator* iter, PlanState& planState);

  virtual ~PlanIteratorWrapper();

  void open();
  bool next(store::Item_t&);
  void reset();
  void close() throw();
};

} /* namespace zorba */
#endif
