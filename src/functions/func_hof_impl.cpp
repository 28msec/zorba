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
#include "stdafx.h"

#include "common/shared_types.h"
#include "types/typeops.h"

#include "runtime/base/plan_iterator.h"

#include "functions/function.h"
#include "functions/function_impl.h"

#include "system/globalenv.h"


namespace zorba
{

/*******************************************************************************

********************************************************************************/
class fn_map : public function
{
public:
  fn_map(const signature& sig, FunctionConsts::FunctionKind kind)
    : 
    function(sig, kind)
  {

  }

  bool accessesDynCtx() const { return true; }

  PlanIter_t codegen(CompilerCB* cb,                        
                     static_context* sctx,                  
                     const QueryLoc& loc,                   
                     std::vector<PlanIter_t>& argv,         
                     expr& ann) const
  {
    return NULL;
  }
};


/*******************************************************************************

********************************************************************************/
void populate_context_hof_impl(static_context* sctx)
{
  std::vector<xqtref_t> args;
  args.push_back(GENV_TYPESYSTEM.ITEM_TYPE_ONE);
  
  xqtref_t hofParamType = GENV_TYPESYSTEM.create_function_type(
      args,
      GENV_TYPESYSTEM.ITEM_TYPE_STAR,
      TypeConstants::QUANT_ONE);
                                       
  DECL_WITH_KIND(sctx, fn_map,
        (createQName(static_context::W3C_FN_NS, "", "map"), 
        hofParamType, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR, 
        GENV_TYPESYSTEM.ITEM_TYPE_STAR),
        FunctionConsts::FN_MAP_2);
  
}

}

/* vim:set et sw=2 ts=2: */
