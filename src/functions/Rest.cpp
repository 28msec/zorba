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
rest_get::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestGetIterator(sctx, loc, argv, false);
}

rest_get_tidy::rest_get_tidy(const signature& sig)
  : function(sig)
{}

PlanIter_t
rest_get_tidy::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestGetIterator(sctx, loc, argv, true);
}

rest_post::rest_post(const signature& sig)
  : function(sig)
{}

PlanIter_t
rest_post::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestPostIterator(sctx, loc, argv);
}

xqtref_t
rest_post::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


rest_put::rest_put(const signature& sig) : function(sig)
{
}

PlanIter_t rest_put::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestPutIterator(sctx, loc, argv);
}

xqtref_t rest_put::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


rest_delete::rest_delete(const signature& sig) : function(sig)
{
}

PlanIter_t rest_delete::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestDeleteIterator(sctx, loc, argv);
}

xqtref_t rest_delete::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}


rest_head::rest_head(const signature& sig) : function(sig)
{
}

PlanIter_t rest_head::codegen (short sctx, const QueryLoc& loc, std::vector<PlanIter_t>& argv, AnnotationHolder &ann) const
{
  return new ZorbaRestHeadIterator(sctx, loc, argv);
}

xqtref_t rest_head::return_type (const std::vector<xqtref_t> &arg_types) const
{
  return GENV_TYPESYSTEM.ITEM_TYPE_STAR;
}

} /* namespace zorba */
