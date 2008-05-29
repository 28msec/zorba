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
#include "runtime/api/plan_iterator_wrapper.h"

#include "runtime/base/plan_iterator.h"

namespace zorba {
  /*******************************************************************************
    class PlanIteratorWrapper
   ********************************************************************************/
  PlanIteratorWrapper::PlanIteratorWrapper(const PlanIterator* iter, PlanState& state) 
    : theIterator(iter),
    theStateBlock(&state)
  {
  }


  PlanIteratorWrapper::~PlanIteratorWrapper()
  {
  }

  void
  PlanIteratorWrapper::open()
  {
  }

  bool
  PlanIteratorWrapper::next(store::Item_t& result)
  {
    return PlanIterator::consumeNext(result, theIterator, *theStateBlock);
  }

  void
  PlanIteratorWrapper::reset()
  {
    theIterator->reset(*theStateBlock);
  }


  void
  PlanIteratorWrapper::close() throw()
  {
  }

} /* namespace zorba */
