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
#include "functions/Alexis.h"

#include "runtime/util/UtilImpl.h"

using namespace std;

namespace zorba {

PlanIter_t zorba_decode_base64::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaBase64DecodeIterator ( loc, argv );
}


PlanIter_t zorba_encode_base64::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaBase64EncodeIterator ( loc, argv );
}


PlanIter_t
zorba_schema_type::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaSchemaTypeIterator(loc, argv);
}

#ifdef ZORBA_WITH_TIDY
  PlanIter_t
  zorba_tidy::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
  {
    return new ZorbaTidyIterator(loc, argv);
  }
#endif
}
/* vim:set ts=2 sw=2: */
