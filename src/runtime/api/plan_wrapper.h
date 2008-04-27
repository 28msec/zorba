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
#ifndef XQP_PLAN_WRAPPER_H
#define XQP_PLAN_WRAPPER_H

#include "common/shared_types.h"
#include "store/api/iterator.h"

namespace zorba {

  class PlanState;

  /*******************************************************************************
    Wrapper used to drive the evaluation of an iterator (sub)tree.

    The wrapper wraps the root iterator of the (sub)tree. It is responsible
    for allocating and deallocating the plan state that is shared by all
    iterators in the (sub)tree. In general, it hides internal functionality
    like separation of code and execution, or garabage collection, and it
    provides a simple interface that the application can use.
   ********************************************************************************/
  class PlanWrapper : public store::Iterator
  {
    protected:
      PlanIter_t   theIterator;
      PlanState*   theStateBlock;
#ifndef NDEBUG
      bool		     theIsOpened;
#endif

    public:
      PlanWrapper(const PlanIter_t& iter, CompilerCB*, dynamic_context* aDynamicContext);

      virtual ~PlanWrapper();

      virtual void 
      open();

      virtual store::Item_t 
      next();

      virtual void 
      reset();

      virtual void
      close() throw ();
  };

} /* namespace zorba */
#endif
