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
#ifndef ZORBA_RUNTIME_API_PLAN_WRAPPER
#define ZORBA_RUNTIME_API_PLAN_WRAPPER

#include "common/shared_types.h"

#include "store/api/iterator.h"


namespace zorba 
{

class PlanState;
class ZorbaDebuggerCommons;
class ZorbaDebuggerRuntime;
class Timeout;
class XQueryImpl;

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
  friend class ZorbaDebuggerRuntime;

protected:
  PlanIter_t         theIterator;
  PlanState        * theStateBlock;
  dynamic_context  * theDynamicContext;
  XQueryImpl       * theQuery;
#ifndef NDEBUG
  bool		           theIsOpened;
#endif
  Timeout          * theTimeout;

public:
  PlanWrapper(
        const PlanIter_t& iter,
        CompilerCB*,
        dynamic_context* aDynamicContext,
        XQueryImpl* aQuery,
        uint32_t aStackDepth = 0,
        long aTimeout = -1);

  virtual ~PlanWrapper();

  virtual void 
  open();

  virtual bool
  next(store::Item_t&);

  virtual void 
  reset();

  virtual void
  close() throw ();

  virtual void checkDepth(const QueryLoc &loc);

  const RuntimeCB* getRuntimeCB() const;
};

} /* namespace zorba */
#endif

/*
 * Local variables:
 * mode: c++
 * End:
 */
