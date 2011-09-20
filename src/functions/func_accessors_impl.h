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
#ifndef ZORBA_FUNCTIONS_ACCESSORS_IMPL_H
#define ZORBA_FUNCTIONS_ACCESSORS_IMPL_H


#include "common/shared_types.h"
#include "functions/function.h"
#include "functions/function_impl.h"
#include "functions/function_consts.h"


namespace zorba {


void populate_context_accessors_impl(static_context* sctx);

/*******************************************************************************

********************************************************************************/
class fn_name_func : public function
{
public:
  fn_name_func(const signature& sig) : function(sig, FunctionConsts::FN_UNKNOWN)
  {
    theKind = (sig.paramCount() == 0 ?
              FunctionConsts::FN_NAME_0 :
              FunctionConsts::FN_NAME_1);
  }

  CODEGEN_DECL();
};

} //namespace zorba


#endif 
/* vim:set et sw=2 ts=2: */
