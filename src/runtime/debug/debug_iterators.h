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
#ifndef ZORBA_DEBUG_ITERATORS_H
#define ZORBA_DEBUG_ITERATORS_H

#include "zorbatypes/xqpstring.h"

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {


class FnTraceIteratorState : public PlanIteratorState {
  public:
    store::Item_t theTagItem;
    xqpString theTag;

    void init(PlanState&);
    void reset(PlanState&);
};

NARY_ITER_STATE(FnTraceIterator, FnTraceIteratorState);

} /* namespace zorba */

#endif /* ZORBA_DEBUG_ITERATORS_H */
/* vim:set ts=2 sw=2: */
