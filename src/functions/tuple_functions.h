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
#ifndef ZORBA_TUPLE_FUNCTIONS_H
#define ZORBA_TUPLE_FUNCTIONS_H

#include <vector>
#include "common/shared_types.h"
#include "functions/function.h"

namespace zorba {

class zop_createtuple : public function {
  public:
    zop_createtuple(const signature&);
    PlanIter_t codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

class zop_gettuplefield : public function {
  public:
    zop_gettuplefield(const signature&);
    PlanIter_t codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const;
};

}

#endif /* ZORBA_TUPLE_FUNCTIONS_H */
/* vim:set ts=2 sw=2: */
