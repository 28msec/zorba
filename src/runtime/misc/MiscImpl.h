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
#ifndef ZORBA_MISC_IMPL_H
#define ZORBA_MISC_IMPL_H
 
#include "common/shared_types.h"

#include "runtime/base/narybase.h"
#include "runtime/api/plan_iterator_wrapper.h"

#include "zorbaerrors/errors.h"

namespace zorba {

// 3 The Error Function
NARY_ITER(FnErrorIterator);

// 8.1 fn:resolve-uri
NARY_ITER(FnResolveUriIterator);

class SequentialIterator : public NaryBaseIterator<SequentialIterator, PlanIteratorState >
{
private:
  bool theUpdating;
public:
  SequentialIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, bool aUpdating) 
  : NaryBaseIterator<SequentialIterator, PlanIteratorState>(loc, aChildren), theUpdating(aUpdating)
  {}

public:
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const; 
  bool isUpdating() const { return theUpdating; }
};

class FlowCtlIterator : public NaryBaseIterator<FlowCtlIterator, PlanIteratorState>
{
public:
  enum action {
    BREAK, CONTINUE, EXIT
  };

  class FlowCtlException : public error::ZorbaInternalException {
  public:
  enum action act;
    
    FlowCtlException (enum action act_)
      : act (act_) 
    {}
  };

  class ExitException : public FlowCtlException {
  public:
    store::Iterator_t val;
    ExitException (store::Iterator_t val_)
      : FlowCtlException (EXIT),
        val (val_)
    {}
  };

private:
  enum action act;

public:
  FlowCtlIterator(const QueryLoc& loc, std::vector<PlanIter_t>& aChildren, enum action act_)
    : NaryBaseIterator<FlowCtlIterator, PlanIteratorState>(loc, aChildren), act (act_)
  {}
  bool nextImpl(store::Item_t& result, PlanState& aPlanState) const; 
};

NARY_ITER (FnReadStringIterator);

} /* namespace zorba */

#endif /* ZORBA_MISC_IMPL_H */

/*
 * Local variables:
 * mode: c++
 * End:
 */
