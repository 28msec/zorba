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
 
#ifndef ZORBA_FUNCTIONS_JSONIQ_FUNCTIONS_IMPL_H
#define ZORBA_FUNCTIONS_JSONIQ_FUNCTIONS_IMPL_H


#include "common/shared_types.h"
#include "functions/function_impl.h"


namespace zorba 
{

#ifdef ZORBA_WITH_JSON

void populate_context_jsoniq_functions_impl(static_context* sctx);


/*******************************************************************************
  jn:object($objs as object()*) as object()

  It performs object construction by unioning the input objects.
********************************************************************************/
class jn_object : public function
{
public:
  jn_object(const signature& sig)
    :
  function(sig, FunctionConsts::JN_OBJECT_1)
  {
  }

  bool mustCopyInputNodes(expr* fo, csize producer) const { return false; }

  CODEGEN_DECL();
};


#endif // ZORBA_WITH_JSON

}

#endif
