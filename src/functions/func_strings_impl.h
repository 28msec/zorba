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

// ******************************************
// *                                        *
// * THIS IS A GENERATED FILE. DO NOT EDIT! *
// * SEE .xml FILE WITH SAME NAME           *
// *                                        *
// ******************************************


#ifndef ZORBA_FUNCTIONS_STRINGS_IMPL_H
#define ZORBA_FUNCTIONS_STRINGS_IMPL_H

#include "common/shared_types.h"
#include "functions/function.h"
#include "functions/function_impl.h"

namespace zorba
{

class fn_substring_intopt: public function
{
public:
  fn_substring_intopt(const signature& sig, FunctionConsts::FunctionKind kind)
    : function(sig, kind) {}

  bool specializable() { return false; }

  function* specialize(static_context *sctx,
        const std::vector<xqtref_t>& argTypes) const;

  CODEGEN_DEF(fn_substring_intopt);
};

}
#endif

