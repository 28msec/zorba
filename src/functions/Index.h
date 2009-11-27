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
#ifndef ZORBA_FUNCTIONS_INDEX
#define ZORBA_FUNCTIONS_INDEX

#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba 
{

/******************************************************************************
  create-internal-index($indexName as xs:QName) as ()

  This is an intenal function that is used by the hashjoins rule to create and
  populate a temp index. There are 3 reasons why we need a different function
  than the regular create-index, which is defined below:

  1. create-index assumes that the domain and key expressions do not reference
     any free variables. This is not true for the temp index created by the
     hashjoin rule.
  2. The argument to create-index can be any arbitrary expression that returns
     a QName. In the case of create-internal-index we know that the arg is a
     const expr holding a qname item.
  3. create-internal-index is a "simple" function, whereas create-index is an
     updating function.
********************************************************************************/
class FunctionCreateInternalIndex : public function 
{
public:
  FunctionCreateInternalIndex(const signature& sig) 
    :
    function(sig, FunctionConsts::OP_CREATE_INTERNAL_INDEX_1)
  {
  }

  bool requires_dyn_ctx() const { return true; }

  CODEGEN_DECL();
};



void populateContext_Index(static_context* sctx);

}

#endif
/* vim:set ts=2 sw=2: */

/*
 * Local variables:
 * mode: c++
 * End:
 */
