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
#include "functions/tuple_functions.h"
#include "runtime/core/tuple_iterators.h"

namespace zorba {

zop_createtuple::zop_createtuple(const signature& sig)
  : function(sig) { }

PlanIter_t zop_createtuple::codegen(const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new CreateTupleIterator(loc, argv);
}

zop_gettuplefield::zop_gettuplefield(const signature& sig)
  : function(sig) { }

PlanIter_t zop_gettuplefield::codegen(const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new GetTupleFieldIterator(loc, argv);
}

}
/* vim:set ts=2 sw=2: */
