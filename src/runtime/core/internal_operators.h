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
#pragma once
#ifndef ZORBA_RUNTIME_INTERNAL_OPERATORS_H
#define ZORBA_RUNTIME_INTERNAL_OPERATORS_H

#include "common/shared_types.h"
#include "runtime/base/narybase.h"

namespace zorba {

class HoistIteratorState : public PlanIteratorState {
  public:
    bool theDone;

    void init(PlanState& planState);
    void reset(PlanState& planState);
};

NARY_ITER_STATE(HoistIterator, HoistIteratorState);

NARY_ITER(UnhoistIterator);

}

#endif /* ZORBA_RUNTIME_INTERNAL_OPERATORS_H */
/* vim:set et sw=2 ts=2: */
