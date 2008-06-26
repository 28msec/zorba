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

} /* namespace zorba */

#endif /* ZORBA_MISC_IMPL_H */

