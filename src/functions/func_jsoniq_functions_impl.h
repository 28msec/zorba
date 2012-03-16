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
  updating function jn:object-insert(
      $o as object(),
      $name1 as xs:integer, $value1 as item(), 
      ..., 
      $nameN as xs:integer, $valueN as item())
********************************************************************************/
class op_object_insert : public function
{
public:
  op_object_insert(const signature& sig)
    : 
    function(sig, FunctionConsts::OP_OBJECT_INSERT_N)
  {

  }

  short getScriptingKind() const { return UPDATING_EXPR; }

  bool accessesDynCtx() const { return true; }

  bool mustCopyInputNodes(expr* fo, csize producer) const;

  CODEGEN_DECL();
};



#endif // ZORBA_WITH_JSON

}

#endif
