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
#include "functions/Rest.h"
#include "system/globalenv.h"

#include "runtime/rest/rest.h"

namespace zorba {

rest_get::rest_get(const signature& sig)
 : function(sig)
{}

PlanIter_t
rest_get::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestGetIterator(loc, argv);
}

xqtref_t
rest_get::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


rest_post::rest_post(const signature& sig)
  : function(sig)
{}

PlanIter_t
rest_post::codegen (const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestPostIterator(loc, argv);
}

xqtref_t
rest_post::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

} /* namespace zorba */
