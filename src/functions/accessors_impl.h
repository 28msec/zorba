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
 
#ifndef ZORBA_FUNCTIONS_ACCESSORS_IMPL_H
#define ZORBA_FUNCTIONS_ACCESSORS_IMPL_H


#include "common/shared_types.h"
#include "functions/function.h"
#include "functions/single_seq_func.h"
#include "functions/function_enum.h"


namespace zorba {


void populate_context_accessors_impl(static_context* sctx);

/*******************************************************************************
  
********************************************************************************/
class fn_name_func : public function
{
public:
  fn_name_func(const signature& s) : function (s) {}

  PlanIter_t codegen(CompilerCB* cb,
                     static_context* sctx,
                     const QueryLoc& loc,
                     std::vector<PlanIter_t>& argv,
                     AnnotationHolder& ann) const;
};

} //namespace zorba


#endif 
