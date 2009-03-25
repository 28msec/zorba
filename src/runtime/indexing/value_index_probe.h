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
#ifndef ZORBA_VALUE_INDEX_PROBE_H
#define ZORBA_VALUE_INDEX_PROBE_H

#include "runtime/base/unarybase.h"
#include "runtime/base/narybase.h"
#include "indexing/value_index.h"
#include "store/api/store.h"
#include "store/api/iterator.h"
#include "store/api/iterator_factory.h"
#include "store/api/index.h"

namespace zorba {

class ValueIndexPointProbeState : public PlanIteratorState {
  public:
    xqpStringStore_t theUri;
    store::Index *theIndex;
    store::IndexProbeIterator_t theIterator;

    void init(PlanState&);
    void reset(PlanState&);
};

class ValueIndexPointProbe : public NaryBaseIterator<ValueIndexPointProbe, ValueIndexPointProbeState> {
  public:
    ValueIndexPointProbe(const QueryLoc& loc, std::vector<PlanIter_t> aChildren)
      : NaryBaseIterator<ValueIndexPointProbe, ValueIndexPointProbeState>(loc, aChildren) { }

    virtual ~ValueIndexPointProbe() { }

    bool nextImpl(store::Item_t& result, PlanState& planState) const;

    virtual void accept(PlanIterVisitor& v) const;
};

}

#endif /* ZORBA_VALUE_INDEX_PROBE_H */
/* vim:set ts=2 sw=2: */
