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
#include "functions/Convertors.h"

#include "runtime/convertors/ConvertorsImpl.h"

namespace zorba {
//Json
PlanIter_t
zorba_json_parse::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaJsonParseIterator(sctx, loc, argv);
}

PlanIter_t
zorba_json_serialize::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaJsonSerializeIterator(sctx, loc, argv);
}

//Json ML
PlanIter_t
zorba_json_ml_parse::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaJsonMLParseIterator(sctx, loc, argv);
}

PlanIter_t
zorba_json_ml_serialize::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaJsonMLSerializeIterator(sctx, loc, argv);
}
}
/* vim:set ts=2 sw=2: */
